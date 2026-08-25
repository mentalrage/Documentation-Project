** TARGET-REPORT-UID:0001DH **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Report - [UID:0001DH] AttachmentAnchorResolver Source Quality

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0001DH-AttachmentAnchorResolver-source-quality.md`

Target: `source-3/project-documentation/by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md`

Assignment: B-agent source-quality / heuristic research for `AttachmentAnchorResolver`.

No target/support `by-*` docs, generated files, or `by-memory/-coverage-report.md` were edited during this report pass. Existing B015 reports, including `00013G`, `00014F`, `0002IR`, and `0002PY`, were preserved.

## Summary Recommendation

`0x0053c700-0x0053c92e` is source-authored project code and should stay owned by the exact modeled `AttachmentAnchorResolver` helper class/page. The range contains two modeled methods:

| Range | Source-quality name | Recommended signature |
| --- | --- | --- |
| `0x0053c700-0x0053c802` | `AttachmentAnchorResolver::ResolveAnchorPoint` | `ScreenPoint *ResolveAnchorPoint(ScreenPoint *outPoint)` |
| `0x0053c810-0x0053c92e` | `AttachmentAnchorResolver::ComputeScreenBounds` | `RectBounds *ComputeScreenBounds(RectBounds *outBounds)` |

Recommended target score: `88/90`, reconstructable, with first-draft C++ ready.

Keep raw siblings as separate non-emitting/no-code children:

- [UID:0002TX] `0x0053c6b0-0x0053c6f7` raw metric helper
- [UID:0002TY] `0x0053c930-0x0053c97b` raw screen-bounds notify helper
- [UID:0002U0] `0x0053c9f0-0x0053ca1b` raw light-apply twin

Those raw siblings are not blockers for emitting first-draft C++ for [UID:0001DH]. Current raw-PE reachability checks still show no direct calls and no dword pointer hits to their starts.

Source placement policy: preserve the exact modeled `AttachmentAnchorResolver` ownership for this target, but document that the higher-probability original source placement is a private helper/class inside `NexusTK/map/AttachedObjectPane.cpp`, not a broad `ObjectPane` method and not `LightingObjectPane`. The existing [UID:0000HL] standalone `AttachmentAnchorResolver` by-file page is still useful as a synthetic documentation/autogen root unless the supervisor chooses a later route migration to [UID:0000HJ] `AttachedObjectPane`.

## Evidence Checked

Instruction/context docs checked:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`
- `.codex/AGENTS.md`

Target and direct support docs checked:

- [UID:0001DH] target by-memory page
- [UID:00000O] `by-class/AttachmentAnchorResolver.md`
- [UID:0000HL] `by-file/AttachmentAnchorResolver.md`
- Generated `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`
- Current `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `project-level/-auto-completion-stats.md` rows

Related support checked:

- [UID:0000HJ] `by-file/AttachedObjectPane.md`
- [UID:00000M] `by-class/AttachedObjectPane.md`
- [UID:0001D8] `0x005380b0-0x005387a3.AttachedObjectPane.md`
- [UID:0000M5]/[UID:00009R] `ObjectPane` file/class and exact attach/detach/object-data children
- [UID:0002IV] `LightObjImageLib::GetLightBounds`
- `LightInfo`, `LightObjImageLibLayout`, `g_pLightObjImageLib`
- `RectBoundsLayout`, `RectGeometryHelpers`, `RectBounds`
- `MapPane`, `MapTilePixelDimensions`, `ScaleDirectionOffsetToPixels`, `g_movementSubstepScale`
- raw siblings [UID:0002TX], [UID:0002TY], [UID:0002TZ], [UID:0002U0]
- B003 executed source-quality report for [UID:0002IV], because it repaired the caller-side `0x0053c810` LightObjImageLib dependency.

Current-session IDA MCP status:

- `http://127.0.0.1:13337/` timed out in this session. I did not rely on current live IDA RPC.

Current raw PE checks:

- PE used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- Image base: `0x00400000`
- Target maps to `.text`, file offset `0x0013bb00`, length `0x22e` / 558 bytes.
- Current disassembly confirms `0x0053c700-0x0053c802`, 14 bytes of `0xcc` padding at `0x0053c802-0x0053c810`, and `0x0053c810-0x0053c92e`.
- Current rel32 scan:
  - `0x0053c700`: two direct calls at `0x005096be` and `0x0050aabf`.
  - `0x0053c810`: ten direct calls at `0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, and `0x0053c958`.
  - `0x0053c9c0`: two direct calls at `0x005096cc` and `0x0050aacf`.
  - raw starts `0x0053c6b0`, `0x0053c930`, and `0x0053c9f0`: zero direct rel32 calls.
  - `0x004dfb40`: one direct call at `0x0053c82b`.
  - `0x005386c0`: seven direct calls, including the two target calls at `0x0053c7d3` and `0x0053c8f9`.
- Current pointer scan across `.text`, `.rdata`, and `.data` found zero dword pointer hits for `0x0053c6b0`, `0x0053c700`, `0x0053c810`, `0x0053c930`, `0x0053c9c0`, and `0x0053c9f0`.
- Current padding bytes:
  - `0x0053c6a1-0x0053c6b0`: fifteen `0xcc`
  - `0x0053c6f7-0x0053c700`: nine `0xcc`
  - `0x0053c802-0x0053c810`: fourteen `0xcc`
  - `0x0053c92e-0x0053c930`: two `0xcc`
  - `0x0053c97b-0x0053c980`: five `0xcc`
  - `0x0053c9b5-0x0053c9c0`: eleven `0xcc`
  - `0x0053c9eb-0x0053c9f0`: five `0xcc`
  - `0x0053ca1b-0x0053ca20`: five `0xcc`

Numeric checks with `tools/int_convert.py`:

- `0x102` = 258
- `0x11e` = 286
- `0x128` = 296
- `0x12c` = 300
- `0x130` = 304
- `0x134` = 308
- `0x1c` = 28
- `0x3e0` = 992
- `0x22e` = 558

## Heuristic / Inference Reanalysis And Validation

### 1. Source Placement

The exact modeled methods should remain under [UID:00000O] `AttachmentAnchorResolver`. They are not `LightingObjectPane` code:

- `0x0053c700` and `0x0053c810` work from an anchor source object pointer at `this+0x134`, source object map coordinates, source object type, local offsets, and the active map coordinate helpers.
- `0x0053c810` is a consumer of [UID:0002IV] `LightObjImageLib::GetLightBounds`; it does not own the LightObjImageLib method.
- The adjacent `LightingObjectPane::SetIntensity` at `0x0053c980-0x0053c9b5` is separated by padding and has its own callers/field semantics.

The higher-probability original source file is `AttachedObjectPane.cpp`, as a private helper/class, not a standalone original `AttachmentAnchorResolver.cpp`:

- [UID:0000HJ] `AttachedObjectPane` already groups attached overlay classes and explicitly lists `AttachmentAnchorResolver` as a shared anchor point/bounds helper.
- `ObjectPane::AttachObject`, `ObjectPane::DetachObject`, and `ObjectPane::SetObjectData` call `0x0053c810` only as attached-object geometry consumers.
- `AttachedObjectPane` destructor/update helpers call `0x0053c810` while adjusting attached payload height/bounds.
- Map render loops call `0x0053c810`, test intersection, call `0x0053c700`, then call [UID:0002TZ] `0x0053c9c0` to apply the light at the resolved anchor.
- There is no constructor, destructor, vtable, static singleton, or source-tree-only evidence strong enough to require a separate original `.cpp`.

Rejected routes:

- `ObjectPane.cpp`: rejected as final owner. Base ObjectPane attach/detach methods consume the helper, but the helper's local state (`+0x128` through `+0x134`) describes the attached payload anchor/light descriptor, not base ObjectPane fields.
- `LightingObjectPane.cpp`: rejected. The target resolves attached anchors and bounds; light behavior is a dependency through `LightObjImageLib` and the global light table, not ownership.
- `MapPane.cpp`: rejected. MapPane render paths consume the helper and own coordinate globals, but the helper's object layout and attached-object lifecycle callers point to attached overlay source.
- Standalone `AttachmentAnchorResolver.cpp`: plausible as a synthetic documentation/autogen root and current validator route, but lower probability as original source than a private helper inside `AttachedObjectPane.cpp`.

Implementation policy:

- Preserve exact modeled range ownership as `AttachmentAnchorResolver`.
- If the supervisor wants a conservative low-churn implementation, leave metadata route `0001DH -> 00000O -> 0000HL` and document `0000HL` as a synthetic/staging root.
- If the supervisor wants final source-tree fidelity now, migrate [UID:00000O] upward to [UID:0000HJ] `AttachedObjectPane`; the target by-memory owner can stay [UID:00000O].

### 2. Names, Signatures, And Local Types

Best source-quality method names:

- `ResolveAnchorPoint` for `0x0053c700`.
- `ComputeScreenBounds` for `0x0053c810`.

Best signatures:

```cpp
ScreenPoint *AttachmentAnchorResolver::ResolveAnchorPoint(ScreenPoint *outPoint);
RectBounds *AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds);
```

The methods return the caller-provided output pointer in `eax`; all checked direct callers ignore the return and use the output local. A `void` output-parameter signature is source-style plausible, but the explicit `mov eax, out` epilogues make pointer-return signatures the better first-draft match.

Recommended local point/offset shape:

```cpp
struct ScreenPoint {
    int y;
    int x;
};
```

Rationale:

- Map/world helper code uses row/column pair ordering.
- `RectBounds` support confirms rectangle order is `left, top, right, bottom`.
- `OffsetRect` at `0x004b7e10` takes `(RectBounds *rect, int dx, int dy)` and adds `dx` to left/right and `dy` to top/bottom.
- At `0x0053c906-0x0053c91b`, `+0x12c` contributes to the top/bottom translation and `+0x130` contributes to the left/right translation.

Recommended field names:

| Offset | Source-quality name | Type | Evidence |
| --- | --- | --- | --- |
| `+0x128` | `m_lightImageIndex` or `m_lightIndex` | `int` | Passed to `LightObjImageLib::GetLightBounds`, used by [UID:0002TZ] light-table apply, and read by ObjectPane attach/detach for light descriptor height/offset effects. Prefer `m_lightImageIndex` because it covers both bounds and light-table roles. |
| `+0x12c` | `m_localOffsetY` | `int` | Added to the point `y` component and to `OffsetRect`'s `dy` argument. |
| `+0x130` | `m_localOffsetX` | `int` | Added to the point `x` component and to `OffsetRect`'s `dx` argument. |
| `+0x134` | `m_anchorSource` | `ObjectPane *` | Source object for type, map position, attached screen position, and living-object interpolation fields. |

Source object fields used:

- `ObjectPane +0xf8`: `m_objectType`.
- `ObjectPane +0x100`: `m_mapX`.
- `ObjectPane +0x104`: `m_mapY`.
- `LivingObjectPane +0x1c5`: `m_facing`.
- `LivingObjectPane +0x1c6`: `m_moveFrame`.

### 3. Behavior And Range/Error Semantics

`ResolveAnchorPoint` behavior:

1. Load `ObjectPane *source = this->m_anchorSource`.
2. If `source->m_objectType == 3` (`LivingObjectPane` direction), build a point from source map coordinates, convert through MapPane `WorldToScreenCoords`, derive a direction offset from `m_facing`, scale it to pixels, and apply `(m_moveFrame * offset) / (4 * g_movementSubstepScale)` to account for in-progress movement.
3. If `source->m_objectType == 2` or `4`, delegate to shared attached-screen-position helper `0x005386c0`.
4. Otherwise, build a point from source map coordinates and call MapPane `WorldToScreenCoords`.
5. Add resolver local offsets: `m_localOffsetY` to `y`, `m_localOffsetX` to `x`.
6. Return `outPoint`.

`ComputeScreenBounds` behavior:

1. Load `g_pLightObjImageLib`.
2. Call `LightObjImageLib::GetLightBounds(m_lightImageIndex, outBounds)`.
3. Compute the same anchor point semantics used by `ResolveAnchorPoint` with local offsets.
4. Offset the returned local light bounds through `OffsetRect(outBounds, anchor.x, anchor.y)`.
5. Return `outBounds`.

Range/error behavior:

- No null checks are present for `m_anchorSource`, `g_activeMapPane` / `dword_67A764`, or `g_pLightObjImageLib`.
- `LightObjImageLib::GetLightBounds` owns range behavior for `m_lightImageIndex`: negative or out-of-range index uses fallback; missing generated frame returns empty `0,0,0,0` bounds.
- `DirectionToTileOffset` handles invalid direction values by producing a zero direction pair per MapPane helper docs.
- Division uses `4 * g_movementSubstepScale` without a local zero guard. Current storage initializes `g_movementSubstepScale` to `1`, and support docs found no direct writer.

### 4. Raw Neighbor Policy

Raw neighbors are resolved enough for policy:

- [UID:0002TX] `0x0053c6b0` remains a raw no-entry helper. Current PE scan finds zero direct calls and zero pointer hits to `0x0053c6b0`.
- [UID:0002TY] `0x0053c930` remains a raw no-entry helper. Current PE scan finds zero direct calls and zero pointer hits to `0x0053c930`.
- [UID:0002U0] `0x0053c9f0` remains a raw no-entry helper. Current PE scan finds zero direct calls and zero pointer hits to `0x0053c9f0`.
- [UID:0002TZ] `0x0053c9c0` is modeled and caller-backed; it should remain a separate exact child, not folded into [UID:0001DH].

No raw sibling should be emitted as formal C++ until a caller, callback slot, vtable entry, or table reference proves reachability and original API shape. This is an active no-code proof, not a passive blocker for [UID:0001DH].

## First-Draft Source-Style C++

This is suitable for target/class docs as first-draft C++ once the supervisor chooses the route. Helper/type names are intentionally source-facing and should be synchronized with surrounding docs before formal insertion.

```cpp
struct ScreenPoint {
    int y;
    int x;
};

