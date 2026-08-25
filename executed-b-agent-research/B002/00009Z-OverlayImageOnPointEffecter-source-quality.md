** TARGET-REPORT-UID:00009Z **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Source-Quality Report: [UID:00009Z] OverlayImageOnPointEffecter

Assignment id: `B002-goal2-overlay-image-on-point-effecter-source-quality-00009Z-20260619`

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\OverlayImageOnPointEffecter.md`

Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00009Z-OverlayImageOnPointEffecter-source-quality.md`

Report-only status: no by-* documentation files, generated files, or coverage reports were edited. `by-memory/-coverage-report.md` was not edited.

## Final Recommendation

Raise [UID:00009Z] from `84/90` to `88/91`, keep it reconstructable, and keep the owner/emitter route through [UID:0000IZ][Effects](../../../../../by-file/Effects.md) / `NexusTK/render/Effects.cpp`.

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000IZ
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IZ
```

The current no-C++ rationale is stale. This target clears the active first-draft gate: it is reconstructable, its emitter route is already [UID:0000IZ] `Effects`, and the combined score should be above `85`. Populate first-draft C++ for the source-authored constructor, ordinary destructor, and render/paint method. Do not emit handwritten source for the scalar deleting destructor, adjusted destructor thunks, vtable stores, SEH handlers, or security-cookie scaffolding.

Best source-facing method inventory:

| Range | Source-facing role | Recommendation |
| --- | --- | --- |
| `0x0055a7a0-0x0055a7c6` | Pane/GrafPort paint-slot renderer | Keep `RenderOverlayImageAtPoint()` as the behavior name already used by local generated metadata; note that this is the `+0x04` adjusted-view paint slot and may become `OnPaint()` if the effecter family standardizes paint-slot names. |
| `0x0055a7d0-0x0055a8da` | Complete-object constructor | Emit first-draft constructor C++ under `OverlayImageOnPointEffecter`. |
| `0x0055a8e0-0x0055a987` | Ordinary destructor | Emit source-style destructor that releases the owned frame/image block. Treat base/pane vtable resets and teardown as compiler/base destructor mechanics. |
| `0x0055be10-0x0055bee3` | Scalar deleting destructor | Compiler-generated wrapper; document flags and object size, but no formal handwritten C++. |

The central source-quality correction is adjusted-this normalization. The renderer is installed in the embedded `+0x04` Pane/GrafPort vtable view at slot `0x00623854 -> 0x0055a7a0`; therefore its `ecx` is `complete this + 4`. Renderer offsets such as `this+0x11c`, `this+0x140`, and `this+0x150` normalize to complete-object `+0x120`, `+0x144`, and `+0x154`. This resolves the old palette/name and frame-handle confusion.

## Evidence Checked

Instruction and workflow docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`

Primary and support documentation:

- Target [UID:00009Z][OverlayImageOnPointEffecter](../../../../../by-class/OverlayImageOnPointEffecter.md)
- Base/sibling pages: [UID:00009W][OverlayEffecter](../../../../../by-class/OverlayEffecter.md), [UID:00009X][OverlayFrameImageEffecter](../../../../../by-class/OverlayFrameImageEffecter.md), [UID:00009Y][OverlayImageEffecter](../../../../../by-class/OverlayImageEffecter.md), [UID:0000A0][OverlayMovingImageEffecter](../../../../../by-class/OverlayMovingImageEffecter.md), [UID:0000FZ][WaterFilterEffecter](../../../../../by-class/WaterFilterEffecter.md), [UID:0000C9][ScreenEffecter](../../../../../by-class/ScreenEffecter.md)
- Owner/runtime/vtable docs: [UID:0000IZ][Effects](../../../../../by-file/Effects.md), [UID:0001GE][ScreenEffecterRuntimeCluster](../../../../../by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), [UID:0001YO][ScreenEffecterVtableFamily](../../../../../by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][ScreenEffecterVtableData](../../../../../by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- Resource/render helpers: [UID:000165][SurfacePaintHelpers](../../../../../by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md), [UID:00016A][GrafPortDrawTiledBackground](../../../../../by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md), [UID:0002P4][LoadImageFrameTable](../../../../../by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md), [UID:0002P5][DestroyOwnedImageBlock](../../../../../by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), [UID:0002KP][ResourceLayoutTableLookupLayoutEntry](../../../../../by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md), [UID:00004I][EPFTileContext](../../../../../by-class/EPFTileContext.md), [UID:0000QU][g_pEPFLib](../../../../../by-global/g_pEPFLib.md), [UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md)
- Coverage/generated state: `by-class/-coverage-report.md`, `by-memory/-coverage-report.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/NexusTK/render/Effects.cpp`
- Sibling B reports checked for consistency: B004 `00009Y-OverlayImageEffecter-source-quality.md`, B015 `00009X-OverlayFrameImageEffecter-source-quality.md`, B001 `0000A0-OverlayMovingImageEffecter-source-quality.md`
- Generated/source leads: `source-3/simroot_v2/class_OverlayImageOnPointEffecter.cpp` and `.meta_wave3`

Local binary evidence:

- Parsed local PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- File size `2679296`
- MD5 `4247e04e20b65d6414c7238aa8ff5515`
- Image base `0x00400000`
- Relevant sections:
  - `.text 0x00401000-0x0060c600`, raw `0x400-0x20ba00`
  - `.rdata 0x0060d000-0x0066c200`, raw `0x20ba00-0x26ac00`
  - `.data 0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`
- Local PE scan verified exact method sizes, padding, vtable pointer hits, direct rel32 branches/calls, and helper caller counts.
- Current IDA MCP endpoint check at `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`, so this report does not claim new live IDA state beyond existing docs. Local PE evidence and previously recorded IDA evidence were used instead.
- `int_convert.py` verified the constants used in this report: `0x26` / 38, `0x10a` / 266, `0xa7` / 167, `0xd3` / 211, `0x18` / 24, `0x170` / 368, `0x12c` / 300, `0x100` / 256, `0x120` / 288, `0x140` / 320, `0x144` / 324, `0x150` / 336, `0x16c` / 364, `0x16e` / 366, `0xb0` / 176, `0xb4` / 180, `0xf9` / 249, `0xa4` / 164, `0xa8` / 168, and `0x31` / 49.

## Exact Range And Boundary Findings

The four target ranges are correct half-open ranges:

| Range | Size | Role | Boundary notes |
| --- | ---: | --- | --- |
| `0x0055a7a0-0x0055a7c6` | `0x26` / 38 bytes | Render/paint-slot body | Ends at `ret`; `0x0055a7c6-0x0055a7d0` is ten `0xcc` bytes before the constructor. |
| `0x0055a7d0-0x0055a8da` | `0x10a` / 266 bytes | Complete-object constructor | Ends with `ret 0x18`, proving six explicit stack arguments; `0x0055a8da-0x0055a8e0` is six `0xcc` bytes. |
| `0x0055a8e0-0x0055a987` | `0xa7` / 167 bytes | Ordinary destructor | Ends at `ret`; `0x0055a987-0x0055a990` is nine `0xcc` bytes before the moving-effecter render body. |
| `0x0055be10-0x0055bee3` | `0xd3` / 211 bytes | Scalar deleting destructor | Ends with `ret 4`; `0x0055bee3-0x0055bef0` is thirteen `0xcc` bytes before `OverlayMovingImageEffecter` scalar destructor. |

No merge is justified. The padding is clean, the class-specific vtable slots point to the renderer and scalar wrapper, and the constructor/destructor have independent modeled bodies.

## Vtable And Reachability Findings

Four-view vtable identity:

| View | Address | Evidence |
| --- | --- | --- |
| Primary complete-object view | `0x006237ec` | Constructor writes immediate at `0x0055a817`; destructor at `0x0055a90c`; scalar wrapper at `0x0055be3c`. |
| Embedded `+0x04` Pane/GrafPort view | `0x00623810` | Constructor writes at `0x0055a81d`; destructor at `0x0055a912`; scalar wrapper at `0x0055be43`. Renderer slot is `0x00623854 -> 0x0055a7a0`. |
| `+0xa4` adjusted view | `0x0062385c` | Constructor writes at `0x0055a824`; destructor at `0x0055a919`; scalar wrapper at `0x0055be4d`. |
| `+0xa8` adjusted view | `0x0062388c` | Constructor writes at `0x0055a82e`; destructor at `0x0055a923`; scalar wrapper at `0x0055be57`. |

Local pointer/ref scan:

- `0x0055a7a0` has one VA pointer hit: `0x00623854`, the `+0x04` view render slot.
- `0x0055be10` has one VA pointer hit: `0x00623804`, the primary scalar deleting destructor slot.
- `0x0055a7d0` constructor has zero VA/RVA/raw-offset pointer hits and no direct `.text` rel32 branch/call hits.
- `0x0055a8e0` ordinary destructor has zero VA/RVA/raw-offset pointer hits and no direct `.text` rel32 branch/call hits.
- Direct rel32 branches to `0x0055be10` occur at `0x0055ba9d`, `0x0055baa8`, and `0x0055bab3`, the destructor-adjustor jump strip.
- Direct rel32 calls to shared helpers match the documented consumer set:
  - `0x004b9980` / `RenderTileFrame`: 311 direct rel32 calls, including this renderer.
  - `0x004d0f50` / `LoadImageFrameTable`: 25 calls, with target constructor call at `0x0055a849`.
  - `0x004d15d0` / `DestroyOwnedImageBlock`: 8 calls, with target destructor call at `0x0055a933` and scalar wrapper call at `0x0055be6a`.
  - `0x004d02f0` / `ResourceLayoutTable::LookupLayoutEntry`: 440 calls, with target constructor call at `0x0055a884`.
  - `0x00457a60` / `InitTileContext`: 337 calls, with target constructor call at `0x0055a838`.
  - `0x0055a2e0` / `OverlayEffecter` constructor: exactly four overlay-subclass constructor calls, at `0x0055a4d3`, `0x0055a651`, `0x0055a803`, and `0x0055ab32`.

Reachability conclusion: the renderer and scalar wrapper are vtable-owned, while the constructor and ordinary destructor lack direct static callers in the local PE scan. That is a confidence limiter but not a no-code proof. The constructor body is source-authored, installs this class's vtables, initializes source fields, and follows the sibling overlay-effecter constructor pattern. The ordinary destructor is the expected source destructor body that releases the owned frame/image block before base teardown.

## Renderer / Adjusted Receiver

Raw renderer body:

```asm
0055a7a0 push 0
0055a7a2 lea eax, [ecx+0x11c]
0055a7a8 push eax
0055a7a9 movzx eax, byte ptr [ecx+0x70]
0055a7ad push eax
0055a7ae lea eax, [ecx+0x44]
0055a7b1 push eax
0055a7b2 lea eax, [ecx+0x150]
0055a7b8 push eax
0055a7b9 lea eax, [ecx+0x140]
0055a7bf push eax
0055a7c0 call 0x004b9980
0055a7c5 ret
```

Because the slot is in the embedded `+0x04` view, normalize the renderer offsets by adding four to get complete-object offsets:

| Renderer offset | Complete offset | Best source role |
| --- | --- | --- |
| adjusted `+0x11c` | complete `+0x120` | second copied name, best source name `m_paletteName` / `m_overlayName`; passed to `RenderTileFrame` and then to `g_pPaletteLib->GetPaletteByName`. |
| adjusted `+0x140` | complete `+0x144` | embedded `EPFTileContext` / frame draw record after the owned block pointer. |
| adjusted `+0x150` | complete `+0x154` | source bounds/record field inside the tile context / frame draw record. |
| adjusted `+0x44` | complete `+0x48` | inherited Pane/GrafPort draw/destination bounds. |
| adjusted `+0x70` | complete `+0x74` | inherited draw/blit mode byte. |

This makes the renderer consistent with `OverlayImageEffecter`, `OverlayFrameImageEffecter`, and `OverlayMovingImageEffecter` after their adjusted-view corrections. The old complete-object reading of renderer `this+0x11c` should not be carried forward as a standalone field name.

The shared helper at `0x004b9980` is the Surface/GrafPort `RenderTileFrame` wrapper from [UID:000165]. Local disassembly and helper docs show it resolves the fifth argument through `g_pPaletteLib->GetPaletteByName`, then dispatches through callback slot `dword_69B3E8`. Current fitting-room/download helper provenance is caller-biased and should not affect this class's owner or method names.

## Constructor Findings

`0x0055a7d0` takes six explicit arguments and returns with `ret 0x18` (`0x18` / 24 bytes, Verified with `int_convert.py`):

```cpp
OverlayImageOnPointEffecter::OverlayImageOnPointEffecter(
    const wchar_t *imageName,
    const wchar_t *paletteName,
    short overlayX,
    short overlayY,
    short pointX,
    short pointY);
```

Argument names are source-quality descriptive names, not symbol-proven final names. `overlayX`/`overlayY` are the two words forwarded to `OverlayEffecter(1, overlayX, overlayY)`. If the broader Effects family standardizes these as `paneWidth`/`paneHeight`, only the parameter spelling should change. `pointX`/`pointY` is supported by generated source naming and the point-overlay role, but the inherited mirror fields at complete `+0xb4/+0xb0` should remain explicitly documented until the `OverlayEffecter` layout is fully named.

Constructor behavior:

- Calls `OverlayEffecter` constructor at `0x0055a2e0` with fixed first argument `1` and the two base placement arguments.
- Installs the four `OverlayImageOnPointEffecter` vtable views: `0x006237ec`, `0x00623810`, `0x0062385c`, and `0x0062388c`.
- Calls `InitTileContext` (`0x00457a60`) on complete `this+0x144`.
- Calls `LoadImageFrameTable(g_pEPFLib, imageName, 0)` at `0x004d0f50` and stores the owned block at complete `this+0x140`.
- Copies two bounded wide strings through `0x005cd657` with size argument `0x10`:
  - first name to complete `this+0x100`;
  - second name to complete `this+0x120`.
- Calls `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, this+0x100, 0, this+0x144)` at `0x004d02f0`.
- Stores point coordinates:
  - first point argument to trailing word complete `+0x16c` and sign-extended mirror complete `+0xb4`;
  - second point argument to trailing word complete `+0x16e` and sign-extended mirror complete `+0xb0`.
- Writes active/visible byte complete `+0xf9 = 1`.
- Writes `0x12c` / 300 to complete `+0x50` and `+0x54`. Best current source-facing interpretation is fixed draw/bounds extents for the point overlay's Pane/GrafPort state, not a proven lifetime timer. The current target's "300-tick/state" wording should be softened or replaced with "fixed 300-pixel draw/bounds extents or inherited point-overlay extents" unless an inherited field audit proves timer names.
- Uses SEH handler `0x0060761d`, security cookie load `[0x00672f24]`, and `[ebp-4]` unwind-state writes. These are compiler constructor-unwind scaffolding, not handwritten source C++.

Recommended field model after complete-object normalization:

| Complete offset | Best name / role | Confidence |
| --- | --- | --- |
| `+0x100` | `wchar_t m_imageName[16]` / primary frame resource name | High for role and size; final spelling open. |
| `+0x120` | `wchar_t m_paletteName[16]` / secondary overlay name | High for renderer consumption after adjusted mapping. |
| `+0x140` | `m_frameRecord.imageBlock` / owned block returned by `LoadImageFrameTable` | High; destructor frees this exact field. |
| `+0x144` | `m_frameRecord.tileContext` / `EPFTileContext` | High; initialized by `InitTileContext` and filled by lookup. |
| `+0x154` | `m_frameRecord.sourceRect` / bounds inside tile context | Medium-high; passed to `RenderTileFrame`. |
| `+0x16c` | `short m_pointX` | Medium-high; first point argument and generated source agree on X, but inherited mirror-field axis names remain provisional. |
| `+0x16e` | `short m_pointY` | Medium-high; second point argument and generated source agree on Y, with same caveat. |
| `+0xb4` | inherited point/draw X mirror | Medium; sign-extended first point argument. |
| `+0xb0` | inherited point/draw Y mirror | Medium; sign-extended second point argument. |
| `+0xf9` | active/visible byte | High for boolean role, final base-field name open. |
| `+0x50/+0x54` | fixed draw/bounds extents set to 300 | Medium; old lifetime wording is not strongly supported by the paint/bounds context. |

## Destructor And Scalar Wrapper

Ordinary destructor `0x0055a8e0-0x0055a987`:

- Reinstalls the four most-derived vtable views during the derived destructor phase.
- Loads complete `this+0x140` and calls `DestroyOwnedImageBlock` at `0x004d15d0`.
- Reinstalls the four `OverlayEffecter` base views: `0x006235e8`, `0x0062360c`, `0x00623658`, and `0x00623688`.
- Calls inherited Pane cleanup/destructor helpers `0x00544ce0` and `0x00544580` on complete `this+0x04`.
- Resets primary base view to `ScreenEffecter` vtable `0x006235a4`.
- Uses SEH handler `0x00607638` and security-cookie scaffolding; do not emit those as source.

Source-facing body should be the ordinary destructor releasing the owned frame/image block. The base and embedded Pane teardown should be left to normal C++ destructor chaining in first-draft source.

Scalar deleting destructor `0x0055be10-0x0055bee3`:

- Repeats the release/base-teardown sequence because MSVC emitted a deleting-destructor wrapper body.
- Checks deletion flags:
  - `(flags & 1) == 0`: no storage delete.
  - `(flags & 1) != 0 && (flags & 4) == 0`: calls MemoryMan/operator-delete wrapper `0x004f4ac0`.
  - `(flags & 4) != 0`: calls guard/sized-delete helper `0x0041b6a0(this, 0x170)`.
- Confirms complete object size `0x170` / 368 bytes (Verified with `int_convert.py`).
- Uses SEH handler `0x005fce80`.

This wrapper is compiler-generated. It should remain in the method inventory, vtable docs, and IDA naming recommendations, but not in the formal source C++ block.

Adjusted scalar destructor thunks:

- `0x0055ba9a`: secondary `+0x04` view adjustor, subtracts `4`, jumps to `0x0055be10`; direct branch target in scan at `0x0055ba9d`.
- `0x0055baa2`: secondary `+0xa4` view adjustor, subtracts `0xa4`, jumps to `0x0055be10`; direct branch target at `0x0055baa8`.
- `0x0055baad`: secondary `+0xa8` view adjustor, subtracts `0xa8`, jumps to `0x0055be10`; direct branch target at `0x0055bab3`.

## Helper And Raw Name Resolution

Use these source-facing names/roles instead of leaving raw labels:

| Address / raw label | Recommended name / role | Evidence |
| --- | --- | --- |
| `0x004b9980` / `sub_4B9980` | `RenderTileFrame` shared Surface/GrafPort render wrapper | [UID:000165] documents `0x004b9980-0x004b99b1`, 311 callers, palette lookup via `g_pPaletteLib`, and callback slot `dword_69B3E8`; current recovered feature owner labels are caller-biased. |
| `0x004d0f50` / `sub_4D0F50` | `LoadImageFrameTable` | Existing ImageFrameTable helper doc; target constructor stores result at complete `+0x140`. |
| `0x004d15d0` / `sub_4D15D0` | `DestroyOwnedImageBlock` | Existing helper doc explicitly lists `OverlayImageOnPointEffecter` constructor/destructor pair and frees complete `+0x140`. |
| `0x004d02f0` / `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | Existing central EPF/EPD layout lookup doc; target constructor call writes complete `+0x144`. |
| `0x00457a60` / `sub_457A60` | `InitTileContext` / `EPFTileContext::Init` | EPFTileContext docs define the 0x28-byte layout and initializer. |
| `0x005cd657` | bounded wide-string copy / likely secure wide copy helper | Local/sibling evidence supports `wcscpy_s(dest, 0x10, source)` source style; exact CRT import name is not symbol-proven. |
| `0x004f4ac0` | MemoryMan-backed `operator delete` wrapper | Used only by scalar deleting destructor storage-delete path; source C++ should not call it directly. |
| `0x0041b6a0` | guarded sized/vector-delete path helper | Only `(flags & 4)` deleting-destructor path; compiler glue. |
| `0x00544ce0` / `0x00544580` | inherited Pane cleanup / ordinary Pane teardown | Base destructor mechanics, not effecter-specific source calls. |

Reject these alternatives:

- Do not leave `sub_55A7A0`, `sub_55A7D0`, `sub_55A8E0`, or `sub_55BE10` as passive blockers. The class/method roles are strong enough to name.
- Do not route `0x004b9980` through `FittingRoomDownloadControlPane`; that is recovered-owner pollution contradicted by Surface/GrafPort helper docs and 311-call breadth.
- Do not route the class itself through `Surface`, `GrafPort`, `ImageFrameTable`, or `ResourceLayoutTable`; those are dependencies/consumers, not the runtime effecter owner.
- Do not interpret the lack of direct constructor refs as dead compiler glue. The body is source-shaped and consistent with every pane-backed overlay subclass constructor; the missing call route only caps confidence below final audit.

## Owner / Source Placement Ranking

1. [UID:0000IZ] `Effects` / `NexusTK/render/Effects.cpp` remains the best owner and emitter. It already owns the ScreenEffecter runtime family and the sibling overlay effecters.
2. `OverlayEffecter` is the direct semantic base and should be referenced for inherited Pane/GrafPort state, base constructor arguments, and destructor chain. It is not the canonical source owner for this subclass.
3. [UID:0001GE] `ScreenEffecterRuntimeCluster`, [UID:0001YO] `ScreenEffecterVtableFamily`, and [UID:0002OR] `ScreenEffecterVtableData` are support/aggregate docs. They should carry exact evidence and adjusted-offset notes, not replace the class/file emitter route.
4. `Surface`/`GrafPort` own render helpers and callback-table plumbing, not the effecter class.
5. `ImageFrameTable` / `ResourceLayoutTable` own the loader/destroy/lookup helpers, not the class.
6. No-owner/non-emitting is rejected: this is a source-authored class with class vtables, constructor/destructor bodies, and an Effects emitter route.
7. A future `render/effects/OverlayEffecters.cpp` or exact by-memory child split is possible, but current docs support `Effects.cpp` and do not justify a standalone `OverlayImageOnPointEffecter.cpp` split.

## First-Draft C++ Recommendation

Populate the target `RECONSTRUCTION_CPP` block after supervisor acceptance with source-style code for constructor, destructor, and renderer. The exact field names below are first-draft descriptive names; prose in the target should retain the offset table and uncertainty notes.

```cpp
OverlayImageOnPointEffecter::OverlayImageOnPointEffecter(const wchar_t *imageName,
                                                         const wchar_t *paletteName,
                                                         short overlayX,
                                                         short overlayY,
                                                         short pointX,
                                                         short pointY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    InitTileContext(&m_frameRecord.tileContext);
    m_frameRecord.imageBlock = LoadImageFrameTable(g_pEPFLib, imageName, 0);

    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_paletteName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_frameRecord.tileContext);

    m_pointX = pointX;
    m_pointY = pointY;
    m_drawPointX = pointX;
    m_drawPointY = pointY;

    m_active = true;
    m_drawBounds.right = 300;
    m_drawBounds.bottom = 300;
}

