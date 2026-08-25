** TARGET-REPORT-UID:0003UH **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0003UH] LivingObjectPaneUpdateScreenPosition Source-Quality Reanalysis

Agent: B008  
Assignment: `B008-goal2-livingobject-update-screen-position-source-quality-0003UH-20260619`  
Target: `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`  
Report-only output: `tools/leaser/Agents/Agent-B008/research/0003UH-LivingObjectPaneUpdateScreenPosition-source-quality.md`  
Date: 2026-06-19

## Report-Only Guard

This pass is a source-quality research report only. No `by-*` documentation file is edited by this report, and `by-memory/-coverage-report.md` is not edited. The implementation notes below are exact callback instructions for a later accepted implementation pass.

The governing files checked for this pass were:

- `tools/leaser/Agents/Supervisor.md`, including the report-only B-agent scope and coverage-owner rule.
- `E:\NTK\GhidraBridge\.codex\AGENTS.md`, including Rule 26: accepted report details must later be incorporated at full factual detail and must not be compressed into a shallow summary.
- `by-structure.md`, especially the source-quality and C++ emission gates.
- `inference_research.md`, especially evidence separation and field/helper naming standards.
- `proposed-source-tree.md`, especially `map/LivingObjectPane.cpp`, `map/MapPane.cpp`, `map/ObjectPane.cpp`, and `ui/UserPane.cpp` ownership guidance.

The current session did not have a live IDA MCP tool available, so the binary checks below are from the local NexusTK PE plus current IDA-backed project documentation. Historical generated material was treated only as search/indexing evidence, not as source authority.

## Executive Recommendation

Recommended source-facing function name and signature:

```cpp
void LivingObjectPane::UpdateScreenPosition();
```

Recommended metadata after incorporation:

```text
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 00007B
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00007B
```

Recommended source placement remains `map/LivingObjectPane.cpp`, owned and emitted by [UID:00007B] `LivingObjectPane`. The only direct caller is in the MapPane render path, but the callee receives the active local player pane through `MapPane+0x418` and mutates local-player/LivingObjectPane screen-position and hit-bound cache fields. MapPane owns the coordinate conversion helpers and map tile dimension globals; it does not own this method.

First-draft C++ should be emitted on the target page during implementation. This is not a no-route helper, not padding, not a compiler thunk, and not a UserPane virtual body. The exact body, half-open range, one direct caller, helper chain, globals, and cached-field writes are supported well enough for source-quality C++ with coordinate-order and original-field-spelling caveats documented.

## Evidence Checked

Target and local documentation checked:

- `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
- `by-class/LivingObjectPane.md`
- `by-file/LivingObjectPane.md`
- `by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md`
- `by-memory/0x005a2530-0x005b8395.UserPane.md`
- `by-class/UserPane.md`
- `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`
- `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
- `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md`
- `by-global/MapTilePixelDimensions.md`
- `by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`
- `by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md`

Local binary checked:

- PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Image base: `0x00400000`
- Relevant executable section: `.text`
- Disassembly method: local PE bytes decoded with Capstone and direct byte/rel32 scans.

Binary checks performed:

- Exact target half-open bytes and instruction decode for `0x005a88d0-0x005a89c9`.
- Predecessor and successor padding bytes around the target.
- Direct rel32 call scan to `0x005a88d0`.
- Absolute dword pointer scan to `0x005a88d0`.
- Local decode of callees `0x005374d0`, `0x00505130`, `0x00505080`, and `0x00505100`.
- Displacement scans for target-written and target-read fields: `+0x3ec4`, `+0x1340cc`, `+0x1340d0`, `+0x1340d8`, `+0x1340e8`, `+0x1340f8`, `+0x1c5`, and `+0x1c6`.
- Scoped validator baseline for the existing target page.

## Exact Range, Padding, And Function Status

The target is an ordinary function body at:

```text
0x005a88d0-0x005a89c9
```

The local decode starts with a standard frame setup:

```asm
0x005a88d0  push ebp
0x005a88d1  mov  ebp, esp
0x005a88d3  sub  esp, 0x14
0x005a88d6  push ebx
0x005a88d7  push esi
0x005a88d8  push edi
```

It ends with a normal epilogue and `ret`:

```asm
0x005a89bf  add  esp, 0x28
0x005a89c2  pop  edi
0x005a89c3  pop  esi
0x005a89c4  pop  ebx
0x005a89c5  mov  esp, ebp
0x005a89c7  pop  ebp
0x005a89c8  ret
```

The last instruction ends at `0x005a89c9`, so the target half-open range is exact.

Boundary proof:

- `0x005a8840-0x005a88cf` is the predecessor `UserPane::OnClipBounds` body documented in the UserPane support docs.
- The predecessor returns with `ret 8` at `0x005a88cc`, ending at `0x005a88cf`.
- Byte `0x005a88cf` is `0xcc` padding.
- Target starts immediately after that padding at `0x005a88d0`.
- Target ends at `0x005a89c9`.
- Bytes `0x005a89c9-0x005a89d0` are seven `0xcc` padding bytes.
- The next body starts at `0x005a89d0`.

