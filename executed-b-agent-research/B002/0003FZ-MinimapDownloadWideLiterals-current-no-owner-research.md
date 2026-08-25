** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: valid no-owner-with-emitters pooled literal case. The physical `.rdata` block is reconstructable source-authored UTF-16LE data used by two proven source-use routes, but no single declaration/source owner is defensible.
- Required action: no target metadata change, no emitter change, no split, no merge, no reclassification, no IDA-safe rename, no shared constants owner, no shared coverage-report edit, and no final reconstruction C++ recommendation.
- Confidence: high. Keep the page at `COMPLETION:89` and `CONFIDENCE:93`; recommendation confidence is `92/100`.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Required output report path: `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, current Goal 2 no-owner memory work, active row assigned to Agent-B002.
- Prior report reviewed first as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-current-no-owner-sweep.md`.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists the item as no-owner with `CANONICAL_OWNER:NONE`, emitters `0000JC`,`0000LE`, and staged source route beginning at `auto-generated/NexusTK/network/FileDownloader.cpp`.
- Current target scores and metadata: `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`.

## Executive Recommendation

Keep the current owner/emitter state unchanged. This target is one coherent minimap download literal group:

```text
0x0060d7f4-0x0060d7fc  L"000"
0x0060d7fc-0x0060d808  L"%03d"
0x0060d808-0x0060d818  L".mnm"
0x0060d818-0x0060d880  L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894  L"%s%s/%s%s"
0x0060d894-0x0060d8b8  L"Downloading : %d\n"
```

Current IDA MCP and PE evidence prove two independent source-use routes:

- [UID:0000JC] `by-file/FileDownloader.md`: `FileDownloader::OnMessage` / `sub_41B110` dispatches message `10000` to `sub_41A750`, and `sub_41A750` references every target literal.
- [UID:0000LE] `by-file/MiniMap.md`: `MiniMapDownloader::OnThreadTask` / `sub_453A00` dispatches message `0` to `sub_453AA0`, and `sub_453AA0` references every target literal. A raw MiniMap-neighborhood body at `0x00454e30-0x00455040` also references `.mnm`, the S3 minimap URL, and the progress string.

Neither route proves that the original source declared the physical literal block in one source owner. The current state, `CANONICAL_OWNER:NONE` plus `EMITTER_UIDS:0000JC,0000LE`, is the most accurate by-structure representation.

## Supervisor Active Recheck

- Supervisor instruction: perform a fresh current-state review of [UID:0003FZ] and determine whether it should remain no-owner with current multi-emitter routing, gain a canonical owner, change emitters, split/merge/reclassify, or receive supporting documentation repair.
- Split repair required before report: no. The range is exact and coherent. Predecessor [UID:0003FY] ends at `0x0060d7f4`; successor [UID:0003G0] begins at `0x0060d8b8`.
- Direct in-scope by-* repair required: no. Current target page, generated rows, and shared coverage row match the current IDA/PE evidence.
- Shared coverage-report handling: no direct edit made; exact row to retain is included below.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from output routing. `CANONICAL_OWNER` requires a defensible direct semantic owner. `EMITTER_UIDS` records source output routes and may contain multiple emitters. It explicitly allows compiler/linker-pooled string literals or shared constants to remain `CANONICAL_OWNER:NONE` while carrying multiple emitters when independent source-use contexts are proven.

`inference_research.md` treats consumer xrefs as evidence, not automatic declaration ownership proof. For this target, xrefs prove that FileDownloader and MiniMap both need the literals in source output, but they do not prove whether the original source duplicated the literals in two source files, used a shared header/static declaration, or relied on linker/string pooling. No source/debug breadcrumb resolves that question.

Existing docs and prior reports were treated as leads, then checked against the current target page, parent/sibling/successor pages, FileDownloader and MiniMap file roots, helper pages, current generated rows, live IDA MCP evidence, and a fresh PE-level byte/reference scan.

## Evidence Standards Used

