** TARGET-REPORT-UID:0002T3 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002T3] IconsPaneHitTestIcon Source-Quality Report

Agent: Agent-B012  
Assignment: B012-report-0002T3-icons-pane-hit-test-icon-20260625  
Target: [by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md](../../../../../by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md)  
Mode: report-only; no by-* edits and no leases taken  
Date: 2026-06-25

## Executive Finding

[UID:0002T3] is ready for a first-draft formal reconstruction in the exact target page after supervisor validation.

The previous blank-code blockers are now resolved by current project evidence:

- The shared rectangle helper is already named and documented by RectBounds support pages as `PointInRect`.
- The coordinate convention is documented as vertical-first, horizontal-second, matching the live caller flow.
- The target range is a single live IDA function with four direct caller sites from `IconsPane::OnMouseEvent`.
- The slot geometry, full/reduced start index, miss sentinel, and helper call order are exact.

Recommended target result:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | raise from `86` to `90` |
| `CONFIDENCE` | raise from `90` to `92` |
| `CANONICAL_OWNER` | keep `00006B` (`IconsPane`) |
| `EMITTER_UIDS` | keep `00006B` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `RECONSTRUCTION_CPP CODE` | populate with the formal block in this report |

Do not raise higher yet because exact original parameter names and the historical source spelling of the inline rectangle construction remain source-facing reconstructions, not recovered symbols. The nearby `OnMouseEvent` method and raw action-dispatch/gap pages also still carry wider event/action naming caveats, but those do not block this helper's first-draft C++.

## MCP Evidence Provenance

IDA MCP was mandatory and was used successfully. No fallback-only report was produced.

| Check | Result |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Server | `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18` |
| Active database | session `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Input path reported by MCP | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Worker PID | `26892` |
| Health | `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready |

Primary MCP calls used:

- `idb_list` and `server_health` for current MCP availability and database provenance.
- `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, and `make_signature_for_range` for `0x004cf7d0-0x004cf862`.
- `analyze_function`, `decompile`, and `disasm` for shared helper `0x004b7e80`.
- `decompile` and `disasm` for caller `0x004cf3e0`.
- `decompile` and `disasm` for adjacent no-route helper bytes at `0x004cf7a0`.

Two byte-read attempts used an outdated `get_bytes` schema and one local PowerShell request wrapper initially malformed the `arguments` field. Those were request-construction issues only; MCP remained responsive and the evidence was recollected through corrected calls.

## Current Target State

The target currently has correct ownership and behavior notes but keeps the formal C++ blank.

Current target metadata:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `86` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `00006B` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `00006B` |
| Formal C++ | blank |

The target's stale source-shape note says the two coordinate parameters are pending final event-struct naming and currently describes them in horizontal-first terms. Current RectBounds and caller evidence supersede that: the first coordinate is the vertical component and the second coordinate is the horizontal component.

## Exact Boundary And Reachability

Keep the exact range `0x004cf7d0-0x004cf862`.

Current MCP facts:

| Address | MCP result |
| --- | --- |
| `0x004cf7d0` | `sub_4CF7D0`, size `0x92` / 146 bytes |
| `0x004cf862` | no function; alignment/padding before next helper |
| `0x004cf870` | successor `sub_4CF870`, size `0x65` |
| `0x004cf3e0` | only ordinary caller function, `sub_4CF3E0`, size `0x36b` |
| `0x004b7e80` | shared `PointInRect` helper, size `0x27` |

`xrefs_to 0x004cf7d0` reports exactly four code xrefs, all inside `IconsPane::OnMouseEvent`:

| Caller address | Event path | Use |
| --- | --- | --- |
| `0x004cf44e` | mouse down | Stores hit result as the selected icon index before capture/highlight. |
| `0x004cf4a2` | hover/help | Chooses localized tooltip ids `202..209`; `-1` suppresses tooltip handling. |
| `0x004cf667` | captured move/drag | Re-hit-tests while captured and toggles highlight by comparing to the stored selected icon. |
| `0x004cf6b0` | mouse up | Re-hit-tests before action dispatch; dispatch requires the same selected icon and no input lock. |

No split, merge, or owner change is recommended. The adjacent `0x004cf7a0-0x004cf7c9` no-route rectangle builder remains part of the predecessor gap documented by `IconsPaneCore` and `IconsPaneOnMouseEvent`; it should not be merged into this target.

## Coordinate Order Resolution

Current evidence resolves the old coordinate-order blocker.

RectBounds support pages establish the project convention:

- [by-file/RectBounds.md](../../../../../by-file/RectBounds.md) names `0x004b7e80-0x004b7ea7` as `PointInRect` with arguments ordered `y, x, rect`.
- [by-class/RectBounds.md](../../../../../by-class/RectBounds.md) documents `ContainsPoint` with the same `y, x` stack order and explicitly rejects horizontal-first rewriting.
- [by-type/by-struct/RectBoundsLayout.md](../../../../../by-type/by-struct/RectBoundsLayout.md) confirms the fields are `left`, `top`, `right`, `bottom`, and says both class and free point tests preserve the current binary/source-facing `y, x` order.

Current MCP confirms the same order for this IconsPane family:

- `IconsPane::OnMouseEvent` reads the first coordinate from event dword `Block[2]` and the second from `Block[3]`.
- The same two values are passed in the same order to the pane-bounds `PointInRect` checks and to this target helper.
- `IconsPaneHitTestIcon` passes its first explicit parameter as the first `PointInRect` coordinate and its second explicit parameter as the second `PointInRect` coordinate.
- `PointInRect` compares its second coordinate against the rectangle left/right fields and its first coordinate against the top/bottom fields.

Therefore the target's first formal parameter should be the vertical coordinate and the second should be the horizontal coordinate. The existing target text that points toward horizontal-first source shape should be corrected during implementation.

## Behavior And Geometry

The function maps a mouse point to the visible icon index in the old IconsPane strip.

Exact behavior:

- Reads `this+0xf8`, documented by the IconsPane class as `m_showAllIcons`.
- Starts at icon index `0` when `m_showAllIcons` is nonzero.
- Starts at icon index `6` when `m_showAllIcons` is zero.
- Computes the slot x-position as `iconIndex * 20`.
- Builds a stack `RectBounds` with `left = x`, `top = 0`, `right = x + 19`, `bottom = 14`.
- Calls shared `PointInRect` with vertical-first coordinate order.
- Returns the current icon index on hit.
- Advances by `20` pixels and one icon index on miss.
- Stops when the next x-position reaches `160`.
- Returns signed `-1` if no visible slot contains the point.

Reduced mode therefore tests only icon indexes `6` and `7` at x-positions `120` and `140`. Full mode tests icon indexes `0` through `7` at x-positions `0` through `140`.

The rectangle bounds are intentionally recorded as the executable writes them: right edge `x + 19` and bottom edge `14`. Do not silently rewrite this to `x + 20` or `15` during reconstruction.

## Support Docs Read

The following support docs were read and used:

- [by-class/IconsPane.md](../../../../../by-class/IconsPane.md)
- [by-file/IconsPane.md](../../../../../by-file/IconsPane.md)
- [by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md](../../../../../by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md](../../../../../by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md)
- [by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md](../../../../../by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md)
- [by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md](../../../../../by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md)
- [by-file/RectBounds.md](../../../../../by-file/RectBounds.md)
- [by-class/RectBounds.md](../../../../../by-class/RectBounds.md)
- [by-type/by-struct/RectBoundsLayout.md](../../../../../by-type/by-struct/RectBoundsLayout.md)
- [by-resource/iconspane-icon-resources.md](../../../../../by-resource/iconspane-icon-resources.md)
- [auto-generated/NexusTK/ui/panels/IconsPane.cpp](../../../../../auto-generated/NexusTK/ui/panels/IconsPane.cpp), read only
- Executed reports B003 `00016Z-IconsPaneCore-source-quality.md` and B004 `0002T1-IconsPaneOnPaint-source-quality-report.md`, used as historical/support context only

The generated `IconsPane.cpp` is stale for this target: it still has an empty marker for [UID:0002T3] and stale child scores. Do not edit generated output by hand; let the validator/generated refresh pipeline update it after accepted by-* implementation.

## Formal RECONSTRUCTION_CPP CODE Insertion Text

Use this exact formal insertion text for the target if the supervisor approves implementation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int IconsPane::HitTestIcon(int y, int x)
{
    RectBounds iconRect;

    int iconIndex = m_showAllIcons ? 0 : 6;
    int iconX = iconIndex * 20;

    while (iconX < 160) {
        InitRectBounds(&iconRect, iconX, 0, iconX + 19, 14);

        if (PointInRect(y, x, &iconRect)) {
            return iconIndex;
        }

        iconX += 20;
        ++iconIndex;
    }

    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This block uses the project-supported `PointInRect` and `InitRectBounds` names. It does not call the adjacent no-route `0x004cf7a0` helper because the target executable body builds the same rectangle inline and has no call/xref to that raw helper start.

## Target Doc Update Details

Apply these edits only after supervisor validation and implementation callback:

- Update metadata to `COMPLETION:90`, `CONFIDENCE:92`.
- Preserve `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00006B`.
- Replace the stale horizontal-first signature wording with the vertical-first coordinate order proven by RectBounds and `OnMouseEvent`.
- Replace the blank-code blocker with the formal C++ block above.
- Update behavior text to name the shared helper as `PointInRect` and preserve the same vertical-first coordinate order shown in the formal block.
- Record current MCP session `80de0a67`, function size `0x92`, four caller xrefs, exact helper call order, and unique range signature.
- Keep the `0x004cf862-0x004cf870` successor padding and `0x004cf870` highlight-helper boundary unchanged.
- Keep the adjacent `0x004cf7a0-0x004cf7c9` raw rectangle-builder gap outside this target.

## Support Synchronization Details

Recommended support edits for a later implementation callback:

| File | Recommended sync |
| --- | --- |
| `by-class/IconsPane.md` | Mark [UID:0002T3] as first-draft C++ ready/present after target edit; correct any helper signature wording to vertical-first coordinate order; preserve wider `OnMouseEvent` and action-dispatch caveats. |
| `by-file/IconsPane.md` | Record that `HitTestIcon` now has formal C++ in the exact child; preserve file-level raw gap/action-dispatch caveats. |
| `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md` | Update the child table/status for [UID:0002T3]; keep aggregate C++ marker-only. |
| `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` | If touched, clarify that `Block[2]`/`Block[3]` flow into `PointInRect` and `HitTestIcon` as vertical-first/horizontal-second coordinates; do not attempt full `OnMouseEvent` C++ here. |
| `by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md` | No required update unless support wording is being synchronized for the selected/highlight field names. |
| RectBounds docs | No required update; they already carry the canonical `PointInRect` name and `y, x` convention. |
| Generated files and coverage reports | Do not edit by hand. |

Suggested support score direction after implementation:

- `by-class/IconsPane.md`: consider `88/90` if the target and support sync are accepted, but retain caveats for `OnMouseEvent`, action dispatch, and the `0x004cf74b-0x004cf7d0` gap.
- `by-file/IconsPane.md`: consider `89/88` if the target and support sync are accepted, with the same caveats retained.
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`: consider `87/89` after child status sync, keeping aggregate C++ marker-only.

