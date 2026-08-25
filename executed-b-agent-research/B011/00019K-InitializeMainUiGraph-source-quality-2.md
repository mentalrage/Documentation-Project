** TARGET-REPORT-UID:00019K **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Report - [UID:00019K] InitializeMainUiGraph Source Quality Recheck

Assignment id: `B011-report-00019K-initialize-main-ui-graph-source-quality-20260626`
Agent: `B011`
Mode: report-only research
Report path: `tools/leaser/Agents/Agent-B011/research/00019K-InitializeMainUiGraph-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00019K] at `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000L1`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L1`.
- Final disposition: [UID:00019K] remains a reconstructable MainUiGraph bootstrap function routed through [UID:0000L1] `MainUiGraph`. Formal C++ should remain blank under the existing target-specific no-code proof.
- Required action: correct the current target/support docs where they still imply the active IDB contains the saved `InitializeMainUiGraph` label. Live MCP session `80de0a67` reports the function as `sub_4F7D10`; the documentation source-facing name is still supported, but the current IDB label claim is stale or at least not confirmed by the active worker.
- Confidence: very strong for range, sole caller, graph-pointer handoff, branch selector, frame-resource refs, common-tail side effects, owner route, and no-code disposition; medium for current IDB label persistence and complete root object layout.

## Target

- Target UID: [UID:00019K]
- Target path: `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`
- Related item view: [UID:0000UV] `by-item/InitializeMainUiGraph_004F7D10.md`
- Source queue/report row: assignment originally named `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`. Current generated tracker now shows [UID:00019K] as covered by `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md`; that generated state was read-only input.
- Current supervisor classification: source-quality and first-draft-C++ readiness pass.
- Current scores and parent state: [UID:00019K] is `90/91`, owner/emitter [UID:0000L1] `MainUiGraph`, reconstructable `TRUE`, C++ block blank. Direct parent [UID:0000L1] is `88/88`.

## Current Target State

- Existing metadata: `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000L1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L1`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing owner/emitter/reconstructable state: correct and still supported. The sole caller passes [UID:0000RF] `g_pMainUiGraph` in `ecx`; the target builds the live in-game UI graph, not the login dialog itself.
- Existing C++/emitter state: eligible under the minimum metadata/emitter gate, but formal C++ correctly remains blank because the full 3611-byte bootstrap would still require unrecovered `MainUiGraph` layout and broad constructor/helper source shapes.
- Existing open questions/blockers: concrete `MainUiGraph` type/layout, exact layer-slot declaration shape, all constructor/helper source signatures, and current IDB label persistence.
- Related target/support docs checked: target by-memory page, [UID:0000UV], [UID:0000L1], [UID:0000RF], [UID:0000T6], [UID:0000T7], [UID:0001R7], [UID:000294], [UID:0002QH], [UID:00029D], [UID:0000Q8], [UID:00039S], [UID:0003ZI], [UID:0002F8], and selected executed B reports listed below.
- Current workspace caveat: a central executed B011 report already exists and current by-* pages already contain most of its accepted facts. This active report treats that material as read-only current state and adds a current MCP-backed label-state correction.

## Executive Recommendation

Keep the current MainUiGraph ownership and no-code disposition. Do not split, rename, reassign, lower reconstructable state, or add first-draft C++.

Apply a narrow documentation correction during a supervisor-approved implementation callback:

- [UID:00019K] and [UID:0000UV] should no longer state unqualified that the active/current IDA label is saved as `InitializeMainUiGraph`.
- Preserve the historical 2026-06-16 C001 rename attempt as historical evidence if desired, but add the current live-session correction: MCP session `80de0a67` reports no function/name entity for `InitializeMainUiGraph`; `lookup_funcs` resolves `0x004f7d10` and `sub_4F7D10` as `sub_4F7D10`.
- Keep the source-facing documentation name `InitializeMainUiGraph` because behavior, caller, owner, and source role still strongly support it. This is a documentation/source-facing name, not a currently confirmed IDB symbol in the active worker.

## Supervisor Active Recheck

- Supervisor instruction: continue report-only B011 work for [UID:00019K] `InitializeMainUiGraph`; recheck exact range, caller, branch structure, graph-pointer handoff, constructor/callee inventory, direct data refs, padding/end boundary, support relationships, source-quality blockers, and first-draft C++ readiness.
- Split repair: no split is recommended. IDA models one coherent function from `0x004f7d10` through last byte `0x004f8b2a`, with half-open end `0x004f8b2b` and successor at `0x004f8b30`.
- Source-bearing children: callee pages such as BackPane, MapPane, Chatting, ScreenPane setter, SoundManager restart, and MapPane teardown carry their own owner/source routes. This target should not absorb their code.

## Inference Research Guidance Check

This pass separates IDA facts, current documentation evidence, and inference:

- IDA fact: active MCP session `80de0a67` is healthy and reports `sub_4F7D10`, size `0xe1b`; only one xref to `0x004f7d10`; frame string refs at `0x004f7d76` and `0x004f856c`; common-tail refs to `g_pScreenPane`, `g_pApplicationCleanupQueue`, `g_pScreenDimmer`, and `g_pApplication`.
- Documentation evidence: current by-* docs resolve the source-facing name, owner route, frame resources, active map-session byte, layer-slot names, ScreenPane presentation setter, SoundManager restart, and Chatting line-count helper.
- Inference: `InitializeMainUiGraph` is the best source-facing function name and [UID:0000L1] `MainUiGraph` remains the best source file. Exact original spelling and current IDB label are not proven by the active MCP session.
- Wave2/Wave3/generated material: read only as lead context where current docs mention it. No stale Wave2/Wave3 claim was used as authority.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Name Versus Current IDB Label

- Best source-facing name: `InitializeMainUiGraph`, inferred/accepted from the function role, sole login-success graph handoff, and current by-* documentation.
- Current IDB evidence: `lookup_funcs` for `InitializeMainUiGraph` returns `Not found`; `entity_query` for functions and names matching `InitializeMainUiGraph` returns zero hits; `lookup_funcs 0x004f7d10` and `lookup_funcs sub_4F7D10` return `sub_4F7D10`, size `0xe1b`.
- Rejected alternative: treat the missing IDB name as proof the documentation name is wrong. Rejected because the runtime role and owner evidence still strongly support the source-facing name; the missing IDB label only invalidates the claim that the active IDB currently carries that label.
- Recommendation: do not edit IDA DB in this report-only pass. If an authorized IDA sync later re-applies the label, verify it through `lookup_funcs InitializeMainUiGraph` before documenting it as current IDB state.

### Ownership And Source Placement

[UID:0000L1] `MainUiGraph` remains accepted.

- Evidence for: sole caller loads [UID:0000RF] `g_pMainUiGraph` at `0x004fac95` before `call sub_4F7D10` at `0x004fac9b`; target constructs the post-login in-game pane graph; it uses [UID:0000T6] MainUiLayerSlots and downstream UI/map/social/profile/audio/input dependencies.
- Evidence against weaker owners: login is the trigger only; Application owns process lifecycle and some globals but not this graph-building body; pane-specific files are callees/dependencies; ScreenPane, BlackHole, SoundManager, and ProfileStorage are common-tail consumers/dependencies.
- Decision: keep `CANONICAL_OWNER:0000L1` and `EMITTER_UIDS:0000L1`.

### Helper/Global Name Resolution

Current docs already resolve the major old raw labels and this pass reconfirmed the evidence route:

- `off_61E100` / `off_61E114`: UTF-16 `FRAME.EPF` / `FRAME.EPD`, one xref each from this target.
- `sub_557820`: [UID:00039S] `ScreenPane::EnablePresentationMode`, called at `0x004f8a8e` after loading [UID:0000S7] `g_pScreenPane`.
- `sub_57B370`: [UID:0003ZI] `SoundManager::RestartMusic`, called with `0xbb8` / decimal `3000` (Verified with `int_convert.py`).
- `sub_480AD0`: [UID:0002F8] `ChattingModifyHeightPane::SetLineCount`.
- `dword_67A74C`: [UID:0000Q8] `g_pApplicationCleanupQueue`; `0x00469180` remains the BlackHole deferred-deletion queue helper.
- `unk_69AE08`: [UID:00029D] `g_pScreenDimmer`.
- `unk_67AB1C + 0x840`: [UID:000294] `g_pApplication` active map-session byte; [UID:0002QH] proves the teardown clear.
- `word_66DA9C` / `word_66DAA0`: [UID:0000T7] map-tile width/height bytes, each `0x30` / decimal `48` (Verified with `int_convert.py`).
- `dword_69B36x`: [UID:0000T6] layer/context slots, with accepted source-facing names but unresolved declaration shape.

### First-Draft C++ Readiness

The metadata/emitter gate is met, but formal C++ remains unsafe. This is not a generic "needs more investigation" deferral; current-pass investigation narrowed the blockers:

- The function has `0xe1b` / decimal `3611` bytes (Verified with `int_convert.py`), two layout branches, a shared tail, 39 direct callees, 139 basic blocks, 1218 listed instructions, and SEH cleanup records.
- Current support docs resolve many helper names, but the full `MainUiGraph` root object layout, class fields, allocation wrappers, exact constructor signatures, layer declaration shape, and all branch-local temporary object names are still not recovered.
- A formal body now would either omit material runtime setup or look like decompiler output with raw locals, raw `operator new` scaffolding, broad temporary variables, and unresolved helper signatures.
- Correct action: keep documentation source-quality high, keep C++ blank, and allow child/pane targets to emit their own narrower code when ready.

## Evidence Standards Used

- IDA MCP: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `callees`, `get_bytes`, `find_bytes`, `disasm`, `entity_query`.
- Raw bytes: boundary bytes, frame resource strings, layout selector byte, map-tile bytes.
- Documentation evidence: target/support by-* docs and executed B reports used as leads, then checked against current docs/MCP.
- Negative evidence: zero absolute little-endian pointer hits for target start, last byte, half-open end, and successor; no current `InitializeMainUiGraph` function/name entity in IDB.
- Tool limitation: MCP cannot prove original source spelling or complete type/layout without matching source metadata. The missing active IDB label prevents using the IDB as proof of the current label state.

