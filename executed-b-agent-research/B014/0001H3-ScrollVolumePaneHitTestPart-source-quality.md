** TARGET-REPORT-UID:0001H3 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B014 source-quality report: [UID:0001H3] ScrollVolumePaneHitTestPart

Status: FINISHED report-only research; no by-* documentation edited.

Target: `source-3/project-documentation/by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0001H3-ScrollVolumePaneHitTestPart-source-quality.md`  
Primary aggregate/owner route: [UID:0001H2] `source-3/project-documentation/by-memory/0x00564710-0x005654ec.ScrollVolumePane.md` -> class [UID:0000CO] `by-class/ScrollVolumePane.md` -> file [UID:0000NK] `by-file/ScrollVolumePane.md`.

## Recommendation summary

`0x00564e30-0x00565006` is a complete source-authored `ScrollVolumePane` hit-test helper and should emit first-draft C++. The stale generated signature `TextEditPane::TrackScrollButtonF(int mouseX, int mouseY)` is owner/name pollution from reused scrollbar helper naming and should be removed from the source-facing model. The best current source-facing name is:

```cpp
ScrollVolumePart ScrollVolumePane::HitTestPart(int x, int y);
```

If the implementation pass does not want to introduce `ScrollVolumePart` yet, use `char ScrollVolumePane::HitTestPart(int x, int y)` with documented constants. The binary returns the part id in `AL` and returns `0xff`, which is source `-1`, for no hit.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0001H2
EMITTER_UIDS:0001H2
EMITTER_POSITION_OPTIONAL:100
```

Rationale: current 85/86 already clears the current 85/85 gate after correcting the owner/signature. Direct PE/Capstone evidence gives exact bounds, exact callers, exact callees, and a closed source shape. Remaining uncertainty is limited to original field/member names for coordinate components and the unrecovered writer for `+0xfb`; it does not block a first-draft body.

## Evidence checked

Documentation reviewed:

- `tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `tools/leaser/Agents/Agent-B014/goal.md`
- Target `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`
- Aggregate `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`
- Class `by-class/ScrollVolumePane.md`
- File `by-file/ScrollVolumePane.md`
- Layout `by-type/by-struct/ScrollVolumePaneLayout.md`
- Vtable support `by-type/by-vtable/ScrollVolumePaneVtables.md`
- Sibling/support pages:
  - `by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md` [UID:0002LB]
  - `by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md` [UID:0002LC]
  - `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md` [UID:0001H4]
  - `by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md` [UID:0001H5]
  - `by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md` [UID:0002LD]
  - `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
  - `by-type/by-struct/RectBoundsLayout.md`
- Generated/autogen references:
  - `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp`
  - `validation-logs/wave3_data_issues.md`
  - `by-memory/-coverage-report.md` current row text only; no edits made.

Binary checked:

- PE: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2,679,296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Sections used:
  - `.text` `0x00401000-0x0060c4ac`
  - `.rdata` `0x0060d000-0x0066c0be`
  - `.data` `0x0066d000-0x0069ce24`
  - `.rsrc` `0x0069d000-0x006b2c38`

Direct recheck results:

- Exact target start/end: `0x00564e30-0x00565006`.
- Body size: `0x1d6`.
- Function ends with `ret 8` at `0x00565003`; exclusive range end `0x00565006`.
- Boundary/padding:
  - `0x00564e21-0x00564e2f`: 15 bytes of `0xcc` before the target.
  - `0x00565006-0x0056500f`: 10 bytes of `0xcc` after the target.
  - `0x00565010` starts the successor geometry helper, currently modeled as `ScrollVolumePane::GetPartRect`.
- Direct rel32 callers to `0x00564e30`:
  - `0x005649f1` inside `ScrollVolumePane` mouse-event handling.
  - `0x0056530f` inside [UID:0001H4] `ScrollVolumePaneCommitInteraction`.
- Absolute VA dword hits for `0x00564e30`: none found.
- Callees from target:
  - `0x004a9090`: event/cursor-position helper, best current name `EventMan::GetCursorPosition`.
  - `0x005447c0`: pane screen-origin/offset helper, best current name `Pane::GetScreenOffset` or `Pane::GetScreenOrigin`.
  - `0x004b7c50`: rectangle initializer, documented as `InitRectBounds`; source-facing name can be `SetRect`.
  - `0x004b7e80`: rectangle hit helper, documented as `PointInRect`.
  - `0x005c772f`: runtime helper path seen in arithmetic support; no source-facing call should be emitted directly.
- `0x00565010` (`GetPartRect`) has separate route/callers and is not called by this target. It is the geometry counterpart, not the implementation dependency of this helper.

## Corrected behavior model

The helper iterates candidate part ids `0..4`, constructs the corresponding rectangle inline, tests the caller-supplied point against that rectangle, and returns the matching part id. If no part matches, it returns `0xff` in `AL`, which is source `-1`.

This is horizontal slider geometry, not vertical top/bottom geometry:

- Part `0`: leading edge/cap. The helper copies the pane bounds and collapses `right` to `left`.
- Part `1`: page/track area before the thumb. With enabled/range-positive state, it copies the pane bounds and sets `right` to `thumbLeft`. With disabled/range-nonpositive state, it becomes an empty rectangle.
- Part `2`: thumb. With enabled/range-positive state, rectangle is `[thumbLeft, top, thumbLeft + 38, bottom]`. With disabled/range-nonpositive state, the fallback thumb rectangle is the pane bounds inset by `38` on both horizontal sides.
- Part `3`: page/track area after the thumb. With enabled/range-positive state, it copies the pane bounds and sets `left` to `thumbLeft + 38`. With disabled/range-nonpositive state, it becomes an empty rectangle.
- Part `4`: trailing edge/cap. The helper copies the pane bounds and collapses `left` to `right`.
- No hit: `0xff` / `-1`.

Fixed metric:

- `0x26` decimal `38` is the thumb span/width for this horizontal geometry. Recommended source constant: `kScrollVolumeThumbSpan = 38`.

The current target wording that describes top/track-above/thumb/track-below/bottom is stale for this helper. The binary arithmetic is left/right, and `OnPaint` confirms horizontal behavior by drawing left segment, thumb, then right segment around the `GetPartRect(2)` thumb rectangle.

## Field and helper recommendations

Recommended `ScrollVolumePane` field names and roles:

| Offset | Recommended source-facing name | Evidence and confidence |
|---:|---|---|
| `+0x44` | `m_bounds` / inherited pane bounds | Copied into candidate rectangles. Strong; already supported by layout docs. |
| `+0xf8` | unresolved low state word, provisional `m_scrollState`/`m_sliderState` | Written by raw setter [UID:00031M], not central to this helper. Medium-low; avoid over-specific naming in target. |
| `+0xfa` | unresolved state byte, provisional `m_initializedState` | Written by raw setter [UID:00031N], not central to this helper. Medium-low; avoid over-specific naming in target. |
| `+0xfb` | `m_thumbDragActive` or `m_thumbDragOverrideActive` | Read by hit-test, `GetPartRect`, and paint to choose cursor-derived thumb position instead of value-derived position. No local writer recovered inside `0x00564710-0x005654ec` other than constructor zeroing through the surrounding dword. Best name: `m_thumbDragActive`; note missing writer as a confidence cap. |
| `+0xfc` | `m_volumeType` | Constructor/related docs already identify a volume type byte/word. Strong. |
| `+0xfe` | `m_currentValue` | Used in proportional thumb position calculation. Strong. |
| `+0x100` | `m_range` or `m_maxValue` | Positive divisor/range for proportional thumb position. Best name: `m_range`. Strong. |
| `+0x102` | `m_enabled` | Gates normal track/thumb partitioning. Strong. |
| `+0x103` | `m_highlightPart` | Used by highlight setter [UID:0002LB] and paint. Strong. |
| `+0x104` | `m_activePart` | Used by begin/commit/reset interaction helpers. Strong. |
| `+0x108/+0x10c` | `m_thumbDragOffset` | Set by begin-interaction [UID:0002LC] and consumed as a two-component point. `+0x10c` is the track-axis component used by this helper's drag override math. Strong role, medium exact component-name confidence. |

Recommended helper names:

- `0x004a9090`: `EventMan::GetCursorPosition(Point *out)`.
- `0x005447c0`: `Pane::GetScreenOffset(Point *out)` or `Pane::GetScreenOrigin(Point *out)`. Use `GetScreenOffset` in draft C++ to match existing fitting-room/source-doc language; exact original name remains unresolved.
- `0x004b7c50`: `SetRect(RectBounds *rect, int left, int top, int right, int bottom)` or retained doc name `InitRectBounds`. In handwritten C++ use `SetRect`.
- `0x004b7e80`: `PointInRect(int x, int y, const RectBounds *rect)`.
- `0x00565010`: `ScrollVolumePane::GetPartRect(ScrollVolumePart part, RectBounds *rect)`. This is the geometry counterpart and sibling helper, not a callee from `0x00564e30`.

Recommended part enum:

```cpp
enum ScrollVolumePart {
    kScrollVolumePartLeading = 0,
    kScrollVolumePartPageBeforeThumb = 1,
    kScrollVolumePartThumb = 2,
    kScrollVolumePartPageAfterThumb = 3,
    kScrollVolumePartTrailing = 4,
    kScrollVolumePartNone = -1
};
```

`LeadingCap`/`TrailingCap` are plausible alternatives for `0`/`4`, but the binary rectangles are collapsed leading/trailing edges. `Leading` and `Trailing` avoid overclaiming a visible cap image while still correcting the stale vertical top/bottom naming.

## Open-question closure and rejected alternatives

- Final method name/signature: resolved to `ScrollVolumePane::HitTestPart(int x, int y)` as best high-probability source name. The function returns an enum-like byte; use `ScrollVolumePart` in source docs if the enum is introduced, or `char` with constants if not.
- Stale `TextEditPane::TrackScrollButtonF`: rejected. Direct callers, fields, vtable/source route, sibling methods, and aggregate membership all support `ScrollVolumePane`. The stale name appears only as generated-output/template pollution and should be documented as rejected evidence.
- Vertical/top-bottom slider naming: rejected for this target. The binary manipulates `left/right`, has a 38-pixel horizontal thumb span, and `OnPaint` draws left/thumb/right regions.
- `GetPartRect` call-through implementation: rejected. `0x00564e30` calls cursor/origin/rectangle helpers and builds rectangles inline. `0x00565010` is a sibling geometry helper with overlapping logic.
- Generic `ScrollBar` or `TextEditPane` ownership: rejected. No separate generic scrollbar class route was found in direct evidence, and the fields are `ScrollVolumePane` fields.
- OptionPane ownership: rejected. OptionPane constructs/uses `ScrollVolumePane`; it does not own this helper's source body.
- Compiler-generated/no-code treatment: rejected for the target. This is not a thunk, vtable, scalar deleting destructor, or synthetic wrapper. It is a bounded source-authored helper with two direct source callers.
- `+0xfb` exact writer/source name: not fully resolved. Evidence checked: field reference scan within the `ScrollVolumePane` function island found reads in paint/hit-test/GetPartRect and constructor zeroing, but no local explicit setter. Best inference is `m_thumbDragActive` / drag override flag; exact lifecycle likely sits outside the recovered island or through a raw state helper not yet named.
- Coordinate component naming: partially resolved. Binary uses the second point component at `+0x10c` for track-axis drag math, while existing sibling docs use mixed `mouseY`/`mouseX` argument names. The source-quality direction is to name this as the drag offset's track-axis component and avoid hard-locking the public field to `x`/`y` until a coordinate-convention pass resolves the helper prototypes.

## First-draft C++ recommendation

Emit first-draft C++ in the target. This body is source-authored, non-generated, has a valid owner/emitter route, and clears the current 85/85 gate after the source-quality corrections.

Recommended draft C++:

```cpp
ScrollVolumePart ScrollVolumePane::HitTestPart(int x, int y)
{
    Point cursor;
    Point origin;

    EventMan::GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.x != -1000 || origin.y != -1000) {
        cursor.x -= origin.x;
        cursor.y -= origin.y;
    }

    for (int partValue = kScrollVolumePartLeading;
         partValue <= kScrollVolumePartTrailing;
         ++partValue) {
        const ScrollVolumePart part = static_cast<ScrollVolumePart>(partValue);
        RectBounds rect = m_bounds;

        if (part == kScrollVolumePartLeading) {
            rect.right = rect.left;
        } else if (part == kScrollVolumePartTrailing) {
            rect.left = rect.right;
        } else if (m_enabled && m_range > 0) {
            const int trackStart = m_bounds.left;
            const int thumbLimit = m_bounds.right - kScrollVolumeThumbSpan;
            int thumbLeft;

            if (m_thumbDragActive) {
                const int cursorAlongTrack = cursor.y;
                const int dragOffsetAlongTrack = m_thumbDragOffset.y;

                thumbLeft = m_bounds.left + cursorAlongTrack - dragOffsetAlongTrack;

                if (thumbLeft < trackStart)
                    thumbLeft = trackStart;
                if (thumbLeft > thumbLimit)
                    thumbLeft = thumbLimit;
            } else {
                thumbLeft = trackStart +
                    ((thumbLimit - trackStart) * m_currentValue) / m_range;
            }

            const int thumbRight = thumbLeft + kScrollVolumeThumbSpan;

            if (part == kScrollVolumePartThumb) {
                rect.left = thumbLeft;
                rect.right = thumbRight;
            } else if (part == kScrollVolumePartPageBeforeThumb) {
                rect.right = thumbLeft;
            } else if (part == kScrollVolumePartPageAfterThumb) {
                rect.left = thumbRight;
            }
        } else if (part == kScrollVolumePartThumb) {
            rect.left += kScrollVolumeThumbSpan;
            rect.right -= kScrollVolumeThumbSpan;
        } else {
            SetRect(&rect, 0, 0, 0, 0);
        }

        if (PointInRect(x, y, &rect))
            return part;
    }

    return kScrollVolumePartNone;
}
```

Notes for implementer:

- The draft intentionally stays within this helper's covered range and does not call `GetPartRect`.
- If support docs do not yet introduce `ScrollVolumePart`, use a local doc note plus `char ScrollVolumePane::HitTestPart(int x, int y)` in the target C++ block. Preferred source-quality direction is to introduce the enum in class/layout support docs.
- The drag branch uses `cursorAlongTrack`/`dragOffsetAlongTrack` to preserve the binary's current component convention without overclaiming the original `Point` member names. If a later coordinate-convention pass proves the project stores horizontal track coordinates in the other component, the variable names can be adjusted without changing the helper's source shape.

## Target doc changes to make later

In `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`:

1. Raise metadata to:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0001H2
EMITTER_UIDS:0001H2
EMITTER_POSITION_OPTIONAL:100
```

