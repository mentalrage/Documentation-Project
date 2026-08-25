** TARGET-REPORT-UID:0001GI **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B010 Report - [UID:0001GI] ScrollPaneOnDraw Source Quality

Assignment id: `B010-report-0001GI-scroll-pane-on-draw-source-quality-20260626`

Target: [UID:0001GI] `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`

Mode: report-only research. No by-* documentation was edited in this phase.

## Recommendation Summary

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CM
```

Recommended source route stays `ScrollPane` [UID:0000CM] through source file [UID:0000NF] `ScrollBar`. The current `85/88` target page already has the correct owner/emitter route, exact half-open range, and vtable-only reachability. This pass raises the recommended score because the prior blocker list can now be narrowed: the shared helper names are no longer just generic generated labels, the important field names are supported by the freshly split ScrollPane child pages, the EPF/classic resource names and table consumers are current-session MCP backed, and first-draft formal C++ is defensible under the current 85/85 code-entry rule.

Do not raise this target above the low-90s yet. The target is a large 4871-byte virtual draw body with 142 basic blocks and 82 cyclomatic complexity in the current MCP analysis. The first-draft source shape is supportable, but exact original local helper spellings for classic frame selection, the final declaration of the draw-mode byte at `+0x70`, and the public names of `GrafPort`/`Surface` helper wrappers remain inferred.

## Evidence Checked

Current MCP session:

- `idb_list` found active session `80de0a67` for `NexusTK.exe.i64`; `server_health` reported healthy, auto-analysis ready, Hex-Rays ready, strings cache ready, and imagebase `0x400000`.
- `lookup_funcs` confirmed `0x0055c650 -> sub_55C650`, size `0x1307` / decimal `4871`, and no function at the exclusive endpoint `0x0055d957`; successor function starts at `0x0055d960`.
- `get_bytes 0x0055d957 size 16` returned nine `0xcc` bytes before the successor prologue, confirming the target end and padding boundary.
- `analyze_function 0x0055c650 include_asm=false` returned prototype `char __thiscall(int this)`, size `4871`, 142 blocks, cyclomatic complexity `82`, callees `sub_457A60`, `sub_4A9090`, `sub_4B7C50`, `sub_4B7CC0`, `sub_4B7E10`, `sub_4B9660`, `sub_4B96C0`, `sub_4B9980`, `sub_4BA6B0`, `sub_4D02F0`, `sub_5447C0`, `sub_55C3E0`, `sub_55D9E0`, `unk_69B3FC`, and the security-cookie check.
- `analyze_function 0x0055c650 include_asm=true` confirmed the major control/data anchors used below, including the `g_useEpfAssets` branch at `0x0055c663`, EPF library loads through `dword_67A744` / `dword_67A754`, current clip fetch through `sub_4B96C0`, resource lookup through `sub_4D02F0`, tile render through `sub_4B9980`, classic/tiled background render through `sub_4BA6B0`, color/fill preparation through `sub_4B9660` plus `unk_69B3FC`, and four direct calls to `ScrollPane::GetScrollPartRect`.
- `xrefs_to 0x0055c650` from the earlier current-session check found the single data route from vtable slot `0x00623da0`; no direct code callers were found.
- `xrefs_to 0x0055d9e0` confirmed 15 callers for `ScrollPane::GetScrollPartRect`, including the four OnDraw call sites at `0x0055ce8f`, `0x0055cf4c`, `0x0055d664`, and `0x0055d77f`.
- `xrefs_to 0x0055c3e0` confirmed draw and geometry consumers of `ScrollPane::IsScrollThumbVisible`; the current child page records ten direct xrefs, eight from this draw method and two from `GetScrollPartRect`.
- `entity_query names` around `0x0061879c` and `0x0060ddb0` plus `get_bytes` decoded current wide string evidence:
  - `0x0061879c`: `SCRL001.PAD`
  - `0x006187b8`: `SCRL001.EPF`
  - `0x006187cc`: `SCRL001.EPD`
  - `0x0060ddb0`: `SLIDEBG.EPF`
  - `0x0060ddc8`: `SLIDEBG.PAL`
  - `0x0060dde0`: `SCRBUTT.EPF`
  - `0x0060ddf8`: `BUTTON.PAL`
- `get_bytes 0x00624144 size 24` showed `38, 38, 38, 13, 12, 12`; `get_bytes 0x0062415c size 24` showed `13, 10, 10` followed by the UTF-16 start of `SCRBUTT2.EPF`. The draw method references the exact `0x00624144` and `0x0062415c` tables as small scrollbar dimension/style constants.
- `xrefs_to 0x00624144` reported 22 refs, including four from this target and consumers in `ScrollPane::GetScrollPartRect`, ScrollablePane layout, and specialized scroll pane draw/layout methods. `xrefs_to 0x0062415c` reported 12 refs, including six from this target and consumers in geometry/update helpers. These are shared generic scroll constants, not target-local globals.
- `xrefs_to 0x0061879c`, `0x006187cc`, `0x0060ddb0`, `0x0060ddc8`, `0x0060dde0`, and `0x0060ddf8` tie the classic and EPF literals to this target and sibling themed scroll panes. Resource sharing is not ownership evidence.

Current by-* and report evidence checked:

- Target page [UID:0001GI] `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`.
- [UID:0000CM] `by-class/ScrollPane.md`.
- [UID:0000NF] `by-file/ScrollBar.md`.
- [UID:00042V] `ScrollPaneConstructor`, [UID:00042W] raw range setter, [UID:00042X] raw byte-state setter, [UID:000432] `ScrollPaneIsScrollThumbVisible`, [UID:000433] mouse handler, [UID:000434] `ScrollPaneCanScroll`, and [UID:000435] timer callback.
- [UID:0001GK] `ScrollPaneGetScrollPartRect`.
- [UID:0003A5] `ScrollPaneInputGeometryHelpers`.
- [UID:0003CK] `ScrollPaneVtableData`.
- [UID:00026D] `ScrollPaneReadOnlyData` and [UID:0003CQ] `ScrollPaneScrollbarConstantData`.
- [UID:0000SW] `g_useEpfAssets`.
- [UID:0000XY] `EPFTileContext`, [UID:00015S] `RectGeometryHelpers`, [UID:000162] `GrafPortDrawStateAccessors`, [UID:000164] `GrafPortGetClipRect`, [UID:000165] `SurfacePaintHelpers`, [UID:00016A] `GrafPortDrawTiledBackground`, [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry`, and [UID:0000TN]/[UID:0001PI] render callback table docs where found.
- Executed B004 `0001GH-ScrollPaneInputCore-source-quality.md` for current field names and receiver/route decisions.
- Executed B002 FittingRoom scroll-pane draw/hit/timer report and the implemented [UID:0002D6] FittingRoom scroll draw page as a sibling draw-method precedent.
- `auto-generated/NexusTK/ui/core/ScrollBar.cpp`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-research-tracker.md` were checked only as generated/stale leads. They still show older empty-emitter/low-score state for [UID:0001GI] and must not be treated as source of truth.

## Current Target State

Current target header:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000CM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CM
RECONSTRUCTION_CPP CODE: blank
Item Summary: vtable-only ScrollPane draw virtual; exact boundary, vtable slot, four GetScrollPartRect calls, classic/EPF resources, callee set, padding.
```

