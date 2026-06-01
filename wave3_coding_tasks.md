# Wave3 Coding Tasks Handoff

Last updated: 2026-05-23

This document is the current coding handoff for Wave3 tool development. Work was briefly resumed to fix the noticed timeout/client-cleanup issue while the other agent was paused. Do not start heavy imports, broad regrades, broad materialization, or long profiling runs while another agent is actively using the tool.

## Current Functional State

Wave3 was left in a functional v2 state after the latest cache/runtime changes and the client-cleanup follow-up fix.

Latest 2026-05-23 tool-fix pass:

- Fixed compact `.meta_wave3` sidecar export. Entity `history`, `changes`, active/disabled C++ bodies, and historical code snapshots are omitted from simroot `.meta_wave3` sidecars and replaced with compact summaries.
- Regenerated `simroot_v2\class_FontImageLib.meta_wave3`; size dropped from about `869 MB` to about `8.3 MB` and JSON parsing succeeds immediately.
- Fixed targeted workflow-index construction so file refreshes do not scan all non-sharded methods, do not rehydrate already-scoped entries one by one, and do not expand pathological field owner-file sets. `debug profile workflow-index class_FontImageLib.cpp` now reports about `3.1` seconds cache-side build time and returns only summary/profile data.
- Fixed lower-only address lookup performance. `resolve_catalog_entry(method|global, 0x...)` now fails fast on exact current-catalog misses so runtime can fall back to prewave instead of scanning all current methods/globals.
- Added layer-aware/cached bundle reference resolution in the v2 runtime so prewave decomp/xref views do not repeatedly probe unrelated cache layers.
- Fixed class-scoped `list next-method` to use class method ids and scoped metadata instead of the broad gradable-entry path.
- Added cache-side `get_catalog_entries` and routed `inspect class` method samples through one batch RPC.
- Final health check after retests: `python wave3d.py debug show queue-status` returned `status: ok`, with no active main request, no active cache request, and no queue issues.

Latest 2026-05-23 noticed-problems follow-up:

- Fixed `set global-data-type` command safety. It now supports `--dry-run` in both v1-compatible and v2 runtime entrypoints, and the dispatcher strips the flag instead of appending it to the C++ type string.
- Added focused dispatcher regression coverage for `set global-data-type ... --dry-run`.
- Corrected the transient bad `g_pFontImageLib` type created during investigation; the live item is now `FontImageLib*`, not `FontImageLib*--dry-run`.
- Set true Wave3 owner for `g_pFontImageLib` to `class_FontImageLib.cpp`; its global-data type/owner issue is resolved and the generated class file now declares `FontImageLib* g_pFontImageLib;`.
- Fixed `recompute memory-range ... --from-children` to derive child ranges from the live targeted workflow index and apply range overlays to cache-backed workflow/grade views.
- Optimized range mutation refresh to avoid duplicate project-problem refreshes, delegate memory system-document refresh to `wave3_cache`, and short-circuit unchanged normalized range edits with `noop: true`.
- Verified `FontImageLib` active output now contains all six methods, has no disabled companion file, reports six class ranges/six child ranges, and passes class memory/source-line provenance grading.
- Remaining content/data issue: two generated UI call sites still use `g_pDirectX` for font helper calls. Treat that as reconstruction work unless a later tool feature can safely rewrite call-site receiver globals from provenance.

Verification from this follow-up:

```powershell
python -m py_compile core\commands\dispatcher_impl.py core\runtime\in_memory_state_impl.py core\runtime\in_memory_state_impl_v2.py core\cache\wave3_state_v2.py
python -m unittest -v core.tests.test_project_problems.ProjectProblemCommandRoutingTest.test_dispatcher_routes_set_global_data_type
python wave3d.py debug reload-logic
python wave3.py set global-data-type g_pFontImageLib "FontImageLib*" --dry-run
python wave3.py show global-data g_pFontImageLib --summary
python wave3.py show grade class FontImageLib
python wave3.py list memory-range class FontImageLib
```

Notes for future agents:

- Do not run normal mutating Wave3 commands in parallel. The main service serializes them, and parallel shells distort timing while increasing cancellation-marker noise.
- Use `wave3d.py debug profile command --include-result --health -- <command...>` for timing investigations instead of guessing where a command is slow.
- For range recompute performance, distinguish an actual changed update from a repeated no-op. Repeated unchanged `FontImageLib` recompute is now about `8.6` service seconds; a changed update was still roughly `58` seconds and should be optimized later if it blocks workflow.

Latest 2026-05-23 program/data issue classification pass:

- Moved the data-only reports that had been appended under `wave3_noticed_problems.md` into `wave3_data_issues.md` under `Migrated From Wave3 Program Notices - 2026-05-23`.
- Left `wave3_noticed_problems.md` focused on program defects and added a pointer explaining that reconstructed-source accuracy, ownership, naming, method-boundary, and generated-data cleanup reports belong in the data issue file.
- Fixed the broad unresolved-memory scan reported by another agent. `wave3_cache.find_catalog_entries` now scans lightweight resident/project-index catalog entries instead of hydrating every match through `get_catalog_entry`. Live profile for `list memory-unresolved --entity-kind class --limit 25` completed with service duration about `4.599` seconds and no queue/cache residue.
- Classified the parallel 10-second class-summary report as a usage/serialization note, not a current program defect. Sequential `show class BoardListDialog --summary` profiled at about `5.866` service seconds with no residue; parallel normal `wave3.py` commands are still serialized through one main queue.
- Fixed simroot generated-code normalization for repeated helper definitions and wrapped scoped-install markers. `class_ScrollWidget.cpp` now suffixes repeated helper names by method address, and `class_TextEditPane.cpp` now emits `// NTK_ScopedInstall(~TextEditPane, 0x0058e140)` on one line.
- Added focused unit coverage for cache field-filter lookup and simroot marker/helper normalization.

Observed lightweight state checks after the follow-up fix:

- `python wave3d.py debug show queue-status` reported `status: ok`.
- `python wave3d.py show service-status` reported all services ready.
- `selected_implementation_version` is `v2`.
- `service_version_status` is `match`.
- Main service was ready with no active request.
- Main command queue had `pending_request_count: 0`, `pending_result_count: 0`, `stale_request_count: 0`, `stale_result_count: 0`, `cancellation_count: 0`, and `cancellation_bytes: 0`.
- `prewave_cache`, `wave2_cache`, and `wave3_cache` were all ready with no active request.
- The latest recorded main request after the final service restart was `search symbol Registry --limit 60`, completed successfully in about `1.591` service seconds.
- Recent request history includes repeated successful `search symbol GetCurrentTick --limit 25` calls after the symbol-search optimization; the latest recorded successful run completed in about `1.641` seconds.
- Recent request history also includes `list memory-libraries --limit 5`, `show memory-coverage`, `validate command-inventory`, `inspect source-map class_AboveFrame.cpp --summary`, and the formerly timed-out noticed-problem commands, all completed successfully.

Current service snapshot from the handoff check:

- Main PID: `7040`, phase `ready`, implementation `v2`.
- `prewave_cache` PID: `19500`, ready, revision `768a995772ee0cd88328bfdc89d5659ec1e0035b`.
- `wave2_cache` PID: `9720`, ready/reused, revision `0ba120864208f53283d3af8553b3d65c42cd0bf7`.
- `wave3_cache` PID: `13044`, ready, revision `dcd2d5d5642e71b4ec7a6550ce29e72b07297273`.
- Active generated roots:
  - Simroot: `E:\NTK\GhidraBridge\source-3\simroot_v2`.
  - Builder: `E:\NTK\GhidraBridge\source-3\builder_v2`.
  - Workdir: `E:\NTK\GhidraBridge\source-3\workdir_v2`.
- `wave3_cache` currently has a small number of non-stale result files under cache RPC. They are below the stale threshold and should not be manually deleted while another agent is using the tool.

Use only lightweight state checks while another agent is active:

```powershell
python wave3d.py debug show queue-status
python wave3d.py show service-status
python wave3d.py debug show cache-request-history --slow-only --limit 10
```

Avoid these until the active investigating agent is finished:

```powershell
python wave3d.py debug restart cache prewave
python wave3d.py debug restart cache wave2
python wave3d.py debug restart cache wave3
python wave3d.py debug reimport prewave
python wave3d.py debug reimport wave2
python wave3d.py debug reimport wave3
python wave3d.py debug refresh memory-indexes
python wave3d.py debug regrade-all
```

## Primary User Request Being Implemented

The current development request is to make Wave3 fully support memory coverage tracking for reverse engineering accuracy.

User requirements, restated concretely:

- Track memory coverage globally across executable/image ranges.
- Classify top-level executable/image regions as reconstruction work, null/padding, library, CRT, compiler-generated, import stubs, resources, or other reviewed categories.
- Track coverage down through ownership tiers: image range, reconstruction range, file/class/method/global/global-data/static-member, sub-entity range, and source line.
- Maintain a per-emitted-source-line provenance/source map so a C++ line can be traced back to original memory addresses/ranges.
- Include source-line provenance in scoring/grading.
- Detect duplicate memory coverage across different items.
- Allow reviewed duplicate/shared coverage to be omitted or marked with reasons.
- Allow external/generated ranges to be classified with reasons and metadata, including library name, version, build reference, and whether a build reference is required.
- Provide commands to list libraries/CRT/library-like functions in the program, inspect their memory ranges, and decide whether they need build references.
- Keep all of this cache-backed and bounded so `main.py` asks caches for needed blocks instead of reading entire cache files or broad catalogs.

## What Was Implemented In This Pass

### Source-Line Provenance For Final Simroot Output

Implemented final emitted-source source maps for simroot `.cpp` files.

Important behavior:

- Simroot emission now writes `.source_map.json` sidecars next to active and disabled emitted `.cpp` outputs.
- Source maps are generated after final emitted text is assembled, so line numbers include autograder headers, penalty comments, include normalization, disabled-file comments, and `$$SIMPATH` handling.
- `wave3_cache` prefers the simroot source-map sidecar for the `source_map` block when available.
- The old file-storage `live.cpp` source map remains as fallback for files that have not been emitted yet.
- Manual source-line overrides still live in the file memory-range overlay under `source_line_overrides`.
- `set source-line-range` and `clear source-line-range` now trigger targeted refresh/regrade so source-map and scoring state update after the edit.

Key files:

- `core/export/simroot_impl.py`
- `core/cache/wave3_state_v2.py`
- `core/runtime/in_memory_state_impl_v2.py`
- `core/store/wave3/source_line_map.py`

Live verification performed:

```powershell
python wave3d.py inspect source-map class_AboveFrame.cpp --summary
python wave3d.py show source-line class_AboveFrame.cpp 22
```

Observed live result:

- `class_AboveFrame.cpp` source map used `output_kind: simroot_active_cpp`.
- Output path was under `simroot_v2`.
- Summary reported `line_count: 210`, `mapped_line_count: 9`.
- `show source-line class_AboveFrame.cpp 22` mapped final emitted line 22 to `class:AboveFrame` and its class aggregate memory ranges.

### Memory Image Gap Work Packets

Implemented `inspect problem` routing for `memory_image_issue` rows.

Important behavior:

- Memory image gaps now resolve to target kind `memory-image-gap`.
- `inspect problem <memory_image_gap:...>` returns gap metadata: start, end, byte count, classification, segment name, and target id.
- The work packet gives a direct decision path:
  - Add product coverage with `add memory-range` or `set source-line-range`.
  - Classify external/generated bytes with `classify memory-segment`.
  - Only allow/ignore/dismiss after the range is intentionally explained.
- The packet includes `show memory-at` context for the first byte.
- The packet includes a bounded prewave function sample for the gap range.

Key files:

- `core/runtime/in_memory_state_impl_v2.py`
- `core/cache/wave3_state_v2.py`
- `core/cache/prewave_state_v2.py`
- `core/commands/dispatcher_impl.py`
- `core/commands/inventory_impl.py`

Live verification performed:

```powershell
python wave3d.py inspect problem memory_image_gap:0x00401000:0x0041429f
```

Observed live result:

- Target kind was `memory-image-gap`.
- Work packet included `gap`, `decision`, `next_commands`, `memory_at_start`, and `prewave_functions`.
- Prewave sample returned lower functions overlapping the gap.

