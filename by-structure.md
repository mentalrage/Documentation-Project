# Project Documentation Structure

This directory records reverse-engineering findings for the NexusTK client source reconstruction. The docs should connect generated Wave3/Wave2 entities, `source-3\simroot_v2` output, memory ranges, and original-source layout hypotheses so the reconstructed project can converge toward plausible late-1999 through mid-2000s C++ source organization.

Treat this documentation task as effectively ongoing. Even after broad binary coverage is achieved, continue improving precision, evidence quality, cross-references, naming, source placement, and reconstructed C++ where useful.

Source-quality investigation is part of ordinary documentation work, not a final-only phase. When a page has unresolved field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ questions, keep researching those questions during the score/evidence pass even if the page already reaches 85/85. Do not use 85/85 as a stop condition. Before adding `RECONSTRUCTION_CPP CODE`, the relevant source-quality questions must either be resolved or documented with exact evidence showing why they cannot currently be resolved without speculation. If an unresolved question materially limits behavior, ownership, source placement, or confidence, keep the score conservative rather than marking the page complete.

## Primary Inputs

- `E:\NTK\GhidraBridge\source-3\simroot_v2`: current generated Wave3 v2 simulated source tree. Use it as a lead source for possible classes, files, functions, globals, names, and grouping hints, not as authority. Information in this tree can be highly flawed: wrong ownership, bad ranges, stale names, missing helpers, incorrect source grouping, or generated assumptions. Verify any finding that affects documentation confidence, ownership, or migration against IDA/MCP or manual disassembly.
- `E:\NTK\GhidraBridge\source-3\core\data\readonly\wave2`: imported Wave2 class/global records and missing-reference notes.
- `E:\NTK\GhidraBridge\source-2\core\wave2\wave2.py`: older Wave2 tool. It may contain outdated information, but it can still be useful as a fallback reference when Wave3 is unstable or insufficient.
- `E:\NTK\GhidraBridge\source-3\core\data\cache`: normalized Wave3 cache indexes and metadata.
- `wave3.py` / `wave3d.py`: local inspection, ownership, memory, source-line, and grading commands. Treat their output as generated research evidence that must be checked before it becomes a high-confidence claim.
- If `wave3.py` is being patched, unstable, or reserved for another agent, do not call it directly; fall back to `simroot_v2`, cached/generated files, and IDA/MCP evidence, then record any resulting data caveats in `wave3_data_issues.md`.
- IDA/MCP or other disassembler evidence is the ground truth for addresses, function boundaries, xrefs, ownership, types, and behavior. If those tools are not available in a session, record that the finding is based only on local Wave3/Wave2/simroot evidence and keep confidence conservative.

### IDA MCP Manual Notes