This is a real function with an exact local frame and a reachable caller. It must not be merged into predecessor [UserPane clip-bounds] or successor body. It also must not be treated as no-function padding.

## Caller And Reachability

The direct call scan found exactly one direct rel32 call to the target:

```asm
0x00509550  cmp  byte ptr [ebx+0x3f0], 0
0x00509557  jne  0x0050a4c8
0x0050955d  mov  ecx, dword ptr [ebx+0x418]
0x00509563  call 0x005a88d0
```

This caller sits in [UID:00037V] `MapPaneRenderViewCore`, within the MapPane render path `0x005094b0-0x0050a4fd`. Existing UserPane constructor documentation identifies `MapPane+0x418` as the cached active/local pane pointer installed when the UserPane is constructed. Therefore the call is:

```cpp
mapPane->m_activeUserPaneOrLocalPane->UpdateScreenPosition();
```

The absolute dword pointer scan found no data-pointer hits to `0x005a88d0`. This does not reduce confidence, because the rel32 route is enough to prove reachability and source placement. It does reject a vtable-dispatch-only explanation for this target.

## Body Behavior

The target recalculates the local actor's cached screen center and two screen-space hit rectangles from:

- inherited map/world tile position,
- active MapPane map-to-screen conversion,
- facing direction,
- movement substep/interpolation frame,
- global tile pixel dimensions,
- global movement substep scale,
- and the local-player hit radius field.

Instruction-level behavior:

```asm
0x005a88d9  lea  eax, [ebp-0xc]
0x005a88de  mov  [ebp-4], ebx
0x005a88e2  call 0x005374d0
```

The method first calls `ObjectPane::GetMapPosition` with a two-int stack pair at `[ebp-0xc]`.

```asm
0x005a88e7  mov  ecx, [ebx+0x1340f8]
0x005a88f0  lea  eax, [ebp-0xc]
0x005a88f3  push eax
0x005a88f4  call 0x00505130
```

It then calls the MapPane map-to-screen coordinate helper with `this+0x1340f8` as `MapPane *m_mapPane`. The helper mutates the two-int coordinate pair in place.

```asm
0x005a88f9  movzx eax, byte ptr [ebx+0x1c5]
0x005a88fd  mov   ecx, [ebx+0x1340f8]
0x005a8909  call  0x00505080
0x005a890d  mov   ecx, [ebx+0x1340f8]
0x005a8918  call  0x00505100
```

It builds a facing-direction tile offset from `this+0x1c5`, then scales that offset from tile units into pixels.

```asm
0x005a891c  movsx esi, byte ptr [ebx+0x1c6]
0x005a8923  movsx edi, byte ptr [0x0066da96]
0x005a892a  imul  eax, [ebp-0x10]
0x005a8930  shl   edi, 2
0x005a8933  imul  esi, [ebp-0x14]
0x005a8938  idiv  edi
```

It uses signed `m_moveFrame`/walk-substep `this+0x1c6` and divisor `4 * g_movementSubstepScale` to interpolate along the pixel direction vector.

```asm
0x005a893c  movsx eax, word ptr [0x0066da9c]
0x005a8943  add   ebx, [ebp-8]
0x005a894b  sar   eax, 1
0x005a894d  add   ebx, eax
...
0x005a895d  movsx eax, word ptr [0x0066daa0]
0x005a8964  add   ecx, [ebp-0xc]
0x005a896d  sar   eax, 1
0x005a896f  lea   edx, [eax+ecx]
```

It adds half the tile pixel width and height to convert from a tile origin/top-left to a centered screen point. The width global is `g_mapTilePixelWidth` at `0x0066da9c`; the height global is `g_mapTilePixelHeight` at `0x0066daa0`.

```asm
0x005a8967  mov [edi+0x1340d0], ebx
0x005a897b  mov [edi+0x1340cc], edx
```

It caches the resulting local-player screen center:

- `this+0x1340d0`: cached screen X.
- `this+0x1340cc`: cached screen Y.

```asm
0x005a8972  mov ecx, [edi+0x3ec4]
...
0x005a8996  call 0x004b7c50
```

It initializes `RectBounds` at `this+0x1340d8` as a full symmetric screen hit/render bounds rectangle:

```text
left   = screenX - radius
top    = screenY - radius
right  = screenX + radius
bottom = screenY + radius
```

```asm
0x005a899b  mov ecx, [edi+0x3ec4]
...
0x005a89ba  call 0x004b7c50
```

It initializes `RectBounds` at `this+0x1340e8` as a lower-body/lower-half screen hit rectangle:

```text
left   = screenX - radius
top    = screenY
right  = screenX + radius
bottom = screenY + radius
```

The field `this+0x3ec4` is used as the symmetric radius/half-extent for both rectangles. Constructor-side evidence initializes it to `2 * g_mapTilePixelWidth`, and nearby clipping code also uses it as a radius-like extent. The original source spelling is not recovered, but the role is concrete.

## Helper And Global Evidence

`ObjectPane::GetMapPosition` at `0x005374d0`:

```asm
0x005374d0  mov edx, [ecx+0x100]
0x005374d6  mov ecx, [ecx+0x104]
0x005374df  mov [eax+4], edx
0x005374e2  mov [eax], ecx
0x005374e4  ret 4
```

This proves the target starts from inherited ObjectPane map coordinate fields. The observed pair order is not the intuitive `x,y` order: `+0x104` is copied to pair element 0, and `+0x100` is copied to pair element 1. Current packet-helper evidence uses pair element 1 as packet tile X and pair element 0 as packet tile Y. Implementation should preserve this coordinate-order caveat in support docs.

MapPane map-to-screen helper at `0x00505130`:

```text
pair[1] = (pair[1] - MapPane::tileOriginX + 1) * g_mapTilePixelWidth
pair[0] = (pair[0] - MapPane::tileOriginY + 1) * g_mapTilePixelHeight
```

The helper is currently documented in `MapPaneWeatherCoordinateObjectCore.md` as the map-to-screen coordinate helper. It is the best source-facing support name for target documentation. If implementation wants a C++ helper spelling, `MapPane::MapCoordsToScreen` or `MapPane::MapToScreenCoords` is better than the raw `sub_505130` label. Use only one spelling in emitted code and list the other as a search alias if needed.

MapPane direction-to-tile-offset helper at `0x00505080`:

- Takes the current facing/direction byte as an input.
- Writes a two-int direction vector through the point-pair initializer at `0x004b7c30`.
- Is documented as a direction-to-tile-offset helper in the MapPane aggregate.
- Directly feeds the target's pixel-offset scaling.

`ScaleDirectionOffsetToPixels` at `0x00505100`:

```text
pair[1] *= g_mapTilePixelWidth
pair[0] *= g_mapTilePixelHeight
```

Existing documentation already records direct caller `sub_5A88D0` and the coordinate-order caveat. The target confirms that this helper is used for movement interpolation, not for final map coordinate placement alone.

`InitRectBounds` at `0x004b7c50`:

- Writes `RectBounds { left, top, right, bottom }`.
- The target calls it twice, once for `this+0x1340d8` and once for `this+0x1340e8`.
- `RectBoundsLayout.md` supports the exact field order and size.

Globals:

- `0x0066da96`: `g_movementSubstepScale`, signed byte read, used as `4 * g_movementSubstepScale`.
- `0x0066da9c`: `g_mapTilePixelWidth`, signed word read, half added to screen X after interpolation.
- `0x0066daa0`: `g_mapTilePixelHeight`, signed word read, half added to screen Y after interpolation.

## Field And Type Recommendations

| Offset / Address | Best source-facing name | Evidence | Caveat |
|---|---|---|---|
| `this+0x100` | inherited ObjectPane tile X / map column field | `ObjectPane::GetMapPosition` copies it to pair element 1, and packet code treats element 1 as packet tile X. | Keep coordinate-order caveat because the getter output order is `pair[0]=+0x104`, `pair[1]=+0x100`. |
| `this+0x104` | inherited ObjectPane tile Y / map row field | `ObjectPane::GetMapPosition` copies it to pair element 0, and packet code treats element 0 as packet tile Y. | Same coordinate-order caveat. |
| `this+0x1c5` | `m_facing` | Current LivingObjectPane docs identify `+0x1c5` as facing; target passes it to direction-to-tile-offset helper. | `m_facingDirection` is a valid descriptive alias, but `m_facing` is the established class-wide name. |
| `this+0x1c6` | `m_moveFrame` | Current docs identify `+0x1c6` as movement frame; target uses it as signed interpolation numerator. | Target-specific role may be described as walk substep/interpolation frame. Keep source-facing name aligned with existing docs. |
| `this+0x3ec4` | `m_localPlayerHitRadius` | Constructor-side code initializes it from `2 * g_mapTilePixelWidth`; predecessor clip code and target both use it as a radius/half-extent around screen position. | Original spelling not recovered. Use this descriptive name only with the evidence note; do not claim an original symbol. |
| `this+0x1340cc` | `m_screenY` or `m_cachedScreenY` | Target writes centered screen Y after adding interpolated Y and half tile height; render consumer reads it from the active local pane/global pointer path. | Large offset belongs to adjusted local-player/UserPane aggregate view, not compact base `LivingObjectPane`. |
| `this+0x1340d0` | `m_screenX` or `m_cachedScreenX` | Target writes centered screen X after adding interpolated X and half tile width; render consumer reads it. | Same large-offset aggregate caveat. |
| `this+0x1340d8` | `m_screenHitBounds` | Target initializes a full symmetric `RectBounds` around `screenX,screenY`. | Original spelling not recovered; role is exact. |
| `this+0x1340e8` | `m_screenLowerHitBounds` | Target initializes left/right around X, top at center Y, bottom at `screenY+radius`; render-side code copies this and the full bounds. | Original spelling not recovered; lower-body/interaction role inferred from rectangle geometry and render consumer. |
| `this+0x1340f8` | `m_mapPane` | UserPane constructor docs and target reads prove cached MapPane pointer; target calls three MapPane coordinate helpers through it. | Large-offset aggregate caveat. |
| Stack `[ebp-0xc]` / `[ebp-8]` | `MapPoint screenPos` or `MapCoordinatePair screenPos` | Filled from ObjectPane map position, then converted in place to screen coordinates. | Pair element order is `y,x` / `row,column` in observed helper layout. |
| Stack `[ebp-0x14]` / `[ebp-0x10]` | `MapPoint stepOffset` or `MapCoordinatePair stepOffset` | Filled from facing direction and scaled to pixels before interpolation. | Same coordinate-order caveat. |
| `RectBounds` | `RectBounds { left, top, right, bottom }` | `InitRectBounds` and `RectBoundsLayout.md` agree on edge order. | None for target. |

