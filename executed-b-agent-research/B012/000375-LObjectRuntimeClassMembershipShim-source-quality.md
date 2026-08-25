** TARGET-REPORT-UID:000375 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000375 LObjectRuntimeClassMembershipShim Source-Quality Research


## Target

- Target UID: `000375`
- Target path: `by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md`
- Assignment: `B012-report-000375-LObjectRuntimeClassMembershipShim-20260702`
- Queue source: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`, tracker command `000000004649` refreshed `2026-07-02T16:12:33-04:00`.
- Current target scores: `COMPLETION:85`, `CONFIDENCE:88`, average `86.5`.
- Current metadata: `CANONICAL_OWNER:00007D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007D`, blank emitter position.
- Current formal C++ block: nonblank formal comment-only no-code marker for the raw membership shim.

## Current Target State

- Existing page documents an exact raw `.text` range `0x004f4b20-0x004f4b30`, inclusive start/exclusive end.
- Existing page correctly says IDA does not model a function at `0x004f4b20`.
- Existing behavior summary is accurate: the bytes call the current object's vtable slot at `+0x04`, move the returned runtime-class pointer into `ecx`, restore `ebp`, and tail-jump to `0x005568e0`.
- Existing owner/emitter route is plausible and should remain [UID:00007D][LObject](../../../by-class/LObject.md): this shim is the object-facing membership entry that starts from an `LObject`-family instance in `ecx`.
- Existing source file route through [UID:0000KV][LObject](../../../by-file/LObject.md) is supported by parent docs and generated `auto-generated/NexusTK/util/LObject.cpp`.
- Existing item summary is blank and should be filled.
- Existing prose still underspecifies why the nonblank formal C++ block is a no-code marker rather than a body to compile as a standalone shim.
- Existing page lacks current MCP session evidence. The current project session is `supervisor_resume_20260629`.
- Related docs checked:
  - [UID:00007D][LObject](../../../by-class/LObject.md)
  - [UID:0000KV][LObject](../../../by-file/LObject.md)
  - [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](../../../by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md)
  - [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](../../../by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md)
  - [UID:000371][0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor](../../../by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md)
  - [UID:000373][0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor](../../../by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md)
  - [UID:0003OO][0x0061cf68-0x0061cf78.LObjectVtableData](../../../by-memory/0x0061cf68-0x0061cf78.LObjectVtableData.md)
  - [UID:00025O][0x0061cf68-0x0061d118.LObjectLogoReadOnlyData](../../../by-memory/0x0061cf68-0x0061d118.LObjectLogoReadOnlyData.md)

## Evidence Checked

- Read assignment and workflow evidence:
  - `tools/leaser/Agents/Agent-B012/goal.md`
  - `.codex/skills/ntk-b-agent-workflow/SKILL.md`
  - `.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
  - `.codex/skills/ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
  - `by-structure.md` IDA MCP Output Discipline
  - `by-memory/-guidance.md`
- Report-history searches performed with `rg` terms:
  - `000375`
  - `0x004f4b20`
  - `0x004F4B20`
  - `LObjectRuntimeClassMembershipShim`
  - `RuntimeClassMembership`
  - `membership shim`
  - `0x005568e0`
  - `CallbackAndListMembershipHelpers`
  - Search roots included `tools/leaser/Agents`, `executed-b-agent-research`, `archived`, `tools/leaser/Agents/Older-Research`, and `tools/leaser/Agents/SpecialReports`.
- Relevant report matches:
  - `executed-b-agent-research/B011/000195-LObjectRuntimeShell-source-quality.md`: accepted mixed runtime-shell report. It includes UID000375 as exact child support and supplied the currently installed formal membership-shim no-code marker.
  - `executed-b-agent-research/B003/B003-MEMTOOL-005568D0-CallbackAndListMembershipHelpers.md`: accepted helper-island report. It confirms the `0x005568e0` helper relation, no direct xrefs to `0x004f4b20`, and no table hits for the helper starts.
  - `executed-b-agent-research/B005/0000WM-LObjectDefaultNoOpVirtual-source-quality.md`: accepted sibling default-virtual report. It confirms exact LObject shell children, including UID000375, as class-owned by [UID:00007D].
- Generated/project-state read-only evidence:
  - `auto-generated/-ag-research-tracker.md` row lists UID000375 at `85/88`, reconstructable, with zero executed reports for this target.
  - `project-level/-auto-completion-stats.md` row lists UID000375 at `85/88`, average `86.5`.
  - `auto-generated/NexusTK/util/LObject.cpp` header is `validator-command-id: 000000004586`, `validator-refreshed-at: 2026-07-02T15:11:58-04:00`; it contains the UID000375 formal comment marker and does not treat UID000375 as an empty emitter marker.
- Current IDA MCP evidence, all narrow and schema-current through JSON-RPC on active session `supervisor_resume_20260629`:
  - `idb_list`: one active session `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, owned/adopted worker session.
  - `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
  - `lookup_funcs` for `0x004f4b10`, `0x004f4b20`, `0x004f4b30`, `0x005568d0`, `0x005568e0`, `0x00556910`.
  - `get_bytes` for `0x004f4b10` size `0x30`, `0x005568d0` size `0x40`, `0x0061cf44` size `0x30`, and `0x0061cf68` size `0x18`.
  - `xrefs_to` for `0x004f4b20`, `0x004f4b2b`, `0x005568d0`, `0x005568e0`, `0x0061cf44`, `0x0061cf68`, with `limit:50`.
  - `disasm` for `0x004f4b20` with `max_instructions:10`.
  - `disasm` for `0x005568d0` with `max_instructions:40`.
  - `disasm` for `0x004f4b10` and `0x004f4b30`, both bounded.
  - `xrefs_to` for sibling/function boundaries `0x004f4b10`, `0x004f4b30`, `0x004f4b50`, `0x004f4b70`, `0x004f4b90`, with `limit:20`.
  - `find_bytes` for pointer patterns `20 4b 4f 00`, `d0 68 55 00`, and `e0 68 55 00`, each with `limit:20`.
- Intentionally skipped:
  - No broad function listing, no callgraph, no unbounded text search, no type sweep, no IDA edits.
  - No validator run because this is report-only and no by-* docs were edited.

## Positive Evidence Summary

- Current MCP `lookup_funcs` reports `0x004f4b20` is not a function and confirms the neighboring modeled functions: `sub_4F4B10` at `0x004f4b10` size `0x6`, `sub_4F4B30` at `0x004f4b30` size `0x1c`, and `sub_556910` at `0x00556910` size `0x14a`. It also reports no function at raw helper starts `0x005568d0` or `0x005568e0`.
- Current MCP `get_bytes 0x004f4b10 size 0x30` returns the sequence containing:
  - accessor bytes `b8 44 cf 61 00 c3` at `0x004f4b10-0x004f4b16`;
  - ten `0xcc` bytes at `0x004f4b16-0x004f4b20`;
  - shim bytes `55 8b ec 8b 01 ff 50 04 8b c8 5d e9 b0 1d 06 00` at `0x004f4b20-0x004f4b30`;
  - next function prologue at `0x004f4b30`.
- Current MCP `disasm 0x004f4b20 max_instructions:10` decodes exactly:
  - `push ebp`
  - `mov ebp, esp`
  - `mov eax, [ecx]`
  - `call dword ptr [eax+4]`
  - `mov ecx, eax`
  - `pop ebp`
  - `jmp loc_5568E0`
  - followed by `sub_4F4B30` at `0x004f4b30`.
- Current MCP `xrefs_to 0x004f4b20` returns zero xrefs; this supports the raw shim/no direct caller status.
- Current MCP `xrefs_to 0x005568e0` returns exactly one code xref from `0x004f4b2b`, and the xref's function is null because the source site is raw/unmodeled. This proves the UID000375 tail-jump is the only current code edge to the membership/base-chain helper start.
- Current MCP `xrefs_to 0x005568d0` returns zero xrefs. The sibling helper at `0x005568d0` remains related runtime-class machinery but is not reached by UID000375.
- Current MCP `find_bytes` for little-endian pointers to `0x004f4b20`, `0x005568d0`, and `0x005568e0` returns no matches under the capped scan. This supports "no table-installed standalone function pointer" for the shim or helper starts.
- Current MCP `get_bytes 0x005568d0 size 0x40` and `disasm 0x005568d0 max_instructions:40` confirm the helper island:
  - `0x005568d0-0x005568dc`: reads `[ecx+8]`, jumps through it when non-null, otherwise returns zero.
  - `0x005568dc-0x005568e0`: four `0xcc` alignment bytes.
  - `0x005568e0-0x00556907`: frame setup, null `ecx` check, loads target from `[ebp+8]`, compares target to `ecx`, walks `[ecx+0x0c]`, returns `al=1` on match and `al=0` on miss/null.
  - `0x00556907-0x00556910`: alignment before `sub_556910`.
- Current MCP `get_bytes 0x0061cf44 size 0x30` shows the runtime-class record starts with pointer `0x0061cf54`, size dword `4`, null callback/base fields for the base record, UTF-16 `LObject`, then the `LObject` vtable entries at `0x0061cf68`.
- Current MCP `get_bytes 0x0061cf68 size 0x18` shows vtable entries `0x004f4b90`, `0x004f4b10`, `0x0041b6c0`, followed by adjacent data. This matches the LObject vtable page.
- Current MCP `xrefs_to 0x0061cf44` returns exactly one xref, from accessor `0x004f4b10`.
- Current MCP `xrefs_to 0x0061cf68` returns exactly three refs: constructor store at `0x004f4a80`, destructor-body store at `0x004f4a90`, and scalar deleting destructor reset at `0x004f4bb8`.
- Current MCP `xrefs_to 0x004f4b10 limit:20` returns data-table/vtable refs with `more:true`, confirming inherited/shared virtual-slot use and not ordinary direct calls.
- Current MCP confirms adjacent Application wrappers have ordinary code callers: `0x004f4b30` has four refs, `0x004f4b50` has seven refs, and `0x004f4b70` has two refs. That contrast helps separate UID000375 from the following Application wrapper cluster.

## Negative Evidence Summary

- No IDA function object exists at `0x004f4b20`; defining the target as a normal source method body would misrepresent current IDA/modeling evidence.
- No direct xrefs to `0x004f4b20` exist; there is no evidence for a named ordinary callable function entry, import, export, table slot, or direct call surface.
- Capped pointer scans find no little-endian dword references to `0x004f4b20`, `0x005568d0`, or `0x005568e0`; there is no evidence that the shim or helper starts are stored as explicit function pointers.
- `0x004f4b20` is not owned by the following Application wrappers. Those wrappers begin at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70`, use `g_pChangeMan`/`sub_47ED50` family calls, and have ordinary direct code callers.
- `0x004f4b20` is not padding. The byte sequence decodes to a coherent seven-instruction tail-jump shim and is the sole code edge to `0x005568e0`.
- `0x004f4b20` should not be assigned to [UID:00023R] as direct owner. UID00023R owns the shared helper island at `0x005568d0-0x00556907`; UID000375 is the object-facing shim that obtains the current object's runtime-class pointer through its vtable and forwards into that helper.
- `0x004f4b20` should not emit a standalone C++ function body with an invented name such as `LObjectRuntimeClassMembershipShim`. The source-level representation should be the `LObject` runtime-class membership API and runtime-class declaration/helper machinery; hand-writing an artificial wrapper would bake in IDA-shaped structure.
- Wave2/Wave3 artifacts were not used as evidence. Current by-* docs, executed reports, generated output headers, and current MCP evidence were used instead.