OverlayImageOnPointEffecter::~OverlayImageOnPointEffecter()
{
    DestroyOwnedImageBlock(g_pEPFLib, m_frameRecord.imageBlock);
}

void OverlayImageOnPointEffecter::RenderOverlayImageAtPoint()
{
    RenderTileFrame(&m_frameRecord.tileContext,
                    &m_frameRecord.tileContext.bounds,
                    &m_drawBounds,
                    m_drawMode,
                    m_paletteName,
                    0);
}
```

Implementation notes:

- If support docs standardize `RenderOverlayImageAtPoint` as `OnPaint()`, use `void OverlayImageOnPointEffecter::OnPaint()` and preserve `RenderOverlayImageAtPoint` as a behavior alias. The vtable slot evidence supports paint-slot semantics; local generated metadata supports the current behavior name.
- If the helper docs prefer free-helper spelling over member-like spelling, keep `RenderTileFrame(...)` as a free helper. Do not invent `DrawOverlayImageAtPoint`.
- If the project standardizes `LoadImageFrameTable(imageName, 0)` / `DestroyOwnedImageBlock(block)` without explicit `g_pEPFLib`, adjust the first-draft body to match that helper signature while preserving the call evidence that `ecx` loads `g_pEPFLib`.
- `m_drawPointX`, `m_drawPointY`, `m_drawBounds`, `m_drawMode`, and `m_active` are inherited/base-field names inferred from behavior. The target prose should keep the offset mapping so these names can be refined later.
- Do not include scalar deleting destructor, adjusted thunks, vtable stores, SEH handlers, or cookie/unwind-state writes in formal source.

## Recommended Target Doc Changes

For `by-class/OverlayImageOnPointEffecter.md`:

1. Change metadata to:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace the empty C++ block with the first-draft constructor/destructor/renderer code above, adjusted only for locally established helper spelling.

3. Update method notes:

```text
| `0x0055a7a0-0x0055a7c6` | `RenderOverlayImageAtPoint` / paint-slot renderer | `+0x04` Pane/GrafPort view method; adjusted receiver maps renderer offsets to complete-object `m_paletteName` `+0x120`, `m_frameRecord.tileContext` `+0x144`, tile bounds/source record `+0x154`, inherited draw bounds `+0x48`, and draw mode `+0x74`; calls shared Surface/GrafPort `RenderTileFrame(..., m_paletteName, 0)`. |
| `0x0055a7d0-0x0055a8da` | constructor | Six-argument complete-object constructor; calls `OverlayEffecter(1, overlayX, overlayY)`, installs four views, initializes the frame record/tile context, loads owned image/frame block at `+0x140`, copies two 16-wide names, resolves EPF layout through `g_pEPFLib->LookupLayoutEntry`, stores point coordinate words and inherited mirrors, sets active byte, and seeds fixed 300 draw/bounds extents. |
| `0x0055a8e0-0x0055a987` | destructor | Ordinary destructor releases owned complete `+0x140` block through `DestroyOwnedImageBlock`; vtable/base/pane resets are compiler/base destructor mechanics. |
| `0x0055be10-0x0055bee3` | scalar deleting destructor | Compiler-generated wrapper; repeats teardown, checks delete flags, calls `0x004f4ac0` for ordinary scalar delete and `0x0041b6a0(this, 0x170)` for the `(flags & 4)` path. No formal C++. |
```

4. Add explicit adjusted-this explanation:

```text
The renderer at `0x0055a7a0` is installed in the `+0x04` Pane/GrafPort view at `0x00623854`, so its receiver is `complete this + 4`. Normalize render-body offsets before naming fields: adjusted `+0x11c/+0x140/+0x150/+0x44/+0x70` are complete `+0x120/+0x144/+0x154/+0x48/+0x74`.
```

5. Replace "overlay resource id" / "render handle" wording with a clearer field model:

```text
Complete `+0x140` is the owned image/frame block returned by `LoadImageFrameTable`; complete `+0x144` is the EPFTileContext/frame draw record initialized by `InitTileContext` and used by the renderer. The ordinary and scalar destructors free only the owned `+0x140` block. The renderer uses the adjusted `+0x140` pointer, which is complete `+0x144`, not the owned-block pointer itself.
```

6. Replace "300-tick state" wording with:

```text
The constructor writes `0x12c` / 300 to inherited draw/bounds fields at complete `+0x50` and `+0x54`. Current evidence favors fixed point-overlay draw/bounds extents rather than a proven lifetime timer; keep the field names provisional until `OverlayEffecter`/Pane layout names are finalized.
```

7. Preserve no-direct-caller evidence but explain impact:

```text
Local PE xref scans found no direct rel32 or absolute pointer route to `0x0055a7d0` or `0x0055a8e0`. This caps final confidence but is not a no-code proof: the constructor/destructor are source-shaped, install/release class-owned state, and match the overlay-effecter family pattern. Renderer/scalar wrapper reachability is vtable-owned.
```

8. Add score rationale:

```text
Completion 88: source placement, exact ranges, adjusted receiver mapping, field layout, helper names, owned resource lifetime, scalar-wrapper policy, and first-draft C++ are now resolved.
Confidence 91: method boundaries, vtables, local PE pointer/ref scans, helper docs, and sibling overlay reports agree. Confidence stays below final audit because direct constructor/destructor caller routes are still not found, final original field/helper spellings are inferred, and the `OverlayEffecter` inherited point/draw field names remain provisional.
```

## Recommended Support-Doc Changes

For [UID:0000IZ][Effects](../../../../../by-file/Effects.md):

- Update the `OverlayImageOnPointEffecter` row to show exact ranges `0x0055a7a0-0x0055a987` and `0x0055be10-0x0055bee3`.
- Add that B002 resolves the class as source-ready under `NexusTK/render/Effects.cpp`, with first-draft constructor/destructor/renderer C++ and compiler-generated scalar destructor treatment.
- Mention the adjusted `+0x04` view correction so future Effects-family work does not copy adjusted offsets as complete-object fields.

For [UID:0001GE][ScreenEffecterRuntimeCluster](../../../../../by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md):

- Add exact padding/range details from this report.
- Replace old renderer field wording with the normalized mapping:
  - adjusted renderer `+0x11c` -> complete `+0x120` palette/secondary name;
  - adjusted `+0x140` -> complete `+0x144` tile context;
  - adjusted `+0x150` -> complete `+0x154` source/bounds record;
  - complete `+0x140` remains owned block freed by destructors.
- Add constructor `ret 0x18`, six-argument shape, coordinate stores, active byte, and 300 draw/bounds extents.
- Keep no direct constructor/destructor ref caveat and scalar deleting destructor compiler policy.

For [UID:0001YO][ScreenEffecterVtableFamily](../../../../../by-type/by-vtable/ScreenEffecterVtableFamily.md):

- Preserve four-view addresses and store evidence.
- Add slot detail: `0x00623854 -> 0x0055a7a0` is the `+0x04` Pane/GrafPort view paint/render slot and receives an adjusted receiver.
- Add scalar wrapper detail: `0x00623804 -> 0x0055be10`; secondary adjustor thunks at `0x0055ba9a`, `0x0055baa2`, and `0x0055baad`.

For [UID:0002OR][ScreenEffecterVtableData](../../../../../by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md):

- Add or refresh `OverlayImageOnPointEffecter` vtable view spans and slot notes:
  - primary `0x006237ec`, scalar wrapper slot `0x00623804`;
  - `+0x04` view `0x00623810`, render slot `0x00623854 -> 0x0055a7a0`;
  - `+0xa4` view `0x0062385c`;
  - `+0xa8` view `0x0062388c`.
- Keep this page generated-binary/vtable-data support, not a source emitter.

For helper/global support docs:

- [UID:000165][SurfacePaintHelpers](../../../../../by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) already documents `RenderTileFrame` as shared Surface/GrafPort helper with broad caller evidence; no owner change required. Optional consumer note only.
- [UID:0002P4][LoadImageFrameTable](../../../../../by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) and [UID:0002P5][DestroyOwnedImageBlock](../../../../../by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) already list the target's constructor/destructor pair; optional note can add adjusted-render distinction between owned block `+0x140` and tile context `+0x144`.
- [UID:00004I][EPFTileContext](../../../../../by-class/EPFTileContext.md) needs no mandatory edit unless implementation wants an overlay-effecter consumer cross-link.
- [UID:0000QU][g_pEPFLib](../../../../../by-global/g_pEPFLib.md) needs no mandatory edit; current `LookupLayoutEntry` and loader roles are sufficient.

No new UID is required for this report. If the supervisor later wants exact method children, the natural split is renderer, constructor, ordinary destructor, and scalar deleting destructor/no-code wrapper. That split is optional for this target because the class page can safely carry first-draft code, but exact children would improve consistency with some sibling effecter work.

## Exact Coverage Text

Recommended replacement row for `by-class/-coverage-report.md`:

```text
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md) : reconstructable : 88% : very strong : B002 source-quality pass resolves this Effects-owned point overlay-image effecter with exact renderer/constructor/destructor/scalar-wrapper ranges, clean padding, four-view vtables, adjusted `+0x04` Pane/GrafPort paint receiver mapping (`+0x120` palette name, `+0x144` tile context, `+0x154` source bounds), owned `LoadImageFrameTable` block at complete `+0x140` freed by `DestroyOwnedImageBlock`, point coordinate stores/mirrors, `g_pEPFLib` lookup, shared `RenderTileFrame` route, no direct constructor/non-scalar-destructor ref caveat, compiler-generated scalar-delete policy including `0x170` sized path, and first-draft constructor/destructor/render C++ readiness.
```

Recommended supervisor-owned replacement row for `by-memory/-coverage-report.md` if the runtime-cluster support doc is updated:

```text
    - [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) 0x0055a260-0x0055c1ff | class/helper cluster | ScreenEffecterRuntimeCluster : reconstructable : 86% : strong : Attached runtime effecter aggregate with live IDA/local PE-confirmed ScreenEffecter/overlay/filter/pixel/lake method inventory, vtable stores, render helper data flow, resource load/free ownership, raw constructor islands, boundary padding, selected source-ready method children, and B002's corrected OverlayImageOnPointEffecter adjusted-receiver mapping separating complete `+0x140` owned block from complete `+0x144` tile context plus point-coordinate and scalar-wrapper policy.
