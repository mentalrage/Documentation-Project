** TARGET-REPORT-UID:0002T1 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002T1] IconsPaneOnPaint Source-Quality Report

Agent: Agent-B004  
Assignment: B004-report-0002T1-icons-pane-on-paint-20260625  
Target: `by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md`  
Mode: report-only; no by-* edits and no leases taken  
Date: 2026-06-25

## Recommendation

Implement [UID:0002T1] as a first-draft reconstructed `IconsPane::OnPaint` body in the target by-memory document.

The previous no-code blocker is stale. The current project gate is satisfied: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00006B`, and current target score average `(86 + 90) / 2 = 88`, which is above the 85 threshold. Live IDA MCP evidence also confirms the exact range, vtable-only reachability, resource operands, loop/control flow, helper calls, and state-field accesses.

Recommended target score update:

- Current: `COMPLETION:86`, `CONFIDENCE:90`
- Recommended: `COMPLETION:89`, `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:00006B`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:00006B`

Do not raise higher yet because several shared names remain source-facing reconstructions rather than proven original spellings: `SurfaceRenderCallbackTable::PreparePaneRegion`, `RenderTileFrame`, the inherited draw/blit-mode byte at `this+0x70`, and the public type/member spellings around `g_pEPFLib`. The exact `ICONS.EPD` package payload is also not present in current resource packages, although the binary operand and frame math are exact.

## MCP Evidence Provenance

IDA MCP was responsive and was used for this report. No fallback-only conclusion was made.

- Endpoint checked: `http://127.0.0.1:13337/mcp`
- TCP listener: `127.0.0.1:13337` responded
- JSON-RPC `initialize`: HTTP 200, server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`
- `tools/list`: HTTP 200; IDB-backed tools require a `database` argument
- `idb_list`: active session `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path reported by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

Primary MCP calls used:

- `lookup_funcs` for `0x004cf300`, nearby IconsPane methods, and helper callees
- `analyze_function` for `0x004cf300`, `0x004b9660`, `0x004b9980`, `0x004d02f0`, `0x00457a60`
- `disasm` for `0x004cf300`
- `xrefs_to` for `0x004cf300`, `0x0061b48c`, `0x0061b554`, `0x006152ec`, `0x0067a744`, `0x0069b3fc`, and helper functions
- `callees` for `0x004cf300`
- `make_signature_for_range` for `0x004cf300-0x004cf3d3`

One attempted `get_bytes` request used the wrong argument shape for the current MCP schema and returned parse errors. That was a schema mismatch only; MCP itself remained responsive and the required byte/string/callee evidence was available through disassembly, xrefs, decompilation, and support docs.

## Current Target State

The target document currently describes the correct high-level behavior but leaves the formal C++ block blank under an obsolete stricter 95+ gate and older helper-name blockers.

