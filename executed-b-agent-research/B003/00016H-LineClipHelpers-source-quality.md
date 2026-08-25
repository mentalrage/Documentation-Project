** TARGET-REPORT-UID:00016H **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016H LineClipHelpers Source-Quality Recheck

Report-only B-agent pass for `[UID:00016H] by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`.

Assignment id: `B003-report-00016H-line-clip-helpers-source-quality-20260626`.

## Finalized Report / Current Recommendation

- Current recommendation: do not change [UID:00016H] target metadata or formal C++; the current target page already contains the source-quality result that this assignment originally requested.
- Final disposition: keep `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, and the current formal `LineClipPoint` / `ClipLineToRect` / `ClipLineParameter` C++ block.
- Required action: no target by-memory edit is required for [UID:00016H]. If supervisor accepts this B003 report for implementation, perform only the support-doc cleanup listed in the checklist: refresh stale [UID:0002PJ] `Item Summary` text and fill the blank [UID:0003XF] `Item Summary`; otherwise treat target/support details as already present at same-or-greater detail from the executed B002 pass.
- Confidence: strong for the no-change target disposition; medium-high for the optional support-summary cleanup because it is metadata text synchronization, not a new ownership or behavior claim.

## Target

- Target UID: `00016H`
- Target path: `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`
- Source queue/report row: current `auto-generated/-ag-research-tracker.md` line for [UID:00016H] now lists `90/91`, average `90.5`, `true`, one executed report, updated `2026-06-26T15:11:04`, author `B002`, report `executed-b-agent-research/B002/00016H-LineClipHelpers-source-quality.md`. This supersedes the assignment's stale "not covered" context.
- Current supervisor classification: report-only research first; no split-execution override and no implementation callback.
- Goal-file stale context: `goal.md` says the target was `COMPLETION:86`, `CONFIDENCE:89`, blank formal C++, and not covered by an executed B-agent report. Current source docs and generated tracker show that B002 has already executed the same source-quality target.

## Current Target State

- Existing metadata: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`.
- Existing C++ state: formal `RECONSTRUCTION_CPP CODE` is populated with a file-local `LineClipPoint` record, `ClipLineToRect`, and private `ClipLineParameter`.
- Existing owner/emitter route: [UID:0000OC] `by-file/Surface.md`, staged under `NexusTK/render/Surface.cpp`.
- Existing target detail: current page records MCP-backed function boundaries, xrefs, callees, decompile behavior, raw padding, separation from [UID:0003XF], separation from [UID:00016I], source-shape rationale, stale `RankingEventListPane` rejection, score rationale, and B002 implementation history.
- Existing open questions/blockers in target: no current blocker prevents target first-draft C++; remaining caveats are final-audit caps only: inferred/descriptive helper names and provisional exact original Surface source-unit split.
- Related support docs checked: [UID:0000OC] `Surface`, [UID:0000TN] `SurfaceRenderCallbackTable`, [UID:0002PG] compat line callback, [UID:0002PJ] RGB565 line callback, [UID:00015S] `RectGeometryHelpers`, [UID:0000N2] `RectBounds`, [UID:0001VP] `RectBoundsLayout`, [UID:0003XF] raw pattern-pack island, [UID:00016I] `GrafPortDrawGlyph`, and the relevant `by-project-structure/proposed-source-tree.md` render/UI geometry sections.

## Supervisor Active Recheck

- This pass followed the current user instruction to continue as Agent-B003 and use live IDA MCP. MCP was available; no fallback-only report was produced.
- The target did not require split execution. The exact child pages around the boundary already exist: [UID:0003XF] for `0x004bb5b0-0x004bb5d1` and [UID:00016I] for `0x004bb5e0-0x004bb7e0`.
- Every source-bearing child in scope is either already documented or has a precise blocker. [UID:00016H] is source-ready; [UID:0003XF] remains no-owner/non-emitting because no entry route or xref exists; [UID:00016I] is independently GrafPort-owned and emits its own C++.

## Inference Research Guidance Check

- Address adjacency was treated as weak evidence. Ownership is based on xrefs/call surfaces, callback-table route, support docs, and source-family context.
- Current generated `RankingEventListPane` output was treated as stale generated-owner pollution. No ranking-specific state, vtable route, UI method caller, or ranking support doc supports owning [UID:00016H].
- IDA decompiler argument types were treated as evidence, not truth. MCP decompile labels the main function as `char __stdcall(float, float, _DWORD *)`, but disassembly and data flow show the first two stack arguments are point-record pointers and the third is a `RectBounds *`.
- The current target source names are not claimed as original symbols. `LineClipPoint`, `ClipLineToRect`, and `ClipLineParameter` are the best source-facing descriptive names supported by behavior and local render/geometry style.
- No Wave2/Wave3 source data was used as authority. The only Wave/simroot-related material used was as a rejected pollution clue.