Current generated state is stale. `auto-generated/NexusTK/ui/core/ScrollBar.cpp` still renders [UID:0001GI] as `Completion:78 | Confidence:86 | Empty Emitter Marker`, and the research tracker still lists it as not covered. The by-memory file is the source-of-truth for this report; implementation should update the source by-* file and run validators rather than manually editing generated/project-level files.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Best owner: [UID:0000CM] `ScrollPane`.

Evidence:

- The only direct reachability route is the `ScrollPane` vtable slot at `0x00623da0`; no direct code callers were found.
- The constructor child [UID:00042V] installs the `ScrollPane` primary, EventHandler, and TimerHandler vtables and initializes the same state fields consumed by this draw body.
- The vtable-data page [UID:0003CK] already routes the surrounding `ScrollPane` primary/adjusted vtable family to `ScrollPane`; [UID:0001GI] is listed as a related draw slot.
- The body reads `ScrollPane` state at `+0xf8`, `+0xfa`, `+0xfb`, `+0xfc`, `+0xfe`, `+0x100`, `+0x102`, `+0x103`, and inherited pane bounds at `+0x44`.
- `ScrollPane::GetScrollPartRect` and `ScrollPane::IsScrollThumbVisible` are current `ScrollPane` children and direct dependencies of this body.

Best source file: [UID:0000NF] `ScrollBar`.

Evidence:

- The file page records generic scrollbar infrastructure and explicitly includes `ScrollPane` draw/geometry/input helpers.
- `ScrollablePane` constructs horizontal and vertical `ScrollPane` children, and multiple text-edit/scrollable consumers call the generic `ScrollPane` geometry helper rather than owning this draw routine.
- Shared resource strings and shared Surface/GrafPort helpers are consumer/dependency evidence only. They do not move this method into FittingRoom, Ranking, TextEditPane, or Surface.

Rejected owner alternatives:

- `FittingRoomScrollPane`: rejected. [UID:0002D6] shares `SLIDEBG`/`SCRBUTT` art and rendering helpers but has a separate vtable neighborhood, fitting-room-local state/table route, and FittingRoom class owner. B002 already documented that [UID:0002D6] cannot prove generic `ScrollPane` ownership of FittingRoom code; the reverse is also true.
- `TextEditPane`: rejected. TextEditPane scrollbar handlers consume `ScrollPane::GetScrollPartRect`; they do not own the generic `ScrollPane` draw slot.
- `Surface`, `GrafPort`, `EPFTileContext`, `ResourceLayoutTable`, or render callback table: rejected. These are callee/helper owners. Their functions should be named in the target prose and formal draft, but their ownership does not absorb this `ScrollPane` virtual body.
- Generated helper-owner labels such as `RankingEventListPane::GetClipRect`, `FittingRoomDownloadControlPane::RenderTileFrame`, and `FittingRoomListPane::SetTextColor`: rejected as caller-biased generated pollution. Current support docs identify the source-facing roles as generic clip, draw-color, pane-region/fill callback, `ResourceLayoutTable::LookupLayoutEntry`, `RenderTileFrame`, and GrafPort tiled-background/render helpers.

### Field And Type Name Resolution

The current pass can replace the target's old generic field uncertainty with the field names already accepted on exact ScrollPane child pages:

| Offset | Best source-facing name | Evidence |
| --- | --- | --- |
| `+0x44` | inherited `m_bounds` / pane bounds rect | Constructor/input children and broad Pane docs use `this+0x44` as the inherited bounds rectangle; draw copies it repeatedly for clipping and rendering. |
| `+0x70` | inherited draw/blit mode byte | Many paint docs record direct clears/stores before fill/render callbacks. In this body it is cleared to `0` before normal fill/prep and set to `2` in disabled classic branches. Exact public field name remains broader GrafPort/Pane work. |
| `+0xf8` | `m_scrollStyle` or `m_trackStateWord` depending consumer | Constructor sets `m_trackStateWord = 0` and `m_scrollStyle = 1`; raw setters prove word/byte state. In this draw body the word is used as a style/table index into `0x00624144` and `0x0062415c`, so source prose should call it the style/table index, not a raw `word_`. |
| `+0xfa` | `m_scrollStyle` / nonzero classic fallback style byte | [UID:00042X] proves the raw byte setter; disabled classic branch tests it before drawing fallback art. |
| `+0xfb` | drag/adjustment flag | This draw body and the geometry helpers branch on it while adjusting thumb/track rectangle extents; exact source spelling remains inferred. |
| `+0xfc` | `m_orientation` | Constructor stores `horizontal ? 1 : 0`; class page defines `0 = vertical`, `1 = horizontal`. Draw uses this branch throughout. |
| `+0xfe` | `m_scrollPosition` | Geometry and draw calculations compare/current-position against range. |
| `+0x100` | `m_scrollRange` | Visibility predicate formal C++ proves `m_enabled && m_scrollRange > 0`; draw tests it before drawing an active thumb/track. |
| `+0x102` | `m_enabled` | Visibility predicate and mouse handler docs use it as enabled byte. Draw clears/fallbacks when it is false. |
| `+0x103` | `m_highlightPart` / hot part | Draw uses it to select button/thumb frames for parts `0`, `1`, `2`, `3`, and `4`. Class page calls this pressed/hot state around `+0x103/+0x104`; exact split between hover and active remains inferred. |
| `+0x104` | `m_activePart` | Timer callback formal C++ uses this as active part and compares to none. |

The final implementation prose should keep raw offsets as evidence aliases but should not leave `byte_`, `dword_`, `sub_`, or unrelated generated owner names as source-facing terminology.

### Helper Name Resolution

Current support is sufficient to use these source-facing helper names in target prose and first-draft C++:

| Raw label | Source-facing role for this target | Support |
| --- | --- | --- |
| `sub_457A60` | `InitTileContext` / `EPFTileContext::Initialize` | [UID:0000XY] and many paint-handler reports use this as EPF tile context setup. |
| `sub_4A9090` and `sub_5447C0` | cursor/origin or pane-local coordinate conversion helpers | Still descriptive; enough for prose, but do not overclaim final public names. |
| `sub_4B7C50` | `InitRectBounds` / rectangle initializer | [UID:00015S] rectangle helper family. |
| `sub_4B7CC0` | `IntersectRects` | [UID:00015S] and B001 RectBounds report document this name and nullable/output behavior. |
| `sub_4B7E10` | `OffsetRect` | [UID:00015S] rectangle offset helper. |
| `sub_4B9660` | `GrafPort::SetDrawColor` / active draw-fill color setter | [UID:000162] and multiple B-agent paint reports prove `+0x74` draw color. |
| `sub_4B96C0` | `GrafPort::GetClipRect` | [UID:000164] clip helper docs. |
| `sub_4B9980` | shared `RenderTileFrame` wrapper | [UID:000165], callback table docs, and many accepted paint reports reject generated fitting-room ownership. |
| `sub_4BA6B0` | `GrafPort::DrawTiledBackground` / classic tiled-background draw helper | [UID:00016A] and callback-table docs place it in GrafPort/Surface tile/background rendering. |
| `sub_4D02F0` | `ResourceLayoutTable::LookupLayoutEntry` | [UID:0002KP] and paint/resource reports. |
| `unk_69B3FC` | pane-region fill/invalidate/presentation callback after draw-color setup | [UID:0000TN]/callback-table docs identify slot-7 style fill/prep consumers; do not use stale `g_pfnLockSurface` as source name here. |
| `sub_55C3E0` | `ScrollPane::IsScrollThumbVisible` | [UID:000432], formal C++ already present. |
| `sub_55D9E0` | `ScrollPane::GetScrollPartRect` | [UID:0001GK], direct 15-caller geometry child. |

`dword_67A744` and `dword_67A754` should be normalized to current EPF/resource layout table globals, with the exact global split taken from the support docs at implementation time. This report uses `g_pEPFLib` and `g_pResourceLayoutTable` as source-facing names because current accepted paint reports use them for the same lookup family; raw labels remain evidence aliases only.

### Draw Behavior

The body starts by initializing an `EPFTileContext` stack object and reading the current clip rectangle. It then splits on `g_useEpfAssets`:

- EPF/high-resource mode (`byte_66DA97 == 1`) uses `SLIDEBG.EPF`/`SLIDEBG.PAL` for the track/background strips and caps, and `SCRBUTT.EPF`/`BUTTON.PAL` for the thumb. It repeats horizontal and vertical rectangle arithmetic, intersects each candidate with the clip rect, clears/fills the pane-region with draw color `0`, restores draw color `0x80`, looks up the correct EPF frame, renders one-pixel strips through `RenderTileFrame` and `OffsetRect`, then renders cap/thumb frames.
- Classic mode uses `SCRL001.PAD` and `SCRL001.EPD`, the small scroll dimension/style tables at `0x00624144` and `0x0062415c`, `GetScrollPartRect`, `RenderTileFrame`, and `GrafPort::DrawTiledBackground` style helpers. It still uses the same `m_orientation`, `m_scrollStyle`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, and hot/active part state.
- Disabled/no-range branches do not just skip drawing. They set draw color, change the inherited draw/blit mode byte, and call the slot-7 pane-region fill/prep callback over the relevant rectangle/bounds, matching other accepted paint-handler interpretations of `dword_69B3FC`.

The accepted part-id contract remains:

```text
0 = first/start button
1 = track/page before thumb
2 = thumb
3 = track/page after thumb
4 = second/end button
255 / -1 = no active part
```

### First-Draft C++ Decision

Formal first-draft C++ is recommended. Keeping the target C++ blank would now be too weak because:

- The function is a modeled `ScrollPane` vtable method with current MCP-backed range, padding, vtable route, callee set, resources, tables, and field offsets.
- The exact child split under [UID:0001GH] now gives source-facing ScrollPane field names and confirms the `IsScrollThumbVisible` predicate and timer/active-part names.
- Accepted sibling paint pages already use source-facing names for `InitTileContext`, `ResourceLayoutTable::LookupLayoutEntry`, `RenderTileFrame`, `GrafPort::SetDrawColor`, `IntersectRects`, `OffsetRect`, `GrafPort::DrawTiledBackground`, and slot-7 pane-region fill/prep callbacks.
- The old blocker was "generic helper/source names are unresolved"; the current helper docs narrow that to final original spelling only, not first-draft readiness.

