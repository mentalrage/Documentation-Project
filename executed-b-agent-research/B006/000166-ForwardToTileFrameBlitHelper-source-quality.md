** TARGET-REPORT-UID:000166 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID000166 ForwardToTileFrameBlitHelper Source-Quality Report

## Final Recommendation

Raise [UID:000166] `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md` from `85/88` to `88/91`, reroute direct owner/emitter from [UID:0000OC] `Surface` to [UID:00005V] `GrafPort`, and populate a first-draft `GrafPort` helper body. Keep [UID:0000OC] `Surface` and [UID:0000TN] `SurfaceRenderCallbackTable` as dependency/support context only.

The decisive current-session change is receiver evidence. Earlier support wording said UID000166 has no GrafPort receiver and should stay Surface/file-local. Current MCP disassembly proves the opposite: all three live callers set `ecx` to the drawing object immediately before `call sub_4B99F0`, and UID000166 saves that incoming `ecx` at `0x004b9a01`, restores it at `0x004b9a3a`, then calls slot 2 / `dword_69B3E8` with the destination receiver still in `ecx`. This matches the accepted slot-2 receiver model used by `GrafPort::BlitSurface` and `GrafPort::DrawTiledBackground`.

## Target

- UID: `000166`.
- Target path: `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`.
- Target title/range: `0x004b99f0-0x004b9a63 ForwardToTileFrameBlitHelper`.
- Assignment/report path: `tools/leaser/Agents/Agent-B006/research/000166-ForwardToTileFrameBlitHelper-source-quality.md`.
- Tracker row/source: `auto-generated/-ag-research-tracker.md`, `## by-memory`, `### Not-Covered Files - Reconstructable`; current row lists UID000166 at `85/88`, combined `86.5`, reconstructable `true`, Reports `0`, target path `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`.
- Current scores: `COMPLETION:85`, `CONFIDENCE:88`.
- Current parent/owner/emitter state: `CANONICAL_OWNER:0000OC`, [UID:0000OC] `Surface`; `EMITTER_UIDS:0000OC`; current generated route is `auto-generated/NexusTK/render/Surface.cpp`.
- Current reconstructable state: `RECONSTRUCTABLE:TRUE`.
- Current formal code state: blank `RECONSTRUCTION_CPP CODE`; generated `Surface.cpp` currently contains a UID000166 `Empty Emitter Marker`.
- Recommended implementation state: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`, `RECONSTRUCTABLE:TRUE`, formal `GrafPort::ForwardToTileFrameBlitHelper` C++ block populated under UID000166.

## Current Target State

- Target: [UID:000166] `0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current generated marker: `auto-generated/NexusTK/render/Surface.cpp` line 160 is an `Empty Emitter Marker` for UID000166 at `85/88`.
- Research tracker row: `auto-generated/-ag-research-tracker.md` lists UID000166 under not-covered reconstructable files at `85/88`, combined `86.5`, `Reports 0`.
- Current generated memory coverage: `auto-generated/-ag-memory-coverage.md` says the target emits through `0000OC` but has `emits_code:no`.

## Evidence Checked

Target-specific MCP checks:

- `idb_list`: active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active and not analyzing.
- `server_health` with `database=supervisor_resume_20260629`: server ok, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs`: checked `0x004b99f0`, `0x004b9a62`, `0x004b9a63`, `0x004b9980`, `0x004b99c0`, `0x004b99ee`, and `0x004b9a70`; confirmed UID000166 size `0x73`, exclusive end `0x004b9a63`, raw sibling non-functions, and successor `0x004b9a70`.
- `decompile 0x004b99f0`: confirmed offset-rectangle construction and slot-2 callback dispatch.
- `disasm 0x004b99f0`: confirmed hidden receiver save/restore, source rect loads, local `RectBounds` construction, callback argument order, security-cookie check, and `retn 18h`.
- `callees 0x004b99f0`: confirmed only `sub_4B78D0`, `unk_69B3E8`, and `@__security_check_cookie@4`.
- `xrefs_to` / `xref_query 0x004b99f0`: confirmed exactly three direct code callers at `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- `decompile 0x004b5810` and `decompile 0x005c3950`: checked caller semantics for FolderTreePane/tree traversal drawing and WorldMapPane drawing.
- Caller disassembly windows around `0x004b5917`, `0x005c3b60`, and `0x005c3db0`: confirmed each caller sets `ecx` to the draw object immediately before the call and pushes x/y/source/palette/mode/options.

Manual/byte/generated checks:

- `get_bytes`: confirmed two `0xcc` bytes before UID000166, the 115-byte body, and thirteen `0xcc` bytes after it.
- Target doc read: checked current metadata, behavior, caller evidence, Surface ownership wording, score rationale, and blank C++.
- Support docs read: `SurfacePaintHelpers`, `SurfaceSpriteBlitHelper`, `GrafPortDrawTiledBackground`, `Surface`, `GrafPort` class/file, and `SurfaceRenderCallbackTable`.
- Generated files read-only checked: `auto-generated/NexusTK/render/Surface.cpp`, `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`.
- Existing report searches: searched UID/address/name/tile-frame/blit/rendering/owner/source-family terms across active/executed B-agent research; relevant matches were B003 UID000167, B005 Surface empty-emitter family, B007 UID00035C, B004 EPFTileContext, B002 UID00016A, and related no-route positive-control reports.

