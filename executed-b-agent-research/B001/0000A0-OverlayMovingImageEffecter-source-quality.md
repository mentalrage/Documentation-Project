** TARGET-REPORT-UID:0000A0 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000A0 OverlayMovingImageEffecter Source-Quality Research

Assignment: `B001-goal2-overlay-moving-image-effecter-source-quality-0000A0-20260619`  
Agent: `Agent-B001`  
Target: `[UID:0000A0] source-3/project-documentation/by-class/OverlayMovingImageEffecter.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0000A0-OverlayMovingImageEffecter-source-quality.md`  
Current target score: `84/88`

## Final Recommendation

Raise the target to `88/90`, keep it reconstructable, keep the owner/emitter route through [UID:0000IZ][Effects](by-file/Effects.md), and populate first-draft C++ for the source-authored constructor, ordinary destructor, and paint/update virtual.

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000IZ
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000IZ
```

The current class/page name `OverlayMovingImageEffecter` is supported by decorated vtable names, sibling effecter docs, and the runtime cluster. Do not split the four modeled methods into separate by-memory children during the first implementation pass; the class target is the right emission surface for the constructor/destructor/paint body. The scalar deleting destructor should stay documented as compiler-generated vtable glue and should not be emitted as handwritten C++.

Best source-facing method names:

```text
0x0055a990-0x0055aae3  OverlayMovingImageEffecter::OnPaint()
                       behavior alias: UpdateAndRender / moving overlay update paint body
0x0055ab00-0x0055ac4a  OverlayMovingImageEffecter::OverlayMovingImageEffecter(...)
0x0055ac50-0x0055acf7  OverlayMovingImageEffecter::~OverlayMovingImageEffecter()
0x0055bef0-0x0055bfc3  compiler-generated scalar deleting destructor
```

`OnPaint()` is the best final source-facing virtual name because the body is installed in the adjusted `+0x04` Pane/GrafPort view at slot `+0x44`, the same source-facing route accepted for `WaterFilterEffecter::OnPaint()` at [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md). Keep `UpdateAndRender` in prose as a useful behavior label because this override advances the scroll state before drawing.

## Report-Only Compliance

No target by-class docs, support by-* docs, generated reports, IDA database state, generated source, or coverage files were edited. This report is the only intended changed file for this assignment.

Previously completed B001 reports, including `0002NQ`, `00013I`, `00016R`, `00019L`, `0001C1`, `000250`, and `00022H`, were not modified or moved. I did not use or coordinate with A/C agents.

## Evidence Checked

Primary target and owner docs:

- `source-3/project-documentation/by-class/OverlayMovingImageEffecter.md`
- `source-3/project-documentation/by-file/Effects.md`
- `source-3/project-documentation/auto-generated/NexusTK/render/Effects.cpp`
- `source-3/project-documentation/by-class/-coverage-report.md`
- `source-3/project-documentation/auto-generated/-ag-class-coverage.md`

Sibling/base/runtime docs:

- `by-class/OverlayEffecter.md`
- `by-class/OverlayImageEffecter.md`
- `by-class/OverlayFrameImageEffecter.md`
- `by-class/OverlayImageOnPointEffecter.md`
- `by-class/WaterFilterEffecter.md`
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`
- `by-memory/0x00623480-0x00623d58.ScreenEffecterReadOnlyData.md`

Helper/global support docs:

- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-item/LoadImageFrameTable_004D0F50.md`
- `by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md`
- `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`
- `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`
- `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`
- `by-class/GrafPort.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-global/g_pEPFLib.md`
- `by-global/MapTilePixelDimensions.md`
- `by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md`
- `by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md`

Generated/source leads:

- `source-3/simroot_v2/class_OverlayMovingImageEffecter.cpp`
- `source-3/simroot_v2/class_OverlayEffecter.cpp`
- `source-3/simroot_v2/class_OverlayImageEffecter.cpp`
- `source-3/simroot_v2/class_OverlayFrameImageEffecter.cpp`
- `source-3/simroot_v2/class_OverlayImageOnPointEffecter.cpp`
- `source-3/simroot_v2/class_WaterFilterEffecter.cpp`

Local binary evidence:

- Parsed PE sections from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Disassembled the four target bodies, the destructor adjustor strip, `0x004b9980`, `0x00457a60`, `_wcscpy_s` at `0x005cd657`, `operator delete` wrapper `0x004f4ac0`, and the no-op guard stubs around `0x0041b6a0`.
- Scanned for direct rel32/branch routes to target function starts and for absolute vtable pointer literals.
- Dumped boundary bytes around all method starts/ends and vtable bytes around `0x00623894-0x0062393c`.
- Converted relevant sizes and offsets: `0x153=339`, `0x14a=330`, `0xa7=167`, `0xd3=211`, `0x20=32`, `0x18c=396`, `0x140=320`, `0x144=324`, `0x150=336`, `0x16c=364`, `0x16e=366`, `0x170=368`, `0x172=370`, `0x174=372`, `0x178=376`, `0x17c=380`, `0x180=384`, `0x184=388`, `0x188=392`, `0xa4=164`, and `0xa8=168`.

## Exact Range And Boundary Findings

The four target ranges in the current doc are correct as half-open ranges:

| Range | Size | Role | Boundary notes |
| --- | ---: | --- | --- |
| `0x0055a990-0x0055aae3` | `0x153` / 339 bytes | `OnPaint()` / update-and-render body | Preceded by `0xcc` padding at `0x0055a987-0x0055a990`. Ends with `ret` at `0x0055aae2`; followed by a 4-entry switch jump table at `0x0055aae4-0x0055aaf4`, then `0xcc` padding to the constructor at `0x0055ab00`. |
| `0x0055ab00-0x0055ac4a` | `0x14a` / 330 bytes | Constructor | Starts after the update jump-table padding. Ends with `ret 0x20`; `0x0055ac4a-0x0055ac50` is six `0xcc` bytes. |
| `0x0055ac50-0x0055acf7` | `0xa7` / 167 bytes | Ordinary destructor | Ends with `ret` at `0x0055acf6`; `0x0055acf7-0x0055ad00` is `0xcc` alignment before `FilterEffecter`. |
| `0x0055bef0-0x0055bfc3` | `0xd3` / 211 bytes | Scalar deleting destructor | Preceded by `0x0055bee3-0x0055bef0` padding after the prior scalar destructor; ends with `ret 4` at `0x0055bfc0-0x0055bfc2`; `0x0055bfc4-0x0055bfd0` is padding before `ScreenEffecter` scalar deleting destructor. |

The update switch table is concrete data, not a separate source function:

```text
0x0055aae4 -> 0x0055a9ad  mode 1
0x0055aae8 -> 0x0055a9e7  mode 2
0x0055aaec -> 0x0055aa37  mode 3
0x0055aaf0 -> 0x0055aa6d  mode 4
```

## Vtable And Reachability Findings

The class has the same four-view effecter shape as `OverlayEffecter` and the other pane-backed effecter classes:

| View | Address | Evidence |
| --- | --- | --- |
| RTTI/COL pointer before primary | `0x00623894 -> 0x0064f3c8` | Decorated RTTI/vtable island evidence. |
| Primary view | `0x00623898` | Constructor writes at `0x0055ab44`; destructor writes at `0x0055ac7c`; scalar destructor writes at `0x0055bf1c`. |
| `+0x04` Pane/GrafPort view | `0x006238bc` | Constructor writes at `0x0055ab4a`; destructor writes at `0x0055ac82`; scalar destructor writes at `0x0055bf22`. The paint/update slot is `0x00623900 -> 0x0055a990`. |
| `+0xa4` view | `0x00623908` | Constructor writes at `0x0055ab51`; destructor writes at `0x0055ac89`; scalar destructor writes at `0x0055bf29`. |
| `+0xa8` view | `0x00623938` | Constructor writes at `0x0055ab5b`; destructor writes at `0x0055ac93`; scalar destructor writes at `0x0055bf33`. |

Important vtable entries from the local PE scan:

```text
0x00623898 -> 0x0055c1b0  shared boolean virtual stub
0x0062389c -> 0x0055c1b0  shared boolean virtual stub
0x006238a0 -> 0x0055c1c0  shared boolean virtual stub
0x006238a4 -> 0x0055c1d0  ScreenEffecter completion query
0x006238b0 -> 0x0055bef0  scalar deleting destructor
0x006238bc -> 0x0055bab8  adjusted scalar dtor thunk, subtract this by 4
0x00623900 -> 0x0055a990  adjusted Pane/GrafPort paint slot +0x44
0x00623908 -> 0x0055bac0  adjusted scalar dtor thunk, subtract this by 0xa4
0x00623938 -> 0x0055bacb  adjusted scalar dtor thunk, subtract this by 0xa8
```

The destructor adjustor strip around `0x0055ba22` confirms this class's secondary-view routes:

```text
0x0055bab8: sub ecx, 4;    jmp 0x0055bef0
0x0055bac0: sub ecx, 0xa4; jmp 0x0055bef0
0x0055bacb: sub ecx, 0xa8; jmp 0x0055bef0
```

Direct ordinary calls to the constructor/destructor/update starts were not found in the PE scan. That is expected for this runtime effecter family: constructor starts are normally reached through factory paths that may be raw/callsite-specific, paint/update is vtable-owned, and scalar deleting destructors are vtable/thunk-owned. The only direct branch/call routes into `0x0055bef0` are the three adjustor jumps above. Literal function pointer scans found `0x0055a990` at `0x00623900` and `0x0055bef0` at `0x006238b0`.

## Behavior And Field Inference

### Paint/update body

`0x0055a990` reads a signed word at `this+0x16e`, subtracts one, and dispatches modes `1..4`. All modes then call the shared render wrapper at `0x004b9980`.

Best direction constants:

```cpp
enum OverlayMoveDirection {
    kOverlayMoveRight = 1,
    kOverlayMoveLeft = 2,
    kOverlayMoveDown = 3,
    kOverlayMoveUp = 4
};
```

The exact original enum names are not recoverable from current evidence. The directional labels are inferred from the sign of the scroll update and whether the code compares against `g_mapTilePixelWidth` or `g_mapTilePixelHeight`. If implementation prefers axis-neutral names, use `kOverlayMovePositiveX`, `kOverlayMoveNegativeX`, `kOverlayMovePositiveY`, and `kOverlayMoveNegativeY`.

Observed update logic:

- Mode `1`: adds `m_stepPixels` (`this+0x16c`) to horizontal scroll state at `this+0xb0`; wraps to `this+0x180` when the value reaches `this+0x178 + this+0x180`; writes the derived draw/right boundary at `this+0x4c`.
- Mode `2`: subtracts `m_stepPixels` from horizontal scroll state at `this+0xb0`; wraps to `this+0x178` when `(short)this+0xf8 + scrollX == g_mapTilePixelWidth`; writes the derived draw/right boundary at `this+0x4c`.
- Mode `3`: adds `m_stepPixels` to vertical scroll state at `this+0xac`; wraps to `this+0x184` when the value equals `this+0x17c`; writes the derived draw/bottom boundary at `this+0x50` using `g_mapTilePixelHeight`.
- Mode `4`: subtracts `m_stepPixels` from vertical scroll state at `this+0xac`; wraps to `this+0x17c` when `(short)this+0xfa + scrollY == g_mapTilePixelHeight`; writes the derived draw/bottom boundary at `this+0x50`.
- Any non-`1..4` mode skips motion adjustment and still renders the current frame.

The two globals are already documented as `g_mapTilePixelWidth` (`word_66DA9C`, initial `48`) and `g_mapTilePixelHeight` (`word_66DAA0`, initial `48`) under [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md). This target should not use raw `word_66DA9C` / `word_66DAA0`.

### Constructor body

`0x0055ab00` takes eight explicit stack arguments and returns with `ret 0x20`:

| Stack arg | Best source-facing role | Evidence |
| --- | --- | --- |
| `[ebp+0x08]` | `imageName` / frame-table resource name | Passed to `LoadImageFrameTable(g_pEPFLib, imageName, 0)`, copied to `this+0x100`, and used as the `ResourceLayoutTable::LookupLayoutEntry` name. |
| `[ebp+0x0c]` | `paletteName` / overlay secondary name | Copied to `this+0x120` with `_wcscpy_s(..., 0x10, ...)`. Current renderer uses a nearby key at `this+0x11c`, so the exact field relationship needs a final source-layout check. |
| `[ebp+0x10]` | `paneWidth` / `overlayX` / base argument 1 | Passed to `OverlayEffecter(1, arg10, arg14)`. Generated source calls these `imageWidth`/`imageHeight`, while `OverlayEffecter` generated source calls them `overlayX`/`overlayY`. Best neutral implementation name is `paneWidth`/`paneHeight` or `overlayWidth`/`overlayHeight` until caller context proves original spelling. |
| `[ebp+0x14]` | `paneHeight` / `overlayY` / base argument 2 | Same base-constructor evidence as above. |
| `[ebp+0x18]` | `moveRangeY` / secondary motion parameter | Stored as word at `this+0x172`; not read by `OnPaint`, so final spelling is inferred from generated sibling output and constructor grouping only. |
| `[ebp+0x1c]` | `moveRangeX` / secondary motion parameter | Stored as word at `this+0x170`; not read by `OnPaint`, so final spelling is inferred. |
| `[ebp+0x20]` | `stepPixels` | Stored at `this+0x16c`; directly added/subtracted in every motion case. |
| `[ebp+0x24]` | `directionMode` | Stored at `this+0x16e`; drives the `1..4` switch. The constructor also applies this value as an initial X/clip offset, so the final source field should preserve a note that it is used both as mode and initial offset in the binary. |

Field and subobject layout direction:

| Offset | Best name / type direction | Evidence |
| --- | --- | --- |
| `+0x100` | `wchar_t m_imageName[16]` | `_wcscpy_s(dest=this+0x100, size=0x10, imageName)`. |
| `+0x120` | `wchar_t m_overlayName[16]` / `m_paletteName[16]` | `_wcscpy_s(dest=this+0x120, size=0x10, arg0c)`. |
| `+0x11c` | `m_paletteLookupKey` / short overlay lookup string | `OnPaint` passes `this+0x11c` to `RenderTileFrame`, whose fifth argument is passed to `g_pPaletteLib->GetPaletteByName`. This offset overlaps the tail of the `+0x100` wide buffer if the buffer is exactly `wchar_t[16]`; see open question below. |
| `+0x140` | `m_frameRecord` start / first dword `m_frameBlock` | Constructor stores `LoadImageFrameTable` result here; destructor/scalar destructor pass `[this+0x140]` to `DestroyOwnedImageBlock`; renderer passes `this+0x140` as the source frame/tile descriptor. |
| `+0x144` | embedded `EPFTileContext` or frame-record context inside `m_frameRecord` | Constructor calls the documented EPFTileContext initializer at this address; lookup writes layout fields into the same object. |
| `+0x150` | frame-record source rect/view passed to `RenderTileFrame` | Renderer passes `this+0x150` as its second explicit argument. This is consistent with a source descriptor at `+0x140` whose source rectangle begins at an internal offset. |
| `+0x16c` | `short m_stepPixels` | Used as signed movement delta in all four cases. |
| `+0x16e` | `short m_directionMode` | Switch input and constructor initial offset. |
| `+0x170` | `short m_moveRangeX` / motion parameter | Constructor stores arg `0x1c`; not read in current paint method. |
| `+0x172` | `short m_moveRangeY` / motion parameter | Constructor stores arg `0x18`; not read in current paint method. |
| `+0x174..+0x183` | saved draw/clip rectangle or wrap state copied from `+0x48..+0x57` | Constructor copies a 16-byte block from `this+0x48` through `movups`; update uses the component dwords at `+0x178`, `+0x17c`, and `+0x180` as wrap/boundary values. |
| `+0x184` | saved vertical reset / old `+0xb4` | Constructor copies old `this+0xb4`; mode `3` uses it as the reset value. |
| `+0x188` | saved horizontal reset / old `+0xb0` | Constructor copies old `this+0xb0`; not read in the current `OnPaint` body, but it completes the saved scroll pair. |
| `+0xf9` | active/visible byte | Constructor writes `1`, matching sibling overlay constructors. |

The constructor initializes `+0x144`, stores the image block at `+0x140`, copies names, resolves frame layout through `ResourceLayoutTable::LookupLayoutEntry`, stores motion parameters, snapshots draw/clip/scroll state, marks active, then applies the initial `stepPixels` and `directionMode` offsets to scroll/clip state.

### Destructor and scalar deleting destructor

The ordinary destructor and scalar deleting destructor duplicate the expected cleanup sequence:

1. Reinstall the most-derived `OverlayMovingImageEffecter` vtable views.
2. Call `DestroyOwnedImageBlock(g_pEPFLib, this->m_frameRecord.imageBlock)` using `[this+0x140]`.
3. Reset all four views to `OverlayEffecter`.
4. Run pane/overlay cleanup on the `+0x04` Pane/GrafPort view through `0x00544ce0` and `0x00544580` style helpers.
5. Reset primary view to `ScreenEffecter`.
6. Only the scalar deleting destructor checks deletion flags and optionally frees storage through the MemoryMan-backed `operator delete` wrapper at `0x004f4ac0`; if bit `4` is also set it calls the no-op guard/vector-delete stub `0x0041b6a0` with object size `0x18c` / 396 bytes.

The scalar deleting destructor is compiler-generated. Its existence is required for vtable documentation, but formal source C++ should emit only the ordinary destructor body.

## Helper Name Resolution

Use these names in target/support updates instead of raw helper labels:

| Address / raw label | Recommended documentation name | Evidence |
| --- | --- | --- |
| `sub_457A60` / `0x00457a60` | `EPFTileContext` initializer, or `FrameDrawRecord::InitTileContext` when discussing the frame-record subobject | The EPFTileContext page documents a 0x28-byte initializer that zeroes pointers/stride/rect/mask fields. Constructor calls it on `this+0x144`. |
| `sub_4D0F50` / `0x004d0f50` | `LoadImageFrameTable` | Existing ImageFrameTable docs identify the 12-byte header plus 24-byte records loader; overlay constructors store its result at `+0x140`. |
| `sub_4D02F0` / `0x004d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | Existing doc identifies the central lookup API writing `EPFTileContext`-like output. |
| `sub_4D15D0` / `0x004d15d0` | `DestroyOwnedImageBlock` | Existing doc records overlay constructors/destructors storing/destroying the `+0x140` frame block. |
| `sub_4B9980` / `0x004b9980` | `RenderTileFrame` shared render wrapper | `SurfacePaintHelpers` already names the body `RenderTileFrame`; local disassembly shows it resolves the fifth argument through `g_pPaletteLib->GetPaletteByName`, then calls `dword_69B3E8` with source descriptor, source rect, destination rect, draw mode, palette, and flags. It has 311 callers and is not fitting-room-owned despite old generated labels. |
| `dword_69B3E8` | `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` | `SurfaceRenderCallbackTable`, `GrafPort::BlitSurface`, and `GrafPort::DrawTiledBackground` all support this descriptive slot-2 name. |
| `word_66DA9C` | `g_mapTilePixelWidth` | Existing two-byte global page and grouped by-global page. |
| `word_66DAA0` | `g_mapTilePixelHeight` | Existing two-byte global page and grouped by-global page. |
| `sub_4F4AC0` | MemoryMan-backed `operator delete` wrapper | Local disassembly calls `GetMemoryMan` then a free helper; `g_pMemoryMan` docs already identify `0x004f4aa0`/`0x004f4ac0` as allocation/free wrappers. |
| `sub_544CE0` | Pane layer/visual cleanup, likely `Pane::RemoveFromLayer` or `Pane::ReleaseLayerState` | Pane cleanup docs and destructor pages use this as inherited pane cleanup. |
| `sub_544580` | ordinary `Pane::~Pane()` / base pane teardown | Pane vtable/core docs identify `0x00544580-0x00544687` as ordinary Pane teardown. |

