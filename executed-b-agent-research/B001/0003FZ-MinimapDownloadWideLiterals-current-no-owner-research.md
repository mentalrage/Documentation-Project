** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` unchanged.
- Final disposition: valid pooled/shared literal case with `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000LE`.
- Required action: no canonical-owner change, no emitter change, no split, no merge, no reclassification, no IDA-safe rename repair, no by-memory edit, no shared coverage-report edit, and no final reconstruction C++ insertion.
- Confidence: high. Keep `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`.

This is no-owner, but it is not a non-emitting dead end. Current IDA evidence proves two source-use routes: FileDownloader message `10000` through `sub_41A750`, and MiniMapDownloader message `0` through `sub_453AA0` plus raw MiniMap-neighborhood literal uses. Current documentation and generated file coverage show both emitter UIDs resolve to valid generated file roots.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` no-owner/multi-emitter row, tracked in `tools/leaser/Agents/no_owner_b-agent-tracker.md`.
- Current supervisor classification: current Goal 2 no-owner memory sweep; assigned to Agent-B001 on 2026-06-14.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md`.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.

## Executive Recommendation

Keep the current no-owner/multi-emitter state. The target is a coherent UTF-16LE minimap download literal group:

```text
0x0060d7f4-0x0060d7fc  L"000"
0x0060d7fc-0x0060d808  L"%03d"
0x0060d808-0x0060d818  L".mnm"
0x0060d818-0x0060d880  L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"
0x0060d880-0x0060d894  L"%s%s/%s%s"
0x0060d894-0x0060d8b8  L"Downloading : %d\n"
```

[UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap` are both proven source-use contexts. Neither is a defensible canonical declaration owner for the entire physical pooled block, and no shared constants declaration/source owner is proven.

## Supervisor Active Recheck

- Supervisor instruction: verify whether current `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000LE` are still correct, sufficient, non-dead-end, and accurately documented.
- Split repair required before report: no. The range is exact and behaviorally coherent.
- Direct by-* repair required: no. Current target, sibling/container documentation, generated rows, and shared coverage row match current evidence.
- Shared coverage-report handling: do not edit `by-memory/-coverage-report.md`; no replacement is required.

## Inference Research Guidance Check

`by-structure.md` separates semantic ownership from generated-output routing. `CANONICAL_OWNER` needs a direct source/declaration owner. `EMITTER_UIDS` records output routes and can contain multiple emitters for pooled string literals or shared constants when no single declaration owner is proven.

`inference_research.md` treats consumer xrefs as evidence, not automatic declaration ownership proof. Here, xrefs prove the literals must be represented in two source-use contexts. They do not prove whether original source duplicated the literals, used a shared declaration, or relied on linker/string pooling. The correct documentation model preserves that uncertainty while retaining the two proven emitters.

## Evidence Standards Used

- Current documentation: target page, mixed parent container, predecessor/successor literal pages, emitter file pages, consumer memory pages, generated memory/file coverage, and proposed source tree.
- Live IDA MCP session: `b001_0002bd`.
- Live IDA MCP tools used: `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_component`, `get_bytes`, `make_signature_for_range`, `find_xref_signatures`, `entity_query`, and `find_regex`.
- Local generated-output checks: generated file roots, generated `.cpp` files, and `rg` for target UID/address/literal annotations.
- Local binary identity check: `Get-FileHash -Algorithm MD5` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## IDA MCP Facts

Session facts:

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
MD5: 4247E04E20B65D6414C7238AA8FF5515
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
0x00455040 -> not a function
0x00455050 -> sub_455050, size 0x3
0x0060d7f4 -> not a function
0x0060d8b8 -> not a function
```

Decompiler facts:

```text
sub_41B110:
  case 10000:
    sub_41A750((int)Block);
    sub_5C7526(Block);
  case 10001:
    sub_41AE20(Block);
  case 10002:
    sub_41AA00((int)Block);
    (**Block)(Block, 1);
  default:
    sub_596920(a1, Block, a3);