Negative checks and failed/skipped checks:

- Checked and rejected Surface direct owner, feature-owner routes, callback-table target route, PaletteLib ownership, and no-code/covered-by route.
- Checked prior B003 "no GrafPort receiver" statement and rejected it as stale under current disassembly.
- MCP calls using `database=NexusTK.exe` failed with `Session not found`; the corrected session id was `supervisor_resume_20260629`.
- An early wrapper accidentally used PowerShell automatic `$args`, producing `database is required`; rerun with a corrected wrapper succeeded. This was not MCP unavailability.
- The older `callers` tool name is not present on the current MCP server; `xrefs_to` and `xref_query` supplied the caller proof instead.
- No local PE no-route scan was needed for UID000166 because MCP reports a modeled function and three direct code callers; prior local PE scans in B002/B004/B005/B007 already use UID000166's three rel32 callers as positive controls.
- No validators were run and no generated/coverage/project-level files were edited because this is report-only repair.

## Evidence Sources Checked

- `goal.md` for Agent-B006 assignment `B006-report-000166-ForwardToTileFrameBlitHelper-20260702`.
- Project-level `ntk-b-agent-workflow` skill and required report/source-quality references.
- Target page `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`.
- Support pages: `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`, `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`, `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`, `by-file/Surface.md`, `by-class/GrafPort.md`, `by-file/GrafPort.md`, and `by-global/SurfaceRenderCallbackTable.md`.
- Generated state read-only checks: `auto-generated/NexusTK/render/Surface.cpp`, `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/-ag-memory-coverage.md`.
- Existing report search terms: `000166`, `004b99f0`, `004b9a63`, `ForwardToTileFrameBlitHelper`, `RenderTileFrame`, `dword_69B3E8`, `SurfaceSpriteBlitProc`, `FrameDrawRecord`, `TileFrame`, `GrafPort`, `Surface`.

Relevant prior report matches:

- B003 `000167-SurfaceSpriteBlitHelper-source-quality.md`: says UID000166 should stay Surface/file-local because it has no GrafPort receiver. This statement is superseded by current MCP caller/target disassembly.
- B005 `0000OC-Surface-empty-emitter-family-source-quality.md`: keeps UID000166 blank because wrapper signature/typedef was not source-ready. This is partly superseded by current `SurfaceRenderCallbackTable` slot-2 support, which now accepts `SurfaceSpriteBlitProc` with nullable `const SurfaceSpriteBlitOptions *options`; the exact helper signature is now recoverable.
- B007 `00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality.md`: uses UID000166 as a positive-control live reachable sibling with three direct callers. That remains valid.
- B004 `00004I-EPFTileContext-class-source-quality.md` and B002 `00016A-GrafPortDrawTiledBackground-source-quality.md`: support broad slot-2 source descriptor use and `FrameDrawRecord` / EPF-compatible source rectangle typing.

## Positive Evidence Summary

The strongest direct facts are current and mutually reinforcing:

- UID000166 is a modeled function with exact half-open range `0x004b99f0-0x004b9a63` and size `0x73`; `0x004b9a62` is inside the function and `0x004b9a63` is outside it.
- The body is isolated from neighbors by padding: `0x004b99ee-0x004b99f0` is two `0xcc` bytes before the function and `0x004b9a63-0x004b9a70` is thirteen `0xcc` bytes after it.
- The wrapper has three live direct code callers: `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- All three direct callers set `ecx` to the draw object immediately before `call sub_4B99F0`; this proves the helper has a hidden destination draw receiver.
- The target saves incoming `ecx` at `0x004b9a01`, constructs a local destination rectangle from caller x/y offsets plus source descriptor rect fields at `+0x10..+0x1c`, restores saved `ecx` at `0x004b9a3a`, then calls slot 2 / `dword_69B3E8`.
- The target's callback argument order is source descriptor, source rect pointer, destination rect, mode, palette, options; helper argument 5 becomes callback mode and helper argument 4 becomes callback palette.
- Current `SurfaceRenderCallbackTable` support has already resolved slot 2 enough for first-draft source: `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, `int` return, destination draw receiver in `ecx`, six stack arguments, and nullable opaque `const SurfaceSpriteBlitOptions *options`.
- Accepted sibling pages [UID:000167] `GrafPort::BlitSurface` and [UID:00016A] `GrafPort::DrawTiledBackground` route to GrafPort for the same destination-receiver plus slot-2 callback pattern. UID000166 is smaller, but the ownership signal is the same.

