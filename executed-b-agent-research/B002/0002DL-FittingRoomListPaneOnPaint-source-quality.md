** TARGET-REPORT-UID:0002DL **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: FittingRoomListPane::OnPaint

Assignment: implementation callback for the accepted Gate 1 report for [UID:0002DL] `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`.

Implementation callback result: accepted target/support by-* doc changes were applied, the report ledger/checklist was updated, scoped validators passed, generated `FittingRoom.cpp` was checked after validator refresh, B002 leases were released, and no `execute_report` or lifecycle/archive command was run.

## Finalized Report / Current Recommendation

Keep [UID:0002DL] as source-authored `FittingRoomListPane::OnPaint`, owned and emitted by [UID:000053] `FittingRoomListPane` through [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp`, with `RECONSTRUCTABLE:TRUE`.

Implemented metadata change:

| Field | Before callback | After callback |
| --- | ---: | ---: |
| `COMPLETION` | 86 | 88 |
| `CONFIDENCE` | 90 | 91 |
| `CANONICAL_OWNER` | `000053` | keep |
| `RECONSTRUCTABLE` | `TRUE` | keep |
| `EMITTER_UIDS` | `000053` | keep |

The existing formal C++ should not be blanked, but it should be revised. Current live MCP evidence confirms the same source body and route, while later support-doc work makes several helper names in the existing formal block stale:

- `ForwardToTileFrameBlitHelper(...)` is wrong for this callsite. [UID:0002DL] calls `0x004b9980`, now documented as [UID:0004H6] `GrafPort::RenderTileFrame(...)`. The similarly named `0x004b99f0` helper is [UID:000166] and is not called by this body.
- `g_pItemObjImageLib->GetItemGlyphBounds(...)` should be the free helper [UID:0000UQ] `GetItemGlyphBounds(short, RectBounds *)`, not an `ItemObjImageLib` method.
- `g_pItemObjImageLib->DrawItem(...)` / `DrawLargeItem(...)` should be source-facing calls to `ItemObjImageLib::DrawItemImageIn43x43Slot(...)` and `ItemObjImageLib::DrawItemImageUnscaled(...)`.
- `SelectionVectorContains(...)` and `DrawWrappedFittingRoomItemName(...)` are convenient reverse-engineering helpers. They should be lowered in the formal block to the selected-entry vector scan and caller-local secure formatting/token wrapping sequence, because [UID:00030X] and [UID:00030V] are now documented as non-emitting MSVC/UCRT fixed-buffer support.

## Supporting Research

This pass used the project workflow skill, current target/support docs, accepted executed reports, generated output as a stale-output check only, and fresh IDA MCP evidence from the active session.

Current MCP status:

- Session/database: `supervisor_nexustk_20260709`.
- HTTP MCP session id observed in this pass: `78f9c9e7-8e79-4e18-85d2-8d5bdd366054`.
- `server_health` command id `13`: `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Earlier command ids `5-12` failed with `"database is required"` because my PowerShell wrapper used a reserved `$args` variable and dropped the database payload. Command ids `13+` corrected the wrapper and succeeded. This is not MCP unavailability.

## Target

- Target UID: `0002DL`.
- Target path: `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`.
- Current source-facing name: `FittingRoomListPane::OnPaint`.
- Current owner/emitter: [UID:000053] `FittingRoomListPane`.
- Current file route: [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp`.

## Current Target State

The current target page records `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000053`, and a populated first-draft `FittingRoomListPane::OnPaint()` formal block.

The current generated output at `auto-generated/NexusTK/cashshop/FittingRoom.cpp` still emits the same stale formal body under UID0002DL. It contains:

- `ForwardToTileFrameBlitHelper(...)` at the background tile draw call;
- `SelectionVectorContains(...)` for selected-entry highlight lookup;
- `g_pItemObjImageLib->GetItemGlyphBounds(...)`;
- `DrawWrappedFittingRoomItemName(...)`.

These generated-source observations are not primary proof; they confirm that the stale target formal block is what downstream generation currently reflects.

## Heuristic / Inference Reanalysis And Validation

The source-facing method name and owner route remain correct. Fresh MCP gives `sub_41F2B0` as a `void __thiscall(_DWORD *this)` function with no direct code xrefs and one data xref from vtable cell `0x0060dd54`. The function reads and mutates inherited pane/GrafPort drawing state, list scroll fields, fitting-room dialog item-state/catalog state, and selected-entry vector state. That combination is list-pane paint behavior, not a generic render helper.

The old reason to keep C++ only at `86/90` was not the target route; it was source-name quality for helper calls. That blocker has improved enough to revise the formal block:

- Current GrafPort docs make `0x004b9980` source-ready as `RenderTileFrame`, and make `0x004b99f0` a separate `ForwardToTileFrameBlitHelper` helper that this target does not call.
- Current ItemObjImageLib docs make `0x004df460` source-ready as free `GetItemGlyphBounds`, while the two draw callees are class methods with known source-facing names even though their own formal bodies remain blank.
- Current WideFormatWrapper128 docs make `0x00421260` non-emitting CRT/UCRT support and explicitly state the source-level operation belongs in this caller.
- Current SurfaceRenderCallbackTable docs reject `g_pfnLockSurface` and support slot `0x0069b3fc` as fill/invalidate/presentation infrastructure for this callsite.

Remaining unresolved items are exact original field names, exact original helper declarations, the final public selection-entry vector type spelling, and the exact text/string class API spelling. Those cap the target below final-audit confidence but no longer justify leaving known stale helper names in the formal C++.

## Evidence Standards Used

- Current IDA MCP evidence is primary for function boundaries, xrefs, callees, constants, decompilation, disassembly, and byte padding.
- Existing target/support docs and executed reports are treated as leads and historical incorporation records unless current MCP or current support pages agree.
- Generated output is used only as an output-state/stale-shape check.
- No fallback-only research was finalized.

## Evidence Checked

Files read:

- `tools/leaser/Agents/Agent-B002/goal.md`
- `.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `.codex/skills/ntk-b-agent-workflow/references/report-template.md`
- `.codex/skills/ntk-b-agent-workflow/references/score-blocker-standard.md`
- `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`
- `by-class/FittingRoomListPane.md`
- `by-file/FittingRoom.md`
- `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`
- `by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md`
- `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`
- `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`
- `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
- `by-class/FittingRoomDialogItemState.md`
- `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`
- `by-global/g_pItemObjImageLib.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-class/EPFTileContext.md`
- `by-class/GrafPort.md`
- `by-file/GrafPort.md`
- `by-class/ItemObjImageLib.md`
- `by-class/Region.md`
- `by-memory/0x004b9980-0x004b99b1.GrafPortRenderTileFrame.md`
- `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
- `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-memory/0x00421260-0x00421290.WideFormatWrapper128.md`
- `by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md`
- `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`
- `by-memory/0x004defc0-0x004df1d4.ItemObjImageLibDrawItemImageIn43x43Slot.md`
- `by-memory/0x004df1e0-0x004df2b7.ItemObjImageLibDrawItemImageUnscaled.md`
- `by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md`
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `executed-b-agent-research/B003/0002DF-0002DL-0002DN-0002DQ-FittingRoomListPanePaintInputScroll-source-quality.md`
- `executed-b-agent-research/B002/00030X-WideFormatWrapper128-source-quality.md`
- `executed-b-agent-research/B002/00016A-GrafPortDrawTiledBackground-source-quality.md`
- `executed-b-agent-research/B006/000166-ForwardToTileFrameBlitHelper-source-quality.md`

MCP commands used as fresh evidence:

- `13 server_health`: healthy active IDB and Hex-Rays readiness.
- `14 lookup_funcs`: target `0x0041f2b0` is `sub_41F2B0`, size `0x8eb`; `0x0041fb9a` is inside; `0x0041fb9b` is not a function; successor `0x0041fba0` is `sub_41FBA0`, size `0x125`; support starts `0x0041f220`, `0x0041ee10`, `0x0041fcd0`, `0x00422690`, `0x004226d0`, `0x004b9980`, `0x004b99f0`, `0x004df460`, `0x004defc0`, `0x004df1e0`, `0x004ba9a0`, `0x004bab70`, `0x00421260`, and `0x00421230` all resolve as expected.
- `21 xrefs_to 0x0041f2b0`: exactly one data xref from `0x0060dd54`.
- `22 callees 0x0041f2b0`: reports `0x00457a60`, `0x00554680`, `0x004d02f0`, `0x004b9590`, `0x004b95b0`, `0x004b9980`, `0x004b7e10`, `0x004b9580`, `0x004f4a90`, `0x0041ee10`, `0x00422690`, `0x004226d0`, `0x004b7c30`, `0x004b78d0`, `0x004b9660`, `0x0069b3fc`, `0x004df460`, `0x004defc0`, `0x004df1e0`, `0x00421260`, `0x004b9680`, `0x00421590`, `_wcstok`, `_memset`, `0x004ba9a0`, `0x004b9600`, `0x004bab70`, `0x00421230`, `0x005c7526`, security cookie, `0x00421510`, and invalid-parameter support.
- `24 xrefs_to` support addresses: confirms `g_pEPFLib`/resource service `0x0067a744` use at `0x0041f2fb`; `WBOARDBK.EPF` at `0x0041f30a`; `WBOARDBK.PAL` at `0x0041f40c`; `g_pFittingRoomDialog` at `0x0041f48e`; `g_pItemObjImageLib` at `0x0041f72d`, `0x0041f79c`, `0x0041f854`; `dword_69B3FC` at `0x0041f6bd`; `0x00421260` at `0x0041f89b`; `0x00421230` at `0x0041f9e7` and `0x0041f9fc`; `0x004df460` at `0x0041f73f`; `0x004defc0` at `0x0041f7bc`; `0x004df1e0` at `0x0041f886`.
- `27 get_bytes`: `0x0041f2a6` has ten `0xcc` bytes before the prologue; `0x0041fb9b` has five `0xcc` bytes before successor prologue; vtable cell `0x0060dd54` contains `b0 f2 41 00`.
- `28 analyze_function`: prototype shape `void __thiscall(_DWORD *this)`, size `2283`, callers empty, one vtable data xref, basic blocks `81`, cyclomatic complexity `38`.
- `29 int_convert`: verified `0x8eb=2283`, `0x33=51`, `0x42=66`, `0x60=96`, `0x70=112`, `0x108=264`, `0x10a=266`, `0x10c=268`, `0x11c=284`, `0x240=576`, `0x744=1860`, `0x784=1924`, `30000=0x7530`. The `0xb4` one-byte conversion failed because 180 needs more than one byte, which itself confirms it is not a byte-sized field.
- `31 decompile 0x0041f2b0`: confirms the tiled background, active category/catalog reads, `UpdateScrollBar`, visible-grid loop, selected-entry vector scan, item image draw branches, fixed-buffer text formatting/tokenization, and final draw-state reset.
- `32/33 disasm`: confirms total instruction count `618` in this MCP build, the pre-visible enabled-entry scan at `0x0041f510-0x0041f573`, `0x004b9980` tile render call, selected-entry stride `0xb4`, highlight fill through `0x0069b3fc`, item-image helper calls, and text formatting callsites.
- `34 find_bytes`: VA bytes for `0x0041f2b0` appear once at `0x0060dd54`; bytes for `0x0060dd54` as a pointer were not found.
- `35 type_query`: no recovered project UDT/type records for `*FittingRoom*`, `*ItemCatalog*`, `*EPFTile*`, or `*GrafPort*`.
- `36 entity_query`: only `sub_41F2B0` and successor `sub_41FBA0` exist in the local target window; no local source-quality names in that range.
- `37 xref_query`: zero code xrefs to target, one data xref to target from `0x0060dd54`, and the vtable cell points from `0x0060dd54` to `0x0041f2b0`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002DL-01 | Keep [UID:0002DL] as `FittingRoomListPane::OnPaint`, owned/emitted by [UID:000053] through [UID:0000JE]. | High | MCP `lookup_funcs` id `14`; `xref_query` id `37`; vtable cell `0x0060dd54`; current target, class, and file docs. | Target metadata header; `## Status`; class UID0002DL method row; file FittingRoomListPane source-context note. | incorporate | applied |
| C-0002DL-02 | Preserve exact half-open range `0x0041f2b0-0x0041fb9b`; successor `0x0041fba0`; no split/reclassification. | High | MCP `lookup_funcs` id `14`; `get_bytes` id `27`; `entity_query` id `36`; padding bytes before/after target. | Target `## Live Evidence`; `## Range / Split / Padding / Reclassification Analysis`; class boundary caution if touched. | incorporate | applied |
| C-0002DL-03 | Preserve vtable-only reachability and no ordinary direct callers. | High | MCP `xrefs_to` id `21`; `analyze_function` id `28` callers empty; `find_bytes` id `34` finds target VA only at `0x0060dd54`. | Target `## Signature` / `## Live Evidence`; class boundary caution. | incorporate | applied |
| C-0002DL-04 | Refresh current MCP evidence from session `supervisor_nexustk_20260709`, including current instruction count `618`; label older `604` wording as historical if retained. | High | MCP `server_health` id `13`; `disasm` ids `32`/`33`; `analyze_function` id `28`. | Target `## Live Evidence`; class UID0002DL boundary caution if edited. | incorporate | applied |
| C-0002DL-05 | Replace stale background call name `ForwardToTileFrameBlitHelper` with `RenderTileFrame` for the actual callee `0x004b9980`. | High | MCP `callees` id `22`; disasm id `32` at `0x0041f427`; support page [UID:0004H6] `GrafPortRenderTileFrame`; [UID:000166] starts at `0x004b99f0` and is not a target callee. | Target formal C++ block; target C++ shape notes; class/file source-context notes. | incorporate | applied |
| C-0002DL-06 | Treat `GetItemGlyphBounds` as free ItemObjImageLib-file helper, not a `g_pItemObjImageLib` method. | High | MCP xrefs id `24` callsite `0x0041f73f`; support page [UID:0000UQ] source-ready free helper and method-route rejection. | Target formal C++ block; target helper-role notes; class/file source-context notes. | incorporate | applied |
| C-0002DL-07 | Use current item draw names `ItemObjImageLib::DrawItemImageIn43x43Slot` and `ItemObjImageLib::DrawItemImageUnscaled` for `0x004defc0` and `0x004df1e0`. | Medium-high | MCP xrefs id `24`; support pages [UID:00041S] and [UID:00041T]. Their own bodies remain blank, but source-facing method names/signatures are documented. | Target formal C++ block; target helper-role notes. | incorporate | applied |
| C-0002DL-08 | Lower `SelectionVectorContains` into the selected-entry vector scan over item-state `+0x240/+0x244` / dialog `+0x744/+0x748`, stride `0xb4`, comparing category and catalog index. | High | MCP decompile id `31`; disasm ids `32`/`33`; existing [UID:0002DN] and selection-vector support docs. | Target formal C++ block; target selected-entry/vector notes; class source-context note if touched. | incorporate | applied |
| C-0002DL-09 | Lower `DrawWrappedFittingRoomItemName` into caller-local fixed-buffer formatting, tokenization, width measurement, move, and draw sequence; fixed-count wrappers remain non-emitting UCRT support. | High | MCP decompile id `31`; disasm id `33` at `0x0041f89b`, `0x0041f9e7`, `0x0041f9fc`; accepted [UID:00030X] report and [UID:00030V] support. | Target formal C++ block; target C++ shape notes; file source-context note. | incorporate | applied |
| C-0002DL-10 | Use source-facing `FillRect`/fill-invalidate role for `dword_69B3FC`; reject generated `g_pfnLockSurface`. | High | MCP xrefs id `24` callsite `0x0041f6bd`; SurfaceRenderCallbackTable global and memory docs. | Target formal C++ block; target helper-role notes; class UID0002DL row if touched. | incorporate | applied |
| C-0002DL-11 | Raise target metadata from `86/90` to `88/91`; keep owner/emitter/reconstructable unchanged. | Medium-high | Current MCP confirms range/reachability/helper set; support docs remove stale helper blockers; remaining original spelling and local type uncertainties cap score. | Target metadata header and score rationale; no support score change. | incorporate | applied |
| C-0002DL-12 | Leave generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp` and coverage reports untouched; check generated output only after scoped validator/autogen refresh during callback. | High | Assignment boundary; workflow generated-file rules; generated file currently reflects stale C++ but is validator-owned. | Report checklist; later callback final response. | not-applicable | applied |

## Positive Evidence Summary

- Current MCP confirms a real function at `0x0041f2b0`, size `0x8eb`, with exclusive end `0x0041fb9b`.
- Predecessor padding is ten `0xcc` bytes and successor padding is five `0xcc` bytes before `OnKeyScroll`.
- The only route to the function is the vtable data cell `0x0060dd54`; direct code xrefs are zero.
- The body directly references `WBOARDBK.EPF`, `WBOARDBK.PAL`, `g_pFittingRoomDialog`, `g_pItemObjImageLib`, and `dword_69B3FC`.
- The body calls `UpdateScrollBar`, item-state count/index lookups, shared GrafPort/Region/rectangle helpers, item-image helpers, fixed-buffer wide formatting wrappers, tokenization, text measurement/move/draw helpers, and security-cookie/runtime cleanup.
- The body does not read `this+0x10c`, so a row-mode paint branch should not be invented in this exact target.
- Current support pages now resolve several old helper-name blockers enough to revise target C++.

## Negative Evidence Summary

- No IDA project UDT/type records exist for `FittingRoom`, `ItemCatalog`, `EPFTile`, or `GrafPort`; exact original source spellings remain inferred.
- No local source-quality name exists in the target range; IDA still calls the function `sub_41F2B0`.
- `0x004b99f0` / [UID:000166] is not a callee of this target; using `ForwardToTileFrameBlitHelper` for the `0x004b9980` call is stale.
- `0x00421260` and `0x00421230` should not emit as project `StringUtil` helpers; they are CRT/UCRT fixed-count secure formatting support.
- The current target doc formal body, before the later implementation callback, still uses synthetic helper names that would create source APIs not backed by current support docs.
- Exact source names for the scratch tile contexts, final text/string class methods, and final selected-entry vector declaration remain unresolved.

## Ranked Ownership Analysis

1. [UID:000053] `FittingRoomListPane` - best and current owner. The body is a vtable method in the list-pane vtable neighborhood and consumes list-pane scroll/draw fields, active fitting-room category, catalog data, selected-entry vector state, and item-grid paint layout.
2. [UID:0000JE] `FittingRoom` - correct file/emitter route through the class. The surrounding dialog/list/scroll/item-state methods are already placed in `NexusTK/cashshop/FittingRoom.cpp`.
3. [UID:000051] `FittingRoomDialogItemState` / historical `ItemCatalog` - rejected as owner. They provide count/index storage and selected-entry vector state, but the paint traversal, highlight, icon placement, and text drawing are UI pane behavior.
4. GrafPort/Surface/Region/EPFTileContext/ItemObjImageLib - rejected as owner. They own shared helper callees and globals, not this fitting-room method.
5. CRT/UCRT/StringUtil - rejected as owner. Fixed-format wrappers are dependency/support mechanics for caller-local formatting, not authored product helpers.

## Source Placement

Keep source placement in [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp`, emitted by [UID:000053] `FittingRoomListPane`.

No split, no no-owner reclassification, and no generated-helper source file is recommended. Shared render, item-image, Surface callback, Region, and CRT/UCRT helpers should remain dependencies or their own exact child pages.

## Range / Split / Padding / Reclassification Analysis

The current range remains a single exact function:

- Start: `0x0041f2b0`.
- End-exclusive: `0x0041fb9b`.
- Size: `0x8eb` / `2283`.
- Predecessor: [UID:0002DK] `FittingRoomListPaneOnDetachPane` ends at `0x0041f2a6`, followed by ten `0xcc` bytes.
- Successor: [UID:0002DM] `FittingRoomListPaneOnKeyScroll` starts at `0x0041fba0`, after five `0xcc` bytes.
- Vtable route: `0x0060dd54 -> 0x0041f2b0`.

Do not split this target. The loops, helper calls, selected-entry scan, icon drawing, and wrapped text block are all part of one virtual paint method. Do not reclassify any subset as raw helper, padding, compiler-only code, or a separate item-image/string/render source owner.

## IDA Rename / Type / Comment Recommendations

No IDA database edits are requested during this report-only pass.

If a future IDA rename pass is approved, safe descriptive labels would be:

- `sub_41F2B0` -> `FittingRoomListPane_OnPaint`.
- Data comment at `0x0060dd54`: `FittingRoomListPane::OnPaint vtable slot`.
- Callsite comment at `0x0041f427`: `GrafPort::RenderTileFrame` / [UID:0004H6], not `ForwardToTileFrameBlitHelper`.
- Callsite comment at `0x0041f73f`: free `GetItemGlyphBounds`, not an ItemObjImageLib method.
- Callsite comment at `0x0041f6bd`: shared fill/invalidate/presentation callback slot `dword_69B3FC`, not generated `g_pfnLockSurface`.

Do not apply these in this pass.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. Exact formal insertion text for the target `RECONSTRUCTION_CPP CODE` block follows. This is the callback insertion text, not illustrative prose.

```cpp
void FittingRoomListPane::OnPaint()
{
    EPFTileContext boardFrame;
    Region savedClip;

    EPFTileContext::Construct(&boardFrame);
    Region::Construct(&savedClip);

    if (g_pResourceMan->LoadFrame(L"WBOARDBK.EPF", 0, &boardFrame)) {
        RectBounds visible = m_bounds;
        m_drawMode = 1;

        SaveClipRegion(&savedClip);
        IntersectClipRect(visible);

        const int tileWidth = boardFrame.source.right - boardFrame.source.left;
        const int tileHeight = boardFrame.source.bottom - boardFrame.source.top;
        if (tileWidth > 0 && tileHeight > 0) {
            for (int y = visible.top; y < visible.bottom; y += tileHeight) {
                for (int x = visible.left; x < visible.right; x += tileWidth) {
                    RectBounds destination;
                    SetRectLTRB(&destination, x, y, x + tileWidth, y + tileHeight);
                    RenderTileFrame(&boardFrame,
                                    &boardFrame.source,
                                    &destination,
                                    m_drawMode,
                                    L"WBOARDBK.PAL",
                                    0);
                }
            }
        }

        RestoreClipRegion(&savedClip);
    }

    Region::Destroy(&savedClip);

    FittingRoomDialog *dialog = g_pFittingRoomDialog;
    FittingRoomDialogItemState *itemState = &dialog->m_itemState;
    const int activeCategory = dialog->m_activeCategory;
    const unsigned char catalogCategory = static_cast<unsigned char>(activeCategory);

    EPFTileContext itemScratch;
    EPFTileContext glyphScratch;
    EPFTileContext::Construct(&itemScratch);
    EPFTileContext::Construct(&glyphScratch);

    UpdateScrollBar();

    const short totalItems = itemState->GetItemCount(catalogCategory);

    short enabledBeforeVisibleStart = 0;
    for (short scanIndex = 1; scanIndex <= totalItems; ++scanIndex) {
        FittingRoomCatalogEntry *scanEntry =
            itemState->GetItemByIndex(catalogCategory, scanIndex);
        if (scanEntry != 0 && scanEntry->enabled != 0) {
            ++enabledBeforeVisibleStart;
            if (m_scrollPosition * kFittingRoomGridColumns < enabledBeforeVisibleStart) {
                break;
            }
        }
    }

    Point cell;
    SetPoint(&cell, 31, 17);
    m_drawMode = 1;

    unsigned char cellIndex = 0;
    short drawnCells = 0;
    short catalogIndex = static_cast<short>(m_scrollPosition * kFittingRoomGridColumns);
    if (m_enabledItemCount == 0 ||
        m_scrollPosition + kFittingRoomGridVisibleCells > totalItems) {
        catalogIndex = 0;
    }

    while (catalogIndex < totalItems && drawnCells < kFittingRoomGridVisibleCells) {
        FittingRoomCatalogEntry *entry =
            itemState->GetItemByIndex(catalogCategory, catalogIndex);

        if (entry != 0) {
            for (FittingRoomSelectionEntry *selected = itemState->m_selectedFittingItems.begin();
                 selected != itemState->m_selectedFittingItems.end();
                 ++selected) {
                if (selected->category == activeCategory &&
                    selected->catalogIndex == catalogIndex) {
                    RectBounds highlight;
                    SetRectLTRB(&highlight, cell.x, cell.y, cell.x + 50, cell.y + 50);
                    SetDrawColor(0x8a);
                    FillRect(&highlight);
                    break;
                }
            }

            if (entry->enabled != 0) {
                RectBounds &glyphBounds = glyphScratch.source;
                GetItemGlyphBounds(entry->tile, &glyphBounds);

                RectBounds iconRect;
                const int glyphWidth = glyphBounds.right - glyphBounds.left;
                const int glyphHeight = glyphBounds.bottom - glyphBounds.top;
                if (glyphWidth <= 50 && glyphHeight <= 50) {
                    SetRectLTRB(&iconRect, cell.x, cell.y, cell.x + 50, cell.y + 50);
                    g_pItemObjImageLib->DrawItemImageIn43x43Slot(
                        this, &iconRect, entry->tile, entry->color, 0, 0.0f);
                } else {
                    const int centeredLeft = cell.x + ((50 - glyphWidth) / 2);
                    const int centeredTop = cell.y + ((50 - glyphHeight) / 2);
                    SetRectLTRB(&iconRect,
                                centeredLeft,
                                centeredTop,
                                centeredLeft + glyphWidth,
                                centeredTop + glyphHeight);
                    g_pItemObjImageLib->DrawItemImageUnscaled(
                        this, &iconRect, entry->tile, entry->color);
                }

                SetBkColor(0x8f);

                wchar_t formattedName[128];
                swprintf_s(formattedName, _countof(formattedName), L"%s", entry->name);

                SimpleUString itemName;
                itemName.Assign(formattedName, wcslen(formattedName));

                wchar_t line[32];
                memset(line, 0, sizeof(line));

                wchar_t *nextToken = 0;
                wchar_t *token = wcstok(itemName.MutableData(), L" ", &nextToken);
                int lineLength = 0;
                int textY = cell.y + 0x42;
                const int textX = cell.x - 6;

                while (token != 0) {
                    if (lineLength > 0) {
                        const int tokenLength = static_cast<int>(wcslen(token));
                        if (lineLength + tokenLength >= 14) {
                            const short width = MeasureTextWidth(line, lineLength);
                            MoveTo(textX - width / 2 + 31, textY);
                            DrawWideText(line, lineLength);
                            textY += 16;
                            line[0] = 0;
                            lineLength = 0;
                        }
                    }

                    if (lineLength != 0) {
                        swprintf_s(line, _countof(line), L"%s %s", line, token);
                    } else {
                        swprintf_s(line, _countof(line), L"%s", token);
                    }

                    lineLength = static_cast<int>(wcslen(line));
                    token = wcstok(0, L" ", &nextToken);
                }

                if (lineLength > 0) {
                    const short width = MeasureTextWidth(line, lineLength);
                    MoveTo(textX - width / 2 + 31, textY);
                    DrawWideText(line, lineLength);
                }
            }

            ++drawnCells;
            cellIndex = static_cast<unsigned char>((cellIndex + 1) % kFittingRoomGridColumns);
            cell.x = cellIndex * 0x60 + 0x11;
            if (cellIndex == 0) {
                cell.y += 0x70;
            }
        }

        ++catalogIndex;
    }

    SetDrawColor(0x8f);
    m_drawMode = 2;
}
```

Notes for implementer:

- `m_drawMode`, `FittingRoomCatalogEntry`, `FittingRoomSelectionEntry`, `m_selectedFittingItems`, `SimpleUString`, `itemScratch`, and `glyphScratch` are implementation-ready source-facing names for still-unrecovered original spellings. They are intended to be inserted as written in this first-draft block; unresolved original spellings cap confidence but do not force no-code.
- The selected-entry check is intentionally caller-local vector iteration. Do not reintroduce a synthetic `SelectionVectorContains` helper.
- The text wrapping is intentionally caller-local fixed-buffer formatting/token wrapping. `swprintf_s(..., _countof(...))` represents the fixed-count UCRT wrapper calls at `0x00421260` and `0x00421230`; do not reintroduce project-owned `WideFormatWrapper*` helpers.
- Use `FillRect` or the locally accepted Surface/GrafPort fill wrapper name for `dword_69B3FC`; do not use generated `g_pfnLockSurface`.

## Final Recommendation

Implement a target C++ refresh and source-quality note update for [UID:0002DL]. Keep the route and reconstructability, raise target metadata to `88/91`, and update support docs only enough to preserve the corrected helper/source-quality facts. Do not split or reroute the target.

## Recommended Target Doc Changes

For `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`:

- Change `COMPLETION:86` to `COMPLETION:88`.
- Change `CONFIDENCE:90` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000053`.
- Replace the formal C++ body with the exact insertion text in `## First-Draft C++ Recommendation`.
- Update evidence wording to current MCP session `supervisor_nexustk_20260709` and current instruction count `618`.
- Replace stale `ForwardToTileFrameBlitHelper` wording for this body with `GrafPort::RenderTileFrame` / [UID:0004H6].
- Replace `g_pItemObjImageLib->GetItemGlyphBounds` wording with free `GetItemGlyphBounds`.
- Record that the text wrap block is caller-owned source logic using non-emitting fixed-count UCRT wrappers.

## Recommended Support Doc Changes

Support docs should receive narrow synchronization only if the supervisor accepts the target changes:

- [UID:000053] `by-class/FittingRoomListPane.md`: update the UID0002DL row and boundary caution from old `604` instruction wording to current MCP `618` if touching that line; mention `RenderTileFrame`, free `GetItemGlyphBounds`, and caller-local text wrapping.
- [UID:0000JE] `by-file/FittingRoom.md`: add one source-context note that UID0002DL now uses corrected shared-helper names and that its formal body no longer treats fixed-format wrappers as project helpers.
- No support score changes are required. Current class/file scores already remain appropriate because broader field/type spellings are still unresolved.
- Do not edit `GrafPort`, `ItemObjImageLib`, `SurfaceRenderCallbackTable`, or WideFormat wrapper pages unless the supervisor explicitly asks; they already contain the facts needed for this target.

## Score And Metadata Recommendation

Recommended target score: `88/91`.

Rationale:

- Completion rises because fresh MCP reconfirms exact range, padding, vtable route, callee/xref set, decompilation, and visible-grid behavior, and because current support docs resolve several stale helper names enough for a more source-authentic formal body.
- Confidence rises slightly because current MCP agrees with the historical route and clarifies no direct caller, vtable-only reachability, current callee identities, current support helper owner names, and non-emitting format-wrapper handling.
- Do not raise above `88/91` because original field/type spellings, the final selection-entry vector API, exact string class API, scratch context rationale, and full icon-centering expression remain inferred.

## Open Questions With Attempted Resolution

- Exact original name for `m_drawMode` versus `m_blitMode`: current GrafPort support accepts both directions; use `m_drawMode` in target prose and C++ because current target already uses it and support docs permit it.
- Exact original type/name for the selected-entry vector: current [UID:0002DN] and selection-vector docs prove the `0xb4` layout and category/index fields; the formal block uses implementation-ready source-facing names `m_selectedFittingItems` and `FittingRoomSelectionEntry` instead of a synthetic helper.
- Exact text/string class API: MCP proves `Src[128]`, `Buffer[32]`, `sub_421590`, `wcstok`, `MeasureTextWidth`, `MoveTo`, and `DrawWideText`; the formal block uses `SimpleUString::Assign` and `SimpleUString::MutableData` as implementation-ready source-facing names while preserving caller-local formatting/token wrapping.
- Exact scratch context purpose after background draw: current MCP proves two `EPFTileContext` initializations. The formal block keeps `itemScratch` for source-shape preservation and uses `glyphScratch.source` for the free `GetItemGlyphBounds` output.
- Icon centering arithmetic: current decompile proves the branch and draw calls. The formal block lowers the remaining centering behavior to direct centered-rectangle arithmetic using the measured glyph bounds, so no unresolved centering helper remains.

No open question forces a blank formal C++ block or a no-code recommendation. The unresolved exact original spellings are confidence caps only.

## Validator Results

Implementation callback validators run from `source-3/project-documentation` while B002 held the target/support by-* leases:

| File | Command ID | Command timestamp | Exit code | Result | Warnings / side effects |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md` | `000000008130` | `2026-07-09T13:13:00-04:00` | `0` | `ok: 1` | `completion_update 88`; `confidence_update 91`; `autogen_registry_update`; `uid_link_insert` for [UID:0004H6]/[UID:000166]; `reference_index_add` for [UID:000166], [UID:00030V], [UID:0004H6]; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-class/FittingRoomListPane.md` | `000000008131` | `2026-07-09T13:13:11-04:00` | `0` | `ok: 1` | `uid_link_insert` / `reference_index_add` for [UID:0004H6]; `projected_stats_update`; `generated_refresh: deferred`. |
| `by-file/FittingRoom.md` | `000000008132` | `2026-07-09T13:13:18-04:00` | `0` | `ok: 1` | `uid_link_insert` / `reference_index_add` for [UID:0004H6]; known pre-existing `missing_ref_uid 0003AM` reported 4 times; `projected_stats_update`; `generated_refresh: deferred`. |

Generated-output check:

- Queue status probe `000000008133` at `2026-07-09T13:13:32-04:00` reported `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` header shows `validator-command-id: 000000008132` and `validator-refreshed-at: 2026-07-09T13:13:18-04:00`, equal to the last scoped validator command.
- UID0002DL generated output now emits `RenderTileFrame`, `FillRect`, free `GetItemGlyphBounds`, `DrawItemImageIn43x43Slot`, and `DrawItemImageUnscaled`.
- UID0002DL generated output no longer contains stale `ForwardToTileFrameBlitHelper`, `SelectionVectorContains`, `DrawWrappedFittingRoomItemName`, or `g_pItemObjImageLib->GetItemGlyphBounds` shape.

## Changed Files

Implementation callback files updated:

- `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`
- `by-class/FittingRoomListPane.md`
- `by-file/FittingRoom.md`
- `tools/leaser/Agents/Agent-B002/research/0002DL-FittingRoomListPaneOnPaint-source-quality.md`

Validator-owned side effects were reported by scoped validation/autogen refresh, including generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, `autogen_registry_update`, and `projected_stats_update`. B002 did not manually edit generated files, coverage reports, supervisor ledgers, validator state, queues, locks, lifecycle/archive files, or `-coverage-report.md` files.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 review accepted. Proof: user callback cites audit `2026-07-09T13:06:05-04:00 - B002 UID0002DL Gate 1 Audit`, state `GATE1_PASSED`, accepted SHA256 `E72A8F65FBB66A30DF2E35EA17AEA0B99C48CF0A1262BD8713A0A4169A7484B9`.
- [x] Lease acquired immediately before editing accepted by-* docs for UID0002DL implementation callback. Proof: `python .\tools\leaser\leaser.py B002 lease ...` returned `Success` for the target, class, and file docs.
- [x] Target edit applied to `by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md`: `COMPLETION:86` -> `COMPLETION:88`, `CONFIDENCE:90` -> `CONFIDENCE:91`, with `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000053` left unchanged.
- [x] Target `RECONSTRUCTION_CPP CODE` block replaced with the exact formal insertion text from `## First-Draft C++ Recommendation`. Proof: post-edit comparison reported `FORMAL_CPP_MATCHES_ACCEPTED_REPORT`.
- [x] Target evidence/source-quality wording updated to current MCP session `supervisor_nexustk_20260709`, current instruction count `618`, `RenderTileFrame` / [UID:0004H6], free `GetItemGlyphBounds`, caller-local selected-entry vector scan, caller-local wrapped text, and `FillRect`/fill-invalidate handling for `dword_69B3FC`.
- [x] Support edit applied to `by-class/FittingRoomListPane.md`: UID0002DL row/boundary caution synchronized from old `604` wording to current `618` wording, and helper notes mention `RenderTileFrame`, free `GetItemGlyphBounds`, selected-entry vector scan, caller-local text wrapping, and no class score change.
- [x] Support edit applied to `by-file/FittingRoom.md`: added source-context and change-log notes that UID0002DL uses corrected shared-helper names and no longer treats fixed-count UCRT format wrappers as project-owned helpers. No file score change.
- [x] Leave unchanged unless supervisor explicitly expands scope: `by-class/GrafPort.md`, `by-class/ItemObjImageLib.md`, `by-memory/0x0069b3fc-0x0069b3ff.SurfaceRenderCallbackTable.md`, WideFormat wrapper docs, coverage reports, supervisor ledgers, queues, locks, archives, lifecycle files, and all `-coverage-report.md` files. Proof: no manual edits were made to those files; generated/validator-owned side effects came only from the required scoped validators.
- [x] Claim ledger verification states updated during callback from `proposed` to `applied` for each C-0002DL row.
- [x] Scoped validator run after target edit: `python .\tools\validator.py --mode file --file by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md --apply --queue-timeout 240`. Proof: command `000000008130`, timestamp `2026-07-09T13:13:00-04:00`, exit `0`, `ok: 1`.
- [x] Scoped validator run after class support edit: `python .\tools\validator.py --mode file --file by-class/FittingRoomListPane.md --apply --queue-timeout 240`. Proof: command `000000008131`, timestamp `2026-07-09T13:13:11-04:00`, exit `0`, `ok: 1`.
- [x] Scoped validator run after file support edit: `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240`. Proof: command `000000008132`, timestamp `2026-07-09T13:13:18-04:00`, exit `0`, `ok: 1`; known `missing_ref_uid 0003AM` warnings remain.
- [x] Generated `auto-generated/NexusTK/cashshop/FittingRoom.cpp` checked after validator/autogen refresh, without manual generated-file edits. Proof: header command `000000008132`, refreshed at `2026-07-09T13:13:18-04:00`; UID0002DL output no longer contains stale `ForwardToTileFrameBlitHelper`, `SelectionVectorContains`, `DrawWrappedFittingRoomItemName`, or `g_pItemObjImageLib->GetItemGlyphBounds` shape.
- [x] Lease released immediately after validator batch and generated-output inspection. Proof: `python .\tools\leaser\leaser.py B002 unlease ...` returned `Success` for the target, class, and file docs.
- [x] Implementation callback stops at `READY_FOR_SUPERVISOR_EXECUTE` with report path/SHA256, changed files, leases used/released, validator command IDs/timestamps/results, generated-output check result, and boundary confirmations.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000008146","destination_path":"executed-b-agent-research/B002/0002DL-FittingRoomListPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002DL-FittingRoomListPaneOnPaint-source-quality.md","timestamp":"2026-07-09T13:25:28-04:00","uid":"0002DL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