### Prewave Function Range Scan

Added a bounded range query for lower prewave functions.

Command:

```powershell
python wave3d.py list prewave-function --range 0x00401000 0x0041429f --limit 5
```

Important behavior:

- Proxies through `wave3_cache` to `prewave_cache`.
- Returns lower functions overlapping the requested memory range.
- Includes id, address, end, size, name, overlap start/end, library/external flags, classification, build reference fields, and follow-up commands.
- Supports `--limit`, `--offset`, and `--exclude-external`.

Live verification result:

- Query over `0x00401000` to `0x0041429f` returned `total_count: 320`, `returned_count: 5`, `has_more: true`.

### Memory Image Coverage Hardening

Fixed a stale/corrupt memory image coverage issue found during verification.

Observed bug:

- `show memory-coverage` temporarily reported image coverage at `0.0%`.
- Entity coverage interval count was incorrectly tiny.
- The real disk `memory_range_index` had thousands of ranges.

Fix:

- `wave3_cache.load_cached_only` now refreshes derived startup system documents through the derived-document refresh path.
- `memory_image_map` is rebuilt from `memory_range_index`, not imported from stale generated output directly.
- Live default refreshes refuse to overwrite real image coverage from a tiny/incomplete in-memory stub when the real range index exists on disk.

Live verification result after refresh:

- `show memory-coverage` reported `reconstruction_coverage_percent: 40.4958`.
- `entity_coverage_interval_count: 3580`.
- `global_gap_interval_count: 3583`.
- `covered_reconstruction_byte_count: 1107350`.

### Lower Library/CRT Discovery Optimization

Implemented a resident lower-library index in `prewave_cache`.

Problem:

- `list memory-libraries --limit 5` took about 42 seconds live.
- It was scanning/resolving every lower prewave function payload to find library/CRT functions.

Fix:

- `prewave_cache` now builds `library_function_rows` during eager startup.
- `list_library_functions` uses this resident index and returns bounded pages from memory.
- `memory_usage_summary` reports `library_function_index` memory use.
- `list memory-libraries` now shows `detected_lower_libraries.index_source: resident_library_function_index`.

Live verification:

```powershell
python wave3d.py debug profile command --include-result --health -- list memory-libraries --limit 5
```

Observed:

- Client elapsed time dropped from about 42 seconds to about 2.8 seconds.
- Service duration was about 1.6 seconds.
- Queue remained clean.
- Output returned lower library families such as `msvc_stl`, `ida_library_unknown`, and `msvc_crt`.

### Lower Prewave Symbol Search Index

Implemented a compact prewave symbol metadata index.

Problem:

- Prewave symbol search misses previously scanned/resolved all function payloads and could contribute to 30+ second search timeouts.
- A miss such as `GetCurrentTick` was especially expensive.

Fix:

- During prewave import, each function index entry now stores `symbol_search_fields` for address, preferred name, name maps, method name, class hints, and signature.
- On eager startup, `prewave_cache` builds `symbol_search_index`.
- `search_symbols` now scans these compact fields instead of resolving full function payloads.
- Decompiled text remains excluded from symbol search to avoid false positives.

Tests:

- Added regression coverage that a symbol miss does not call `load_function`.
- Added import test that `functions_index.json` contains `symbol_search_fields`.

Important caveat:

- Existing normalized prewave cache on disk may not have `symbol_search_fields` until a prewave reimport happens.
- Because lazy loading is disabled and the new eager startup path builds `symbol_search_index` from resident payloads, live service can still benefit without reimport.
- A future prewave reimport will persist the compact index into normalized cache files.

### Wave3 Symbol Search Catalog Optimization

Implemented Wave3-side symbol search over lightweight catalog/index entries.

Problem:

- Even after the prewave symbol index, `search symbol GetCurrentTick --limit 25` still timed out in `wave3_cache`.
- The slow path was `wave3_cache.search_symbols`, which hydrated full catalog entries for each id.

Fix:

- Added `_iter_symbol_search_catalog_entries`.
- `search_symbols` now iterates lightweight catalog-store entries or project-index entries directly.
- It falls back to `get_catalog_entry` only in legacy/unit-test style states where no manifest/store is present.
- It still includes created overlay entities and excludes deleted overlay entities.