## Heuristic / Inference Reanalysis And Validation

- Raw no-function status: resolved. The target is not a modeled IDA function, but current bytes and disassembly prove a real executable shim. The correct documentation state is "raw runtime-class membership shim", not "unknown bytes", "padding", or a normal IDA function.
- Source-facing name: `LObjectRuntimeClassMembershipShim` is acceptable as a descriptive documentation token, but should not be presented as original symbol proof or a final standalone C++ function name. The source-facing API concept is an `LObject` runtime-class membership test, plausibly equivalent to a method such as `IsKindOf`/`IsDerivedFrom` in MFC-style runtime-class systems, but exact original spelling is not currently proven.
- Owner/emitter: keep direct class owner/emitter [UID:00007D]. The shim starts with `ecx` as an object, calls virtual slot `+4`, and therefore belongs to the class/runtime surface rather than the file-level helper island. Generated output still routes through [UID:0000KV] because the class emits to `NexusTK/util/LObject.cpp`.
- Helper relation: validated. UID000375 obtains the dynamic runtime-class record by calling vtable slot `+4`, then tail-jumps to UID00023R's base-chain helper at `0x005568e0`. UID00023R itself remains file-level runtime-class helper machinery under [UID:0000KV].
- Formal C++ route: the existing formal comment-only no-code marker is acceptable under current rules because it lives inside the formal `RECONSTRUCTION_CPP CODE` block and explains that no standalone shim body should be hand-authored. This is not a blank emitter problem for UID000375; generated `LObject.cpp` already includes the marker.
- Item summary blocker: unresolved in the page but implementation-ready. The target should receive a concise Item Summary recording exact raw-shim bytes/behavior, no function object, no direct xrefs, sole tail-jump to `0x005568e0`, LObject owner/emitter, and formal no-code marker.
- Score blocker: metadata can improve modestly after adding current MCP evidence and item summary. It should not move to `95+` because original runtime-class API naming, exact runtime-class struct declaration spelling, and header/source declaration shape remain inferred.
- Existing support docs are adequate for this target. They already record the LObject shell, vtable/runtime-class record, helper island, and generated output route. No mandatory support edit is needed unless the supervisor wants broader cleanup of blank Item Summary fields on sibling pages, which is outside UID000375-only scope.