For emitted C++, prefer the established class names where available and use descriptive field names for the large-offset local-player fields. The support docs should explicitly say that `+0x1340cc/+0x1340d0/+0x1340d8/+0x1340e8/+0x1340f8` are adjusted local-player/UserPane aggregate offsets seen from this method, not proof that compact base `LivingObjectPane` has a 0x134100-byte intrinsic layout.

## Relationship To Local Movement Helpers

This method is part of the local-player movement/render-position cluster under [UID:00007B] `LivingObjectPaneLocalPlayerExtensions`, but it is not a packet sender and does not mutate the movement-history ring.

Relationship points:

- `LivingObjectPaneProcessMovement` and the raw facing/movement packet helpers update local movement state, send packets, and maintain movement-history fields.
- This target consumes the resulting actor map position, facing, and movement frame to compute screen-space state for rendering and hit tests.
- The fields `m_facing` and `m_moveFrame` are shared movement-state inputs across the cluster.
- `m_movementHistory` fields at `+0x13eb14/+0x13eb18/+0x13eb1c` are not read or written here.
- `m_mapPane` at `+0x1340f8` links the local pane to MapPane-owned coordinate conversion helpers.
- The MapPane render path calls this method immediately before or during rendering of the local pane through `MapPane+0x418`.

Therefore support docs should describe this as the screen-position/cache update companion to local movement helpers, not as another network or movement-history update helper.

## Caller / Owner / Source Placement

Recommended canonical owner and emitter remain [UID:00007B] `LivingObjectPane`.

Evidence for LivingObjectPane ownership:

- The method is reached with `ecx = [MapPane+0x418]`, which UserPane constructor docs identify as the active local pane pointer.
- The method's own state accesses are actor/local-pane fields: inherited ObjectPane map position, `m_facing`, `m_moveFrame`, cached screen center, and hit bounds.
- The method has no MapPane `this` layout except for dereferencing cached `m_mapPane` to call conversion helpers.
- Existing `proposed-source-tree.md` places `0x005a88d0` in `map/LivingObjectPane.cpp`.
- Existing `by-file/LivingObjectPane.md` and `LivingObjectPaneLocalPlayerExtensions.md` already group the range with LivingObjectPane local-player movement/action helpers.

Rejected owner/source placements:

- Not `MapPane.cpp`: MapPane owns the caller and conversion helpers, but target `this` is the active local pane and target mutates pane fields.
- Not `UserPane.cpp`: the predecessor `0x005a8840-0x005a88cf` is UserPane clip-bounds behavior, but target is separated by `0xcc` padding, has a different single `this` receiver, and is documented in LivingObjectPane local-player extensions.
- Not `ObjectPane.cpp`: target starts from ObjectPane coordinates but consumes LivingObjectPane movement state and local-player aggregate fields.
- Not an anonymous compiler helper: direct source-like stateful method, normal prologue, explicit field writes, and exact caller route.

## Heuristic / Inference Reanalysis And Validation

### Compiler / Generated Names

`sub_5A88D0` is the raw IDA/generated function label. It should remain only as a search alias in evidence. It is not a source name.

`LivingObjectPaneUpdateScreenPosition` is the documentation filename slug and matches the best source-facing semantic name. It should not be used as a literal C++ symbol.

`LivingObjectPane::UpdateScreenPosition` is the best source-facing symbol. It is supported by:

- body semantics: screen position and bounds update,
- current target filename and aggregate grouping,
- historical generated report naming as a search hint,
- and direct call from render path before local rendering.

The historical generated name is not needed as authority; the current body is enough to justify the name.

### Function Signature

Best signature:

```cpp
void LivingObjectPane::UpdateScreenPosition();
```

Validation:

- `ecx` is the only receiver input.
- No stack arguments are read.
- Function returns with plain `ret`, not `ret N`.
- Return register is not used by the only direct caller in the decoded context.
- All output is stored into `this` fields and two local `RectBounds` initializations.

Rejected alternatives:

- `int` or `bool` return: no final return value is preserved or consumed.
- Explicit `MapPane *` argument: MapPane is loaded from `this+0x1340f8`, not from caller stack.
- Static helper: uses `this` fields throughout.

### World / Map Position Fields

Best interpretation:

- `this+0x100`: inherited ObjectPane tile X / map column.
- `this+0x104`: inherited ObjectPane tile Y / map row.

