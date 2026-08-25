** TARGET-REPORT-UID:0001GH **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:0001GH] ScrollPaneInputCore

## Assignment

- Agent: B004.
- Assignment id: `B004-rework-0001GH-scroll-pane-input-core-20260626`.
- Target: [UID:0001GH][by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md](../../../../../by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md).
- Source queue: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; generated tracker/coverage rows are stale inputs only and must be refreshed by validator-owned flows after source-page implementation.
- Required disposition for this turn: report only. I made no by-* edits, generated edits, coverage edits, validator-state edits, or IDA DB writes.
- Current-pass update: this report was produced on 2026-06-25 and reworked in place on 2026-06-26 with live IDA MCP session `80de0a67`; no subagents and no leases were used.

## Recommendation

Implement after supervisor validation.

The current [UID:0001GH] page is evidence-strong, but it is not source-quality as one emitting by-memory target. It crosses two classes, eleven distinct method/raw-helper bodies, and ten internal padding islands:

- `ScrollPane` constructor/state/input/timer bodies.
- `ScrollWidget` target/current/enabled-state bodies.
- Three unmodeled raw setter-shaped bodies with no entry xrefs or pointer hits.
- EventHandler/TimerHandler adjusted receiver methods.
- Padding rows already recorded in [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md).

Recommended parent action:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
Nested:11
Item Summary: Non-emitting ScrollPane/ScrollWidget split index for the input-core corridor; exact child pages carry constructor, raw setter, widget state, EventHandler, default virtual, and TimerHandler bodies while existing ignored rows carry internal 0xcc padding.
RECONSTRUCTION_CPP CODE: blank
```

Recommended source-disposition marker for the parent page:

```text
Source disposition: non-emitting mixed ScrollPane/ScrollWidget split index; exact child pages carry source ownership, and selected child pages carry first-draft formal C++ insertion blocks. This parent stays blank because it spans multiple source methods/classes and internal padding.
```

This is not a fallback-only no-code recommendation. The current code-entry score gate is satisfied by the present `86/88` target metadata, but the one-source-unit requirement fails. Emitting one formal C++ block on [UID:0001GH] would either merge unrelated class methods, omit bytes in the target range, or misrepresent child-specific source declarations. The strict rework below supplies exact child formal C++ insertion text where the body, owner/emitter route, and caller/vtable evidence support it.

## Recommended Child Split

The child file names below are source-quality recommendations, not assigned UIDs. A validator-backed implementation pass must create the pages and use their assigned UIDs. Every child that receives `CANONICAL_OWNER`/`EMITTER_UIDS` is now at or above the strict `85/85` gate; no below-gate child is assigned an owner or emitter.

| Child path | COMPLETION | CONFIDENCE | CANONICAL_OWNER | RECONSTRUCTABLE | EMITTER_UIDS | Nested | Item Summary | Formal C++ disposition |
| --- | ---: | ---: | --- | --- | --- | ---: | --- | --- |
| `by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md` | `86` | `88` | `0000CM` | `TRUE` | `0000CM` | `0` | Constructs `ScrollPane` as a `Pane`, installs primary/EventHandler/TimerHandler vtables, stores orientation, initializes scroll state, and initializes the callback rect/state object. | Formal block `CXX-01` supplied. |
| `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | `85` | `87` | `0000CM` | `TRUE` | `0000CM` | `0` | Raw `ScrollPane` word-state setter; updates `+0xf8` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank `RECONSTRUCTION_CPP CODE`; no-code proof `NC-02`. |
| `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | `85` | `87` | `0000CM` | `TRUE` | `0000CM` | `0` | Raw `ScrollPane` byte-state setter; updates `+0xfa` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank `RECONSTRUCTION_CPP CODE`; no-code proof `NC-03`. |
| `by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md` | `86` | `88` | `0000CP` | `TRUE` | `0000CP` | `0` | Clamps `ScrollWidget` target to `0..30000`, lowers current when needed, stores `+0x100`, and invalidates the inherited bounds rect. | Formal block `CXX-04` supplied. |
| `by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md` | `85` | `87` | `0000CP` | `TRUE` | `0000CP` | `0` | Raw `ScrollWidget` current-position setter; updates `+0xfe` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank `RECONSTRUCTION_CPP CODE`; no-code proof `NC-05`. |
| `by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md` | `85` | `88` | `0000CP` | `TRUE` | `0000CP` | `0` | Enables `ScrollWidget` when `+0x102` is clear and invalidates the inherited bounds rect through the primary vtable slot. | Formal block `CXX-06` supplied. |
| `by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md` | `85` | `88` | `0000CP` | `TRUE` | `0000CP` | `0` | Disables `ScrollWidget` when `+0x102` is set and invalidates the inherited bounds rect through the primary vtable slot. | Formal block `CXX-07` supplied. |
| `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md` | `85` | `88` | `0000CM` | `TRUE` | `0000CM` | `0` | Returns true when the `ScrollPane` enabled byte is set and the range word at `+0x100` is positive; used by draw and geometry helpers. | Formal block `CXX-08` supplied. |
| `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | `86` | `89` | `0000CM` | `TRUE` | `0000CM` | `0` | EventHandler-adjusted `ScrollPane` mouse handler; hit-tests scroll parts, handles EPF/legacy mode, capture/release, drag start, cursor reset, and owner notification. | Blank `RECONSTRUCTION_CPP CODE`; no-code proof `NC-09`. |
| `by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md` | `85` | `89` | `0000CM` | `TRUE` | `0000CM` | `0` | Primary vtable default for the scroll-query slot; body returns false and is reached through `ScrollPane` vtable data. | Formal block `CXX-10` supplied. |
| `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | `86` | `89` | `0000CM` | `TRUE` | `0000CM` | `0` | TimerHandler-adjusted repeat callback; on timer id `0`, processes the active scroll part and reschedules repeat work for 30 ticks. | Formal block `CXX-11` supplied. |

Keep the current [UID:0001GH] range as a parent/index page after creating those exact children. Do not put formal C++ on the parent. Do not create child pages that include padding bytes; the existing ignored rows already identify the padding subranges.

## Current Target State

The target currently has:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000NF
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NF
RECONSTRUCTION_CPP CODE: blank
```

The page correctly records most function boundaries, raw setter bodies, caller sets, and padding rows. The stale defect is source disposition: it treats the mixed aggregate as reconstructable under [UID:0000NF][ScrollBar](../../../../../by-file/ScrollBar.md) and explains the blank C++ with older final-source-gate language. Under the current Rule 26/code-entry policy, the problem is not the score gate; it is that [UID:0001GH] is not one source unit.

Generated state is currently stale against the live target page. `auto-generated/-ag-research-tracker.md` still renders [UID:0001GH] at `76/86`, `auto-generated/-ag-coverage-report-by-memory.md` still renders it as `reconstructable` with `emits_code:false`, and `auto-generated/NexusTK/ui/core/ScrollBar.cpp` still contains the empty emitter marker with `Completion:76 | Confidence:86`. These are not source-of-truth facts; implementation should update source by-* metadata and run validators, not hand edit generated files.

## Heuristic / Inference Reanalysis And Validation

Key source-quality issue: [UID:0001GH] is a mixed memory corridor, not a single source function or one class-local method family. The current parent page is useful as an index and evidence ledger, but the current `RECONSTRUCTABLE:TRUE`/`EMITTER_UIDS:0000NF` route implies the parent itself can emit source through `ScrollBar.cpp`. That is not source-quality under current by-structure rules because the exact bytes cover `ScrollPane`, `ScrollWidget`, raw no-function helper bodies, EventHandler/TimerHandler adjusted entries, and padding.

Accepted inference: convert the parent to a non-emitting split index and create exact child pages. This is stronger than keeping the current aggregate as a blank emitter because it preserves reconstructable source-bearing bytes on child pages while letting the parent carry mixed-range evidence, rejected alternatives, padding, and split rationale.

Rejected alternative: keep [UID:0001GH] as a coherent aggregate like B001's executed [UID:0001GL] `ScrollablePaneCore` report. B001 rejected splitting [UID:0001GL] because that whole interval has one direct owner, [UID:0000CF] `ScrollablePane`, and its raw starts are same-class helpers. [UID:0001GH] differs materially: it alternates `ScrollPane` and `ScrollWidget` direct owners, and a file-level `ScrollBar` ancestor is too broad to be the source-facing owner for every method body.

Rejected alternative: assign the parent directly to `ScrollPane`. This would misown the `ScrollWidget` target/current/enable/disable helpers at `0x0055c310-0x0055c3da`.

Rejected alternative: assign the parent directly to `ScrollWidget`. This would misown the constructor, raw `ScrollPane` setters, visibility predicate, mouse handler, default false virtual, and timer handler.

