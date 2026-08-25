** TARGET-REPORT-UID:0002KG **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B-Agent Research Report: UID 0002KG ParcelPaneOnPaint

Agent: Agent-B001  
Assignment: B001-report-0002KG-parcel-pane-on-paint-20260624  
Target: [UID:0002KG] `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md`  
Report path: `tools/leaser/Agents/Agent-B001/research/0002KG-ParcelPaneOnPaint-source-quality.md`  
Mode: initial report-only pass accepted by supervisor; implementation callback applied on 2026-06-25 and tracked in the checklist below.

## Initial Target State At Report Time

- At report time, the target header was `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A6`, with an empty formal C++ block.
- At report time, the target summary said it draws left/right alert buttons from `ALERTBTN.EPF` and `ALERTBTN.PAL`.
- Current range is exact as `0x00546890-0x0054696f`, with executable body ending at `0x0054696e` and one `0xcc` alignment byte at `0x0054696f`.
- At report time, the target page already had the right high-level owner route, but still carried stale prose using old `AUTOGEN_PARENT_UID` wording and a stale blank-C++ blocker list.
- At report time, generated/tracker state was stale relative to the target page: `auto-generated/-ag-research-tracker.md`, `project-level/-auto-completion-stats.md`, and generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` still showed UID 0002KG as `74/84` and no body. The implementation callback refreshed generated state through the validator only.

## Evidence Checked

- Live IDA MCP session `80de0a67` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, health OK on 2026-06-25 with `auto_analysis_ready=true` and `hexrays_ready=true`.
- IDA MCP calls used: `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `get_bytes`, `get_string`, and targeted sibling/helper analysis.
- Target docs checked: UID 0002KG target page, [UID:0000A6] `by-class/ParcelPane.md`, [UID:0000MF] `by-file/ParcelPane.md`, [UID:0001VI] `by-type/by-struct/ParcelNotificationPaneLayouts.md`.
- Sibling parcel docs checked: `ParcelPaneGetButtonFrameIndex`, `ParcelPaneProcessSlotAnimations`, `ParcelPaneUpdateAnimationCounter`, `ParcelPaneSetParcelSlotData`, `ParcelPaneOnMouseEvent`, `ParcelNotificationVtableData`, `ParcelNotificationVtableFamily`, and `FlyingParcelPaneDrawParcelOrLetter`.
- Helper/support docs checked: `EPFTileContext`, `GrafPortDrawStateAccessors`, `g_pEPFLib`, `ResourceLayoutTable`, `ResourceLayoutTableLookupLayoutEntry`, `SurfacePaintHelpers`, and `SurfaceRenderCallbackTable`.

## Positive Evidence