Validation:

- `ObjectPane::GetMapPosition` is the immediate first helper.
- It copies `+0x100` and `+0x104` into a caller-supplied two-int pair.
- Packet helper documentation confirms pair element 1 is packet tile X and pair element 0 is packet tile Y.

Remaining caveat is not an open question for target behavior: the coordinate pair order is unusual and must be documented. The target itself is correct if emitted with a named pair type whose layout states the order.

### Screen Position Fields

Best interpretation:

- `this+0x1340cc`: cached local-player screen Y.
- `this+0x1340d0`: cached local-player screen X.

Validation:

- `0x005a8967` writes X-like value from tile-width-scaled/interpolated pair plus half tile width to `+0x1340d0`.
- `0x005a897b` writes Y-like value from tile-height-scaled/interpolated pair plus half tile height to `+0x1340cc`.
- Render-side consumer at `0x004dd61b` reads these fields from the active local pane/global path and subtracts them from graphical object coordinates to position render rectangles.

Rejected alternatives:

- Raw map coordinates: the values are after MapPane map-to-screen conversion, direction-vector pixel scaling, movement interpolation, and half-tile centering.
- Global camera origin fields: they are written on the active local pane object, not on MapPane.

### Bounds / Hit Rectangle Fields

Best interpretation:

- `this+0x1340d8`: full screen hit/render bounds around local-player screen center.
- `this+0x1340e8`: lower-half/lower-body screen hit or interaction bounds.

Validation:

- Both are written through `InitRectBounds`.
- `+0x1340d8` receives `(x-r, y-r, x+r, y+r)`.
- `+0x1340e8` receives `(x-r, y, x+r, y+r)`.
- The first is symmetric around center; the second starts at center Y and extends downward.
- Render-side code copies both bounds for later tests/placement.

Rejected alternatives:

- Two identical rectangles: edge construction differs.
- Width/height rectangle layout: `RectBoundsLayout.md` proves edge order `left, top, right, bottom`, not `x,y,w,h`.
- Map-tile bounds: all inputs are screen-space pixel values after conversion and interpolation.

### Direction And Walk-Step Fields

Best interpretation:

- `this+0x1c5`: `m_facing`.
- `this+0x1c6`: `m_moveFrame`, with target-specific role as walk substep/interpolation frame.

Validation:

- Existing LivingObjectPane docs name `+0x1c5/+0x1c6` as facing and move frame.
- Target passes `+0x1c5` to the direction-to-tile-offset helper.
- Target uses signed `+0x1c6` as a numerator against the pixel direction vector and divisor `4 * g_movementSubstepScale`.

Rejected alternatives:

- Packet direction byte only: `+0x1c5` is shared actor movement state, not a local packet buffer byte.
- Animation frame only: `+0x1c6` directly changes screen interpolation, so it is movement/walk frame state even if sprite animation is coupled elsewhere.

### Hit Radius Field `this+0x3ec4`

Best source-quality name:

```cpp
m_localPlayerHitRadius
```

Validation:

- Constructor-side code initializes it from `2 * g_mapTilePixelWidth`.
- Target uses it as the same half-extent on left/right/top/bottom rectangle edges.
- Predecessor clip-bounds code reads it and combines it with tile half-width/height during local clipping.
- UI/graph helper calls near construction pass this value as a dimension/extent.

Remaining caveat:

- Original source spelling is not recovered. `m_localPlayerHitRadius` is a descriptive source-facing placeholder and should be documented as such. The role is strong enough for C++ readability, but the implementation should not claim it is an exact recovered member name.

Rejected alternatives:

- Tile width: initialized from tile width but later used as independent radius.
- Rectangle pointer: read as scalar and used arithmetically.
- Sprite width/height pair: a single scalar field is used for both X and Y extents.

### MapPane Helper Names

Best support names:

- `MapPane::MapCoordsToScreen` or `MapPane::MapToScreenCoords` for `0x00505130`.
- `MapPane::DirectionToTileOffset` for `0x00505080`.
- `ScaleDirectionOffsetToPixels` for `0x00505100`.

Validation:

- Existing MapPane aggregate already documents `0x00505130` as the map-to-screen coordinate helper and `0x00505080` as direction-to-tile-offset.
- Existing child page already names `0x00505100` as `ScaleDirectionOffsetToPixels`.
- The target confirms all three roles through call order and subsequent arithmetic.

Remaining caveat:

- `MapPane::MapCoordsToScreen` versus `MapPane::MapToScreenCoords` is a source spelling choice. Use one consistently and record the raw address and raw IDA label as aliases if no recovered symbol is available.

### Globals

Best names:

- `g_movementSubstepScale` for `0x0066da96`.
- `g_mapTilePixelWidth` for `0x0066da9c`.
- `g_mapTilePixelHeight` for `0x0066daa0`.

Validation:

- Existing by-global docs name and type these globals.
- Target's use of width in the pair element that becomes screen X and height in the pair element that becomes screen Y confirms their semantics.
- `g_movementSubstepScale` appears in the divisor `4 * value`, matching interpolation/substep scale.

