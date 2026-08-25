** TARGET-REPORT-UID:00015W **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B-Agent Source-Quality Report: [UID:00015W] GeneralPurposePanelChildAccessors

Agent: Agent-B011
Assignment: implementation callback after Gate 1 approval
Target: `source-3/project-documentation/by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00015W-GeneralPurposePanelChildAccessors-source-quality.md`

## Finalized Report / Current Recommendation

Keep [UID:00015W] as a source-authored `GeneralPurposePanel` method cluster, owned and emitted by [UID:00005Q] `GeneralPurposePanel` through [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`:

```text
CANONICAL_OWNER:00005Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005Q
```

Implemented metadata:

```text
COMPLETION:88
CONFIDENCE:91
```

Final disposition: first-draft formal C++ is now implemented in the target. Current MCP evidence confirms exact helper bodies, current generated output has compatible class declarations and field names, PaneCore support resolves the inherited virtual slot as `Pane::InvalidateRect`, and the stale `SpellOneArgInputPane` route is contradicted by class RTTI, constructor field layout, generated GeneralPurposePanel output, and broad caller behavior.

The most important precision point is that `GetChildPaneByIndex` performs only an upper-bound signed comparison. Do not add a defensive `index < 0` guard in the formal code unless a later source-authenticity pass explicitly accepts that behavior change.

## Supporting Research

Instruction and workflow sources read:

- Project-level skill: `ntk-b-agent-workflow`.
- Agent goal: `tools/leaser/Agents/Agent-B011/goal.md`.
- Required B-agent report template and score-blocker audit standard.

Target/support docs checked:

- [UID:00015W] `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`.
- [UID:0000JQ] `by-file/GeneralPurposePanel.md`.
- [UID:00005Q] `by-class/GeneralPurposePanel.md`.
- [UID:00015V] `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`.
- [UID:00015X] `by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md`.
- [UID:0003A2] `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`.
- [UID:0000A2] `by-class/Pane.md` and Pane vtable/support pages for slot `+0x20`.
- [UID:0000SW] `by-global/g_useEpfAssets.md`.
- [UID:0000R0] `by-global/g_pGeneralPurposePanel.md` and [UID:00028X] storage page.

Prior reports and generated output checked:

- `executed-b-agent-research/B003/00015V-GeneralPurposePanel-source-quality.md`.
- `executed-b-agent-research/B007/0003A2-ScreenPanePaletteVisibleTilesRedrawRaw-source-quality.md`.
- B003/B006/B008 AboveFrame reports for `g_pGeneralPurposePanel->m_activeChildIndex + 5`.
- A002 notes and Rule 26 tracker entries mentioning UID00015W/UID00015V/UID0003A2.
- `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- `auto-generated/-ag-memory-coverage.md`, `-ag-coverage-report-by-memory.md`, and `-ag-research-tracker.md`.

## Target

- UID: `00015W`
- Path: `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`
- Current metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00005Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005Q`
- Current formal C++: populated with the accepted `GetChildPaneByIndex`, `GetActiveChildPane`, and `DispatchActiveChildRefresh` bodies.
- Current generated state: `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` refreshed to validator command `000000007975` and now emits UID00015W method bodies instead of an empty emitter marker.

## Current Target State

The current target page carries the correct owner/emitter route, reconstructable state, populated formal C++, and source-quality notes for the three helpers:

- `0x004b85f0-0x004b8616/17`: child lookup by index, EPF/current mode exposing seven children and legacy exposing four.
- `0x004b8620-0x004b862f/30`: active-child getter using `this[8]` / offset `+0x20`.
- `0x004b8630-0x004b8643/44`: active-child virtual refresh/invalidation dispatch.

The former implementation blockers are resolved for first-draft C++: exact ranges/padding, public method spellings, field names, explicit `g_useEpfAssets == 1`, upper-bound-only index behavior, the `m_activeChildIndex == -1` sentinel, `Pane::InvalidateRect(NULL)`, and rejected stale `SpellOneArgInputPane` ownership are all recorded in the target.

## IDA MCP Facts

Supervisor-provided active database/session used:

```text
b007_uid0002oc_20260708
```

Fresh health/provenance:

- `idb_list`: one active NexusTK session, `b007_uid0002oc_20260708`, active true, analysis not running.
- `server_health` on that database: `status: ok`, module `NexusTK.exe`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`.
- MCP tools used: `initialize`, `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `decompile`, `disasm`, `get_bytes`, `basic_blocks`, `callees`, `xrefs_to`, `xref_query`, `entity_query`, `search_structs`, and `type_query`.
- Prohibited MCP/process operations were not used: no `idb_open`, no process start/stop/restart/kill, no lifecycle/archive/execute command.

## Function / Child Inventory

Fresh MCP `lookup_funcs` and `entity_query` confirm the relevant function inventory:

| Address query | Current IDA function | Size | Boundary result |
| --- | --- | ---: | --- |
| `0x004b85f0` | `sub_4B85F0` | `0x27` | Function covers `0x004b85f0-0x004b8617`; `0x004b8617` is not a function. |
| `0x004b8620` | `sub_4B8620` | `0x10` | Function covers `0x004b8620-0x004b8630`. |
| `0x004b8630` | `sub_4B8630` | `0x14` | Function covers `0x004b8630-0x004b8644`; `0x004b8644` is not a function. |
| `0x004b8650` | `sub_4B8650` | `0x1d3` | Next GeneralPurposePanel helper begins after `0xcc` padding. |

Fresh `get_bytes` confirms padding:

- `0x004b8617-0x004b8620`: nine `0xcc` bytes.
- `0x004b8644-0x004b8650`: twelve `0xcc` bytes.
- Preceding destructor tail ends before `0x004b85f0` with `0xcc` padding.

## Direct Xref / Caller Inventory

Fresh MCP `xrefs_to` / `xref_query`:

- `0x004b85f0`: 50 direct code refs. Representative caller functions include `0x004c78e0`, `0x004c82d0`, `0x0050feb0`, `0x00514640`, `0x00568cb0`, `0x005a3e30`, `0x005a76c0`, `0x005aa480`, `0x005aac80`, `0x005abda0`, `0x005adfd0`, `0x005ae380`, `0x005aed40`, `0x005b0810`, `0x005b0b50`, `0x005b0e30`, `0x005b10c0`, `0x005b1310`, `0x005b7a20`, `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, `0x005b8030`, `0x005b8100`, and `0x005ba4a0`.
- `0x004b8620`: four direct code refs at `0x0049e5d5`, `0x005698a8`, `0x005a6d30`, and `0x005a6e33`.
- `0x004b8630`: two direct code refs at `0x00556e06` in function `0x00556d50` and `0x005593fc` inside the ScreenPane palette refresh raw helper.

Fresh MCP `callees` reports no modeled direct callees for all three functions. The third helper's vtable call is indirect and does not appear as a modeled callee.

## Documentation Evidence And IDA Status

Fresh IDA symbol/type state:

- The three target helpers are still named `sub_4B85F0`, `sub_4B8620`, and `sub_4B8630`; no IDA-applied names exist for `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, `RefreshActiveChild`, `m_childPanes`, or `m_activeChildIndex`.
- `entity_query` for `GeneralPurposePanel` finds RTTI/vtable names, including `??_7GeneralPurposePanel@@6B@` at `0x0061a888` and `??_7GeneralPurposePanel2@@6B@` at `0x0061a898`.
- `entity_query` for `SpellOneArgInputPane` finds only its own RTTI/vtable/data names in the spell-input area, not evidence tying UID00015W to that class.
- `search_structs` and `type_query` find no current UDT/type record for `GeneralPurposePanel` or `SpellOneArgInputPane`. The field names are accepted documentation/generator names, not imported IDA type members.

Generated output is current with the implementation callback: the refreshed `GeneralPurposePanel` output lists the public methods `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, and `SwitchActiveTab`, the private fields `m_childPanes[7]` and `m_activeChildIndex`, and the UID00015W method bodies.

Generated freshness:

- File: `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`
- `validator-command-id: 000000007975`
- `validator-refreshed-at: 2026-07-08T16:20:53-04:00`
- `validator-refresh-source: deferred-generated-refresh`
- UID00015W currently appears as `Completion:88 | Confidence:91` with emitted method bodies, not an empty emitter marker.

## Range / Split / Padding / Reclassification Analysis

No split repair is needed for UID00015W. Fresh IDA boundaries match the current child cluster:

- Half-open function range `0x004b85f0-0x004b8617` is represented by the target path's inclusive-style `0x004b85f0-0x004b8643` cluster.
- Half-open function range `0x004b8620-0x004b8630` follows after pure `0xcc` padding.
- Half-open function range `0x004b8630-0x004b8644` follows contiguously and ends before pure `0xcc` padding.

The body is not compiler-generated glue, a thunk island, data, padding, or vtable support. It is three source-shaped class methods over the same receiver, fields, global mode byte, and child array.

## Heuristic / Inference Reanalysis And Validation

### Child-array/member naming

Resolution: use `Pane* m_childPanes[7]`.

Validation:

- Constructor/support docs and generated output agree on seven child pointer slots at object offsets `+0x04..+0x1c`.
- Fresh decompile/disassembly for `0x004b85f0`, `0x004b8620`, and `0x004b8630` all index `this[index + 1]` / `[ecx+eax*4+4]`.
- Generated `GeneralPurposePanel.cpp` already declares `Pane* m_childPanes[7]`.

### Active child index naming

Resolution: use `int m_activeChildIndex`.

Validation:

- Fresh decompile/disassembly for `0x004b8620` and `0x004b8630` read `this[8]` / `[ecx+20h]`.
- The field uses sentinel `-1`.
- GeneralPurposePanel class/global/AboveFrame docs already accept `m_activeChildIndex`; FrameChrome derives dynamic frame id as `m_activeChildIndex + 5`.
- Generated `GeneralPurposePanel.cpp` already declares `int m_activeChildIndex`.

### Public method spellings

Resolution:

- `Pane* GeneralPurposePanel::GetChildPaneByIndex(int index)`
- `Pane* GeneralPurposePanel::GetActiveChildPane()`
- `void GeneralPurposePanel::DispatchActiveChildRefresh()`

Validation:

- Current generated `GeneralPurposePanel.cpp` declares these exact methods.
- UID0003A2 and ScreenPane support docs now use `DispatchActiveChildRefresh`.
- B003's `RefreshActiveChild` alternate is behaviorally good but has been superseded by B007/Rule 26 naming consistency and the current generated declaration.

### Inherited virtual refresh/update slot naming

Resolution: use `Pane::InvalidateRect(NULL)` for the slot `+0x20` dispatch in the C++ body.

Validation:

- Fresh disasm for `0x004b8630`: loads active child, `push 0`, loads vtable, calls `[eax+20h]`.
- `by-class/Pane.md` and Pane vtable support identify primary vtable slot `+0x20` / `0x00621a08 -> 0x00544800` as `Pane::InvalidateRect`.
- Legacy by-memory report records source signature `void Pane::InvalidateRect(int* rect)`, so `NULL` is the correct argument form for the observed zero push.

### Stale SpellOneArgInputPane generated ownership

Resolution: reject.

Validation:

- Fresh IDA class names show separate GeneralPurposePanel RTTI/vtables around `0x0061a888` and SpellOneArgInputPane RTTI/vtables in the spell-input area; no IDA symbol route connects UID00015W to SpellOneArgInputPane.
- GeneralPurposePanel constructor/support docs establish a seven-child side-panel shell and `g_pGeneralPurposePanel` lifecycle.
- Current generated output emits UID00015W under `NexusTK/ui/panels/GeneralPurposePanel.cpp`, not a spell-input file.
- Broad UID00015W callers are side-panel/gameplay UI consumers, not one spell-input virtual dispatch.

### EPF-vs-legacy child-count logic

Resolution: preserve exact binary logic with an explicit `g_useEpfAssets == 1` test selecting `7` children, otherwise `4`.

Validation:

- Fresh decompile for `0x004b85f0` reads `byte_66DA97 == 1`, then compares the index to `7` or `4`.
- `by-global/g_useEpfAssets.md` identifies `byte_66DA97` as the project-wide current EPF/high-layout versus legacy selector.
- Existing target/support docs already identify seven current-mode children and four legacy children.

### Upper-bound-only index check

Resolution: formal C++ must not add `index >= 0`.

Validation:

- Fresh disassembly for `0x004b85f0` uses `cmp eax, 7` or `cmp eax, 4`, followed by signed `jge` to the null return.
- A negative signed index is not rejected by this body and would index before `m_childPanes[0]`.
- The current code callers appear to pass controlled nonnegative UI action indices, so this is probably source precondition behavior rather than an omitted decompiler lower-bound.

### Broad caller set

Resolution: broad callers support a shared `GeneralPurposePanel` public helper, not a narrow owner move.

Validation:

- `0x004b85f0` has 50 direct code refs from multiple UI/gameplay clusters.
- `0x004b8620` has four active-child refs.
- `0x004b8630` has ScreenPane/ScreenPane-helper refs.
- This call shape is exactly what a shared side-panel shell accessor cluster should have.

### Source placement through GeneralPurposePanel

Resolution: source placement is [UID:00005Q] `GeneralPurposePanel`, emitted through [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`.

Validation:

- Current target owner/emitter already use `00005Q`.
- Generated output places class declarations under `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- Aggregate [UID:00015V] and file/class support route GeneralPurposePanel and GeneralPurposePanel2 through `GeneralPurposePanel.cpp`.

## Evidence Standards Used

This report applies the B-agent source-quality standard:

- Prefer current IDA MCP for exact ranges, decompilation, disassembly, xrefs, and current symbol/type state.
- Use generated output as source-shape evidence only after confirming it does not contradict IDA behavior.
- Treat public method/member names without recovered symbols as inferred source-facing names and cap score accordingly.
- Do not promote code that changes observable binary behavior, including adding a lower-bound check absent from the helper.
- Keep dependencies such as PaneCore, ScreenPane, FrameChrome, `g_useEpfAssets`, and SpellInputPanes as dependencies/rejected owners rather than blurring ownership.

## Evidence Checked

Fresh MCP evidence:

- `server_health`: ok, Hex-Rays ready.
- `lookup_funcs`: exact functions and boundaries around `0x004b85f0`, `0x004b8620`, `0x004b8630`, and neighbors.
- `decompile`: all three target helpers with address comments.
- `disasm`: all three target helpers with instruction counts.
- `get_bytes`: target function bytes and surrounding `0xcc` padding.
- `basic_blocks`: six blocks for `0x004b85f0`, three blocks for `0x004b8620`, three blocks for `0x004b8630`.
- `callees`: no modeled direct callees for all three helpers.
- `xrefs_to` / `xref_query`: 50, 4, and 2 direct refs respectively.
- `entity_query`, `search_structs`, `type_query`: current IDA symbol/type status and negative UDT/member evidence.

Local documentation/generated evidence:

- Current target/support docs and executed reports listed in Supporting Research.
- Current generated `GeneralPurposePanel.cpp` with validator command id `000000007975`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID00015W boundaries are correct as three helpers plus padding. | High | `lookup_funcs`, `get_bytes`, and `basic_blocks` confirm the three function bodies and `0xcc` padding. | Target `Current Target State` and range notes. | incorporate | applied |
| C002 | `0x004b85f0` is `GeneralPurposePanel::GetChildPaneByIndex`. | High | Decompile/disasm shows EPF/legacy child-count compare and child-array load. | Target formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied |
| C003 | `GetChildPaneByIndex` must not add a negative-index guard. | High | Signed `jge` follows only the upper-bound compare; no lower-bound test exists. | Target formal C++ and source-quality note. | incorporate | applied |
| C004 | `0x004b8620` is `GeneralPurposePanel::GetActiveChildPane`. | High | Reads `this[8]`, tests sentinel `-1`, returns `this[index + 1]`. | Target formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied |
| C005 | `0x004b8630` dispatches active-child invalidation/refresh. | High | Reads `this[8]`, tests `-1`, loads active child, pushes `0`, calls vtable slot `+0x20`. | Target formal `RECONSTRUCTION_CPP CODE` block. | incorporate | applied |
| C006 | `m_childPanes[7]` is the target field name to use. | High | Constructor/support docs and generated class declaration agree on seven child pointer slots. | Target formal C++ and target source-quality note. | incorporate | applied |
| C007 | `m_activeChildIndex` is the target field name to use. | High | Offset `+0x20`, generated declaration, and FrameChrome support all use this name. | Target formal C++ and target source-quality note. | incorporate | applied |
| C008 | `DispatchActiveChildRefresh` is the current project method spelling. | High | Current generated declaration and B007 ScreenPane report use this spelling. | Target formal C++ and target source-quality note. | incorporate | applied |
| C009 | Active-child slot `+0x20` should be represented as `Pane::InvalidateRect(NULL)`. | High | Pane class/vtable docs identify slot `+0x20` as `Pane::InvalidateRect`; disasm pushes zero. | Target formal C++ and target source-quality note. | incorporate | applied |
| C010 | `SpellOneArgInputPane` ownership is stale generated pollution. | High | IDA RTTI separation, GeneralPurposePanel source route, and broad caller set reject spell-input ownership. | Target historical/generated-owner caveat. | reject-stale | applied |
| C011 | `byte_66DA97` must be tested as `g_useEpfAssets == 1`, not generic truthiness. | High | Fresh decompile/disasm shows `cmp byte_66DA97, 1`; no proof exists that other nonzero values are equivalent. | Target formal C++ and target source-quality note. | incorporate | applied |
| C012 | Current owner/emitter/reconstructable metadata is correct. | High | Current target metadata, generated GeneralPurposePanel output, and support docs all route UID00015W through [UID:00005Q]. | Target metadata headers. | already-present | already-present |
| C013 | Score should become `88/91` after formal C++ insertion. | Medium-high | All named blockers are resolved; exact original public/member spellings remain inferred. | Target metadata headers. | incorporate | applied |
| C014 | `by-class/GeneralPurposePanel.md` already carries the needed method and field names. | High | Current support doc/generated output lists accessors, `DispatchActiveChildRefresh`, `m_childPanes[7]`, and `m_activeChildIndex`. | Support `by-class/GeneralPurposePanel.md`. | already-present | already-present |
| C015 | `by-file/GeneralPurposePanel.md` already carries the needed source route. | High | Current file support routes the class through `NexusTK/ui/panels/GeneralPurposePanel.cpp`. | Support `by-file/GeneralPurposePanel.md`. | already-present | already-present |
| C016 | PaneCore support already resolves virtual slot `+0x20`. | High | `by-class/Pane.md` and Pane vtable docs identify the slot as `Pane::InvalidateRect`. | Support `by-class/Pane.md` and Pane vtable support. | already-present | already-present |
| C017 | UID0003A2 support already validates `DispatchActiveChildRefresh` as the caller-facing dependency name. | High | B007 ScreenPane palette report and current docs use `g_pGeneralPurposePanel->DispatchActiveChildRefresh()`. | Support `by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md`. | already-present | already-present |

## Positive Evidence Summary

- Fresh MCP confirms exact helper bodies, boundaries, padding, and xrefs.
- Current generated GeneralPurposePanel output already declares the needed class, method signatures, and member fields.
- PaneCore support resolves the inherited virtual slot enough to name the call `InvalidateRect(NULL)`.
- UID0003A2 ScreenPane evidence validates `DispatchActiveChildRefresh` as the current project spelling for `0x004b8630`.
- The target already clears owner/emitter/reconstructable gates; only the formal code is missing.

## Negative Evidence Summary

- No recovered original symbol proves these exact public/member spellings; confidence should stay at `91`, not final-audit quality.
- Current IDA has no `GeneralPurposePanel` UDT members and no function renames for these helpers.
- `0x004b85f0` does not reject negative indices, so an intuitively safer C++ body would be binary-inaccurate.
- `SpellOneArgInputPane` is not a valid owner for this cluster.
- PaneCore owns `InvalidateRect`; UID00015W should call it but not claim the inherited slot implementation.

## Ranked Ownership Analysis

### 1. [UID:00005Q] GeneralPurposePanel - accepted

Best owner. The helpers operate on the seven-child `GeneralPurposePanel` shell, use its child array and active index, and are declared in the generated `GeneralPurposePanel` class.

### 2. [UID:0000JQ] GeneralPurposePanel.cpp - file route, not direct child owner

Correct source-file route for generated output and class declarations. The memory page owner remains [UID:00005Q] because the bodies are class methods.

### 3. [UID:0000A2] Pane / PaneCore - dependency only

PaneCore owns `InvalidateRect` and inherited vtable slot `+0x20`, but UID00015W owns only the call site that dispatches through an active child.

### 4. [UID:0000NB] ScreenPane - caller/dependency only

ScreenPane calls `GeneralPurposePanel::DispatchActiveChildRefresh` from `ScreenPane::HandleMessage` and the palette raw helper. Those refs validate the method name but do not own the method.

### 5. [UID:0000SW] g_useEpfAssets - global dependency only

The global selects seven versus four visible children. It is not an owner for the accessor code.

### 6. SpellOneArgInputPane - rejected

Stale generated ownership only. Its real code, RTTI, vtables, constructor, submit handler, and source route live in SpellInputPanes, not this GeneralPurposePanel cluster.

## Source Placement

Recommended source placement:

```text
NexusTK/ui/panels/GeneralPurposePanel.cpp
class GeneralPurposePanel
```

Recommended metadata route:

```text
CANONICAL_OWNER:00005Q
EMITTER_UIDS:00005Q
```

Do not route any implementation body from this target to ScreenPane, FrameChrome, PaneCore, SpellInputPanes, or the `g_useEpfAssets` global page.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. Recommended code is only this exact formal insertion text for the target page:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Pane* GeneralPurposePanel::GetChildPaneByIndex(int index)
{
    const int childCount = (g_useEpfAssets == 1) ? 7 : 4;
    if (index >= childCount) {
        return NULL;
    }

    return m_childPanes[index];
}

Pane* GeneralPurposePanel::GetActiveChildPane()
{
    if (m_activeChildIndex == -1) {
        return NULL;
    }

    return m_childPanes[m_activeChildIndex];
}

void GeneralPurposePanel::DispatchActiveChildRefresh()
{
    if (m_activeChildIndex != -1) {
        m_childPanes[m_activeChildIndex]->InvalidateRect(NULL);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this body is implementation-ready:

- Uses generated `Pane*` signatures and generated fields.
- Matches the binary's direct field access and sentinel behavior.
- Preserves the upper-bound-only index check.
- Uses an explicit `g_useEpfAssets == 1` comparison for `byte_66DA97`.
- Uses PaneCore's accepted `InvalidateRect` name for slot `+0x20`.

## Final Recommendation

Implementation callback is complete for UID00015W. The target metadata is `88/91`, the formal C++ block is populated with the accepted insertion text, source-quality notes were updated, support docs were verified same-or-greater with no edits, and scoped validation refreshed the generated output to command `000000007975`.

## Recommended Target Doc Changes

1. Metadata changed:

```text
COMPLETION:88
CONFIDENCE:91
```

2. Owner/emitter/reconstructable fields were kept unchanged:

```text
CANONICAL_OWNER:00005Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005Q
```

3. The formal C++ block was populated with the exact body in `First-Draft C++ Recommendation`.

4. Source-quality notes were added/updated for this evidence:

```text
Current MCP evidence confirms the three helper bodies as source-authored `GeneralPurposePanel` methods. `GetChildPaneByIndex` uses only an upper-bound signed check against the EPF/current child count `7` when `g_useEpfAssets == 1`, otherwise the legacy child count `4`; do not add a negative-index guard in the formal reconstruction. `GetActiveChildPane` and `DispatchActiveChildRefresh` read `m_activeChildIndex` at `+0x20`, with `-1` as the inactive sentinel. The refresh dispatcher invokes the active child inherited Pane slot `+0x20`, now documented as `Pane::InvalidateRect`, with a null rectangle argument.
```

5. The generated-owner pollution caveat was kept as a historical rejected route:

```text
Historical generated output once associated this cluster with `SpellOneArgInputPane`; current GeneralPurposePanel RTTI/class docs, generated `GeneralPurposePanel.cpp`, child field layout, and caller set reject that route.
```

## Recommended Support Doc Changes

No support by-* edits were required during implementation because current support docs already carry the needed names and route:

- `by-class/GeneralPurposePanel.md` already exposes `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, `m_childPanes[7]`, and `m_activeChildIndex`.
- `by-file/GeneralPurposePanel.md` already routes the class through `NexusTK/ui/panels/GeneralPurposePanel.cpp`.
- `by-class/Pane.md` already resolves slot `+0x20` as `Pane::InvalidateRect`.
- UID0003A2 already uses `GeneralPurposePanel::DispatchActiveChildRefresh`.

## Score And Metadata Recommendation

Implemented after callback:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00005Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005Q
```

Rationale:

- Raise completion from `85` to `88` because all named report blockers are resolved and the C++ body is implementation-ready.
- Keep confidence at `91` because behavior/ranges/ownership are strongly MCP-backed, but exact original public/member spellings are still inferred from project docs and generated output rather than recovered symbols.
- Do not exceed `91` until source symbols/types or original source names are recovered.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Current disposition |
| --- | --- | --- |
| Are the exact public method spellings original? | Checked IDA names/types, generated output, B003, B007, and support docs. | Original symbols not recovered; generated/project spellings are sufficient for first-draft C++. |
| Should `RefreshActiveChild` replace `DispatchActiveChildRefresh`? | Compared B003 alternate with B007 ScreenPane incorporation and current generated declaration. | Keep `DispatchActiveChildRefresh`; mention `RefreshActiveChild` only as descriptive alias if needed. |
| Should `GetChildPaneByIndex` reject negative indices? | Disassembled the comparison and branch. | No; binary uses upper-bound-only signed check. |
| Is slot `+0x20` an update, refresh, redraw, or invalidate? | Checked Pane class and vtable docs. | Use `Pane::InvalidateRect(NULL)`; "refresh" remains a contextual description. |
| Does broad caller fan-in indicate a different owner? | Reviewed fresh xrefs and GeneralPurposePanel shell docs. | No; broad fan-in supports public side-panel accessors. |
| Is SpellOneArgInputPane still relevant? | Checked IDA RTTI/names and generated route. | Rejected as stale generated-owner pollution. |

## Validator Results

Required scoped target validator:

> Executable block R001 was removed from this report and preserved verbatim in [00015W-GeneralPurposePanelChildAccessors-source-quality-removed.md](00015W-GeneralPurposePanelChildAccessors-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Command metadata:

| Field | Value |
| --- | --- |
| Working directory | `source-3/project-documentation` |
| Wrapper timestamp | `2026-07-08T16:20:53.0215803-04:00` |
| Validator `command_id` | `000000007975` |
| Validator `command_timestamp` | `2026-07-08T16:20:53-04:00` |
| Exit code | `0` |
| `ok` count | `1` |
| Generated refresh | `deferred` |
| Generated refresh command id | `000000007975` |
| Generated refresh timestamp | `2026-07-08T16:20:53-04:00` |

Validator notices/warnings:

- `missing_ref_uid`: four notices total, for UID `0003A2` and UID `0003UT` appearing twice each; these UID references are not present in `validator.ini`.
- No validator failure; scanned markdown files `1`, `ok: 1`.

Generated freshness:

- `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` refreshed to `validator-command-id: 000000007975`.
- Header reports `validator-refreshed-at: 2026-07-08T16:20:53-04:00` and `validator-refresh-source: deferred-generated-refresh`.
- UID00015W no longer appears as an unexplained empty-emitter marker in that generated file. It now emits the accepted `GetChildPaneByIndex`, `GetActiveChildPane`, and `DispatchActiveChildRefresh` bodies with `(g_useEpfAssets == 1) ? 7 : 4` and `InvalidateRect(NULL)`.

No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, IDA process command, MCP process command, or `idb_open` was run.

Research command metadata:

| Command family | Date/session | Result |
| --- | --- | --- |
| MCP `server_health` | 2026-07-08, database `b007_uid0002oc_20260708` | exit 0 via PowerShell JSON-RPC; `status: ok`, Hex-Rays ready. |
| MCP boundary/decompile/disasm bytes batch | 2026-07-08, same database | exit 0; confirmed function sizes, decompiled bodies, instructions, padding bytes. |
| MCP xref/callee/block batch | 2026-07-08, same database | exit 0; confirmed no modeled callees and xref counts `50`, `4`, `2`. |
| MCP entity/type checks | 2026-07-08, same database | exit 0 for narrow queries; no UDT/type records for GeneralPurposePanel/SpellOneArgInputPane; functions remain `sub_*`. |
| Local `rg`/file reads | 2026-07-08 | Used only for report research; no files edited outside this report. |

## Changed Files

B011-edited files:

```text
source-3/project-documentation/by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md
source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00015W-GeneralPurposePanelChildAccessors-source-quality.md
```

Validator-refreshed/generated output:

```text
source-3/project-documentation/auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp
source-3/project-documentation/project-level/-auto-completion-stats.md
```

Support by-* docs were checked and did not require edits. No coverage reports, supervisor ledgers, archives, lifecycle files, queues, or IDA DB state were edited manually.

## Leases

Target lease used for the immediate by-* edit batch:

| File | Lease action | Timestamp/result |
| --- | --- | --- |
| `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md` | leased by B011 | `2026-07-08T20:13:17Z`; success, expiration `2026-07-08T20:18:17Z` |
| `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md` | released by B011 | `2026-07-08T16:17:08.6400168-04:00`; success, exit code `0` |
| `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md` | leased by B011 | `2026-07-08T16:20:33.7313087-04:00`; success, second note-tightening batch |
| `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md` | released by B011 | `2026-07-08T16:21:10.3748663-04:00`; success, exit code `0` |

Post-release check: `tools/leaser/Agents/current_leases.md` reports no active leases.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Read project-level workflow skill, B011 `goal.md`, report template, and B-agent workflow reference.
- [x] Confirmed MCP availability against supervisor-provided active database `b007_uid0002oc_20260708`.
- [x] Rechecked helper ranges `0x004b85f0-0x004b8616`, `0x004b8620-0x004b862f`, and `0x004b8630-0x004b8643` with current MCP evidence.
- [x] Checked target/support docs, generated output, and old B reports relevant to UID00015W.
- [x] Recorded every accepted claim in `Claim And Incorporation Ledger` with required action and verification state.

Implemented target edits:

- [x] Target formal C++ insertion applied for `by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md`: ledger rows C002, C003, C004, C005, C006, C007, C008, C009, and C011; action `incorporate`; verification state `applied`.
- [x] Target metadata score changed to `COMPLETION:88` / `CONFIDENCE:91`: ledger row C013; action `incorporate`; verification state `applied`.
- [x] Owner/emitter/reconstructable fields preserved: ledger row C012; action `already-present`; verification state `already-present`.
- [x] Target source-quality wording updated for exact ranges, helper roles, field names, public method spellings, explicit `g_useEpfAssets == 1`, upper-bound-only index behavior, active-index sentinel, Pane `InvalidateRect(NULL)` dispatch, generated-output empty-emitter repair, and rejected stale `SpellOneArgInputPane` ownership: ledger rows C001, C003, C009, C010, and C011; verification state `applied`.

Support-doc disposition after implementation:

- [x] `by-class/GeneralPurposePanel.md` has same-or-greater method/field naming detail: ledger row C014; action `already-present`; verification state `already-present`.
- [x] `by-file/GeneralPurposePanel.md` has same-or-greater source-route detail: ledger row C015; action `already-present`; verification state `already-present`.
- [x] `by-class/Pane.md` / Pane vtable support has same-or-greater slot `+0x20` detail: ledger row C016; action `already-present`; verification state `already-present`.
- [x] UID0003A2 ScreenPane palette support has same-or-greater `DispatchActiveChildRefresh` caller-name detail: ledger row C017; action `already-present`; verification state `already-present`.

Validation and release:

- [x] Required scoped target validator ran with final `command_id: 000000007975`, exit code `0`, and `ok: 1`.
- [x] Generated `auto-generated/NexusTK/ui/panels/GeneralPurposePanel.cpp` refreshed to command `000000007975`; UID00015W no longer remains an empty-emitter marker.
- [x] Target lease released; current lease table shows no active leases.
- [ ] `execute_report` run. Supervisor-only; prohibited for B011.
- [x] Implementation callback ready for supervisor execute.

## Gate State

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007983","destination_path":"executed-b-agent-research/B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00015W-GeneralPurposePanelChildAccessors-source-quality.md","timestamp":"2026-07-08T16:36:08-04:00","uid":"00015W"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015W-GeneralPurposePanelChildAccessors-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