## Evidence Checked

### IDA MCP/manual checks performed

- Listener/status: `127.0.0.1:13337` listening; MCP `initialize` and `tools/list` succeeded.
- Active IDB: `idb_list` reports session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `26892`, not analyzing.
- Health: `server_health` reports `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Function boundary: `lookup_funcs` for `0x004f7d10`, `0x004f8b2a`, `0x004f8b2b`, `0x004f8b30`, `0x004fac9b`, and `0x0067aba4`.
- Xrefs: `xrefs_to` for `0x004f7d10`, `0x0067aba4`, `0x0061e100`, `0x0061e114`, `0x0067ab1c`, `0x0069ae08`, `0x0067a7cc`, and `0x0067a74c`.
- Branch/tail: `disasm` at `0x004f7d40`, `0x004f8a80`, and `0x004fab10`.
- Bytes: `get_bytes` for `0x004f7d00`, `0x004f8b20`, `0x0061e100`, `0x0066da97`, and `0x0066da9c`.
- Negative pointer routes: `find_bytes` for `10 7d 4f 00`, `2a 8b 4f 00`, `2b 8b 4f 00`, and `30 8b 4f 00`.
- Label state: `entity_query` for `InitializeMainUiGraph` over functions/names and `lookup_funcs` for `InitializeMainUiGraph`, `sub_4F7D10`, and `0x004f7d10`.
- Numeric conversions: `tools/int_convert.py` JSON-stdin batch for `0xe1b`, `0x5d`, `0x128`, `0x910`, `0x104`, `0xbb8`, `0x840`, `0x12c`, and `0x30`.

### Docs, reports, generated inputs checked

- Target/support docs: [UID:00019K], [UID:0000UV], [UID:0000L1], [UID:0000RF], [UID:0000T6].
- Generated read-only inputs: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md` via `rg`.
- Existing executed report: `executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md`, read as historical accepted state and not edited.
- Relevant executed reports used as leads/support context: B005 BackPane construction/destruction, B009 ScreenPane presentation-mode setters, B002 MapPane lifecycle, B001 Chatting message ingress/constructor family. Their relevant claims were compared against current target/support docs and current MCP where this target depends on them.

### Failed or intentionally skipped checks

- A broad `search_text` probe for `unk_67ABA4` over `.text` returned a server traceback text instead of structured JSON. MCP remained healthy afterward (`server_health: ok`), so this is recorded as a failed broad search, not MCP unavailability. It is not used as evidence.
- No IDA rename, type, or comment edits were attempted. The assignment forbids IDA DB edits.
- No validators were run because no target/support by-* docs were edited during this report-only pass.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:00019K] is one function, half-open `0x004f7d10-0x004f8b2b`. | Confirmed | `lookup_funcs 0x004f7d10` size `0xe1b`; `0x004f8b2a` inside; `0x004f8b2b` not a function; successor `0x004f8b30`; bytes show return then five `0xcc`. | Successor start and last-byte/half-open end checked. | None for boundary. |
| Sole executable route is login-success caller `0x004fac9b`. | Confirmed | `xrefs_to 0x004f7d10` count 1; caller disasm shows `0x004fac95 mov ecx, unk_67ABA4`, then `0x004fac9b call sub_4F7D10`. | Absolute pointer patterns for start/end/successor all zero hits. | Indirect runtime reflection not indicated by current static evidence. |
| Source-facing name `InitializeMainUiGraph` remains correct. | Strong inferred | Target behavior, owner route, post-login graph construction, current by-* docs. | Active IDB does not have the name; `lookup_funcs InitializeMainUiGraph` not found. | If an authorized IDA sync re-applies the label, verify before saying current IDB label is saved. |
| Current IDB label claim is stale or unverified. | Confirmed for active session | `lookup_funcs 0x004f7d10` returns `sub_4F7D10`; `entity_query` for `InitializeMainUiGraph` finds no function/name. | Checked both name and address lookup. | Could differ in another IDB/session; current report only claims session `80de0a67`. |
| Owner/emitter should remain [UID:0000L1] MainUiGraph. | Strong | Caller passes `g_pMainUiGraph`; target builds live in-game UI graph; current by-file/global/layer docs agree. | LoginDialogPane/Application/pane-specific owners rejected as trigger/dependency/callee roles. | Full root object layout still open but does not block current owner route. |
| Formal C++ should remain blank. | Strong | Function breadth, 39 callees, 139 blocks, 1218 instructions, two branch families, unresolved root layout/helper signatures. | Major raw helper names were checked and many resolved; remaining blocker is source shape, not skipped evidence. | Requires recovered `MainUiGraph` layout and constructor/helper source family before code. |

## Positive Evidence Summary

