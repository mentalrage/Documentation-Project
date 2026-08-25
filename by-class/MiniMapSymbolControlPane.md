*** UID:00008G | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MiniMapSymbolControlPane class declaration is intentionally withheld: method routes,
// TimerHandler-compatible vtable evidence, resources, and field candidates are documented,
// but base-subobject spelling and center-coordinate field order are not source-quality yet.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapSymbolControlPane

## Status

- Confidence: very strong for class behavior, method starts, minimap ownership, timer/draw evidence, the omitted center-position setter, and EPF/palette collaborators; still capped by exact base declaration and center-coordinate offset ordering.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably beside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Current recovered file: `source-3/simroot_v2/class_MiniMapSymbolControlPane.cpp`
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- Class-level C++ policy: emit only the formal class-index marker with `[[CHILDREN]]`. Exact method bodies should live in split by-memory method children after base layout and field names are accepted.

## Class Purpose

`MiniMapSymbolControlPane` is the animated symbol/marker control used by `MiniMapDialog` for player, NPC, portal, and party markers. It stores EPF/palette-backed sprite state, a text label, frame range, animation timing, and a timer callback path for cycling symbol frames.

The source route stays in the MiniMap feature family because all construction/update evidence comes from `MiniMapDialog`, the resource names are minimap-specific (`MNSYMBOL.EPF`, `MNSYMBOL.PAL`, `MNPLAYER.EPF`, `MNPLAYER.PAL`, with `BARAM.PAL` as a constructor fallback), and the class is grouped with `MiniMapRenderer`/`MiniMapImageControlPane` in the renderer/control memory island. Timer, EPF, palette, and tile-context libraries are collaborators only.

## Methods

| Address | Source-facing method | Role |
| --- | --- | --- |
| `0x00455e60-0x00456031` | `MiniMapSymbolControlPane::MiniMapSymbolControlPane(...)` | Real source constructor. Builds the control pane, installs the primary/secondary/timer vtables, initializes EPF tile context state, copies label/resource/palette strings, records symbol metadata, sets the initial frame, and seeds the center-position fields from the caller point. |
| `0x00456040-0x0045609e` | `MiniMapSymbolControlPane::~MiniMapSymbolControlPane()` | Real non-deleting destructor body. Tears down symbol-control resources, resets the vtable family, and chains through shared pane/tile-context cleanup. |
| `0x004560a0-0x004560e1` | `StartAnimation(int firstFrame, int lastFrame, int intervalMs)` | Real helper. Stores first/last/current frame state, records the timer interval, enables animation, and schedules timer id `0` through `TimerHandler::ScheduleTimer` at `0x005975e0` using the secondary timer subobject at full-object `+0xa4`. |
| `0x004560f0-0x00456175` | `SetCenterPosition(int centerX, int centerY)` | Real helper omitted by older docs. Stores the symbol center pair, rebuilds a rectangle from the current EPF frame dimensions, and dispatches the pane `SetBounds` vtable slot. Sole exported caller is `MiniMapDialog` code at `0x00452f4e`, after renderer view-origin update and image-control position setting. |
| `0x00456180-0x00456293` | `OnAnimationTick(int timerId, int payload1, int payload2)` | Real timer callback through the TimerHandler-compatible vtable. Checks active/visible state and `timerId == 0`, advances/wraps frame state, reloads the EPF layout entry, adjusts bounds if dimensions changed, invalidates/redraws the control, reschedules with the saved interval, and returns true. The two extra payload arguments are unused by this class. |
| `0x004562a0-0x004562f8` | `OnDraw()` | Real draw method. Resolves the palette, draws the EPF-backed symbol sprite through shared callbacks, and uses the label/text path for marker labeling. |
| `0x004562f8-0x00456303` | adjustor thunk | Compiler-generated destructor adjustor; no source-authored method body. |
| `0x00456303-0x0045630e` | adjustor thunk | Compiler-generated destructor adjustor; IDA-active even though some generated output previously disabled the row. No source-authored method body. |
| `0x00456310-0x004563af` | scalar deleting destructor | Compiler-generated deleting wrapper with optional `operator delete` path; document as ABI glue and do not emit as handwritten C++. |
| `0x004563b0-0x004563b5` | `GetControlType() const` | Real tiny vtable method returning control type `0x17` / decimal `23`. |