- IDA MCP current session `b001_0002bd` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- IDA MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `decompile`, and `analyze_component`.
- Raw PE evidence: section mapping, byte decoding, exact block uniqueness, duplicate literal search, absolute-VA/RVA/rel32 reference forms, predecessor/successor boundary confirmation, and source/debug marker scan.
- Documentation evidence: target page, prior report, parent split-audit container [UID:0003AL], predecessor [UID:0003FY], successor [UID:0003G0], [UID:0000JC] FileDownloader, [UID:0000LE] MiniMap, [UID:0002TR] DownloadMinimapFile, [UID:0000XN] MiniMapDownloader, [UID:0001SF] DownloaderMessageIds, generated memory coverage rows, shared coverage row, and proposed source tree.

Two attempted MCP calls used stale parameter names and returned schema errors; they were retried with the current `addr` / `addrs` schemas. The failed calls are not used as evidence.

## IDA MCP Facts

Session health:

```text
status: ok
module: NexusTK.exe
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
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
0x00454e52 -> not a function
0x00454e6f -> not a function
0x00454e7b -> not a function
0x00454fcc -> not a function
0x00455040 -> not a function
0x00455050 -> sub_455050, size 0x3
0x00455060 -> sub_455060, size 0x68
0x004550d0 -> sub_4550D0, size 0x10f
0x0060d7f4 -> not a function
0x0060d8b8 -> not a function
```

Dispatcher decompilation facts:

```text
sub_41B110:
  case 10000: sub_41A750((int)Block); sub_5C7526(Block);
  case 10001: sub_41AE20(Block);
  case 10002: sub_41AA00((int)Block); (**Block)(Block, 1);
  default: sub_596920(a1, Block, a3);

sub_453A00:
  if (a1) sub_596920(a1, Block, a3);
  else { sub_453AA0(Block); sub_5C7526(Block); }
```

Component comparison for `sub_41A750` and `sub_453AA0`:

- Both have the same WinINet/file callee family: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, `InternetCloseHandle`, `OutputDebugStringW`, `sub_41B9B0`, `unk_69BE34`, `unk_69BE60`, `_memset`, `__alloca_probe`, and the security-check helper.
- Internal call graph nodes are `0x41a750` and `0x453aa0` with no edge between them.
- Shared globals/literals accessed by both helpers include `0x60d7f4`, `0x60d7f8`, `0x60d7fc`, `0x60d808`, `0x60d818`, `0x60d880`, and `0x60d894`.

Xref facts:

| Address | Xrefs | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` | `L"000"` used by both modeled helpers |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` | overlapping/tail literal head used by both modeled helpers |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` | `L"%03d"` used by both modeled helpers |
| `0x0060d808` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f` | `L".mnm"` used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d818` | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b` | S3 minimap URL used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d880` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0` | format string used by both modeled helpers |
| `0x0060d894` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc` | progress string used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` | successor item-shop literal child, not part of this target |
| `0x0041a750` | caller `0x0041b168` in `sub_41B110` | FileDownloader message `10000` route |
| `0x0041b110` | data xref from `0x0060d7d4` | FileDownloader vtable/dispatch route |
| `0x00453a00` | data xref from `0x006106fc` | MiniMapDownloader vtable/task route |
| `0x00453aa0` | code xref `0x00453a16` in `sub_453A00`; raw extra xref `0x004539f4` | modeled MiniMapDownloader route plus raw-context caveat |
| `0x00454e30` | 0 xrefs | raw body has literal refs but no proven incoming route |

## PE / Raw Evidence

Read-only scan path:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
image_base: 0x00400000
.text:  0x00401000 raw 0x400 size 0x20b600
.rdata: 0x0060d000 raw 0x20ba00 size 0x5f200
.data:  0x0066d000 raw 0x26ac00 size 0xd800
.rsrc:  0x0069d000 raw 0x278400 size 0x15e00
target: 0x0060d7f4-0x0060d8b8 -> raw 0x20c1f4-0x20c2b8, length 0xc4
```

Exact range and decoded chunks:

```text
exact target block hits: 1, at raw 0x20c1f4 / VA 0x0060d7f4

