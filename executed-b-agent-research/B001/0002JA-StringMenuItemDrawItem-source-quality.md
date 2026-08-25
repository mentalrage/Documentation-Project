** TARGET-REPORT-UID:0002JA **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002JA StringMenuItemDrawItem Source-Quality Research

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0002JA] `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md` as source-authored `void StringMenuItem::DrawItem(GrafPort *port)`, owned and emitted by [UID:0000E8] `StringMenuItem`, with source-file output through [UID:0000MN] `PopupMenuControls` at `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.

No split, owner move, no-owner disposition, non-reconstructable downgrade, wrapper/no-code disposition, or by-file direct-owner flattening is recommended. The current formal C++ block is source-quality first draft and should be preserved. Recommended metadata after supervisor callback is `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000E8`.

Current generated state is not empty. Read-only generated output refreshed by validator command `000000007524` at `2026-07-06T01:15:47-04:00` contains the `StringMenuItem::DrawItem(GrafPort *port)` body, and `auto-generated/-ag-memory-coverage.md` lists [UID:0002JA] as `coded` with owner/emitter `0000E8` and output file `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`. `Select-String` found `0` `Empty Emitter Marker` occurrences in the current generated file.

Historical B003 wording that described `PopupMenuControls.cpp` as length `0`, said current generated output was empty, or treated coverage `emits` rows as not proving code is present is stale as a current-state claim. It may remain only if explicitly labeled historical pre-B008/pre-current-generation context.

## Supporting Research

Workflow and assignment context read before acting:

- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`.
- `references/b-agent-research-and-implementation-workflow.md`.
- `references/b-agent-report-template.md`.
- `references/score-blocker-audit-standard.md`.
- `source-3/project-documentation/by-structure.md`.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`.
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/notes.md` (`No active notes.`).

Target and support docs checked:

- [UID:0002JA] `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`.
- [UID:0000E8] `by-class/StringMenuItem.md`.
- [UID:00007V] `by-class/MenuItem.md`.
- [UID:0000MN] `by-file/PopupMenuControls.md`.
- [UID:0001V5] `by-type/by-struct/MenuItemLayouts.md`.
- [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md`.
- Siblings [UID:0002J6], [UID:0002J7], [UID:0002J8], and [UID:0002J9].
- Current generated output `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- Current generated memory coverage and research tracker rows for `0002JA`.

Prior report search terms used: `0002JA`, `StringMenuItemDrawItem`, `StringMenuItem::DrawItem`, `0x005170f0`, `005170f0`, `0x0061ebc8`, `dword_69B3FC`, `PopupMenuControls.cpp`, `Empty Emitter`, and `generated`. Opened matching prior reports as leads: B003 popup-menu-controls source-quality, B004 separator draw source-quality, B008 PopupMenuControls empty-emitter family, and B013 StringMenuItem metric source-quality.

Live MCP was confirmed before binary-backed evidence. Session `7bfdc746` was active, `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and no analysis was running.

## Target

- UID: `0002JA`.
- Target path: `source-3/project-documentation/by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`.
- Range: `0x005170f0-0x005171a2`, size `0xb2` / 178 bytes.
- Current metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, blank emitter position.
- Current source role: virtual `StringMenuItem::DrawItem(GrafPort *port)` at `StringMenuItem` vtable slot `+0x14` / cell `0x0061ebc8`.
- Source root: `by-file/PopupMenuControls.md`, generated path `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.

## Current Target State

The target page already contains a formal C++ body:

```cpp
void StringMenuItem::DrawItem(GrafPort *port)
{
    port->m_textRunDirty = true;

    if (IsSelected()) {
        port->SetTextColor(0x80);
        g_surfaceRenderCallbacks.fillOrInvalidate(port, &m_bounds);
        port->SetBackgroundColor(0x8f);
    } else {
        port->SetBackgroundColor(0x80);
    }

    port->MoveTo(m_bounds.left + 12, m_bounds.bottom - 1);
    port->DrawWideText(m_text, static_cast<int>(wcslen(m_text)));
}
```

That body is still the recommended first-draft source. It matches the live decompiler behavior, the accepted `MenuItem`/`StringMenuItem` class declarations, the `MenuItemLayouts` offsets, and the generated output body. The only remaining source-quality caveats are exact original names for GrafPort helper methods, the draw-context byte at `port+0x88`, and the global callback/typedef around `0x0069b3fc`.

Current generated output state:

- Header: `validator-command-id: 000000007524`, `validator-refreshed-at: 2026-07-06T01:15:47-04:00`, `Source by-file UID: 0000MN`.
- The generated file contains [UID:0002JA] with `Completion:86 | Confidence:89` followed by the body above.
- `auto-generated/-ag-memory-coverage.md` row 1169 lists [UID:0002JA] as `coded`, owner `0000E8`, emitter `0000E8`, output file `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.
- `auto-generated/-ag-research-tracker.md` still lists [UID:0002JA] at `86/89`; that is a score/reporting state, not evidence of empty generation.

## Heuristic / Inference Reanalysis And Validation

`DrawItem(GrafPort *port)` remains the best source signature. Live decompilation shows one explicit stack argument, `a2`, used consistently as the draw context/port receiver for GrafPort helpers; the function returns by `retn 4` and the `MenuPane` caller ignores the virtual call return value at `0x005168f0`.

`StringMenuItem` remains the direct semantic owner. The function reads inherited `MenuItem` bounds at `this+0x04`, the selected/highlighted byte at `this+0x15`, and the `StringMenuItem` inline UTF-16 label at `this+0x18`. These offsets are already declared through the current `MenuItem` and `StringMenuItem` class pages.

The highlighted branch is source-visible menu-item rendering, not a separate Surface or GrafPort-owned helper. It tests `m_selected`, sets the text/draw state to `0x80`, invokes the shared surface callback over `&m_bounds`, switches background state to `0x8f`, and then draws the text. The normal branch sets background state to `0x80` and performs the same text positioning and drawing.

The method range is exact. `lookup_funcs(0x005170f0)` returns `sub_5170F0`, size `0xb2`; the preceding seven bytes at `0x005170e9-0x005170ef` and following fourteen bytes at `0x005171a2-0x005171af` are `0xcc`; the next function starts at `0x005171b0`.

The vtable route is current and unique. `get_bytes(0x0061ebb4, 24)` reads the `StringMenuItem` vtable cells ending with `0x0061ebc0 -> 0x00517090`, `0x0061ebc4 -> 0x005170d0`, and `0x0061ebc8 -> 0x005170f0`. `xrefs_to(0x005170f0)` returns only data xref `0x0061ebc8`; `find_bytes "f0 70 51 00"` finds only `0x0061ebc8`.

The old generated-empty inference is invalid for current state. B003's statements that `PopupMenuControls.cpp` was length `0` and that current generated output was empty were true for its historical pre-callback context only. B008 and later validator refreshes superseded that state; current generated output is coded and non-empty.

## Evidence Standards Used

- Current live MCP/IDA evidence was required for binary-backed claims in this report.
- Existing by-* docs and executed reports were used as leads and support, not as substitutes for live target checks.
- Generated files and generated coverage were read-only evidence. No generated output, coverage report, validator state, supervisor ledger, or by-* documentation was edited.
- Source-quality names are accepted only when binary behavior, class layout, vtable dispatch, and support docs agree. Exact original spelling remains capped where only role evidence is available.
- Historical report claims are rejected as current facts when contradicted by current generated output.

## Evidence Checked

MCP calls against session `7bfdc746`:

- `server_health`: `ok`, auto-analysis ready, Hex-Rays ready, strings ready.
- `lookup_funcs`: `0x005170f0 -> sub_5170F0 size 0xb2`; `0x005170e9` not a function; `0x005171a2` not a function; `0x005171b0 -> sub_5171B0 size 0x6d`; `0x005168ef` belongs to `sub_516790`.
- `get_bytes`: target body, pre-padding, post-padding, and `StringMenuItem` vtable run.
- `disasm 0x005170f0`: 72 instructions, selected/normal branch, shared text draw tail, `retn 4`.
- `decompile 0x005170f0`: writes `a2+136 = 1`, tests `this+21`, calls `sub_4B9660`, `unk_69B3FC`, `sub_4B9680`, `sub_4B9600`, and `sub_4BAB70`.
- `callees 0x005170f0`: `0x004b9660`, `0x0069b3fc`, `0x004b9680`, `0x004b9600`, `0x004bab70`.
- `xrefs_to` / `xref_query`: only xref to `0x005170f0` is data from `0x0061ebc8`; no xrefs to the vtable-cell address itself.
- `find_bytes`: little-endian target VA `f0 70 51 00` found only at `0x0061ebc8`; little-endian vslot address `c8 eb 61 00` not found.
- `decompile 0x00516790`: `MenuPane` draw loop calls `(*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 20))(v5, this)` at `0x005168f0`, proving generic `DrawItem` virtual dispatch through slot `+0x14`.

Read-only generated state:

- `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` header command `000000007524`.
- The current generated file contains the [UID:0002JA] formal body and has no `Empty Emitter Marker` occurrences.
- `auto-generated/-ag-memory-coverage.md` row marks [UID:0002JA] `coded`.

Prior reports checked as leads:

- B003 popup-menu-controls source-quality report supplied the original `StringMenuItem::DrawItem` recommendation and also contains historical generated-empty wording that is now stale as current-state text.
- B004 separator draw report confirms the sibling `SeparatorMenuItem` slot `+0x14` is also source-facing `DrawItem(GrafPort *port)` and that the `MenuPane` caller ignores the virtual return.
- B008 empty-emitter implementation confirms `PopupMenuControls.cpp` became the current source root and the former empty markers were repaired through class declarations, support types, and no-code markers.
- B013 metric report confirms `StringMenuItem::GetItemSize` and the `left+12` / total-width-padding relation used by this draw method.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Live MCP session `7bfdc746` is healthy and current enough for binary-backed evidence. | High | `server_health` returned `ok`, auto-analysis ready, Hex-Rays ready, strings ready. | [UID:0002JA] Status / IDA Evidence. | incorporate | applied: target Status now names session `7bfdc746`; IDA Evidence names the B001 live MCP checks. |
| C02 | [UID:0002JA] is exact range `0x005170f0-0x005171a2`, size `0xb2`, bounded by padding and successor `0x005171b0`. | High | `lookup_funcs` and `get_bytes` for target, pre-pad, post-pad, and successor. | [UID:0002JA] Item Summary / IDA Evidence / Score Rationale. | incorporate | applied: target metadata remains same range and Item Summary/Score Rationale now record exact `0xb2` body and range. |
| C03 | [UID:0002JA] is `StringMenuItem` vtable slot `+0x14`, cell `0x0061ebc8`, with no direct code callers. | High | `xrefs_to(0x005170f0)` only data xref `0x0061ebc8`; `find_bytes` only target-pointer hit at `0x0061ebc8`; `MenuPane` dispatches slot `+0x14`. | [UID:0002JA] Item Summary / IDA Evidence / Status. | incorporate | applied: target records unique pointer at `0x0061ebc8`, `MenuPane` dispatch through slot `+0x14`, and no direct-caller route. |
| C04 | The current first-draft C++ body accurately models behavior. | High | Live decompile/disasm matches generated and target formal body. | [UID:0002JA] `RECONSTRUCTION_CPP CODE` block. | already-present | already-present: formal `StringMenuItem::DrawItem(GrafPort *port)` block was preserved unchanged and validated. |
| C05 | Current generated output is coded and non-empty. | High | Generated header command `000000007524`; [UID:0002JA] body present; memory coverage row `coded`; empty marker count `0`. | [UID:0002JA] Item Summary / Status / Current Generated Output State. | incorporate | applied: target records report evidence command `000000007524`, coded generated output, and callback validator preservation; final generated header refreshed to `000000007532`. |
| C06 | B003's generated-empty statements are historical only. | High | B003 lines describe `PopupMenuControls.cpp` length `0`; current generated output contradicts that. | [UID:0002JA] Item Summary / Current Generated Output State. | reject-stale | applied: target states stale pre-callback empty-output wording is historical only and rejects older empty-output/current-empty claims as current evidence. |
| C07 | Helper/global names remain descriptive rather than proven original spellings. | Medium-high | Binary names still `sub_4B9660`, `sub_4B9680`, `sub_4B9600`, `sub_4BAB70`, and `unk_69B3FC`; support docs give role names. | [UID:0002JA] Item Summary / Status / Score Rationale. | incorporate | applied: target preserves caveats for exact original GrafPort helper names, draw-context dirty-byte name, and callback typedef/name. |
| C08 | Score can rise from `86/89` to `88/91`. | Medium-high | Current live MCP reconfirms behavior/range/vtable/caller route and current generated output is coded. | [UID:0002JA] metadata and Score Rationale. | incorporate | applied: target metadata is now `COMPLETION:88` and `CONFIDENCE:91`; final scoped validator `000000007532` returned `ok:1`. |
| C09 | No by-* support doc has to change before source output is valid. | High | `MenuItem`, `StringMenuItem`, `MenuItemLayouts`, and `MenuItemVtables` already contain the needed declarations/offsets/slot map. | Support docs unchanged. | not-applicable | not-applicable: support docs were left unchanged because they already contain same-or-greater-detail `StringMenuItem::DrawItem`, `m_selected`, `m_bounds`, `m_text[0x80]`, and vtable slot `+0x14` facts; no direct stale contradiction was found. |

## Positive Evidence Summary

- Exact live IDA function boundary: `sub_5170F0`, size `0xb2`.
- Exact vtable identity: `StringMenuItem` cell `0x0061ebc8 -> 0x005170f0`.
- Unique pointer hit for target VA: `find_bytes "f0 70 51 00"` finds only `0x0061ebc8`.
- Behavior matches the current source block: selected branch fills/invalidates item bounds, normal branch skips the callback, both branches move to `m_bounds.left + 12` / `m_bounds.bottom - 1` and draw `m_text`.
- Class layout support is already present: `MenuItem::m_bounds`, `MenuItem::m_selected`, `StringMenuItem::m_text[0x80]`, and virtual `DrawItem(GrafPort *port)`.
- `MenuPane` current live decompile dispatches slot `+0x14` through the item vtable and ignores return, supporting `void DrawItem(GrafPort *port)`.
- Current generated output emits the body and current memory coverage marks it `coded`.

## Negative Evidence Summary

- No direct code callers to `0x005170f0`; reachability is vtable dispatch, not dead code.
- No pointer hits for `0x005170f0` outside the vtable cell.
- No xrefs to the vtable-cell address `0x0061ebc8`, which is normal for table data and not a reason to move ownership.
- No evidence that the source method belongs to GrafPort, SurfaceRenderCallbackTable, a dialog feature file, or a raw helper/no-owner bucket.
- No current generated empty-emitter evidence remains for this UID.
- No proof of exact original names for `port+0x88`, `0x004b9660`, `0x004b9680`, `0x004b9600`, `0x004bab70`, or `0x0069b3fc`; keep descriptive names and caveats.

## Ranked Ownership Analysis

1. [UID:0000E8] `StringMenuItem` is the correct direct owner. The function reads string-item text at `+0x18`, inherited menu-item state/bounds, and occupies the `StringMenuItem` vtable slot `+0x14`.
2. [UID:0000MN] `PopupMenuControls` is the correct source-file root, not the direct method owner. It owns the current generated `NexusTK/ui/menu/PopupMenuControls.cpp` family and receives the class child output.
3. [UID:00007V] `MenuItem` is support/base context only. The generic virtual is declared there, but this concrete implementation is `StringMenuItem`.
4. [UID:0000AO]/[UID:0000TL] `GrafPort` and [UID:0000TN] `SurfaceRenderCallbackTable` are dependencies only. Their helpers/callbacks are called by the method; they do not own the menu-item behavior.
5. Feature/dialog callers are consumers only. The reusable menu item draw method is reached through the menu-pane virtual draw route.
6. No-owner, raw-helper, vtable-data, compiler-generated-wrapper, and non-reconstructable alternatives are rejected because the method is source-authored behavior with a valid class owner/emitter route and formal C++.

## Source Placement

Keep source placement under [UID:0000MN] `PopupMenuControls`, generated at:

```text
auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp
```

The current consolidated source root remains appropriate. A future original-source review may split `MenuPane.cpp`, `MenuItem.cpp`, or `PopupMenuControlPane.cpp`, but no current evidence requires moving [UID:0002JA] away from the `PopupMenuControls.cpp` output route. If a later split is accepted, `StringMenuItem::DrawItem` should move with the `StringMenuItem` class implementation, not to GrafPort, Surface, or a caller-specific dialog file.

## First-Draft C++ Recommendation

Preserve the existing target formal C++:

```cpp
void StringMenuItem::DrawItem(GrafPort *port)
{
    port->m_textRunDirty = true;

    if (IsSelected()) {
        port->SetTextColor(0x80);
        g_surfaceRenderCallbacks.fillOrInvalidate(port, &m_bounds);
        port->SetBackgroundColor(0x8f);
    } else {
        port->SetBackgroundColor(0x80);
    }

    port->MoveTo(m_bounds.left + 12, m_bounds.bottom - 1);
    port->DrawWideText(m_text, static_cast<int>(wcslen(m_text)));
}
```

Do not lower this into raw pointer arithmetic in final docs unless a validator requires temporary diagnostics. Do not emit raw vtable data, a generated `sub_5170F0` wrapper, or a standalone callback-owned helper.

## Final Recommendation

Supervisor callback should update the report/evidence state for [UID:0002JA], not rework the source route. Recommended final state:

- `COMPLETION:88`.
- `CONFIDENCE:91`.
- `CANONICAL_OWNER:0000E8`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000E8`.
- Keep emitter position blank.
- Keep the existing formal C++ body.
- Add current MCP session `7bfdc746` and generated command `000000007524` evidence.
- Explicitly mark old generated-empty wording as historical if any such wording is copied forward.

