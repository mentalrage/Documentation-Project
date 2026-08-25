** TARGET-REPORT-UID:0002D4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: FittingRoomScrollPane Draw / Hit / Timer

Assignment id: `B002-goal2-fittingroom-scrollpane-draw-hit-timer-source-quality-0002D4-0002D6-0002D8-20260618`

Agent: `Agent-B002`

Report-only status: no by-memory, by-class, by-file, generated source, generated reports, IDA DB, or coverage-report files were edited by this report. The only intended file change is this research report.

Primary targets:

- [UID:0002D4] `by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md`
- [UID:0002D6] `by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md`
- [UID:0002D8] `by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md`

Summary recommendation:

- Keep all three targets source-owned by [UID:000054] `FittingRoomScrollPane`, emitting through [UID:000054] into [UID:0000JE] `cashshop/FittingRoom.cpp`.
- Do not split these targets into a generic `ScrollBar` / `ui/core/ScrollBar.cpp` owner. Shared scrollbar art and shared drawing helpers are real, but the constructor/vtable route, class fields, fixed extent table, and FittingRoom-local source chain keep these methods under `FittingRoomScrollPane`.
- Populate first-draft C++ for all three targets under the current code-entry gate. The stale "below 95/95" wording should be removed.
- Update coverage rows for [UID:0002D4], [UID:0002D6], and [UID:0002D8]. Recommended scores:
  - [UID:0002D4] `COMPLETION: 89`, `CONFIDENCE: 91`
  - [UID:0002D6] `COMPLETION: 88`, `CONFIDENCE: 90`
  - [UID:0002D8] `COMPLETION: 88`, `CONFIDENCE: 90`
- Keep [UID:000054] and [UID:0000JE] scores unchanged unless the supervisor wants a separate class/file rescore pass after applying C++.

## Evidence Checked

Instruction and workflow files:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `project-documentation/by-structure.md`
- `project-documentation/inference_research.md`
- `project-documentation/by-project-structure/proposed-source-tree.md`

Primary target docs:

- [UID:0002D4] `project-documentation/by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md`
- [UID:0002D6] `project-documentation/by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md`
- [UID:0002D8] `project-documentation/by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md`

Accepted prior B002 interaction work:

- `tools/leaser/Agents/Agent-B002/research/executed/0002D2-0002D7-0002D5-0002D9-0002DB-FittingRoomScrollPaneInteraction-source-quality.md`
- Updated target pages for [UID:0002D2], [UID:0002D7], [UID:0002D5], [UID:0002D9], and [UID:0002DB]
- Updated support pages [UID:000054], [UID:0000JE], [UID:0002DA], [UID:0003AM], and [UID:0000JE]

Support docs checked:

- [UID:000054] `FittingRoomScrollPane`
- [UID:0000JE] `FittingRoom`
- [UID:0003AM] `FittingRoomReadOnlyData`
- [UID:0001K8] `TimerHandlerScheduleRemoveWrappers`
- [UID:00015S] `RectGeometryHelpers`
- [UID:0000XY] `EPFTileContext`
- [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry`
- [UID:000165] `SurfacePaintHelpers`
- [UID:000164] `GrafPortClipRectHelper`
- [UID:000162] `GrafPortDrawStateAccessors`
- [UID:0001PI] `SurfaceRenderCallbackTable`
- [UID:0001RK] `ranking-ui-resources`
- [UID:0001GI] generic `ScrollPane::OnDraw`
- [UID:0001GQ] `ScrollNewGroupPaneHitTestPart`

Generated output and coverage checked:

- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `project-documentation/by-memory/-coverage-report.md`
- `project-documentation/project-level/-unresolved.md`

Local PE/export evidence checked:

- `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- image base `0x00400000`
- `.text` section `0x00401000-0x0060c4ac`
- `.rdata` section `0x0060d000-0x0066c0be`
- `.data` section `0x0066d000-0x0069ce24`
- local decompiler export `NexusTK.exe.c`
- local listing/map exports for vtable/data/string labels around `0x0060dc78-0x0060ddff`

IDA MCP evidence status:

- Attempted a live MCP HTTP probe at `127.0.0.1:13337`; connection failed. This report therefore relies on target docs, accepted prior reports, local decompiler/listing/map exports, and direct PE byte/xref scans. No IDA database was edited.

## Binary / Xref Facts

[UID:0002D4] `0x0041da70-0x0041daa3`:

- Function boundary is isolated by `CC` padding before and after the body.
- No direct `rel32` code caller to `0x0041da70` was found in the PE scan.
- The only data route found is the vtable pointer at `.rdata:0x0060dd08`.
- The body is a small timer callback:
  - It tests the first argument / timer id against zero.
  - It reads `this[96]` on the adjusted `TimerHandler` receiver. Because the receiver is the embedded timer handler at object `+0xa4`, this byte is object field `+0x104`, the accepted `m_activePart`.
  - If active part is not `0xff`, it calls `0x0041e8b0` with `this - 0xa4`, which is [UID:0002D5] `FittingRoomScrollPane::ProcessActivePart`.
  - It then calls `0x005975e0` with `(this, 0, 30, 0, 0)`, matching [UID:0001K8] `TimerHandler::ScheduleTimer`.
  - It returns `1`.

[UID:0002D6] `0x0041dab0-0x0041e1c6`:

- Function boundary is isolated by `CC` padding after [UID:0002D4] and before [UID:0002D8].
- No direct `rel32` code caller to `0x0041dab0` was found.
- The only data route found is the draw virtual slot at `.rdata:0x0060dccc`.
- The method initializes an `EPFTileContext` stack object with `0x00457a60`, obtains a `GrafPort` clip rectangle with `0x004b96c0`, computes track/thumb rectangles from `FittingRoomScrollPane` fields, fills/clips track rectangles, looks up EPF frames through `0x004d02f0`, and renders them through `0x004b9980`.
- Direct helper calls inside the method include:
  - `0x00457a60` EPF/tile context initializer
  - `0x004a9090` cursor position query
  - `0x005447c0` pane screen offset/origin query
  - `0x0041e4f0` [UID:0002D7] `GetPartRect`, called for part `2` / thumb near the end
  - `0x004b7c50` rectangle initializer
  - `0x004b7cc0` rectangle intersection
  - `0x004b7e10` rectangle offset
  - `0x004b9660` draw color / GrafPort state setter
  - `0x004b96c0` `GrafPort::GetClipRect`
  - `0x004b9980` tile-frame renderer
  - `0x004d02f0` resource layout table lookup
- Resource string bytes in `.rdata` decode as:
  - `0x0060ddb0`: `SLIDEBG.EPF`
  - `0x0060ddc8`: `SLIDEBG.PAL`
  - `0x0060dde0`: `SCRBUTT.EPF`
  - `0x0060ddf8`: `BUTTON.PAL`
- IDA's `aBu` label is only a bad partial-string alias into `BUTTON.PAL`. It is not a source literal `"BU"` and should not be documented as a distinct resource.
- The fixed extent table at `0x0060dc78` is three 32-bit entries `{0x26, 0x26, 0x26}` and should continue to be named `kFittingRoomScrollPartExtentBySkin[3]`. The following dword at `0x0060dc84` is a different `.rdata` object, not a fourth extent entry.

[UID:0002D8] `0x0041e1d0-0x0041e4ed`:

- Function boundary is isolated by `CC` padding before [UID:0002D7].
- No vtable or static data pointer route was found for `0x0041e1d0`.
- Exactly two direct code callers were found:
  - `0x0041d951` from [UID:0002D2] `FittingRoomScrollPane::OnMouseEvent`
  - `0x0041e91f` from [UID:0002D5] `FittingRoomScrollPane::ProcessActivePart`
- The helper loops over part ids `0..4`, builds a candidate rectangle inline, tests it with `0x004b7e80` `PointInRect`, returns the first matching part, and returns `0xff` / `-1` for no match.
- It recomputes cursor/screen-origin context inside the loop. This is probably the compiler result of a source shape that reuses the same geometry code as `GetPartRect` or inlines a small part-rect builder. For source-level C++, a single local cursor/origin calculation before the loop is the cleaner source-facing form, but the formal block should still show inline rectangle construction rather than a simple `GetPartRect(...)` call-through.

## Heuristic / Inference Reanalysis And Validation

Timer receiver and signature:

- Best inference: [UID:0002D4] is a `TimerHandler` virtual invoked on the embedded handler at `FittingRoomScrollPane + 0xa4`, but the source-facing behavior belongs to `FittingRoomScrollPane::OnTimer`.
- Evidence:
  - The callback reads `this[96]`; adding the accepted timer-handler offset `0xa4` maps this to object field `+0x104`, already accepted as `m_activePart`.
  - The callback passes `this - 0xa4` into [UID:0002D5], proving the adjusted receiver is not the full pane object.
  - [UID:0001K8] documents `0x005975e0` as `TimerHandler::ScheduleTimer`; the call receives the adjusted timer-handler receiver directly.
  - The vtable-only data pointer at `0x0060dd08` supports callback/virtual reachability rather than direct call reachability.
- Source-facing signature recommendation:
  - Use `bool FittingRoomScrollPane::OnTimer(int timerId, int, int)` in the formal draft.
  - If the support framework wants the embedded receiver shown explicitly, document the emitted entry as `TimerHandler`-adjusted and source-owned by `FittingRoomScrollPane`.
- Rejected alternatives:
  - `EventHandler` receiver: rejected because the receiver adjustment and `ScheduleTimer` helper both match `TimerHandler`, not the mouse/event-handler base.
  - Standalone FittingRoom repeat helper: rejected because the helper is a broad 163-reference generic `TimerHandler::ScheduleTimer` wrapper documented by [UID:0001K8].
  - Timer id `30`: rejected. `30` is the delay/repeat interval argument passed to `ScheduleTimer`; the timer id/event id tested by the callback and rescheduled is `0`.
- Remaining uncertainty:
  - The exact framework names for the two unused trailing callback arguments are not recoverable from this target alone. They should remain unnamed or documented as unused payload parameters. This does not block first-draft C++.

Timer repeat helper naming:

- Best inference: source should call `m_repeatTimer.ScheduleTimer(0, 30, 0, 0)` or `m_timerHandler.ScheduleTimer(0, 30, 0, 0)`.
- Accepted field naming already records `+0xa4` as `m_repeatTimer` / `m_timerHandler`; `m_repeatTimer` is more behavior-specific for this class, while `m_timerHandler` is more type-literal. The target formal C++ can use `m_repeatTimer` and the class-layout support page can keep both as aliases.
- The 30 ms value should be documented as `kFittingRoomScrollRepeatDelayMs = 30` if constants are being named.

Draw resource selection:

- Best inference: [UID:0002D6] is a FittingRoom-local themed scrollbar draw method that reuses shared ranking/UI scrollbar art:
  - Track resource: `SLIDEBG.EPF`
  - Track palette: `SLIDEBG.PAL`
  - Thumb/button resource: `SCRBUTT.EPF`
  - Thumb/button palette: `BUTTON.PAL`
- Frame mapping inferred from call order and branch structure:
  - Vertical page-before track: repeating strip frame `1`, near/leading cap frame `0`
  - Vertical page-after track: repeating strip frame `1`, far/trailing cap frame `2`
  - Horizontal page-before track: repeating strip frame `4`, near/leading cap frame `3`
  - Horizontal page-after track: repeating strip frame `4`, far/trailing cap frame `5`
  - Thumb: `SCRBUTT.EPF` frame `0` normally, frame `1` when `m_hotPart == kFittingRoomScrollPartThumb`
- Evidence:
  - The resource strings are contiguous literal UTF-16 data in the FittingRoom scroll-pane `.rdata` neighborhood.
  - `0x004d02f0` calls carry the EPF name and frame index, followed by `0x004b9980` tile-frame rendering with the corresponding palette literal.
  - The thumb frame index is derived from `*(_BYTE *)(this + 259) == 2`, mapping to object field `+0x103` `m_hotPart` and enum value `2` `kFittingRoomScrollPartThumb`.
  - Track geometry uses field `+0xf8` to index `kFittingRoomScrollPartExtentBySkin[3]`, field `+0xfc` for vertical/horizontal orientation, and fields `+0xfe/+0x100/+0xfb/+0x108` for scroll position/range/thumb-drag geometry.
- Rejected alternatives:
  - `aBu` as a source string: rejected as IDA partial-string corruption; the complete literal is `BUTTON.PAL`.
  - `dword_60DC78` as a four-entry or mixed-purpose table: rejected because direct bytes show only three `0x26` dwords before a separate RTTI/COL-related pointer.
  - Ranking-specific owner: rejected because [UID:0001RK] confirms shared art resources, not source ownership. Resource sharing does not prove ranking source placement.
  - Generic `ScrollBar` owner: rejected below under source split.
- Remaining uncertainty:
  - The exact original names for the small drawing concepts are not recoverable from this target alone. Recommended descriptive names: `DrawScrollTrackSegment`, `DrawScrollTrackCap`, `DrawScrollThumb`, `kFittingRoomScrollTrackEpf`, `kFittingRoomScrollTrackPalette`, `kFittingRoomScrollThumbEpf`, and `kFittingRoomScrollButtonPalette`.
  - This uncertainty caps [UID:0002D6] below 95/95 but does not block a first-draft C++ body.

Draw helper names and types:

- Best source-facing helper names:
  - `0x00457a60`: `EPFTileContext::Initialize` or `InitTileContext`
  - `0x004b96c0`: `GrafPort::GetClipRect`
  - `0x004b9660`: `GrafPort::SetDrawColor` / `SetColor`
  - `dword_69B3FC`: `FillRect` / solid-rect presentation callback through the active surface/GrafPort
  - `0x004d02f0`: `ResourceLayoutTable::LookupLayoutEntry`
  - `0x004b9980`: `RenderTileFrame` / `Surface::RenderTileFrame`
  - `0x004b7cc0`: `IntersectRects`
  - `0x004b7e10`: `OffsetRect`
- These should be referenced as shared support helpers, not renamed into FittingRoom-specific functions.

Hit-test inline rectangle source shape:

- Best inference: [UID:0002D8] should be modeled as `FittingRoomScrollPane::HitTestPart(int x, int y)` returning `FittingRoomScrollPart`, with inline part-rectangle construction inside the method.
- Evidence:
  - The helper has two direct class-local callers and no vtable/data route.
  - It loops part ids `0..4` and returns `-1` / `0xff` when no part contains the point.
  - It uses the same fields and five-part enum accepted by the previous B002 interaction report.
  - It uses the same drag-aware thumb geometry as [UID:0002D7] `GetPartRect`, but it does not directly call `0x0041e4f0`.
- Source shape recommendation:
  - Do not populate a call-through-only draft such as `for (...) { GetPartRect(part, &rect); ... }`.
  - Use source-facing inline rectangle construction in the formal block. It may share comments/constants with `GetPartRect`, but the C++ should visibly build the leading/page-before/thumb/page-after/trailing rectangles in this target's body.
- Rejected alternatives:
  - Separate exported `ScrollBar::HitTestPart`: rejected because direct callers are FittingRoomScrollPane methods and no constructor/vtable route points at a shared generic class.
  - `GetPartRect` call-through as exact source: plausible as a high-level developer style, but contradicted by the current binary body and by the assignment's inline-rectangle source-shape requirement.
  - Treating `0xff` as a sixth scroll part: rejected. It is the signed/byte representation of `kFittingRoomScrollPartNone = -1`.
- Remaining uncertainty:
  - The decompiler's temporary field ordering for leading/trailing cap rectangles is hard to read because it uses packed vector temporaries. The accepted [UID:0002D7] part semantics, enum, and `PointInRect` use are sufficient for first-draft C++.

Source split / generic `ScrollBar` recheck:

- Best inference: keep [UID:0002D4], [UID:0002D6], and [UID:0002D8] under `FittingRoomScrollPane` in `cashshop/FittingRoom.cpp`.
- Evidence supporting FittingRoom-local ownership:
  - [UID:000054] documents the FittingRoomScrollPane constructor, vtable family, accepted field layout, event path, timer handler, and owner routing.
  - [UID:0002D4] and [UID:0002D6] are vtable-only through FittingRoomScrollPane vtables, not generic ScrollPane vtables.
  - [UID:0002D8] has only two direct callers, both already inside FittingRoomScrollPane interaction logic.
  - The fixed extent table `0x0060dc78` is in the FittingRoomScrollPane `.rdata` block and has been resolved as `kFittingRoomScrollPartExtentBySkin[3]`.
  - Generic [UID:0001GI] `ScrollPane::OnDraw` is much larger, owns a different vtable/data neighborhood, has classic and EPF render branches, uses its own constants, and calls generic `ScrollPane::GetScrollPartRect` repeatedly.
- Evidence that suggests shared idioms but not ownership:
  - FittingRoom and generic scroll-pane drawing both use `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, and `BUTTON.PAL`.
  - FittingRoom and ScrollNewGroupPane hit tests share a five-part scrollbar geometry pattern.
  - Shared art and repeated source idioms are consistent with copy/paste, inline helpers, or a local themed-scrollbar implementation, but they are insufficient to move these methods to a generic `ScrollBar` page without a non-FittingRoom constructor, vtable route, or direct caller route.
- Rejected alternatives:
  - Move targets to `ui/core/ScrollBar.cpp`: rejected for now.
  - Create a new shared `ThemedScrollBar` owner: not supported by current binary ownership evidence. It may be noted as a possible future source abstraction only if another class routes to the same constructor/vtable/data block.
  - Split [UID:0002D6] draw into separate child pages: not justified. The body is long but is a single virtual draw method and the internal helper calls already have support pages.

Validation or contradiction of current docs:

- Validated:
  - [UID:0002D4] is a timer callback with adjusted receiver and repeat scheduling.
  - [UID:0002D6] is the draw virtual for FittingRoomScrollPane.
  - [UID:0002D8] is a class-local hit-test helper.
  - [UID:000054] field aliases for `+0xf8`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, `+0x104`, and `+0x108` remain correct.
  - [UID:0003AM] `kFittingRoomScrollPartExtentBySkin[3]` is correct.
- Contradicted/stale:
  - Any "below 95/95" final-C++ gate wording is stale. The active gate is reconstructable, emitting owner present, and average completion/confidence above 85.
  - Any text treating `dword_60DC78` as unresolved is stale.
  - Any text treating `aBu` as a separate source literal is stale.
  - Any text describing generated output as zero-byte for FittingRoom is stale. `auto-generated/NexusTK/cashshop/FittingRoom.cpp` now exists and contains prior accepted interaction methods; these three targets simply still lack formal C++.
- Unresolved but non-blocking:
  - Exact original local helper names for draw-strip/cap concepts.
  - Exact framework parameter names for unused timer callback arguments.
  - Exact source spelling of rectangle axis helpers in [UID:0002D8].

Impact:

- Score/metadata: raise all three target rows modestly as listed above.
- Owner/emitter: unchanged, [UID:000054].
- Source placement: unchanged, `cashshop/FittingRoom.cpp` through [UID:0000JE].
- C++ readiness: all three should receive first-draft C++.

## First-Draft C++ Recommendation

All three targets satisfy the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS:000054`
- generated source route exists through `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- current and recommended average completion/confidence are above 85

The formal C++ blocks should be populated. Names below intentionally use source-facing aliases already accepted by the previous interaction report and support pages. The supervisor may adjust exact style to match nearby generated output.

### [UID:0002D4] `FittingRoomScrollPane::OnTimer`

Recommended formal C++:

```cpp
bool FittingRoomScrollPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kFittingRoomScrollPartNone) {
        ProcessActivePart();
        m_repeatTimer.ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}