Strongest inference chain: current MCP proves a hidden draw receiver; accepted slot-2 support defines that receiver as the destination GrafPort/draw object; accepted GrafPort siblings route comparable receiver/callback wrappers through [UID:00005V]; therefore UID000166 should stop being a Surface-emitted empty marker and become a small GrafPort-routed first-draft helper.

## Negative Evidence Summary

Checked and rejected routes:

- Surface direct ownership: rejected as the direct owner for this exact helper. Surface still owns callback-table/backend context, but current disassembly proves a hidden destination draw receiver and no Surface-specific state. Emitting under `Surface.cpp` would either require artificial `__thiscall` ABI scaffolding or an explicit receiver argument the callers do not push.
- Feature-owner routes: rejected for `FolderTreePane` and `WorldMapPane`. They are consumers only; the three callers span tree and world-map draw paths, and the helper body has no feature fields, feature globals, packet state, or UI-specific policy.
- Callback-table target route: rejected. UID000166 calls `dword_69B3E8`; it is not assigned into the callback table. Slot 2 targets remain the software render callback functions, while UID000166 is an ordinary direct-call wrapper.
- No-code route: rejected for this target after current recheck. Unlike UID00035C, UID000166 has a modeled function and three direct code callers. It is not padding, not an aggregate, not covered by a child page, and not blocked by absent entry route.
- Prior B003 no-GrafPort-receiver claim: rejected as stale. Current target disassembly and caller instruction windows directly show caller-set `ecx`, target save/restore of `ecx`, and slot-2 dispatch with that receiver.
- PaletteLib ownership: rejected. UID000166 does not call PaletteLib; all currently known direct callers pass `0` for palette.
- Confidence caps: original helper spelling is not recovered; `FrameDrawRecord` versus `TileFrameDrawRecord` remains a source-facing type-name caveat; `SurfaceSpriteBlitOptions` remains intentionally opaque because UID00041R/UID00041U prove nonuniform option initialization/reads; and the implementation needs coordinated support wording in GrafPort/Surface helper docs.

## Heuristic / Inference Reanalysis And Validation

Helper role:

- Direct behavior is not heuristic: MCP decompile/disassembly shows a compact wrapper that offsets a source-record rectangle by caller x/y coordinates, builds a local destination `RectBounds`, and forwards to slot 2 / `dword_69B3E8`.
- The best source-facing role is a small tile/frame offset blit forwarder. It is not a full renderer, not a callback target, and not a feature-specific draw method.

Source placement:

- Existing placement under [UID:0000OC] `Surface` is understandable as callback-table neighborhood context, but current receiver evidence makes it weaker as direct source placement.
- The recommended placement is [UID:00005V] `GrafPort`, emitted through [UID:0000JR] `GrafPort` / `NexusTK/render/GrafPort.cpp`, because the hidden receiver is the destination draw object and accepted slot-2 siblings route through GrafPort.
- Surface should remain dependency context for callback table ownership, software-render target families, and the surrounding `SurfacePaintHelpers` address neighborhood.

Owner/emitter candidates:

- `GrafPort` owner/emitter: accepted recommendation. Matches hidden receiver, accepted sibling precedent, and slot-2 `SurfaceSpriteBlitProc` destination receiver.
- `Surface` owner/emitter: rejected as direct owner. It would require source-unfriendly ABI scaffolding or a mismatched explicit receiver model.
- `FolderTreePane` / `WorldMapPane`: rejected. They are direct consumers only.
- `SurfaceRenderCallbackTable`: rejected. UID000166 consumes `dword_69B3E8`; it is not installed as a callback target.
- `PaletteLib`: rejected. UID000166 does not resolve palettes and currently receives null palette from known callers.

Type/name direction:

- `GrafPort::ForwardToTileFrameBlitHelper` is the safest first-draft method spelling because it preserves the target identity while reflecting behavior.
- `FrameDrawRecord` / possible `TileFrameDrawRecord` is the best current source descriptor type; exact original spelling remains confidence-capping only.
- `RectBounds` is supported by the existing rectangle initializer at `0x004b78d0`.
- `SurfaceSpriteBlitProc g_pfnBlitSprite` and nullable `const SurfaceSpriteBlitOptions *options` are accepted slot-2 direction from current callback-table support; the options structure stays opaque.

Raw/caller evidence:

- Raw bytes, function lookup, and padding prove an exact isolated 115-byte source-authored function.
- Caller xrefs prove three live direct routes.
- Caller instruction windows prove the hidden receiver setup at every route, resolving the core ownership dispute.

Rejected alternatives:

- No-code path is rejected for the primary recommendation because the function is reachable, modeled, and source-shape-ready after GrafPort reroute.
- Surface formal C++ is rejected because it would encode an artificial ABI shape.
- Feature-owner and callback-table target routes are rejected for lack of supporting state/registration evidence.

Final C++ readiness:

- Formal C++ is ready only as UID000166 insertion content after changing `CANONICAL_OWNER`/`EMITTER_UIDS` to `00005V`.
- The formal block should not be inserted under the current Surface route.
- Remaining uncertainty is limited to original helper/type spelling and opaque options layout, not behavior, range, caller route, owner family, or callback argument order.