## Recommended Target Doc Changes

If supervisor executes this report, update [UID:0002JA] as follows:

1. Change score metadata from `86/89` to `88/91`.
2. Add a current 2026-07-06 evidence note recording MCP session `7bfdc746`, target size `0xb2`, unique vtable pointer at `0x0061ebc8`, `MenuPane` slot `+0x14` dispatch, and generated header command `000000007524`.
3. Update the Item Summary to clarify current generated output is coded, not an empty marker.
4. Keep the existing `StringMenuItem::DrawItem(GrafPort *port)` formal C++ block.
5. Preserve caveats for exact original GrafPort helper names, `port+0x88`, and `g_surfaceRenderCallbacks.fillOrInvalidate` naming.

Suggested Item Summary replacement:

```text
2026-07-06 B001 live MCP session 7bfdc746 reconfirms exact 0xb2 vtable draw method at 0x005170f0-0x005171a2, unique target pointer at StringMenuItem vtable slot 0x0061ebc8, MenuPane virtual dispatch through slot +0x14, selected/normal branch split on MenuItem +0x15, draw-context byte +0x88 write, bounds-based cursor at left+12/bottom-1, inline StringMenuItem +0x18 UTF-16 label scan, shared GrafPort draw-state/text helpers, and selected-branch dword_69B3FC render callback. Current generated output is coded in auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp under validator command 000000007524; stale pre-callback empty-generated-output wording is historical only. Remaining caveats are exact original GrafPort helper names, draw-context dirty-byte name, and callback typedef/name.
```

