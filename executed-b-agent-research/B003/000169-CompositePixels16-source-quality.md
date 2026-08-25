** TARGET-REPORT-UID:000169 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000169 CompositePixels16 Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: reroute [UID:000169] from the provisional [UID:0000OC] `Surface` bucket to [UID:00005V] `GrafPort`, emitted through [UID:0000JR] `GrafPort.cpp`, and use `GrafPort::CompositePixels(const RectBounds *rect)` as the best source-facing method direction.
- Final disposition: source-authored, reconstructable, exact one-function body at `0x004ba540-0x004ba6ad`; no split repair is required.
- Required action: change target metadata from `84/88`, owner/emitter [UID:0000OC], blank C++ to `88/90`, owner/emitter [UID:00005V], with first-draft C++ populated.
- Confidence: high for range, caller set, callee set, GrafPort receiver fields, palette conversion, and zero-fill/nonzero-invert semantics; medium-high for exact original public name because no PDB/source strings are available.

## Supporting Research

## Target

- Target UID: `000169`
- Target path: `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`
- Assignment id: `B003-goal2-composite-pixels16-source-quality-000169-20260618`
- Current state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current generated state: `auto-generated/-ag-memory-coverage.md` routes [UID:000169] to `auto-generated/NexusTK/render/Surface.cpp`; that file is currently zero bytes, so the item is metadata-routed but not emitting behavior. `auto-generated/NexusTK/render/GrafPort.cpp` already contains accepted [UID:00022M] and [UID:000167] output.

## Evidence Checked

- Required instructions: `tools/leaser/Agents/Agent-B003/goal.md`, `tools/leaser/Agents/Supervisor.md`, `by-structure.md`, `inference_research.md`, and `tools/leaser/Agents/Agent-B003/notes.md`.
- Target page: [UID:000169] `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`.
- Direct owner/source candidates:
  - [UID:00005V] `by-class/GrafPort.md`
  - [UID:0000JR] `by-file/GrafPort.md`
  - [UID:0000OC] `by-file/Surface.md`
  - [UID:0000HU] `by-file/BowGaugeObjectPane.md`
  - [UID:0000ON] `by-file/TextEditPane.md`