```

Notes for supervisor:

- The emitted entry receives `this` as the embedded `TimerHandler` at pane offset `+0xa4`; the formal source-facing method should still be attached to `FittingRoomScrollPane`.
- `m_repeatTimer` may be replaced with `m_timerHandler` if the class support page standardizes on the type-literal name.
- If formal C++ wants an explicit constant, use `kFittingRoomScrollRepeatDelayMs = 30`.

### [UID:0002D6] `FittingRoomScrollPane::OnDraw`

Recommended formal C++:

```cpp
void FittingRoomScrollPane::OnDraw()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (m_scrollEnabled && m_scrollRange > 0) {
        const bool horizontal = (m_orientation != 0);

        for (int pass = 0; pass < 2; ++pass) {
            const FittingRoomScrollPart part =
                pass == 0 ? kFittingRoomScrollPartPageBeforeThumb
                          : kFittingRoomScrollPartPageAfterThumb;

            GetPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);

            const int fillFrame = horizontal ? 4 : 1;
            const int capFrame = horizontal
                ? (pass == 0 ? 3 : 5)
                : (pass == 0 ? 0 : 2);

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SLIDEBG.EPF",
                fillFrame,
                &tile);

            stripRect = drawRect;
            if (horizontal) {
                stripRect.right = stripRect.left + 1;
                while (stripRect.left < drawRect.right) {
                    RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                    OffsetRect(&stripRect, 1, 0);
                }
            } else {
                stripRect.bottom = stripRect.top + 1;
                while (stripRect.top < drawRect.bottom) {
                    RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                    OffsetRect(&stripRect, 0, 1);
                }
            }

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SLIDEBG.EPF",
                capFrame,
                &tile);
            RenderTileFrame(this, &tile, &drawRect, L"SLIDEBG.PAL");
        }

        GetPartRect(kFittingRoomScrollPartThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SCRBUTT.EPF",
                m_hotPart == kFittingRoomScrollPartThumb ? 1 : 0,
                &tile);
            RenderTileFrame(this, &tile, &drawRect, L"BUTTON.PAL");
        }
        return;
    }

    if (!m_scrollEnabled) {
        SetDrawColor(0);
        FillRect(&clipRect);
        SetDrawColor(128);
    }
}
```

Notes for supervisor:

- The draft uses `GetPartRect` for source clarity. The binary inlines most track rectangle calculation and calls [UID:0002D7] directly only for the thumb. This is acceptable for first draft because the target is reconstructable and the accepted support pages already tie the same geometry to [UID:0002D7]. If supervisor wants closer binary shape, replace the `GetPartRect` calls for page-before/page-after with local inline geometry copied from [UID:0002D7].
- The frame mapping and resource names should be preserved even if helper spellings are changed.
- `RenderTileFrame`, `FillRect`, `SetDrawColor`, and `ResourceLayoutTable::LookupLayoutEntry` are source-facing names backed by support pages. Exact function signatures may need to match generated support headers.
- `g_pResourceLayoutTable` names the global loaded through `dword_67A744`; if a project-standard name exists, use that name.
- The disabled branch is intentionally conservative. The binary has an additional byte gate at object `+0xfa` before filling the clip rect. If that field is already named in [UID:000054], substitute it; otherwise document it as a disabled/clear gate and leave score below 95/95.

### [UID:0002D8] `FittingRoomScrollPane::HitTestPart`

Recommended formal C++:

```cpp
FittingRoomScrollPart FittingRoomScrollPane::HitTestPart(int x, int y)
{
    Point cursor;
    Point origin;

    EventManager::GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.x == -1000 && origin.y == -1000) {
        return kFittingRoomScrollPartNone;
    }

    cursor.x -= origin.x;
    cursor.y -= origin.y;

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? (m_bounds.bottom - m_bounds.top)
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    const int trackStart = horizontal ? m_bounds.left + fixedExtent
                                      : m_bounds.top + fixedExtent;
    const int trackEnd = horizontal ? m_bounds.right - fixedExtent
                                    : m_bounds.bottom - fixedExtent;
    const int trackSize = trackEnd - trackStart;

    int thumbStart = trackStart;
    int thumbEnd = trackEnd;

    if (m_scrollEnabled && m_scrollRange > 0 && trackSize > 0) {
        const int thumbLimit = trackEnd - fixedExtent;
        if (m_thumbDragActive) {
            thumbStart = horizontal
                ? cursor.x - m_thumbDragOffset.x
                : cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart + (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        }
        thumbEnd = thumbStart + fixedExtent;
    }

    for (int partIndex = kFittingRoomScrollPartLeading;
         partIndex <= kFittingRoomScrollPartTrailing;
         ++partIndex) {
        RectBounds rect = m_bounds;
        const FittingRoomScrollPart part = static_cast<FittingRoomScrollPart>(partIndex);

        if (horizontal) {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.right = m_bounds.left + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.left = trackStart;
                rect.right = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.left = thumbStart;
                rect.right = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.left = thumbEnd;
                rect.right = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.left = m_bounds.right - fixedExtent;
                break;
            default:
                rect.left = rect.right = rect.top = rect.bottom = 0;
                break;
            }
        } else {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.bottom = m_bounds.top + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.top = trackStart;
                rect.bottom = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.top = thumbStart;
                rect.bottom = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.top = thumbEnd;
                rect.bottom = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.top = m_bounds.bottom - fixedExtent;
                break;
            default:
                rect.left = rect.right = rect.top = rect.bottom = 0;
                break;
            }
        }

        if (PointInRect(x, y, &rect)) {
            return part;
        }
    }

    return kFittingRoomScrollPartNone;
}
```

Notes for supervisor:

- This draft intentionally builds rectangles inline inside [UID:0002D8] instead of calling [UID:0002D7].
- If the project-standard `PointInRect` wrapper expects `(y, x, rect)` at the binary ABI, the source wrapper should still expose a natural `(x, y, rect)` call and perform the ABI ordering internally.
- The source draft computes cursor/origin once. The binary repeats the calls inside the loop, likely from inlined helper code. This difference is not behaviorally significant for first-draft source unless the project wants exact side-effect order modeled.

## Exact Supervisor Edits

### [UID:0002D4] target doc edits

Recommended metadata replacement:

```text
COMPLETION: 89
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Replace stale final-C++ gate wording with:

```text
Formal C++ recommendation: populate the final block. This target meets the active code-entry gate: RECONSTRUCTABLE:TRUE, nonblank emitting owner [UID:000054], and average completion/confidence above 85. The body is a TimerHandler-adjusted virtual entry for the embedded handler at FittingRoomScrollPane +0xa4; the source-facing method is FittingRoomScrollPane::OnTimer(int timerId, int, int).
```

Insert or replace source-shape note with:

```text
Source-facing behavior: if timerId is 0 and m_activePart (+0x104, reached as this[96] on the TimerHandler-adjusted receiver) is not kFittingRoomScrollPartNone/0xff, call ProcessActivePart() on the containing FittingRoomScrollPane and reschedule the embedded repeat timer with ScheduleTimer(0, 30, 0, 0). Return true. The 30 value is the repeat interval/delay argument, not the timer id.
```

Recommended final C++ block: use the [UID:0002D4] block from `## First-Draft C++ Recommendation`.

### [UID:0002D6] target doc edits

Recommended metadata replacement:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Replace stale final-C++ blocker text with:

```text
Formal C++ recommendation: populate the final block. The old "below 95/95" gate text is stale under the active supervisor rule. Remaining unresolved items are exact local draw-helper spellings and exact disabled-clear flag naming; they cap the target below 95/95 but do not block first-draft source.
```