## Ranked Ownership Analysis

### 1. [UID:00007D] LObject class

- Evidence for:
  - The shim's incoming receiver is `ecx`; the first data operation is `mov eax, [ecx]`.
  - The shim calls vtable slot `+4`, which [UID:0003OO] identifies as `LObject` runtime-class accessor slot and [UID:000371] documents as returning the runtime-class record.
  - LObject constructor/destructor/scalar deleting destructor are the only current xrefs to the `LObject` vtable base `0x0061cf68`.
  - [UID:00007D] and [UID:0000KV] already list UID000375 as part of the true LObject runtime shell.
  - Generated `auto-generated/NexusTK/util/LObject.cpp` includes UID000375 under the LObject source route.
- Evidence against:
  - The shim is not a normal modeled IDA function and has no direct xrefs.
  - It immediately tail-jumps into a file-level helper island, so it is glue for the runtime-class API rather than a body with rich `LObject` member logic.
- Decision:
  - Keep `CANONICAL_OWNER:00007D` and `EMITTER_UIDS:00007D`. The direct semantic owner is the LObject class/runtime surface.

### 2. [UID:0000KV] LObject source file

- Evidence for:
  - `by-file/LObject.md` is the source route for the LObject runtime shell.
  - UID00023R's helper island is file-owned by [UID:0000KV], and UID000375 tail-jumps into that island.
  - Generated output path for [UID:00007D] is `NexusTK/util/LObject.cpp`, owned by [UID:0000KV].