## Heuristic / Inference Reanalysis And Validation

### Helper Names

- Best source-facing names: `ClipLineToRect` for `0x004bb2e0`, `ClipLineParameter` for `0x004bb520`, and local `LineClipPoint` for the two-int endpoint records.
- Evidence: the main helper calls `PointInRect`, clips against `left`, `right - 1`, `top`, and `bottom - 1`, updates enter/leave line parameters, and rewrites endpoints only after the segment survives. The private helper is called only by the main helper and implements the Liang-Barsky parameter accept/reject/update test.
- Rejected alternatives: `sub_4BB2E0`, `sub_4BB520`, `ClipTestParameter_4BB520`, `RankingEventListPane::ClipLine`, and a public `RectBounds` geometry helper name. Raw/decompiler names are rejected for source; `RectBounds` ownership is rejected because the external callers are software render line callbacks only.
- Remaining uncertainty: exact original helper spellings are not recovered. This caps confidence but does not block first-draft C++.

### Point And Rect Types

- Best type inference: endpoint record is two `int` fields in `y, x` order. `RectBounds` is the existing four-int `left, top, right, bottom` record.
- Evidence: MCP decompile/disasm show `PointInRect(*point, *(point+4), bounds)` for both endpoints; [UID:00015S] and [UID:0001VP] document `PointInRect(int y, int x, const RectBounds *bounds)` and half-open `left <= x < right`, `top <= y < bottom`.
- Rejected alternatives: `x, y` endpoint order would invert the observed `PointInRect` stack order; using `RECT` or an anonymous `_DWORD[2]` in final source would preserve decompiler shape rather than source shape.
- Remaining uncertainty: no dedicated by-type page for `LineClipPoint` exists, but a local private struct in the formal block is sufficient for this helper pair.

### Source Placement And Ownership

- Best direct owner/emitter: [UID:0000OC] `Surface` / `NexusTK/render/Surface.cpp`.
- Evidence: current MCP xrefs to `0x004bb2e0` are only `0x004bbc81` inside [UID:0002PG] and `0x004c0b71` inside [UID:0002PJ]. Both callback targets are installed through Surface render callback slot `0x0069b3e4` and have no ordinary feature-pane direct caller.
- Rejected alternatives: `RankingEventListPane` is generated callsite pollution; `RectBounds.cpp` is a type/helper dependency but not the call-surface owner; `GrafPort` owns adjacent glyph/text helpers but not this render-callback clipper; [UID:0003XF] and [UID:00016I] are neighboring but separate ranges.
- Remaining uncertainty: exact original render source-unit split among `Surface.cpp`, software-render callback files, and blend/helper files is provisional. This caps final-audit confidence, not the current owner/emitter route.

### Range / Split / Boundary

- Best range decision: keep [UID:00016H] exactly `0x004bb2e0-0x004bb5a5`.
- Evidence: MCP `lookup_funcs` confirms `sub_4BB2E0` at `0x004bb2e0` size `0x237` / 567 bytes (Verified with `int_convert.py`) and `sub_4BB520` at `0x004bb520` size `0x85` / 133 bytes (Verified with `int_convert.py`). MCP `make_signature_for_range` confirms `0x004bb517-0x004bb520` is nine `CC` bytes, `0x004bb5a5-0x004bb5b0` is eleven `CC` bytes, and `0x004bb5d1-0x004bb5e0` is fifteen `CC` bytes.
- Rejected merge routes: `0x004bb5b0` has zero MCP xrefs and no modeled function; `0x004bb5e0` is `sub_4BB5E0` size `0x200` / 512 bytes (Verified with `int_convert.py`) with two GrafPort text-helper callers, not a line-clip successor.
- Remaining uncertainty: none that affects [UID:00016H] boundaries.

### First-Draft C++

- Decision: keep the existing formal C++ block. It is safe now and already inserted.
- Evidence: current MCP decompile of `0x004bb2e0` confirms both-endpoints-inside early success, horizontal and vertical half-open edge tests, helper calls for top/bottom clipping, endpoint rewrite order, and signed 16-bit truncating delta application. Current MCP decompile of `0x004bb520` confirms positive denominator updates enter, negative denominator updates leave, and zero denominator accepts only when the edge distance is not positive.
- Rejected alternative: leaving `RECONSTRUCTION_CPP` blank is stale; the original assignment's blank-C++ blocker has already been resolved.
- Remaining uncertainty: source names are descriptive and some member/callback typedef names in the callers remain unresolved, so do not raise above current `90/91`.

