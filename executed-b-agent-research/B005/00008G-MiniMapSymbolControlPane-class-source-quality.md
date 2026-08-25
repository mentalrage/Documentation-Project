** TARGET-REPORT-UID:00008G **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00008G - MiniMapSymbolControlPane Class Source-Quality Report

## Verdict

Recommended target metadata after implementation:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `0000LE` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000LE` |
| `RECONSTRUCTION_CPP` | keep blank |

`MiniMapSymbolControlPane` should stay owned and emitted through [UID:0000LE][MiniMap](../../../by-file/MiniMap.md). The current `85/86` page is materially under-documented: it omits the real `0x004560f0-0x00456175` method, does not resolve the timer-secondary-subobject pollution, and does not name or bound the EPF/palette/label/frame/center fields well enough for later source work.

I recommend `88/90`, not merely `85/85`, because exported function evidence, current support docs, generated coverage, and the MiniMapDialog caller bodies now support a complete class method inventory, a better source-facing name for the omitted setter, and a high-confidence source route. I do not recommend higher than `88/90` because exact inheritance/base declarations and the x/y field-offset order for the center pair remain insufficient for class-level C++.

Class-level first-draft C++ is not ready. The class page should remain an emitting marker with blank formal C++ until the base layout and center-field order are finalized. Future code should be placed in exact method child pages, especially the missing `0x004560f0-0x00456175.MiniMapSymbolControlPaneSetCenterPosition.md` child, not as a monolithic class body.

## Evidence Re-read

Target and owner/support docs re-read for this pass:

- [UID:00008G][MiniMapSymbolControlPane](../../../by-class/MiniMapSymbolControlPane.md)
- [UID:0000LE][MiniMap](../../../by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](../../../by-class/MiniMapDialog.md)
- [UID:00008F][MiniMapRenderer](../../../by-class/MiniMapRenderer.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](../../../by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)
- [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](../../../by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md)
- [UID:0000XT][0x006104f4-0x006108d4.MiniMapUiReadOnlyData](../../../by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md)
- [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md)
- [UID:0001QU][client_timing](../../../by-meta/client_timing.md)
- [UID:00037U][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0000K2][g_pEPFLib](../../../by-global/g_pEPFLib.md)
- [UID:0000MB][g_pPaletteLib](../../../by-global/g_pPaletteLib.md)
- [UID:00004I][EPFTileContext](../../../by-class/EPFTileContext.md)
- [UID:00004G][EPFImageControlPane](../../../by-class/EPFImageControlPane.md)
- [UID:0000XO] B007 report `tools/leaser/Agents/Agent-B007/research/0000XO-MiniMapRendererAndControls-source-quality.md`
- `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`
- Generated rows in `auto-generated/-ag-class-coverage.md`, `by-class/-coverage-report.md`, `project-level/-auto-completion-stats.md`, and `project-level/-unresolved.md`
- Exported function JSON for `0x004523d0`, `0x00452ea0`, `0x004540a0`, `0x00455e60`, `0x00456040`, `0x004560a0`, `0x004560f0`, `0x00456180`, `0x004562a0`, `0x004562f8`, `0x00456303`, `0x00456310`, and `0x004563b0`

B007's `0000XO` report is treated as a lead, not proof. The source-facing setter conclusion below is independently revalidated from exported function bodies, caller/callee lists, current support docs, and generated rows.

Generated state revalidated:

- `auto-generated/-ag-class-coverage.md` still lists [UID:00008G] as emitting through `auto-generated/NexusTK/map/MiniMap.cpp`, with no formal code.
- `project-level/-auto-completion-stats.md` still lists [UID:00008G] as `85/86`.
- `by-class/-coverage-report.md` still has the older `85% : strong` row and does not mention `0x004560f0`.
- `auto-generated/NexusTK/map/MiniMap.cpp` contains only the empty-emitter marker for [UID:00008G], so no class-level or monolithic C++ currently exists.

Scoped validator dry run:

> Executable block R001 was removed from this report and preserved verbatim in [00008G-MiniMapSymbolControlPane-class-source-quality-removed.md](00008G-MiniMapSymbolControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit `0`, `ok: 1`, dry run only. The output also reported stale unrelated registry noise for missing [UID:0002K8], and `stats_incremental_skip` because `--apply` was not used. No target write was performed.

## Current Metadata And Score Justification

Current target metadata is `COMPLETION:85`, `CONFIDENCE:86`, owner/emitter [UID:0000LE], reconstructable, and blank C++. That was enough for the parent gate, but it is not current source-quality standard.

Recommended `88/90` is justified by:

- The full symbol-control method island is now bounded, including the omitted active method `0x004560f0-0x00456175`.
- Constructor callers are four `MiniMapDialog::RenderSymbols` calls at `0x004526b1`, `0x004526e8`, `0x00452991`, and `0x00452bb2`.
- `StartAnimation` has one MiniMapDialog caller at `0x00452bc9` and schedules via [UID:00037U] `TimerHandler::ScheduleTimer` at `0x005975e0`.
- `0x004560f0` has one caller at `0x00452f4e` in `0x00452ea0`, immediately after `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9` and the analogous image-control position setter at `0x00452f3d`.
- `OnAnimationTick`, `OnDraw`, destructor thunks, scalar deleting destructor, and `GetControlType` are reached through MiniMapSymbolControlPane vtable slots in the `0x0061081c`, `0x00610884`, and `0x006108b4` vtable family.
- The EPF/palette collaborators are no longer raw globals: `DAT_0067a744` is [UID:0000K2] `g_pEPFLib`, `DAT_0067a7e0` is [UID:0000MB] `g_pPaletteLib`, and `0x005975e0` is the TimerHandler schedule wrapper, not FittingRoom code.

Remaining cap below 90/92:

- The exact original inheritance spelling is not final. The object clearly combines a pane/control base with a TimerHandler-compatible secondary subobject at offset `+0xa4`; decompilers still mislabel that subobject as `FittingRoomDialog` in timer calls.
- The source field names for the center coordinate pair are resolved semantically, but the exact offset-to-x/y mapping needs a child-level check before field declarations are emitted.
- Existing docs do not yet have exact child pages for the individual methods, so source-ready methods cannot be emitted in the correct place.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Keep direct owner/emitter [UID:0000LE][MiniMap](../../../by-file/MiniMap.md). The source route should be the MiniMap feature file family under `map/`, likely beside `MiniMapDialog` and `MiniMapRenderer`.

Evidence:

- Constructor and animation start are called from [UID:00008C] `MiniMapDialog`.
- The class consumes MiniMap-specific resources: `MNSYMBOL.EPF`, `MNSYMBOL.PAL`, `MNPLAYER.EPF`, and `MNPLAYER.PAL`, with `BARAM.PAL` as the constructor fallback palette.
- Proposed source tree places `MiniMapDialog`, `MiniMapRenderer`, `MiniMapImageControlPane`, `MiniMapSymbolControlPane`, `MiniMapButtonPane`, `MiniMapDownloader`, and `MiniMapVersionManager` under `map/MiniMap*.cpp`.
- `MiniMapRendererAndControls` already groups this class with the MiniMap renderer/image-control island.

Rejected owners:

- `TimerHandler` / `TimerMgr`: only provide callback scheduling. They do not own the minimap sprite, label, EPF, palette, or dialog call sites.
- `EPFImageControlPane` / `EPFTileContext`: provide comparable resource-loading/rendering helpers. The symbol-control class has MiniMapDialog construction and MiniMap resources.
- `PaletteLib` / `EPFLib`: global resource libraries only.
- `FittingRoomDialog` or fitting-room controls: decompiler pollution from shared pane/timer helpers. No construction/caller/resource evidence routes this class to fitting-room source.
- `MiniMapRenderer`: renderer support explains coordinate updates but the class is constructed and owned by MiniMapDialog symbol-rendering logic, not by renderer instance methods.
- `MiniMapDialog` as the direct file owner: dialog construction is the strongest caller evidence, but the file-level source route is the MiniMap feature module, not a dialog-only file, until the final source split is known.

### Method Inventory And Split

Recommended target method table:

| Range | Source-facing method | Status |
| --- | --- | --- |
| `0x00455e60-0x00456031` | `MiniMapSymbolControlPane::MiniMapSymbolControlPane(...)` | Real source constructor. |
| `0x00456040-0x0045609e` | `MiniMapSymbolControlPane::~MiniMapSymbolControlPane()` | Real non-deleting destructor body. |
| `0x004560a0-0x004560e1` | `MiniMapSymbolControlPane::StartAnimation(int firstFrame, int lastFrame, int intervalMs)` | Real helper; schedules timer through `TimerHandler::ScheduleTimer`. |
| `0x004560f0-0x00456175` | `MiniMapSymbolControlPane::SetCenterPosition(int centerX, int centerY)` | Real helper omitted from current target; add it. |
| `0x00456180-0x00456293` | `MiniMapSymbolControlPane::OnAnimationTick(int timerId, int payload1, int payload2)` | Real timer callback, called through secondary TimerHandler vtable. |
| `0x004562a0-0x004562f8` | `MiniMapSymbolControlPane::OnDraw()` | Real draw method. |
| `0x004562f8-0x00456303` | adjustor thunk to scalar deleting destructor | Compiler-generated glue, no source body. |
| `0x00456303-0x0045630e` | adjustor thunk to scalar deleting destructor | Compiler-generated glue, no source body. |
| `0x00456310-0x004563af` | scalar deleting destructor | Compiler-generated deleting wrapper; document but do not emit source. |
| `0x004563b0-0x004563b5` | `MiniMapSymbolControlPane::GetControlType() const` | Real tiny vtable method returning `0x17`. |

The current target omits `0x004560f0-0x00456175`; `MiniMapRendererAndControls` also omits it. That omission creates an artificial gap between `StartAnimation` and `OnAnimationTick` and should be fixed in both docs.

### `0x004560f0-0x00456175` Name And Semantics

Preferred source-facing name: `SetCenterPosition`.

Evidence:

- Exported function JSON identifies `0x004560f0` as a real non-thunk method, size `0x88`, with one IDA xref at `0x00452f4e`.
- The body stores the two integer parameters into the class's center-position pair, derives a rectangle from the current EPF frame bounds, and dispatches the pane vtable slot `+0x2c`, which support docs identify as `Pane::SetBounds`.
- The only caller is MiniMapDialog method `0x00452ea0`. That caller first invokes `MiniMapRenderer::UpdateViewOriginFromPlayer` at `0x00452ee9`, computes display-space marker centers, calls image-control `0x0049a950` at `0x00452f3d`, then calls this symbol-control method at `0x00452f4e` with the same center-like coordinate pair.
- The analogous image-control helper `0x0049a950` treats its first argument as the horizontal anchor and second as the vertical anchor before building bounds, which supports `centerX, centerY` source wording for the symbol setter.
- `SetMapPosition` is rejected because the caller has already converted player/map state into display coordinates through the renderer view-origin calculation and minimap layout constants.
- `SetBounds` is rejected because the caller does not pass a rectangle and the method computes one from EPF frame dimensions.
- `MoveTo` / `SetPosition` remain plausible, but `SetCenterPosition` is more precise because the body subtracts half the current sprite dimensions before calling `SetBounds`.

Offset caveat:

- Constructor JSON stores the point-like constructor argument into `+0x210/+0x214`.
- Setter JSON stores the first setter argument at `+0x214` and the second at `+0x210`.
- The first setter argument also feeds the first `RectBounds::SetLTRB` coordinate, and the analogous image-control setter treats its first argument as horizontal. Therefore the best current field mapping is `+0x214 = m_centerX` and `+0x210 = m_centerY`, but implementation should document the mapping caveat instead of emitting a hard class declaration.

### Base Class And Timer Liveness

The timer helper source-facing name/liveness issue is resolved enough for documentation:

- `StartAnimation` writes `firstFrame`, `lastFrame`, `currentFrame`, and `intervalMs`, sets an animation-enabled byte, then calls `0x005975e0` with `this + 0xa4`.
- [UID:00037U] documents `0x005975e0` as `TimerHandler::ScheduleTimer`, forwarding to `TimerMgr`, with broad callers.
- `OnAnimationTick` is reached through a secondary vtable entry at `0x006108b8`, not through a direct call. Its `this` is adjusted to the timer subobject: IDA/Ghidra accesses such as `this + 0x15c`, `+0x160`, `+0x164`, `+0x168`, `+0x16c`, and `+0x170` correspond to full-object `+0x200`, `+0x204`, `+0x208`, `+0x20c`, `+0x210`, and `+0x214`.
- The `FittingRoomDialog::meth_0x5975e0` label is decompiler pollution over the generic TimerHandler wrapper. Do not carry any fitting-room owner or helper names into the target.

Best current signature:

```cpp
bool MiniMapSymbolControlPane::OnAnimationTick(int timerId, int payload1, int payload2);
```

The body checks that the pane is visible/active and that `timerId == 0`, advances the current frame with wraparound, reloads the EPF frame through `g_pEPFLib`, adjusts bounds if the frame rectangle changes, invalidates/redraws the control, reschedules the timer with `m_animationIntervalMs`, and returns true. `payload1`/`payload2` are unused by this class but belong to the TimerHandler callback shape.

### Constructor And Field Names

Best source-facing constructor signature:

```cpp
MiniMapSymbolControlPane(
    const wchar_t *label,
    int symbolType,
    const int *centerPosition,
    const wchar_t *epfFileName,
    short initialFrame,
    bool visible,
    const wchar_t *paletteName);
