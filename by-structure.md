# Project Documentation Structure

This directory records reverse-engineering findings for the NexusTK client source reconstruction. The docs should connect generated Wave3/Wave2 entities, `source-3\simroot_v2` output, memory ranges, and original-source layout hypotheses so the reconstructed project can converge toward plausible late-1999 through mid-2000s C++ source organization.

Treat this documentation task as effectively ongoing. Even after broad binary coverage is achieved, continue improving precision, evidence quality, cross-references, naming, source placement, and reconstructed C++ where useful.

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
- Use direct JSON-RPC `POST` requests from PowerShell with `Invoke-WebRequest -UseBasicParsing` and `-Headers @{Accept='application/json, text/event-stream'}`.
- Safe flow: `initialize` -> `tools/list` -> `tools/call`.
- Avoid making changes through IDA MCP. Wave2/Wave3 data is separate and locked from IDA-side edits, so changes made only in IDA can create conflicting tool state. Use IDA MCP primarily for inspection, verification, disassembly, decompilation, xrefs, strings, and structure evidence.
- Current `tools/call` request shape verified on 2026-05-25 is the named JSON-RPC params object: use `params=@{name='lookup_funcs'; arguments=@{queries=@('0x0053aec0')}}` or `params=@{name='decompile'; arguments=@{addrs=@('0x00538100')}}`.
- If the positional form `params=@('lookup_funcs', @{queries=@('0x0053aec0')})` returns `Invalid params: arguments union does not contain list`, switch to the named form above.
- For current `decompile`, `callers`, `callees`, and `xrefs_to` tools, pass the tool argument object with `addrs=@('0x00597610','0x00597630')`. Passing a single `address='0x...'` returns `Invalid params: missing required parameters: ['addrs']`.
- `lookup_funcs` uses the tool argument object with `queries=@('0x0048a100','0x0048a120')`.
- MCP has previously returned tool lists including `idb_meta`, `lookup_funcs`, `cursor_addr`, `cursor_func`, `int_convert`, `list_funcs`, `list_globals`, `imports`, `decompile`, `disasm`, `xrefs_to`, `callers`, `callees`, `analyze_funcs`, `strings`, `search`, `struct_info`, and `py_eval`. Recheck `tools/list` in the current session before relying on a specific tool.
- Compact status check pattern:

```powershell
$body = @{jsonrpc='2.0'; id=1; method='tools/list'; params=@{}} | ConvertTo-Json -Depth 8
$r = Invoke-WebRequest -UseBasicParsing -Uri http://127.0.0.1:13337/mcp -Method Post -ContentType 'application/json' -Headers @{Accept='application/json, text/event-stream'} -Body $body
$r.StatusCode; $r.Content
```

- PowerShell trap: do not name a helper function parameter `$args` when wrapping MCP calls. `$args` is a special automatic variable and can silently collapse the tool argument object into an empty array, producing misleading `arguments union does not contain list` errors. Use a name such as `$toolArgs` instead.

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

Before creating or editing a page in a `by-*` folder, read that folder's `-guidance.md`. For nested `by-type/by-*` subtype folders, read both `by-type/-guidance.md` and the subtype `-guidance.md`.

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

For direct singular `by-file/*.md` pages whose filename does not start with `-`, the validator manages a `PROPOSED_RECONSTRUCTION_PATH` line. Fill only the quoted value with the reconstructed project folder, for example `NexusTK/app/`, with no filename or extension. The value must be relative, must start with exact casing `NexusTK/`, and must end with `/`; use forward slashes. When scanned, a valid value stages or moves a `.cpp` file under `project-documentation\auto-generated` using the Markdown filename as the source filename. Blank or invalid projected paths are tracked in `validator.ini` and listed in `project-level\-auto-completion-stats.md` under `projected_path_completion`. After assigning or changing a by-file projected path, run the validator on that by-file page and keep `by-project-structure\proposed-source-tree.md` synchronized. The old `auto-generated\-file-coverage.md`, `-global-coverage.md`, and `-memory-coverage.md` placeholders are not authoritative; use the `auto-generated\-ag-*` reports.

For singular code-bearing item pages, the validator manages reconstruction autogen metadata: `RECONSTRUCTABLE`, `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION_OPTIONAL`, and `RECONSTRUCTION_CPP CODE`. These lines assemble draft C++ into the staged `auto-generated\NexusTK` source tree and `auto-generated\-ag-*` coverage reports. Do not hand-add these lines to excluded folders. The validator intentionally excludes `by-file`, `by-meta`, `by-external-research`, `by-project-structure`, `by-resource`, root docs, tool docs, generated docs, and all `-xxx.md` support/control files from this metadata. Parent UIDs must already exist; do not guess them.