2. Replace the stale generated signature note with:

```text
Current source-quality pass rejects the generated `TextEditPane::TrackScrollButtonF(int mouseX, int mouseY)` signature as stale template/name pollution. Direct callers, fields, sibling helpers, and owner/emitter route identify this as `ScrollVolumePane::HitTestPart(int x, int y)`.
```

3. Replace behavior wording that says the helper calls `GetPartRect`. The target builds each candidate rectangle inline; `GetPartRect` at `0x00565010` is the sibling geometry helper with overlapping logic.

4. Replace vertical/top-bottom part names with horizontal names:

```text
0 = leading edge/cap, 1 = page/track before thumb, 2 = thumb, 3 = page/track after thumb, 4 = trailing edge/cap, 0xff/-1 = no hit.
```

5. Add exact binary evidence:

```text
Direct PE/Capstone recheck: function is exactly `0x00564e30-0x00565006`, body size `0x1d6`, ends with `ret 8` at `0x00565003`, has 15 bytes of `0xcc` before the target and 10 bytes of `0xcc` before `0x00565010`, has direct rel32 callers at `0x005649f1` and `0x0056530f`, and has no absolute VA dword route hits for `0x00564e30`.
```

6. Add helper and field facts:

```text
The helper calls `EventMan::GetCursorPosition`, `Pane::GetScreenOffset`/screen-origin helper, `SetRect`/`InitRectBounds`, and `PointInRect`. It uses `m_bounds`, `m_thumbDragActive` at `+0xfb`, `m_currentValue` at `+0xfe`, `m_range` at `+0x100`, `m_enabled` at `+0x102`, and `m_thumbDragOffset` at `+0x108/+0x10c`. The fixed thumb span is `0x26`/38 pixels.
```