## Current MCP Session Facts

- Active session from `idb_list`: `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, not analyzing, worker PID `14860`.
- Initial calls using `database=NexusTK.exe` failed with `Session not found: NexusTK.exe`; calls using an invalid PowerShell `$args` wrapper also returned `database is required`. These were wrapper/schema errors, not MCP unavailability.
- Corrected `server_health` with `database=supervisor_resume_20260629`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Function, Boundary, And Padding Evidence

MCP `lookup_funcs`:

| Query | Result |
| --- | --- |
| `0x004b99f0` | `sub_4B99F0`, size `0x73`. |
| `0x004b9a62` | Still inside `sub_4B99F0`. |
| `0x004b9a63` | Not a function; correct exclusive end. |
| `0x004b9980` | `sub_4B9980`, size `0x31`. |
| `0x004b99c0` / `0x004b99ee` | Not functions; sibling raw helper area. |
| `0x004b9a70` | Successor `sub_4B9A70`, size `0x7da`. |

MCP `get_bytes`:

- `0x004b99b1-0x004b99c0`: fifteen `0xcc` bytes before UID00035C.
- `0x004b99ee-0x004b99f0`: two `0xcc` bytes before UID000166.
- `0x004b99f0-0x004b9a63`: 115-byte body beginning `55 8b ec 83 ec 1c` and ending `5d c2 18 00`.
- `0x004b9a63-0x004b9a70`: thirteen `0xcc` bytes after UID000166.

## Raw Behavior

MCP decompile:

```c
int __stdcall sub_4B99F0(int a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  _DWORD v7[4];

  sub_4B78D0(v7, a1 + a3[4], a2 + a3[5], a1 + a3[6], a2 + a3[7]);
  return unk_69B3E8(a3, a3 + 4, v7, a5, a4, a6);
}
```

MCP disassembly resolves the missing receiver detail:

- `0x004b9a01`: `mov [ebp+var_1C], ecx`, saving incoming draw receiver.
- `0x004b9a0b`: `lea ebx, [ecx+10h]`, where this `ecx` has been replaced by the source record pointer from stack arg 3, so `ebx` is `sourceRecord + 0x10`.
- `0x004b9a0f-0x004b9a34`: reads source rect fields at `+0x10`, `+0x14`, `+0x18`, `+0x1c`, adds caller x/y offsets, and calls `sub_4B78D0` to build a local `RectBounds`.
- `0x004b9a3a`: restores saved draw receiver into `ecx`.
- `0x004b9a40-0x004b9a4a`: pushes options, mode, palette, destination rect, source rect, and source record, then calls `dword ptr unk_69B3E8`.
- `0x004b9a60`: `retn 18h`, six explicit stack arguments plus hidden receiver.

Callees are only `sub_4B78D0`, `unk_69B3E8`, and `@__security_check_cookie@4`.

## Caller And Reachability Evidence

MCP `xrefs_to` and `xref_query` both report exactly three code xrefs:

| Call site | Parent | Receiver/argument proof |
| --- | --- | --- |
| `0x004b5917` | `sub_4B5810`, size `0x1c5` | At `0x004b5902`, caller loads `ecx = [ebx]`; pushes `0`, `1`, `0`, `ecx+0x148`, y, x; then calls UID000166. |
| `0x005c3b60` | `sub_5C3950`, size `0x4f1` | Current-layout WorldMap path sets `ecx = ebx`, pushes `0`, `1`, `0`, `ebx+edi`, y, x, then calls UID000166. |
| `0x005c3db0` | `sub_5C3950`, size `0x4f1` | Old-layout WorldMap path repeats the same shape: set `ecx = ebx`, push `0`, `1`, `0`, `ebx+edi`, y, x, call UID000166. |

Caller decompilation confirms the semantic role:

- `sub_4B5810` is FolderTreePane/tree traversal drawing. It calls UID000166 with `sourceRecord = *this + 0x148`, `palette = 0`, `mode = 1`, `options = 0`.
- `sub_5C3950` is WorldMapPane drawing. It draws current and old layouts, sets draw mode byte `this+0x70` through surrounding draw-state calls, computes per-entry coordinates, and calls UID000166 with source records at offsets selected by `0x124` or `0x14c`, `palette = 0`, `mode = 1`, `options = 0`.

There is no evidence for a callback-table target route into UID000166; it is an ordinary directly called wrapper that consumes slot 2.

## Ownership Reanalysis

Accepted sibling precedent now favors GrafPort, not Surface:

- [UID:000167] `GrafPort::BlitSurface` is routed to GrafPort because the destination draw receiver is in `ecx` and the slot-2 call consumes GrafPort draw state.
- [UID:00016A] `GrafPort::DrawTiledBackground` is routed to GrafPort because it uses the same slot-2 callback with destination `GrafPort` in `ecx`, a `FrameDrawRecord`, source/destination rects, draw mode, palette, and null options.
- UID000166 has the same hidden receiver and slot-2 call shape, even though it does not directly mutate fields before forwarding.

Surface remains relevant because slot 2 and callback target families are Surface/render infrastructure. That is dependency ownership, not direct method ownership for this exact wrapper. The prior B003 reason for keeping UID000166 under Surface, "no GrafPort receiver", is now directly contradicted by current MCP disassembly and caller setup.

Recommended owner route:

- `CANONICAL_OWNER:00005V`
- `EMITTER_UIDS:00005V`
- file route through [UID:0000JR] `GrafPort` / `NexusTK/render/GrafPort.cpp`
- retain cross-links to [UID:0000OC] `Surface`, [UID:0000TN] `SurfaceRenderCallbackTable`, [UID:000165] `SurfacePaintHelpers`, [UID:000167], and [UID:00016A].

## Type And Name Direction

Recommended source-facing helper name: `GrafPort::ForwardToTileFrameBlitHelper` for minimal churn, or `GrafPort::BlitTileFrameAtOffset` if supervisors prefer a more descriptive final name. The existing documentation title is acceptable as the first-draft function name because it reflects the exact behavior and avoids inventing original spelling.

Recommended types:

- `FrameDrawRecord` or `TileFrameDrawRecord`: source descriptor whose source rect begins at offset `+0x10`.
- `RectBounds`: four-int rectangle initialized by `sub_4B78D0`.
- `SurfaceSpriteBlitProc g_pfnBlitSprite`: accepted slot-2 direction from current `SurfaceRenderCallbackTable`.
- `const SurfaceSpriteBlitOptions *options`: opaque nullable final argument; current callers pass `NULL`.
- `void *palette`: null or palette pointer. UID000166 callers currently pass `0`, unlike `RenderTileFrame`, which resolves a palette name before dispatch.

## First-Draft C++ Recommendation

Populate formal C++ only if the implementation callback also reroutes UID000166 to [UID:00005V] `GrafPort` and sets `EMITTER_UIDS:00005V`. The formal block belongs in UID000166's `RECONSTRUCTION_CPP CODE` region after reroute; it should then emit through `NexusTK/render/GrafPort.cpp` by the GrafPort class/file route. Do not emit this body under `Surface.cpp` with an artificial `__thiscall` helper; that would preserve the old owner but encode ABI scaffolding instead of source structure.

Exact formal `RECONSTRUCTION_CPP CODE` insertion content for UID000166:

```cpp
int GrafPort::ForwardToTileFrameBlitHelper(
    int destinationX,
    int destinationY,
    const FrameDrawRecord *frameRecord,
    void *palette,
    int mode,
    const SurfaceSpriteBlitOptions *options)
{
    RectBounds destinationRect;
    SetRectLTRB(&destinationRect,
                destinationX + frameRecord->source.left,
                destinationY + frameRecord->source.top,
                destinationX + frameRecord->source.right,
                destinationY + frameRecord->source.bottom);

    return g_pfnBlitSprite(this,
                           frameRecord,
                           &frameRecord->source,
                           &destinationRect,
                           mode,
                           palette,
                           options);
}
```

This body preserves the observed instruction behavior: source rect fields at `+0x10..+0x1c`, caller x/y offsets, callback argument reordering where helper arg 5 becomes callback mode and helper arg 4 becomes callback palette, hidden receiver in `ecx`, and return value from slot 2. It does not attempt to define the opaque options layout.

If the supervisor rejects the owner/emitter move to [UID:00005V], then do not insert this C++ block under the existing Surface route. In that fallback case, the target-specific no-code proof is: UID000166 is source-authored and reachable, but Surface ownership does not match the hidden receiver ABI; a Surface formal block would invent a non-source declaration shape. The report's primary recommendation is therefore "GrafPort reroute plus formal block," not "Surface no-code."

## Score And Metadata Recommendation

Current metadata:

| Field | Current |
| --- | --- |
| `COMPLETION` | `85` |
| `CONFIDENCE` | `88` |
| `CANONICAL_OWNER` | `0000OC` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000OC` |
| Formal C++ | blank |

