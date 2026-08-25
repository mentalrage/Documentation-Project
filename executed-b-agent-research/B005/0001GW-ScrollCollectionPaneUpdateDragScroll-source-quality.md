** TARGET-REPORT-UID:0001GW **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001GW ScrollCollectionPane UpdateDragScroll Source-Quality Research

Agent: Agent-B005
Assignment: B005-report-0001GW-scroll-collection-pane-update-drag-scroll-20260626
Report status: REPORT ONLY
Target from goal.md: [UID:0001GW] `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`
Report timestamp: 2026-06-26T00:49:25-04:00

## Executive Recommendation

Accept [UID:0001GW] as source-authored `ScrollCollectionPane::UpdateDragScroll()` and populate first-draft C++ in the target page. The previous blockers are now resolved at report level: live MCP confirms the exact modeled function, the two modeled callers plus the raw start-drag caller, the helper/callee graph, the active/highlight field offsets, the pane-local cursor conversion, and the relationship to `HitTestScrollRegion`, `SetActiveRegionAndStartDragRaw`, and `UpdatePositionFromCursor`.

Recommended post-implementation metadata:

| Field | Current observed state | Recommendation |
|---|---:|---:|
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000NG` | `0000CG` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000NG` | `0000CG` |
| `EMITTER_POSITION_OPTIONAL` | blank | `70` |
| Source name | `UpdateDragScroll` page title | `ScrollCollectionPane::UpdateDragScroll()` |