- Function boundary and padding are stable in the current IDB.
- Caller and graph-pointer handoff are exact: one code xref, and caller loads `g_pMainUiGraph` immediately before the call.
- Branch selector and frame resources are direct data facts: `byte_66DA97 == 1` branch, `FRAME.EPF`, `FRAME.EPD`, map-tile bytes `0x30`.
- Common-tail behavior is directly visible in disassembly and matched by support docs: profile load, ScreenPane presentation enable, BlackHole cleanup-queue touch, optional ScreenDimmer hook, InputMan retarget, SoundManager restart `3000`, and Application active map-session flag set.
- Current support reports reject caller/dependency ownership for BackPane, ScreenPane setters, MapPane constructor, and Chatting panes; this keeps MainUiGraph as orchestrator/consumer.

## IDA MCP Facts

### Function/range facts

- `lookup_funcs 0x004f7d10`: `sub_4F7D10`, size `0xe1b` / decimal `3611` (Verified with `int_convert.py`).
- `lookup_funcs 0x004f8b2a`: inside `sub_4F7D10`.
- `lookup_funcs 0x004f8b2b`: not a function.
- `lookup_funcs 0x004f8b30`: `sub_4F8B30`, size `0x5d` / decimal `93` (Verified with `int_convert.py`).
- `get_bytes 0x004f8b20`: tail bytes include stack-cookie call, `mov esp, ebp`, `pop ebp`, `retn`, five `0xcc`, then successor prologue.
- `analyze_function 0x004f7d10`: prototype-shaped output `int __thiscall(wchar_t *this)`, size `3611`, one caller, 39 callees, 139 basic blocks, cyclomatic complexity 5, decompile truncated at 406 lines.
- `disasm 0x004f7d10`: total instructions `1218`.

### Xref facts

- `xrefs_to 0x004f7d10`: one code xref, `0x004fac9b` inside `sub_4FAB10`.
- `xrefs_to 0x0067aba4`: 31 refs; key hit `0x004fac95` in `sub_4FAB10`.
- `xrefs_to 0x0061e100`: one data xref at `0x004f7d76` in `sub_4F7D10`.
- `xrefs_to 0x0061e114`: one data xref at `0x004f856c` in `sub_4F7D10`.
- `xrefs_to 0x0067ab1c`: 140 refs; key hit `0x004f8b03` in `sub_4F7D10`.
- `xrefs_to 0x0069ae08`: 40 refs; key hit `0x004f8a9f` in `sub_4F7D10`.
- `xrefs_to 0x0067a7cc`: 145 refs; key hit `0x004f8a88` in `sub_4F7D10`.
- `xrefs_to 0x0067a74c`: 72 refs; key hit `0x004f8a93` in `sub_4F7D10`.

### Branch and byte facts

- `get_bytes 0x0061e100 size 64`: UTF-16LE `FRAME.EPF`, null, `FRAME.EPD`, null, then `STORY.EPF`.
- `get_bytes 0x0066da97 size 1`: `0x01`.
- `get_bytes 0x0066da9c size 8`: `30 00 00 00 30 00 00 00`, matching `48` and `48` map-tile dimensions (Verified with `int_convert.py`).
- `disasm 0x004f7d40`: `cmp byte_66DA97, 1`; current-layout branch pushes `off_61E100`, calls `sub_467830`, allocates `0x910` / `2320`, calls `sub_504110` with `17` and `15`, reads `word_66DAA0` and `word_66DA9C`, and pushes `unk_69B364`.
- `disasm 0x004f8a80`: tail calls profile load, `sub_557820`, `sub_469180`, optional `unk_69AE08` hook, old-layout `sub_4E9D00`, input retarget `sub_4E8CF0`, `sub_57B370` with `0xbb8`, then writes `[g_pApplication + 0x840] = 1`.

### Negative IDA facts