## Ownership And Parent Gate

This class is assigned to [UID:0000LE][MiniMap](by-file/MiniMap.md). The direct parent is scored `86/88`, and this child is raised to `88/90` because the class page, [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), and the MiniMap file page now identify the same minimap-local symbol-control role including the missing `SetCenterPosition` helper.

The ownership evidence is direct rather than merely topical: the memory aggregate records the constructor/destructor/animation/draw helper ranges, `MiniMapDialog` construction and use sites, and the generic timer-registration caveat. No other candidate source owner currently explains the marker sprite/text state, minimap dialog callers, and minimap control-type helper as well as `MiniMap.cpp`.

Rejected owners:

- `TimerHandler` / `TimerMgr`: they only supply scheduling and callback dispatch. They do not own minimap sprite resources, labels, EPF/palette state, or dialog construction sites.
- `EPFImageControlPane`, `EPFTileContext`, `EPFLib`, and `PaletteLib`: they supply comparable rendering/resource helpers but not the symbol-control owner, MiniMapDialog callers, or minimap marker semantics.
- `FittingRoomDialog`: decompiler pollution from the shared timer wrapper. No construction, resource, or caller evidence routes this class to fitting-room code.
- `MiniMapRenderer` alone: renderer support explains coordinate conversion, but `MiniMapDialog::RenderSymbols` constructs and updates the symbol controls inside the MiniMap feature module.

## Boundary Caveats

- Active generated output previously kept `0x00456303` in the disabled partition even though IDA has a real thunk there. Treat `0x004562f8-0x00456303` and `0x00456303-0x0045630e` as two explicit half-open compiler adjustor-thunk ranges.
- `0x00456310-0x004563af` is scalar deleting destructor glue. It wraps the real destructor and optional delete; it is not a source-authored class method.
- The `StartAnimation` decompile uses a polluted `FittingRoomDialog` timer-host cast. IDA shows the callee is generic timer registration (`0x005975e0`), so source migration should name this through the timer base/handler path rather than fitting-room code.
- The exact original base declaration is still not safe to emit. The object clearly combines a pane/control primary base with a TimerHandler-compatible secondary subobject at full-object `+0xa4`, but base order and original inheritance spelling need a method-child/layout pass.

## Constructor And Field Candidates

Best current source-facing constructor shape is `MiniMapSymbolControlPane(const wchar_t *label, int symbolType, const Point *centerPosition, const wchar_t *epfFileName, short initialFrame, bool visible, const wchar_t *paletteName)`. This is a signature-shape note for split children, not class-level formal C++.

Recommended field names and caveats:

| Offset | Recommended name | Evidence and caveat |
| --- | --- | --- |
| `+0x108` | `m_tileContext` / `m_spriteContext` | Initialized by the `EPFTileContext` init path at `0x00457a60`; consumed by EPF lookup/render callbacks; same broad shape as [UID:00004I][EPFTileContext](by-class/EPFTileContext.md). |
| `+0x118` to `+0x124` | EPF frame bounds | Filled by `g_pEPFLib` layout lookup and used for width/height and draw bounds. Use final EPFTileContext field names once support docs settle. |
| `+0x130` | `m_symbolType` | Constructor stores the symbol type; `MiniMapDialog` passes player/symbol/label marker categories. |
| `+0x134` | `m_symbolRecordId` | Constructor initializes `-1`; `MiniMapDialog` writes the current `.mnm` record id after construction. |
| `+0x138` | `m_relatedObjectId` / `m_npcObjectId` | `MiniMapDialog` writes the related object value only for symbol type `1`, otherwise `-1`; final name depends on `.mnm` record-layout naming. |
| `+0x13c` | `m_epfFileName[0x20]` | Constructor copies the EPF file name with `_wcscpy_s(..., 0x20, epfFileName)`; callers use `MNSYMBOL.EPF` or `MNPLAYER.EPF`. |
| `+0x17c` | `m_initialFrame` / `m_resourceFrame` | Constructor stores the initial frame and passes it to the EPF layout lookup. |
| `+0x17e` | `m_paletteName[0x20]` | Constructor copies the supplied palette or default `BARAM.PAL`; `OnDraw` resolves it through `g_pPaletteLib`. |
| `+0x1be` | `m_label[0x20]` | Constructor copies the marker label with `_wcscpy_s(..., 0x20, label)`. Use `m_label` rather than `m_symbolName` because player labels and marker labels share the buffer. |
| `+0x1fe` | `m_animationEnabled` | Constructor clears it; `StartAnimation` sets it. |
| `+0x200` | `m_firstFrame` | Constructor initializes to the initial frame; `StartAnimation` writes the first frame; tick wraps to it. |
| `+0x204` | `m_lastFrame` | Constructor initializes to the initial frame; `StartAnimation` writes the last frame; tick compares current frame against it. |
| `+0x208` | `m_currentFrame` | Constructor initializes to the initial frame; `StartAnimation` resets it to first frame; tick increments/wraps it. |
| `+0x20c` | `m_animationIntervalMs` | Constructor clears it; `StartAnimation` writes the delay; tick reschedules with it. |
| `+0x210` | `m_centerY` candidate | Center-coordinate pair. Setter/timer adjusted-this evidence suggests this is the second coordinate, but constructor point-copy order still needs child-level verification. |
| `+0x214` | `m_centerX` candidate | Center-coordinate pair. Setter body and image-control analogy make this the stronger first/horizontal coordinate candidate. |

Rejected names: `m_mapX/m_mapY` overstate raw map ownership because the caller passes display centers after renderer view-origin conversion; `m_frameCount` is wrong for `+0x204` because it is compared as a last-frame index; `m_timerId` is wrong for `+0x20c` because timer id is fixed `0` and `+0x20c` is the interval.

## Center Setter Evidence

`0x004560f0-0x00456175` should be named `MiniMapSymbolControlPane::SetCenterPosition(int centerX, int centerY)`.

