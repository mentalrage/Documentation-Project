*** UID:0000N1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RectangleControlPane

## Status

- Confidence: very strong for the complete source inventory, standalone route, class/header surface, exact authored methods, and compiler-product exclusions.
- Settled module: `ui/controls/RectangleControlPane.cpp` with required sibling `RectangleControlPane.h`.
- Main address ranges: `0x00499c60-0x00499d37`, plus destructor/thunk support in `0x0049afc1-0x0049b8f5`
- Vtable layout: [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) and exact data [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)

## File Role

`RectangleControlPane` is a minimal `ControlPane`-derived filled-rectangle control. Its constructor source shape is `RectangleControlPane(int drawColor, const RectBounds *bounds) : ControlPane(8, bounds) { SetDrawColor(drawColor); }`; it applies the drawing color through the inherited draw-state setter at `0x004b9660`, then paints its full bounds as a solid rectangle.

Current IDA caller evidence ties construction to [UID:0000LE][MiniMap](by-file/MiniMap.md) symbol rendering, where it creates small background rectangles behind symbol/text overlays. The class remains generic visual-control infrastructure rather than minimap-owned code.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `RectangleControlPane` | [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) | Constructor; source body calls `ControlPane(8, bounds)` and `SetDrawColor(drawColor)`. The three Rectangle vtable installs are compiler output from the class declaration. |
| `~RectangleControlPane` | [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) | Authored out-of-line empty ordinary destructor source child; compiler output restores the three Rectangle vtable views and tail-jumps to inherited [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown. |
| `OnPaint` / paint virtual | [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) | Copies inherited pane bounds with `GetBounds(&bounds)` and invokes Surface-owned slot 7 directly as `g_pfnFillRect(this, &bounds)`. |
| adjustor thunks | [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) | Compiler thunks forwarding to scalar deleting destructor; excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) | Compiler-generated MSVC deleting-destructor wrapper; no handwritten source body or emitter route. |
| `HitTestPart(int,int)` | [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md) | Authored terminal primary-vtable override; ignores both coordinates and returns fixed hit-test part `21`. |
| vtable layout | [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) | Non-emitting source-declaration evidence for the primary, secondary, and tertiary views. |
| vtable/RTTI data | [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) | Compiler-emitted primary, secondary, and tertiary vtable/RTTI storage generated from the class declaration; no handwritten source body. |

## Ownership Decision

Keep this as the standalone `ui/controls/RectangleControlPane.cpp` with sibling `RectangleControlPane.h`. The one-class method island, dedicated RTTI/vtables, generic control semantics, current source-tree topology, and standalone control analogs outweigh the lack of an original debug file record. MiniMap is a consumer only. ControlPane and GrafPort are base/dependency owners only. The former `BasicControlPanes.cpp` fold is retained as rejected historical speculation because no shared helper, data, symbol, or emitter route supports it.

## Evidence Notes