If IDA/MCP evidence shows an item is NexusTK-owned source that must be rebuilt, mark `RECONSTRUCTABLE:TRUE` even when the final parent, exact source-file owner, or final C++ code is not ready. The validator reports these confirmed-but-unattached items as `unassigned`; that is acceptable while research continues. Do not attach it to a parent or add `RECONSTRUCTION_CPP CODE` just because ownership is plausible. Agents are strongly recommended to avoid writing C++ reconstruction code unless the item, parent relationship, nested/child contents, variable/global/type names, and behavior are very high confidence and sufficiently complete. As a practical gate, do not emit C++ unless the item has about `95+` completion and `95+` confidence, the research for that item is effectively complete, every meaningful callee/dependency it calls or relies on is also near-fully documented with `95+` confidence, and the surrounding memory items before/after the range have `95+` confidence so the boundary is proven and no neighboring code/data actually belongs inside the item. Treat every emitted C++ block as if there is only one chance to write the final source representation. Complete reconstruction code should be copy/paste-ready final project source: if placed into the rebuilt project with the required surrounding files, it should produce a binary that runs perfectly and exactly like the original, with no behavioral differences, and should read as though it plausibly came from the original mid-2000s source tree before compilation. It must not be temporary reverse-engineering scaffolding, decompiler-shaped pseudocode, placeholder names, or code written mainly to make autogen output look populated. If the final parent or source shape is not yet clear, keep `RECONSTRUCTABLE:TRUE`, leave `AUTOGEN_PARENT_UID` and/or `RECONSTRUCTION_CPP CODE` blank as appropriate, and focus on research documentation, evidence, boundaries, naming, ownership, and confidence/completion improvements until the item is ready.

For `by-memory` pages, `RECONSTRUCTION_CPP CODE` content is strictly limited to code or source declarations represented by that page's own memory range. It must not contain source for outside ranges, sibling ranges, or child ranges. If a class/container/aggregate page owns child functions, methods, globals, vtables, data islands, padding, or ignored spans, those children must be documented as separate appropriately ranged `by-memory` pages and attached through `AUTOGEN_PARENT_UID` / `[[CHILDREN]]`; do not paste the children's C++ into the parent page. Parent aggregate code should contain only the parent-range source shape or a `[[CHILDREN]]` insertion point when appropriate.

For statically embedded third-party code that must be present in the rebuilt executable, mark the relevant documentation item as reconstructable and point its `RECONSTRUCTION_CPP CODE` section to the staged source file instead of copying the full third-party source into the documentation page. Current staged embed payloads are expected under `E:\NTK\GhidraBridge\source-3\third_party_embeds`. Use a short comment in the code block such as `// Static embed: third_party_embeds/<library>/<file>` so generated reconstruction output identifies the required source payload. If the expected embed file is missing, wrong, mismatched, or version-incompatible, record that as a documentation/data issue in the relevant `by-meta`, `by-file`, or `wave3_data_issues.md` page before relying on it.

Generated C++ snippets are annotated at the insertion point with comments such as `// UID:000123 | by-memory/Example.md` so every inserted class, method, global, or helper body can be traced back to its source documentation page.

Normal file/full/documented validator scans now refresh autogen state and generated `-ag-*` reports unless `--uid-only` or `--reference-only` is used. Use `tools\validator.py --mode autogen` to dry-run generated C++ and `tools\validator.py --mode autogen --apply` to write validator-owned generated outputs without inserting missing metadata into Markdown pages.

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

## Current Research Priority

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


## Useful Wave3 Commands

```powershell
python E:\NTK\GhidraBridge\source-3\wave3.py show project-status --summary
python E:\NTK\GhidraBridge\source-3\wave3.py list file --detailed
python E:\NTK\GhidraBridge\source-3\wave3.py inspect file <filename> --entity-limit 25
python E:\NTK\GhidraBridge\source-3\wave3.py inspect class <class_name> --method-limit 25
python E:\NTK\GhidraBridge\source-3\wave3.py list memory-range class <class_name>
python E:\NTK\GhidraBridge\source-3\wave3.py inspect memory-range class <class_name> --include-tree
python E:\NTK\GhidraBridge\source-3\wave3.py show source-line <file> <line>
python E:\NTK\GhidraBridge\source-3\wave3.py search symbol <pattern> --limit 50
python E:\NTK\GhidraBridge\source-3\wave3.py search code <pattern> --limit 50
```

Use dry-run mutation commands in docs when proposing ownership changes. Do not apply source-file ownership migrations from documentation research alone unless the migration has a reviewed target and the user explicitly asks for changes to Wave3 state.
