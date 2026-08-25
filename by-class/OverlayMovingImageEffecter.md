*** UID:0000A0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum OverlayMoveDirection {
    kOverlayMoveRight = 1,
    kOverlayMoveLeft = 2,
    kOverlayMoveDown = 3,
    kOverlayMoveUp = 4
};

OverlayMovingImageEffecter::OverlayMovingImageEffecter(const wchar_t *imageName,
                                                       const wchar_t *paletteName,
                                                       short paneWidth,
                                                       short paneHeight,
                                                       short moveRangeY,
                                                       short moveRangeX,
                                                       short stepPixels,
                                                       short directionMode)
    : OverlayEffecter(1, paneWidth, paneHeight)
{
    m_frameRecord.tileContext.Init();
    m_frameRecord.imageBlock = LoadImageFrameTable(imageName, 0);

    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_overlayName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_frameRecord.tileContext);

    m_moveRangeX = moveRangeX;
    m_moveRangeY = moveRangeY;
    m_stepPixels = stepPixels;
    m_directionMode = directionMode;

    m_savedVerticalReset = m_scrollY2;
    m_savedHorizontalReset = m_scrollX;
    m_active = 1;

    m_scrollY2 += m_stepPixels;
    m_scrollX += m_directionMode;
    m_drawBounds.bottom -= m_stepPixels;
    m_drawBounds.right -= m_directionMode;
    m_savedDrawBounds = m_drawBounds;
}

OverlayMovingImageEffecter::~OverlayMovingImageEffecter()
{
    DestroyOwnedImageBlock(g_pEPFLib, m_frameRecord.imageBlock);
}