- Required support docs:
  - [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
  - [UID:000168] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
  - [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
  - [UID:000165] `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
  - [UID:000166] `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
  - [UID:000162] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - [UID:000164] `by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md`
  - [UID:00004I] `by-class/EPFTileContext.md`
  - [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
  - [UID:0001QI] `by-meta/client_new_rendering_mode.md`
- Palette support docs:
  - [UID:0000MA] `by-file/Palette.md`
  - [UID:0000MB] `by-file/PaletteLib.md`
  - [UID:0000A1] `by-class/PaletteLib.md`
  - [UID:00003Z] `by-class/DLPalette.md`
  - [UID:0000RW] `by-global/g_pPaletteLib.md`
  - [UID:0001E4] `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`
  - [UID:0001E8] `by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md`
- Caller support docs:
  - [UID:000011] / [UID:0000HU] `BowGaugeObjectPane`
  - [UID:0000ON] / [UID:0000EO] `TextEditPane`
  - [UID:0001DB] `0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`
  - [UID:000245] `0x00590810-0x005909e3.TextEditPaneOnDraw.md`
  - [UID:00024A] `0x00591740-0x005917c9.TextEditPaneInvalidateTextRegion.md`
- Generated/read-only state:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
  - `auto-generated/NexusTK/render/Surface.cpp`
  - `auto-generated/NexusTK/render/GrafPort.cpp`
  - `source-3/simroot_v2/class_BowGaugeObjectPane.cpp`
  - `source-3/simroot_v2/class_TextEditPane.cpp`
- Prior B-agent context:
  - `tools/leaser/Agents/Agent-B003/research/executed/000167-SurfaceSpriteBlitHelper-source-quality.md`
  - `tools/leaser/Agents/Agent-B002/research/000168-GrafPortDrawRectFrame-source-quality.md` as active B002 context, used only as read-only evidence and not edited.
- Raw executable checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, PE image base `0x00400000`, `.text` section RVA `0x1000`, virtual size `0x20b4ac`.
- IDA MCP availability check: `http://127.0.0.1:13337/mcp` was unavailable in this session (`Unable to connect to the remote server`). Current binary facts below are from raw PE/Capstone plus existing IDA-backed documentation, not a live MCP query.

## Binary Facts From Current Recheck

- `0x004ba53b-0x004ba540` is five `0xcc` bytes after [UID:000168].
- `0x004ba540-0x004ba6ad` is a 365-byte (`0x16d`) modeled body beginning `55 8b ec 83 ec 2c`.
- `0x004ba6ad-0x004ba6b0` is three `0xcc` bytes before [UID:00016A].
- The function ends with `ret 4`, proving a `__thiscall` shape with one explicit pointer argument and `ecx` as the receiver.
- Absolute VA dword scan for `0x004ba540` found zero hits. This is expected for a normally direct-called helper and shows no hidden pointer-table/vtable route was found in the PE bytes.
- Direct rel32 scan found exactly three direct `call` references to `0x004ba540`:
  - `0x00538ce5` inside `BowGaugeObjectPane::OnPaint` (`0x00538c50`)
  - `0x00590960` inside `TextEditPane::OnDraw` (`0x00590810`)
  - `0x005917a3` inside `TextEditPane::InvalidateTextRegion` (`0x00591740`)
- Callees inside the target:
  - `0x004b96c0` `GrafPort::GetClipRect` / clip-rect helper.
  - `0x004b7cc0` rectangle intersection helper.
  - `0x004b7eb0` empty/invalid rectangle predicate.
  - `0x00543d40` `PaletteLib::GetCurrentPalette`.
  - `0x00542ac0` `DLPalette::MapColor`.
  - `0x005c772f` security-cookie check.
- Absolute memory operands in the target are only:
  - `0x00672f24` security cookie.
  - `0x0067a7e0` / `g_pPaletteLib`.
  - `0x00619660`, a 16-byte all-ones constant.
- `0x00619660` bytes are sixteen `0xff` bytes, interpreted as eight `uint16_t(0xffff)` lanes.
- Global `dword_69B3FC` has 206 absolute references across the binary, but the target body has no reference to `0x0069b3fc`. That slot appears in caller context, especially TextEdit/BowGauge paint clearing paths, not in this helper.

## Caller Evidence

| Call site | Caller | Current source role | Meaning for ownership |
| --- | --- | --- | --- |
| `0x00538ce5` | [UID:0001DB] `BowGaugeObjectPane::OnPaint` | Draws `BGAUGE.EPF`/`BGAUGE.pal`, then calls this helper on `ecx = this` with a stack rectangle. | BowGauge is a real consumer, but it is not the owner because TextEditPane also calls the same helper and the body uses only GrafPort state. |
| `0x00590960` | [UID:000245] `TextEditPane::OnDraw` | Active-selection branch builds temporary selection rectangles, iterates them, and calls this helper for each rectangle. | TextEditPane uses the helper as a selection/caret rectangle pixel effect. |
| `0x005917a3` | [UID:00024A] `TextEditPane::InvalidateTextRegion` | Builds dirty rectangles for a text range and calls this helper for each rectangle before cleanup. | Reinforces the helper as shared GrafPort pixel-state behavior, not BowGauge-local source. |

The three caller windows all pass `ecx` as the pane object, and the called function consumes only base GrafPort fields. That is consistent with an inherited `GrafPort` method callable from both BowGaugeObjectPane and TextEditPane.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Name And Signature

Best source-facing direction:

```cpp
void GrafPort::CompositePixels(const RectBounds *rect);
```

Evidence:

- The function is a `__thiscall` method (`ecx` receiver, one explicit stack argument, `ret 4`).
- Every caller sets `ecx` to the pane/GrafPort-derived object and passes only a rectangle pointer.
- The body reads only shared GrafPort fields and palette state; it does not read BowGauge-specific, TextEdit-specific, packet, resource, or vtable-slot state.
- Current generated recovery calls the method `CompositePixels16` on BowGaugeObjectPane/TextEditPane receivers. The generated owner is wrong, but `CompositePixels` is still a useful naming lead for the source-facing role.
- The `16` suffix is a documentation/implementation qualifier, not a necessary public method name. The method operates on 16-bit surface pixels because the current render path is 16-bit, but the surrounding GrafPort public methods (`DrawRectFrame`, `DrawTiledBackground`, `BlitSurface`) do not generally expose bit-depth suffixes.

Rejected alternatives:

- `BowGaugeObjectPane::CompositePixels` / `BowGaugeObjectPane::CompositePixels16`: rejected. BowGauge has one caller and no exclusive state in the body; TextEditPane has two direct call sites.
- `TextEditPane::CompositePixels16`: rejected. TextEditPane has two callers, but BowGauge independently consumes the same helper, and the body has no text-edit fields.
- `Surface::CompositePixels16` / file-local Surface helper: rejected as canonical owner. Surface callback/pixel infrastructure is relevant context, but this function has a concrete GrafPort receiver and no `Surface` class evidence.
- `InvertPixels`: behaviorally accurate for nonzero pixels, but incomplete because zero pixels are filled with the current background palette color.
- `FillAndInvertPixels` / `InvertNonBackgroundPixels`: descriptive but less likely to be an original mid-2000s API name than the recovered `CompositePixels` lead.
- Leaving `CompositePixels16` as the final source name: useful documentation title, but it should be refined to `CompositePixels` for a class method while preserving the 16-bit implementation detail in comments/docs.

### Receiver Type And Fields

Best receiver type: `GrafPort *this`.

Field recommendations:

| Offset | Best source-facing name/type | Evidence |
| --- | --- | --- |
| `this+0x20` | `m_surfaceContext.pixelData` / `uint16_t *` current pixel buffer | The body uses it as the base destination pointer. [UID:00004I] proves `GrafPort+0x1c` embeds an `EPFTileContext`, so `+0x20` is context `pixelData`. |
| `this+0x28` | `m_surfaceContext.rowStride` / pixels per row | The body doubles it for byte row advance and uses it before multiplying by two-byte pixels. This matches `EPFTileContext +0x0c`. |
| `this+0x2c` | `m_surfaceContext.bounds.left` / source X origin | Pointer math subtracts this from the clipped left coordinate. It is `EPFTileContext +0x10`, not an independent top-level field. |
| `this+0x30` | `m_surfaceContext.bounds.top` / source Y origin | Pointer math subtracts this from the clipped top coordinate. It is `EPFTileContext +0x14`. |
| `this+0x71` | `m_drawEnabled` | Early gate returns before clip fetch or pixel access if clear; [UID:000168] and [UID:000162] support this draw-state naming. |
| `this+0x7c` | `m_backgroundColor` / background palette index | [UID:000162] documents `0x004b9680` as the broad `SetBkColor` setter for field `+0x7c`. This helper passes the field to `DLPalette::MapColor`, so the stored value is a palette index/color id for background fill. |

Rejected field interpretations:

- `+0x7c` as generic palette index only: partly true but too vague. It is the GrafPort background-color field set by `SetBkColor`; the target uses it as a palette index into the current `DLPalette`.
- `+0x2c/+0x30` as unrelated view-origin fields: older target docs called them origin fields, but [UID:00004I] and [UID:000167] show these offsets are inside the embedded `EPFTileContext` bounds. Their role in this target is origin-like, but source declarations should route them through `m_surfaceContext.bounds.left/top`.
- `+0x20/+0x28` as independent top-level `m_pixels`/`m_stride` fields: behaviorally correct but structurally incomplete. They are subfields of `m_surfaceContext`.
- `+0x71` as pane visibility: weaker. The function tests it as a draw operation gate before all render work; `m_drawEnabled` is the best descriptive name.

### Rectangle Type And Clip Behavior

Best source type: `RectBounds` or the project typedef compatible with Win32 `RECT` (`left`, `top`, `right`, `bottom` dwords).

Evidence:

- The explicit argument is copied as a 16-byte block.
- The function calls `GrafPort::GetClipRect`, intersects a stack copy of the caller rectangle with the clip rectangle, then rejects empty/invalid rectangles.
- The loop width is `clipped.right - clipped.left`; height is `clipped.bottom - clipped.top`.
- The destination pointer is computed from the clipped rectangle, not from the original input rectangle.

This differs from [UID:000168] `DrawRectFrame`, where the clipped rectangle is only a visibility gate and the original rectangle is used for edges. For [UID:000169], the clipped rectangle controls the actual pixel span.

### Palette Helpers And Color Type

Best names/types:

```cpp
extern PaletteLib *g_pPaletteLib;
DLPalette *PaletteLib::GetCurrentPalette();
uint16_t DLPalette::MapColor(unsigned int paletteIndex) const;
```

Evidence:

- Target loads `g_pPaletteLib` from `0x0067a7e0`, pushes `this+0x7c`, calls `0x00543d40`, then calls `0x00542ac0` on the returned palette object.
- `0x00543d40` disassembly checks `PaletteLib +0x758`, selects either offset `0x238` or `0x0c`, adds the chosen offset to `this`, and returns that `DLPalette *`. [UID:0000A1] already names this helper `GetCurrentPalette`.
- `0x00542ac0` reads the palette index argument, returns zero if it is greater than `0xff`, otherwise returns `word [DLPalette +0x2c + index*2]`. [UID:0001E4] and [UID:00003Z] name this `DLPalette::MapColor`.
- Therefore the target's fill color is the current palette's native 16-bit color for the GrafPort background-color index.

Rejected alternatives:

- Direct `g_pPaletteLib` field ownership under `Surface`: rejected. `g_pPaletteLib` is PaletteLib-owned render palette state; this helper only consumes it.
- Treating `0x00542ac0` as an RGB conversion helper: rejected for this target. It does not convert RGB components here; it maps a palette index to a precomputed 16-bit native color.
- Treating `0x00543d40` as a named palette lookup: rejected. `0x00543d70` is the named-palette lookup used by [UID:00016A]; `0x00543d40` is current/base palette selection.

### Pixel Effect Semantics

Confirmed per-pixel behavior:

- If a destination pixel is `0`, the helper writes the current background color converted through `g_pPaletteLib->GetCurrentPalette()->MapColor(m_backgroundColor)`.
- If a destination pixel is nonzero, the helper writes the bitwise inverse of the 16-bit pixel (`~pixel & 0xffff`).
- This is not alpha blending, sprite blitting, DirectDraw copying, or `dword_69B3FC` fill dispatch. It directly mutates the current 16-bit pixel buffer.

Vector/scalar evidence:

- The hot loop processes eight 16-bit pixels per iteration with SSE instructions: `pcmpeqw` builds a zero-pixel mask, `pand`/`pandn`/`por` select either fill color or inverted original pixel, and `movups` stores the eight-lane result.
- `0x00619660` supplies the all-ones vector used for `~pixel` in the vector path.
- The scalar tail performs the same operation: read a word; if zero, substitute the fill color; otherwise `not ecx` and store the low word.
- The source-level effect is simple enough that the first-draft C++ should be a clear scalar loop. The SSE path is likely compiler optimization or a local optimized build artifact for a hot 16-bit span loop. If later evidence proves the original source used explicit intrinsics, that can be revised, but formal reconstruction should not paste a decompiler-shaped SSE implementation when the source semantics are this clear.

Best effect description:

`GrafPort::CompositePixels` applies a selection/highlight-style 16-bit composite over a clipped rectangle: transparent/background pixels become the current background color, and drawn pixels are inverted. TextEditPane uses it for active selection and invalidated text-range rectangles; BowGauge uses it after drawing the bow gauge frame. This is consistent with a mid-2000s game UI helper that gives selection/gauge overlay pixels high contrast without a separate alpha blend path.

### Callback / Global Interaction Context

- `dword_69B3FC` is not called by [UID:000169]. The target is a direct pixel-buffer mutator.
- BowGauge `OnPaint` calls `dword_69B3FC` at `0x00538c7b` with `ecx = this` and `this+0x44` before resource drawing and before this helper. That appears to clear or prepare the paint region through Surface callback slot 7.
- TextEditPane `OnDraw` also uses broader GrafPort/context helpers and `dword_69B3FC` in its draw flow before selection rectangle passes.
- Therefore `dword_69B3FC` is support context for the callers' draw/clear setup, not ownership or implementation evidence for this target.
- `dword_69B3E8` and `dword_69B3E4` are adjacent helper dependencies for [UID:000167], [UID:000168], and [UID:00016A], but [UID:000169] does not dispatch through the callback table.

### Owner / Source Route

Ranked ownership recommendation:

1. [UID:00005V] `GrafPort` class, emitted through [UID:0000JR] `GrafPort.cpp`: accepted.
   - Evidence for: `__thiscall` receiver; one rectangle argument; direct reads of GrafPort draw-state and embedded `EPFTileContext` fields; broad use by BowGaugeObjectPane and TextEditPane; sibling [UID:000167] and [UID:00016A] now route to the GrafPort class; [UID:000168] active B002 evidence also recommends GrafPort class ownership.
   - Evidence against: palette and pixel-render support are shared render infrastructure, and the helper could have physically lived near Surface helpers in the original object file. This does not outweigh the method receiver and class-state dependence under by-structure's narrowest-owner rule.
   - Decision: set `CANONICAL_OWNER:00005V`, `EMITTER_UIDS:00005V`.
2. [UID:0000JR] `GrafPort.cpp` file direct owner: acceptable fallback, weaker than class owner.
   - Evidence for: final generated file is `render/GrafPort.cpp`; the method should surface through this file.
   - Evidence against: by-structure says class methods should use the class UID when the receiver/class evidence is strong.
   - Decision: use [UID:00005V] as owner/emitter; output still reaches `GrafPort.cpp` through the class/file chain.
3. [UID:0000OC] `Surface.cpp`: rejected as canonical owner, retained as support context.
   - Evidence for: address adjacency to Surface/GrafPort helper neighborhood, 16-bit software-render state, and historical Surface bucket route.
   - Evidence against: target does not call Surface callback slots and does not have a standalone `Surface` receiver. `Surface.cpp` is a provisional bucket for callback table and paint lifecycle helpers, not the narrowest owner for a GrafPort method.
   - Decision: update Surface docs to mark [UID:000169] as former bucket/dependency and no longer a Surface-owned emitter.
4. [UID:0000HU] `BowGaugeObjectPane`: rejected.
   - Evidence for: one caller and old generated owner history.
   - Evidence against: two TextEdit callers, no BowGauge fields, no BowGauge resources inside the target, and support docs already mark it as shared.
   - Decision: keep as consumer dependency only.
5. [UID:0000ON] `TextEditPane`: rejected.
   - Evidence for: two callers in selection/invalidation paths.
   - Evidence against: BowGauge also calls the target; body has no editor fields; this is a lower GrafPort render effect.
   - Decision: keep as consumer dependency only.

### Range, Split, And Merge Decision

- Keep [UID:000169] as a single exact by-memory target.
- No split is required: the body is one function, has one source-level operation, and no embedded data table besides the external all-ones constant at `0x00619660`.
- Do not merge with [UID:000168] or [UID:00016A]. Exact `0xcc` padding separates all three functions, and the roles differ: rectangle-frame line callback, direct pixel composite effect, tiled-background sprite callback.
- Do not merge into [UID:000165]. [UID:000165] is the earlier Surface paint lifecycle cluster ending at `0x004ba24a`; [UID:000169] is a precise later GrafPort method.

### Generated Output And Current Docs Validation

Validated:

- Existing target docs are correct about the exact range, size `0x16d`, three caller set, clip/intersection/empty-rect behavior, pointer math, palette conversion, and scalar/vector semantics.
- Existing BowGauge/TextEditPane docs are correct that generated BowGauge ownership is caller-biased and that TextEditPane uses the helper for selection/invalidation rectangles.
- Existing Palette docs correctly identify `0x00543d40` as `PaletteLib::GetCurrentPalette` and `0x00542ac0` as `DLPalette::MapColor`.
- Existing GrafPort support correctly places this helper in GrafPort/surface review and identifies feature-owner pollution.

Superseded or corrected:

- Target `CANONICAL_OWNER:0000OC` / `EMITTER_UIDS:0000OC` should change to [UID:00005V] because the receiver and concrete field use identify a GrafPort method.
- Blank C++ should be superseded. The target is reconstructable, has a nonblank emitter route after reroute, the combined score will be above the active code-entry gate, and source semantics are clear enough for a first draft.
- Field `+0x7c` should be named as the GrafPort background color/palette index, not generic palette index.
- Fields `+0x2c/+0x30` should be described structurally as `m_surfaceContext.bounds.left/top`, even though they act as origin offsets in this pointer formula.
- `dword_69B3FC` should not be presented as target implementation context; it is caller draw/clear setup context only.

## Recommended Metadata And Score Changes

Target [UID:000169]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: exact range/padding, caller set, callee set, receiver layout, palette conversion, field names, ownership route, and first-draft C++ are now resolved. Keep below final-audit scores because exact original method spelling and whether the SSE path came from source intrinsics versus compiler vectorization remain unproven.

Support score recommendations:

- [UID:00005V] `by-class/GrafPort.md`: recommend `86/88 -> 87/89` after adding [UID:000169] as `GrafPort::CompositePixels`, recording `+0x7c` as background color/palette index evidence, and converting `+0x2c/+0x30` to embedded `EPFTileContext` bounds wording for this helper.
- [UID:0000JR] `by-file/GrafPort.md`: recommend `88/86 -> 89/87` after adding this source-bearing method to the proposed contents and keeping the accepted [UID:000167]/[UID:00016A] GrafPort route consistent. If the supervisor is applying B002's active [UID:000168] report in the same pass, reconcile score changes once rather than double-counting.
- [UID:0000OC] `by-file/Surface.md`: no score change required. Replace the [UID:000169] row so Surface preserves dependency/history but does not claim canonical ownership.
- [UID:000162] `GrafPortDrawStateAccessors`: no score change required. Add a support note that `+0x7c` / `SetBkColor` is consumed by [UID:000169] as the palette-index source for zero-pixel fill.
- [UID:0000MA] / [UID:0000MB] / [UID:00003Z] palette docs: no score change required. Add one cross-reference note if desired, but the current docs already prove the needed helper names.
- [UID:0000TN] `SurfaceRenderCallbackTable`: no score change required. This target does not dispatch through the table; only mention `dword_69B3FC` in caller context if updating target/caller docs.

## First-Draft C++ Recommendation

Populate [UID:000169] formal C++ after rerouting owner/emitter to [UID:00005V]. Use the project's final rectangle spelling if it differs from `RectBounds`; `RECT` is layout-compatible.

```cpp
void GrafPort::CompositePixels(const RectBounds *rect)
{
    if (!m_drawEnabled)
        return;

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds clippedRect = *rect;
    IntersectRects(&clippedRect, &clipRect, &clippedRect);
    if (IsRectEmptyOrInvalid(&clippedRect))
        return;

    const int width = clippedRect.right - clippedRect.left;
    const int height = clippedRect.bottom - clippedRect.top;
    if (width <= 0 || height <= 0)
        return;

    DLPalette *palette = g_pPaletteLib->GetCurrentPalette();
    const unsigned short fillColor =
        palette->MapColor(static_cast<unsigned int>(m_backgroundColor));

    unsigned short *row =
        static_cast<unsigned short *>(m_surfaceContext.pixelData) +
        (clippedRect.top - m_surfaceContext.bounds.top) * m_surfaceContext.rowStride +
        (clippedRect.left - m_surfaceContext.bounds.left);

    for (int y = 0; y < height; ++y) {
        unsigned short *pixel = row;
        for (int x = 0; x < width; ++x, ++pixel) {
            if (*pixel == 0) {
                *pixel = fillColor;
            } else {
                *pixel = static_cast<unsigned short>(~*pixel);
            }
        }

        row += m_surfaceContext.rowStride;
    }
}
```

C++ integration notes:

- `m_backgroundColor` is the field at `this+0x7c`, set by the broad GrafPort `SetBkColor` helper at `0x004b9680`. If the final field is named `m_backgroundColorIndex`, use that spelling consistently.
- `m_surfaceContext` is the embedded [UID:00004I] `EPFTileContext` at `GrafPort+0x1c`.
- The binary has an SSE eight-pixel hot loop and scalar tail. The scalar source above is intentionally source-like and behaviorally exact. A later compiler or hand-optimization pass can reproduce vectorization if the reconstruction project requires binary-shape tuning.
- The source does not call `dword_69B3FC`, `dword_69B3E8`, DirectDraw, or `EndPaint`.
- No null check for `rect`, `g_pPaletteLib`, current palette, or `pixelData` is added because the compiled function does not guard those inputs.

## Exact Supervisor Changes Required

### Target Metadata Replacement

In `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`, replace the metadata values with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Populate the formal `RECONSTRUCTION_CPP CODE` block with the draft in `## First-Draft C++ Recommendation`.

### Target Status Replacement

In the target page `## Status`, replace the current owner/C++ bullets with:

```markdown
- Confidence: very strong for exact function boundary, caller set, callee set, GrafPort receiver state, palette conversion, and zero-fill/nonzero-invert pixel semantics; capped below final-audit quality because the exact original public method spelling and explicit-intrinsics-versus-compiler-vectorization source shape remain inferred.
- Current generated owner history: older generated output emitted this as `BowGaugeObjectPane::CompositePixels` / `CompositePixels16`, but current source-quality evidence rejects BowGauge ownership because TextEditPane also calls the helper and the body uses only base GrafPort state.
- Preferred reconstruction owner: [UID:00005V][GrafPort](by-class/GrafPort.md), emitted through [UID:0000JR][GrafPort](by-file/GrafPort.md) in `NexusTK/render/GrafPort.cpp`.
- Source-facing name direction: `GrafPort::CompositePixels(const RectBounds *rect)`; keep `CompositePixels16` as the documentation title or historical implementation label if the supervisor does not rename the file yet.
- Entity kind: source-authored GrafPort pixel-composite/highlight method.
- Rebuild handling: `source-authored`.
- C++ status: populate first-draft C++ after this B003 pass. The old blank-C++ blocker is stale because the receiver, field model, palette helper names, owner route, and behavior are now resolved enough for the active combined-score/emitter gate.
```

### Target Function Table Replacement

Replace the target page function row with:

```markdown
| Range | Current/proposed name | Notes |
| --- | --- | --- |
| `0x004ba540-0x004ba6ad` | `GrafPort::CompositePixels` / documentation label `CompositePixels16` | Clips the caller rectangle to the active GrafPort clip rectangle, maps the GrafPort background color field through the current `DLPalette`, and mutates the 16-bit destination buffer so zero pixels become the mapped background color while nonzero pixels are bitwise inverted. The binary contains an eight-pixel SSE hot loop plus scalar tail with identical semantics. |
```

### Target Evidence Insert

Append to `## Evidence Notes`:

```markdown
- 2026-06-18 B003 raw PE/Capstone recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirms `0x004ba53b-0x004ba540` is five `0xcc` bytes, `0x004ba540-0x004ba6ad` is a 365-byte `ret 4` thiscall body, and `0x004ba6ad-0x004ba6b0` is three `0xcc` bytes before [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md).
- The same recheck found zero absolute VA pointer hits for `0x004ba540` and exactly three direct rel32 callers: `0x00538ce5`, `0x00590960`, and `0x005917a3`.
- B003 callee disassembly confirms the target calls `GrafPort::GetClipRect` (`0x004b96c0`), rectangle intersection (`0x004b7cc0`), empty-rect predicate (`0x004b7eb0`), `PaletteLib::GetCurrentPalette` (`0x00543d40`), `DLPalette::MapColor` (`0x00542ac0`), and the security-cookie check.
- The target has no direct `dword_69B3FC`, `dword_69B3E8`, or DirectDraw dispatch. `dword_69B3FC` appears in caller paint/setup paths only.
- The all-ones SIMD constant at `0x00619660` is sixteen `0xff` bytes, used by the vector path to invert nonzero 16-bit pixels.
```

### Target Touched State Replacement

Replace `## Touched State` with:

```markdown
## Touched State

| State | Evidence | Reconstruction note |
| --- | --- | --- |
| `this + 0x71` | Early return when the byte is zero. | `m_drawEnabled`, shared GrafPort draw-state gate. |
| RECT-like argument | Copied as 16 bytes, intersected with the active clip rectangle, and then used for width/height and pixel address math. | Use `RectBounds` or the project `RECT`-layout type. |
| `this + 0x20` | Base pointer for destination word-pixel writes. | `m_surfaceContext.pixelData`, the `EPFTileContext +0x04` subfield. |
| `this + 0x28` | Row advance in pixels; doubled internally for byte stride. | `m_surfaceContext.rowStride`, the `EPFTileContext +0x0c` subfield. |
| `this + 0x2c` / `this + 0x30` | Subtracted from clipped left/top before computing the destination pointer. | `m_surfaceContext.bounds.left/top`; origin-like in this formula but structurally part of the embedded `EPFTileContext` bounds. |
| `this + 0x7c` | Passed to `DLPalette::MapColor` after `PaletteLib::GetCurrentPalette`. | GrafPort background-color/background-palette-index field set by the `0x004b9680` `SetBkColor` accessor. |
| Pixel contents | Zero words become the mapped background color; nonzero words are bitwise inverted. | Selection/highlight-style 16-bit composite helper, not alpha blending or Surface callback dispatch. |
```

### Target Caller Context Replacement

Replace `## Caller Context` with:

```markdown
## Caller Context

The three direct callers disprove pane-local ownership and also explain the visual role. BowGauge paint calls this after drawing `BGAUGE.EPF`/`BGAUGE.pal`. TextEditPane draw and invalidation paths build selection or dirty rectangles and call this helper for each rectangle. In all three cases `ecx` is the pane/GrafPort-derived object and the only explicit argument is a rectangle pointer.

This means the old `BowGaugeObjectPane::CompositePixels` owner label is generated caller pollution. The helper belongs to the shared GrafPort pixel-effect API and is consumed by BowGaugeObjectPane and TextEditPane.
```

### Target Ownership Notes Replacement

Replace `## Ownership Notes` with:

```markdown
## Ownership Notes

Treat `BowGaugeObjectPane::CompositePixels` and `CompositePixels16` owner labels as caller-biased generated output. BowGauge is one consumer, while TextEditPane has two direct call sites in selection and invalidation paths.

The best direct owner is [UID:00005V][GrafPort](by-class/GrafPort.md). The function is a `__thiscall` method on a GrafPort-derived receiver, takes one rectangle argument, gates on GrafPort draw state, uses embedded `EPFTileContext` pixel/bounds/stride fields, and reads the GrafPort background-color field before mapping it through the current palette.

[UID:0000OC][Surface](by-file/Surface.md) remains surrounding render infrastructure context, especially for adjacent callback-based helpers, but this exact target does not dispatch through the Surface callback table and should no longer emit through `Surface.cpp`.

[UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) and [UID:0000ON][TextEditPane](by-file/TextEditPane.md) should keep this as a dependency only.
```

### Target Changes Entry

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality reanalysis:
  - Before: `84/88`, owner/emitter [UID:0000OC][Surface](by-file/Surface.md), blank formal C++, and unresolved Surface-vs-GrafPort/source-name/field-name blockers.
  - After recommendation: `88/90`, owner/emitter [UID:00005V][GrafPort](by-class/GrafPort.md), with formal first-draft `GrafPort::CompositePixels(const RectBounds *rect)` C++ populated.
  - Evidence: raw PE/Capstone confirms exact padded boundaries, one `ret 4` thiscall body, three direct callers (`0x00538ce5`, `0x00590960`, `0x005917a3`), no pointer-table route, no direct Surface callback dispatch, GrafPort draw gate and embedded `EPFTileContext` pixel/stride/bounds fields, `+0x7c` background color mapped through `PaletteLib::GetCurrentPalette` and `DLPalette::MapColor`, and matching SSE/scalar zero-fill/nonzero-invert semantics.
```

### GrafPort Class Support Insert

In `by-class/GrafPort.md`, after the current [UID:000169] paragraph or near the [UID:000167]/[UID:000168] draw-helper notes, replace the provisional paragraph with:

```markdown
[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) should route to this class as `GrafPort::CompositePixels(const RectBounds *rect)`. B003's 2026-06-18 recheck confirms the function is a `ret 4` thiscall method with one rectangle argument, three direct callers from BowGaugeObjectPane and TextEditPane, and no pointer-table or Surface callback route. The body gates on `m_drawEnabled` at `+0x71`, clips the rectangle through `GrafPort::GetClipRect`, writes the embedded `EPFTileContext` pixel buffer at `+0x20` using row stride `+0x28` and bounds `+0x2c/+0x30`, maps the `SetBkColor`/background-color field at `+0x7c` through `PaletteLib::GetCurrentPalette` and `DLPalette::MapColor`, and then fills zero 16-bit pixels with that color while bitwise-inverting nonzero pixels. BowGaugeObjectPane and TextEditPane are consumers only.
```

Add to `## Method Notes`:

```markdown
| `CompositePixels` | `0x004ba540-0x004ba6ad` | Applies a clipped 16-bit selection/highlight composite: zero pixels receive the current background palette color, and nonzero pixels are bitwise inverted. |
```

Recommended score after this insert: `COMPLETION:87`, `CONFIDENCE:89`.

### GrafPort File Support Insert

In `by-file/GrafPort.md`, add or replace the [UID:000169] proposed-contents row with:

```markdown
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) | `0x004ba540-0x004ba6ad` | `GrafPort::CompositePixels`, a source-authored clipped 16-bit pixel-effect method used by BowGaugeObjectPane and TextEditPane; it fills zero pixels with the current background palette color and inverts nonzero pixels. |
```

Append to `## Ownership Decision`:

```markdown
[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) should route through the GrafPort class rather than the provisional Surface bucket or BowGauge/TextEdit consumers. The decisive evidence is the `__thiscall` receiver plus concrete GrafPort state: draw-enabled byte `+0x71`, embedded `EPFTileContext` pixel/stride/bounds fields at `+0x20/+0x28/+0x2c/+0x30`, and the background-color field at `+0x7c`. Surface remains adjacent render infrastructure context only.
```

Recommended score after this insert: `COMPLETION:89`, `CONFIDENCE:87`, unless the supervisor is applying B002's [UID:000168] report in the same pass and consolidates one combined GrafPort score update.

### Surface File Support Replacement

In `by-file/Surface.md`, replace the [UID:000169] proposed-contents row with:

```markdown
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) | `0x004ba540-0x004ba6ad` | dependency / former Surface bucket item | B003 2026-06-18 reanalysis reroutes this exact function to [UID:00005V][GrafPort](by-class/GrafPort.md) as `GrafPort::CompositePixels`; Surface remains surrounding render infrastructure context, but this target directly mutates GrafPort's 16-bit pixel buffer and does not call Surface callback slots. |
```

Append to the Surface changes/evidence area:

```markdown
- 2026-06-18 B003 source-quality reanalysis reroutes [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) from the provisional Surface bucket to [UID:00005V][GrafPort](by-class/GrafPort.md). The function is a `ret 4` GrafPort method that clips a rectangle, maps `this+0x7c` background color through the current `DLPalette`, and directly fills/inverts 16-bit pixels in `m_surfaceContext`; it does not dispatch through `dword_69B3FC` or `dword_69B3E8`.
```

No Surface score change required.

### GrafPort Draw-State Accessor Support Insert

In [UID:000162] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, under the `0x004b9680` row or evidence notes, insert:

```markdown
2026-06-18 B003 [UID:000169] reanalysis strengthens the `0x004b9680` field name: `this+0x7c` is consumed by `GrafPort::CompositePixels` as the background color/palette index. The helper passes the stored value to `DLPalette::MapColor` after `PaletteLib::GetCurrentPalette`, then uses the mapped 16-bit color to fill zero pixels in a clipped rectangle. This supports `SetBkColor` / `m_backgroundColor` over generic palette-index-only naming.
```

No score change required.

### BowGauge And TextEdit Support Inserts

In [UID:0000HU] / [UID:000011] BowGauge support pages, replace dependency wording for [UID:000169] with:

```markdown
[UID:000169] is now best routed as `GrafPort::CompositePixels`, not a BowGauge-owned helper. BowGaugeObjectPane::OnPaint remains one direct consumer at `0x00538ce5` after drawing `BGAUGE.EPF`/`BGAUGE.pal`.
```

In [UID:0000ON] / [UID:0000EO] TextEditPane support pages, replace dependency wording for [UID:000169] with:

```markdown
[UID:000169] is now best routed as `GrafPort::CompositePixels`, a shared GrafPort pixel-effect method. TextEditPane::OnDraw and TextEditPane::InvalidateTextRegion remain direct consumers for active selection and dirty text-range rectangles.
```

No support score changes required.

### Palette Support Optional Insert

In [UID:00003Z] `DLPalette` or [UID:0000A1] `PaletteLib`, add this optional cross-reference note only if the supervisor wants direct consumer coverage:

```markdown
[UID:000169] `GrafPort::CompositePixels` is a direct render consumer of `PaletteLib::GetCurrentPalette` (`0x00543d40`) and `DLPalette::MapColor` (`0x00542ac0`): it maps the GrafPort background-color field to a native 16-bit fill color before mutating clipped destination pixels.
```

No palette score change required.

## Coverage Report Replacement Text

In `by-memory/-coverage-report.md`, replace the current [UID:000169] row near `0x004ba540` with:

```markdown
    - [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) 0x004ba540-0x004ba6ad | class method | GrafPort::CompositePixels : reconstructable : 88% : very-strong : B003 2026-06-18 source-quality pass reroutes this from the provisional Surface/BowGauge history to [UID:00005V][GrafPort](by-class/GrafPort.md); raw PE/Capstone recheck confirms five leading and three trailing `0xcc` padding bytes, one 365-byte `ret 4` thiscall body, exactly three direct rel32 callers from BowGaugeObjectPane and TextEditPane (`0x00538ce5`, `0x00590960`, `0x005917a3`), no absolute pointer-table route, no direct `dword_69B3FC`/`dword_69B3E8` dispatch, clip/intersection/empty-rect gating, embedded `EPFTileContext` pixel/stride/bounds fields (`+0x20/+0x28/+0x2c/+0x30`), draw-enabled byte `+0x71`, background-color field `+0x7c` mapped through `PaletteLib::GetCurrentPalette` and `DLPalette::MapColor`, matching SSE/scalar zero-fill and nonzero-bitwise-invert semantics, stale BowGauge/TextEdit/Surface owner rejection, and first-draft `GrafPort::CompositePixels(const RectBounds *rect)` C++ readiness through `auto-generated/NexusTK/render/GrafPort.cpp`.
```

Keep the row in address order. Do not move it into an owner-grouped location because `by-memory/-coverage-report.md` is address ordered.

## Validation / State Checks Run

Commands run in this session:

> Executable block R001 was removed from this report and preserved verbatim in [000169-CompositePixels16-source-quality-removed.md](000169-CompositePixels16-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Local PE/Capstone checks:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
0x004ba53b-0x004ba540 padding
0x004ba540-0x004ba6ad target disassembly
0x004ba6ad-0x004ba6b0 padding
absolute VA scan for 0x004ba540
rel32 direct-call scan for 0x004ba540
callee and absolute-memory operand extraction inside the target
constant bytes at 0x00619660
caller windows around 0x00538ce5, 0x00590960, and 0x005917a3
support callee disassembly for 0x00543d40, 0x00542ac0, 0x004b96c0, 0x004b7cc0, and 0x004b7eb0
```

Supervisor validation commands after applying recommended docs:

> Executable block R002 was removed from this report and preserved verbatim in [000169-CompositePixels16-source-quality-removed.md](000169-CompositePixels16-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated state after supervisor application:

- `auto-generated/NexusTK/render/GrafPort.cpp` should gain [UID:000169] `GrafPort::CompositePixels(...)` after existing GrafPort emitted items.
- `auto-generated/NexusTK/render/Surface.cpp` may remain empty unless other Surface-owned targets receive formal C++; [UID:000169] should no longer be routed there.
- [UID:000169] should no longer appear as `84/88` in `project-level/-auto-completion-stats.md`; it should appear as `88/90`.

## Remaining Blockers

- No blocker remains for first-draft formal C++ entry after the owner/emitter reroute.
- Original public method spelling is inferred. `CompositePixels` is the strongest source-facing direction from generated naming plus behavior, but no PDB/source string proves it. This caps confidence below final audit and does not block code entry.
- Exact final spelling of the rectangle type may be `RectBounds`, `RECT`, or a local `Rect` typedef. The layout and semantics are proven; the typedef name can be normalized with the existing rectangle docs during supervisor application.
- Exact field spelling for `+0x7c` remains `m_backgroundColor` versus `m_backgroundColorIndex`. Current evidence favors background color/palette-index wording through `SetBkColor` and `DLPalette::MapColor`. This does not block C++ if the supervisor chooses one spelling consistently.
- Whether the SSE path came from explicit source intrinsics or compiler vectorization is not proven. The scalar source draft is behaviorally exact and better matches the project's source-like reconstruction policy; this uncertainty caps final-audit confidence but does not block draft C++.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/000169-CompositePixels16-source-quality.md`
- Modified: none outside Agent-B003 research.
- No by-* docs, generated reports/source, IDA DB, project-level files, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000169-CompositePixels16-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000169"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000169-CompositePixels16-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000169-CompositePixels16-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000169"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