7. Add the first-draft C++ block above or a `char`-return variant if the enum is deferred.

8. Replace stale no-C++ gate wording with:

```text
Under the current 85/85 code-entry gate, this source-authored helper is first-draft C++ eligible. Remaining uncertainty in exact coordinate-component member names and the unrecovered writer for `+0xfb` caps confidence but does not require no-code treatment.
```

## Support doc changes to make later

### `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`

- Update the child row for [UID:0001H3] to say first-draft C++ is ready in the child and the helper is `ScrollVolumePane::HitTestPart(int x, int y)`.
- Remove/qualify stale `TextEditPane` generated-signature caveats for [UID:0001H3].
- Correct the sibling relationship:
  - `0x00564e30` hit-tests by inline rectangle construction.
  - `0x00565010` returns/builds a requested part rectangle for callers.
- Correct vertical wording to horizontal part geometry.
- Recommended score if these corrections are incorporated: `COMPLETION:87`, `CONFIDENCE:90` from current `86/89`. If the supervisor wants aggregate score changes only after all ScrollVolumePane sibling helpers are first-draft ready, keep score unchanged and add the corrected child facts.

### `by-class/ScrollVolumePane.md`

- Add or update source-facing declarations:

```cpp
enum ScrollVolumePart {
    kScrollVolumePartLeading = 0,
    kScrollVolumePartPageBeforeThumb = 1,
    kScrollVolumePartThumb = 2,
    kScrollVolumePartPageAfterThumb = 3,
    kScrollVolumePartTrailing = 4,
    kScrollVolumePartNone = -1
};

static const int kScrollVolumeThumbSpan = 38;

ScrollVolumePart HitTestPart(int x, int y);
void GetPartRect(ScrollVolumePart part, RectBounds *rect);
```