void OverlayMovingImageEffecter::OnPaint()
{
    switch (m_directionMode) {
    case kOverlayMoveRight:
        m_scrollX += m_stepPixels;
        if (m_scrollX >= m_wrapXStart + m_wrapXSpan) {
            m_scrollX = m_wrapXStart;
        }
        m_drawBounds.right = m_wrapXStart + m_wrapXSpan - m_scrollX;
        break;

    case kOverlayMoveLeft:
        m_scrollX -= m_stepPixels;
        if (m_scrollX + m_viewWidth == g_mapTilePixelWidth) {
            m_scrollX = m_wrapXSpan;
        }
        m_drawBounds.right = g_mapTilePixelWidth + m_wrapXSpan - m_scrollX;
        break;

    case kOverlayMoveDown:
        m_scrollY += m_stepPixels;
        if (m_scrollY == m_wrapYSpan) {
            m_scrollY = m_savedVerticalReset;
        }
        m_drawBounds.bottom = g_mapTilePixelHeight + m_wrapYSpan - m_scrollY;
        break;

    case kOverlayMoveUp:
        m_scrollY -= m_stepPixels;
        if (m_scrollY + m_viewHeight == g_mapTilePixelHeight) {
            m_scrollY = m_wrapYSpan;
        }
        m_drawBounds.bottom = g_mapTilePixelHeight + m_wrapYSpan - m_scrollY;
        break;
    }

    RenderTileFrame(&m_frameRecord,
                    &m_frameRecord.sourceRect,
                    &m_drawBounds,
                    m_drawMode,
                    m_paletteLookupKey,
                    0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OverlayMovingImageEffecter

## Status

- Confidence: strong for class identity, source ownership, Effects emitter route, method boundaries, four-view vtable identity, direction-mode update behavior, frame-table lifetime, and the `OnPaint` source route.
- Likely source module: [UID:0000IZ][Effects](by-file/Effects.md), generated under `NexusTK/render/Effects.cpp`.
- Runtime aggregate: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md).
- Base class: [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md).
- C++ status: first-draft source-style C++ is populated for the constructor, ordinary destructor, and paint/update virtual. The scalar deleting destructor is compiler-generated glue and remains prose-only evidence.

## Responsibility

`OverlayMovingImageEffecter` is a pane-backed, scrolling/repeating overlay image effect. It derives from [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md), owns an EPF frame/table record loaded through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), stores two copied wide-character names, keeps movement range/step/direction parameters, snapshots draw/clip/scroll state, advances the active scroll rectangle according to a four-way direction mode, and renders the current frame through the shared [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) wrapper and [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot 2.

The source-facing method name for `0x0055a990` is `OverlayMovingImageEffecter::OnPaint()`. `UpdateAndRender` remains useful behavior wording because the override advances motion state immediately before rendering, but the vtable evidence places the body in the adjusted `+0x04` Pane/GrafPort paint slot, matching the accepted `WaterFilterEffecter::OnPaint()` route.

## Method And Boundary Inventory

| Range | Size | Source-facing method | Boundary notes |
| --- | ---: | --- | --- |
| `0x0055a990-0x0055aae3` | `0x153` / 339 bytes | `OverlayMovingImageEffecter::OnPaint()`; behavior alias `UpdateAndRender` | Preceded by `0xcc` padding at `0x0055a987-0x0055a990`; ends with `ret` at `0x0055aae2`; followed by a four-entry switch jump table at `0x0055aae4-0x0055aaf4`, then `0xcc` padding to the constructor. |
| `0x0055ab00-0x0055ac4a` | `0x14a` / 330 bytes | `OverlayMovingImageEffecter::OverlayMovingImageEffecter(...)` | Starts after update jump-table padding; calls `OverlayEffecter(1, arg10, arg14)` at `0x0055ab32`; ends with `ret 0x20`; `0x0055ac4a-0x0055ac50` is six bytes of `0xcc` padding. |
| `0x0055ac50-0x0055acf7` | `0xa7` / 167 bytes | `OverlayMovingImageEffecter::~OverlayMovingImageEffecter()` | Ends with `ret` at `0x0055acf6`; `0x0055acf7-0x0055ad00` is `0xcc` alignment before `FilterEffecter`. |
| `0x0055bef0-0x0055bfc3` | `0xd3` / 211 bytes | compiler-generated scalar deleting destructor | Preceded by padding at `0x0055bee3-0x0055bef0`; ends with `ret 4` at `0x0055bfc0-0x0055bfc2`; `0x0055bfc4-0x0055bfd0` is padding before the `ScreenEffecter` scalar deleting destructor. |

The `OnPaint` jump table is concrete switch data, not a separate source function:

```text
0x0055aae4 -> 0x0055a9ad  mode 1
0x0055aae8 -> 0x0055a9e7  mode 2
0x0055aaec -> 0x0055aa37  mode 3
0x0055aaf0 -> 0x0055aa6d  mode 4
```

## Vtable And Reachability

`OverlayMovingImageEffecter` has the same four-view effecter shape as [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) and the other pane-backed effecter classes:

| View | Address | Evidence |
| --- | --- | --- |
| RTTI/COL pointer before primary | `0x00623894 -> 0x0064f3c8` | Decorated RTTI/vtable island evidence. |
| Primary view | `0x00623898` | Constructor writes at `0x0055ab44`; destructor writes at `0x0055ac7c`; scalar destructor writes at `0x0055bf1c`. |
| `+0x04` Pane/GrafPort view | `0x006238bc` | Constructor writes at `0x0055ab4a`; destructor writes at `0x0055ac82`; scalar destructor writes at `0x0055bf22`; paint slot `+0x44` is `0x00623900 -> 0x0055a990`. |
| `+0xa4` view | `0x00623908` | Constructor writes at `0x0055ab51`; destructor writes at `0x0055ac89`; scalar destructor writes at `0x0055bf29`. |
| `+0xa8` view | `0x00623938` | Constructor writes at `0x0055ab5b`; destructor writes at `0x0055ac93`; scalar destructor writes at `0x0055bf33`. |

Important vtable entries from the local PE scan:

```text
0x00623898 -> 0x0055c1b0  shared boolean virtual stub
0x0062389c -> 0x0055c1b0  shared boolean virtual stub
0x006238a0 -> 0x0055c1c0  shared boolean virtual stub
0x006238a4 -> 0x0055c1d0  ScreenEffecter completion query
0x006238b0 -> 0x0055bef0  scalar deleting destructor
0x006238bc -> 0x0055bab8  adjusted scalar destructor thunk, subtract this by 4
0x00623900 -> 0x0055a990  adjusted Pane/GrafPort paint slot +0x44
0x00623908 -> 0x0055bac0  adjusted scalar destructor thunk, subtract this by 0xa4
0x00623938 -> 0x0055bacb  adjusted scalar destructor thunk, subtract this by 0xa8
```

The destructor adjustor strip confirms the three secondary-view routes:

```text
0x0055bab8: sub ecx, 4;    jmp 0x0055bef0
0x0055bac0: sub ecx, 0xa4; jmp 0x0055bef0
0x0055bacb: sub ecx, 0xa8; jmp 0x0055bef0
```

Direct ordinary calls to the constructor, ordinary destructor, or `OnPaint` start were not found in the PE scan. That is expected for this runtime effecter family: the constructor is reached through factory paths or raw callsite-specific creation, the paint/update method is vtable-owned, and the scalar deleting destructor is reached by vtable entries and adjustor thunks. Literal function-pointer scans found `0x0055a990` at `0x00623900` and `0x0055bef0` at `0x006238b0`.

## Behavior And Field Inference

`OnPaint` reads the signed word at `this+0x16e`, subtracts one, dispatches modes `1..4`, then calls the shared render wrapper at `0x004b9980`. Best current direction constants are:

```cpp
enum OverlayMoveDirection {
    kOverlayMoveRight = 1,
    kOverlayMoveLeft = 2,
    kOverlayMoveDown = 3,
    kOverlayMoveUp = 4
};
```

The exact original enum names are not recoverable from current evidence. The directional labels are high-probability source names inferred from the sign of the scroll update and whether the code compares against [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) width or height. Axis-neutral spellings such as `kOverlayMovePositiveX`, `kOverlayMoveNegativeX`, `kOverlayMovePositiveY`, and `kOverlayMoveNegativeY` remain acceptable alternatives if later caller context proves that style.

Observed update behavior:

- Mode `1`: adds `m_stepPixels` (`this+0x16c`) to horizontal scroll state at `this+0xb0`; wraps to `this+0x180` when the value reaches `this+0x178 + this+0x180`; writes the derived draw/right boundary at `this+0x4c`.
- Mode `2`: subtracts `m_stepPixels` from horizontal scroll state at `this+0xb0`; wraps to `this+0x178` when `(short)this+0xf8 + scrollX == g_mapTilePixelWidth`; writes the derived draw/right boundary at `this+0x4c`.
- Mode `3`: adds `m_stepPixels` to vertical scroll state at `this+0xac`; wraps to `this+0x184` when the value equals `this+0x17c`; writes the derived draw/bottom boundary at `this+0x50` using `g_mapTilePixelHeight`.
- Mode `4`: subtracts `m_stepPixels` from vertical scroll state at `this+0xac`; wraps to `this+0x17c` when `(short)this+0xfa + scrollY == g_mapTilePixelHeight`; writes the derived draw/bottom boundary at `this+0x50`.
- Any non-`1..4` mode skips the motion adjustment and still renders the current frame.

Use [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) names `g_mapTilePixelWidth` and `g_mapTilePixelHeight` instead of raw `word_66DA9C` and `word_66DAA0`.

## Constructor Parameters

The constructor has eight explicit stack arguments and returns with `ret 0x20`:

| Stack arg | Best source-facing role | Evidence and caveat |
| --- | --- | --- |
| `[ebp+0x08]` | `imageName` / frame-table resource name | Passed to `LoadImageFrameTable(imageName, 0)`, copied to `this+0x100`, and used as the `ResourceLayoutTable::LookupLayoutEntry` lookup name. B010 2026-07-03 clarifies that nearby `g_pEPFLib` / `ecx` setup is not a target parameter for `LoadImageFrameTable`. |
| `[ebp+0x0c]` | `paletteName` / overlay secondary name | Copied to `this+0x120` with `wcscpy_s(..., 0x10, ...)`. `OnPaint` passes a nearby key at `this+0x11c` to the renderer, so the exact field relationship remains a documented layout ambiguity. |
| `[ebp+0x10]` | `paneWidth` / `overlayWidth` | Passed to `OverlayEffecter(1, arg10, arg14)`. Sibling generated names conflict between `imageWidth/imageHeight` and `overlayX/overlayY`; use neutral names until caller/factory context proves original spelling. |
| `[ebp+0x14]` | `paneHeight` / `overlayHeight` | Same base-constructor evidence as above. |
| `[ebp+0x18]` | `moveRangeY` | Stored as word at `this+0x172`; not read by the current `OnPaint` body, so the name is inferred from constructor grouping and generated sibling output. |
| `[ebp+0x1c]` | `moveRangeX` | Stored as word at `this+0x170`; not read by the current `OnPaint` body, so the name is inferred. |
| `[ebp+0x20]` | `stepPixels` | Stored at `this+0x16c`; directly added/subtracted in every motion case. |
| `[ebp+0x24]` | `directionMode` | Stored at `this+0x16e`; drives the `1..4` switch. The constructor also applies this value as an initial X/clip offset, so keep that dual role in field comments. |

## Field And Subobject Direction

| Offset | Best name/type direction | Evidence |
| --- | --- | --- |
| `+0x100` | `wchar_t m_imageName[16]` | `wcscpy_s(dest=this+0x100, size=0x10, imageName)`. |
| `+0x120` | `wchar_t m_overlayName[16]` / `m_paletteName[16]` | `wcscpy_s(dest=this+0x120, size=0x10, arg0c)`. |
| `+0x11c` | `m_paletteLookupKey` / short overlay lookup string | `OnPaint` passes `this+0x11c` to `RenderTileFrame`, whose fifth argument is resolved through `g_pPaletteLib->GetPaletteByName`; this overlaps the tail of the `+0x100` wide buffer under the current 16-wide-char model. |
| `+0x140` | `m_frameRecord` start; first dword `m_frameRecord.imageBlock` | Constructor stores the `LoadImageFrameTable` result here; ordinary and scalar destructors pass `[this+0x140]` to `DestroyOwnedImageBlock`; renderer passes `this+0x140` as the source frame/tile descriptor. |
| `+0x144` | embedded `EPFTileContext` / frame-record tile context | Constructor calls the documented EPFTileContext initializer at this address; `ResourceLayoutTable::LookupLayoutEntry` writes frame/layout metadata into the same object. |
| `+0x150` | frame-record source rect/view passed to `RenderTileFrame` | Renderer passes `this+0x150` as the second explicit argument. |
| `+0x16c` | `short m_stepPixels` | Used as signed movement delta in all four cases. |
| `+0x16e` | `short m_directionMode` | Switch input and constructor initial offset. |
| `+0x170` | `short m_moveRangeX` | Constructor stores arg `0x1c`; not read by current paint body. |
| `+0x172` | `short m_moveRangeY` | Constructor stores arg `0x18`; not read by current paint body. |
| `+0x174..+0x183` | saved draw/clip rectangle or wrap state copied from `+0x48..+0x57` | Constructor copies a 16-byte block with `movups`; update uses component dwords at `+0x178`, `+0x17c`, and `+0x180` as wrap/boundary values. |
| `+0x184` | saved vertical reset / prior `+0xb4` | Constructor copies old `this+0xb4`; mode `3` uses it as the reset value. |
| `+0x188` | saved horizontal reset / prior `+0xb0` | Constructor copies old `this+0xb0`; not read by current `OnPaint`, but it completes the saved scroll pair. |
| `+0xf9` | active/visible byte | Constructor writes `1`, matching sibling overlay constructors. |

The constructor initializes the frame-record tile context, stores the loaded image block, copies both names, resolves frame layout through `ResourceLayoutTable::LookupLayoutEntry`, stores motion parameters, snapshots draw/clip/scroll state, marks the pane/effect active, and applies initial `stepPixels`/`directionMode` offsets to scroll/clip state.

## Destructor Handling

The ordinary destructor and scalar deleting destructor perform the same owned-resource and pane/base teardown:

1. Reinstall the most-derived `OverlayMovingImageEffecter` vtable views.
2. Call `DestroyOwnedImageBlock(g_pEPFLib, this->m_frameRecord.imageBlock)`.
3. Reset all four views to `OverlayEffecter`.
4. Run pane/overlay cleanup on the `+0x04` Pane/GrafPort view through the inherited pane cleanup helper and ordinary `Pane::~Pane()`.
5. Reset the primary view to `ScreenEffecter`.
6. Only the scalar deleting destructor checks delete flags and optionally frees storage through the MemoryMan-backed `operator delete` wrapper at `0x004f4ac0`; if bit `4` is also set it calls the no-op guard/vector-delete stub with object size `0x18c` / 396 bytes.

Do not emit a source method named `ScalarDeletingDestructor`. Its vtable slot, adjustor thunks, delete-flag behavior, and object-size evidence belong in reverse-engineering prose and exact vtable/memory docs, while source C++ should use the ordinary destructor declaration/body.

## Helper Name Resolution

| Address/raw label | Recommended documentation name | Evidence |
| --- | --- | --- |
| `0x00457a60` / `sub_457A60` | `EPFTileContext` initializer or `FrameDrawRecord::InitTileContext` | The EPFTileContext page documents a 0x28-byte initializer; the constructor calls it on `this+0x144`. |
| `0x004d0f50` / `sub_4D0F50` | `LoadImageFrameTable` | Existing ImageFrameTable docs identify the frame-table loader; overlay constructors store its result at `+0x140`. |
| `0x004d02f0` / `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | Existing docs identify the central resource-layout lookup API writing EPFTileContext-like output. |
| `0x004d15d0` / `sub_4D15D0` | `DestroyOwnedImageBlock` | Existing docs record overlay constructors/destructors storing and destroying the `+0x140` frame block. |
| `0x004b9980` / `sub_4B9980` | shared `RenderTileFrame` wrapper | `SurfacePaintHelpers` names the body `RenderTileFrame`; local disassembly shows it resolves the fifth argument through `g_pPaletteLib->GetPaletteByName`, then calls slot `dword_69B3E8` with source descriptor, source rect, destination rect, draw mode, palette, and flags. It is not fitting-room-owned despite old generated labels. |
| `0x0069b3e8` / `dword_69B3E8` | `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` | `SurfaceRenderCallbackTable`, `GrafPort::BlitSurface`, and `GrafPort::DrawTiledBackground` support this descriptive slot-2 name. |
| `word_66DA9C` | `g_mapTilePixelWidth` | Existing two-byte global and grouped global pages. |
| `word_66DAA0` | `g_mapTilePixelHeight` | Existing two-byte global and grouped global pages. |
| `0x004f4ac0` / `sub_4F4AC0` | MemoryMan-backed `operator delete` wrapper | Disassembly calls `GetMemoryMan` and a free helper; `g_pMemoryMan` docs identify this as the free wrapper family. |
| `0x00544ce0` / `sub_544CE0` | pane layer/visual cleanup, likely `Pane::RemoveFromLayer` or `Pane::ReleaseLayerState` | Pane cleanup docs and destructor pages use this as inherited pane cleanup. |
| `0x00544580` / `sub_544580` | ordinary `Pane::~Pane()` / base pane teardown | Pane vtable/core docs identify `0x00544580-0x00544687` as ordinary Pane teardown. |

## Owner And Source Placement

Keep `CANONICAL_OWNER:0000IZ` and `EMITTER_UIDS:0000IZ`. [UID:0000IZ][Effects](by-file/Effects.md) owns the `ScreenEffecter` / `PixelEffecter` / `OverlayEffecter` / filter / water / lake runtime hierarchy, and this class already emits through `auto-generated/NexusTK/render/Effects.cpp`.

Rejected or lower-ranked alternatives:

- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) is the base-class dependency, not the direct source emitter for this subclass.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is useful aggregate context, but exact class C++ belongs here.
- [UID:0000JR][GrafPort](by-file/GrafPort.md), [UID:0000OC][Surface](by-file/Surface.md), and [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md) are render dependencies only.
- Image/resource-layout docs own the loader/lookup/destroy helpers, not the motion policy, vtable route, or subclass destructor.
- No-owner/non-emitting is rejected: the class is source-authored, vtable-reachable, in a known runtime class family, has a valid Effects emitter route, and clears the active combined score/code gate.

## Open Questions And Best Current Resolution

- `+0x11c` palette/lookup string: `RenderTileFrame` treats `this+0x11c` as a palette-name pointer, but the constructor copies 16-wide-character strings to `+0x100` and `+0x120`; `+0x11c` lies at the tail of the first buffer. Use `m_paletteLookupKey` / `m_overlayLookupName` with an explicit overlap caveat. This is a confidence cap, not a reason to leave raw offsets.
- Constructor base arguments `[0x10]/[0x14]`: definitely the two values passed after fixed pane type `1` to `OverlayEffecter`. Use `paneWidth`/`paneHeight` or `overlayWidth`/`overlayHeight` until caller/factory context proves original names.
- `+0x170`/`+0x172`: best current names are `m_moveRangeX` and `m_moveRangeY` from constructor grouping and generated sibling output, though current `OnPaint` does not read them.
- `0x0055a990` source name: `OnPaint()` is stronger than `UpdateAndRender` because the body is installed at adjusted Pane/GrafPort view slot `+0x44`; keep `UpdateAndRender` only as a behavior alias.
- Scalar deleting destructor: compiler-generated glue. Keep evidence and vtable route; do not emit as handwritten source.

## C++ Readiness

This page now carries first-draft C++ because the constructor, ordinary destructor, and `OnPaint` behavior are source-authored, have a stable owner/emitter, and have enough helper/field names for readable mid-2000s-style source. The draft intentionally uses descriptive field/helper names rather than raw offsets and does not include the compiler deleting destructor.

The draft still carries source-quality caveats:

- `m_scrollY2` is a placeholder for the dword at `+0xb4`; a later field-model pass may prefer `m_scrollY` for `+0xb4` and `m_offsetY` for `+0xac`.
- `m_paletteLookupKey` preserves the unresolved `+0x11c` overlap issue.
- `paneWidth`/`paneHeight`, `moveRangeX/Y`, and the direction enum names are best-current inferred source names.

These caveats keep the page below final-audit scores, but they no longer justify blank C++.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page now incorporates exact PE ranges, method sizes, padding, jump-table addresses, four-view vtable layout, adjusted paint slot, adjustor thunks, helper names, constructor parameters, field/subobject directions, resource lifetime, render callback route, owner/source placement, rejected alternatives, no-code policy for compiler destructor, and first-draft C++ for the eligible handwritten methods. |
| Confidence `90` | Confidence is strong for the class/source route and method behavior because local binary evidence, sibling effecter docs, vtable data, runtime aggregate docs, helper docs, and render callback docs align. Confidence remains below final-source quality due to the unresolved `+0x11c` palette/key layout and original spellings for constructor/motion fields. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)

## Changes

- 2026-06-20 B001 Rule 26 source-quality incorporation:
  - Before: `84/88`, blank C++, high-level `UpdateAndRender` wording, raw helper names in evidence, stale final-source-gate language, and no detailed parameter/field/source-quality resolution.
  - After: `88/90`, owner/emitter still [UID:0000IZ][Effects](by-file/Effects.md), first-draft constructor/destructor/`OnPaint` C++ populated, scalar deleting destructor retained as compiler-generated no-source glue, and raw helpers replaced with source-facing names.
  - Incorporated evidence: exact half-open ranges and method sizes; `0x0055aae4-0x0055aaf4` switch table; constructor/destructor padding spans; four-view vtable bases `0x00623898`, `0x006238bc`, `0x00623908`, and `0x00623938`; paint slot `0x00623900 -> 0x0055a990`; scalar destructor adjustors at `0x0055bab8`, `0x0055bac0`, and `0x0055bacb`; direction-mode update behavior; constructor stack-argument roles; field/subobject offsets through `+0x188`; `LoadImageFrameTable`, `ResourceLayoutTable::LookupLayoutEntry`, `DestroyOwnedImageBlock`, `RenderTileFrame`, `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`, and map-tile dimension naming; source-placement alternatives; and the remaining source-spelling/layout caveats.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: frame-table resource evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to EPF frame-table loading.
- 2026-06-05:
  - Before: scored `72/82`, reconstructability and parent metadata were blank, and the page only had high-level method-range notes.
  - After: scored `84/88`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and kept reconstruction C++ blank.
  - Why: live IDA evidence confirmed exact modeled function ranges, constructor base call and four-view vtable stores, frame-table load/free helpers, two copied 16-wide-character names, direction-mode switch behavior, render flow through `sub_4B9980`, scalar-delete jump-strip refs, exact vtable slot targets, and the remaining lack of direct constructor/non-scalar-destructor callers.
- Before: completion/confidence metadata were `0/0` while the page already documented role, method ranges, ownership, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: update/render direction-mode behavior, constructor, destructor, scalar deleting destructor, source-family, and vtable family are documented; completion remains below high because exact fields, callers, and reconstructed C++ are not yet exhaustive.