## Ownership And Rejected Alternatives

Accepted ownership:

1. `by-class/IconsPane.md` / `IconsPane` is the semantic owner. The function reads `m_showAllIcons`, is called only by `IconsPane::OnMouseEvent`, and shares geometry/state with `OnPaint` and `SetIconHighlight`.
2. `by-file/IconsPane.md` is the source-file route for implementation.
3. `RectBounds` owns the shared `PointInRect` and `InitRectBounds` helpers, not this target.

Rejected alternatives:

| Alternative | Rejection reason |
| --- | --- |
| No-owner/raw helper | The target is an IDA function with four direct code xrefs from the IconsPane mouse method. |
| Merge with `OnMouseEvent` | The target has its own function entry, stack frame, return convention, unique signature, and four call sites. |
| Merge with adjacent `0x004cf7a0` raw helper | The adjacent start has no modeled function and is part of the documented predecessor gap; this target does not call it. |
| Horizontal-first C++ signature | Conflicts with RectBounds docs and current MCP caller/helper argument order. |
| Emit raw `sub_4CF7D0`/`sub_4B7E80` names | Current project source-facing docs already provide `IconsPane::HitTestIcon` and `PointInRect`. |

## Implementation Checklist

- [x] Supervisor validates/accepts this report before any by-* edit. Proof: implementation callback `B012-implement-0002T3-icons-pane-hit-test-icon-20260625` in `Agent-B012/goal.md` accepted this report and supplied the exact target/support edit checklist.
- [x] Lease only the accepted target/support by-* files immediately before implementation, then release immediately after scoped validation. Proof: B012 leased only the five edited by-* files at `2026-06-25T17:51:30Z` through `2026-06-25T17:56:30Z`; the target/class/file leases expired before release, then B012 renewed only `IconsPaneCore` and `IconsPaneOnMouseEvent` for the remaining validators. `leaser.py B012 unlease ...` reported `Success` for the renewed memory-page leases and `Rejected[No active lease]` for already-expired target/class/file leases; the final `current_leases.md` check reported `No active leases.`
- [x] Update [by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md](../../../../../by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) metadata to `90/92`, preserve owner/emitter, correct coordinate order, and add the formal C++ block above. Proof: target now has `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:00006B`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006B`, blank `EMITTER_POSITION_OPTIONAL`, and formal `int IconsPane::HitTestIcon(int y, int x)` C++ in the managed block.
- [x] Apply only accepted support sync edits; do not broaden into unrelated IconsPane refactors. Proof: edited only `by-class/IconsPane.md`, `by-file/IconsPane.md`, `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`, and `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` to record HitTestIcon first-draft status and vertical-first/horizontal-second coordinate order while preserving action-dispatch, raw-gap, and aggregate marker-only caveats.
- [x] Run scoped validators only for edited files. Proof:
  - `python .\tools\validator.py --mode file --file by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001534`; `command_timestamp: 2026-06-25T13:54:57-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-class/IconsPane.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001539`; `command_timestamp: 2026-06-25T13:55:26-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-file/IconsPane.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001544`; `command_timestamp: 2026-06-25T13:56:10-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001550`; `command_timestamp: 2026-06-25T13:57:02-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
  - `python .\tools\validator.py --mode file --file by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001553`; `command_timestamp: 2026-06-25T13:57:53-04:00`; exit code `0`; `ok: 1`; `generated_refresh: completed`.