Replace unresolved table/resource wording with:

```text
Resource and table resolution: dword_60DC78 is resolved as kFittingRoomScrollPartExtentBySkin[3] = {38, 38, 38}, indexed by m_scrollSkinIndex (+0xf8). The following dword at 0x0060dc84 is not a fourth table entry. The draw resources are UTF-16 literals in the FittingRoomScrollPane .rdata block: SLIDEBG.EPF, SLIDEBG.PAL, SCRBUTT.EPF, and BUTTON.PAL. IDA's aBu label is a partial-string artifact inside BUTTON.PAL and should not be documented as a source literal.
```

Insert source-shape note:

```text
Source-facing draw shape: initialize an EPFTileContext, obtain the current GrafPort clip rectangle, draw page-before and page-after track regions with SLIDEBG.EPF/SLIDEBG.PAL, then draw the thumb with SCRBUTT.EPF/BUTTON.PAL. Track frame mapping is vertical before {fill 1, cap 0}, vertical after {fill 1, cap 2}, horizontal before {fill 4, cap 3}, horizontal after {fill 4, cap 5}. Thumb frame is 1 when m_hotPart (+0x103) is kFittingRoomScrollPartThumb, otherwise 0.
```

Insert source-placement note:

```text
Source placement remains FittingRoomScrollPane in cashshop/FittingRoom.cpp. Shared SLIDEBG/SCRBUTT art and shared GrafPort/resource helpers do not justify moving this target to generic ScrollBar.cpp. Generic ScrollPane::OnDraw has a different vtable/data neighborhood, a larger classic+EPF branch structure, and a separate generic owner route.
```