## Evidence Checked

### Live IDA MCP Evidence

MCP endpoint `http://127.0.0.1:13337/mcp` was live.

- `initialize` JSON-RPC id `1`: returned `ida-pro-mcp` server `1.0.0`, protocol `2025-06-18`.
- `tools/list` JSON-RPC id `2`: confirmed current tool schema uses `database` session IDs and exposes `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `xrefs_to`, `decompile`, `disasm`, `trace_data_flow`, and `make_signature_for_range`.
- `idb_list` JSON-RPC id `3`: active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, `is_analyzing:false`.
- `server_health` JSON-RPC id `10`: `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- `lookup_funcs` JSON-RPC id `11`: `0x004bb2e0` is `sub_4BB2E0` size `0x237`; `0x004bb517` is not a function; `0x004bb520` is `sub_4BB520` size `0x85`; `0x004bb5a5`, `0x004bb5b0`, and `0x004bb5d1` are not functions; `0x004bb5e0` is `sub_4BB5E0` size `0x200`; `0x004bb9b0` is `sub_4BB9B0` size `0x6da`; `0x004c0850` is `sub_4C0850` size `0x72a`.
- `analyze_function` JSON-RPC id `12` for `0x004bb2e0`: size `567`, 34 basic blocks, cyclomatic complexity 21, callees `sub_4B7E80` and `sub_4BB520`, callers `sub_4BB9B0` and `sub_4C0850`, xrefs to `0x4bbc81` and `0x4c0b71`.
- `analyze_function` JSON-RPC id `13` for `0x004bb520`: size `133`, 12 basic blocks, cyclomatic complexity 4, no callees, two xrefs from `sub_4BB2E0` at `0x4bb46b` and `0x4bb492`.
- `py_eval` JSON-RPC id `14`: not available in this MCP session (`Method 'py_eval' not found`). This is a tool-schema absence, not MCP unavailability; no evidence in this report depends on `py_eval`.
- `xrefs_to` JSON-RPC id `20`: `0x004bb2e0` has exactly two code xrefs, `0x4bbc81` from `sub_4BB9B0` and `0x4c0b71` from `sub_4C0850`; `0x004bb520` has exactly two code xrefs from `sub_4BB2E0`; `0x004bb5b0` has zero xrefs; `0x004bb5e0` has two GrafPort text-helper code xrefs; `0x004bb9b0` and `0x004c0850` each have only callback setup data refs; `0x0069b3e4` has 26 slot refs including callback setup and dispatch users.
- `make_signature_for_range` JSON-RPC ids `24`, `25`, and `26`: padding signatures are `CC` repeated 9 bytes at `0x004bb517-0x004bb520`, `CC` repeated 11 bytes at `0x004bb5a5-0x004bb5b0`, and `CC` repeated 15 bytes at `0x004bb5d1-0x004bb5e0`.
- `decompile` JSON-RPC id `30` for `0x004bb2e0`: confirms the line clipping behavior and endpoint rewrites. Decompiler argument type names are rejected as final source types.
- `decompile` JSON-RPC id `31` for `0x004bb520`: confirms the parameter helper behavior.
- `disasm` JSON-RPC ids `32` and `33`: main function uses `retn 0Ch`; helper has 48 instructions and returns via `retn 10h`.

### Numeric Conversion Evidence

Used `python .\tools\int_convert.py` with JSON batch input, not manual conversion:

- `0x237 == 567`
- `0x85 == 133`
- `0x6da == 1754`
- `0x72a == 1834`
- `0x200 == 512`
- `0x9 == 9`
- `0xb == 11`
- `0xf == 15`
- `0x5b == 91`

Each value above is Verified with `int_convert.py`.

### Documentation And Generated Inputs Checked