- `find_bytes` found zero hits for `10 7d 4f 00`, `2a 8b 4f 00`, `2b 8b 4f 00`, and `30 8b 4f 00`.
- `entity_query` found zero functions/names matching `InitializeMainUiGraph` in active session `80de0a67`.
- `lookup_funcs InitializeMainUiGraph` returned `Not found`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f7d10-0x004f8b2b` half-open | [UID:00019K] target | MainUiGraph bootstrap function | `TRUE` | [UID:0000L1] | `90/91` | Keep; update IDB-label wording only. |
| `0x004f8b2b-0x004f8b30` | none | five-byte `0xcc` padding | no source body | none | n/a | Keep documented as padding; no child needed. |
| `0x004f8b30` | successor function | next login-dialog helper | separate function | outside target | n/a | Not part of this range. |
| `0x00467830` | [UID:00030M] | BackPane construction/destruction | `TRUE` | BackPane | current support | Callee; not owned by MainUiGraph. |
| `0x00504110` | [UID:0002I7] | MapPane constructor/init | `TRUE` | MapPane | current support | Callee; exact parameter/source shape remains MapPane-family issue. |
| `0x00557820` | [UID:00039S] | ScreenPane enable presentation mode | `TRUE` | ScreenPane | current support | Callee; MainUiGraph is caller only. |
| `0x0057b370` | [UID:0003ZI] | SoundManager restart music | `TRUE` | SoundManager | current support | Callee; MainUiGraph passes delay. |
| `0x00480ad0` | [UID:0002F8] | ChattingModifyHeightPane line-count helper | `TRUE` | Chatting | current support | Callee; not a raw anonymous helper anymore. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004fac95` | `mov ecx, dword ptr unk_67ABA4` | Loads [UID:0000RF] `g_pMainUiGraph` as receiver/context. |
| `0x004fac9b` | `call sub_4F7D10` | Sole executable call to the initializer. |
| `0x004f7d76` | xref to `0x0061e100` | Current-layout `FRAME.EPF` operand. |
| `0x004f856c` | xref to `0x0061e114` | Old-layout `FRAME.EPD` operand. |
| `0x004f8a88` | xref to `0x0067a7cc` | Loads `g_pScreenPane` before `ScreenPane::EnablePresentationMode`. |
| `0x004f8a93` | xref to `0x0067a74c` | Loads `g_pApplicationCleanupQueue` before BlackHole deferred deletion helper. |
| `0x004f8a9f` | xref to `0x0069ae08` | Loads `g_pScreenDimmer` before optional hook. |
| `0x004f8b03` | xref to `0x0067ab1c` | Loads `g_pApplication` before setting byte `+0x840`. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: [UID:00019K], [UID:0000UV], [UID:0000L1], [UID:0000RF], and [UID:0000T6] already preserve range/caller/owner/no-code reasoning at high detail.
- Existing docs that are stale or incomplete: [UID:00019K] and [UID:0000UV] still carry unqualified current-IDB-label wording from the 2026-06-16 C001 refresh. Active MCP no longer confirms that label.
- Generated/coverage report state: generated auto coverage reports show [UID:00019K] as `90/91`; the generated research tracker already lists an executed B011 report. The legacy manual `by-memory/-coverage-report.md` row located by `rg` appears stale at `78%`, but this assignment does not authorize B011 to edit coverage reports. No generated or manual coverage report was modified.

## Ranked Ownership Analysis

### 1. [UID:0000L1] MainUiGraph

- Evidence for: graph-pointer handoff, UI graph construction behavior, layer slots, current by-file placement under `NexusTK/ui/`, and support docs.
- Evidence against: exact root object type/layout is not fully recovered.
- Decision: keep as canonical owner and emitter. Layout uncertainty limits C++ and score ceiling, not ownership.

### 2. LoginDialogPane

- Evidence for: sole caller is login-success path in `sub_4FAB10`.
- Evidence against: caller loads `g_pMainUiGraph` into `ecx`; callee builds live game UI, not login UI; downstream constructed panes are not login-owned.
- Decision: reject as owner; keep as caller context only.

### 3. Application

- Evidence for: target tail writes `g_pApplication + 0x840` and uses application-level cleanup/input/audio dependencies.
- Evidence against: target is invoked after login and owns UI graph construction; Application is lifecycle shell/dependency.
- Decision: reject as direct owner.

### 4. Pane-specific owners

- Evidence for: many callee families belong to BackPane, MapPane, Chatting, ScreenPane, SoundManager, ProfileStorage, InputMan, and BlackHole.
- Evidence against: they are constructed/called by this bootstrap, and support reports keep them as separate direct owners.
- Decision: reject for the target. Keep as dependencies/callees.

## Source Placement

- Recommended source file/class/global/module placement: `NexusTK/ui/MainUiGraph.cpp` through [UID:0000L1].
- Why it fits: proposed source tree already places `MainUiGraph.cpp` under `ui/`; current docs show this file bridges successful login to the live game UI graph. It is neither app startup nor login dialog implementation.
- Rejected placements: `login/LoginDialogPane.cpp`, `app/Application.cpp`, `map/MapPane.cpp`, `ui/core/ScreenPane.cpp`, `social/Chatting.cpp`, `audio/SoundManager.cpp`.
- Remaining placement uncertainty: whether the original source declared layer slots as globals or fields of a recovered graph/context object.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: IDA half-open `0x004f7d10-0x004f8b2b`, last covered byte `0x004f8b2a`; `0x004f8b2b-0x004f8b30` is five `0xcc` bytes; successor begins at `0x004f8b30`.
- Children/subranges: no new child split recommended. The body is one modeled function; contained constructor/helper calls are already separate callees.
- Padding/table/data/code distinctions: no internal data table or pointer-route ownership found; no absolute start/end/successor pointer hits.
- Parent/container impact: [UID:00019I] remains a broad mixed MainMenu/Login/MainUiGraph aggregate context; [UID:00019K] is the exact reconstructable child.

## Negative Evidence Summary