ScreenPoint *AttachmentAnchorResolver::ResolveAnchorPoint(ScreenPoint *outPoint)
{
    ObjectPane *source = m_anchorSource;

    if (source->m_objectType == ObjectPaneType::Living) {
        outPoint->y = source->m_mapY;
        outPoint->x = source->m_mapX;
        WorldToScreenCoords(outPoint);

        ScreenPoint step = {};
        DirectionToTileOffset(&step, static_cast<LivingObjectPane *>(source)->m_facing);
        ScaleDirectionOffsetToPixels(&step);

        const int divisor = 4 * g_movementSubstepScale;
        const int frame = static_cast<signed char>(
            static_cast<LivingObjectPane *>(source)->m_moveFrame);
        outPoint->y += (frame * step.y) / divisor;
        outPoint->x += (frame * step.x) / divisor;
    } else if (source->m_objectType == 2 || source->m_objectType == 4) {
        ScreenPoint attachedPoint = {};
        GetAttachedScreenPosition(source, &attachedPoint);
        *outPoint = attachedPoint;
    } else {
        outPoint->y = source->m_mapY;
        outPoint->x = source->m_mapX;
        WorldToScreenCoords(outPoint);
    }

    outPoint->y += m_localOffsetY;
    outPoint->x += m_localOffsetX;
    return outPoint;
}

