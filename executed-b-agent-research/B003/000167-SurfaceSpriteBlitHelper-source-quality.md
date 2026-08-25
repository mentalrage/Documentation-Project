** TARGET-REPORT-UID:000167 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000167 SurfaceSpriteBlitHelper Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: rename the source-facing function direction from a Surface bucket helper to `GrafPort::BlitSurface` / `GrafPort::BlitSurfaceFrom`, keep the memory filename if the supervisor does not want a rename yet, but change the exact target owner/emitter from [UID:0000OC] `Surface` to [UID:00005V] `GrafPort`.
- Final disposition: source-authored, reconstructable, exact live method body at `0x004ba250-0x004ba444`; no split repair is required.
- Required action: populate first-draft C++ in [UID:000167], update metadata to `87/90`, reroute to `CANONICAL_OWNER:00005V` / `EMITTER_UIDS:00005V`, and update support docs/coverage rows with the field and source-placement findings below.
- Confidence: high for range, callers, DirectDraw/software paths, receiver layout, and MapPane owner rejection; medium-high for the final original public method spelling because no PDB/source names are available.

## Supporting Research

## Target

- Target UID: `000167`
- Target path: `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
- Assignment id: `B003-goal2-surface-sprite-blit-helper-source-quality-000167-20260618`
- Required report path: `tools/leaser/Agents/Agent-B003/research/000167-SurfaceSpriteBlitHelper-source-quality.md`
- Current state: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank formal C++.
- Current generated state: `auto-generated/-ag-memory-coverage.md` routes [UID:000167] to `auto-generated/NexusTK/render/Surface.cpp`, but `auto-generated/NexusTK/render/Surface.cpp` is currently zero bytes because the target formal C++ is blank.

## Evidence Checked

- Required instructions: `tools/leaser/Agents/Agent-B003/goal.md`, `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B003/notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Target page: [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`.
- Direct owner/source candidates:
  - [UID:0000OC] `by-file/Surface.md`
  - [UID:0000JR] `by-file/GrafPort.md`
  - [UID:00005V] `by-class/GrafPort.md`
  - [UID:0000L3] `by-file/MapPane.md`
- Support pages:
  - [UID:000165] `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
  - [UID:000166] `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
  - [UID:000168] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
  - [UID:000169] `by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md`
  - [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
  - [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
  - [UID:0001QI] `by-meta/client_new_rendering_mode.md`
  - [UID:00004I] `by-class/EPFTileContext.md`
- Generated/read-only state:
  - `auto-generated/NexusTK/render/Surface.cpp`
  - `auto-generated/NexusTK/render/GrafPort.cpp`
  - `auto-generated/NexusTK/map/MapPane.cpp` search for stale `DrawSpriteAtPosition` output
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `by-memory/-coverage-report.md`
- Prior executed B-agent context:
  - `Agent-B002/research/executed/0003XE-SurfaceTileBufferBlitRaw-goal2-reanalysis.md`
  - Current Agent-B003 notes about the accepted GrafPort split/source-quality and Surface raw-island work.
- Raw executable checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, length `2679296`, timestamp `2025-12-11 11:24:42`.
- Local PE/Capstone checks run in this session:
  - Section parse and byte windows for `0x004ba24a-0x004ba250`, `0x004ba250-0x004ba444`, and `0x004ba444-0x004ba450`.
  - Absolute VA scan for `0x004ba250`.
  - Direct `E8/E9/0F 8*` rel32 scan for `0x004ba250`.
  - Absolute operand scan for `0x0069b3e8`.
  - Capstone disassembly of `0x004ba250-0x004ba444`.
  - Capstone disassembly of support helpers `0x004b9820` `UpdateSurfaceInfo`, `0x004b98c0` `EndPaint`, `0x004b8bf0` `GrafPort` constructor, selected `0x004b8e20` render-region instructions, and callback targets `0x004bc090` / `0x004c0f80`.
  - Clean caller-window disassembly around `0x004f12b4`, `0x0050978f`, `0x00549986`, `0x0055b27b`, `0x0055b45f`, `0x0055b592`, `0x0055b930`, and `0x0055b9c7`.

## Binary Facts From Current Recheck

- PE image base is `0x00400000`; `.text` maps executable code and contains the target.
- `0x004ba24a-0x004ba250` is six `0xcc` bytes before the helper.
- `0x004ba250-0x004ba444` is a 500-byte modeled function body beginning `55 8b ec 83 ec 30 ...`.
- `0x004ba444-0x004ba450` is twelve `0xcc` bytes before [UID:000168] `GrafPortDrawRectFrame`.
- Raw scan found zero absolute VA dword hits for `0x004ba250`; this is expected for an ordinary directly called function and does not contradict liveness.
- Raw rel32 scan found exactly eight direct `call` hits to `0x004ba250`: `0x004f12b4`, `0x0050978f`, `0x00549986`, `0x0055b27b`, `0x0055b45f`, `0x0055b592`, `0x0055b930`, and `0x0055b9c7`.
- Raw scan found 114 absolute references to callback slot `0x0069b3e8`, matching [UID:0000TN]'s documented broad slot-2 fanout.
- The target body references `dword_69B3E8` at `0x004ba2ca` and `0x004ba403`.
- The target calls [UID:000165] helpers `0x004b9820` and `0x004b98c0`, the security-cookie check at `0x005c772f`, the Win32 `SetRect` import pointer at `0x0060d43c`, and DirectDraw surface vtable slots from object field `+0x18`.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Helper Name And Signature

Best defensible name: `GrafPort::BlitSurface` or `GrafPort::BlitSurfaceFrom`.

Recommended draft signature:

```cpp
void GrafPort::BlitSurface(GrafPort* source,
                           const RECT* sourceRect,
                           const RECT* destinationRect,
                           int mode);
```

Evidence:

- The function is a true `__thiscall`: it receives the destination object in `ecx`, preserves it in `edi`, uses four stack arguments, and returns with `ret 0x10`.
- The destination and source objects both match the documented `GrafPort` layout. The body reads `+0x18` DirectDraw surface pointers, passes `source + 0x1c` to the software sprite callback, reads/writes `+0x90` alpha, branches on `+0x94` software-buffer state, and clears `+0x20/+0x28` paint-context subfields.
- Direct callers pass a destination GrafPort/Panes-derived receiver in `ecx`, a source GrafPort-like object as the first pushed argument, a source rectangle, a destination rectangle, and a mode byte/int. For example, `PhotoPane::OnPaint` at `0x00549950` sets `ecx = this`, pushes `this+0xf8` as the source surface, pushes the same local rectangle as source/destination, and passes mode `0`.
- Layer/map/effect callers pass broader pane render mode bytes such as `sourcePane + 0xb5`, which explains why the fourth argument is not merely a DirectDraw flag.

Rejected alternatives:

- `MapPane::DrawSpriteAtPosition`: rejected. MapPane is one caller and [UID:0000L3] now explicitly excludes `0x004ba250` from `map/MapPane.cpp`. The caller set spans Layer render traversal, MapPane render, PhotoPane paint, and four ScreenEffecter runtime paths.
- `SurfaceSpriteBlitHelper` as a file-local free function: rejected as final source shape. It is a useful documentation title and Surface callback dependency, but the `ecx` receiver and concrete `GrafPort` field model make a class method more defensible than a cdecl/static Surface helper.
- `DrawSpriteAtPosition`: rejected as too narrow. The function blits a whole source surface/GrafPort view; effecters use it for shifted/flipped screen regions and PhotoPane uses it for cached surface drawing, not only sprite placement.
- `CopyPixels`, `CopySurfaceRect`, or `BltFast` as the public name: plausible but weaker. The body chooses DirectDraw `BltFast` only for modes `0` and `1` when the destination is DirectDraw-backed; otherwise it uses the software render callback and alpha/state transfer. `BlitSurface` captures both paths without overfitting to the DirectDraw branch.

### Receiver / Source / Destination Types

Best defensible type: both destination receiver and source argument are `GrafPort*` or a `GrafPort`-layout render target.

Evidence:

- The `GrafPort` constructor at `0x004b8bf0` writes the vtable, initializes `this+0x1c` through [UID:00004I] `EPFTileContext::InitTileContext`, initializes rectangles at `+0x2c` and `+0x44`, point/cursor state at `+0x68`, draw mode/default state at `+0x70..+0x90`, and clears DirectDraw/software backing fields `+0x18`, `+0x20`, `+0x28`, `+0x94`, `+0x98`, and `+0x9c`.
- [UID:00005V] already documents `+0x94` as `m_usesSoftwareBuffer` and `+0x90` as current alpha/opacity evidence from WaterFilterEffecter.
- [UID:00004I] documents the 0x28-byte `EPFTileContext` layout; the constructor call at `lea ecx, [edi+0x1c]` proves `GrafPort + 0x1c` is the embedded decoded-surface context, not an anonymous pointer.
- The software callback targets `0x004bc090` and `0x004c0f80` save `ecx` as the destination object and check destination byte `+0x71`, matching GrafPort draw-enabled state.

Rejected alternatives:

- A separate `Surface` class: no `by-class/Surface.md` exists, no vtable/RTTI evidence for a Surface class was found in this pass, and all concrete receiver offsets match the existing `GrafPort` class page.
- `EPFTileContext*` as the method receiver: the callback source descriptor is `source + 0x1c`, but the method receiver is the enclosing GrafPort because it also needs DirectDraw surface pointer `+0x18`, alpha `+0x90`, and software-buffer flag `+0x94`.
- DirectDraw surface wrapper as the receiver: the function stores DirectDraw interfaces inside GrafPort fields and calls COM vtable slots through `+0x18`, but the receiver is not itself an `IDirectDrawSurface`.

### Field Names And Types

Recommended field model for this target:

| Offset | Best source-facing name/type | Evidence and role |
| --- | --- | --- |
| `+0x18` | `LPDIRECTDRAWSURFACE m_ddSurface` / DirectDraw surface interface pointer | DirectDraw branch loads `destination + 0x18` and `source + 0x18`; `UpdateRenderRegion` writes the newly created surface here; cleanup calls COM `Release`/`Unlock` style vtable slots from this pointer. |
| `+0x1c` | `EPFTileContext m_surfaceContext` / `m_paintContext` start | `GrafPort` constructor calls `EPFTileContext::InitTileContext` at `this + 0x1c`; target passes `source + 0x1c` as the first software sprite callback argument. |
| `+0x20` | `m_surfaceContext.pixelData` | `UpdateSurfaceInfo` writes the locked DirectDraw or software pixel pointer to `this+0x20`; target clears it after callback paths. This is `EPFTileContext +0x04`, not a separate top-level field. |
| `+0x28` | `m_surfaceContext.rowStride` / `m_surfaceContext.rowPitchPixels` | `UpdateSurfaceInfo` derives it from DirectDraw pitch or software stride and writes `this+0x28`; target clears it after callback paths. This is `EPFTileContext +0x0c`. |
| `+0x90` | `float m_alpha` / `m_currentAlpha` / `m_opacity` | Target saves destination alpha, borrows source alpha when source `<= 1.0f`, and restores saved alpha when saved `<= 1.0f`. [UID:00005V] already records WaterFilterEffecter evidence for `+0x90` as current draw alpha/opacity. |
| `+0x94` | `bool m_usesSoftwareBuffer` | [UID:00022M] writes this byte; constructor clears it; `UpdateSurfaceInfo`, `EndPaint`, and this target branch on it to choose software-buffer versus DirectDraw lock/unlock behavior. |

Rejected names:

- `dirtyFlag` for `+0x94`: rejected by accepted GrafPort evidence. Dirty/exposed state is Region-backed; `+0x94` selects owned software backing.
- `callback payload pointer` for `+0x1c`: superseded. It is the embedded `EPFTileContext`; the callback receives its address as a source descriptor.
- Top-level `lockedPixels` and `lockedStride` fields at `+0x20/+0x28`: partially correct behaviorally, but structurally incomplete. They are the `pixelData` and `rowStride` subfields of the embedded `EPFTileContext`.
- `scale` for `+0x90`: possible in older notes, but current target and WaterFilterEffecter usage support alpha/opacity more strongly than geometric scale.

### DirectDraw Versus Software Callback Mode

The destination `m_usesSoftwareBuffer` byte decides the first-level path:

- If destination `+0x94` is nonzero, the helper uses the software callback path immediately.
- If destination `+0x94` is zero and `mode == 1`, it builds local Win32 `RECT`s and calls `destination->m_ddSurface->BltFast(destinationRect->left, destinationRect->top, source->m_ddSurface, &sourceRect, 0x11)`.
- If destination `+0x94` is zero and `mode == 0`, it uses the same DirectDraw `BltFast` call with flag `0x10`.
- If destination `+0x94` is zero and `mode` is neither `0` nor `1`, it falls back to `UpdateSurfaceInfo`, software sprite callback dispatch, alpha borrow/restore, and `EndPaint` calls for both destination and source.

DirectDraw flag inference:

- The called COM vtable slot is `+0x1c` on the DirectDraw surface, matching `IDirectDrawSurface::BltFast` rather than `Blt`.
- The push order is `flags`, source rect pointer, source surface pointer, destination `y`, destination `x`, `this surface`, matching `BltFast(DWORD x, DWORD y, LPDIRECTDRAWSURFACE src, LPRECT srcRect, DWORD flags)`.
- `0x10` is best named `DDBLTFAST_WAIT`.
- `0x11` is best named `DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY`.

Mode enum inference:

```cpp
enum GrafPortBlitMode {
    kGrafPortBlitCopy = 0,          // hardware path: DDBLTFAST_WAIT
    kGrafPortBlitSourceColorKey = 1 // hardware path: DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY
    // Other values are accepted and routed through software callbacks.
};
```

Do not claim the full enum is solved. Caller windows show Layer/ScreenEffecter paths passing pane draw mode bytes such as `sourcePane + 0xb5`, and [UID:00016A] / WaterFilterEffecter evidence shows related draw mode value `2` reaches `dword_69B3E8` in tiled-background paths. The safe conclusion is that `0` and `1` have precise DirectDraw fast-blit meanings; higher mode values are software composition/draw modes whose exact global enum names remain broader GrafPort/Pane render-mode work.

### Callback Slot `dword_69B3E8` Type And Name

Best descriptive slot name: `g_pfnBlitSprite` or `g_pfnSurfaceSpriteBlit`.

Recommended typedef direction:

```cpp
typedef void (__thiscall *SurfaceSpriteBlitProc)(
    GrafPort* destination,
    EPFTileContext* sourceContext,
    const RECT* sourceRect,
    const RECT* destinationRect,
    int mode,
    void* palette,
    int flags);
```

Evidence:

- [UID:0000TN] identifies slot `0x0069b3e8` as table slot 2, installed as either `0x004bc090` or `0x004c0f80` by the surface initializer.
- Those target pages are already named `SoftwareRenderCompatSpriteBlitCallback` and `SoftwareRenderRgb565SpriteBlitCallback`.
- Current disassembly of `0x004bc090` and `0x004c0f80` shows both callbacks save `ecx` as the destination GrafPort, use stack argument 1 as the source context pointer, stack arguments 2/3 as source/destination rectangles, stack argument 4 as mode, and stack argument 5 as palette or null fallback.
- This helper calls the slot with destination `ecx`, `source + 0x1c`, source rect, destination rect, mode, null palette, and zero flags.

Rejected names:

- `dword_69B3E8`: compiler/generated storage name, not source quality.
- `g_uiTileRenderer`: rejected by broader docs as a stale alias over EPF/resource draw paths.
- `g_pfnBlitTileFrame` as the sole name: too tile/frame-specific for this target and for callback pages named sprite blit; acceptable as a historical alias in support docs but weaker than `g_pfnBlitSprite` / `g_pfnSurfaceSpriteBlit`.
- A MapPane-specific callback name: rejected by 114 broad slot references and surface initializer ownership.

### Owner / Source Route

Ranked ownership recommendation:

1. [UID:00005V] `GrafPort` class, emitted through [UID:0000JR] `GrafPort.cpp`: accepted.
   - Evidence for: true `__thiscall` receiver; concrete GrafPort fields; embedded `EPFTileContext` at `+0x1c`; DirectDraw surface field `+0x18`; software-buffer byte `+0x94`; alpha field `+0x90`; sibling class-owned helpers [UID:00016A] and class/file docs already place draw/blit modes in GrafPort.
   - Evidence against: helper depends on Surface callback table and uses Surface paint lifecycle helpers, so the physical source file could still have lived in a render helper source near `Surface.cpp`. This does not outweigh the class-method receiver for canonical owner.
   - Decision: change `CANONICAL_OWNER` and `EMITTER_UIDS` to `00005V`. The generated file remains `auto-generated/NexusTK/render/GrafPort.cpp` through the class/file chain.
2. [UID:0000OC] `Surface.cpp`: rejected as canonical owner, retained as dependency/support context.
   - Evidence for: `dword_69B3E8`, `UpdateSurfaceInfo`, `EndPaint`, DirectDraw/software selection, and the existing Surface page's render-helper bucket.
   - Evidence against: by-structure requires the narrowest true semantic owner; a method with a proven GrafPort receiver should be class-owned. There is no source-proofed `Surface` class. Current `Surface.cpp` is a migration review bucket for callback table, paint lifecycle, and file-local helpers, not a stronger direct owner than the class receiver.
   - Decision: keep `Surface.cpp` as a dependency and support-document cross-reference; do not keep it as direct owner/emitter for this exact method.
3. [UID:0000JR] `GrafPort.cpp` file direct owner: acceptable fallback but weaker than class owner.
   - Evidence for: final generated file and source module are `render/GrafPort.cpp`; sibling [UID:000168] currently uses file owner.
   - Evidence against: by-structure says class methods should use the class UID when supported.
   - Decision: use [UID:00005V] as canonical owner/emitter, not the file UID directly.
4. [UID:0000L3] `MapPane.cpp`: rejected.
   - Evidence for: one important render call at `0x0050978f`; older generated source polluted this helper as `MapPane::DrawSpriteAtPosition`.
   - Evidence against: seven non-MapPane call contexts, current MapPane file docs explicitly exclude `0x004ba250`, and the body has no MapPane fields, packets, resources, or object-list state.
   - Decision: no MapPane owner/emitter.

### Related Render-Helper Grouping

- [UID:000165] `SurfacePaintHelpers` should remain Surface-owned as an aggregate over generic paint lifecycle and callback wrappers, but its notes should say [UID:000167] has been reclassified as a GrafPort method that depends on those helpers.
- [UID:000166] `ForwardToTileFrameBlitHelper` should stay Surface/file-local because it is a free wrapper around `dword_69B3E8` and has no `GrafPort` receiver.
- [UID:000168] and [UID:00016A] remain useful sibling comparisons. [UID:00016A] already uses class owner [UID:00005V]; [UID:000168]'s file-owner route may deserve a later consistency pass, but that is outside this report's direct edit scope.
- [UID:000169] `CompositePixels16` remains a Surface/GrafPort pixel helper under review; it uses GrafPort fields but is less obviously a normal public class method than [UID:000167] because its semantic role is a special pixel effect used by BowGauge/TextEditPane.

### Current Docs Validated Or Superseded

Validated:

- Exact range and padding facts in the target page are correct.
- Eight direct callers in the target page are correct.
- DirectDraw flag paths `16`/`17` are correct; this report refines them to `BltFast` flags `DDBLTFAST_WAIT` and `DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY`.
- Callback paths through `dword_69B3E8` are correct.
- Surface callback table and `client_new_rendering_mode` support docs correctly reject feature-local aliases.
- MapPane support docs correctly reject `0x004ba250` as MapPane-owned.

Superseded:

- Target-page wording that leaves `+0x1c` as a generic callback payload is superseded by the `EPFTileContext` embedding proof.
- Target-page wording that keeps final C++ blank because Surface/GrafPort split is unsettled is superseded for this exact method. The source-file split is still inferential, but the class receiver is strong enough for first-draft C++ under the current gate.
- Current [UID:0000OC] direct owner/emitter is now weaker than [UID:00005V].
- Any stale generated `MapPane::DrawSpriteAtPosition` wording should be retained only as historical/generated-owner pollution, not as a current source candidate.

### Remaining Unresolved Issues And Impact

- Exact original method spelling is not proven. `GrafPort::BlitSurface` is a descriptive high-probability name, not a PDB/source name. This caps completion below final-audit range but does not block C++ entry.
- Full `GrafPortBlitMode` enum remains incomplete beyond `0` and `1`. Higher modes are software/composition modes and likely share values with pane draw modes. This caps confidence below final-audit range but does not block the helper body because the binary forwards higher values unchanged.
- Exact original callback slot name is not proven. `g_pfnBlitSprite` / `g_pfnSurfaceSpriteBlit` is descriptive and should be propagated carefully as a source-quality alias, while support docs can keep historical aliases for searchability.
- Full formal `GrafPort` and `EPFTileContext` declarations are broader support work. The target C++ can refer to documented fields/types, but final project integration still needs shared declarations in the appropriate class/type pages.

## Recommended Metadata And Score Changes

Target [UID:000167]:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion rises from `84` to `87` because the receiver type, key fields, mode `0/1` meanings, DirectDraw `BltFast` path, callback typedef, and MapPane/Surface/GrafPort ownership ranking are now resolved enough for first-draft C++.
- Confidence rises from `88` to `90` because raw PE disassembly independently confirms the target body, rel32 caller set, padding, DirectDraw vtable shape, and callback uses. It should not exceed `90` because original source names and full mode enum names are not recovered.
- `CANONICAL_OWNER` should change from [UID:0000OC] to [UID:00005V]. `EMITTER_UIDS` should also change to [UID:00005V], which surfaces to `auto-generated/NexusTK/render/GrafPort.cpp` through [UID:0000JR].
- `EMITTER_POSITION_OPTIONAL` can remain blank. If the supervisor wants deterministic ordering in `GrafPort.cpp`, use a position after [UID:00022M] `EnableSoftwareBuffer`; no specific position is required for correctness.

Support score recommendations:

- [UID:00005V] `by-class/GrafPort.md`: recommend `85/87 -> 86/88` after incorporating the `BlitSurface` method, `EPFTileContext` embedding, and field table. The class page currently lacks this method and the embedded-context proof.
- [UID:0000JR] `by-file/GrafPort.md`: recommend `88/85 -> 88/86` after adding [UID:000167] as a GrafPort method in `render/GrafPort.cpp`.
- [UID:0000OC] `by-file/Surface.md`: no score change required. Replace direct-ownership wording for [UID:000167] with dependency/cross-reference wording.
- [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`: no score change required. Add the typedef/name refinement for slot 2.
- [UID:0000L3] `by-file/MapPane.md`: no score change required; current exclusion wording is already correct and only needs optional name refresh.

## First-Draft C++ Recommendation

Populate [UID:000167]'s formal `RECONSTRUCTION_CPP CODE` block after rerouting the target to [UID:00005V].

Recommended first-draft C++:

```cpp
enum GrafPortBlitMode {
    kGrafPortBlitCopy = 0,
    kGrafPortBlitSourceColorKey = 1
};

typedef void (__thiscall *SurfaceSpriteBlitProc)(
    GrafPort* destination,
    EPFTileContext* sourceContext,
    const RECT* sourceRect,
    const RECT* destinationRect,
    int mode,
    void* palette,
    int flags);

extern SurfaceSpriteBlitProc g_pfnBlitSprite;

void GrafPort::BlitSurface(GrafPort* source,
                           const RECT* sourceRect,
                           const RECT* destinationRect,
                           int mode)
{
    if (m_usesSoftwareBuffer) {
        source->UpdateSurfaceInfo();
        UpdateSurfaceInfo();

        const float savedAlpha = m_alpha;
        if (source->m_alpha <= 1.0f) {
            m_alpha = source->m_alpha;
        }

        g_pfnBlitSprite(this, &source->m_surfaceContext, sourceRect, destinationRect, mode, 0, 0);

        if (savedAlpha <= 1.0f) {
            m_alpha = savedAlpha;
        }

        if (!m_usesSoftwareBuffer && m_ddSurface != 0) {
            m_ddSurface->Unlock(0);
        }
        m_surfaceContext.pixelData = 0;
        m_surfaceContext.rowStride = 0;

        if (!source->m_usesSoftwareBuffer && source->m_ddSurface != 0) {
            source->m_ddSurface->Unlock(0);
        }
        source->m_surfaceContext.pixelData = 0;
        source->m_surfaceContext.rowStride = 0;
        return;
    }

    RECT ddSourceRect;
    RECT ddDestinationRect;
    SetRect(&ddSourceRect, sourceRect->left, sourceRect->top, sourceRect->right, sourceRect->bottom);
    SetRect(&ddDestinationRect,
            destinationRect->left,
            destinationRect->top,
            destinationRect->right,
            destinationRect->bottom);

    if (mode == kGrafPortBlitSourceColorKey) {
        m_ddSurface->BltFast(ddDestinationRect.left,
                             ddDestinationRect.top,
                             source->m_ddSurface,
                             &ddSourceRect,
                             DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY);
        return;
    }

    if (mode == kGrafPortBlitCopy) {
        m_ddSurface->BltFast(ddDestinationRect.left,
                             ddDestinationRect.top,
                             source->m_ddSurface,
                             &ddSourceRect,
                             DDBLTFAST_WAIT);
        return;
    }

    source->UpdateSurfaceInfo();
    UpdateSurfaceInfo();

    const float savedAlpha = m_alpha;
    if (source->m_alpha <= 1.0f) {
        m_alpha = source->m_alpha;
    }

    g_pfnBlitSprite(this, &source->m_surfaceContext, sourceRect, destinationRect, mode, 0, 0);

    if (savedAlpha <= 1.0f) {
        m_alpha = savedAlpha;
    }

    EndPaint();
    source->EndPaint();
}
```

C++ notes for supervisor:

- If the project declarations do not expose `IDirectDrawSurface::BltFast`, use the local DirectDraw wrapper/interface type already planned for `GrafPort::UpdateRenderRegion`; do not replace the semantic call with raw vtable indexing in final source.
- `m_surfaceContext` is the embedded `EPFTileContext` at `GrafPort + 0x1c`.
- `pixelData` and `rowStride` are the accepted [UID:00004I] field names. If the eventual `EPFTileContext` declaration chooses `rowPitch` / `pitchPixels`, update both places consistently.
- `g_pfnBlitSprite` is a recommended descriptive alias for `dword_69B3E8`. If the supervisor prefers table-member naming, use `g_surfaceRenderCallbacks.blitSprite` and update [UID:0000TN] in the same pass.
- The explicit cleanup in the first software-buffer branch mirrors the binary. It is intentionally not replaced by `EndPaint()` because the original code does not call `0x004b98c0` in that branch.

## Exact Supervisor Changes Required

### Target Page Metadata

In `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`, replace the metadata header values with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005V | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Populate the formal C++ block with the code in `## First-Draft C++ Recommendation`.

### Target Page Status Replacement

In the target page `## Status`, replace the current owner/C++ bullets with:

```markdown
- Current generated owner history: older generated output emitted this as `MapPane::DrawSpriteAtPosition`, but current source-quality evidence rejects MapPane ownership.
- Preferred reconstruction owner: [UID:00005V][GrafPort](by-class/GrafPort.md), emitted through [UID:0000JR][GrafPort](by-file/GrafPort.md) in `NexusTK/render/GrafPort.cpp`.
- Source-facing name direction: `GrafPort::BlitSurface(GrafPort *source, const RECT *sourceRect, const RECT *destinationRect, int mode)`.
- IDA function: `sub_4BA250`, size `0x1f4`.
- Address range: `0x004ba250-0x004ba444`, end-exclusive.
- Entity kind: source-authored GrafPort surface blit/composition method.
- Rebuild handling: `source-authored`.
- C++ status: populate first-draft C++ after this B003 pass; the old blank-C++ blocker was stale because the receiver, key fields, DirectDraw fast-blit flags, callback typedef direction, and owner route are now resolved enough for the active combined-score/emitter gate.
```

### Target Page Field Table Replacement

In the target page `## Touched State And Dependencies`, replace the table with:

```markdown
| State or dependency | Evidence | Interpretation |
| --- | --- | --- |
| `this + 0x18`, `source + 0x18` | DirectDraw branch calls the vtable slot at `+0x1c` on `this+0x18` and passes `source+0x18` as the source surface; `GrafPort::UpdateRenderRegion` writes the created DirectDraw surface here. | `LPDIRECTDRAWSURFACE m_ddSurface`. |
| `this + 0x1c`, `source + 0x1c` | `GrafPort::GrafPort` initializes `this+0x1c` through [UID:00004I] `EPFTileContext::InitTileContext`; the software callback receives `source+0x1c`. | Embedded `EPFTileContext m_surfaceContext` / paint-source context. |
| `this + 0x20`, `source + 0x20` | `UpdateSurfaceInfo` writes the locked/software pixel pointer here and this helper clears it after callback paths. | `m_surfaceContext.pixelData`, not a separate top-level field. |
| `this + 0x28`, `source + 0x28` | `UpdateSurfaceInfo` writes the pitch/row stride in pixels here and this helper clears it after callback paths. | `m_surfaceContext.rowStride` / pitch in pixels. |
| `this + 0x90`, `source + 0x90` | Helper temporarily borrows source alpha when source alpha is `<= 1.0f`, then restores the saved destination alpha when saved alpha is `<= 1.0f`; WaterFilterEffecter docs already tie this field to alpha/opacity. | `float m_alpha` / `m_currentAlpha`. |
| `this + 0x94`, `source + 0x94` | Branches select software-buffer cleanup versus DirectDraw lock/unlock; [UID:00022M] writes this byte as `GrafPort::EnableSoftwareBuffer`. | `bool m_usesSoftwareBuffer`. |
| `dword_69B3E8` | Calls at `0x004ba2ca` and `0x004ba403`; callback targets `0x004bc090` and `0x004c0f80` save `ecx` as destination GrafPort. | `SurfaceSpriteBlitProc g_pfnBlitSprite` / primary sprite-tile blit callback slot. |
| `mode == 0` | DirectDraw-backed destination calls `BltFast` with flag `0x10`. | `kGrafPortBlitCopy`, `DDBLTFAST_WAIT`. |
| `mode == 1` | DirectDraw-backed destination calls `BltFast` with flag `0x11`. | `kGrafPortBlitSourceColorKey`, `DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY`. |
| `mode >= 2` or other nonzero/nonone values | DirectDraw-backed destination falls back to software callback; Layer/effect callers pass pane draw-mode bytes such as `+0xb5`. | Higher software/composition modes; exact enum names remain broader GrafPort/Pane render-mode work. |
```

### Target Page Ownership Notes Replacement

Replace `## Ownership Notes` with:

```markdown
## Ownership Notes

Treat the old `MapPane::DrawSpriteAtPosition` label as callsite-biased generated output. The direct caller set spans Layer render traversal, MapPane render, PhotoPane paint, and ScreenEffecter runtime effects, and the body has no MapPane fields or packet/resource state.

The best direct owner is [UID:00005V][GrafPort](by-class/GrafPort.md). The helper is a `__thiscall` method whose receiver is the destination GrafPort; the first argument is a source GrafPort. It uses the accepted GrafPort DirectDraw surface field at `+0x18`, embedded [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) at `+0x1c`, alpha at `+0x90`, and software-buffer selector at `+0x94`.

[UID:0000OC][Surface](by-file/Surface.md) remains an important dependency and callback-table source route for `dword_69B3E8`, `UpdateSurfaceInfo`, and `EndPaint`, but it should no longer be the canonical owner/emitter for this exact method. The source implementation should emit through `GrafPort.cpp` as `GrafPort::BlitSurface`.
```

### Target Page Changes Entry

Append to `## Changes`:

```markdown
- 2026-06-18 B003 source-quality reanalysis:
  - Before: `84/88`, owner/emitter [UID:0000OC][Surface](by-file/Surface.md), blank formal C++, and unresolved Surface/GrafPort/source-name field blockers.
  - After recommendation: `87/90`, owner/emitter [UID:00005V][GrafPort](by-class/GrafPort.md), formal first-draft `GrafPort::BlitSurface` C++ populated.
  - Evidence: local PE/Capstone recheck confirmed six leading and twelve trailing `0xcc` padding bytes, eight direct rel32 callers, no absolute pointer ownership route, `dword_69B3E8` calls at `0x004ba2ca`/`0x004ba403`, DirectDraw `BltFast` flag paths `0x10`/`0x11`, software callback fallback for other modes, `GrafPort` constructor proof that `+0x1c` is an embedded `EPFTileContext`, accepted `+0x94` software-buffer flag, `+0x90` alpha, and MapPane owner rejection.
```

### GrafPort Class Support Insert

In `by-class/GrafPort.md`, under `## Observed State` after the paragraph about [UID:00022M], insert:

```markdown
[UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) should be treated as `GrafPort::BlitSurface`, not a MapPane method and not a file-local Surface helper. The destination receiver is the GrafPort in `ecx`, and the first argument is the source GrafPort. B003's 2026-06-18 source-quality pass confirms the method reads `m_ddSurface` at `+0x18`, passes the embedded `EPFTileContext` at `+0x1c` to `dword_69B3E8`, clears `m_surfaceContext.pixelData` at `+0x20` and `m_surfaceContext.rowStride` at `+0x28` after paint/callback paths, borrows/restores `m_alpha` at `+0x90`, and branches on `m_usesSoftwareBuffer` at `+0x94`. On DirectDraw-backed destinations, mode `0` maps to `BltFast(..., DDBLTFAST_WAIT)` and mode `1` maps to `BltFast(..., DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY)`; other mode values route through the software sprite callback.
```

Also add this method row under `## Method Notes`:

```markdown
| `BlitSurface` | `0x004ba250-0x004ba444` | Blits from a source GrafPort to this GrafPort, using DirectDraw `BltFast` for modes `0`/`1` when the destination is DirectDraw-backed and using the `dword_69B3E8` software sprite callback otherwise. |
```

### GrafPort File Support Insert

In `by-file/GrafPort.md`, add this row to `## Proposed Contents` after [UID:0003XC] or near the other draw/blit helpers:

```markdown
| [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) | `0x004ba250-0x004ba444` | `GrafPort::BlitSurface`, a source-authored destination-GrafPort method that chooses DirectDraw `BltFast` for copy/source-color-key modes or the `dword_69B3E8` software sprite callback for software/composition modes. |
```

Append to `## Ownership Decision`:

```markdown
[UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) should route through `GrafPort` rather than the provisional Surface bucket. The decisive evidence is the `__thiscall` receiver and the concrete GrafPort field model: `+0x18` DirectDraw surface, embedded `EPFTileContext` at `+0x1c`, `+0x20/+0x28` context pixel/stride fields, `+0x90` alpha, and `+0x94` software-buffer flag. Surface remains the callback-table and lifecycle dependency, not the direct semantic owner for this exact method.
```

### Surface File Support Replacement

In `by-file/Surface.md`, replace the [UID:000167] row in `## Proposed Contents` with:

```markdown
| [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) | `0x004ba250-0x004ba444` | dependency / former Surface bucket item | B003 2026-06-18 reanalysis reroutes this exact function to [UID:00005V][GrafPort](by-class/GrafPort.md) as `GrafPort::BlitSurface`; Surface remains the owner of callback-table context and paint lifecycle dependencies (`dword_69B3E8`, `UpdateSurfaceInfo`, `EndPaint`). |
```

Append to the Surface evidence/change area:

```markdown
- 2026-06-18 B003 source-quality reanalysis reroutes [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) from the provisional Surface bucket to [UID:00005V][GrafPort](by-class/GrafPort.md). Surface remains the dependency owner for `dword_69B3E8` and paint lifecycle helpers, but the target itself is a `__thiscall` destination-GrafPort method with receiver fields `+0x18/+0x1c/+0x20/+0x28/+0x90/+0x94` matching the accepted GrafPort/EPFTileContext layout.
```

### SurfaceRenderCallbackTable Support Insert

In `by-global/SurfaceRenderCallbackTable.md`, under the slot-2 row or evidence list, insert:

```markdown
- B003 2026-06-18 reanalysis of [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) supports naming slot 2 descriptively as `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`. The caller sets `ecx` to the destination GrafPort and passes `EPFTileContext *sourceContext`, `sourceRect`, `destinationRect`, `mode`, `paletteOrNull`, and `flags`. The installed callback targets `0x004bc090` and `0x004c0f80` both preserve `ecx` as the destination and consume the same first stack arguments, so callsite-specific aliases such as `g_uiTileRenderer` remain rejected.
```

### MapPane Support Optional No-Score Update

`by-file/MapPane.md` already excludes `0x004ba250`. Optional replacement for the existing exclusion sentence:

```markdown
Current generated output and older simroot data also emitted shared UI/render helpers at `0x004ba250`, `0x005446e0-0x00544b7d`, and root screen layer-list helpers at `0x00556ce0-0x00556d41`. Do not migrate those into `map/MapPane.cpp`: `0x004ba250` is now best documented as [UID:000167][GrafPort::BlitSurface](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md), `0x005446e0` belongs with [UID:0000MC][Pane](by-file/Pane.md) dirty/motion infrastructure, and `0x00556ce0` belongs with [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer management.
```

## Coverage Report Replacement Text

In `by-memory/-coverage-report.md`, replace the current [UID:000167] row near the `0x004b9820-0x004ba81d` Surface/GrafPort helper neighborhood with:

```markdown
    - [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) 0x004ba250-0x004ba444 | method | GrafPortBlitSurface : reconstructable : 87% : strong : B003 2026-06-18 source-quality pass reroutes this from the provisional Surface bucket to [UID:00005V][GrafPort](by-class/GrafPort.md) as `GrafPort::BlitSurface`; local PE/Capstone recheck confirms six leading and twelve trailing `0xcc` padding bytes, eight direct rel32 callers across Layer/MapPane/PhotoPane/ScreenEffecter paths, no MapPane-specific state, DirectDraw `BltFast` paths with flags `0x10` (`DDBLTFAST_WAIT`) and `0x11` (`DDBLTFAST_WAIT | DDBLTFAST_SRCCOLORKEY`) for modes `0`/`1`, software callback paths through `dword_69B3E8` for software-buffer or higher composition modes, receiver/source fields matching GrafPort layout (`+0x18` DirectDraw surface, `+0x1c` embedded `EPFTileContext`, `+0x20/+0x28` context pixel/stride fields, `+0x90` alpha, `+0x94` software-buffer flag), and first-draft C++ should be populated through `auto-generated/NexusTK/render/GrafPort.cpp`.
```

If the supervisor keeps the row under the Surface helper section for address order, the row text should still state the new [UID:00005V] owner/emitter. No address-order movement is required because `by-memory/-coverage-report.md` is address ordered, not owner grouped.

## Validation / State Checks Run

Commands run in this session:

> Executable block R001 was removed from this report and preserved verbatim in [000167-SurfaceSpriteBlitHelper-source-quality-removed.md](000167-SurfaceSpriteBlitHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Local PE/Capstone scripts checked:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
0x004ba24a-0x004ba250 padding
0x004ba250-0x004ba444 target disassembly
0x004ba444-0x004ba450 padding
rel32 callers to 0x004ba250
absolute refs to 0x0069b3e8
support helper disassembly for 0x004b9820, 0x004b98c0, 0x004b8bf0, 0x004bc090, 0x004c0f80
caller windows around all eight call sites
```

Supervisor validation commands after applying recommended docs:

> Executable block R002 was removed from this report and preserved verbatim in [000167-SurfaceSpriteBlitHelper-source-quality-removed.md](000167-SurfaceSpriteBlitHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated output after supervisor application:

- `auto-generated/NexusTK/render/GrafPort.cpp` should contain existing [UID:00022M] `GrafPort::EnableSoftwareBuffer()` plus new [UID:000167] `GrafPort::BlitSurface(...)`.
- `auto-generated/NexusTK/render/Surface.cpp` may remain empty unless other Surface-owned targets receive formal C++; [UID:000167] should no longer be the reason Surface.cpp exists.
- [UID:000167] should no longer appear in low-score 84/88 stats; it should appear as `87/90`.

## Remaining Blockers

- No blocker remains for first-draft formal C++ entry after the owner/emitter reroute.
- Original public method name remains inferred/descriptive. This caps completion/confidence below final audit but does not block source emission.
- Higher `mode` values beyond `0` and `1` remain broader GrafPort/Pane render-mode work. The target can still emit because it forwards those values unchanged exactly as the binary does.
- Full shared declarations for `GrafPort`, `EPFTileContext`, and `SurfaceSpriteBlitProc` need normal support-page integration. This is a project integration dependency, not a target no-code proof.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/000167-SurfaceSpriteBlitHelper-source-quality.md`
- Modified: none outside Agent-B003 research.
- No by-* docs, generated reports/source, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000167-SurfaceSpriteBlitHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000167"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000167-SurfaceSpriteBlitHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000167-SurfaceSpriteBlitHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000167"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