- `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`
- `executed-b-agent-research/B002/00016H-LineClipHelpers-source-quality.md`
- `by-file/Surface.md`
- `by-file/RectBounds.md`
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
- `by-type/by-struct/RectBoundsLayout.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`
- `by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md`
- `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`
- `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`
- `by-project-structure/proposed-source-tree.md` render/Surface and UI/core RectBounds sections
- Read-only generated reports: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/-ag-memory-coverage.md`

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:00016H] remains exact `0x004bb2e0-0x004bb5a5`. | Confirmed | MCP function lookup, padding signatures, neighbor function lookup, target docs. | Checked `0x004bb5b0` zero xrefs and `0x004bb5e0` separate caller set. | None for current split. |
| Direct source/emitter route remains Surface. | Strong | Only two external target xrefs from software line callbacks; callback slot `0x0069b3e4`; Surface docs and proposed source tree. | Rejected RankingEventListPane, RectBounds direct ownership, GrafPort adjacency, raw/glyph neighbor merge. | Original source-unit split remains provisional below final audit. |
| `LineClipPoint` is `y, x`. | Strong | `PointInRect` argument order in target, [UID:00015S], [UID:0001VP]. | Rejected `x, y` because it inverts the current stack order. | No dedicated type page; local private struct is sufficient. |
| Existing formal C++ is behavior-equivalent first draft. | Strong | MCP decompile/disasm for both functions, caller/callee closure, current target body. | Checked helper direction, half-open edges, endpoint rewrite order, signed 16-bit truncation. | Exact original names remain unrecovered. |
| [UID:0002PJ] top `Item Summary` is stale. | Confirmed | Header summary still says old `78/86` and blank parent route while page metadata/status/changes now say assigned `87/89`. | Body and metadata are current; stale text is limited to summary. | Support-doc cleanup only. |
| [UID:0003XF] blank `Item Summary` is a support-doc quality gap. | Confirmed | Header has `Item Summary:` blank while body documents exact raw island, zero xrefs, no owner/emitter/C++. | Body has same-or-greater detail; generated coverage lacks concise summary text. | Support-doc cleanup only. |

## Positive Evidence Summary

- Live MCP reconfirms current [UID:00016H] function starts, sizes, callers, private helper xrefs, decompiled behavior, and neighbor separation.
- Current target page already incorporates the exact source-quality result requested by the stale B003 goal: score raised, C++ inserted, final helper/type names chosen, range boundary fixed, [UID:00015S] dependency applied, and [UID:0003XF] separation documented.
- Generated research tracker now records B002 as an executed report for [UID:00016H], and generated memory coverage marks [UID:00016H] as `coded` through `auto-generated/NexusTK/render/Surface.cpp`.
- Surface, SurfaceRenderCallbackTable, and line callback docs independently align on callback slot `0x0069b3e4` and software line-callback ownership.

## Negative Evidence Summary

- No ranking-specific xref, field, class route, vtable path, or support doc supports `RankingEventListPane` ownership.
- No external xrefs reach `0x004bb520`; it is private to `0x004bb2e0`.
- No xrefs reach `0x004bb5b0`; it must remain separate from [UID:00016H].
- `0x004bb5e0` has its own GrafPort text-helper callers, so it is not a LineClip child.
- No original symbol/debug evidence recovers exact names `ClipLineToRect`, `ClipLineParameter`, or `LineClipPoint`; they remain inferred source-facing names.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004bb2e0-0x004bb517` | [UID:00016H] target subrange | `ClipLineToRect` main body | TRUE | [UID:0000OC] Surface | target `90/91` | Source-ready; emits in target block. |
| `0x004bb517-0x004bb520` | target subrange | 9-byte `0xcc` alignment | n/a | target containment | target `90/91` | Confirmed padding. |
| `0x004bb520-0x004bb5a5` | [UID:00016H] target subrange | `ClipLineParameter` private helper | TRUE | [UID:0000OC] Surface | target `90/91` | Source-ready; emits in target block. |
| `0x004bb5a5-0x004bb5b0` | padding before [UID:0003XF] | 11-byte `0xcc` alignment | n/a | separate boundary | [UID:0003XF] `85/88` support | Not LineClip code. |
| `0x004bb5b0-0x004bb5d1` | [UID:0003XF] | raw pattern-pack island | TRUE but no owner/emitter | NONE | `85/88` | Separate exact page; C++ remains blank. |
| `0x004bb5d1-0x004bb5e0` | padding before [UID:00016I] | 15-byte `0xcc` alignment | n/a | separate boundary | [UID:00016I] context | Not LineClip code. |
| `0x004bb5e0-0x004bb7e0` | [UID:00016I] | `GrafPort::DrawGlyph` | TRUE | [UID:00005V] GrafPort | `90/92` | Separate GrafPort emitter with first-draft C++. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004bb2e0` | code xrefs from `0x004bbc81` and `0x004c0b71` | Only external callers are compat and RGB565 line callbacks. |
| `0x004bb520` | code xrefs from `0x004bb46b` and `0x004bb492` | Private helper called only by `ClipLineToRect`. |
| `0x004bb9b0` | data refs from `0x00558734` and `0x00558b8a` | Compat callback target is installed by setup/table refs. |
| `0x004c0850` | data refs from `0x00558822` and `0x00558ea6` | RGB565 callback target is installed by setup/table refs. |
| `0x0069b3e4` | 26 xrefs | Surface line-delta callback slot used by line/rectangle drawing paths. |
| `0x004bb5b0` | zero xrefs | Adjacent raw island has no entry route. |
| `0x004bb5e0` | code xrefs from `0x004bab57` and `0x004bac8a` | Separate GrafPort glyph drawer. |

## Ranked Ownership Analysis

### 1. [UID:0000OC] Surface

- Evidence for: exclusive external callers are Surface software line callbacks; callback slot `0x0069b3e4` and setup/table xrefs route through Surface render dispatch; Surface page already lists [UID:00016H] as source-ready line-clip support.
- Evidence against: exact original file split among Surface and software-render callback implementation files is not proven.
- Decision: accepted direct owner/emitter. Keep current metadata unchanged.

### 2. [UID:0000N2] RectBounds

- Evidence for: target uses `RectBounds`, `PointInRect`, and half-open rectangle geometry; support docs define field order and point argument order.
- Evidence against: no external callers from the RectBounds helper family; only software line callbacks call [UID:00016H].
- Decision: dependency/support context only.

### 3. GrafPort / GrafPort Text Helpers

- Evidence for: adjacent [UID:0003XF] and [UID:00016I] belong to GrafPort/glyph text context; line callbacks ultimately draw into GrafPort-like surface state.
- Evidence against: [UID:00016H] has no GrafPort receiver, no text/glyph semantics, and no GrafPort text-helper caller.
- Decision: rejected as direct owner for [UID:00016H].

### 4. RankingEventListPane / RankingDialog

- Evidence for: historical generated output attached this range to ranking UI.
- Evidence against: live xrefs show no ranking-specific caller/state; support docs identify the callback family as Surface render dispatch.
- Decision: rejected generated-owner pollution.

## Source Placement

Recommended source placement remains `NexusTK/render/Surface.cpp`, under [UID:0000OC] `Surface`.

This is stronger than `ui/core/RectBounds.cpp` because the only external call surface is the software-render line callback pair, not general geometry helpers. It is stronger than `GrafPort.cpp` because this helper is a free clipping helper for callback implementations rather than a `GrafPort` receiver method. It is stronger than feature UI ownership because callback registration and data refs are shared render infrastructure.

The original source may have used a narrower file such as `SoftwareRender.cpp` or `SurfaceBlitters.cpp`, but no current by-file page is more specific and validated than [UID:0000OC]. Keep [UID:0000OC] until a family-wide render-source split is created and clears the by-structure gate.

## Range / Split / Padding / Reclassification Analysis

No split or reclassification is required for [UID:00016H]. The current split is correct:

- `0x004bb2e0-0x004bb517`: main clipper.
- `0x004bb517-0x004bb520`: target-internal padding.
- `0x004bb520-0x004bb5a5`: private helper.
- `0x004bb5a5-0x004bb5b0`: post-target padding.
- `0x004bb5b0-0x004bb5d1`: separate raw island [UID:0003XF].
- `0x004bb5d1-0x004bb5e0`: pre-glyph padding.
- `0x004bb5e0-0x004bb7e0`: separate GrafPort glyph drawer [UID:00016I].

The assignment's "nearby `0x004bb5b0` byte island/source-boundary issue" is resolved in target/source docs at the behavior and boundary level. Only [UID:0003XF]'s blank `Item Summary` remains a support metadata quality gap.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edit is requested or permitted in this report-only pass.
- Source-facing documentation names to preserve: `LineClipPoint`, `ClipLineToRect`, `ClipLineParameter`, `RectBounds`, `PointInRect`.
- Keep raw IDA names only as search aliases in evidence: `sub_4BB2E0`, `sub_4BB520`, `sub_4BB9B0`, `sub_4C0850`.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The current formal target block is already the recommended block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct LineClipPoint {
    int y;
    int x;
};

static bool ClipLineParameter(int delta, int edgeDistance, float *enter, float *leave);

static bool ClipLineToRect(LineClipPoint *start,
                           LineClipPoint *end,
                           const RectBounds *bounds)
{
    if (PointInRect(start->y, start->x, bounds) &&
        PointInRect(end->y, end->x, bounds)) {
        return true;
    }

    const int deltaY = end->y - start->y;
    const int deltaX = end->x - start->x;
    float enter = 0.0f;
    float leave = 1.0f;

    if (!ClipLineParameter(deltaX, bounds->left - start->x, &enter, &leave) ||
        !ClipLineParameter(-deltaX, start->x - bounds->right + 1, &enter, &leave) ||
        !ClipLineParameter(deltaY, bounds->top - start->y, &enter, &leave) ||
        !ClipLineParameter(-deltaY, start->y - bounds->bottom + 1, &enter, &leave)) {
        return false;
    }

    if (leave < 1.0f) {
        end->x = start->x + static_cast<short>(static_cast<int>(static_cast<float>(deltaX) * leave));
        end->y = start->y + static_cast<short>(static_cast<int>(static_cast<float>(deltaY) * leave));
    }

    if (enter > 0.0f) {
        start->x += static_cast<short>(static_cast<int>(static_cast<float>(deltaX) * enter));
        start->y += static_cast<short>(static_cast<int>(static_cast<float>(deltaY) * enter));
    }

    return true;
}

static bool ClipLineParameter(int delta, int edgeDistance, float *enter, float *leave)
{
    if (delta > 0) {
        const float t = static_cast<float>(edgeDistance) / static_cast<float>(delta);
        if (t > *leave) {
            return false;
        }
        if (t > *enter) {
            *enter = t;
        }
        return true;
    }

    if (delta < 0) {
        const float t = static_cast<float>(edgeDistance) / static_cast<float>(delta);
        if (*enter > t) {
            return false;
        }
        if (*leave > t) {
            *leave = t;
        }
        return true;
    }

    return edgeDistance <= 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves behavior: it implements the same half-open rectangle tests, enter/leave clipping, rejection cases, endpoint update order, and signed 16-bit truncating delta writes visible in MCP decompile/disasm.

Reason it matches plausible original mid-2000s source: it uses file-local static helpers and a small POD endpoint record, avoids IDA labels and decompiler temporaries, and keeps the helper private to the render source unit.

Reason not higher than current score: exact original helper/type spellings and source-file split are inferred rather than symbol-proven.

## Recommended Target Doc Changes

Target path: `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md`

Recommended target changes: none. Current target already contains the accepted B002 evidence and source C++ at same-or-greater detail than this B003 recheck needs to preserve.

If the supervisor wants a B003 audit breadcrumb, add it only as a short change-log note after implementation callback. That is optional; the target does not need duplicate MCP facts to be correct.

## Recommended Support Doc Changes

### `by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md`

The body and metadata are current, but the header `Item Summary` is stale. It still describes the 2026-06-07 A010 state (`78/86`, blank parent route) even though the page metadata/status/changes now show assigned `87/89`.

Recommended exact replacement for the `Item Summary` value:

```text
RGB565 slot dword_69B3E4 line callback; live IDA refreshes confirm exact bounds, callback-table xrefs, no direct callers, LineClipHelpers callee, RGB565 blend-helper dependencies, compat peer, and source-C++ blockers for typedef/receiver fields.
```

No score, owner, emitter, reconstructable, or C++ changes are recommended for [UID:0002PJ].

### `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`

The body has useful boundary/no-entry proof, but the header `Item Summary` is blank. Because [UID:0003XF] is the support page that closes the [UID:00016H] `0x004bb5b0` boundary issue, fill the summary.

Recommended exact replacement for the `Item Summary` value:

```text
Separate no-entry two-color six-byte pattern-pack raw island between LineClipHelpers and GrafPortDrawGlyph; exact padding envelopes, zero xrefs/entry-route scans, inline pattern match in GrafPort text helpers, and blank formal C++ until liveness is proven.
```

No score, owner, emitter, reconstructable, or C++ changes are recommended for [UID:0003XF].

### Other Support Docs

No edits are recommended for `Surface.md`, `RectBounds.md`, `RectGeometryHelpers.md`, `RectBoundsLayout.md`, `SurfaceRenderCallbackTable.md`, [UID:0002PG], or [UID:00016I]. Those docs already contain same-or-greater detail for the [UID:00016H] decision or have independent non-target C++ blockers.

## Score And Metadata Recommendation

- Stale assignment baseline: `COMPLETION:86`, `CONFIDENCE:89`, owner/emitter [UID:0000OC], blank formal C++.
- Actual current before B003 report: `COMPLETION:90`, `CONFIDENCE:91`, owner/emitter [UID:0000OC], formal C++ populated.
- Recommended after B003 report: unchanged `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`, current formal C++ retained.
- Score rationale: current target has enough evidence and source C++ to remain above the code-entry gate. It should not rise to `95+` or final-audit range because helper names and exact original source-unit split remain inferred, and the immediately related callback typedef/receiver fields are still not final-source quality on the caller pages.
- Score-improvement attempt: the assignment's blockers were checked directly. Helper names are resolved to source-facing inferred names; point/rect structure is constrained by [UID:00015S]/[UID:0001VP]; source placement remains [UID:0000OC] after checking caller/callback route; [UID:00015S] dependency constrains type/order but does not own the target; first-draft C++ is already safe and present; the `0x004bb5b0` island is proven separate.

## Open Questions With Attempted Resolution

- Original exact helper/type names: unresolved as original symbols, but resolved for source reconstruction as `LineClipPoint`, `ClipLineToRect`, and `ClipLineParameter`. Evidence checked: MCP decompile/disasm, support docs, generated pollution, caller route, and current target. Score impact: caps confidence at `91`; no C++ block.
- Exact original source-unit split: unresolved as original file proof, but current `Surface.cpp` route is the best supported direct emitter. Evidence checked: Surface docs, callback table, line callback pages, proposed source tree, xrefs. Score impact: caps final-audit score; no owner/emitter change.
- [UID:0003XF] liveness: unresolved for that support page, but not a [UID:00016H] blocker. Evidence checked: MCP `xrefs_to 0x004bb5b0` zero xrefs and existing support page route scans. Score/C++ impact: [UID:0003XF] remains no-owner/non-emitting/blank C++; [UID:00016H] remains separate.
- [UID:0002PJ] callback C++: unresolved, but outside target C++ scope. Evidence checked: line callback page still documents callback typedef/receiver blockers. Score/C++ impact: no change to [UID:00016H].

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` or validator-owned generated-report row text is supplied. The only recommended generated-coverage-affecting edits are source-page `Item Summary` values for [UID:0002PJ] and [UID:0003XF], to be handled through normal by-memory page edits and scoped validator refresh if the supervisor sends an implementation callback.

