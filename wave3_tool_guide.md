# Wave3 Tool Guide

This file is the living usage manual for Wave3. When commands, workflows, or development-only tooling change, update this document in the same pass as the code change.

## Entry Points

Use `wave3.py` for normal project work. It rejects development-only commands so user-facing workflows stay separate from test/debug workflows.

Use `wave3d.py` for development-only work, service inspection, cache inspection, imports, and test/debug commands. Development commands should go through `wave3d.py`, not `wave3.py`.

Common service checks:

```powershell
python wave3.py --help
python wave3d.py --help
python wave3d.py debug show command-routing --contains cache
python wave3d.py show service-status
python wave3d.py debug bootstrap
python wave3d.py debug reload-logic
```

Help is local to the entrypoint and does not start or query the main service. Use `python wave3.py --help` for normal command discovery and `python wave3d.py --help` when development/debug commands are needed. `wave3.py` intentionally hides development commands from the runnable command list; `wave3d.py` includes them in a separate `development_commands` list.

Use `debug show command-routing` when you need to know which entrypoint owns a command and whether `wave3d.py` handles it locally or forwards it through the main command queue:

```powershell
python wave3d.py debug show command-routing
python wave3d.py debug show command-routing --contains cache
python wave3d.py debug show command-routing --include-commands
```

`python wave3d.py debug bootstrap` reports the current cache-backed catalog counts and materialization counts. The `materialization` block is produced by `wave3_cache`, so `main.py` does not need to read full cache system documents just to report file-storage, simroot, or memory-issue totals.

Wave3 preserves the logical checkout path in runtime state and generated-root reporting. Even if `source-3`, `source-2`, `source`, or `exports` are Windows junctions to faster storage, service status and generated metadata should continue to use stable paths under `E:\NTK\GhidraBridge` instead of resolved `C:\FastStorage` targets.

## Caches

Wave3 v2 uses three cache services:

- `prewave_cache`: read-only baseline data.
- `wave2_cache`: read-only Wave2 overlay data.
- `wave3_cache`: writable Wave3 overlay data.

The runtime should ask caches for the specific data it needs. `main.py` should not read normalized cache files directly for normal command handling.

Useful cache inspection commands:

```powershell
python wave3d.py show cache-status
python wave3d.py show cache-health
python wave3d.py debug show queue-status
python wave3d.py debug smoke readonly --list-cases
python wave3d.py debug show cache-memory wave3_cache --detail
python wave3d.py debug dump-memory-usage wave3_cache
python wave3d.py debug show cache-request-history wave3 --slow-only
python wave3d.py debug cleanup cache-rpc
python wave3d.py debug cleanup command-queue
python wave3d.py debug restart cache wave3
python wave3d.py debug import wave3
python wave3d.py debug reimport wave3
python wave3d.py debug refresh memory-indexes
python wave3d.py debug refresh memory-indexes --rematerialize
python wave3d.py debug refresh memory-indexes --rematerialize --file class_FolderTreePane.cpp --batch-size 1
python wave3d.py debug refresh memory-indexes --rematerialize --offset 0 --limit 50 --batch-size 5
```

`debug cleanup cache-rpc` defaults to dry-run mode and reports stale one-shot cache RPC requests/results. Use `--confirm` to delete stale artifacts after review:

```powershell
python wave3d.py debug cleanup cache-rpc --service wave3 --confirm
```

Cache services also prune stale cache-RPC artifacts in the background. This prevents abandoned full-payload results from consuming disk space or polluting source audits after a client timeout/crash.
Cache RPC requests now carry priority metadata. Lightweight health, manifest, revision, summary, and memory-summary requests are processed ahead of heavy workflow-index requests when both are queued. This does not interrupt an already-running request, but it prevents stale broad requests from blocking new startup/health checks while waiting in the queue.

Use `debug show queue-status` when you need a compact queue snapshot that does not send cache RPC probes. It reads main/cache state files plus RPC artifact directories only, so it is safe to run while checking whether a cache process is blocked:

```powershell
python wave3d.py debug show queue-status
python wave3d.py debug show queue-status --detail
```

Use `debug smoke readonly` after tool changes to run representative read-only user workflows with timings and key output assertions. It exercises project status, progress, issue queues, missing-ref queues, accuracy-work queues, symbol search, code search, class alias lookup, class inspection, class-layout inspection, bounded field listing, field inspection, field metadata dry-run, method summary, method inspection, method metadata suggestions, global-function inspection, xrefs, callgraph inspection, decompilation, and current-vs-imported diffs without mutating Wave3 data:

```powershell
python wave3d.py debug smoke readonly --list-cases
python wave3d.py debug smoke readonly
python wave3d.py debug smoke readonly --case project_status_summary
python wave3d.py debug smoke readonly --slow-threshold 5
python wave3d.py debug smoke readonly --stop-on-failure
```

Use `debug show cache-request-history` to inspect recent cache RPC timings without submitting a command to `main.py` or adding another cache RPC request. It reads the cache service state files directly and supports all cache layers, slow-only filtering, minimum elapsed seconds, and bounded output:

```powershell
python wave3d.py debug show cache-request-history
python wave3d.py debug show cache-request-history wave3 --slow-only
python wave3d.py debug show cache-request-history --service wave2 --min-seconds 5 --limit 10
```

`debug cleanup command-queue` is the equivalent cleanup tool for the main Wave3 command queue. It defaults to dry-run mode and removes only expired command requests, stale unclaimed command results, or stale cancellation markers when `--confirm` is used:

```powershell
python wave3d.py debug cleanup command-queue --dry-run
python wave3d.py debug cleanup command-queue --confirm
```

Normal `wave3.py` command requests include their client timeout, client PID, parent PID, and cancellation marker path in the queued payload. If a client times out, is interrupted, or loses its launching parent shell, it marks the request abandoned and removes its pending request/result artifacts. The v2 command server skips abandoned queued requests and avoids writing unclaimed results when the client dies while a command is already running. `debug show queue-status` reports `cancellation_count` and `cancellation_bytes` for this cleanup path.
Avoid running normal `wave3.py` commands in parallel when timing matters. The main service processes normal user commands through a single queue, so parallel shells can cause later clients to hit short caller timeouts even when each command is healthy by itself. Use sequential commands, `debug smoke readonly`, or a future batch command for multi-target inspection.

Use `debug restart cache <prewave|wave2|wave3>` after changing cache service code. The command stops main, restarts the selected cache and dependent higher cache layers in order, then restarts main unless `--no-main` is supplied. Use `debug reload-logic` for runtime/main logic changes that do not change cache service code.
`debug reload-logic` reloads the v2 command queue module as well as dispatcher/runtime modules, so main queue metadata and command-processing fixes can be applied without restarting caches.
`debug reload-logic` refreshes the main service's consumed cache revision markers after rebinding runtime views. After direct in-process tests or cache-mutating development workflows, `show cache-health` should return to `ok` without requiring a cache restart.
`debug reload-logic` also reloads the external-embed helper module. Use this after changing `core/external_embeds.py`; unchanged `refresh embeds` calls should report `changed=false` and skip Wave3 cache system-document sync.
`debug reload-logic` also reloads shared JSON/check-out workflow helpers. This matters for service recovery because runtime state files may contain a UTF-8 BOM if written or edited by external tools; `core.jsonfs.load_json` accepts those files with `utf-8-sig` so a BOM in `active_checkouts.json` or similar runtime JSON does not block startup/reload.
On startup, `wave3_cache` may report `reused_refreshed` when only refreshable system documents changed while the cache was stopped, such as project issues, memory indexes, stale refs, rename registry, or system overlays. That path reloads the existing normalized cache and refreshes the changed system documents; it should not require a full `debug reimport wave3`. Changes to `project_index`, file storage membership, or file source documents still require the normal import/reimport path unless a targeted refresh command updated the cache first.
Exact class/file catalog lookups are cache-index operations. When an exact class or file id is not found through the direct catalog, fast overlay lookup, or resident indexes, `wave3_cache` now returns a miss instead of scanning the full workflow envelope. This keeps commands such as `create class NewName --file class_NewName.cpp` from blocking the cache for minutes while proving the destination file does not already exist.
Code body rendering strips UTF-8 BOM and mojibake BOM markers from persisted method/global text before file-storage source-map generation and simroot export. This prevents visible `﻿// NTK_ScopedInstall` or `Ã¯Â»Â¿` artifacts from leaking into generated C++ while preserving the underlying overlay data.
Normal Wave3 cache writes return a `data_revision`. The v2 runtime updates its consumed Wave3 cache revision from that response, so `show cache-health` should not report a false revision mismatch immediately after commands such as `issues --refresh` or overlay persistence.
Project issue refresh imports generated `global-data` rows from file-storage metadata, including rows stored under file `entity_overrides`. This catches unresolved generated symbols such as `g_pWeatherState`, rain table globals, `g_pScreenEffecterList`, and `g_pCashShopRequest` in `issues --kind global_data_issue` and `inspect global-data` without treating file-side references as true ownership.
Readonly lower caches keep resident code-search indexes when lazy loading is disabled. `wave2_cache` indexes method/global text and `prewave_cache` indexes function text, so `search code` can screen lower-layer candidates in memory instead of scanning every normalized payload per request. `wave3_cache` also batches lower-cache bundle hydration through `get_bundles` when inspection commands need multiple caller/callee/xref/decomp bundles.
The v2 runtime keeps a small bounded cache of lower raw fragments and resolved catalog queries. This is process-local acceleration only; Wave2/Prewave remain readonly, and `debug reload-logic` clears/rebuilds runtime-local state without requiring cache reimports.

Use project status for routine health checks:

```powershell
python wave3.py show project-status
python wave3.py show project-status --summary
```

In v2, the default `show project-status` response is the bounded summary form. It returns project counts, source stats, parity checks, `catalog_counts`, catalog status, materialization, memory coverage, active checkouts, and cache revisions.
Use `show project-status --full` only when you need the full storage, simroot, memory, issue, overlay, and rename-registry payloads. The full dump can be very large and is intentionally not the routine health-check path.
All forms include `next_commands` for common follow-up checks such as progress, issues, accuracy work, cache health, and service status. Development-only follow-up commands are shown with the `python wave3d.py` prefix.

## External Library Embeds

Wave3 can embed read-only external/static library source folders into the generated simroot. Parent folders under `E:\NTK\GhidraBridge\source-3\third_party_embeds` are treated as libraries and emitted under `simroot_v2\third_party\<library>` by default. Current embedded libraries include `jsoncpp`, `libjpeg`, `lodepng`, and `zlib`.

Embedded files are not Wave3-owned reconstructed files. They are copied into simroot as immutable external inputs, marked read-only, excluded from checkout/edit/disable/regrade workflows, and included by build generation as normal C/C++ source dependencies. If an embedded file conflicts with a generated Wave3 output path, the embedded file takes priority and the Wave3-generated file is copied under `simroot_v2\CONFLICTS\external_embeds\...` so both versions remain inspectable.

Useful commands:

```powershell
python wave3.py show embeds
python wave3.py show embed zlib
python wave3.py show embed-conflicts
python wave3.py refresh embeds
python wave3.py set embed-simpath zlib vendor\zlib --dry-run
python wave3.py set embed-simpath zlib vendor\zlib
python wave3.py set embed-dir zlib vendor\zlib
python wave3.py generate build
```

Config lives under `external_embeds` in `wave3.yaml`:

```yaml
external_embeds:
  enabled: true
  root: E:\NTK\GhidraBridge\source-3\third_party_embeds
  default_simpath: third_party
  conflict_policy: embed_wins_keep_wave3_conflict_copy
  set_readonly: true
  libraries:
    zlib:
      simpath: vendor\zlib
```

Only placement should be changed for embedded libraries. Use `set embed-simpath <library> <path>` or the clearer alias `set embed-dir <library> <path>` to update `wave3.yaml` and refresh the emitted read-only files. The path is always relative to simroot, so `set embed-dir zlib vendor\zlib` emits zlib under `simroot_v2\vendor\zlib\...`. The command accepts `--dry-run`; it does not make embedded files editable. A non-dry-run placement change copies the library to the new simroot-relative directory and removes stale files from the previous emitted directory. Setting the path back to the default `<default_simpath>\<library>` removes the per-library override from `wave3.yaml`.

## Inspection Commands

Full inspection commands return complete payloads and can be large:

```powershell
python wave3.py show class AboveFrame
python wave3.py show method 0x004616b0
python wave3.py show global IsCompactDisplayMode
python wave3.py show file class_AboveFrame.cpp
```

Use `--summary` for fast, focused inspection. Summary mode avoids heavy raw Wave2/file sidecar payloads and returns the key identity, grade, memory, ownership, and follow-up commands.
For files, summary mode hydrates only that file's cache-backed storage and simroot records, so it reports the storage path, emitted relative path, generated simroot paths, disabled companion state, and simpath errors without loading full sidecars.
Summary `detail_commands` are intended to be runnable as shown. Development-only follow-up commands include the `python wave3d.py` prefix explicitly.
Method/global inspection uses cache-backed lower raw fragments and batched bundle hydration. The first inspection of a method or global may hydrate lower Wave2/Prewave context; repeated inspections of the same entity should be served from runtime-local caches and stay bounded.

```powershell
python wave3.py show class AboveFrame --summary
python wave3.py show method 0x004616b0 --summary
python wave3.py show global IsCompactDisplayMode --summary
python wave3.py show global-data g_pEffectManager --summary
python wave3.py show file class_AboveFrame.cpp --summary
```

Use full mode only when you need raw import data, sidecars, or complete generated metadata.
Entity views may include `grade_freshness`. If it reports `status: stale`, the stored `autograder_result` was written before current project-problem counts changed; run the included `show grade ...` command for the live score or `regrade grade ...` to persist it.
Method body grading requires a real function definition in `current_code`. A scoped marker followed only by includes, structs, enums, typedefs, or other declaration scaffolding fails required `body_not_stub` with `missing_function_definition`; use this to catch emitted methods such as `LineInputPane::HandleKeyInput` or `EmotionInputPane::OnCharInput` where the real decompiled body is absent.
Use `list missing-method-body` to list scoped methods whose stored `current_code` has no function definition. This is cache-native and is the quickest way to find declaration-only generated method sections that need rewrite work:

```powershell
python wave3.py list missing-method-body --limit 25
python wave3.py show grade method 0x004f25a0
python wave3.py regrade grade method 0x004f25a0
```
Generic entity views and summary views include `next_commands` for the expected inspection, grading, and checkout steps. Method/global summaries include xref, decompilation, diff, memory inspection, owner class/file, grade/regrade, and checkout commands. Global-data summaries include type and owner suggestion commands before grade/regrade.

Use `inspect file` when reconstructing an emitted C++ source file and you need the file-level work packet before editing. The default response hydrates only that file's storage/simroot records and includes materialization paths, simpath state, stored grade summary, memory summary, bounded attached class/global samples, high-value file-owned global-data, and direct follow-up commands. Use `--entity-limit <n>` to change the attached/owned entity sample size. Add `--include-all-owned` when you need the slower full auxiliary-owner scan across structs/enums/macros/etc. Add `--include-issues` for matching file issue rows and `--include-grade-details` for stored file grade failure details. Run `show grade file <filename>` or `regrade grade file <filename>` when you need a live recomputation.
Use `replace file-code-text` for exact, reviewed edits to file-level `live.cpp` storage when a method/global command cannot edit the source because the entity has no per-entity `current_code`. The command loads the file document through `wave3_cache`, replaces only the exact requested text, persists through the cache commit path with a backup/version id, and refreshes the emitted file. Use `--dry-run` first and keep `--old` text specific enough that the reported replacement count is expected.
Use `replace project-code-text` for reviewed project-wide alias or naming cleanup after a storage/name issue has already been proven. It first asks `wave3_cache` for candidate files through the current code-search index, then loads only matching file documents, reports affected files in dry-run mode, commits changed file documents with backups/version history, and refreshes all touched files once. Use it only for exact identifiers or text fragments that are globally safe to replace. The response includes `candidate_file_count` and `search_source`; if it ever reports `file_storage_full_scan_fallback`, treat that run as a slower degraded path and prefer a narrower `replace file-code-text`.

```powershell
python wave3.py inspect file class__DatFileMgr.cpp
python wave3.py inspect file class__DatFileMgr.cpp --entity-limit 25
python wave3.py inspect file class__DatFileMgr.cpp --include-all-owned
python wave3.py inspect file class__DatFileMgr.cpp --include-issues --include-grade-details
python wave3.py replace file-code-text class_Pane.cpp --old "void MapPane::GetCurrentMotionRegion" --new "void Pane::GetCurrentMotionRegion" --source-evidence "owner qualifier cleanup after method-owner review" --dry-run
python wave3.py replace project-code-text --old dword_67A7EC --new g_packetSender --source-evidence "same packet-sender storage verified by memory xrefs" --dry-run
```

Use `inspect class` when you are reconstructing or auditing a class and need the class-level work packet before diving into individual methods. The default response is bounded: it includes class identity, true/default file ownership, entry-grade fields, memory range summary, a method work sample, and direct follow-up commands. Use `--method-limit <n>` to change the method sample size. Add `--include-grade-details` when you need stored class grade test failures inline, and `--include-issues` when you also want missing-ref context plus class-issue rows that explicitly reference the inspected class. Run `show grade class <name>` or `regrade grade class <name>` when you need a live recomputation.

```powershell
python wave3.py inspect class _DatFileMgr
python wave3.py inspect class _DatFileMgr --method-limit 25
python wave3.py inspect class _DatFileMgr --include-issues --include-grade-details
```

Use `inspect class-layout` when reconstructing C++ member declarations for a class. It asks `wave3_cache` for only that class's indexed fields, sorts by offset, returns a bounded field page with type/access/offset status, reports returned-page layout gaps, and links each questionable member to `inspect field` plus dry-run `set field-*` repair commands. Use `--field-limit` and the returned `next_offset` to page large classes.

```powershell
python wave3.py inspect class-layout AboveFrame
python wave3.py inspect class-layout AboveFrame --field-limit 50 --offset 50
```

Use `inspect field` when class layout reconstruction is blocked on one member. It returns the field's owner file/class, offset, size, type/access/qualifier state, original Wave2 field metadata, access-pattern search commands, a bounded owner-class method sample, and direct dry-run repair commands. By default it does not scan method code. Add `--include-code` to scan the bounded method sample for field-name/offset patterns and return snippets.

```powershell
python wave3.py inspect field AboveFrame field_0x100
python wave3.py inspect field AboveFrame::field_0x100@256
python wave3.py inspect field AboveFrame field_0x100 --method-limit 5 --include-code
```