## Owner And Source-Placement Alternatives

Accepted owner/emitter:

- [UID:0000IZ][Effects](by-file/Effects.md), source route `NexusTK/render/Effects.cpp`. This file already owns the ScreenEffecter/PixelEffecter/OverlayEffecter/filter/water/lake runtime family, the target already emits through `auto-generated/NexusTK/render/Effects.cpp`, and sibling overlay effecters use the same owner.

Rejected or lower-ranked alternatives:

- `OverlayEffecter` direct owner: rejected as the source emitter. It is the base class and should be referenced for inherited constructor/destructor behavior, but this class has its own vtables, constructor, motion fields, and paint override.
- `ScreenEffecterRuntimeCluster`: useful aggregate/context only. The exact class page is a better emitter, and the aggregate should not duplicate child class C++.
- `GrafPort` / `Surface` / `SurfacePaintHelpers`: rejected as target owner. `RenderTileFrame` and `dword_69B3E8` are render dependencies only; the motion fields, vtable slot, frame-block ownership, and destructor are all effecter-owned.
- `ImageFrameTable` / `ResourceLayoutTable`: rejected as owner. They own loader/lookup/destroy helpers, not the class policy or vtable slot.
- No-owner/non-emitting: rejected. The class is source-authored, vtable-reachable, in a known class family, has a valid Effects emitter route, and clears the active combined-score/emitter code gate.
- Split child rows: not needed for this assignment. The class page can accurately carry the method inventory and first-draft C++. If later memory-level exact children are created for consistency with WaterFilter/YFlip, the recommended split would be `OnPaint` as an exact by-memory child and the scalar deleting destructor as a no-code compiler child, but that is not required to implement the accepted source-quality update.