- Correct class narrative from vertical/top-bottom slider to horizontal leading/page-before/thumb/page-after/trailing geometry where it describes this part map.
- Add field-name recommendations:
  - `m_thumbDragActive` at `+0xfb` with no recovered local writer.
  - `m_currentValue` at `+0xfe`.
  - `m_range` at `+0x100`.
  - `m_enabled` at `+0x102`.
  - `m_highlightPart` at `+0x103`.
  - `m_activePart` at `+0x104`.
  - `m_thumbDragOffset` at `+0x108/+0x10c`.
- Add rejected stale signature note: `TextEditPane::TrackScrollButtonF` is not a source-facing owner or method name for this class.
- Recommended score if incorporated: `COMPLETION:88`, `CONFIDENCE:88` from current `87/85`, because this pass resolves a class-level stale owner/signature issue and fixes the part enum. If the supervisor wants class score changes deferred until all helper children are updated, keep score unchanged and add these facts.

### `by-file/ScrollVolumePane.md`

- Update file-level source-shape notes to state that `HitTestPart` is now first-draft ready and belongs in `NexusTK/ui/controls/ScrollVolumePane.cpp`.
- Replace stale generated-output caveat with the corrected route:

```text
`0x00564e30` should be modeled as `ScrollVolumePane::HitTestPart(int x, int y)`, not as `TextEditPane::TrackScrollButtonF`. The stale name is generated-signature pollution from scrollbar-like helper matching.
```