Current target metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:00006B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006B`
- Formal C++ block: blank

The current summary is substantively correct:

- Initializes a tile context
- Clears draw state
- Prepares the pane region using `this + 0x44`
- Starts at icon index 0 when `this+0xf8` is true, otherwise index 6
- Draws 20-pixel-wide slots until `x < 160`
- Uses pressed/selected frames `iconIndex + 8` when `this+0xfc == iconIndex` and `this+0x100` is true
- Loads frames from `ICONS.EPD`
- Renders through `NPAL7.PAL`

The target should be updated from "ready but blank" to "first-draft C++ present, support names source-facing."

## IDA MCP Facts

Function boundary:

- `0x004cf300`: `sub_4CF300`
- Size: `0xd3` bytes
- Range: `0x004cf300-0x004cf3d3`
- Next IconsPane function starts at `0x004cf3e0`
- `0x004cf3d3` is not a separate function
- No split is needed

Reachability:

- Direct code callers: none reported
- Data xref: `0x0061b48c -> 0x004cf300`
- This is the IconsPane vtable OnPaint slot and supports class ownership through `IconsPane`

Core target disassembly/decompilation facts:

- `0x004cf310`: reads `dword_67A744`
- `0x004cf320`: calls `sub_457A60` on a stack tile context
- `0x004cf329`: calls `sub_4B9660(this, 0)`
- `0x004cf331`: stores zero to byte `[this+0x70]`
- `0x004cf338`: calls `dword_69B3FC(this, this+0x44)`
- `0x004cf340`: initializes `iconIndex = 6`
- `0x004cf345-0x004cf34b`: if byte `[this+0xf8]` is nonzero, start index becomes `0`
- `0x004cf34e-0x004cf351`: computes `x = iconIndex * 20`
- `0x004cf35b-0x004cf36b`: if `iconIndex == [this+0xfc]` and byte `[this+0x100]` is nonzero, draw frame `iconIndex + 8`; otherwise draw `iconIndex`
- `0x004cf379`: pushes `offset off_61B554` (`ICONS.EPD`)
- `0x004cf37e`: calls `sub_4D02F0`
- `0x004cf385`: pushes `offset off_6152EC` (`NPAL7.PAL`)
- `0x004cf3b1`: calls `sub_4B9980`
- `0x004cf3b4-0x004cf3ba`: increments `x` by 20
- `0x004cf3ba-0x004cf3c0`: loops while `x < 160`
- `0x004cf3ca`: compiler stack-cookie check

Resource xrefs:

- `0x0061b554` (`ICONS.EPD`) has a single code data xref at `0x004cf379` inside this target
- `0x006152ec` (`NPAL7.PAL`) has ten code data xrefs; this target contributes `0x004cf385`

Helper fan-in confirms shared utility status rather than target-local ownership:

- `sub_4D02F0`: 440 xrefs
- `sub_4B9980`: 311 xrefs
- `sub_457A60`: 337 xrefs
- `sub_4B9660`: 319 xrefs
- `dword_69B3FC`: 206 xrefs

The unique range signature was produced successfully by MCP. This supports stable function identity for later validation and diff review.

## Helper Resolution

The helper names below are sufficiently supported for first-draft source reconstruction. They should be treated as source-facing names unless and until a stronger original symbol is recovered.

| Binary artifact | Recommended source-facing role | Evidence |
| --- | --- | --- |
| `sub_457A60` | `EPFTileContext::Initialize()` | Initializes a 0x28-byte tile context; support docs and accepted paint reconstructions use this role. |
| `sub_4B9660(this, 0)` | `SetDrawColor(0)` / `GrafPort::SetDrawColor(0)` | Stores the argument at `this+0x74`; broad GrafPort draw-state accessor. |
| direct store `[this+0x70] = 0` | inherited draw/blit-mode byte, recommended field spelling `m_drawMode = 0` | Exact direct field write in target; final source spelling remains inferred. |
| `dword_69B3FC(this, this+0x44)` | `SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds)` | Slot-7 surface/pane-region callback; accepted `ParcelPane::OnPaint` uses the same source-facing pattern. |
| `sub_4D02F0(dword_67A744, L"ICONS.EPD", frame, &tileContext)` | `g_pEPFLib->LookupLayoutEntry(L"ICONS.EPD", frame, &tileContext)` | Resource-layout lookup helper writes the tile context from a named EPF/EPD frame. |
| `sub_4B9980(&tileContext, &tileContext.bounds, &iconRect, 0, L"NPAL7.PAL", 0)` | `RenderTileFrame(...)` | Palette lookup plus slot-2 render forwarder; accepted paint reconstructions use this role. |
| `dword_67A744` | `g_pEPFLib` | Existing global/support documentation treats it as the ImageLib/EPF resource-layout singleton. |

Important negative resolutions:

- Do not document `dword_69B3FC` as stale generated `g_pfnLockSurface`; the support page already rejects that alias.
- Do not make `ICONS.EPD` or `NPAL7.PAL` the owner. They are resource operands.
- Do not assign canonical ownership to EPF/ImageLib/GrafPort helper pages. Those are shared dependencies.
- Do not keep the formal C++ blank merely because the helper spellings are source-facing. Current gate and accepted nearby reconstructions allow a draft with caveats.

## Ownership Ranking

1. `by-class/IconsPane.md` / `NexusTK::IconsPane` is the correct semantic owner. The method uses IconsPane fields at `+0xf8`, `+0xfc`, and `+0x100`, is reached through the IconsPane vtable, and matches adjacent IconsPane hit-test/highlight logic.
2. `by-file/IconsPane.md` is the source-file route for implementation. The method belongs in the IconsPane source unit with the other core pane methods.
3. `by-resource/iconspane-icon-resources.md` is supporting evidence only. It should carry operand and package caveats, not ownership.
4. `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-class/EPFTileContext.md`, and `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md` are support pages only.

No no-owner classification is warranted.

## Range And Split Decision

Keep the target exact range `0x004cf300-0x004cf3d3`.

Reasons:

- MCP resolves `0x004cf300` as a single `0xd3`-byte function.
- The next nearby method starts at `0x004cf3e0`.
- The data xref at `0x0061b48c` points exactly to `0x004cf300`.
- The function has one coherent paint-handler body: initialize context, prepare region, compute icon-strip start, loop over slots, draw frames.
- The stack-cookie call is compiler epilogue and belongs to the function range.

No helper extraction, split, merge, or range expansion is recommended.

## Field And Resource Semantics

Recommended field notes for target/support synchronization:

- `this+0x44`: pane bounds/paint bounds passed to the slot-7 surface callback.
- `this+0x70`: inherited active draw/blit-mode byte; target clears it before drawing.
- `this+0x74`: inherited draw color/state written by `SetDrawColor(0)`.
- `this+0xf8`: `m_showAllIcons`; true starts at icon index 0, false starts at icon index 6.
- `this+0xfc`: `m_selectedIconIndex`.
- `this+0x100`: `m_isPressed` / pressed-highlight flag.

Recommended resource notes:

- `ICONS.EPD` is the frame source for this pane.
- `NPAL7.PAL` is the palette operand passed to the render helper.
- Frame IDs 0-7 are normal frames in the full-icon strip.
- Frame IDs 8-15 are pressed/highlight variants selected by `iconIndex + 8`.
- Reduced mode starts from frame/index 6 and therefore draws indexes 6 and 7 at `x=120` and `x=140`.
- Full mode starts from frame/index 0 and draws eight slots from `x=0` through `x=140`.

## Formal C++ Recommendation

Use a formal `RECONSTRUCTION_CPP CODE` block in the target. The spelling below follows current support docs and accepted nearby paint-handler precedent. The only intentionally inferred member spelling is `m_drawMode` for the inherited byte at `this+0x70`.

Paste-ready target block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IconsPane::OnPaint()
{
    EPFTileContext tileContext;
    RectBounds iconRect;

    tileContext.Initialize();

    SetDrawColor(0);
    m_drawMode = 0;
    SurfaceRenderCallbackTable::PreparePaneRegion(this, &m_bounds);

    int iconIndex = m_showAllIcons ? 0 : 6;
    int x = iconIndex * 20;

    while (x < 160) {
        int frameIndex = iconIndex;
        if (iconIndex == m_selectedIconIndex && m_isPressed) {
            frameIndex += 8;
        }

        g_pEPFLib->LookupLayoutEntry(L"ICONS.EPD", frameIndex, &tileContext);

        InitRectBounds(&iconRect, x, 0, x + 19, 14);
        RenderTileFrame(&tileContext,
                        &tileContext.bounds,
                        &iconRect,
                        0,
                        L"NPAL7.PAL",
                        0);

        x += 20;
        ++iconIndex;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

During implementation, only modify the target content between `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END`; leave the marker lines themselves intact. Do not use a raw `sub_4CF300`, `sub_4D02F0`, `sub_4B9980`, `unk_69B3FC`, or `field_70` style final C++ block. Those names may be retained in evidence notes, but the reconstruction block should be source-facing.

## Target Doc Update Details

Apply these edits to `by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` if accepted:

- Update score to `COMPLETION:89`, `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006B`.
- Replace the stale "blank under 95+ gate/helper names unresolved" blocker with the current gate explanation.
- Add MCP evidence provenance: session `80de0a67`, function size `0xd3`, vtable xref `0x0061b48c`, resource xrefs, and helper fan-in counts.
- Add the formal C++ block above.
- Document `this+0x70` as a cleared inherited draw/blit-mode byte with inferred source spelling.
- Document `dword_69B3FC` as the slot-7 pane-region callback, not as stale `g_pfnLockSurface`.
- Record the exact loop geometry and frame selection:
  - start `0` when `m_showAllIcons` is true
  - start `6` when false
  - x coordinate equals `iconIndex * 20`
  - destination rect `(x, 0, x + 19, 14)`
  - loop while `x < 160`
  - selected pressed frame equals `iconIndex + 8`
- Mark old shared-helper spelling caveats as nonblocking support caveats.

## Support Synchronization Details

Update only support pages that already own the relevant class/file/resource/helper facts. Do not edit generated reports or coverage reports.

### `by-class/IconsPane.md`

Recommended score update:

- Current: `COMPLETION:86`, `CONFIDENCE:88`
- Recommended: `COMPLETION:87`, `CONFIDENCE:89`

Sync details:

- Mark [UID:0002T1] `IconsPane::OnPaint` as first-draft reconstructable with C++ in the exact child page.
- Keep class-level C++ blank/aggregate-oriented if that is the current class convention.
- Add or update notes for fields `m_showAllIcons`, `m_selectedIconIndex`, and `m_isPressed` as consumed by OnPaint.
- Add the `this+0x70` inherited draw/blit-mode caveat if the class doc has a field/state caveat section.
- Keep raw action-dispatch and uncovered gap blockers scoped to the relevant mouse/action methods, not to OnPaint.

### `by-file/IconsPane.md`

Recommended score update:

- Current: `COMPLETION:87`, `CONFIDENCE:86`
- Recommended: `COMPLETION:88`, `CONFIDENCE:87`

Sync details:

- Note that `IconsPane::OnPaint` now has a formal first-draft child reconstruction.
- Keep file-level caveats for raw action dispatch and the `0x004cf74b-0x004cf7d0` gap.
- Do not let the file-level caveats suppress the exact child C++ block.
- Keep file ownership through the IconsPane source unit.

### `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`

Recommended score update: none required.

Sync details:

- Update the [UID:0002T1] child row/status to say `OnPaint` now has a first-draft C++ block in the exact child page.
- Keep the aggregate C++ marker-only.
- Keep range/gap caveats scoped to the aggregate and non-OnPaint children.

### `by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md`

Recommended score update: none required.

Sync details:

- Add the primary vtable slot evidence `0x0061b48c -> 0x004cf300 IconsPane::OnPaint`.
- Note that `OnPaint` is vtable-only reached in MCP and should not be treated as dead code.
- Keep the vtable page non-emitting/data-support only.

### `by-resource/iconspane-icon-resources.md`

Recommended score update: none required.

Sync details:

- Add that `ICONS.EPD` has a single code xref from `IconsPane::OnPaint` at `0x004cf379`.
- Add that `NPAL7.PAL` is passed by `IconsPane::OnPaint` at `0x004cf385`.
- Keep the current caveat that the current packages expose `ICONS.EPF` but not exact `ICONS.EPD` payload.
- Reclassify that caveat as a resource-packaging/frame-name caveat, not a blocker for OnPaint first-draft code.

### `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`

Recommended score update: none required.

Sync details:

- Add `IconsPane::OnPaint` as a slot-7 consumer: `dword_69B3FC(this, this+0x44)` after `SetDrawColor(0)` and after clearing the draw/blit-mode byte.
- Add a note that this is a pane-region preparation/fill/presentation callback used before drawing the icon strip.
- Preserve the rejection of stale generated alias `g_pfnLockSurface`.

### `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`

Recommended score update: none required.

Sync details:

- Add `IconsPane::OnPaint` as a consumer of `sub_4B9660(this, 0)`.
- Note that OnPaint also directly clears `this+0x70`, while `sub_4B9660` writes `this+0x74`.
- Keep `SetDrawColor(0)` / active draw-state naming as source-facing unless a stronger original name is recovered.

### No Support Edit Required

The following pages were checked and already provide enough context for this target. No direct edit is required unless the supervisor wants cross-reference polish:

- `by-class/EPFTileContext.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-global/g_pEPFLib.md`
- `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
- Accepted precedent pages such as `ParcelPaneOnPaint` and `TotemFrame`