Recommended final C++ block: use the [UID:0002D6] block from `## First-Draft C++ Recommendation`, with helper spellings adjusted to project-standard support declarations.

### [UID:0002D8] target doc edits

Recommended metadata replacement:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 000054
EMITTER_UIDS: 000054
```

Replace stale final-C++ blocker text with:

```text
Formal C++ recommendation: populate the final block. The old gate wording and "pending inline rectangle rewrite" blocker are stale. The method should be represented as a class-local inline rectangle hit test returning FittingRoomScrollPart, not as a generic ScrollBar method and not as a call-through-only wrapper around GetPartRect.
```

Insert source-shape note:

```text
Source-facing hit-test shape: loop over FittingRoomScrollPart values 0..4, build the candidate part rectangle inline from m_bounds, m_orientation (+0xfc), m_scrollSkinIndex (+0xf8), m_scrollPosition (+0xfe), m_scrollRange (+0x100), m_scrollEnabled (+0x102), m_thumbDragActive (+0xfb), and m_thumbDragOffset (+0x108), then return the first part whose rectangle contains the point. Return kFittingRoomScrollPartNone/-1/0xff if no part matches.
```

Insert caller/reachability note:

```text
Reachability: exactly two direct callers are expected, FittingRoomScrollPane::OnMouseEvent at 0x0041d951 and FittingRoomScrollPane::ProcessActivePart at 0x0041e91f. No vtable or static data route was found for 0x0041e1d0. This is a class-local helper under [UID:000054].
```

Recommended final C++ block: use the [UID:0002D8] block from `## First-Draft C++ Recommendation`.