- Current endpoint: `http://127.0.0.1:13337/mcp`.
- Alternate/status endpoints: SSE at `http://127.0.0.1:13337/sse` and config UI at `http://127.0.0.1:13337/config.html`.
- Treat port `13337` as the project-stable MCP endpoint in documentation. If migrating from the current GUI plugin to upstream `idalib-mcp`, start `idalib-mcp` on the same host/port, for example `idalib-mcp --host 127.0.0.1 --port 13337`, and make sure the old GUI plugin is not also listening on that port. Keeping the port preserves endpoint references, but it does not guarantee old tool calls remain identical.
- `idalib-mcp` is the newer upstream-preferred path and can adopt GUI sessions or run headless workers, but its session model may require an explicit `database` argument after `idb_open`/`idb_list`. Before using examples written for the GUI plugin, run `tools/list` against the active server and adapt calls to the returned schema. Do not assume old GUI-plugin calls like `decompile(addrs=...)` work unchanged under `idalib-mcp`.
- Use direct JSON-RPC `POST` requests from PowerShell with `Invoke-WebRequest -UseBasicParsing` and `-Headers @{Accept='application/json, text/event-stream'}`.
- Safe flow: `initialize` -> `tools/list` -> `tools/call`.
- Avoid making changes through IDA MCP. Wave2/Wave3 data is separate and locked from IDA-side edits, so changes made only in IDA can create conflicting tool state. Use IDA MCP primarily for inspection, verification, disassembly, decompilation, xrefs, strings, and structure evidence.
- Treat MCP call examples as schema examples, not durable command contracts. The active `tools/list` response is authoritative for exact tool names, required fields, singular/plural address keys, pagination fields, and optional caps.
- Current `tools/call` request shape verified on 2026-05-25 is the named JSON-RPC params object: use `params=@{name='lookup_funcs'; arguments=@{queries=@('0x0053aec0')}}`. For each tool, populate `arguments` from the current schema; for example, some MCP versions use singular `addr` for `decompile`, while older examples used `addrs`.
- If the positional form `params=@('lookup_funcs', @{queries=@('0x0053aec0')})` returns `Invalid params: arguments union does not contain list`, switch to the named form above.
- `lookup_funcs` uses the tool argument object with `queries=@('0x0048a100','0x0048a120')`.
- MCP has previously returned tool lists including `idb_meta`, `lookup_funcs`, `cursor_addr`, `cursor_func`, `int_convert`, `list_funcs`, `func_query`, `list_globals`, `entity_query`, `imports`, `imports_query`, `decompile`, `disasm`, `xrefs_to`, `xref_query`, `callees`, `analyze_function`, `analyze_component`, `analyze_batch`, `find_regex`, `search_text`, `find`, `find_bytes`, `struct_info`, `type_query`, `type_inspect`, and `py_eval`. Recheck `tools/list` in the current session before relying on a specific tool.
- Compact status check pattern:

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
$r = Invoke-WebRequest -UseBasicParsing -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body
$r.StatusCode; $r.Content
```

- PowerShell trap: do not name a helper function parameter `$args` when wrapping MCP calls. `$args` is a special automatic variable and can silently collapse the tool argument object into an empty array, producing misleading `arguments union does not contain list` errors. Use a name such as `$toolArgs` instead.

#### IDA MCP Output Discipline

Use the narrowest MCP call that can prove the current claim. Prefer exact-address workflows: `lookup_funcs` first, then targeted `analyze_function`, `decompile`, `disasm`, xref, byte, string, global, or type-inspection calls for the assigned function/range/page.

Do not run broad listing, search, disassembly, callgraph, type, or batch-analysis calls without filters and explicit caps. For exploratory calls, set `count` or `limit` to 50 or less unless a supervisor explicitly asks for broad enumeration. Page with `offset` instead of raising caps. Avoid `count=0`, `limit=0`, or any "all results" setting unless explicitly approved.

For rendered-listing searches, set `start` and `end` when the schema supports them; unbounded full-image searches can make MCP appear hung. For disassembly, start with `max_instructions` no higher than 200 and page with `offset` if more evidence is needed. For decompilation, disable line-address markers when the current claim does not need line-level address comments. Keep callgraphs bounded, normally `max_depth <= 2`, `max_nodes <= 100`, and `max_edges <= 300` unless broader graph proof is explicitly required.

Use `py_eval` only for read-only targeted checks when it appears in the active schema. A `py_eval` call must return scalar values or a small capped summary, not IDB-wide function/global/string lists, full decompiler output, raw large arrays, or file contents.

## Directory Roles

### Canonical Documentation Homes

Use the narrowest durable home for each fact, then connect related pages with UID references:

| Subject | Canonical home |
| --- | --- |
| Full function or method body, exact binary evidence, raw code, reconstructed C++ candidate | `by-memory` |
| Function/method name-centric index, rewrite status, overload disambiguation, high-traffic reference target | `by-function` |
| Class responsibility, inheritance/layout summary, method inventory, class-owned state | `by-class` |
| Likely original `.cpp`/`.h` ownership and source-module grouping | `by-file` |
| Process-wide globals, singleton pointers, concrete vtables/tables, global data ownership | `by-global` |
| Temporary narrow questions, unresolved small findings, one-off behavior notes | `by-item` |
| C/C++ declarations, layouts, callback/function-pointer types, vtable type structure | `by-type` |
| DAT/resource/assets/string-table ownership and formats | `by-resource` |
| Client-level topic docs that cut across many entities | `by-meta` |
| Original project/folder layout and migration batches | `by-project-structure` |

A research assignment whose primary target is a singular `by-file` page covers the entire inferred source file or coherent compilation unit at every score and must finish the reconstructed module, not just its documentation. The agent must inventory and deeply research all reasonably discoverable file-owned functions and other code, globals/statics/data, types/layouts/vtables, resources/imports, exact ranges/gaps/padding/children, callers/callees/xrefs, source order, and affected related by-* pages. It must compare that inventory with routed/generated output, find and repair missing or incomplete functions/code/data, stubs/placeholders/empty emitters, missing declarations/types/includes/forward declarations, fragment routing/order defects, and a required missing/incomplete `.h`, then validate and reread the validator-generated `.cpp`/`.h`. Generated files are read-only; repairs belong in formal source channels. A sibling `.h` may remain absent only with file-specific evidence that no header is required. A representative subset, one-function pass, by-file-page-only refresh, or documentation-complete but source-incomplete result is incomplete. `by-memory` remains the canonical home for exact function/range evidence, and the other narrow by-* homes remain canonical for their subjects, but whole-file research must find, reconcile, link, and give a source/documentation disposition to every item in the compilation unit. See `by-file/-guidance.md` for the complete inventory and completion gate.

Before creating or editing a page in a `by-*` folder, read that folder's `-guidance.md`. For nested `by-type/by-*` subtype folders, read both `by-type/-guidance.md` and the subtype `-guidance.md`.


### Frequent Documentation/MCP Issues

1. IDA's string typing is frequently wrong for Korean UTF-16 messages; decode the byte sequences directly before recording UI text.

2. NEVER convert number bases yourself. Use `E:\NTK\GhidraBridge\source-3\project-documentation\tools\int_convert.py` to do this. Always verify in documentation this was done with (Verified with int_convert.py) after the converted base. If you come accross documentation without this please make sure you reverify the base looking it up using ida mcp, using int-convert.py and then adding (Verified with int_convert.py) for each converted base in that document, otherwise documentation is considered partially incomplete.

### Rebuild Handling Classification

When documenting code or data, distinguish the source semantics that must be recreated from binary artifacts that the compiler/linker should regenerate. Do not assume non-`.text` ranges are disposable compiler output.

Use these rebuild-handling labels in `by-memory`, `by-global`, `by-type`, and `by-file` docs when relevant:

- `source-authored`: handwritten source code or explicit source data that should be recreated in the rebuilt project.
- `source-declared/generated-binary`: source-level declarations are required, but the exact binary bytes should be produced by the compiler/linker. Examples include vtables from class declarations, string literals, const arrays, static globals, function-pointer tables, and initialized writable globals.
- `resource-derived`: data should come from DAT/resource/assets or generated resource packaging, not hard-coded as arbitrary binary bytes.
- `third-party/runtime`: external library, CRT/STL/compiler/runtime code or data that should come from the dependency/toolchain rather than NexusTK source.
- `compiler/linker-generated`: pure build artifact such as import tables, startup tables, EH/RTTI glue, security-cookie support, adjustor thunks, padding, or alignment. Document for recognition and exclusion, but do not hand-port as source unless a source declaration is required to cause it.
- `unknown`: not yet classified; keep confidence low until IDA/MCP or byte-level review decides whether it is source-authored, source-declared, resource-derived, third-party/runtime, compiler/linker-generated, padding, or empty.

For the current IDA layout, `.text` is executable code at `0x00401000-0x0060d000`. The later `.idata`, `.rdata`, and `.data` ranges are non-executable but can still contain rebuild-relevant source semantics such as vtables, strings, const tables, globals, singleton pointers, and initialized state. Rebuild documentation should capture the required C++ declarations/initializers/ownership, not require identical original addresses.

### `-ignored.md` Ledgers

Every `by-*` folder, including `by-type/by-*` subtype folders, should contain a `-ignored.md` ledger. Use these files to record confirmed ranges, symbols, files, types, resources, topics, or research leads that should not be repeatedly reviewed for NexusTK-owned reconstruction.

Ignored entries are not dumping grounds. Add an entry only after verification. Each entry should include the exact id/address/name, the reason it can be ignored, the evidence used, and the replacement owner or external dependency when applicable. Common ignore categories include MSVC CRT/STL/Dinkumware support, compiler-generated EH/RTTI/security-cookie helpers, Windows SDK/import glue, third-party library code that should be vendored or linked separately, stale generated aliases, and duplicate/raw ranges superseded by better exact documentation.

Exception: payload-only evidence folders under a `by-*` directory, such as `by-meta/obtained_thirdparty_files/archives`, `runtime_from_local_client`, and `static_embeds`, should not be polluted with per-subdirectory ledgers. Record ignores at the parent documentation level, in `by-meta/-ignored.md`, or in `by-meta/obtained_thirdparty_files/-ignored.md`. This keeps `static_embeds` limited to staged third-party source/header payloads and avoids changing evidence/archive directories with documentation files.

### `-coverage-report.md` Reports

Every `by-*` folder, including `by-type/by-*` subtype folders, should contain a `-coverage-report.md` file. These reports work with the local `-ignored.md` ledger and summarize the current state of documentation coverage for that folder's data type.

Each coverage report should summarize reconstructable coverage, ignored coverage, known uncovered inventory, and confidence/completion state. Most folders should keep rows alphabetized; `by-memory` should keep rows in low-to-high address order.

The standard sections are `Covered Items To Replicate`, `Covered Items To Ignore`, and `Uncovered Items`. Any row listed as ignored should also be represented in `-ignored.md` with the reason, evidence, and replacement owner or dependency. Rows generally use this shape:

```text
ItemNameOrAddressRange : reconstructable|ignored|unknown|uncovered : estimated documentation completion : estimated accuracy/confidence : brief description
```

Completion means completion of highly detailed documentation for the item in question, not merely that a page exists or that its top-level behavior is known. A `100` completion score means the item has literally everything about it documented to the level needed for reconstruction: exact range/bounds, owner, source placement, behavior, raw evidence, callers/callees, touched state, relevant data structures, source-level rewrite shape where applicable, dependencies, nested/contained subitems, open caveats resolved or explicitly closed, and useful cross-references. Lower scores should reflect missing detail, unresolved subitems, weak source placement, absent raw evidence, missing reconstructed C++ candidates, incomplete field/global/local/variable naming, incomplete relationship mapping, or incomplete explanation of internal behavior.

Confidence means how confident the agent is that the contained documentation is correct, including every nested claim inside the page. It covers address boundaries, ownership, behavior, caller/callee interpretation, source-file placement, type/layout claims, renamed globals/fields/locals/variables, replacement of synthetic or generated names with accurate human names, and the detailed explanation of exactly what the item does. Keep confidence conservative when any important contained claim still depends on generated Wave3/Wave2/simroot output, unresolved synthetic names, incomplete IDA/MCP checks, unverified inferred source structure, or partially understood internal data flow.

Score both values against the entire documented item and everything contained inside it. A page with an accurate headline summary can still have low completion or confidence if nested methods, globals, fields, locals, data structures, external references, or generated placeholder names are not yet understood in detail.

#### 95+ Scoring Gate

Hard rule: assigning `95` or higher to either `COMPLETION` or `CONFIDENCE` is never routine. It is allowed only after extreme documentation for that exact file/item is complete, all material data has been verified against authoritative evidence, and the page records enough proof for another agent to audit the score without relying on session memory.

Operational rule: if the page does not already contain enough written evidence to prove extreme verification is complete for the whole file/item, including all material data and not just the subtopic currently being edited, both scores must stay below `95`. Treat `94` as the practical maximum for very strong research that has not yet reached final-audit quality.

Do not use `95+` as a confidence boost, progress reward, or "no known gaps" marker. It is only appropriate after extreme documentation is already complete for that exact file/item, all material data has been verified against authoritative evidence, and the page itself records the verification clearly enough for another agent to audit without repeating the investigation.

Rating any item `95` or higher for either `COMPLETION` or `CONFIDENCE` must be rare and deliberate. Do not do it lightly, and do not do it immediately after ordinary improvement work. A `95+` value means extreme documentation for that exact file/item is already complete, every material data point has been verified against authoritative evidence, and the page records enough proof for another agent to audit the rating without trusting the current session.

Before setting either value to `95` or higher, stop and verify that the page is already exhaustively documented, all material data has been checked against authoritative evidence, and the written evidence is strong enough that another agent can audit the score without rerunning the whole investigation.

Do not rate completion or confidence at `95` or higher lightly. Treat every score from `95` through `100` as a rare, near-final audit decision for the exact file/item being scored, not a routine progress score, cleanup grade, queue-clearing marker, or sign that the page is merely useful, improved, mostly accurate, or reconstructable. A `95+` score means the extreme verification work has already been completed and documented for that file/item; it must not be used as a prediction, target, optimism marker, or reward for partial progress. Use `94` as the practical ceiling for ordinary research progress.

Do not set either score to `95+` because an item was reviewed, substantially improved, or appears to have no obvious remaining issues. The file/item must already have extreme, written documentation, all material data must be verified against authoritative evidence, and the page must prove that verification in a way another agent can audit without trusting the previous session.

For any file or item, `95+` means the documentation is already at final-audit quality for that exact subject. It should only be assigned after extreme documentation has been completed, every important byte/range/name/relationship/behavior claim has been verified against authoritative evidence, and the written page contains that evidence or stable UID links to it. If the evidence exists only in the current agent's memory, if any major data is merely inferred, if any nested dependency or neighboring boundary still needs checking, or if another agent would need to redo broad verification before trusting the page, the score must stay below `95`.

Raising either value to `95+` must be treated as a final-audit action: every important fact for that item must already be verified, every meaningful uncertainty must be resolved or explicitly documented, and the page must contain enough evidence for another agent to independently confirm why the score is justified.

Only assign `95+` after extreme documentation for that exact file/item is already complete and written down, and after all important data has been verified rather than assumed. The page itself, or clearly linked supporting pages using stable UID references, must record the evidence chain for every material claim so another agent can audit the rating without relying on session memory. Private conclusions, generated grades, stale coverage rows, Wave3/Wave2/simroot-only assumptions, or checked-but-unwritten facts do not justify `95+`.

If any material fact is still unverified, only checked in memory during the current session, still needs IDA/MCP or byte-level confirmation, or is not documented well enough for another agent to audit, the item must stay below `95` even if the current interpretation looks highly likely.

For `95+`, all material data must be verified against authoritative evidence. Required verification includes exact ranges and bytes, decompilation/disassembly evidence, callers and callees, touched globals/fields/resources/tables, type/layout claims, internal data flow, parent/child relationships, neighboring/surrounding ranges, source ownership and placement, generated-name replacements, rebuild assumptions, and relevant dependencies. If any of these are incomplete, only partially recorded, still depend on generated data, or would need another broad IDA/MCP pass before final reconstruction, keep the score below `95`.

For file-level pages, `95+` means the whole proposed source file has been audited as a coherent unit: every included class, function, method, global, static table, resource dependency, embedded third-party payload, cross-reference, generated-name replacement, and neighboring ownership/boundary question has been verified or explicitly closed. Do not assign a file or item `95+` because one important part is well understood.

This gate applies independently to both fields. A `95+` completion score still requires verified evidence and defensible confidence, and a `95+` confidence score still requires documentation detailed enough that another agent can audit it from the page alone. When assigning either value at `95+`, add or update an explicit evidence/audit note in the page explaining why the score is justified. If that note would be thin, the score is too high.

Use the local folder `-guidance.md` for coverage row details. In particular, `by-memory/-guidance.md` is canonical for address-ordered rows, entity type fields, `UNKNOWN` gap rows, `EMPTY` rows, and nested aggregate/subrange display.

### `memory_ranges.py` by-memory Coverage Tool

Use `E:\NTK\GhidraBridge\source-3\project-documentation\tools\memory_ranges.py` to generate the supplemental by-memory range map report at `E:\NTK\GhidraBridge\source-3\project-documentation\auto-generated\by-memory-tool-report.md`. Settings live in `tools\memory_ranges.data`.

This tool scans `by-memory` filenames and Markdown metadata to estimate configured binary range coverage, identify uncovered filename-range gaps, flag barrier-crossing overlaps, list largest leaf ranges, and run cautious advanced filename/content consistency checks. It is filename/settings map coverage only: it does not read binary bytes or query IDA/MCP. Use the report to find broad coverage, stale range names, suspicious overlaps, manual classification issues, and candidate cleanup work before doing more expensive IDA/MCP verification.

### `-guidance.md` Files

Every live `by-*` folder, including `by-type/by-*` subtype folders, should contain a `-guidance.md` file. Use it for concise local rules that are specific to that folder and not already covered by this master structure document.

Guidance files are support documents, not reconstruction targets. Score them `COMPLETION:-1` and `CONFIDENCE:-1`, and keep them short enough that agents can quickly check folder-local expectations before creating or editing pages.

Detailed folder page templates, local coverage-row expectations, and subtype-specific rules belong in the relevant `-guidance.md` file, not in this master document. When adding or correcting a rule that only applies to one `by-*` folder, update that folder's guidance file and keep this file limited to cross-folder policy, routing, and workflow requirements.

### Folder Guidance Pointers

The folder notes below are routing summaries only. Do not treat them as local page templates. Before creating or editing a page in a folder, read that folder's `-guidance.md`; for `by-type/by-*` subtype folders, read both `by-type/-guidance.md` and the subtype `-guidance.md`.

- `by-memory`: canonical exact address-range documentation for full function/method bodies, raw evidence, reconstructed C++ candidates, data ranges, aggregate ranges, gap rows, and nesting. See `by-memory/-guidance.md`.
- `by-function`: optional name-centric index for functions/methods that need durable tracking or disambiguation. It points to canonical `by-memory` pages and does not replace them. See `by-function/-guidance.md`.
- `by-class`: class responsibility, inheritance/layout summaries, method inventories, class-owned state, and tightly coupled helper types. See `by-class/-guidance.md`.
- `by-file`: likely original `.cpp`/`.h` or coherent source-module reconstruction. Singular pages are source roots and use the validator-managed `PROPOSED_RECONSTRUCTION_PATH` line to record the reconstructed project folder for staged `.cpp` output. Other reconstructable pages attach to `by-file` UIDs through validator autogen metadata. Keep `by-project-structure/proposed-source-tree.md` synchronized with source-file additions, removals, renames, and placement changes. See `by-file/-guidance.md`.
- `by-global`: process-wide symbols, singleton pointers, concrete vtables/tables, callback tables, global arrays, module-scope state, and free/helper symbol ownership. See `by-global/-guidance.md`.
- `by-type`: C/C++ declaration, ABI, layout, subtype, and compiler-metadata research that is not primarily class or source-file ownership. See `by-type/-guidance.md` and the relevant subtype guidance file.
- `by-resource`: DAT entries, UI resources, image/palette/audio assets, string tables, and resource-to-class ownership. See `by-resource/-guidance.md`.
- `by-project-structure`: top-level project/folder layout, Visual C++ project grouping, subsystem boundaries, and migration batches. Keep `proposed-source-tree.md` current. See `by-project-structure/-guidance.md`.
- `by-item`: temporary or narrow findings that do not yet justify a class, file, type, global, resource, or memory page. Promote items once ownership is clear. See `by-item/-guidance.md`.
- `by-meta`: client-level topics, cross-cutting subsystem behavior, binary formats, protocols, third-party libraries, and broad research that links down to concrete evidence. See `by-meta/-guidance.md`.
- `by-external-research`: third-party, online, fan-site, repository, and historical research leads. Treat it as context only until verified against local binary evidence. See `by-external-research/-guidance.md`.
- `project-level`: broad findings that affect the whole reconstruction, such as naming conventions, compiler/runtime policy, build-system decisions, library exclusions, resource-packaging behavior, subsystem maps, workflow notes, and generated completion statistics.

### `wave3_noticed_problems.md` and `wave3_data_issues.md`

Use `wave3_noticed_problems.md` to record problems encountered while using `wave3.py`, `wave3d.py`, Wave3 services, generated output, or command behavior. Use `wave3_data_issues.md` for incorrect or suspect reconstruction data. Keep the two categories separate:

- core program issues: command hangs, service/cache failures, crashes, bad routing, stale processes, incorrect command output shape, materialization bugs, or tool behavior that prevents normal work;
- data issues: incorrect ownership, bad names, missing or wrong memory ranges, stale generated files, bad source-line provenance, invalid global-data types, unresolved class/file grouping, or reconstruction data that needs review.

Each entry should include the date, command or file involved, observed behavior, expected behavior if clear, impact on current research, and a suggested follow-up command or investigation path. Keep workarounds in the entry so later agents can continue without rediscovering the same failure. If a session finds suspect Wave3 class ownership, function-boundary data, generated names, or memory-range ownership while researching docs, record it in `wave3_data_issues.md` even if the finding is also mentioned in the class/file docs.

Mixed issues should be recorded in both places when useful: put the command/generation failure in `wave3_noticed_problems.md`, and put the affected ownership, boundary, or source-layout caveat in `wave3_data_issues.md`.

### Generic/General Documentation

All mentioned folders can also contain generic documentation on the subfolder topic they are contained within. Prefix those support files with `-` at the start of the filename to differentiate them from standard singular item pages. These support files should normally be scored `COMPLETION:-1` and `CONFIDENCE:-1` unless they are intentionally being treated as a direct reconstruction target.

### Standard Page Change Sections

Standard documentation pages, meaning singular entity/topic pages whose filenames do not start with `-`, should include a change-tracking section at the bottom when existing documentation is corrected, removed, renamed, or materially reclassified.

This rule is only for normal single-subject pages such as one class, file, memory range, global, function, item, resource, or type page. Do not require `## Changes` sections in control pages, guidance files, ignored ledgers, coverage reports, generated reports, broad rolling index files, global memory coverage files, or other large files that are constantly updated. Also exclude `by-meta`, `by-external-research`, `by-project-structure`, and similar support/planning/research folders unless a specific page is intentionally being treated as a singular reconstruction item.