Live verification:

- After cache restart, lightweight queue status showed latest `search symbol GetCurrentTick --limit 25` completed successfully in about `1.641` seconds.

Important note:

- I had just restarted `wave3_cache` and main after this patch. The current state check confirms the post-restart service is functional.

## Tests Run

Focused and broad targeted suites that passed after the memory/source-map work and library optimization:

```powershell
python -m py_compile core\cache\prewave_state_v2.py core\cache\wave3_state_v2.py core\runtime\in_memory_state_impl_v2.py core\commands\dispatcher_impl.py core\commands\inventory_impl.py core\tests\test_cache_v2.py core\tests\test_project_problems.py
```

```powershell
python -m unittest -v core.tests.test_cache_v2.PrewaveCacheStateTest core.tests.test_cache_v2.Wave3CacheStateTest
```

Result:

- `266` tests passed in about `97.420` seconds.

```powershell
python -m unittest -v core.tests.test_project_problems core.tests.test_memory_ranges core.tests.test_grade_engine
```

Result:

- `112` tests passed in about `1.802` seconds.

Focused tests after the final symbol-search patches:

```powershell
python -m py_compile core\cache\wave3_state_v2.py core\cache\prewave_state_v2.py
```

```powershell
python -m unittest -v core.tests.test_cache_v2.Wave3CacheStateTest.test_wave3_cache_search_symbols_is_bounded_and_kind_prioritized core.tests.test_cache_v2.Wave3CacheStateTest.test_wave3_cache_search_symbols_includes_prewave_lower_function_hits core.tests.test_cache_v2.PrewaveCacheStateTest.test_search_symbols_scans_prewave_function_metadata_without_decompiled_noise
```

Result:

- Focused search tests passed.

Outstanding verification not yet completed:

- Rerun the full `PrewaveCacheStateTest` and `Wave3CacheStateTest` after the final Wave3-side symbol search optimization. The focused tests passed, and the previous broad run passed before this final patch.
- Run a full live `debug profile command --health -- search symbol GetCurrentTick --limit 25` after the final restart if no other agent is using the tool. A lightweight queue-status check already shows this command completed successfully in about `1.641` seconds.

## Files Modified In This Work Area

Primary implementation files:

- `core/export/simroot_impl.py`
- `core/cache/prewave_state_v2.py`
- `core/cache/wave3_state_v2.py`
- `core/runtime/in_memory_state_impl_v2.py`
- `core/commands/dispatcher_impl.py`
- `core/commands/inventory_impl.py`
- `core/store/wave3/source_line_map.py`
- `core/store/wave3/memory_image_store_impl.py`

Tests touched:

- `core/tests/test_cache_v2.py`
- `core/tests/test_project_problems.py`
- `core/tests/test_memory_ranges.py`
- `core/tests/test_grade_engine.py`

Documentation touched:

- `project-documentation/wave3_tool_guide.md`
- `project-documentation/wave3_coding_tasks.md`

## Current Incomplete Or Future Work

### Do Not Run Immediately

Another agent is using Wave3. Defer heavy tests and all restarts until that agent finishes.

### Final Search Verification

When the tool is free:

```powershell
python wave3d.py debug profile command --include-result --health -- search symbol GetCurrentTick --limit 25
python wave3d.py debug show cache-request-history wave3 --slow-only --limit 10
python wave3d.py debug show queue-status
```

Expected:

- `search symbol GetCurrentTick --limit 25` should complete, not timeout.
- Queue should remain empty after the command.
- `wave3_cache` should not record a slow `search_symbols` request.

### Full Search Regression Suite

When the tool is free:

```powershell
python -m unittest -v core.tests.test_cache_v2.PrewaveCacheStateTest core.tests.test_cache_v2.Wave3CacheStateTest
```

This should be run once more because the last broad cache test run happened before the final `_iter_symbol_search_catalog_entries` patch. Focused tests passed after the patch.

### Prewave Reimport To Persist Symbol Search Fields

The live service benefits from the eager startup symbol index, but existing normalized cache files may not have the new `symbol_search_fields` entries until prewave is reimported.

