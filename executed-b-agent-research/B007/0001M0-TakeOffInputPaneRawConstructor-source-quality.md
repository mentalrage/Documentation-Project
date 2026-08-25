** TARGET-REPORT-UID:0001M0 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B007 Source-Quality Report: UID 0001M0 - TakeOffInputPaneRawConstructor

Assignment: `B007-report-0001M0-take-off-input-pane-raw-constructor-20260625`

Target: [UID:0001M0] `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`

Report path: `tools/leaser/Agents/Agent-B007/research/0001M0-TakeOffInputPaneRawConstructor-source-quality.md`

Report-only result: no target/support by-* docs, generated files, project-level files, coverage reports, validator state/cache, IDA DB state, or leases were touched. This report is the only file created in this pass.

## Finalized Report / Current Recommendation

- Current recommendation: accept [UID:0001M0] as source-ready first-draft `TakeOffInputPane::TakeOffInputPane()` constructor C++ while preserving the raw-start/no-route caveat as a confidence cap.
- Final disposition: raise target metadata from `86/88` to `88/90`; preserve `CANONICAL_OWNER:0000EC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Required action: update the target and support docs after supervisor validation; insert the exact formal C++ block listed below into the target only during an implementation callback.
- Confidence: high for constructor semantics, owner, source route, range, vtable identity, and no-route evidence; capped below final-audit range by no direct raw-start route, unresolved original prompt-id constant spelling, and stale generated/cache output.

## Target

- Target UID: `0001M0`.
- Target path: `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`.
- Source queue row: `auto-generated/-ag-research-tracker.md` -> by-memory not-covered reconstructable row still shows stale generated state `74/84`.
- Current target source header: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000EC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EC`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current Item Summary: `Raw constructor-shaped TakeOffInputPane bytes with prompt id 0x22, CharInputPane base construction, exact vtable stores, no function/xref record, and boundary caveats.`
- Direct class parent: [UID:0000EC] `by-class/TakeOffInputPane.md`, currently `88/86`.
- Source route: [UID:0000KC] `by-file/ItemActionInputPanes.md`, currently `90/85`, generated path `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.

## Current Target State

The target already documents the 64-byte raw constructor-shaped body, exact prompt id, `CharInputPane` base-constructor call, three `TakeOffInputPane` vtable stores, no IDA function object, no direct xref, no raw pointer hit, and inline command-factory mirror at `0x005aa0c0`.

The stale part is the disposition that formal C++ must remain blank because raw-start liveness/source-form proof is missing. That was reasonable as support-scope text in B002's [UID:0001M1] aggregate implementation, but it is no longer the best target-specific conclusion. Current by-structure code-entry rules allow eligible emitter targets above the combined-score gate when behavior, boundaries, dependencies, and source shape are documented. Current accepted constructor precedents, especially [UID:0003O5] `SelfSaveInputPane::SelfSaveInputPane()` and [UID:0001KS] `QuitInputPane::QuitInputPane`, treat "no direct raw-start route" as a confidence cap, not as a no-code proof, when the body is a complete constructor with a confirmed owner/emitter route.

Current generated output is stale relative to source docs. `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`, refreshed by validator command `000000000889` at `2026-06-25T01:33:25-04:00`, still contains an empty marker for [UID:0001M0] with `Completion:74 | Confidence:84`. `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` also still render `74/84`. The source target header is the authority for this report, and implementation must use a scoped target validator with generated refresh to correct generated state.

## Supervisor Active Recheck

- The current user instruction resumes the report-only [UID:0001M0] assignment from `Agent-B007/goal.md`.
- The target is not a split-execution assignment. No by-* docs may be edited until a supervisor validates this report and sends an implementation callback.
- MCP was mandatory. MCP was responsive and used for the current evidence pass, session `80de0a67`.
- No leases were taken because report-only research does not require leases.

## Inference Guidance / Stale Source Check

- Current `by-structure.md` rules were applied: [UID:0001M0] is eligible for formal C++ because it is reconstructable, has a confirmed emitter route, and clears the current combined-score gate; the rule does not require the older `95/95` threshold.
- Existing by-* docs, generated output, and the executed B002 report were treated as leads and rechecked against current MCP before changing the disposition.
- Generated output is stale for this target and is not treated as authority.
- No current Wave2/Wave3 material was used as proof. The referenced `source-3/simroot_v2` folder was absent in this worktree, so no simroot evidence was used.
- Direct IDA facts are separated from source-shape inference: bytes, instruction decoding, xrefs, function lookup, decompile failure, factory decompile, vtable refs, and PE route scans are facts; the conclusion that the formal source should be a thin constructor initializer is source-shape inference supported by those facts and accepted project precedents.

## Evidence Checked

### MCP Provenance

- JSON-RPC id `1`: `initialize` returned protocol `2025-06-18` and server `ida-pro-mcp`.
- JSON-RPC ids `3`, `5`, and `10`: `tools/list` confirmed current schemas for `idb_list`, `server_health`, `lookup_funcs`, `get_bytes`, `xrefs_to`, `find_bytes`, `find`, `insn_query`, `decompile`, and `int_convert`.
- JSON-RPC id `4`: `idb_list` reported active session `80de0a67`, file `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, `is_active:true`, `is_analyzing:false`, worker PID `26892`.
- JSON-RPC id `11`: `server_health(database=80de0a67)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- JSON-RPC id `12`: `lookup_funcs` for `0x005b26d0`, `0x005b26e0`, `0x005b2720`, `0x005aa0c0`, `0x004f0350`, `0x004f28a0`, `0x005b27c0`, `0x005b2830`, and `0x005b7940`.
- JSON-RPC id `13`: `get_bytes` for `0x005b26d0+0x50`, `0x005b26e0+0x40`, and `0x005b2720+0x10`.
- JSON-RPC id `14`: `xrefs_to` for `0x005b26e0`, `0x0062f92c`, `0x0062f97c`, `0x0062f9ac`, `0x004f28a0`, and `0x004f0350`.
- JSON-RPC id `15`: `find_bytes` for VA pointer pattern `e0 26 5b 00` and RVA pointer pattern `e0 26 1b 00`.
- JSON-RPC id `16`: `find type=code_ref` for `0x005b26e0`.
- JSON-RPC id `17`: `find type=immediate` for `0x005b26e0`, `0x1b26e0`, and `0x22`.
- JSON-RPC id `18`: `insn_query` over `0x005b26e0-0x005b2720`.
- JSON-RPC id `19`: `decompile 0x005b26e0`, expected failure because no function object exists.
- JSON-RPC id `20`: `decompile 0x005aa0c0`, confirming the inline command-factory construction mirror.
- JSON-RPC ids `21` and `22`: `int_convert` verified `0x22 = 34`, `0x40 = 64`, `0xa0 = 160`, `0xa4 = 164`, `0x108 = 264`, `0x80 = 128`, `0x1b26e0 = 1779424`, and `0x1b1ae0 = 1776352`.

### Documentation And Generated Leads Checked

- Target [UID:0001M0] `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`.
- Aggregate sibling [UID:0001M1] `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`.
- Exact method children [UID:00041L] `TakeOffInputPaneHandleTakeOffShortcut` and [UID:00041M] `TakeOffInputPaneProcessUnequipCommand`.
- Helper [UID:0001M2] `by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md`.
- Class parent [UID:0000EC] `by-class/TakeOffInputPane.md`.
- File route [UID:0000KC] `by-file/ItemActionInputPanes.md`.
- Vtable support [UID:0001XU] `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`.
- Base constructor [UID:000363] `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md` and [UID:00001P] `by-class/CharInputPane.md`.
- Language lookup/global docs for `LanguageMan::GetLocalizedString` and `g_pLanguageMan`.
- Constructor precedents: [UID:0003O5] `SelfSaveInputPaneConstructorRaw`, [UID:0001KS] `QuitInputPaneConstructor`, and related SelfSave/Quit support docs.
- Generated output `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Generated tracker/coverage rows for [UID:0001M0].
- Executed B002 report `executed-b-agent-research/B002/0001M1-TakeOffInputPane-source-quality.md` as a lead only; current MCP session `80de0a67` rechecked the target-specific facts.