## Open Questions And Best Current Resolution

1. Exact spelling and layout of the `+0x11c` palette/lookup string:
   - Evidence checked: target body, sibling generated overlay classes, `_wcscpy_s` disassembly at `0x005cd657`, `RenderTileFrame` disassembly, `SurfacePaintHelpers`, `SurfaceRenderCallbackTable`.
   - Result: `RenderTileFrame` treats `this+0x11c` as a palette-name pointer, but the constructor copies `wchar_t[16]` to `+0x100` and `+0x120`. `+0x11c` lies at the tail of the first 16-wide-character buffer. This is real source-layout ambiguity, not a reason to leave raw names. Best direction is to name the consumed field `m_paletteLookupKey` / `m_overlayLookupName` with a note that it may be an overlapping short key inside the first resource-name buffer. This should cap confidence below final-audit range but should not block first-draft C++.
2. Constructor base arguments `[0x10]/[0x14]`:
   - Evidence checked: moving constructor, `OverlayEffecter` generated/source docs, sibling overlay constructors.
   - Result: They are definitely the two arguments after fixed pane type `1` to `OverlayEffecter`. Generated names conflict between `imageWidth/imageHeight` and `overlayX/overlayY`. Use neutral `paneWidth`/`paneHeight` or `overlayWidth`/`overlayHeight` in documentation until caller sites or factory names prove original spelling.