## Manual Coverage Instructions

Do not manually edit `by-memory/-coverage-report.md`, `by-resource/-coverage-report.md`, or any other `-coverage-report.md`.

Expected generated coverage effect after implementation and validator refresh:

- The exact target should move from blank formal C++ to first-draft source reconstruction.
- The support docs should gain cross-reference/detail sync.
- Coverage reports should be regenerated only by the appropriate validator pipeline, not by hand.

No manual coverage row text is proposed.

## Scoped Validators For Implementation Callback

After accepted implementation edits, run validators scoped to only the files edited. Suggested validator scope if all recommended support sync is accepted:

- `by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md`
- `by-class/IconsPane.md`
- `by-file/IconsPane.md`
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- `by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md`
- `by-resource/iconspane-icon-resources.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`

Do not run broad validators that rewrite unrelated generated/cache state. If the validator scripts refresh generated coverage reports, confirm whether those generated outputs must be excluded or reverted according to supervisor instruction before final closeout.

## Lease Instructions For Implementation Callback

No lease was taken for this report-only assignment.

For the later implementation callback, lease only immediately before editing accepted target/support by-* docs and release immediately after scoped validation. Do not lease during research. Do not edit lease files except through the project leaser workflow.

## Implementation Checklist

- [x] Supervisor validates/accepts this report before any by-* edit.
  - Proof: updated `goal.md` assignment `B004-implement-0002T1-icons-pane-on-paint-20260625` states this report was accepted for implementation.