`source-3/simroot_v2` was not present in this worktree, so no simroot lead was used as evidence. That absence is not a blocker because current MCP, current by-* docs, and generated validator output are sufficient.

### Supplemental PE Scan

A read-only PowerShell PE scan of `E:\NTK\Resources\NexusTK\NexusTK.exe` was used as supplemental negative route evidence, not as a substitute for MCP:

- File length: `2679296`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Image base: `0x400000`.
- `.text` VA: `0x401000`; raw pointer `0x400`; raw size `0x20b600`.
- Target VA: `0x005b26e0`; target RVA: `0x1b26e0`; target file offset: `0x1b1ae0`.
- VA pointer pattern `e0 26 5b 00`: zero hits.
- RVA pointer pattern `e0 26 1b 00`: zero hits.
- rel32 `call`/`jmp` to `0x005b26e0` in `.text`: zero hits.

## IDA MCP Facts

### Function And Boundary Facts

`lookup_funcs` in session `80de0a67` reports:

| Query | Current result |
| --- | --- |
| `0x005b26d0` | Not a function |
| `0x005b26e0` | Not a function |
| `0x005b2720` | `sub_5B2720`, size `0x93` |
| `0x005aa0c0` | `sub_5AA0C0`, size `0x80` |
| `0x004f0350` | `sub_4F0350`, size `0x22` |
| `0x004f28a0` | `sub_4F28A0`, size `0x73` |
| `0x005b27c0` | `sub_5B27C0`, size `0x67` |
| `0x005b2830` | `sub_5B2830`, size `0x13b` |
| `0x005b7940` | `sub_5B7940`, size `0x3b` |