The block below is first-draft and should not be scored as final-source quality. It intentionally uses descriptive, human source-facing helper names for the classic frame-selection and pane-region prep operations. If implementation wants to avoid private helper declarations, the frame-selection helpers can be expanded inline; they should not be emitted as new out-of-line binary helpers unless a matching source helper policy is accepted.

Recommended exact formal block content:

```cpp
void ScrollPane::OnDraw()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    const bool horizontal = (m_orientation != 0);
    const bool hasThumb = IsScrollThumbVisible();

    if (g_useEpfAssets) {
        if (hasThumb) {
            const ScrollPanePart trackParts[2] = {
                kScrollPanePartPageBeforeThumb,
                kScrollPanePartPageAfterThumb
            };

            for (int i = 0; i < 2; ++i) {
                const ScrollPanePart part = trackParts[i];

                GetScrollPartRect(part, &partRect);
                if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                    continue;
                }

                SetDrawColor(0);
                PreparePaneRegion(&drawRect);
                SetDrawColor(0x80);

                const int fillFrame = horizontal ? 4 : 1;
                const int capFrame = horizontal
                    ? (part == kScrollPanePartPageBeforeThumb ? 3 : 5)
                    : (part == kScrollPanePartPageBeforeThumb ? 0 : 2);

                g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

                stripRect = drawRect;
                if (horizontal) {
                    stripRect.right = stripRect.left + 1;
                    while (stripRect.left < drawRect.right) {
                        RenderTileFrame(&tile, &tile.bounds, &stripRect, 1, L"SLIDEBG.PAL", 0);
                        OffsetRect(&stripRect, 1, 0);
                    }
                } else {
                    stripRect.bottom = stripRect.top + 1;
                    while (stripRect.top < drawRect.bottom) {
                        RenderTileFrame(&tile, &tile.bounds, &stripRect, 1, L"SLIDEBG.PAL", 0);
                        OffsetRect(&stripRect, 0, 1);
                    }
                }

                g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"SLIDEBG.PAL", 0);
            }

            GetScrollPartRect(kScrollPanePartThumb, &partRect);
            if (IntersectRects(&drawRect, &partRect, &clipRect)) {
                SetDrawColor(0);
                PreparePaneRegion(&drawRect);
                SetDrawColor(0x80);

                const int frame = (m_highlightPart == kScrollPanePartThumb) ? 1 : 0;
                g_pEPFLib->LookupLayoutEntry(L"SCRBUTT.EPF", frame, &tile);
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"BUTTON.PAL", 0);
            }
        } else {
            SetDrawColor(0);
            PreparePaneRegion(&m_bounds);
        }

        return;
    }

    if (hasThumb) {
        const ScrollPanePart parts[5] = {
            kScrollPanePartFirstButton,
            kScrollPanePartPageBeforeThumb,
            kScrollPanePartThumb,
            kScrollPanePartPageAfterThumb,
            kScrollPanePartSecondButton
        };

        for (int i = 0; i < 5; ++i) {
            const ScrollPanePart part = parts[i];

            GetScrollPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            const int frame = ResolveClassicScrollFrame(part, horizontal, m_highlightPart, m_scrollStyle);
            g_pResourceLayoutTable->LookupLayoutEntry(L"SCRL001.EPD", frame, &tile);

            if (part == kScrollPanePartPageBeforeThumb ||
                part == kScrollPanePartPageAfterThumb) {
                DrawTiledBackground(&tile, &drawRect, L"SCRL001.PAD");
            } else {
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 0, L"SCRL001.PAD", 0);
            }
        }

        return;
    }

    if (m_scrollStyle != 0) {
        GetScrollPartRect(kScrollPanePartFirstButton, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            g_pResourceLayoutTable->LookupLayoutEntry(
                L"SCRL001.EPD",
                ResolveClassicScrollFrame(kScrollPanePartFirstButton, horizontal, m_highlightPart, m_scrollStyle),
                &tile);
            RenderTileFrame(&tile, &tile.bounds, &drawRect, 0, L"SCRL001.PAD", 0);
        }
    }

    SetDrawColor(0);
    m_drawMode = 2;
    PreparePaneRegion(&m_bounds);
}
```

Implementation note for the supervisor: if `ResolveClassicScrollFrame` is considered too helper-like for the formal block, expand it into local switch/if frame arithmetic during implementation and document the exact frame numbers from the disassembly. Do not leave `sub_`, `dword_`, `aSc`, or unrelated generated owner names in the inserted block.