- Live IDA confirms real functions at `0x00499c60`, `0x00499ce0`, `0x00499d00`, `0x0049b490`, and `0x0049b8f0`, plus compiler adjustor thunks at `0x0049afc1` and `0x0049afcc`.
- The constructor calls `ControlPane` base construction with kind `8`, installs Rectangle vtables as compiler output, applies the configured color through the inherited color/draw-state setter at `0x004b9660`, and has one ordinary caller at `0x0045252c` inside `MiniMapDialog::RenderSymbols`.
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) documents `0x004b9660` as the active draw-color state setter writing `this+0x74`, so the constructor's first-draft C++ uses descriptive `SetDrawColor(drawColor)` rather than generated feature-owned helper names such as `FittingRoomListPane::SetTextColor`.
- The paint virtual [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) has vtable-only reachability at `0x00618478`, calls `GetBounds` at `0x004b8e00` to copy the inherited Pane rectangle at `this+0x44`, restores the pane receiver to `ecx`, pushes the local rectangle address, and dispatches [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc` directly.
- Generated invalidation naming is rejected for the paint method because the observed body fills current bounds; BackPane, Pane, GrafPort, SurfaceRenderCallbackTable, and MiniMap evidence are dependencies or consumer route, not file ownership.
- The terminal primary-vtable slot at `0x00618494` points to `0x0049b8f0`, whose `mov al,15h; retn 8` body is `RectangleControlPane::HitTestPart(int,int)`. Named same-slot CheckBox and Scrollable overrides independently prove the two-coordinate byte-return ABI; the former type-id interpretation is superseded.
- The primary destructor wrapper has a vtable data ref at `0x00618434`; secondary and tertiary adjustor thunk table cells are at `0x0061849c` and `0x006184cc`.
- [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) carries the authored out-of-line empty ordinary destructor source body. Generated `RectangleControlPane.cpp` should contain constructor [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md), destructor [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md), and paint [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) through exact source-bearing children, while [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md) is only a non-emitting grouping page.
- [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) remains exact binary evidence, but no source should be emitted for it. The wrapper is reached by the primary vtable slot and adjustor thunks, restores Rectangle vtable views, calls [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown at `0x00544580`, conditionally frees through [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), and has no Rectangle-specific field/resource cleanup. B010 local PE/Capstone proof also closes the surrounding padding (`0x0049b487-0x0049b490` and `0x0049b4e5-0x0049b4f0`), confirms the adjustor `this-0xa0`/`this-0xa4` routes, and identifies the `flags & 4` branch as a compiler/runtime guarded size-delete path through `0x0041b6a0` with size `0x108`. `RectangleControlPane.cpp` should express the class constructor, `OnPaint`, `HitTestPart`, and authored out-of-line ordinary destructor semantics; MSVC should regenerate the adjustor thunks and scalar deleting destructor from the class declaration.
- The exact [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) page records the primary RTTI/vtable span at `0x00618430-0x00618498`, the secondary RTTI/vtable span at `0x00618498-0x006184c8`, and the tertiary RTTI/vtable span at `0x006184c8-0x006184d4`, bounded by `NumericStringControlPane` before it and `CheckBoxControlPane` after it.
- Vtable reconstruction should come from the class declaration and inherited pane/control interfaces. The secondary and tertiary deleting-destructor slots are compiler-generated adjustor thunk entries, not handwritten source bodies for this file.

## Destructor Source Order And Emission Boundary

- The exact local function order is constructor `0x00499c60-0x00499cd2`, ordinary destructor `0x00499ce0-0x00499cff`, and OnPaint `0x00499d00-0x00499d37`. Fourteen and one byte of internal `0xcc` alignment separate the bodies; nine trailing `0xcc` bytes close the island.
- UID0004HL has no direct start xref, raw pointer, vtable slot, or constructor-EH route. Constructor cleanup reaches inherited Pane teardown through `0x005fd191 -> 0x00421370 -> 0x00544580` and bypasses the ordinary function.
- Same-family CheckBoxControlPane supplies the compiler comparator: it has equivalent three-view RTTI/vtables and a deleting wrapper but no standalone ordinary destructor in its local source island. Rectangle's standalone body therefore reflects authored source rather than mandatory ABI glue.
- The strongest source-unit shape is an explicitly authored out-of-line empty destructor between the constructor and OnPaint definitions. Historical implicit/default/inline uncertainty is retained only as superseded provenance; C++11 defaulted spelling and non-empty explicit compiler operations are rejected.
- `RectangleControlPane.cpp` emits UID00011P, UID0004HL, and UID00011R exactly once through their method pages. UID00011Q, UID000125, UID000122, and vtable data/type pages remain non-method or compiler-generated support and must not emit duplicate bodies.
- File score is now `94/95`; reconstruction path `NexusTK/ui/controls/` and generic-control ownership remain unchanged.

## Surface Fill Dependency And Source Closure

- The exact paint call is a process-global function-pointer dispatch, not a C++ member call. At `0x00499d00-0x00499d37`, the body calls `GetBounds(&bounds)`, reloads the RectangleControlPane receiver into `ecx`, pushes `&bounds`, and executes `call dword ptr ds:0x0069b3fc`. This preserves the observed thiscall-style ABI exactly.
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) owns slot 7 as `SurfaceFillRectProc g_pfnFillRect`; [UID:0000OC][Surface](by-file/Surface.md) emits the single definition in `Surface.cpp` and the `SurfaceFillRectProc` typedef plus single `extern g_pfnFillRect` declaration in `Surface.h`.
- The source-facing method body must therefore call `g_pfnFillRect(this, &bounds)`. `RectangleControlPane` is GrafPort-derived, so the receiver satisfies the callback's `GrafPort *` parameter; `RectBounds *` converts to the declared `const RectBounds *` parameter without changing the binary call shape.
- `RectangleControlPane.cpp` must include its sibling `RectangleControlPane.h` first and `../../render/Surface.h` second before child expansion. The relative route follows the settled `NexusTK/ui/controls/RectangleControlPane.cpp` placement to the existing `NexusTK/render/Surface.h` declaration owner.
- [UID:0000JR][GrafPort](by-file/GrafPort.md) and the current generated inheritance headers expose inherited `GetBounds` and `SetDrawColor`, but no callable `GrafPort::FillRect`. A member wrapper would invent an undeclared source API and conceal the literal global-slot dispatch, so that alternative is rejected rather than deferred.
- The complete `RectangleControlPane.h` declaration remains unchanged: no Surface include, callback typedef, global extern, new member, or forward declaration belongs in this class header. The dependency is implementation-only and stays in the CPP preamble.
- Surface remains dependency owner only. This edge does not move RectangleControlPane, alter UID0000N1/UID0000BT ownership, duplicate the Surface definition, or create another callback-table emitter. MiniMap remains the sole ordinary class consumer rather than a source owner.
- The prior `FillRect(&bounds)` spelling is retained only as historical descriptive shorthand. It was behaviorally suggestive but not source-closed because no inherited generated header declared that member. The direct global spelling closes the callable dependency while preserving exact behavior.
- Score `94/95` remains appropriate after this bounded correction: class/file inventory, ownership, layout, source order, compiler exclusions, and behavioral identity were already exact, and the remaining lexical uncertainty is limited to stripped original names rather than an unresolved callable. It should not be raised above the final-code barrier solely for this dependency repair.

## Cross-References

- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md)
- [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md)
- [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md)
- [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md)
- [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md)
- [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md)
- [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md)
- [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0000OC][Surface](by-file/Surface.md)

## 2026-08-16 B006 Whole-File Completion

Exact source order and emission ownership:

| Position | UID | Source contribution |
| ---: | --- | --- |
| 10 | UID0000BT | CPP include/preamble plus complete `RectangleControlPane.h` class declaration |
| 20 | UID00011P | `RectangleControlPane(int,const RectBounds *)` definition |
| 30 | UID0004HL | authored out-of-line empty `~RectangleControlPane()` definition |
| 40 | UID00011R | `OnPaint()` definition |
| 50 | UID000128 | `HitTestPart(int,int)` definition returning `21` |

The complete object is `0x108` bytes. Rectangle adds no data members: the constructor uses inherited draw-color state, and no authored method reads or writes a derived field. RTTI complete-object locators and vptr stores identify the complete, EventHandler, and TimerHandler views at offsets `0`, `0xA0`, and `0xA4`.

The authored inventory is exactly four definitions. The exact core boundaries are constructor `[0x00499c60,0x00499cd2)`, fourteen bytes of `0xCC` alignment, ordinary destructor `[0x00499ce0,0x00499cff)`, one byte of alignment, OnPaint `[0x00499d00,0x00499d37)`, and nine trailing alignment bytes. UID000122 contains only the two eleven-byte `this-0xA0`/`this-0xA4` deleting-destructor adjustors. UID000125 is only the 85-byte MSVC scalar deleting wrapper for a `0x108`-byte object. UID0002OE/UID0003IT are compiler-emitted vtable/RTTI evidence. None of those compiler products may emit handwritten source.

The vtable data range `[0x00618430,0x006184d4)` is 164 bytes and contains 25 primary slots, 11 secondary slots, and 2 tertiary slots. Primary slots route scalar deletion through `0x0049b490`, OnPaint through `0x00499d00`, and HitTestPart through `0x0049b8f0`; secondary/tertiary deletion routes use `0x0049afc1` and `0x0049afcc`. COL offsets are `0/0xA0/0xA4`, and the seven-base hierarchy is RectangleControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler.

The sole ordinary constructor call is `0x0045252c` in the MiniMap dialog cluster. That route confirms use but not ownership. No other Rectangle-authored function, source-owned global/static/constant/table/string/resource/import, or third-party embed was found. NumericStringControlPane before the vtable range and CheckBoxControlPane after it are boundary evidence, not file members.

Expected generated completion is one CPP containing `#include "RectangleControlPane.h"`, `#include "../../render/Surface.h"`, and exactly four authored definitions in the order above. `OnPaint` must call `g_pfnFillRect(this, &bounds)` directly after `GetBounds(&bounds)`. The one H contains the complete unchanged class declaration. There must be no class, HitTestPart, vtable-data, or vtable-type empty-emitter marker, no emitted scalar wrapper/adjustor/vtable body, and no placeholder, stub, or TODO.

Historical correction: earlier pages called UID000128 a type-id helper and left the standalone-versus-fold question open. The `retn 8` ABI and named same-slot siblings settle the method as `HitTestPart(int,int)`, while the complete source topology supports the standalone file. Exact original lexical names and debug file records remain unavailable, which caps confidence rather than preserving raw/decompiler names in final source.

## Changes

- 2026-08-16 B006 Surface dependency closure callback:
  - Replaced the unsupported member-wrapper shorthand with the exact direct-global slot-7 call and documented its ECX receiver, bounds-pointer argument, declaration owner, and required relative CPP include.
  - Rejected a new GrafPort member from current header and binary evidence, preserved the Rectangle header unchanged, and retained Surface as dependency rather than class/file owner.
  - Kept `94/95`, standalone `ui/controls/` placement, complete authored/compiler inventory, all historical corrections, and no-duplicate-emitter policy unchanged.

- 2026-07-14 B001 UID0004HL source-quality callback:
  - Preserved file score/path and all unrelated constructor, paint, type-id, vtable, and ownership detail.
  - Replaced empty/default wording with the authored out-of-line ordinary destructor disposition and added exact source order, alignment, no-route/EH evidence, same-family comparator, compiler emission boundary, rejected alternatives, and historical treatment.

- 2026-07-05 B001 implementation callback for `00011Q-RectangleControlPaneCore-source-quality.md`:
  - Linked the exact ordinary destructor child [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md).
  - Recorded that generated `RectangleControlPane.cpp` should get constructor, empty/default destructor, and paint method bodies from exact children, while [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md) remains a non-emitting grouping page.
- 2026-06-21 B007 scalar deleting destructor Rule 26 incorporation:
  - No file score change. Updated the ordinary destructor helper endpoint from `0x00499cfe` to half-open `0x00499cff`, changed the scalar deleting destructor row to no-code compiler wrapper wording, and documented that `RectangleControlPane.cpp` should express class/ordinary destructor semantics while the compiler regenerates the adjustor thunks and scalar deleting destructor.
  - Evidence incorporated: [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) has primary vtable and adjustor-thunk reachability only, calls [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md) teardown and [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md), preserves the scalar-delete flag behavior, and contains no Rectangle-specific handwritten cleanup.
- 2026-06-21 B010 scalar deleting destructor Rule 26 recheck:
  - No file score change. Added the B010 local PE/Capstone proof for [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md): exact `0x55` wrapper body, nine-byte prepad, eleven-byte postpad, vtable/data pointer routes, secondary/tertiary `this` adjustor jumps, `Pane::~Pane()` base cleanup, normal MemoryMan-backed delete path, and the guarded size-delete path through `0x0041b6a0` with size `0x108`.
  - Source policy remains unchanged: do not hand-author a scalar deleting destructor function or keep an empty UID marker in generated `RectangleControlPane.cpp`; the ordinary class destructor declaration/default semantics now live on [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) as the source-facing representation.
- 2026-06-19 B005 paint implementation support update:
  - No file score change. Updated the paint proposed-content row and evidence notes to match [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md)'s accepted `86/90` first-draft C++ state.
  - Evidence incorporated: `OnPaint` as best current source-facing name with unresolved `Paint` alternate, vtable-only reachability at `0x00618478`, inherited Pane `+0x44` bounds copy through `0x004b8e00`, `FillRect` over [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `0x0069b3fc`, rejection of generated invalidation wording, and retention of `ui/controls/RectangleControlPane.cpp` as the file route.
- 2026-06-19 B004 constructor source-quality implementation support update:
  - No file score change. Updated the file role, proposed contents, and evidence notes to match [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md)'s accepted first-draft constructor C++.
  - Evidence incorporated: `ControlPane(8, bounds)` base setup, `SetDrawColor(drawColor)` as the source-facing wrapper for inherited field write `this+0x74`, Rectangle vtable stores as compiler output, sole MiniMapDialog consumer call at `0x0045252c`, and class/file source route through `NexusTK/ui/controls/RectangleControlPane.cpp`.
- 2026-06-12 A004 Batch 331:
  - No score change. Added exact source-local vtable type child [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) as the type-level owner under [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md); the mixed [UID:0001YA][NumericRectangleControlPaneVtables](by-type/by-vtable/NumericRectangleControlPaneVtables.md) aggregate is now non-emitting.
- 2026-06-06 A008 vtable-data consistency pass:
  - Before: the file page referenced the shared vtable type page and method refs, but did not list the exact `0x00618430-0x006184d4` RectangleControlPane `.rdata` child or its neighboring boundaries.
  - After: raised from `84/86` to `86/88`, added the exact vtable-data child to proposed contents and cross-references, and documented source-declared/generated-binary handling for primary/secondary/tertiary vtable views.
  - Evidence: [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) records the RTTI pointers, decorated vtable globals, constructor/destructor vptr stores, paint/type-id table refs, and `NumericStringControlPane`/`CheckBoxControlPane` boundaries.
- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented rectangle-control constructor anchor at `0x00499c60`; proposed-source-tree groups this fixed visual control with reusable UI controls beside `NumericStringControlPane.cpp`.
- 2026-06-05 A004 live refresh:
  - Before: the file page still carried recovered-source provenance and stale external-tool caveats, and it omitted the local non-deleting destructor helper.
  - After: raised from `82/78` to `84/86`, removed stale provenance, added the `0x00499ce0` helper, and refreshed evidence for constructor/paint/destructor/type-id behavior.
  - Evidence: live IDA confirms function sizes, constructor caller, vtable refs, color setter, bounds/draw callback path, type-id constant, adjustor thunk routing, and generic source-file placement.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents class role, proposed contents, ownership decision, IDA/vtable evidence, constructor caller, and cross-references; confidence remains capped by final split into standalone control file versus broader primitive-control grouping.
