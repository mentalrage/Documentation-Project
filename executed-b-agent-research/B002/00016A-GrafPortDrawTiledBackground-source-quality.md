** TARGET-REPORT-UID:00016A **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016A GrafPortDrawTiledBackground Source-Quality Research

Assignment id: `B002-goal2-grafport-draw-tiled-background-source-quality-00016A-20260618`

Primary target: [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`

Report-only status: this report creates no by-documentation, generated-output, generated-source, IDA database, or shared coverage-report edits. All replacement text below is intended for supervisor review/application.

## Final Recommendation

[UID:00016A] should remain a single source-bearing `GrafPort` class method owned and emitted by [UID:00005V] `GrafPort`. The current owner/emitter route is correct; the stale source-quality blockers are mostly naming, callback-typing, generated-owner pollution, and an overgeneral cleanup description.

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005V
EMITTER_UIDS: 00005V
```

Recommended source-facing method shape:

```cpp
void GrafPort::DrawTiledBackground(const RectBounds *clipRect,
                                   const FrameDrawRecord *frameRecord,
                                   const wchar_t *paletteName);
```

`FrameDrawRecord` is the strongest current source-facing type because [UID:0001GF] already models the WaterFilter caller with `FrameDrawRecord`, [UID:0002P6] names the producer `LoadFrameDrawRecord`, and the binary consumes `frameRecord + 0x10` as the source rectangle. `TileFrameDrawRecord` remains a possible original spelling, but raw `uint8_t *`, generated `TileData_004ba6b0`, or EPF-only names are weaker because this helper is called by broad UI and effect code, not only EPF-tile loaders.

Formal first-draft C++ should be populated now. The target is reconstructable, has a valid emitter route, clears the active code-entry gate, and has no range or owner blocker. Remaining exact-name uncertainty is suitable for descriptive names in first-draft code.

## Evidence Checked

Read and compared:

- [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
- [UID:00005V] `by-class/GrafPort.md`
- [UID:0000JR] `by-file/GrafPort.md`
- [UID:0000OC] `by-file/Surface.md`
- [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
- [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
- [UID:000168] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
- [UID:000169] `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`
- [UID:0001GF] `by-memory/0x0055b500-0x0055b705.WaterFilterEffecterUpdateCausticEffect.md`
- [UID:0000UX] `by-item/LoadFrameDrawRecord_004D1600.md`
- [UID:0002P6] `by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md`
- [UID:0003XE] `by-memory/0x005ba370-0x005ba3f9.SurfaceTileBufferBlitRaw.md`
- [UID:000166] `by-memory/0x004ba1b0-0x004ba245.ForwardToTileFrameBlitHelper.md`
- [UID:0002PH] and [UID:0002PK] callback target pages for `dword_69B3E8`
- [UID:00004I] `by-structure/EPFTileContext.md`
- [UID:0001FW] `by-memory/0x00554680-0x005548ea.RegionAndMotionRect.md`
- [UID:0000BV] `by-class/Region.md`
- [UID:0000N3] `by-file/Region.md`
- [UID:0002R9] `by-memory/0x00554720-0x0055479e.MotionRectSetAndCopy.md`
- [UID:0000RW] `by-global/g_pPaletteLib.md`
- `by-memory/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-file/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/render/GrafPort.cpp`
- `simroot_v2/render/class_GrafPort.cpp`
- `simroot_v2/class_RankingEventListPane.cpp`
- `by-project-structure/proposed-source-tree.md`
- `by-structure.md`
- `tools/leaser/Agents/inference_research.md`

Live IDA MCP was not available for this pass. `Get-NetTCPConnection -LocalAddress 127.0.0.1 -LocalPort 13337` found no local listener, so the low-level checks used the read-only PE image and current documentation instead of mutating IDA state.

Read-only PE checks used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. The target bytes and xref scans were read-only. No IDA database or generated source was edited.

## Raw Boundary And Body Evidence

The function boundary is exact:

- `0x004ba6ad-0x004ba6b0` is `cc cc cc` padding before the function.
- `0x004ba6b0` starts a full SEH/security-cookie prologue.
- `0x004ba81a` returns with `ret 0x0c`, proving three explicit stack arguments.
- `0x004ba81d-0x004ba820` is `cc cc cc` padding after the function.

Receiver and arguments:

- `0x004ba6da mov edi, ecx` preserves `ecx` as the receiver. This is a `GrafPort *this` route, not a free Surface helper.
- `[ebp+0x08]` is the caller-supplied clip/destination area rectangle pointer.
- `[ebp+0x0c]` is the tile/frame draw record pointer.
- `[ebp+0x10]` is the palette-name pointer passed to `PaletteLib::GetPaletteByName`.

Important body facts:

```asm
004ba6ee call 0x554680        ; stack Region constructor
004ba704 call 0x554760        ; savedClip.CopyRectFrom(this+0x54)
004ba70d call 0x554720        ; this+0x54.SetRect(clipRect)
004ba715 lea ecx, [eax+0x10]  ; sourceRect = frameRecord + 0x10
004ba71b mov esi, [eax+0x18]
004ba71e sub esi, [ecx]       ; tileWidth = right - left
004ba720 mov ecx, [eax+0x1c]
004ba723 sub ecx, [eax+0x14]  ; tileHeight = bottom - top
004ba72e jle 0x004ba7f8       ; non-positive width skips restore
004ba736 jle 0x004ba7f8       ; non-positive height skips restore
004ba746 movups xmm0, [edi+0x44] ; copy visible bounds
004ba790 mov al, [edi+0x70]      ; draw/blit mode byte
004ba796 mov ecx, [0x0067a7e0]   ; g_pPaletteLib
004ba79f call 0x00543d70         ; PaletteLib::GetPaletteByName
004ba7b6 call dword ptr [0x0069b3e8] ; slot-2 sprite/tile blitter
004ba7bc call 0x004b7e10         ; OffsetRect(destRect, tileWidth, 0)
004ba7d2 call 0x004b7e10         ; OffsetRect(rowRect, 0, tileHeight)
004ba7f3 call 0x00554760         ; this+0x54.CopyRectFrom(savedClip)
004ba7fb call 0x004f4a90         ; local Region/LObject cleanup
```

The current target doc is correct that the helper saves and restores a region on the normal path, but it overstates the restore as unconditional. If `tileWidth <= 0` or `tileHeight <= 0`, the binary branches directly to `0x004ba7f8` and calls only the stack Region cleanup helper. The explicit restore call at `0x004ba7ec-0x004ba7f3` is reached only after the positive tile-dimension block. Valid callers appear to provide positive dimensions, so this is probably an original precondition rather than a practical UI bug, but formal C++ should preserve this placement unless the supervisor intentionally chooses source-level cleanup normalization.

Direct caller scan found exactly 26 rel32 calls:

```text
0x0045b32e 0x0045e017 0x0045f429 0x0046b09b 0x0046c418
0x0048172d 0x004838d0 0x00496d24 0x00496e54 0x00497132
0x00497262 0x00497443 0x0049838b 0x0049f2bf 0x00500e04
0x00516831 0x00545dac 0x0055534d 0x00555ccd 0x0055a613
0x0055b673 0x0055d3ad 0x0055d657 0x0055d6b5 0x0055d759
0x005bd60d
```

Mapped to current by-memory ranges, those calls sit in ranking dialogs, browser dialog/control panes, chatting UI, button/choice controls, popup/dialog panes, blue alert panes, menu panes, editable paper/right-button/vote panes, ScreenEffecter/WaterFilter effect code, ScrollPane draw code, and menu variety panes. This broad caller set rejects the stale generated owner bias toward `RankingEventListPane`; ranking code is only one caller family.

Absolute text references confirmed:

- `0x0069b3e8` has broad text usage and is referenced by this function at the callback callsite. This is the slot-2 sprite/tile/frame blit callback from [UID:0000TN].
- `0x0067a7e0` is referenced here as `g_pPaletteLib`, and the call to `0x00543d70` is the documented palette-name lookup helper.

## Behavior Summary For Incorporation

[UID:00016A] temporarily replaces the current `GrafPort` clip region with a caller-supplied rectangle, then tiles a frame/source rectangle across the port visible bounds. The source tile rectangle is the `FrameDrawRecord` rectangle at record offset `+0x10`. Tile width is `sourceRect.right - sourceRect.left`; tile height is `sourceRect.bottom - sourceRect.top`. If both dimensions are positive, the function computes the number of rows and columns needed to cover `this+0x44..+0x50`, initializes a row destination rectangle from those visible bounds, clips each destination tile to one tile-size extent, and dispatches each tile through `dword_69B3E8`.

The callback receives the destination `GrafPort` in `ecx`, the frame/tile record pointer, the source rectangle pointer, the current destination rectangle, the byte at `this+0x70`, the palette pointer returned by `g_pPaletteLib->GetPaletteByName(paletteName)`, and a zero flags/options argument. The palette lookup is performed inside the inner tile loop in the binary; a future cleanup could hoist it for source readability only if the project accepts a non-literal rewrite.

After each tile, the destination rectangle is advanced horizontally by `OffsetRect(&destinationRect, tileWidth, 0)`. After each row, the row rectangle is advanced vertically by `OffsetRect(&rowRect, 0, tileHeight)`. On the positive-dimension path, `this+0x54` is restored from the saved stack Region before the local Region cleanup. On non-positive tile dimensions, the body skips the restore and only destructs the stack Region; that exact control flow should be documented because the existing text implies unconditional restoration.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Method Name And Signature

Best inference:

```cpp
void GrafPort::DrawTiledBackground(const RectBounds *clipRect,
                                   const FrameDrawRecord *frameRecord,
                                   const wchar_t *paletteName);
```

Evidence:

- The receiver is `ecx` and is used as a `GrafPort` object with known fields at `+0x44`, `+0x54`, `+0x70`, and callback destination receiver usage.
- The function returns with `ret 0x0c`, so it has three explicit arguments.
- The first argument is passed to `Motion::SetRect` on `this+0x54`, making it a `RectBounds`-like clip/bounds rectangle pointer.
- The second argument is dereferenced at `+0x10`, `+0x14`, `+0x18`, and `+0x1c` as a source rectangle. It is also passed whole to callback slot 2. [UID:0002P6] produces the same draw-record layout, and [UID:0001GF] already calls this helper with a `FrameDrawRecord`.
- The third argument is passed to `PaletteLib::GetPaletteByName`, so `const wchar_t *paletteName` is stronger than raw pointer or resource-id interpretations.

Rejected alternatives:

- `Surface::DrawTiledBackground`: rejected because the receiver is a full `GrafPort` object, the helper mutates `GrafPort` clip state, reads port draw state, and calls a callback with `ecx=this` as destination port.
- Free helper in `Surface.cpp`: rejected as the primary owner for the same receiver-state reasons. Surface docs can retain dependency context because slot 2 ultimately renders to surfaces.
- Caller-owned `RankingEventListPane::Draw...`: rejected because ranking is one of 26 direct callers and generated caller output is polluted by inherited member availability.
- Raw `sub_4ba6b0(uint8_t *, uint8_t *, wchar_t *)`: rejected because all three parameter roles can be identified at source-quality level.

### Frame/Tile Source Record Type

Best inference: `FrameDrawRecord` for first-draft code and docs, with a note that `TileFrameDrawRecord` remains a possible original spelling.

Evidence:

- [UID:0002P6] is explicitly `LoadFrameDrawRecord`; it writes a 0x28-style output record with payload/image metadata, a width-like field, a source rectangle at `+0x10`, and trailing span/baseline fields.
- [UID:0001GF] WaterFilter formal C++ already uses `FrameDrawRecord frameRecord`, fills it through `LoadFrameDrawRecord`, and passes it to `DrawTiledBackground`.
- [UID:00004I] `EPFTileContext` is layout-compatible in important areas, but `DrawTiledBackground` receives records from frame tables and UI resources outside EPF-specific map-tile code.
- [UID:000166] and [UID:0003XE] show `dword_69B3E8` accepts a source descriptor plus source rectangle and destination rectangle; the slot is not restricted to one narrow source-record class.

Rejected alternatives:

- `EPFTileContext *` as the formal parameter: too narrow for UI/effect frame records and conflicts with WaterFilter source shape.
- `TileData_004ba6b0` or `GrafPortState_004ba6b0`: generated-only names from simroot; no source-facing evidence.
- `LoadFrameDrawRecordOutput *`: descriptive but awkward and less likely as original source name than `FrameDrawRecord`.

Impact: this name uncertainty does not block first-draft C++. Use `FrameDrawRecord` now and document the alternate original-spelling possibility in support docs.

### Region, Rectangle, And Cleanup Helpers

Best source names and roles:

- `0x00554680`: `Region::Region`
- `0x00554760`: `Motion::CopyRectFrom` or `Region::CopyRectFrom`, depending on the final class declaration naming. For this method, the role is copying rectangular region state.
- `0x00554720`: `Motion::SetRect` or `Region::SetRect`
- `0x004b7e10`: `OffsetRect(RectBounds *, int dx, int dy)`
- `0x004f4a90`: stack local Region/LObject cleanup helper

Evidence:

- [UID:0001FW], [UID:0000BV], [UID:0000N3], and [UID:0002R9] already identify the Region/Motion rectangle helper family.
- The binary calls the constructor on a stack local, copies `this+0x54` into it, sets `this+0x54` from the caller rectangle, later copies the saved local back into `this+0x54`, and always calls the cleanup helper for the stack local.
- `0x004b7e10` receives a rectangle pointer and x/y deltas at both tile-advance callsites.

Rejected alternatives:

- Treating `this+0x54` as a generic temporary drawing rectangle: rejected because the stack save/restore and helper calls match the documented Region object, not a loose RECT.
- Treating `0x004f4a90` as a `GrafPort` destructor: rejected because it is called on the stack local object, not `this`, and appears only after Region construction.

Impact: helper roles are strong enough for formal C++ and for replacing `sub_` names in target docs.

### GrafPort Field Meanings

Best field inferences for [UID:00016A]:

- `this+0x44..+0x50`: `m_visibleBounds` or `m_visibleRect`, copied as `left/top/right/bottom` and used to compute row/column coverage.
- `this+0x54`: `m_clipRegion` or `m_clipRectRegion`, temporarily replaced for the draw.
- `this+0x70`: `m_drawMode` or `m_blitMode`, a byte passed to `dword_69B3E8` for every tile.
- `this+0x90`: `m_alpha`, not directly read by [UID:00016A] but a receiver-state dependency for slot-2 blits. [UID:0001GF] sets `m_alpha` before calling this method and restores it afterward.

Evidence:

- Raw [UID:00016A] instructions read `+0x44..+0x50` for visible coverage and `+0x70` for the mode byte.
- [UID:00005V] and [UID:0001GF] already validate `+0x70` draw/blit mode and `+0x90` alpha in the effect drawing path.
- [UID:000167] uses the same `GrafPort` receiver family and the slot-2 callback path, supporting the mode/alpha interpretation.

Rejected alternatives:

- `this+0x70` as an alpha field: rejected because WaterFilter separately uses `+0x90` as alpha and sets `+0x70` to draw mode `2`.
- `this+0x44..+0x50` as only caller-supplied bounds: rejected because they are persistent receiver fields copied from `edi`, not arguments.
- `this+0x54` as visible bounds: rejected because visible bounds are at `+0x44`, while `+0x54` is manipulated through Region helper calls.

Impact: field names are high-confidence descriptive names, suitable for GrafPort field glossary updates and first-draft method code.

### Palette Lookup And Global Meaning

Best inference:

- `0x0067a7e0` is `g_pPaletteLib`.
- `0x00543d70` is `PaletteLib::GetPaletteByName`.
- `paletteName` is a wide string resource/palette name such as `L"CAUST.PAL"` in WaterFilter code.

Evidence:

- [UID:0000RW] and PaletteLib support docs identify `dword_67A7E0` as the global palette library.
- [UID:0001GF] passes `L"CAUST.PAL"` to `DrawTiledBackground`.
- The binary loads `g_pPaletteLib` immediately before calling `0x00543d70` with the third target argument.

Rejected alternatives:

- Treating the third argument as a filename resource object: no object methods or reference-count operations are visible; it is passed directly as a string to PaletteLib.
- Treating the callback palette argument as optional state from `GrafPort`: rejected because the function explicitly resolves and passes a palette pointer per tile.

Impact: no source blocker. The per-tile lookup should be documented because a source cleanup may be tempting but would no longer be instruction-faithful.

### Callback Slot `dword_69B3E8`

Best inference:

- `dword_69B3E8` is the slot-2 sprite/tile/frame blit procedure from [UID:0000TN].
- Best current alias remains `g_pfnBlitSprite` or the more generic `SurfaceSpriteBlitProc`.
- For [UID:00016A], the callback signature is effectively:

```cpp
typedef void (__thiscall *SurfaceSpriteBlitProc)(GrafPort *dstPort,
                                                 const FrameDrawRecord *sourceRecord,
                                                 const RectBounds *sourceRect,
                                                 const RectBounds *destinationRect,
                                                 unsigned char drawMode,
                                                 DLPalette *palette,
                                                 int flags);
```

Evidence:

- The callsite passes destination port in `ecx`, then pushes source record, source rect, destination rect, mode byte, palette, and zero flags/options.
- [UID:000167] uses the same global callback slot for `GrafPort::BlitSurface`.
- [UID:000166] forwards a source record and source rect to the same callback.
- [UID:0003XE] uses `dword_69B3E8` with tile-buffer source data, reinforcing that the slot is a generic frame/sprite/tile blitter rather than a text or single-class callback.

Rejected alternatives:

- `g_pfnBlitText`: rejected. No text glyph/string data is involved at [UID:00016A], and the same slot handles sprite/tile records.
- `g_uiTileRenderer`: too vague and UI-specific; the slot is lower-level render dispatch shared by many callers.
- `SurfaceRectFrameProc`: rejected because [UID:000168] uses `dword_69B3E4`, not this slot.

Impact: callback typedef exactness remains a support-level uncertainty, not a blocker for [UID:00016A]. The callback-table doc should record that [UID:00016A] proves the first source argument can be a `FrameDrawRecord`/EPF-compatible source descriptor rather than only an `EPFTileContext`.

### Source Placement And Owner Ranking

Ranked source-placement alternatives:

1. Keep [UID:00016A] as `GrafPort::DrawTiledBackground` in [UID:00005V] and emitted through [UID:0000JR] `NexusTK/render/GrafPort.cpp`.
2. Mention as Surface-render dependency in [UID:0000OC] only, because the final pixel work goes through Surface callback infrastructure.
3. Mention as caller dependency in WaterFilter, ScrollPane, ranking, dialog, and other UI docs only where those callers use it.

Rejected weaker placements:

- Surface owner/emitter: rejected because this target mutates `GrafPort` clip state and reads `GrafPort` visible/draw state before delegating to Surface-level callback code.
- `RankingEventListPane` owner: rejected as generated-output pollution. Ranking has several calls but is not semantically privileged among 26 callers.
- `CompositePixels16`/Pixel helper owner: rejected because [UID:000169] is an adjacent low-level Surface pixel operation, while [UID:00016A] is a higher-level GrafPort tiling wrapper.
- `ImageFrameTable`/`LoadFrameDrawRecord` owner: rejected because those pages produce or describe the source record; [UID:00016A] consumes that record while drawing into a GrafPort.
- `ScreenEffecter`/WaterFilter owner: rejected because [UID:0001GF] is only one effect caller. Its value is proving `m_drawMode`, `m_alpha`, and `FrameDrawRecord` usage.

Impact: no split or owner change is needed. The existing `CANONICAL_OWNER:00005V` and `EMITTER_UIDS:00005V` should remain.

### B002/B003 Surface-Render Cluster Reconciliation

The accepted [UID:000167] routing and [UID:000168] routing do not conflict with [UID:00016A]:

- [UID:000167] is a GrafPort blit wrapper around slot 2 and direct surface/source state.
- [UID:000168] is a GrafPort rectangle-frame helper through slot 1 `dword_69B3E4`.
- [UID:00016A] is a GrafPort tiling wrapper around slot 2, repeatedly dispatching a frame source rectangle over visible bounds.
- [UID:000169] remains an adjacent Surface pixel-composition helper and should not absorb [UID:00016A].
- [UID:0001GF] remains a WaterFilter caller that configures `m_drawMode`, `m_alpha`, and `FrameDrawRecord` before using [UID:00016A].

Impact: the support docs should present these as a layered render family rather than competing owners.

### Generated Output Pollution

Current formal autogen state:

- `auto-generated/-ag-memory-coverage.md` lists [UID:00016A] as emitting through `auto-generated/NexusTK/render/GrafPort.cpp`, but it is not coded because the formal C++ block is blank.
- `auto-generated/NexusTK/render/GrafPort.cpp` currently includes accepted `GrafPort` methods such as `BlitSurface` and `DrawRectFrame`, but not [UID:00016A].
- `simroot_v2/render/class_GrafPort.cpp` contains a generated `DrawTiledBackground` body, but it uses generated types, modern style, and unstable callback aliases.
- `simroot_v2/class_RankingEventListPane.cpp` calls `DrawTiledBackground` through generated caller code and casts tile context data; this should not drive ownership.

Specific generated artifacts to avoid copying:

- Generated names such as `GrafPortState_004ba6b0`, `TileData_004ba6b0`, and `g_pfnBlitText`.
- Modern `std::uint8_t`, `auto`, and alignment/cast-heavy code shape in simroot.
- Caller-biased `RankingEventListPane` source placement.

Impact: generated pollution is now understood and should no longer cap the target below first-draft C++ readiness.

### Range And Split Decision

No split is recommended.

Evidence:

- The exact function is one `0x16d`-byte body with single prologue/epilogue and three explicit arguments.
- Leading and trailing padding are clean.
- The callees are already covered or support-covered helper functions.
- The loops and callback callsite are one coherent method. Splitting would create artificial children for loop internals or stack-local helper calls and would reduce source fidelity.

Rejected alternatives:

- Split a callback-dispatch child: no function boundary exists; the callsite is loop-local code.
- Split region save/restore helpers: those are external helper calls already documented.
- Merge with [UID:000169]: adjacent padding and different helper semantics reject a merge.

Impact: keep one page and raise score rather than adding child pages.

### Remaining Uncertainty And Score Impact

Unresolved but non-blocking:

- Original spelling of `FrameDrawRecord` versus `TileFrameDrawRecord` is not fully proven. Current source-facing docs and WaterFilter C++ favor `FrameDrawRecord`.
- Exact final callback typedef for slot 2 remains broader than any one caller because it accepts source descriptors used by [UID:000167], [UID:000166], [UID:0003XE], and [UID:00016A].
- Exact member names for `m_visibleBounds`, `m_clipRegion`, and `m_drawMode` are inferred from behavior and support docs rather than original symbols.
- The non-positive-dimension no-restore path could be original-source precondition behavior or an artifact of optimized cleanup placement. The binary behavior is exact, but the intended source style is not provable from available evidence.

These uncertainties cap the target below the mid-90s but do not justify staying at `84/90` or withholding first-draft C++. Recommended `88/91` reflects exact range/body/caller evidence plus defensible names, with remaining source-spelling uncertainty documented.

## First-Draft C++ Recommendation

Populate the formal C++ block for [UID:00016A] with a source-facing first draft. This draft intentionally preserves the observed restore placement inside the positive tile-dimension branch.

```cpp
void GrafPort::DrawTiledBackground(const RectBounds *clipRect,
                                   const FrameDrawRecord *frameRecord,
                                   const wchar_t *paletteName)
{
    Region savedClipRegion;
    savedClipRegion.CopyRectFrom(&m_clipRegion);
    m_clipRegion.SetRect(clipRect);

    const RectBounds *sourceRect = &frameRecord->sourceRect;
    const int tileWidth = sourceRect->right - sourceRect->left;
    const int tileHeight = sourceRect->bottom - sourceRect->top;

    if (tileWidth > 0 && tileHeight > 0) {
        const int rowCount =
            (m_visibleBounds.bottom - m_visibleBounds.top - 1) / tileHeight + 1;
        const int columnCount =
            (m_visibleBounds.right - m_visibleBounds.left - 1) / tileWidth + 1;

        RectBounds rowRect = m_visibleBounds;
        rowRect.right = rowRect.left + tileWidth;
        rowRect.bottom = rowRect.top + tileHeight;

        for (int row = 0; row < rowCount; ++row) {
            RectBounds destinationRect = rowRect;

            for (int column = 0; column < columnCount; ++column) {
                DLPalette *palette = g_pPaletteLib->GetPaletteByName(paletteName);

                g_pfnBlitSprite(this,
                                frameRecord,
                                sourceRect,
                                &destinationRect,
                                m_drawMode,
                                palette,
                                0);

                OffsetRect(&destinationRect, tileWidth, 0);
            }

            OffsetRect(&rowRect, 0, tileHeight);
        }

        m_clipRegion.CopyRectFrom(&savedClipRegion);
    }
}
```

C++ notes for supervisor application:

- If the GrafPort class glossary settles on `m_blitMode` instead of `m_drawMode`, replace that one member name consistently. [UID:0001GF] currently supports the draw-mode wording.
- If callback-table support prefers `SurfaceSpriteBlitProc` as the global alias instead of `g_pfnBlitSprite`, use that alias in the formal block. Do not use `g_pfnBlitText`.
- If the final record declaration uses `TileFrameDrawRecord`, replace `FrameDrawRecord` consistently. The field `sourceRect` should map to record offset `+0x10`.
- Do not hoist `GetPaletteByName` outside the inner loop in first-draft formal C++; the binary performs the lookup per tile.
- Do not move `m_clipRegion.CopyRectFrom(&savedClipRegion)` outside the positive-dimension `if` unless the project intentionally accepts a source-level behavior normalization.

## Exact Supervisor Edits

### Target [UID:00016A] Metadata Replacement

Placement: replace the existing target metadata values in `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`.

```yaml
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005V
EMITTER_UIDS: 00005V
```

### Target [UID:00016A] Summary / Status Text

Placement: replace current source-quality/open-question text that says the public method name, source split, and generated owner route are provisional.

Suggested replacement text:

```markdown
B002 2026-06-18 source-quality reanalysis confirms this range as a single `GrafPort::DrawTiledBackground` method. The function has an exact `0x004ba6b0-0x004ba81d` boundary with padding on both sides, receives `GrafPort *this` in `ecx`, returns with `ret 0x0c`, and takes `const RectBounds *clipRect`, `const FrameDrawRecord *frameRecord`, and `const wchar_t *paletteName`. It saves `this+0x54` into a stack `Region`, replaces `this+0x54` from the caller rectangle, reads the source tile rectangle at `frameRecord+0x10`, computes tile width/height from that rectangle, covers `this+0x44..+0x50` visible bounds with repeated destination rectangles, resolves the named palette through `g_pPaletteLib->GetPaletteByName`, and dispatches each tile through slot-2 callback `dword_69B3E8`. `this+0x70` is the draw/blit mode byte passed to the callback; `this+0x90` is not read directly here but is a slot-2 receiver-state dependency proven by the WaterFilter caller. The normal positive-dimension path restores `this+0x54` from the saved Region before stack cleanup. The binary branches directly to stack Region cleanup without the restore when tile width or height is non-positive, so docs and first-draft C++ should preserve that observed control flow unless the project intentionally applies source-level cleanup normalization.
```

### Target [UID:00016A] Ownership / Generated Pollution Text

Placement: replace existing generated-owner or source-placement uncertainty paragraph.

```markdown
Ownership remains [UID:00005V] `GrafPort` and emission remains through [UID:0000JR] `NexusTK/render/GrafPort.cpp`. The 26 direct callers span ranking, browser, chatting, button/choice, popup/dialog, alert, menu, editable-paper, vote-menu, effect, WaterFilter, ScrollPane, and menu-variety code. This breadth rejects `RankingEventListPane` and other caller-owned generated routes as pollution. [UID:0000OC] `Surface` and [UID:0000TN] `SurfaceRenderCallbackTable` remain support dependencies because the final blit is callback-dispatched, but [UID:00016A] itself mutates and reads `GrafPort` state and should not move to Surface ownership.
```

### Target [UID:00016A] Helper / Field Glossary Insert

Placement: add under the target's field/helper notes.

```markdown
Resolved helper and field aliases for this body:

- `0x00554680`: `Region::Region` stack local constructor.
- `0x00554760`: `Region`/`Motion` rectangle copy helper, used to save and restore `this+0x54`.
- `0x00554720`: `Region`/`Motion` rectangle set helper, used to install the caller clip rectangle.
- `0x004b7e10`: `OffsetRect(RectBounds *, int dx, int dy)`, used for horizontal tile advance and vertical row advance.
- `0x004f4a90`: stack Region/LObject cleanup helper.
- `0x0067a7e0`: `g_pPaletteLib`.
- `0x00543d70`: `PaletteLib::GetPaletteByName`.
- `0x0069b3e8`: slot-2 sprite/tile/frame blitter, best alias `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`.
- `this+0x44..+0x50`: `m_visibleBounds` / `m_visibleRect`.
- `this+0x54`: `m_clipRegion`.
- `this+0x70`: `m_drawMode` / `m_blitMode`.
- `this+0x90`: `m_alpha`, a callback-consumed receiver-state dependency set by effect callers before invoking this method.
```

### Target [UID:00016A] Formal C++ Block

Placement: populate the currently blank formal C++ block with the block from `## First-Draft C++ Recommendation`.

### [UID:00005V] GrafPort Support Update

Placement: in `by-class/GrafPort.md`, add [UID:00016A] to the accepted render-helper/source-quality cluster near existing [UID:000167] and [UID:000168] notes.

```markdown
[UID:00016A] `GrafPort::DrawTiledBackground` is now source-routed to this class. It is a `GrafPort` method, not a Surface or caller-owned helper: the body saves/replaces `m_clipRegion`, reads `m_visibleBounds`, passes `m_drawMode` to slot-2 `dword_69B3E8`, depends on `m_alpha` as callback-visible receiver state, resolves palettes through `g_pPaletteLib`, and repeatedly blits a `FrameDrawRecord` source rectangle over the visible bounds. This reinforces the GrafPort field glossary for `m_visibleBounds` (`+0x44..+0x50`), `m_clipRegion` (`+0x54`), `m_drawMode`/`m_blitMode` (`+0x70`), and `m_alpha` (`+0x90`).
```

Recommended [UID:00005V] metadata update:

```yaml
COMPLETION: 88
CONFIDENCE: 90
```

### [UID:0000JR] GrafPort File Support Update

Placement: in `by-file/GrafPort.md`, add to the render-helper emission list.

```markdown
[UID:00016A] should emit as `GrafPort::DrawTiledBackground` in `NexusTK/render/GrafPort.cpp`. The broad 26-caller set and direct receiver-state usage reject caller-owned files and support keeping the tiled-background helper with the other GrafPort draw/blit wrappers, alongside [UID:000167] and [UID:000168].
```

Recommended [UID:0000JR] metadata update:

```yaml
COMPLETION: 89
CONFIDENCE: 88
```

### [UID:0000OC] Surface File Support Update

Placement: in `by-file/Surface.md`, add or revise the dependency note for GrafPort-routed helpers.

```markdown
[UID:00016A] remains a Surface-render dependency but not a Surface owner. Its final pixel transfer is dispatched through Surface callback slot `dword_69B3E8`, but the wrapper itself saves/replaces GrafPort clip state and reads GrafPort visible/draw state. Keep Surface support notes focused on callback implementation and pixel-transfer dependencies; do not reassign [UID:00016A] away from [UID:00005V].
```

No score change is required for [UID:0000OC].

### [UID:0000TN] SurfaceRenderCallbackTable Support Update

Placement: under slot `0x0069b3e8` / `dword_69B3E8` notes.

```markdown
[UID:00016A] proves slot `0x0069b3e8` is used by `GrafPort::DrawTiledBackground` with `ecx` as the destination `GrafPort`, a frame/tile source descriptor pointer, a source `RectBounds *` at descriptor offset `+0x10`, a destination `RectBounds *`, a draw/blit mode byte from `GrafPort+0x70`, a palette pointer from `PaletteLib::GetPaletteByName`, and zero flags/options. This supports a generic `SurfaceSpriteBlitProc` / `g_pfnBlitSprite` alias and rejects text-specific or caller-specific aliases. The first source argument should be described as a `FrameDrawRecord`/EPF-compatible source descriptor until the final shared typedef is settled.
```

No score change is required for [UID:0000TN].

### [UID:0002P6] / [UID:0000UX] LoadFrameDrawRecord Support Update

Placement: in the source-record/type notes for `LoadFrameDrawRecord`.

```markdown
[UID:00016A] consumes the record produced by `LoadFrameDrawRecord` as the source descriptor for tiled GrafPort drawing. The `+0x10..+0x1f` rectangle is used as the source tile rectangle, with width `right-left` and height `bottom-top`; the whole record is passed to callback slot `dword_69B3E8`. This supports the source-facing `FrameDrawRecord` name in caller code such as WaterFilter and in `GrafPort::DrawTiledBackground`, while leaving exact final field names as the remaining shared record-typing question.
```

No target score change is required, but the [UID:0002P6] by-memory coverage row is stale and should be replaced as listed below.

## Coverage Row Recommendation

Agents must not edit coverage reports directly. The following rows are exact supervisor-owned replacement text.

### `by-memory/-coverage-report.md` [UID:00016A]

Replace the current [UID:00016A] row with:

```markdown
    - [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) 0x004ba6b0-0x004ba81d | class method | GrafPort::DrawTiledBackground : reconstructable : 88% : very strong : B002 2026-06-18 source-quality reanalysis confirms exact `0x16d` body, three-byte leading/trailing padding, 26 direct rel32 callers across ranking/browser/chatting/button/dialog/alert/menu/effect/scroll UI paths, `GrafPort *` receiver and three-argument `ret 0xc` signature, temporary `this+0x54` clip-region replacement through `Region::Region`, `Motion::CopyRectFrom`, and `Motion::SetRect`, tile dimensions from `FrameDrawRecord` source rect `+0x10..+0x1f`, visible bounds at `this+0x44..+0x50`, draw/blit mode byte `this+0x70`, named palette lookup through `g_pPaletteLib` / `PaletteLib::GetPaletteByName`, repeated slot-2 `dword_69B3E8` blits, exact restore caveat for non-positive tile dimensions, stale RankingEventListPane/Surface owner rejection, GrafPort class owner/emitter [UID:00005V], and first-draft C++ readiness.
```

### `by-class/-coverage-report.md` [UID:00005V]

Replace the current [UID:00005V] row with:

```markdown
- [UID:00005V][GrafPort](by-class/GrafPort.md) : reconstructable : 88% : very strong : Core graphics-port class with backing-store state, dirty/clip/draw helpers, constructor/update/destructor coverage, Batch 119 wrapped text/text-effect helper ownership evidence, B003 `GrafPort::BlitSurface` routing for [UID:000167], B002 `GrafPort::DrawRectFrame` routing for [UID:000168], and B002 `GrafPort::DrawTiledBackground` routing for [UID:00016A] with `m_clipRegion`, `m_visibleBounds`, `m_drawMode`, `m_alpha` dependency, `FrameDrawRecord` tile source rects, `g_pPaletteLib`/`PaletteLib::GetPaletteByName`, and `dword_69B3E8` repeated sprite/tile blits; direct parent for assigned text/blit/frame/tiled-background helpers after GrafPort file and class cleared the corrected 85/85 gate.
```

### `by-file/-coverage-report.md` [UID:0000JR]

Replace the current [UID:0000JR] row with:

```markdown
- [UID:0000JR][GrafPort](by-file/GrafPort.md) : reconstructable : 89% : strong : Render-file bucket for GrafPort and related draw helpers, with accepted ownership for text helpers, [UID:000167] `GrafPort::BlitSurface`, [UID:000168] `GrafPort::DrawRectFrame`, and [UID:00016A] `GrafPort::DrawTiledBackground`; source route remains `NexusTK/render/GrafPort.cpp`, with Surface callback/table docs retained only as render-backend dependencies.
```

### `by-file/-coverage-report.md` [UID:0000OC]

If the Surface row currently lists only [UID:000167]/[UID:000168] as former-bucket or dependency context, replace it with a row that also names [UID:00016A]. Keep the score unchanged unless the supervisor is already updating Surface for other work.

Suggested replacement:

```markdown
- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 88% : strong : Surface render backend and callback dependency file; [UID:000167], [UID:000168], and [UID:00016A] are retained here as GrafPort-owned dependency/former-bucket context rather than Surface-owned emitters, while low-level callback and pixel-transfer helpers remain under Surface review.
```

### `by-memory/-coverage-report.md` [UID:0002P6] Stale Support Row

During required support review, [UID:0002P6] was found stale in the shared coverage report: the by-memory page is already `86/90`, while the row still reports `80%`. Replace the [UID:0002P6] row with:

```markdown
        - [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) 0x004d1600-0x004d165d | function | LoadFrameDrawRecord : reconstructable : 86% : strong : Exact ImageFrameTable-owned frame-record projection helper with no callees, ten modeled caller functions/81 total refs, confirmed `0x5d` boundary and padding, output record fields at `+0x04/+0x0c/+0x10/+0x20/+0x24`, next-record boundary/span semantics, adjacent raw helper split pages [UID:00031T]/[UID:00031U], WaterFilterEffecter CAUST consumer evidence, [UID:00016A] tiled-background consumer evidence for the source rect at record `+0x10`, and final C++ intentionally blank pending shared frame-record field names and return-value intent.
```

## Validator Commands

Suggested commands after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [00016A-GrafPortDrawTiledBackground-source-quality-removed.md](00016A-GrafPortDrawTiledBackground-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files / Direct-Edit Statement

Created exactly one report file:

```text
tools/leaser/Agents/Agent-B002/research/00016A-GrafPortDrawTiledBackground-source-quality.md
```

No by-memory, by-class, by-file, by-global, by-item, generated report, generated source, IDA database, or shared coverage-report files were edited by this agent. All coverage/support/metadata/C++ changes above are recommendations for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00016A-GrafPortDrawTiledBackground-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00016A"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016A-GrafPortDrawTiledBackground-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00016A-GrafPortDrawTiledBackground-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