- Recommended score if incorporated: `COMPLETION:88`, `CONFIDENCE:87` from current `88/85`.

### `by-type/by-struct/ScrollVolumePaneLayout.md`

- Update part-code/state notes to horizontal part names:
  - `0` leading edge/cap.
  - `1` page/track before thumb.
  - `2` thumb.
  - `3` page/track after thumb.
  - `4` trailing edge/cap.
  - `-1` no hit.
- Update `+0xfb` to `m_thumbDragActive` / `m_thumbDragOverrideActive`; include the no-local-writer caveat.
- Update `+0x108/+0x10c` as `m_thumbDragOffset`, with `+0x10c` documented as the track-axis component consumed by hit-test/GetPartRect drag math pending coordinate-convention cleanup.
- Add constant `kScrollVolumeThumbSpan = 38`.
- Recommended score if incorporated: `COMPLETION:88`, `CONFIDENCE:89` from current `87/88`.

### `by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md` [UID:0001H4]

- Update cross-reference to use `ScrollVolumePane::HitTestPart(int x, int y)` instead of the stale `TextEditPane` helper name.
- Keep [UID:0001H4] C++ policy unchanged unless separately accepted; this report only resolves the [UID:0001H3] helper.

### `by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md` [UID:0001H5]

- Update cross-reference terminology for the part enum and `GetPartRect` geometry names.
- Keep [UID:0001H5] C++ policy unchanged unless separately accepted.

