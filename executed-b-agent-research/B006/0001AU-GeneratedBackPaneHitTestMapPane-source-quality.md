** TARGET-REPORT-UID:0001AU **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Source-Quality Report: [UID:0001AU] GeneratedBackPaneHitTestMapPane

Report-only assignment: `B006-report-0001AU-generated-backpane-hit-test-mappane-20260624`  
Target: `by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md`  
Required report path: `tools/leaser/Agents/Agent-B006/research/0001AU-GeneratedBackPaneHitTestMapPane-source-quality.md`  
Agent: B006  
Mode: report-only research; no leases taken; no target, support, generated, by-project-structure, tool-state, IDA DB, or coverage-report edits made.

## Executive Recommendation

[UID:0001AU] is a complete 53-byte MapPane helper, not a BackPane source method. It performs a bounds-gated hit test against the inherited pane rectangle at `this+0x44`, and only when the point is inside that rectangle does it forward to the MapPane object-row lookup helper at `0x0050c470`. The stale generated BackPane wording should be retained only as historical provenance, not as owner, source file, or method-name guidance.

Recommended metadata for [UID:0001AU]:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `89` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `00007Q` | keep `00007Q` |
| `RECONSTRUCTABLE` | `TRUE` | keep `TRUE` |
| `EMITTER_UIDS` | `00007Q` | keep `00007Q` |
| `EMITTER_POSITION_OPTIONAL` | blank | keep blank |

Recommended source placement:

| Role | UID/path | Recommendation |
| --- | --- | --- |
| Direct owner/emitter | [UID:00007Q] `by-class/MapPane.md` | Keep. The receiver is the active MapPane object and the callee scans MapPane object rows. |
| Source file/root | [UID:0000L3] `by-file/MapPane.md` | Keep. The helper belongs in MapPane source, with target-selection panes as callers only. |
| Stale generated label | target filename `GeneratedBackPaneHitTestMapPane` | Preserve only as generated-name history. Do not move to BackPane. |

Recommended final source-facing helper names:

| Address/UID | Final role | Recommended source-facing name |
| --- | --- | --- |
| `0x00506ce0` / [UID:0001AU] | Bounds-checked public MapPane target/object hit-test wrapper | `MapPane::HitTestObjectAtPoint` |
| `0x0050c470` / currently covered by [UID:00037Y] | Inner object-row and per-object-rect search after caller has supplied a map-pane point | `MapPane::FindObjectAtMapPoint` |

This split resolves the current naming collision in existing documentation where `0x0050c470` was tentatively called `HitTestObjectAtPoint`. The outer wrapper at [UID:0001AU] is the better owner of that public name because it performs the pane-bounds gate before delegating.

## Current Blockers Resolved

| Blocker from goal/target | Resolution |
| --- | --- |
| Generated BackPane wording versus MapPane ownership | BackPane ownership is rejected. All direct callers are target-selection mouse handlers passing the active MapPane; BackPane docs already reject this address as a BackPane method. |
| Final source-facing helper name | Use `MapPane::HitTestObjectAtPoint` for [UID:0001AU]. Reserve `MapPane::FindObjectAtMapPoint` for `0x0050c470`. |
| Return type/object lookup contract for `0x0050c470` | [UID:0001AU] returns a targetable object pane pointer or zero. Target-selection callers use the result as a living target: highlight toggle through `0x0053b1b0` and inherited object id read at `+0xfc`. |
| Typed rectangle/member names at `this+0x44` | `this+0x44` is inherited `Pane::m_bounds`, type `RectBounds`, with `left/top/right/bottom`. Existing Pane/RectBounds docs preserve source argument order `y, x`. |
| Caller family | Four direct callers are the spell/item/select-object/target-object target-selection mouse paths. MapPane's own large mouse handler calls `0x0050c470` directly and bypasses this wrapper. |
| Owner/emitter route | Keep owner and emitter [UID:00007Q] MapPane, file route [UID:0000L3] MapPane. Target-selection input panes are consumers, not source owners. |
| First-draft C++ readiness | Ready. The function is exact, closed, and has only two callees. Formal C++ insertion text is recommended below. |

