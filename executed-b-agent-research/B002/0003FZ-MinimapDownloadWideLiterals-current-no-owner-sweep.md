** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Current No-Owner Sweep

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: valid no-owner-with-emitters pooled literal case. The item is reconstructable source-authored UTF-16LE data whose physical `.rdata` block is consumed by two proven source-use routes, but no single declaration/source owner is defensible.
- Required action: no target metadata change, no split, no merge, no reclassification, no IDA-safe rename, no new shared constants file, no coverage-report edit, no reconstruction C++.
- Confidence: high. I would keep the page at `COMPLETION:89` and `CONFIDENCE:93`; recommendation confidence is `92/100`.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, active 2026-06-14 remaining no-owner sweep, assigned to Agent-B002.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists the item as no-owner with `CANONICAL_OWNER:NONE`, emitters `0000JC`,`0000LE`, and first staged output route `auto-generated/NexusTK/network/FileDownloader.cpp`.
- Current target scores and metadata: `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B003/research/executed/0003FZ-MinimapDownloadWideLiterals-current-goal2-pass.md`.

## Executive Recommendation

Keep the current state unchanged. The target is a coherent minimap download literal group:

```text
0x0060d7f4-0x0060d7fc  L"000"
0x0060d7fc-0x0060d808  L"%03d"
0x0060d808-0x0060d818  L".mnm"
0x0060d818-0x0060d880  L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894  L"%s%s/%s%s"
0x0060d894-0x0060d8b8  L"Downloading : %d\n"
```

Current IDA MCP evidence proves two independent source-use routes:

- [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md): `FileDownloader::OnMessage` / `sub_41B110` dispatches message `10000` to `sub_41A750`, and `sub_41A750` references every target literal.
- [UID:0000LE][MiniMap](../../../by-file/MiniMap.md): `MiniMapDownloader::OnThreadTask` / `sub_453A00` dispatches message `0` to `sub_453AA0`, and `sub_453AA0` references every target literal. A raw MiniMap-neighborhood body at `0x00454e30-0x00455040` also references `.mnm`, the S3 minimap URL, and the progress string.

Neither route proves a single source declaration owner for the physical pooled `.rdata` block. `CANONICAL_OWNER:NONE` plus both proven emitters is therefore the correct by-structure model.

## Supervisor Active Recheck

- Supervisor assignment: recheck current Goal 2 no-owner memory target `0003FZ`; do not force a canonical owner just to remove `NONE`; justify current no-owner-with-emitters or recommend a defensible repair.
- Split repair required before final report: no. The range is already exact and coherent; the preceding child is [UID:0003FY] `0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString`, and the successor starts at [UID:0003G0] `0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals`.
- In-scope by-* repair required: no. The current target page, generated rows, and shared coverage row match the current evidence.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from generated-output routing. `CANONICAL_OWNER` must be the narrowest proven direct semantic owner, while `EMITTER_UIDS` records source output routes. It explicitly allows compiler/linker-pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while carrying multiple emitters when independent source-use contexts are proven.

`inference_research.md` treats address adjacency and consumer xrefs as evidence, not proof of original source-file declaration ownership. For this target, the xrefs prove source-use routes but do not prove whether the original source repeated identical literals in two source files, used an unmodeled shared declaration, or relied on compiler/linker pooling. No debug/source breadcrumb resolves that uncertainty.

Existing docs were treated as leads, not authority. I rechecked the current target page, parent container, sibling/successor literal pages, FileDownloader and MiniMap file roots, helper pages, proposed source tree, generated coverage rows, and live IDA/PE evidence.

## Evidence Standards Used