3. `+0x170`/`+0x172` names:
   - Evidence checked: constructor stores and paint body reads. No reads in the current paint method.
   - Result: Best current names are `m_moveRangeX` and `m_moveRangeY` from constructor grouping and generated output. Mark as inferred; do not leave as raw offsets.
4. Source method name for `0x0055a990`:
   - Evidence checked: vtable slot placement, WaterFilterEffecter `OnPaint` precedent, generated names, behavior.
   - Result: `OnPaint()` is stronger source-facing name; `UpdateAndRender` remains behavior alias.
5. Scalar deleting destructor:
   - Evidence checked: vtable slot, adjustor strip, body disassembly, delete helper, object size.
   - Result: compiler-generated glue. Keep in evidence and method table, but do not emit hand-authored C++.

## First-Draft C++ Recommendation

Populate the target `RECONSTRUCTION_CPP` block after supervisor acceptance. This is intentionally first-draft source-style code: it avoids synthetic reserved fields, modern fixed-width types, generated helper names, and explicit compiler deleting-destructor code. Field names are descriptive and should be paired with the offset table above in the prose.

```cpp
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
    m_frameRecord.imageBlock = LoadImageFrameTable(g_pEPFLib, imageName, 0);

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
```

Implementation notes for the supervisor callback:

- The `m_scrollY2` name in the constructor draft is only a placeholder for the dword at `+0xb4`, because current docs distinguish both `+0xac` and `+0xb4` vertical/scroll-like fields. If the accepted local field model prefers `m_scrollY` for `+0xb4` and `m_offsetY` for `+0xac`, adjust names consistently.
- The formal C++ block should not include `ScalarDeletingDestructor`. The page should describe it in prose as compiler-generated.
- If the implementation pass is allowed to touch sibling support docs first, consider adding or accepting a small `OverlayMovingFrameRecord` / `FrameDrawRecord` note for the `+0x140` shape. The draft above uses `m_frameRecord.imageBlock`, `m_frameRecord.tileContext`, and `m_frameRecord.sourceRect` to avoid raw offset prose in C++.