Rejected alternatives:

- Per-object fields: all three are absolute global reads.
- Tile count/grid dimensions: target uses them as pixel multipliers and half-pixel offsets.

### Type Choices

Recommended types:

- `MapCoordinatePair` or `MapPoint` for the two-int coordinate pair, with documented storage order.
- `RectBounds` for `+0x1340d8` and `+0x1340e8`.
- `unsigned char` or small enum-like direction type for `m_facing`, but existing docs should keep the established byte field.
- signed byte or `char` for `m_moveFrame` unless a broader movement-state enum is established.

Validation:

- Coordinate helpers mutate two contiguous ints.
- `InitRectBounds` writes four int edges.
- `movzx` reads `m_facing` as unsigned byte.
- `movsx` reads `m_moveFrame` as signed byte.

### Owner / Source Placement

Best owner:

```text
[UID:00007B] LivingObjectPane
```

Validation:

- Mutates LivingObjectPane/local-player fields.
- Consumes LivingObjectPane movement state.
- Only calls into MapPane for coordinate conversion.
- Existing split inventory already includes the target in `LivingObjectPaneLocalPlayerExtensions`.

Rejected placements are `MapPane`, `UserPane`, `ObjectPane`, and anonymous compiler helper for the reasons listed in the caller/source-placement section.

### First-Draft C++ Eligibility

First-draft C++ is eligible and recommended now.

Eligibility evidence:

- Target has `RECONSTRUCTABLE: TRUE`.
- Current owner and emitter are nonblank and correct: [UID:00007B].
- Current average score is already above the standard C++ gate.
- Exact range and padding are proven.
- There is an ordinary direct caller route.
- No switch table, exception frame, compiler thunk, or raw no-function block complicates this body.
- Body has a short, straight-line sequence with named support helpers and documented globals.

Remaining caveats do not block C++:

- The original spelling of `m_localPlayerHitRadius`, `m_screenHitBounds`, and `m_screenLowerHitBounds` is not recovered.
- The coordinate pair layout must be documented in the C++ comments or support type docs.
- Large offsets must be described as local-player/UserPane aggregate offsets, not compact base-class layout proof.

These are source-quality annotation caveats, not no-code proof.

## Rejected Alternatives

Rejected `UserPane::UpdateScreenPosition`:

- The predecessor is UserPane code, but the target is separated by padding and belongs to the LivingObjectPane local-player cluster.
- The direct caller supplies `[MapPane+0x418]`, the active local pane pointer, not a generic UserPane virtual dispatch.
- Target state is actor position, facing, movement frame, screen center, and hit bounds.

Rejected `MapPane::UpdateScreenPosition`:

- MapPane is the caller and helper owner only.
- Target `ecx` points at the active pane object.
- Target reads `this+0x1340f8` to obtain MapPane; a MapPane method would not need that as a nested field.

Rejected raw coordinate-conversion helper:

- Target writes persistent object fields and two rectangles.
- It is not a pure helper over caller-provided coordinate buffers.

Rejected no-code/no-route status:

- One direct rel32 caller exists.
- Body is ordinary and reconstructable.
- Current source-quality blockers are naming caveats, not reachability or structural uncertainty.

Rejected exact original names for unresolved fields:

- No symbol evidence proves original member spellings for `+0x3ec4`, `+0x1340cc`, `+0x1340d0`, `+0x1340d8`, or `+0x1340e8`.
- Use descriptive names with evidence notes instead of pretending exact recovery.

## Open-Question Closure

The target page's current unresolved questions can be closed as follows:

- Final function name/signature: resolved to `void LivingObjectPane::UpdateScreenPosition()`.
- World/map position fields: resolved to inherited ObjectPane coordinate fields `+0x100/+0x104`, with the coordinate-order caveat copied from `ObjectPane::GetMapPosition`.
- Screen position fields: resolved to cached screen center fields `+0x1340cc` screen Y and `+0x1340d0` screen X.
- Hit rectangle/bounds fields: resolved to `RectBounds` at `+0x1340d8` full bounds and `+0x1340e8` lower-half/lower-body bounds.
- Direction field: resolved to `m_facing` at `+0x1c5`.
- Walk-step/interpolation field: resolved to `m_moveFrame` at `+0x1c6`, target role signed walk substep/interpolation numerator.
- Movement interpolation global: resolved to `g_movementSubstepScale`, used as divisor component `4 * scale`.
- Tile dimension globals: resolved to `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- MapPane relationship: resolved as helper owner/caller context, not canonical owner.
- Local movement helper relationship: resolved as screen-position/cache companion to movement prediction and packet helpers, not a movement-history writer.
- Caller route: resolved to direct call at `0x00509563` from MapPane render path via `MapPane+0x418`.
- First-draft C++: recommended now.

No generic future-work question should remain on the target page. The only caveats that should remain are explicit source-spelling and coordinate-order caveats:

- original field spelling for `+0x3ec4`, `+0x1340d8`, and `+0x1340e8` is not recovered,
- and the coordinate pair storage order must be kept explicit until shared coordinate type docs settle the `x/y` naming convention.

## First-Draft C++ Recommendation

Recommended first-draft C++ for the target page during implementation:

```cpp
void LivingObjectPane::UpdateScreenPosition()
{
    MapCoordinatePair screenPos;
    GetMapPosition(&screenPos);
    m_mapPane->MapCoordsToScreen(&screenPos);

    MapCoordinatePair stepOffset;
    m_mapPane->DirectionToTileOffset(&stepOffset, m_facing);
    ScaleDirectionOffsetToPixels(&stepOffset);

    const int divisor = 4 * g_movementSubstepScale;
    const int screenX =
        screenPos.x + (m_moveFrame * stepOffset.x) / divisor + g_mapTilePixelWidth / 2;
    const int screenY =
        screenPos.y + (m_moveFrame * stepOffset.y) / divisor + g_mapTilePixelHeight / 2;

    m_screenX = screenX;
    m_screenY = screenY;

    InitRectBounds(
        &m_screenHitBounds,
        screenX - m_localPlayerHitRadius,
        screenY - m_localPlayerHitRadius,
        screenX + m_localPlayerHitRadius,
        screenY + m_localPlayerHitRadius);

    InitRectBounds(
        &m_screenLowerHitBounds,
        screenX - m_localPlayerHitRadius,
        screenY,
        screenX + m_localPlayerHitRadius,
        screenY + m_localPlayerHitRadius);
}
```

Implementation caveat for this code block:

- The emitted support docs must define or describe `MapCoordinatePair` so that `.x` maps to the helper's width-scaled element and `.y` maps to the height-scaled element. In observed binary layout, the pair helper stores Y/row in element 0 and X/column in element 1. The C++ above is source-facing pseudocode, not a claim that the raw stack offsets are laid out as `{ x, y }`.
- If the project avoids introducing a named coordinate type in this target, emit the same logic with explicit local names `screenTileYOrRow`, `screenTileXOrColumn`, `stepY`, and `stepX` to avoid hiding the pair-order caveat.
- `m_localPlayerHitRadius`, `m_screenHitBounds`, and `m_screenLowerHitBounds` should be marked as descriptive field names unless another accepted report or live symbol evidence recovers original spellings.

This is preferable to leaving formal C++ blank because the behavior is straight-line, caller-proven, and reconstructable.

## Proposed Metadata And Score Rationale

Recommended metadata:

```text
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 00007B
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 00007B
```

Score rationale:

- Raise above `85/87` because the boundary, route, helper calls, globals, position fields, and bounds writes are now directly rechecked.
- Do not raise to `95+` because several member spellings are descriptive rather than recovered original names, and coordinate-pair naming still requires an explicit order caveat.
- Confidence can reach `90` because the behavior and ownership are independently supported by local PE disassembly, existing IDA-backed docs, and cross-file support docs.

## Exact Target / Support Implementation Checklist

Target page `by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007B`.
- Replace unresolved summary/open questions with the exact body narrative from this report: map/world position read, MapPane map-to-screen conversion, facing direction vector, pixel offset scaling, signed movement-frame interpolation, half-tile centering, cached screen center writes, and two `RectBounds` writes.
- Add boundary proof: predecessor `0x005a8840-0x005a88cf`, one `0xcc` byte at `0x005a88cf`, target `0x005a88d0-0x005a89c9`, seven `0xcc` bytes at `0x005a89c9-0x005a89d0`, next body at `0x005a89d0`.
- Add caller proof: exactly one direct rel32 call at `0x00509563` from the MapPane render path with `ecx=[MapPane+0x418]`; no absolute pointer hits.
- Add callee/helper evidence for `ObjectPane::GetMapPosition`, MapPane map-to-screen helper `0x00505130`, direction-to-tile-offset helper `0x00505080`, `ScaleDirectionOffsetToPixels`, and `InitRectBounds`.
- Add the field table with best source-quality names and caveats.
- Add the first-draft C++ above or an equivalent order-preserving C++ body.

`by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`:

- Expand the `0x005a88d0-0x005a89c9` row from "screen/hit-bounds update" to the report-level details: `ObjectPane::GetMapPosition`, MapPane conversion, facing/move-frame interpolation, screen center fields, full/lower bounds fields, and direct MapPane render caller.
- Clarify this target is not a movement-history writer, but it consumes movement-state fields maintained by the local movement cluster.

`by-class/LivingObjectPane.md`:

- Add or refine local-player adjusted fields:
  - `m_localPlayerHitRadius` at `+0x3ec4` as descriptive.
  - `m_screenY`/`m_cachedScreenY` at `+0x1340cc`.
  - `m_screenX`/`m_cachedScreenX` at `+0x1340d0`.
  - `m_screenHitBounds` at `+0x1340d8`.
  - `m_screenLowerHitBounds` at `+0x1340e8`.
  - `m_mapPane` at `+0x1340f8`.
- Preserve the large-offset local-player/UserPane aggregate caveat.
- Keep `m_facing` `+0x1c5` and `m_moveFrame` `+0x1c6` as established movement fields.

`by-file/LivingObjectPane.md`:

- Add the source-quality placement note that `UpdateScreenPosition` belongs in `map/LivingObjectPane.cpp`, consumes MapPane helper APIs, and should now be eligible for first-draft C++.
- Include the single direct caller from MapPane render and note that caller ownership does not move the function to MapPane.

`by-memory/0x005a83b0-0x005a87ad.UserPaneHandleAnimationStep.md` and `by-memory/0x005a2530-0x005b8395.UserPane.md`:

- Add a boundary/neighbor note that `0x005a8840-0x005a88cf` is UserPane clip-bounds behavior, but `0x005a88d0-0x005a89c9` is a separate LivingObjectPane local-player screen-position method.
- Do not reassign target ownership to UserPane.

`by-class/UserPane.md`:

- Keep the cached MapPane relationship and `MapPane+0x418` inverse pointer evidence, but cross-reference that the direct render caller reaches LivingObjectPane `UpdateScreenPosition`.

`by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`:

- Refine the displacement-user note for `this+0x1340f8` to state that `0x005a88d0` reads `m_mapPane` three times to call MapPane map-to-screen, direction-to-tile-offset, and direction-offset pixel-scaling helpers.

`by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`:

- Add the exact caller sequence at `0x0050955d/0x00509563` and the condition at `0x00509550`.
- State that the render path calls `UpdateScreenPosition` on `[MapPane+0x418]` before local rendering/position-dependent work.

`by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`:

- Add target-specific consumer notes for `0x00505130`, `0x00505080`, and `0x00505100`.
- Preserve MapPane helper ownership while noting this target is a LivingObjectPane consumer.

`by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md`:

- Expand the caller note for `sub_5A88D0`: the scaled offset is multiplied by signed `m_moveFrame`, divided by `4 * g_movementSubstepScale`, and added to the MapPane-converted screen coordinate.

`by-global/MapTilePixelDimensions.md`:

- Add target-specific usage: width scales direction pair element 1 and contributes half-tile X center; height scales element 0 and contributes half-tile Y center.

`by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md`:

- Add target-specific usage: direct byte read at `0x005a8923`, divisor `4 * g_movementSubstepScale`, with signed movement-frame interpolation.

`by-memory/0x005374d0-0x005374eb.ObjectPaneGetMapPosition.md`:

- Add `UpdateScreenPosition` as a consumer.
- Preserve the coordinate-order caveat: output element 0 comes from `+0x104`, output element 1 comes from `+0x100`.

`by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`:

- Add target cross-reference that it calls `InitRectBounds` twice for full and lower screen hit bounds.

`by-type/by-struct/RectBoundsLayout.md`:

- Optional support update: cross-reference `UpdateScreenPosition` as evidence for edge-ordered `RectBounds` construction in screen-space.

`by-memory/-coverage-report.md`:

- Supervisor-owned insertion only. Do not edit during implementation callback unless explicitly authorized; use the exact row below.

## Exact Supervisor-Owned Coverage Row

```text
    - [UID:0003UH][0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition](by-memory/0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md) 0x005a88d0-0x005a89c9 | class method | LivingObjectPane::UpdateScreenPosition : reconstructable : 88% : very strong : B008 2026-06-19 source-quality reanalysis confirms exact modeled thiscall body `0x005a88d0-0x005a89c9`, predecessor [UID:0000FQ] `UserPane::OnClipBounds` ending at `0x005a88cf` plus one `0xcc`, seven trailing `0xcc` bytes before the next body at `0x005a89d0`, exactly one direct caller at `0x00509563` from [UID:00037V] `MapPane` render view via `MapPane+0x418`, no target pointer hits, callee chain through `ObjectPane::GetMapPosition`, MapPane map-to-screen and direction-offset helpers, `ScaleDirectionOffsetToPixels`, `g_movementSubstepScale`, `g_mapTilePixelWidth/g_mapTilePixelHeight`, cached local-player screen center fields `+0x1340cc/+0x1340d0`, hit/lower-hit `RectBounds` at `+0x1340d8/+0x1340e8`, `m_facing`/`m_moveFrame` interpolation, and first-draft C++ readiness with coordinate-order and original field-spelling caveats.
```

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003UH-LivingObjectPaneUpdateScreenPosition-source-quality-removed.md](0003UH-LivingObjectPaneUpdateScreenPosition-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
Exit code: 0
mode: file
scanned markdown files: 1
ok: 1
```

The validator output included `ok 0003UH ... UID header exists`. Autogen-related dry-run/noop lines appeared, but no validation failure appeared and no by-* files were edited by this report-only pass.

## Report-Only Integrity

This report is the only intended file output for this assignment:

```text
tools/leaser/Agents/Agent-B008/research/0003UH-LivingObjectPaneUpdateScreenPosition-source-quality.md
```

No `by-*` documentation file and no `by-memory/-coverage-report.md` should be changed by this research pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0003UH-LivingObjectPaneUpdateScreenPosition-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0003UH"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003UH-LivingObjectPaneUpdateScreenPosition-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0003UH-LivingObjectPaneUpdateScreenPosition-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003UH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