- Evidence against:
  - UID000375 begins with an object receiver and a virtual slot call, making class ownership narrower than direct file ownership.
  - Current metadata already uses class owner/emitter, matching sibling constructor/destructor/accessor pages.
- Decision:
  - Keep as source-file route/support, not direct canonical owner for UID000375.

### 3. [UID:00023R] CallbackAndListMembershipHelpers

- Evidence for:
  - UID000375 tail-jumps directly to UID00023R helper body at `0x005568e0`.
  - UID00023R documents the base-chain walk used by UID000375.
- Evidence against:
  - UID00023R is a separate address range and helper island.
  - UID000375 is the caller/forwarding shim that obtains the current object's runtime class. The helper does not own the shim's object-facing virtual call surface.
- Decision:
  - Keep as required support/callee relation only.

### 4. Following Application wrapper cluster

- Evidence for:
  - The next modeled function starts immediately at `0x004f4b30`, and the physical address island contains Application wrapper code.
- Evidence against:
  - Current bytes place UID000375 before `sub_4F4B30`.
  - Application wrappers use `g_pChangeMan` and have ordinary direct code callers; UID000375 has no direct xrefs and routes to runtime-class helper code.
- Decision:
  - Reject.

### 5. No-owner/non-emitting

- Evidence for:
  - The target has no IDA function object and no direct xrefs.
- Evidence against:
  - The byte semantics, runtime-class accessor/vtable record, helper relation, LObject parent docs, and generated output route are all strong enough for a direct owner/emitter.
- Decision:
  - Reject. This is not a no-owner or non-emitting case.

## Source Placement

- Recommended source placement: keep UID000375 under [UID:00007D][LObject](../../../by-class/LObject.md), emitted through [UID:0000KV][LObject](../../../by-file/LObject.md) to `NexusTK/util/LObject.cpp`.
- Source-shape interpretation: source should expose an LObject runtime-class membership operation and runtime-class declaration/helper machinery, not a named standalone function body corresponding one-to-one to raw bytes at `0x004f4b20`.
- The current formal marker is the right source-output form for this pass:
  - It is nonblank formal content, so generated output can preserve the target-specific no-code decision.
  - It avoids compiling artificial code for an unmodeled tail-jump shim.
  - It points future reconstruction toward the runtime-class API declaration.