0x0060d7f4-0x0060d7fc: "000"
0x0060d7fc-0x0060d808: "%03d"
0x0060d808-0x0060d818: ".mnm"
0x0060d818-0x0060d880: "https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894: "%s%s/%s%s"
0x0060d894-0x0060d8b8: "Downloading : %d\n"
0x0060d8b8-0x0060d91c: "https://secure.kru.com/itemshop/data/itemshop.ver"
```

Literal duplicate scan:

```text
"000": 3 hits at 0x0060d7f4, 0x006107b2, 0x00612840
"%03d": 2 hits at 0x0060d7fc, 0x00612e82
".mnm": 2 hits at 0x0060d808, 0x006107fa
S3 minimap URL: 1 hit at 0x0060d818
"%s%s/%s%s": 1 hit at 0x0060d880
"Downloading : %d\n": 1 hit at 0x0060d894
```

Reference-form scan:

| Target VA | Absolute VA hits | RVA hits | rel32 hits |
| --- | --- | --- | --- |
| `0x0060d7e0` | `0x0041a774`, `0x0041aa3c`, `0x0041ae5c`, `0x00453ac4`, `0x00454e53` | none | none |
| `0x0060d7f4` | `0x0041a796`, `0x00453ae6` | none | none |
| `0x0060d7f8` | `0x0041a7a2`, `0x00453aef` | none | none |
| `0x0060d7fc` | `0x0041a7d3`, `0x00453b13` | none | none |
| `0x0060d808` | `0x0041a7e3`, `0x00453b23`, `0x00454e70` | none | none |
| `0x0060d818` | `0x0041a7f3`, `0x00453b33`, `0x00454e7c` | none | none |
| `0x0060d880` | `0x0041a7f8`, `0x00453b38` | none | none |
| `0x0060d894` | `0x0041a989`, `0x00453cd8`, `0x00454fcd` | none | none |
| `0x0060d8b8` | `0x0041aa65` | none | none |

Source/debug marker scan:

```text
RSDS: 0
NB10: 0
.pdb/.PDB: 0
.cpp/.CPP/.cxx: 0
```

No source/debug path or named shared declaration object was found in the executable.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | `0003AL` `CashShopDownloaderLiterals` | Reviewed mixed literal split-audit container | `FALSE` | `NONE` / blank emitters | `89/92` | Not a source owner; exact children carry routing |
| `0x0060d7e0-0x0060d7f4` | `0003FY` `SharedDownloaderUserAgentWideString` | Shared `L"HTTPTEST"` user-agent | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `88/93` | Predecessor confirms shared-pool model |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | Minimap download literal group | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `89/93` | Keep unchanged |
| `0x0060d8b8-0x0060d94c` | `0003G0` `CashShopVersionDownloadWideLiterals` | Item-shop version URL/progress literals | `TRUE` | `0000JC`; emitter `0000JC` | `86/91` | Successor confirms target end boundary |
| `0x0041a750-0x0041a9fe` | `0002TR` `DownloadMinimapFile` | FileDownloader message `10000` minimap helper | `TRUE` | `0000JC`; emitter `0000JC` | `80/84` | Current page score is lower, but this pass directly proves source use |
| `0x00453910-0x00453def` | `0000XN` `MiniMapDownloader` | MiniMapDownloader worker and direct minimap helper | `TRUE` | `0000LE`; emitter `0000LE` | `86/90` | Supports MiniMap emitter |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-neighborhood helper body | unknown | none | n/a | Literal consumer evidence only; no incoming route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794`, `0x00453ae4` | `L"000"` used by FileDownloader and MiniMapDownloader modeled helpers |
| `0x0060d7fc` | `0x0041a7d2`, `0x00453b12` | `L"%03d"` used by both modeled helpers |
| `0x0060d808` | `0x0041a7e2`, `0x00453b22`, raw `0x00454e6f` | `.mnm` used by both modeled helpers and raw MiniMap-side body |
| `0x0060d818` | `0x0041a7f2`, `0x00453b32`, raw `0x00454e7b` | S3 minimap URL used by both modeled helpers and raw MiniMap-side body |
| `0x0060d880` | `0x0041a7f7`, `0x00453b37` | URL/path format used by both modeled helpers |
| `0x0060d894` | `0x0041a988`, `0x00453cd7`, raw `0x00454fcc` | Progress string used by both modeled helpers and raw MiniMap-side body |
| `0x0041b168 -> 0x0041a750` | FileDownloader `sub_41B110` case `10000` | Proven FileDownloader source-use route |
| `0x00453a16 -> 0x00453aa0` | MiniMapDownloader `sub_453A00` case `0` | Proven MiniMap source-use route |
| `0x00454e30` | no incoming xrefs | Raw body cannot be used as a separate owner/emitter yet |

