** TARGET-REPORT-UID:0001GK **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001GK] ScrollPaneGetScrollPartRect Empty-Emitter Source-Quality Report

## Assignment

- Agent: `Agent-B009`
- Assignment ID: `B009-empty-emitter-report-0001GK-ScrollPaneGetScrollPartRect-20260629`
- Target: [UID:0001GK] `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`
- Required output path: `tools/leaser/Agents/Agent-B009/research/0001GK-ScrollPaneGetScrollPartRect-empty-emitter-source-quality.md`
- Mode: report-only research. No leases taken. No by-* docs, generated files, coverage reports, validator state, tool state, IDA state, or executed archives were edited.

## Current Conclusion

[UID:0001GK] is a source-authored `ScrollPane` geometry method and should stop being an empty emitter. Current MCP evidence resolves the prior blocker set: exact range, caller set, owner route, part ids, field offsets, shared constant tables, EPF/classic branch split, vertical/horizontal rectangle formulas, drag-override behavior, and source-shaped `void` output-parameter signature.

Recommended metadata:

| Field | Current | Recommended | Reason |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `89` | The exact branch formulas and first-draft method body are now implementation-ready. Remaining uncertainty is original symbol spelling, not behavior. |
| `CONFIDENCE` | `88` | `91` | MCP decompile/xrefs/bytes and existing accepted support docs align on range, data flow, part ids, field offsets, constants, and caller consumption. |
| `CANONICAL_OWNER` | `0003A5` | `0003A5` | Keep the established exact-child-under-cluster route. The semantic class remains [UID:0000CM] `ScrollPane`, with source-file ancestor [UID:0000NF] `ScrollBar`. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored method with normal callers and output-parameter behavior. |
| `EMITTER_UIDS` | `0003A5` | `0003A5` | Preserve current emission route through the input/geometry helper cluster into `ScrollBar.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No position change is needed by this report. |

Pre-implementation generated-state note: before the callback, `auto-generated/NexusTK/ui/core/ScrollBar.cpp` contained `// UID:0001GK | by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md | Completion:85 | Confidence:88 | Empty Emitter Marker`, so the empty emitter was caused by the blank formal C++ block, not by a missing owner route. Post-callback generated freshness is recorded in `Implementation Callback Proof`.

## MCP Evidence