- No absolute little-endian VA patterns were found for the target start, last byte, half-open end, or successor.
- No active-session function/name entity exists for `InitializeMainUiGraph`.
- Address adjacency to LoginDialogPane and downstream panes is not ownership proof; caller/context and callee/dependency roles are separated.
- Current support reports reject MainUiGraph as owner for narrower callee targets like BackPane constructor and ScreenPane setters; that also prevents absorbing their C++ into [UID:00019K].

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing name: keep `InitializeMainUiGraph` in documentation.
- Current IDA DB state: active session `80de0a67` reports `sub_4F7D10`; no `InitializeMainUiGraph` function/name found.
- Recommendation: do not edit IDA DB in this B011 report. In by-* docs, qualify the prior C001 label text as historical or stale relative to session `80de0a67`.
- Optional authorized future action: if supervisor/user permits IDA DB sync, re-apply a low-risk function label `InitializeMainUiGraph` and verify with `lookup_funcs InitializeMainUiGraph` and `lookup_funcs 0x004f7d10`. B011 did not perform that action.

## First-Draft C++ Recommendation

- Eligible for draft C++ by metadata gate: yes, minimum gate is met (`TRUE`, nonblank emitter [UID:0000L1], average score `90.5`).
- Recommended code: none. Do not insert formal C++ for this target in the next implementation callback.
- Reason it preserves exact original behavior to keep code blank: the current documentation captures behavior, but a full C++ body cannot yet be written without inventing material layout, helper, and allocation details.
- Reason it matches plausible original source shape to keep code blank: a human-written mid-2000s C++ body would likely use named graph/context members, source-level constructors, pane wrapper helpers, and stable local names. Current evidence does not recover enough of those names and declarations for this 3611-byte orchestrator.
- Inferred names safe for docs but not full code: `InitializeMainUiGraph`, `g_pMainUiGraph`, `g_pApplication->m_inMapSession`, `rootPaneLayerContext`, `effectPaneLayerContext`, `overlayPaneLayerContext`, `layoutPaneLayerContext`, `statusPaneLayerContext`, `fpsOverlayLayerContext`.
- Exact no-code proof: one broad UI bootstrap, two layout branches, shared common tail, 39 direct callees, 139 basic blocks, 1218 instructions, SEH cleanup records, unresolved root layout and constructor/helper source families. Formal C++ now would be decompiler-shaped or incomplete.

## Final Recommendation

- Exact changes recommended: update target/support docs to correct current IDB label state; otherwise keep current [UID:00019K] metadata and no-code proof.
- Exact parent assignments recommended: keep [UID:00019K] owner/emitter [UID:0000L1].
- Exact items left no-owner/non-emitting: none in this target.
- Exact future work outside this report-only pass: recover `MainUiGraph` concrete layout and layer-slot declaration shape through separate class/global/source-layout work before attempting formal C++.

## Recommended Target Doc Changes

### `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`

- Keep metadata `90/91`, owner/emitter [UID:0000L1], `RECONSTRUCTABLE:TRUE`, blank formal C++.
- Add a current MCP correction under the 2026-06-16 C001 label text or a new change note:
  - Live MCP session `80de0a67` on this B011 report-only recheck reports `lookup_funcs 0x004f7d10 -> sub_4F7D10`, `lookup_funcs InitializeMainUiGraph -> Not found`, and zero function/name query hits for `InitializeMainUiGraph`.
  - The page's source-facing name remains `InitializeMainUiGraph`, but the active IDB label is not currently saved/visible in this session.
- Preserve historical C001 rename context if desired, but do not use it as current label proof.
- Preserve all current range, caller, branch, resource, tail, ownership, and no-code facts.

### `by-item/InitializeMainUiGraph_004F7D10.md`

- Keep metadata `90/91`, owner/emitter [UID:0000L1], blank formal C++.
- Replace or qualify `Current IDA label: InitializeMainUiGraph saved on 2026-06-16` with current-session wording:
  - Source-facing documentation name is `InitializeMainUiGraph`.
  - Active MCP session `80de0a67` reports the IDB function label as `sub_4F7D10`; no current `InitializeMainUiGraph` name entity was found.
- Preserve behavior, branch construction tables, common tail, no-code proof, and support links.

## Recommended Support Doc Changes

### `by-file/MainUiGraph.md`

- No required score or metadata change.
- Optional note only if touched: the source-facing initializer name remains accepted, but active session `80de0a67` does not currently expose an IDB `InitializeMainUiGraph` label.
- Keep `88/88`; current source-placement and no-code cap remain accurate.

### `by-global/g_pMainUiGraph.md`

- No required score or metadata change.
- Current handoff evidence remains accurate; no new text required unless supervisor wants to cross-link this report's current label correction.

### Coverage Reports

- B011 must not edit `by-memory/-coverage-report.md` or generated reports.
- No exact generated-report row text is supplied.
- Legacy manual `by-memory/-coverage-report.md` appears stale for [UID:00019K], but this assignment did not explicitly request manual coverage-report text. Supervisor should decide whether to sync that supervisor-owned manual row separately.

## Score And Metadata Recommendation