## Recommended Target Edits

In `by-class/OverlayMovingImageEffecter.md`:

1. Change metadata to `88/90`, owner/emitter unchanged.
2. Update the method table to use `OnPaint` / behavior alias `UpdateAndRender`, constructor, ordinary destructor, and compiler scalar deleting destructor.
3. Add the exact range/boundary notes, including the switch table at `0x0055aae4-0x0055aaf4`, padding spans, and method sizes.
4. Replace raw helper names:
   - `sub_457A60` -> `EPFTileContext` initializer / frame-record tile-context init.
   - `sub_4D0F50` -> `LoadImageFrameTable`.
   - `sub_4D02F0` -> `ResourceLayoutTable::LookupLayoutEntry`.
   - `sub_4D15D0` -> `DestroyOwnedImageBlock`.
   - `sub_4B9980` -> shared `RenderTileFrame` wrapper from [UID:000165].
   - `dword_67A744` -> `g_pEPFLib`.
   - `dword_69B3E8` -> `g_pfnBlitSprite` / `SurfaceSpriteBlitProc` when explaining the render path.
   - `word_66DA9C` / `word_66DAA0` -> `g_mapTilePixelWidth` / `g_mapTilePixelHeight`.
   - `sub_4F4AC0` -> MemoryMan-backed `operator delete` wrapper.
   - `sub_544CE0` / `sub_544580` -> pane cleanup / ordinary `Pane::~Pane`.