Active MCP availability was verified before relying on IDA data:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `idb_list`: active session `b6b3c97e`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, analyzing `false`, worker PID `15332`.
- `server_health`: `ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays available.

Target facts from current MCP:

- `lookup_funcs 0x0055d9e0`: `sub_55D9E0`, size `0x4b9` / 1209 bytes (Verified with `int_convert.py`).
- `lookup_funcs 0x0055de99`: not a function; successor `0x0055dea0` is `sub_55DEA0`, size `0x70`.
- Boundary bytes:
  - `0x0055d9d6-0x0055d9e0`: ten `0xcc` bytes before the prologue at `0x0055d9e0`.
  - `0x0055de99-0x0055dea0`: seven `0xcc` bytes after `retn 8` and before successor `sub_55DEA0`.
- `analyze_function 0x0055d9e0`: 68 basic blocks, cyclomatic complexity 17, callees `sub_55C3E0`, `sub_4A9090`, `sub_4B7C50`, `sub_5447C0`.
- `xrefs_to 0x0055d9e0`: 15 direct code refs:
  - `sub_55C650` / [UID:0001GI] `ScrollPane::OnDraw`: `0x55ce8f`, `0x55cf4c`, `0x55d664`, `0x55d77f`.
  - `sub_55D960`: `0x55d989`.
  - `sub_55DEA0`: `0x55decc`, `0x55dee8`.
  - `sub_55DF10`: `0x55df41`, `0x55df59`, `0x55df78`.
  - `sub_55DFD0`: `0x55e06f`, `0x55e1c7`.
  - `sub_55E210`: `0x55e242`, `0x55e413`.
  - `sub_55E600`: `0x55e636`.
- `decompile 0x0055d9e0`: decompiler prototype is `char __thiscall sub_55D9E0(int this, char a2, int *a3)`, but every caller passes a part id plus an output `RectBounds *` and ignores the incidental integer/low-byte return. Source shape is `void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)`.
- Constant bytes:
  - `0x00624144`: `38, 38, 38, 13, 12, 12, 13, 10, 10` as 32-bit little-endian integers.
  - `0x0062415c`: first slice is `13, 10, 10`; following bytes begin UTF-16 `SCRBUT...`.
  - Current decompile reads `dword_624144[m_scrollSkinIndex]` in EPF vertical mode and `dword_62415C[m_scrollSkinIndex]` in classic vertical mode.

## Existing Docs Checked

- Target [UID:0001GK] `ScrollPaneGetScrollPartRect`: report-only starting state was `85/88`, empty formal C++, blocker text for branch formulas/field names/style tables.
- [UID:0000CM] `ScrollPane`: already records the part ids, field offsets, orientation semantics, and ScrollBar source route.
- [UID:0000NF] `ScrollBar`: already owns the generic scrollbar source family and warns not to fold TextEditPane consumers into this file.
- [UID:0001GI] `ScrollPane::OnDraw`: accepted first-draft C++ calls this helper for buttons, page-before/page-after, and thumb geometry.
- [UID:000433] `ScrollPaneHandleMouseEvent`: consumer-side input handler; no ownership change needed.
- [UID:0003A5] `ScrollPaneInputGeometryHelpers`: containing helper cluster and current direct owner/emitter for this exact child.
- [UID:000432] `ScrollPane::IsScrollThumbVisible`: exact predicate `m_enabled && m_scrollRange > 0`, called twice from this target.
- [UID:0003CQ] `ScrollPaneScrollbarConstantData`: shared constants at `0x00624144` and `0x0062415c`; owner remains file-level `ScrollBar`.
- [UID:0001GR] `ScrollNewGroupPanePartRect` and [UID:0001GU] `ScrollCollectionPaneHitTestScrollRegion`: accepted source-facing precedents for `m_scrollSkinIndex`, `kScrollPanePartExtentBySkin`, local cursor conversion, drag-offset clamping, and zeroing non-visible page parts.
- Current generated `ScrollBar.cpp`: confirms UID0001GK remains an empty emitter.

Historical report search terms included `0001GK`, `0x0055d9e0`, `ScrollPaneGetScrollPartRect`, `GetScrollPartRect`, `ScrollPane`, `ScrollWidget`, `ScrollablePane`, and `ScrollBar`. Relevant old leads were used only to guide checks. The decisive evidence in this report is the current `b6b3c97e` MCP pass plus current support docs.

## Source Behavior

`ScrollPane::GetScrollPartRect` writes the rectangle for one of five scrollbar parts:

| Value | Source-facing enum | Meaning |
| ---: | --- | --- |
| `0` | `kScrollPanePartFirstButton` | Leading/first button or EPF leading edge line. |
| `1` | `kScrollPanePartPageBeforeThumb` | Track/page region before the thumb. |
| `2` | `kScrollPanePartThumb` | Thumb rectangle, or full interior when no thumb is visible. |
| `3` | `kScrollPanePartPageAfterThumb` | Track/page region after the thumb. |
| `4` | `kScrollPanePartSecondButton` | Trailing/second button or EPF trailing edge line. |
| `0xff` / `-1` | `kScrollPanePartNone` | State sentinel; not an output case in this method. |

Field usage resolved from current MCP and support docs:

| Offset | Source-facing field | Evidence |
| ---: | --- | --- |
| `+0x44` | `m_bounds` | Copied as four-int `RectBounds` in all paths. |
| `+0xf8` | `m_scrollSkinIndex` | Signed word table index into `dword_624144` and `dword_62415C`; existing ScrollNewGroup/ScrollCollection support already uses this name for the shared table-index role. |
| `+0xfb` | `m_thumbDragActive` | EPF vertical branch chooses drag cursor override when nonzero. |
| `+0xfc` | `m_orientation` | `0` vertical, nonzero horizontal. |
| `+0xfe` | `m_scrollPosition` | Signed word position used in thumb interpolation. |
| `+0x100` | `m_scrollRange` | Signed word denominator; guarded positive via `IsScrollThumbVisible`. |
| `+0x102` | `m_enabled` | `IsScrollThumbVisible` predicate. |
| `+0x108` | `m_thumbDragOffset.y` | First point-pair component used in vertical drag override. |

The global branch is `g_useEpfAssets` / `byte_66DA97`. When it is true, the function first reads the current cursor and pane screen offset, returns early on the `(-1000, -1000)` offset sentinel, then converts cursor coordinates to pane-local values. Only the EPF vertical drag path uses the local cursor; the binary still performs the setup before the orientation split.

EPF/high-resource geometry:

- Horizontal:
  - First/second parts collapse to zero-width edge lines (`right = left`, `left = right`).
  - Thumb extent is the scrollbar height: `bounds.bottom - bounds.top`.
  - When the thumb is visible, `thumbLeft = bounds.left + m_scrollPosition * (bounds.right - bounds.left - thumbExtent) / m_scrollRange`; the page-before and page-after rectangles are split around the thumb.
  - When the thumb is not visible, requesting the thumb returns the interior after trimming one thumb extent from both horizontal ends; page-before/page-after return an empty rectangle.
- Vertical:
  - First/second parts collapse to zero-height edge lines (`bottom = top`, `top = bottom`).
  - Thumb extent is `kScrollPanePartExtentBySkin[m_scrollSkinIndex]` / `dword_624144[m_scrollSkinIndex]`.
  - When the thumb is visible and `m_thumbDragActive` is false, `thumbTop = bounds.top + (bounds.bottom - thumbExtent - bounds.top) * m_scrollPosition / m_scrollRange`.
  - When `m_thumbDragActive` is true, `thumbTop = bounds.top + localCursor.y - m_thumbDragOffset.y`, clamped to `[bounds.top, bounds.bottom - thumbExtent]`.
  - When the thumb is not visible, requesting the thumb returns the interior after trimming one vertical extent from both ends; page-before/page-after return an empty rectangle.

Classic geometry:

- Horizontal:
  - Button/thumb extent is the scrollbar height: `bounds.bottom - bounds.top`.
  - First button is `[left, left + extent]`; second button is `[right - extent, right]`.
  - When the thumb is visible, the thumb travels inside the track after both buttons with a fixed thumb width equal to the button extent:
    `thumbLeft = bounds.left + extent + m_scrollPosition * (bounds.right - bounds.left - 3 * extent) / m_scrollRange`.
  - Page-before is `[left + extent, thumbLeft]`; page-after is `[thumbRight, right - extent]`.
  - When the thumb is not visible, requesting the thumb returns the button-trimmed interior; page-before/page-after return an empty rectangle.
- Vertical:
  - Button/thumb extent is `kClassicScrollPanePartExtentBySkin[m_scrollSkinIndex]` / `dword_62415C[m_scrollSkinIndex]`.
  - First button is `[top, top + extent]`; second button is `[bottom - extent, bottom]`.
  - When the thumb is visible, the thumb travels inside the track after both buttons with fixed height equal to the button extent:
    `thumbTop = bounds.top + extent + m_scrollPosition * (bounds.bottom - bounds.top - 3 * extent) / m_scrollRange`.
  - Page-before is `[top + extent, thumbTop]`; page-after is `[thumbBottom, bottom - extent]`.
  - When the thumb is not visible, requesting the thumb returns the button-trimmed interior; page-before/page-after return an empty rectangle.

## Ownership And Placement

Keep the existing target ownership route:

- Exact target owner/emitter: [UID:0003A5] `ScrollPaneInputGeometryHelpers`.
- Semantic class: [UID:0000CM] `ScrollPane`.
- Source-file ancestor: [UID:0000NF] `ScrollBar`, generated as `auto-generated/NexusTK/ui/core/ScrollBar.cpp`.

Rejected alternatives:

- Do not route to `TextEditPane`: TextEditPane and related scrollbar variants consume this helper, but the helper also serves `ScrollPane::OnDraw` and the generic input cluster.
- Do not route to `ScrollWidget` or `ScrollablePane`: those are neighboring generic scrollbar classes; this method reads `ScrollPane` fields and is called by `ScrollPane` draw/input methods.
- Do not create a private constants owner for `0x00624144` / `0x0062415c`: current support docs and MCP consumers show shared scrollbar data under `ScrollBar`.
- Do not keep blank C++ solely because exact original helper names are unknown: accepted project precedent allows first-draft source-facing aliases when behavior, fields, and route are proven.

## Formal C++ Insertion Text

Use the following exact body for the target `RECONSTRUCTION_CPP CODE` block. The support update should define or document `kClassicScrollPanePartExtentBySkin` as the `dword_62415C` slice and should normalize `+0xf8` to `m_scrollSkinIndex`; `kScrollPanePartExtentBySkin`, `InitRectBounds`, `g_pEventMan->GetCursorPosition`, and `GetScreenOffset` already have accepted support precedents in nearby scrollbar docs.

```cpp
void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)
{
    if (g_useEpfAssets) {
        Point cursor;
        Point origin;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        if (origin.y == -1000 && origin.x == -1000) {
            return;
        }

        cursor.y -= origin.y;
        cursor.x -= origin.x;

        const RectBounds bounds = m_bounds;
        if (m_orientation != 0) {
            const int thumbExtent = bounds.bottom - bounds.top;

            switch (part) {
            case kScrollPanePartFirstButton:
                *outRect = bounds;
                outRect->right = outRect->left;
                return;

            case kScrollPanePartSecondButton:
                *outRect = bounds;
                outRect->left = outRect->right;
                return;

            default:
                break;
            }

            if (IsScrollThumbVisible()) {
                const int thumbLeft =
                    bounds.left +
                    (m_scrollPosition * (bounds.right - bounds.left - thumbExtent)) /
                        m_scrollRange;
                const int thumbRight = thumbLeft + thumbExtent;

                *outRect = bounds;
                switch (part) {
                case kScrollPanePartThumb:
                    outRect->left = thumbLeft;
                    outRect->right = thumbRight;
                    return;

                case kScrollPanePartPageBeforeThumb:
                    outRect->right = thumbLeft;
                    return;

                case kScrollPanePartPageAfterThumb:
                    outRect->left = thumbRight;
                    return;

                default:
                    return;
                }
            }

            if (part == kScrollPanePartThumb) {
                *outRect = bounds;
                outRect->left += thumbExtent;
                outRect->right -= thumbExtent;
                return;
            }

            if (part == kScrollPanePartPageBeforeThumb ||
                part == kScrollPanePartPageAfterThumb) {
                InitRectBounds(outRect, 0, 0, 0, 0);
            }
            return;
        }

        const int thumbExtent = kScrollPanePartExtentBySkin[m_scrollSkinIndex];

        switch (part) {
        case kScrollPanePartFirstButton:
            *outRect = bounds;
            outRect->bottom = outRect->top;
            return;

        case kScrollPanePartSecondButton:
            *outRect = bounds;
            outRect->top = outRect->bottom;
            return;

        default:
            break;
        }

        if (IsScrollThumbVisible()) {
            const int thumbLimit = bounds.bottom - thumbExtent;
            int thumbTop;

            if (m_thumbDragActive) {
                thumbTop = bounds.top + cursor.y - m_thumbDragOffset.y;
                if (thumbTop < bounds.top) {
                    thumbTop = bounds.top;
                }
                if (thumbTop > thumbLimit) {
                    thumbTop = thumbLimit;
                }
            } else {
                thumbTop =
                    bounds.top +
                    ((thumbLimit - bounds.top) * m_scrollPosition) / m_scrollRange;
            }

            const int thumbBottom = thumbTop + thumbExtent;

            *outRect = bounds;
            switch (part) {
            case kScrollPanePartThumb:
                outRect->top = thumbTop;
                outRect->bottom = thumbBottom;
                return;

            case kScrollPanePartPageBeforeThumb:
                outRect->bottom = thumbTop;
                return;

            case kScrollPanePartPageAfterThumb:
                outRect->top = thumbBottom;
                return;

            default:
                return;
            }
        }

        if (part == kScrollPanePartThumb) {
            *outRect = bounds;
            outRect->top += thumbExtent;
            outRect->bottom -= thumbExtent;
            return;
        }

        if (part == kScrollPanePartPageBeforeThumb ||
            part == kScrollPanePartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    const RectBounds bounds = m_bounds;
    if (m_orientation != 0) {
        const int extent = bounds.bottom - bounds.top;

        switch (part) {
        case kScrollPanePartFirstButton:
            *outRect = bounds;
            outRect->right = outRect->left + extent;
            return;

        case kScrollPanePartSecondButton:
            *outRect = bounds;
            outRect->left = outRect->right - extent;
            return;

        default:
            break;
        }

        if (IsScrollThumbVisible()) {
            const int thumbLeft =
                bounds.left + extent +
                (m_scrollPosition * (bounds.right - bounds.left - 3 * extent)) /
                    m_scrollRange;
            const int thumbRight = thumbLeft + extent;

            *outRect = bounds;
            switch (part) {
            case kScrollPanePartThumb:
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
                return;

            case kScrollPanePartPageBeforeThumb:
                outRect->left += extent;
                outRect->right = thumbLeft;
                return;

            case kScrollPanePartPageAfterThumb:
                outRect->left = thumbRight;
                outRect->right -= extent;
                return;

            default:
                return;
            }
        }

        if (part == kScrollPanePartThumb) {
            *outRect = bounds;
            outRect->left += extent;
            outRect->right -= extent;
            return;
        }

        if (part == kScrollPanePartPageBeforeThumb ||
            part == kScrollPanePartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    const int extent = kClassicScrollPanePartExtentBySkin[m_scrollSkinIndex];

    switch (part) {
    case kScrollPanePartFirstButton:
        *outRect = bounds;
        outRect->bottom = outRect->top + extent;
        return;

    case kScrollPanePartSecondButton:
        *outRect = bounds;
        outRect->top = outRect->bottom - extent;
        return;

    default:
        break;
    }

    if (IsScrollThumbVisible()) {
        const int thumbTop =
            bounds.top + extent +
            (m_scrollPosition * (bounds.bottom - bounds.top - 3 * extent)) /
                m_scrollRange;
        const int thumbBottom = thumbTop + extent;

        *outRect = bounds;
        switch (part) {
        case kScrollPanePartThumb:
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
            return;

        case kScrollPanePartPageBeforeThumb:
            outRect->top += extent;
            outRect->bottom = thumbTop;
            return;

        case kScrollPanePartPageAfterThumb:
            outRect->top = thumbBottom;
            outRect->bottom -= extent;
            return;

        default:
            return;
        }
    }

    if (part == kScrollPanePartThumb) {
        *outRect = bounds;
        outRect->top += extent;
        outRect->bottom -= extent;
        return;
    }

    if (part == kScrollPanePartPageBeforeThumb ||
        part == kScrollPanePartPageAfterThumb) {
        InitRectBounds(outRect, 0, 0, 0, 0);
    }
}
```

## Recommended Target And Support Edits For Implementation Callback

Target [UID:0001GK]:

- Raise metadata to `89/91`.
- Insert the formal C++ body above.
- Replace the old final-C++ blocker text with a resolved-status section covering:
  - current MCP session `b6b3c97e`;
  - exact `0x4b9` size and padding before/after;
  - 15 direct callers;
  - `g_useEpfAssets` branch split;
  - `m_scrollSkinIndex`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, and `m_thumbDragOffset.y` fields;
  - part ids 0-4 and sentinel -1;
  - EPF/classic horizontal/vertical formulas;
  - `dword_624144` and `dword_62415C` table-slice use;
  - source-shaped `void` signature and incidental return rejection.

Support docs to update at report-level detail:

- [UID:0000CM] `ScrollPane`: add that UID0001GK is first-draft C++ ready, normalize `+0xf8` to `m_scrollSkinIndex`, and record that the geometry method uses the drag-active byte only in the EPF vertical drag override path.
- [UID:0000NF] `ScrollBar`: add that UID0001GK now has source-ready formal C++ under the existing generic scrollbar route; keep TextEditPane as consumer-only.
- [UID:0003A5] `ScrollPaneInputGeometryHelpers`: update the UID0001GK child row from formula-blocked to exact child with source-ready formal C++; keep the parent cluster's own aggregate C++ blank unless the callback scope says otherwise.
- [UID:0003CQ] `ScrollPaneScrollbarConstantData`: record UID0001GK's direct reads of `0x00624144` / `dword_624144` in EPF vertical mode and `0x0062415c` / `dword_62415C` in classic vertical mode; add or document the source-facing alias `kClassicScrollPanePartExtentBySkin` for the latter slice.
- [UID:0001GI] `ScrollPaneOnDraw`: update dependency wording from UID0001GK blocker to resolved geometry method.
- [UID:000433] `ScrollPaneHandleMouseEvent`: update dependency wording to say UID0001GK geometry is implementation-ready; the handler itself may remain no-code.
- Generated `ScrollBar.cpp`: do not edit directly. After scoped validation/generation, confirm UID0001GK no longer appears as an `Empty Emitter Marker`.

## Claim And Incorporation Ledger

| ID | Claim | Evidence | Target/support action | Status for callback |
| --- | --- | --- | --- | --- |
| GK-001 | Exact function range is `0x0055d9e0-0x0055de99`, size `0x4b9` / 1209 bytes. | Current MCP `lookup_funcs`; bytes show prologue at `0x0055d9e0`, `retn 8` before `0x0055de99`, successor at `0x0055dea0`. | Update target evidence and score rationale. | applied: target Status/Function/Evidence/Score updated; restored MCP session `B006_0002F1_20260629` reconfirmed lookup facts. |
| GK-002 | Padding excludes neighboring code: ten `0xcc` bytes before start and seven `0xcc` bytes after end. | Current MCP `get_bytes 0x0055d9d0` and `0x0055de90`. | Update target range/padding section; no split/merge. | applied: target Evidence Notes and Changes include pre/post padding; no split/merge made. |
| GK-003 | The source signature is `void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)`. | Current decompile writes `a3` in every meaningful path; callers ignore decompiler's incidental `char/int` return. | Insert formal C++; document return rejection. | applied: target formal block inserted and Rectangle Formulas section rejects incidental return. |
| GK-004 | Caller fan-in is 15 direct refs from OnDraw and nearby input/geometry helpers. | Current MCP `xrefs_to 0x0055d9e0`. | Add caller table to target/support. | applied: target Evidence Notes and cluster support preserve 15 caller refs; restored session reconfirmed same 15 direct refs. |
| GK-005 | Owner/emitter route should remain UID0003A5 under ScrollPane/ScrollBar. | Current docs and generated marker already route UID0001GK through ScrollBar.cpp; callers are generic ScrollPane paths. | Keep owner/emitter metadata; update rationale. | applied: target metadata keeps `CANONICAL_OWNER:0003A5`, `EMITTER_UIDS:0003A5`; ScrollPane/ScrollBar/cluster support preserve route and reject TextEditPane/ScrollWidget/ScrollablePane/private-constants alternatives. |
| GK-006 | Part ids are `0` first, `1` page-before, `2` thumb, `3` page-after, `4` second, with `-1` sentinel used only for state. | Target docs, ScrollPane class docs, OnDraw formal C++, current branch comparisons to `0`, `1`, `2`, `3`, `4`. | Add source enum table. | applied: target Part IDs And Fields table documents all values and sentinel. |
| GK-007 | `+0xf8` should be documented as `m_scrollSkinIndex` for this target. | Current decompile reads signed word `this+0xf8` for `dword_624144` and `dword_62415C`; accepted ScrollNewGroup/ScrollCollection docs use `m_scrollSkinIndex` for the same shared-table role. | Update target and ScrollPane support aliases; use `m_scrollSkinIndex` in formal C++. | applied: target formal C++ and field table use `m_scrollSkinIndex`; ScrollPane and constants support already had B004 alias and now include UID0001GK-specific use. |
| GK-008 | EPF branch is selected by `g_useEpfAssets` and does cursor/local-origin setup with `(-1000,-1000)` sentinel early return. | Current decompile: `byte_66DA97 == 1`, calls `sub_4A9090(dword_67A754, ...)`, `sub_5447C0(this, ...)`, returns on sentinel. | Document helper aliases and formal C++ setup block. | applied: target formal C++ and Rectangle Formulas section include `g_useEpfAssets`, cursor/origin setup, and sentinel return. |
| GK-009 | EPF horizontal buttons collapse to edge lines; thumb extent is scrollbar height; thumb track formula excludes one thumb extent. | Current decompile addresses `0x55da64-0x55db46`. | Insert formal C++ EPF horizontal block. | applied: target formal C++ and Rectangle Formulas document EPF horizontal behavior. |
| GK-010 | EPF vertical uses `dword_624144[m_scrollSkinIndex]` and supports drag-active thumb clamping. | Current decompile addresses `0x55db61-0x55dc68`; constant bytes at `0x00624144`. | Insert formal C++ EPF vertical block; update constants support. | applied: target formal C++, ScrollPane support, cluster support, and constants support document EPF vertical table use and drag clamp. |
| GK-011 | Classic horizontal uses full button rectangles and `bounds.right - bounds.left - 3 * extent` travel formula. | Current decompile addresses `0x55dc6b-0x55dd88`. | Insert formal C++ classic horizontal block. | applied: target formal C++ and Rectangle Formulas document classic horizontal behavior. |
| GK-012 | Classic vertical uses `dword_62415C[m_scrollSkinIndex]` and the same button-trimmed travel model. | Current decompile addresses `0x55dd92-0x55de72`; constant bytes at `0x0062415c`. | Insert formal C++ classic vertical block; document alias `kClassicScrollPanePartExtentBySkin`. | applied: target formal C++ and constants page document `kClassicScrollPanePartExtentBySkin` / `dword_62415C`. |
| GK-013 | Page-before/page-after return empty rectangles when the thumb is not visible. | Current decompile falls through to `sub_4B7C50(a3,0,0,0,0)` for part `1`/`3` in both EPF and classic no-thumb paths. | Use `InitRectBounds(outRect, 0, 0, 0, 0)` in formal C++; document behavior. | applied: target formal C++ uses `InitRectBounds` and formulas document no-thumb page rectangles. |
| GK-014 | UID0001GK generated empty marker remains present before implementation. | `rg` in `auto-generated/NexusTK/ui/core/ScrollBar.cpp` shows UID0001GK empty marker at current `85/88`. | Callback must validate generated file freshness after target formal C++ insertion. | applied: validators refreshed generated `ScrollBar.cpp` through command `000000000576`; read-only check shows UID0001GK at completion/confidence `89/91` with emitted `ScrollPane::GetScrollPartRect` and no UID0001GK empty marker. |

## Score-Blocker Audit

Prior blockers and disposition:

- Boundary/size: resolved by current MCP `lookup_funcs`, successor lookup, and padding bytes.
- Caller set: resolved by current MCP `xrefs_to`; 15 callers named above.
- Owner/emitter: resolved by generic ScrollPane caller family and existing ScrollBar output route; no reroute recommended.
- Part-id enum: resolved by branch comparisons, target/class docs, and OnDraw formal C++.
- Field names: resolved enough for implementation. Use `m_scrollSkinIndex` for `+0xf8`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_enabled`, and `m_thumbDragOffset.y`. Exact original names remain inferential, but project precedent accepts these source-facing aliases.
- Constant tables: resolved for behavior. `dword_624144` is `kScrollPanePartExtentBySkin`; add `kClassicScrollPanePartExtentBySkin` for `dword_62415C`.
- Branch formulas: resolved by full decompile and formal C++ above.
- Helper names: resolved to existing project aliases where available: `IsScrollThumbVisible`, `GetScreenOffset`, `g_pEventMan->GetCursorPosition`, `InitRectBounds`. Exact original spellings remain non-blocking source-name uncertainty.

No in-scope source-quality blocker is being left as future work. The remaining uncertainty is original symbol spelling/header normalization, not behavior or implementation readiness.

## Validator Plan For Callback

Report-only pass did not run validators and did not edit by-* docs. Implementation callback should run scoped validators after applying accepted edits, at minimum:

- `python .\tools\validator.py --mode file --file by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory\0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-class\ScrollPane.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-file\ScrollBar.md --apply --queue-timeout 240 --wait-generated`
- `python .\tools\validator.py --mode file --file by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md --apply --queue-timeout 240 --wait-generated`
- Optional dependency wording checks if edited: `ScrollPaneOnDraw` and `ScrollPaneHandleMouseEvent`.
- Generated freshness check: `rg -n "UID:0001GK|ScrollPane::GetScrollPartRect|Empty Emitter Marker" auto-generated/NexusTK/ui/core/ScrollBar.cpp`.

## Implementation Callback Proof

Leases: B009 acquired edit leases for the target, `ScrollPane`, `ScrollBar`, `ScrollPaneInputGeometryHelpers`, `ScrollPaneScrollbarConstantData`, and `ScrollPaneHandleMouseEvent`. A stale/overlapping B004 lease conflict was encountered before implementation; after resume, `current_leases.md` showed no active leases and B009 acquired the required set. Leases were released after validation.

Current MCP spot-check used restored session `B006_0002F1_20260629` rather than relying only on the accepted report's older `b6b3c97e` pass. `server_health` was `ok`; `lookup_funcs`, `xrefs_to`, and `get_bytes` reconfirmed target range, endpoint, successor, 15 callers, padding, and constants.

Scoped validators run from `source-3/project-documentation`:

| File | Command ID | Timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory\0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md` | `000000000571` | `2026-06-29T10:24:59-04:00` | `0` | `1` | completed, same command id/timestamp |
| `by-memory\0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | `000000000572` | `2026-06-29T10:25:08-04:00` | `0` | `1` | completed, same command id/timestamp |
| `by-class\ScrollPane.md` | `000000000573` | `2026-06-29T10:25:17-04:00` | `0` | `1` | completed, same command id/timestamp |
| `by-file\ScrollBar.md` | `000000000574` | `2026-06-29T10:25:26-04:00` | `0` | `1` | completed, same command id/timestamp |
| `by-memory\0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` | `000000000575` | `2026-06-29T10:25:35-04:00` | `0` | `1` | completed, same command id/timestamp |
| `by-memory\0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | `000000000576` | `2026-06-29T10:25:45-04:00` | `0` | `1` | completed, same command id/timestamp |

Known unrelated validator warnings remained: missing stale [UID:0001GJ] path `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md` appeared on the target and cluster validator runs. The current valid path is already `0x0055d960-0x005654ec` in surrounding docs; no validator/tool state was edited.

Generated freshness: `auto-generated/NexusTK/ui/core/ScrollBar.cpp` header is `validator-command-id: 000000000576`, `validator-refreshed-at: 2026-06-29T10:25:45-04:00`, equal to the last scoped validator. Read-only `rg` shows UID0001GK at line `195` with `Completion:89 | Confidence:91` and the emitted `void ScrollPane::GetScrollPartRect(...)` body at line `196`; UID0001GK no longer appears as an `Empty Emitter Marker`.

## Implementation Tracking Checklist

- [x] Update target [UID:0001GK] metadata to `COMPLETION:89`, `CONFIDENCE:91`. Proof: target header updated; validator `000000000571` recorded `completion_update 0001GK 89` and `confidence_update 0001GK 91`.
- [x] Insert the exact formal `void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)` body from this report into the target `RECONSTRUCTION_CPP CODE` block. Proof: target formal block now contains the accepted method body; generated `ScrollBar.cpp` line `196` emits the method.
- [x] Replace target blocker wording with current MCP evidence, caller table, part-id table, field table, constants, and formulas from this report. Proof: target now has Part IDs And Fields, Rectangle Formulas, updated Evidence Notes, restored MCP `B006_0002F1_20260629` spot-check, and updated Score Rationale.
- [x] Keep target owner/emitter route as `0003A5`; do not reroute to TextEditPane, ScrollWidget, ScrollablePane, or a private constants owner. Proof: target metadata keeps `CANONICAL_OWNER:0003A5` and `EMITTER_UIDS:0003A5`; target/support Changes preserve rejected alternatives and generic ScrollPane/ScrollBar route.
- [x] Update [UID:0000CM] `ScrollPane` with `m_scrollSkinIndex` and UID0001GK source-ready geometry details. Proof: `ScrollPane.md` Method Families, Evidence Notes, Current Caveats, and Changes now record UID0001GK first-draft readiness, `m_scrollSkinIndex`, and EPF vertical drag-active-only behavior.
- [x] Update [UID:0000NF] `ScrollBar` with UID0001GK first-draft C++ readiness under the generic scrollbar route. Proof: `ScrollBar.md` Proposed Contents, Evidence Notes, and Changes now record UID0001GK first-draft geometry C++ and preserve TextEditPane consumer-only reasoning.
- [x] Update [UID:0003A5] `ScrollPaneInputGeometryHelpers` to mark UID0001GK as resolved/source-ready while keeping aggregate cluster handling intact. Proof: cluster Item Summary, Final C++ gate, child row, Behavior Summary, Evidence, Score Rationale, and Changes now mark UID0001GK source-ready while keeping the aggregate block blank.
- [x] Update [UID:0003CQ] `ScrollPaneScrollbarConstantData` with UID0001GK direct reads of `dword_624144` and `dword_62415C`, including the `kClassicScrollPanePartExtentBySkin` alias or equivalent accepted wording. Proof: constants Item Summary, Observed Contents, Evidence, and Changes now document `kScrollPanePartExtentBySkin` and `kClassicScrollPanePartExtentBySkin`.
- [x] Update dependency wording in [UID:0001GI] `ScrollPaneOnDraw` and [UID:000433] `ScrollPaneHandleMouseEvent` if callback scope includes them. Proof: `ScrollPaneOnDraw.md` already treated UID0001GK as a dependency, not a current blocker, so it was already-present and unedited; `ScrollPaneHandleMouseEvent.md` no-code proof was updated to remove UID0001GK as an open geometry blocker while preserving handler no-code status.
- [x] Run scoped validators listed above with `--wait-generated` where applicable. Proof: validators `000000000571` through `000000000576` all exited `0` with `ok:1` and completed generated refresh.
- [x] Verify generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp` no longer has UID0001GK as an `Empty Emitter Marker`. Proof: generated header is command `000000000576`; `rg` shows UID0001GK emitted at lines `195-196` and no UID0001GK empty marker.
- [x] Update this report's Claim And Incorporation Ledger statuses from `proposed` to proof-backed `incorporated` during implementation callback. Proof: ledger rows GK-001 through GK-014 now have applied proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001GK-ScrollPaneGetScrollPartRect-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001GK-ScrollPaneGetScrollPartRect-empty-emitter-source-quality.md","timestamp":"2026-06-29T10:29:24","uid":"0001GK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