```

Field recommendations:

| Offset | Recommended name | Evidence and caveat |
| --- | --- | --- |
| `+0x108` | `m_tileContext` / `m_spriteContext` | Initialized by `0x00457a60`; consumed by EPF lookup/render callbacks; same shape as [UID:00004I] `EPFTileContext`. |
| `+0x118` to `+0x124` | EPF frame bounds | Filled by `g_pEPFLib->LookupLayoutEntry`; used for width/height and draw bounds. Use EPFTileContext field names once support names are final. |
| `+0x130` | `m_symbolType` | Constructor stores `a3`; MiniMapDialog passes `0`, `1`, or `2` for player/symbol/label-related marker cases. |
| `+0x134` | `m_symbolRecordId` | Constructor initializes `-1`; MiniMapDialog writes current `.mnm` record id after construction. |
| `+0x138` | `m_relatedObjectId` / `m_npcObjectId` | MiniMapDialog writes `pdVar11[0x11]` only for `m_symbolType == 1`, otherwise `-1`; exact source name remains record-layout dependent. |
| `+0x13c` | `m_epfFileName[0x20]` | Constructor `_wcscpy_s(..., 0x20, epfFileName)`; caller passes `MNSYMBOL.EPF` or `MNPLAYER.EPF`. |
| `+0x17c` | `m_initialFrame` / `m_resourceFrame` | Constructor stores `short initialFrame`; passed to `g_pEPFLib->LookupLayoutEntry`. |
| `+0x17e` | `m_paletteName[0x20]` | Constructor copies supplied palette or default `BARAM.PAL`; `OnDraw` resolves it through `g_pPaletteLib`. |
| `+0x1be` | `m_label[0x20]` | Constructor copies `label` with `_wcscpy_s(..., 0x20, label)`. |
| `+0x1fe` | `m_animationEnabled` | Constructor clears; `StartAnimation` sets to true. |
| `+0x200` | `m_firstFrame` | Constructor initializes to initial frame; `StartAnimation` writes first frame; tick wraps to it. |
| `+0x204` | `m_lastFrame` | Constructor initializes to initial frame; `StartAnimation` writes last frame; tick compares current frame against it. |
| `+0x208` | `m_currentFrame` | Constructor initializes to initial frame; `StartAnimation` resets to first frame; tick increments/wraps. |
| `+0x20c` | `m_animationIntervalMs` | Constructor clears; `StartAnimation` writes interval; tick reschedules with it. |
| `+0x210` | `m_centerY` candidate | Center-coordinate pair; setter evidence suggests this is the second coordinate, but constructor point order needs final child-level verification. |
| `+0x214` | `m_centerX` candidate | Center-coordinate pair; setter and image-control analogy make this the stronger first/horizontal coordinate candidate. |

Rejected names:

- `m_mapX/m_mapY`: caller passes display centers after view-origin conversion, not raw map tiles.
- `m_frameCount`: `+0x204` is not a count; it is compared as the last frame index.
- `m_timerId`: timer id is fixed `0` in schedule/tick checks; `+0x20c` is the delay/interval.
- `m_symbolName` for `+0x1be`: plausible, but `m_label` is safer because player labels and marker labels use the same buffer and text-control context.

### EPF, Palette, And Resource Helpers

Resolved helper/global names for target/support docs:

| Raw/decompiler name | Recommended source-facing name | Evidence |
| --- | --- | --- |
| `DAT_0067a744` / `dword_67A744` | `g_pEPFLib` | [UID:0000K2] global and constructor/tick calls to `0x004d02f0` resource lookup. |
| `0x004d02f0` | `ResourceLayout::LookupLayoutEntry` / `EPFLib::LookupLayoutEntry` | Existing [UID:0000K2] docs name this as the resource layout lookup. |
| `DAT_0067a7e0` / `dword_67A7E0` | `g_pPaletteLib` | [UID:0000MB] global and `OnDraw` palette lookup. |
| `0x00543d70` | `PaletteLib::FindLoadedPaletteIndex` candidate | Same palette lookup shape used by EPFImageControlPane. |
| `0x00457a60` | `EPFTileContext` constructor/init | [UID:00004I] tile context docs. |
| `0x00457ab0` | `EPFTileContext` post-draw/reset helper | Draw tail helper; exact source name remains support-level. |
| `0x00458500` | `EPFTileContext` cleanup/destructor helper | Destructor path cleanup. |
| `0x004b78d0` | `RectBounds::SetLTRB` | B001 RectBounds report and exported JSON; broad rectangle setter. |
| `0x004b7ed0` | `RectBounds` equality/changed predicate candidate | Tick snapshots the old bounds and only calls `SetBounds` when comparison returns false; exact support name remains open. |
| `0x00544bd0` / vtable slot `+0x2c` | `Pane::SetBounds` | Pane support report resolves this slot as bounds setter. |
| `dword_69B3FC` | render-target prep callback | Shared EPFImageControlPane draw callback; source name not final. |
| `dword_69B3E8` | EPF sprite render callback | Shared EPFImageControlPane draw callback; source name not final. |

Resource string decisions:

- `MNSYMBOL.EPF` and `MNSYMBOL.PAL` are MiniMap symbol resources used for non-player markers.
- `MNPLAYER.EPF` and `MNPLAYER.PAL` are player marker resources.
- `BARAM.PAL` is the constructor fallback palette when the palette argument is null.
- Truncated/interior IDA labels such as `MBOL.PAL` or `PLAYER.PAL` should not be promoted as source names. Support docs should describe them as interior labels unless the full-string start is proven in the read-only-data page.

### Vtables, Adjustors, And No-Code Boundaries

The class has three vtable stores in construction/destruction:

- Primary vtable at `0x0061081c`.
- Secondary adjusted vtable at `0x00610884`.
- Timer/callback adjusted vtable at `0x006108b4`, including the `OnAnimationTick` data reference at `0x006108b8`.

Compiler-generated ranges:

- `0x004562f8-0x00456303` adjusts `this - 40` and jumps/calls the scalar deleting destructor.
- `0x00456303-0x0045630e` adjusts `this - 41` and jumps/calls the scalar deleting destructor.
- `0x00456310-0x004563af` is a scalar deleting destructor with optional `operator delete` at `0x004f4ac0` and a guard check path. It should be documented as compiler glue, not emitted as source-authored class logic.

The current target caveat that `0x00456303` is "disabled but real" is correct; the refreshed target should make the half-open thunk ranges explicit.

### Open Questions That Remain

The following are investigated but not safely final:

- Exact original inheritance declaration: evidence supports a pane/control primary base and a TimerHandler-compatible secondary subobject at `+0xa4`, but the original class declaration and base order are not safe to emit.
- Exact `+0x210/+0x214` x/y offset order: setter evidence favors `+0x214 = centerX` and `+0x210 = centerY`, while constructor point-copy evidence still needs a focused child-page or point-struct check.
- Exact `+0x138` record-related field name: MiniMapDialog writes it only for symbol type `1`; final source name depends on `.mnm` record layout names from `MiniMapRenderer::BuildSymbolViews`.
- Exact callback names for `dword_69B3FC` and `dword_69B3E8`: support docs prove render-role usage but not original function-pointer names.

These open items lower the target from a potential `90+` and keep class-level C++ blank, but they do not block `88/90` documentation quality.

## C++ Readiness Decision

Class-level C++: not ready and should remain blank.

Reason:

- A class declaration would force unstable inheritance/base-subobject spelling and the x/y offset order for `+0x210/+0x214`.
- The page is a class-level owner marker. Per current project style, exact method bodies should live in by-memory method children once split.
- The scalar deleting destructor and adjustor thunks are compiler-generated and must not be represented as source-authored methods.

Exact future child pages that should carry code if a later split is authorized:

| Proposed child page | C++ policy |
| --- | --- |
| `by-memory/0x00455e60-0x00456031.MiniMapSymbolControlPaneConstructor.md` | Method-level first draft after base/field layout wording is stabilized. |
| `by-memory/0x00456040-0x0045609e.MiniMapSymbolControlPaneDestructor.md` | Method-level first draft can describe EPFTileContext cleanup and base destructor chaining. |
| `by-memory/0x004560a0-0x004560e1.MiniMapSymbolControlPaneStartAnimation.md` | Method-level first draft ready. |
| `by-memory/0x004560f0-0x00456175.MiniMapSymbolControlPaneSetCenterPosition.md` | Method-level first draft ready; use `SetCenterPosition` and document the center-field offset caveat. |
| `by-memory/0x00456180-0x00456293.MiniMapSymbolControlPaneOnAnimationTick.md` | Method-level first draft ready after TimerHandler callback signature is stated. |
| `by-memory/0x004562a0-0x004562f8.MiniMapSymbolControlPaneOnDraw.md` | Method-level first draft ready with provisional render-callback names. |
| `by-memory/0x004563b0-0x004563b5.MiniMapSymbolControlPaneGetControlType.md` | Method-level first draft ready; returns `0x17`. |

Do not create source-emitting children for `0x004562f8-0x0045630e` or `0x00456310-0x004563af`. If documented, they should be compiler-glue/no-formal-C++ pages.

Specific decision for `0x004560f0-0x00456175`: add it to the class and aggregate docs now as `SetCenterPosition`; do not leave it as `meth_0x4560f0`, `SetMapPosition`, or a generic bounds setter. The method is source-authored and child-code-ready, but the current report-only task should not create the child page.

## Exact Implementation Checklist

Target [UID:00008G] `by-class/MiniMapSymbolControlPane.md`:

1. Change metadata to `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged as `0000LE`, reconstructable `TRUE`, and formal C++ blank.
2. Update `Status` to say ownership/method inventory/timer/render behavior are strong, with remaining caveats limited to exact inheritance and center-offset ordering.
3. Add `0x004560f0-0x00456175` to the method table as `SetCenterPosition`.
4. Replace the old boundary caveats with explicit half-open ranges for both adjustor thunks, scalar deleting destructor, and padding/alignment gaps.
5. Add a field table using the names above, including the `+0x210/+0x214` caveat.
6. Add a timer/base subsection resolving `0x005975e0` to `TimerHandler::ScheduleTimer` and rejecting the FittingRoom decompiler label.
7. Add EPF/palette/global helper names: `g_pEPFLib`, `g_pPaletteLib`, `BARAM.PAL`, `MNSYMBOL.EPF`, `MNSYMBOL.PAL`, `MNPLAYER.EPF`, `MNPLAYER.PAL`, `RectBounds::SetLTRB`, and `Pane::SetBounds`.
8. Add a class-level no-code proof and list future child pages as above.
9. Add a 2026-06-20 change entry summarizing the B005 reanalysis and validator dry run.