RectBounds *AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)
{
    g_pLightObjImageLib->GetLightBounds(m_lightImageIndex, outBounds);

    ScreenPoint anchorPoint = {};
    ResolveAnchorPoint(&anchorPoint);
    OffsetRect(outBounds, anchorPoint.x, anchorPoint.y);
    return outBounds;
}
```

Binary-shape caveat: `0x0053c810` duplicates or inlines the anchor-point branch instead of directly calling `0x0053c700`. The source-style draft above uses `ResolveAnchorPoint` to avoid duplicating the same source logic. If a binary-shape draft is preferred, expand the same branch in `ComputeScreenBounds`; do not change the behavior.

## Recommended Target Doc Changes

Target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00000O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00000O | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target `Status` replacement:

```text
- Confidence: very strong for exact modeled function starts/ranges, source-facing names/signatures, output structs, field offsets, byte-level call flow, and raw-neighbor separation.
- Primary class: [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- Proposed source placement: exact modeled ownership stays with `AttachmentAnchorResolver`; higher-probability original source placement is a private helper/class in [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), while [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) remains the current synthetic documentation/autogen route unless the supervisor migrates the class parent.
- Evidence basis: existing by-* ownership docs, current raw PE disassembly/rel32/pointer scans, LightObjImageLib source-quality reanalysis, RectBounds/MapPane coordinate support, and ObjectPane/AttachedObjectPane caller checks.
- Parent handling: attached to [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md); first-draft C++ is ready for the two modeled methods. Raw sibling pages stay separate/no-code because current checks find no callers or pointer hits to their starts.
```

Recommended `Anchors` table replacement:

```text
| Address range | Proposed method | Notes |
| --- | --- | --- |
| `0x0053c700-0x0053c802` | `AttachmentAnchorResolver::ResolveAnchorPoint(ScreenPoint *outPoint)` | Resolves `m_anchorSource` into a screen-space point using ObjectPane map coordinates, living-object movement interpolation, shared attached-position helper `0x005386c0` for object types `2`/`4`, then applies `m_localOffsetY`/`m_localOffsetX`. |
| `0x0053c810-0x0053c92e` | `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)` | Calls `g_pLightObjImageLib->GetLightBounds(m_lightImageIndex, outBounds)`, resolves the same anchor point, and translates the local bounds through `OffsetRect(outBounds, anchor.x, anchor.y)`. |
```

Recommended layout/field paragraph:

```text
The resolver-local tail fields are now source-quality enough for first-draft code: `+0x128` is best named `m_lightImageIndex` / `m_lightIndex`, `+0x12c` is `m_localOffsetY`, `+0x130` is `m_localOffsetX`, and `+0x134` is `m_anchorSource` (`ObjectPane *`). The local point structure is a two-int screen pair stored as `{ y, x }`; this order matches the MapPane row/column coordinate helpers and the `OffsetRect` argument flow. Object type `3` is the LivingObjectPane path using `m_facing` at `+0x1c5` and `m_moveFrame` at `+0x1c6`; object types `2` and `4` delegate to shared attached-screen-position helper `0x005386c0`.
```

Recommended score rationale:

```text
| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | The page documents both modeled helper ranges, current source-quality signatures, field offsets, local point and rectangle semantics, LightObjImageLib bounds dependency, map/world-to-screen helper use, ObjectPane/AttachedObjectPane caller context, raw sibling no-code policy, source placement recommendation, and first-draft C++ readiness. |
| Confidence | 90 | Current raw PE disassembly and scans confirm exact bodies, caller counts, no pointer hits to sibling starts, padding boundaries, and dependency calls. Confidence remains below final-symbol quality because original helper/class spelling and the final metadata route between the synthetic standalone file and private `AttachedObjectPane.cpp` helper remain inferred. |
```

Recommended `Changes` entry:

```text
- 2026-06-19 B015 source-quality report:
  - Before: score `85/87`; final C++ was blank because field names, local struct shape, raw-neighbor reachability, and final source-file placement were listed as unresolved.
  - Changed to: recommended score `88/90` and first-draft C++ readiness for `ResolveAnchorPoint` and `ComputeScreenBounds`. Raw siblings remain no-code by active no-caller/no-pointer proof rather than by passive uncertainty.
  - Evidence: current raw PE disassembly confirms `0x0053c700-0x0053c802` and `0x0053c810-0x0053c92e`; rel32 scan finds two calls to `0x0053c700`, ten calls to `0x0053c810`, and no calls/pointers to raw sibling starts; support docs resolve `LightObjImageLib::GetLightBounds`, `RectBounds`/`OffsetRect`, `g_movementSubstepScale`, ObjectPane map fields, and LivingObjectPane `m_facing`/`m_moveFrame`.
```

## Recommended Support Doc Changes

### [UID:00000O] `by-class/AttachmentAnchorResolver.md`

Recommended score: `88/90`.

Keep [UID:00000O] as the exact helper class owner. Replace passive caveats with:

```text
Source placement is now policy-resolved as exact `AttachmentAnchorResolver` modeled ownership with higher-probability original placement as a private helper/class in `AttachedObjectPane.cpp`. The current [UID:0000HL] standalone file root remains a synthetic documentation/autogen route unless the supervisor performs route migration to [UID:0000HJ]. This source-placement caveat no longer blocks first-draft C++ for the exact modeled methods.
```

Replace layout notes with the field table from this report: `m_lightImageIndex`, `m_localOffsetY`, `m_localOffsetX`, `m_anchorSource`, and `ScreenPoint { y, x }`.

Change method notes:

```text
| `ResolveAnchorPoint(ScreenPoint *outPoint)` | `0x0053c700-0x0053c802` | Resolves `m_anchorSource` to a screen-space anchor using ObjectPane map fields, LivingObjectPane movement interpolation for type `3`, shared attached-position helper `0x005386c0` for types `2`/`4`, and local offsets. |
| `ComputeScreenBounds(RectBounds *outBounds)` | `0x0053c810-0x0053c92e` | Calls `LightObjImageLib::GetLightBounds(m_lightImageIndex, outBounds)`, resolves the anchor point, and offsets the local light bounds through `OffsetRect`. |
```

### [UID:0000HL] `by-file/AttachmentAnchorResolver.md`

Recommended score if kept as synthetic file root: keep `86/88` or raise to `87/89` only after text sync. Do not overstate standalone original-file proof.

Recommended text:

```text
`AttachmentAnchorResolver` is retained here as the current synthetic documentation/autogen root for the exact attachment-anchor helper family. Source-quality review now favors private placement inside [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) for original source, because the helper is a compact attached-overlay payload/placement helper with ObjectPane and AttachedObjectPane consumers and no independent constructor/destructor/vtable evidence. If the supervisor migrates route metadata, [UID:00000O] should attach upward to [UID:0000HJ]; until then, this file root remains the non-disruptive emitter route.
```

### [UID:0000HJ] `by-file/AttachedObjectPane.md`

Recommended text addition under file role or boundary notes:

```text
B015 source-quality reanalysis of [UID:0001DH] resolves `AttachmentAnchorResolver` as exact helper-class ownership with higher-probability original source placement as a private attached-overlay helper in this source file. `ObjectPane` attach/detach/object-data methods and MapPane render paths are consumers; they do not make the helper a base `ObjectPane` or `MapPane` owner. The current standalone [UID:0000HL] file root can remain a synthetic route unless supervisor route migration is performed.
```

### [UID:0000M5]/[UID:00009R] `ObjectPane` docs

Recommended text addition to `AttachObject`, `DetachObject`, and `SetObjectData` notes if those pages are touched:

```text
The `0x0053c810` call is `AttachmentAnchorResolver::ComputeScreenBounds` on the attached payload object. It recomputes or invalidates attached-object geometry from the payload's light/image index and anchor source. This is consumer evidence for ObjectPane attachment lifecycle, not owner evidence for the resolver helper.
```

### LightObjImageLib, RectBounds, MapPane, LivingObjectPane support

No required support edits. Existing docs already provide enough current names:

- `LightObjImageLib::GetLightBounds(int lightIndex, RectBounds *outBounds)`
- `LightInfo` row size `0x1c`
- `RectBounds` layout and `OffsetRect`
- `g_movementSubstepScale`
- `MapTilePixelDimensions`
- `LivingObjectPane` `m_facing` / `m_moveFrame`

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly from B015. If the supervisor accepts this report, replace the current [UID:0001DH] row with:

```text
    - [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md) 0x0053c700-0x0053c92e | method-cluster | AttachmentAnchorResolver : reconstructable : 88% : very-strong : B015 source-quality pass resolves the exact range as two source-authored helpers, `AttachmentAnchorResolver::ResolveAnchorPoint(ScreenPoint *outPoint)` at `0x0053c700-0x0053c802` and `AttachmentAnchorResolver::ComputeScreenBounds(RectBounds *outBounds)` at `0x0053c810-0x0053c92e`; current raw-PE checks confirm two calls to the point resolver, ten calls to the bounds helper, 14-byte padding between them, zero calls or dword pointer hits to raw sibling starts, LightObjImageLib local-bounds dependency through `g_pLightObjImageLib->GetLightBounds(+0x128,outBounds)`, ObjectPane map fields, LivingObjectPane `m_facing`/`m_moveFrame` interpolation through `g_movementSubstepScale`, shared attached-position helper `0x005386c0`, local offsets `+0x12c` vertical/top and `+0x130` horizontal/left, higher-probability private `AttachedObjectPane.cpp` source placement while preserving exact modeled helper ownership, and first-draft C++ readiness with raw siblings kept separate/no-code.
```

If the supervisor also refreshes [UID:00000O] class coverage, recommended replacement:

```text
- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md) : reconstructable : 88% : very-strong : Exact attached-anchor helper class with B015 source-quality reanalysis resolving `ResolveAnchorPoint` and `ComputeScreenBounds` signatures, `ScreenPoint {y,x}` local shape, `m_lightImageIndex`, `m_localOffsetY`, `m_localOffsetX`, `m_anchorSource`, LightObjImageLib/RectBounds/MapPane dependencies, ObjectPane and AttachedObjectPane consumer routing, raw sibling no-code proof, private `AttachedObjectPane.cpp` placement recommendation, and first-draft C++ readiness for the modeled methods while preserving current synthetic standalone route unless supervisor migration is chosen.
```

If the supervisor also refreshes [UID:0000HL] file coverage without route migration, recommended replacement:

```text
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) : reconstructable : 87% : very-strong : Synthetic `NexusTK/map/` documentation/autogen root for the attachment-anchor helper family; B015 resolves first-draft C++ readiness for [UID:0001DH], validates raw sibling no-code separation, field/local struct names, LightObjImageLib and MapPane dependencies, and recommends higher-probability original placement as a private helper in `AttachedObjectPane.cpp` while retaining this route unless supervisor performs metadata migration to [UID:0000HJ].
```

## Validator Needs

B015 did not run validators because this was report-only and no by-* docs or coverage files were edited.

If the supervisor implements the target/support edits, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0001DH-AttachmentAnchorResolver-source-quality-removed.md](0001DH-AttachmentAnchorResolver-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If ObjectPane consumer notes are edited, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0001DH-AttachmentAnchorResolver-source-quality-removed.md](0001DH-AttachmentAnchorResolver-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor migrates [UID:00000O] from synthetic [UID:0000HL] to [UID:0000HJ], validate the route with focused file/class/autogen coverage before applying C++.

## Open Questions

- Exact original symbol spelling for `AttachmentAnchorResolver`, `ResolveAnchorPoint`, and `ComputeScreenBounds` is not symbol-proven. The proposed names are behavior-backed and source-quality sufficient for first draft.
- Exact enum names for source object type values `2` and `4` remain unresolved. Use descriptive comparison or temporary constants, not invented final enum labels.
- Final metadata route remains a supervisor decision: retain [UID:0000HL] as synthetic standalone autogen root, or migrate [UID:00000O] to [UID:0000HJ] for original source placement fidelity.
- Raw helper siblings still need a future reachability trigger before formal C++. Current evidence supports no-code separation.

## Implementation Readiness

[UID:0001DH] is ready for first-draft C++ on the exact modeled methods. The stale blank-output rationale should be replaced: raw sibling reachability and source-placement uncertainty no longer block this exact target. The only implementation decision is whether to emit through the current synthetic `AttachmentAnchorResolver.cpp` route or first migrate the helper under `AttachedObjectPane.cpp`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0001DH-AttachmentAnchorResolver-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0001DH"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001DH-AttachmentAnchorResolver-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0001DH-AttachmentAnchorResolver-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001DH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
