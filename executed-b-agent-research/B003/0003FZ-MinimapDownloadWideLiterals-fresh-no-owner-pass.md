** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Fresh No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` unchanged.
- Final disposition: valid pooled/shared literal case with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000LE`.
- Required action: no owner change, no emitter change, no split, no merge, no reclassification, no IDA-safe rename repair, no target edit, and no shared coverage-report edit.
- Confidence: high. Retain `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`.

This is no-owner but not non-emitting. Current IDA MCP and raw PE evidence prove the literal group is used by two independent source-use routes: [UID:0000JC] `FileDownloader` through `sub_41A750`, and [UID:0000LE] `MiniMap` through `sub_453AA0` plus raw MiniMap-neighborhood references. Neither route proves a single declaration/source owner for the whole physical pooled literal block.

## Supporting Research

## Target

- Target UID: `0003FZ`
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner/multi-emitter rows.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` active 2026-06-14 row for Agent-B003.
- Prior report reviewed as evidence only: `tools/leaser/Agents/Agent-B001/research/executed/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md`
- Current scores and routing: `89/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.

## Executive Recommendation

Keep the page as a reconstructable source-literal group with no canonical owner and two emitters. The block contains:

```text
0x0060d7f4-0x0060d7fc  L"000"
0x0060d7fc-0x0060d808  L"%03d"
0x0060d808-0x0060d818  L".mnm"
0x0060d818-0x0060d880  L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894  L"%s%s/%s%s"
0x0060d894-0x0060d8b8  L"Downloading : %d\n"
```

The source-use routes are proved, but declaration ownership is not. The best current model is therefore:

```text
CANONICAL_OWNER:NONE
EMITTER_UIDS:0000JC,0000LE
```

## Supervisor Active Recheck

The current assignment asks for a fresh Goal 2 no-owner memory pass on `0003FZ`, independently rechecking current documentation and IDA MCP evidence from scratch. No split repair was required before this report because the range is already an exact child of [UID:0003AL] `CashShopDownloaderLiterals` and current bytes/xrefs confirm the half-open boundary `0x0060d7f4-0x0060d8b8`.

No by-* file was edited. The required output is this root Agent-B003 research report.

## Inference Research Guidance Check

`by-structure.md` distinguishes semantic ownership from output routing:

- `CANONICAL_OWNER` must be the direct semantic source/declaration owner.
- `EMITTER_UIDS` is output routing and can contain multiple routes.
- Compiler/linker-pooled literals and shared constants can legitimately remain `CANONICAL_OWNER:NONE` while using multiple proven source-use emitters.

`inference_research.md` warns that consumer xrefs and address adjacency are evidence, not proof of original source-file ownership. That matters here: the two modeled helpers and the raw MiniMap-side body prove source use, but do not prove whether the original source duplicated these literals, declared them in one translation unit, or used a shared header/static constant.

## Evidence Standards Used

Evidence checked:

- Current target page, generated memory coverage rows, shared coverage row, tracker row, related by-file pages, related by-memory consumer pages, container/sibling literal pages, and proposed source tree.
- Live IDA MCP session `a001_goal2_class_batch`: server health, function lookup, string reads, bytes, xrefs, decompilation, callees, component comparison, entity names, and signature generation.
- Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: section layout, file hashes, UTF-16LE decoding, exact block uniqueness, VA/RVA reference counts, and neighboring boundaries.
- Negative evidence for a shared constants owner, stale range, stale label, dead-end emitters, and raw-helper ownership.

## Current Metadata Before And After

Before:

```text
UID:0003FZ
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

After recommendation:

```text
UID:0003FZ
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Score impact: no score change. The page already records exact literal subranges, xrefs, byte evidence, raw-helper caveats, source-use emitters, and the direct-owner blocker.

## IDA MCP Facts

Current IDA MCP session:

```text
session: a001_goal2_class_batch
module: NexusTK.exe
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Function lookup:

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
0x00455040 -> not a function
0x00455050 -> sub_455050, size 0x3
0x0060d7f4 -> not a function
0x0060d8b8 -> not a function
```

IDA `get_string` confirms the target and boundaries:

```text
0x0060d7e0: "H" through IDA's narrow-at-wide head view; raw bytes decode as L"HTTPTEST"
0x0060d7f4: "0"
0x0060d7fc: "%03d"
0x0060d808: ".mnm"
0x0060d818: "https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880: "%s%s/%s%s"
0x0060d894: "Downloading : %d\n"
0x0060d8b8: "https://secure.kru.com/itemshop/data/itemshop.ver"
0x0060d91c: "Downloading : %d / %d\n"
0x0060d94c: "version"
0x0060d958: "https://secure.kru.com/itemshop/data/itemshop.json"
```