- Rejected placements:
  - `Application.cpp`: following functions only.
  - `CallbackAndListMembershipHelpers` as direct owner: callee/helper, not object-facing shim.
  - `MemoryMan`: unrelated allocation wrappers in the same mixed island.
  - raw no-owner/non-emitting: evidence is too strong for LObject route.
- Remaining placement uncertainty:
  - Exact original API spelling for the runtime-class membership test is unresolved. This affects confidence and final header shape but not owner/emitter placement.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `85` | `87` | Current MCP refresh closes the raw/no-function evidence gap, reconfirms exact bytes, no direct xrefs, helper edge, runtime-class/vtable data, and adjacent boundaries. Adding Item Summary and no-code proof will make the page materially more complete. Cap below final because exact source API/type names remain unresolved. |
| `CONFIDENCE` | `88` | `91` | Current MCP agrees with target/support docs and generated output. The behavior is seven instructions with one tail-jump edge, and the runtime-class/vtable relationship is strongly corroborated. Cap below `95+` because original source spelling and declaration machinery are inferred. |
| `CANONICAL_OWNER` | `00007D` | `00007D` | LObject class remains the narrow direct semantic owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | The source runtime-class membership surface must be represented in the rebuilt source. |
| `EMITTER_UIDS` | `00007D` | `00007D` | Class-owned target already emits through `NexusTK/util/LObject.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No special ordering needed beyond existing LObject generated output route. |
| Formal C++ block | comment-only marker | keep existing marker | Existing formal marker is acceptable and should be preserved, with prose explaining why it is a no-code proof rather than C++ body. |

Score-improvement attempt:

- Raw/no-function blocker: resolved with current `lookup_funcs`, `get_bytes`, and `disasm`.
- LObject/runtime-class ownership blocker: resolved with current vtable/runtime-class xrefs and support docs; keep owner/emitter.
- Shared helper relation blocker: resolved with current `xrefs_to 0x005568e0` and helper disassembly.
- Source-facing name blocker: partially resolved. Descriptive page name is fine; exact API spelling remains unsafe. This caps score and supports no-code marker rather than body C++.
- Missing Item Summary blocker: implementation-ready target edit.
- Existing formal block acceptability blocker: resolved. Formal marker is acceptable because it is target-specific, in the formal block, and already appears in generated `LObject.cpp`.

## First-Draft C++ Recommendation

- Eligible for standalone C++ body: no.
- Recommended formal block: keep the existing formal comment-only marker exactly unless the supervisor prefers minor wording cleanup:

```cpp
// Runtime-class membership shim for 0x004f4b20-0x004f4b30.
// The binary calls the object's runtime-class virtual slot at +4 and tail-jumps
// to the shared base-chain helper at 0x005568e0. Source should express this via
// the LObject runtime-class membership API, not as a standalone shim function.
```

- Reason this preserves behavior: the binary behavior is already a compiler/runtime-shaped tail-jump shim. The actual final source should declare the runtime-class API and helper machinery so the equivalent shim/control flow is generated or represented at the correct abstraction level.
- Reason this matches likely original source shape: late-1990s/early-2000s C++ runtime-class systems usually express this as a base object API and class metadata declarations, not as a handwritten function named after a raw address shim.
- Inferred names used: `runtime-class membership shim`, `LObject runtime-class membership API`, `base-chain helper`. These are descriptive, not original-symbol proof.
- Exact no-code proof:
  - Current MCP proves no IDA function object at `0x004f4b20` and no direct xrefs to the shim start.
  - The seven-instruction body is glue: call virtual runtime-class accessor at slot `+4`, move the return into `ecx`, and tail-jump to the shared helper at `0x005568e0`.
  - The shared helper already owns the base-chain walk through offset `+0x0c`; duplicating that logic in UID000375 would be wrong.
  - Exact original runtime-class API spelling and metadata declaration type are not proven.
  - Generated `NexusTK/util/LObject.cpp` already carries the formal comment marker for UID000375 rather than an empty marker.
  - Therefore a standalone C++ function body would be decompiler-shaped and less source-faithful than the formal no-code marker.

Do not insert any illustrative C++ body outside the formal block.

## Recommended Target Doc Changes

Target path: `by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md`

Recommended edits:

- Set metadata to `COMPLETION:87`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00007D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007D`, blank emitter position.
- Keep the existing formal `RECONSTRUCTION_CPP CODE` comment-only marker; do not replace it with body C++.
- Fill `Item Summary` with a concise statement such as:
  - `Raw LObject runtime-class membership shim; current MCP confirms no IDA function at 0x004f4b20, exact seven-instruction body, no direct xrefs, sole tail-jump edge at 0x004f4b2b to 0x005568e0, class owner/emitter route, and formal no-code marker rather than standalone C++.`