```

If the implementation callback touches only the class page and not the runtime cluster, no `by-memory/-coverage-report.md` row change is required. In all cases, B002 must not edit `by-memory/-coverage-report.md`; coverage application remains supervisor-owned.

## Validation Commands Needed After Accepted Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [00009Z-OverlayImageOnPointEffecter-source-quality-removed.md](00009Z-OverlayImageOnPointEffecter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If helper docs are optionally touched, run validator file mode for those touched helper docs too. If the formal C++ block changes generated output, run the repository's normal validator/autogen workflow and inspect `auto-generated/NexusTK/render/Effects.cpp`, `auto-generated/-ag-class-coverage.md`, projected stats, and any validator registry changes. Do not hand-edit generated files unless the local workflow requires it.

No validators were run in this report-only pass because no by-* files were edited.

## IDA Rename / Type / Comment Recommendations

Function labels:

- Rename/comment `0x0055a7a0` as `OverlayImageOnPointEffecter::RenderOverlayImageAtPoint` or `OverlayImageOnPointEffecter::OnPaint_RenderOverlayImageAtPoint`; high confidence for class and role, medium-high for final spelling. Add repeatable comment: `ecx is adjusted +0x04 Pane/GrafPort view; normalize fields to complete this + 4`.
- Rename/comment `0x0055a7d0` as `OverlayImageOnPointEffecter::OverlayImageOnPointEffecter`.
- Type `0x0055a7d0` as:

```cpp
OverlayImageOnPointEffecter *__thiscall OverlayImageOnPointEffecter_ctor(
    OverlayImageOnPointEffecter *this,
    const wchar_t *imageName,
    const wchar_t *paletteName,
    short overlayX,
    short overlayY,
    short pointX,
    short pointY);