sub_453A00:
  if (a1)
    sub_596920(a1, Block, a3);
  else {
    sub_453AA0(Block);
    sub_5C7526(Block);
  }
```

Component comparison:

- `analyze_component` on `0x0041a750` and `0x00453aa0` reports matching WinINet/file callee families: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, `InternetCloseHandle`, `OutputDebugStringW`, `sub_41B9B0`, `unk_69BE34`, `unk_69BE60`, `_memset`, `__alloca_probe`, and security-cookie support.
- The internal call graph contains both nodes but no edge between them, so one modeled helper does not own or call the other.
- Shared globals/literals accessed by both modeled helpers include `0x60d7f4`, `0x60d7f8`, `0x60d7fc`, `0x60d808`, `0x60d818`, `0x60d880`, and `0x60d894`.

## Byte, Name, And Boundary Facts

IDA MCP `get_bytes` for `0x0060d7e0` forward decodes the predecessor `HTTPTEST` user-agent, this target's full literal group, the successor item-shop version URL at `0x0060d8b8`, the successor item-shop progress string, the narrow `version` key, and the later item-shop JSON URL. This confirms the target starts after [UID:0003FY] and ends immediately before [UID:0003G0].

`make_signature_for_range 0x0060d7f4-0x0060d8b8` returned a full literal byte signature and `unique:true`:

```text
30 00 30 00 30 00 00 00
25 00 30 00 33 00 64 00 00 00 00 00
2E 00 6D 00 6E 00 6D 00 00 00 00 00 00 00 00 00
68 00 74 00 74 00 70 00 73 00 3A 00 2F 00 2F 00 ...
25 00 73 00 25 00 73 00 2F 00 25 00 73 00 25 00 73 00 00 00
44 00 6F 00 77 00 6E 00 6C 00 6F 00 61 00 64 00 69 00 6E 00 67 00 20 00 3A 00 20 00 25 00 64 00 0A 00 00 00
```

IDA names around the target:

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
```

The target itself has descriptive IDA names for some literal heads, but no source/debug marker or named shared declaration object was found. `find_regex` for `.pdb`, `.PDB`, `.cpp`, `.CPP`, `.cxx`, `RSDS`, `NB10`, `MinimapDownloadWideLiterals`, `MiniMapConstants`, and `DownloadMinimap` returned zero string-cache matches.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `CashShopDownloaderLiterals` | Mixed literal split-audit container | `FALSE` | `NONE` / blank emitters | `89/92` | Correct non-emitting container |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY] `SharedDownloaderUserAgentWideString` | Shared `L"HTTPTEST"` user-agent | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `88/93` | Adjacent shared-literal precedent |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ] target | Minimap download wide literals | `TRUE` | `NONE`; emitters `0000JC,0000LE` | `89/93` | Keep unchanged |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `CashShopVersionDownloadWideLiterals` | Item-shop version URL/progress literals | `TRUE` | `0000JC`; emitter `0000JC` | `86/91` | Confirms successor boundary |
| `0x0041a750-0x0041a9fe` | [UID:0002TR] `DownloadMinimapFile` | FileDownloader message `10000` minimap helper | `TRUE` | `0000JC`; emitter `0000JC` | `80/84` | Current pass proves source use; page score is not the emitter root |
| `0x00453910-0x00453def` | [UID:0000XN] `MiniMapDownloader` | MiniMapDownloader worker and direct minimap helper | `TRUE` | `0000LE`; emitter `0000LE` | `86/90` | Supports MiniMap emitter |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-neighborhood literal-consuming body | unknown | none | n/a | Consumer evidence only; no incoming xref |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` | `L"000"` used by both modeled helpers |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` | Overlapped/tail literal head used by both modeled helpers |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` | `L"%03d"` used by both modeled helpers |
| `0x0060d808` | `0x0041a7e2`; `0x00453b22`; raw `0x00454e6f` | `.mnm` used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d818` | `0x0041a7f2`; `0x00453b32`; raw `0x00454e7b` | S3 minimap URL used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d880` | `0x0041a7f7`; `0x00453b37` | URL/path format used by both modeled helpers |
| `0x0060d894` | `0x0041a988`; `0x00453cd7`; raw `0x00454fcc` | Progress string used by both modeled helpers plus raw MiniMap-side code |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` | Successor item-shop literal child, not part of target |
| `0x0041a750` | code xref `0x0041b168` in `sub_41B110` | FileDownloader message `10000` source-use route |
| `0x00453aa0` | code xref `0x00453a16` in `sub_453A00`; raw `0x004539f4` | MiniMapDownloader source-use route plus raw-context caveat |
| `0x00454e30` | zero xrefs to raw start | Raw body is not a separate owner/emitter route yet |