- IDA MCP `lookup_funcs` reports `sub_546890` at `0x00546890`, size `0xdf`; `0x0054696f` is not a function; the next function is `sub_546970` at `0x00546970`.
- IDA MCP `get_bytes 0x00546960 size 24` confirms the tail sequence ending in `retn` at `0x0054696e`, then `0xcc`, then the `0x00546970` successor prologue.
- IDA MCP `xrefs_to 0x00546890` reports exactly one data xref, from `0x00621c80`, matching the ParcelPane primary paint vtable slot.
- IDA MCP `get_bytes 0x00621c80 size 16` confirms the vtable cell sequence: `0x00546890`, `0x00546970`, `0x005469e0`, then `0x0064dc68`. This ties paint, animation advance, and frame-index helper slots together.
- IDA MCP `analyze_function 0x00546890` shows one basic block, 78 instructions, no direct code callers, and callees `0x00457a60`, `0x004b9660`, `0x0069b3fc`, `0x004d02f0`, `0x004b9980`, and the security-cookie helper.
- The live decompiler shape is the expected source sequence: initialize a stack EPF tile context, set draw/fill color to zero, prepare/fill the inherited pane bounds at `this+0x44`, resolve the left frame through vtable offset `+0x4c`, load `ALERTBTN.EPF`, render through `ALERTBTN.PAL` into `this+0x100`, then repeat for the right side into `this+0x110`.
- Field offsets match `ParcelNotificationPaneLayouts`: `+0xf9` left count, `+0xfa` right count, `+0xfc` left button state, `+0xfd` right button state, `+0x100` left button rect, `+0x110` right button rect.
- IDA MCP `get_string` confirms `0x00621d50` is `ALERTBTN.EPF` and `0x00621d6c` is `ALERTBTN.PAL`.
- IDA MCP `xrefs_to` for the two resource strings reports three xrefs each: two from ParcelPaneOnPaint and one from FlyingParcelPaneDrawParcelOrLetter. This supports shared parcel source-family resource ownership rather than target-local string ownership.
- IDA MCP `analyze_function 0x005469e0` confirms the vtable helper behind `ResolveButtonFrameIndex`: states 0/1/2 select idle/hover/pressed frames, nonzero slot count selects occupied frames, right-side frames are offset to 14/17/18/19, and state 3 returns animation bytes at `this+0xfe` or `this+0xff`.
- IDA MCP `analyze_function 0x00546df0` confirms FlyingParcelPane is the sibling resource consumer: it initializes an EPF tile context, chooses `ALERTBTN.EPF` frame 5 plus `ALERTBTN.PAL` or `LETTER.EPF` frame 0 plus `LETTER.PAL`, then calls the same `RenderTileFrame` wrapper.
- IDA MCP `analyze_function 0x004b9980` confirms the render wrapper resolves the palette name through `0x00543d70` and dispatches through surface callback slot `0x0069b3e8`. This supports source-facing `RenderTileFrame` and rejects old feature-local helper labels.
- IDA MCP `analyze_function 0x004d02f0` confirms `LookupLayoutEntry` lazy-loads/fetches a resource bucket, bounds-checks the frame index, and writes `EPFTileContext` fields including pixel pointer, row stride, bounds, mask byte count, and mask pointer.

## Negative Evidence And Rejections

- No direct code callers were observed for `0x00546890`; reachability is vtable-only. This supports a normal virtual paint override, not a free helper or directly invoked utility.
- No function exists at `0x0054696f`; the single `0xcc` byte is padding. Do not split the target before `0x0054696f`, and do not merge it with `0x00546970`.
- The body has no branch, loop, direct input handling, packet handling, timer scheduling, or parcel state mutation. Those concerns belong to sibling ParcelPane methods, not this paint method.
- The body has no `LETTER.EPF` or `LETTER.PAL` reference. Letter drawing belongs to FlyingParcelPaneDrawParcelOrLetter, not ParcelPaneOnPaint.
- The body has no `ReleaseBuffers` call or compiler destructor call after the render calls. Do not add a cleanup call to the target C++ just because other EPFTileContext consumers release owned decoded buffers.
- Helper owners are dependencies only. Do not move canonical ownership to EPFTileContext, GrafPort, Surface, ImageLib, ResourceLayoutTable, or the read-only resource string island.
- Do not retain polluted names such as `FittingRoomDownloadControlPane::RenderTileFrame`, raw `dword_69B3FC`, or generated `g_pfnLockSurface` in source-facing target prose. The current support docs justify `RenderTileFrame`, `SurfaceRenderCallbackTable::PreparePaneRegion`, `GrafPort::SetDrawColor`, `g_pEPFLib`, and `LookupLayoutEntry`.
- Do not treat generated/autogen stale `74/84` rows as the current target state; the source page is already `87/90`.

## Heuristic And Inference Reanalysis

