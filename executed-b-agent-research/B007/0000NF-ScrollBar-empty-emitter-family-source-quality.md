** TARGET-REPORT-UID:0000NF **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B007 Report: [UID:0000NF] ScrollBar Empty-Emitter Family

## Assignment

- Agent: B007.
- Assignment id: `B007-report-0000NF-ScrollBar-empty-emitter-family-20260701`.
- Primary target: [UID:0000NF] `by-file/ScrollBar.md`.
- Generated output under audit: `auto-generated/NexusTK/ui/core/ScrollBar.cpp`.
- Mode: report-only research. No target/support by-* docs, generated files, coverage reports, validator state, queue files, archives, supervisor ledgers, or IDA database state were edited.
- Existing ScrollBar child reports were used as support leads only. They do not substitute for this by-file family report.

## Recommendation

Implement after supervisor validation.

The current generated `ScrollBar.cpp` family has 26 total emitters, 13 populated outputs, and 13 empty markers. The empty set is not one defect class. It splits into:

- broad by-file/class route pages that should receive durable generated-output audit or comment-only route markers;
- aggregate code corridors that should not emit one merged C++ body;
- compiler-generated vtable/RTTI data pages that should receive source-declared/generated-binary no-code markers;
- one file-level source-declared constant table range that is ready for first-draft C++.

Recommended primary by-file metadata:

```text
COMPLETION:90
CONFIDENCE:87
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"
CANONICAL_OWNER:FILE
```

Keep `ScrollBar.md` as the file root for the generic scrollbar family. Add a durable 2026-07-01 generated-output audit section recording the current validator header, generated freshness, 13 populated outputs, 13 empty markers, and per-marker disposition below. The by-file page itself should remain broad; exact source bodies belong to method child pages or comment-only/no-code markers when the target represents aggregate or generated-binary material.

## Generated Output Audit

Current generated header inspected:

```text
auto-generated/NexusTK/ui/core/ScrollBar.cpp
validator-command-id: 000000003290
validator-refreshed-at: 2026-07-01T04:46:53-04:00
source by-file UID: 0000NF
```

Tracker context from `auto-generated/-ag-research-tracker.md`:

```text
[UID:0000NF] ScrollBar
26 total emitters
13 filled
13 empty
50.0%
```

Populated generated outputs already present:

| UID | Current generated disposition |
| --- | --- |
| `0001E3` | `CScrollBarBackPane` scalar deleting destructor comment-only no-code marker. |
| `00042V` | `ScrollPane` constructor C++ output. |
| `00042W` | `void ScrollPane::SetSkinIndex(unsigned short skinIndex)`. |
| `00042X` | Formal comment-only/no-body marker for the raw byte-state setter. |
| `000432` | `bool ScrollPane::IsScrollThumbVisible()`. |
| `000434` | `bool ScrollPane::CanScroll(int) { return false; }`. |
| `000435` | `bool ScrollPane::OnTimer(...)`. |
| `0001GI` | `void ScrollPane::OnDraw()`. |
| `0001GK` | `void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)`. |
| `00042Y` | `ScrollWidget::SetScrollTargetValue(short targetPosition)`. |
| `00042Z` | `ScrollWidget::SetScrollCurrentValue(short currentPosition)`. |
| `000430` | `ScrollWidget::Enable()`. |
| `000431` | `ScrollWidget::Disable()`. |

Current empty markers and recommended dispositions:

| UID | Target | Recommended action | Verification state |
| --- | --- | --- | --- |
| `00003D` | `by-class/CScrollBarBackPane.md` | Add a class route comment-only marker and generated-output audit; do not emit a broad class declaration yet. | proposed |
| `0001DV` | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` | Add aggregate no-code marker; the target mixes constructor bytes, cleanup helper, and draw method. | proposed |
| `0003LR` | `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` | Add generated-binary vtable/RTTI no-code marker and nonblank item summary. | proposed |
| `0000CM` | `by-class/ScrollPane.md` | Add a class route comment-only marker; exact bodies already emit from children or remain on exact aggregate pages. | proposed |
| `000433` | `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | Insert first-draft `bool ScrollPane::OnMouseEvent(const PaneMouseEvent& event)` formal C++; preserve adjusted EventHandler receiver, EPF/classic branch, capture, helper, and invalidation evidence. | proposed |
| `0003A5` | `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` | Add aggregate route marker; exact child `GetScrollPartRect` already emits and this page spans multiple helpers. | proposed |
| `0003CK` | `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md` | Add generated-binary vtable/RTTI no-code marker. | proposed |
| `0000CP` | `by-class/ScrollWidget.md` | Add a class route comment-only marker; exact widget method bodies emit from children. | proposed |
| `0000CF` | `by-class/ScrollablePane.md` | Add a class route comment-only marker and audit note; exact core/default/vtable pages carry details. | proposed |
| `0001GL` | `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` | Add aggregate no-code marker; this is a multi-method class cluster, not one formal C++ body. | proposed |
| `0001H6` | `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md` | Add aggregate no-code marker preserving compiler-thunk/deleting-wrapper caveat. | proposed |
| `0003CL` | `by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md` | Add generated-binary vtable/RTTI no-code marker and nonblank item summary. | proposed |
| `0003CQ` | `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` | Insert first-draft source constant declarations for four 3-entry extent tables. | proposed |

## Live MCP Evidence

MCP was available and current; this report is not fallback-only.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp` version `1.0.0`.
- Session id: `supervisor_resume_20260629`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`; imagebase `0x400000`.
- Health: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Evidence calls used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `get_int`, `xrefs_to`, `analyze_batch`, `analyze_function`, and `decompile`.
- Write-capable MCP tools were not used.

Key MCP facts:

| Address/range | Fact |
| --- | --- |
| `0x0053fea0` | Not an IDA function; constructor bytes are embedded in the `CScrollBarBackPaneCore` range. |
| `0x0053fee0` | `sub_53FEE0`, size `0x1f`; cleanup restores three `CScrollBarBackPane` vtables and calls `Pane::~Pane` helper `sub_544580`. |
| `0x0053ff00` | `sub_53FF00`, size `0x8d`; draw method calls position helper `sub_4B9600` and line/global helper `unk_69B3E4`; vtable data xref at `0x00621060`. |
| `0x0055c400` | `sub_55C400`, size 511, prototype `bool __thiscall(int this, int)`, vtable data xref at `0x00623dac`, 30 basic blocks, cyclomatic complexity 16. |
| `0x0055d960` | `sub_55D960`, size `0x76`; geometry helper called from mouse/layout helpers. |
| `0x0055df10` | `sub_55DF10`, size `0xbf`. |
| `0x0055dfd0` | `sub_55DFD0`, size `0x21d`. |
| `0x0055e210` | `sub_55E210`, size `0x3e6`; adjusted input/drag helper, references scrollbar extent tables. |
| `0x0055e600` | `sub_55E600`, size `0x5c`. |
| `0x0055e660` | `sub_55E660`, size `0x11e`; `ScrollablePane` constructor cluster. |
| `0x0055e990` | `sub_55E990`, size `0x145`; scroll synchronization helper. |
| `0x0055ec00` | `sub_55EC00`, size `0x1eb`; layout/update-bounds virtual consuming all four constant-table triples. |
| `0x0055f250` | `sub_55F250`, size 511; internal viewport/content rect recompute helper. |
| `0x005654ec` | `sub_5654EC`, size `0xb`; destructor adjustor thunk. |
| `0x00565510` | `sub_565510`, size `0x8b`; scalar deleting destructor wrapper. |
| `0x005655a0`, `0x005655b0`, `0x005655c0`, `0x005655e0`, `0x00565600` | Small default virtual bodies in the `ScrollablePaneVirtualDefaults` aggregate. |
| `0x00624138-0x00624168` | Twelve little-endian `u32` constants: `{13,13,13}`, `{38,38,38}`, `{13,12,12}`, `{13,10,10}`. |

Constant-data xrefs:

- `0x00624138`: one data xref from `sub_55EC00` at `0x55ecc0`.
- `0x00624144`: many data xrefs, including `sub_55D9E0`, `sub_55EC00`, `sub_55C650`, and neighboring pane helpers.
- `0x00624150`: one data xref from `sub_55EC00` at `0x55ed75`.
- `0x0062415c`: twelve data xrefs, including `sub_55D9E0`, `sub_55E210`, `sub_55EC00`, and draw/geometry helpers.
- `0x00624168`: data xref from successor function `sub_564B50`; this confirms `0x00624168` is the next object boundary, not part of UID `0003CQ`.

The `sub_55EC00` decompile proves the four constant triples are source-facing scrollbar extents by mode/axis/skin-index. In `byte_66DA97 == 1` mode it uses `0x00624144` for horizontal scrollbar height and `0x00624138` for vertical scrollbar width. In the alternate mode it uses `0x0062415c` for horizontal scrollbar height and `0x00624150` for vertical scrollbar width.

## Prior Reports Used As Leads

Opened support leads:

- B004 `[UID:0001GH] ScrollPaneInputCore`: confirms the parent input corridor was split and exact children carry first-draft C++. Its older [UID:000433] no-code proof is superseded by this revision's current MCP pass and sibling input-handler precedent.
- B001 `[UID:0001GL] ScrollablePaneCore`: confirms `0x0055e660-0x0055f44f` is a coherent `ScrollablePane` class cluster, not a mixed file-level owner, but not a single function body.
- B002 `[UID:0001H6] ScrollablePaneVirtualDefaults`: confirms this aggregate mixes destructor adjustor thunks, scalar deleting destructor wrapper, and default virtual bodies; no formal aggregate C++ should be written.
- B003 `[UID:0001E3] CScrollBarBackPaneDestructor`: confirms `CScrollBarBackPane` deleting destructor policy and that comment-only formal markers are valid for compiler-generated wrapper material.

Other generated-populated child reports in tracker were treated as support leads, including B010 `[UID:0001GI]`, B009 `[UID:0001GK]`, B004 `[UID:00042W]`, B006 `[UID:00042X]`, and B001 `[UID:00042Z]`.

## Empty Marker Recommendations

### [UID:00003D] `CScrollBarBackPane`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
```

Recommended formal C++ comment marker:

```cpp
// CScrollBarBackPane class routing is documented here; exact constructor, draw, destructor, and vtable output belongs to child pages.
```

Rationale: the class page is a route/evidence page, not a source-quality class declaration yet. MCP confirms the constructor bytes are not a function, cleanup is a helper, draw is a separate vtable method, and the draw body still relies on unresolved source-facing names for `sub_4B9600` and `unk_69B3E4`.

Rejected alternative: emit a broad `class CScrollBarBackPane` declaration now. The class layout and helper names remain too incomplete for final source-facing declaration quality, and exact generated output already belongs to children.

### [UID:0001DV] `CScrollBarBackPaneCore`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:00003D
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00003D
```

Recommended formal C++ comment marker:

```cpp
// CScrollBarBackPane core groups constructor bytes, cleanup glue, and fixed-line draw behavior; exact source bodies are not emitted as one aggregate block.
```

Rationale: the range combines constructor bytes at `0x0053fea0`, cleanup helper `0x0053fee0`, and draw method `0x0053ff00`. MCP confirms distinct source shapes: not-a-function constructor bytes, cleanup restoring vtables and calling `Pane::~Pane`, and a draw method with direct vtable data xref at `0x00621060`. A single formal C++ body would merge constructor/destructor/draw semantics.

### [UID:0003LR] `CScrollBarBackPaneVtableData`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00003D
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00003D
```

Recommended item summary:

```text
CScrollBarBackPane RTTI/vtable data group for primary/secondary/tertiary panes; slots route to deleting destructor, adjustor thunks, draw method, and inherited Pane interface entries.
```

Recommended formal C++ comment marker:

```cpp
// CScrollBarBackPane RTTI/vtable bytes are compiler-generated from the class virtual method set; no handwritten table source is emitted.
```

Rationale: this is generated-binary table data. MCP xrefs confirm `0x0053ff00` is referenced from vtable slot `0x00621060`; prior destructor report confirms deleting destructor and adjustor slots. Handwriting the table as C++ would duplicate ABI output.

### [UID:0000CM] `ScrollPane`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:88
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
```