## Documentation Evidence And IDA Status

- Target page `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`, exact literal subranges, modeled xrefs, raw MiniMap-side refs, and no single declaration owner. Current IDA/PE evidence confirms that state.
- Parent [UID:0003AL] `CashShopDownloaderLiterals` is correctly a `RECONSTRUCTABLE:FALSE` split-audit container, not an owner.
- Predecessor [UID:0003FY] uses the same ownerless/multi-emitter model for the shared downloader user-agent. Its xrefs span FileDownloader and MiniMap, consistent with this target.
- Successor [UID:0003G0] is FileDownloader-owned because its xrefs are item-shop version/catalog helpers, not MiniMap. The `0x0060d8b8` boundary is byte-confirmed by current PE decoding and one xref from `sub_41AA00`.
- [UID:0000JC] `FileDownloader` is a valid file root at `85/88` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`; current decompilation confirms message `10000` dispatch to `sub_41A750`.
- [UID:0000LE] `MiniMap` is a valid file root at `85/86` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`; current decompilation confirms the `MiniMapDownloader` task route to `sub_453AA0`.
- [UID:0002TR] `DownloadMinimapFile` remains only `80/84`, but this current pass directly verifies the FileDownloader route and all target literal xrefs. The emitter route is through the valid file root `0000JC`, not dependent on raising `0002TR` in this assignment.
- [UID:0001SF] `DownloaderMessageIds` documents FileDownloader message `10000` for `DownloadMinimapFile_41A750`; current decompilation confirms that message path.
- `by-project-structure/proposed-source-tree.md` keeps FileDownloader under `network/` and MiniMap under `map/`, and notes that `DownloadMinimapFile_41A750` downloads the same `.mnm` family but is reached through FileDownloader message `10000`.