- The old blank-C++ blocker was valid when render callback and EPF helper names were still polluted. Current support docs have enough source-quality names for a first-draft target body. The remaining uncertainty is declaration spelling across shared support, not the target behavior.
- `sub_457A60` is source-facing `EPFTileContext::Initialize` / historical `InitTileContext`. For the formal draft below, prefer `tileContext.Initialize()` because the current EPFTileContext class declaration exposes `Initialize()`.
- The source-rectangle argument to `RenderTileFrame` is `ebp-0x1c`, which is `EPFTileContext + 0x10`. The current EPFTileContext class declaration names that member `bounds`; use `&tileContext.bounds` in this target draft. Older docs sometimes say `tile.m_bounds`; that inconsistency should not block this target, but implementation should keep support declarations consistent.
- `0x004b9660` is not text-color-only. The current best source-facing role is the shared GrafPort active draw/fill color setter, so this target should say `SetDrawColor(0)`.
- `0x0069b3fc(this, this+0x44)` matches the same pane-region preparation/fill callback used by other pane paint paths. Use the existing emitted style `SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds)`.
- `0x004d02f0` is sufficiently resolved as `LookupLayoutEntry`; `g_pEPFLib` final public type remains open (`ImageLib*`, `ResourceLayoutTable*`, or facet/base), but all current callers use it as the resource-layout receiver. This is not target-blocking.
- `0x004b9980` is sufficiently resolved as the shared `RenderTileFrame` wrapper. It is Surface/render infrastructure, but the target should call it as a shared dependency, not own or rename it.
- The raw IDA prototype is `int __thiscall(int this)` because the last helper return remains in `eax`; pane paint slots in this codebase are source-facing `void OnPaint()`. Use `void ParcelPane::OnPaint()` and ignore the final helper return.
- `ParcelButtonState` and the left/right count/state/rect field names are no longer current-scope blockers. The frame resolver and layout pages independently support them.

## Ranked Ownership And Source Placement

1. Direct canonical owner: [UID:0000A6] `ParcelPane`. Evidence: primary vtable slot `0x00621c80 -> 0x00546890`, use of ParcelPane-local fields at `+0xf9/+0xfa/+0xfc/+0xfd/+0x100/+0x110`, and sibling ParcelPane helper slot `0x00621c88 -> 0x005469e0`.
2. Emitting source route: [UID:0000MF] `by-file/ParcelPane.md`, currently `NexusTK/ui/panels/ParcelPane.cpp` / parcel notification source family. Evidence: class/file docs group ParcelPane, ParcelIconPane, and FlyingParcelPane; the vtable island and resource strings sit in the same parcel notification read-only data region.
3. Shared dependencies only: EPFTileContext, GrafPort, SurfaceRenderCallbackTable, SurfacePaintHelpers, g_pEPFLib, ResourceLayoutTable. These own helper implementations and declarations, not this paint body.

## First-Draft C++ Recommendation

Recommendation: populate the target formal C++ block during the implementation callback. This is now source-quality enough for first-draft reconstruction because the function body is exact, the owner route is exact, the field offsets are supported by current layout docs, and the old helper-name blockers have accepted source-facing names.