Use `suggest field-type` before applying `set field-type`. It is read-only and ranks candidate member types from field-name conventions, size metadata, and, when requested, a bounded owner-method scan for casts, `new` assignments, boolean usage, `this` assignments, and receiver-like static calls. By default it is metadata-only to stay responsive; pass `--method-limit <n>` for a deeper decompilation scan when the first result is weak. The command reports evidence rows, confidence, unresolved candidate type checks, and dry-run `set field-type ...` commands; review the evidence before applying any mutation.

```powershell
python wave3.py suggest field-type AboveFrame field_0x100
python wave3.py suggest field-type AboveFrame field_0x100 --method-limit 0
python wave3.py suggest field-type AboveFrame field_0x100 --method-limit 25
```

Use field metadata commands to refine reconstructed class layout after reviewing decompiler/member-access evidence. These commands affect emitted class declarations, so start with `--dry-run` and confirm the `would_update` payload before applying the mutation. `set field-offset` accepts decimal or `0x...` offsets and returns the normalized integer offset in dry-run output. Use `list field --limit <n>` to page the derived field catalog; do not use `--all` unless the catalog is known to be small.

```powershell
python wave3.py list field --limit 25
python wave3.py show field AboveFrame::field_0x100@256
python wave3.py suggest field-type AboveFrame field_0x100
python wave3.py set field-type AboveFrame field_0x100 std::uint32_t --dry-run
python wave3.py set field-offset AboveFrame field_0x100 0x100 --dry-run
python wave3.py set field-access AboveFrame field_0x100 private --dry-run
python wave3.py set field-flags AboveFrame field_0x100 --static --const --bitfield-width 3 --dry-run
```

Use `inspect method` when you are actively reverse-engineering one method and want the normal evidence bundle in one bounded response. By default it combines method identity/owner data, the stored autograder summary with failing-test reasons when present, xref summary, decompilation/code statistics, and diff statistics without dumping full code, full diff text, or recomputing the full grade. Add `--include-code`, `--include-diffs`, or `--include-grade-details` only when you need the full payloads inline; `--include-grade-details` computes the live grade before returning details.
Use `suggest method-signature <addr_or_name>` before applying `set method-signature`. It is read-only and ranks signatures that already exist in Wave3 metadata, current source text, imported signature blocks, or imported decompiler/code evidence. It does not invent types. The response includes evidence rows, confidence, the current signature, the best candidate, and suggested dry-run/real `set method-signature ...` commands only when the best candidate differs from the current value.
Use `set method-code <addr_or_name> --code-file <path> [--source-evidence <text>] [--signature <text>] [--dry-run]` when the method is already attached to the correct class/file but the stored current body is malformed, missing, or lacks a scoped source-map marker. V2 stores the reviewed snippet as the method current-code overlay, automatically adds `// NTK_ScopedInstall(<method>, <addr>)` when missing, optionally rewrites the function header from `--signature`, and refreshes the owning file so emitted source/source-map output updates. Header rewrite keeps ABI detail in metadata but strips emitted-source calling-convention artifacts such as `__thiscall`/`__cdecl`, and constructor/destructor headers are emitted without fake return types. For file-owned methods, the command also splices the scoped section into the editable file `live.cpp`: it replaces an existing scoped section when present, removes stale omitted-body markers for that method, or appends a new scoped section without overwriting other hand-edited file content. Prefer `--code-file` over inline `replace method-code-text` when replacing multi-line C++ that contains quotes, backslashes, or semicolons; shell escaping mistakes can corrupt the submitted source before Wave3 sees it. When using both `--source-evidence` and `--signature`, put `--source-evidence` before `--signature`; the current dispatcher treats `--signature` as the final free-form option.
Use `suggest method-flags <addr_or_name>` before applying `set method-flags`. It is read-only and scores constructor, destructor, operator, const, static, virtual, pure-virtual, and override flags from current names, signatures, current code, and imported decompiler/signature evidence. The command returns candidates, evidence rows, current flags, and suggested dry-run/real `set method-flags ...` commands when there is something to apply. Run the `--dry-run` command first; both suggestion commands report `manual_review_required: true`. Use `set method-flags <addr_or_name> --thunk` only after confirming the method is compiler-generated glue such as a this-adjustor thunk; pair it with `classify memory-range ... compiler_generated` so metadata and coverage agree.

```powershell
python wave3.py inspect method 0x004616b0
python wave3.py inspect method 0x004616b0 --include-code
python wave3.py inspect method 0x004616b0 --include-diffs --include-grade-details
python wave3.py suggest method-signature 0x004616b0
python wave3.py set method-signature 0x004616b0 "void AboveFrame::OnNotify(int senderId, int messageData)" --dry-run
python wave3.py set method-code 0x004616b0 --code-file workdir_v2\reviewed_method.cpp --source-evidence "manual IDA review" --signature "void AboveFrame::OnNotify(int senderId, int messageData)" --dry-run
python wave3.py replace method-code-text 0x004616b0 --old "oldExactText" --new "newExactText" --source-evidence "small reviewed source correction" --dry-run
python wave3.py suggest method-flags 0x004616b0
python wave3.py set method-flags 0x004671b0 --operator += --dry-run
python wave3.py set method-flags 0x004f2e59 --thunk --dry-run
```

Use `inspect global` for standalone global functions. It mirrors the method inspection packet but omits class ownership: identity, owner file, stored grade, xref summary, decompiler/code summaries, diff summary, memory status, and follow-up commands are returned by default. Add `--include-code`, `--include-diffs`, or `--include-grade-details` only when the full payloads are needed inline.
Use `set global-signature <addr_or_name> <signature>` to correct a standalone global function signature after inspection. Run it with `--dry-run` first; when applied, Wave3 updates the stored signature metadata, rewrites the current-code function header when it can match the header safely, refreshes the owning file, and re-materializes the source-map/grade artifacts. Use `set global-owner <addr_or_name> <filename>` when a real standalone helper was reconstructed into the wrong source file; dry-run shows the current owner, target owner, and touched files before mutation. Applied owner moves also repair the target file's `attached_globals` list, remove stale attachments from prior owner files, and refresh the memory-range index so `show memory-at` reports the new owner immediately.
Use `replace global-code-text` for small, reviewed edits to a standalone global function body when the function is otherwise correctly owned. It performs exact text replacement in the current-code overlay, supports dry-run previews, refreshes the owning file, and re-materializes source-map/grade artifacts. Keep PowerShell arguments quoted, and avoid semicolons inside `--source-evidence` or `--reason` text because unquoted semicolons split commands before Wave3 sees them.

```powershell
python wave3.py inspect global 0x004b60b0
python wave3.py inspect global IsCompactDisplayMode
python wave3.py inspect global 0x004b60b0 --include-code --include-diffs --include-grade-details
python wave3.py set global-signature 0x004b60b0 "bool IsCompactDisplayMode()" --dry-run
python wave3.py set global-owner 0x004b60b0 UtilityHelpers.cpp --dry-run
python wave3.py replace global-code-text 0x004b60b0 --old "oldExactText" --new "newExactText" --source-evidence "manual IDA review" --dry-run
```

Use `inspect global-data` for global variables/data symbols that need type or ownership repair. The default packet is bounded: it includes current type state, true owner-file state, observed owner provenance, memory coverage, stored grade summary, active global-data issue rows, and direct repair/follow-up commands. Add `--include-suggestions` only when you want inline type and owner suggestion summaries; this runs the heavier evidence scorers. Add `--include-grade-details` when you need the live global-data grade failures inline.
Use `merge global-data` when two global-data records are verified to represent the same storage and one should become an alias of the other. The command preserves the source identifier/address as target aliases, merges compatible memory ranges, updates exact source-code references through the rename path, tombstones the duplicate source record, and refreshes the touched file state. It is not a type suggestion tool: only merge records after memory provenance proves they are the same storage, and do not merge distinct globals just because call sites inferred the same type.

```powershell
python wave3.py inspect global-data g_gameClock
python wave3.py inspect global-data g_gameClock --include-suggestions
python wave3.py inspect global-data g_gameClock --include-grade-details
python wave3.py merge global-data dword_67AB40 g_pDATFileMgr --type DATFileMgr* --owner class_DATFileMgr.cpp --reason "same storage verified by memory xrefs" --dry-run
```

Use `inspect callgraph` when method/global accuracy depends on understanding nearby control flow before rewriting. It starts from the same target resolution as `show xref`, follows caller and/or callee addresses, and returns a bounded node/edge packet with per-node xref counts and follow-up commands. Defaults are intentionally small: depth 1, direction both, limit 25. Depth is capped at 3 and limit is capped at 100 so accidental project-wide graph walks do not block the tool. Nodes at the requested depth boundary are lightweight placeholders with `show xref`/`show decomp` follow-ups; increase `--depth` only when those neighbors need to be expanded.

```powershell
python wave3.py inspect callgraph 0x004616b0
python wave3.py inspect callgraph 0x004616b0 --direction callees --depth 2 --limit 40
python wave3.py inspect callgraph OnNotify --direction callers --depth 1 --limit 10
```

Cross-reference inspection resolves cache bundle references before returning results:

```powershell
python wave3.py show xref 0x004616b0
```

The `callers`, `callees`, `xrefs_to`, `xrefs_from`, and `data_refs` fields should contain usable lists/maps, not unresolved `bundle:...` references.
The response also includes `xref_summary` with normalized related addresses and `next_commands` for jumping to caller/callee `show xref` and `show decomp` views.

Use `show prewave-function <addr>` when a target exists in the lower prewave function cache but has not been reconstructed into Wave3 yet. This is especially useful from `show missing-ref target <addr>`: the missing-ref view includes `lower_function_evidence` with prewave names, signatures, class hints, caller/callee samples, and direct follow-up commands. The default and `--summary` forms stay bounded; use `--include-decomp` only when you need the lower decompiler payload. Standard `show xref <addr>` and `show decomp <addr>` also fall back to the prewave function cache for lower-only addresses, so missing-ref targets can be inspected before a Wave3 method/global record exists. For an existing Wave3 method whose current scoped section contains declarations/comments but no real function body, use `set method-code <addr> --from-decomp [--decomp-source best|ida|ghidra|ghidra_ghidrassist] --source-evidence <text>` to seed the method body directly from the cache-backed decompiler payload without creating a temporary code file.
`show memory-at <addr> --include-ignored --include-allowed` reports matching lower prewave functions in `lower_layer_matches.prewave_functions` when the global Wave3 address index has no direct hit. If a lower hit maps back to an existing Wave3 method/global range, the command also reports that current range with `address_index_source: targeted_entity_range_fallback`. Use this to diagnose uncovered or index-missed helper starts that have lower evidence.
Use `show prewave-class <cls_...>` when prewave evidence points at an OOAnalyzer class id but no Wave3 class has been reconstructed yet. It runs a bounded prewave metadata search for that class id and summarizes matching lower-only functions with signatures, caller/callee hints, and direct `show prewave-function`, `show xref`, and `show decomp` commands. If a matching missing-ref class entry exists, the response also links to `show missing-ref class ...` and the reviewed projected-name workflow. Individual `show prewave-function` and `show missing-ref` evidence blocks link back to `show prewave-class` when they expose a prewave class candidate.

```powershell
python wave3.py show prewave-function 0x00437470 --summary
python wave3.py show prewave-function 0x00437470 --include-decomp
python wave3.py show prewave-class cls_0x4306e0 --limit 10
python wave3.py show xref 0x00437470
python wave3.py show decomp 0x00437470
python wave3.py show memory-at 0x0051f510 --include-ignored --include-allowed
```

`search symbol <pattern> [--limit <n>] [--include-fields]` is cache-backed and returns bounded catalog hits with `count`, `returned_count`, `total_count` when known, `minimum_total_count`, `has_more`, top-level `next_commands`, and row-level `next_commands`. Field catalog search is skipped by default because the field catalog is very large; pass `--include-fields` only when you intentionally need that scan. When Wave3 catalogs do not fill the requested limit, symbol search also asks the prewave function cache for lower-only function metadata hits across address, name, method name, class, and signature fields. These rows use `kind: prewave-function` and link to `show prewave-function`, `show xref`, and `show decomp`.

## Issue And Accuracy Work

Use `issues` as the general project information and problem command. It includes project issue counts plus stored compact diagnostics such as memory coverage and related status when the cached issue index contains them.
Issue rows may include a `context` block with repair-oriented metadata and `next_commands`; for example, `global_data_issue` rows include current type evidence, owner context, source evidence, memory coverage status, code search, owner method/class inspection, and the exact `set global-data-type` command shape. `missing_ref_issue` rows include the missing-ref key, projected name/owner, reference counts, notes, and triage commands.
Use `issues --refresh` when you need a fresh full project issue index before trusting counts. Normal `issues` reads the stored cache-backed issue index; `--refresh` rebuilds the index first and returns an `issue_index` block with `generated_at`, `refreshed`, `refresh_scope`, and the equivalent refresh command. Use `--include-diagnostics` only when you need freshly recomputed diagnostics inline; normal limited pages avoid broad diagnostic refresh work.
If a stored issue index has inconsistent summary counts and row data for the issue kind being read, normal issue reads self-heal once by refreshing the issue index. In that case `issue_index.self_healed_row_summary_mismatch` is true and `row_summary_mismatch` shows the stale count difference that triggered the refresh. The broad global-data catalog probe is scoped to `issues --kind global_data_issue`, `issues --entity-kind global-data`, `list global-data-issues`, or explicit refresh so a general `issues --limit N` page does not scan the full global-data catalog before returning.
Project-issue refreshes are fail-closed: if `wave3_cache` cannot provide required catalog entries, the refresh should fail rather than writing a partial issue index that hides work.
Use `list global-data-issues` when the raw `issues` payload is too broad and you want a concise global-data repair queue. `--needs-type` filters to missing normalized type rows, `--needs-owner` filters to missing true owner-file rows, and `--with-suggestions` attaches bounded read-only suggestion summaries for the returned rows. The response includes `count`, `returned_count`, `total_count`, and a `summary` block with work-type/severity counts. Rows include standard `kind`, `entity_kind`, `id`, and `entity_id` aliases plus the legacy `global_data` field. Suggestion rows expose a generic `suggestion` alias plus the nested `type_suggestion` or `owner_suggestion` payload. Type suggestions from `--with-suggestions` are intentionally lightweight name-only hints; use `--deep-suggestions` for a small batch when you want `suggest global-data-type` code/decomp/peer evidence included directly in the queue. Owner suggestions from `--with-suggestions` are lightweight issue-context hints from observed `owner_files` and owner class default filenames; `--deep-suggestions --needs-owner` runs the deeper owner scorer for the returned rows. Deep suggestions are capped to 5 rows per call to avoid turning a queue view into a broad project scan. The response-level `next_commands` promote the first returned row actions, including suggestion and review commands, so the queue can be used as a direct repair launcher.
When `list global-data-issues` is filtered with `--needs-type` or `--needs-owner`, its suggestion follow-up commands preserve that filter. For example, a type queue points to `list global-data-issues --needs-type --deep-suggestions ...` rather than the unscoped deep queue.
Direct `suggest global-data-type <id>` responses expose `best`, `best_score`, `best_confidence`, and `manual_review_required` aliases in addition to the full sorted `candidates` list. Deep and lightweight `list global-data-issues` suggestion rows expose the same aliases in `type_suggestion`. Owner suggestions expose `best_score`, `best_files`, `best_is_tied`, `best_confidence`, and `manual_review_required`; tied owner scores report `best_confidence: ambiguous` because the tool cannot choose one materialization owner safely. Confidence is a triage hint only; still inspect the evidence and prefer `review global-data-type ... --dry-run` or `review global-data-owner ... --dry-run` for changes tied to an issue. When an issue exists, direct type suggestions list the reviewed dry-run command before the raw `set global-data-type` command.
Use `list global-data-issues --confidence <high|medium|low|ambiguous|none>` to filter queue rows by the attached suggestion confidence. Passing `--confidence` implies suggestions even if `--with-suggestions` was omitted. With lightweight suggestions the command can scan the full matching queue; with `--deep-suggestions`, the command uses a bounded scan and reports `confidence_scanned_count`, `confidence_scan_limit`, and `confidence_scan_complete` in the summary. Use `--scan-limit <n>` to raise or lower that bounded deep scan.
Deep global-data suggestion queues are intentionally capped for main-service responsiveness. `--deep-suggestions` returns at most three rows per call, and confidence-filtered deep scans probe one row per call. If `--deep-suggestions --confidence ... --scan-limit <n>` requests too many rows, the response adds a `deep_suggestion_scan_capped` diagnostic and reports the effective `deep_suggestion_scan_cap`; if the per-row lower-cache evidence probes consume the command budget, the response adds `deep_suggestion_time_budget_hit`. Use direct `suggest global-data-type <id>` or `suggest global-data-owner <id>` for specific rows when a wider evidence pass is required.
Missing-ref issues with a projected owner attach to that owner class. Missing-ref issues without a true owner use virtual entity kinds such as `missing-ref-class` or `missing-ref-target` with the missing-ref identifier as `entity_id`, so issue rows remain filterable before the recovered class/method/global exists in Wave3. The virtual entity fields do not change the historical issue-id hash. Missing-ref create scaffolds intentionally keep `<RecoveredClassName>`, `<RecoveredMethodName>`, or `<RecoveredGlobalName>` placeholders until a real projected name is recorded; the raw target address is still used for memory/search commands but should not be treated as a recovered C++ symbol name. For target refs, `show missing-ref` checks the prewave function cache and exposes lower-layer function evidence when present, so triage can start from historical signatures and caller context instead of blank memory/code searches. For class refs with a parsed `cls_0x...` address, `show missing-ref` also checks the corresponding prewave function address to expose constructor/helper signatures, callees, and decompiler follow-ups that can help recover the class name.
Use `inspect missing-ref <target|class> <identifier>` as the normal missing-reference triage packet. It combines reconstruction safety, current projected metadata, compact lower prewave evidence, candidate owner/name signals, related issue rows, recommended manual-review steps, and direct follow-up/create commands. Add `--include-lower-evidence` only when you need the full lower evidence payload inline, and `--include-raw` only when debugging the underlying `show missing-ref` and `suggest missing-ref` payloads.
Use `suggest missing-ref <target|class> <identifier>` when you want the missing-ref evidence converted into an explicit triage plan without mutating state. It reports reconstruction safety, current projected metadata, lower prewave owner/name candidates, candidate-name quality, recommended inspection commands, safe owner/name/reconstruct commands, and note commands for preserving lower address-derived names as evidence. If an entry is already `ready`, the response also includes `reviewed_create_commands` and recommended dry-run/create steps so the reviewed reconstruction path is visible without digging through generic `next_commands`. Address-derived lower names such as `meth_0x...`, `sub_...`, and `cls_0x...` are deliberately not offered as direct projected-name commands because they are evidence identifiers, not recovered C++ source names.
When `show missing-ref target ...` finds lower prewave class evidence and no reviewed Wave3 owner yet, it prioritizes the suggestion/evidence workflow and suppresses direct `create global ...` scaffolds in that focused view. Use the suggested owner/name/reconstruct commands after manually confirming whether the target is a method, global function, or data-backed helper.
Bootstrap, duplicate-ownership, and memory-range issue rows also include contexts. Bootstrap overlay issues include contamination inspection/cleanup dry-run commands, duplicate-owner rows include method/xref/decomp plus candidate owner class commands, and memory-range rows include memory tree/range validation/recompute commands plus allow/ignore review commands.
The `issues` response keeps the historical nested `get_problems` payload and also exposes top-level `issues`, `summary`, `returned_count`, `total_count`, and `next_commands` for direct use. `show problem <issue_id>` likewise exposes `issue` and top-level `next_commands`.
Use `inspect problem <issue_id>` when an issue row is the starting point and you want the tool to route it to the right bounded work packet. It summarizes issue status, entity/file ownership, details/context signals, and issue-specific follow-up commands. For example, global-data issues route to `inspect global-data ... --include-suggestions`, missing-ref issues route to `inspect missing-ref ...`, memory-range issues route to `inspect memory-range ...`, duplicate ownership routes to `suggest method-owner ...`, and stale refs route to the referencing entity plus code search. Add `--include-entity` only when you want the linked entity inspection embedded inline; add `--include-raw` only when debugging the full stored issue row.
Project issue rows are decorated with `show problem <issue_id>` and `inspect problem <issue_id>` in their `next_commands`, so queue commands can be used as launchers instead of manual ID lookup.
The top-level `summary` is an overall generated-issue summary. Use `visible_summary` or `summary.visible` for the filtered rows actually returned by the current `--kind`, `--entity-kind`, `--include-ignored`, and `--include-dismissed` options. Both summaries include `total_count`, all-row `issue_kind_counts`/`source_counts`/`severity_counts`/`message_counts`, and active-only `active_issue_kind_counts`/`active_source_counts`/`active_severity_counts`/`active_message_counts`. `message_counts` is important because `global_data_issue` covers both missing normalized types and missing true owner files. This matters for allowed memory/duplicate-owner rows: generated diagnostics can still mention them in all-row counts while active-only counts stay focused on actionable issues.
The dedicated memory issue commands (`show memory-issue`, `list memory-conflict`, `list memory-overlap`, `list memory-gap`, `list memory-unresolved`) return the same actionable memory context as `issues`.
`list stale-ref` returns raw stale-reference rows from the rename/simpath scanner. Rows include `next_commands` for the corresponding project problem, the referencing entity/file inspection, code search for stale and expected names, and stale-ref dismiss/undismiss actions. Use `--refresh` when you need to rescan stale references; the refresh path is cache-native, reuses the previous scan when the relevant input digest has not changed, and avoids paging full method/global catalogs through `main.py`.
Use `--include-ignored` to include ignored/allowed problem rows and `--include-dismissed` to include dismissed rows in `issues`; resolved inactive rows still stay hidden.
Memory coverage in `issues` and `show project-status --summary` is the current project/catalog coverage view, so coverable entities that have not produced memory range records still reduce the percentage. The raw materialized range-index coverage is nested under `materialized_range_index_coverage` when both views are available. `issues` uses compact memory coverage output: relevant entity kinds are kept, and zero-coverable/no-range kinds are summarized under `_omitted`.