No stale filename, stale range, stale label, split/merge issue, owner/emitter mismatch, or supporting documentation repair was found.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`

- Evidence for: both modeled helpers consume every target literal; the helpers are reached through independent dispatchers; `analyze_component` shows no internal call edge between `sub_41A750` and `sub_453AA0`; long target literals are unique in the PE; raw MiniMap-side code adds more MiniMap-side use without replacing the FileDownloader route; by-structure explicitly supports pooled/shared literal pages with no canonical owner and multiple emitters.
- Evidence against: a named shared declaration or header could have existed in source.
- Decision: accepted. Current evidence proves source-use emitters, not one declaration owner.

### 2. Canonical owner [UID:0000LE] MiniMap

- Evidence for: the literals are minimap-specific; `sub_453AA0` is MiniMapDownloader-owned; raw MiniMap-neighborhood body references `.mnm`, S3 URL, and progress text.
- Evidence against: FileDownloader message `10000` also consumes the full target group through a valid independent route. No evidence proves FileDownloader imported these literals from a MiniMap declaration.
- Decision: rejected as canonical owner; retained as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] FileDownloader

- Evidence for: `sub_41A750` consumes every target literal and is dispatched by FileDownloader message `10000`; FileDownloader is a valid generated file root.
- Evidence against: MiniMapDownloader also consumes every target literal, and the identifying strings are minimap feature data. Assigning FileDownloader as canonical owner would overclaim declaration ownership for MiniMap-side source uses.
- Decision: rejected as canonical owner; retained as emitter `0000JC`.

### 4. New shared constants/helper owner

- Evidence for: two near-clone download helpers share one physical literal block, so a shared declaration is possible.
- Evidence against: PE scan found no source/debug marker or named declaration object; IDA found no shared table/object owner; by-structure warns not to invent a standalone helper/global file solely to avoid `NONE`.
- Decision: rejected.

### 5. Split the range

- Evidence for: short literals have duplicates elsewhere; only `.mnm`, S3 URL, and progress text have raw MiniMap-neighborhood refs.
- Evidence against: the complete `0xc4` block is unique and coherent; both modeled helpers use the full target group; predecessor and successor boundaries are already exact.
- Decision: rejected. No split repair is warranted.

### 6. Merge into [UID:0003AL] parent container

- Evidence for: the target sits inside that physical `.rdata` container.
- Evidence against: [UID:0003AL] is a non-emitting split-audit container spanning multiple ownership outcomes. Merging would lose correct exact-child ownership/emitter routing.
- Decision: rejected.

### 7. Reclassify non-reconstructable

- Evidence for: the physical pooled layout is compiler/linker-produced.
- Evidence against: the string contents are source-authored NexusTK literals that must surface through reconstructed source contexts.
- Decision: rejected. Keep `RECONSTRUCTABLE:TRUE`.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: [UID:0003AL] is an audit container; raw `0x00454e30-0x00455040` lacks an incoming route; a synthetic shared constants owner would be invented rather than evidence-backed.
- Standalone, narrow, or broad source-file inference: not applicable. The best-supported model is no canonical owner with two proven emitters.

## Negative Evidence Summary

- Consumer xrefs prove source-use contexts, not source declaration ownership.
- FileDownloader and MiniMap each overclaim if made canonical owner for the whole physical block.
- The parent mixed literal page is a container, not a source owner.
- Raw MiniMap-side references are not inside a modeled function and have no incoming xrefs to `0x00454e30`; they do not create a third emitter.
- PE scan found no RVA refs, rel32 refs, source/debug marker, PDB path, source file path, or named shared declaration object.
- Short-literal duplicates elsewhere do not justify splitting this target because the full block and the long identifying literals are unique and both modeled helpers consume the whole group.

## Final Recommendation

- Exact changes applied or recommended: create this research report only; no by-* target edit recommended.
- Exact parent assignments applied or recommended: retain `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: retain `EMITTER_UIDS:0000JC,0000LE`.
- Exact items left no-owner/non-emitting and why: [UID:0003FZ] remains no-owner but not non-emitting. No single declaration owner is proven, while two source-use emitters are proven.
- Reconstruction C++: no final C++ is entered or recommended. Although the target is `RECONSTRUCTABLE:TRUE`, has nonblank emitters, and averages above 85, the remaining source-declaration style for this pooled literal block is unresolved. The target should surface through consuming source contexts, not as a standalone by-memory C++ block.
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

Retain the generated no-owner/non-emitting queue row:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | `0000JC`,`0000LE` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

Optional tracker row replacement for supervisor application:

```text
| `0003FZ` | 0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md` | `Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-current-no-owner-sweep.md` |
```

## Follow-Up Actions

- Supervisor actions: mark the active tracker row complete-no-change if desired. No shared coverage-report edit is needed.
- A-agent actions: optional future improvement of [UID:0002TR] `DownloadMinimapFile` above `85/85`; not required for this emitter decision because the current pass directly proves the FileDownloader route and the file root clears the source-output route gate.
- B002 future research actions: only investigate raw `0x00454e30-0x00455040` if separately assigned as a raw MiniMap-side helper/function-boundary target.

## Confidence

- Recommendation confidence: `92/100`.
- Before/after scores: before `COMPLETION:89`, `CONFIDENCE:93`; after unchanged at `89/93`.
- Remaining uncertainty: original source declaration style. The binary does not prove whether the original source duplicated literals in two translation units, used a shared header/static declaration, or was pooled by the compiler/linker. The current no-owner-with-emitters model preserves that uncertainty while still routing proven source uses.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: no by-* target, generated, project-level, or coverage-report file was edited. Validator `--apply` was not required.
- Dry runs: none used.
- Unresolved validator warnings/errors: none introduced by this assignment.

## Lease State

- No by-* files were edited, so no by-* lease was required or acquired.
- Per `goal.md`, Agent-B002 research reports inside the assigned agent folder do not require a lease.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md`.
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B002/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