- [x] Lease the accepted target/support docs immediately before implementation.
  - Proof: `python .\tools\leaser\leaser.py B004 lease ...` returned `Success` for all eight accepted by-* docs before edits.
- [x] Update `by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md` metadata to `89/91`, preserve owner/emitter, add MCP evidence, replace stale blocker, and add the formal C++ block.
  - Proof: target metadata now reads `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`; formal `IconsPane::OnPaint` C++ is present in `RECONSTRUCTION_CPP CODE`; sections `Raw Code Evidence`, `Reconstruction Notes`, `Score Rationale`, `Parent Gate`, and `Changes` now include session `80de0a67`, helper fan-in, resource xrefs, vtable reachability, current code-entry gate, and stale 95+ blocker supersession.
  - Validator proof: `python .\tools\validator.py --mode file --file by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md --apply --queue-timeout 240`, `command_id: 000000001298`, `command_timestamp: 2026-06-25T05:56:57-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-class/IconsPane.md` to `87/89` and synchronize the OnPaint child status/field caveats.
  - Proof: class metadata now reads `87/89`; layout/status/method/autogen/change sections record `OnPaint` first-draft C++ in the exact child, `m_showAllIcons`, `m_selectedIconIndex`, `m_isPressed`, inherited `this+0x70` / inferred `m_drawMode`, slot-7 callback use, and caveat scoping away from raw action-dispatch/gap issues.
  - Validator proof: `command_id: 000000001299`, `command_timestamp: 2026-06-25T05:56:59-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-file/IconsPane.md` to `88/87` and synchronize OnPaint first-draft status while preserving file-level raw-dispatch/gap caveats.
  - Proof: file metadata now reads `88/87`; score rationale, behavior notes, data caveats, and changes record exact child `OnPaint` first-draft status while preserving `0x004cf8e0` raw dispatcher and `0x004cf74b-0x004cf7d0` gap caveats.
  - Validator proof: `command_id: 000000001300`, `command_timestamp: 2026-06-25T05:57:00-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` child status while keeping aggregate C++ marker-only.
  - Proof: covered-range table, resource-xref note, behavior summary, data issues, and changes now state [UID:0002T1] has first-draft C++ in the exact child; aggregate `RECONSTRUCTION_CPP CODE` remains marker-only.
  - Validator proof: `command_id: 000000001301`, `command_timestamp: 2026-06-25T05:57:02-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md` with `0x0061b48c -> IconsPane::OnPaint`.
  - Proof: summary, observed contents, evidence, reconstruction notes, and changes now record primary vtable slot `0x0061b48c -> 0x004cf300 IconsPane::OnPaint`, vtable-only reachability, and non-dead-code status.
  - Validator proof: `command_id: 000000001302`, `command_timestamp: 2026-06-25T05:57:03-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-resource/iconspane-icon-resources.md` with the `ICONS.EPD` and `NPAL7.PAL` OnPaint xrefs and nonblocking resource-packaging caveat.
  - Proof: confirmed resources, blocker classification, rebuild notes, IDA MCP evidence, and changes now record `ICONS.EPD` xref `0x004cf379`, `NPAL7.PAL` use `0x004cf385`, ten total palette xrefs, and missing exact `ICONS.EPD` payload as a resource-packaging/frame-name caveat rather than an `OnPaint` C++ blocker.
  - Validator proof: `command_id: 000000001303`, `command_timestamp: 2026-06-25T05:57:04-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` with the `dword_69B3FC` IconsPane slot-7 consumer note.
  - Proof: representative dispatch evidence, xref summary, and changes now record `IconsPane::OnPaint` as a slot-7 consumer, `dword_69B3FC(this, this+0x44)` after `SetDrawColor(0)` and direct `this+0x70` clear, before the icon-strip draw loop; stale `g_pfnLockSurface` is rejected for this callsite.
  - Validator proof: `command_id: 000000001304`, `command_timestamp: 2026-06-25T05:57:06-04:00`, exit `0`, `ok: 1`.