## MCP Provenance

IDA MCP was available and responsive. Evidence was collected from the active MCP database rather than fallback-only documentation.

| Item | Value |
| --- | --- |
| MCP endpoint | `http://127.0.0.1:13337/mcp` |
| Active database id | `80de0a67` |
| IDB path | `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Module | `NexusTK.exe` |
| Input path reported by server | `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` |
| Image base | `0x400000` |
| Server state | `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true` |
| Target MCP functions used | `server_health`, `idb_list`, `lookup_funcs`, `decompile`, `disasm`, `analyze_function`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `find_bytes` |

## Exact Range And Boundary Evidence

| Address | MCP result |
| --- | --- |
| `0x00506cdd` | Not a function. Three preceding bytes are `CC CC CC`. |
| `0x00506ce0` | Function `sub_506CE0`, size `0x35` bytes. |
| `0x00506d14` | Last byte still belongs to `sub_506CE0`. |
| `0x00506d15` | Not a function. Following bytes are padding `CC`. |
| `0x00506d20` | Next function `sub_506D20`, size `0xcc`; separated by padding. |

The exact target bytes for `0x00506ce0..0x00506d14` are 53 bytes with SHA-256:

`71a07289a98c40d7ea761c13c0d26e5a394c87d7127de3a7359a2ad95022151b`

The disassembly has 23 instructions, 3 basic blocks, and one conditional branch. The function preserves `esi`, reads `this` from `ecx`, builds the rectangle address with `lea eax,[esi+44h]`, pushes the same two integer arguments for both callees, calls `0x004b7e80`, and either returns zero or tail-delegates through `0x0050c470`. Both exits use `retn 8`, confirming two explicit integer arguments after the `this` receiver.

## Decompiled Behavior

IDA decompilation for [UID:0001AU] reduced to the following behavior:

| Step | Evidence | Meaning |
| --- | --- | --- |
| Receiver setup | `mov esi, ecx` | `this` is the MapPane receiver. |
| Rectangle address | `lea eax, [esi+44h]` | The tested rectangle is inherited `Pane::m_bounds`/`RectBounds` at receiver offset `+0x44`. |
| Bounds call | `sub_4B7E80(a2, a3, this + 17)` | Calls the shared `RectBounds` point predicate with source argument order `y, x`. |
| Rejection path | `test al, al`; conditional branch to `xor eax,eax` | Outside-pane points return zero without scanning objects. |
| Acceptance path | `sub_50C470(this, a2, a3)` | Inside-pane points forward to the MapPane object lookup helper. |
| Return | returned callee pointer or zero | The helper returns a targetable object pane pointer on hit, otherwise zero. |

The wrapper is source-significant even though it is short: it is the only observed direct caller-side gate that prevents the target-selection paths from object-scanning outside the MapPane rectangle.

## Receiver And Rectangle Layout

| Offset | Size | Field/member | Type | Evidence source | Target use |
| --- | ---: | --- | --- | --- | --- |
| `this+0x44` | 16 | `m_bounds` | `RectBounds` with `left`, `top`, `right`, `bottom` | [UID:0000A2] Pane docs; [UID:0001VH] PaneLayout; [UID:0001VP] RectBoundsLayout; [UID:000161] BackPaneGetBounds copies this exact 16-byte inherited field | [UID:0001AU] passes this address to `0x004b7e80`. |
| `this+0x400` | 4 | tile-origin Y / row origin | integer row coordinate base | [UID:00007Q] MapPane field glossary; `0x0050c470` decompilation uses `this[256]` | Inner lookup derives an object-list row from the vertical coordinate. |
| `this+0x424` | 4 | `m_objectList` | object-list/index container | [UID:00007Q] MapPane field glossary; `0x0050c470` decompilation uses `this[265]` in `sub_532670` | Inner lookup fetches row buckets and iterates object entries. |

`RectBoundsLayout` resolves the unusual parameter-order blocker: both class and free point tests preserve current binary/source-facing argument order `y, x`. Therefore [UID:0001AU] should not be documented or emitted as an `x, y` wrapper unless the entire RectBounds convention is deliberately renamed later.

## Callee Contracts

| Callee | MCP body facts | Contract for [UID:0001AU] |
| --- | --- | --- |
| `0x004b7e80` | Size `0x27`; no callees; compares the second explicit argument against rect left/right and the first explicit argument against rect top/bottom; half-open bounds. | Shared `RectBounds` point predicate. In current project naming, this is `PointInRect(y, x, &m_bounds)`. |
| `0x0050c470` | Size `0xd9`; callees `0x00505290`, `0x00532670`, `0x004b7e80`, security-cookie check. Uses `this+0x400` to choose a row, `this+0x424` object-list rows, per-object virtual rectangle fetch, and `0x004b7e80` per object. | Inner MapPane object lookup. Recommended name `FindObjectAtMapPoint`. Returns the found target object pane pointer or zero. |

The return contract is supported by all four direct callers: they compare the returned pointer against a saved current target, pass it to the highlight helper at `0x0053b1b0`, and read the inherited object id at pointer offset `+0xfc`. That caller behavior is stronger evidence for a targetable living/object-pane pointer than the raw IDA type `int`.

## Caller And UID Relation Matrix

| Address/callsite | Current documented UID/path | Relationship to [UID:0001AU] |
| --- | --- | --- |
| `0x005ae8b2` in `sub_5AE730` | SpellWho input pane pointer-selection path | Direct caller. Computes translated map-pane point, calls [UID:0001AU], updates target highlight and saved target id. |
| `0x005af1b5` in `sub_5AF050` | ItemWho input pane mouse input | Direct caller. Same target-object pointer-selection pattern. |
| `0x005afb51` in `sub_5AFA10` | SelectObject mouse event path | Direct caller. Same target-object pointer-selection pattern. |
| `0x005b03d1` in `sub_5B0290` | TargetObject mouse event path | Direct caller. Same target-object pointer-selection pattern. |
| `0x0050726d`, `0x0050747c`, `0x005075e3`, `0x005079d9`, `0x00507a72` in `sub_507150` | MapPane large mouse/event handler covered by [UID:00037Y] | These call `0x0050c470` directly, proving the inner finder is a separate lower-level helper used inside MapPane itself. |

MCP `xrefs_to` found exactly four code xrefs to `0x00506ce0` and six code xrefs to `0x0050c470`. No BackPane core/help/paint caller reaches [UID:0001AU].

## Negative Route Checks

| Check | Result | Impact |
| --- | --- | --- |
| Data xrefs to `0x00506ce0` | none found | No evidence for table-dispatched BackPane virtual/helper route. |
| Data xrefs to `0x0050c470` | none found | Inner finder is direct-call code, not pointer-table owned. |
| Byte search for target VA `E0 6C 50 00` | zero matches | No static pointer route to [UID:0001AU]. |
| Byte search for target RVA `E0 6C 10 00` | zero matches | No RVA table route to [UID:0001AU]. |
| Byte search for callee VA `70 C4 50 00` | zero matches | No static pointer route to the inner finder. |
| Byte search for callee RVA `70 C4 10 00` | zero matches | No RVA table route to the inner finder. |
| BackPane support docs | BackPane docs explicitly reject `0x00506ce0` BackPane ownership | Confirms generated BackPane filename wording is stale. |

## Rejected Alternatives

| Alternative | Rejection reason |
| --- | --- |
| BackPane owner/source method | The receiver comes from active MapPane paths, the body uses MapPane object lookup, direct callers are target-selection mouse handlers, and BackPane docs already mark this generated address as not BackPane-owned. |
| TargetSelectionInputPanes as canonical owner | The target-selection panes are the four direct consumers, but the receiver and callee are MapPane and MapPane's own event handler calls the inner finder directly. Source placement should remain MapPane. |
| Naming both [UID:0001AU] and `0x0050c470` as `HitTestObjectAtPoint` | This creates a collision and hides the real split. [UID:0001AU] performs the pane-bounds gate; `0x0050c470` performs object-row and per-object-rectangle search. |
| Emitting the wrapper with `x, y` source argument order | Current `RectBoundsLayout` explicitly preserves `y, x` source order for the shared point-test helper. Reversing the order would misrepresent the observed stack order. |
| Keeping formal C++ blank | The current blockers are resolved by MCP and support-doc evidence. The range is exact, the body is complete, the owner route is stable, and the only remaining naming issue is handled by the wrapper/finder split. |

## Formal C++ Recommendation

Recommended exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0001AU]:

```cpp
LivingObjectPane *MapPane::HitTestObjectAtPoint(int y, int x)
{
    if (!PointInRect(y, x, &m_bounds))
        return 0;

    return FindObjectAtMapPoint(y, x);
}
```

Rationale:

| Decision | Evidence |
| --- | --- |
| Return type `LivingObjectPane *` | All direct target-selection callers use the result as a target actor: highlight state toggling through `0x0053b1b0` and inherited object id read at `+0xfc`. |
| Receiver `MapPane` | Direct receiver is the active MapPane, callee uses MapPane fields `+0x400` and `+0x424`, and source owner [UID:00007Q] is already accepted. |
| Helper name `HitTestObjectAtPoint` | This wrapper owns the source-visible hit-test contract because it includes the pane-bounds test before object lookup. |
| Argument order `int y, int x` | Preserves project RectBounds source convention and the observed stack order through `0x004b7e80`. |
| Member `m_bounds` | Existing [UID:000161] formal C++ already uses `m_bounds` for the inherited `+0x44` rectangle. |
| Inner call `FindObjectAtMapPoint` | Avoids the stale collision where `0x0050c470` was tentatively also named `HitTestObjectAtPoint`; describes the callee's row/object search role. |

No other C++ is recommended in this report. If the implementation supervisor declines the `LivingObjectPane *` type or the `FindObjectAtMapPoint` callee spelling, the target should keep formal C++ blank until the support docs define the accepted inner-finder declaration, because any alternate C++ would be formal insertion text rather than sample code.

## Support-Doc Impact

Target implementation should be the primary edit. Support docs are not edited in this report-only pass. The following support sync is recommended if the implementation callback allows directly related support corrections:

| Support doc | Recommended correction |
| --- | --- |
| [UID:00037Y] `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md` | Rename or qualify `0x0050c470` from tentative public `HitTestObjectAtPoint` to inner `FindObjectAtMapPoint`; state that [UID:0001AU] owns the bounds-checked public hit-test wrapper. |
| [UID:00007Q] `by-class/MapPane.md` | Add the resolved wrapper/finder distinction and preserve `m_bounds`/`RectBounds` `y, x` argument order if the class method table is updated. |
| [UID:0000L3] `by-file/MapPane.md` | Keep [UID:0001AU] in MapPane source and update wording so generated BackPane naming is stale provenance only. |
| Target-selection mouse docs | If touched later, ensure calls to the wrapper preserve `y, x` argument order rather than source text that reads as `x, y`. |

The following support docs already contain compatible facts and do not require direct edits for this report: [UID:0000A2] Pane, [UID:0001VH] PaneLayout, [UID:0001VP] RectBoundsLayout, [UID:000161] BackPaneGetBounds, [UID:00009R] ObjectPane, [UID:00007B] LivingObjectPane, and the BackPane class/file docs that already reject this generated BackPane address.

## Score Rationale

Recommended `89/91` is higher than the current `85/88` because MCP resolved the core blockers:

| Factor | Effect |
| --- | --- |
| Exact range, boundaries, byte hash, and instruction count | Raises completion and confidence. |
| Full body decompile is stable and has only two callees | Raises C++ readiness. |
| Direct caller family is complete and target-specific | Raises source-placement confidence. |
| Negative data/pointer route checks are clean | Reduces BackPane/table-dispatch risk. |
| Support docs independently confirm Pane `+0x44` and MapPane object-list fields | Raises type/member confidence. |
| Remaining support-doc name sync for `0x0050c470` | Keeps completion below the low-to-mid 90s until support docs and declarations are harmonized. |

## Implementation Checklist

Implementation callback status:

- [x] Edited only the accepted target/support scope: target [UID:0001AU], support [UID:00037Y], support [UID:00007Q], and support [UID:0000L3]. No generated reports, coverage reports, by-project-structure docs, validator code/state by manual edit, IDA DB, or unrelated by-* docs were manually edited.
- [x] Set [UID:0001AU] metadata to `COMPLETION:89`, `CONFIDENCE:91`; preserved `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Replaced unresolved target open questions with the resolved MapPane wrapper, `Pane::m_bounds` / `RectBounds`, `y, x` argument order, target-selection caller family, and `0x0050c470` inner-finder evidence.
- [x] Added MCP provenance for session/database `80de0a67`, exact 53-byte range, boundary padding, byte SHA-256, decompile/disassembly anchors, caller/callee matrix, negative data/pointer route checks, and no-BackPane-caller proof.
- [x] Inserted the accepted formal C++ exactly in the target's formal `RECONSTRUCTION_CPP CODE` block:

```cpp
LivingObjectPane *MapPane::HitTestObjectAtPoint(int y, int x)
{
    if (!PointInRect(y, x, &m_bounds))
        return 0;

    return FindObjectAtMapPoint(y, x);
}
```

- [x] Added no sample, illustrative, draft, or side-section C++ for [UID:0001AU]. The only target C++ is the formal block above.
- [x] Added rejected alternatives and score rationale at report-level detail, including rejected BackPane ownership, rejected target-selection-pane ownership, rejected wrapper/finder name collision, rejected `x, y` rewrite, and rejected blank-C++ disposition.
- [x] Applied the callback-authorized support sync: [UID:00037Y] now treats `0x0050c470` as inner `MapPane::FindObjectAtMapPoint`; [UID:00007Q] documents the wrapper/finder distinction and inherited `m_bounds`; [UID:0000L3] keeps [UID:0001AU] in MapPane source and marks generated BackPane wording as stale provenance only.
- [x] Used short by-* leases only for the immediate edit/validator batch. B006 leases were held for the four edited by-* files during validation and released successfully afterward: target, [UID:00037Y], [UID:00007Q], and [UID:0000L3].
- [x] Ran the scoped validators from `source-3/project-documentation`:
  - Target first pass: `command_id: 000000000576`, `command_timestamp: 2026-06-24T16:18:47-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
  - [UID:00037Y]: `command_id: 000000000577`, `command_timestamp: 2026-06-24T16:18:57-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
  - [UID:00007Q]: `command_id: 000000000578`, `command_timestamp: 2026-06-24T16:19:04-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
  - [UID:0000L3]: `command_id: 000000000579`, `command_timestamp: 2026-06-24T16:20:47-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.
  - Target post-support-link rerun: `command_id: 000000000580`, `command_timestamp: 2026-06-24T16:20:52-04:00`, exit code `0`, `ok: 1`, `generated_refresh: deferred`.

Implementation status: complete. No checklist items remain intentionally unapplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001AU-GeneratedBackPaneHitTestMapPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001AU-GeneratedBackPaneHitTestMapPane-source-quality.md","timestamp":"2026-06-24T16:24:16","uid":"0001AU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