Rejected alternative: keep the raw setter starts as unclassified padding or compiler trash. Live MCP disassembly shows source-shaped compare/write/notify bodies with normal returns; they lack function objects and direct/pointer routes, but they are executable source-authored helper bodies.

Rejected alternative: use caller classes (`ScrollablePane`, `ChattingHandlePane`, `TextEditPane`, `ScrollableControlPane`) as direct owners. Those pages supply construction/caller/consumer evidence only. The vtable stores, receiver adjustment, state offsets, and local method roles keep the target in the generic `ScrollBar.cpp` class family through `ScrollPane` and `ScrollWidget`.

Remaining uncertainty is child-level declaration quality for raw no-route starts and the large EventHandler-adjusted mouse body, not parent disposition or owner/emitter routing. The 2026-06-26 strict rework resolves the rejection by supplying formal C++ for supported modeled/routed children and target-specific no-code proofs only for the raw setters and mouse handler.

## Evidence Standards Used

Evidence hierarchy applied in this report:

- Direct IDA MCP facts: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `find_bytes`, `get_bytes`, `insn_query`, `decompile`, and `analyze_function include_asm=true` on live session `80de0a67`.
- Documentation evidence: target page [UID:0001GH], direct class pages [UID:0000CM] and [UID:0000CP], source-file ancestor [UID:0000NF], vtable data [UID:0003CK], padding ledger [UID:0000VN], support pages [UID:0001GI], [UID:0001GK], [UID:0003A5], [UID:0000F0], [UID:0001K8], [UID:00004N], [UID:0000SW], generated tracker/coverage rows, and proposed source-tree context.
- Negative evidence: no IDA function objects at raw starts `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`; no direct xrefs to those raw starts; no VA/RVA pointer-byte hits for the same starts; generated rows stale relative to source metadata.
- Inference: source-facing split/owner disposition and child page names. Original source names, local variable names, exact class field names, and source-file line placement remain inferred/descriptive unless separately documented. Child owner/emitter decisions are not inferred below gate; every owner/emitter child in this report is explicitly scored at least `85/85`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| Parent [UID:0001GH] should be a non-emitting split index. | Strong | Range alternates `ScrollPane` and `ScrollWidget` bodies, includes raw non-function helper bodies and `0xcc` padding, and live MCP confirms exact starts/ends. | B001 [UID:0001GL] comparable aggregate was checked; it has one direct class owner, unlike this target. | Child pages need validator-assigned UIDs during implementation. |
| `ScrollPane` owns `0x0055c200-0x0055c304` and `0x0055c3e0-0x0055c643`. | Strong | Constructor stores `ScrollPane` vtables, `ScrollablePane` constructs `ScrollPane(1)`/`ScrollPane(0)`, vtable slots reference `0x0055c400`, `0x0055c600`, and `0x0055c610`, and class/page docs route through `ScrollBar`. | Direct file-level owner alone was rejected as too broad; `ScrollWidget` cannot own these bodies. | Formal C++ is supplied for the constructor, visibility predicate, false virtual, and timer callback; raw `ScrollPane` setters and the large mouse handler remain blank under target-specific proofs. |
| `ScrollWidget` owns `0x0055c310-0x0055c3da`. | Strong | `SetScrollTargetValue` clamps target/current fields; raw current setter and enable/disable use `+0xfe/+0x100/+0x102`; the primary `+0x20` vtable slot is the inherited `InvalidateRect(&m_bounds)` route; callers are `ScrollablePane` sync and `ChattingHandlePane` enable/disable users. | Caller classes were rejected as consumers; `ScrollPane` does not own the target/current helper set. | Formal C++ is supplied for the routed target setter and enable/disable pair; the raw current setter remains blank under target-specific proof. |
| Raw starts are live source-shaped bodies, not padding. | Strong for body classification and direct owner, medium for liveness route. | 2026-06-26 `insn_query` shows exact compare/write/notify/return patterns; constructor/class docs initialize or consume the same fields; padding before/after is byte-verified `0xcc`; [UID:0000CM]/[UID:0000CP]/[UID:0000NF] all clear the gate. | `lookup_funcs` says not functions; `xrefs_to` reports zero direct xrefs; `find_bytes` finds no VA/RVA pointer encodings. | Exact original route/name unavailable, so child pages are `85/87` with blank C++ and no-code proof, not below-gate no-owner pages. |
| Parent formal C++ must stay blank. | Strong | One formal block would merge two class owners, multiple method bodies, adjusted interface entries, and padding. | Current score/emitter gate was checked; the block is blocked by source-unit shape, not by the old `95/95` rule. | Child-specific disposition is now split: `CXX-*` blocks for supported small/modeled/routed children and `NC-*` no-code proofs for raw no-route setters and the large mouse handler. |

## Live IDA MCP Session