`find_xref_signatures` also produced short stable signatures for the literal refs, including the raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`. This supports the raw-consumer evidence but still does not make `0x00454e30` a callable or owned function page.

## Generated Route Evidence

Current `auto-generated/-ag-file-coverage.md` rows show both emitter UIDs are valid file roots:

```markdown
| [UID:0000JC][FileDownloader](by-file/FileDownloader.md) | emits | `FILE` |  |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-file/FileDownloader.md` | by-file generated root |
| [UID:0000LE][MiniMap](by-file/MiniMap.md) | emits | `FILE` |  |  | no | `auto-generated/NexusTK/map/MiniMap.cpp` | `by-file/MiniMap.md` | by-file generated root |
```

Current generated `.cpp` files exist at both paths:

```text
auto-generated/NexusTK/network/FileDownloader.cpp
auto-generated/NexusTK/map/MiniMap.cpp
```

Both files are currently zero-length, and `rg` found no `0003FZ`, `0x0060d7f4`, `MinimapDownloadWideLiterals`, S3 minimap URL, or progress literal annotation in either generated file. This is expected because the target's `RECONSTRUCTION_CPP` block is blank. The emitter chain is non-dead-end structurally, but the target is not yet emitting final source text.

The generated memory row reports the first output path only, but the emitter list itself correctly includes both file roots:

```markdown
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` |  |
```

The generated no-owner-with-emitters route row also lists both emitters:

```markdown
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000LE][MiniMap](by-file/MiniMap.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

## Documentation Evidence And IDA Status

- Target page `0003FZ` already records exact literal subranges, representative modeled xrefs, raw MiniMap-side refs, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`, and a no-single-owner decision. Current IDA MCP confirms those claims.
- [UID:0003AL] `CashShopDownloaderLiterals` is a reviewed `RECONSTRUCTABLE:FALSE` split-audit container. It is not a source owner.
- [UID:0003FY] predecessor uses the same `NONE` plus `0000JC,0000LE` emitter model for `L"HTTPTEST"` and records the appropriate source-placement guidance: spell the literal at consuming sites unless source/debug evidence proves a named shared declaration.
- [UID:0003G0] successor is FileDownloader-owned and starts at `0x0060d8b8`; current bytes and xrefs confirm this target should not absorb the item-shop version URL.
- [UID:0000JC] `FileDownloader` is `85/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, and documents the message `10000` path through `sub_41A750`.
- [UID:0000LE] `MiniMap` is `85/86`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, and documents the MiniMapDownloader worker path through `sub_453AA0`.
- [UID:0002TR] `DownloadMinimapFile` is below `85/85` as a standalone memory page, but that is not a blocker for retaining the `0000JC` emitter: the route is through the valid `FileDownloader` file root, and this pass directly reverified `sub_41A750` source use.
- [UID:0000XN] `MiniMapDownloader` is `86/90`, owned/emitted through `0000LE`, and current IDA reconfirms its `sub_453A00 -> sub_453AA0` task route.
- `by-project-structure/proposed-source-tree.md` keeps `FileDownloader.cpp` under `network/` and `MiniMap.cpp` under `map/`, and explicitly notes that `DownloadMinimapFile_41A750` downloads the same `.mnm` family through `FileDownloader::OnMessage` while minimap ownership remains linked.

No stale filename, stale label, stale range, missing split, merge need, bad emitter, dead-end emitter, or source-routing repair was found.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- Both modeled helpers reference the complete literal group.
- `sub_41A750` is reached from FileDownloader message `10000`.
- `sub_453AA0` is reached from MiniMapDownloader task message `0`.
- `analyze_component` shows the two helpers share literals and API behavior but do not call each other.
- Raw MiniMap-neighborhood refs strengthen MiniMap-side use but do not erase the FileDownloader route.
- Both emitter UIDs are valid generated file roots with generated paths.
- By-structure explicitly allows pooled/shared literals to stay ownerless while routing through multiple proven source-use contexts.

Evidence against:

- The original source may have used a named shared declaration or header constant, but the binary does not prove that.

Decision: accepted.

### 2. Assign canonical owner [UID:0000LE] `MiniMap`

Evidence for:

- The strings are minimap-specific.
- The MiniMapDownloader route consumes every target literal.
- Raw MiniMap-side code additionally references `.mnm`, the S3 minimap URL, and the progress string.

Evidence against:

- FileDownloader message `10000` independently consumes the same physical group through `sub_41A750`.
- No evidence proves `FileDownloader` imported these literals from a MiniMap declaration.
- Making MiniMap canonical would overclaim the FileDownloader source-use context.

Decision: rejected as canonical owner; retained as emitter `0000LE`.

### 3. Assign canonical owner [UID:0000JC] `FileDownloader`

Evidence for:

- FileDownloader dispatches message `10000` to `sub_41A750`.
- `sub_41A750` references every target literal.
- `0000JC` is a valid generated file root.

Evidence against:

- MiniMapDownloader also references every target literal through `sub_453AA0`.
- The literal contents are minimap feature data, not generic FileDownloader-only state.
- Making FileDownloader canonical would overclaim MiniMap source-use contexts.

Decision: rejected as canonical owner; retained as emitter `0000JC`.

### 4. Create a new shared constants owner

Evidence for:

- A shared declaration is plausible because two near-clone download helpers use one physical literal block.

Evidence against:

- IDA MCP found no source/debug marker, source path, shared declaration object, global table, or named constants owner.
- The current physical pooling alone is not enough to invent a new source file.
- By-structure specifically warns not to invent a standalone owner solely to avoid `NONE`.

Decision: rejected.

### 5. Split the target

Evidence for:

- Some shorter literals have duplicates elsewhere.
- Raw MiniMap-side refs only touch `.mnm`, the URL, and progress text.

Evidence against:

- The full target block is unique.
- Both modeled helpers use all literal heads in the block.
- The group is a coherent minimap URL/path/progress literal cluster.
- Splitting would produce smaller pages with the same owner/emitter conclusion and worse context.

Decision: rejected.

### 6. Merge into [UID:0003AL] `CashShopDownloaderLiterals`

Evidence for:

- The target is physically inside the broader `.rdata` literal container.

Evidence against:

- [UID:0003AL] is a non-emitting mixed split-audit container with children carrying different ownership outcomes.
- Merging would lose exact child routing for `0003FZ`, `0003G0`, `0003G1`, and `0003G2`.

Decision: rejected.

### 7. Reclassify non-reconstructable

Evidence for:

- The physical pooling/layout is linker/compiler output.

Evidence against:

- The literal contents are source-authored NexusTK data that must appear in reconstructed source uses.
- Current by-structure rules classify source string literals as `source-declared/generated-binary` and reconstructable when source uses are known.

Decision: rejected.

## Negative Evidence Summary

- Consumer xrefs prove source-use routes, not declaration ownership.
- No source/debug marker or shared declaration object was found.
- No single candidate owner covers both FileDownloader and MiniMap source uses without overclaiming.
- Raw refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc` are not inside IDA-modeled functions; they support MiniMap-side use but do not establish a separate emitter.
- `xrefs_to 0x00454e30` is zero, so the raw MiniMap-neighborhood body is not yet a callable source target.
- The generated `.cpp` roots are empty because no reconstruction C++ is entered; this is not an emitter dead-end, but it is a code-entry caution.

## C++ Placement And Code-Entry Implications

The current minimum code-entry gate is technically partly satisfied: the item is `RECONSTRUCTABLE:TRUE`, has nonblank emitter UIDs, and the average score is above `85`.

However, no final `RECONSTRUCTION_CPP` should be entered or recommended for this target now. The unresolved question is source shape, not routing:

- It may have been duplicated inline at both source-use sites.
- It may have been file-local constants in each translation unit.
- It may have been a shared header/static declaration.
- The current binary does not prove which source form was used.

Recommended placement guidance: keep this page's C++ block blank. When the consuming helper bodies are eventually reconstructed, spell the minimap literals at the FileDownloader and MiniMap consumer sites unless later source/debug evidence proves a named shared declaration. Do not create a standalone shared constants file for this target from current evidence.

## Final Recommendation

- Exact changes applied or recommended: create this B001 research report only.
- Exact parent assignments applied or recommended: retain `CANONICAL_OWNER:NONE`.
- Exact emitter assignments applied or recommended: retain `EMITTER_UIDS:0000JC,0000LE`.
- Exact items left no-owner/non-emitting and why: none. `0003FZ` remains no-owner but emitting/routed through two proven source-use emitters.
- Exact future work outside this assignment scope: optional future research of raw `0x00454e30-0x00455040` as a MiniMap-neighborhood helper, and optional improvement of [UID:0002TR] `DownloadMinimapFile` above `85/85`. Neither is required for this owner/emitter decision.

## Exact Recommended Edits

No target or shared-report edits are required.

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

## Supervisor-Owned Shared-Report Text

No `by-memory/-coverage-report.md` replacement is required. Retain the current row:

```markdown
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002 post-migration and B001 second-pass reviews keep `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retain `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

Optional provenance-refresh replacement if the supervisor wants this current B001 pass reflected in the shared row:

```markdown
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B001 current no-owner recheck keeps `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retains `EMITTER_UIDS:0000JC,0000LE` because current IDA MCP evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0`), with raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`; both emitter UIDs resolve to valid generated file roots, and no split, merge, reclassification, shared constants owner, IDA repair, or final C++ placement is justified.
```

This optional row is not required; the current shared row is substantively correct.

## Follow-Up Actions

- Supervisor actions: mark the active tracker row complete-no-change if accepted. No shared coverage-report edit is required.
- A-agent actions: none required. Optional future improvement can raise [UID:0002TR] `DownloadMinimapFile` above `85/85`, but this is not needed to retain `0000JC` as an emitter.
- B001 future research actions: none for this target unless raw `0x00454e30-0x00455040` is separately assigned.

## Confidence

- Recommendation confidence: high.
- Before/after scores: before `89/93`; after unchanged at `89/93`.
- Score confidence: high for current behavior, range, and emitter routing; below final-audit range because original source declaration style is still unresolved.
- Remaining uncertainty: whether original source duplicated the literals in both helper bodies, used file-local constants, or used a shared declaration. Current evidence does not justify collapsing that uncertainty into a canonical owner.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: no by-* documentation, generated file, project-level report, or shared coverage-report file was edited.
- Dry runs: none used.
- Unresolved validator warnings/errors introduced: none.

## Lease State

- No leases were acquired.
- Reason: only this report in Agent-B001's own research folder was created; no leased-scope by-* or shared files were edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md`.
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B001/0003FZ-MinimapDownloadWideLiterals-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
