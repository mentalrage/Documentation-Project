** TARGET-REPORT-UID:0001GU **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GU ScrollCollectionPane HitTestScrollRegion Source-Quality Research

Agent: Agent-B006
Assignment: `B006-report-0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-20260627`
Mode: report-only research
Target: [UID:0001GU] `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md`
Required report path: `tools/leaser/Agents/Agent-B006/research/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md`
Report timestamp: 2026-06-27

## Executive Recommendation

Accept [UID:0001GU] as source-authored `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` and populate first-draft C++ in the target page. The current blank-C++ blockers are stale: live MCP confirms the exact modeled function, caller pair, callee set, boundary/padding, inline part-rectangle loop, point-in-rect behavior, and the same field/helper vocabulary already accepted by the adjacent ScrollCollectionPane helper reports.

Recommended post-implementation metadata:

| Field | Current observed state | Recommendation |
| --- | ---: | ---: |
| `COMPLETION` | `85` | `89` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000CG` | `0000CG` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000CG` | `0000CG` |
| `EMITTER_POSITION_OPTIONAL` | blank | `40` |
| Formal C++ | blank | populate with the C++ block below |

Use [UID:0000CG] `ScrollCollectionPane` as the direct class owner/emitter. [UID:0000NG] `ScrollCollectionPane.md` remains the source-file route under `NexusTK/ui/core/ScrollCollectionPane.cpp`, with the existing broader `ScrollBar.cpp` caveat preserved only as a file-family placement question.

Recommended formal C++ insertion:

```cpp
ScrollCollectionPart ScrollCollectionPane::HitTestScrollRegion(int localY,
                                                               int localX)
{
    for (int partValue = kScrollCollectionPartLeading;
         partValue <= kScrollCollectionPartTrailing;
         ++partValue) {
        const ScrollCollectionPart part =
            static_cast<ScrollCollectionPart>(partValue);
        Point cursor;
        Point origin;
        RectBounds rect;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.x == -1000 && origin.y == -1000) {
            InitRectBounds(&rect, 0, 0, 0, 0);
        } else {
            cursor.x -= origin.x;
            cursor.y -= origin.y;
            rect = m_bounds;

            if (m_orientation == 0) {
                const int thumbSpan =
                    kScrollPanePartExtentBySkin[m_scrollSkinIndex];

                if (part == kScrollCollectionPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollCollectionPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackTop = m_bounds.top;
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y -
                                   m_thumbDragOffset.y;
                        if (thumbTop < trackTop) {
                            thumbTop = trackTop;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = trackTop +
                            ((thumbLimit - trackTop) * m_scrollPosition) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kScrollCollectionPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollCollectionPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollCollectionPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollCollectionPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kScrollCollectionPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollCollectionPartTrailing) {
                    rect.left = rect.right;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackLeft = m_bounds.left;
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kScrollCollectionPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollCollectionPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollCollectionPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollCollectionPartThumb) {
                    rect.left += thumbSpan;
                    rect.right -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }

    return kScrollCollectionPartNone;
}
```

The compiled body constructs the part rectangles inline instead of calling `0x00562bf0` / `GetPartRect`. The recommended draft therefore follows the same inline source shape used by accepted sibling hit-test pages, rather than making this target a call-through wrapper that the binary does not show.

## Current Target State

Observed [UID:0001GU] target state:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000CG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000CG`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++

The existing page says C++ is blank because the adjacent geometry helper lacks its own exact by-memory page and field/helper names were provisional. That is no longer a sufficient blocker. Current ScrollCollectionPane support docs and accepted B-agent implementations now provide the source-facing part, field, helper, and sibling-code names needed for a first-draft body.

## IDA MCP Availability

IDA MCP was available and used. This is not a fallback-only report.

| Field | Value |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` |
| Protocol | `2025-06-18` |
| Active session/database | `b001_000241_20260627` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Module | `NexusTK.exe` |
| Imagebase | `0x400000` |
| Worker PID | `23132` |
| Auto-analysis | ready / `is_analyzing:false` |
| Hex-Rays | ready |
| Strings cache | ready, size `2067` |

