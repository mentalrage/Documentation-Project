** TARGET-REPORT-UID:00048H **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# UID00048H SimpleHelpPaneOnMouseDown Source Quality Report

## Finalized Report / Current Recommendation

Gate 1 accepted UID00048H as a real source-emitting `SimpleHelpPane::OnMouseDown` child method. The implementation callback raised the target score from `COMPLETION:85` / `CONFIDENCE:90` to `COMPLETION:88` / `CONFIDENCE:92` and kept the existing formal C++ body unchanged.

The new score is not `95+` because IDA still has no original source symbol for the method name, no recovered final `PaneEvent` type/name proof for the unused argument group, and no direct runtime caller beyond the vtable slot. The body, range, vtable route, helper call, and split are now strongly verified by current IDA MCP evidence.

## Supporting Research

Primary target:

- `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`

Support context read during this report-only pass:

- `by-class/SimpleHelpPane.md`
- `by-file/HelpPanes.md`
- `by-memory/0x004c6f90-0x004c7287.SimpleHelpPaneConstructor.md`
- `by-memory/0x004c7310-0x004c743e.SimpleHelpPaneOnPaintFrame.md`
- `by-memory/0x004c7450-0x004c7491.SimpleHelpPaneOnTimerEvent.md`
- `by-memory/0x004c74a0-0x004c74b0.SimpleHelpPaneOnKeyPress.md`
- `by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md`
- `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` was read only to confirm current generated emission state.
- `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-research-tracker.md` were read only for tracker/generated status.

Executed/support reports read:

- `executed-b-agent-research/B007/00016S-SimpleHelpPanes-source-quality.md`
- `executed-b-agent-research/B004/0000JU-HelpPanes-empty-emitter-family-source-quality.md`

Duplicate/report search result:

- No existing exact `TARGET-REPORT-UID:00048H` active or executed B-agent report was found before writing this report.
- The current assignment row in `goal.md` listed UID00048H at `85/90`, combined `87.5`, `RECONSTRUCTABLE:TRUE`, and report count `0`.

No target/support by-* documents, generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, report execution locations, or IDA database files were edited during this report-only pass.

## Target

UID00048H currently documents:

- Address range: `0x004c7440-0x004c7450`
- Name: `SimpleHelpPaneOnMouseDown`
- Current metadata after callback: `COMPLETION:88`, `CONFIDENCE:92`
- Pre-callback metadata was `COMPLETION:85`, `CONFIDENCE:90`
- Current ownership: `CANONICAL_OWNER:0000D6`
- Current reconstruction state: `RECONSTRUCTABLE:TRUE`
- Current emitter route: `EMITTER_UIDS:0000D6`
- Current optional emitter position: blank
- Current nesting marker: `Nested:0`
- Current formal C++ block:

```cpp
bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)
{
    Close();
    return false;
}
```

## Current Target State

The current target is already source-shaped and emits a concrete method body through `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`. The target does not need a new split, owner change, range change, or body rewrite.

The current body is credible because current IDA MCP confirms a one-block function at `0x004c7440` that adjusts `ecx`, calls the shared close/dismiss helper `sub_544690`, clears `al`, and returns with `retn 0Ch`. The C++ representation as `Close(); return false;` is the right source-facing abstraction for this child page.

The remaining quality gap is documentary, not functional: the target page should incorporate the current MCP session facts, the exact vtable/data xref route, the no-direct-caller caveat, the boundary bytes, the helper behavior, and the reason the name/signature remain inference-bound.

## Heuristic / Inference Reanalysis And Validation

The prior `85/90` score was conservative because the method was a short event handler with no IDA symbol and only vtable-based reachability. Current evidence reduces the uncertainty around range, ownership, and body semantics, but it does not eliminate all source-name/type uncertainty.

Event-handler source name/signature:

- IDA names the function `sub_4C7440`, not `SimpleHelpPane::OnMouseDown`.
- IDA's recovered prototype is raw: `char __thiscall(char *this, int, int, int)`.
- The source-facing signature `bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)` remains an inference from the SimpleHelpPane child split, the virtual table route, sibling event-handler pages, and the source-shaped return convention.
- The argument group is unused by this function, so current machine code cannot prove the final source parameter name or full event type by field access inside this body.

Vtable/class route:

- `xrefs_to(0x004c7440)` returns one data xref at `0x0061ac64`.
- `xrefs_to(0x0061ac60)` returns three data xrefs from SimpleHelpPane construction/destruction paths: `0x004c7019`, `0x004c72cb`, and `0x004ce5a2`.
- `xrefs_to(0x0061ac64)` returns zero xrefs to the slot address itself, so there is no direct slot-address liveness beyond the function pointer data xref and base vtable users.
- The class route is still stronger than a standalone helper interpretation because the target function is vtable-referenced and adjusts `this` before calling the shared close helper.

Empty-emitter / generated cause:

- UID00048H is not an empty-emitter target now. The generated HelpPanes output already emits the concrete formal body.
- At assignment time, the tracker listed the target in a not-covered reconstructable queue because no exact B-agent report existed before this pass, not because the body was blank.
- The broad parent UID00016S remains the non-emitting split index for the SimpleHelpPane family. UID00048H is the exact emitting child for this method.

Formal C++ eligibility:

- The body has one direct helper call and a constant false return.
- The helper call target is not local source code for UID00048H, but the helper's behavior supports the source-facing `Close()` abstraction.
- Keeping the existing formal block is appropriate. Historical uncertainty about original spelling remains a confidence cap, not a reason to blank the C++.

Child/parent coverage relationship:

- UID00016S covers the broad `0x004c6f90-0x004c7680` SimpleHelpPanes block as a split index and `RECONSTRUCTABLE:FALSE`.
- UID00048H is one of the exact source children under that parent and is the correct source-emitting range for `0x004c7440-0x004c7450`.
- No child split or parent range change is recommended.

## Evidence Standards Used

This report used the project-level `ntk-b-agent-workflow` instructions and the `by-structure.md` `IDA MCP Output Discipline`:

- Exact-address MCP calls were used.
- `lookup_funcs` was used for function-start and boundary checks.
- Decompile, disassembly, basic-block, callees, xrefs, bytes, and byte-pattern queries were narrow and paged.
- Limits were kept small and bounded.
- No broad unbounded IDA scraping was used.
- No `py_eval` was used.
- A failed `find_bytes` wrapper call with the stale singular `pattern` field was discarded as non-evidence; the check was rerun successfully with the schema-current `patterns` argument.

MCP availability:

- Active session: `supervisor_recovery_20260705`
- Server health: `ok`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true
- Strings cache ready: true

This is not a fallback-only report.

## Evidence Checked

Current IDA MCP calls used as direct evidence:

- `idb_list`
- `server_health`
- `lookup_funcs` at `0x004c743e`, `0x004c7440`, `0x004c7450`, `0x004c74a0`, `0x00544690`, and `0x005446ad`
- `analyze_function` at `0x004c7440`
- `decompile` at `0x004c7440`
- `disasm` at `0x004c7440`
- `basic_blocks` at `0x004c7440`
- `callees` at `0x004c7440`
- `xrefs_to` at `0x004c7440`
- `get_bytes` at `0x004c7440`
- `get_bytes` at `0x004c7438`
- `xrefs_to` at `0x0061ac60`, `0x0061ac64`, `0x0061ac28`, `0x0061ac30`, and `0x004c74a0`
- `get_bytes` at `0x0061abe4`, `0x0061ac30`, and `0x0061ac60`
- `get_int` at selected vtable dwords around `0x0061abe4`, `0x0061ac28`, `0x0061ac30`, `0x0061ac60`, `0x0061ac64`, `0x0061ac68`, and `0x0061ac6c`
- `find_bytes` for the target VA pointer pattern `40 74 4C 00`
- `find_bytes` for the target RVA-style pattern `40 74 0C 00`
- `find_bytes` for the exact target body bytes
- `find_bytes` for the close-handler body shape with wildcarded call displacement
- `analyze_function` at `0x00544690`

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---|---|---|
| C001 | Current IDA MCP evidence is available and not fallback-only: session `supervisor_recovery_20260705`, health `ok`, imagebase `0x400000`. | High | `idb_list` and `server_health` returned active session, `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, analysis/Hex-Rays ready. | `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` -> Evidence And Behavior. | incorporate | applied |
| C002 | UID00048H is a real function start at `0x004c7440` with size `0x10`; adjacent starts are clean. | High | `lookup_funcs(0x004c7440)` -> `sub_4C7440`, size `0x10`; `0x004c743e` -> not a function; `0x004c7450` -> `sub_4C7450`, size `0x41`. | Target -> Evidence And Behavior / Xrefs And Boundary Detail. | incorporate | applied |
| C003 | The target body is exactly a close/dismiss call followed by false return. | High | `analyze_function`, `decompile`, and `disasm` show `add ecx, 0FFFFFF5Ch`, `call sub_544690`, `xor al, al`, `retn 0Ch`. | Target -> Evidence And Behavior and preserved formal C++ block. | incorporate | applied |
| C004 | The body is one basic block with no CFG complexity. | High | `basic_blocks(0x004c7440)` -> one block `0x004c7440-0x004c7450`, no predecessors or successors. | Target -> Evidence And Behavior. | incorporate | applied |
| C005 | The direct callee is shared close/dismiss helper `sub_544690`; source-facing `Close()` remains appropriate. | High | `callees(0x004c7440)` -> `sub_544690`; helper analysis checks/sets `[ecx+0xF4]` and queues through `dword_67A74C` / `sub_469180`. | Target -> Evidence And Behavior / Source-Quality Notes. | incorporate | applied |
| C006 | The target has no direct code callers in IDA; reachability is vtable/data based. | High | `analyze_function` callers empty; `xrefs_to(0x004c7440)` has one data xref and no code xrefs. | Target -> Xrefs And Boundary Detail / Source-Quality Notes. | incorporate | applied |
| C007 | The exact vtable/data xref to the method is `0x0061ac64`. | High | `xrefs_to(0x004c7440)` -> data xref `0x0061ac64`; `find_bytes "40 74 4C 00"` -> one match at `0x0061ac64`. | Target -> Xrefs And Boundary Detail. | incorporate | applied |
| C008 | The SimpleHelpPane vtable base has constructor/destructor route evidence. | High | `xrefs_to(0x0061ac60)` -> `0x004c7019`, `0x004c72cb`, `0x004ce5a2`. | Target -> Xrefs And Boundary Detail. | incorporate | applied |
| C009 | The slot address itself has no direct xrefs and remains a reachability caveat. | High | `xrefs_to(0x0061ac64)` -> zero. | Target -> Xrefs And Boundary Detail / Source-Quality Notes. | incorporate | applied |
| C010 | RVA-style pointer-pattern search does not independently find the target. | High | `find_bytes "40 74 0C 00"` -> zero matches. | Target -> Xrefs And Boundary Detail. | incorporate | applied |
| C011 | Exact body bytes and wildcarded close-handler byte shape are unique to `0x004c7440`. | High | Exact target body pattern and wildcarded pattern each matched only `0x004c7440`. | Target -> Xrefs And Boundary Detail. | incorporate | applied |
| C012 | The range boundary is clean and does not require a split/range change. | High | `get_bytes(0x004c7438, 40)` shows previous tail, two `0xcc` bytes at `0x004c743e-0x004c7440`, target body at `0x004c7440-0x004c7450`, next timer prologue at `0x004c7450`. | Target -> Xrefs And Boundary Detail. | incorporate | applied |
| C013 | The formal C++ block is correct and should remain unchanged. | High | Decompiled body calls close helper and returns `0`; generated HelpPanes output emits the same source-shaped body after validator refresh. | Target -> `RECONSTRUCTION_CPP CODE`; generated freshness checked in `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`. | already-present | already-present |
| C014 | Ownership/emitter metadata should remain `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, blank optional emitter position, and `Nested:0`. | High | Target/support docs route SimpleHelpPane children through HelpPanes/SimpleHelpPane; current vtable route aligns with that split. | Target -> Metadata. | already-present | already-present |
| C015 | Target scores should improve to `COMPLETION:88` and `CONFIDENCE:92`, not `95+`. | Medium-High | Current MCP removes range/body/vtable ambiguity; original source symbol, final event type/name, and direct runtime caller remain unproven. | Target -> Metadata and Source-Quality Notes. | incorporate | applied |
| C016 | Support docs need prose sync only if accepted; support score changes are not recommended. | Medium-High | Callback explicitly excluded support edits and accepted `by-class/SimpleHelpPane.md` / `by-file/HelpPanes.md` as already directionally correct. | `by-class/SimpleHelpPane.md` and `by-file/HelpPanes.md` -> no edit by callback scope. | not-applicable | excluded-with-reason |
| C017 | Raw-helper, broad-parent, SimpleHelpPane2, blank-C++, and unrelated family alternatives are rejected. | High | Vtable route, exact child split, generated emission, and helper analysis support UID00048H as SimpleHelpPane mouse-down close handler; no evidence connects MapPane, Crasher, Monitor, zlib, LodePNG, or other unrelated families. | Target -> Source-Quality Notes. | reject-invalid | applied |
| C018 | Generated HelpPanes.cpp is evidence only and must not be manually edited. | High | Generated output header refreshed to validator command `000000007064` and still emits UID00048H body; no generated manual edit was performed. | `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` -> read-only generated freshness observation only. | not-applicable | applied |
| C019 | The discarded stale `find_bytes` wrapper call is not evidence. | High | Singular `pattern` parameter returned an MCP schema error; the check was rerun successfully with `patterns`. | Report-only Evidence Standards note; no by-* destination. | not-applicable | excluded-with-reason |
| C020 | Pre-report tracker state with report count `0` is historical once this report exists. | High | `goal.md` assignment and generated tracker showed no exact UID00048H report before this file was created. | Report `Supporting Research` historical context only; no target-doc destination. | historicalize | applied |