Use a bottom section named `## Changes` or append to an existing `## Changes` section. Each entry should state:

- what existed before;
- what it was changed to, or exactly what was removed;
- a short summary of why the change was made;
- the evidence supporting the change, such as IDA/MCP output, manual disassembly, exact xrefs, source-line provenance, or linked memory/class/file docs.

Do not add change entries for pure additions to a page. Recording every new section or newly documented item creates unnecessary length; reserve `## Changes` for corrections, removals, and reclassification of existing claims.

### Validator UID Workflow

Hard rule: do not guess UIDs. Every new `.md` file created under a scanned `by-*` folder must be registered with the validator so it receives a stable UID header and `validator.ini` mapping. Do not guess, reserve, hand-write, or copy/paste placeholder UIDs for new documents.

### Git Backup Workflow

Git is used here as a general backup and sync tool for documentation work, not as a review-polish or worktree-cleanliness task. Only stop to commit and push after roughly 30 minutes of documentation work or after a large batch, about 50+ meaningful edits. Do not interrupt smaller documentation passes for Git, and do not spend documentation time trying to keep the worktree cosmetically tidy, hand-clean validator output, remove generated placeholders, or optimize diffs for review polish. Treat validator-produced updates as normal generated state. The priority is accurate documentation progress backed up to the remote repository at practical intervals.