```powershell
python wave3.py issues --limit 25
python wave3.py issues --refresh --limit 25
python wave3.py issues --include-diagnostics --limit 25
python wave3.py issues --kind missing_ref_issue --limit 25
python wave3.py inspect missing-ref target 0x00437470
python wave3.py inspect missing-ref target 0x00437470 --include-lower-evidence
python wave3.py suggest missing-ref target 0x00437470
python wave3.py suggest missing-ref class cls_0x4306e0
python wave3.py issues --refresh --kind global_data_issue --limit 25
python wave3.py issues --entity-kind method --limit 25
python wave3.py show problem <issue_id>
python wave3.py inspect problem <issue_id>
python wave3.py inspect problem <issue_id> --include-entity
python wave3.py list global-data-issues --limit 25
python wave3.py list global-data-issues --needs-type --limit 25
python wave3.py list global-data-issues --needs-owner --with-suggestions --limit 5
python wave3.py list global-data-issues --needs-type --deep-suggestions --limit 3
python wave3.py list global-data-issues --needs-owner --deep-suggestions --confidence high --scan-limit 50 --limit 5
python wave3.py list stale-ref --limit 25
python wave3.py list stale-ref --refresh --limit 25
python wave3.py list stale-ref --include-resolved --limit 25
```

Use `suggest method-owner` for duplicate method-owner issues. It is read-only: it scores candidate owner classes from the current Wave3 owner, owner file, `this` pointer signatures, scoped C++ definitions, and duplicate-owner issue context. If the best owner matches the current Wave3 owner, review the result and then use the returned `allow problem ... reviewed --reason selected owner <Class>` command. If `owner_mismatch: true`, the helper intentionally does not return an allow command; inspect the current and suggested owners before resolving the underlying ownership.
Use `set method-owner` only after review. Start with `--dry-run`; the real command moves the method overlay to the target owner's file, updates `canonical_owner`/`owner_class`/`owner_file`, updates class method membership lists, refreshes affected files, and leaves the duplicate-owner issue visible for final review.
Use `review method-owner` when a duplicate-owner issue has been reviewed and the selected owner is known. It requires the issue id and selected owner, rejects non-duplicate-owner issues, verifies the owner is one of the conflicting imported owners, optionally applies the owner move, then marks the problem reviewed with an auditable reason. Start with `--dry-run`.
Use `attach class <class_name> --to-file <filename>` when a class has been verified to belong to a true file container rather than only its default ownerless file. The command updates the class `owner_file`, adds the class to the target file's `attached_classes`, removes stale class attachments from previous files, and returns a bounded refresh summary. Use `attach classes <class_name> [<class_name> ...] --to-file <filename>` for reviewed batch ownership moves; it performs all class/method ownership updates first and then refreshes affected files once. Use `set file-simpath <filename> <path> --dry-run` before moving a file under a generated subdirectory; the dry-run reports the resolved file and target path without rewriting simroot or cache state.
Use `delete files <filename> [<filename> ...]` only after the files are empty and their classes/globals have already been moved. It tombstones all listed empty file records and performs one cleanup refresh instead of running full single-file delete cleanup repeatedly.
Use `attach method <addr_or_name> [<addr_or_name> ...] --to-file <filename>` when a method has no true class owner and should be emitted as a file-level helper in a reviewed source file. The command clears class ownership, sets the target file owner, removes stale class membership, moves scoped live C++ sections out of the old file when present, removes omitted markers from the target file, syncs method signatures from the moved file-level definitions, and refreshes affected output. Start with `--dry-run` to confirm the target file and method set before changing data.
Use `set template-params-many <kind> <id=params> [<id=params> ...]` when several reviewed template entities share one owner file. It persists every template-parameter update first and then refreshes/regrades each touched owner file once.

```powershell
python wave3.py suggest method-owner 0x0046d580
python wave3.py suggest method-owner 0x0046d580 --owners RankingDialog,WebBoardDialog
python wave3.py set method-owner 0x00494f70 ButtonControlPane --dry-run
python wave3.py set method-owner 0x00494f70 ButtonControlPane
python wave3.py review method-owner problem_0e8f9c94e90e1f4e ButtonControlPane --dry-run
python wave3.py review method-owner problem_0e8f9c94e90e1f4e ButtonControlPane --reason this pointer and scoped definition evidence
python wave3.py attach class ScreenshotCapture --to-file class_ScreenshotCapture.cpp
python wave3.py attach classes ProtectedArray_struct_ShoeInfo_ ProtectedArray_struct_WeaponInfo_ --to-file ProtectedArray.h
python wave3.py delete files class_ProtectedArray_struct_ShoeInfo_.cpp class_ProtectedArray_struct_WeaponInfo_.cpp
python wave3.py set template-params-many class ProtectedArray_struct_HairInfo_=HairInfo ProtectedArray_struct_Acc2Info_=Acc2Info
python wave3.py attach method 0x004bb8d0 0x004bb9b0 --to-file SoftwareBlend16.cpp --dry-run
python wave3.py attach method 0x004bb8d0 0x004bb9b0 --to-file SoftwareBlend16.cpp
```

If issue classification logic changes during development, refresh the stored issue index without rebuilding simulation output. Prefer the user-facing `issues --refresh` when you only need accurate counts/output. Use the development command when you intentionally want to refresh the stored issue index as a dev operation:

```powershell
python wave3.py issues --refresh --limit 25
python wave3d.py debug refresh project-issues
```

`debug refresh project-issues` updates the project issue index. It does not automatically regrade every affected entity, because that can touch a large part of the project. After changing issue classification or fixing metadata, regrade the affected item or kind:

```powershell
python wave3d.py debug regrade global-data g_pEffectManager
python wave3.py regrade grade global-data g_pEffectManager
python wave3d.py debug regrade-all --kind global-data
```

Use contamination cleanup cautiously and always start with a dry-run:

```powershell
python wave3d.py debug show contamination --pattern Wave3
python wave3d.py debug cleanup contamination --pattern Wave3 --dry-run
python wave3d.py debug cleanup contamination --pattern Wave3 --confirm
```

The cleanup matcher compares entity ids, file ids, emitted/generated basenames, and derived-baseline basenames. It intentionally ignores parent directory names such as `core\data\wave3` and stable sidecar suffixes such as `.meta_wave3`, so broad patterns do not accidentally match every generated file.

If memory range indexing or memory collection logic changes, refresh the memory index explicitly. Use `--rematerialize` when the per-file memory documents need to be regenerated from the current workflow project graph before the global memory index is rebuilt:

```powershell
python wave3d.py debug refresh memory-indexes
python wave3d.py debug refresh memory-indexes --rematerialize
python wave3d.py debug refresh memory-indexes --rematerialize --file class_FolderTreePane.cpp --batch-size 1
python wave3d.py debug refresh memory-indexes --rematerialize --offset 0 --limit 50 --batch-size 5
```

`debug refresh memory-indexes --rematerialize` supports bounded development runs. Use `--file` for one file, or `--offset` and `--limit` to process a slice of the file list. `--batch-size` controls how many files are merged into each targeted workflow-index request. Long refresh, simulation rebuild, and all-regrade commands have extended client timeouts and update the operation-status file so progress can be monitored with `wave3d.py show service-status`.

`show grade <kind> <id>` evaluates the current score without being a development command and includes `next_commands` for the relevant inspection/regrade/checkout workflow. For file-owned classes, methods, and globals, v2 uses a targeted file-scoped project index instead of asking `main.py` to load the full project graph. Global-data grading uses a single-entity metadata scope because type/owner repair scoring does not need unrelated file/class context. Global-only files that emit only `global-data` declarations are treated as valid declaration owner files: file grading uses the owned global-data rollup plus source-line provenance instead of failing required code-body tests as `no_code`. `regrade grade <kind> <id>` now uses the same targeted grading scope as `show grade`, persists the updated score through a cache-native file-entity override update, and skips file-storage/simroot rematerialization when the stored grade result is unchanged. `debug regrade <kind> <id>` is the development-only equivalent and should be run through `wave3d.py`.
For file-level inspection, `show grade file <filename>` uses a targeted v2 project index for that file instead of scanning the full runtime project graph.

Regrade refresh summaries include `timing_seconds` for materialization, cache file-document refresh, simroot rebuild, runtime-index sync, and runtime cache hydration. A changed grade still refreshes the owning emitted file so score comments stay current; an unchanged grade reports `grade_result_unchanged` and returns without rewriting metadata or emitted files.

Project problem links are attached to entity views and cache work queues. If `issues --kind global_data_issue` reports an active issue for an entity, `show global-data <id>` should also show `project_problem_counts.global_data_issue`, and regrade should include the matching `problem:global_data_issue` autograder row.
Targeted commit/refresh/stale-ref workflows must refresh project issues in file scope only. A targeted file operation should not replace the full project issue index with a partial project graph.

Fix existing global-data items with missing or incorrect normalized types using `set global-data-type`. Start with `--dry-run`; the preview resolves the item, normalizes the target type, reports whether the value would change, and skips persistence/refresh. The real command updates the Wave3 overlay and triggers targeted refresh/regrade for the owning file when one exists.
Use `suggest global-data-type` first when the correct type is not obvious. It is read-only: it resolves the global-data item, searches indexed current code evidence, scores candidate C++ type strings from casts/assignments/name evidence/member-access evidence, and returns the exact `set global-data-type` command to run after manual review. Add `--exhaustive` when you specifically need owner-method decompilation evidence included inline; the default path avoids owner-method decomp hydration so normal type checks stay responsive. Indexed table globals can infer pointer-to-element candidates from explicit narrow element casts in owner decompilation, such as `static_cast<short>(g_table[index])` producing `short*`; widening casts such as `static_cast<int>(g_table[index])` are reported as non-candidate evidence because they may hide a narrower stored element type. When explicit casts are absent, it also reports conservative heuristics from global naming conventions (`g_pFoo`, `g_isFoo`, `g_hFoo`, `g_szFoo`), known WinAPI dispatch entries (`g_pfnGetLocaleInfo`, `g_winApiCreateFileMapping`), receiver-like static class-call arguments such as `EffectManager::ResetEffect(g_pEffectManager)`, and object member access such as `g_gameClock->GetCurrentTick()` when the member name uniquely resolves to one known Wave3 class owner or when every other typed global using the same member agrees on one type. Static call arguments only infer `Class*` when the symbol is the first receiver-like argument or the symbol name matches the class; later resource/value arguments are reported as non-candidate evidence instead of producing unsafe class pointer suggestions.

`suggest global-data-type` uses cache-native support packets for the normal indexed evidence path. `wave3_cache` resolves the target global-data row, performs lightweight current-line searches for direct symbol/member evidence, returns active global-data issue ids, and includes type-resolution hints for peer-typed member evidence. This keeps the public `search code` command feature-rich while avoiding unnecessary full search-result decoration inside suggestion commands. The response `evidence_mode` is `indexed_full` for the normal direct command, `quick_code_search` when a queue command asks for the fast first pass, and `exhaustive` when `--exhaustive` is requested.
Candidate rows include `type_resolution`. `project_type` means the candidate base type currently exists in Wave3 catalogs, `known_external_or_primitive` covers primitives/Win32/CRT-style types, `function_pointer_or_callback` covers explicit function-pointer signatures, and `unresolved_project_type` means the candidate name is not currently known to Wave3 and needs manual confirmation or a missing type/class import before relying on it. When the top candidate is unresolved, `next_commands` includes `search symbol <BaseType>` and `search code <BaseType>` follow-ups before review/apply.
When no safe candidate can be inferred, the evidence list should still explain the usage shape. For helper calls such as `LoadUiSpriteFrame(g_uiResourceManager, ...)`, `function_argument_shape` records the function name and argument index so the next manual step is to inspect that helper signature or peer call sites.
Use `review global-data-type` when a missing-type `global_data_issue` has been inspected and the selected type is known. It requires the issue id and explicit type, validates that the issue is a type issue, shows the current suggestion in `--dry-run`, applies the type through `set global-data-type`, then reports whether the original issue resolved. It does not blindly allow/hide the issue; ownership-only global-data issues must be fixed with `set global-data-owner`.
Use `suggest global-data-owner` for ownership-only `global_data_issue` rows before setting a true owner. It is read-only and scores candidate files from observed `owner_files` provenance, owner method materialization files, owner class files, and singleton assignment evidence such as `g_pTextFilter = this;` inside `class_TextFilter.cpp`. The command intentionally warns that `owner_files` are reference/provenance evidence only; the real owner should be set only after review.
Owner suggestions include `best_files` and `best_is_tied`. If `best_is_tied` is true, multiple files have equal evidence and the command is telling you to inspect those files rather than blindly apply the first candidate.
Use `review global-data-owner` when an ownership `global_data_issue` has been inspected and the selected file is known. It requires the issue id and explicit target file, validates that the issue is an owner-file issue, shows the current suggestion in `--dry-run`, applies `set global-data-owner`, then reports whether the original issue resolved. If the selected file does not match the top suggestion, the response sets `owner_mismatch: true` so the choice is auditable.
Use `set global-data-owner` when a global-data row has a type but no true Wave3 owning file. Start with `--dry-run`; the real command sets `owner_file`, preserves observed `owner_files`, refreshes the target file output, regrades affected file-owned entities, and refreshes project issues.
Use `set global-data-storage` when a reviewed global-data row has all three facts at once: normalized type, true owner file, and exact storage address range. It replaces separate `set global-data-type`, `set global-data-owner`, and `add memory-range` calls with one audited command and one refresh path. Start with `--dry-run`; the preview reports the current type/owner/range state, whether the exact range already exists, and `blocked_by_existing_ranges` when another entity already owns any byte in the proposed range. The real command refuses those overlaps because they are alias/merge or range-boundary problems, not safe storage repairs.
Use `rename global-data <old> <new> --dry-run` only for simple symbol renames. If `<new>` already resolves to another global-data entity, dry-run reports `blocked: true` with `target_conflict`, and the real command refuses the rename. That case is an alias/merge problem, not a rename; inspect both entries and use a dedicated merge workflow when available instead of creating duplicate records for one storage address.
Normal repair commands return bounded refresh summaries. For example, `set global-data-type` reports target file ids, total storage/simroot record counts, regrade counts, and synced cache documents instead of dumping the full file-storage/simroot index. `owner_files` on global-data are reference/source context, not true Wave3 file ownership; only `owner_file` or an intentional default file drives materialization refresh.
After applying a global-data type/owner repair, run `issues --refresh --kind global_data_issue --limit 25` if the entity view and grade disagree about active project problems. Then run `regrade grade global-data <id>` to persist the new score.
If a global is used through `->` but no safe concrete class can be inferred, `suggest global-data-type` reports non-candidate member-access evidence such as `member_access_no_known_method_owner` or `peer_typed_member_access_ambiguous`. Treat that as a pointer/object hint that needs class/member correlation before setting a type.

```powershell
python wave3.py suggest global-data-type g_inventorySlotTable --limit 25
python wave3.py suggest global-data-type g_gameClock --limit 1
python wave3.py suggest global-data-type g_gameClock --limit 25 --exhaustive
python wave3.py review global-data-type problem_00e2c461cbe4595a bool --dry-run
python wave3.py review global-data-type problem_00e2c461cbe4595a bool --reason boolean flag evidence
python wave3.py suggest global-data-owner g_pIdleWatcher
python wave3.py review global-data-owner <owner_issue_id> class_IdleWatcher.cpp --dry-run
python wave3.py review global-data-owner <owner_issue_id> class_IdleWatcher.cpp --reason single materialized owner
python wave3.py set global-data-owner g_pIdleWatcher class_IdleWatcher.cpp --dry-run
python wave3.py set global-data-owner g_pIdleWatcher class_IdleWatcher.cpp
python wave3.py set global-data-storage g_pIdleWatcher --type IdleWatcher* --owner class_IdleWatcher.cpp --range 0x0069b000 0x0069b003 --source documented-ida-singleton-xrefs --notes "reviewed singleton storage" --dry-run
python wave3.py set global-data-storage g_pIdleWatcher --type IdleWatcher* --owner class_IdleWatcher.cpp --range 0x0069b000 0x0069b003 --source documented-ida-singleton-xrefs --notes "reviewed singleton storage"
python wave3.py set global-data-type g_pEffectManager EffectManager* --dry-run
python wave3.py set global-data-type g_pEffectManager EffectManager*
python wave3.py show global-data g_pEffectManager
python wave3.py show grade global-data g_pEffectManager
```

