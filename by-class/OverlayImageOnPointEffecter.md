*** UID:00009Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
OverlayImageOnPointEffecter::OverlayImageOnPointEffecter(const wchar_t *imageName,
                                                         const wchar_t *paletteName,
                                                         short overlayX,
                                                         short overlayY,
                                                         short pointX,
                                                         short pointY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    m_frameRecord.tileContext.Init();
    m_frameRecord.imageBlock = LoadImageFrameTable(imageName, 0);

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
                    &m_frameRecord.sourceRect,
                    &m_drawBounds,
                    m_drawMode,
                    m_paletteName,
                    0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OverlayImageOnPointEffecter

## Status

- Confidence: strong for class identity, Effects ownership, exact method boundaries, four-view vtable identity, the adjusted Pane/GrafPort paint receiver, frame-table lifetime, helper names, point-coordinate storage, and first-draft C++ readiness.
- Proposed source: [UID:0000IZ][Effects](by-file/Effects.md), generated under `NexusTK/render/Effects.cpp`.
- Runtime aggregate: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md).
- Base class: [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md).
- C++ status: first-draft source-style C++ is populated for the source-authored constructor, ordinary destructor, and render/paint method. The scalar deleting destructor, adjusted destructor thunks, vtable stores, SEH handlers, and security-cookie/unwind scaffolding are compiler output and remain prose-only evidence.

## Responsibility

`OverlayImageOnPointEffecter` is a pane-backed [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) subclass that draws an overlay image at a fixed pane point. It owns an image/frame block loaded through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), initializes an embedded EPF tile/frame record, keeps copied primary and secondary wide-character names, stores point coordinates in both class-local words and inherited draw-point mirrors, marks the inherited pane state active, and renders through the shared [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) `RenderTileFrame` route.

The older "overlay resource id", "render handle", and "300-tick state" wording is superseded. Complete `+0x140` is the owned image/frame block returned by `LoadImageFrameTable`; complete `+0x144` is the EPFTileContext/frame draw record initialized by `InitTileContext` and passed to the renderer; complete `+0x50/+0x54` are fixed draw/bounds extents set to `300`, not a proven lifetime timer.

## Method And Boundary Inventory

| Range | Size | Source-facing role | Boundary notes |
| --- | ---: | --- | --- |
| `0x0055a7a0-0x0055a7c6` | `0x26` / 38 bytes | `RenderOverlayImageAtPoint`; paint-slot renderer | Ends at `ret`; `0x0055a7c6-0x0055a7d0` is ten `0xcc` bytes before the constructor. Installed in the embedded `+0x04` Pane/GrafPort view, so `ecx` is `complete this + 4`. |
| `0x0055a7d0-0x0055a8da` | `0x10a` / 266 bytes | complete-object constructor | Ends with `ret 0x18`, proving six explicit stack arguments; `0x0055a8da-0x0055a8e0` is six `0xcc` bytes. |
| `0x0055a8e0-0x0055a987` | `0xa7` / 167 bytes | ordinary destructor | Ends at `ret`; `0x0055a987-0x0055a990` is nine `0xcc` bytes before `OverlayMovingImageEffecter`. |
| `0x0055be10-0x0055bee3` | `0xd3` / 211 bytes | scalar deleting destructor | Ends with `ret 4`; `0x0055bee3-0x0055bef0` is thirteen `0xcc` bytes before `OverlayMovingImageEffecter` scalar destructor. Compiler-generated wrapper, not formal handwritten source. |

No merge is justified: all four bodies have clean padding, class-specific vtable or source-shaped constructor/destructor evidence, and independent roles. No direct rel32 or absolute pointer route was found to the constructor `0x0055a7d0` or ordinary destructor `0x0055a8e0` in the local PE scan; this caps final confidence but is not a no-code proof because both bodies are coherent source-authored class methods.

## Vtable And Reachability

`OverlayImageOnPointEffecter` uses the four-view object shape shared by pane-backed effecters:

| View | Address | Evidence |
| --- | --- | --- |
| Primary complete-object view | `0x006237ec` | Constructor store at `0x0055a817`, ordinary destructor store at `0x0055a90c`, scalar wrapper store at `0x0055be3c`. |
| Embedded `+0x04` Pane/GrafPort view | `0x00623810` | Constructor store at `0x0055a81d`, ordinary destructor store at `0x0055a912`, scalar wrapper store at `0x0055be43`; render slot `0x00623854 -> 0x0055a7a0`. |
| `+0xa4` adjusted view | `0x0062385c` | Constructor store at `0x0055a824`, ordinary destructor store at `0x0055a919`, scalar wrapper store at `0x0055be4d`. |
| `+0xa8` adjusted view | `0x0062388c` | Constructor store at `0x0055a82e`, ordinary destructor store at `0x0055a923`, scalar wrapper store at `0x0055be57`. |

Important slot and xref facts:

- `0x0055a7a0` has one VA pointer hit, `0x00623854`, the adjusted `+0x04` Pane/GrafPort paint/render slot.
- `0x0055be10` has one VA pointer hit, `0x00623804`, the primary scalar deleting destructor slot.
- Direct rel32 branches to `0x0055be10` occur at `0x0055ba9d`, `0x0055baa8`, and `0x0055bab3`, the secondary-view destructor adjustor strip.
- Adjusted scalar destructor thunks are `0x0055ba9a` (`sub ecx, 4`), `0x0055baa2` (`sub ecx, 0xa4`), and `0x0055baad` (`sub ecx, 0xa8`); each jumps to `0x0055be10`.
- Shared helper call counts from the local PE scan support broad helper ownership rather than caller-local names: `RenderTileFrame` at `0x004b9980` has 311 direct calls, `LoadImageFrameTable` at `0x004d0f50` has 25 calls, `DestroyOwnedImageBlock` at `0x004d15d0` has 8 calls, `ResourceLayoutTable::LookupLayoutEntry` at `0x004d02f0` has 440 calls, and `InitTileContext` at `0x00457a60` has 337 calls.
- The shared [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) constructor at `0x0055a2e0` has four overlay-subclass constructor calls: `0x0055a4d3`, `0x0055a651`, `0x0055a803`, and `0x0055ab32`.

## Adjusted Renderer Receiver

The renderer is installed in the `+0x04` Pane/GrafPort view, so its `ecx` is not the complete object start. Normalize render-body offsets by adding four before naming fields:

| Renderer offset | Complete offset | Best current source role |
| --- | --- | --- |
| adjusted `+0x11c` | complete `+0x120` | `m_paletteName` / secondary overlay name, passed to `RenderTileFrame` and then palette lookup. |
| adjusted `+0x140` | complete `+0x144` | embedded `EPFTileContext` / frame draw record after the owned block pointer. |
| adjusted `+0x150` | complete `+0x154` | source bounds/record field inside the tile context/frame record. |
| adjusted `+0x44` | complete `+0x48` | inherited Pane/GrafPort draw/destination bounds. |
| adjusted `+0x70` | complete `+0x74` | inherited draw/blit mode byte. |

This adjusted-this correction resolves the old confusion between the owned block at complete `+0x140` and the render descriptor at complete `+0x144`. The renderer calls `RenderTileFrame(&m_frameRecord.tileContext, &m_frameRecord.sourceRect, &m_drawBounds, m_drawMode, m_paletteName, 0)`. If the effecter family later standardizes all `+0x04` paint slots as `OnPaint()`, this method can be renamed to `OnPaint()` while preserving `RenderOverlayImageAtPoint` as the behavior alias.

## Constructor Details

`0x0055a7d0` returns with `ret 0x18`, so the source-shaped constructor has six explicit arguments:

```cpp
OverlayImageOnPointEffecter::OverlayImageOnPointEffecter(
    const wchar_t *imageName,
    const wchar_t *paletteName,
    short overlayX,
    short overlayY,
    short pointX,
    short pointY);
```

Observed constructor behavior:

- Calls `OverlayEffecter(1, overlayX, overlayY)` at `0x0055a803`.
- Installs the four `OverlayImageOnPointEffecter` vtable views at `0x006237ec`, `0x00623810`, `0x0062385c`, and `0x0062388c`.
- Calls `InitTileContext` / `EPFTileContext::Init` at `0x00457a60` on complete `this+0x144`.
- Calls `LoadImageFrameTable(imageName, 0)` at `0x004d0f50` and stores the owned image/frame block at complete `this+0x140`; B010 2026-07-03 caller-disassembly evidence shows nearby `g_pEPFLib` / `ecx` setup is not a target parameter for this loader.
- Copies `imageName` to complete `this+0x100` and `paletteName` to complete `this+0x120` through the bounded wide-string copy helper at `0x005cd657` with size argument `0x10`.
- Calls `ResourceLayoutTable::LookupLayoutEntry(g_pEPFLib, this+0x100, 0, this+0x144)` at `0x004d02f0`.
- Stores the first point argument to trailing word complete `+0x16c` and sign-extended inherited mirror complete `+0xb4`.
- Stores the second point argument to trailing word complete `+0x16e` and sign-extended inherited mirror complete `+0xb0`.
- Writes active/visible byte complete `+0xf9 = 1`.
- Writes `0x12c` / 300 to complete `+0x50` and `+0x54`. Current evidence favors fixed point-overlay draw/bounds extents or inherited point-overlay extents rather than a proven lifetime timer.
- Uses MSVC constructor-unwind scaffolding: SEH handler `0x0060761d`, security cookie `[0x00672f24]`, and unwind-state writes. These are not source statements.

## Field And Subobject Direction

| Complete offset | Best name/type direction | Evidence and caveat |
| --- | --- | --- |
| `+0x100` | `wchar_t m_imageName[16]` | Primary frame resource name copied with size `0x10`; used as the `LookupLayoutEntry` key. |
| `+0x120` | `wchar_t m_paletteName[16]` / secondary overlay name | Copied from the second name argument and passed by the adjusted renderer to `RenderTileFrame`; final spelling remains inferred. |
| `+0x140` | `m_frameRecord.imageBlock` / owned image-frame block pointer | Stores the `LoadImageFrameTable` result and is the field freed by ordinary and scalar destructors. |
| `+0x144` | `m_frameRecord.tileContext` / embedded `EPFTileContext` | Initialized by `InitTileContext`, filled by `LookupLayoutEntry`, and passed to `RenderTileFrame` after adjusted receiver normalization. |
| `+0x154` | `m_frameRecord.sourceRect` / source bounds record | Passed to `RenderTileFrame` as the frame/source bounds argument. |
| `+0x16c` | `short m_pointX` | First point argument; also mirrored to inherited draw-point field complete `+0xb4`. |
| `+0x16e` | `short m_pointY` | Second point argument; also mirrored to inherited draw-point field complete `+0xb0`. |
| `+0xb4` | inherited `m_drawPointX` / point mirror | Sign-extended first point argument; final inherited field name remains provisional. |
| `+0xb0` | inherited `m_drawPointY` / point mirror | Sign-extended second point argument; final inherited field name remains provisional. |
| `+0xf9` | inherited active/visible byte | Constructor writes `1`, matching sibling overlay constructors. |
| `+0x50/+0x54` | fixed draw/bounds extents set to `300` | Old lifetime wording is not supported strongly enough; keep exact field names provisional until the base layout is finalized. |

## Destructor Handling

The ordinary destructor `0x0055a8e0-0x0055a987` reinstalls the most-derived vtable views, releases the owned complete `+0x140` image/frame block through `DestroyOwnedImageBlock` at `0x004d15d0`, resets the four base [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) views (`0x006235e8`, `0x0062360c`, `0x00623658`, `0x00623688`), runs inherited Pane cleanup/destructor helpers `0x00544ce0` and `0x00544580` on the `+0x04` view, and resets the primary base to [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) vtable `0x006235a4`.

The source-facing body should only release the owned frame/image block. Vtable resets, Pane teardown, base destructor chaining, SEH handler `0x00607638`, and cookie scaffolding are compiler/base mechanics.

The scalar deleting destructor `0x0055be10-0x0055bee3` is compiler-generated:

- `(flags & 1) == 0`: no storage delete.
- `(flags & 1) != 0 && (flags & 4) == 0`: call MemoryMan-backed `operator delete` wrapper `0x004f4ac0`.
- `(flags & 4) != 0`: call guarded sized/vector-delete helper `0x0041b6a0(this, 0x170)`.
- The object size is `0x170` / 368 bytes.
- It repeats release/base-teardown structure because MSVC emitted a deleting-destructor wrapper body.

Do not emit a source method named `ScalarDeletingDestructor`. Keep the wrapper, delete flags, object size, and secondary adjustor thunks in reverse-engineering/vtable prose only.

## Helper Name Resolution

| Address/raw label | Source-facing name/role | Evidence |
| --- | --- | --- |
| `0x004b9980` / `sub_4B9980` | `RenderTileFrame` shared Surface/GrafPort render wrapper | [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) documents the helper, broad caller count, palette lookup through `g_pPaletteLib`, and callback slot `dword_69B3E8`; fitting-room/download ownership is caller pollution. |
| `0x004d0f50` / `sub_4D0F50` | `LoadImageFrameTable` | Existing ImageFrameTable helper docs; constructor stores the returned block at complete `+0x140`. |
| `0x004d15d0` / `sub_4D15D0` | `DestroyOwnedImageBlock` | Existing helper docs list overlay image constructors/destructors and free this target's complete `+0x140` block. |
| `0x004d02f0` / `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | Existing central EPF/EPD layout lookup; constructor fills complete `+0x144`. |
| `0x00457a60` / `sub_457A60` | `InitTileContext` / `EPFTileContext::Init` | EPFTileContext docs define the 0x28-byte context initializer; constructor calls it on complete `+0x144`. |
| `0x005cd657` | bounded wide-string copy, likely `wcscpy_s(dest, 0x10, source)` | Sibling overlay constructors and local argument order support the secure-copy source spelling, though the exact CRT import name is not symbol-proven. |
| `0x004f4ac0` | MemoryMan-backed `operator delete` wrapper | Storage-delete path inside the scalar deleting destructor only. |
| `0x0041b6a0` | guarded sized/vector-delete path helper | `(flags & 4)` scalar-wrapper path with object size `0x170`; compiler glue. |
| `0x00544ce0` / `0x00544580` | inherited Pane cleanup and ordinary Pane teardown | Base destructor mechanics, not effecter-specific source calls. |

Rejected alternatives:

- Do not leave `sub_55A7A0`, `sub_55A7D0`, `sub_55A8E0`, or `sub_55BE10` as passive blockers; class/method roles are strong enough to name.
- Do not route `0x004b9980` through `FittingRoomDownloadControlPane`; Surface/GrafPort helper docs and the broad 311-call profile contradict that owner.
- Do not read renderer adjusted `this+0x11c/+0x140/+0x150/+0x44/+0x70` as complete-object fields.
- Do not classify the constructor/destructor no-direct-route result as no-code proof.
- Do not emit scalar deleting destructor, adjusted thunks, vtable stores, SEH, or security-cookie code as handwritten source.

## Owner And Source Placement

Keep `CANONICAL_OWNER:0000IZ` and `EMITTER_UIDS:0000IZ`. [UID:0000IZ][Effects](by-file/Effects.md) owns the runtime `ScreenEffecter` / `PixelEffecter` / overlay / filter / water / lake hierarchy and already emits `NexusTK/render/Effects.cpp`.

Rejected or lower-ranked routes:

- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) is the base-class dependency, not the direct source emitter for this subclass.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) are aggregate/vtable support docs, not the class emitter.
- Surface/GrafPort and ImageFrameTable/ResourceLayoutTable docs own the shared helpers, not this class's vtable route, point policy, or resource lifetime.
- No-owner/non-emitting is rejected because the class is source-authored, vtable-reachable, inside a known runtime class family, and now has a valid first-draft source body.

## Open Questions And Best Current Resolution

- Final render method name: `RenderOverlayImageAtPoint` matches current generated metadata and behavior. A future family-wide paint-slot naming pass may prefer `OnPaint`; preserve the vtable-role alias until standardized.
- Final names for `overlayX`/`overlayY`: they are the two words forwarded after fixed `1` to `OverlayEffecter(1, ..., ...)`. Use descriptive names until factory/caller context proves original spelling.
- Final inherited point/bounds field names at complete `+0xb4/+0xb0/+0x50/+0x54`: exact writes are known, but base layout names remain provisional. Use behavior names in C++ plus offset notes in prose.
- Direct constructor/destructor reachability: local PE VA/RVA/raw-offset pointer scans and `.text` rel32 branch scans found none for `0x0055a7d0` or `0x0055a8e0`; this remains a confidence limiter, not a C++ blocker.
- Exact helper signatures: call sites load `g_pEPFLib` as receiver for the layout/destroy family and may also load `ecx` before the loader call, but B010 2026-07-03 confirms `LoadImageFrameTable` itself consumes only two stack arguments. The draft follows current Effects-family style while preserving the argument semantics.

## C++ Readiness

This page now carries first-draft source-style C++ because the source-authored constructor, ordinary destructor, and paint/render method have stable ownership, exact ranges, helper names, vtable route, field offsets, and sibling-effecter precedent. The draft intentionally uses descriptive field/helper names rather than raw offsets and excludes compiler deleting-destructor machinery.

The draft remains below final-audit quality because original field spellings, inherited base field names, exact helper signatures, and the direct constructor/destructor caller route are not fully recovered.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | Source placement, exact ranges and padding, adjusted receiver mapping, four-view vtables, owned resource lifetime, field layout, helper names, scalar-wrapper policy, rejected alternatives, and first-draft C++ for eligible handwritten methods are now documented. |
| Confidence `91` | Method boundaries, local PE pointer/ref scans, helper docs, sibling overlay reports, vtable data, and runtime aggregate docs agree. Confidence stays below final audit because constructor/destructor direct routes remain absent, original field/helper spellings are inferred, and inherited point/draw field names remain provisional. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md)
- [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- 2026-06-20 B002 Rule 26 source-quality incorporation:
  - Before: `84/90`, blank C++, high-level render/resource wording, raw adjusted renderer offsets written as complete-object fields, and stale "300-tick state" language.
  - After: `88/91`, owner/emitter still [UID:0000IZ][Effects](by-file/Effects.md), first-draft constructor/destructor/render C++ populated, scalar deleting destructor retained as compiler-generated no-source glue, and adjusted `+0x04` Pane/GrafPort receiver mapping resolved.
  - Incorporated evidence: exact half-open ranges and sizes; clean padding; local PE image/section and pointer/ref scan results from the B002 report; four-view vtable bases `0x006237ec`, `0x00623810`, `0x0062385c`, and `0x0062388c`; render slot `0x00623854 -> 0x0055a7a0`; primary scalar slot `0x00623804 -> 0x0055be10`; adjusted scalar destructor thunks at `0x0055ba9a`, `0x0055baa2`, and `0x0055baad`; constructor `ret 0x18` six-argument shape; `OverlayEffecter(1, overlayX, overlayY)` call; `InitTileContext`, `LoadImageFrameTable`, bounded wide-string copy, `ResourceLayoutTable::LookupLayoutEntry`, `DestroyOwnedImageBlock`, `RenderTileFrame`, MemoryMan delete, and guarded sized-delete helper names; complete offset model for `m_imageName`, `m_paletteName`, owned image block, tile context, source bounds, point coordinates, inherited point mirrors, active byte, and fixed `300` extents; no-direct constructor/destructor route caveat; rejected owner/name/source alternatives; and first-draft C++ readiness with remaining final-spelling caveats.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: constructor metadata evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to EPF resource metadata lookup.
- 2026-06-04: Raised completion/confidence from `72/78` to `84/90`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Summary/evidence: live IDA MCP verified exclusive function endpoints, constructor base call and four-view vtable stores, resource load/free helpers, two copied names, point-coordinate storage, render helper arguments, and destructor/scalar-destructor ownership. Completion remained below final-source quality because final public method/field names and all creator/caller contexts still needed reconstruction.
- Before: completion/confidence metadata were `0/0` even though the page already documented responsibility, method boundaries, owner, and provisional field-layout caveats.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: fixed-point overlay rendering, constructor, destructor, scalar deleting destructor, base relationship, and vtable family are documented; confidence remained medium-high because final field names and reconstructed C++ were incomplete.