The exact target range is still `0x005b26e0-0x005b2720`, size `0x40` / 64 bytes (verified with MCP `int_convert`). It ends at the byte before the modeled `0x005b2720` method. The predecessor window `0x005b26d0-0x005b26df` contains `4f 01 00` followed by thirteen `0xcc` bytes, so this page must not absorb predecessor material or padding. The successor starts with a fresh prologue at `0x005b2720`.

### Raw Constructor Bytes And Instructions

`get_bytes 0x005b26e0+0x40` returned:

```text
55 8b ec 51 56 8b f1 8b 0d 50 a7 67 00 6a 22 89
75 fc e8 59 dc f3 ff 50 8b ce e8 a1 01 f4 ff c7
06 2c f9 62 00 8b c6 c7 86 a0 00 00 00 7c f9 62
00 c7 86 a4 00 00 00 ac f9 62 00 5e 8b e5 5d c3
```

`insn_query 0x005b26e0-0x005b2720` decoded 20 instructions with no owning IDA function:

| Address | Operation | Source meaning |
| --- | --- | --- |
| `0x005b26e0-0x005b26e5` | constructor prologue, save `this` in `esi` | ordinary thiscall constructor shape |
| `0x005b26e7` | load `dword_67A750` | `g_pLanguageMan` consumer |
| `0x005b26ed` | push `0x22` | take-off localized prompt id, decimal `34` |
| `0x005b26f2` | call `0x004f0350` | `LanguageMan::GetLocalizedString` / equivalent lookup |
| `0x005b26f7-0x005b26fa` | push returned text, set `ecx=this`, call `0x004f28a0` | `CharInputPane::CharInputPane(const wchar_t *)` |
| `0x005b26ff` | store `0x0062f92c` at `this+0x00` | primary `TakeOffInputPane` vptr, compiler output |
| `0x005b2705` | move `this` to `eax` | constructor return value |
| `0x005b2707` | store `0x0062f97c` at `this+0xa0` | secondary vptr, compiler output |
| `0x005b2711` | store `0x0062f9ac` at `this+0xa4` | tertiary vptr, compiler output |
| `0x005b271b-0x005b271f` | restore and return | plain `ret`, no explicit source parameters |

`decompile 0x005b26e0` failed with `Decompilation failed at 0x5b26e0`, matching the no-function state.

### Xrefs And Route Negatives

`xrefs_to 0x005b26e0` returned `xref_count:0`.

`find_bytes` returned zero matches for both raw-start pointer encodings:

| Pattern | Meaning | MCP result |
| --- | --- | --- |
| `e0 26 5b 00` | absolute VA `0x005b26e0` | 0 matches |
| `e0 26 1b 00` | RVA `0x1b26e0` | 0 matches |

`find type=code_ref 0x005b26e0` returned zero matches. `find type=immediate` returned zero matches for both `0x005b26e0` and `0x1b26e0`. The same immediate search for `0x22` returned 34 matches across the binary, so the prompt id alone is not a unique route or owner proof.

The supplemental PE scan also found zero absolute VA pointer hits, zero RVA pointer hits, and zero rel32 `call`/`jmp` instructions targeting `0x005b26e0`.

### Vtable And Class Identity

`xrefs_to` for the three `TakeOffInputPane` vtable bases returned exactly three refs each:

| Vtable base | Current xrefs | Meaning |
| --- | --- | --- |
| `0x0062f92c` | `0x005a6ca4`, `0x005aa116`, `0x005b26ff` | UserPane dispatcher store, inline factory store, raw constructor store |
| `0x0062f97c` | `0x005a6cac`, `0x005aa11c`, `0x005b2707` | UserPane dispatcher store, inline factory store, raw constructor store |
| `0x0062f9ac` | `0x005a6cb6`, `0x005aa126`, `0x005b2711` | UserPane dispatcher store, inline factory store, raw constructor store |

This proves the body constructs `TakeOffInputPane`, not a base `CharInputPane`, generic item prompt, or adjacent class. The three vptr writes are compiler-emitted effects of the class declaration and inheritance layout, not source statements to emit manually.

### Inline Factory Mirror

`decompile 0x005aa0c0` models a command-factory construction path that:

- allocates `0x108` / 264 bytes,
- reads `dword_67A750`,
- calls `0x004f0350` with id `34` / `0x22`,
- calls `0x004f28a0` for `CharInputPane` construction,
- stores the same three `TakeOffInputPane` vtables at `0x005aa116`, `0x005aa11c`, and `0x005aa126`,
- returns the constructed pointer or null after allocation failure.