### [UID:000054] `FittingRoomScrollPane` support edits

Add a source-quality subsection near the existing interaction/helper notes:

```text
Draw/timer/hit-test source-quality update:

- The embedded TimerHandler at +0xa4 is the adjusted receiver for the timer vtable entry [UID:0002D4]. Source-facing FittingRoomScrollPane::OnTimer checks timer id 0, gates on m_activePart (+0x104) != kFittingRoomScrollPartNone, calls ProcessActivePart(), and reschedules the repeat timer with ScheduleTimer(0, 30, 0, 0).
- The draw virtual [UID:0002D6] uses FittingRoomScrollPane-local fields and FittingRoom .rdata resources. SLIDEBG.EPF/SLIDEBG.PAL draw track/page regions; SCRBUTT.EPF/BUTTON.PAL draw the thumb. Track frame mapping is vertical before {1,0}, vertical after {1,2}, horizontal before {4,3}, horizontal after {4,5}; thumb frame is selected by m_hotPart == kFittingRoomScrollPartThumb.
- The hit-test helper [UID:0002D8] is a direct-call class-local helper. It builds candidate part rectangles inline for the five FittingRoomScrollPart values and returns kFittingRoomScrollPartNone for no hit.
- Generic ScrollBar source ownership remains rejected for this class until a non-FittingRoom constructor/vtable route is found. Shared scrollbar art and shared GrafPort/resource helper usage are support evidence only, not ownership evidence.
```

Recommended score change for [UID:000054]: none required by this report. If supervisor chooses to rescore after populating C++, a modest class confidence increase may be defensible, but the target-specific row changes are sufficient.

### [UID:0000JE] `FittingRoom` support edits

Add or merge into the existing FittingRoomScrollPane source-placement note:

```text
FittingRoomScrollPane draw/timer/hit-test methods [UID:0002D4], [UID:0002D6], and [UID:0002D8] continue to emit through FittingRoomScrollPane into cashshop/FittingRoom.cpp. The accepted interaction report plus this draw/hit/timer reanalysis reject a generic ScrollBar.cpp reroute for now: the relevant vtable entries, direct callers, fixed extent table, and constructor/source chain are FittingRoom-local even though the art resources and helper APIs are shared.
```

Recommended score change for [UID:0000JE]: none.

### [UID:0003AM] `FittingRoomReadOnlyData` support edits

If not already present at equal or greater detail, add:

```text
0x0060dc78 is kFittingRoomScrollPartExtentBySkin[3] = {38, 38, 38}. It is used by FittingRoomScrollPane draw, get-part-rect, update-drag, and hit-test logic as the fixed vertical part/thumb extent indexed by m_scrollSkinIndex (+0xf8). The following dword at 0x0060dc84 belongs to the next .rdata object and is not part of this table.
```