- Current score/metadata: [UID:00019K] `90/91`, owner/emitter [UID:0000L1], reconstructable `TRUE`, blank C++.
- Recommended score/metadata: unchanged.
- Score rationale and reason not higher: current docs are strong, but current IDB label persistence is contradicted by MCP session `80de0a67`; root graph layout, layer declaration shape, and constructor/helper source signatures remain below formal-code readiness.
- Reason not lower: boundary, caller, handoff, branch behavior, major resources, major tail callees/globals, owner route, and no-code proof are all current and well-supported. The IDB label mismatch is a documentation/source-state caveat, not a runtime behavior or ownership contradiction.
- Score-improvement attempt: investigated IDB label state, root-pointer handoff, branch/tail bytes, pointer-route negatives, support reports, layer-slot docs, and no-code blockers. Result: no score movement is safer than raising or lowering; narrow doc correction is required.
- Metadata fields to leave unchanged: `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER`, `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, formal C++.

## Open Questions With Attempted Resolution

1. Is `InitializeMainUiGraph` the current IDB label?
   - Evidence checked: `lookup_funcs`, `entity_query` functions/names.
   - Resolution: no in active session `80de0a67`; current docs must qualify prior saved-label claims.
   - Impact: documentation correction; no owner/score/C++ change.

2. Is `InitializeMainUiGraph` still the right source-facing name?
   - Evidence checked: sole caller, graph-pointer handoff, branch/tail role, current docs.
   - Resolution: yes, strongly inferred/accepted.
   - Impact: keep file/page names and source-facing prose.

3. Can formal C++ be emitted now?
   - Evidence checked: current metadata gate, branch/tail disassembly, callee inventory, support reports, root/layout docs.
   - Resolution: no. Keep exact no-code proof.
   - Impact: blank formal C++; score capped below final-audit.

4. Does the target need a split?
   - Evidence checked: function boundary, padding, successor, callee ownership docs.
   - Resolution: no. One modeled function with coherent source role; callees stay separate.
   - Impact: no split/rename/new child.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No exact manual coverage/tracker text is supplied in this report. The assignment did not grant B011 permission to edit any `-coverage-report.md`, and generated reports are validator-owned. The legacy manual by-memory coverage row for [UID:00019K] appears stale, but supervisor should decide whether a separate supervisor-owned manual sync is still desired.

## Follow-Up Actions

- Supervisor actions: validate this report; if accepted, send B011 an implementation callback limited to current-IDB-label wording in [UID:00019K] and [UID:0000UV], with optional support note in [UID:0000L1]. Do not execute a duplicate report over the existing central executed report without deciding whether this active report is a rework/addendum.
- A-agent actions: none.
- B011 future implementation callback: apply the label-state correction under leases, run scoped validators for touched by-* docs, update this checklist with proofs, and report validator `command_id`, timestamp, exit code, and `ok` count.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for unchanged `90/91`; medium for whether supervisor wants to treat the IDB label mismatch as score-impacting.
- Remaining uncertainty: exact original function spelling, active IDB label persistence across sessions, concrete `MainUiGraph` layout, and final layer-slot declarations.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory\0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md --apply --queue-timeout 240`
  - Working directory: `source-3/project-documentation`
  - `command_id`: `000000003579`
  - `command_timestamp`: `2026-06-26T22:38:17-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Warnings/side effects: `missing_ref_uid` warnings for `00039S` / `0003ZI` support UID references not present in `validator.ini`; `stats_incremental_noop 00019K`; `projected_stats_update 1`; `generated_refresh: deferred` with `generated_refresh_command_id: 000000003579`.
- `python .\tools\validator.py --mode file --file by-item\InitializeMainUiGraph_004F7D10.md --apply --queue-timeout 240`
  - Working directory: `source-3/project-documentation`
  - `command_id`: `000000003581`
  - `command_timestamp`: `2026-06-26T22:38:32-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Warnings/side effects: `missing_ref_uid` warnings for `0003ZI` / `00039S` support UID references not present in `validator.ini`; `stats_incremental_noop 0000UV`; `projected_stats_update 1`; `generated_refresh: deferred` with `generated_refresh_command_id: 000000003581`.
