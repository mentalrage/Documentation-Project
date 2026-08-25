** TARGET-REPORT-UID:0000W4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Report: [UID:0000W4] ZlibDeflateAndTrees Source Quality

Assignment source: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0000W4-ZlibDeflateAndTrees-source-quality.md`
Target: `by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md`
Current target metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000PC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PC`, blank `RECONSTRUCTION_CPP`
MCP session used: `80de0a67`
Research mode: report only. No target/support by-* documentation was edited. No `-coverage-report.md` file was edited. No IDA MCP process was started, stopped, restarted, or otherwise managed.

## MCP Session Status

Session `80de0a67` was available and responsive.

Verified MCP status:

- `idb_list`: active session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, created `2026-06-23T14:11:02.684517`, backend worker active.
- `server_health` for database `80de0a67`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

No fallback-only evidence was used.

## Function / Child Inventory

The current target range is not one contiguous source-file block. It contains two zlib source clusters and also crosses a sibling inflate/Adler block already documented by `0000W5`.

### Functions In Current Range

| Address | MCP name | Size | Source identity | Recommended disposition |
|---|---:|---:|---|---|
| `0x00414820` | `sub_414820` | `0x2ad` | `deflate.c:deflate` | Keep under narrowed `0000W4` deflate worker child |
| `0x00414ad0` | `sub_414AD0` | `0x2f` | `deflate.c:putShortMSB` | Keep under narrowed `0000W4` |
| `0x00414b00` | `sub_414B00` | `0x72` | `deflate.c:flush_pending` | Keep under narrowed `0000W4` |
| `0x00414b80` | `sub_414B80` | `0xaa` | `deflate.c:deflateEnd` | Keep under narrowed `0000W4` |
| `0x00414c30` | `sub_414C30` | `0x93` | `deflate.c:lm_init` | Keep under narrowed `0000W4` |
| `0x00414cd0` | `sub_414CD0` | `0x157` | `deflate.c:deflate_stored` | Keep under narrowed `0000W4` |
| `0x00414e30` | `sub_414E30` | `0x122` | `deflate.c:fill_window` | Keep under narrowed `0000W4` |
| `0x00414f60` | `sub_414F60` | `0x71` | `deflate.c:read_buf` | Keep under narrowed `0000W4` |
| `0x00414fe0` | `sub_414FE0` | `0x32d` | `deflate.c:deflate_fast` | Keep under narrowed `0000W4` |
| `0x00415310` | `sub_415310` | `0x16f` | `deflate.c:longest_match` | Keep under narrowed `0000W4` |
| `0x00415480` | `sub_415480` | `0x42a` | `deflate.c:deflate_slow` | Keep under narrowed `0000W4` |
| `0x004158b0` | `sub_4158B0` | `0x42` | `inflate.c`/zlib API sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415900` | `sub_415900` | `0x48` | zlib allocator/API sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415950` | `sub_415950` | `0x10e` | `adler32.c`/zlib sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415a60` | `sub_415A60` | `0x1a` | inflate support sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415a80` | `sub_415A80` | `0x3f7` | inflate API sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415eb0` | `sub_415EB0` | `0x13` | zlib allocator sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415ed0` | `sub_415ED0` | `0x0c` | zlib allocator sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00415ee0` | `sub_415EE0` | `0x12e` | inflate API sibling | Exclude from `0000W4`; already belongs to `0000W5` |
| `0x00416010` | `sub_416010` | `0x6c` | `trees.c:_tr_init` | Move to new exact trees child |
| `0x00416080` | `nullsub_8` | `0x1` | `trees.c:tr_static_init`, optimized no-op | Move to new exact trees child |
| `0x00416090` | `sub_416090` | `0x66` | `trees.c:init_block` | Move to new exact trees child |
| `0x00416100` | `sub_416100` | `0x9d` | `trees.c:_tr_stored_block` | Move to new exact trees child |
| `0x004161a0` | `sub_4161A0` | `0x255` | `trees.c:_tr_align` | Move to new exact trees child |
| `0x00416400` | `sub_416400` | `0x1ee` | `trees.c:_tr_flush_block` | Move to new exact trees child |
| `0x004165f0` | `sub_4165F0` | `0x233` | `trees.c:build_tree` | Move to new exact trees child |
| `0x00416830` | `sub_416830` | `0xd1` | `trees.c:pqdownheap` | Move to new exact trees child |
| `0x00416910` | `sub_416910` | `0x221` | `trees.c:gen_bitlen` | Move to new exact trees child |
| `0x00416b40` | `sub_416B40` | `0x73` | `trees.c:gen_codes` | Move to new exact trees child |
| `0x00416bc0` | `sub_416BC0` | `0x6f` | `trees.c:build_bl_tree` | Move to new exact trees child |
| `0x00416c30` | `sub_416C30` | `0xe7` | `trees.c:scan_tree` | Move to new exact trees child |
| `0x00416d20` | `sub_416D20` | `0x265` | `trees.c:send_all_trees` | Move to new exact trees child |
| `0x00416f90` | `sub_416F90` | `0x575` | `trees.c:send_tree` | Move to new exact trees child |
| `0x00417510` | `sub_417510` | `0x43b` | `trees.c:compress_block` | Move to new exact trees child |
| `0x00417950` | `sub_417950` | `0x74` | `trees.c:set_data_type` | Move to new exact trees child |
| `0x004179d0` | `sub_4179D0` | `0x1f` | `trees.c:bi_reverse` | Move to new exact trees child |
| `0x004179f0` | `sub_4179F0` | `0x8b` | `trees.c:bi_flush` | Move to new exact trees child |
| `0x00417a80` | `sub_417A80` | `0x7c` | `trees.c:bi_windup` | Move to new exact trees child |
| `0x00417b00` | `sub_417B00` | `0x97` | `trees.c:copy_block` | Move to new exact trees child |

`0x00417ba0 sub_417BA0` is the next function start and belongs to `0000W6` inflate internals, not to this target.

### Recommended Exact Children

1. Preserve UID `0000W4` but narrow/rename it to:
   - `by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md`
   - Meaning: zlib `deflate.c` worker/API tail after the public setup/reset block.

2. Create a new exact child:
   - `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`
   - Meaning: zlib `trees.c` Huffman tree, block flushing, bit output, and stored-copy helpers.

3. Leave `0000W5` unchanged for:
   - `0x004158b0-0x0041600e` inflate API, zlib allocation shims, and Adler/checksum support.

4. Leave `0000W6` unchanged for:
   - `0x00417ba0-0x00419e56` inflate internals.

The source-file view should also acknowledge that `deflate.c` starts before the current `0000W4` range: public setup/reset code at approximately `0x00414570-0x00414813` is documented on parent `0000W3` but lacks its own exact child.

## Direct Xref / Caller Inventory

Representative current MCP observations:

- `0x00414820 sub_414820` matches `deflate.c:deflate`.
  - Caller: `0x004142c0 sub_4142C0` public compression wrapper path.
  - Callees: `0x00414ad0` (`putShortMSB`), `0x00414b00` (`flush_pending`), `0x004161a0` (`_tr_align`), `0x00416100` (`_tr_stored_block`).
  - Data xref: `0x004149b4` references `0x00632560`, IDA name `funcs_4149B4`, which is the zlib `configuration_table`.
  - Constants and states include zlib deflate values such as `42`, `113`, `666`, `0x7800`, flush handling, zlib header/trailer logic, and dispatch through `configuration_table[s->level].func`.

- `0x00414c30 sub_414C30` matches `deflate.c:lm_init`.
  - Caller: `0x004147a0` deflate reset/setup path.
  - Uses compression-level configuration values corresponding to `configuration_table`.

- `0x00415480 sub_415480` matches `deflate.c:deflate_slow`.
  - Direct callers: none, because it is reached through `configuration_table` function pointers.
  - Callees: `0x00415310` (`longest_match`), `0x00414e30` (`fill_window`), `0x00416400` (`_tr_flush_block`), `0x00414b00` (`flush_pending`).
  - The lack of a direct caller is not dead-code evidence.

- `0x00416010 sub_416010` matches `trees.c:_tr_init`.
  - Caller: `0x004147a0` deflate reset/setup path.
  - Callees: `0x00416080 nullsub_8` and `0x00416090 init_block`.
  - Initializes tree descriptors, bit buffer state, `last_eob_len`, and block state.

- `0x00416400 sub_416400` matches `trees.c:_tr_flush_block`.
  - Callers: `0x00414cd0 deflate_stored`, `0x00414fe0 deflate_fast`, `0x00415480 deflate_slow`.
  - Callees: `build_tree`, `set_data_type`, `send_all_trees`, `bi_windup`, `compress_block`, `build_bl_tree`, `init_block`, `_tr_stored_block`.

- `0x00417b00 sub_417B00` matches `trees.c:copy_block`.
  - Caller: `0x00416100 _tr_stored_block`.
  - Callee: `0x00417a80 bi_windup`.
  - Emits stored block length/complement and raw bytes.

Important data xrefs:

- `0x00632560` is not runtime tail. It is zlib deflate `configuration_table[10]`.
  - Bytes at `0x00632560` contain function pointers to `0x00414cd0`, `0x00414fe0`, and `0x00415480` plus the known zlib compression-level parameters.
  - The table length is `10 * 12 = 0x78`, so the exact table span is `0x00632560-0x006325d8`.
- `0x00671b88`, `0x00671ba0`, and `0x00671bb8` are zlib tree descriptor/static table routes referenced by `_tr_init`.

## Documentation Evidence And IDA Status

Documents reviewed:

- `by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md`
- `by-file/Zlib.md`
- `by-memory/0x004142c0-0x00419e56.ZlibCore.md`
- `by-memory/0x004142c0-0x0041456f.ZlibPublicCompressionAndChecksums.md`
- `by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md`
- `by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md`
- `by-meta/client_libraries.md`
- `by-meta/obtained_thirdparty_files/README.md`
- `by-project-structure/proposed-source-tree.md`
- `by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md`
- `by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md`
- `by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/third_party/zlib/Zlib.cpp`
- `auto-generated/by-memory-tool-report.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md` read only
- `source-3/third_party_embeds/zlib/deflate.c`
- `source-3/third_party_embeds/zlib/trees.c`
- `source-3/third_party_embeds/zlib/deflate.h`

Current documentation is broadly correct that the island is zlib 1.1.4 under `0000PC`. The weakness is structural:

- Current `0000W4` crosses `0000W5`, so its filename/range implies one contiguous zlib deflate/tree source block when the actual source-bearing children should be separated.
- `by-file/Zlib.md` correctly favors the stock multi-file zlib layout under `third_party/zlib/`.
- `by-meta/client_libraries.md` correctly classifies zlib as a statically embedded third-party dependency and recommends preserving stock files.
- `by-meta/obtained_thirdparty_files/README.md` documents official zlib 1.1.4 provenance and local mirror equivalence.
- Generated `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` contains empty emitter markers only. That is an autogen artifact and should not override the source-file placement in `third_party_embeds/zlib/*.c`.
- `by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md` has a specific support-data problem: it currently treats `0x00632560` as the boundary before MSVC runtime read-only data, but current MCP bytes and xrefs show `0x00632560-0x006325d8` is zlib `configuration_table[10]`.

IDA naming status:

- IDA still uses generic names such as `sub_414820` and `sub_416400`.
- The IDA data name `funcs_4149B4` at `0x00632560` should be documented as historical/generic IDA naming for zlib `configuration_table`.
- No IDA rename/type/comment edits were made during this report-only pass.

## Ranked Ownership Analysis

1. `0000PC` `by-file/Zlib.md`, stock zlib 1.1.4 static embed: accepted owner.
   - Positive evidence: zlib 1.1.4 source files are obtained and staged, source order and constants match, public wrapper xrefs are contained inside the zlib island, and support data includes zlib strings/tables.
   - Negative evidence against alternatives: no game-specific logic or NexusTK domain behavior appears inside these functions.

2. Exact source-bearing by-memory children under `0000PC`: accepted placement.
   - `0x00414820-0x004158aa` for `deflate.c` worker functions.
   - `0x00416010-0x00417b97` for `trees.c` output helpers.
   - This provides a cleaner range model than the current broad mixed page.

3. Flattened generated `NexusTK/third_party/zlib/Zlib.cpp`: acceptable only as an autogen fallback, rejected as primary source placement.
   - The documented source tree and obtained source preserve zlib's native multi-file layout.
   - A flattened generated file loses source-quality information.

4. Consumer modules such as DAT, MetaMan, image loaders, or product-specific code: rejected.
   - They can call zlib public wrappers, but the implementation body is a third-party library island.

5. Recovered one-function C++ output from decompiler: rejected.
   - It would duplicate third-party source poorly and obscure the verified official source.

6. No-owner/non-emitting classification: rejected for the source-bearing children.
   - The broad current page needs splitting, but the underlying source owner and emitter are known.

## Source Placement

Recommended source placement remains:

- `NexusTK/third_party/zlib/deflate.c`
  - Covers stock deflate public setup/reset and workers.
  - The current `0000W4` first cluster specifically covers `0x00414820-0x004158aa`.
  - Parent `0000W3` also contains earlier `deflate.c` public setup/reset at approximately `0x00414570-0x00414813`.

- `NexusTK/third_party/zlib/trees.c`
  - Covers `0x00416010-0x00417b97`.
  - Includes `_tr_init`, `tr_static_init`, `init_block`, `_tr_stored_block`, `_tr_align`, `_tr_flush_block`, build/scan/send helpers, `compress_block`, bit helpers, and `copy_block`.

Source procurement should come from:

- `source-3/third_party_embeds/zlib/deflate.c`
- `source-3/third_party_embeds/zlib/trees.c`
- Related headers from `source-3/third_party_embeds/zlib/`

Do not reconstruct these bodies from Hex-Rays output when the obtained zlib source is available and documented.

## Range / Split / Padding / Reclassification Analysis

Current range:

- `0x00414820-0x00417b97`

Problem:

- The range includes `0000W5` from `0x004158b0-0x0041600e`.
- The range joins non-contiguous source clusters by skipping over a sibling source island.
- It also joins different source files, `deflate.c` and `trees.c`, into one child.

Recommended split:

- `0x00414820-0x004158aa` -> `ZlibDeflateWorkers`
- `0x004158b0-0x0041600e` -> existing `0000W5` `ZlibInflateApiAllocatorAndAdler`
- `0x00416010-0x00417b97` -> new `ZlibDeflateTreeOutputHelpers`
- `0x00417ba0-0x00419e56` -> existing `0000W6` `ZlibInflateInternals`

Verified alignment/padding:

- `0x00414813-0x00414820`: thirteen `0x90` bytes between deflate setup/reset and `deflate`.
- `0x004158aa-0x004158b0`: six `0x90` bytes between `deflate_slow` and `0000W5`.
- `0x0041600e-0x00416010`: two `0x90` bytes between `0000W5` and `trees.c:_tr_init`.
- `0x00417b97-0x00417ba0`: nine `0x90` bytes between `trees.c:copy_block` and `0000W6`.

These padding spans should be documented but should not receive source reconstruction bodies.

Support-data range correction:

- `0x00632560-0x006325d8` should be treated as zlib `configuration_table[10]`, not MSVC runtime read-only data.
- Recommended new support child: `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`.
- Existing support/runtime pages should be corrected to avoid claiming `0x00632560` as the immediate runtime boundary.

## Negative Evidence Summary

Negative evidence against keeping current `0000W4` unchanged:

- It spans a documented sibling `0000W5` range.
- It merges `deflate.c` and `trees.c` despite strong source-file evidence for separate stock files.
- It has stale code-gate wording about not emitting C++ because the score is below `95/95`, which does not match the current B-agent reconstruction policy.
- Its blank `RECONSTRUCTION_CPP` is acceptable only if explained as third-party static-embed/no-code proof, not as a score-gate failure.

Negative evidence against source edits from decompiler:

- Official zlib 1.1.4 source is already obtained and staged.
- Function order, constants, dispatch table, tree descriptors, strings, and callgraph all match the stock source.
- Recovered decompiler C++ would be lower quality than preserving the official third-party source.

Negative evidence against consumer ownership:

- No NexusTK-specific structures, DAT parsing, UI logic, network protocol logic, or map/resource object ownership appears in these functions.
- Consumers call zlib through public wrapper boundaries.

Negative evidence against declaring tree helpers dead:

- Several `trees.c` helpers are reached only through the deflate worker chain.
- Several deflate workers are reached indirectly through `configuration_table`; missing direct xrefs are expected for function-pointer dispatch.

Negative evidence against existing support-data boundary:

- MCP bytes at `0x00632560` decode to a table of zlib deflate function pointers and compression parameters.
- `0x004149b4` references `0x00632560` from inside `deflate.c:deflate`.

## Heuristic / Source-Quality Reanalysis

The current zlib identification is source-quality rather than name-only or heuristic-only.

Positive source-quality evidence:

- Official zlib 1.1.4 source is present in `third_party_embeds`.
- Function order and function roles match zlib `deflate.c` and `trees.c`.
- zlib status constants, flush modes, block-state flow, and `configuration_table` compression parameters match stock source.
- `trees.c` descriptors and tree-building flow match stock source.
- Strings and static data pages carry zlib 1.1.4 identifiers and support tables.

Remaining heuristic elements:

- Function names are inferred from stock zlib source and binary behavior, not from PDB symbols.
- Local variable names and exact compiler type spelling should not be overclaimed.
- `tr_static_init` appearing as `nullsub_8` is inferred to be an optimization/static-data result. The source identity is strong, but the exact compiler reason should remain a note rather than a hard claim.
- Configuration-table field order in raw bytes should be documented carefully through compiler layout, not by assuming source declaration order from text alone.

Source quality should improve after split because each child will match a specific source-file cluster and no longer contain a sibling range.

## IDA Rename / Type / Comment Recommendations

No IDA database edits were performed.

Recommended future IDA/documentation names if a supervisor authorizes implementation:

- `0x00414820` -> `zlib_deflate`
- `0x00414ad0` -> `zlib_putShortMSB`
- `0x00414b00` -> `zlib_flush_pending`
- `0x00414b80` -> `zlib_deflateEnd`
- `0x00414c30` -> `zlib_lm_init`
- `0x00414cd0` -> `zlib_deflate_stored`
- `0x00414e30` -> `zlib_fill_window`
- `0x00414f60` -> `zlib_read_buf`
- `0x00414fe0` -> `zlib_deflate_fast`
- `0x00415310` -> `zlib_longest_match`
- `0x00415480` -> `zlib_deflate_slow`
- `0x00416010` -> `zlib__tr_init`
- `0x00416080` -> `zlib_tr_static_init_optimized_noop`
- `0x00416090` -> `zlib_init_block`
- `0x00416100` -> `zlib__tr_stored_block`
- `0x004161a0` -> `zlib__tr_align`
- `0x00416400` -> `zlib__tr_flush_block`
- `0x004165f0` -> `zlib_build_tree`
- `0x00416830` -> `zlib_pqdownheap`
- `0x00416910` -> `zlib_gen_bitlen`
- `0x00416b40` -> `zlib_gen_codes`
- `0x00416bc0` -> `zlib_build_bl_tree`
- `0x00416c30` -> `zlib_scan_tree`
- `0x00416d20` -> `zlib_send_all_trees`
- `0x00416f90` -> `zlib_send_tree`
- `0x00417510` -> `zlib_compress_block`
- `0x00417950` -> `zlib_set_data_type`
- `0x004179d0` -> `zlib_bi_reverse`
- `0x004179f0` -> `zlib_bi_flush`
- `0x00417a80` -> `zlib_bi_windup`
- `0x00417b00` -> `zlib_copy_block`
- `0x00632560` -> `zlib_configuration_table`

Recommended comments:

- At `0x00415480`: "Reached through zlib configuration_table, so direct xrefs are not expected."
- At `0x00416080`: "Stock zlib tr_static_init collapsed to optimized no-op because static tables are already materialized."
- At `0x00632560`: "zlib deflate.c configuration_table[10], span 0x00632560-0x006325d8."

## First-Draft C++ Recommendation

Current target `0000W4` should not receive decompiler-derived C++.

Exact no-code proof:

- The target is a third-party static embed, not product-native code.
- Official zlib 1.1.4 source is already obtained and staged.
- Current broad `0000W4` is range-mixed because it spans `0000W5`.
- Function-body C++ generated from Hex-Rays would duplicate lower-quality versions of stock `deflate.c` and `trees.c`.
- The correct reconstruction source is the stock zlib source under `third_party_embeds/zlib`, projected into `NexusTK/third_party/zlib/`.

Recommended by-memory `RECONSTRUCTION_CPP` handling after split:

- Prefer blank `RECONSTRUCTION_CPP` plus explicit static-embed/no-code proof in the page body.
- If the generator requires a nonblank marker, use comments only:

```cpp
// Static embed: third_party_embeds/zlib/deflate.c
```

for `0x00414820-0x004158aa.ZlibDeflateWorkers.md`, and:

```cpp
// Static embed: third_party_embeds/zlib/trees.c
```

for `0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`.

Do not paste full zlib source into by-memory pages.

## Final Recommendation

Implement the split, preserve zlib ownership, and correct the support-data table boundary.

Required target-side outcome:

- Replace current broad `0x00414820-0x00417b97.ZlibDeflateAndTrees.md` with an exact `deflate.c` worker child at `0x00414820-0x004158aa`.
- Create a new exact `trees.c` child at `0x00416010-0x00417b97`.
- Leave `0000W5` and `0000W6` as separate siblings.
- Add explicit padding facts so validators and future authors do not re-merge the ranges.

Required support-side outcome:

- Correct `0x00632560` from runtime-tail boundary to zlib deflate `configuration_table[10]`.
- Add or adjust support data documentation for `0x00632560-0x006325d8`.

Do not keep the current `0000W4` as a single source-bearing emitter page unless it is intentionally demoted to a non-emitting split/container page. Demotion is inferior to the split because exact source-bearing ranges are available.

## Recommended Target Doc Changes

For `by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md`:

1. Rename/re-range to:
   - `by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md`
2. Preserve UID:
   - `0000W4`
3. Update title/name:
   - `ZlibDeflateWorkers`
4. Update range:
   - `0x00414820-0x004158aa`
5. Keep:
   - `CANONICAL_OWNER:0000PC`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000PC`
6. Replace current evidence with current MCP session `80de0a67` evidence:
   - `deflate`, `putShortMSB`, `flush_pending`, `deflateEnd`, `lm_init`, `deflate_stored`, `fill_window`, `read_buf`, `deflate_fast`, `longest_match`, `deflate_slow`.
   - `configuration_table` at `0x00632560`.
   - Function-pointer dispatch for `deflate_stored`, `deflate_fast`, and `deflate_slow`.
7. Remove stale "below 95/95" code-gate wording.
8. Add no-code proof that reconstruction uses stock zlib `deflate.c`, not Hex-Rays C++.
9. Add negative evidence excluding `0000W5` and the `trees.c` cluster from this exact child.
10. Add padding note for `0x004158aa-0x004158b0`.

Create new target child:

1. File:
   - `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`
2. UID:
   - New validator-assigned UID or temporary `TMP:"by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md"` during authoring.
3. Range:
   - `0x00416010-0x00417b97`
4. Owner/emitter:
   - `CANONICAL_OWNER:0000PC`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000PC`
5. Source:
   - `third_party_embeds/zlib/trees.c`
6. Evidence:
   - `_tr_init`, optimized `tr_static_init` no-op, `init_block`, `_tr_stored_block`, `_tr_align`, `_tr_flush_block`, tree-build helpers, send helpers, bit helpers, and `copy_block`.
   - `_tr_flush_block` xrefs from deflate workers.
   - `_tr_init` xref from deflate reset/setup.
   - tree descriptor data routes at `0x00671b88`, `0x00671ba0`, `0x00671bb8`.
7. Add no-code proof that reconstruction uses stock zlib `trees.c`.
8. Add padding notes for `0x0041600e-0x00416010` and `0x00417b97-0x00417ba0`.

Parent and sibling updates:

- `by-memory/0x004142c0-0x00419e56.ZlibCore.md`
  - Update child list to show narrowed `0000W4`, unchanged `0000W5`, new trees child, unchanged `0000W6`.
  - Add note that `0x00414570-0x00414813` is earlier `deflate.c` setup/reset and may deserve a future exact child.
  - Add exact padding spans.
  - Add config-table support correction.

- `by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md`
  - No ownership change. Add only a cross-boundary note if the supervisor wants consistency: it separates deflate workers from `trees.c`.

- `by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md`
  - No ownership change. Add only a cross-boundary note if the supervisor wants consistency: previous padding ends at `0x00417ba0`.

## Recommended Support Doc Changes

`by-file/Zlib.md`:

- Keep `0000PC` as canonical owner.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/third_party/zlib/"`.
- Update source split section to list:
  - `deflate.c`: setup/reset plus `0x00414820-0x004158aa` worker range.
  - `trees.c`: `0x00416010-0x00417b97`.
  - `inflate.c`/allocator/Adler sibling: `0000W5`.
  - inflate internals: `0000W6`.
- Clarify that `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` is an empty-marker generator artifact, not the preferred source placement.

`by-meta/client_libraries.md`:

- Keep zlib static embed classification.
- Update W4 reference if the file is renamed/re-ranged.
- Add new trees child reference once its UID is assigned.

`by-meta/obtained_thirdparty_files/README.md`:

- No required content change. Existing zlib 1.1.4 provenance remains valid.

`by-project-structure/proposed-source-tree.md`:

- No required content change. Existing `NexusTK/third_party/zlib/` file list already supports the recommended split.

`by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md`:

- Remove or revise any statement that `0x00632560` is cleanly the beginning of MSVC runtime read-only data.
- Add cross-reference to the new `0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md` support child.

New support page recommendation:

- `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`
- Owner/emitter:
  - `CANONICAL_OWNER:0000PC`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000PC`
- Evidence:
  - `0x004149b4` xref from `deflate.c:deflate`.
  - Pointers to deflate worker functions.
  - Ten 12-byte zlib compression-level entries.
  - Match to zlib 1.1.4 `configuration_table`.

Runtime read-only data page covering the `0x00632560` region, if present:

- Exclude `0x00632560-0x006325d8` from runtime ownership or document it as already carved out for zlib.

`by-memory/-ignored.md`:

- After implementation, update the zlib ignored ledger to cite the narrowed `0000W4`, the new trees child, unchanged `0000W5`/`0000W6`, and the padding facts.

`by-memory/-coverage-report.md`:

- Supervisor-owned only. Do not let B-agent report-only implementation edit it.
- Exact replacement text is provided below.

## Score And Metadata Recommendation

Current broad `0000W4`:

- Do not raise as-is.
- It is source-quality zlib evidence, but the range is structurally mixed.

Recommended after split:

- `0000W4` as `0x00414820-0x004158aa.ZlibDeflateWorkers.md`
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000PC`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000PC`
  - `RECONSTRUCTION_CPP`: blank preferred, or static-embed marker comment only.

- New `0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:0000PC`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000PC`
  - `RECONSTRUCTION_CPP`: blank preferred, or static-embed marker comment only.

- `0000W3` parent:
  - Candidate after incorporating split/support corrections: `COMPLETION:88`, `CONFIDENCE:91`.

- `0000PC` `by-file/Zlib.md`:
  - Implementation result: support-data correction is now implemented, the source split is documented, and the page remains a stock third-party source aggregate with generated `Zlib.cpp` caveat rather than a decompiler-derived emitter. No unresolved score blocker remains for this callback.

## Open Questions With Attempted Resolution

Question: Should zlib be represented as stock multi-file source or generated `Zlib.cpp`?

- Resolved: `by-file/Zlib.md`, `client_libraries.md`, `obtained_thirdparty_files/README.md`, and `proposed-source-tree.md` all favor stock `third_party/zlib/` source files. The implementation uses multi-file placement and keeps generated `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` as a validator-owned static-embed placeholder/caveat, not the authoritative source layout.

Question: Is `0x00415480 deflate_slow` unused because direct xrefs are absent?

- Resolved: no. It is reached through `configuration_table` at `0x00632560`. MCP bytes and xrefs confirm the table route, and [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) now records the ten 12-byte entries and worker pointers.

Question: Is `0x00416080 nullsub_8` really zlib `tr_static_init`?

- Resolved: yes. Its position, caller from `_tr_init`, and stock `trees.c` flow identify it as `tr_static_init`; [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) phrases the implementation reason as "compiled/optimized no-op because static tree data is already materialized."

Question: Does the current `0x00631850-0x00632560` support page correctly stop before runtime data?

- Resolved: the implementation corrected this. [UID:0003OJ][0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings](by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md) now stops before [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md), and runtime-tail/read-only parent pages now carve out that zlib child.

Question: Should `0x00414570-0x00414813` get an exact child?

- Resolved for this accepted callback: no new child was created because the accepted implementation preserved UID `0000W4` starting at `0x00414820` and requested only a parent/Zlib setup/reset note for `0x00414570-0x00414813`. [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) and [UID:0000PC][Zlib](by-file/Zlib.md) now record `0x00414570-0x00414813` as stock `deflate.c` setup/reset before the alignment padding `0x00414813-0x00414820`. It is outside the narrowed `0000W4` page and does not block W4 score or C++ readiness.

Question: What exact new UID should the trees child use?

- Resolved: validator assigned [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md). The zlib configuration-table child was also registered as [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md).

## Exact Supervisor-Owned Coverage Text

Per supervisor instruction, B002 did not edit any `-coverage-report.md` file. The exact supervisor-owned replacement/insert text with assigned UIDs is:

```markdown
- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) : ignored : 88% : strong : Current MCP session 80de0a67 and B002 split review keep the full bundled zlib 1.1.4 island under [UID:0000PC] Zlib; child rows separate public wrappers/checksums, deflate setup/workers, inflate API/allocator/Adler, trees.c output helpers, and inflate internals. Alignment padding is confirmed at 0x00414813-0x00414820, 0x004158aa-0x004158b0, 0x0041600e-0x00416010, and 0x00417b97-0x00417ba0.
    - [UID:0000W2][0x004142c0-0x0041456f.ZlibPublicCompressionAndChecksums](by-memory/0x004142c0-0x0041456f.ZlibPublicCompressionAndChecksums.md) 0x004142c0-0x0041456f | third-party function cluster | ZlibPublicCompressionAndChecksums : ignored : 86% : strong : Public zlib compression/checksum wrappers remain owned by [UID:0000PC] Zlib.
    - [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md) 0x00414820-0x004158aa | third-party function cluster | ZlibDeflateWorkers : ignored : 88% : strong : Current MCP verifies stock zlib 1.1.4 deflate.c worker/API-tail functions, including deflate, putShortMSB, flush_pending, deflateEnd, lm_init, deflate_stored, fill_window, read_buf, deflate_fast, longest_match, and deflate_slow. Indirect worker dispatch is through zlib configuration_table at 0x00632560.
    - [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) 0x004158b0-0x0041600e | third-party function cluster | ZlibInflateApiAllocatorAndAdler : ignored : 86% : strong : Existing sibling remains the inflate API/allocator/Adler segment between deflate.c workers and trees.c output helpers.
    - [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) 0x00416010-0x00417b97 | third-party function cluster | ZlibDeflateTreeOutputHelpers : ignored : 88% : strong : Current MCP verifies stock zlib 1.1.4 trees.c output helpers from _tr_init through copy_block, including optimized tr_static_init no-op, init_block, _tr_stored_block, _tr_align, _tr_flush_block, build/scan/send tree helpers, bit output helpers, and copy_block.
    - [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) 0x00417ba0-0x00419e56 | third-party function cluster | ZlibInflateInternals : ignored : 86% : strong : Existing sibling remains the zlib inflate internal implementation after the trees.c padding boundary.
```

Insert this coverage row near the existing zlib read-only data rows and adjust any runtime-tail row that currently begins at `0x00632560`:

```markdown
- [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) 0x00632560-0x006325d8 | third-party const table | ZlibDeflateConfigurationTable : ignored : 88% : strong : zlib 1.1.4 deflate.c configuration_table[10], referenced from deflate at 0x004149b4 and containing compression-level parameters plus pointers to deflate_stored, deflate_fast, and deflate_slow; this span is zlib-owned and must not be counted as MSVC runtime read-only data.
```

## Implementation Outcome

The accepted Rule 26 split/repair is implemented. No remaining score blocker or C++ readiness blocker is carried forward for UID `0000W4`, the new trees child, or the new configuration-table child.

- Preserved [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md) with `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter [UID:0000PC], `RECONSTRUCTABLE:TRUE`, and blank formal C++.
- Created [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) with `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter [UID:0000PC], `RECONSTRUCTABLE:TRUE`, and blank formal C++.
- Created [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) with `COMPLETION:88`, `CONFIDENCE:91`, owner/emitter [UID:0000PC], `RECONSTRUCTABLE:TRUE`, and blank formal C++.
- Preserved [UID:0000W5] and [UID:0000W6] as separate siblings.
- Supervisor verification correction: updated [proposed-source-tree.md](by-project-structure/proposed-source-tree.md) so the `third_party/zlib/` source-tree section links [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), includes [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and records [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) as zlib `configuration_table[10]` support data.
- Kept no decompiler-derived C++ bodies in zlib pages. The implementation uses blank formal C++ because these are stock third-party source/static-data embeddings owned by [UID:0000PC].
- Current MCP evidence was not re-opened or extended during implementation; the accepted report evidence from verified session `80de0a67` was incorporated. MCP/IDA process state was not managed.

## Validator Results

All scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

- `python .\tools\validator.py --mode file --file by-memory\0x00414820-0x004158aa.ZlibDeflateWorkers.md --uid-only --apply --queue-timeout 240` exited `0`, `ok: 1`; preserved UID `0000W4` and updated path mapping from the former broad page.
- `python .\tools\validator.py --mode file --file by-memory\0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md --apply --queue-timeout 240` exited `0`, `ok: 1`; assigned UID `00041N`.
- `python .\tools\validator.py --mode file --file by-memory\0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md --apply --queue-timeout 240` exited `0`, `ok: 1`; assigned UID `00041O`.
- Batch command `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` exited `0`, `ok: 1` for each of:
  - `by-memory\0x00414820-0x004158aa.ZlibDeflateWorkers.md`
  - `by-memory\0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`
  - `by-memory\0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`
  - `by-memory\0x004142c0-0x00419e56.ZlibCore.md`
  - `by-file\Zlib.md`
  - `by-meta\client_libraries.md`
  - `by-memory\0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md`
  - `by-memory\0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md`
  - `by-memory\0x0060d670-0x0066d000.ReadOnlyDataSection.md`
  - `by-memory\0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
  - `by-memory\0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`
  - `by-memory\0x00401000-0x0060d000.MasterCodeTextSection.md`
  - `by-memory\0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md`
  - `by-memory\-ignored.md`
- Validator batch note: `by-memory\-ignored.md` reported pre-existing unrelated `missing_ref_target 0003E6` for `by-memory/0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md`; the command still exited `0` with `ok: 1`.
- Validator-owned generated side effects occurred: `tools/validator.ini`, `project-level/-auto-completion-stats.md`, `auto-generated/NexusTK/third_party/zlib/Zlib.cpp`, `auto-generated/-ag-memory-coverage.md`, and validator backup folders under `tools/validator_autogen_backup/`.
- Supervisor verification correction command: `python .\tools\validator.py --mode file --file by-project-structure\proposed-source-tree.md --apply --queue-timeout 240` exited `0`, `ok: 1`; added reference-index entries for `00041N` and `00041O`, updated `project-level/-auto-completion-stats.md`, rebuilt `tools/validator.ini`, and left all `auto-generated/-ag-*-coverage.md` reports unchanged (`autogen_report_noop: 7`).

## Changed Files

Renamed/deleted:

- Removed old path `by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md` after preserving UID `0000W4` at the narrowed path.

Created:

- `by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md`
- `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`
- `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`

Updated target/support docs:

- `by-memory/0x004142c0-0x00419e56.ZlibCore.md`
- `by-file/Zlib.md`
- `by-meta/client_libraries.md`
- `by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md`
- `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md`
- `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
- `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`
- `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`
- `by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md`
- `by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md`
- `by-memory/-ignored.md`
- `by-project-structure/proposed-source-tree.md`
- `tools/leaser/Agents/Agent-B002/research/0000W4-ZlibDeflateAndTrees-source-quality.md`

No `-coverage-report.md` file was edited by B002.

## Implementation Tracking Checklist

- [x] Supervisor accepted the `0000W4` range split under Rule 26; implementation used the accepted disposition.
- [x] Renamed/re-ranged `0000W4` to `by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md`; validator preserved UID `0000W4` and path update succeeded.
- [x] Created `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md`; validator assigned UID `00041N`.
- [x] Preserved `0000W5` and `0000W6` as separate siblings; parent/Zlib/ignored docs reference them unchanged.
- [x] Updated `0000W3` parent child inventory, source-file map, setup/reset note, padding facts, support correction, and score rationale.
- [x] Updated `by-file/Zlib.md` with the source split, `configuration_table[10]` support child, and generated `Zlib.cpp` caveat.
- [x] Updated `by-meta/client_libraries.md` with narrowed `0000W4`, new `00041N` trees child, and new `00041O` configuration-table child.
- [x] Corrected `0x00632560-0x006325d8` as zlib `configuration_table[10]` with `0x004149b4` xref and worker function pointers.
- [x] Created `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`; validator assigned UID `00041O`.
- [x] Updated `0x00631850`, `0x00632560` runtime tail, `0x0060d670` read-only section, and `0x00631570` predecessor support pages so `0x00632560-0x006325d8` is a zlib carve-out rather than runtime-only data.
- [x] Updated stale active references in `0x004142c0-0x00414565`, `0x00401000-0x0060d000`, and `0x00671a74-0x00672eb4`.
- [x] Updated `by-memory/-ignored.md` with narrowed zlib rows, new trees child, configuration-table carve-out, unchanged siblings, and padding facts.
- [x] Did not edit any `-coverage-report.md` file; exact supervisor-owned coverage replacement/insert text with UIDs `00041N` and `00041O` is recorded above.
- [x] Ran scoped validators on every changed/created by-* / by-file / by-meta support doc; each command exited `0` with `ok: 1`.
- [x] Confirmed no decompiler-derived function-body C++ was emitted for stock zlib third-party source; formal `RECONSTRUCTION_CPP` blocks remain blank for the zlib pages.
- [x] Applied supervisor verification correction to `by-project-structure/proposed-source-tree.md`: replaced the removed `0x00414820-0x00417b97.ZlibDeflateAndTrees` W4 link with narrowed [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), added [UID:00041N][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and added [UID:00041O][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) for zlib `configuration_table[10]`; scoped validator exited `0` with `ok: 1`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000W4-ZlibDeflateAndTrees-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0000W4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