Use the work queues to choose what to reverse next:

```powershell
python wave3.py list accuracy-work --limit 25
python wave3.py list next-class --limit 10
python wave3.py list next-method --class AboveFrame --limit 10
python wave3.py list missing-ref --class AboveFrame --limit 25
python wave3.py list ungraded --limit 25
python wave3.py regrade ungraded --kind file --limit 10 --dry-run
python wave3.py regrade ungraded --kind file --limit 10
python wave3.py list stale-grade --limit 25
python wave3.py regrade stale-grade --kind global-data --limit 25 --dry-run
python wave3.py regrade stale-grade --kind global-data --limit 25
python wave3.py filter method --callers-gt 3 --limit 10
```

Work queue rows include `next_commands` for the immediate inspection and grading actions. `list accuracy-work` rows include both `reasons` and `work_reasons`, plus a `summary` block with full/backlog reason counts. Method/global work rows include the core reverse-engineering evidence commands (`show xref`, `show decomp`, `show diff`, memory range/tree validation, grade/regrade, and checkout) so the next step can be run directly from the queue row. Commands are shown without the `python wave3.py` prefix unless the command itself is development-only.
Global-data work rows include `suggest global-data-type <id> --limit 25` and `suggest global-data-owner <id>` so type/owner repair work can start from evidence before regrading.
Large queue responses also include top-level `next_commands` for the safest batch action. For example, `list ungraded` points to `regrade ungraded ... --dry-run` and then the real bounded batch command; `list stale-grade` does the same for `regrade stale-grade`. `list accuracy-work`, `list next-class`, `list next-method`, `list next-global`, `list new-class`, `list new-global`, and `list stub` promote the first few returned row commands to top-level `next_commands` so the response can be used directly as a triage launcher. Method/global queues promote enough row commands to include xref, decompilation, and diff evidence.
When `list accuracy-work --kind global-data` sees active global-data project problems, the response also links to `list global-data-issues --needs-type`, `list global-data-issues --needs-owner --with-suggestions`, and `issues --kind global_data_issue` before regrade-only actions.
`list accuracy-work` only treats memory coverage as work when the entity has unresolved coverable memory or explicit memory conflicts. Normal resolved, aggregate, and not-applicable memory statuses are not queue reasons by themselves.
Use `list stale-grade` after refreshing project issues, memory indexes, or metadata scans. It lists entities whose stored `autograder_result` was computed against older project-problem counts, so `show progress` and `list accuracy-work` do not silently overstate completion. `show progress` includes a `stale_grades` counter and treats stale grades as incomplete until they are regraded.
`show progress` includes `ungraded` and `stale_grades` counters, visible active issue backlog counts, and `recommended_work` entries for the largest accuracy blockers. The issue backlog excludes ignored/allowed/dismissed rows, while `issues` can still show the broader generated summary. When `--kind <kind>` is used, the issue backlog is filtered to issues relevant to that kind; for example, `--kind global-data` reports global-data type/owner issues instead of unrelated missing-ref backlogs. Recommendations link directly to global-data type/owner queues, missing-ref reconstruction queues, duplicate-owner review, memory diagnostics, and stale/ungraded regrade batches when those backlogs exist. Global-data recommendations include the small `--deep-suggestions` queues first so high-confidence type/owner fixes are visible without reading the broader issue list.
Use `regrade stale-grade` to fix stale stored grades in bounded batches instead of running a broad `regrade-all`. Start with `--dry-run` to see the exact rows, then rerun without `--dry-run` to persist updated scores and refresh affected outputs.
Use `regrade ungraded` for bounded first-pass scoring of items returned by `list ungraded`. File batches are grouped so selected files are graded together and affected outputs are refreshed once per batch instead of one process per file.
Cache-backed queue commands include `count`/`returned_count` for the limited response and `total_count` for the full matching backlog.
`filter method` is cache-backed in v2. Wave3 catalog filters are applied by `wave3_cache`, and raw method metrics such as stub/thunk/caller counts are read by `wave2_cache` from resident normalized Wave2 data instead of forcing `main.py` to request lower raw data one method at a time. Results are sorted before `--limit` is applied: incomplete/stale/ungraded methods come before complete methods, then lower grades and higher caller counts are prioritized. Rows include `complete`, `work_reasons`, `returned_count`, and `total_count` so the command can be used as a reverse-engineering triage queue.
Method navigation commands (`resolve method`, `resolve global`, `filter method`, `show decomp`, and `show diff`) include `next_commands` in v2. Use those follow-ups to inspect xrefs, compare decompiler/current code, review grades, open checkout, and validate memory ownership without manually guessing the next command. `resolve method` and `resolve global` are cache-backed in v2 through `wave3_cache` catalog matching; `show diff` computes from the v2 `show decomp` payload and does not call the legacy v1 runtime implementation.
File navigation commands (`list file`, `list global-file`, `show file`, and `show file --summary`) also include `next_commands` in v2. File follow-ups cover grade/regrade, checkout, simpath/rename dry-run, materialization refresh, and the first attached classes/globals when available.

The default missing-ref queue is actionable-only. Entries marked `should_reconstruct: no` or explicitly excluded are hidden unless `--include-excluded-targets` is passed.
Untriaged target rows without a projected name or owner are also hidden by default; use `--include-unknown` when auditing raw target gaps from `issues --kind missing_ref_issue`. Missing-ref issue rows for untriaged targets now include `list missing-ref --include-unknown --limit 25` in `next_commands` so the referenced queue is not accidentally empty.
Use `list missing-ref-classes` for actionable class-level missing-ref work; `list missing-ref` only shows unresolved target-level rows, so it can be empty when all actionable targets have already been imported but class-level gaps remain.
Missing-ref queue rows include `next_commands` for triage and reconstruction. Target rows include memory/code lookup plus `create method ... --dry-run` or `create global ... --dry-run` previews before the matching mutating create scaffolds when enough owner context exists. Ready class rows include projected-name/reconstruct commands, a `create class ... --dry-run` preview, and the real `create class ... --missing-ref-class <id>` scaffold with `--class-addr`, a synthetic `missing-ref/class/<id>` source file, reviewed missing-ref source evidence, and `--integration-source missing-ref:<entry_key>`. Run the dry-run first; it reports the payload and default owner/file effects without creating storage, cache overlay entries, or simroot output. Method/global dry-runs omit full `current_code` bodies from the preview payload and report the code length/path instead. Rows that still need naming or safety review keep placeholders instead of pretending the create command is ready.
For manual create commands, prefer this option order when all fields are present: `create method <class> <addr> --name <name> --code-file <path> --source-evidence <text> --signature <signature>`. This avoids free-form option parsing ambiguity and keeps dry-run previews accurate.
Real `create method`, `create global`, and `create global-data` responses return bounded refresh summaries. `create method` seeds the new method memory range from a matching prewave function extent when the cache has one, installs the scoped method body into the owning file `live.cpp`, then syncs `memory_range_index`, `memory_issue_payload`, and `memory_image_map`; `show memory-at <addr>` should report the new Wave3 method immediately without a development refresh. `create global --file <filename>` also attaches the new global to the target file's `attached_globals` list immediately, so a separate `set global-owner` repair should not be needed for ordinary manual helper creation.
Missing-ref class issue contexts and class queue rows parse addresses from ids like `cls_0x560a10` and use that value in the `create class ... --class-addr ...` scaffold; if no address is recoverable, the command keeps `<addr>` as a placeholder.
Missing-ref rows include `reconstruction_safety`. Use `--ready` to show only rows that have reviewed reconstruction metadata and no detected safety blockers, `--blocked` to show mixed/unstable buckets that should not be directly created, `--needs-name` to show rows needing a projected name/target triage, and `--triage-required` to show rows that are not explicitly marked `should_reconstruct: yes`.
For class buckets whose notes say they conflate unrelated families, the tool suppresses the direct `create class ...` scaffold and instead suggests marking the bucket non-reconstructable or splitting/reviewing per target. This avoids turning legacy mixed buckets into inaccurate Wave3 classes.
`list missing-ref` and `list missing-ref-classes` include both `entries` and `items` for compatibility, plus top-level `count`, `returned_count`, `total_count`, `summary`, and `next_commands` so generic queue tooling does not need to unpack command-specific aliases. Their `summary` block includes `candidate_count`, `filtered_total_count`, `safety_status_counts`, and `returned_safety_status_counts`, so ready/blocked/triage proportions are visible without running every filter separately. `list missing-ref-classes` also exposes a `list_missing_ref_classes` response alias in addition to the historical generic `list_missing_ref` key.
Missing-ref list responses include top-level `next_commands` for the current list plus the main filtered queues (`--ready`, `--blocked`, `--needs-name`, `--triage-required`) and focused `show missing-ref ...` commands for the first returned rows.
Use `show missing-ref <target|class> <identifier>` for focused inspection of one missing-ref annotation without first finding its problem id. It resolves `target:<id>` or `class:<id>` keys, returns the merged readonly/overlay entry, related active issues, and the next triage/reconstruction commands. The response also mirrors the key reconstruction fields at the top level: `projected_name`, `projected_owner_class`, `should_reconstruct`, `reference_count`, `notes`, `readonly_present`, `overlay_present`, `reconstruction_safety`, and `related_issues`.
Incremental missing-ref issue refreshes resolve current Wave3 class/method/global ids from `wave3_cache` before regenerating missing-ref problem rows. This prevents already-imported missing-ref targets or classes from reappearing in `issues` and `show progress` after metadata edits.

```powershell
python wave3.py list missing-ref --include-unknown --limit 25
python wave3.py list missing-ref-classes --limit 25
python wave3.py list missing-ref-classes --ready --limit 25
python wave3.py list missing-ref-classes --blocked --limit 25
python wave3.py list missing-ref-classes --needs-name --include-unknown --limit 25
python wave3.py show missing-ref target 0x0046f680
python wave3.py show missing-ref class cls_0x560a10
python wave3.py show missing-ref class:cls_0x560a10
python wave3.py create class RecoveredPane --class-addr 0x00001234 --source-file missing-ref/class/cls_0x1234 --source-evidence reviewed missing-ref class cls_0x1234 references=2 --integration-source missing-ref:class:cls_0x1234 --missing-ref-class cls_0x1234 --dry-run
```

Use symbol search for fast navigation by recovered class, method, global, file, and metadata names:

```powershell
python wave3.py search symbol MiniMap --limit 10
python wave3.py search symbol MiniMap --include-fields --limit 10
```

Symbol search is served by `wave3_cache` and returns bounded, kind-prioritized results with row-level `next_commands`. Normal symbol search uses a resident lightweight id/name index (`resident_symbol_search_index`) instead of walking full catalog entries. Field symbols are skipped by default because the field catalog is very large; use `--include-fields` only when you explicitly need field-name search.

Use code search for bounded text lookup in current Wave3 emitted file documents:

```powershell
python wave3.py search code HandlePacket --limit 10
python wave3.py search code OnNotify --class AboveFrame --limit 10
```

`search code` returns `count`, `returned_count`, `total_count` when known, `minimum_total_count`, `has_more`, row-level `next_commands`, and top-level `next_commands`. It searches current Wave3 file documents first and only asks lower Wave2/prewave caches when the current file search does not fill the requested limit. When the search term matches an entity id/key/name in a current Wave3 file, the file row adds direct entity commands such as `show global-data <id>`, `suggest global-data-type <id> --limit 25`, `show method <addr> --summary`, and `matched_entities` records the matched entity previews with their own `next_commands`. The cache scans the full entity range for command generation even though the returned `entities` preview remains bounded.

Code search is served by `wave3_cache`. It searches current file-document text first, then asks `wave2_cache` and `prewave_cache` for lower-layer code evidence only when more result slots are needed. The lower searches run in parallel for bounded requests, and the readonly caches use resident lowercase code-search indexes to avoid per-request full payload scans. Results can be file rows from current Wave3 output or method/global/function rows from lower cache evidence; rows include line snippets, context where available, source layer, and `next_commands`. `main.py` does not walk every method/global through lower-cache raw reads.

Memory range tools help verify ownership/coverage before changing overlays:

```powershell
python wave3.py show memory-at 0x00430058
python wave3.py show memory-coverage
python wave3.py show memory-coverage --include-catalog
python wave3.py inspect memory-image
python wave3.py list memory-segment --classification needs_reconstruction --limit 25
python wave3.py list memory-segment --include-gaps --limit 25
python wave3.py list memory-gap-global --limit 25
python wave3.py classify memory-segment 0x00401000 0x00401fff needs_reconstruction --reason "project-owned code that must be recreated"
python wave3.py classify memory-segment 0x00402000 0x00402fff crt --reason "MSVC CRT startup/helper code" --library msvc_crt --version "reviewed" --build-ref libcmt.lib --requires-build-ref
python wave3.py classify memory-segment 0x00403000 0x00403fff library --library "Miles Sound System" --version "6.x" --build-ref mss32.lib --requires-build-ref --reason "third-party audio code; reference/link instead of rewriting"
python wave3.py clear memory-segment-classification 0x00403000 0x00403fff
python wave3.py unclassify memory-segment 0x00403000 0x00403fff
python wave3.py list memory-range class ClanBankItemListPane
python wave3.py inspect memory-range class ClanBankItemListPane
python wave3.py inspect memory-range class ClanBankItemListPane --include-tree --include-validation-details
python wave3.py show memory-tree class ClanBankItemListPane
python wave3.py validate memory-range class ClanBankItemListPane
python wave3.py recompute memory-range class ClanBankItemListPane --from-children --dry-run
python wave3.py set class-vtable TextFilter 0x0062e188 --slot 0x005958d0 --slot-count 1 --reason "IDA xrefs confirm TextFilter one-slot vtable"
python wave3.py set class-vtable-family LineInputPane 0x0061ca58 0x0061caa8 0x0061cad8 --slots "0x004f2ea0,0x004f2e59,0x004f2e64" --slot-counts "19,11,2" --reason "IDA decorated vtables and constructor stores confirm the LineInputPane family tables"
python wave3.py mark memory-range method 0x00430058 0x00430058 0x00430067 allowed_shared --reason "alternate entry inside 0x00430041"
python wave3.py classify memory-range method 0x00430058 0x00430058 0x00430067 crt --reason "MSVC CRT helper; do not recreate as product code"
python wave3.py classify memory-range method 0x00430058 0x00430058 0x00430067 library --library "Miles Sound System" --version "6.x" --build-ref mss32.lib --requires-build-ref --reason "third-party audio import"
python wave3.py classify memory-range method 0x00430058 0x00430058 0x00430067 duplicate_omitted --reason "same compiler-generated thunk already covered by owning item"
python wave3.py list memory-conflict --limit 25
python wave3.py list memory-duplicate --limit 25 --offset 0
python wave3.py list memory-libraries --limit 25
python wave3.py list memory-libraries --assigned-only --limit 25
python wave3.py list prewave-function --range 0x00401000 0x00414283 --limit 25
python wave3.py ignore memory-issue <issue_id> --reason <text>
python wave3.py allow memory-issue <issue_id> allowed_shared --reason <text>
python wave3.py unallow memory-issue <issue_id>
python wave3.py show memory-issue <issue_id>
```

Memory coverage is tiered:

1. Executable/image tier: the whole PE image is split into normalized segments and gaps. Use this layer to classify `needs_reconstruction`, `library`, `crt`, `third_party`, `compiler_generated`, `import_stub`, `resource`, `padding`, `unmapped_gap`, `null_area`, or `unknown_review_required`.
2. Reconstruction-scope tier: ranges marked `needs_reconstruction` are the bytes Wave3 expects project source/entities/source lines to cover.
3. Owner/entity tier: file, class, method, global, global-data, static-member, and related metadata entities own specific memory ranges.
4. Sub-entity tier: class child ranges, method body ranges, data symbols, vtables, switch tables, thunks, and other reviewed subranges refine entity coverage.
5. Source provenance tier: final emitted simroot source lines map back to entity/range provenance or exact manual line overrides. If a simroot map is not available yet, Wave3 falls back to the file-storage `live.cpp` map until the file is materialized.
6. Issue/exception tier: overlaps, duplicates, missing ranges, external/library omissions, and manual allow/ignore reasons make exceptions auditable.

`show memory-coverage` reports the fast memory-range/source-line summary plus the top-level image coverage. Use `show memory-coverage --include-catalog` when you need the full catalog-visible entity rollup, including rows that only exist in sharded catalog storage. `inspect memory-image` gives the image summary plus bounded segment and global-gap samples. `list memory-segment` is for reviewing PE segments and override chunks. `list memory-gap-global` shows bytes inside `needs_reconstruction` image ranges that have no product entity/source coverage yet. These gaps also surface through `issues --kind memory_image_issue --limit 25` so the normal issue workflow can track global uncovered executable/data regions. `inspect problem <memory_image_gap:...>` now produces a bounded work packet for the exact image gap, including start/end/classification/segment metadata, `show memory-at` context for the first byte, and direct commands for either adding product coverage or classifying the range as external/generated. Classify external/library/CRT/compiler-generated chunks at the image tier with `classify memory-segment`; remove a mistaken image-tier override with `clear memory-segment-classification` or `unclassify memory-segment`. Classify a specific entity range with `classify memory-range`.

Use `list prewave-function --range <start> <end> --limit 25` when a global image gap is too large to review as one chunk. It asks `wave3_cache` to proxy a bounded prewave function-range scan, showing each lower function that overlaps the range, known size/end address, library/external flags, and direct `show prewave-function` / `show decomp` follow-ups. When an image-tier `classify memory-segment` override covers the lower function, the returned prewave row is decorated with the effective segment classification, library name/version, build reference, and `classification_source: wave3_memory_image_segment`; this keeps read-only prewave data unchanged while making reviewed Wave3 overlay classifications visible. `inspect problem` includes a 10-row sample from this scan for `memory_image_issue` rows.

Treat `.bss` or zero-initialized data as real data until reviewed. `unmapped_gap` means no PE-backed memory; it is not the same as zero-filled project globals. Use `null_area` or `padding` only when you have verified the range is not meaningful reconstruction work.