Recommended score change for [UID:0003AM]: none if this is already recorded.

### [UID:0001RK] resource support edits

If not already present at equal or greater detail, add:

```text
FittingRoomScrollPane::OnDraw [UID:0002D6] consumes the shared scrollbar resources SLIDEBG.EPF, SLIDEBG.PAL, SCRBUTT.EPF, and BUTTON.PAL. This is resource-sharing evidence only; ownership remains with FittingRoomScrollPane because the constructor/vtable/field route is FittingRoom-local.
```

Recommended score change for [UID:0001RK]: none.

### [UID:0001GI] generic `ScrollPane::OnDraw` support edits

If a comparison note is useful, add:

```text
Do not use FittingRoomScrollPane::OnDraw [UID:0002D6] as proof that generic ScrollPane::OnDraw owns the FittingRoom scrollbar code. Both methods share SLIDEBG/SCRBUTT art and shared rendering helpers, but the generic ScrollPane draw method has a separate vtable/data neighborhood, different constants, and additional classic/EPF branch structure. FittingRoomScrollPane remains a class-local themed scrollbar implementation unless a non-FittingRoom route is found.
```

Recommended score change for [UID:0001GI]: none.

### Project unresolved cleanup

Remove or revise stale unresolved entries that still present `dword_60DC78`, `aBu`, stale "zero-byte generated output", or stale "below 95/95" final-C++ gate language for [UID:0002D4], [UID:0002D6], and [UID:0002D8]. Replacement substance:

```text
The former FittingRoomScrollPane blockers for dword_60DC78 and aBu are resolved. dword_60DC78 is kFittingRoomScrollPartExtentBySkin[3] = {38,38,38}; aBu is an IDA partial-string artifact inside BUTTON.PAL. The active C++ gate is average completion/confidence above 85 with a valid emitter, so [UID:0002D4], [UID:0002D6], and [UID:0002D8] should receive first-draft C++.
```

## Coverage Row Recommendation

Supervisor-owned file: `project-documentation/by-memory/-coverage-report.md`

Replace the existing [UID:0002D4] row with:

```text
- [UID:0002D4](0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md) 0x0041da70-0x0041daa3 | method | FittingRoomScrollPaneOnTimer : reconstructable : 89% : very strong : B002 source-quality reanalysis resolves the TimerHandler-adjusted receiver at FittingRoomScrollPane +0xa4, source-facing OnTimer signature, timer id 0 active-part gate, ProcessActivePart call, generic TimerHandler::ScheduleTimer(0,30,0,0) repeat, vtable-only reachability through 0x0060dd08, and first-draft C++ readiness under the active combined-score gate; exact unused callback payload parameter names remain descriptive.
```

Replace the existing [UID:0002D6] row with:

```text
- [UID:0002D6](0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) 0x0041dab0-0x0041e1c6 | method | FittingRoomScrollPaneOnDraw : reconstructable : 88% : very strong : B002 source-quality reanalysis resolves FittingRoomScrollPane-local draw ownership, SLIDEBG.EPF/SLIDEBG.PAL track resources, SCRBUTT.EPF/BUTTON.PAL thumb resources, vertical/horizontal frame mapping, kFittingRoomScrollPartExtentBySkin[3] use, GrafPort/resource/render helper roles, vtable-only reachability through 0x0060dccc, rejection of generic ScrollBar source reroute, and first-draft C++ readiness; exact original local draw-helper spellings and disabled-clear flag name remain descriptive.
```

Replace the existing [UID:0002D8] row with:

```text
- [UID:0002D8](0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) 0x0041e1d0-0x0041e4ed | method | FittingRoomScrollPaneHitTestPart : reconstructable : 88% : very strong : B002 source-quality reanalysis resolves the class-local direct-call route, five-part FittingRoomScrollPart return enum, inline rectangle source shape, field/table aliases, drag-aware thumb geometry, no-vtable/no-static-data status, rejection of generic ScrollBar source reroute, and first-draft C++ readiness; exact original rectangle-axis helper spellings remain descriptive.
```

No new coverage rows are required. No child split is recommended.

## Validator Commands To Run After Supervisor Application

Suggested after applying target/support/coverage edits and first-draft C++:

> Executable block R001 was removed from this report and preserved verbatim in [0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality-removed.md](0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator script uses different mode names in the current workspace, run the equivalent file validation for the three by-memory target files, affected support docs, coverage report, autogen, and rescore passes.

## Changed Files / No Direct Edit Statement

Created by this report:

- `tools/leaser/Agents/Agent-B002/research/0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md`

Not edited by this report:

- by-memory target docs
- by-class or by-file support docs
- generated reports
- generated source
- IDA database
- `project-documentation/by-memory/-coverage-report.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002D4"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002D4-0002D6-0002D8-FittingRoomScrollPaneDrawHitTimer-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002D4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