This mirror strengthens the source-level constructor shape. It does not create a direct route to raw start `0x005b26e0`; the raw start remains retained/no-route. In source, a factory should eventually be represented as `new TakeOffInputPane` or equivalent, not as manual vtable stores.

## Positive Evidence Summary

- The target is a complete 64-byte constructor-shaped body with normal thiscall prologue/return.
- It has exact in-range behavior: `g_pLanguageMan` lookup of prompt id `0x22`, `CharInputPane` base construction, return `this`, and compiler vtable stores.
- Vtable stores identify the derived class as `TakeOffInputPane` through IDA-decorated vtable names and stable support docs.
- The class parent [UID:0000EC] and file route [UID:0000KC] both clear the current by-structure assignment gate.
- The emitter route is already present and eventually surfaces to `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Current constructor precedents in this project accept first-draft constructor C++ for complete raw retained constructors even when no direct raw-start route exists, provided the no-route caveat is documented.
- The no direct route state is well proved, so the report can preserve it as a score/confidence cap without using it as a no-code proof.

## Negative / Counter-Evidence Summary

- IDA still does not model `0x005b26e0` as a function.
- `decompile 0x005b26e0` fails.
- MCP xrefs, code-ref search, immediate search, VA pointer search, RVA pointer search, and supplemental PE rel32 scan all find no route to the raw start.
- The prompt id `0x22` appears as a non-unique immediate elsewhere, so the id alone does not prove ownership.
- The exact current `STR.RES` English text for id `0x22` is not documented in current resource pages and was not recovered in this pass; the source should use the id, not an invented literal.
- The generated output is stale and still has an empty marker for [UID:0001M0].
- No evidence proves the original source spelling of the prompt-id constant. `kTakeOffPromptStringId`, a broader localized-string enum, or a literal id are all plausible source spellings.

## Heuristic / Inference Reanalysis And Validation

### Raw helper role and liveness

Best inference: [UID:0001M0] is a retained out-of-line `TakeOffInputPane` constructor body. It is source-authored behavior even though current IDA has no function object and no route.

Rejected alternatives:

- Padding or accidental bytes: rejected because the byte sequence is executable constructor-shaped code ending in `ret`, calls real project constructors/helpers, and writes class vtables.
- Direct live callgraph anchor: rejected because every current route search is negative.
- Factory-owned body: rejected because the factory at `0x005aa0c0` duplicates construction after allocation; it does not own or replace this constructor page.

Score/C++ impact: no-route remains a confidence cap, but it is not a no-code proof for this exact constructor page.

### Placeholder/generated names

Source-facing replacements:

- `dword_67A750` -> `g_pLanguageMan`, with support from [UID:0000RC] / [UID:0001OS].
- `sub_4F0350` -> `LanguageMan::GetLocalizedString` or equivalent `GetString`; current project docs favor `GetLocalizedString` for formal first-draft constructor code.
- `sub_4F28A0` -> `CharInputPane::CharInputPane(const wchar_t *promptText)`.
- `TakeOffInputPaneRawConstructor` -> documentation filename only; source-facing constructor is `TakeOffInputPane::TakeOffInputPane()`.
- vtable names remain IDA/evidence labels; source should not emit vptr assignments.

### Prompt id

Best inference: prompt id `0x22` is the take-off prompt id used by both the retained raw constructor and the inline factory mirror. It should be represented as the source argument to `LanguageMan::GetLocalizedString`.

Rejected alternatives:

- Hard-code English prompt text: rejected because current resource docs do not map id `0x22` to text in this pass.
- Name a final constant with original spelling: rejected because original source spelling is not proved.
- Leave `sub_4F0350(..., 34)` in final C++: rejected because project docs now have a source-facing language-manager name.

For the formal first-draft block, the safest exact behavior is the numeric id `0x22`. A support note can say a later project-wide localized-string enum may replace it.

### Source placement

Best placement: direct class owner [UID:0000EC] `TakeOffInputPane`, emitting through [UID:0000EC] to [UID:0000KC] `ItemActionInputPanes.cpp`.

Rejected placements:

- [UID:0000KC] as canonical owner: too broad for a constructor that constructs one class, though it remains the correct file route.
- [UID:0000K7] `InputPanes` or [UID:00001P] `CharInputPane`: they own the reusable base constructor only.
- [UID:0000P1] `UserPane`: dispatcher/factory consumer only.
- [UID:0001M1] aggregate: sibling method island; it should reference this constructor child, not absorb its C++.
- No-owner/non-emitting: rejected by class vtable identity, class parent gate, and existing emitter route.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x005b26e0-0x005b2720` is a complete `TakeOffInputPane` constructor body. | High | Current bytes/instructions, `CharInputPane` call, `this` return, three TakeOff vtable stores, inline factory mirror. | No function object, no xrefs, no pointer/rel32 route. | Original liveness route remains unknown. |
| Direct owner is [UID:0000EC] `TakeOffInputPane`. | High | Vtable names/bases, class docs, factory mirror, sibling method/vtable family. | File-level and base-class alternatives checked. | Original source file grouping is still inferred through current project docs. |
| Formal constructor C++ is now acceptable. | High | Complete constructor behavior, current code-entry gate, existing emitter route, accepted raw-constructor precedents. | Old target no-code rationale and B002 support-scope text checked. | Prompt constant spelling and direct route remain caps, not blockers. |
| Vtable stores should not be emitted manually. | Confirmed source-shape inference | Normal C++ constructor compiler output and current project vtable docs. | Manual-vtable source alternative rejected as decompiler-shaped. | None for first-draft source. |