5. Add a field table covering `+0x100`, `+0x120`, `+0x11c`, `+0x140`, `+0x144`, `+0x150`, `+0x16c`, `+0x16e`, `+0x170`, `+0x172`, `+0x174`, `+0x178`, `+0x17c`, `+0x180`, `+0x184`, and `+0x188`.
6. Add the constructor parameter table and explicitly mark `paneWidth`/`paneHeight`, `moveRangeX/Y`, and `m_paletteLookupKey` as best current source-facing names with remaining original-spelling uncertainty.
7. Add the first-draft C++ block above, or an accepted version of it with local field names adjusted to the final support-doc model.
8. Add a score rationale explaining why the page rises above the active code gate but remains below final-audit scores due to `+0x11c` layout and constructor parameter spelling.

## Recommended Support-Doc Updates

These should be part of the implementation checklist if the supervisor accepts the report direction:

- `by-file/Effects.md`: update the `OverlayMovingImageEffecter` row to half-open ranges `0x0055a990-0x0055acf7` and `0x0055bef0-0x0055bfc3`; add that B001 resolves the paint body as `OnPaint()` with source-ready first-draft C++ and compiler-generated scalar destructor handling.
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`: add the exact `OverlayMovingImageEffecter` range/boundary summary, `0x00623900 -> 0x0055a990` adjusted paint slot, and the render helper resolution to `RenderTileFrame`.
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`: add slot-level detail for `OverlayMovingImageEffecter` that the `+0x04` Pane/GrafPort view slot `+0x44` at `0x00623900` is `OnPaint`, and the three secondary scalar-deleting destructor adjustors subtract `4`, `0xa4`, and `0xa8`.
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`: add the same `0x00623900 -> OnPaint` slot note and keep vtable data ownership under read-only data, not the class emitter.
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`: optionally add `OverlayMovingImageEffecter::OnPaint` as one of the many `RenderTileFrame` consumers; no owner change.
- `by-global/SurfaceRenderCallbackTable.md`: optionally add the local `0x004b9980` disassembly detail that the fifth argument is palette-name input and the sixth is forwarded flags/options, strengthening slot-2 typing.
- `by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md`: already records the moving effecter `+0x140` destroy path; no required change unless adding the `FrameDrawRecord` wording.
- `by-class/OverlayEffecter.md`: optionally add a one-line support note that `OverlayMovingImageEffecter::OnPaint` follows the same adjusted Pane/GrafPort paint-slot pattern as `WaterFilterEffecter::OnPaint`.

## Exact Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md`. This is a by-class target and I found no direct by-memory coverage row for [UID:0000A0] that should be changed in this report-only pass.

Pending replacement row for `source-3/project-documentation/by-class/-coverage-report.md`:

```text
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) : reconstructable : 88% : strong : B001 source-quality pass resolves this as an Effects-owned OverlayEffecter subclass with exact PE ranges, the four-view vtable layout, `OnPaint`/`UpdateAndRender` direction-mode switch, `LoadImageFrameTable`/`DestroyOwnedImageBlock` frame-table ownership, `ResourceLayoutTable::LookupLayoutEntry` plus EPFTileContext setup, shared `RenderTileFrame`/`dword_69B3E8` renderer routing, compiler-generated scalar deleting destructor policy, and first-draft constructor/destructor/paint C++ readiness; remaining caveats are exact original spelling/layout for the `+0x11c` palette lookup key and constructor motion/base-argument names.
```

Pending autogen class coverage expectation after implementation/validator:

```text
| [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md) | emits | `0000IZ` | `0000IZ` |  | yes | `auto-generated/NexusTK/render/Effects.cpp` | `by-class/OverlayMovingImageEffecter.md` |  |
```

The exact autogen row may be regenerated by `validator.py --mode file --apply`; do not hand-edit generated coverage unless the supervisor explicitly requests it.

## Validation Commands Needed After Implementation

For the accepted implementation pass, run:

> Executable block R001 was removed from this report and preserved verbatim in [0000A0-OverlayMovingImageEffecter-source-quality-removed.md](0000A0-OverlayMovingImageEffecter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then inspect for raw names or stale code-gate language:

> Executable block R002 was removed from this report and preserved verbatim in [0000A0-OverlayMovingImageEffecter-source-quality-removed.md](0000A0-OverlayMovingImageEffecter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited in the implementation callback, run validator file mode for each edited support doc as well. A full/documented scan is not needed unless the supervisor wants regenerated project-level references beyond the touched files.

## IDA Rename, Type, And Comment Recommendations

Function labels:

- `sub_55A990` -> `OverlayMovingImageEffecter_OnPaint` or `OverlayMovingImageEffecter_UpdateAndRender_OnPaint` (high confidence for class/method route; medium-high for final spelling).
- `sub_55AB00` -> `OverlayMovingImageEffecter_ctor` (high).
- `sub_55AC50` -> `OverlayMovingImageEffecter_dtor` (high).
- `sub_55BEF0` -> `OverlayMovingImageEffecter_scalar_deleting_destructor` (high; mark compiler-generated).
- `0x0055bab8` -> `OverlayMovingImageEffecter_scalar_dtor_adjustor_4` (high).
- `0x0055bac0` -> `OverlayMovingImageEffecter_scalar_dtor_adjustor_A4` (high).
- `0x0055bacb` -> `OverlayMovingImageEffecter_scalar_dtor_adjustor_A8` (high).
- `0x004b9980` -> `RenderTileFrame` / `GrafPort_RenderTileFrame` only after the shared helper's owner policy is reviewed; do not use `FittingRoomDownloadControlPane::RenderTileFrame` as the final source owner (medium-high).

Vtable labels:

- `0x00623898` -> `OverlayMovingImageEffecter_vftable_primary`.
- `0x006238bc` -> `OverlayMovingImageEffecter_vftable_pane`.
- `0x00623908` -> `OverlayMovingImageEffecter_vftable_a4`.
- `0x00623938` -> `OverlayMovingImageEffecter_vftable_a8`.
- Add a repeatable comment at `0x00623900`: `Pane/GrafPort +0x44 paint slot -> OverlayMovingImageEffecter::OnPaint`.

Type/field recommendations:

- Create or refine a frame-record type at complete offset `+0x140` with first dword `imageBlock`, embedded `EPFTileContext` beginning at `+0x144`, and source rectangle/record view beginning at `+0x150`.
- `+0x100`: `wchar_t imageName[16]`.
- `+0x120`: `wchar_t overlayName[16]` / `paletteName[16]` (medium).
- `+0x11c`: comment as `palette lookup string/key passed to RenderTileFrame; overlaps tail of imageName buffer under current field model` until source layout is finalized (medium).
- `+0x16c`: `short stepPixels` (high).
- `+0x16e`: `short directionMode` (high for role, medium for exact spelling).
- `+0x170`: `short moveRangeX` (medium).
- `+0x172`: `short moveRangeY` (medium).
- `+0x174`: saved draw/clip/wrap state block copied from `+0x48` (high for copy, medium for field names).
- `+0x178`, `+0x17c`, `+0x180`, `+0x184`, `+0x188`: wrap/span/reset fields used by `OnPaint` (medium-high for behavior, medium for final names).

Decompiler comments:

- At `0x0055a9a6`: `switch(directionMode - 1), jump table at 0x0055aae4`.
- At `0x0055aadd`: `RenderTileFrame(&m_frameRecord, &m_frameRecord.sourceRect, &m_drawBounds, m_drawMode, m_paletteLookupKey, 0)`.
- At `0x0055ab65`: `initialize frame-record EPFTileContext subobject`.
- At `0x0055ab76`: `LoadImageFrameTable(g_pEPFLib, imageName, 0)`.
- At `0x0055abb7`: `ResourceLayoutTable::LookupLayoutEntry(imageName, 0, &frameRecord.tileContext)`.
- At `0x0055bf95`: `MemoryMan-backed operator delete path for scalar deleting destructor`.

## Changed Files

Created this report only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0000A0-OverlayMovingImageEffecter-source-quality.md
```

Leases used: none. This report is under the B001 research folder and no by-* implementation edits were made.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000A0-OverlayMovingImageEffecter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000A0"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000A0-OverlayMovingImageEffecter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000A0-OverlayMovingImageEffecter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000A0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