Support docs to update:

1. `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`
   - Add row `0x004560f0-0x00456175 | MiniMapSymbolControlPane::SetCenterPosition | Stores the symbol center pair, rebuilds bounds from current EPF frame dimensions, and calls Pane::SetBounds.`
   - Add a short note that `0x00452f4e` is the sole exported caller.
   - Do not change aggregate score solely for this class update unless the supervisor is also applying B007's accepted aggregate report.
2. `by-class/MiniMapDialog.md`
   - In symbol/layout evidence, state that `0x00452ea0` updates renderer view origin through `0x004540a0`, then calls image-control position setter at `0x00452f3d` and `MiniMapSymbolControlPane::SetCenterPosition` at `0x00452f4e`.
   - Score unchanged.
3. `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`
   - Add the same caller note for `0x00452ea0` / `0x00452f4e`.
   - Score unchanged.
4. `by-class/MiniMapRenderer.md`
   - Add or cross-reference `0x004540a0-0x00454143` as `MiniMapRenderer::UpdateViewOriginFromPlayer`, because it is the direct setup call before the symbol center setter.
   - Score unchanged unless the renderer page receives a separate accepted implementation.
5. `by-file/MiniMap.md`
   - Update the MiniMap control list to say MiniMapSymbolControlPane includes constructor/destructor, `StartAnimation`, `SetCenterPosition`, `OnAnimationTick`, `OnDraw`, compiler thunk/deleting-destructor glue, and `GetControlType`.
   - Keep source split wording open: the final file may be compact `MiniMap.cpp` or split `MiniMapDialog.cpp`/`MiniMapRenderer.cpp` with private controls.