Recommended metadata:

| Field | Recommended |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `00005V` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00005V` |
| Formal C++ | populate exact `GrafPort::ForwardToTileFrameBlitHelper` block above |

Score rationale:

- Completion should rise to `88` because this pass resolves the previous source-shape blockers: exact receiver, exact direct caller setup, exact callback argument order, exact range/padding, accepted slot-2 typedef direction, and a formal first-draft C++ block with implementation route.
- Confidence should rise to `91` because the decisive owner evidence is instruction-level and repeated at all three direct callers, and it aligns with accepted GrafPort sibling precedent. It should not rise higher because original helper/type spelling remains inferred and `SurfaceSpriteBlitOptions` is deliberately opaque.
- Reason not lower: leaving the score at `85/88` would preserve now-stale "no GrafPort receiver" and "wrapper signature not source-ready" blockers despite current direct evidence.
- Reason not higher: exact original method name, `FrameDrawRecord` versus `TileFrameDrawRecord`, and final callback-table declaration style are still broader subsystem questions.

Score-improvement attempts against named blockers:

| Prior blocker | Recheck/action | Result |
| --- | --- | --- |
| Helper role | Decompiled and disassembled target. | Resolved: offset-rectangle slot-2 forwarder. |
| Ownership / source placement | Checked target receiver save/restore, all caller `ecx` setup, GrafPort sibling routes, Surface support. | Resolved enough for GrafPort owner/emitter reroute. |
| Callback typedef | Checked current `SurfaceRenderCallbackTable` support after UID00041R/UID00041U repairs. | Resolved enough for opaque options pointer typedef; concrete options layout remains intentionally unresolved. |
| Source-facing names/types | Compared `FrameDrawRecord`, `RectBounds`, `SurfaceSpriteBlitProc`, sibling helper names. | Resolved to first-draft descriptive names; original spelling remains confidence cap only. |
| Final C++ safety | Converted exact instruction behavior to a class-method block matching hidden receiver. | Resolved if and only if UID000166 reroutes to `EMITTER_UIDS:00005V`. |
| Surface/feature ownership alternatives | Checked Surface, FolderTreePane, WorldMapPane, callback-table target, PaletteLib. | Rejected as direct owner routes; retained only as dependency/consumer context. |
| No-code possibility | Compared to UID00035C no-entry sibling and generated marker state. | Rejected for primary recommendation because UID000166 has direct callers and a source-ready GrafPort route. |

## Rejected Alternatives

- Keep Surface owner and add formal C++ anyway: rejected. The binary ABI is a hidden-receiver call; a Surface free helper would require non-source `__thiscall` scaffolding or an extra explicit draw receiver that callers do not push.
- Keep blank C++ with no score change: rejected. Current MCP resolves the exact hidden receiver, caller setup, slot-2 typedef direction, range, padding, and first-draft source body enough to clear the prior blockers.
- Mark as no-code/covered-by: rejected. UID000166 is exact source-authored code with three direct callers and is not emitted by any child page or callback target.
- Reroute to `WorldMapPane` or `FolderTreePane`: rejected. Caller set spans tree and world-map draw code, and the body has no feature-specific state.
- Callback-table target ownership: rejected. UID000166 calls `dword_69B3E8`; slot targets are the software render callbacks, not this wrapper.
- PaletteLib ownership: rejected. UID000166 does not call PaletteLib; palette is an incoming pointer, currently null at all three direct callers.

## Recommended Target Doc Changes

- Update metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`, `RECONSTRUCTABLE:TRUE`.
- Replace Surface/file-local ownership wording with GrafPort hidden-receiver evidence from current MCP.
- Add current MCP session facts and note the corrected use of `database=supervisor_resume_20260629`.
- Add the exact caller instruction proof for `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- Add the byte/padding boundaries: `0x004b99ee-0x004b99f0` and `0x004b9a63-0x004b9a70` are `0xcc`; body is `0x73` bytes.
- Add the formal C++ block above after reroute.
- Historicalize/supersede the prior B003 "no GrafPort receiver" wording.

## Recommended Support Doc Changes

- `by-class/GrafPort.md`: add UID000166 as a small source-routed tile/frame offset blit helper beside `BlitSurface` and `DrawTiledBackground`; state it forwards a `FrameDrawRecord` source rect through slot 2 with destination receiver in `ecx`.
- `by-file/GrafPort.md`: add UID000166 to proposed contents under `NexusTK/render/GrafPort.cpp`; note Surface remains callback-table dependency context.
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`: keep UID000166 as adjacent context but change owner row from Surface to dependency/GrafPort-routed exact child.
- `by-file/Surface.md`: demote UID000166 from Surface proposed-content row to dependency/context row, similar to the existing treatment for UID000167 and UID00016A.
- `by-global/SurfaceRenderCallbackTable.md`: optional support sync only; it already records UID000166 as a slot-2 consumer and the accepted `SurfaceSpriteBlitProc` direction.