## Recommended Support Doc Changes

No support-doc structural change is required for source output. Optional evidence notes if the supervisor wants full propagation:

- `by-class/StringMenuItem.md`: add a short B001 note that current live MCP reconfirms [UID:0002JA] and current generated output is coded.
- `by-type/by-vtable/MenuItemVtables.md`: no slot change; optional note that 2026-07-06 MCP again finds `0x0061ebc8 -> 0x005170f0`.
- `by-file/PopupMenuControls.md`: no metadata change; optional note that [UID:0002JA] is current coded output in `PopupMenuControls.cpp` and not an empty marker.
- `by-type/by-struct/MenuItemLayouts.md`: no change needed; existing `m_selected`, bounds, and `m_text[0x80]` evidence is sufficient.

Do not edit generated files, generated coverage, manual coverage reports, validator state, supervisor ledgers, or executed archives by hand.

## Score And Metadata Recommendation

Recommended target score: `COMPLETION:88`, `CONFIDENCE:91`.

Completion can rise because current live MCP revalidated function boundary, behavior, vtable route, caller route, and generated coded output. It should stay below `90` because exact source spellings for several GrafPort/helper/global names are descriptive rather than original-name proven.

Confidence can rise because the binary facts are direct and current, the class/support docs already agree, and generated output proves the route is active. It should stay below final-audit range because callback typedef/name, dirty byte name, and final original method/helper spelling remain inferred.

Metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000E8
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000E8
EMITTER_POSITION_OPTIONAL:
```

## Open Questions With Attempted Resolution

- Exact original name for `port+0x88`: attempted resolution through live decompile and target/support docs. Role is resolved as a draw/text-run dirty byte written before drawing; spelling remains inferred.
- Exact original names for GrafPort helpers `0x004b9660`, `0x004b9680`, `0x004b9600`, and `0x004bab70`: attempted resolution through B004/GrafPort support docs and current callees. Roles are resolved as draw/text state, move-to, and wide text draw helpers; exact names remain descriptive.
- Exact original callback/global name for `0x0069b3fc`: attempted resolution through B004 SurfaceRenderCallbackTable context. Role is rect fill/invalidate/presentation callback taking `GrafPort *` and bounds; original typedef/name remains unproven.
- Whether the original source split used one consolidated `PopupMenuControls.cpp`: attempted resolution through B008, current generated output, and by-file notes. Current route remains consolidated; possible future split is not a blocker.

None of these questions blocks first-draft C++ or the recommended `88/91` score.

## Validator Results

Scoped validators were run from `source-3/project-documentation` only for the changed by-memory target. No support docs were edited, so no support validators were run. No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, or coverage-report edit was run.

| Command | command_id | command_timestamp | Exit | ok | Warnings / notes | Generated freshness |
| --- | --- | --- | ---: | ---: | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x005170f0-0x005171a2.StringMenuItemDrawItem.md --apply --queue-timeout 240` | `000000007530` | `2026-07-06T04:51:00-04:00` | 0 | 1 | Updated `COMPLETION:88` and `CONFIDENCE:91`; projected stats updated; no target warnings. | `generated_refresh: deferred`; generated output later refreshed, then superseded by follow-up target wording validator runs. |
| same command | `000000007531` | `2026-07-06T04:52:47-04:00` | 0 | 1 | Revalidated generated-freshness wording repair; projected stats updated; no target warnings. | `generated_refresh: deferred`; generated output later refreshed, then superseded by final validator run. |
| same command | `000000007532` | `2026-07-06T04:54:04-04:00` | 0 | 1 | Final target validation; projected stats updated; no target warnings. | `generated_refresh: deferred`; read-only header check shows `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` at `validator-command-id: 000000007532`, `validator-refreshed-at: 2026-07-06T04:54:04-04:00`, `validator-refresh-source: deferred-generated-refresh`. |