Recommended formal C++ comment marker:

```cpp
// ScrollPane class routing is documented here; exact constructor, draw, geometry, input, timer, and raw-state source emits through child pages.
```

Rationale: the class page is the owner route for several exact children, many of which already emit. A broad class declaration would duplicate exact child bodies and overclaim unresolved EventHandler/input helper surfaces.

### [UID:000433] `ScrollPaneHandleMouseEvent`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CM
```

Recommended formal C++ insertion:

```cpp
bool ScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;

    if (g_useEpfAssets) {
        switch (event.type) {
        case kPaneMouseMove:
            if (m_activePart != kScrollPanePartNone) {
                InvalidateRect(&m_bounds);
                return true;
            }
            return false;

        case kPaneMouseDown:
            if (!PointInRect(event.x, event.y, &m_bounds)) {
                return false;
            }
            if (!m_enabled || m_scrollRange <= 0) {
                return false;
            }
            if (m_activePart == kScrollPanePartNone) {
                const ScrollPanePart part = HitTestPart(event.x, event.y);
                if (part != kScrollPanePartNone) {
                    CaptureMouse();
                    BeginPartPress(part, event.x, event.y);
                    InvalidateRect(&m_bounds);
                }
            }
            m_thumbDragActive = true;
            return true;

        case kPaneMouseUp:
            if (m_activePart != kScrollPanePartNone) {
                ReleaseMouseCapture();
                ResetScrollState();
                handled = true;
            }
            m_thumbDragActive = false;
            InvalidateRect(&m_bounds);
            return handled;

        default:
            return false;
        }
    }

    switch (event.type) {
    case kPaneMouseMove:
        return m_activePart != kScrollPanePartNone;

    case kPaneMouseDown:
        if (!PointInRect(event.x, event.y, &m_bounds)) {
            return false;
        }
        if (!m_enabled || m_scrollRange <= 0) {
            return false;
        }
        if (m_activePart == kScrollPanePartNone) {
            const ScrollPanePart part = HitTestPart(event.x, event.y);
            if (part != kScrollPanePartNone) {
                CaptureMouse();
                BeginPartPress(part, event.x, event.y);
            }
        }
        return true;

    case kPaneMouseUp:
        if (m_activePart != kScrollPanePartNone) {
            ReleaseMouseCapture();
            ResetScrollState();
            return true;
        }
        return false;

    default:
        return false;
    }
}
```

Rationale: current MCP confirms a real 511-byte source-authored virtual body at `0x0055c400`, vtable data xref `0x00623dac`, six callees, 30 basic blocks, and EventHandler-adjusted receiver `this - 0xa0`. The body reads `event+4` as event type, `event+8` as `x`, and `event+0xc` as `y`; branches on `g_useEpfAssets` / `byte_66DA97`; calls `PointInRect`, `Pane::CaptureMouse`, `Pane::ReleaseMouseCapture`, `ScrollPane::HitTestPart`, `ScrollPane::BeginPartPress`, and `ScrollPane::ResetScrollState`; checks `m_enabled`, `m_scrollRange`, and `m_activePart`; toggles `m_thumbDragActive`; and invalidates `m_bounds` through the Pane vtable slot. FittingRoom scrollbar input precedent already accepts `PaneMouseEvent`, `kPaneMouseMove`, `kPaneMouseDown`, `kPaneMouseUp`, capture/release naming, hot/active part names, and first-draft helper names when exact original spellings are not recoverable. Exact original enum/member/helper spellings remain a source-quality caveat, but they are not a no-code blocker for this exact body.

Target/support update instructions: update `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` with the formal C++ body above, metadata `88/90`, and prose preserving the adjusted-receiver/event-field/EPF-vs-classic branch evidence. Update `by-class/ScrollPane.md` to replace the stale blank-body note with a child-body summary for `OnMouseEvent`. Update `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` only as support evidence for the helper names used by this body: `0x0055d960` = `HitTestPart`, `0x0055df10` = `BeginPartPress`, `0x0055dfd0` = `ProcessActivePart`, and `0x0055e600` = `ResetScrollState`.

Rejected alternative: keep a comment-only marker because exact event/helper names are unresolved. Current EventHandler/Event docs, exact helper decompiles, field offsets, sibling FittingRoom scrollbar input handlers, and direct MCP evidence provide enough same-pass inference for source-quality first-draft C++.

### [UID:0003A5] `ScrollPaneInputGeometryHelpers`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000CM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CM
```