MCP calls used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `xrefs_to`, `callees`, `decompile`, `disasm`, `analyze_function`, and `insn_query`.

## Evidence Checked

Primary/support docs:

- [UID:0001GU] `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md`
- [UID:0000CG] `by-class/ScrollCollectionPane.md`
- [UID:0000NG] `by-file/ScrollCollectionPane.md`
- [UID:0001GT] `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`
- [UID:0001VZ] `by-type/by-struct/ScrollCollectionPaneLayout.md`
- [UID:0003MX] `by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md`
- [UID:0003MY] `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`
- [UID:0001GW] `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`
- [UID:0001GX] `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`
- [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md`
- [UID:0003CQ] `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`
- Accepted executed reports for [UID:0001GV], [UID:0001GW], [UID:0001GX], and [UID:0001GY]
- Accepted sibling precedents [UID:0001GQ] `ScrollNewGroupPane::HitTestPart`, [UID:0001GR] `ScrollNewGroupPane::GetPartRect`, and [UID:0002D8] `FittingRoomScrollPane::HitTestPart`

Read-only generated output checked for style precedent:

- `auto-generated/NexusTK/social/Group.cpp`
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
- `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp`

## IDA MCP Findings

### Function Boundary And Padding

MCP confirms [UID:0001GU] is an IDA-modeled function:

| Query | MCP result |
| --- | --- |
| `lookup_funcs 0x005628d0` | `sub_5628D0`, size `0x31d` |
| `lookup_funcs 0x00562bed` | `Not a function` |
| `lookup_funcs 0x00562bf0` | `sub_562BF0`, size `0x287` |
| `entity_query functions 0x00561f00-0x00563090` | includes `sub_5621F0`, `sub_5628D0`, `sub_562BF0`, `sub_562FB0`, and `sub_563070` as separate modeled functions |
| `get_bytes 0x00562bd0 size 48` | shows both target epilogues, three `0xcc` bytes at `0x00562bed-0x00562bf0`, and the next prologue at `0x00562bf0` |

The half-open target range remains exactly `0x005628d0-0x00562bed`. It should not be merged into the draw helper before it or the geometry helper after it.

### Xrefs And Callees

Incoming xrefs to `0x005628d0`:

| Callsite | Function | Meaning |
| --- | --- | --- |
| `0x00562091` | `sub_561FB0` | `ScrollCollectionPane` input/press handler calls hit-test to decide the initial active part |
| `0x0056301f` | `sub_562FB0` | `UpdateDragScroll` calls hit-test to check whether the current cursor remains over the active non-thumb part |

Outgoing callees from `0x005628d0`:

| Callee | Source-facing role |
| --- | --- |
| `0x004a9090` / `sub_4A9090` | `g_pEventMan->GetCursorPosition(&cursor)` |
| `0x005447c0` / `sub_5447C0` | `GetScreenOffset(&origin)` |
| `0x004b7c50` / `sub_4B7C50` | `InitRectBounds(&rect, left, top, right, bottom)` |
| `0x004b7e80` / `sub_4B7E80` | `PointInRect(localY, localX, &rect)` |
| `0x005c772f` | compiler stack-cookie check |

`xrefs_to 0x00562bf0` reports thirteen rectangle-helper callsites across the input handler, draw helper, raw highlight/start-drag children, `UpdateDragScroll`, `UpdatePositionFromCursor`, and reset-state helper. The target [UID:0001GU] does not call `0x00562bf0`; it duplicates the same rectangle-building family inline, just like accepted sibling hit-test pages.

### Target Body

MCP `decompile 0x005628d0`, `disasm 0x005628d0`, and `insn_query 0x005628d0-0x00562bed` show:

- a loop byte initialized to `0` at `0x005628e5`;
- a loop over candidate part ids `0` through `4`;
- each iteration reads cursor position through `dword_67A754` / `sub_4A9090`;
- each iteration reads pane/screen offset through `sub_5447C0`;
- the sentinel `(-1000, -1000)` path bypasses normal cursor-local geometry;
- normal path copies `this+0x44` bounds into a local `RectBounds`;
- orientation byte `this+0xfc` selects vertical (`0`) versus horizontal (`nonzero`) geometry;
- vertical geometry reads `dword_624144[*(__int16 *)(this+0xf8)]` as the fixed extent;
- ranged/enabled geometry gates on `this+0x102` and `this+0x100 > 0`;
- stored scroll position at `this+0xfe` places the thumb when no drag-position override is active;
- vertical drag-position override reads byte `this+0xfb` and offset `this+0x108`;
- part ids choose leading edge, page-before, thumb, page-after, and trailing edge rectangles;
- parts `1` and `3` become empty rectangles when the scroll range is disabled/unavailable;
- the final point test calls `sub_4B7E80(a2, a3, &rect)`;
- the function returns the matching part byte or `-1` / `0xff` after part `4` fails.

MCP `analyze_function 0x004b7e80` decompiles the containment helper as:

```cpp
return rect[0] <= x && x < rect[2] && rect[1] <= y && y < rect[3];
```

This proves the source call order as `PointInRect(localY, localX, &rect)` for this target.

### Sibling Geometry Equivalence

`0x00562bf0` / `GetPartRect` decompiles with the same rectangle formulas and field set, but receives a part id argument and writes the output rectangle. The accepted [UID:0001GQ] `ScrollNewGroupPane::HitTestPart` and [UID:0002D8] `FittingRoomScrollPane::HitTestPart` pages already model this pattern as inline hit-test rectangle construction, not as a mandatory call-through wrapper around `GetPartRect`.

This target should follow the same source-facing shape: the hit-test method builds candidate rectangles inline, calls `PointInRect`, and returns the first matching part.

## Source-Facing Names And Alias Decisions

Recommended source-facing names for this target and support docs:

| Binary item | Recommended source-facing name | Confidence | Rationale |
| --- | --- | ---: | --- |
| `0x005628d0` | `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` | high | Existing page/class name, two caller roles, and `UpdateDragScroll(localY, localX)` call site agree. |
| return type | `ScrollCollectionPart` | medium-high | Existing class page uses `ScrollCollectionPart`; return values are part ids `0..4` and no-part `0xff`. |
| part `0` | `kScrollCollectionPartLeading` | medium-high | Matches sibling `ScrollNewGroupPart`/`FittingRoomScrollPart` conventions. |
| part `1` | `kScrollCollectionPartPageBeforeThumb` | medium-high | Rectangle is track/page area before the thumb. |
| part `2` | `kScrollCollectionPartThumb` | high | Already accepted by [UID:0001GW] and [UID:0003MY]. |
| part `3` | `kScrollCollectionPartPageAfterThumb` | medium-high | Rectangle is track/page area after the thumb. |
| part `4` | `kScrollCollectionPartTrailing` | medium-high | Matches trailing/down-right end part in layout docs. |
| no-part `0xff` | `kScrollCollectionPartNone` | high | Already accepted by [UID:0001GW], [UID:0003MX], [UID:0003MY], and [UID:0001GY]. |
| `this+0xf8` | `m_scrollSkinIndex` | medium-high | Preferred current support alias from `ScrollNewGroupPane` and shared `dword_624144` consumers; historical `m_scrollStyle` is acceptable only as old wording. |
| `dword_624144` | `kScrollPanePartExtentBySkin` vertical slice | medium-high | Shared scrollbar constant data [UID:0003CQ] and `ScrollNewGroupPane::GetPartRect` support this generic name. |
| `this+0xfb` | `m_thumbDragActive` | medium-high | It selects live-cursor/thumb-offset geometry instead of stored-position geometry; sibling hit-test pages use the same alias. |
| `this+0xfc` | `m_orientation` | high | Accepted layout/class alias. |
| `this+0xfe` | `m_scrollPosition` | high | Accepted by `SetScrollPosition` and `UpdatePositionFromCursor`. |
| `this+0x100` | `m_scrollRange` | high | Accepted range/max-range role. |
| `this+0x102` | `m_scrollEnabled` | medium-high | Existing docs call it enabled byte; formal code should use source-shaped member name. |
| `this+0x108/+0x10c` | `m_thumbDragOffset.y / .x` | high | Accepted by [UID:0001GX] and [UID:0003MY]. |
| `0x004b7c50` | `InitRectBounds` | high | Existing generated source and helper docs use this shape. |
| `0x004b7e80` | `PointInRect` | high | Existing generated source uses this name and MCP confirms argument order. |

Rejected or superseded names:

- Do not use `GetScrollRegionRect` in new formal C++; `GetPartRect` is the accepted source-facing geometry helper name.
- Do not use `dword_624144`, `sub_4B7E80`, `sub_4B7C50`, raw offsets, or `v4`-style decompiler names in formal C++.
- Do not model this target as generic `ScrollBar::HitTestPart` yet. It is class-local to `ScrollCollectionPane`; only the final physical file placement remains open.
- Do not leave C++ blank solely because exact original spelling of `m_scrollSkinIndex`, `m_thumbDragActive`, or the part constants is not symbol-proven. The project rules require high-probability source-facing names instead of raw IDA names.

## Positive Evidence

- The target is a real modeled function with exact range `0x005628d0-0x00562bed`.
- MCP reconfirmed the predecessor/successor separation and three-byte padding before `0x00562bf0`.
- There are exactly two direct callers, both inside the `ScrollCollectionPane` input/update cycle.
- The target returns a compact part id from `0` through `4` or `-1`.
- The callee set is only cursor position, pane origin, rectangle initialization, point-in-rect, and stack-cookie check.
- Current support docs already accept `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `kScrollCollectionPartNone`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `HitTestScrollRegion`, `GetPartRect`, `UpdateDragScroll`, and `UpdatePositionFromCursor`.
- [UID:0001GQ] `ScrollNewGroupPane::HitTestPart` has the same modeled size, same inline rectangle geometry, same caller/callee family, same generated formal C++ structure, and same adjacent `GetPartRect` relationship.
- [UID:0002D8] `FittingRoomScrollPane::HitTestPart` independently confirms the same five-part source model and inline hit-test source shape.

## Negative Evidence And Rejected Alternatives

- No preserved original enum, member, or table symbol was found in IDA. The names above are source-facing inferences.
- The target does not call `0x00562bf0`, so a formal body that only calls `GetPartRect(part, &rect)` would hide the observed inline geometry. That may be source-plausible under inlining, but the accepted sibling style for this exact pattern is to write the hit-test geometry inline.
- The adjacent `0x00562bf0` helper lacks an exact by-memory page today. That is a support-document gap for `GetPartRect`, but it is not a blocker to [UID:0001GU] because this target's own body is modeled, bounded, and documented with the same inline geometry.
- The final physical source file may later fold into [UID:0000NF] `ScrollBar.md`. That does not change the direct method owner/emitter for [UID:0001GU].
- The exact original spelling of `HitTestScrollRegion` versus `HitTestPart` is not symbol-proven. Keep current `HitTestScrollRegion` because existing callers/support docs already use it and it avoids unnecessary churn.

## Heuristic / Inference Reanalysis And Validation

The previous unresolved questions can be resolved without waiting for later C++ work:

| Old blocker/question | Resolution |
| --- | --- |
| Field/helper names provisional | Current support docs and accepted sibling implementations now provide source-facing names. Remaining exact-symbol uncertainty is a confidence cap, not a blank-C++ blocker. |
| Adjacent `0x00562bf0` lacks an exact page | Not a blocker for this target. [UID:0001GU] builds rectangles inline and only needs to reference `GetPartRect` as a sibling equivalence/support helper. |
| Part ids only known as raw `0..4` | Promote full `ScrollCollectionPart` constants using sibling scroll-part naming: leading, page-before-thumb, thumb, page-after-thumb, trailing, none. |
| `+0xf8` table-index name unclear | Use `m_scrollSkinIndex` and shared `kScrollPanePartExtentBySkin` for new formal C++; preserve historical `m_scrollStyle` as an alias only if needed. |
| `+0xfb` drag flag unclear | Use `m_thumbDragActive`, because the binary uses it to switch vertical thumb geometry to live cursor minus `m_thumbDragOffset`. |
| Formal C++ blank until final source | Rejected. Active project rules require a draft C++ block once evidence clears the gate. This target has exact boundary, source owner, callers, body, helper names, and sibling precedent. |

## Recommended Target Documentation Edits

For `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md`:

- Set `COMPLETION:89`, `CONFIDENCE:91`, keep owner/emitter `0000CG`, and set `EMITTER_POSITION_OPTIONAL:40`.
- Insert the formal C++ block from this report.
- Update the item summary to mention first-draft C++, exact modeled boundary, two callers, inline five-part rectangle loop, cursor/origin sentinel handling, vertical/horizontal orientation, `m_scrollSkinIndex`, `m_thumbDragActive`, `m_scrollPosition`, `m_scrollRange`, `m_scrollEnabled`, `m_thumbDragOffset`, `PointInRect`, and the stale blocker resolution.
- Replace blank-C++ wording with the current source-ready rationale and remaining confidence caps.
- Preserve exact MCP evidence for current session `b001_000241_20260627`.

For `by-class/ScrollCollectionPane.md`:

- Add full `ScrollCollectionPart` constants: leading, page-before-thumb, thumb, page-after-thumb, trailing, none.
- Record that [UID:0001GU] now emits first-draft `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` C++ at child position `40`, before the already-emitting interaction/update children at positions `50`, `60`, `70`, and `80`.
- Add/support `m_scrollSkinIndex`, `m_thumbDragActive`, `m_scrollEnabled`, and `kScrollPanePartExtentBySkin` aliases where needed for this target.
- Preserve the current class score `88/90` unless the supervisor wants a broader class pass; this report mainly resolves one child.

For `by-file/ScrollCollectionPane.md`:

- Record [UID:0001GU] as a source-ready formal child under the current `ScrollCollectionPane.cpp` route.
- Preserve the possible later `ScrollBar.cpp` merge caveat.
- No required score change.

For `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md`:

- Update the child row/status for [UID:0001GU] to say it now emits exact first-draft C++.
- Keep aggregate C++ blank; child method bodies should not be duplicated in the aggregate.
- No required score change.

For `by-type/by-struct/ScrollCollectionPaneLayout.md`:

- If touched, clarify `+0xf8` as `m_scrollSkinIndex` / historical `m_scrollStyle`, `+0xfb` as `m_thumbDragActive`, `+0x102` as `m_scrollEnabled`, and note [UID:0001GU]'s use of those fields.
- Keep layout score unchanged unless a broader layout audit is performed.

For `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`:

- Optional only: add [UID:0001GU] as another `dword_624144` / `0x00624144` vertical fixed-extent consumer.
- No required score change.

## IDA DB Recommendations

Do not modify the IDA database as part of this report. The target is already modeled as `sub_5628D0`, and this report's output is documentation/source reconstruction, not an IDA rename/type/comment callback.

If a later supervisor-authorized IDA naming pass occurs, a non-invasive rename/comment candidate is `ScrollCollectionPane::HitTestScrollRegion` at `0x005628d0`, but that is out of scope for this report-only task.

## Score And Blocker Disposition

Recommended score: `89/91`.

Rationale for the increase:

- Exact function boundary, padding, caller set, callee set, decompile, and instruction-level loop are live-MCP confirmed.
- Source-facing names for the helper cluster have been resolved by adjacent accepted B-agent work.
- The previous formal-C++ blocker is now a resolved source-quality issue, not a valid reason to keep blank C++.
- The function can emit a source-shaped first-draft body matching accepted sibling hit-test style.

Reasons not higher:

- Exact original enum/member/table spellings are inferred, not symbol-recovered.
- The final physical source file remains `ScrollCollectionPane.cpp` versus possible broader `ScrollBar.cpp` fold.
- The adjacent `GetPartRect` helper still lacks its own exact by-memory page, even though it no longer blocks this target.

Reasons not lower:

- The body is not raw/no-route; it is a normal modeled function.
- The call graph is class-local and narrow.
- The code shape has two strong accepted sibling precedents.
- Existing `ScrollCollectionPane` support docs are already at `88/90` and adjacent source-bearing children now clear `87/90+`.

## Validation Commands Expected After Implementation

Run validators only after a supervisor implementation callback and accepted by-* edits.

Working directory:

> Executable block R001 was removed from this report and preserved verbatim in [0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md](0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Required scoped validators:

> Executable block R002 was removed from this report and preserved verbatim in [0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md](0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional constants page is edited:

> Executable block R003 was removed from this report and preserved verbatim in [0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md](0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not hand-edit generated source/tracker/coverage reports or any manual `-coverage-report.md` files. Let validators refresh generated artifacts.

## Original Report-Only No-Edit Proof

- During the original report-only research pass, no by-* target/support docs were edited.
- During the original report-only research pass, no generated files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB were edited.
- During the original report-only research pass, no leases were taken because that phase was report-only research.
- During the original report-only research pass, no validators were run because no by-* files were edited.

## Implementation Callback Addendum

Supervisor implementation callback was received through `tools/leaser/Agents/Agent-B006/goal.md` assignment `B006-implement-0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-20260627`. The accepted report was implemented into the target/support by-* docs, validators were run, and the checklist below records the current implementation proof. No generated reports/source, manual `-coverage-report.md` files, IDA DB, or MCP process state were manually edited.

## Implementation Tracking Checklist

- [x] Confirm supervisor implementation callback is present before editing by-* target/support docs. Proof: `tools/leaser/Agents/Agent-B006/goal.md` assignment `B006-implement-0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-20260627` explicitly accepted this report for implementation and named the target/support pages.
- [x] Lease only the immediate by-* files being edited, immediately before edits; release leases immediately after the edit/validator batch. Proof: `python tools\leaser\leaser.py B006 lease ...` succeeded for the six touched by-* files before editing. Cleanup after validators reported `Rejected[No active lease]` for all six paths, and `tools/leaser/Agents/current_leases.md` had no `B006`, `ScrollCollectionPane`, `0x005628d0`, `0x00561db0`, or `0x00624138` active rows.
- [x] Update [UID:0001GU] target metadata to `COMPLETION:89`, `CONFIDENCE:91`, owner/emitter `0000CG`, and `EMITTER_POSITION_OPTIONAL:40`. Proof: `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md` header now has `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CG`, `EMITTER_UIDS:0000CG`, and `EMITTER_POSITION_OPTIONAL:40`; validator command `000000004835` confirmed `completion_update 0001GU 89`, `confidence_update 0001GU 91`, and autogen registry position `40`.
- [x] Insert the accepted `ScrollCollectionPane::HitTestScrollRegion(int localY, int localX)` formal C++ block into the target `RECONSTRUCTION_CPP CODE` header. Proof: target `RECONSTRUCTION_CPP CODE:BEGIN/END` now contains the accepted formal C++ body with full inline five-part geometry, source-facing part constants, field aliases, cursor/origin sentinel handling, and `PointInRect(localY, localX, &rect)`; validator command `000000004835` reported `autogen_registry_update ... blank -> block`.
- [x] Update the target body with report-level MCP facts: current session/database, boundary, padding, two callers, callee set, inline part loop, field/table aliases, point-in-rect helper, and stale blocker resolution. Proof: target Status, Behavior, Touched State And Calls, IDA MCP Evidence, Reconstruction Notes, Score Rationale, Item Summary, and Changes now record session `b001_000241_20260627`, database/input paths, exact boundary/padding, caller pair, callee set, inline loop, field/table aliases, `InitRectBounds`, `PointInRect`, and why the adjacent `GetPartRect` page gap is not a C++ blocker.
- [x] Update `by-class/ScrollCollectionPane.md` with full `ScrollCollectionPart` constants and [UID:0001GU] source-ready child status. Proof: Source-Facing Scroll Part Aliases now lists leading, page-before-thumb, thumb, page-after-thumb, trailing, none, `m_scrollSkinIndex`, `m_thumbDragActive`, `m_scrollEnabled`, and `kScrollPanePartExtentBySkin`; Method Notes and Parent And Score Rationale list [UID:0001GU] as first-draft C++ at position `40` with `89/91`.
- [x] Update `by-file/ScrollCollectionPane.md` with [UID:0001GU] source-ready status while preserving the `ScrollBar.cpp` caveat. Proof: Hypothesis, Proposed Contents, Score Rationale, and Changes now list [UID:0001GU] as source-ready under current `ScrollCollectionPane.cpp`; Migration Notes and confidence cap still preserve possible later [UID:0000NF] `ScrollBar.cpp` merge.
- [x] Update aggregate [UID:0001GT] child row/status for [UID:0001GU] and keep aggregate C++ blank. Proof: `by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md` Item Summary, Status, Covered Functions, IDA MCP Evidence, Barrier Repair And Routing, and Changes now identify [UID:0001GU] as a source-ready exact child at position `40`; aggregate `RECONSTRUCTION_CPP CODE` remains blank with rationale that exact children own method bodies.
- [x] Update layout [UID:0001VZ] only as needed for `m_scrollSkinIndex`, `m_thumbDragActive`, and `m_scrollEnabled` aliases; do not raise score unless a broader layout audit is done. Proof: `by-type/by-struct/ScrollCollectionPaneLayout.md` keeps `COMPLETION:85`, `CONFIDENCE:88`, and updates only the relevant field rows, part-code table, IDA MCP Evidence, Reconstruction Notes, and Changes for the accepted aliases and [UID:0001GU] usage.
- [x] Optionally update constants [UID:0003CQ] to add [UID:0001GU] as another `dword_624144` consumer if the supervisor accepts the support edit. Proof: `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` Item Summary, Observed Contents, Evidence, Related Documentation, and Changes now list [UID:0001GU] as another `dword_624144` / `kScrollPanePartExtentBySkin` vertical fixed-extent consumer; score/metadata unchanged.
- [x] Do not edit generated reports/source, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB. Proof: no manual edits were made to generated/project/coverage/IDA files; validator-owned side effects were produced only by scoped validator commands (`tools/validator.ini`, projected stats, autogen registry, reference index, and deferred generated refresh).
- [x] Run scoped validators for every touched by-* file and record command id, timestamp, exit code, `ok`, warnings, and generated-refresh state. Proof: all commands ran from `E:\NTK\GhidraBridge\source-3\project-documentation` and exited `0` with `ok: 1`: `000000004835` at `2026-06-27T23:53:59-04:00` for [UID:0001GU] target; `000000004836` at `2026-06-27T23:54:07-04:00` for `by-class/ScrollCollectionPane.md`; `000000004837` at `2026-06-27T23:54:09-04:00` for `by-file/ScrollCollectionPane.md`; `000000004839` at `2026-06-27T23:54:19-04:00` for aggregate [UID:0001GT]; `000000004840` at `2026-06-27T23:54:30-04:00` for layout [UID:0001VZ]; `000000004842` at `2026-06-27T23:54:37-04:00` for constants [UID:0003CQ]. Each reported `generated_refresh: deferred`.
- [x] Re-read the target/support docs after validation and check off this list with exact proof for each implemented item. Proof: post-validation stale-phrase check confirmed remaining `blank-C++`/`omitted scoped method` matches are only intentional aggregate blank-C++ rationale, historical change-log "Before" entries, or target text saying the blank-C++ blocker is resolved; no active target/support status contradicts the accepted implementation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md","timestamp":"2026-06-28T00:04:46","uid":"0001GU"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001GU-ScrollCollectionPaneHitTestScrollRegion-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