Validator-owned side effects observed: `project-level/-auto-completion-stats.md` projected path completion section was updated, and `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` refreshed to command `000000007532`. These were validator-generated side effects; no generated file, project-level file, validator state, supervisor ledger, or coverage report was edited by hand.

## Changed Files

- Created: none.
- Modified manually: `source-3/project-documentation/by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`.
- Modified manually: `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002JA-StringMenuItemDrawItem-source-quality.md`.
- Validator-generated side effects: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` refreshed to command `000000007532`; `project-level/-auto-completion-stats.md` projected path completion section updated.
- No support docs, generated files, coverage reports, validator state, supervisor ledgers, executed archives, or lifecycle files were edited by hand.

## Implementation Tracking Checklist

Report-only research:

- [x] Loaded project-level B-agent workflow skill and B001 goal.
- [x] Read target, support docs, generated output, generated coverage, and relevant prior reports.
- [x] Confirmed live MCP session before binary-backed evidence.
- [x] Checked function boundary, bytes, disassembly, decompile, callees, xrefs, pointer hits, vtable route, and virtual dispatch caller.
- [x] Checked current generated output and rejected old empty-output wording as stale current-state evidence.
- [x] Wrote report-only recommendation with exact first-draft C++ disposition and score/metadata recommendation.
- [x] Did not edit by-* docs, generated files, coverage reports, validator state, supervisor ledgers, or executed archives.
- [x] Did not run validators, lifecycle, execute, archive, lease, or generated-refresh commands.

Implementation callback checklist:

- [x] Update [UID:0002JA] score to `88/91`. Proof: target metadata now reads `COMPLETION:88`, `CONFIDENCE:91`; validator `000000007532` returned `ok:1`.
- [x] Keep `CANONICAL_OWNER:0000E8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000E8`, and blank emitter position unchanged. Proof: target header preserves those fields.
- [x] Preserve existing formal `StringMenuItem::DrawItem(GrafPort *port)` C++ block. Proof: target formal block still contains the same source-shaped body, not pointer/decompiler style.
- [x] Add current MCP/generated-state evidence to [UID:0002JA]. Proof: target Item Summary, Status, IDA Evidence, Current Generated Output State, Score Rationale, and Changes record session `7bfdc746`, exact `0x005170f0-0x005171a2` / `0xb2` body, unique `0x0061ebc8` pointer, `MenuPane` `+0x14` dispatch, branch behavior, `+0x88`, `left+12` / `bottom-1`, `StringMenuItem +0x18`, GrafPort helpers, `dword_69B3FC`, generated command `000000007524`, and validator-preserved coded output.
- [x] Historicalize or reject stale pre-callback generated-empty wording wherever it would otherwise be restated as current truth. Proof: target Item Summary and Current Generated Output State explicitly mark old empty-output wording historical only.
- [x] Preserve remaining caveats for exact original GrafPort helper names, draw-context dirty-byte name, and callback typedef/name. Proof: target Item Summary, Status, and Score Rationale retain those caveats.
- [x] Leave support docs unchanged unless direct stale contradiction is found. Proof: `StringMenuItem.md`, `MenuItemVtables.md`, and `PopupMenuControls.md` already contain same-or-greater-detail support facts; no direct stale contradiction requiring a support edit was found; ledger C09 records this disposition.
- [x] Run scoped validators for every changed by-* doc. Proof: target validator runs `000000007530`, `000000007531`, and final `000000007532` all exited `0`, `ok:1`; no support validators were needed because no support docs were edited.
- [x] Release leases immediately after edit/validator batch. Proof: B001 leased `by-memory\0x005170f0-0x005171a2.StringMenuItemDrawItem.md` for each target edit/validator batch and released it after validation; read-only lease check found no active B001 lease.

Unchecked blockers: none. All accepted implementation items are applied, already present, or not applicable as recorded in the ledger.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000007540","destination_path":"executed-b-agent-research/B001/0002JA-StringMenuItemDrawItem-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002JA-StringMenuItemDrawItem-source-quality.md","timestamp":"2026-07-06T04:58:28-04:00","uid":"0002JA"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