Exact formal insertion text for UID 0002KG:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ParcelPane::OnPaint()
{
    EPFTileContext tileContext;
    tileContext.Initialize();

    SetDrawColor(0);
    SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds);

    int frameIndex = ResolveButtonFrameIndex(&m_leftButtonState,
                                             m_leftParcelCount,
                                             false);
    g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", frameIndex, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_leftButtonRect,
                    1,
                    L"ALERTBTN.PAL",
                    0);

    frameIndex = ResolveButtonFrameIndex(&m_rightButtonState,
                                         m_rightParcelCount,
                                         true);
    g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", frameIndex, &tileContext);
    RenderTileFrame(&tileContext,
                    &tileContext.bounds,
                    &m_rightButtonRect,
                    1,
                    L"ALERTBTN.PAL",
                    0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Implementation caveat: if the implementation callback finds that the active emitted EPFTileContext declaration uses `InitTileContext()` or `m_bounds` instead of `Initialize()` and `bounds`, update the shared support declaration consistently or adjust this target body to the accepted declaration. Do not mix incompatible spellings in emitted C++.

## Score And Metadata Recommendation

- Target score after implementation: raise UID 0002KG from `87/90` to `91/91`.
- Rationale for completion 91: exact live MCP boundary and body reconfirmed; vtable route, resource strings, helper roles, field offsets, sibling frame resolver, sibling resource consumer, and first-draft C++ are all documented.
- Rationale for confidence 91: behavior and ownership are direct evidence; source names are strong but still not final/perfect because `g_pEPFLib` public type and some EPFTileContext/render-helper declaration spellings remain support-level caveats.
- Recommended target summary: `Paints both ParcelPane alert buttons by preparing the pane region, resolving left/right ALERTBTN frame indices, loading ALERTBTN.EPF entries, and rendering with ALERTBTN.PAL.`
- Keep `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000A6`.
- Support metadata changes are not required by this report. `by-class/ParcelPane.md`, `by-file/ParcelPane.md`, and `ParcelNotificationPaneLayouts.md` already carry sufficient parent/layout evidence. They should receive concise sync notes only if the implementation callback adds target C++ and wants the support docs to mention that OnPaint is now first-draft populated.

## Exact Implementation Notes For Callback

- Target page should get a new 2026-06-25 live MCP evidence note with session `80de0a67`, exact range `0x00546890-0x0054696f`, IDA size `0xdf`, no function at `0x0054696f`, one data xref from `0x00621c80`, no direct code callers, and two xrefs each to `ALERTBTN.EPF`/`ALERTBTN.PAL` from the target.
- Replace stale "C++ remains blank until helper names are final" wording with this report's narrower caveat: declaration spellings remain support-level, but target behavior is ready for first-draft C++.
- Update stale `AUTOGEN_PARENT_UID` prose to current `CANONICAL_OWNER`/`EMITTER_UIDS` terminology.
- Keep raw helper aliases as evidence only; source-facing target prose should use `EPFTileContext`, `GrafPort::SetDrawColor`, `SurfaceRenderCallbackTable::PreparePaneRegion`, `g_pEPFLib->LookupLayoutEntry`, and `RenderTileFrame`.
- Record explicitly that no `ReleaseBuffers` call appears in the live target body.
- After source doc implementation, run the scoped validator/autogen refresh path rather than editing generated files manually. Generated `ParcelPane.cpp` and tracker rows are currently stale.

## Implementation Tracking Checklist

- [x] Update UID 0002KG target metadata to recommended `91/91` while preserving owner/emitter/reconstructable values. Proof: `by-memory/0x00546890-0x0054696f.ParcelPaneOnPaint.md` header is now `COMPLETION:91`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A6`, blank `EMITTER_POSITION_OPTIONAL`. Validator proof: command `python .\tools\validator.py --mode file --file by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240`, `command_id: 000000000721`, `command_timestamp: 2026-06-25T00:23:17-04:00`, exit `0`, `ok: 1`.
- [x] Insert the exact formal C++ block above into UID 0002KG. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains `void ParcelPane::OnPaint()`, `EPFTileContext tileContext`, `tileContext.Initialize()`, `SetDrawColor(0)`, `SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds)`, both `ResolveButtonFrameIndex` calls, both `g_pEPFLib->LookupLayoutEntry(L"ALERTBTN.EPF", ...)` calls, and both `RenderTileFrame(... L"ALERTBTN.PAL", 0)` calls. Generated proof: `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` includes `// UID:0002KG ... Completion:91 | Confidence:91` and the same body after final generated refresh `command_id: 000000000792`, `validator-refreshed-at: 2026-06-25T00:40:16-04:00`.
- [x] Add the 2026-06-25 IDA MCP evidence note to UID 0002KG. Proof: target `IDA MCP Evidence` records session `80de0a67`, exact range `0x00546890-0x0054696f`, size `0xdf`, no function at `0x0054696f`, vtable xref `0x00621c80`, no direct code callers, resource string xrefs, helper callees, sibling helper evidence, and no `ReleaseBuffers`/destructor/timer/state mutation calls.
- [x] Replace stale helper-blocker prose in UID 0002KG with the resolved helper/source-name analysis from this report. Proof: target `Behavior`, `Helper And State Boundaries`, `Negative Evidence And Rejected Alternatives`, `Assignment Decision`, and `Reconstruction Notes` now use `EPFTileContext::Initialize`, `GrafPort::SetDrawColor`, `SurfaceRenderCallbackTable::PreparePaneRegion`, `g_pEPFLib->LookupLayoutEntry`, and `RenderTileFrame`; raw `sub_`/`dword_` labels are evidence aliases only.
- [x] Update UID 0002KG item summary to the recommended paint-behavior summary. Proof: after the 2026-06-25 correction pass and final required validator run, the target header reads exactly `Paints both ParcelPane alert buttons by preparing the pane region, resolving left/right ALERTBTN frame indices, loading ALERTBTN.EPF entries, and rendering with ALERTBTN.PAL.` Auto-generated by-memory coverage now renders the same summary for UID 0002KG after final generated refresh `command_id: 000000000792`.
- [x] Remove or rewrite stale `AUTOGEN_PARENT_UID` wording in UID 0002KG. Proof: target text no longer contains `AUTOGEN_PARENT_UID`; current owner/emitter prose uses `CANONICAL_OWNER:0000A6` and `EMITTER_UIDS:0000A6`.
- [x] Sync `by-class/ParcelPane.md` to mention that OnPaint is first-draft populated and uses the accepted left/right field names and frame resolver. Proof: class method row, evidence note, assignment gate, score rationale, open question, and change log now mention first-draft UID 0002KG C++, accepted left/right count/state/rect fields, `ResolveButtonFrameIndex`, helper/source names, session `80de0a67`, and no `ReleaseBuffers`. Validator proof: command `python .\tools\validator.py --mode file --file by-class\ParcelPane.md --apply --queue-timeout 240`, `command_id: 000000000724`, `command_timestamp: 2026-06-25T00:23:35-04:00`, exit `0`, `ok: 1`.
- [x] Sync `by-file/ParcelPane.md` to mention that UID 0002KG no longer has a blank-C++ blocker after this source-quality pass. Proof: file role, migration notes, and change log now record UID 0002KG as first-draft populated, keep `ParcelPane.cpp` as the source-family owner, and preserve remaining timer/helper-class caveats. Validator proof: command `python .\tools\validator.py --mode file --file by-file\ParcelPane.md --apply --queue-timeout 240`, `command_id: 000000000726`, `command_timestamp: 2026-06-25T00:23:42-04:00`, exit `0`, `ok: 1`.
- [x] Verify `ParcelNotificationPaneLayouts.md` still matches the target field names; no required change is currently identified. Proof: checked `by-type/by-struct/ParcelNotificationPaneLayouts.md`; it already records `m_leftParcelCount`, `m_rightParcelCount`, `m_leftButtonState`, `m_rightButtonState`, left/right button rectangles, and the accepted `ResolveButtonFrameIndex` frame map. No edit or lease was needed.
- [x] Do not manually edit generated files, project-level stats, validator state, IDA DB, or coverage reports. Proof: manual edits were limited to the three source by-* docs and this Agent-B001 report. The 2026-06-25 summary correction manually edited only the target source page and this report checklist; the supervisor-owned `by-memory/-coverage-report.md` row was not edited by B001. Validator-managed generated/project updates occurred only through validator commands; no IDA DB, generated file, project-level file, validator state, or manual coverage report was manually edited.
- [x] Run the appropriate scoped validation/autogen refresh during implementation callback after source docs were updated. Proof: original target command `000000000721` exit `0`, `ok: 1`, `generated_refresh: deferred`; class command `000000000724` exit `0`, `ok: 1`, `generated_refresh: deferred`; file command `000000000726` exit `0`, `ok: 1`, `generated_refresh: deferred`; earlier target generated refresh command `000000000729` exit `0`, `ok: 1`, `generated_refresh: completed`. Summary-correction proof: required command `python .\tools\validator.py --mode file --file by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240 --wait-generated`, `command_id: 000000000784`, `command_timestamp: 2026-06-25T00:39:13-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, exposed the stale metadata overwrite; source-only corrective command `python .\tools\validator.py --mode file --file by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240 --no-generated-refresh`, `command_id: 000000000790`, `command_timestamp: 2026-06-25T00:40:04-04:00`, exit `0`, `ok: 1`, `generated_refresh: skipped`, `generated_refresh_detail: disabled by --no-generated-refresh`; final required command `python .\tools\validator.py --mode file --file by-memory\0x00546890-0x0054696f.ParcelPaneOnPaint.md --apply --queue-timeout 240 --wait-generated`, `command_id: 000000000792`, `command_timestamp: 2026-06-25T00:40:16-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`, `generated_refresh_command_id: 000000000792`, `generated_refresh_timestamp: 2026-06-25T00:40:16-04:00`, `generated_metadata_refresh: 272`, `memory_auto_coverage_update: 1`, and `memory_coverage_metadata_update: 3`. Queue status command `000000000799` at `2026-06-25T00:40:51-04:00` reported `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002KG-ParcelPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002KG-ParcelPaneOnPaint-source-quality.md","timestamp":"2026-06-25T00:50:23","uid":"0002KG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