## Positive Evidence Summary

- Current MCP server health is `ok` in session `supervisor_recovery_20260705`, with imagebase `0x400000`.
- `lookup_funcs` proves `0x004c7440` is a function start and the exact target size is `0x10`.
- The instruction sequence is short, stable, and source-shaped: adjust `this`, call shared close helper, set return value false, return.
- `basic_blocks` reports one basic block and no CFG complexity.
- The only target xref is the expected data xref at `0x0061ac64`.
- `find_bytes "40 74 4C 00"` returns exactly that vtable slot and no other absolute pointer-pattern matches.
- The raw body and wildcarded body shape each match only `0x004c7440`.
- The boundary bytes show two `0xcc` bytes immediately before the target and the next function starting immediately at `0x004c7450`.
- The generated HelpPanes output already emits the formal body under UID00048H.

## IDA MCP Facts

Current target facts:

- `lookup_funcs(0x004c743e)` -> not a function start.
- `lookup_funcs(0x004c7440)` -> `sub_4C7440`, size `0x10`.
- `lookup_funcs(0x004c7450)` -> `sub_4C7450`, size `0x41`.
- `lookup_funcs(0x004c74a0)` -> `sub_4C74A0`, size `0x10`.
- `lookup_funcs(0x00544690)` -> `sub_544690`, size `0x1d`.
- `lookup_funcs(0x005446ad)` -> not a function start.

Target decompile:

```c
char __thiscall sub_4C7440(char *this, int a2, int a3, int a4)
{
  sub_544690(this - 164);
  return 0;
}
```

Target disassembly:

```asm
0x004c7440  add ecx, 0FFFFFF5Ch
0x004c7446  call sub_544690
0x004c744b  xor al, al
0x004c744d  retn 0Ch
```

Target body bytes:

```text
81 c1 5c ff ff ff e8 45 d2 07 00 32 c0 c2 0c 00
```

Boundary bytes from `0x004c7438`:

```text
10 00 8b e5 5d c3 cc cc
81 c1 5c ff ff ff e8 45 d2 07 00 32 c0 c2 0c 00
55 8b ec 8b 45 08 8a 40 04 3c 01 74 1e 3c 04 74
```

Interpretation:

- `0x004c7438-0x004c743e` is the tail of the preceding paint-frame function.
- `0x004c743e-0x004c7440` contains two `0xcc` bytes.
- `0x004c7440-0x004c7450` is the full UID00048H body.
- `0x004c7450` begins the next function, the SimpleHelpPane timer handler.

Helper facts for `sub_544690`:

- Recovered prototype: `void __thiscall(_BYTE *this)`.
- Body checks byte `[ecx+0xF4]`; if not already set, it sets that byte and calls `sub_469180` through `dword_67A74C`.
- The helper has many callers, including the SimpleHelpPane mouse/key close-handler siblings.
- This is shared close/dismiss behavior, not UID00048H-owned source code.

## Function / Child Inventory

Relevant SimpleHelpPane child inventory:

| Range | Current child | Current role |
|---|---|---|
| `0x004c6f90-0x004c7287` | UID00048E | `SimpleHelpPane` constructor |
| `0x004c7310-0x004c743e` | UID00048G | paint/frame source body |
| `0x004c7440-0x004c7450` | UID00048H | mouse-down close handler |
| `0x004c7450-0x004c7491` | UID00048I | timer event handler |
| `0x004c74a0-0x004c74b0` | UID00048J | key-press close handler |

UID00048H should remain the exact child for `0x004c7440-0x004c7450`; the parent UID00016S should remain a non-emitting split index.