Recommended formal C++ comment marker:

```cpp
// ScrollPane input/geometry helper cluster is an aggregate route; exact method bodies emit from child pages such as GetScrollPartRect, and unsplit helpers are not emitted from this aggregate.
```

Rationale: MCP reconfirms multiple distinct helper functions inside this cluster (`0x0055d960`, `0x0055df10`, `0x0055dfd0`, `0x0055e210`, `0x0055e600`) with different roles. [UID:0001GK] already emits `GetScrollPartRect`. The aggregate should not produce one merged C++ body.

### [UID:0003CK] `ScrollPaneVtableData`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:0000CM
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CM
```

Recommended formal C++ comment marker:

```cpp
// ScrollPane RTTI/vtable bytes are compiler-generated from the class virtual method set; no handwritten table source is emitted.
```

Rationale: generated-binary vtable data. MCP confirms [UID:000433] is reached from `0x00623dac`, not by a handwritten source table.

### [UID:0000CP] `ScrollWidget`

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:86
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
```

Recommended formal C++ comment marker:

```cpp
// ScrollWidget class routing is documented here; exact target/current/enable/disable method bodies emit through child pages.
```

Rationale: exact child method bodies already emit for target/current/enable/disable. The class page should clear its empty marker as a route page without duplicating method bodies or inventing a final class declaration.

### [UID:0000CF] `ScrollablePane`

Recommended metadata:

```text
COMPLETION:89
CONFIDENCE:90
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
```

Recommended formal C++ comment marker:

```cpp
// ScrollablePane class routing is documented here; constructor/layout/default virtual bodies remain on exact child pages and compiler destructor/vtable artifacts are not hand-written here.
```

Rationale: [UID:0001GL], [UID:0001H6], and [UID:0003CL] carry exact cluster/default/vtable detail. The class page is high-confidence but still a route/declaration page, not a place to emit aggregate C++ that would duplicate those targets.

### [UID:0001GL] `ScrollablePaneCore`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CF
```

Recommended formal C++ comment marker:

```cpp
// ScrollablePane core is a multi-method class cluster; exact constructor, layout, input, sync, and helper source is not emitted as one aggregate body.
```

Rationale: B001 and current MCP agree that `0x0055e660-0x0055f44f` is coherent `ScrollablePane` ownership, but it contains many modeled methods and raw helpers. MCP confirms representative sizes and callers, including constructor `0x0055e660`, layout `0x0055ec00`, sync `0x0055e990`, and rect recompute `0x0055f250`. One formal C++ block would merge unrelated methods.

### [UID:0001H6] `ScrollablePaneVirtualDefaults`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000CF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CF
```

Recommended formal C++ comment marker:

```cpp
// ScrollablePane late virtual/default island mixes adjustor thunks, scalar deleting destructor glue, and default metric bodies; no handwritten aggregate C++ is emitted here.
```

Rationale: B002 already resolved this target's exact source shape. Current MCP reconfirms the adjustor thunk at `0x005654ec`, scalar deleting destructor wrapper at `0x00565510`, and small default bodies through `0x00565600`. Source-facing methods may be named in prose/class docs, but the aggregate formal block should remain comment-only.

### [UID:0003CL] `ScrollablePaneVtableData`