Owner/emitter route: use [UID:0000CG] `ScrollCollectionPane` as the direct class owner/emitter. [UID:0000NG] `ScrollCollectionPane` remains the source-file route under `NexusTK/ui/core/ScrollCollectionPane.cpp`, not the direct canonical owner. Reject generic `ScrollBar.cpp`, file-level-only ownership, and shared-scrollbar ownership for this target.

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void ScrollCollectionPane::UpdateDragScroll()
{
    Point cursor;
    Point origin;
    RectBounds rect;
    int localY;
    int localX;
    ScrollCollectionPart activePart;
    ScrollCollectionPart hitPart;
    ScrollCollectionPart highlightPart;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    localY = cursor.y - origin.y;
    localX = cursor.x - origin.x;

    activePart = static_cast<ScrollCollectionPart>(m_activePart);
    if (activePart == kScrollCollectionPartThumb) {
        UpdatePositionFromCursor(localY, localX);
        return;
    }

    hitPart = HitTestScrollRegion(localY, localX);
    if (hitPart == activePart) {
        UpdatePositionFromCursor(localY, localX);
    }

    highlightPart = static_cast<ScrollCollectionPart>(m_highlightPart);
    if (highlightPart != kScrollCollectionPartNone) {
        GetPartRect(highlightPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = kScrollCollectionPartNone;
    }
}
```

The method is `void`. IDA decompiles a `char` return artifact because the last helper or byte load leaves `AL` live, but all three callers ignore the value. Source shape should match the caller behavior and sibling scroll-pane patterns.

## Current Repository State

No by-* or generated files were edited during this report-only pass.

Observed target state:

| Item | Current observation |
|---|---|
| Target path | `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md` |
| Header metadata | `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000NG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NG`, blank emitter position |
| Formal C++ | blank |
| Existing page summary | Already records exact modeled boundary, modeled/raw callers, cursor/input global, invalid point sentinel, active/highlight fields, hit-test/update calls, stale-highlight invalidation, and next-helper boundary |
| Generated tracker | `auto-generated/-ag-research-tracker.md` still has a stale row for UID `0001GW` at old `76/86` and report count `0` |
| Generated C++ | `auto-generated/NexusTK/ui/core/ScrollCollectionPane.cpp` contains the accepted `ResetScrollState()` body, but still has an empty marker for UID `0001GW` with stale `76/86` marker text |

Primary documents read as evidence:

| Path | Evidence used |
|---|---|
| `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md` | Current target state, prior boundary/caller/callee/body notes, stale C++ blocker wording |
| `by-class/ScrollCollectionPane.md` | Direct class owner [UID:0000CG], method table, sibling helper rows, source route through file UID `0000NG` |
| `by-file/ScrollCollectionPane.md` | Current source-file route `NexusTK/ui/core/ScrollCollectionPane.cpp`; final standalone-vs-scrollbar caveat |
| `by-type/by-struct/ScrollCollectionPaneLayout.md` | Accepted field names and offsets: `m_highlightPart` at `+0x103`, `m_activePart` at `+0x104`, `m_thumbDragOffset` at `+0x108/+0x10c`, orientation/range/current/enabled fields, part-code table |
| `by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md` | Hit-test role, caller pair, part ids `0..4/-1`, relationship to this target |
| `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md` | Raw start-drag setup, active-part store, thumb drag-offset setup, immediate call into this target |
| `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md` | Cursor-to-position helper role, two callsites from this target, argument/offset relationship |
| `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md` | Accepted C++ precedent for `m_highlightPart`, `m_activePart`, `GetPartRect`, `InvalidateRect`, and `-1` sentinel |
| `executed-b-agent-research/B014/0001GY-ScrollCollectionPaneClearHighlightRaw-source-quality.md` | Accepted B014 implementation rationale for `ResetScrollState`, direct class owner, helper names, and stale gate correction |
| `executed-b-agent-research/B008/00014C-EventManAndEventFactoryHelpers-source-quality.md` and related cursor-helper docs | `dword_67A754` as `g_pEventMan`, `0x004a9090` as `EventMan::GetCursorPosition(Point*)` |
| `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md` | Current project convention that `Point` fields are y/x while `RectBounds` fields are top/left/bottom/right |

## IDA MCP Availability

IDA MCP was available and used for this report. This is not a fallback-only report.

| Field | Value |
|---|---|
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` version `1.0.0` |
| Protocol | `2025-06-18` |
| Active session | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Input path | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Module | `NexusTK.exe` |
| Imagebase | `0x400000` |
| Worker PID | `26892` |
| Auto-analysis | ready / `is_analyzing:false` |
| Hex-Rays | ready |
| Strings cache | ready, size `2067` |

Current MCP calls used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `xrefs_to`, `xref_query`, `callees`, `decompile`, `disasm`, `analyze_function`, and `insn_query`.

One `get_bytes` request initially used the obsolete `addr`/`size` shape and returned a schema error requiring `regions`. It was rerun successfully with the current schema. That was a request-shape error, not MCP unavailability or busy state.

## IDA MCP Findings

### Function Boundary

MCP confirms `0x00562fb0` is a modeled function:

| Address/query | MCP result |
|---|---|
| `lookup_funcs 0x00562fb0` | `sub_562FB0`, size `0xc0` |
| `lookup_funcs 0x00563070` | `sub_563070`, size `0x18d` |
| `entity_query functions 0x00562f90-0x00563090` | exactly `sub_562FB0` at `0x562fb0` size `0xc0` and `sub_563070` at `0x563070` size `0x18d` |
| `get_bytes 0x00562fab size 5` | `5d c2 0c 00 cc`; the prior raw helper returns with `retn 0Ch`, then one `cc` byte at `0x00562faf` |
| `get_bytes 0x00562faf size 1` | `cc` |
| `get_bytes 0x00563070 size 8` | `55 8b ec 83 ec 48 a1 24`; the next modeled helper begins immediately at `0x00563070` |

The target range is exactly `0x00562fb0-0x00563070`, size `0xc0` / 192 decimal. There is one `cc` byte immediately before the function and no post-function padding before `0x00563070`; the next helper starts at the half-open end.

### Xrefs And Callees

Incoming xrefs to `0x00562fb0`:

| Callsite | Containing function | Meaning |
|---|---|---|
| `0x00562123` | `sub_561FB0`, size `0x1e1` | modeled input/press path calls this target after setting active part and before scheduling the `0xc8` repeat timer |
| `0x005621c8` | `sub_5621B0`, size `0x33` | modeled timer/update callback calls this target when active part is not `0xff`, then schedules interval `0x1e` |
| `0x00562f82` | `fn:null` | raw `SetActiveRegionAndStartDragRaw` call after active-part store |

Outgoing callees from `0x00562fb0`:

| Callee | Source-facing role |
|---|---|
| `0x004a9090` / `sub_4A9090` | `g_pEventMan->GetCursorPosition(&cursor)` |
| `0x005447c0` / `sub_5447C0` | inherited `Pane::GetScreenOffset(&origin)` |
| `0x005628d0` / `sub_5628D0` | `ScrollCollectionPane::HitTestScrollRegion(localY, localX)` |
| `0x00562bf0` / `sub_562BF0` | `ScrollCollectionPane::GetPartRect(part, &rect)` |
| `0x00563070` / `sub_563070` | `ScrollCollectionPane::UpdatePositionFromCursor(localY, localX)` |
| `0x005c772f` / security check | compiler stack-cookie epilogue |

Relevant sibling xrefs:

| Target | MCP result |
|---|---|
| `xrefs_to 0x005628d0` | two xrefs: `0x00562091` in `sub_561FB0` and `0x0056301f` in this target |
| `xrefs_to 0x00563070` | two xrefs: `0x0056300b` and `0x00563034`, both inside this target |
| `xrefs_to 0x00562bf0` | thirteen xrefs across input, draw, raw highlight/start-drag helpers, this target, `UpdatePositionFromCursor`, and reset-state helper |

### Target Body

MCP decompilation and disassembly for `sub_562FB0` show:

| Address | Instruction/decompile fact | Source interpretation |
|---|---|---|
| `0x00562fc6-0x00562fcd` | reads `dword_67A754`; calls `sub_4A9090` | `g_pEventMan->GetCursorPosition(&cursor)` |
| `0x00562fd3-0x00562fd8` | pushes local and calls `sub_5447C0` | `GetScreenOffset(&origin)` |
| `0x00562fe2-0x00562fec` | compares both origin components to `0xfffffc18` / `-1000` | sentinel check for invalid pane/screen origin |
| `0x00562ff1-0x00563003` | subtracts origin components from cursor components | pane-local coordinate conversion |
| `0x00562ffb` | `cmp byte ptr [esi+104h], 2` | active part is thumb |
| `0x0056300b` | calls `sub_563070` | thumb drag path calls `UpdatePositionFromCursor(localY, localX)` and returns |
| `0x0056301f` | calls `sub_5628D0` | non-thumb path calls `HitTestScrollRegion(localY, localX)` |
| `0x00563024` | compares hit-test result to `[esi+104h]` | only update when cursor remains over active non-thumb region |
| `0x00563034` | calls `sub_563070` | repeat/page path calls `UpdatePositionFromCursor(localY, localX)` |
| `0x00563039-0x0056303f` | reads `[esi+103h]`, compares with `0xff` | checks old highlighted part |
| `0x0056304a` | calls `sub_562BF0` with old highlight and local rect | `GetPartRect(highlightPart, &rect)` |
| `0x00563057` | indirect call through vtable slot `+0x20` | inherited `InvalidateRect(&rect)` |
| `0x0056305a` | writes `0xff` to `[esi+103h]` | `m_highlightPart = -1` |

This body does not write `m_activePart`; it consumes the field set by the input/raw/timer contexts and clears only stale highlight state on the non-thumb path.

### Modeled Caller Roles

`sub_561FB0` is the modeled input/press path. MCP decompilation shows it:

- pulls event coordinates from `a2 + 8` and `a2 + 12`;
- rejects disabled/range-empty state;
- calls `HitTestScrollRegion` at `0x00562091`;
- if the hit part is thumb, invalidates old/new thumb highlight, stores the thumb drag offset through `sub_4B7C30(&this+0x108, mouseY - rect.top, mouseX - rect.left)`;
- stores active part at `this+0x104` at `0x0056211d`;
- calls this target at `0x00562123`;
- schedules the embedded `+0xa4` update handler with interval `0xc8` at `0x00562139`;
- ignores this target's decompiler return artifact.

`sub_5621B0` is the modeled timer/update callback. MCP decompilation and disassembly show:

- it checks `arg_0 == 0`;
- it checks the adjusted receiver byte `this[96] != 0xff`, which maps to object field `+0x104` because the receiver is the embedded handler view at object `+0xa4`;
- it calls this target at `0x005621c8`;
- it schedules the handler with interval `0x1e` at `0x005621d7`;
- it returns `1`, ignoring this target's `AL`.

### Raw Start-Drag Caller

MCP `insn_query` over `0x00562ef0-0x00562faf` confirms the raw helper has `fn:null` for all 70 instructions and ends with `retn 0Ch` before the single `cc` byte. The raw body is [UID:0003MY] `ScrollCollectionPaneSetActiveRegionAndStartDragRaw`.

Relevant raw instructions:

| Address | Instruction | Source interpretation |
|---|---|---|
| `0x00562f07` | `cmp bl, 2` | special thumb setup only for part `2` |
| `0x00562f0c` | `mov al, [esi+103h]` | read `m_highlightPart` |
| `0x00562f21`, `0x00562f39`, `0x00562f58` | calls `sub_562BF0` | invalidate old/new/thumb rectangles through `GetPartRect` |
| `0x00562f49` | `mov byte ptr [esi+103h], 2` | set highlight part to thumb |
| `0x00562f5d-0x00562f72` | subtracts thumb rect top/left from incoming coordinates and calls `sub_4B7C30` on `esi+108h` | store `m_thumbDragOffset` |
| `0x00562f7c` | `mov [esi+104h], bl` | store `m_activePart` |
| `0x00562f82` | `call sub_562FB0` | immediate call to this target |
| `0x00562f87-0x00562f98` | pushes `0, 0xc8, 0, 0` and calls `sub_5975E0` through `esi+0xa4` | schedule repeat/update handler |

This proves the raw helper sets up the exact state that this target consumes. The raw helper should remain a separate child; no split or merge is needed for UID `0001GW`.

### UpdatePositionFromCursor Argument Order

MCP decompilation/disassembly of `0x00563070` confirms `UpdatePositionFromCursor` accepts the pane-local first component and second component as two stack arguments. In source-facing project convention, these are `localY` then `localX`:

| Address | Evidence | Interpretation |
|---|---|---|
| `0x00563189-0x00563195` | orientation `0` branch reads `arg_0` and subtracts `[this+0x108]` | vertical/default path consumes first argument and first drag-offset component |
| `0x00563151-0x0056315d` | nonzero orientation branch reads `arg_4` and subtracts `[this+0x10c]` | horizontal path consumes second argument and second drag-offset component |
| `0x00563085` | reads old position from `+0xfe` | target update is position math, not hit-test or highlight state |
| `0x005631d6-0x005631e5` | vtable `+0x1c` owner lookup, then `sub_56FA90(orientation, oldPosition, newPosition)` | callback to the owning `CollectionPane` only on position change |

The formal block therefore uses `UpdatePositionFromCursor(localY, localX)` and `HitTestScrollRegion(localY, localX)`. This follows the current accepted `Point` y/x convention while keeping `RectBounds` top/left/bottom/right separate.

## Source-Facing Names And Aliases

Recommended names:

| Binary item | Source-facing name | Confidence | Rationale |
|---|---|---:|---|
| `0x00562fb0` | `ScrollCollectionPane::UpdateDragScroll()` | High | Existing target title, caller/timer role, and sibling scroll-pane patterns |
| `0x005628d0` | `HitTestScrollRegion(localY, localX)` | High | Existing child page and call role; returns part id `0..4/-1` |
| `0x00562bf0` | `GetPartRect(part, &rect)` | High | Accepted B014 reset C++ uses this name; all callers materialize part rectangles |
| `0x00563070` | `UpdatePositionFromCursor(localY, localX)` | High | Existing child page and position-math behavior |
| `0x004a9090` with `dword_67A754` | `g_pEventMan->GetCursorPosition(&cursor)` | High | EventMan helper reports and current cursor callers agree |
| `0x005447c0` | `GetScreenOffset(&origin)` | High | Pane offset/origin helper precedent; use `GetScreenOffset` for this draft |
| `this+0x103` | `m_highlightPart` | High | Accepted B014 implementation and layout page |
| `this+0x104` | `m_activePart` | High | Accepted B014 implementation, modeled timer receiver adjustment, raw start-drag store |
| `this+0x108/+0x10c` | `m_thumbDragOffset` | High role, medium component spelling | Raw start-drag writes it; update-position consumes it |
| part enum/constants | `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `kScrollCollectionPartNone` | Medium-high | Matches `ScrollVolumePart`, `ScrollNewGroupPart`, and `FittingRoomScrollPart` naming style; exact original enum spelling is not symbol-proven |

Rejected alternatives:

| Alternative | Rejection reason |
|---|---|
| `char` return / boolean-returning source method | caller decompilations and disassembly ignore the return; `AL` is a compiler/decompiler artifact |
| Direct file-level owner [UID:0000NG] | current class docs, layout, sibling helper implementations, and call graph make [UID:0000CG] the narrower direct owner; file UID is the source route only |
| Generic `ScrollBar.cpp` or shared-scrollbar owner | this body uses `ScrollCollectionPane` field offsets, collection callback route, and class-local helper island; no independent generic source owner is evidenced |
| `ScrollCollectionPane` as an unqualified file/free-function owner | target is a class method; use `ScrollCollectionPane::UpdateDragScroll()` under class owner [UID:0000CG] |
| `ProcessActivePart` | good sibling analogy for FittingRoom, but the existing ScrollCollection target/source route already names the behavior `UpdateDragScroll`; changing it would add churn without stronger evidence |
| `GetScreenOrigin` for this target | acceptable descriptive alias in some older docs, but `GetScreenOffset` is the current stronger project-facing name from recent ScrollNewGroup and cursor-helper implementations |
| Leaving C++ blank because exact original spellings are not symbol-proven | current rules allow source-facing inferred names when evidence is strong; the unresolved exact spellings do not materially block this body |

## Split And Range Implications

No split is recommended for UID `0001GW`.

- `0x00562fb0` is a modeled function of exact size `0xc0`.
- The previous raw helper ends with `retn 0Ch` at `0x00562fac`, followed by one `cc` byte at `0x00562faf`.
- The next modeled helper starts immediately at `0x00563070`.
- The raw start-drag helper `0x00562ef0-0x00562faf` and the next update-position helper `0x00563070-0x005631fd` are separate children with distinct responsibilities.
- The unsplit geometry helper at `0x00562bf0` does not block this target's C++. Accepted sibling code already uses the source-facing `GetPartRect` call, and this target only calls that helper rather than reconstructing its internal geometry.

## C++ Readiness

This target is ready for first-draft C++ now.

Readiness criteria:

| Criterion | Status |
|---|---|
| Exact body boundary | Resolved by MCP `lookup_funcs`, `entity_query`, bytes, and disassembly |
| Direct owner/emitter | Resolved as class [UID:0000CG] with file route [UID:0000NG] |
| Caller roles | Resolved: input press, timer callback, raw start-drag |
| Callee/helper names | Resolved to current source-facing names |
| Active/highlight fields | Resolved by accepted B014 implementation and current MCP field use |
| Cursor/local conversion | Resolved with `g_pEventMan`, `GetScreenOffset`, sentinel check, and `localY/localX` |
| Return type | Resolved as `void` from caller behavior |
| Split/range concern | No split needed |
| Source placement concern | Direct class owner; file route remains `NexusTK/ui/core/ScrollCollectionPane.cpp` |

The recommended score `89/91` is intentionally below perfect because exact original enum/member spellings and final standalone-vs-merged source-file layout remain inferred, and sibling `HitTestScrollRegion` / `UpdatePositionFromCursor` C++ is still blank. Those caveats no longer block this target's own formal C++.

## Implementation Plan

When the supervisor accepts this report, the implementation callback should lease only the immediate docs being edited, apply the accepted details at report-level detail, run scoped validators, and release leases immediately.

Required target edit:

- Update `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`.
- Set `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`, `EMITTER_POSITION_OPTIONAL:70`.
- Insert the exact C++ block from this report into the formal `RECONSTRUCTION_CPP CODE` section.
- Update the item summary and body with current MCP facts: exact `0x00562fb0-0x00563070` boundary, one `cc` byte before and immediate next helper at `0x00563070`, three incoming xrefs, outgoing callees, modeled input/timer callers, raw start-drag caller, cursor helper names, invalid origin sentinel, active/highlight fields, non-thumb hit-test/update rule, thumb direct update, stale-highlight invalidation, and `Point` y/x vs `RectBounds` convention.
- Replace stale "C++ blank until 90/90+" or "helper names unresolved" wording with the current code-readiness rationale.
- Preserve [UID:0000NG] as the source-file route but not direct owner; reject generic/shared scrollbar ownership.

Required support edit:

- Update `by-class/ScrollCollectionPane.md`.
- Add or reconcile a note that [UID:0001GW] now has first-draft `ScrollCollectionPane::UpdateDragScroll()` C++ at child position `70`.
- Reconcile aliases with B014/B014-implemented names: `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `HitTestScrollRegion`, and `UpdatePositionFromCursor`.
- If adding enum wording, use `ScrollCollectionPart` / `kScrollCollectionPartThumb` / `kScrollCollectionPartNone` consistently with the target C++ and sibling scroll-pane enum style. Do not introduce conflicting `region` field names for `+0x103/+0x104`; the fields are accepted as part fields even though the hit-test helper name uses `Region`.

Optional sibling edit:

- `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md` does not require an edit for this report to be actionable. It already records thumb highlight setup, `m_thumbDragOffset` setup/use, `m_activePart` store, immediate call to this target, and repeat scheduling.
- Edit that sibling only if the implementation callback finds stale alias wording that conflicts with the new target C++/enum names. If edited, validate it with a scoped file validator.

Validator commands for the accepted implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality-removed.md](0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the optional raw sibling is edited:

> Executable block R002 was removed from this report and preserved verbatim in [0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality-removed.md](0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not hand-edit generated tracker/source/coverage output. Let validator/autogen refresh stale rows.

## Blocker Resolution

| Named blocker/question | Resolution |
|---|---|
| Source-facing name | Resolved as `ScrollCollectionPane::UpdateDragScroll()` |
| Active/highlight field names | Resolved as `m_activePart` and `m_highlightPart` from B014 and current MCP evidence |
| Cursor helper names | Resolved as `g_pEventMan->GetCursorPosition(&cursor)` and `GetScreenOffset(&origin)` |
| Pane-local coordinate order | Resolved as `localY`, `localX` by target call order and `UpdatePositionFromCursor` argument use |
| Owner/emitter support | Resolved: class [UID:0000CG] direct owner/emitter, file [UID:0000NG] route only |
| Modeled/raw caller roles | Resolved with MCP caller decompilation/disassembly and raw `insn_query` |
| Relation to `HitTestScrollRegion` | Resolved: non-thumb path calls it and updates only when result matches active part |
| Relation to `SetActiveRegionAndStartDragRaw` | Resolved: raw helper writes active part, writes thumb drag offset for thumb, calls this target, schedules repeat |
| Relation to `UpdatePositionFromCursor` | Resolved: this target is the only caller; direct thumb path and matched non-thumb path both call it |
| Split/range implications | Resolved: exact modeled `0xc0` function, no split/merge needed |
| Formal C++ readiness | Resolved: exact formal block supplied above |
| Stale generated/tracker rows | Resolved as implementation/autogen refresh work, not a source-quality blocker |

## Final Report Checklist

- [x] Lease `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md` only when ready to edit it. Proof: `python .\leaser.py B005 lease ...0x00562fb0-0x00563070... ...ScrollCollectionPane.md ...0x00562ef0-0x00562fb0...` returned `Success` for the target immediately before edits.
- [x] Lease `by-class/ScrollCollectionPane.md` only when ready to edit the support note. Proof: the same immediate lease batch returned `Success` for `by-class\ScrollCollectionPane.md`.
- [x] Apply target metadata: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000CG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CG`, `EMITTER_POSITION_OPTIONAL:70`. Proof: target header now carries exactly those values; validator command `000000002044` recorded `completion_update 89`, `confidence_update 91`, and `canonical_owner_update 0000CG`.
- [x] Insert the exact formal C++ block from this report into the target `RECONSTRUCTION_CPP CODE` block. Proof: `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md` now contains the exact `void ScrollCollectionPane::UpdateDragScroll()` block from this report between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`; validator command `000000002044` recorded the reconstruction block hash transition `blank -> block`.
- [x] Update the target item summary/body with report-level MCP facts: boundary, padding, xrefs, callees, caller roles, cursor/local conversion, active/highlight fields, hit-test/update-position relationship, raw start-drag relationship, and source-owner rejections. Proof: target body now records exact `0x00562fb0-0x00563070` boundary, one prior `cc`, immediate next helper `0x00563070`, three incoming xrefs, callee set, modeled input/timer callers, raw start-drag caller, cursor helpers, invalid origin sentinel, `m_activePart`, `m_highlightPart`, `m_thumbDragOffset`, `HitTestScrollRegion`, `GetPartRect`, `UpdatePositionFromCursor`, point y/x convention, no-split decision, and rejected owner/name alternatives.
- [x] Update `by-class/ScrollCollectionPane.md` with the first-draft C++ note for UID `0001GW` at child position `70` and reconciled field/helper aliases. Proof: class page now has a source-facing alias table and method/parent rows for [UID:0001GW] with first-draft `ScrollCollectionPane::UpdateDragScroll()` C++ at position `70`, plus `ScrollCollectionPart`, `kScrollCollectionPartThumb`, `kScrollCollectionPartNone`, `m_highlightPart`, `m_activePart`, `m_thumbDragOffset`, `GetPartRect`, `HitTestScrollRegion`, and `UpdatePositionFromCursor`.
- [x] Do not edit `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md` unless stale alias wording conflicts with this implementation; if edited, validate it. Proof: edited because it still said active/drag field names were provisional; it now uses the accepted aliases and preserves the raw no-C++ caveat. Scoped validator command `000000002046` passed with `ok: 1`.
- [x] Run `python .\tools\validator.py --mode file --file by-memory\0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md --apply --queue-timeout 240` from `source-3/project-documentation`; record timestamp, validator command id, and `ok`. Proof: command_id `000000002044`, timestamp `2026-06-26T01:03:03-04:00`, `ok: 1`, `generated_refresh: deferred`.
- [x] Run `python .\tools\validator.py --mode file --file by-class\ScrollCollectionPane.md --apply --queue-timeout 240` from `source-3/project-documentation`; record timestamp, validator command id, and `ok`. Proof: command_id `000000002045`, timestamp `2026-06-26T01:03:08-04:00`, `ok: 1`, `generated_refresh: deferred`.
- [x] If the optional raw sibling is edited, run its scoped validator and record timestamp, validator command id, and `ok`. Proof: command_id `000000002046`, timestamp `2026-06-26T01:03:19-04:00`, `ok: 1`, `generated_refresh: deferred`; validator registered UID `0003MY` path mapping for the untracked sibling page.
- [x] Confirm leases used were released immediately after the edit/validator batch, or record expiration/release proof. Proof: post-validator path-specific `python .\leaser.py B005 unlease ...` returned `Rejected[No active lease]` for all three leased docs, then `python .\leaser.py B005 unlease` returned `B005: No active leases`; `tools/leaser/Agents/Agent-B005/current_leases.md` had no active B005 rows.
- [x] Confirm generated source/tracker/coverage files were not hand-edited and note any validator/autogen refresh state. Proof: no generated source/tracker/coverage or `-coverage-report.md` files were manually edited. Validators reported `generated_refresh: deferred` for commands `000000002044`, `000000002045`, and `000000002046`; project stats/registry/reference updates were validator/autogen effects only.
- [x] Update this report checklist during implementation with checked items and proof: files changed, exact metadata/C++ applied, validators with command id/timestamp/ok, leases used/released, and generated refresh state. Proof: checklist updated after validators. Files changed by implementation: target `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`, support `by-class/ScrollCollectionPane.md`, optional sibling `by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md`, and this report checklist.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality.md","timestamp":"2026-06-26T01:07:09","uid":"0001GW"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001GW-ScrollCollectionPaneUpdateDragScroll-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