## Ranked Ownership / Source Placement Analysis

### 1. [UID:0000EC] `TakeOffInputPane` class owner - accepted

Evidence for:

- The raw body installs `TakeOffInputPane` primary, secondary, and tertiary vtable views.
- The body constructs the single-character prompt for this class.
- The class doc already owns the raw constructor, shortcut method, command method, destructor path, and scalar deleting destructor context.
- Parent and child both clear the strict assignment gate.

Evidence against:

- No direct route to the raw constructor start is known.

Decision: accept. The no-route condition caps confidence but does not defeat class ownership or first-draft constructor source shape.

### 2. [UID:0000KC] `ItemActionInputPanes` file owner - route only

Evidence for:

- The file page owns the item-action prompt source family and the generated output route.
- The inline factory and dispatcher construction sites are in the broader item-action/UserPane command area.

Evidence against:

- A class constructor's direct semantic owner is the class, not the source file root, when the class parent clears the gate.

Decision: keep as route through [UID:0000EC], not canonical owner.

### 3. [UID:00001P] `CharInputPane` / [UID:0000K7] `InputPanes` - rejected

Evidence for:

- The body calls `CharInputPane::CharInputPane(const wchar_t *)`.

Evidence against:

- The derived vtable stores are `TakeOffInputPane`, and the prompt/command behavior belongs to item-action equipment removal.

Decision: base-constructor dependency only.

### 4. [UID:0000P1] `UserPane` dispatcher/factory context - rejected

Evidence for:

- `0x005a5bd0` and `0x005aa0c0` contain construction stores for this class.

Evidence against:

- Those are consumer/factory sites. They do not own the class constructor body.

Decision: consumer evidence only.

## Range / Split / Padding / Reclassification Analysis

- Preserve exact range `0x005b26e0-0x005b2720`.
- Do not merge predecessor bytes at `0x005b26d0-0x005b26df`; current byte read shows non-padding `4f 01 00` before thirteen `0xcc` bytes.
- Do not merge successor [UID:0001M1] at `0x005b2720`.
- No split is needed inside the target. The 20 decoded instructions form one constructor-shaped body.
- Entity kind should remain raw constructor / retained constructor body, not IDA function. The source-facing name should be `TakeOffInputPane::TakeOffInputPane()`.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The target is reconstructable, has a confirmed emitter route, has combined score above the current code-entry gate, and current evidence documents the body, boundary, owner, dependencies, route negatives, and source-shape limitations.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
TakeOffInputPane::TakeOffInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0x22))
{
}
```

Reason it preserves exact original behavior:

- The raw body reads `g_pLanguageMan`, passes id `0x22` to the language lookup, passes the returned text pointer to `CharInputPane::CharInputPane`, returns `this`, and has no explicit source parameters or source-authored body statements after base construction.
- The vptr stores are compiler output from constructing the derived class; omitting manual vptr assignments is the correct C++ source shape.
- The inline factory mirror at `0x005aa0c0` performs the same construction sequence after allocation, which is consistent with source that constructs `TakeOffInputPane`.

Reason it matches plausible original mid-2000s source shape:

- Thin item-action input-pane constructors in this codebase are simple derived constructors that pass a localized prompt to `CharInputPane`.
- Existing accepted constructors use `g_pLanguageMan->GetLocalizedString(...)` or an equivalent language lookup wrapper.
- A literal `0x22` is used here instead of a made-up prompt-text literal or unproved original constant spelling. A future implementation may replace it with a project-wide localized-string-id enum only after that convention is established.

No-code proof is rejected for this target. The only strong no-code argument is no direct raw-start route; current accepted raw-constructor precedents show that condition is a confidence cap when the body is complete, unique, class-owned, and source-ready.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`.

Required target updates if accepted:

- Set `COMPLETION:88` and `CONFIDENCE:90`.
- Preserve `CANONICAL_OWNER:0000EC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EC`, and blank `EMITTER_POSITION_OPTIONAL`.
- Replace Item Summary with concise source-quality text, for example: `Constructs TakeOffInputPane with localized prompt id 0x22 and a CharInputPane base; vtable stores are compiler output.`
- Replace stale no-code wording with: formal first-draft constructor C++ is present; no direct raw-start route remains a confidence cap rather than a no-code proof.
- Insert the exact formal C++ block from this report.
- Add current MCP session `80de0a67` evidence at report-level detail: health/session, lookup, bytes, instruction query, xrefs, decompile failure, factory mirror, route-negative searches, int conversions, and generated stale state.
- Add supplemental PE scan evidence: SHA-256, target file offset, zero VA/RVA pointer hits, and zero rel32 call/jump hits.
- Preserve rejected alternatives: padding, base-class ownership, file-root ownership, UserPane ownership, manual vptr stores, literal prompt text invention, and no-owner/non-emitting.
- Preserve exact range boundary and predecessor/successor caveats.

## Recommended Support Doc Changes

Required if accepted:

- `by-class/TakeOffInputPane.md`: update the raw constructor row/notes to state [UID:0001M0] now has formal first-draft constructor C++, while no direct raw-start route remains documented. Keep the class-level formal C++ block blank if broader class declarations/method names remain policy-blocked.
- `by-file/ItemActionInputPanes.md`: update the `TakeOffInputPane` row and boundary notes so [UID:0001M0] is source-ready first-draft constructor C++ through the `ItemActionInputPanes.cpp` route after validator refresh. Preserve that [UID:0001M1] aggregate remains blank-C++ and [UID:0001M2] remains the file-level helper.
- `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`: update the raw constructor covered-range row/support note to say [UID:0001M0] is now a source-ready constructor child, not just a blank raw evidence page. Preserve [UID:0001M1]'s aggregate no-code proof.
- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: update the reconstruction note for [UID:0001M0] so "not an IDA function-boundary anchor" does not read as "no formal constructor C++." It should say the raw start remains no-route/no-function but may now be used as source-ready constructor evidence.

Check-only unless contradiction is found:

- `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md` and `by-class/CharInputPane.md`: already support `CharInputPane::CharInputPane(const wchar_t *)`; optional future support sync can add [UID:0001M0] as another concrete consumer.
- `by-global/g_pLanguageMan.md` and `by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md`: already document broad prompt-constructor consumers and exact lookup children. Optional sync can add [UID:0001M0] as a current prompt id `0x22` consumer.
- `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md`: no contradiction expected; source helper name supports the recommended code.
- Generated files and generated reports: do not edit manually; rely on target validator refresh.

## Score And Metadata Recommendation

Current target metadata:

```text
COMPLETION:86
CONFIDENCE:88
CANONICAL_OWNER:0000EC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EC
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000EC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000EC
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: populated with first-draft constructor C++
```

Completion `88`: the target has exact bytes, exact boundary, current MCP provenance, no-route evidence, PE route scan, constructor semantics, owner/emitter route, source-ready formal C++, and support-doc update plan. It remains below final-audit range because no direct raw-start liveness route is known, generated output is stale, and the exact original prompt-id constant spelling/text is unresolved.

Confidence `90`: current MCP and PE checks strongly confirm every material behavior and negative route fact. Confidence remains below `95+` because IDA has no function object, no caller route is known, original names are inferred, and generated output must still be refreshed.

No owner/emitter change is recommended. [UID:0000EC] remains the direct semantic class owner, and [UID:0000KC] remains the generated source file route through the class.

## Open Questions With Attempted Resolution

- Direct raw-start route: unresolved after MCP xrefs, MCP code-ref/immediate/pointer searches, and supplemental PE VA/RVA/rel32 scan all returned zero. Score impact: caps confidence; does not block constructor C++.
- Original localized prompt-id constant spelling: unresolved. The code should use `0x22` now and avoid inventing a final constant name. Score impact: minor source-quality cap.
- Current English `STR.RES` text for id `0x22`: unresolved in current docs/resource leads. The code should not hard-code a guessed English literal. Score impact: minor completion cap.
- Generated output/cache stale state: generated C++ and generated tracker/coverage rows still show `74/84` empty marker. Implementation must run target validator with generated refresh. Score impact: implementation verification requirement, not a source behavior blocker.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit `by-memory/-coverage-report.md`, `auto-generated/-ag-*`, or tracker files in the B-agent implementation callback.

If the supervisor still needs the legacy manual `by-memory/-coverage-report.md` row synchronized after implementation, replace the current [UID:0001M0] row with:

```text
    - [UID:0001M0][0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor](by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md) 0x005b26e0-0x005b2720 | raw constructor | TakeOffInputPane::TakeOffInputPane : reconstructable : 88% : very strong : Source-ready retained TakeOffInputPane constructor; current MCP session `80de0a67` confirms exact `0x40` bytes, no IDA function/decompile/xref route, prompt id `0x22` through `g_pLanguageMan->GetLocalizedString`, `CharInputPane` base construction, compiler-emitted vptr stores at `+0/+0xa0/+0xa4`, three-vtable class identity, `0x005aa0c0` inline factory mirror, zero VA/RVA pointer hits, and zero PE rel32 call/jump hits; formal first-draft constructor C++ is ready while no-route and prompt-id spelling remain confidence caps.
```