- [x] Update `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md` with the `SetDrawColor(0)` / `this+0x70` OnPaint note.
  - Proof: covered-functions table, evidence notes, and changes now record `IconsPane::OnPaint` as a `sub_4B9660(this, 0)` consumer, with `sub_4B9660` writing `this+0x74` and direct `this+0x70` clear kept as separate inherited draw/blit-mode behavior.
  - Validator proof: `command_id: 000000001305`, `command_timestamp: 2026-06-25T05:57:07-04:00`, exit `0`, `ok: 1`.
- [x] Run scoped validators only for edited files.
  - Proof: ran exactly the file-scoped validator command for each of the eight edited by-* docs above from `source-3/project-documentation`. All eight exited `0` with `ok: 1`. Validator output initially reported deferred generated refresh and projected stats updates; those were validator-owned side effects, not manual edits. Final `python .\tools\validator.py --queue-status` returned `command_id: 000000001307`, `command_timestamp: 2026-06-25T05:59:02-04:00`, with `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- [x] Do not manually edit generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: manual edits were limited to the eight accepted by-* docs and this Agent-B004 research report checklist. No manual edits were made to generated files, project-level files, coverage reports, validator state/cache, or IDA DB. Scoped validator output did report tool-owned projected stats/autogen registry/generated-refresh side effects.
- [x] Release the lease immediately after validation.
  - Proof: after validation, `python .\tools\leaser\leaser.py B004 unlease ...` returned `Rejected[No active lease]` for each accepted by-* path, meaning the short leases had already expired by cleanup. The current lease report was then checked and shows no active B004 leases.
- [x] Final implementation closeout reports edited files, validators, lease release, and any remaining source-facing name caveats.
  - Proof: final response must report the eight edited by-* docs plus this report, validator IDs `000000001298` through `000000001305`, lease expiry/no-active-lease state, deferred generated-refresh state, score/metadata before-after, and remaining source-facing caveats for `m_drawMode`, `PreparePaneRegion`, `LookupLayoutEntry`, `RenderTileFrame`, `g_pEPFLib`, and exact legacy `ICONS.EPD` payload/frame names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002T1-IconsPaneOnPaint-source-quality-report.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0002T1-IconsPaneOnPaint-source-quality-report.md","timestamp":"2026-06-25T06:02:47","uid":"0002T1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