## Follow-Up Actions

- Supervisor: validate this report as a stale-assignment/current-state recheck. Decide whether to send B003 a narrow implementation callback for the two support `Item Summary` cleanups, or mark the report as superseded/no-target-change because B002 already executed [UID:00016H].
- B003 implementation callback, if sent: edit only the two listed support `Item Summary` fields, run scoped validators for those two by-memory files, update this checklist with proof, and do not touch generated reports or coverage reports.
- No A-agent action is required for [UID:00016H].

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for keeping current `90/91`, conservative against raising above it.
- Remaining uncertainty: original symbol names and exact original render source split are unavailable; they are already documented as score caps.

## Validator Results

- Commands run from `source-3/project-documentation` during the accepted implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md --apply --queue-timeout 240`
    - Exit code: `0`
    - `command_id: 000000003578`
    - `command_timestamp: 2026-06-26T22:38:11-04:00`
    - `ok: 1`
    - Warnings: none reported.
    - Validator side effects reported: `insert_header_blank: 1`, `autogen_registry_update: 2`, `canonical_owner_update: 1`, `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_incremental_noop: 1`.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000003578`, `generated_refresh_timestamp: 2026-06-26T22:38:11-04:00`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md --apply --queue-timeout 240`
    - Exit code: `0`
    - `command_id: 000000003580`
    - `command_timestamp: 2026-06-26T22:38:21-04:00`
    - `ok: 1`
    - Warnings/diagnostics: `missing_ref_uid 0003XD` reported twice; scoped validator still returned exit code `0` and `ok: 1`.
    - Validator side effects reported: `insert_header_blank: 1`, `path_update: 1`, `autogen_registry_update: 5`, `canonical_owner_update: 1`, `completion_update: 1`, `confidence_update: 1`, `reference_index_add: 10`, `projected_stats_update: 1`, `stats_incremental_noop: 1`.
    - Generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000003580`, `generated_refresh_timestamp: 2026-06-26T22:38:21-04:00`.