6. `by-memory/0x006104f4-0x006108d4.MiniMapUiReadOnlyData.md`
   - If not already explicit, clarify that `0x0061081c`, `0x00610884`, and `0x006108b4` are the MiniMapSymbolControlPane vtable family and that `0x006108b8` references `OnAnimationTick`.
   - Score unchanged.
7. Timer, EPF, palette, and EPFTileContext docs
   - No required metadata changes. The target should cite their existing names rather than duplicating raw names.

No edits should be made to `by-memory/-coverage-report.md` by the agent. For this class task, no by-memory child pages should be created unless the supervisor explicitly authorizes a split callback.

## Supervisor-Owned Coverage Row

Exact replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:00008G][MiniMapSymbolControlPane](by-class/MiniMapSymbolControlPane.md) : reconstructable : 88% : very-strong : B005 2026-06-20 source-quality reanalysis resolves the omitted `0x004560f0-0x00456175` method as `MiniMapSymbolControlPane::SetCenterPosition`, confirms MiniMap ownership through MiniMapDialog construction/update callers and MiniMap resources, separates TimerHandler secondary-subobject scheduling from polluted FittingRoom labels, documents EPF/palette/label/frame/center field candidates plus vtable/thunk/deleting-destructor boundaries, and keeps class C++ blank pending final base-layout and center-offset ordering while future exact method children carry code.
```

## Validator Commands For Later Implementation

Run after target/support edits:

> Executable block R002 was removed from this report and preserved verbatim in [00008G-MiniMapSymbolControlPane-class-source-quality-removed.md](00008G-MiniMapSymbolControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If validator reports generated stats or autogen changes are stale after the file passes:

> Executable block R003 was removed from this report and preserved verbatim in [00008G-MiniMapSymbolControlPane-class-source-quality-removed.md](00008G-MiniMapSymbolControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Post-validation inspection:

> Executable block R004 was removed from this report and preserved verbatim in [00008G-MiniMapSymbolControlPane-class-source-quality-removed.md](00008G-MiniMapSymbolControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated-output result after target-only implementation: `auto-generated/NexusTK/map/MiniMap.cpp` should still have [UID:00008G] as an empty-emitter marker unless exact method child pages are created in a separate authorized split.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00008G-MiniMapSymbolControlPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00008G"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00008G-MiniMapSymbolControlPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00008G-MiniMapSymbolControlPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00008G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