IDA names around the block:

```text
0x60d7e0 szAgent
0x60d7e4 aTptest
0x60d7fc a03d
0x60d808 aMnm
0x60d818 aHttpsS3Amazona
0x60d880 aSSSS
0x60d894 aDownloadingD
0x60d8b8 szUrl
0x60d91c aDownloadingDD
0x60d94c aVersion
0x60d958 aHttpsSecureKru_0
0x60d9c4 ??_7FittingRoomDownloadControlPane@@6B@
```

The `0x60d9c4` vtable name after the successor literals supports the existing broader-container split: this target must not merge beyond the item-shop/catalog literal children.

## Direct Xref / Caller Inventory

| Address / item | Current IDA xrefs | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` | `L"000"` used by both modeled minimap download helpers |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` | Overlapped/tail dword used by both modeled helpers |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` | `L"%03d"` used by both modeled helpers |
| `0x0060d808` | `0x0041a7e2`; `0x00453b22`; raw `0x00454e6f` | `.mnm` used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d818` | `0x0041a7f2`; `0x00453b32`; raw `0x00454e7b` | S3 minimap URL used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d880` | `0x0041a7f7`; `0x00453b37` | URL format used by both modeled helpers |
| `0x0060d894` | `0x0041a988`; `0x00453cd7`; raw `0x00454fcc` | Progress text used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` | Successor item-shop version literal, not part of target |
| `0x0041a750` | code xref `0x0041b168` in `sub_41B110` | FileDownloader message `10000` route |
| `0x00453aa0` | code xref `0x00453a16` in `sub_453A00`; raw `0x004539f4` with no containing function | MiniMapDownloader route plus raw-context caveat |
| `0x00454e30` | zero xrefs to raw start | Raw body is not a separate source owner/emitter yet |

## Decompilation And Component Facts

`sub_41B110` is the FileDownloader dispatch path. Hex-Rays currently shows:

```text
case 10000:
  sub_41A750((int)Block);
  sub_5C7526(Block);
case 10001:
  sub_41AE20(Block);
case 10002:
  sub_41AA00((int)Block);
default:
  sub_596920(a1, Block, a3);
```

`sub_453A00` is the MiniMapDownloader task path. Hex-Rays currently shows:

```text
if (a1)
  sub_596920(a1, Block, a3);
else {
  sub_453AA0(Block);
  sub_5C7526(Block);
}
```

`sub_41A750` and `sub_453AA0` have matching minimap-download behavior:

- open WinINet session using the shared predecessor user-agent literal.
- seed/formats a three-digit minimap directory using `L"000"` and `L"%03d"`.
- build an S3 `.mnm` URL with the URL prefix and `L"%s%s/%s%s"`.
- open the URL, set Internet options, query HTTP status, stream bytes to a local file, emit `L"Downloading : %d\n"`, and delete partial output on failed completion.

`callees` and `analyze_component` confirmed matching API/helper sets for both modeled helpers: `InternetOpenW`, `InternetOpenUrlW`, `InternetSetOptionW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `OutputDebugStringW`, `CloseHandle`, `InternetCloseHandle`, `sub_41B9B0`, `unk_69BE34`, `unk_69BE60`, `_memset`, `__alloca_probe`, and security-cookie support.

`analyze_component` also reported:

```text
internal_call_graph nodes: 0x41a750, 0x453aa0
internal_call_graph edges: none
shared_globals: szAgent, 0x60d7f4, 0x60d7f8, a03d, aMnm,
                aHttpsS3Amazona, aSSSS, aDownloadingD