- IDA MCP current session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, image base `0x00400000`.
- IDA tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_component`, `get_bytes`, and `find_regex`.
- Raw PE evidence: section mapping, direct byte decode, exact block uniqueness, literal duplicate scan, absolute-VA/RVA/rel32 reference forms, and target/successor boundaries.
- Documentation evidence: target page, parent split-audit container, FileDownloader and MiniMap file roots, DownloadMinimapFile, MiniMapDownloader, sibling/successor literal pages, current generated coverage rows, shared coverage row, tracker row, and proposed source tree.

## IDA MCP Facts

Session health:

```text
status ok
module NexusTK.exe
input E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase 0x400000
auto_analysis_ready true
hexrays_ready true
strings_cache_ready true, size 2067
```

Function/range facts:

```text
0x0041a750 -> sub_41A750, size 0x2ae
0x0041b110 -> sub_41B110, size 0x70
0x0041b168 -> inside sub_41B110
0x00453a00 -> sub_453A00, size 0x2f
0x00453a16 -> inside sub_453A00
0x00453aa0 -> sub_453AA0, size 0x2af
0x00454e30 -> not a function
0x00454e6f -> not a function
0x00454e7b -> not a function
0x00454fcc -> not a function
0x00455050 -> sub_455050, size 0x3
0x00455060 -> sub_455060, size 0x68
0x004550d0 -> sub_4550D0, size 0x10f
```

Dispatcher decompilation facts:

- `sub_41B110` switches on the message id. Case `10000` calls `sub_41A750((int)Block)` at `0x0041b168` and then frees the block. Cases `10001` and `10002` call the item-shop helpers. Other messages delegate to `sub_596920`.
- `sub_453A00` delegates nonzero messages to `sub_596920`; message `0` calls `sub_453AA0(Block)` at `0x00453a16` and then frees the block.

Component comparison for `sub_41A750` and `sub_453AA0`:

- Both functions use the same WinINet/file callee family: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, `InternetCloseHandle`, `OutputDebugStringW`, `_memset`, `sub_41B9B0`, `unk_69BE34`, and `unk_69BE60`.
- The internal call graph has nodes `0x41a750` and `0x453aa0` with no edge between them.
- Shared globals/literals include `0x60d7f4`, `0x60d7f8`, `0x60d7fc`, `0x60d808`, `0x60d818`, `0x60d880`, and `0x60d894`, all accessed by both `sub_41A750` and `sub_453AA0`.

String/debug search facts:

- Search for minimap/update terms found minimap RTTI names and minimap/update strings, including `MiniMapDownloader`.
- Search for `.pdb`, `.cpp`, `.cxx`, `.h`, `RSDS`, and `NB10` found zero hits. No source/debug path or header/source filename breadcrumb was found.

## PE / Raw Evidence

Read-only scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

```text
Image base: 0x00400000
.text  0x00401000-0x0060c600, raw 0x400+0x20b600
.rdata 0x0060d000-0x0066c200, raw 0x20ba00+0x5f200
.data  0x0066d000-0x0069ce24, raw 0x26ac00+0xd800
.rsrc  0x0069d000-0x006b2e00, raw 0x278400+0x15e00
Target mapping: 0x0060d7f4-0x0060d8b8 -> .rdata raw 0x20c1f4-0x20c2b8, length 0xc4
Exact target block hits: one, at 0x0060d7f4
```

Decoded chunks:

```text
0x0060d7f4-0x0060d7fc  000
0x0060d7fc-0x0060d808  %03d
0x0060d808-0x0060d818  .mnm
0x0060d818-0x0060d880  https://s3.amazonaws.com/kru-downloads/tk/minimaps/
0x0060d880-0x0060d894  %s%s/%s%s
0x0060d894-0x0060d8b8  Downloading : %d\n
0x0060d8b8-0x0060d91c  https://secure.kru.com/itemshop/data/itemshop.ver
```

Literal uniqueness:

- The full `0xc4` target block occurs once.
- Long identifying target literals are unique: S3 minimap URL at `0x0060d818`, `%s%s/%s%s` at `0x0060d880`, and `Downloading : %d\n` at `0x0060d894`.
- Short literals have expected duplicates elsewhere: `000` also appears at `0x006107b2` and `0x00612840`; `%03d` also appears at `0x00612e82`; `.mnm` also appears at `0x006107fa`.

Reference-form scan:

| Target VA | Absolute VA hits | RVA hits | rel32 hits |
| --- | --- | --- | --- |
| `0x0060d7f4` | `0x0041a796`, `0x00453ae6` | none | none |
| `0x0060d7f8` | `0x0041a7a2`, `0x00453aef` | none | none |
| `0x0060d7fc` | `0x0041a7d3`, `0x00453b13` | none | none |
| `0x0060d808` | `0x0041a7e3`, `0x00453b23`, `0x00454e70` | none | none |
| `0x0060d818` | `0x0041a7f3`, `0x00453b33`, `0x00454e7c` | none | none |
| `0x0060d880` | `0x0041a7f8`, `0x00453b38` | none | none |
| `0x0060d894` | `0x0041a989`, `0x00453cd8`, `0x00454fcd` | none | none |
| `0x0060d8b8` | `0x0041aa65` | none | none |

The raw MiniMap-side body at `0x00454e30-0x00455040` is not an IDA function and has no incoming xrefs to its start, but the bytes include direct immediates for `0x0060d7e0`, `0x0060d808`, `0x0060d818`, and `0x0060d894`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | Pooled minimap download wide literals | `TRUE` | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` | `89/93` | Keep unchanged. |
| `0x0060d7e0-0x0060d7f4` | `0003FY` shared user-agent literal | Preceding shared downloader user-agent | `TRUE` | `NONE`; `0000JC,0000LE` | `88/93` | Confirms predecessor split. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` mixed literal container | Split-audit container for downloader/fitting-room literals | `FALSE` | none | `89/92` | Not an owner; exact children carry routing. |
| `0x0060d8b8-0x0060d94c` | `0003G0` cash-shop version literals | Successor item-shop version URL/progress child | `TRUE` | `0000JC`; `0000JC` | `86/91` | Confirms target end boundary. |
| `0x0041a750-0x0041a9fe` | `0002TR` DownloadMinimapFile | FileDownloader message `10000` minimap helper | `TRUE` | `0000JC`; `0000JC` | `80/84` | Low page score, but live IDA proves this source-use route. |
| `0x00453910-0x00453def` | `0000XN` MiniMapDownloader | MiniMapDownloader function island including `sub_453AA0` | `TRUE` | `0000LE`; `0000LE` | `86/90` | Supports MiniMap emitter. |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-neighborhood body using selected target literals | unknown | none | n/a | Evidence for MiniMap-side use only, not a separate emitter. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` | `L"000"` head used by both modeled helpers. |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` | overlapping/tail literal head used by both modeled helpers. |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` | `L"%03d"` used by both modeled helpers. |
| `0x0060d808` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f` | `L".mnm"` used by both modeled helpers plus raw MiniMap-side code. |
| `0x0060d818` | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b` | S3 minimap URL used by both modeled helpers plus raw MiniMap-side code. |
| `0x0060d880` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0` | URL/path format string used by both modeled helpers. |
| `0x0060d894` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc` | progress string used by both modeled helpers plus raw MiniMap-side code. |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` | successor item-shop literal child, not part of `0003FZ`. |
| `0x0041a750` | `0x0041b168` in `sub_41B110` | FileDownloader message `10000` route. |
| `0x0041b110` | data xref from `0x0060d7d4` | FileDownloader vtable/task-dispatch route. |
| `0x00453aa0` | `0x00453a16` in `sub_453A00`; extra raw code xref `0x004539f4` with no function | MiniMapDownloader task route plus raw-context caveat. |
| `0x00453a00` | data xref from `0x006106fc` | MiniMapDownloader vtable/task-dispatch route. |
| `0x00454e30` | no incoming xrefs | Raw body is consumer evidence only, not a separately routed source owner/emitter. |

## Documentation Evidence And IDA Status

- `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` already records the exact literal subranges, FileDownloader and MiniMapDownloader xrefs, raw MiniMap-side refs, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`. Current IDA/PE evidence confirms this state.
- [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md) is a valid file root at `85/88` with path `NexusTK/network/`. Its page documents `FileDownloader::OnMessage`, message `10000`, and the FileDownloader dispatcher. Current decompilation confirms that dispatch.
- [UID:0000LE][MiniMap](../../../by-file/MiniMap.md) is a valid file root at `85/86` with path `NexusTK/map/`. Its page documents `MiniMapDownloader` and keeps the final compact `MiniMap.cpp` versus focused `MiniMapDownloader.cpp` split open. Current decompilation confirms the task route.
- [UID:0002TR][DownloadMinimapFile](../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) is only `80/84`, but this pass directly proves the `sub_41A750` source-use route and the file root itself clears the route gate.
- [UID:0000XN][MiniMapDownloader](../../../by-memory/0x00453910-0x00453def.MiniMapDownloader.md) is `86/90` and assigned/emitted through MiniMap; its `sub_453AA0` helper matches the current route.
- [UID:0003AL][CashShopDownloaderLiterals](../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) is a reviewed non-emitting split-audit container and is not a semantic owner.
- `by-project-structure/proposed-source-tree.md` places `FileDownloader.cpp` under `network/` and MiniMap-related files under `map/`; it explicitly notes that `DownloadMinimapFile_41A750` downloads the same `.mnm` family but is reached through `FileDownloader::OnMessage` message `10000`.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`

- Evidence for: this is the exact by-structure case for pooled/shared source-authored literals. Both modeled helpers consume every target literal. The source-use routes are independent: FileDownloader message `10000` and MiniMapDownloader message `0`. Component analysis shows no internal call edge between `sub_41A750` and `sub_453AA0`. The raw PE scan found no hidden table, RVA form, rel32 route, source/debug path, or named declaration object.
- Evidence against: a shared source header/helper declaration is possible, but no current evidence proves it.
- Decision: accepted. Keep `NONE` with two emitters.

### 2. Canonical owner [UID:0000LE] MiniMap

- Evidence for: the string semantics are minimap-specific, MiniMapDownloader consumes the whole target block, and raw MiniMap-neighborhood code references `.mnm`, the S3 minimap URL, and progress text.
- Evidence against: FileDownloader message `10000` also consumes the whole target block through an independent dispatcher route. There is no proof that FileDownloader imports these literals from a MiniMap declaration.
- Decision: reject as canonical owner; retain as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] FileDownloader

- Evidence for: `sub_41A750` consumes every target literal and is directly dispatched by `FileDownloader::OnMessage`; nearby successor item-shop literal children are FileDownloader-owned.
- Evidence against: MiniMapDownloader also consumes every target literal, and the identifying strings are minimap feature data rather than generic downloader infrastructure. Assigning FileDownloader as owner would overclaim declaration ownership.
- Decision: reject as canonical owner; retain as emitter `0000JC`.

### 4. New shared `MinimapDownloadConstants` or helper file

- Evidence for: two near-clone helpers share one physical literal group, so a shared declaration is plausible.
- Evidence against: no binary evidence identifies a shared declaration object, header, pointer table, source path, or source module. By-structure explicitly says not to invent a standalone helper/global file solely to avoid `NONE`.
- Decision: reject. No new owner/file should be created.

### 5. Split the literal range further

- Evidence for: short literals have duplicate physical occurrences elsewhere, and only some target literals have raw MiniMap-neighborhood refs.
- Evidence against: the target block is unique as a complete `0xc4` sequence and behaviorally coherent. Both modeled helpers use every target literal. The predecessor and successor boundaries are already documented and byte-confirmed.
- Decision: reject. No split repair is needed.

### 6. Merge back into [UID:0003AL] `CashShopDownloaderLiterals`

- Evidence for: the target is physically inside that broader `.rdata` neighborhood.
- Evidence against: `0003AL` is a non-emitting split-audit container. Merging would lose the exact child route model and mix FileDownloader-only, MiniMap-shared, FittingRoom, and StartupWindow literal use.
- Decision: reject.

### 7. Reclassify as non-reconstructable compiler/linker data

- Evidence for: the physical pooling/layout is compiler/linker-produced.
- Evidence against: the strings are source-authored NexusTK literals that must surface through reconstructed source-use contexts. By-structure classifies this as source-declared/generated-binary, not non-reconstructable.
- Decision: reject. Keep `RECONSTRUCTABLE:TRUE`.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: `0003AL` is an audit container, `0x00454e30-0x00455040` is not a modeled callable source root, and a synthetic shared constants file would be invented rather than evidence-backed.
- Standalone, narrow, or broad source-file inference: not applicable because the best-supported result is no canonical owner with two emitters.

## Negative Evidence Summary

- Consumer xrefs prove source-use routes, not declaration ownership.
- Minimap semantics make `MiniMap` a strong emitter but do not override the independent FileDownloader consumer.
- FileDownloader dispatch makes `FileDownloader` a strong emitter but does not override the full MiniMapDownloader consumer and minimap-specific string content.
- The parent mixed literal block is a non-emitting container, not an owner.
- The raw MiniMap-side byte body has no incoming xrefs and is not an IDA-modeled function, so it strengthens MiniMap-side use but does not create a third emitter or a canonical owner.
- Raw PE scan found no RVA refs, rel32 refs, hidden table, source/debug strings, PDB/source path, or named shared declaration object.
- Address adjacency to FileDownloader-only item-shop strings is weak because the target’s complete xref set spans FileDownloader and MiniMap.

## Final Recommendation

- Exact changes applied or recommended: none to target by-* docs, generated reports, project-level docs, or shared coverage.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000JC,0000LE`.
- Exact items left no-owner/non-emitting and why: `0003FZ` remains no-owner but not non-emitting. No single declaration owner is proven, while both source-use emitters are proven.
- Reconstruction C++: keep blank. This literal page should surface through consuming source contexts; do not emit standalone C++ from the by-memory page.
- Split/merge/reclassification: none.