- Add a current MCP evidence note dated 2026-07-02 for session `supervisor_resume_20260629` covering:
  - `server_health` ready state.
  - `lookup_funcs`: `0x004f4b20` not a function; neighboring `sub_4F4B10` size `0x6`; `sub_4F4B30` size `0x1c`; helper starts `0x005568d0`/`0x005568e0` not functions; next modeled helper `sub_556910` at `0x00556910` size `0x14a`.
  - exact bytes at `0x004f4b20-0x004f4b30`: `55 8b ec 8b 01 ff 50 04 8b c8 5d e9 b0 1d 06 00`.
  - exact disassembly of the shim.
  - `xrefs_to 0x004f4b20`: zero.
  - `xrefs_to 0x005568e0`: exactly one code xref from `0x004f4b2b`, with null owning function because the shim is raw.
  - `find_bytes` pointer scans for shim/helper starts: no matches under the capped scan.
  - runtime-class record/vtable evidence: `0x0061cf44` unique accessor xref from `0x004f4b10`; `0x0061cf68` xrefs from `0x004f4a80`, `0x004f4a90`, and `0x004f4bb8`.
- Add a source-quality/no-code proof section or expand `Confidence And Open Questions`:
  - Explain that `LObjectRuntimeClassMembershipShim` is a descriptive documentation token, not proven original symbol spelling.
  - Explain that source should represent this through the `LObject` runtime-class membership API and runtime-class declaration/helper machinery.
  - State that the existing formal comment-only marker is the correct formal output for this pass.
- Update `Score Rationale` to explain `87/91` and why the score should not go higher.
- Add a `2026-07-02 B012 source-quality recommendation` change entry preserving rejected alternatives:
  - not Application wrapper code;
  - not padding;
  - not direct UID00023R ownership;
  - not a standalone C++ body;
  - not no-owner/non-emitting.

## Recommended Support Doc Changes