No auto-generated tracker text should be supplied. After implementation and supervisor execution of this report, `auto-generated/-ag-research-tracker.md` should refresh through validator-owned report execution.

## Expected Validators After Accepted Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited by-* file:

> Executable block R001 was removed from this report and preserved verbatim in [0001M0-TakeOffInputPaneRawConstructor-source-quality-removed.md](0001M0-TakeOffInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If edited:

> Executable block R002 was removed from this report and preserved verbatim in [0001M0-TakeOffInputPaneRawConstructor-source-quality-removed.md](0001M0-TakeOffInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional check-only support docs are edited to remove a contradiction, run the corresponding scoped file validator for each one.

## Follow-Up Actions

- Supervisor: validate or reject the report direction, especially the change from no-code to first-draft constructor C++ despite no direct raw-start route.
- Implementation callback, if accepted: update target/support docs under short leases only, run the scoped validators above, confirm generated `ItemActionInputPanes.cpp` refresh no longer shows the stale [UID:0001M0] empty marker, and update this checklist with proof.
- Supervisor-owned coverage/tracker: apply the manual `by-memory/-coverage-report.md` replacement row only if the legacy manual report still needs synchronization outside validator-owned generated reports.

## Confidence

- Recommendation confidence: high. Current MCP session `80de0a67` and supplemental PE scanning agree on both the constructor semantics and the no-route negative evidence.
- Score confidence: high for `88/90`; the target is now source-ready but remains below final-audit range because no raw-start route, original prompt-id constant spelling, and generated refresh state remain unresolved.
- Residual risk: a future source-style pass could replace literal `0x22` with a project-wide localized-string enum, but that does not change behavior or block first-draft constructor C++.

## Changed Files

Created:

```text
tools/leaser/Agents/Agent-B007/research/0001M0-TakeOffInputPaneRawConstructor-source-quality.md
```

Not edited:

- `by-memory/0x005b26e0-0x005b2720.TakeOffInputPaneRawConstructor.md`
- `by-class/TakeOffInputPane.md`
- `by-file/ItemActionInputPanes.md`
- `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`
- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
- generated files, project-level files, coverage reports, validator state/cache, and IDA DB

Validators run: none during report-only research.

Leases used: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report for implementation in the 2026-06-25 callback and supplied accepted disposition plus validator minimums.
- [x] Target metadata: set [UID:0001M0] to `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000EC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EC`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target readback after validator `000000000942` shows `88/90`, owner `0000EC`, reconstructable true, emitter `0000EC`, and blank optional position.
- [x] Target Item Summary: replace with concise source-quality summary equivalent to `Constructs TakeOffInputPane with localized prompt id 0x22 and a CharInputPane base; vtable stores are compiler output.` Proof: B007 reproduced the generated-refresh rewrite with target validators `000000000939` and `000000000942`; supervisor then restored the accepted source summary and validated it with UID-only scoped validator `000000000951` (`2026-06-25T02:19:53-04:00`, exit `0`, ok `1`, generated refresh skipped) to avoid the known generated-refresh metadata rewrite.
- [x] Target formal C++: insert exactly the `TakeOffInputPane::TakeOffInputPane()` `RECONSTRUCTION_CPP CODE` block from this report; do not add body-only/sample/prose-only C++ elsewhere. Proof: target and generated `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` after command `000000000942` contain the exact constructor block.
- [x] Target no-code/status wording: replace stale blank-C++/no-route wording with first-draft C++ readiness; preserve no direct raw-start route as a confidence cap. Proof: target `Status`, `IDA Evidence`, `First-Draft C++`, and `Score Rationale` sections now state formal first-draft source C++ is present while the no-function/no-route result remains a confidence cap.
- [x] Target evidence sections: add current MCP session `80de0a67` health, lookup, bytes, instruction query, xrefs, route-negative searches, decompile failure, inline factory mirror, int conversions, generated stale state, and supplemental PE scan facts at report-level detail. Proof: target `IDA Evidence` includes the accepted MCP session and PE-scan evidence.
- [x] Target source-quality naming: normalize `dword_67A750` to `g_pLanguageMan`, `sub_4F0350` to `LanguageMan::GetLocalizedString`, `sub_4F28A0` to `CharInputPane::CharInputPane(const wchar_t *)`, and `TakeOffInputPaneRawConstructor` to source-facing `TakeOffInputPane::TakeOffInputPane()` while retaining raw labels as search/evidence aliases only. Proof: target names use source-facing labels in formal C++ and prose, with raw labels retained only as aliases/evidence.
- [x] Target range/split: preserve exact `0x005b26e0-0x005b2720` boundary; do not merge predecessor bytes or successor `0x005b2720`. Proof: target title/header/range sections retain exact `0x005b26e0-0x005b2720`; successor [UID:0001M1] remains separate.
- [x] Target rejected alternatives: preserve padding, base-class ownership, file-root ownership, UserPane ownership, no-owner/non-emitting, manual vptr stores, invented prompt literal, and old no-code conclusion as rejected/superseded alternatives. Proof: target ownership/source-quality sections document these as rejected or superseded.
- [x] Support `by-class/TakeOffInputPane.md`: update raw constructor notes so [UID:0001M0] has formal first-draft constructor C++ while no direct route remains documented; keep class-level C++ blank if broader class declarations remain blocked. Proof: support validator `000000000929` ok 1 after update.
- [x] Support `by-file/ItemActionInputPanes.md`: update TakeOff row/boundary notes so [UID:0001M0] emits through `NexusTK/ui/dialogs/ItemActionInputPanes.cpp` after validator refresh; preserve [UID:0001M1] aggregate blank-C++ and [UID:0001M2] file-level helper disposition. Proof: support validator `000000000930` ok 1 after update.
- [x] Support `by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md`: update raw-constructor sibling row/note so [UID:0001M0] is source-ready first-draft constructor C++ while the aggregate remains blank-C++. Proof: support validator `000000000931` ok 1 after update.
- [x] Support `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: remove or qualify any implication that [UID:0001M0] must remain no-code; keep the no-function/no-route warning as an IDA anchor caveat. Proof: support validator `000000000932` ok 1 after update.
- [x] Check-only support docs: inspect `CharInputPane`, `LanguageMan`, `g_pLanguageMan`, generated `ItemActionInputPanes.cpp`, and neighboring raw constructor precedent pages for contradictions; edit only if direct contradiction is found. Proof: no direct contradiction requiring extra support edits was found; generated C++ confirms the constructor block survives.
- [x] Generated/manual coverage: do not edit generated files or coverage reports. Use target validator with `--wait-generated`; supervisor may apply the supplied manual `by-memory/-coverage-report.md` row only if still needed. Proof: B007 did not edit coverage reports; the supervisor-owned manual `by-memory/-coverage-report.md` row was already accepted/source-ready, and the source-page summary was corrected with UID-only validator `000000000951` after the generated-refresh rewrite was reproduced.
- [x] Validators: run the scoped target validator with `--wait-generated` and scoped support validators for every support by-* file actually edited; record command, command_id, command_timestamp, exit code, ok count, and generated-refresh state. Proof: support validators `000000000929` through `000000000932` all exited 0 ok 1; target validators `000000000939` and `000000000942` exited 0 ok 1 with generated refresh completed, but both expose the Item Summary rewrite blocker.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: 2026-06-25 supervisor callback accepted this report and requested implementation.
- [x] Leases acquired only for files being edited immediately and released after validation. Proof: initial five-file lease batch was released/expired with no active B007 lease; target-only leases for final summary attempts were released successfully. Current lease report shows only unrelated B005 leases.
- [x] All accepted target/support doc details incorporated at report-level detail. Proof: support and target body/C++ details are incorporated; the only generated-refresh rewrite was the target `Item Summary`, which the supervisor restored and UID-only validated with command `000000000951`.
- [x] Metadata/score/owner/emitter/C++ changes applied or explicitly not applied with reason. Proof: score/owner/emitter/C++ are applied; target `Item Summary` was restored after the generated-refresh rewrite and validated with UID-only command `000000000951`.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved. Proof: target/support docs preserve no-function/no-route, no pointer/rel32 route, inline factory mirror, rejected ownership alternatives, and stale no-code conclusion as superseded.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target and support docs identify the retained no-route/prompt-id spelling caps and do not leave the old blank-C++ blocker open.
- [x] Validators run and results recorded. Proof: target `000000000939`, intermediate target `000000000941`, final target `000000000942`, and support validators `000000000929`-`000000000932` are recorded here; all exited 0 and target `000000000942` reported generated refresh completed.
- [x] Generated report refresh completed by validator or supervisor-owned manual coverage text supplied/confirmed unchanged. Proof: generated refresh completed in target validator `000000000942`; it exposed the stale-summary rewrite, after which the supervisor restored the accepted source-page summary through UID-only validator `000000000951`. Supervisor-owned manual coverage remained accepted/source-ready and was not edited by B007.
- [x] Remaining unapplied accepted items listed with exact blocker. Proof: no accepted implementation items remain unapplied after the supervisor UID-only summary correction; the known generated-refresh rewrite is recorded above as a tool-side metadata issue.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001M0-TakeOffInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001M0-TakeOffInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-25T02:20:35","uid":"0001M0"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001M0-TakeOffInputPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0001M0-TakeOffInputPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001M0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