## Score Recommendation

| Field | Recommendation | Rationale |
| --- | ---: | --- |
| Completion | `88` | Current MCP and support docs resolve the exact modeled range/end/padding, vtable-only route, EPF/classic branch families, resource literals, table consumers, four `GetScrollPartRect` calls, `IsScrollThumbVisible` dependency, helper roles, field offsets, owner/emitter route, stale generated-state status, and first-draft formal C++ readiness. Completion remains below final audit because exact original classic frame-selection helper spelling and some branch-level inlining are still inferred. |
| Confidence | `90` | Confidence is strong for owner, reachability, boundaries, resource literals, callee roles, and field meanings from current MCP session `80de0a67` plus accepted ScrollPane child docs. Confidence is not higher because no original symbols for this method/local helpers survive, the compact decompile body is truncated on this large function, and some helper declaration spellings remain source-facing inferences. |

Reason not lower:

- The old blank-C++ reason is no longer sufficient. Current docs and MCP evidence support a formal first-draft source shape.
- Helper labels have current shared-owner support; they are not unresolved enough to block code entry.
- The class/file owner route is already gate-cleared and does not need a split.

Reason not higher:

- The method is still large and branch-heavy.
- Exact classic frame-selection naming and final helper declarations are inferred.
- Generated outputs are stale and should be refreshed only after source by-* updates and validation.
- Final source should eventually expand or validate the `ResolveClassicScrollFrame` source shape against full branch-level frame constants before any 95+ score.

## Open Questions With Attempted Resolution

- Open question: Should [UID:0001GI] be split? Resolution: no split recommended. The target is one modeled vtable method, exact `sub_55C650` size `0x1307`, with one class owner and a single successor boundary. Unlike [UID:0001GH], it is not a mixed class/source corridor.
- Open question: Is blank formal C++ still justified? Resolution: no. The old blockers are now reduced to final original spelling, not first-draft readiness. This report supplies a formal block.
- Open question: Are `FittingRoomScrollPane::OnDraw` and generic `ScrollPane::OnDraw` the same owner/source? Resolution: no. The FittingRoom page and executed B002 report share resource/helper evidence only. Vtable/data neighborhood and class fields remain separate.
- Open question: Are `dword_624144` and `dword_62415C` private target globals? Resolution: no. Current xrefs show they are shared scrollbar dimension/style constants consumed by this draw body, `GetScrollPartRect`, ScrollablePane layout, and specialized scroll panes.
- Open question: Can raw helper labels remain in target prose? Resolution: no. The report identifies accepted source-facing roles for the relevant helpers; raw labels should remain only as evidence aliases.

## Recommended Implementation Edits

Target edit: `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000CM`.
- Insert the formal first-draft C++ block from this report into the target's `RECONSTRUCTION_CPP CODE` header/block, adjusting only if the supervisor chooses to expand `ResolveClassicScrollFrame` inline.
- Rewrite the item summary to mention exact vtable-only `ScrollPane::OnDraw`, current MCP size/end/padding, EPF/classic branches, `g_useEpfAssets`, `SLIDEBG`/`SCRBUTT` and `SCRL001` resources, shared scrollbar constant tables, `GetScrollPartRect`/`IsScrollThumbVisible`, and first-draft C++ readiness.
- Preserve the old exact range/end/vtable evidence, but replace stale helper-owner caveats with the current helper-role names and rejected generated-owner labels.
- Add evidence for MCP session `80de0a67`, `analyze_function` size/block/complexity/callee set, string/table bytes, and generated state being stale.

Support edits:

- `by-class/ScrollPane.md`: add a 2026-06-26 B010 note that [UID:0001GI] now has current MCP-backed first-draft C++ readiness and that helper names should use shared `GrafPort`/`Surface`/`ResourceLayoutTable` roles instead of generated feature-class owners. Keep class score unchanged unless the implementation performs broader class declaration work.
- `by-file/ScrollBar.md`: add a short evidence note that generic `ScrollPane::OnDraw` is now source-shaped under this file route with EPF/classic scrollbar resources and shared constants; do not move FittingRoom themed scroll ownership here.
- `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md`: optionally add the exact draw slot `0x00623da0 -> [UID:0001GI]` if not already present at equal detail. This page currently lists the target as related but omits the observed-content row for the draw slot.
- `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`: optionally clarify that `0x00624144` and `0x0062415c` are directly consumed by [UID:0001GI] with current-session xrefs, while still keeping the constants owned by [UID:0000NF] `ScrollBar`.
- No generated/project-level files should be edited manually. The research tracker and generated source should be refreshed only through the validator/executed-report flow.
- No manual `-coverage-report.md` file should be edited by B010. If the supervisor still maintains a manual coverage row, the recommended row substance is: [UID:0001GI] should be `88%` / very strong and mention B010 source-quality reanalysis resolving first-draft C++ readiness, exact `0x1307` draw virtual boundary, vtable-only slot `0x00623da0`, EPF/classic branch/resource evidence, shared scroll constant tables, `GetScrollPartRect`/`IsScrollThumbVisible`, helper-role normalization, and remaining final-spelling caveats.