- Generated refresh state: deferred for both scoped validators. Generated output was not used for this narrow label-state correction.
- Validator-owned side effects observed in git status after scoped validation: `project-level/-auto-completion-stats.md` and `tools/validator.ini` changed by the validator. B011 did not manually edit those files.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B011/research/00019K-InitializeMainUiGraph-source-quality.md`.
- Modified by B011 implementation callback: `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`; `by-item/InitializeMainUiGraph_004F7D10.md`; this report checklist/results section.
- Reviewed and not edited: `by-file/MainUiGraph.md`; current wording uses `sub_4F7D10` lookup evidence and does not make the same unqualified active-IDB-label claim.
- Validator-owned side effects from the scoped `--apply` validators: `project-level/-auto-completion-stats.md`; `tools/validator.ini`.
- Renamed: none.
- Report execution: leave blank during B-agent pass. Supervisor owns `tools/validator.py execute_report ... --apply` only after verification.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report as a narrow current-IDB-label correction and issued implementation callback `B011-implement-00019K-initialize-main-ui-graph-label-state-20260626`.
- [x] Target/support docs to update: `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md` and `by-item/InitializeMainUiGraph_004F7D10.md`. Proof: both files were updated; optional `by-file/MainUiGraph.md` was reviewed and not edited because it does not make the same unqualified active-label claim.
- [x] Current target state and actual evidence checked recorded: MCP session `80de0a67`, health, boundary, xrefs, bytes, branch/tail disassembly, callee count, negative pointer-route search, name-query negative, support docs, and selected executed reports. Proof: incorporated as current-label correction text and preserved existing evidence sections in both target/support docs.
- [x] Metadata/score changes to apply: none; keep [UID:00019K] `90/91`, [UID:0000UV] `90/91`, [UID:0000L1] `88/88`. Proof: headers in [UID:00019K] and [UID:0000UV] remain unchanged; [UID:0000L1] was not edited.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or exact evidence-backed no-improvement proof: current IDB label mismatch resolved as doc correction; root layout/layer declaration/C++ blockers narrowed with exact no-code proof; no split needed. Proof: docs now distinguish historical saved-label context from active-session state and preserve no-code proof.
- [x] Owner/emitter/reconstructable changes to apply: none; keep [UID:00019K] owner/emitter [UID:0000L1], reconstructable `TRUE`. Proof: metadata headers unchanged.
- [x] Split/rename/new-child changes to apply: none. Proof: no files renamed or created beyond this already-created report; target filenames unchanged.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: keep `ui/MainUiGraph.cpp`; keep range and filename convention; do not edit IDA DB; qualify current IDB label status. Proof: no IDA DB action was taken; source-facing name retained; active-label caveat added.
- [x] First-draft C++ or no-code proof to apply: preserve blank C++ and no-code proof; no formal C++ insertion. Proof: formal `RECONSTRUCTION_CPP CODE` headers remain blank in [UID:00019K] and [UID:0000UV]; no-code proof text preserved.
- [x] Exact target/support doc facts to incorporate at report-level detail: active session reports `sub_4F7D10`, no `InitializeMainUiGraph` name entity; source-facing name remains accepted; all range/caller/owner/no-code facts remain valid. Proof: added to [UID:00019K] Status / B011 implementation / Score Rationale / Changes and to [UID:0000UV] Status / B011 implementation / Score Rationale / Data And Naming Caveats / Changes.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve historical C001 rename context as historical if useful; add current correction; preserve rejected LoginDialogPane/Application/pane-owner alternatives and pointer-route negatives. Proof: 2026-06-16 C001 notes now explicitly say the label was verified at that time; 2026-06-26 current correction preserves pointer-route negatives and owner reasoning.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated/simroot provenance not used as authority. Proof: no generated/simroot row text was added; by-file generated-source reference was reviewed but not edited.
- [x] Open questions to close or document as evidence-backed unresolved: IDB label mismatch closed for current session; root layout and C++ readiness remain documented unresolved with score/C++ impact. Proof: current-label state now closed for `80de0a67`; C++ no-code proof remains unchanged.
- [x] Validators to run after implementation callback: `python .\tools\validator.py --mode file --file by-memory\0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md --apply --queue-timeout 240`; `python .\tools\validator.py --mode file --file by-item\InitializeMainUiGraph_004F7D10.md --apply --queue-timeout 240`; optional `python .\tools\validator.py --mode file --file by-file\MainUiGraph.md --apply --queue-timeout 240` if touched. Proof: first two validators ran and passed with `ok: 1`; by-file was not touched, so optional validator not run.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator may refresh generated state after scoped file validations; no exact manual coverage text supplied; B011 must not edit generated reports or any `-coverage-report.md`. Proof: validators reported `generated_refresh: deferred`; no generated or `-coverage-report.md` files were manually edited.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation. Proof: supervisor requested this narrow implementation callback for [UID:00019K] current-IDB-label-state correction.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: both [UID:00019K] and [UID:0000UV] now state the exact `80de0a67` `lookup_funcs` / `entity_query` correction and retain source-facing `InitializeMainUiGraph`.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason. Proof: no metadata, score, owner, emitter, split, rename, or C++ changes were required or made; formal C++ remains blank under the no-code proof.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: 2026-06-16 rename is kept as historical context; active-session correction added; negative pointer-route and non-owner alternatives remain in docs.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: active IDB-label question resolved for session `80de0a67`; root layout/C++ blockers remain documented with score/C++ impact.
- [x] Validators run and results recorded with `command_id`, `command_timestamp`, exit code, and `ok` count. Proof: validator results section records commands `000000003579` and `000000003581`, both exit `0`, both `ok: 1`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged. Proof: both scoped validators reported `generated_refresh: deferred`; generated output was not used; no manual coverage/tracker text applies.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: none; all accepted narrow implementation items applied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality-2.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00019K-InitializeMainUiGraph-source-quality.md","timestamp":"2026-06-26T22:44:24","uid":"00019K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