The v2 memory inspection commands are cache-backed. `show memory-at` reads the cache-loaded memory-range index and reports visible matches, hidden allowed/ignored counts, and `next_commands` for the matched entities. It also asks `wave3_cache` for the effective image segment at that exact address; if no Wave3 entity range covers the byte, a classified image segment is returned as a `memory-segment` match, and lower prewave function evidence is still included under `lower_layer_matches.prewave_functions`. `inspect memory-range` is the normal entity-level memory packet: it combines bounded range samples, child/conflict counts, validation issue summaries, and direct recompute/allow/ignore follow-ups. Use `--range-limit <n>` to change the sample size, `--include-tree` for the full memory tree payload, and `--include-validation-details` for the raw validation output. `list memory-range`, `show memory-tree`, `validate memory-range`, and the memory issue lists remain available for direct focused reads and include counts plus `next_commands` for drilling into entity ownership, reviewing the issue, or making a dry-run recompute before changing overlay data. `global-data` is a primary coverable memory kind: `show memory-coverage --include-catalog` includes catalog-visible global-data rows even when they only exist in sharded catalog storage, and `list memory-unresolved --entity-kind global-data` uses current file range overlays before deciding whether a data symbol is still unresolved. `list memory-unresolved` includes both generated memory issues and catalog-visible coverable entities whose coverage status is still unresolved, so it is the queue to use when project memory coverage is below 100%.

Use `set class-vtable` when IDA confirms one class vtable that Wave3 has not imported yet. The command records reviewed vtable metadata on the class, including the table address, slot count, slot target addresses, and source evidence, then refreshes the owner file and grading. Add a matching `add memory-range class <class> <vtable_start> <vtable_end> --kind vtable ...` row when the vtable bytes should also appear in address coverage and `show memory-at`.

Use `set class-vtable-family` when IDA shows a compact multi-view class table family such as primary/secondary/tertiary tables. It records all table metadata and adds matching class-level `vtable` memory ranges in one owner-file refresh, which avoids repeated mutation/materialization work. The number of `--slots` and `--slot-counts` entries must match the number of vtable addresses.

Source-line provenance maps final emitted source lines back to memory ranges:

```powershell
python wave3.py inspect source-map class_AboveFrame.cpp --summary
python wave3.py list source-lines class_AboveFrame.cpp --limit 25
python wave3.py list source-lines class_AboveFrame.cpp --entity-kind method --entity-id 0x004616b0 --limit 25
python wave3.py list source-lines class_AboveFrame.cpp --memory-range 0x004616b0 0x004616ff --limit 25
python wave3.py list source-lines class_AboveFrame.cpp --missing-ranges --limit 25
python wave3.py list source-lines class_AboveFrame.cpp --unmapped --limit 25
python wave3.py show source-line class_AboveFrame.cpp 42
python wave3.py set source-line-range class_AboveFrame.cpp 42 0x004616b0 0x004616c4 --reason "manual instruction-to-line review" --entity-kind method --entity-id 0x004616b0
python wave3.py clear source-line-range class_AboveFrame.cpp 42
```

The generated source map is stored with each Wave3 file document and is served through `wave3_cache`; `main.py` asks for the `source_map` and `ranges` blocks only. When a simroot file has been emitted, `wave3_cache` prefers the simroot source-map sidecar so line numbers match the final `.cpp` after autograder headers, penalty comments, include normalization, and `$$SIMPATH` handling. The storage `live.cpp` source map remains a fallback for files that have not been emitted yet. Automatic rows use `entity_range_by_line` provenance because a line inside a method/class/global inherits that entity's reviewed memory ranges. Global-data references inside method/global bodies also receive `global_data_reference` rows when the symbol has a reviewed storage range, so singleton assignments such as `g_pFoo = this` can carry the data-storage provenance even when no standalone declaration line is emitted. Use `set source-line-range` only when you have manually verified a narrower exact address span for one source line. Manual line overrides are stored in the file memory-range overlay under `source_line_overrides`, refreshed through targeted file/simroot materialization and regrade, and reported as `line_exact_manual`.
Recovered-file include normalization treats scoped install comments and entity banners as body boundaries. Includes found after those markers are moved/commented into the normalized top include section instead of being emitted twice as active includes.

The `source_line_provenance_present` grader test is enabled for files, classes, methods, globals, and global-data. It fails when emitted source lines for a coverable item have no memory range and are not explicitly classified as external/omitted. Use `list source-lines <file> --missing-ranges` or the grader line findings to see the exact emitted lines that are subtracting provenance score. Range classification is part of scoring: `crt`, `library`, `third_party`, `compiler_generated`, `runtime_external`, and `duplicate_omitted` markers tell the source map and overlap scanner that the range is intentionally external/shared instead of missing product code.

Generated memory issues can be automatically allowed by markers such as CRT/shared-overlap markers. Manual `allow` or `unallow` commands are stored in the system overlay and override the generated scanner result. `memory_image_issue` rows are global image gaps; resolve them by adding entity/source coverage for product bytes or classifying the range as library/CRT/compiler/resource/padding/etc with a reason. `mark memory-range` stores a marker on the actual entity range; class aggregate ranges inherit child method markers, so a reviewed shared method range can also suppress the derived class aggregate conflict when appropriate. `mark memory-range` and `unmark memory-range` are metadata-only fast paths, but they still incrementally sync `memory_range_index`, `memory_issue_payload`, and `memory_image_map`; normal users should not need `wave3d.py debug refresh memory-indexes` after ordinary marker edits. Use `regrade grade ...` only when stored grade output itself needs immediate regeneration. Memory-range mutation commands return bounded refresh summaries instead of full storage/simroot payloads.
Tombstoned/deleted memory entities are excluded when memory indexes are rebuilt. If memory collection or tombstone logic changes, run `python wave3d.py debug refresh memory-indexes` and then verify with `show memory-at <addr> --include-ignored --include-allowed`.
File-scoped rematerialization with `debug refresh memory-indexes --rematerialize --file <file>` rewrites the requested file documents but rebuilds the global memory index against the full active project catalog. It must not shrink the global memory index to only the rematerialized file's catalog view.
When a manual override contradicts the generated scanner result, `show memory-issue` reports `generated_allowed`, `generated_reason`, `allowed_overridden`, and `memory_issue_override` so the active state is auditable.
`list memory-duplicate` shows exact duplicate address ranges across different items. Use `allow memory-issue <issue_id> duplicate_omitted --reason <text>` for issue-level review or `classify memory-range ... duplicate_omitted --reason <text>` when the range itself should permanently carry the omission marker. `list memory-libraries` combines entity-level Wave3 memory ranges, image-tier `classify memory-segment` overlays, and lower prewave library-function evidence from IDA/Ghidra flags. It reports library names, versions, build references, `requires_build_reference`, ranges, and follow-up commands for marking CRT/library code. Use `--assigned-only` when you only want reviewed/current Wave3 library assignments and do not need the lower prewave discovery sample. The lower prewave library sample is served from a resident `prewave_cache` library-function index, so the command should return a bounded page instead of scanning and resolving every prewave function payload each time.
Exact duplicate validation suppresses class aggregate ranges that only mirror a non-class child range in the same owner file. Those aggregate rows summarize child coverage and are not competing owners. Cross-owner exact duplicates still report, including cases where a method is owned by one file but a different class aggregate claims the same span.

Normal `wave3.py` data edits must keep memory validation current. Commands that create coverable globals/global-data, change memory ranges, move owners, or set memory-affecting metadata such as `disabled`/`excluded` sync `memory_range_index`, `memory_issue_payload`, and `memory_image_map` during the normal command path. Normal memory issue reads also prune stale generated range-conflict rows when the referenced ranges no longer exist in the current cache-backed index. `wave3d.py debug refresh memory-indexes` is a development/repair command for memory scanner logic changes or suspected corruption, not a required step after ordinary Wave3 data edits.

Use `--dry-run` first. `recompute memory-range ... --from-children` uses the current live child ranges from the targeted workflow index, not stale imported parent metadata, then preserves separate child address clusters and only merges overlapping or adjacent ranges. It replaces stale child-derived aggregate rows but preserves reviewed non-aggregate rows such as `vtable`, `raw_helper`, `library`, `crt`, and `duplicate_omitted` coverage; delete those rows explicitly if they were wrong. Repeating the same recompute is a no-op: Wave3 compares the proposed normalized range fields against the current overlay, skips storage/simroot/memory-index/project-issue/regrade refresh work when nothing changed, and returns `noop: true` with reason `memory_range_unchanged`.
`add memory-range ... --dry-run` is non-mutating and returns `refresh.skipped: true`. A real `add memory-range` is idempotent for an existing identical start/end pair and returns `noop: true` with reason `memory_range_already_exists` instead of appending duplicate overlay rows.

Future memory-coverage updates still worth adding:

- Rich PE section import: current image-map input comes from normalized prewave/exported segment metadata. If future exports include `.bss`, resources, TLS, relocations, or linker map data, import them as explicit image-tier ranges instead of inferring from existing segment rows.
- Block-level semantic coverage: add first-class sub-entity records for vtables, RTTI, switch tables, jump tables, import thunks, exception tables, and string/data pools so image coverage can explain non-method bytes without forcing them into broad class ranges.
- Build-reference resolution: library/CRT classifications already store library/version/build-reference fields, but the tool should eventually validate these against project build inputs and report missing link/reference requirements automatically.

## Editing Workflow

Use checkout/commit for code edits so Wave3 can validate stale baselines and persist overlays correctly.

```powershell
python wave3.py checkout edit method 0x004616b0
python wave3.py commit edit method 0x004616b0
python wave3.py commit edit ALL
```

Use `show ... --summary` before checkout to confirm the owner, grade, memory state, and next commands.

## Development Testing Workflow

Before and after code changes, prefer focused tests first, then broader suites:

```powershell
python -m py_compile core\commands\dispatcher_impl.py core\runtime\in_memory_state_impl_v2.py
python -m unittest -v core.tests.test_cache_v2
python -m unittest -v core.tests.test_client_entrypoints
python -m unittest -v core.tests.test_file_commands
```

For longer or failure-prone suites, prefer the development test runner so progress and tail output remain inspectable without confusing the main Wave3 command queue:

```powershell
python wave3d.py debug run-tests core.tests.test_cache_v2 core.tests.test_project_problems --timeout 1800 --poll 5 --tail 80
python wave3d.py debug start-tests core.tests.test_code_entity_commands --timeout 1800
python wave3d.py debug show test-run --tail 80
python wave3d.py debug stop test-run
python wave3d.py debug cleanup test-runs --keep-last 10 --dry-run
```

`debug run-tests` starts a background worker and waits for completion by default. Add `--no-wait` or use `debug start-tests` when you want the command to return immediately, then poll with `debug show test-run`. Test logs and state live under `core/runtime/reports/test_runs`.
`--timeout` and `--poll` must be greater than zero; `--tail` must be zero or greater. `debug stop test-run` first terminates the child unittest process and worker process, escalates if needed, and only reports `stopped` when those processes are no longer alive. If a stop cannot fully terminate a process, the run stays in `stop_requested` so a follow-up `debug start-tests` cannot accidentally overlap another live test worker.
When a waited test run or terminal `debug show test-run` observes that cache-mutating tests changed `wave3_cache`, `wave3d.py` checks cache-health and automatically runs `debug reload-logic` if the main service has stale consumed cache revisions. The refresh result is returned as `post_test_cache_refresh`.
Direct `python -m unittest core.tests...` runs also install a package-level exit hook that performs the same main cache-revision refresh at process exit. Set `WAVE3_TEST_DISABLE_CACHE_REFRESH=1` only when intentionally debugging stale-revision behavior.
Use `debug cleanup test-runs` to prune old test-run report directories. It keeps a live active run and the newest `--keep-last` runs, defaults to dry-run mode, and requires `--confirm` before deleting report folders. Stopped, passed, failed, and timed-out runs are not protected as active; use `--keep-last 0 --confirm` when you intentionally want to remove all terminal test-run reports.

Configured generated roots may be absolute or relative paths. Relative values under `runtime.generated_roots` are interpreted under `source-3`, and all generated-root reporting preserves the logical project path instead of resolving Windows junction targets.

Use `debug self-audit` for a compact tool-health scan that combines service/cache health, command inventory, unchecked implementation TODOs, v1 fallback markers, broad projection markers, and test-run residue. The audit separates actionable report/list/show projection usage from mutation and runtime-infrastructure projection usage. Intentional full-workflow cache endpoints are reported separately as `full_workflow_endpoint_reference_count` so `broad_projection_reference_count` stays focused on actionable report-path regressions. The v2 runtime still imports/inherits the v1 class for compatibility scaffolding; those markers are reported as `v1_compatibility_reference_count`, while `v1_fallback_reference_count` is reserved for actionable fallback/delegation paths.

```powershell
python wave3d.py debug self-audit
python wave3d.py debug self-audit --detail
```

Use `debug profile command` when a normal Wave3 command may be slow. It reports client elapsed time, active/last main-service request timing, queue wait time, service execution duration, client overhead, queue state before/after, diagnostics, and optional cache-health snapshots. Diagnostics call out queue-wait dominated runs, slow service execution, pending queue residue after the command, and request-id mismatches. If the wrapped command times out or raises, the profiler returns a structured `ok=false` diagnostic payload with the active service request and error instead of crashing:

```powershell
python wave3d.py debug profile command -- show project-status --summary
python wave3d.py debug profile command --health --include-result -- list accuracy-work --kind method --limit 5
```

Mutation commands that refresh materialized files may include `refresh.timing_seconds` in their result summary. Use that block to separate local main-service phases such as targeted workflow-index build, initial materialized-view refresh, project-problem refresh, autograde, final materialized-view refresh, cleanup refresh, and total refresh time. If `debug show cache-request-history --slow-only` is empty but `refresh.timing_seconds` is high, the bottleneck is local materialization/autograde work in `main.py`, not cache RPC.

Use `debug profile workflow-index <file_id...>` when targeted materialization or `debug refresh file` is slow. It asks `wave3_cache` to build the same targeted workflow index used by runtime refreshes, but returns only scope counts and stage timings by default so the profiler does not dump or parse the full workflow payload:

```powershell
python wave3d.py debug profile workflow-index class_FontImageLib.cpp
python wave3d.py debug profile workflow-index class_FontImageLib.cpp --cleanup old_file.cpp
```

While a main command is actively running, `show service-status` includes `current_request.elapsed_seconds`, `current_request.timeout_seconds`, and `current_request.timeout_remaining_seconds` so long operations can be monitored without submitting more work. Main service state also keeps a bounded request history and slow-request history for the current service process:

```powershell
python wave3d.py debug show request-history
python wave3d.py debug show request-history --slow-only
python wave3d.py debug show request-history --min-seconds 5 --limit 10
```

For cache-side hangs or expensive cache RPCs, use `debug show cache-request-history` in the same way. It exposes each cache layer's `active_request`, `last_request`, recent history, and slow-request history from cache service state without touching the cache RPC queue:

```powershell
python wave3d.py debug show cache-request-history wave3
python wave3d.py debug show cache-request-history wave3 --slow-only --limit 10
```

`show cache-health` separates `active_inflight_request_count` from `queued_request_count`, so a single request currently being processed by `main.py` stays visible without turning health to `attention`. Fresh queued requests are reported in the queue counters without changing health status; warnings are reserved for long-waiting queued requests, old unclaimed results, stale artifacts, revision mismatches, or failed services.

If a command/test appears to hang, check service and cache status instead of piling on more requests:

```powershell
python wave3d.py show service-status
python wave3d.py show cache-status
python wave3d.py show cache-health
Get-ChildItem core\runtime\cache_rpc\wave3_cache\requests -File
```

Use `debug cleanup cache-rpc --dry-run` and `debug cleanup command-queue --dry-run` before deleting stale artifacts. Only use `--confirm` after confirming the owning client is stopped or the request is clearly abandoned.

## Change Notes

- `search code` now uses cache-backed search through `wave3_cache`, including class-scoped current file hits plus lower-layer Wave2/prewave code evidence, so it stays responsive without losing legacy decompilation search coverage.
- `filter method` now uses cache-backed method filtering for raw metrics such as `--callers-gt`, `--stubs`, and `--thunks`.
- `wave3.py --help`, `wave3.py help`, `wave3d.py --help`, and `wave3d.py help` now return local command inventory without starting or querying `main.py`.
- Missing-ref target and class queue rows now include `next_commands` for triage and reconstruction scaffolding.

- 2026-05-18: Added `--summary` mode for `show class`, `show method`, `show global`, and `show file` to make inspection faster and avoid huge default payloads during routine reverse-engineering work.
- 2026-05-18: Updated `show file --summary` to hydrate the targeted file runtime records from `wave3_cache`, so storage and simroot path fields are accurate after logic reloads.
- 2026-05-18: Optimized class attach/detach ownership moves to batch file-overlay edits; command usage is unchanged, but repeated class-owner test/setup flows should spend less time saving the same overlays.
- 2026-05-18: Fixed incremental `rebuild simulation`/simroot emission for default-owner files that contain file-level declarations such as includes, macros, aliases, enums, packing, or alignment metadata. These files now emit generated paths instead of being mistaken for empty ownerless placeholders.
- 2026-05-18: Fixed cache-backed `debug bootstrap` status so top-level catalog/count fields and materialization totals come from current `wave3_cache` summaries instead of stale persisted bootstrap metadata.
- 2026-05-18: Added `show project-status --summary` for bounded project health checks without dumping full storage/simroot/system payloads.
- 2026-05-18: Fixed `show xref` to resolve Wave3, Wave2, and prewave cache bundle references before returning caller/callee/xref/data-ref fields.
- 2026-05-18: Moved `search symbol` to a bounded `wave3_cache` search path. `search symbol MiniMap --limit 5` now returns prioritized class hits in under a second instead of scanning hydrated runtime catalogs from `main.py`.
- 2026-05-18: Added stale cache-RPC artifact reporting/cleanup. `show cache-health` now reports stale cache RPC result/request payloads, and `debug cleanup cache-rpc` can dry-run or delete abandoned artifacts.
- 2026-05-18: Fixed missing-ref issue/list filtering so reviewed `should_reconstruct: no` entries are not treated as actionable. Added `debug refresh project-issues` to rebuild the stored issue index after classification logic changes.
- 2026-05-18: Fixed project issue attachment so `issues`, `show <entity>`, `list accuracy-work`, and autograder issue tests agree on active project problems. Also fixed false namespace issues where imported method metadata used the owner class id as `namespace`.
- 2026-05-18: Fixed global-data regrade idempotency. Repeated `show grade` or `debug regrade` now uses a stable metadata baseline instead of subtracting penalties from the previous auto grade.
- 2026-05-18: Added `set global-data-type <addr_or_name> <type>` so missing global-data type issues can be fixed directly without recreating the item.
- 2026-05-18: Aligned global-data issue detection with grading: either `type_string` or `type` now counts as type evidence, avoiding false `global_data_issue` rows for typed imports.
- 2026-05-18: Tightened `show project-status --summary` so it returns bounded `catalog_counts`/status data instead of the full catalog-summary payload.
- 2026-05-18: Optimized `show grade file <filename>` to use a targeted v2 workflow index. A sample file-grade check dropped from about 40 seconds to about 2 seconds.
- 2026-05-18: Fixed `recompute memory-range ... --from-children` so disjoint child ranges are not collapsed into one large min/max range.
- 2026-05-18: Fixed memory range indexing so disabled/excluded entities no longer contribute active memory range conflicts, and added bounded `debug refresh memory-indexes [--rematerialize] [--file <filename>] [--offset <n>] [--limit <n>] [--batch-size <n>]` for rebuilding memory indexes after scanner changes.
- 2026-05-18: Clarified memory issue override reporting. `show memory-issue` now keeps generated scanner context when a manual overlay override changes `allowed` or `ignored`, avoiding contradictory active issue output.
- 2026-05-18: Added actionable `context` to `global_data_issue` rows so `issues --kind global_data_issue` reports type evidence, owner/source context, memory coverage, and repair commands without changing stable issue IDs.
- 2026-05-18: Added actionable `context` to `missing_ref_issue` rows so `issues --kind missing_ref_issue` reports projected reconstruction data, reference counts, notes, and the next triage commands.
- 2026-05-18: Added `next_commands` to cache-served work queues (`list ungraded`, `list accuracy-work`, and next/stub/new queues) so ungraded or incomplete items are directly actionable.
  - 2026-05-18: Updated summary `detail_commands` so user-facing regrade steps use `regrade grade`, development-only refresh/materialization steps include `python wave3d.py`, and class summaries include `list missing-ref-classes`.