## Implementation Tracking Checklist

Implementation callback pass checked 2026-06-26:

- [x] Edit `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md` metadata to `88/90`, preserving owner/emitter route `0000CM`.
  - Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000CM`; final target validator `000000002905` returned exit `0`, `ok: 1`.
- [x] Insert the accepted formal `RECONSTRUCTION_CPP CODE` block for `ScrollPane::OnDraw`.
  - Proof: target `RECONSTRUCTION_CPP CODE:BEGIN/END` now contains the accepted first-draft `void ScrollPane::OnDraw()` block with `g_useEpfAssets`, `SLIDEBG`/`SCRBUTT`, `SCRL001`, `GetScrollPartRect`, and source-facing helper names.
- [x] Update the target item summary and prose with current MCP evidence, resource/table evidence, helper-name normalization, first-draft C++ readiness, and generated-state staleness.
  - Proof: target item summary and `2026-06-26 B010 Source-Quality Refresh` section record MCP session `80de0a67`, size/end/padding, vtable-only route, resource/table evidence, field names, helper-role mapping, first-draft readiness, and stale generated-output state.
- [x] Ensure raw/generated labels (`sub_4B9980`, `sub_4BA6B0`, `sub_4B9660`, `unk_69B3FC`, `dword_67A744`, `aSc`, etc.) remain evidence aliases only and have source-facing names in prose.
  - Proof: target caveats and B010 refresh map raw labels to `RenderTileFrame`, `GrafPort::DrawTiledBackground`, `GrafPort::SetDrawColor`, `ResourceLayoutTable::LookupLayoutEntry`, `g_pEPFLib`, `g_pResourceLayoutTable`, and pane-region fill/prep roles; raw labels are retained only as evidence aliases.
- [x] Update `by-class/ScrollPane.md` with the B010 draw-method readiness note if not already present at equal detail.
  - Proof: class Method Families, Evidence Notes, Current Caveats, and Changes now record [UID:0001GI] first-draft readiness, vtable slot `0x00623da0`, exact range/padding, and shared renderer/resource helper roles; final class validator `000000002906` returned exit `0`, `ok: 1`.
- [x] Update `by-file/ScrollBar.md` with the generic draw-method source-route note if not already present at equal detail.
  - Proof: file Proposed Contents, Evidence Notes, and Changes now record [UID:0001GI] as source-shaped under [UID:0000CM] / [UID:0000NF], with rejected FittingRoom/TextEditPane ownership boundaries; final file validator `000000002908` returned exit `0`, `ok: 1`.
- [x] Optionally update `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md` with the `0x00623da0 -> [UID:0001GI]` draw slot row.
  - Proof: vtable Observed Contents now includes `0x00623da0` primary draw slot to [UID:0001GI], plus evidence/change notes; final vtable validator `000000002910` returned exit `0`, `ok: 1`.
- [x] Optionally update `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` with `0x00624144` / `0x0062415c` direct [UID:0001GI] xref details.
  - Proof: constants page item summary, Observed Contents, Evidence, Related Documentation, and Changes record B010 direct [UID:0001GI] xrefs while preserving [UID:0000NF] ownership; final constants validator `000000002911` returned exit `0`, `ok: 1`.
- [x] Do not edit generated/project-level files or any `-coverage-report.md` manually.
  - Proof: no manual edits were made to generated/project-level/manual coverage files. Validator commands produced expected tool-owned side effects, including `projected_stats_update`, generated refresh jobs, and validator registry/reference updates for related stale UIDs.
- [x] Run scoped validator for each edited by-* file from `source-3/project-documentation`, for example `python .\tools\validator.py --mode file --file by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md --apply --queue-timeout 240`.
  - Proof: final clean validators from `source-3/project-documentation`: target `000000002905`, class `000000002906`, file `000000002908`, vtable `000000002910`, constants `000000002911`; each returned exit `0`, `ok: 1`.
- [x] Record validator command, command id, timestamp, exit code, ok count, and generated refresh state.
  - Proof: recorded below in `Implementation Callback Proof`.
- [x] Confirm no active B010 leases remain after implementation.
  - Proof: final `tools/leaser/Agents/current_leases.md` check showed active B005 leases only, no B010 rows.

## Report-Only Proof

- By-* target/support docs were not edited.
- Generated/project-level files were not edited.
- Manual `-coverage-report.md` files were not edited.
- IDA DB was not edited.
- No leases were taken; this report file is in B010's own research folder.
- Validators were not run because this phase only creates a research report and does not change by-* docs.

## Implementation Callback Proof

Changed by-* docs:

- `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`
- `by-class/ScrollPane.md`
- `by-file/ScrollBar.md`
- `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md`
- `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md`

Validator-owned support mapping cleanup performed because scoped validators exposed stale/missing registry entries for directly related support UIDs:

- `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` registered/remapped [UID:0001GK] from stale `0x0055de98` path.
- `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` registered [UID:0003A5].
- `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` registered/remapped [UID:0001GL] from stale `0x0055f242` path.
- `by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md` registered [UID:0003CL].

Validators:

| File | Command | command_id | command_timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md` | `python .\tools\validator.py --mode file --file by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md --apply --queue-timeout 240` | `000000002905` | `2026-06-26T16:28:30-04:00` | `0` | `1` | deferred; caught up by `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header `000000002911` and `auto-generated/-ag-memory-coverage.md` header `000000002912` |
| `by-class/ScrollPane.md` | `python .\tools\validator.py --mode file --file by-class/ScrollPane.md --apply --queue-timeout 240` | `000000002906` | `2026-06-26T16:28:38-04:00` | `0` | `1` | deferred; final queue status `000000002927` showed no queued/processing generated refresh jobs |
| `by-file/ScrollBar.md` | `python .\tools\validator.py --mode file --file by-file/ScrollBar.md --apply --queue-timeout 240` | `000000002908` | `2026-06-26T16:28:51-04:00` | `0` | `1` | deferred; generated `ScrollBar.cpp` header advanced to `000000002911` |
| `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md --apply --queue-timeout 240` | `000000002910` | `2026-06-26T16:29:03-04:00` | `0` | `1` | deferred; final queue status clean |
| `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` | `python .\tools\validator.py --mode file --file by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240` | `000000002911` | `2026-06-26T16:29:16-04:00` | `0` | `1` | deferred; final generated `ScrollBar.cpp` header equal to `000000002911`, memory coverage header newer at `000000002912` |

Support validator commands, all exit `0` / `ok: 1`:

- [UID:0001GK] `000000002896` at `2026-06-26T16:27:24-04:00`; remapped stale path and reported broad pre-existing stale coverage/ignored-ledger references outside this callback.
- [UID:0003A5] `000000002899` at `2026-06-26T16:27:51-04:00`; registered missing UID and still reported stale [UID:0001GJ] references.
- [UID:0001GL] `000000002903` at `2026-06-26T16:28:04-04:00`; remapped stale path and reported broad pre-existing stale coverage/ignored-ledger references outside this callback.
- [UID:0003CL] `000000002904` at `2026-06-26T16:28:18-04:00`; registered missing UID cleanly.

Lease record:

- Initial lease batch succeeded for target, class, file, and vtable docs at `2026-06-26T20:21:01Z`; constants page was actively leased by B005 until `2026-06-26T20:25:40Z`, so B010 released the first batch after validation and waited rather than holding a reservation lease.
- B010 leased the constants page after B005's lease expired, edited/validated/released it, then took a short validation-only lease batch for related stale UID mapping cleanup and released all B010 leases.
- Final lease report contained no B010 rows.

Generated/project-level/tool-state side effects:

- Validators updated `tools/validator.ini`, reference indexes, projected stats, and generated outputs through normal validator-owned mechanisms.
- Generated refresh completed after the deferred queue drained; final `python .\tools\validator.py --queue-status` command `000000002927` at `2026-06-26T16:32:52-04:00` reported `queued generated refresh jobs: 0` and `processing generated refresh jobs: 0`.
- No IDA DB edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001GI-ScrollPaneOnDraw-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0001GI-ScrollPaneOnDraw-source-quality.md","timestamp":"2026-06-26T16:38:12","uid":"0001GI"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