- Exported function evidence identifies `0x004560f0` as a real non-thunk method with one xref from `0x00452f4e`.
- The body stores both integer arguments into the center-position pair, derives a rectangle from current EPF frame bounds, and dispatches the pane vtable slot `+0x2c`, documented by support pages as `Pane::SetBounds`.
- The sole caller is inside `MiniMapDialog` code at `0x00452ea0`: it updates renderer view origin through `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, computes display-space marker centers, calls the analogous image-control position setter at `0x00452f3d`, then calls this symbol-control setter at `0x00452f4e`.
- `SetMapPosition` is rejected because map/player state has already been converted to display coordinates. `SetBounds` is rejected because the caller does not pass a rectangle; this method computes bounds from center coordinates and EPF frame dimensions. `MoveTo` / `SetPosition` remain plausible, but `SetCenterPosition` best captures the half-width/half-height subtraction before `SetBounds`.

## Timer, EPF, Palette, And Helper Names

- `StartAnimation` uses [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) / [UID:0001QU][client_timing](by-meta/client_timing.md) semantics. The source-facing route is `TimerHandler::ScheduleTimer`, not a fitting-room helper.
- `OnAnimationTick` is reached through the secondary TimerHandler-compatible vtable at `0x006108b4`, with the callback entry at `0x006108b8`. Decompiler adjusted-this accesses such as `+0x15c`, `+0x160`, `+0x164`, `+0x168`, `+0x16c`, and `+0x170` correspond to full-object `+0x200`, `+0x204`, `+0x208`, `+0x20c`, `+0x210`, and `+0x214`.
- `DAT_0067a744` / `dword_67A744` is [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md). Its layout lookup at `0x004d02f0` should be described as `EPFLib::LookupLayoutEntry` / `ResourceLayout::LookupLayoutEntry` until the library source spelling is final.
- `DAT_0067a7e0` / `dword_67A7E0` is [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md). The palette lookup path around `0x00543d70` is a `PaletteLib::FindLoadedPaletteIndex` candidate by analogy with EPF image controls.
- `0x00457a60`, `0x00457ab0`, and `0x00458500` are EPFTileContext init/post-draw-reset/cleanup style helpers. Use support names rather than raw decompiler names.
- `0x004b78d0` is `RectBounds::SetLTRB`. `0x004b7ed0` is a rectangle equality/changed predicate candidate; tick compares old/new bounds before calling `SetBounds`.
- `dword_69B3FC` and `dword_69B3E8` are render-target preparation and EPF sprite render callbacks shared with EPFImageControlPane. Their roles are known, but source names remain open.

Resource string decisions:

- `MNSYMBOL.EPF` and `MNSYMBOL.PAL` are minimap symbol resources used for non-player markers.
- `MNPLAYER.EPF` and `MNPLAYER.PAL` are player marker resources.
- `BARAM.PAL` is the constructor fallback palette.
- Interior IDA labels such as `MBOL.PAL`, `PLAYER.PAL`, and `RAM.PAL` should not be promoted as source string names when the full UTF-16 string starts are available.

## B010 Declaration-Shell Audit And C++ Disposition

Class-level first-draft C++ is intentionally limited to the formal marker with `[[CHILDREN]]`.

Reasons:

- A class declaration would force unstable inheritance/base-subobject spelling and unresolved `+0x210/+0x214` x/y offset ordering.
- This class page is a high-level owner/emitter marker; exact source method bodies should live in split by-memory method children.
- The adjustor thunks and scalar deleting destructor are compiler-generated and must not be represented as source-authored methods.

The vtable audit supports the marker-only shape: primary/secondary/tertiary vtables at `0x0061081c`, `0x00610884`, and `0x006108b4` include a TimerHandler-compatible tertiary view, and current xrefs confirm constructor/destructor/scalar references. Constructor `0x00455e60`, destructor `0x00456040`, `StartAnimation`, `SetCenterPosition`, `OnAnimationTick`, `OnDraw`, thunks, scalar deleting destructor, and `GetControlType` are documented. The B005 inventory lists exact proposed children, but the primary base declaration, TimerHandler secondary subobject spelling, `+0x210/+0x214` center-coordinate ordering, and `.mnm` record id field names remain blockers for class-level C++.

Exact child pages that can carry source-level C++ only after split authorization:

| Proposed child | C++ policy |
| --- | --- |
| `by-memory/0x00455e60-0x00456031.MiniMapSymbolControlPaneConstructor.md` | Method-level draft after base/field layout wording is stabilized. |
| `by-memory/0x00456040-0x0045609e.MiniMapSymbolControlPaneDestructor.md` | Method-level draft can describe EPFTileContext cleanup and base destructor chaining. |
| `by-memory/0x004560a0-0x004560e1.MiniMapSymbolControlPaneStartAnimation.md` | Method-level draft ready. |
| `by-memory/0x004560f0-0x00456175.MiniMapSymbolControlPaneSetCenterPosition.md` | Method-level draft ready with `SetCenterPosition` name and the center-field offset caveat. |
| `by-memory/0x00456180-0x00456293.MiniMapSymbolControlPaneOnAnimationTick.md` | Method-level draft ready after the TimerHandler callback signature is stated. |
| `by-memory/0x004562a0-0x004562f8.MiniMapSymbolControlPaneOnDraw.md` | Method-level draft ready with provisional render-callback names. |
| `by-memory/0x004563b0-0x004563b5.MiniMapSymbolControlPaneGetControlType.md` | Method-level draft ready; returns `0x17`. |

Do not create source-emitting children for `0x004562f8-0x0045630e` or `0x00456310-0x004563af`; those are compiler glue/no-formal-C++ spans.

## Current-Pass Class Declaration Exclusions

- The original inheritance declaration and base order are excluded from this callback: evidence supports a pane/control primary base plus a TimerHandler-compatible secondary subobject at `+0xa4`, but source spelling is not safe.
- `+0x210/+0x214` coordinate order is excluded from class-level C++: setter evidence favors `+0x214 = centerX` and `+0x210 = centerY`, but constructor point-copy order needs an exact child/point-struct check.
- `+0x138` field naming is excluded until `.mnm` record-layout names are accepted; MiniMapDialog writes it only for symbol type `1`.
- `dword_69B3FC` and `dword_69B3E8` callback names remain support-doc names only; render-role usage is proven, but original callback identifiers are not.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page now records the full symbol-control method inventory including `0x004560f0-0x00456175`, source-facing names for constructor/destructor/animation/center/tick/draw/type methods, direct minimap parentage, MiniMapDialog construction/update callers, timer-secondary-subobject behavior, EPF/palette/global helper names, resource strings, field candidates, compiler-glue boundaries, and the no-class-C++ proof. It remains below 90 because exact base declarations, child pages, and center-offset ordering are not final. |
| Confidence | 90 | Confidence is very strong because class, memory aggregate, file root, caller bodies, vtable data, and support docs all agree on minimap-local ownership and method boundaries. It is capped below final quality by unresolved class layout spelling and the center-coordinate field-order caveat, not by ownership or behavior. |
| Parent | [UID:0000LE][MiniMap](by-file/MiniMap.md) | Child `88/90` and parent `86/88` both clear the strict 85/85 gate. By-structure ownership is direct because this is a minimap marker control constructed and updated by the MiniMap dialog/renderer family and backed by minimap-specific EPF/palette resources. |

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:00008F][MiniMapRenderer](by-class/MiniMapRenderer.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0003FP][0x006104f4-0x006108d4.MiniMapUiReadOnlyData](by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- 2026-06-30 B010 empty-emitter implementation callback:
  - Inserted the accepted formal class-index marker with `[[CHILDREN]]`, added the declaration-shell audit, renamed C++ readiness to an explicit marker/body disposition, removed non-formal source-style snippets, and converted open questions into current-pass class declaration exclusions.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Reconciled the constructor guidance to use a `Point`/center-position input, kept `SetCenterPosition` as the preferred source-facing name, and added child-level source-style drafts for `StartAnimation` and `SetCenterPosition` while preserving the class-level no-C++ policy.
- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Before: `85/86`; the class page omitted `0x004560f0-0x00456175`, left timer/base inference underdocumented, and lacked source-quality field/helper/resource/no-code reasoning.
  - After: `88/90`; added `MiniMapSymbolControlPane::SetCenterPosition`, refined MiniMap ownership, TimerHandler secondary-subobject evidence, EPF/palette/global helper names, resource-string decisions, field candidates, compiler-glue boundaries, future child-code routing, and the class-level no-C++ proof.
  - Validation basis: B005 report re-read target/support docs, generated class coverage, MiniMapDialog caller bodies, vtable data, and exported function evidence for `0x004523d0`, `0x00452ea0`, `0x004540a0`, `0x00455e60`, `0x00456040`, `0x004560a0`, `0x004560f0`, `0x00456180`, `0x004562a0`, `0x004562f8`, `0x00456303`, `0x00456310`, and `0x004563b0`.
- 2026-06-07 Batch 093 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:84`, and `AUTOGEN_PARENT_UID` blank because the parent-gate note was stale.
  - After: `COMPLETION:85`, `CONFIDENCE:86`, and parent [UID:0000LE][MiniMap](by-file/MiniMap.md).
  - Why: [UID:0000LE][MiniMap](by-file/MiniMap.md) now clears `85/86`, and [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) already documents the minimap-local constructor/destructor/animation/draw/control-type method set, MiniMapDialog construction/use evidence, and generic timer-registration caveat.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed constructor/destructor/animation/draw/thunk/deleting-destructor/type-helper starts at `0x00455e60`, `0x00456040`, `0x004560a0`, `0x00456180`, `0x004562a0`, `0x004562f8`, `0x00456303`, `0x00456310`, and `0x004563b0`. Left `AUTOGEN_PARENT_UID` blank at that time because the likely MiniMap parent had not yet cleared the attachment gate.
- 2026-05-30: Grading changed from `0/0` to `82/84`.
  - Before: page documented the animated symbol-control role and method ranges but remained unevaluated.
  - After: score reflects documented constructor/destructor, animation timer, draw path, destructor thunks, control-type helper, and the polluted fitting-room timer-host caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts, multiple constructions from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md), and generic timer registration through `0x005975e0`.