### `by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHighlightPartRaw.md` [UID:0002LB]

- Optional low-risk update: change wording from generic `char part` to `ScrollVolumePart part` in prose if the enum is introduced. No C++ body rewrite is required by this report.

### `by-memory/0x005651e0-0x005652a0.ScrollVolumePaneBeginInteractionRaw.md` [UID:0002LC]

- Optional low-risk update: cross-reference `kScrollVolumePartThumb` for part `2` and note `m_thumbDragOffset` is a track-axis drag offset. Because coordinate component naming remains a known caveat, avoid broad body rewrites here unless a separate pass accepts the coordinate convention.

### `by-type/by-vtable/ScrollVolumePaneVtables.md`

- No code emission change. If touched, add only a concise note that the vtable owner route supports the concrete `ScrollVolumePane` method naming and rejects stale `TextEditPane` names for helper children.

## Score and C++ policy

Target recommendation:

- `COMPLETION:85 -> 88`
- `CONFIDENCE:86 -> 90`
- `RECONSTRUCTABLE:TRUE` unchanged
- `CANONICAL_OWNER:0001H2` unchanged
- `EMITTER_UIDS:0001H2` unchanged
- Add/set `EMITTER_POSITION_OPTIONAL:100`

C++ policy:

- Emit first-draft C++ in target [UID:0001H3].
- Do not emit aggregate C++ in [UID:0001H2] solely because this helper is ready; aggregate remains a container/source-partition doc.
- Do not emit vtable C++ in `ScrollVolumePaneVtables.md`; vtable data remains generated-binary support.
- Do not edit `by-memory/-coverage-report.md`; replacement row below is supervisor-owned.

## Exact implementation checklist for callback

If accepted, implement in this order:

1. Edit `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`.
   - Raise metadata to `88/90`.
   - Keep owner/emitter `0001H2`.
   - Add `EMITTER_POSITION_OPTIONAL:100`.
   - Replace stale `TextEditPane::TrackScrollButtonF` wording with rejected generated-name evidence.
   - Correct behavior to horizontal part map and inline rectangle construction.
   - Add exact PE evidence, callers, callees, padding, and no-VA-hit note.
   - Add helper/field names and `kScrollVolumeThumbSpan = 38`.
   - Add first-draft C++ block.
2. Edit `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`.
   - Update [UID:0001H3] child row/source route and remove stale no-C++ gate language for that child.
   - Correct `HitTestPart`/`GetPartRect` relationship.
   - Optional aggregate score to `87/90` if supervisor accepts support-score changes.
3. Edit `by-class/ScrollVolumePane.md`.
   - Add enum/constant/declaration recommendations.
   - Correct horizontal part names and field names.
   - Add stale `TextEditPane` rejection.
   - Optional score to `88/88`.
4. Edit `by-file/ScrollVolumePane.md`.
   - Update source placement and generated-signature caveat.
   - Optional confidence to `87`.