```

- Rename/comment `0x0055a8e0` as `OverlayImageOnPointEffecter::~OverlayImageOnPointEffecter`.
- Rename/comment `0x0055be10` as `OverlayImageOnPointEffecter_scalar_deleting_destructor`; mark compiler-generated.
- Rename/comment `0x0055ba9a`, `0x0055baa2`, and `0x0055baad` as adjusted scalar-deleting destructor thunks for views `+0x04`, `+0xa4`, and `+0xa8`.

Vtable/data labels:

- `0x006237ec`: `OverlayImageOnPointEffecter_vftable_primary`.
- `0x00623810`: `OverlayImageOnPointEffecter_vftable_paneView`.
- `0x0062385c`: `OverlayImageOnPointEffecter_vftable_a4`.
- `0x0062388c`: `OverlayImageOnPointEffecter_vftable_a8`.
- Comment `0x00623854`: `pane/GrafPort view render slot -> OverlayImageOnPointEffecter::RenderOverlayImageAtPoint`.
- Comment `0x00623804`: `primary scalar deleting destructor wrapper`.

Field/type comments:

- Complete `+0x100`: `m_imageName[16]` / primary frame resource name.
- Complete `+0x120`: `m_paletteName[16]` / secondary overlay name; renderer palette/name argument after adjusted mapping.
- Complete `+0x140`: owned `m_frameRecord.imageBlock` returned by `LoadImageFrameTable`.
- Complete `+0x144`: `m_frameRecord.tileContext` / `EPFTileContext`.
- Complete `+0x154`: `m_frameRecord.tileContext.bounds` / source bounds passed to `RenderTileFrame`.
- Complete `+0x16c`: `short m_pointX`; first point argument.
- Complete `+0x16e`: `short m_pointY`; second point argument.
- Complete `+0xb4`: inherited draw/point X mirror of first point argument; final base-field name open.
- Complete `+0xb0`: inherited draw/point Y mirror of second point argument; final base-field name open.
- Complete `+0xf9`: inherited active/visible byte.
- Complete `+0x50/+0x54`: fixed draw/bounds extents set to `300`; do not label as lifetime unless a later base-layout pass proves timer ownership.

Decompiler comments:

- At `0x0055a7c0`: `RenderTileFrame(&tileContext, &tileContext.bounds, &drawBounds, drawMode, paletteName, 0)`, with adjusted receiver note.
- At `0x0055a803`: `OverlayEffecter(1, overlayX, overlayY)`.
- At `0x0055a838`: `InitTileContext(&m_frameRecord.tileContext)`.
- At `0x0055a849`: `m_frameRecord.imageBlock = LoadImageFrameTable(g_pEPFLib, imageName, 0)`.
- At `0x0055a884`: `g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_frameRecord.tileContext)`.
- At `0x0055a891` / `0x0055a8b1`: trailing point words.
- At `0x0055a899` / `0x0055a8a2`: inherited point/draw mirrors.
- At `0x0055a8b8` / `0x0055a8bf`: fixed 300 draw/bounds extents.
- At `0x0055a933` and `0x0055be6a`: `DestroyOwnedImageBlock(m_frameRecord.imageBlock)`.
- At `0x0055beb5`: ordinary scalar delete helper path; at `0x0055bec6`: guarded sized/vector-delete path with object size `0x170`.

## Remaining Open Questions

- Final original renderer name: current target and generated source use `RenderOverlayImageAtPoint`; vtable placement supports a paint-slot name such as `OnPaint`. Best current direction is to keep `RenderOverlayImageAtPoint` as the method name and record `OnPaint` as the vtable-role alias until the overlay family is standardized.
- Final original names for `overlayX`/`overlayY`: they are definitely forwarded to `OverlayEffecter(1, ..., ...)`; sibling reports alternate between `overlayX/overlayY`, `paneWidth/paneHeight`, and similar names. Use descriptive names and keep a base-argument caveat.
- Final inherited point/draw field names at complete `+0xb4/+0xb0` and bounds/extents at `+0x50/+0x54`: evidence shows exact writes, but the inherited Pane/OverlayEffecter field names are not final. Use behavior names in C++ and offset notes in prose.
- Direct constructor/destructor reachability: local PE VA/RVA/raw-offset pointer scans and `.text` rel32 branch scans found none for `0x0055a7d0` or `0x0055a8e0`. Existing docs also lack direct callers. This remains a confidence limiter, not a code-emission blocker, because the class method bodies and vtables are coherent source-authored Effects code.
- Exact helper signatures for `LoadImageFrameTable` and `DestroyOwnedImageBlock`: call sites load `g_pEPFLib` as `ecx`, but support docs may choose free-helper or member-call spelling. Implementation should match the local helper docs while preserving the same argument semantics.
- Exact future split: exact by-memory method children would improve granularity but are not required for the class page to receive first-draft source. Do not create new UIDs during a routine implementation callback unless the supervisor explicitly asks for the split.

## Implementation Readiness

Ready for supervisor review and implementation callback. Recommended implementation scope is the target class page plus the support-doc notes listed above. Coverage application remains supervisor-owned, and `by-memory/-coverage-report.md` must not be edited by B002.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00009Z-OverlayImageOnPointEffecter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00009Z"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00009Z-OverlayImageOnPointEffecter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00009Z-OverlayImageOnPointEffecter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00009Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