Recommended metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000CF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CF
```

Recommended item summary:

```text
ScrollablePane RTTI/vtable data group for primary/secondary/tertiary panes; slots route to destructor/default virtual machinery, input/layout methods, and scroll metric defaults.
```

Recommended formal C++ comment marker:

```cpp
// ScrollablePane RTTI/vtable bytes are compiler-generated from the class virtual/default method set; no handwritten table source is emitted.
```

Rationale: generated-binary table data. Formal source belongs to class/default/body pages, not hand-authored table bytes.

### [UID:0003CQ] `ScrollPaneScrollbarConstantData`

Recommended metadata:

```text
COMPLETION:87
CONFIDENCE:89
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
```

Recommended item summary:

```text
File-level source-declared scrollbar extent tables used by ScrollablePane layout and ScrollPane geometry/draw helpers; four three-entry skin-index tables cover EPF and legacy horizontal/vertical scrollbar extents.
```

Recommended formal C++ insertion:

```cpp
static const int kScrollablePaneEpfVerticalScrollbarWidthBySkin[3] = { 13, 13, 13 };
static const int kScrollablePaneEpfHorizontalScrollbarHeightBySkin[3] = { 38, 38, 38 };
static const int kScrollablePaneLegacyVerticalScrollbarWidthBySkin[3] = { 13, 12, 12 };
static const int kScrollablePaneLegacyHorizontalScrollbarHeightBySkin[3] = { 13, 10, 10 };
```

Rationale: this target is not compiler-generated vtable data and not an aggregate code corridor. MCP `get_int` reads exact values at `0x00624138-0x00624164`, and `sub_55EC00` proves source-facing mode/axis usage. Names are best inferred source names from current evidence: `byte_66DA97 == 1` selects EPF-mode tables, and each branch separately applies horizontal height and vertical width by the child `ScrollPane` skin index at child offset `+0xf8`.

Rejected alternative: comment-only marker. This is source-declared constant data with exact values and direct consumers, so a no-code disposition would be too conservative.

## Heuristic / Inference Reanalysis

Accepted:

- [UID:0000NF] remains the file root for `NexusTK/ui/core/ScrollBar.cpp`.
- Class pages in this family can use comment-only route markers when exact bodies already live on child pages.
- Aggregate memory pages should not emit one C++ block when they span multiple source methods, compiler thunks, or mixed source shapes.
- Vtable/RTTI data targets should use formal comment-only markers, not handwritten table definitions.
- [UID:000433] should emit first-draft `ScrollPane::OnMouseEvent` C++; unresolved original event/helper spellings are addressed through current same-pass inference and sibling handler precedent.
- [UID:0003CQ] should emit source constants because it is file-level source data with exact values and source consumers.

Rejected:

- Treating every empty marker as a future investigation item. Each current marker has a disposition above.
- Keeping [UID:000433] comment-only because exact event/helper names are unresolved. The MCP evidence proves a real source-authored body, and current EventHandler/Event docs plus sibling scrollbar handler precedent support a defensible first-draft source surface.
- Emitting broad class declarations for `ScrollPane`, `ScrollWidget`, `ScrollablePane`, or `CScrollBarBackPane` from route pages. This would duplicate child output and overclaim unresolved layout/source names.
- Editing generated files or coverage rows manually. Generated state must be refreshed by validators after accepted by-* doc implementation.

## Claim And Incorporation Ledger

| Claim | Action | Verification state | Proof / implementation instruction |
| --- | --- | --- | --- |
| Add by-file generated-output audit to `ScrollBar.md`. | incorporate | applied | Applied in `by-file/ScrollBar.md` under `## 2026-07-01 B007 Generated-Output Audit`: header `000000003290` / `2026-07-01T04:46:53-04:00`, tracker row 26/13/13/50.0, all 13 filled outputs, all 13 empty-marker dispositions, accepted route decisions, and generated path `NexusTK/ui/core/ScrollBar.cpp`. |
| Raise `ScrollBar.md` to `COMPLETION:90`, `CONFIDENCE:87`. | incorporate | applied | Metadata updated in `by-file/ScrollBar.md`; final validator `000000003452` returned `ok: 1` and generated refresh completed. |
| Preserve `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/"` and `CANONICAL_OWNER:FILE`. | already-present | already-present | Metadata was already correct and remained unchanged in `by-file/ScrollBar.md`. |
| Populate `00003D` with class-route marker, not full class declaration. | incorporate | applied | `by-class/CScrollBarBackPane.md` now has metadata `87/88` and a formal route marker plus `[[CHILDREN]]`; no broad class declaration was added. Validator `000000003453` returned `ok: 1`. |
| Populate `0001DV` with aggregate no-code marker. | incorporate | applied | `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` now has metadata `87/89`, a formal aggregate marker, and prose preserving constructor bytes / cleanup glue / fixed-line draw split. Validator `000000003454` returned `ok: 1`. |
| Populate `0003LR`, `0003CK`, and `0003CL` with vtable/RTTI no-code markers. | incorporate | applied | `0003LR`, `0003CK`, and `0003CL` now have formal compiler-generated/no-handwritten-table markers; `0003LR` and `0003CL` also have nonblank item summaries. Validators `000000003455`, `000000003459`, and `000000003464` returned `ok: 1`. |
| Populate `0000CM`, `0000CP`, and `0000CF` with route markers. | incorporate | applied | `ScrollPane`, `ScrollWidget`, and `ScrollablePane` class pages now carry formal route markers with `[[CHILDREN]]` so exact child bodies still assemble. Metadata is `0000CM 87/88`, `0000CP 86/86`, `0000CF 89/90`. Validators `000000003456`, `000000003460`, and `000000003461` returned `ok: 1`. |
| Populate `000433` with first-draft `ScrollPane::OnMouseEvent` C++. | incorporate | applied | `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` now has metadata `88/90`, the exact formal body from this report, and prose preserving adjusted receiver, event fields, EPF/classic branches, capture/release, helpers, thumb-drag, and invalidation caveats. Validator `000000003457` returned `ok: 1`; generated `ScrollBar.cpp` contains UID000433 and `bool ScrollPane::OnMouseEvent(const PaneMouseEvent& event)`. |
| Populate `0003A5` with aggregate route marker. | incorporate | applied | `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` now has metadata `87/89`, a formal aggregate marker plus `[[CHILDREN]]`, and helper-name support for UID000433: `HitTestPart`, `BeginPartPress`, `ProcessActivePart`, `ResetScrollState`. Validator `000000003458` returned `ok: 1`. |
| Populate `0001GL` with multi-method aggregate marker. | incorporate | applied | `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` now has metadata `88/90` and formal no-aggregate-body marker. Validator `000000003462` returned `ok: 1`. |
| Populate `0001H6` with compiler-thunk/default aggregate marker. | incorporate | applied | `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md` now has metadata `88/90` and formal marker preserving adjustor-thunk / scalar deleting destructor / default metric body policy. Validator `000000003463` returned `ok: 1`. |
| Populate `0003CQ` with first-draft constant C++. | incorporate | applied | `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` now has metadata `87/89`, nonblank item summary, source declaration prose, and four formal `static const int` tables. Validator `000000003465` returned `ok: 1`; generated `ScrollBar.cpp` contains the four declarations. |
| Do not edit generated reports, generated C++, coverage reports, validator state, queue files, archives, or supervisor ledgers during report pass. | not-applicable | applied | No generated or supervisor-owned files were manually edited. Validators refreshed generated/project state. |
| Do not use fallback-only evidence. | already-present | already-present | MCP evidence remained the basis for the accepted report; implementation used the accepted MCP-backed facts and scoped validators. |