MCP was available and current. I did not use fallback-only evidence.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp` version `1.0.0`.
- JSON-RPC flow used: `initialize`, `tools/list`, then `tools/call` with explicit `database` arguments.
- Session id: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`.
- Imagebase: `0x400000`.
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`.
- 2026-06-26 strict-C++ rework `idb_list`: one active adopted worker session, `is_analyzing:false`, backend `worker`, PID/worker PID `26892`, last accessed during this pass at `2026-06-26T02:59:24.438458`.
- 2026-06-26 strict-C++ rework `server_health(database=80de0a67)`: `uptime_sec:161016.22`, `strings_cache_size:2067`.
- 2026-06-26 tool schema recheck listed read-only evidence tools used here: `lookup_funcs`, `decompile`, `insn_query`, `analyze_function`, `xrefs_to`, `find_bytes`, `get_bytes`, and `idb_list`/`server_health`. Write-capable MCP tools such as `patch`, `rename`, `set_comments`, `define_func`, and `set_type` were not used.

## Boundary And Function Evidence

Live MCP `lookup_funcs` confirms these modeled and raw starts:

| Address | MCP result |
| --- | --- |
| `0x0055c200` | `sub_55C200`, size `0xa1` / 161 bytes (Verified with `int_convert.py`) |
| `0x0055c2b0` | not a function |
| `0x0055c2e0` | not a function |
| `0x0055c310` | `sub_55C310`, size `0x5b` / 91 bytes (Verified with `int_convert.py`) |
| `0x0055c370` | not a function |
| `0x0055c3a0` | `sub_55C3A0`, size `0x1a` / 26 bytes (Verified with `int_convert.py`) |
| `0x0055c3c0` | `sub_55C3C0`, size `0x1a` / 26 bytes |
| `0x0055c3e0` | `sub_55C3E0`, size `0x1a` / 26 bytes |
| `0x0055c400` | `sub_55C400`, size `0x1ff` / 511 bytes |
| `0x0055c600` | `sub_55C600`, size `0x5` / 5 bytes |
| `0x0055c610` | `sub_55C610`, size `0x33` / 51 bytes |
| `0x0055c650` | successor `sub_55C650`, size `0x1307`; not part of this target |

Live MCP `get_bytes` confirms the internal padding rows are all `0xcc`:

```text
0x0055c2a1-0x0055c2b0: 15 bytes
0x0055c2d7-0x0055c2e0: 9 bytes
0x0055c304-0x0055c310: 12 bytes
0x0055c36b-0x0055c370: 5 bytes
0x0055c397-0x0055c3a0: 9 bytes
0x0055c3ba-0x0055c3c0: 6 bytes
0x0055c3da-0x0055c3e0: 6 bytes
0x0055c3fa-0x0055c400: 6 bytes
0x0055c5ff-0x0055c600: 1 byte
0x0055c605-0x0055c610: 11 bytes
0x0055c643-0x0055c650: 13 bytes before successor ScrollPane::OnDraw
```

`int_convert.py` also verified:

- Whole target size `0x443` / 1091 bytes.
- Raw setter sizes `0x27` / 39 bytes, `0x24` / 36 bytes, and `0x27` / 39 bytes.
- Clamp constant `0x7530` / 30000.
- Field offsets `0xf8` / 248, `0xfa` / 250, `0xfe` / 254, `0x100` / 256, `0x102` / 258, and callback object offset `0x44` / 68.
- Adjusted vtable subobject offsets `0xa0` / 160 and `0xa4` / 164.

## Body Evidence

2026-06-26 strict-C++ recheck used live MCP `analyze_function include_asm=true` for the seven minimum supervisor-listed small/routed bodies: `0x0055c200`, `0x0055c310`, `0x0055c3a0`, `0x0055c3c0`, `0x0055c3e0`, `0x0055c600`, and `0x0055c610`. That pass confirmed the decompiler facts below and the exact assembly stores/calls needed for first-draft C++.

Pane/primary-slot evidence checked for the `InvalidateRect(&m_bounds)` route:

- [UID:0000A2][Pane](../../by-class/Pane.md) documents `+0x44` as the inherited local/bounds rect in Pane/GrafPort state.
- [UID:0002V7][PaneSetMode](../../by-memory/0x005446b0-0x005446d4.PaneSetMode.md) has accepted formal C++ that calls `InvalidateRect(&m_bounds)` after a state-byte change.
- The repeated `this + 0x44` receiver passed through primary vtable slot `+0x20` in the raw setters, `ScrollWidget::SetScrollTargetValue`, `ScrollWidget::Enable`, and `ScrollWidget::Disable` is therefore the inherited bounds invalidation route, not an unresolved generic owner callback for the supported `CXX-*` blocks.

### `0x0055c200-0x0055c2a1` ScrollPane constructor

Live MCP `decompile 0x0055c200` shows:

- Calls `sub_544460((char *)this, 1)`.
- Stores the constructor argument byte at `this + 0xfc`.
- Clears a dword at `this + 0xfe`.
- Stores three `ScrollPane` vtable pointers at `this + 0x0`, `this + 0xa0`, and `this + 0xa4`.
- Writes `0x10000` at `this + 0xf8`.
- Writes word `-255` at `this + 0x102`.
- Writes byte `-1` at `this + 0x104`.
- Calls `sub_4B7C30(this + 0x108, 0, 0)`.
- Returns `this`.

MCP `xrefs_to 0x0055c200` reports two constructor callsites inside `sub_55E660` at `0x0055e6f4` and `0x0055e72c`, matching the documented `ScrollablePane` horizontal/vertical `ScrollPane(1)` and `ScrollPane(0)` child construction.

### Raw `ScrollPane` setters

Live MCP `insn_query include_disasm` confirms the raw setter bodies:

- `0x0055c2b0-0x0055c2d7`: compares stack word argument against `[ecx+0xf8]`; on change writes `[ecx+0xf8]`, computes `this + 0x44`, tail-jumps through `[edx+0x20]`, otherwise returns through `pop ebp; retn 4`.
- `0x0055c2e0-0x0055c304`: compares stack byte argument against `[ecx+0xfa]`; on change writes `[ecx+0xfa]`, computes `this + 0x44`, tail-jumps through `[edx+0x20]`, otherwise returns through `pop ebp; retn 4`.

MCP `xrefs_to` reports zero xrefs to both raw starts. MCP `find_bytes` reports zero matches for both VA and RVA pointer encodings:

```text
B0 C2 55 00: 0
B0 C2 15 00: 0
E0 C2 55 00: 0
E0 C2 15 00: 0
```

The 2026-06-26 rework reran the same checks on session `80de0a67`: `lookup_funcs` still reports both raw starts as not functions; `xrefs_to` still reports zero xrefs; `find_bytes` reports zero matches for the same VA/RVA encodings; and range-scoped `insn_query` shows the full 13-instruction compare/write/notify/no-change-return bodies. These raw bodies now clear `85/87` for owner/emitter assignment because the body semantics, `ScrollPane` constructor-initialized field offsets, contiguous class-local placement, callback slot pattern, and [UID:0000CM]/[UID:0000NF] parent gate outweigh the route-name gap. The route-name gap remains a formal C++ blocker, not an owner/emitter blocker.

### `0x0055c310-0x0055c3da` ScrollWidget state helpers

Live MCP `decompile 0x0055c310` shows `ScrollWidget::SetScrollTargetValue` behavior:

- Clamps the signed word argument to `0..30000`.
- If the target changes and the new target is below current position (`this[127]`, offset `+0xfe`), lowers current position and notifies through vtable slot `+0x20` with `this + 0x44`.
- Writes target value at `this[128]`, offset `+0x100`, and notifies through the same slot.

MCP `xrefs_to 0x0055c310` reports three callsites:

- `0x0055e8be`.
- `0x0055e9d0` inside `sub_55E990`.
- `0x0055ea14` inside `sub_55E990`.

Live MCP `insn_query` and `decompile` confirm:

- `0x0055c370-0x0055c397` raw current-value setter compares/writes `[ecx+0xfe]`, calls the same notify slot with `this + 0x44`, and returns through `retn 4`. It has no IDA function object and no xrefs.
- `0x0055c3a0-0x0055c3ba` enables the byte at `+0x102` when it was zero and calls vtable slot `+0x20` with `this + 0x44`.
- `0x0055c3c0-0x0055c3da` clears the byte at `+0x102` when it was one and calls vtable slot `+0x20` with `this + 0x44`.

MCP `xrefs_to` reports:

- `0x0055c370`: zero xrefs; `find_bytes` reports zero matches for `70 C3 55 00` and `70 C3 15 00`.
- `0x0055c3a0`: code xrefs from `0x00481cda` and `0x00481e43`.
- `0x0055c3c0`: code xrefs from `0x00481ce1` and `0x00481e4a`.

The enable/disable callers match current `ChattingHandlePane` docs; they are caller evidence, not ownership evidence.

The 2026-06-26 rework reran `lookup_funcs`, `xrefs_to`, `find_bytes`, `insn_query`, and `decompile` for this cluster. `0x0055c370` is still not a function, still has zero xrefs and zero VA/RVA pointer hits, and still has the exact compare/write/notify/no-change-return body over `+0xfe`. It clears `85/87` because [UID:0000CP][ScrollWidget](../../../../../by-class/ScrollWidget.md) already documents `+0xfe` as current position, `SetScrollTargetValue` decompilation reads/writes the same field and clamps against it, the notify path is shared with the direct-call methods, and [UID:0000CP]/[UID:0000NF] clear the gate. The lack of a direct route/name caps the score and blocks formal C++, not ownership.

### `0x0055c3e0-0x0055c643` ScrollPane input callbacks

Live MCP `decompile 0x0055c3e0` shows the predicate:

```text
return *(byte *)(this + 0x102) && *(__int16 *)(this + 0x100) > 0;
```

MCP `xrefs_to 0x0055c3e0` reports ten code xrefs, including eight from `sub_55C650` (`ScrollPane::OnDraw`) and two from `sub_55D9E0` (`ScrollPane::GetScrollPartRect`). This supports generic `ScrollPane` ownership.

Live MCP `decompile 0x0055c400` shows a 511-byte EventHandler-adjusted mouse method. The decompiler uses `this - 160` and `this - 92`, matching the `ScrollPane + 0xa0` adjusted receiver and the `this + 0x44` callback/owner object. It branches on event byte `[a2+4]`, global `byte_66DA97`, hit tests through `sub_4B7E80`, helper `sub_55D960`, drag/start helper `sub_55DF10`, cursor/reset helper `sub_55E600`, and invalidation/capture helpers `sub_5449D0`/`sub_5449F0`.

MCP `xrefs_to` reports:

- `0x0055c400`: data xref from vtable slot `0x00623dac`.
- `0x0055c600`: data xref from vtable slot `0x00623db0`.
- `0x0055c610`: data xref from vtable slot `0x00623ddc`.

Live MCP `insn_query` confirms:

- `0x0055c600-0x0055c605`: `xor al, al; retn 4`.
- `0x0055c610-0x0055c643`: TimerHandler-adjusted receiver. It checks timer id zero, checks byte `[esi+0x60] != 0xff` (base `ScrollPane +0x104` because receiver is `ScrollPane +0xa4`), calls `sub_55DFD0(this - 0xa4)`, then calls `sub_5975E0(this, 0, 30, 0, 0)`, and returns true through `retn 0Ch`.

The 2026-06-26 rework also decompiled these functions on session `80de0a67`: `0x0055c400` is an EventHandler-adjusted method that branches on canonical [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) / `byte_66DA97`, reads event byte `[a2+4]` and coordinates `[a2+8]/[a2+12]`, uses `this-160` for the owning `ScrollPane`, uses `this-92` for the callback/owner object, and calls `sub_55D960`, `sub_55DF10`, `sub_55E600`, `sub_5449D0`, `sub_5449F0`, and `sub_4B7E80`. `0x0055c600` decompiles to `return 0`. `0x0055c610` decompiles to a `TimerHandler` callback that calls `sub_55DFD0(this-164)` and `sub_5975E0(this, 0, 30, 0, 0)` when timer id is zero and the active-part byte is not `0xff`.

## Vtable And Read-Only Data Evidence

[UID:0003CK][0x00623d58-0x00623de0.ScrollPaneVtableData](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md) already records the exact ScrollPane vtable child:

- `0x00623d58 -> ??_R4ScrollPane@@6B@`.
- `0x00623d5c -> ??_7ScrollPane@@6B@`.
- Constructor store at `0x0055c251`.
- `0x00623de0` begins the `ScrollablePane` successor locator and is excluded.

The current report adds that the input-core virtual slots point to exact child candidates:

- `0x00623dac -> 0x0055c400` for EventHandler-adjusted mouse input.
- `0x00623db0 -> 0x0055c600` for the false/default scroll virtual.
- `0x00623ddc -> 0x0055c610` for TimerHandler-adjusted timer handling.

That vtable evidence supports `ScrollPane` child ownership, not parent-level `ScrollBar` function emission.

## Ownership And Placement

Accepted source-file ancestor: [UID:0000NF][ScrollBar](../../../../../by-file/ScrollBar.md). The file owns the generic scrollbar family: `ScrollPane`, `ScrollWidget`, `ScrollablePane`, vtable data, and constants.

Accepted direct child owners:

- [UID:0000CM][ScrollPane](../../../../../by-class/ScrollPane.md) for `0x0055c200-0x0055c304` and `0x0055c3e0-0x0055c643`.
- [UID:0000CP][ScrollWidget](../../../../../by-class/ScrollWidget.md) for `0x0055c310-0x0055c3da`.

Rejected owners and alternatives:

- Reject direct [UID:0000NF][ScrollBar](../../../../../by-file/ScrollBar.md) as emitter for the parent. It is a file ancestor, not the direct source object for a mixed class-method band.
- Reject direct [UID:0000CF][ScrollablePane](../../../../../by-class/ScrollablePane.md) ownership for `0x0055c310`; `ScrollablePane` calls `ScrollWidget::SetScrollTargetValue` and constructs `ScrollPane` children but does not own the target bodies.
- Reject [UID:0000EO][TextEditPane](../../../../../by-class/TextEditPane.md) ownership. Text edit and later scrollbar variants consume the generic `ScrollPane` geometry/input helpers, but the constructor/vtable/field route here is generic scrollbar infrastructure.
- Reject [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md), `ChattingHandlePane`, and `ScrollableControlPane` as owners. Their evidence is caller/consumer evidence for `ScrollWidget` enable/disable or `ScrollablePane` wrappers, not owner evidence for this range.
- Reject treating the raw setter bodies as padding or generated trash. MCP disassembly shows source-shaped compare/write/notify patterns.
- Reject keeping [UID:0001GH] reconstructable with blank C++ solely under old "95/95" or "final-source gate" wording. Current policy requires target-specific no-code proof, and the proof is the mixed split-index shape.
- Reject merging this parent with successor [UID:0001GI][ScrollPaneOnDraw](../../../../../by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md); `0x0055c643-0x0055c650` is byte-verified padding and `0x0055c650` is the next modeled function.

## First-Draft C++ Eligibility And No-Code Proof

Parent [UID:0001GH] formal C++ must remain blank after implementation.

Exact parent no-code proof:

1. The range contains `ScrollPane` methods, `ScrollWidget` methods, and internal padding, not one source function.
2. `ScrollPane` direct owner and `ScrollWidget` direct owner differ; the shared `ScrollBar.cpp` file route is only an ancestor.
3. The range includes three raw no-function setter bodies with no direct xrefs and no VA/RVA pointer hits.
4. The range includes adjusted EventHandler and TimerHandler receiver methods (`this - 0xa0` and `this - 0xa4` shapes) that should be expressed on exact child pages, not as aggregate file-level code.
5. Emitting one C++ block would merge constructor, setter, predicate, event, timer, and helper logic from different methods.
6. Emitting partial C++ would omit covered bytes and violate the target range.
7. The child-level evidence now supports formal C++ only for selected child pages. The parent still cannot receive C++ because it is not one source unit.

Current-pass C++ evidence checked:

- Live MCP `analyze_function include_asm=true` and `decompile` for `0x0055c200`, `0x0055c310`, `0x0055c3a0`, `0x0055c3c0`, `0x0055c3e0`, `0x0055c600`, and `0x0055c610`.
- Live MCP `decompile` for the large EventHandler-adjusted mouse handler at `0x0055c400`.
- Live MCP `insn_query` for raw starts `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`, plus `0x0055c600` and `0x0055c610`.
- Live MCP `lookup_funcs`, `xrefs_to`, and `find_bytes` for modeled functions, raw starts, vtable slots, direct callers, and VA/RVA pointer routes.
- Current docs for [UID:0000CM][ScrollPane](../../../../../by-class/ScrollPane.md), [UID:0000CP][ScrollWidget](../../../../../by-class/ScrollWidget.md), [UID:0000NF][ScrollBar](../../../../../by-file/ScrollBar.md), [UID:0003CK][ScrollPaneVtableData](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md), [UID:00004N][EventHandler](../../../../../by-class/EventHandler.md), [UID:0000F0][TimerHandler](../../../../../by-class/TimerHandler.md), [UID:0001K8][TimerHandlerScheduleRemoveWrappers](../../../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md), [UID:0003A5][ScrollPaneInputGeometryHelpers](../../../../../by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md), [UID:0001GK][ScrollPaneGetScrollPartRect](../../../../../by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md), [UID:0001GI][ScrollPaneOnDraw](../../../../../by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md), [UID:0000A2][Pane](../../by-class/Pane.md), and [UID:0002V7][PaneSetMode](../../by-memory/0x005446b0-0x005446d4.PaneSetMode.md).
- Source-family naming comparison against documented `ScrollPane`/`ScrollWidget` roles and the sibling scrollbar-family field pattern, including `m_trackStateWord`, `m_scrollStyle`, `m_thumbDragActive`, `m_scrollPosition`, `m_scrollRange`, `m_currentPosition`, `m_targetPosition`, `m_enabled`, `m_highlightPart`, `m_activePart`, `m_bounds`, and `m_thumbDragOffset`.

Child C++ policy for the first implementation callback:

- Create exact child pages with the `CXX-*` formal blocks below where listed.
- Keep formal C++ blank only for the `NC-*` raw/no-route or oversized interface-handler proofs below.
- Do not insert sample, sketch, or pseudocode C++ into the parent or support prose. The `CXX-*` blocks are the proposed formal insertion text.
- Do not mark a child non-reconstructable solely because formal C++ is blank; the raw setter and mouse-handler children are source-authored bodies with exact owner/emitter routes, but their route/signature/helper evidence is not exact enough for a formal block in this pass.

Child formal/no-code disposition:

| Proposed child | Disposition | Evidence basis |
| --- | --- | --- |
| `ScrollPaneConstructor` | Insert `CXX-01`. | `analyze_function` confirms the `Pane(true)` constructor call, three `ScrollPane` vtable stores, packed field initialization, and `InitPointPair(&m_thumbDragOffset,0,0)` call; class/source-family docs supply stable first-draft field names. |
| `ScrollPaneRangeSetterRaw` | Blank formal C++; carry `NC-02`. | Raw no-function start with no direct xrefs or pointer route; field role is inferable, but source-facing method name/route is not. |
| `ScrollPaneByteStateSetterRaw` | Blank formal C++; carry `NC-03`. | Raw no-function start with no direct xrefs or pointer route; byte state role is inferable, but source-facing method name/route is not. |
| `ScrollWidgetSetScrollTargetValue` | Insert `CXX-04`. | Modeled function, three callers, exact clamp/current-lowering/target-write behavior, and inherited `InvalidateRect(&m_bounds)` route through vtable slot `+0x20`. |
| `ScrollWidgetCurrentValueSetterRaw` | Blank formal C++; carry `NC-05`. | Raw no-function start with no direct xrefs or pointer route; shared current-position field is proven, but source-facing setter name/route is not. |
| `ScrollWidgetEnable` | Insert `CXX-06`. | Modeled function, direct callers, exact `m_enabled` transition, and inherited `InvalidateRect(&m_bounds)` route. |
| `ScrollWidgetDisable` | Insert `CXX-07`. | Modeled function, direct callers, exact `m_enabled` transition, and inherited `InvalidateRect(&m_bounds)` route. |
| `ScrollPaneIsScrollThumbVisible` | Insert `CXX-08`. | Modeled predicate, ten direct draw/geometry callers, exact `m_enabled && m_scrollRange > 0` behavior. |
| `ScrollPaneHandleMouseEvent` | Blank formal C++; carry `NC-09`. | Vtable route is proven, but the 511-byte handler depends on open EventHandler signatures, event layout, and still-descriptive helper declarations. |
| `ScrollPaneCanScroll` | Insert `CXX-10`. | Vtable data route and five-byte false-return body prove the source-facing default virtual sufficiently for a first draft. |
| `ScrollPaneOnScrollTimer` | Insert `CXX-11`. | TimerHandler vtable route, settled `OnTimer(int,int,int)` ABI, active-part check, `sub_55DFD0` active-part processing helper, and accepted `ScheduleTimer` wrapper support the first draft. |

### Formal C++ insertion blocks

`CXX-01` for `by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ScrollPane::ScrollPane(bool horizontal)
    : Pane(true)
{
    m_trackStateWord = 0;
    m_scrollStyle = 1;
    m_thumbDragActive = false;
    m_orientation = horizontal ? 1 : 0;
    m_scrollPosition = 0;
    m_scrollRange = 0;
    m_enabled = true;
    m_highlightPart = kScrollPanePartNone;
    m_activePart = kScrollPanePartNone;
    InitPointPair(&m_thumbDragOffset, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-04` for `by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollWidget::SetScrollTargetValue(short targetPosition)
{
    if (targetPosition < 0)
        targetPosition = 0;
    if (targetPosition > 30000)
        targetPosition = 30000;

    if (m_targetPosition == targetPosition)
        return;

    if (targetPosition < m_currentPosition) {
        m_currentPosition = targetPosition;
        InvalidateRect(&m_bounds);
    }

    m_targetPosition = targetPosition;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-06` for `by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollWidget::Enable()
{
    if (m_enabled)
        return;

    m_enabled = true;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-07` for `by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollWidget::Disable()
{
    if (!m_enabled)
        return;

    m_enabled = false;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-08` for `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollPane::IsScrollThumbVisible()
{
    return m_enabled && m_scrollRange > 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-10` for `by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollPane::CanScroll(int)
{
    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

`CXX-11` for `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollPanePartNone) {
        ProcessActivePart();
        ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Target-specific no-code proof to carry into the split batch:

| Proof id | Proposed child | Current-pass evidence checked | Exact target-specific no-code proof |
| --- | --- | --- | --- |
| `NC-02` | `ScrollPaneRangeSetterRaw` | MCP `lookup_funcs` says not a function; `xrefs_to` zero; `find_bytes` zero VA/RVA hits; `insn_query` proves compare `[ecx+0xf8]`, write `[ecx+0xf8]`, notify through primary slot `+0x20` with `this+0x44`, and `retn 4`; ScrollPane constructor/class docs were checked. | The body is owner-quality `ScrollPane` source code and the field is plausibly `m_trackStateWord`, but formal C++ would require inventing an original out-of-line method name and callable route for a raw start that has no function object, direct xrefs, or pointer route. Body semantics and class context alone do not distinguish a retained private setter from an inlined/orphaned source helper or alternative state-name route. |
| `NC-03` | `ScrollPaneByteStateSetterRaw` | MCP `lookup_funcs` says not a function; `xrefs_to` zero; `find_bytes` zero VA/RVA hits; `insn_query` proves compare/write on byte `+0xfa`, notify through primary slot `+0x20` with `this+0x44`, and `retn 4`; ScrollPane constructor/class docs were checked. | The body clears the owner/emitter gate and the byte is plausibly `m_scrollStyle`, but no source-facing method name or route is recoverable beyond setter semantics and `ScrollPane` class context. Emitting a guessed setter would turn a no-function/no-xref raw body into an unsupported callable API. |
| `NC-05` | `ScrollWidgetCurrentValueSetterRaw` | MCP `lookup_funcs` says not a function; `xrefs_to` zero; `find_bytes` zero VA/RVA hits; `insn_query` proves compare/write on `+0xfe`, notify through primary slot `+0x20` with `this+0x44`, and `retn 4`; `SetScrollTargetValue` decompile uses the same current field. | The shared `+0xfe` field and notify pattern clear `85/87`, and the field is plausibly `m_currentPosition`, but a formal body would invent an original setter name and route for a raw no-function/no-xref start. Keep blank and document as a retained source-shaped raw child. |
| `NC-09` | `ScrollPaneHandleMouseEvent` | MCP decompile shows EventHandler-adjusted `this-160`, callback object `this-92`, event byte `[a2+4]`, coordinates `[a2+8]/[a2+12]`, `g_useEpfAssets` branch, and helper calls `sub_55D960`, `sub_55DF10`, `sub_55E600`, `sub_5449D0`, `sub_5449F0`, `sub_4B7E80`; EventHandler/global/helper docs were checked. | The vtable route and owner are strong, but this is a 511-byte interface handler whose formal C++ would need the EventHandler callback signature, event struct/enums, capture/release helper declarations, active/highlight part names, and exact branch-level behavior from the helper cluster. Those dependencies remain open in [UID:00004N], [UID:0003A5], [UID:0001GK], and [UID:0001GI]. Unlike the small routed children, a first-draft block here would still be pseudocode, not exact formal insertion text. |

## Score Rationale

Recommended parent score after split-index conversion:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:FALSE
```

Completion improves from `86` to `88` because the parent would now document the exact function/raw-helper inventory, padding map, direct child split, owner route, live MCP evidence, no-code proof, raw-start negative evidence, vtable slots, and support update plan. Confidence improves from `88` to `90` because live MCP independently confirms the boundaries, xrefs, raw disassembly, byte padding, and vtable/data route. The parent becomes non-reconstructable because exact children, not the mixed parent, should carry code emission.

Every exact child recommended in this report now clears `85/85` before receiving owner/emitter metadata. If implementation cannot carry over the evidence required for a listed score, it must not assign owner/emitter to that below-gate child; otherwise use the exact metadata table above.

Child score rationale:

| Child or group | Score | Rationale |
| --- | ---: | --- |
| `ScrollPaneConstructor` | `86/88` | Modeled function with constructor callers, vtable stores, exact constructor writes, parent class/file gate, and current decompile/assembly evidence. Field names remain first-draft but are sufficient for `CXX-01` because constructor behavior and source-family names align. |
| `ScrollPaneRangeSetterRaw` and `ScrollPaneByteStateSetterRaw` | `85/87` | Raised from the rejected sub-85 completion because current MCP proves exact source-shaped compare/write/notify bodies, padding-separated ranges, constructor-initialized adjacent fields, shared callback slot pattern, and [UID:0000CM]/[UID:0000NF] parent gate. Confidence is capped by no IDA function object, zero direct xrefs, zero VA/RVA pointer hits, and no original source names. |
| `ScrollWidgetSetScrollTargetValue` | `86/88` | Modeled function with three direct callers, clamp constant `30000`, current/target behavior, [UID:0000CP] state documentation, inherited `InvalidateRect(&m_bounds)` route, and parent gate. Evidence is sufficient for `CXX-04`. |
| `ScrollWidgetCurrentValueSetterRaw` | `85/87` | Raised from the rejected sub-85 completion because current MCP proves the exact raw compare/write/notify body over `+0xfe`, and `SetScrollTargetValue` plus [UID:0000CP] docs independently use `+0xfe` as current position. Confidence is capped by no function object, no xrefs, no pointer hits, and no original name. |
| `ScrollWidgetEnable` and `ScrollWidgetDisable` | `85/88` | Modeled small functions with direct ChattingHandlePane callers, `+0x102` transition behavior, inherited `InvalidateRect(&m_bounds)` route, [UID:0000CP] class route, and parent gate. Evidence is sufficient for `CXX-06` and `CXX-07`. |
| `ScrollPaneIsScrollThumbVisible` | `85/88` | Modeled predicate with ten direct code callers from draw/geometry helpers and exact decompile over `+0x102/+0x100`. Evidence is sufficient for `CXX-08`. |
| `ScrollPaneHandleMouseEvent` | `86/89` | Vtable-referenced EventHandler-adjusted method with current decompile, `g_useEpfAssets` global normalization, helper calls, state offsets, and class/vtable route. Completion is capped by EventHandler virtual-family names and helper declarations. |
| `ScrollPaneCanScroll` | `85/89` | Raised from the rejected sub-85 completion because current MCP proves the exact false-return body and `0x00623db0` vtable data route under [UID:0000CM]. Evidence is sufficient for `CXX-10`. |
| `ScrollPaneOnScrollTimer` | `86/89` | Vtable-referenced TimerHandler-adjusted method with current disassembly/decompile, settled base TimerHandler callback ABI, first-draft scheduler wrapper support, and exact repeat scheduling. Evidence is sufficient for `CXX-11` with `ProcessActivePart` as the first-draft source-facing name for `sub_55DFD0`. |

Score-limiting blocker ledger:

| Blocker | Current-pass research performed | Result / score impact |
| --- | --- | --- |
| Mixed range/source split | Checked target page, class pages, source-file page, proposed source-tree entry, generated tracker rows, B001 comparable report, and live MCP function/xref/body facts. | Resolved with implementation-ready split plan. Parent can rise to `88/90` as a non-emitting split index after implementation. |
| Raw helper liveness and names | Live MCP `lookup_funcs`, `xrefs_to`, `find_bytes`, `insn_query`, and padding `get_bytes` were run for `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370`; class docs and source-family docs were checked. | Resolved for gate purposes: raw children are `85/87`, owner/emitter assigned to `ScrollPane` or `ScrollWidget`, and formal C++ remains blank under proof `NC-02`, `NC-03`, or `NC-05`. |
| Owner/emitter route | Ranked `ScrollPane`, `ScrollWidget`, `ScrollBar`, `ScrollablePane`, `TextEditPane`, `ChattingHandlePane`, `ControlPane`, and comparable aggregate outcomes. | Direct child owners are `ScrollPane` and `ScrollWidget`; `ScrollBar` remains source-file ancestor. Parent `RECONSTRUCTABLE` should become `FALSE` and `EMITTER_UIDS` blank. |
| Vtable and adjusted receivers | Live `xrefs_to` confirms vtable/data refs at `0x00623dac`, `0x00623db0`, `0x00623ddc`; decompile/disasm confirms `this - 0xa0` and `this - 0xa4` receiver shapes. | Supports exact child pages for mouse/default/timer entries; blocks parent-level source block. |
| First-draft C++ | Checked current code-entry rule, live MCP decompilation/disassembly, EventHandler/TimerHandler docs, Pane/PaneSetMode invalidation evidence, global/source-family docs, vtable data, callers/callees, and helper pages. | Parent is not eligible because it is not one source unit. Child pages are reconstructable and owner/emitter-routed; `CXX-01`, `CXX-04`, `CXX-06`, `CXX-07`, `CXX-08`, `CXX-10`, and `CXX-11` provide exact formal insertion text, while `NC-02`, `NC-03`, `NC-05`, and `NC-09` prove target-specific no-code disposition. |

## Open Questions With Attempted Resolution

- Open question: can [UID:0001GH] stay as a single reconstructable blank emitter? Resolution: no. The current route meets the numeric code gate but fails source-unit shape. Convert the parent to non-reconstructable split index and move reconstruction eligibility to exact children.
- Open question: are raw setter bodies dead/unreachable and ignorable? Resolution: not ignorable. They are executable source-shaped helper bodies with compare/write/notify behavior. Negative xref/pointer evidence only limits route/name confidence and formal C++ readiness.
- Open question: should child pages emit first-draft C++ immediately? Resolution: yes for the seven small/modeled/routed children with `CXX-*` blocks, and no for the three raw no-route setter bodies plus the large EventHandler mouse handler with `NC-*` proofs. The remaining blank children are blocked by target-specific route/signature/helper gaps, not by uninvestigated work.
- Open question: does the source-file ancestor need to change? Resolution: no. `ScrollBar.cpp` remains the correct source-file ancestor for both `ScrollPane` and `ScrollWidget`; the defect is direct owner/split granularity, not top-level source-file placement.

## Support Documentation Impact

Implementation callback applied these support-doc updates:

- [by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md](../../../../../by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md): convert to non-emitting split index; add child inventory; preserve all raw body, padding, xref, and negative pointer evidence; replace stale old-gate language with the current split-index no-code proof and the child `CXX-*`/`NC-*` disposition.
- [by-class/ScrollPane.md](../../../../../by-class/ScrollPane.md): replace the single `ScrollPaneInputCore` method-family link with exact child links after UID assignment; document constructor writes, raw `+0xf8/+0xfa` setters, `IsScrollThumbVisible`, EventHandler-adjusted `HandleMouseEvent`, default false `CanScroll`, and TimerHandler-adjusted `OnTimer`; note that formal C++ is ready for constructor, visibility predicate, default false virtual, and timer callback but remains blank for raw setters and mouse handler; remove stale `95/95` wording.
- [by-class/ScrollWidget.md](../../../../../by-class/ScrollWidget.md): replace the "main address range" dependence on the mixed parent with exact child links for target/current/enable/disable helpers; preserve `+0xfe/+0x100/+0x102`, `InvalidateRect(&m_bounds)`, direct caller evidence, raw current setter no-route cap, and primary slot `+0x20`; note that formal C++ is ready for target setter and enable/disable but remains blank for the raw current setter.
- [by-file/ScrollBar.md](../../../../../by-file/ScrollBar.md): state that [UID:0001GH] becomes a non-emitting split index while exact `ScrollPane` and `ScrollWidget` children carry owner/emitter routes and selected formal C++ through their classes; keep file score unchanged unless broader file evidence is added.
- [by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md): add child references for the constructor store and the `0x00623dac/0x00623db0/0x00623ddc` input/default/timer slots after child UIDs exist.
- [by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md](../../../../../by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md): optional; update only the `ScrollWidget::SetScrollTargetValue` link to the new exact child if a support pass touches the file.
- [by-memory/-ignored.md](../../../../../by-memory/-ignored.md): likely no edit is needed. It already records all internal `0xcc` padding rows. Edit only if validator requires parent/child wording synchronization.

Do not edit generated/project-level files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` during B-agent implementation unless the supervisor explicitly grants that ownership.

## Generated And Coverage State

Generated outputs are stale relative to current docs and should be refreshed by validators/generators after accepted implementation, not hand edited.

- `auto-generated/NexusTK/ui/core/ScrollBar.cpp` currently still shows [UID:0001GH] as an empty emitter marker with stale `76/86` metadata.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still contain stale rows for [UID:0001GH].
- Manual [by-memory/-coverage-report.md](../../../../../by-memory/-coverage-report.md) is supervisor-owned and was not edited during this implementation callback.

No exact manual coverage-report replacement text is supplied because this assignment did not explicitly request manual `-coverage-report.md` editing. Implementation should update the source by-memory page `Item Summary`/`Nested` metadata and exact child pages, then let scoped validators refresh validator-owned generated reports. Child generated rows require validator-assigned UIDs and should be produced by validator refresh after child files exist.

## Implementation Callback Checklist

If the supervisor validates this report and sends an implementation callback, do the following in a lease-compliant by-* edit turn:

- [x] Acquire leases only for files that will be edited immediately. Do not acquire or edit generated files, project-level generated files, validator state/cache, IDA DB, manual coverage reports, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
- [x] Create these exact child pages with validator-assigned UIDs. Each child gets `Nested:0` and either the matching `CXX-*` formal insertion block or the matching `NC-*` no-code proof listed here:

| Child page to create | Metadata to set | Item Summary | C++ disposition |
| --- | --- | --- | --- |
| `by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md` | `COMPLETION:86`; `CONFIDENCE:88`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | Constructs `ScrollPane` as a `Pane`, installs primary/EventHandler/TimerHandler vtables, stores orientation, initializes scroll state, and initializes the callback rect/state object. | Insert `CXX-01`. |
| `by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | `COMPLETION:85`; `CONFIDENCE:87`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | Raw `ScrollPane` word-state setter; updates `+0xf8` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank; `NC-02`. |
| `by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | `COMPLETION:85`; `CONFIDENCE:87`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | Raw `ScrollPane` byte-state setter; updates `+0xfa` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank; `NC-03`. |
| `by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md` | `COMPLETION:86`; `CONFIDENCE:88`; `CANONICAL_OWNER:0000CP`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CP`; `Nested:0` | Clamps `ScrollWidget` target to `0..30000`, lowers current when needed, stores `+0x100`, and invalidates the inherited bounds rect. | Insert `CXX-04`. |
| `by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md` | `COMPLETION:85`; `CONFIDENCE:87`; `CANONICAL_OWNER:0000CP`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CP`; `Nested:0` | Raw `ScrollWidget` current-position setter; updates `+0xfe` only on change and invalidates the inherited bounds rect through primary slot `+0x20`. | Blank; `NC-05`. |
| `by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md` | `COMPLETION:85`; `CONFIDENCE:88`; `CANONICAL_OWNER:0000CP`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CP`; `Nested:0` | Enables `ScrollWidget` when `+0x102` is clear and invalidates the inherited bounds rect. | Insert `CXX-06`. |
| `by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md` | `COMPLETION:85`; `CONFIDENCE:88`; `CANONICAL_OWNER:0000CP`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CP`; `Nested:0` | Disables `ScrollWidget` when `+0x102` is set and invalidates the inherited bounds rect. | Insert `CXX-07`. |
| `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md` | `COMPLETION:85`; `CONFIDENCE:88`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | Returns true when the `ScrollPane` enabled byte is set and the range word at `+0x100` is positive; used by draw and geometry helpers. | Insert `CXX-08`. |
| `by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | `COMPLETION:86`; `CONFIDENCE:89`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | EventHandler-adjusted `ScrollPane` mouse handler; hit-tests scroll parts, handles EPF/legacy mode, capture/release, drag start, cursor reset, and owner notification. | Blank; `NC-09`. |
| `by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md` | `COMPLETION:85`; `CONFIDENCE:89`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | Primary vtable default for the scroll-query slot; body returns false and is reached through `ScrollPane` vtable data. | Insert `CXX-10`. |
| `by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | `COMPLETION:86`; `CONFIDENCE:89`; `CANONICAL_OWNER:0000CM`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000CM`; `Nested:0` | TimerHandler-adjusted repeat callback; on timer id `0`, processes the active scroll part and reschedules repeat work for 30 ticks. | Insert `CXX-11`. |

- [x] Edit [by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md](../../../../../by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md):
  - [x] Change `COMPLETION` from `86` to `88`.
  - [x] Change `CONFIDENCE` from `88` to `90`.
  - [x] Keep `CANONICAL_OWNER:0000NF`.
  - [x] Change `RECONSTRUCTABLE` from `TRUE` to `FALSE`.
  - [x] Blank `EMITTER_UIDS`.
  - [x] Set `Nested:11`.
  - [x] Set `Item Summary` to: `Non-emitting ScrollPane/ScrollWidget split index for the input-core corridor; exact child pages carry constructor, raw setter, widget state, EventHandler, default virtual, and TimerHandler bodies while existing ignored rows carry internal 0xcc padding.`
  - [x] Keep formal C++ blank and insert the parent source-disposition marker from this report.
  - [x] Add a child table with actual child UIDs/links after creation.
  - [x] Preserve exact body evidence: modeled function sizes, raw setter instructions, `0x7530` clamp, vtable slot refs, padding rows, raw no-xref/no-pointer evidence, and successor `0x0055c650`.
  - [x] Replace stale old-gate wording with current code-entry policy and parent split-index no-code proof.
  - [x] Add rejected alternatives and a 2026-06-25/2026-06-26 B004 change entry recording original report plus current live-MCP rework.
- [x] Edit each newly created child page:
  - [x] Include exact range, function/raw status, xrefs, caller/vtable evidence, padding exclusions, score rationale, and the matching `CXX-*` insertion block or `NC-*` proof from this report.
  - [x] Insert the exact `CXX-*` block for children marked `Insert CXX-*`; keep formal C++ blank only for children marked `Blank; NC-*`.
- [x] Edit [by-class/ScrollPane.md](../../../../../by-class/ScrollPane.md):
  - [x] Replace broad input-core method-family wording with actual child UID links for constructor, raw setters, visibility predicate, mouse handler, default false virtual, and timer handler.
  - [x] Add adjusted receiver notes for EventHandler `+0xa0` and TimerHandler `+0xa4`.
  - [x] Record the raw setters as gate-cleared child pages with blank formal C++ proofs, not sub-85 no-owner bodies.
  - [x] Remove stale `95/95` wording; keep score unchanged unless the implementation adds broader field/declaration evidence and explains a score change.
- [x] Edit [by-class/ScrollWidget.md](../../../../../by-class/ScrollWidget.md):
  - [x] Replace mixed parent dependence with actual child UID links for target setter, raw current setter, enable, and disable.
  - [x] Preserve `+0xfe/+0x100/+0x102`, `0..30000`, inherited `InvalidateRect(&m_bounds)` via primary slot `+0x20`, direct caller sets, and the raw current setter no-route cap.
  - [x] Record the raw current setter as `85/87` with owner/emitter and blank C++ proof `NC-05`; keep class score unchanged unless broader declaration evidence is added.
- [x] Edit [by-file/ScrollBar.md](../../../../../by-file/ScrollBar.md):
  - [x] State that [UID:0001GH] is a non-emitting split index and exact child pages carry owner/emitter routes, with selected formal C++ through `ScrollPane`/`ScrollWidget`.
  - [x] Add actual child UID links in the `ScrollPane`/`ScrollWidget` proposed contents or evidence notes.
  - [x] Keep file score unchanged unless a broader file pass is performed.
- [x] Edit [by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md):
  - [x] Add actual child links for constructor store and vtable slot targets `0x0055c400`, `0x0055c600`, and `0x0055c610`.
  - [x] Keep vtable-data score unchanged unless additional byte/table evidence is added.
- [x] Optionally edit [by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md](../../../../../by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) only to update the `0x0055c310` child link if the support pass touches it. Excluded: the implementation did not touch this optional support page; accepted support edits were complete without changing it.
- [x] Run scoped validators from `source-3/project-documentation` for every edited by-* file with `--wait-generated`. Minimum command set if all required files above are edited:

> Executable block R001 was removed from this report and preserved verbatim in [0001GH-ScrollPaneInputCore-source-quality-removed.md](0001GH-ScrollPaneInputCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Add equivalent validator commands for any optional support file actually edited. Excluded: no optional support file was edited, so no additional validator was required.
- [x] Inspect generated refresh state for [UID:0001GH] after validation, but do not hand edit generated output.
- [x] Release all leases immediately after the edit/validator batch.
- [x] Update this report checklist with proof: leases used/released, files touched, metadata before/after, child UIDs assigned, validator command IDs/timestamps/exit codes/ok counts, generated-refresh observations, and any item left unchecked with concrete reason.
- [x] No manual `-coverage-report.md` text is approved by this report. If the supervisor later explicitly requests a legacy manual coverage update, handle that as a separate supervisor-owned instruction.

### Implementation Proof

Callback implementation completed on 2026-06-26. No generated files, project-level generated files, validator/tool-state files, IDA DB files, manual coverage reports, `by-memory/-coverage-report.md`, or any `-coverage-report.md` were manually edited.

Lease proof:

- B004 leased only the immediate by-* edit/validator set: parent, eleven children, [by-class/ScrollPane.md](../../../../../by-class/ScrollPane.md), [by-class/ScrollWidget.md](../../../../../by-class/ScrollWidget.md), [by-file/ScrollBar.md](../../../../../by-file/ScrollBar.md), and [by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md).
- `python .\leaser.py B004 unlease` released those sixteen by-* leases after the final validator batch; each path returned `Success`.
- `tools/leaser/Agents/current_leases.md` was read after release and had no `B004` row. The confirmation read was immediately before `2026-06-26T04:29:22.1784881-04:00`.

Child UID proof:

| UID | Child file | Registration command | Final disposition proof |
| --- | --- | --- | --- |
| `00042V` | [0x0055c200-0x0055c2a1.ScrollPaneConstructor](../../../../../by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md) | `000000002229`, `2026-06-26T04:01:11-04:00`, exit `0` | `86/88`, owner/emitter `0000CM`, `Nested:0`, formal `CXX-01` block present; sections `Behavior`, `Evidence`, `Score Rationale`, `Cross-References`, `Changes`. |
| `00042W` | [0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw](../../../../../by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md) | `000000002230`, `2026-06-26T04:01:13-04:00`, exit `0` | `85/87`, owner/emitter `0000CM`, `Nested:0`, blank formal C++ with `No-Code Proof` `NC-02`. |
| `00042X` | [0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw](../../../../../by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md) | `000000002231`, `2026-06-26T04:01:14-04:00`, exit `0` | `85/87`, owner/emitter `0000CM`, `Nested:0`, blank formal C++ with `No-Code Proof` `NC-03`. |
| `00042Y` | [0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue](../../../../../by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md) | `000000002232`, `2026-06-26T04:01:16-04:00`, exit `0` | `86/88`, owner/emitter `0000CP`, `Nested:0`, formal `CXX-04` block present. |
| `00042Z` | [0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw](../../../../../by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md) | `000000002233`, `2026-06-26T04:01:17-04:00`, exit `0` | `85/87`, owner/emitter `0000CP`, `Nested:0`, blank formal C++ with `No-Code Proof` `NC-05`. |
| `000430` | [0x0055c3a0-0x0055c3ba.ScrollWidgetEnable](../../../../../by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md) | `000000002234`, `2026-06-26T04:01:19-04:00`, exit `0` | `85/88`, owner/emitter `0000CP`, `Nested:0`, formal `CXX-06` block present. |
| `000431` | [0x0055c3c0-0x0055c3da.ScrollWidgetDisable](../../../../../by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md) | `000000002236`, `2026-06-26T04:01:28-04:00`, exit `0` | `85/88`, owner/emitter `0000CP`, `Nested:0`, formal `CXX-07` block present. |
| `000432` | [0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible](../../../../../by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md) | `000000002238`, `2026-06-26T04:01:30-04:00`, exit `0` | `85/88`, owner/emitter `0000CM`, `Nested:0`, formal `CXX-08` block present. |
| `000433` | [0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent](../../../../../by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md) | `000000002240`, `2026-06-26T04:01:32-04:00`, exit `0` | `86/89`, owner/emitter `0000CM`, `Nested:0`, blank formal C++ with `No-Code Proof` `NC-09`. |
| `000434` | [0x0055c600-0x0055c605.ScrollPaneCanScroll](../../../../../by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md) | `000000002242`, `2026-06-26T04:01:33-04:00`, exit `0` | `85/89`, owner/emitter `0000CM`, `Nested:0`, formal `CXX-10` block present. |
| `000435` | [0x0055c610-0x0055c643.ScrollPaneOnScrollTimer](../../../../../by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md) | `000000002244`, `2026-06-26T04:01:35-04:00`, exit `0` | `86/89`, owner/emitter `0000CM`, `Nested:0`, formal `CXX-11` block present. |

Target/support proof:

- [by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md](../../../../../by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md) now has header `88/90`, owner `0000NF`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, `Nested:11`, the exact accepted `Item Summary`, blank formal C++, a `Functions` child table with all eleven UIDs, `Parent No-Code Proof`, `Split Decision And Rejected Alternatives`, current evidence notes, cross-references, and a B004 2026-06-26 change entry.
- [by-class/ScrollPane.md](../../../../../by-class/ScrollPane.md) now has `2026-06-26 Input-Core Split`, exact `ScrollPane` child UID links, EventHandler `+0xa0` and TimerHandler `+0xa4` notes, raw setter no-code proof notes, and no stale `95/95` wording.
- [by-class/ScrollWidget.md](../../../../../by-class/ScrollWidget.md) now routes the target/current/enable/disable bodies to UIDs `00042Y`, `00042Z`, `000430`, and `000431`, preserves `+0xfe/+0x100/+0x102`, `0..30000`, `InvalidateRect(&m_bounds)` through slot `+0x20`, caller evidence, `NC-05`, and unchanged score.
- [by-file/ScrollBar.md](../../../../../by-file/ScrollBar.md) now states [UID:0001GH] is a non-emitting split index and records exact `ScrollPane`/`ScrollWidget` child ownership/emitter routes and selected formal C++ disposition; score unchanged.
- [by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md](../../../../../by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md) now links the constructor child and vtable slots `0x00623dac`, `0x00623db0`, and `0x00623ddc` to UIDs `000433`, `000434`, and `000435`; score unchanged.
- [by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md](../../../../../by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) was intentionally not edited because the optional support pass did not touch it and no accepted required edit depended on it.

Final scoped validators from `source-3/project-documentation`:

| File | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory\0x0055c200-0x0055c643.ScrollPaneInputCore.md` | `000000002349` | `2026-06-26T04:24:40-04:00` | `0` | `1` | `completed`; generated command `000000002349` |
| `by-memory\0x0055c200-0x0055c2a1.ScrollPaneConstructor.md` | `000000002351` | `2026-06-26T04:24:52-04:00` | `0` | `1` | `completed`; generated command `000000002351` |
| `by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | `000000002352` | `2026-06-26T04:25:04-04:00` | `0` | `1` | `completed`; generated command `000000002352` |
| `by-memory\0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | `000000002353` | `2026-06-26T04:25:16-04:00` | `0` | `1` | `completed`; generated command `000000002353` |
| `by-memory\0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md` | `000000002354` | `2026-06-26T04:25:28-04:00` | `0` | `1` | `completed`; generated command `000000002354` |
| `by-memory\0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md` | `000000002355` | `2026-06-26T04:25:39-04:00` | `0` | `1` | `completed`; generated command `000000002355` |
| `by-memory\0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md` | `000000002356` | `2026-06-26T04:25:51-04:00` | `0` | `1` | `completed`; generated command `000000002356` |
| `by-memory\0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md` | `000000002357` | `2026-06-26T04:26:02-04:00` | `0` | `1` | `completed`; generated command `000000002357` |
| `by-memory\0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md` | `000000002359` | `2026-06-26T04:26:14-04:00` | `0` | `1` | `completed`; generated command `000000002359` |
| `by-memory\0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md` | `000000002360` | `2026-06-26T04:26:27-04:00` | `0` | `1` | `completed`; generated command `000000002360` |
| `by-memory\0x0055c600-0x0055c605.ScrollPaneCanScroll.md` | `000000002361` | `2026-06-26T04:26:39-04:00` | `0` | `1` | `completed`; generated command `000000002361` |
| `by-memory\0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md` | `000000002362` | `2026-06-26T04:26:51-04:00` | `0` | `1` | `completed`; generated command `000000002362` |
| `by-class\ScrollPane.md` | `000000002364` | `2026-06-26T04:27:02-04:00` | `0` | `1` | `completed`; generated command `000000002364` |
| `by-class\ScrollWidget.md` | `000000002365` | `2026-06-26T04:27:14-04:00` | `0` | `1` | `completed`; generated command `000000002365` |
| `by-file\ScrollBar.md` | `000000002366` | `2026-06-26T04:27:26-04:00` | `0` | `1` | `completed`; generated command `000000002366` |
| `by-memory\0x00623d58-0x00623de0.ScrollPaneVtableData.md` | `000000002367` | `2026-06-26T04:27:37-04:00` | `0` | `1` | `completed`; generated command `000000002367` |

Validator warning observation: the final scoped validators also reported existing project-wide registry/coverage diagnostics (`autogen_registry_stale:154` and `memory_coverage_metadata_missing_file:152`). Some files reported `missing_ref_target` counts for stale registered paths, including the old `0001GK` path ending at `0x0055de98`; the edited docs now link to the existing [0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect](../../../../../by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md). No validator-state lifecycle cleanup was part of this accepted checklist, and no validator-state file was edited manually.

### Revised Implementation Correction Proof

Post-execution correction after supervisor rejection: command `000000002377` had executed this report, but the child-page support references for inherited `Pane` bounds and comparable `PaneSetMode` invalidation behavior still pointed at unrelated docs. B004 corrected only the affected child-page support references; no generated files, project-level generated files, coverage reports, validator/tool-state files, or IDA DB files were manually edited.

Search proof:

- The eleven new ScrollPane/ScrollWidget child pages were searched for the wrong `SelfSaveOKPane`/`GameServerNationAndMapInit` support references and their stale UID numbers.
- All occurrences that referred to inherited `Pane` bounds state, primary slot `+0x20`, `InvalidateRect(&m_bounds)`, or comparable `PaneSetMode` behavior were corrected to `[UID:0000A2] by-class/Pane.md` and `[UID:0002V7] by-memory/0x005446b0-0x005446d4.PaneSetMode.md`.
- Follow-up `rg` across the eleven child pages found no remaining wrong `SelfSaveOKPane`/`GameServerNationAndMapInit` support references or stale UID-number references.

Corrected files:

| File | Correction |
| --- | --- |
| `by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | Replaced wrong `SelfSaveOKPane`/`GameServerNationAndMapInit` links in the behavior line and cross-reference bullets with `Pane`/`PaneSetMode`. |
| `by-memory\0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | Replaced wrong cross-reference bullets with `Pane`/`PaneSetMode`. |
| `by-memory\0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md` | Replaced wrong evidence and cross-reference support links with `Pane`/`PaneSetMode`. |
| `by-memory\0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md` | Replaced wrong cross-reference bullets with `Pane`/`PaneSetMode`. |

Lease proof:

- B004 leased exactly the four affected child files for the correction batch.
- `python .\leaser.py B004 unlease` released those four files after validation; each path returned `Success`.
- `tools/leaser/Agents/current_leases.md` was read after release and had no `B004` row; confirmation time `2026-06-26T04:39:50.5299383-04:00`.

Revision validators from `source-3/project-documentation`:

| File | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory\0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md` | `000000002385` | `2026-06-26T04:38:17-04:00` | `0` | `1` | `completed`; generated command `000000002385` |
| `by-memory\0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md` | `000000002386` | `2026-06-26T04:38:30-04:00` | `0` | `1` | `completed`; generated command `000000002386` |
| `by-memory\0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md` | `000000002387` | `2026-06-26T04:38:41-04:00` | `0` | `1` | `completed`; generated command `000000002387` |
| `by-memory\0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md` | `000000002388` | `2026-06-26T04:38:53-04:00` | `0` | `1` | `completed`; generated command `000000002388` |

Revision validator warning observation: the four scoped validators still reported existing project-wide registry/coverage diagnostics (`autogen_registry_stale:152`, `memory_coverage_metadata_missing_file:150`), and `ScrollWidgetSetScrollTargetValue` also reported `missing_ref_target:2` from existing registry state. The corrected child links themselves point at existing current `Pane` and `PaneSetMode` docs, and no validator-state lifecycle cleanup or manual state edit was part of this correction.

## Validation Performed

Implementation validators were run from `source-3/project-documentation` after the by-* edits. The final validator table in `Implementation Proof` records every command ID/timestamp; all sixteen scoped `--wait-generated` file validators exited `0`, returned `ok:1`, and reported `generated_refresh: completed`.

Report-local evidence remains MCP-backed from live session `80de0a67`. No write-capable MCP tools were used. No generated/project-level files, coverage reports, validator/tool-state files, or IDA DB files were manually edited.

## Changed Files

By-* target/support files changed:

```text
by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md
by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md
by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md
by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md
by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md
by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md
by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md
by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md
by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md
by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md
by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md
by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md
by-class/ScrollPane.md
by-class/ScrollWidget.md
by-file/ScrollBar.md
by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md
```

Report proof file changed:

```text
tools/leaser/Agents/Agent-B004/research/0001GH-ScrollPaneInputCore-source-quality.md
```

## Final Implementation Status

Implementation callback is complete. Every accepted checklist item is applied, already present at equal-or-greater detail, or explicitly excluded with a concrete reason. B004 has no active lease, and there are no unchecked blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001GH-ScrollPaneInputCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001GH-ScrollPaneInputCore-source-quality.md","timestamp":"2026-06-26T04:34:47","uid":"0001GH"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GH-ScrollPaneInputCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001GH-ScrollPaneInputCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