## Exact Supervisor-Owned Shared-Report Text

Required edit to `by-memory/-coverage-report.md`: none.

Retain the current row exactly:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002 post-migration and B001 second-pass reviews keep `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retain `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

Required edit to `auto-generated/-ag-memory-coverage.md`: none. This is generated output and currently matches the recommendation.

Retain the generated owner/emitter row:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` |  |
```

Retain the generated emitted no-owner route row:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000LE][MiniMap](by-file/MiniMap.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

Retain the generated non-emitting queue row:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | `0000JC`,`0000LE` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

## Follow-Up Actions

- Supervisor actions: accept the current no-owner-with-emitters state; no coverage-report application is required unless provenance wording is being refreshed.
- A-agent actions: optional future improvement of [UID:0002TR][DownloadMinimapFile](../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) above `85/85`; not required for this emitter decision because live IDA proves the FileDownloader route and the file root clears the route gate.
- Future B-agent actions: only investigate `0x00454e30-0x00455040` if separately assigned as a raw MiniMap-side helper/function-boundary target.

## Confidence

- Recommendation confidence: `92/100`.
- Score confidence: keep `COMPLETION:89`, `CONFIDENCE:93`.
- Remaining uncertainty: original source declaration style. The binary cannot distinguish conclusively between duplicated literals in two source files and an unproven shared header/helper declaration. The current no-owner-with-emitters model preserves that uncertainty while still routing proven source uses.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: no by-* target, generated, project-level, or coverage-report file was edited. Validator `--apply` was not required.
- Dry runs: none used.
- Unresolved validator warnings/errors: none observed in this assignment.

## Leases

- Initial report path did not exist, so the report placeholder was created first as instructed.
- `B002` then successfully leased `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-sweep.md` before substantive edits.
- The initial lease was released after final report write, then the file was briefly re-leased to make this lease-state correction and released again. Final chat status should confirm no active B002 lease.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-sweep.md`.
- Modified: none outside the B002 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B002/0003FZ-MinimapDownloadWideLiterals-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