- Results: both scoped validators passed. The accepted `Item Summary` text is present in both support files after validation. Metadata, owner/emitter, reconstructable state, and formal C++ values for [UID:0002PJ] and [UID:0003XF] remain unchanged from their pre-callback current values.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/00016H-LineClipHelpers-source-quality.md`
- Modified by-* docs during implementation callback:
  - `by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md`: accepted `Item Summary` value only, plus validator-reported header blank normalization.
  - `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`: accepted `Item Summary` value only, plus validator-reported header blank normalization.
- Modified report/checklist: `tools/leaser/Agents/Agent-B003/research/00016H-LineClipHelpers-source-quality.md` updated with callback proof.
- Renamed: none.
- Leases used: B003 leased the two support by-memory files immediately before the summary edits and validator batch. `python .\tools\leaser\leaser.py B003 unlease ...` returned `Success` for both paths after validation, and `tools/leaser/Agents/current_leases.md` recheck showed no active B003 rows.
- Report execution: leave blank during the B-agent pass. The supervisor runs `tools/validator.py execute_report ... --apply` only after verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Supervisor accepted the report as a stale-assignment/current-state recheck with a narrow support-summary cleanup callback.
- [x] Target doc to verify already present: `by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md` remained untouched by B003 during this callback because executed B002 work already covers [UID:00016H] and the callback accepted no [UID:00016H] edit.
- [x] Support doc cleanup accepted/applied: updated only the `Item Summary` value in `by-memory/0x004c0850-0x004c0f7a.SoftwareRenderRgb565LineCallback.md` to the exact accepted text; no score, metadata, owner/emitter, reconstructable, or formal C++ value was manually changed.
- [x] Support doc cleanup accepted/applied: updated only the blank `Item Summary` value in `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md` to the exact accepted text; no score, metadata, owner/emitter, reconstructable, or formal C++ value was manually changed.
- [x] Current target state and actual evidence checked to preserve: B003 MCP session `80de0a67`, JSON-RPC ids `1-3`, `10-13`, `20`, `24-26`, `30-33`; target/support docs and generated reports remain recorded in `Evidence Checked`.
- [x] Metadata/score changes to apply: none for [UID:00016H], [UID:0002PJ], or [UID:0003XF]; callback validation confirmed protected header values remained unchanged from pre-callback current state.
- [x] Score-limiting blockers researched: helper names, point/rect structure, Surface source placement, [UID:00015S] dependency, formal C++ readiness, and `0x004bb5b0` separation all checked in the report; remaining uncertainties are final-audit caps only.
- [x] Owner/emitter/reconstructable changes to apply: none accepted and none manually applied.
- [x] Split/rename/new-child changes to apply: none accepted and none applied.
- [x] Source-placement/range/padding/reclassification changes to apply: none for target; callback synchronized only the two support summaries.
- [x] First-draft C++ to apply: none; [UID:00016H] target block was not edited and support formal C++ values stayed blank.
- [x] Historical/stale assumptions and negative evidence to preserve: stale `RankingEventListPane` generated ownership rejection, RectBounds-as-dependency not owner, GrafPort adjacency not owner, [UID:0003XF] zero-xref non-merge proof, and [UID:00016I] separate GrafPort caller route remain preserved in the report/body docs.
- [x] Wave2/Wave3/generated artifacts encountered and ignored/rejected: generated `RankingEventListPane` ownership and stale original not-covered queue context remain recorded as rejected/stale report evidence.
- [x] Open questions to close or document as evidence-backed unresolved: no open-question by-* edits were accepted in this callback; original symbol names, exact render source-unit split, and [UID:0002PJ] callback C++ blockers remain documented as unresolved final-audit/support blockers.
- [x] Validators run after support-summary edits: both scoped file validators listed in `Validator Results` ran with command id/timestamp/exit/ok count recorded.
- [x] Generated report refresh expected: both validators reported `generated_refresh: deferred`; generated output was not used for this callback, and no generated report or manual `-coverage-report.md` file was edited manually.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted only as stale-assignment/current-state recheck with narrow support-summary cleanup for [UID:0002PJ] and [UID:0003XF].
- [x] All accepted target/support doc details incorporated at report-level detail or verified already present: exact accepted `Item Summary` text is present in both support files after validation; [UID:00016H] remained unchanged as instructed.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: no such changes were accepted. [UID:0002PJ] remains `87/89`, owner/emitter [UID:0000OC], reconstructable true, blank formal C++; [UID:0003XF] remains `85/88`, owner `NONE`, no emitter, reconstructable true, blank formal C++.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: callback changed only the accepted support summary values and validator header blank normalization; report/body evidence and rejected alternatives were not removed.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: no new open-question edits were accepted; unresolved final-audit/source-C++ blockers remain documented.
- [x] Validators run and results recorded: [UID:0002PJ] validator `000000003578` at `2026-06-26T22:38:11-04:00`, exit `0`, `ok: 1`; [UID:0003XF] validator `000000003580` at `2026-06-26T22:38:21-04:00`, exit `0`, `ok: 1`.
- [x] Generated report refresh completed by validator or explicitly not required: both scoped validators reported `generated_refresh: deferred`; generated output was not relied on, and no generated/manual coverage files were edited.
- [x] Leases released: B003 unlease command returned `Success` for both support paths, and `tools/leaser/Agents/current_leases.md` recheck showed no active B003 lease rows.
- [x] Remaining unapplied accepted items listed with exact blocker: none; all accepted callback items were applied and validated.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00016H-LineClipHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/00016H-LineClipHelpers-source-quality.md","timestamp":"2026-06-26T22:45:32","uid":"00016H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