- No mandatory support doc edits are required for this UID000375-only pass.
- [UID:00007D][LObject](../../../by-class/LObject.md), [UID:0000KV][LObject](../../../by-file/LObject.md), [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](../../../by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md), [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](../../../by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), and generated `NexusTK/util/LObject.cpp` already contain enough support context for this callback.
- Optional nonblocking future cleanup outside UID000375 scope: sibling exact LObject pages have blank Item Summary fields, and [UID:00007D] still has an empty class-level emitter marker in generated output. This report does not recommend editing those support docs for the UID000375 callback.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000375-001 | UID000375 is exactly raw bytes `0x004f4b20-0x004f4b30`; `0x004f4b20` is not an IDA function. | high | Current MCP `lookup_funcs`, `get_bytes`, `disasm`; target/support docs | UID000375 Raw Code Evidence / IDA MCP Evidence | incorporate | applied: target Raw Code Evidence records current `lookup_funcs`, boundary bytes, and no-function status. |
| C-000375-002 | The exact shim bytes are `55 8b ec 8b 01 ff 50 04 8b c8 5d e9 b0 1d 06 00`. | high | Current MCP `get_bytes 0x004f4b10 size 0x30` | UID000375 Raw Code Evidence | incorporate | applied: target Raw Code Evidence records the exact byte sequence. |
| C-000375-003 | The shim calls virtual slot `+4`, moves returned runtime-class pointer into `ecx`, and tail-jumps to `0x005568e0`. | high | Current MCP `disasm 0x004f4b20 max_instructions:10` | UID000375 Behavior / Raw Code Evidence | incorporate | applied: target Behavior remains and Raw Code Evidence adds the current exact disassembly. |
| C-000375-004 | Current MCP finds no direct xrefs to `0x004f4b20` and exactly one code xref to `0x005568e0` from `0x004f4b2b`. | high | Current MCP `xrefs_to` | UID000375 Callers And Relationships / IDA MCP Evidence | incorporate | applied: target Callers And Relationships includes current xref table with both facts. |
| C-000375-005 | Capped pointer scans found no pointer-table hits for `0x004f4b20`, `0x005568d0`, or `0x005568e0`. | medium-high | Current MCP `find_bytes` for little-endian pointer patterns with limit `20` | UID000375 Negative Evidence / IDA MCP Evidence | incorporate | applied: target Callers And Relationships records the capped pointer-scan negatives and their interpretation. |
| C-000375-006 | Runtime-class record/vtable context ties the shim to LObject: `0x0061cf44` has unique accessor xref from `0x004f4b10`, and `0x0061cf68` has refs from constructor/destructor/deleting destructor stores. | high | Current MCP `xrefs_to`, `get_bytes`; [UID:0003OO], [UID:000371] | UID000375 Ownership / Callers And Relationships | incorporate | applied: target records current runtime-class/vtable bytes and xrefs. |
| C-000375-007 | Direct owner/emitter should remain [UID:00007D] LObject; [UID:0000KV] is the source-file route. | high | Current MCP behavior, class/file docs, generated `LObject.cpp` | UID000375 Status / Reconstruction Notes | incorporate | applied: metadata remains `00007D`; target Source-Quality section records [UID:0000KV] as source-file route. |
| C-000375-008 | UID00023R is callee/helper support, not direct owner of UID000375. | high | Current MCP tail-jump relation; helper page owner route | UID000375 Ownership / Cross-References | incorporate | applied: target Source-Quality section explicitly rejects direct UID00023R ownership while preserving callee/helper relation. |
| C-000375-009 | The existing formal comment-only no-code marker is acceptable and should remain; no standalone C++ body should be emitted. | high | Current MCP raw/no-function/no-xref facts; generated `LObject.cpp` contains marker; B011 accepted support marker | UID000375 Reconstruction Notes / formal C++ block | incorporate | applied: formal block unchanged; target Reconstruction Notes now contain no-code proof. |
| C-000375-010 | Scores should move from `85/88` to `87/91` after adding current evidence and Item Summary, but stay below `95+` due unresolved original API/type spelling. | medium-high | Current MCP refresh, by-memory scoring rules, support docs | UID000375 metadata / Score Rationale | incorporate | applied: metadata is `87/91`; Score Rationale explains cap. |
| C-000375-011 | Rejected alternatives to preserve: padding, Application wrapper ownership, direct UID00023R ownership, no-owner/non-emitting, and standalone decompiler-shaped C++ body. | high | Current MCP bytes/xrefs/boundaries and support docs | UID000375 Negative Evidence / Changes | incorporate | applied: target Source-Quality and Changes sections preserve each rejected alternative. |

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: `goal.md` names Gate 1 audit `2026-07-02T16:40:18-04:00 - B012 UID000375 Callback Gate 1` and implementation callback assignment `B012-implement-000375-LObjectRuntimeClassMembershipShim-20260702`.
- [x] Target doc `by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md`: update metadata from `85/88` to `87/91`; keep `CANONICAL_OWNER:00007D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007D`, blank emitter position. Proof: target metadata now has `COMPLETION:87`, `CONFIDENCE:91`, unchanged owner/reconstructable/emitter fields, and blank emitter position.
- [x] Target doc: fill blank `Item Summary` with the raw LObject runtime-class membership shim summary, current no-function/no-xref/helper-edge evidence, class owner/emitter route, and formal no-code marker disposition. Proof: target Item Summary now records the raw shim, no IDA function, exact body, no direct xrefs, sole `0x004f4b2b -> 0x005568e0` edge, class route, and formal no-code marker.
- [x] Target doc: add current MCP evidence from session `supervisor_resume_20260629`, including health/ready state, function lookup results, exact bytes, exact disassembly, xref facts, pointer-scan negatives, runtime-class record/vtable xrefs, and adjacent boundary contrast with `sub_4F4B30`. Proof: target Raw Code Evidence and Callers And Relationships include each accepted current MCP fact.
- [x] Target doc: preserve and clarify the existing formal comment-only `RECONSTRUCTION_CPP CODE` marker; do not insert a standalone C++ body and do not add illustrative C++ outside the formal block. Proof: formal block is unchanged; only Reconstruction Notes prose was added.
- [x] Target doc: add or expand target-specific no-code proof explaining why the source should express this through LObject runtime-class membership API/declaration/helper machinery rather than an artificial shim function. Proof: target Reconstruction Notes contain the target-specific no-code proof.
- [x] Target doc: update `Score Rationale` for `87/91` and state why unresolved original runtime-class API/type spelling caps the score below `95+`. Proof: target Score Rationale table has Completion `87` and Confidence `91` rows with cap rationale.
- [x] Target doc: preserve rejected alternatives and negative evidence: not padding, not Application wrapper ownership, not direct UID00023R ownership, not no-owner/non-emitting, and not a standalone decompiler-shaped C++ body. Proof: target Source-Quality And Rejected Alternatives lists each rejection.
- [x] Support docs: no mandatory edits; verify during callback that [UID:00007D], [UID:0000KV], [UID:000195], [UID:00023R], [UID:000371], [UID:000373], and [UID:0003OO] already contain same-or-greater supporting context before deciding not to edit them. Proof: targeted `Select-String` verification found same-or-greater support context for UID000375 owner/helper relation, vtable/runtime-class record, and rejected adjacent ownership; no stale contradiction was found, so no support docs were edited.
- [x] Claim And Incorporation Ledger: update rows C-000375-001 through C-000375-011 from `proposed` to `applied`, `already-present`, or `excluded-with-reason` during implementation callback. Proof: ledger rows C-000375-001 through C-000375-011 are now `applied`.
- [x] Run scoped validator after accepted implementation callback from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md --apply --queue-timeout 240`. Proof: command completed with exit code `0`.
- [x] Record validator command id, command timestamp, exit code, `ok` count, warnings, completion/confidence updates, generated_refresh state, and any generated-output freshness check if generated `NexusTK/util/LObject.cpp` matters to the callback. Proof: validator command_id `000000004687`, command_timestamp `2026-07-02T16:45:13-04:00`, exit code `0`, `ok: 1`, warnings `0`; `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_rescore_recommended: 1`, `stats_row_remove: 1`; generated_refresh `deferred` with generated_refresh_command_id `000000004687` and generated_refresh_timestamp `2026-07-02T16:45:13-04:00`. Generated `auto-generated/NexusTK/util/LObject.cpp` refreshed to command `000000004687` / `2026-07-02T16:45:13-04:00` and now shows UID000375 `Completion:87 | Confidence:91`.
- [x] Generated report refresh expectation: validator-owned generated tracker/project stats may update after the target metadata change; do not manually edit generated reports, project-level reports, coverage reports, validator state, archives, or supervisor ledgers. Proof: no manual generated/project/coverage/tool/supervisor edits were made; validator reported projected stats updates and generated refresh.
- [x] Report execution/archive remains supervisor-owned. Do not run `execute_report`, dry-run/status/probing variants, lifecycle commands, manual report moves, or archive commands. Proof: no execution/lifecycle/archive/manual report-move command was run.

## Validator Results

- Command: `python .\tools\validator.py --mode file --file by-memory\0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md --apply --queue-timeout 240`
- `command_id`: `000000004687`
- `command_timestamp`: `2026-07-02T16:45:13-04:00`
- Exit code: `0`
- `ok`: `1`
- Warnings: none reported.
- Updates: `completion_update: 1`, `confidence_update: 1`, `projected_stats_update: 1`, `stats_rescore_recommended: 1`, `stats_row_remove: 1`.
- `generated_refresh`: `deferred`
- `generated_refresh_command_id`: `000000004687`
- `generated_refresh_timestamp`: `2026-07-02T16:45:13-04:00`
- Generated freshness: `auto-generated/NexusTK/util/LObject.cpp` refreshed to validator command `000000004687` at `2026-07-02T16:45:13-04:00` with UID000375 shown as `Completion:87 | Confidence:91`.

## Changed Files

- Created earlier during report-only pass: `tools/leaser/Agents/Agent-B012/research/000375-LObjectRuntimeClassMembershipShim-source-quality.md`
- Modified during callback: `by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md`
- Modified during callback: `tools/leaser/Agents/Agent-B012/research/000375-LObjectRuntimeClassMembershipShim-source-quality.md`
- Support docs edited: none; verified as already same-or-greater detail.
- Leases: acquired and released `by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md`; post-release lease table has no active B012 lease for UID000375. Other agents may hold unrelated leases.
- Report execution: not run; supervisor-only after Gate 2 implementation verification.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004699","destination_path":"executed-b-agent-research/B012/000375-LObjectRuntimeClassMembershipShim-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/000375-LObjectRuntimeClassMembershipShim-source-quality.md","timestamp":"2026-07-02T16:54:52-04:00","uid":"000375"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