- 2026-05-19: Added v2 `next_commands` and direct counts to memory navigation, method/decomp/diff navigation, file navigation, `issues`, and `show problem`. Fixed bootstrap-unresolved guidance for unknown overlay entities and suppressed tombstoned probe rows from active project issues.
- 2026-05-19: Fixed contamination matching so broad patterns do not match every file through `core\data\wave3` paths or `.meta_wave3` sidecars. Confirmed Wave3 probe cleanup now targets only actual Wave3 probe files/baselines.
- 2026-05-19: Added read-only `suggest global-data-type <addr_or_name> [--limit <n>]` and linked it from `global_data_issue` contexts so missing global-data types can be repaired from scored code/decomp/name evidence instead of guesswork.
- 2026-05-19: Fixed incremental missing-ref project-issue refreshes to preserve `context.next_commands`, and gave no-owner missing-ref rows virtual entity fields (`missing-ref-class`/`missing-ref-target`) without changing historical issue IDs.
- 2026-05-19: Added `suggest global-data-type` to global-data work-row `next_commands`, including stale-grade and accuracy queues, so missing-type repair is visible before regrade commands.
- 2026-05-19: Improved missing-ref class issue and queue scaffolds to parse the address embedded in ids such as `cls_0x560a10` and fill `create class --class-addr` automatically.
- 2026-05-19: Added read-only `suggest method-owner <addr_or_name> [--owners <owner1,owner2>]` and linked it from duplicate-ownership issue contexts so conflicting imported method owners can be reviewed from scored evidence before allowing/dismissing the issue.
- 2026-05-19: Added `set method-owner <addr_or_name> <class_name> [--dry-run]` for reviewed duplicate-owner repairs. It moves the method overlay to the target owner file, updates method owner fields and class method lists, refreshes affected output, and keeps issue review explicit.
- 2026-05-19: Added `review method-owner <issue_id> <class_name> [--dry-run] [--reason <text>]` to combine reviewed duplicate-owner repair and `allow problem ... reviewed` into one audited command after manual evidence review. Also tightened `suggest method-owner` owner-file evidence so base class names are not scored from derived filenames such as `class_UserListDialogPane.cpp`.
- 2026-05-19: Bounded normal repair refresh output for `set global-data-type` and changed `set method-owner` results so they summarize target files/regrade/cache-sync state instead of returning full storage/simroot documents.
- 2026-05-19: Added `review global-data-type <issue_id> <type> [--dry-run] [--reason <text>]` for reviewed global-data type repairs. Verified `g_isHighResMode` as `bool`, fixed its issue, and kept global-data `owner_files` as reference context rather than true materialization ownership to avoid huge false file refreshes.
- 2026-05-19: Fixed memory-range index rebuilding so tombstoned memory entities do not reappear from stale class children, class aggregate ranges inherit child range markers, memory-range mutation refresh output stays bounded, and `issues` now separates filtered `visible_summary` from the overall generated-issue summary.
- 2026-05-19: Added `set global-data-owner <addr_or_name> <filename> [--dry-run]` for global-data rows that have observed reference files but no true Wave3 owning file. Also improved `suggest global-data-type` to use boolean comparisons and `g_ptr = this` singleton assignment evidence while ignoring autogenerated comments as type evidence.
- 2026-05-19: Verified reviewed global-data repairs on live data: `g_pSpellInputPane -> SpellOneArgInputPane*`, `g_snowTypeThresholds -> unsigned char*`, `g_isTradeBlocked -> bool`, `g_pIdleWatcher -> IdleWatcher*` with owner `class_IdleWatcher.cpp`, and `g_pLightObjImageLib -> LightObjImageLib*` with owner `class_LightObjImageLib.cpp`. Also verified small real `regrade ungraded --kind file` and `regrade stale-grade --kind global-data` batches.
- 2026-05-19: Tightened `suggest global-data-type` static class-call evidence so non-receiver resource/value arguments such as `GrafPort::LoadScrollBitmap(grafManager, g_scrollBitmapResource, ...)` no longer produce unsafe `GrafPort*` suggestions, while first receiver-like arguments such as `SpellOneArgInputPane::FindPane(g_pSpellInputPane, 0)` still produce candidate evidence.
- 2026-05-19: Added conservative known-WinAPI function pointer evidence to `suggest global-data-type`. Direct assignments such as `g_pfnGetLocaleInfo = GetLocaleInfoW;`, casted assignments such as `dword_69BEC0 = (int)ImmGetCandidateListW;`, and known dispatch names such as `g_winApiCreateFileMapping` now produce explicit `WINAPI` function-pointer candidate types, while unknown function assignments remain non-candidate evidence until their prototype is added.
- 2026-05-19: Added `show global-data <id> --summary` so global-data repair checks can use the same bounded summary workflow as classes, methods, globals, and files. Verified `g_pfnGetLocaleInfo`, `g_pfnCreateFileMapping`, `g_winApiCreateFileMapping`, and `dword_69BEC0` type repairs and reduced active global-data issues to 1129.
- 2026-05-19: Improved `suggest global-data-type` diagnostics for object-pointer use. Member access such as `g_gameClock->GetCurrentTick()` now reports `member_access_shape` evidence instead of returning no evidence, but it does not invent a class type when the class cannot be proven.
- 2026-05-19: Added user-facing `issues --refresh` plus `issue_index` freshness metadata so stale stored project issue indexes are visible and can be rebuilt without using development commands. Issue summaries now include `severity_counts` and `message_counts`, and missing-ref untriaged target next commands point to `list missing-ref --include-unknown`.
- 2026-05-19: Added `show missing-ref <target|class> <identifier>` for focused missing-ref inspection. It returns the merged annotation entry, related active issue rows, and direct triage/reconstruction next commands.
- 2026-05-19: Added read-only `suggest global-data-owner <addr_or_name>` and linked it from ownership-only global-data issue contexts, so missing true owner files can be reviewed from scored file/method/class evidence before running `set global-data-owner`.
- 2026-05-19: Added `type_resolution` metadata to `suggest global-data-type` candidates so name-derived pointer suggestions distinguish known project types, external/primitive types, function pointers, and unresolved type names that need manual confirmation.
- 2026-05-19: Added auditable `review global-data-owner <issue_id> <filename>` plus `list global-data-issues` so global-data type/owner repair can be queued without reading the full `issues` payload. Queue type suggestions are lightweight and link to deep evidence commands for accuracy review.
- 2026-05-26: Added `attach method <addr_or_name> [<addr_or_name> ...] --to-file <filename> [--dry-run]` for reviewed file-level helper ownership. It repairs metadata and live C++ placement together, so scoped method bodies do not remain emitted in stale owner files after the owner is changed.
- 2026-05-19: Added missing-ref `reconstruction_safety` and `list missing-ref(-classes)` safety filters. Mixed legacy buckets such as `cls_0x427990` no longer expose direct `create class` scaffolds; use `--blocked`, `--ready`, `--needs-name`, and `--triage-required` to separate unsafe triage from ready reconstruction.
- 2026-05-19: Added `python wave3d.py debug refresh file <filename>` as the current development alias for refreshing one file's materialized storage/simroot output. The older `debug rebuild file` command remains compatible. This remains development-only and should not be advertised in normal `wave3.py` user-facing `next_commands`.
- 2026-05-19: Fixed `issues` latency after adding missing-ref safety metadata. The runtime now loads merged missing-ref annotations once per issue read instead of once per missing-ref row; `issues --limit 1` should return in a few seconds instead of around two minutes.
- 2026-05-19: Fixed `list accuracy-work` memory queue noise. Resolved, aggregate, and not-applicable memory coverage no longer make complete entities appear in the accuracy queue; unresolved coverable memory and explicit memory conflicts still surface as work reasons.
- 2026-05-19: Expanded `show progress` into a higher-level accuracy planning command. It now includes an active issue backlog summary plus `recommended_work` entries and direct commands for global-data, missing-ref, duplicate-owner, memory, stale-grade, ungraded, and below-threshold work.
- 2026-05-19: Normalized `list global-data-issues` row shape. Rows now expose `kind`, `entity_kind`, `id`, and `entity_id` aliases for generic queue tooling while keeping the existing `global_data` field.
- 2026-05-19: Improved `suggest global-data-type` object-pointer inference. Member access evidence such as `g_x->Method()` now proposes `Class*` only when `Method` uniquely maps to one known method owner class; ambiguous or currently unknown member names remain non-candidate evidence.
- 2026-05-19: Added peer-typed member-access inference to `suggest global-data-type`. When an untyped global calls `g_x->Method()` and all other typed globals using `Method` agree on one type, that type is returned as a candidate with peer evidence; conflicting peer types remain non-candidate evidence.
- 2026-05-19: Added top-level `next_commands` to missing-ref list responses so `list missing-ref` and `list missing-ref-classes` expose the safest follow-up filtered queues and focused `show missing-ref ...` inspections without reading individual rows first.
- 2026-05-19: Improved global-data accuracy queue guidance. Global-data work rows now include owner suggestions, and `list accuracy-work --kind global-data` links to type/owner issue queues before stale regrade commands when active global-data problems are present.
- 2026-05-19: Improved `filter method` triage ordering. Method filters now sort the full matching set before applying `--limit`, so incomplete/stale/ungraded methods are returned before already-complete high-grade methods, with lower grades and higher caller counts prioritized.
- 2026-05-19: Clarified `issues` summaries. Issue responses now include `total_count` plus active-only breakdowns (`active_issue_kind_counts`, `active_source_counts`, `active_severity_counts`, and `active_message_counts`) so allowed/dismissed/generated diagnostics do not look like actionable backlog counts.
- 2026-05-19: Expanded cache queue `next_commands` for methods and globals. `list next-method`, `list accuracy-work --kind method`, `filter method`, and related queues now include xref/decomp/diff and memory validation commands in addition to grading and checkout actions.
- 2026-05-19: Normalized `list accuracy-work` as a triage queue. Rows now include `work_reasons`, the response includes reason-count summaries, and top-level `next_commands` promote the first returned item actions instead of only repeating the list command.
- 2026-05-19: Added top-level `next_commands` and a compact summary to grade-backed work queues (`next-class`, `next-method`, `next-global`, `new-class`, `new-global`, and `stub`) so row actions are available without parsing every item first.
- 2026-05-19: Added `create class/method/global ... --dry-run` and changed missing-ref reconstruction scaffolds to show dry-run commands before mutating create commands. These create dispatchers now reject unknown options instead of silently folding typos into source evidence.
- 2026-05-19: Fixed kind-scoped `show progress` issue backlog filtering. Scoped progress now reports only issues relevant to that kind instead of always including the full project issue backlog.
- 2026-05-19: Added `next_commands` to `show project-status` output so health checks lead directly to progress, issue, accuracy-work, cache-health, and service-status follow-ups.
- 2026-05-19: Added a `list_missing_ref_classes` response alias for `list missing-ref-classes` while retaining the historical `list_missing_ref` key for compatibility.
- 2026-05-19: Flattened key `show missing-ref` reconstruction fields to the focused response top level and added a `related_issues` alias, so reconstruction safety and evidence metadata are available without unpacking the nested `entry`.
- 2026-05-19: Added missing-ref queue safety summaries. `list missing-ref` and `list missing-ref-classes` now report candidate, filtered, returned, and safety-status counts in a `summary` block.
- 2026-05-19: Added top-level suggestion aliases to `list global-data-issues --with-suggestions`. Rows now expose `suggestion`, `deep_suggestion_command`, or `owner_suggestion_command` without requiring callers to inspect nested suggestion payloads first.
- 2026-05-19: Promoted first-row repair actions into `list global-data-issues` response-level `next_commands`, including type/owner suggestion and review commands.
- 2026-05-19: Fixed incremental missing-ref issue refresh to use fresh Wave3 catalog id snapshots from `wave3_cache`, preventing resolved missing refs from being resurrected into stored project issues when missing-ref metadata changes.
- 2026-05-19: Added `next_commands` to class/method/global/global-data summary views. Summary inspection now exposes the same direct follow-up workflow as full entity views, including global-data owner suggestions.
- 2026-05-19: Normalized `list global-data-issues` queue metadata. The response now includes the standard `count` alias and a concise `summary` block in addition to `returned_count` and `total_count`.
- 2026-05-19: Added `next_commands` to `show grade` responses so scoring failures link directly back to the relevant show/decomp/xref/diff, regrade, memory validation, and checkout workflow.
- 2026-05-19: Optimized `show grade` for file-owned classes, methods, globals, and global-data rows. These now use targeted file-scoped v2 project indexes instead of the legacy full-runtime grade path, while falling back to the legacy path for ownerless/system entities.
- 2026-05-19: Further optimized `show grade global-data`. Global-data scoring now uses a single-entity metadata scope, avoiding unrelated file/class workflow graph construction during type and owner repair loops.
- 2026-05-19: Improved `search symbol` response metadata and navigation. Results now include row-level `next_commands`, `returned_count`, `minimum_total_count`, and `has_more`; `--include-fields` exposes the expensive field-catalog scan only when explicitly requested.
- 2026-05-19: Normalized `search code` response metadata. Bounded code search now reports `returned_count`, `minimum_total_count`, `has_more`, and top-level `next_commands` while preserving current Wave3-first/lower-cache fallback behavior.
- 2026-05-19: Improved current-file `search code` navigation. Symbol/entity text hits now attach entity-level commands to the file row and matching entity preview, so global-data, method, class, and global hits can jump directly into inspection, type/owner suggestion, grading, and checkout workflows.
- 2026-05-19: Fixed v2 runtime cache-revision tracking after Wave3 cache writes. Commands that persist system/overlay documents now update the consumed Wave3 `data_revision`, preventing false `show cache-health` revision mismatch reports after normal writes.
- 2026-05-19: Added issue-index row/summary mismatch self-healing. If stored summary counts claim active issues but the row list is missing them, `issues` and `list global-data-issues` refresh the issue index once instead of returning an empty or misleading queue.
- 2026-05-19: Normalized missing-ref queue and symbol-search response metadata. Missing-ref queues now expose standard top-level counts/items/summary/next commands, and `search symbol` now promotes row follow-up commands to top-level `next_commands`.
- 2026-05-19: Hardened v2 project-issue refreshes against partial catalog reads. Full refresh now builds the payload without the legacy direct-save helper and refuses to write an issue index when required cache catalog entries are unavailable.
- 2026-05-19: Fixed targeted stale-ref scans after commits/file refreshes so they update project issues with `scope_file_ids` instead of rebuilding the full issue index from a file-scoped project graph. This prevents global-data issue rows from disappearing after targeted operations.
- 2026-05-19: Added `list global-data-issues --deep-suggestions` for small evidence-backed type/owner repair batches. Also stored active issue breakdowns in the issue index so self-healed summary mismatches do not keep reappearing on normal `issues` reads.
- 2026-05-19: Tightened missing-ref repair guidance so untriaged targets keep recovered-name placeholders instead of using raw addresses as C++ names, and surfaced global-data deep suggestion queues from `show progress`.
- 2026-05-19: Added `show prewave-function <addr>` and attached prewave function evidence to `show missing-ref target <addr>` for lower-layer-only function triage.
- 2026-05-19: Extended `show xref` and `show decomp` to fall back to prewave functions for lower-only missing-ref targets.
- 2026-05-19: Extended `show missing-ref class ...` to attach prewave evidence for parsed class addresses, and kept standalone `show prewave-function` output free of missing-ref mutation commands.
- 2026-05-19: Extended `search symbol` with prewave lower-function metadata hits so class/function symbols visible only in prewave can be found from normal search.
- 2026-05-19: Added `show prewave-class <cls_...>` as a compact lower-only class/function cluster view for missing-ref class naming.
- 2026-05-19: Added `show prewave-class` follow-ups to prewave function and missing-ref evidence whenever a lower class candidate is present.
- 2026-05-19: Added read-only `suggest missing-ref <target|class> <identifier>` so lower prewave evidence is converted into a safe triage plan without promoting address-derived lower names as recovered C++ names.
- 2026-05-19: Tightened `show missing-ref target ...` next commands so class-backed lower evidence leads with `suggest missing-ref`/prewave inspection and does not present direct global-create scaffolds before owner triage.
- 2026-05-19: Fixed `list missing-ref --triage-required` so it includes `needs_target_triage` rows and promotes both `show missing-ref` and `suggest missing-ref` for returned rows.
- 2026-05-19: Fixed `show progress --kind missing-ref` so the synthetic missing-ref scope includes `missing-ref-class` and `missing-ref-target` issues plus the missing-ref queue recommendations.
- 2026-05-19: Improved `suggest missing-ref` for ready entries so it surfaces reviewed dry-run/create commands in `reviewed_create_commands` and recommended steps.
- 2026-05-19: Fixed `list global-data-issues` follow-up commands so scoped type/owner queues preserve `--needs-type` or `--needs-owner` when suggesting deep/with-suggestion views.
- 2026-05-19: Added `best`, `best_score`, `best_confidence`, and `manual_review_required` aliases to `suggest global-data-type` output and `list global-data-issues` type-suggestion rows; type suggestions now prefer reviewed dry-run commands before raw set commands when an issue exists.
- 2026-05-19: Added `best_confidence` and `manual_review_required` aliases to global-data owner suggestions, including `ambiguous` confidence for tied owner candidates.
- 2026-05-19: Added `--confidence` and `--scan-limit` to `list global-data-issues` so type/owner repair queues can be filtered by suggestion confidence without manually inspecting each row.
- 2026-05-19: Hardened developer service tooling. Main command requests now carry timeout metadata, the v2 command server expires abandoned requests and cleans stale command results, cache RPC queues prioritize lightweight health/manifest requests ahead of heavy queued work, and `wave3d.py` now exposes `debug cleanup command-queue`.
- 2026-05-19: Added a development-only background unittest runner: `debug run-tests`, `debug start-tests`, `debug show test-run`, and `debug stop test-run`. Use it for long suites so status/tail output can be polled without blocking or corrupting the main service queue.
- 2026-05-19: Added `debug cleanup test-runs` so old background test-run reports can be pruned explicitly while preserving the active/latest runs by default.
- 2026-05-19: Fixed generated-root path reporting to preserve logical `E:\NTK\GhidraBridge` paths instead of resolving Windows junctions to `C:\FastStorage` targets.
- 2026-05-19: Fixed main service state updates so processed commands preserve `active_generated_roots`, and extended `debug reload-logic` to reload `core.runtime.command_queue`.
- 2026-05-19: Scoped the legacy bootstrap bundle spec-regression test to v1 so the v2 test suite no longer stalls on the old bootstrap rebuild path.
- 2026-05-20: Hardened generated-root config and the development test runner. Relative generated-root config values now become logical absolute paths under `source-3`; invalid test-run timing arguments are rejected; `debug stop test-run` verifies both worker and unittest child exit; `debug start-tests` refuses to overlap a still-live stopped/stopping worker; and `debug cleanup test-runs --keep-last 0 --confirm` now correctly prunes terminal runs and clears the active pointer.
- 2026-05-20: Added automatic post-test cache revision repair for terminal `debug run-tests`/`debug show test-run` results, `debug self-audit [--detail]`, and `debug profile command [--include-result] [--health] -- <command...>`. Also moved generic v2 `list <kind>` id listing to `wave3_cache` and optimized exact `file_document`/`system_document` requested-block reads so they no longer build full document payloads just to return one block.
- 2026-05-20: Extended direct unittest safety and profiling. `core.tests` now refreshes main cache revisions at process exit after direct cache-mutating unittest runs, `show service-status` exposes active main request elapsed/remaining timing, v2 `show <kind>` no longer delegates to the v1 `show_kind` implementation, and `wave3_cache` can serve direct `catalog_entry` requested-block reads without constructing the full entity envelope.
- 2026-05-20: Moved v2 `list <kind>`, `resolve method`, `resolve global`, and `show diff` off legacy v1 runtime delegates. `wave3_cache` now exposes `find_catalog_matches` for exact id/name/qualified-name resolution without constructing a broad local runtime projection.
- 2026-05-20: Moved v2 memory-range read commands (`list memory-range`, `show memory-tree`, and `validate memory-range`) off legacy v1 delegates while preserving the actionable `next_commands` and issue-context output.
- 2026-05-20: Moved v2 memory-issue payload/list/show reporting off legacy v1 delegates. Overlayed ignored/allowed issue state is now merged through the v2 system-overlay document path before issue context and follow-up commands are generated.
- 2026-05-20: Removed the v1 `show_grade` fallback for ownerless/non-file entities. v2 now evaluates those through the runtime grade helper first, then falls back to a single-entity evaluation scope when no owner file exists.
- 2026-05-20: Moved `regrade-all` execution into the v2 runtime module while preserving the existing batch scheduling, progress-status updates, overlay persistence, and bounded materialized-view refresh behavior.
- 2026-05-20: Added `wave3_cache` field-filtered catalog lookup (`find_catalog_entries`) and moved v2 structural helper paths off local catalog projections for method existence checks, enum-value existence/lookup, file-scoped include/forward-declare lookup, macro deletion, and class-base list/remove operations.
- 2026-05-20: Extended the cache-field lookup route to delete-file ownership discovery and file-owned declaration/entity cleanup, so those paths no longer build broad workflow projections just to find owner-file matches. `validate integrity` now asks `wave3_cache` for a bounded integrity snapshot from cache-resident file/class/method/global catalogs plus the existing stale-ref payload instead of validating against a main-side full project-index projection or blocking the cache with a full stale-ref rescan.
- 2026-05-20: Hardened `debug profile command` timeout handling so a timed-out wrapped command returns structured queue/cache/current-request diagnostics instead of raising out of `wave3d.py`. `debug self-audit` now reports actionable report-path projection usage separately from mutation/infrastructure `self.project_index` access, and `show <kind>` refreshes the v2 catalog-entry cache instead of writing refreshed data back through a local project-index projection.
- 2026-05-20: Reduced false-positive health warnings while commands are actively running. `show cache-health` now treats the main service's current request as in-flight work instead of queued residue, exposes oldest request age, and only warns on queued/unclaimed main-command artifacts after they have waited long enough to indicate a real problem.
- 2026-05-20: Refined `debug self-audit` projection reporting. The actionable `broad_projection_reference_count` no longer includes the intentionally exposed full-workflow cache endpoint definitions; those are reported separately as `full_workflow_endpoint_reference_count`.
- 2026-05-20: Added bounded main-service request timing history. `debug show request-history [--slow-only] [--min-seconds <n>] [--limit <n>]` exposes recent command durations and slow-command history without submitting another main-service command.
- 2026-05-20: Refined `debug self-audit` v1 reporting. Compatibility import/inheritance markers are now reported as `v1_compatibility_reference_count`; actionable fallback/delegation markers remain in `v1_fallback_reference_count`.
- 2026-05-20: Added bounded cache-service request timing history. Cache services now persist recent and slow cache RPC summaries in their state files, `show cache-health` reports the history counts, and `debug show cache-request-history [<prewave|wave2|wave3>] [--slow-only] [--min-seconds <n>] [--limit <n>]` exposes the history locally without queuing work through `main.py` or cache RPC.
- 2026-05-20: Extended main command timing diagnostics. The v2 command queue records `queue_wait_seconds` in current/last request state and `debug profile command` now returns a `timing` block that separates client elapsed time, main-service execution duration, queue wait, and remaining client overhead.
- 2026-05-20: Fixed development help coverage for local `wave3d.py` diagnostics. `wave3d.py --help` now advertises cache health/status, cache memory, cache import/reimport, cache-RPC cleanup, and workflow-index profiling commands, while `wave3.py` rejects `show cache-health` as development-only.
- 2026-05-20: Added `debug show command-routing [--contains <text>] [--include-commands]`, a local `wave3d.py` command that classifies normal commands, development commands, and commands intercepted locally by `wave3d.py` before they can touch the main queue.
- 2026-05-20: Extended `debug profile command` diagnostics. Profile output now includes a `diagnostics` list and `next_commands` that explicitly identify queue-wait dominated runs, slow main-service execution, pending queue residue, and request-id mismatches.
- 2026-05-20: Added `debug show queue-status [--detail]`, a local queue snapshot that reads main/cache state files and RPC artifact directories without sending cache RPC probes. Use it before `show cache-health` when diagnosing suspected hangs.
- 2026-05-20: Added `debug smoke readonly [--case <name>] [--list-cases] [--include-result] [--stop-on-failure] [--slow-threshold <seconds>]`, a development smoke suite for representative read-only Wave3 workflows with per-command timings, configurable slow-case diagnostics, and queue-status before/after snapshots.
- 2026-05-20: Fixed v2 class/type lookup aliases so case variants and ownerless default-file aliases resolve through `wave3_cache` without changing canonical ids. Example: `show class _DatFileMgr --summary` and `show class class__DatFileMgr.cpp --summary` both resolve to `_DATFileMgr`.
- 2026-05-20: Expanded `debug smoke readonly` with core reverse-engineering inspection cases: code search, class alias summary, method summary, combined method inspection, method xref lookup, decompilation view, and current-vs-imported diff view. The suite now covers project status, progress, issues, key work queues, symbol/code search, class lookup, method lookup, combined method context, xref inspection, decomp inspection, and diff inspection.
- 2026-05-21: Added read-only `suggest method-signature <addr_or_name>` and included it in method follow-up commands plus the development smoke suite. It ranks only existing signature evidence from Wave3 metadata/current code/imported decompiler data and returns a reviewed `set method-signature ...` command when the best candidate differs from the current stored signature.
- 2026-05-21: Added real `--dry-run` support to `set method-signature` and `set method-flags`. Suggestion output now lists dry-run commands before real mutation commands so metadata fixes can be previewed instead of relying only on manual caution text.
- 2026-05-21: Added real `--dry-run` support to field metadata commands: `set field-type`, `set field-offset`, `set field-access`, and `set field-flags`. Dry-run output returns the exact `would_update` payload and skips persistence/refresh so class layout edits can be previewed before changing emitted declarations.
- 2026-05-21: Bounded generic `list <kind>` output by default. `list field` now returns the first page instead of dumping the full derived field catalog, `--offset`/`--limit` page through results, and `wave3_cache` slices sharded catalog order directly for large catalogs.
- 2026-05-21: Extended `debug smoke readonly` with bounded field listing and field metadata dry-run assertions so catalog pagination and non-mutating layout preview regressions are caught by the development smoke suite.
- 2026-05-21: Added user-facing `inspect field <field_id>|<class_name> <field_name> [--method-limit <n>] [--include-code]`. It gives class member reconstruction a bounded layout/evidence packet with owner/type/offset state, Wave2 original metadata, access search patterns, owner-class method context, optional code snippets, and dry-run repair commands.
- 2026-05-21: Added user-facing `inspect class-layout <name> [--field-limit <n>] [--offset <n>]`. It uses a cache-native owner-class field index to return bounded per-class field layout pages, type/access/offset attention counts, returned-page gaps, and direct field repair commands without scanning the full field catalog.
- 2026-05-21: Added read-only `suggest field-type <class_name> <field_name> [--method-limit <n>]`. It ranks candidate member types from field naming, size metadata, and bounded owner-method code evidence, and returns reviewed dry-run `set field-type ...` commands for class layout recovery.
- 2026-05-22: Hardened main command client cleanup. `wave3.py` requests now carry client/parent PID plus a cancellation marker, abandon their queued request on timeout/interruption/parent-shell death, and the v2 main queue skips dead-client work or suppresses unclaimed results when the client dies mid-command. `debug show queue-status` now exposes command cancellation marker counts.
- 2026-05-21: Added user-facing `inspect callgraph <addr_or_name> [--depth <n>] [--direction <callers|callees|both>] [--limit <n>]`. It builds a bounded caller/callee neighborhood from existing `show xref` resolution, including lower-only prewave xref fallbacks, so rewrite work can inspect nearby control flow without manually chaining xref commands.
- 2026-05-21: Fixed `list memory-unresolved` so it surfaces catalog-visible coverable entities with unresolved memory coverage, not only pre-generated memory issue rows. This keeps the unresolved queue consistent with `show project-status --summary` memory coverage diagnostics.
- 2026-05-22: Added source-line provenance maps and commands: `inspect source-map`, `list source-lines`, `show source-line`, `set source-line-range`, and `clear source-line-range`. Source-line coverage now participates in grading through `source_line_provenance_present`, exact duplicate ranges surface through `list memory-duplicate`, and `list memory-libraries` combines manual Wave3 range classifications with lower prewave library-function evidence.
- 2026-05-22: Added top-level executable memory-image coverage commands: `show memory-coverage`, `inspect memory-image`, `list memory-segment`, `list memory-gap-global`, `classify memory-segment`, and reversible `clear memory-segment-classification` / `unclassify memory-segment`. Image-tier classifications now distinguish reconstruction bytes from CRT/library/compiler/resource/import/padding/gap ranges before entity/source-line coverage rolls up, and uncovered reconstruction image gaps surface as `memory_image_issue` rows in `issues`.
- 2026-05-22: Source-line provenance now prefers final simroot source maps when available. Simroot emission writes a `.source_map.json` sidecar for emitted `.cpp` files after headers/penalty comments/simpath handling are applied, `wave3_cache` serves that map for source-line block reads, and manual source-line range edits trigger targeted materialization/regrade so grading uses current emitted-line provenance.
- 2026-05-22: `inspect problem` now understands `memory_image_issue` rows as exact image-gap work packets. The packet reports gap metadata, probes `show memory-at` for the first byte, and lists the direct add-coverage or classify-external commands needed to resolve the image-tier coverage issue.
- 2026-05-22: Hardened `wave3_cache` startup refresh for derived memory-image coverage. Startup refresh now rebuilds `memory_image_map` from `memory_range_index` through the derived-document path instead of importing a stale generated file directly, and live default refreshes refuse to overwrite image coverage from a tiny/incomplete in-memory range stub when the real range index is present on disk.
- 2026-05-22: Added `list prewave-function --range <start> <end> [--limit <n>] [--offset <n>] [--exclude-external]` and integrated it into memory-image gap inspection. Large uncovered image gaps can now be decomposed into bounded lower prewave functions with address/size/library evidence before deciding whether to reconstruct or classify the bytes.
- 2026-05-22: Optimized lower CRT/library discovery. `prewave_cache` now builds a resident library-function index during eager startup and `list memory-libraries` uses that index through `wave3_cache`; live profiling for `list memory-libraries --limit 5` dropped from about 42 seconds to about 2.8 seconds client time.
- 2026-05-22: Optimized `search symbol` current-catalog scanning. `wave3_cache` now warms a resident lightweight symbol index for normal non-field symbol search and still falls through to prewave lower evidence when current Wave3 results do not fill the requested page; live profiling for `search symbol GetCurrentTick --limit 25` dropped from about 40 seconds in `wave3_cache` to about 1.6 seconds service time.
- 2026-05-23: Compact `.meta_wave3` sidecars now omit entity history/change code snapshots and write summaries instead. Targeted workflow-index refreshes avoid broad method scans, avoid rehydrating scoped entries one by one, cap pathological synthetic field expansion, and `debug profile workflow-index` returns timing/count summaries instead of the full workflow payload. Lower-only address lookups now fail fast to prewave and layer-aware bundle resolution avoids wrong-cache probes. `inspect class` batches method catalog lookups through `wave3_cache`.
- 2026-05-23: `set global-data-type` now supports real `--dry-run` previews instead of treating `--dry-run` as part of the type string. `recompute memory-range ... --from-children` now uses live targeted child ranges, updates cache-backed range overlays used by grading/workflow views, skips duplicate project-issue refresh work, and returns a fast no-op result when the normalized range fields are unchanged.
- 2026-05-23: `wave3_cache.find_catalog_entries` now uses lightweight resident/project-index catalog entries for field filters instead of hydrating every entry through `get_catalog_entry`; the reproduced `list memory-unresolved --entity-kind class --limit 25` path now profiles around 4.6 service seconds. Simroot emission also normalizes split `NTK_ScopedInstall` marker comments and suffixes repeated file-local helper definitions by method address so generated files like `class_TextEditPane.cpp` and `class_ScrollWidget.cpp` remain machine-readable and compile-safe.
- 2026-05-24: Cleared the verified `wave3_noticed_problems.md` backlog. `list accuracy-work` now uses compact issue counts and cache-local memoization instead of full problem-link expansion, high-method-count `inspect class` calls batch method summaries without problem links, and `mark/unmark memory-range` now persist marker metadata through a fast path that keeps the runtime's local range overlay coherent.
- 2026-05-20: Tightened `debug smoke readonly` with expected-output assertions for key cases. Smoke now fails if canonical lookup IDs, expected search hit counts, xref counts, or decomp/diff payload keys regress even when the command exits successfully.
- 2026-05-20: Added user-facing `inspect method <addr_or_name> [--include-code] [--include-diffs] [--include-grade-details]`. It bundles method identity, owner, stored grade, xref summary, code/decompiler summaries, diff summaries, and follow-up commands so a method can be reviewed for rewrite accuracy without manually chaining five separate commands first. Use `--include-grade-details` when you need live failing-test reasons inline.
- 2026-05-20: Added user-facing `inspect class <name> [--method-limit <n>] [--include-issues] [--include-grade-details]`. It bundles class identity, owner/default-file state, entry or live grade summary, memory ranges, a bounded method work sample, optional missing-ref/issue context, and follow-up commands so class reconstruction does not require manually chaining class summary, next-method, grade, missing-ref, and file commands.
- 2026-05-20: Added user-facing `inspect global <addr_or_name> [--include-code] [--include-diffs] [--include-grade-details]`. It gives standalone global functions the same bounded reverse-engineering packet as methods, including owner file, grade summary, xrefs, code/decompiler summaries, diff summary, memory status, optional full payloads, and direct follow-up commands.
- 2026-05-24: Added `set global-signature <addr_or_name> <signature> [--dry-run]` for standalone global functions. It mirrors method-signature repair by previewing metadata updates, rewriting the function header when possible, and refreshing the owning file after apply.
- 2026-05-24: Added `set global-owner <addr_or_name> <filename> [--dry-run]` so standalone helpers can be moved between emitted files without deleting/recreating the global.
- 2026-05-24: Improved `suggest global-data-owner` so singleton assignment evidence like `g_pFoo = this;` produces the matching `class_Foo.cpp` owner candidate. This keeps owner repair discoverable for globals whose `owner_files` provenance was still empty.
- 2026-05-24: Simroot export now removes duplicate marker-only `// global-data <name>` rows per emitted file and normalizes generated `//` comment punctuation/mojibake to ASCII without touching C++ string literals.
- 2026-05-24: `issues --kind global_data_issue` and `list global-data-issues` now self-heal a stale project-issue index when the cache catalog still contains active global-data type/owner work. Targeted file refreshes also carry `attached_global_data` entries and infer scoped project-issue merges from targeted workflow indexes so they do not silently drop the global-data issue slice.
- 2026-05-24: Project issue refresh now imports `global-data` rows from file-storage source-map metadata as well as the catalog. This surfaces globals that exist only in generated file sidecars, such as `g_pScreenEffecterList`, in `issues --kind global_data_issue` and `inspect global-data` instead of leaving their stored grade failures unlinked.
- 2026-05-25: `show memory-at <addr> --include-ignored --include-allowed` now includes lower prewave function evidence when no Wave3 memory range covers the address, so lower-only helper starts link directly to `show prewave-function`, `show xref`, `show decomp`, and add/classify memory-range follow-ups.
- 2026-05-25: Bounded default `issues --limit N` reads no longer run the broad global-data catalog self-heal probe. Use `issues --kind global_data_issue`, `issues --entity-kind global-data`, `list global-data-issues`, `issues --refresh`, or `--include-diagnostics` when you intentionally need focused global-data repair or fresh diagnostics.
- 2026-05-25: Fixed global-data memory coverage accounting. `show memory-coverage` now treats `global-data` as a primary coverable memory kind and counts all 1,205 catalog-visible rows; `list memory-unresolved --entity-kind global-data` applies current file range overlays before filtering, so the unresolved queue matches the coverage summary instead of listing already covered data symbols.
- 2026-05-25: Fixed class/file aggregate recompute to skip disabled or excluded child entities. `recompute memory-range class <name> --from-children` no longer preserves aggregate coverage for child ranges that are intentionally excluded from active ownership.
- 2026-05-25: Fixed `add memory-range` option parsing so `--notes <text> --dry-run` keeps `--dry-run` as an option instead of appending it to the stored note.
- 2026-05-25: Fixed real `add memory-range` output so the returned refresh block is the bounded mutation summary used by other memory-range commands, not a full storage/simroot payload dump.
- 2026-05-25: Fixed coverage-changing memory-range mutations so `add memory-range` and `delete memory-range` rebuild and sync `memory_range_index`, `memory_issue_payload`, and `memory_image_map` immediately. `validate memory-range` and `show memory-at` now reflect the mutation without a separate `debug refresh memory-indexes`.
- 2026-05-25: Added and hardened `set global-data-storage <id> --type <type> --owner <file> --range <start> <end>` for reviewed global-data repairs where type, true owner, and exact storage range are known together. Dry-run now reports overlapping owners in `blocked_by_existing_ranges`, and the real command refuses unsafe duplicate coverage.
- 2026-05-25: Source maps now emit `global_data_reference` rows for reviewed global-data symbols used inside method/global bodies. This lets global-data grades pass line provenance when the storage is covered by assignment/reference lines but no separate declaration line is present in the emitted file.
- 2026-05-25: Hardened `rename global-data` against unsafe alias collisions. Dry-run now reports `blocked: true` plus `target_conflict` when the target name already resolves to a different global-data entity, and the real command raises instead of creating duplicate-name overlay state.
- 2026-05-25: Capped deep `list global-data-issues --deep-suggestions --confidence ...` scans to one probe per call so broad requested scan limits cannot monopolize the main command queue for several minutes. Non-confidence deep pages remain capped to three rows. Responses now report `deep_suggestion_scan_cap`, cap diagnostics, and time-budget diagnostics when applicable.
- 2026-05-25: Fixed `wave3_cache` global-data resolution so missing alias names use direct/symbol/overlay lookup and then fail fast. A query such as `show global-data g_activeMapPane --summary` now returns `Unknown global-data` instead of scanning every global-data catalog entry and blocking the cache.
- 2026-05-25: Fixed memory-range aggregate recompute to preserve single-address child ranges such as `0x004cfa00-0x004cfa00`. Recompute plus `debug refresh memory-indexes` now clears false `memory_gap` rows for valid one-byte ranges.
- 2026-05-20: Added user-facing `inspect global-data <addr_or_name> [--include-suggestions] [--include-grade-details]`. It bundles global-data type/owner state, owner provenance, memory coverage, stored or live grade summary, active global-data issue rows, optional type/owner suggestion summaries, and direct repair commands for data-symbol accuracy work.
- 2026-05-20: Added user-facing `inspect file <filename> [--entity-limit <n>] [--include-all-owned] [--include-issues] [--include-grade-details]`. It gives emitted source files a bounded reconstruction packet with storage/simroot materialization state, attached class/global samples, file-owned global-data by default, optional full auxiliary-owned entity scans, grade summary, optional issue rows, and direct repair/edit commands.
- 2026-05-21: Added user-facing `inspect missing-ref <target|class> <identifier> [--include-lower-evidence] [--include-raw]`. It combines missing-reference reconstruction safety, compact lower prewave evidence, candidate owner/name signals, related issue rows, recommended review steps, and direct create/triage commands into one bounded packet.
- 2026-05-21: Added user-facing `inspect memory-range <entity_kind> <id> [--range-limit <n>] [--include-tree] [--include-validation-details]`. It combines entity memory range samples, child/conflict counts, validation issue summaries, optional full tree/details, and direct recompute/review commands for memory coverage accuracy work.
- 2026-05-26: Reduced v2 client/status overhead. `core.runtime` now lazy-loads heavyweight runtime exports so normal `wave3.py` commands do not import the full runtime just to enqueue a request, main service state now stores a compact bootstrap summary instead of embedding full catalog/project-summary payloads, and `show cache-health` probes cache layers in parallel with a safe sequential fallback during interpreter shutdown.
- 2026-05-26: Reduced slow read-path refreshes. Normal overlay and rename reads use resident `wave3_cache` documents instead of refreshing `system_overlay_document` from source during ordinary commands, generic `issues --limit N` no longer self-refreshes the full project issue index unless a focused kind/entity probe asks for it, `list memory-unresolved --entity-kind ...` avoids the full catalog coverage rollup before the targeted catalog query, and `show memory-coverage` defaults to the fast summary while `--include-catalog` requests the full catalog-visible rollup. Live profiling after restart: `issues --limit 5` around 0.58s service time, `list memory-unresolved --entity-kind class --limit 5` around 0.43s, and `show memory-coverage` around 0.31s.
- 2026-05-26: Tightened v2 performance defaults and queue behavior. `show project-status` now returns the bounded summary payload by default in v2, while `show project-status --full` preserves the old full storage/simroot/memory/problem dump for explicit audits. Main/cache transient result files are written compactly to reduce service-lock time for large responses, `ensure_service()` validates v2 cache services before taking the main-ready shortcut, `inspect field` uses a cache-native field inspection packet, and deep global-data issue queues cap expensive suggestion probes so routine profiling stays below the 3 second threshold.
- 2026-05-26: Reduced remaining v2 read-path fanout. `wave3_cache` now serves file-owned auxiliary entities for `inspect file --include-all-owned` in one batched request, and nested file-inspection samples use preloaded/lightweight catalog entries instead of resolving each sample with full project-problem links. Deep global-data type suggestions are cached by Wave3 cache revision, and `list global-data-issues --deep-suggestions` uses a quick first-pass evidence mode for queue responsiveness while direct `suggest global-data-type` remains the full evidence command.
- 2026-05-26: Split `suggest global-data-type` into normal indexed and explicit exhaustive modes. The default direct command now uses cache-native global-data type context and peer-member type context packets, including lightweight current-line searches and cache-side type-resolution hints, while `--exhaustive` adds owner-method decompilation evidence for slower manual audits. The readonly smoke suite passes with no cases over the 3 second priority threshold after these changes.
- 2026-05-26: Moved `issues --refresh` to a cache-native source-digest path. After a real source/cache revision change, the first refresh still rebuilds the issue document, but repeated unchanged refreshes reuse the stored `refresh_source_digest` and return in the normal bounded-command budget.
- 2026-05-26: Optimized `inspect file --include-grade-details` and `inspect class --include-grade-details` to return stored autograder failure details with grade-freshness metadata instead of forcing a live grade recomputation. Use `show grade ...` for exact live scoring and `regrade grade ...` to persist a fresh score.
- 2026-05-26: Optimized external embed refresh and reload behavior. `debug reload-logic` now reloads `core.external_embeds`, and unchanged `refresh embeds` reports `changed=false`, skips `simroot_index`/Wave3-cache sync, and returns a bounded no-op result while still scanning the configured `third_party_embeds` source root for real changes.
- 2026-05-26: Optimized method metadata suggestions and memory-range validation. `suggest method-flags` and `suggest method-signature` now prefer the cache-native code-entity inspection packet before falling back to lower raw owner-class import data, and `validate/inspect memory-range` reads effective range records directly instead of hydrating full `show_kind()` raw import/file-owner views.
- 2026-05-26: Hardened v2 mutation freshness and slow-command diagnostics. Cache write/refresh helpers now return Wave3 `data_revision` values so the runtime consumes the current revision after successful writes, entity/file override writes update the in-memory catalog cache immediately, and mutation refresh summaries expose phase-level `timing_seconds` for materialization/autograde diagnosis.
- 2026-05-26: Fixed v2 `recompute memory-range ... --from-children` so recomputing class/file aggregate coverage no longer drops reviewed non-aggregate rows such as vtables and raw helper ranges.
- 2026-05-26: Added real `--dry-run` support for `set file-simpath` and `set global-file-simpath` so command flags cannot be accidentally stored as simroot path text.
- 2026-05-26: Fixed class/method owner moves so cache-backed memory-range overlays move with the entity, then refresh the memory index so `show memory-at` reports the new owner file. Repeating an already-applied `attach class`, `rename file`, or `set file-simpath` now returns a fast no-op instead of re-materializing the file.
- 2026-05-26: Optimized `merge global-data` for alias cleanup. If the source already resolves to the target, it returns a fast no-op; when a merge only tombstones an address alias with no source ranges or code-reference rewrites, it skips redundant file rematerialization and full memory-index rebuild.
- 2026-05-26: Compact method-code mutation output. `set method-code` and `replace method-code-text` now return bounded refresh summaries instead of full raw materialization payloads, while still reporting scoped refresh counts and phase timings.
- 2026-05-26: Compact create/rename mutation output. `create method`, `create global`, and shared rename paths now return bounded refresh summaries instead of dumping full file-storage/simroot indexes after targeted repairs.
- 2026-05-26: Fixed manual create follow-through. `create global-data` now also returns a bounded refresh summary, `create global --file <filename>` attaches the new global to the owner file immediately, and high-method-count class inspection merges current file-overlay grade fields so newly created/regraded methods show current scores in the method list.
- 2026-05-26: Fixed reload/test freshness and omitted-body false positives. `debug reload-logic` refreshes consumed cache revision markers after rebinding runtime views, and simroot omitted-body detection now recognizes multiline C++ method signatures with local helper declarations before the body.
- 2026-05-26: Compact metadata mutation output. `set summary`, `set notes`, and `set grade` now return bounded refresh summaries instead of full materialized file payloads.
- 2026-05-26: Fixed class memory-range child recompute/storage handling for moved or newly created Wave3 methods. BlackHole/List destructor repair verified that stale class child rows can create false gap/overflow issues until memory indexes are refreshed.
- 2026-05-26: Compact file-deletion output. `delete file` now returns the same bounded refresh summary shape as other v2 mutations instead of dumping the full materialized storage payload after cleanup.
- 2026-05-26: Moved full `list stale-ref --refresh` scans into `wave3_cache`. The cache builds the stale-ref scan from resident current method/global entries, persists the raw stale-ref payload, and stores an input digest so repeated unchanged refreshes reuse the previous result. This avoids main-side full catalog paging and keeps repeated stale-ref refreshes in the bounded-command budget.
- 2026-05-27: Fixed normal memory-index freshness for no-op and metadata-only range writes. If a live entity record is already current but the derived `memory_range_index` or `memory_issue_payload` is stale, the normal command path now performs a targeted entity refresh; users should not need `wave3d.py debug refresh memory-indexes` after ordinary range edits or recomputes.
- 2026-05-27: Fixed `mark memory-range` and `unmark memory-range` so metadata-only marker edits immediately sync cache-backed memory validation documents. `validate memory-range` and `show memory-at` now reflect marker changes without a separate development refresh.
- 2026-05-27: Tightened `set method-owner` for data repair work. Owner moves now regrade only the moved method plus affected class/file records instead of every entity in both touched files, and the post-move memory refresh is targeted to the moved method rather than running a full global memory-index refresh.
- 2026-05-27: `set class-vtable-family` refresh summaries now include memory validation document syncs when vtable range rows are added or updated, so the returned `wave3_cache_sync.documents` reflects both file/simroot and memory-index updates.
- 2026-05-27: Optimized `set class-vtable-family` after reviewed table repairs. The command now reuses the scoped range refresh returned by the range writer instead of launching a second full memory-index rebuild, and PowerShell comma-separated `--slots` values are normalized back to real addresses when the shell pre-parses `0x...` tokens as integers.
- 2026-05-27: Hardened file regrading against stale generated annotations and stale file projections. Grading strips inline Wave3 autograder penalty comments before scoring, overlays target file `current_code` from current file storage before file-scope grading, and targeted file indexes include the cache symbol index so cross-file class/method existence checks do not report false missing owners.
- 2026-05-26: Hardened integrity repair and renamed-class lookup. `repair all` now recreates missing active-checkout workdir artifacts from Wave3 storage instead of leaving checkout manifests broken, and `validate integrity` reports `error_count`/`warning_count` with `ok=true` when only warning-severity findings such as undismissed stale refs remain. Cache-side integrity validation now uses resident file documents for metadata checks and lazy-loads derived baselines only when an issue needs class context, keeping steady-state validation in the normal command budget. Owner-qualified method lookups after a class rename now resolve through the renamed owner class and its method list instead of falling into a broad method-catalog scan.
- 2026-05-26: Hardened delete command parsing and malformed cache lookup handling. `delete file|namespace|struct|union|enum|alias|class|method|global|global-data ...` now rejects unsupported flags such as `--dry-run` instead of folding them into the target identifier, and `wave3_cache` fails fast on malformed catalog queries containing option tokens before any broad catalog scan can run.
- 2026-05-26: Fixed delete-memory freshness for code/data entities. `delete class|method|global|global-data ...` now rebuilds and syncs `memory_range_index`, `memory_issue_payload`, and `memory_image_map` after the entity tombstone is applied, so `show memory-at` and memory issue queues no longer report deleted methods or stale class aggregate ranges until a manual debug refresh is run.
- 2026-05-26: Added real `delete memory-range ... --dry-run` support and argument validation. The command now previews the exact range deletion without persisting or refreshing, and rejects trailing unsupported arguments instead of ignoring them.
- 2026-05-26: Surfaced image-tier memory classifications in normal inspection reads. `wave3_cache` now serves address-scoped memory-segment matches, `show memory-at` reports classified image segments alongside lower prewave evidence, `list prewave-function --range` decorates lower rows with covering Wave3 segment classification/library/build-reference metadata, and `list memory-libraries --assigned-only` includes image-tier `classify memory-segment` library assignments instead of only entity-level memory ranges.
- 2026-05-26: Fixed cache-side alias resolution after merges. `wave3_cache` now excludes deleted/tombstoned overlay entities from fast overlay and symbol-resolution paths, so merged global-data aliases such as `g_pStaticObjectManager` resolve to the canonical `g_pStaticObjImageLib` row instead of producing false ambiguity.
- 2026-05-26: Repaired `StaticObjImageLib` data coverage. Active output now emits `RenderStaticObject`, maps the `0x0061b704` vtable, ordinary destructor `0x004dd1e0-0x004dd2bd`, singleton clear helper `0x004e5c00-0x004e5c0b`, normalizes `dword_69B448`/`0x0069b448`/`g_pStaticObjectManager` to `g_pStaticObjImageLib`, and uses `layerCount`/`tileIds` terminology for the `SOBJ.TBL` render record instead of `nameLength`/wide-name wording.
- 2026-05-26: Fixed and optimized targeted regrade. File-owned class/method/global regrades now use the same targeted workflow project index as `show grade`, avoiding stale broad-runtime grading differences, and persist grade fields through a cache-native file-entity override endpoint. Repeating an unchanged `regrade grade method 0x004dcf60` now reports `grade_result_unchanged` and measured about 1.6s end-to-end instead of rematerializing the file; changed scores still refresh the owning file and include phase-level refresh timings.
- 2026-05-27: Fixed simroot source-map fallback boundaries for annotated adjacent methods and generated metadata comments. When autograder inline comments prevent exact current-code matching, marker-based source-line mapping now stops at the next Wave3 entity score header instead of attributing the next method's score/category comments to the previous method; global-data reference scanning also ignores `// Wave3 ...` score headers so generated diagnostics are not counted as source provenance.
- 2026-05-27: Optimized `set global-data-storage ... --dry-run` overlap checking. The preview now checks numeric range overlap before resolving possible global-data aliases, avoiding broad per-range catalog resolution when thousands of unrelated global-data ranges exist.
- 2026-05-27: Fixed normal memory-range no-op freshness. If `recompute memory-range ... --from-children` finds the entity's range overlay unchanged but the cache-backed `memory_range_index` or `memory_issue_payload` still has stale rows for that entity/window, the normal `wave3.py` command now incrementally resyncs the memory index instead of requiring `python wave3d.py debug refresh memory-indexes`.
- 2026-05-27: Fixed create-command text option parsing. `create method` and `create global` now stop `--signature`, `--source-evidence`, `--integration-source`, and related text options at any following known flag, so metadata no longer depends on putting text-valued options last.
- 2026-05-27: Fixed `create method` memory coverage seeding. When the created method address matches a prewave function, Wave3 stores that function extent as the method memory range and refreshes cache-backed memory validation documents during the normal command path.
- 2026-05-27: Fixed file-owned method body installation. `create method` and `set method-code` now splice reviewed scoped sections into the owning editable `live.cpp` file, so generated simroot does not keep stale `WAVE3 OMITTED METHOD BODY` markers after valid current code exists. `inspect method --include-code` also reads file-entity overlay current code before stale source-map extraction.
- 2026-05-27: Replaced full memory-index delete refreshes with targeted deleted-entity syncs for `delete class|method|global|global-data`. Normal deletes now remove tombstoned entities from `memory_range_index`, `memory_issue_payload`, and `memory_image_map` without a full global memory-index rebuild.
- 2026-05-27: Fixed code-issue grading false positives for multiline function definitions and local helper definitions. Method/global code no longer gets missing-call penalties for its own definition or same-snippet helper definitions such as `GetRectBoundsLayout`.
- 2026-05-27: Hardened normal memory-range validation reads against stale cache-backed issue rows. `list memory-range`, `show memory-tree`, and `validate memory-range` now compare the live entity range record with the current `memory_range_index`/`memory_issue_payload` and perform a targeted sync when needed, so stale conflict rows are repaired by normal `wave3.py` reads instead of requiring `wave3d.py debug refresh memory-indexes`.
- 2026-05-27: Fixed `create global` memory coverage seeding to match `create method`. When the created global function address matches a prewave function, Wave3 stores that function extent, syncs `memory_range_index`, `memory_issue_payload`, and `memory_image_map`, and reports `memory_range_seeded` in the normal command result.
- 2026-05-27: Fixed stale generated memory issue cleanup for normal operation. Memory-affecting metadata updates such as `disabled`/`excluded` now sync validation documents during the normal command path, `create global-data` and unresolved `create global` records enter the memory index immediately, and normal issue reads prune stale conflict rows whose referenced ranges no longer exist.
- 2026-05-27: Removed development-only `wave3d.py debug refresh file` suggestions from normal `show file --summary` and file inspection `next_commands`. Normal file/entity changes are expected to refresh materialized views through `wave3.py`; development refresh commands remain documented only in the cache/debug section.
- 2026-05-27: Fixed global-data owner/storage metadata freshness. `set global-data-owner` and duplicate-range `set global-data-storage` now force targeted `memory_range_index`, `memory_issue_payload`, and `memory_image_map` syncs through normal `wave3.py` command handling, so stale validation rows are not left behind until a development refresh.