5. Edit `by-type/by-struct/ScrollVolumePaneLayout.md`.
   - Update part enum, field names, `+0xfb` caveat, and `0x26` constant.
   - Optional score to `88/89`.
6. Edit [UID:0001H4] and [UID:0001H5] only for cross-reference wording if low risk.
7. Do not edit `by-memory/-coverage-report.md`; leave the replacement row to the supervisor.
8. Run scoped validators and autogen as listed below.

## Supervisor-owned coverage row

Exact replacement row for `by-memory/-coverage-report.md` if the target/support edits are accepted:

```text
        - [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md) 0x00564e30-0x00565006 | method | ScrollVolumePaneHitTestPart : reconstructable : 88% : very strong : B014 2026-06-19 source-quality pass raises the modeled ScrollVolumePane hit-test helper to `88/90` and makes first-draft `ScrollVolumePane::HitTestPart(int x, int y)` C++ ready; direct PE/Capstone recheck confirms exact `0x1d6` body, `ret 8`, 15-byte pre-padding and 10-byte post-padding before `GetPartRect`, two direct callers from `OnMouseEvent` and `CommitInteraction`, zero VA dword route hits, stale `TextEditPane::TrackScrollButtonF` rejection, inline five-part rectangle construction instead of a `GetPartRect` call, horizontal part map `Leading/PageBeforeThumb/Thumb/PageAfterThumb/Trailing/None`, fixed thumb span `0x26`/38, `EventMan::GetCursorPosition`, `Pane::GetScreenOffset`/origin helper, `SetRect`/`PointInRect`, fields `m_thumbDragActive` +0xfb, `m_volumeType` +0xfc, `m_currentValue` +0xfe, `m_range` +0x100, `m_enabled` +0x102, `m_highlightPart` +0x103, `m_activePart` +0x104, and `m_thumbDragOffset` +0x108/+0x10c; remaining caveat is exact original coordinate-component naming and no recovered local writer for +0xfb.
```

## Validator commands for implementation callback

Run from `source-3/project-documentation` after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001H3-ScrollVolumePaneHitTestPart-source-quality-removed.md](0001H3-ScrollVolumePaneHitTestPart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validator outcome:

- Target validates with first-draft C++ present.
- Support pages validate if optional score changes are applied consistently.
- Autogen should no longer emit or preserve `TextEditPane::TrackScrollButtonF` for [UID:0001H3]. If autogen still shows that name, the remaining issue is generator/template routing, not target source evidence.

## IDA rename/type/comment recommendations

High confidence:

- Rename function `0x00564e30` to `ScrollVolumePane::HitTestPart`.
- Type `0x00564e30` as `ScrollVolumePart __thiscall ScrollVolumePane_HitTestPart(ScrollVolumePane *this, int x, int y)` if enum support is available, otherwise `char __thiscall ScrollVolumePane_HitTestPart(ScrollVolumePane *this, int x, int y)`.
- Rename/comment `0x00565010` as `ScrollVolumePane::GetPartRect(ScrollVolumePart part, RectBounds *rect)`.
- Add enum comments for part ids `0..4` and `0xff/-1`.
- Comment fixed `0x26` as `kScrollVolumeThumbSpan`.
- Comment `+0xfb` as `m_thumbDragActive` / drag override flag with no recovered local writer in the ScrollVolumePane island.

Medium confidence:

- Rename/comment `0x005447c0` as `Pane::GetScreenOffset` or `Pane::GetScreenOrigin`; source-facing docs should prefer `GetScreenOffset` until the broader pane helper naming pass decides the exact original name.
- Comment `+0x10c` as the track-axis component of `m_thumbDragOffset`; do not hard-lock final `x`/`y` field names until coordinate helper prototypes are reconciled.

Low confidence / do not rename globally from this pass alone:

- `+0xf8` and `+0xfa` state fields. They are adjacent ScrollVolumePane state bytes/word but not essential to [UID:0001H3] source C++ and need their own setter/pass context before final names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001H3-ScrollVolumePaneHitTestPart-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001H3"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001H3-ScrollVolumePaneHitTestPart-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001H3-ScrollVolumePaneHitTestPart-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001H3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