Precise support-doc implementation checklist:

- `by-class/GrafPort.md`: add UID000166 to observed state or method notes, with hidden receiver proof and source descriptor/destination rect behavior; mention support score remains unchanged unless the implementation pass decides otherwise.
- `by-file/GrafPort.md`: add UID000166 to `Proposed Contents` as `GrafPort::ForwardToTileFrameBlitHelper`, a small offset tile/frame blit wrapper emitted through `NexusTK/render/GrafPort.cpp`.
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`: revise the UID000166 row and ownership boundary text so SurfacePaintHelpers remains the address-neighborhood aggregate but not UID000166's direct owner/emitter.
- `by-file/Surface.md`: revise the UID000166 row to dependency/context wording and remove any statement that it is Surface direct proposed content after reroute.
- `by-global/SurfaceRenderCallbackTable.md`: edit only if wording still implies UID000166's owner is Surface; otherwise no change needed.

Do not edit manual `by-memory/-coverage-report.md` or generated/project-level files during implementation; validator refresh may update generated files.

## Claim And Incorporation Ledger

| ID | Claim | Confidence | Destination | Action | Verification state | Proof / verification basis |
| --- | --- | --- | --- | --- | --- | --- |
| C-000166-01 | Exact range remains `0x004b99f0-0x004b9a63`, size `0x73`. | High | Target doc | Incorporate boundary/status evidence. | applied | Target doc now records range, size, body bytes, and `0xcc` padding; validator command `000000004586` exited `ok: 1`. |
| C-000166-02 | UID000166 has three direct code callers. | High | Target doc | Incorporate caller table. | applied | Target doc caller table records `0x004b5917`, `0x005c3b60`, and `0x005c3db0`; validator command `000000004586` exited `ok: 1`. |
| C-000166-03 | Target preserves hidden destination receiver in `ecx`. | High | Target doc; GrafPort support docs | Use as owner/signature proof. | applied | Target, `by-class/GrafPort.md`, and `by-file/GrafPort.md` now record caller-set `ecx` and target save/restore at `0x004b9a01`/`0x004b9a3a`; validators `000000004586`, `000000004587`, and `000000004588` exited `ok: 1`. |
| C-000166-04 | Source record rect fields begin at `+0x10`; callback source rect is `sourceRecord + 4 dwords`. | High | Target doc | Incorporate type/behavior wording. | applied | Target formal C++ and behavior text use `FrameDrawRecord::source` / fields `+0x10..+0x1c`; validator command `000000004586` exited `ok: 1`. |
| C-000166-05 | Slot-2 final argument should be nullable opaque options pointer, not scalar flags. | High | Target doc; optional callback-table support | Use in formal C++ typedef wording. | applied; callback-table already-present | Target formal C++ uses `const SurfaceSpriteBlitOptions *options`; `by-global/SurfaceRenderCallbackTable.md` already had nullable opaque slot-2 options wording, so it was not edited. |
| C-000166-06 | Direct owner should change from Surface to GrafPort. | Medium-high | Target metadata; GrafPort/Surface support docs | Set owner/emitter `00005V`; sync support wording. | applied | Target metadata changed to owner/emitter `00005V`; GrafPort class/file support added; Surface/SurfacePaintHelpers demoted to dependency context; validators `000000004586`-`000000004590` exited `ok: 1`. |
| C-000166-07 | Prior B003 "no GrafPort receiver" claim is stale. | High | Target changes; SurfacePaintHelpers and Surface support if edited | Historicalize/supersede stale claim. | applied | Target and support docs now say the older no-GrafPort-receiver claim is superseded by current disassembly; validators `000000004586`, `000000004587`, `000000004588`, `000000004589`, and `000000004590` exited `ok: 1`. |
| C-000166-08 | Formal C++ is safe only through GrafPort route, not Surface route. | Medium-high | Target formal C++ block | Populate exact block after reroute; otherwise keep no-code under Surface. | applied | Target owner/emitter rerouted to `00005V` and exact formal `GrafPort::ForwardToTileFrameBlitHelper` block inserted; validator `000000004586` reported `autogen_registry_update blank -> block` and `autogen_cpp_update 0000JR`. |
| C-000166-09 | Feature owners are caller-only consumers. | High | Target doc | Reject FolderTreePane/WorldMapPane ownership. | applied | Target ownership section rejects feature ownership and keeps callers as consumer context; validator `000000004586` exited `ok: 1`. |
| C-000166-10 | No-code/covered-by marker is not correct for the primary recommendation. | High | Target doc | Reject no-code path after GrafPort route is accepted. | applied | Target now has formal C++; validator `000000004586` removed UID000166 from not-covered stats and generated GrafPort C++ refresh completed. |
| C-000166-11 | `SurfaceRenderCallbackTable.md` needs editing only if it implies Surface direct ownership for UID000166. | High | Callback-table support doc | Check and skip unless stale direct-owner wording exists. | already-present | The page already describes UID000166 as a slot-2 consumer and slot 2 as nullable `SurfaceSpriteBlitOptions`; no stale direct-owner wording found, so it was not leased or edited. |

## Validator And Generated-Refresh Plan

Report-only phase ran no validators. Implementation callback validators were run from `source-3/project-documentation` after leasing changed files. All scoped validators exited `0` with `ok: 1`.

Expected implementation validators:

> Executable block R001 was removed from this report and preserved verbatim in [000166-ForwardToTileFrameBlitHelper-source-quality-removed.md](000166-ForwardToTileFrameBlitHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run only the support validators for files actually edited. Do not run `execute_report` or any report lifecycle/archive command.

Implementation callback validator results:

> Executable block R002 was removed from this report and preserved verbatim in [000166-ForwardToTileFrameBlitHelper-source-quality-removed.md](000166-ForwardToTileFrameBlitHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-refresh state: target validator `000000004586` completed generated refresh. It reported `autogen_cpp_update 0000JR` and `autogen_cpp_update 0000OC`, so UID000166 generated output was moved into `auto-generated/NexusTK/render/GrafPort.cpp` and the previous `Surface.cpp` empty-emitter state was refreshed validator-side. Generated reports and generated C++ were not edited manually.

## Implementation Tracking Checklist

- [x] Lease `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md` before editing. Proof: `leaser.py Agent-B006 lease ...` returned `Success`.
- [x] Lease `by-class/GrafPort.md` before adding class support wording. Proof: lease returned `Success`.
- [x] Lease `by-file/GrafPort.md` before adding file-level proposed-content wording. Proof: lease returned `Success`.
- [x] Lease `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md` before demoting UID000166 to GrafPort-routed dependency/context. Proof: lease returned `Success`.
- [x] Lease `by-file/Surface.md` before demoting UID000166 from Surface direct proposed content. Proof: lease returned `Success`.
- [x] Lease `by-global/SurfaceRenderCallbackTable.md` only if an implementation callback finds stale owner wording there. Proof: checked and not edited; already-present consumer/options wording, no lease needed.
- [x] Update UID000166 score to `88/91`. Proof: target validator `000000004586` reported `completion_update 000166 ... 88` and `confidence_update ... 91`.
- [x] Reroute UID000166 owner/emitter to `00005V`. Proof: target validator `000000004586` reported `canonical_owner_update ... 0000OC -> 00005V` and registry update to `00005V`.
- [x] Insert exact formal `GrafPort::ForwardToTileFrameBlitHelper` C++ block from this report into UID000166. Proof: target validator `000000004586` reported `autogen_registry_update ... blank -> block`.
- [x] Add current MCP session, boundary, padding, caller, receiver, and slot-2 typedef evidence to UID000166. Proof: target doc edited and validator `000000004586` exited `ok: 1`.
- [x] Supersede stale Surface/no-GrafPort-receiver wording in UID000166 and any edited support docs. Proof: target, GrafPort class/file, SurfacePaintHelpers, and Surface edits validated by commands `000000004586`-`000000004590`.
- [x] Sync GrafPort class/file support with UID000166 as a small emitted helper. Proof: validators `000000004587` and `000000004588` exited `ok: 1`.
- [x] Demote Surface/SurfacePaintHelpers rows to dependency/context if edited. Proof: validators `000000004589` and `000000004590` exited `ok: 1`.
- [x] Run scoped validators for every changed by-* file with `--apply --queue-timeout 240`; use `--wait-generated` on the UID000166 target validator if generated freshness is needed. Proof: commands `000000004586` through `000000004590` all exited `ok: 1`; target used `--wait-generated`.
- [x] Report generated-refresh state after validators, including whether `auto-generated/NexusTK/render/GrafPort.cpp` gained UID000166 and `auto-generated/NexusTK/render/Surface.cpp` lost the UID000166 empty marker. Proof: target validator `000000004586` reported `generated_refresh: completed`, `autogen_cpp_update 0000JR`, and `autogen_cpp_update 0000OC`.
- [x] Release leases immediately after edit/validator batch. Proof: release command after validators returned `Rejected[No active lease]` for the five changed by-* paths and the report path because the short leases had already expired/purged; report was re-leased only to record this closeout status and then released successfully. A final `current_leases.md` check found no `Agent-B006` entries.

Lease release status:

_Executable command block removed from the research report; preserved in [000166-ForwardToTileFrameBlitHelper-source-quality-removed.md](000166-ForwardToTileFrameBlitHelper-source-quality-removed.md)._

Final report-closeout lease was released successfully with:

_Executable command block removed from the research report; preserved in [000166-ForwardToTileFrameBlitHelper-source-quality-removed.md](000166-ForwardToTileFrameBlitHelper-source-quality-removed.md)._

Final lease verification: `Select-String .\tools\leaser\Agents\current_leases.md -Pattern "Agent-B006"` returned no matches.

## Changed Files

Report-only phase changed one file:

- `tools/leaser/Agents/Agent-B006/research/000166-ForwardToTileFrameBlitHelper-source-quality.md`

Implementation callback changed these leased files:

- `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
- `by-class/GrafPort.md`
- `by-file/GrafPort.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-file/Surface.md`
- `tools/leaser/Agents/Agent-B006/research/000166-ForwardToTileFrameBlitHelper-source-quality.md`

No target/support edit was made to `by-global/SurfaceRenderCallbackTable.md` because its consumer/options wording was already present. No generated files, coverage reports, validator state, queues, archives, or supervisor ledgers were edited manually; scoped validators performed their normal generated refresh.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004607","destination_path":"executed-b-agent-research/B006/000166-ForwardToTileFrameBlitHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/000166-ForwardToTileFrameBlitHelper-source-quality.md","timestamp":"2026-07-02T15:21:19-04:00","uid":"000166"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000166-ForwardToTileFrameBlitHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/000166-ForwardToTileFrameBlitHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000166"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