`tools/validator.ini` is tool-owned state and must not be manually edited during normal documentation work. Let `tools/validator.py` create and update it. Manual edits are reserved only for extreme recovery cases, such as confirmed corruption or an `.ini` error that breaks the validator itself.

For ordinary single-file work, create the target document first, run the validator on that exact file so it receives its real UID, then add references to that UID from other documents. For batch work where a parent page needs to reference new child pages before their UIDs are known, use the temporary TMP reference workflow instead of guessing. Write the target path in this form:

```text
[TMP:"by-memory/ExampleTarget.md"]
```

When the source file is validated, the validator resolves the TMP path, assigns a UID to the target file first if needed, and replaces the TMP token with the normal generated UID link:

```text
[UID:000123][ExampleTarget](by-memory/ExampleTarget.md)
```

TMP paths may be documentation-root relative, source-file relative, workspace-relative with a `source-3\project-documentation` prefix, or absolute under either the `E:\NTK` junction path or the resolved `C:\FastStorage` path. Use TMP only for real target files under direct `by-*` folders. If the path is bad, the validator leaves the TMP token in place, records the unresolved reference, and reports it on later runs until the target path is fixed or the TMP token is removed.

After a set of edits, rename, or UID-reference update to one file is complete, normally run the validator once for that file:

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\example.md --apply
```

Only edit the numeric values in validator-managed `COMPLETION` and `CONFIDENCE` lines. Use `1-100` for evaluated documentation, `0` for unevaluated direct reconstruction docs, and `-1` for pages that should be excluded from completion statistics. Control pages, ledgers, guidance, coverage reports, external/meta/project-structure notes, and other non-actionable support docs should normally be scored `-1`. Score completion as the amount of highly detailed documentation completed for the item, where `100` means the item is documented exhaustively for reconstruction. Score confidence as correctness confidence across every contained claim, including names, ownership, behavior, types, source-placement conclusions, internal data-flow understanding, and replacement of generated/synthetic names with accurate human names. The validator will store high values, but it does not make them deserved: setting either score to `95+` is a near-final audit decision and should only happen after extreme documentation is complete, all material data has been verified, and the evidence is written into the page itself. Do not rate completion or confidence at `95` or higher lightly; it requires a deliberate final-audit pass for that exact file/item, with all data checked and enough written evidence for another agent to verify the rating without relying on session memory.

For direct singular `by-file/*.md` pages whose filename does not start with `-`, the validator manages a `PROPOSED_RECONSTRUCTION_PATH` line. Fill only the quoted value with the reconstructed project folder, for example `NexusTK/app/`, with no filename or extension. The value must be relative, must start with exact casing `NexusTK/`, and must end with `/`; use forward slashes. When scanned, a valid value stages or moves a `.cpp` file under `project-documentation\auto-generated` using the Markdown filename as the source filename. Nonblank routed `RECONSTRUCTION_H CODE` also creates the matching sibling `.h`; the validator never creates an empty H placeholder. Blank or invalid projected paths are tracked in `validator.ini` and listed in `project-level\-auto-completion-stats.md` under `projected_path_completion`. Use the exact value `NONE` only for a reviewed by-file page that is intentionally not a standalone source root, and document the corrected owner or non-promotion reason in the page body/change log. After assigning or changing a by-file projected path, run the validator on that by-file page and keep `by-project-structure\proposed-source-tree.md` synchronized. The old `auto-generated\-file-coverage.md`, `-global-coverage.md`, and `-memory-coverage.md` placeholders are not authoritative; use the `auto-generated\-ag-*` reports.

For singular validator-managed item pages, the validator now separates documentation ownership from generated-output routing. Normal singular entity pages receive `CANONICAL_OWNER`, which records the best direct semantic owner for documentation and review. Eligible code-bearing pages additionally receive `RECONSTRUCTABLE`, `EMITTER_UIDS`, `EMITTER_POSITION_OPTIONAL`, `RECONSTRUCTION_CPP CODE`, and `RECONSTRUCTION_H CODE`; these fields assemble implementation and header source into the staged `auto-generated\NexusTK` source tree and `auto-generated\-ag-*` coverage reports. The H block immediately follows the CPP end marker. Do not hand-add these lines to excluded folders. Reconstruction metadata is intentionally excluded from `by-file`, `by-meta`, `by-external-research`, `by-project-structure`, `by-resource`, root docs, tool docs, generated docs, and all `-xxx.md` support/control files. UIDs used as owners or emitters must already exist; do not guess them.

`CANONICAL_OWNER` must point to the correct direct semantic owner, not merely to the nearest `by-file` page or the final generated `.cpp` root. Use the narrowest true owner that the evidence supports and that clears the assignment gate. If a vtable, nested type, static member, method group, or helper belongs directly to a class, set the class UID as the canonical owner. If an item is a file-level free function, source-module helper, global/static declaration, table, or file-owned data object with no narrower class/type owner, use the `by-file` UID. If the correct owner is a global/type/class/resource page, use that owner when supported and document any tooling limitation if it does not. Do not bypass the correct class/type/global owner just to make the item reach a file root sooner.

`EMITTER_UIDS` is output routing, not ownership. It controls which parent or parents receive the page's generated CPP and H source and may contain one UID or multiple comma-separated UIDs. The emitter chain must eventually surface to a singular `by-file` page whose `CANONICAL_OWNER:FILE` and valid `PROPOSED_RECONSTRUCTION_PATH` make it a generated source root. A page can have a canonical owner but no emitters when ownership is known but generated output is not ready or not applicable. A reconstructable page with emitted code and no route to a file is an error and appears as a dead end in the generated `-ag-*` report.

Some source-authored data has no defensible single canonical owner but still needs to appear in more than one reconstructed source context. Common examples include compiler/linker-pooled string literals, shared constants, or small read-only data items referenced from independent source files. In these cases, keep `CANONICAL_OWNER:NONE` when no declaration/source owner is proven, but use multiple `EMITTER_UIDS` for the proven source-use contexts once the evidence is strong enough. This means "no canonical owner, but emitted through multiple files/classes"; it is not the same as non-emitting. Do not invent a standalone global or helper file solely to avoid `NONE`, and do not force ownership to the consumer with the most xrefs if other consumers materially use the same pooled item.

`EMITTER_POSITION_OPTIONAL` controls child ordering under emitters. A single number applies to every emitter. A comma-separated list aligns with `EMITTER_UIDS`, and blank entries mean no position for that specific emitter, for example `1,,3`. Items with positions sort before items without positions. Items with the same position, or with no position, preserve first-seen scan order.

Legacy note: older pages, reports, and research may still mention `AUTOGEN_PARENT_UID` or `AUTOGEN_PARENT_POSITION_OPTIONAL`. Those names belonged to the previous combined system where one field meant both "semantic parent" and "output route." In the current system, old `AUTOGEN_PARENT_UID` references should be interpreted as `CANONICAL_OWNER` for ownership claims and as `EMITTER_UIDS` only when the old text is specifically discussing generated output routing. Old `unassigned` wording in generated-report context now maps to `no-owner` and/or `non-emits`, depending on whether the missing data is canonical ownership, emission routing, or both.

If IDA/MCP evidence shows an item is NexusTK-owned source that must be rebuilt, mark `RECONSTRUCTABLE:TRUE` even when the final owner, emitter route, exact source-file owner, or final C++ code is not ready. The validator reports confirmed-but-ownerless items as `no-owner` and reconstructable items with no output route as `non-emits`; that is acceptable while research continues. Do not set `CANONICAL_OWNER`, fill `EMITTER_UIDS`, or add `RECONSTRUCTION_CPP CODE` just because ownership is plausible. Agents may write C++ reconstruction code only when the item is `RECONSTRUCTABLE:TRUE`, has one or more confirmed nonblank `EMITTER_UIDS` that surface to valid generated source output without a dead-end, and the average of `COMPLETION` and `CONFIDENCE` is greater than `85`. This is a strict combined-score gate: `(COMPLETION + CONFIDENCE) / 2 > 85`, so `85/85` is not enough, while `85/86`, `86/85`, or stronger scores can qualify if the emitter route is confirmed. The older `90/90+` and `95/95` phrasing was previous code-entry policy; `95+` remains a rare final-audit score, but it is no longer required before entering reconstruction C++ when the current combined-score/emitter gate is satisfied. Treat the score/emitter rule as minimum eligibility, not permission to add weak code. Any C++ an agent writes for a target, even first-draft/example/sample code, must be placed in, or supplied as exact insertion text for, the item's formal `RECONSTRUCTION_CPP CODE` header/block. If the agent is not ready to represent that code in the formal block, the correct output is a no-code proof, not a separate prose-only example or body-only review snippet. The item, emitter route, meaningful callees/dependencies, boundaries, source placement, and names used in the code must be documented well enough to support final-output source, and neighboring memory boundaries must have written evidence showing no outside code/data belongs inside the item. Treat every emitted C++ block as if there is only one chance to write the final source representation. Complete reconstruction code should be copy/paste-ready final project source: if placed into the rebuilt project with the required surrounding files, it should produce a binary that runs perfectly and exactly like the original, with no behavioral differences, and should read as though it plausibly came from the original mid-2000s source tree before compilation. It must not be temporary reverse-engineering scaffolding, decompiler-shaped pseudocode, placeholder names, or code written mainly to make autogen output look populated. If the final emitter route or source shape is not yet clear, keep `RECONSTRUCTABLE:TRUE`, leave `EMITTER_UIDS` and/or `RECONSTRUCTION_CPP CODE` blank as appropriate, and focus on research documentation, evidence, boundaries, naming, ownership, and confidence/completion improvements until the item is ready.

If a reconstructable item is intentionally covered by another emitter and should not emit its own body, use a minimal formal C++ comment such as `// Emitted code for this range is covered by [UID:xxxx].` rather than leaving the item looking like an empty emitter.

Treat CPP implementation and H declaration source as two independent formal decisions under the same quality gate. Any implementation/definition text belongs in `RECONSTRUCTION_CPP CODE`; any declaration/header text belongs in `RECONSTRUCTION_H CODE`. A report or agent recommendation must give exact insertion text for each nonblank channel or a target-specific reason that channel remains blank. Header-only content does not count as completed implementation. `[[CHILDREN]]` is independent in each channel. The validator does not invent guards, includes, forward declarations, or `#include "Name.h"`, so source-level directives must be evidence-backed and placed deliberately without duplication across child fragments.

For container, aggregate, section, or mixed-range pages, classify the container itself after review instead of leaving `RECONSTRUCTABLE` blank. Decide based on what the container page represents, not by counting or averaging the child pages. The key question is: "Would this container itself become a source-level object, declaration, module, table, class, source-bearing aggregate, or emitted source range in the rebuilt project?" If yes, mark the container `RECONSTRUCTABLE:TRUE`, even if some contained children are compiler-generated, runtime, padding, ignored spans, or otherwise `RECONSTRUCTABLE:FALSE`. If no, mark the container `RECONSTRUCTABLE:FALSE`, even if some contained children are reconstructable, because those children will carry their own reconstruction state and ownership.

Use `RECONSTRUCTABLE:FALSE` for a reviewed container that is only an audit/index/section map, compiler/runtime grouping, padding/tail-fill range, broad address-neighborhood map, or mixed-owner convenience page whose exact children already carry the real source ownership. This does not make the children non-reconstructable. It only means the parent container should not emit source as a separate source-level item. `RECONSTRUCTABLE:FALSE` pages may still use `CANONICAL_OWNER` to document semantic ownership or containment of other non-emitting documentation pages; they must not have nonblank `EMITTER_UIDS` or nonblank reconstruction code. For example, a broad `by-memory` range that merely groups unrelated exact child functions from `VectorHelpers`, `StringUtil`, and a UI class should normally be `FALSE` after the exact child pages are split and assigned, because the parent is an audit/container page rather than an original source owner.

Use `RECONSTRUCTABLE:TRUE` for a container that is itself a real source-level unit or data object: for example, a static table page that owns source-authored table data, a class/module aggregate that truly represents one source owner, or a source-bearing range that must be recreated as a coherent item. Such a container can still include padding, compiler-generated child spans, or ignored nested ranges without becoming `FALSE`.

A blank `RECONSTRUCTABLE` value means the item is still unexamined or undecided, not "mixed contents." When a mixed aggregate has been reviewed, do not leave it blank just because the children disagree. Record why the container itself is `TRUE` or `FALSE`, keep parent links and C++ blocks blank until their separate attachment and final-source gates are met, and make sure reconstructable exact children remain documented on their own pages.

For `by-memory` pages, both reconstruction blocks are strictly limited to source represented by that page's own memory range. Put implementation/definitions in `RECONSTRUCTION_CPP CODE` and declaration/header source in `RECONSTRUCTION_H CODE`. Neither block may contain source for outside ranges, sibling ranges, or child ranges. If a class/container/aggregate page owns child functions, methods, globals, vtables, data islands, padding, or ignored spans, those children must be documented as separate appropriately ranged `by-memory` pages and routed through `EMITTER_UIDS` / the channel-specific `[[CHILDREN]]` marker when they are ready to emit; do not paste child source into the parent page.

For statically embedded third-party code that must be present in the rebuilt executable, mark the relevant documentation item as reconstructable and point its `RECONSTRUCTION_CPP CODE` header to the staged source file instead of copying the full third-party source into the documentation page. Current staged embed payloads are expected under `E:\NTK\GhidraBridge\source-3\third_party_embeds`, and validator import paths must start with `third_party_embeds/`. Use the validator import directive as the inline `RECONSTRUCTION_CPP CODE` value, for example `<import-from-start>"third_party_embeds/lodepng/lodepng.cpp","third_party_embeds/lodepng/lodepng.h"</import-from-end>`, and keep the multiline BEGIN/END block blank. Do not use `third-party/...`, documentation-root paths, absolute paths, copied source text, or legacy `// Static embed: ...` marker comments when the import directive can cover the target. If the expected embed file is missing, wrong, mismatched, or version-incompatible, record that as a documentation/data issue in the relevant `by-meta`, `by-file`, or data-issue page before relying on it.

Generated CPP and H snippets are annotated at the insertion point with comments such as `// UID:000123 | by-memory/Example.md` so every inserted definition or declaration can be traced back to its source documentation page. Both suffixes under `auto-generated/NexusTK` are validator-owned and must never be edited directly.

Normal file/full/documented validator scans now refresh autogen state and generated `-ag-*` reports unless `--uid-only` or `--reference-only` is used. Use `tools\validator.py --mode autogen` to dry-run generated CPP/H source and `tools\validator.py --mode autogen --apply` to write validator-owned generated outputs without inserting missing metadata into Markdown pages. Empty H blocks generate no file; clearing the last H fragment removes the stale generated H automatically.

When a by-folder `.md` file is removed, run the validator missing-entry cleanup so the deleted file's UID mapping is removed from `validator.ini`:

```powershell
python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode documented --remove-missing --apply
```

For command details, dry-run forms, metadata header format, score defaults, UID repair behavior, TMP reference handling, junction-path notes, path canonicalization, path recovery, reverse-reference updates, isolated-file scans, queued execution, validator lock behavior, and completion-stat behavior, see `tools\validator_README.txt`. Do not run repeated full or documented scans for ordinary single-file edits. If an agent encounters broken UID links, stale generated target annotations, missing UID mappings, unresolved TMP references, or multiple renamed/moved files, recommend or run a full/documented validator resync instead of hand-fixing references.

Use `tools\validator.py` for normal validation. It is a queueing frontend that starts `validator_background.py` if needed and submits jobs in first-enqueued, first-run order, so parallel `validator.py` calls from multiple agents should queue sequentially instead of racing `validator.ini` or crashing from simultaneous writes. Use `tools\validator.py --queue-status` to inspect the worker and pending jobs. Do not bypass the queue by running `validator_background.py` directly except when debugging the validator itself. If multiple files need validation from one agent, still prefer one command at a time or a simple loop so logs remain readable.

After large documentation moves, UID-reference cleanup, or source-tree reorganizations, use the validator isolated scan from `tools\validator_README.txt` to find scoped `by-*` files that exist but have no inbound UID references from other scoped docs.

### UID Cross-References

When adding references from one by-folder `.md` file to another, write the stable target UID instead of a hand-authored Markdown path link. Use this authoring form:

```text
- [UID:TARGETUID] Additional context text.
```

`TARGETUID` is the target document's six-character UID from its first line. Do not invent `TARGETUID`: when referencing a new document, either validate the target file first so its real UID is present in `validator.ini`, or use the `[TMP:"path/to/target.md"]` workflow described above and let the validator assign/replace it. After editing the source file, run the validator on that file. The validator creates or updates the generated target annotation:

```text
- [UID:000123][TargetFile](by-class/TargetFile.md) Additional context text.
```

Do not manually maintain generated target annotations except when resolving validator errors. If a referenced UID is missing from `validator.ini`, run the validator on the target file first. See `tools\validator_README.txt` for reverse-reference and rename behavior.

## Evidence Standards

- Use Wave3 inspection commands and `simroot_v2` for discovery, but do not treat generated Wave3 data as authority. Verify ownership, function boundaries, types, and source-layout decisions with IDA/MCP or manual disassembly before raising confidence or driving migration.
- Treat `import_source_file` as provenance, not proof of final original file ownership. It is evidence to combine with class families, memory locality, xrefs, resource strings, and helper ownership.
- Record confidence explicitly: `confirmed`, `strong`, `medium`, `weak`, or `open`.
- Separate facts from hypotheses. Use "Observed" for tool-backed facts and "Hypothesis" for source-layout reconstruction.
- Keep exact addresses in hex with leading `0x`.
- Rename generated placeholders such as `dword_xxxxxxxx`, `byte_xxxxxxxx`, `sub_xxxxxxxx`, `FUN_xxxxxxxx`, `DAT_xxxxxxxx`, `Class_xxxxxxxx`, or synthetic Wave3 names when IDA/MCP evidence, xrefs, behavior, strings, layout, or surrounding ownership make the real role clear enough. Rename documentation files too when their canonical subject changes; UID headers and UID references are the durable identity, and the validator will update the recorded path/link annotation. When file/module additions, removals, renames, or source-placement changes affect the proposed project layout, update `by-project-structure\proposed-source-tree.md` in the same pass. After editing or renaming a single file, run `tools\validator.py --mode file --file <edited-or-renamed-file> --apply` unless a broader full/documented scan is explicitly needed. Record old generated names only when they remain useful for searching old tool output, traces, IDA labels, or generated Wave3/simroot references.
- Cross-reference related docs with UID references whenever a finding spans class, file, and memory views, then run `tools\validator.py --mode file --file <edited-file> --apply` so generated target annotations stay current.
- For late-1999 through mid-2000s Windows C++ source layout, prefer simple `.h`/`.cpp` modules, Visual C++ 6/7-era naming, subsystem folders, and local helper functions over modern header-only or highly granular one-class-per-file assumptions.

## General Research Priority

This section is general documentation priority. It does not override current supervisor goals, B-agent assignment queues, or validator-generated research tracker priority. For B-agent report-only assignment queues, follow the NTK B-agent workflow and active supervisor overrides.

The active research direction is top down. Prefer building a coherent reconstruction map instead of documenting unrelated isolated items:

Before using scores as the main work queue, make `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md` the primary focus until every executable/data range has some kind of documentation and there are no remaining `UNKNOWN` ranges. Broad range classification comes before polishing individual completion/confidence scores.

1. Start at the global/project level: subsystem boundaries, likely original folders, likely original source modules, major runtime/third-party exclusions, and broad executable/data regions.
2. Move into structures, classes, file-level ownership, globals, and helper groups. Use `simroot_v2` and generated files for leads, then verify with IDA/MCP before raising confidence.
3. Document the contents of those owners: class members, methods, free functions, helper structs, global data, vtables, jump tables, resources, and other subitems.
4. Create or update `by-memory` references for exact address ranges that support those owners. Preserve nesting: parent module/class/library ranges should contain child functions, methods, data islands, padding, and excluded spans when the relationship is real. Do not use one broad class or owner range as a substitute for the actual contained methods/functions; split every understood child item into its own precise `by-memory` page and nest it under the aggregate in coverage reports.
5. Prioritize completely undocumented memory ranges enough to classify every span as project code, unknown, ignored, runtime, third-party, data, padding, or empty. Unknown ranges should be explicit until manually investigated.
6. After broad gaps are accounted for, focus on low-completion or low-confidence items and trace them upward and downward until their real behavior, owner, and source placement are understood.
7. Work on other `by-*` folders and files as needed when the evidence naturally belongs there. Update or create `by-meta` pages when a finding exposes an uncovered client-level topic or cross-cutting subsystem behavior.

Use `project-level\-auto-completion-stats.md` as a secondary work-queue source when choosing what to improve after broad memory coverage is under control. The low-completion, low-confidence, low-both, and per-folder lists identify currently tracked documentation pages that most need review. Ignore entries with `COMPLETION:-1` or `CONFIDENCE:-1`; those are intentionally excluded from grading.