```

This is important negative evidence. The two modeled helpers are sibling consumers of a shared literal block; neither one calls or owns the other.

## PE / Raw Evidence

Raw PE checked:

```text
file: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
md5: 4247e04e20b65d6414c7238aa8ff5515
sha256: 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632
imagebase: 0x400000
.text  rva=0x001000 vsize=0x20b4ac raw=0x000400 raw_size=0x20b600
.rdata rva=0x20d000 vsize=0x05f0be raw=0x20ba00 raw_size=0x05f200
.data  rva=0x26d000 vsize=0x02fe24 raw=0x26ac00 raw_size=0x00d800
.rsrc  rva=0x29d000 vsize=0x015c38 raw=0x278400 raw_size=0x015e00
```

Raw UTF-16LE decode:

```text
0x0060d7e0-0x0060d7f4  "HTTPTEST" predecessor, not part of target
0x0060d7f4-0x0060d7fc  "000"
0x0060d7fc-0x0060d808  "%03d"
0x0060d808-0x0060d818  ".mnm"
0x0060d818-0x0060d880  "https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894  "%s%s/%s%s"
0x0060d894-0x0060d8b8  "Downloading : %d\n"
0x0060d8b8-0x0060d94c  successor item-shop version/progress literals
```

The exact `0x0060d7f4-0x0060d8b8` target block occurs once in the file, at raw `0x20c1f4` / VA `0x0060d7f4`.

Raw absolute-VA pointer/immediate scan:

```text
0x0060d7f4: 2 VA32 hits, at 0x0041a796 and 0x00453ae6
0x0060d7f8: 2 VA32 hits, at 0x0041a7a2 and 0x00453aef
0x0060d7fc: 2 VA32 hits, at 0x0041a7d3 and 0x00453b13
0x0060d808: 3 VA32 hits, at 0x0041a7e3, 0x00453b23, 0x00454e70
0x0060d818: 3 VA32 hits, at 0x0041a7f3, 0x00453b33, 0x00454e7c
0x0060d880: 2 VA32 hits, at 0x0041a7f8 and 0x00453b38
0x0060d894: 3 VA32 hits, at 0x0041a989, 0x00453cd8, 0x00454fcd
0x0060d8b8: 1 VA32 hit, at 0x0041aa65
```

RVA32 scan returned zero hits for all target heads. This matches a PE built with absolute imagebase-relative immediates in code, not RVA table references.

Raw literal duplicate scan:

```text
target block: 1 occurrence
S3 minimap URL: 1 occurrence
%s%s/%s%s: 1 occurrence
Downloading : %d\n: 1 occurrence
.mnm: 2 occurrences
%03d: 2 occurrences
000: 3 occurrences
```

The shorter literals have duplicates elsewhere, but the complete target block and the semantically important URL/format/progress literals are unique. This supports keeping the target block together rather than splitting every short literal into independent pages.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `CashShopDownloaderLiterals` | Mixed downloader literal split-audit container | `FALSE` | `NONE` / blank | `89/92` | Keep as container |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY] `SharedDownloaderUserAgentWideString` | Shared `L"HTTPTEST"` user-agent | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `88/93` | Adjacent shared-literal precedent |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ] target | Minimap download wide literals | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `89/93` | Keep unchanged |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `CashShopVersionDownloadWideLiterals` | FileDownloader item-shop version URL/progress | `TRUE` | owner/emitter `0000JC` | `86/91` | Confirms successor boundary |
| `0x0041a750-0x0041a9fe` | [UID:0002TR] `DownloadMinimapFile` | FileDownloader message `10000` helper | `TRUE` | owner/emitter `0000JC` | `80/84` | Consumer evidence; emitter is valid file root `0000JC` |
| `0x00453910-0x00453def` | [UID:0000XN] `MiniMapDownloader` | MiniMapDownloader worker/helper cluster | `TRUE` | owner/emitter `0000LE` | `86/90` | Consumer evidence; valid MiniMap route |
| `0x00454e30-0x00455040` | no exact current page | Raw MiniMap-neighborhood download-like body | unknown | none | n/a | Evidence of MiniMap-side use, not a separate emitter yet |

## Documentation Evidence And IDA Status

Current target page status:

- Documents exact target range and literal subranges.
- Documents current `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000LE`.
- Lists representative xrefs to FileDownloader and MiniMapDownloader paths.
- Records raw MiniMap-side references at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`.

IDA status: confirmed by current session.

Related docs:

- [UID:0000JC] `by-file/FileDownloader.md` is a valid source file root under `NexusTK/network/`; it owns the `FileDownloader` dispatch and message `10000` route.
- [UID:0000LE] `by-file/MiniMap.md` is a valid source file root under `NexusTK/map/`; it owns the MiniMapDownloader worker family.
- [UID:0002TR] `DownloadMinimapFile` remains below `85/85` as an individual function page, but the direct source-use evidence was reverified live and the emitter UID is the file root `0000JC`, which is `85/88`.
- [UID:0000XN] `MiniMapDownloader` is `86/90` and routes through `0000LE`.
- [UID:0003AL] `CashShopDownloaderLiterals` is correctly `RECONSTRUCTABLE:FALSE` because it is a split-audit container whose exact children carry the real routing decisions.
- [UID:0003FY] is a neighboring shared-literal precedent using the same no-owner/two-emitter model.
- [UID:0003G0] is a neighboring FileDownloader-only child starting exactly at `0x0060d8b8`.
- `by-project-structure/proposed-source-tree.md` places `FileDownloader.cpp` under `network/` and `MiniMap.cpp` under `map/`, matching the two emitter roots.

Generated route evidence:

```markdown
| [UID:0000JC][FileDownloader](by-file/FileDownloader.md) | emits | `FILE` |  |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-file/FileDownloader.md` | by-file generated root |
| [UID:0000LE][MiniMap](by-file/MiniMap.md) | emits | `FILE` |  |  | no | `auto-generated/NexusTK/map/MiniMap.cpp` | `by-file/MiniMap.md` | by-file generated root |
```

Both generated files exist:

```text
auto-generated/NexusTK/network/FileDownloader.cpp
auto-generated/NexusTK/map/MiniMap.cpp
```

Both are currently zero-length, and `rg` found no `0003FZ`, `0x0060d7f4`, S3 URL, or progress literal annotation in them. That is expected because the target's `RECONSTRUCTION_CPP` block is blank. The emitter route exists structurally; this page is not emitting source text yet.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- Both modeled helpers consume every target literal head needed to build the same minimap URL/progress behavior.
- `sub_41A750` is called only from `FileDownloader::OnMessage` message `10000`.
- `sub_453AA0` is called by `MiniMapDownloader::OnThreadTask` message `0`.
- `analyze_component` shows matching callee sets and shared literals, but no call edge between the helpers.
- Raw refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc` strengthen the MiniMap side without eliminating the FileDownloader route.
- Both emitters resolve to valid by-file generated roots.
- By-structure explicitly allows pooled/shared literal data to be no-owner with multiple source-use emitters when no single declaration owner is proven.

Evidence against:

- Original source could have had a shared constant declaration, but no debug/source marker or named data object proves it.

Decision: accepted.

### 2. Assign canonical owner `0000LE` / `MiniMap`

Evidence for:

- The literals are minimap-specific.
- `sub_453AA0` is a MiniMapDownloader helper and consumes the full group.
- Raw MiniMap-neighborhood refs also consume `.mnm`, the S3 minimap URL, and progress text.

Evidence against:

- `sub_41A750` independently consumes the same physical literal block through FileDownloader message `10000`.
- No current evidence proves FileDownloader imported the literals from a MiniMap declaration.
- Owning the block under MiniMap would overclaim the FileDownloader source-use route.

Decision: reject as canonical owner; retain `0000LE` as emitter.

### 3. Assign canonical owner `0000JC` / `FileDownloader`

Evidence for:

- FileDownloader dispatches message `10000` to `sub_41A750`.
- `sub_41A750` consumes the full target literal group.
- `0000JC` is a valid generated file root.

Evidence against:

- `sub_453AA0` independently consumes the same physical literal group through MiniMapDownloader.
- The strings are feature-specific minimap data, not generic FileDownloader-only constants.
- Owning the block under FileDownloader would overclaim the MiniMap source-use route.

Decision: reject as canonical owner; retain `0000JC` as emitter.

### 4. Create a new shared constants owner

Evidence for:

- The physical block is shared by two near-duplicate download helpers.
- A shared header/file-local declaration is possible in original source.

Evidence against:

- IDA string/debug/source search found no `.pdb`, `RSDS`, `NB10`, source extension, `MiniMapConstants`, `MinimapDownloadWideLiterals`, or `DownloadMinimap` source breadcrumb.
- No global data object, table wrapper, constructor, or address-taken declaration object surrounds the target.
- The target is more parsimoniously modeled as linker/string pooling or duplicated source literals.
- By-structure warns not to invent a helper/global file solely to avoid `NONE`.

Decision: reject.

### 5. Split the target further

Evidence for:

- Shorter fragments like `L"000"`, `L"%03d"`, and `L".mnm"` have duplicates elsewhere.
- Raw MiniMap-side refs touch only `.mnm`, the S3 URL, and progress text.

Evidence against:

- The complete target block is unique.
- Both modeled helpers consume the complete group.
- The URL, format, and progress literals form one coherent minimap download literal set.
- Splitting would not produce different owners for the modeled source-use routes and would lose useful context.

Decision: reject.

### 6. Merge with parent or successor literals

Evidence for:

- The target sits inside the broader `0x0060d7e0-0x0060d9c0` downloader literal container.

Evidence against:

- [UID:0003AL] is a non-emitting split-audit container with children carrying different ownership outcomes.
- The predecessor `L"HTTPTEST"` has wider downloader use.
- The successor item-shop version/progress child starts at `0x0060d8b8` and has FileDownloader-only xrefs.
- Raw bytes and IDA names confirm distinct adjacent literals.

Decision: reject.

### 7. Reclassify non-reconstructable

Evidence for:

- Physical pooling and final `.rdata` placement are linker/compiler effects.

Evidence against:

- The strings are source-authored NexusTK literals required by reconstructed source-use sites.
- Current by-structure classifies source literals as `source-declared/generated-binary` and reconstructable when source uses are known.

Decision: reject. Keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

- No IDA source/debug breadcrumb or shared declaration symbol was found.
- No modeled function owns the raw `0x00454e30` body; `xrefs_to 0x00454e30` is zero.
- No RVA-form references were found in the PE scan.
- The two modeled consumers do not call each other.
- The generated `.cpp` roots are empty, so current emitters prove route availability, not final source text.
- Consumer xrefs prove source-use routes but not canonical declaration ownership.

## Split / Merge / Reclassification Reasoning

- Split: not recommended. The target is an exact coherent minimap-download literal group; both modeled helpers use it as a group.
- Merge: not recommended. The predecessor and successor children have different routing decisions, and the parent is a non-emitting split-audit container.
- Reclassification: not recommended. These are source-authored wide literals, not padding, runtime code, or ignored third-party data.
- Rename/IDA repair: not recommended. The filename and title match the current evidence. IDA's local labels are partial (`a03d`, `aMnm`, `aHttpsS3Amazona`, etc.) but not harmful enough to require a documentation rename.

## C++ Entry Eligibility

Mechanical minimum gate:

```text
RECONSTRUCTABLE:TRUE -> yes
confirmed nonblank EMITTER_UIDS -> yes, 0000JC and 0000LE
emitters surface to generated file roots -> yes
(COMPLETION + CONFIDENCE) / 2 = (89 + 93) / 2 = 91 -> yes
```

This means future C++ placement can be considered under the current gate, but this pass does not enter or recommend final C++. The unresolved issue is source shape:

- original source may have duplicated literals inline in both helper bodies;
- original source may have used file-local constants in each translation unit;
- original source may have used a shared header/static declaration;
- current binary evidence does not distinguish those forms.

Recommended handling: keep `RECONSTRUCTION_CPP` blank on this memory page. When `DownloadMinimapFile` and `MiniMapDownloader` helper bodies are reconstructed, spell the literals at the consuming source-use sites unless later source/debug evidence proves a named shared declaration.

## Exact Required Edits

No by-* documentation edit is required.

No direct edit to `by-memory/-coverage-report.md` is required.

Target metadata should remain:

```text
UID:0003FZ
COMPLETION:89
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
```

Target reconstruction C++ should remain blank:

```text
RECONSTRUCTION_CPP CODE:BEGIN
RECONSTRUCTION_CPP CODE:END
```

Current generated rows to retain:

```markdown
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` |  |
```

```markdown
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000LE][MiniMap](by-file/MiniMap.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

```markdown
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | `0000JC`,`0000LE` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

Current `by-memory/-coverage-report.md` row is substantively correct and can remain:

```markdown
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002 post-migration and B001 second-pass reviews keep `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retain `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

No replacement text is required. Optional provenance-only refresh, if the supervisor wants this fresh B003 pass reflected, would be:

```markdown
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B003 fresh no-owner pass keeps `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retains `EMITTER_UIDS:0000JC,0000LE` because current IDA MCP and PE evidence prove source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0`), with raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`; both emitter UIDs resolve to valid generated file roots, and no split, merge, reclassification, shared constants owner, IDA repair, or final C++ placement is justified.
```

This optional row is not required for correctness.

## Follow-Up Actions

- Supervisor actions: mark the active tracker row complete-no-change if accepted. No shared coverage-report edit is required.
- A-agent actions: none required for this target.
- Future optional work: separately research raw `0x00454e30-0x00455040` if assigned, and improve [UID:0002TR] `DownloadMinimapFile` above `85/85` if source-quality reconstruction work later needs it. Neither action is needed to retain the current `0003FZ` routing.

## Confidence

- Recommendation confidence: high.
- Before/after scores: `89/93` unchanged.
- Score confidence: high for range, literal decoding, xrefs, two emitter routes, and the no-single-owner conclusion.
- Remaining uncertainty: original source declaration style. The binary does not prove whether the literals were duplicated inline, file-local in both translation units, or declared through a shared constant/header.

## Validator Results

- Commands run: none.
- Result: not applicable.
- Reason: this pass created only this Agent-B003 research report and recommends no by-* edits.
- Dry runs: none used.

## Lease State

No leases were acquired. No by-* files or shared generated/project files were edited. `tools/leaser/Agents/current_leases.md` showed no active leases during the pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003FZ-MinimapDownloadWideLiterals-fresh-no-owner-pass.md`
- Modified: none
- Renamed: none
- Moved to executed: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B003/0003FZ-MinimapDownloadWideLiterals-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