- [x] Do not manually edit generated files, project-level generated reports, validator state/cache, the IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Proof: manual edits were limited to the five accepted by-* pages and this B012 report; no IDA MCP/DB edits were made and no coverage-report file was manually edited.
- [x] Confirm any validator-owned generated refresh side effects with supervisor policy before closeout. Proof: each validator used `--wait-generated` and reported `generated_refresh: completed` with matching generated refresh command ID/timestamp. Validator-owned side effects included generated metadata refresh, `auto-generated/-ag-coverage-report-by-memory.md` refresh, `project-level/-auto-completion-stats.md` projected-path section update, and `tools/validator_autogen_backup/20260625-*` backup creation. The target validator also reported one generated C++ update. All five runs also reported broad pre-existing diagnostics `autogen_registry_stale: 169` and `memory_coverage_metadata_missing_file: 167`; B012 did not hand-edit validator state or run cleanup lifecycle commands.

## Validation Scope For Implementation Callback

Suggested file-scoped validator set if all recommended support sync is accepted:

- `by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md`
- `by-class/IconsPane.md`
- `by-file/IconsPane.md`
- `by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md`
- `by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md` only if edited

Implementation callback validators were run for all five edited by-* files; see the checked implementation checklist above for command IDs and timestamps.

## Original Report-Only Closeout

This pass edited only this Agent-B012 research report. It did not edit by-* documentation, generated files, project-level generated reports, validator state/cache, coverage reports, IDA DB state, or lease files. No subagents were used.

## Implementation Callback Closeout

B012 applied the accepted implementation callback on 2026-06-25. Changed by-* files were [by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md](../../../../../by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md), [by-class/IconsPane.md](../../../../../by-class/IconsPane.md), [by-file/IconsPane.md](../../../../../by-file/IconsPane.md), [by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md](../../../../../by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md), and [by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md](../../../../../by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md). The target now carries the accepted `90/92` metadata, preserved owner/emitter route, vertical-first `HitTestIcon(int y, int x)` C++, current MCP evidence, exact geometry, padding/successor boundary, and rejected alternatives. No accepted checklist item remains unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0002T3-IconsPaneHitTestIcon-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002T3-IconsPaneHitTestIcon-source-quality.md","timestamp":"2026-06-25T14:05:10","uid":"0002T3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