## Direct Xref / Caller Inventory

Target xrefs:

- `xrefs_to(0x004c7440)` -> one data xref at `0x0061ac64`.
- `analyze_function(0x004c7440)` -> callers empty.
- There are no direct code callers reported by IDA.

Slot/base xrefs:

- `xrefs_to(0x0061ac60)` -> `0x004c7019`, `0x004c72cb`, `0x004ce5a2`.
- `xrefs_to(0x0061ac64)` -> zero.
- `xrefs_to(0x0061ac28)` -> zero.
- `xrefs_to(0x0061ac30)` -> `0x004c700f`, `0x004c72c1`, `0x004ce598`.
- `xrefs_to(0x004c74a0)` -> one data xref at `0x0061ac38`.

Pointer-pattern checks:

- `find_bytes "40 74 4C 00"` -> one match at `0x0061ac64`.
- `find_bytes "40 74 0C 00"` -> zero matches.
- `find_bytes` for exact target body -> one match at `0x004c7440`.
- `find_bytes` for wildcarded close-handler shape -> one match at `0x004c7440`.

## Documentation Evidence And IDA Status

Current target documentation already captures the essential behavior:

- The item summary says the handler closes/dismisses and returns false.
- The formal C++ is already source-shaped and valid.
- The target metadata already routes through `CANONICAL_OWNER:0000D6` and `EMITTER_UIDS:0000D6`.

The target documentation is missing current report-level details:

- MCP session `supervisor_recovery_20260705`, server `ok`, imagebase `0x400000`.
- Function-start proof at `0x004c7440` and adjacent non/next function status.
- Exact vtable slot xref at `0x0061ac64`.
- No direct code callers.
- No xrefs to the slot address itself.
- Pointer-pattern and body-pattern search results.
- Boundary bytes around the split.
- Helper behavior from `sub_544690`.
- Explicit score rationale for `88/92` and the remaining cap below `95+`.

## Ranked Ownership Analysis

1. `SimpleHelpPane::OnMouseDown` under UID0000D6 / HelpPanes is the best ownership route.

Evidence:

- The target is an exact SimpleHelpPane child in the current documentation.
- The function pointer is in the SimpleHelpPane vtable region and the vtable base is referenced from SimpleHelpPane constructor/destructor paths.
- The function is an event callback-shaped method with `retn 0Ch`, a `this` adjustment, and a boolean return in `al`.
- Sibling child pages around this range map constructor, paint, timer, and key-event behavior for the same class family.

2. A standalone raw helper is rejected.

Reason:

- The function is vtable-addressed and receives a `this` context. It is not called as a direct shared utility.
- The actual shared helper is `sub_544690`, not UID00048H.

3. Moving the body to the broad parent UID00016S is rejected.

Reason:

- UID00016S is the non-emitting split index.
- UID00048H is already the exact source-emitting child.

4. Moving the body to SimpleHelpPane2 or another pane class is rejected.

Reason:

- The vtable/data xref route and neighboring children align with SimpleHelpPane, not SimpleHelpPane2.
- No contradictory current MCP evidence points to another class.

5. Blanking the C++ or treating this as unreconstructable is rejected.

Reason:

- The code has a concrete and source-shaped behavior.
- The generated file already emits it.
- The only open questions are original spelling and final declaration details, not body reconstructability.

## Source Placement

Recommended source placement remains:

- File route: `NexusTK/ui/controls/HelpPanes.cpp`
- Class route: `SimpleHelpPane`
- Method route: `SimpleHelpPane::OnMouseDown`
- Owner/emitter route: `0000D6`

No path change is recommended.

## Range / Split / Padding / Reclassification Analysis

No split change is recommended.

Boundary proof:

- `0x004c743e-0x004c7440` contains two `0xcc` padding bytes before UID00048H.
- `0x004c7440-0x004c7450` is the whole UID00048H function.
- `0x004c7450` begins the next function `sub_4C7450`, documented as `SimpleHelpPane::OnTimerEvent`.

No reclassification is recommended:

- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:0000D6`.
- Keep `EMITTER_UIDS:0000D6`.
- Keep blank optional emitter position.
- Keep `Nested:0`.
- Keep the existing formal C++ body.

## Negative Evidence Summary

The following facts cap confidence but do not overturn the current reconstruction:

- IDA does not provide the original source symbol `SimpleHelpPane::OnMouseDown`.
- IDA does not recover the final source event type from this body because the arguments are unused.
- IDA reports no direct code callers, only the vtable data xref.
- The slot address `0x0061ac64` itself has no xrefs.
- The source-facing helper spelling `Close()` is an abstraction over raw helper `sub_544690`; the helper name is not proven by IDA.
- The broad parent UID00016S remains non-emitting; it should not absorb this child body.

Rejected alternatives:

- Raw `sub_4C7440` standalone helper.
- UID00016S as the emitting source page.
- SimpleHelpPane2 or other adjacent pane classes.
- Blank C++ due to unused event argument.
- Treating `sub_544690` as the method body rather than the callee.
- Any move into unrelated image, compression, MapPane, Crasher, Monitor, zlib, or LodePNG support areas; no current evidence connects UID00048H to those families.

## IDA Rename / Type / Comment Recommendations

Report-only recommendation for supervisor/IDA owner consideration:

- Optional function rename: `sub_4C7440` -> `SimpleHelpPane_OnMouseDown` or project-preferred equivalent.
- Optional function comment: `SimpleHelpPane vtable mouse-down close handler; adjusts subobject this, calls shared close/dismiss helper, returns false.`
- Do not force IDA type changes from this report alone; the exact `PaneEvent` source type/name remains inferred.

No IDA database edits were performed.

## First-Draft C++ Recommendation

Keep the current formal `RECONSTRUCTION_CPP CODE` block unchanged:

```cpp
bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)
{
    Close();
    return false;
}
```

Rationale:

- `sub_544690(this - 164)` is source-shaped as `Close()` for this class page.
- `xor al, al` proves false return.
- The event object is unused, which is valid for a source event callback.
- The current C++ is already emitted by the generator and matches the machine-code behavior.

## Final Recommendation

Accept a targeted documentation update for UID00048H after supervisor review:

- Keep ownership/emitter metadata unchanged.
- Keep the formal C++ block unchanged.
- Raise `COMPLETION` to `88`.
- Raise `CONFIDENCE` to `92`.
- Add the current MCP facts and caveats listed in this report to the target page.
- Optionally sync support prose only, with no support score changes by default.

Do not execute lifecycle/report archive commands from the B-agent side. Supervisor owns report execution/archive.

## Recommended Target Doc Changes

For `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`, recommend:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000D6`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000D6`.
- Keep the blank optional emitter position.
- Keep `Nested:0`.
- Keep the formal C++ body unchanged.
- Add current MCP evidence:
  - Session `supervisor_recovery_20260705`, server status `ok`, imagebase `0x400000`.
  - `lookup_funcs`: `0x004c7440` is `sub_4C7440`, size `0x10`; `0x004c743e` is not a function start; `0x004c7450` is `sub_4C7450`, size `0x41`.
  - One-block function with no CFG complexity.
  - Decompile/asm calls `sub_544690(this - 164)`, returns `0`, and compiles source-facing as `Close(); return false;`.
  - Direct callees: only `sub_544690`.
  - Direct code callers: none.
  - `xrefs_to(0x004c7440)`: exactly one data xref at `0x0061ac64`.
  - `xrefs_to(0x0061ac64)`: zero slot-address xrefs.
  - `xrefs_to(0x0061ac60)`: three SimpleHelpPane vtable-base refs from constructor/destructor paths.
  - `find_bytes "40 74 4C 00"`: exactly one match at `0x0061ac64`.
  - `find_bytes "40 74 0C 00"`: zero matches.
  - Exact target bytes and wildcarded close-handler shape each match only `0x004c7440`.
  - Boundary bytes: two `0xcc` bytes at `0x004c743e-0x004c7440`, exact target body at `0x004c7440-0x004c7450`, and the timer handler begins immediately at `0x004c7450`.
  - Helper `sub_544690` is shared close/dismiss support that marks byte `[ecx+0xF4]` and queues the object through `dword_67A74C`/`sub_469180`.
  - Explicit `88/92` rationale and cap below `95+`: no original source symbol, final event type/name still inferred, and no direct runtime caller beyond vtable data evidence.

## Recommended Support Doc Changes

Support docs are already directionally correct. If this report is accepted, sync prose only unless the supervisor finds a concrete metadata reason.

Recommended support prose sync:

- `by-class/SimpleHelpPane.md`: State that UID00048H now has current MCP confirmation as the source-empty-argument mouse-down close handler, emitted through `SimpleHelpPane::OnMouseDown`; `OnMouseDown`, `PaneEvent`, and `Close()` remain source-facing/inferred names, while `sub_4C7440` and `sub_544690` remain raw IDA aliases.
- `by-file/HelpPanes.md`: State that UID00048H is an exact source-emitting child in `HelpPanes.cpp` with vtable-only reachability at `0x0061ac64`, no direct code callers, and no support score change recommended.

No support score changes are recommended by default.

No recommended edits for unrelated support areas or generated/coverage files.

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000D6` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000D6` unchanged
- Optional emitter position unchanged and blank
- `Nested:0` unchanged

Score rationale:

- Completion improves because the C++ body is already source-shaped, the range is exact, the vtable route is exact, helper behavior is verified, and generated output already emits the method.
- Confidence improves because current MCP independently confirms the function start, bytes, block count, callee, xrefs, slot evidence, and boundary.
- The score remains below `95+` because the original source symbol/path is not present in IDA, the source event type/name is inferred from context rather than proven by in-body field use, and runtime reachability is vtable-data based rather than a direct caller list.

## Open Questions With Attempted Resolution

Question: Is the method definitely `OnMouseDown` rather than a raw helper?

Resolution: The method name is source-facing/inferred, not symbol-proven. The vtable slot, neighboring child inventory, source docs, and event-handler shape support keeping `OnMouseDown`.

Question: Is `PaneEvent &event` proven by this function?

Resolution: No. The body does not read the arguments. The event type comes from the class/event-handler family and sibling documentation. This is a confidence cap, not a body blocker.

Question: Is `Close()` the exact original helper spelling?

Resolution: Not proven. The raw callee is `sub_544690`, which implements close/dismiss behavior. `Close()` is the correct source-facing abstraction for the current C++ block, but exact spelling remains a cap.

Question: Is there any direct runtime caller?

Resolution: No direct code caller was found. IDA reports only the vtable data xref at `0x0061ac64`, with base vtable refs from constructor/destructor paths.

Question: Does this require support score changes?

Resolution: No. The class/file support docs already carry the correct SimpleHelpPane child route and remaining confidence caps. Only optional prose sync is recommended.

## Validator Results

Callback scoped validator was run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md](00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- command_id: `000000007064`
- command_timestamp: `2026-07-05T13:02:54-04:00`
- exit code: `0`
- ok count: `1`
- scanned markdown files: `1`
- completion_update: `1`
- confidence_update: `1`
- generated_refresh: `deferred`
- generated_refresh_command_id: `000000007064`
- generated_refresh_timestamp: `2026-07-05T13:02:54-04:00`
- validator side effect: `project-level/-auto-completion-stats.md` projected path completion section updated by the scoped validator.

Support validators were not run because the callback explicitly excluded support doc edits.

Read-only queue status was checked after the deferred refresh:

- command_id: `000000007065`
- command_timestamp: `2026-07-05T13:03:11-04:00`
- queued jobs: `0`
- processing jobs: `0`
- queued generated refresh jobs: `0`
- processing generated refresh jobs: `0`

No `execute_report`, lifecycle/archive command, registry lifecycle command, report-move command, dry-run/probing execute variant, generated manual edit, coverage edit, validator-state edit, or IDA DB edit was performed.

## Generated Refresh State

`auto-generated/NexusTK/ui/controls/HelpPanes.cpp` was inspected read-only after validation.

- Header `validator-command-id`: `000000007064`
- Header `validator-refreshed-at`: `2026-07-05T13:02:54-04:00`
- Header freshness equals the scoped validator command metadata.
- UID00048H generated block now reports `Completion:88 | Confidence:92`.
- UID00048H still emits:

```cpp
bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)
{
    Close();
    return false;
}
```

## Changed Files

Callback manual edits:

- `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md`
- `tools/leaser/Agents/Agent-B002/research/00048H-SimpleHelpPaneOnMouseDown-source-quality.md`

Validator-generated side effects observed, not manually edited:

- `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`
- `project-level/-auto-completion-stats.md`

No support by-* docs, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, report execution/archive locations, or IDA DB files were manually edited.

## Implementation Tracking Checklist

Callback implementation checklist:

- [x] Lease `by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` only when ready to edit it. Proof: no active leases before edit; B002 lease acquired at `2026-07-05T17:02:13Z`, expiring `2026-07-05T17:07:13Z`.
- [x] Target metadata for C014/C015: changed `COMPLETION:85` to `COMPLETION:88`; changed `CONFIDENCE:90` to `CONFIDENCE:92`; kept `CANONICAL_OWNER:0000D6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D6`, blank optional emitter position, and `Nested:0` unchanged.
- [x] Target C++ retention for C003/C005/C013: preserved the formal multiline `RECONSTRUCTION_CPP CODE` block as `bool SimpleHelpPane::OnMouseDown(const PaneEvent &event)` with `Close(); return false;`; did not replace it with raw `sub_4C7440` or blank C++.
- [x] Target provenance/evidence prose for C001-C004: added MCP session `supervisor_recovery_20260705`, server `ok`, imagebase `0x400000`, exact `lookup_funcs` boundaries, one-block CFG, and close/false-return decompile/asm facts to `Evidence And Behavior`.
- [x] Target xref/vtable prose for C006-C010: added no direct code callers, one data xref at `0x0061ac64`, zero slot-address xrefs, SimpleHelpPane vtable-base refs, exact VA pointer-pattern match, and zero RVA-style pointer-pattern matches to `Xrefs And Boundary Detail`.
- [x] Target byte/range prose for C011/C012: added exact/wildcard body-pattern uniqueness and boundary bytes showing two `0xcc` bytes before `0x004c7440`, full target body through `0x004c7450`, and the timer handler beginning immediately at `0x004c7450`.
- [x] Target helper/rejected-alternative prose for C005/C017: preserved `sub_544690` as shared close/dismiss helper behind source-facing `Close()` and rejected raw-helper, broad-parent, SimpleHelpPane2, blank-C++, MapPane, Crasher, Monitor, zlib, LodePNG, and other unrelated-family alternatives in `Source-Quality Notes`.
- [x] Target score rationale for C015: stated that current evidence supports `88/92`, not `95+`, because original source symbol, final event type/name, and direct runtime caller/reachability remain unproven.
- [x] Optional support sync for C016 was excluded by callback scope. Proof: `by-class/SimpleHelpPane.md` was not edited; callback stated support docs were already directionally correct and no support docs should be edited.
- [x] Optional support sync for C016 was excluded by callback scope. Proof: `by-file/HelpPanes.md` was not edited; callback stated support docs were already directionally correct and no support docs should be edited.
- [x] Generated-output expectation for C013/C018: did not manually edit `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`; inspected it read-only after validator refresh and confirmed UID00048H still emits `SimpleHelpPane::OnMouseDown` with `Close(); return false;` and score metadata `88/92`.
- [x] Historical/report-only dispositions for C019/C020: kept the stale singular-`pattern` MCP error as non-evidence in report-only evidence standards and kept pre-report tracker/report-count facts historical, not current target truth.
- [x] Ran the scoped target validator from `source-3/project-documentation` after target edits:

> Executable block R002 was removed from this report and preserved verbatim in [00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md](00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Validator result recorded: command id `000000007064`, timestamp `2026-07-05T13:02:54-04:00`, exit code `0`, ok count `1`.
- [x] `by-class/SimpleHelpPane.md` support validator not run; support doc was not edited by explicit callback scope.

> Executable block R003 was removed from this report and preserved verbatim in [00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md](00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] `by-file/HelpPanes.md` support validator not run; support doc was not edited by explicit callback scope.

> Executable block R004 was removed from this report and preserved verbatim in [00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md](00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Recorded validator command, command id, timestamp, exit code, ok count, generated refresh, and read-only queue status in `## Validator Results`; did not run `execute_report` or any lifecycle/archive/report-move/dry-run/probing execute variant.
- [x] Released acquired target lease immediately after the edit/validator/generated-freshness batch. Proof: `python .\tools\leaser\leaser.py B002 unlease by-memory/0x004c7440-0x004c7450.SimpleHelpPaneOnMouseDown.md` returned success, and the post-release current lease report listed no B002 lease.
- [x] Updated this report's `## Claim And Incorporation Ledger` verification state for every accepted claim to `applied`, `already-present`, or `excluded-with-reason`.
- [x] Updated this checklist with callback proof and updated `## Changed Files` with manual edits plus validator-generated side effects observed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000007072","destination_path":"executed-b-agent-research/B002/00048H-SimpleHelpPaneOnMouseDown-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00048H-SimpleHelpPaneOnMouseDown-source-quality.md","timestamp":"2026-07-05T13:09:07-04:00","uid":"00048H"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00048H-SimpleHelpPaneOnMouseDown-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00048H-SimpleHelpPaneOnMouseDown-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00048H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