When no one else is using the tool and a long operation is acceptable:

```powershell
python wave3d.py debug reimport prewave
python wave3d.py debug restart cache prewave
```

Expected:

- `core\data\cache\prewave\_system\functions_index.json` entries include `symbol_search_fields`.
- `prewave_cache` summary still reports the same `function_count`.
- Symbol search misses should not resolve full payloads.

Do not run this now while another agent is active.

### Client Timeout And Abandoned Process Cleanup

The noticed-problems file records read-only `wave3.py` commands timing out and leaving client processes alive. This was investigated and fixed in the follow-up pass.

Fix status:

- `wave3.py` now includes `client_pid`, `client_parent_pid`, and a cancellation marker path in each queued request.
- `wave3.py` now marks a request abandoned and removes its local request/result artifacts when the client times out, is interrupted, or detects that its launching parent process exited.
- The v2 main queue now skips queued requests whose clients are already dead or cancelled.
- The v2 main queue now avoids writing unclaimed results when the client dies while the request is executing.
- Queue/status summaries now include command cancellation marker counts and bytes.
- The main service was restarted after the patch and is running the updated queue logic.

Verification completed:

```powershell
python -m py_compile wave3.py core\runtime\command_queue.py core\paths.py core\tests\test_client_entrypoints.py
python -m unittest -v core.tests.test_client_entrypoints
```

Results:

- `63` client/entrypoint tests passed.
- Added focused coverage for timeout cleanup, parent-death cleanup, skipping queued dead-client work, and avoiding unclaimed results after mid-request client death.
- The previously timed-out commands were live-profiled and completed successfully:
  - `inspect class RegistryConfig --method-limit 25`: about `9.728` service seconds.
  - `inspect class ProfileDialog --method-limit 20`: about `8.052` service seconds.
  - `show global 0x004f95b0 --summary`: about `4.653` service seconds.
  - `show global 0x004f9280 --summary`: about `4.535` service seconds.
  - `show global 0x0050aba0 --summary`: about `4.637` service seconds.
  - `search symbol Registry --limit 60`: about `1.580` service seconds.
- Controlled parent-death live verification passed: after killing the parent shell for `wave3.py inspect class RegistryConfig --method-limit 25`, no matching Python client remained, the main service recorded `result_delivered: false`, and queue/cancellation directories were clean.

Useful follow-up checks if this class of issue reappears:

```powershell
python wave3d.py debug profile command --health -- inspect class RegistryConfig --method-limit 25
python wave3d.py debug profile command --health -- inspect class ProfileDialog --method-limit 20
python wave3d.py debug profile command --health -- show global 0x004f95b0 --summary
python wave3d.py debug profile command --health -- show global 0x004f9280 --summary
python wave3d.py debug profile command --health -- show global 0x0050aba0 --summary
python wave3d.py debug profile command --health -- search symbol Registry --limit 60
python wave3d.py debug show queue-status
python wave3d.py debug show request-history --limit 20
python wave3d.py debug show cache-request-history --slow-only --limit 20
```

Expected:

- Commands should complete or fail cleanly.
- No stale main queue items should remain.
- No stale cache RPC requests should remain.
- No orphaned `wave3.py` clients should remain after timeout/interruption.

### Build Reference Validation

Current implementation stores build metadata for external/library classifications:

- `library_name`
- `library_version`
- `build_reference`
- `requires_build_reference`

Still missing:

- Automatic validation that required build references are present in project build inputs.
- A queue/report for missing required library/build references.
- A command such as `validate build-references` or a section inside `issues`/`show project-status --summary`.

This should be added later because it directly supports the user's requirement that library/CRT code be identified and either omitted or referenced correctly during build.

### Semantic Sub-Entity Coverage

Current coverage works at image, entity, range, and source-line levels. Future high-value accuracy work:

- Add first-class sub-entity records for vtables.
- Add first-class sub-entity records for RTTI.
- Add first-class sub-entity records for switch tables and jump tables.
- Add first-class sub-entity records for import thunks.
- Add first-class sub-entity records for exception tables.
- Add first-class sub-entity records for string/data pools.

Reason:

- These bytes currently risk being forced into broad class/method ranges or left as global image gaps.
- Semantic records would make coverage more accurate without requiring fake source reconstruction.

### Source-Line Exactness Improvements

Current source-line maps are accurate to final emitted line numbers and inherit entity ranges. Manual exact overrides are supported.

Still worth adding:

- Optional instruction-to-source-line exact mapping when decompiler/IDA/Ghidra line metadata exists.
- A command to bulk import line-level address comments or decompiler line mappings.
- A report that shows methods/classes with only inherited entity-level line provenance but no exact manual/source line provenance.

Reason:

- Current automatic provenance uses `entity_range_by_line`; it is correct enough for coverage/scoring but not always exact instruction-level provenance.

### Better Global Image Gap Triage

Current `inspect problem memory_image_gap:...` includes a 10-row prewave function sample.

Future improvements:

- Add `--limit` / `--offset` options to `inspect problem` for memory image gap prewave sample paging.
- Add command to split a large memory gap into suggested function-sized work items.
- Add direct reviewed commands to classify all lower library functions in a gap as CRT/library when safe.

### Tool Self-Audit Follow-Up

The guide already describes `debug self-audit`. Keep using it after larger changes:

```powershell
python wave3d.py debug self-audit --detail
```

Watch for:

- Stale TODO/spec status.
- V1 fallback usage.
- Broad projection paths.
- Cache revision mismatch.
- Test-run residue.
- New slow request history.

## Triage Of `wave3_noticed_problems.md`

File reviewed:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\wave3_noticed_problems.md
```

Recorded issue:

- Several read-only `wave3.py` inspection commands timed out and left client processes running.

Assessment:

- This should be treated as a real tool robustness issue, not dismissed as purely transient.
- The specific slow `search symbol ...` symptom was reproducible during this pass with `GetCurrentTick`.
- That symbol-search path was fixed by adding lightweight Wave3 catalog scanning and prewave symbol indexing.
- Queue state after the fix is currently clean, and the latest `search symbol GetCurrentTick --limit 25` completed successfully.
- The orphaned/timed-out client process behavior was fixed in the follow-up pass with client PID tracking, parent-death detection, and queue cancellation markers.
- The class/global inspection timeouts were retested live and completed successfully.

Recommended status:

- `search symbol` timeout: fixed for the reproduced cases.
- `inspect class` and `show global --summary` timeouts: fixed for the listed cases.
- Orphaned client processes after timeout/parent death: fixed for the controlled reproduction; continue monitoring future interruptions.

## Safe Handoff Instructions For The Other Agent

The other agent can continue using normal user-facing commands now.

Safe examples:

```powershell
python wave3.py show project-status --summary
python wave3.py inspect class <ClassName> --method-limit 25
python wave3.py inspect method <addr_or_name>
python wave3.py inspect source-map <file> --summary
python wave3.py show source-line <file> <line>
python wave3.py list prewave-function --range <start> <end> --limit 25
python wave3.py list memory-libraries --limit 25
```

If commands slow down, first run:

```powershell
python wave3d.py debug show queue-status
python wave3d.py debug show request-history --limit 10
python wave3d.py debug show cache-request-history --slow-only --limit 10
```

Do not immediately restart caches while the agent is mid-investigation unless queue/status shows a real stuck active request or stale service state.

## Pause Verification Summary

The final action for this handoff was intentionally limited to lightweight status reads and documentation edits.

No heavy command was started for the pause handoff. Specifically, I did not run:

- Full cache reimport.
- Full cache restart.
- Full project materialization.
- Full regrade.
- Broad smoke test.
- Long profiling run.

The tool is ready for the investigating agent because:

- Main service is alive and ready.
- All three cache services are alive and ready.
- Main queue has no pending or stale work.
- Cache RPC queues have no pending or stale request files.
- The current implementation version is v2 and matches the active service.
- Recent command history contains successful readonly commands after the latest cache/runtime changes.

If the other agent sees a timeout, first inspect queue and request history. Do not restart services before checking whether another active request is still legitimate:

```powershell
python wave3d.py debug show queue-status
python wave3d.py debug show request-history --limit 20
python wave3d.py debug show cache-request-history --slow-only --limit 20
python wave3d.py show service-status
```