## Implementation Tracking Checklist

- [x] Update `by-file/ScrollBar.md` metadata to `90/87`, preserve path/FILE owner, and add the 2026-07-01 generated-output audit with all 13 populated outputs and 13 empty-marker dispositions. Proof: metadata and audit applied; validator `000000003452` / `2026-07-01T05:41:46-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-class/CScrollBarBackPane.md` to `87/88` and insert the class route comment marker. Proof: formal route marker plus `[[CHILDREN]]`; validator `000000003453` / `2026-07-01T05:41:56-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md` to `87/89` and insert the aggregate no-code marker. Proof: formal aggregate marker inserted; validator `000000003454` / `2026-07-01T05:42:06-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md` to `87/91`, add the nonblank item summary, and insert the vtable/RTTI marker. Proof: item summary and marker inserted; validator `000000003455` / `2026-07-01T05:42:17-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-class/ScrollPane.md` to `87/88` and insert the class route comment marker. Proof: marker plus `[[CHILDREN]]` inserted and UID000433 child-body summary added; validator `000000003456` / `2026-07-01T05:42:27-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` to `88/90`, insert the first-draft `ScrollPane::OnMouseEvent` formal C++ body, and preserve adjusted receiver, event-field, EPF/classic, capture/release, helper, thumb-drag, and invalidation caveats. Proof: formal body inserted; validator `000000003457` / `2026-07-01T05:42:38-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md` to `87/89`, insert the aggregate route marker, and preserve helper-name support for UID000433: `HitTestPart`, `BeginPartPress`, `ProcessActivePart`, and `ResetScrollState`. Proof: marker plus `[[CHILDREN]]` and helper-name support applied; validator `000000003458` / `2026-07-01T05:42:52-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md` to `87/90` and insert the vtable/RTTI marker. Proof: formal marker inserted; validator `000000003459` / `2026-07-01T05:43:02-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-class/ScrollWidget.md` to `86/86` and insert the class route marker. Proof: marker plus `[[CHILDREN]]` inserted; validator `000000003460` / `2026-07-01T05:43:12-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-class/ScrollablePane.md` to `89/90` and insert the class route marker. Proof: marker plus `[[CHILDREN]]` inserted; validator `000000003461` / `2026-07-01T05:43:23-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md` to `88/90` and insert the multi-method aggregate marker. Proof: formal marker inserted; validator `000000003462` / `2026-07-01T05:43:33-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md` to `88/90` and insert the compiler-thunk/default aggregate marker. Proof: formal marker inserted; validator `000000003463` / `2026-07-01T05:43:43-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md` to `88/91`, add the nonblank item summary, and insert the vtable/RTTI marker. Proof: item summary and marker inserted; validator `000000003464` / `2026-07-01T05:43:54-04:00` returned exit `0`, `ok: 1`.
- [x] Update `by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md` to `87/89`, add the nonblank item summary, and insert the four constant declarations in the formal C++ block. Proof: item summary and four `static const int` declarations inserted; validator `000000003465` / `2026-07-01T05:44:04-04:00` returned exit `0`, `ok: 1`.
- [x] Run scoped validators with `--wait-generated` for the accepted target/support docs only after supervisor callback. Proof: final pass ran all 14 accepted files, commands `000000003452` through `000000003465`, each exit `0`, `ok: 1`, generated refresh completed.
- [x] Inspect regenerated `auto-generated/NexusTK/ui/core/ScrollBar.cpp` after validation and confirm the applicable empty markers no longer appear. Proof: header `validator-command-id: 000000003465`, `validator-refreshed-at: 2026-07-01T05:44:04-04:00`; UID000433 emits `ScrollPane::OnMouseEvent`, UID0003CQ emits four constants, broad pages emit comments, and `rg "EMPTY|empty marker|No reconstruction code|TODO"` found no original empty-marker text.

## Suggested Scoped Validators After Callback

Run validators only after accepted by-* edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000NF-ScrollBar-empty-emitter-family-source-quality-removed.md](0000NF-ScrollBar-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The supervisor may choose a smaller first implementation batch. The by-file audit should record no-code dispositions for unchanged markers so they are not treated as forgotten future work.

## Blockers

None for supervisor validation. MCP was available and all in-scope empty markers have a direct disposition.

## Changed Files

- `tools/leaser/Agents/Agent-B007/research/0000NF-ScrollBar-empty-emitter-family-source-quality.md`

Leases used: none. This was a report-only research file edit.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000NF-ScrollBar-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000NF-ScrollBar-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T05:48:43","uid":"0000NF"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000NF-ScrollBar-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000NF-ScrollBar-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000NF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
