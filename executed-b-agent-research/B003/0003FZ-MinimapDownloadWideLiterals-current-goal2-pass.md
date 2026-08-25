** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: valid no-owner-with-emitters pooled literal case. The target is reconstructable source-authored UTF-16LE data, but no single semantic declaration owner is proven. The two proven source-use output routes are [UID:0000JC][FileDownloader](by-file/FileDownloader.md) and [UID:0000LE][MiniMap](by-file/MiniMap.md).
- Required action: no target metadata change, no split, no merge, no reclassification, no new shared constants file, no coverage-report replacement, no reconstruction C++.
- Confidence: `92/100` for the owner/emitter recommendation. The remaining uncertainty is original source declaration style: repeated identical literals in two source files versus an unproven shared header/helper declaration.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner row lists owner `NONE`, emitters ``0000JC`,`0000LE``, and staged first output path `auto-generated/NexusTK/network/FileDownloader.cpp`.
- Current supervisor classification: Goal 2 current no-owner memory pass; recheck whether no-owner with multiple emitters is still correct.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B001/research/executed/0003FZ-MinimapDownloadWideLiterals-second-pass.md`.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.

## Executive Recommendation

Keep the current state unchanged. `0003FZ` is a coherent minimap download literal block, not an overbroad mixed aggregate needing another split. Live IDA and PE evidence proves two independent source-use routes:

- `0000JC` / `FileDownloader`: `sub_41B110` dispatches message `10000` to `sub_41A750`, and `sub_41A750` references every target literal.
- `0000LE` / `MiniMap`: `sub_453A00` dispatches message `0` to `sub_453AA0`, and `sub_453AA0` references every target literal. Additional raw MiniMap-neighborhood bytes at `0x00454e30-0x00455040` reference the user-agent, `.mnm`, S3 minimap URL, and progress literal.

Neither route proves canonical declaration ownership for the physical `.rdata` block. The correct by-structure model is therefore `CANONICAL_OWNER:NONE` plus both proven `EMITTER_UIDS`.

## Supervisor Active Recheck

- Supervisor instruction: recheck `0003FZ` from current documentation and live IDA MCP evidence under Goal 2 no-owner rules; decide whether it remains no-owner with emitters or needs repair.
- Split repair required before final report: no. The exact target range is bounded by the first minimap literal at `0x0060d7f4` and the successor item-shop URL child at `0x0060d8b8`.
- Direct in-scope doc repair required: no. The current target page already records the correct owner/emitter metadata and the same live xref shape confirmed in this pass.
- Lease status: no lease was acquired because no file outside the B003 research folder was edited.

## Inference Research Guidance Check

- `by-structure.md` separates semantic ownership from output routing. `CANONICAL_OWNER` is the best direct semantic owner; `EMITTER_UIDS` are generated-output routes.
- `by-structure.md` explicitly allows compiler/linker-pooled string literals or shared constants to keep `CANONICAL_OWNER:NONE` while using multiple emitters when independent source-use contexts are proven.
- `inference_research.md` warns that adjacent `.rdata`, consumer xrefs, and string pooling do not by themselves prove same-file declaration ownership. This pass therefore used function containment, dispatcher routes, byte-level PE references, component comparison, adjacent child boundaries, and negative source/debug evidence.
- Existing docs were treated as leads. The current page, B001 prior report, `FileDownloader.md`, `MiniMap.md`, `DownloadMinimapFile.md`, `MiniMapDownloader.md`, and `CashShopDownloaderLiterals.md` were checked against live evidence rather than accepted as final authority.

## Evidence Standards Used

- IDA MCP current session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready.
- IDA MCP tools used: `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, `get_bytes`, and `find_regex`.
- Raw PE evidence: section mapping, UTF-16LE target decode, exact block uniqueness, short/long literal occurrence checks, absolute VA reference scan, RVA negative scan, and rel32 negative scan.
- Documentation evidence: current target page, generated coverage row, by-memory coverage row, FileDownloader/MiniMap file roots, exact helper pages, parent literal-container page, and proposed source-tree notes.
- Evidence strength: strong enough to prove two emitters and no in-scope split/repair; not strong enough to promote either consumer to canonical declaration owner.

## IDA MCP Facts

- `server_health`: status `ok`; module `NexusTK.exe`; input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; image base `0x400000`; auto-analysis ready; Hex-Rays ready; string cache ready with `2067` strings.
- `lookup_funcs` maps `0x0041a750` to `sub_41A750`, size `0x2ae`.
- `lookup_funcs` maps `0x0041b110` to `sub_41B110`, size `0x70`; `0x0041b168` is inside this dispatcher.
- `lookup_funcs` maps `0x00453a00` to `sub_453A00`, size `0x2f`; `0x00453a16` is inside this dispatcher.
- `lookup_funcs` maps `0x00453aa0` to `sub_453AA0`, size `0x2af`.
- `lookup_funcs` reports `0x00454e30`, `0x00454e6f`, `0x00454e7b`, `0x00454fcc`, and `0x00455040` are not IDA-modeled functions. The next modeled functions are `sub_455050`, `sub_455060`, and `sub_4550D0`.
- `decompile 0x0041b110` shows message `10000` calls `sub_41A750` and frees the block; messages `10001` and `10002` route to `sub_41AE20` and `sub_41AA00`; other messages delegate to `sub_596920`.
- `decompile 0x00453a00` shows nonzero messages delegate to `sub_596920`, while message `0` calls `sub_453AA0` and frees the block.
- `analyze_component` for `0x0041a750` and `0x00453aa0` reports no internal call edge between the two helpers.
- The same component analysis reports matching WinINet/file callee families in both helpers: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, `InternetCloseHandle`, `OutputDebugStringW`, `_memset`, `sub_41B9B0`, `unk_69BE34`, and `unk_69BE60`.
- Shared globals/literals accessed by both modeled helpers are `0x0060d7e0` `szAgent`, `0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, `0x0060d894`, and the security cookie.
- `find_regex '(?i)minimap|\.mnm|kru-downloads|itemshop\.ver|itemshop\.json|Downloading'` returns minimap/update strings and MiniMap RTTI names, including `MiniMapDownloader`, but no source-file declaration owner for this target block.
- `find_regex '(?i)\.pdb|\.cpp|\.cxx|\.h'` returns no hits. No embedded source/debug path evidence was found by this check.

## Raw PE Facts

- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE image base: `0x00400000`, machine `0x014c`, four sections.
- `.text`: `0x00401000-0x0060c600`, raw `0x400+0x20b600`, virtual size `0x20b4ac`.
- `.rdata`: `0x0060d000-0x0066c200`, raw `0x20ba00+0x5f200`, virtual size `0x5f0be`.
- Target mapping: `0x0060d7f4-0x0060d8b8` maps to `.rdata` file offsets `0x20c1f4-0x20c2b8`, length `0xc4`.
- UTF-16LE decode of the target block gives `000`, `%03d`, `.mnm`, `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`, `%s%s/%s%s`, and `Downloading : %d\n`.
- Exact `0xc4` target block occurs once in the PE, at file offset `0x20c1f4` / VA `0x0060d7f4`.
- The successor at `0x0060d8b8` is the distinct UTF-16LE `https://secure.kru.com/itemshop/data/itemshop.ver` child.
- Short literal duplicates exist elsewhere, as expected for common strings: `000` appears at `0x0060d7f4`, `0x006107b2`, and `0x00612840`; `%03d` appears at `0x0060d7fc` and `0x00612e82`; `.mnm` appears at `0x0060d808` and `0x006107fa`.
- The identifying long literals are unique at the target: S3 minimap URL at `0x0060d818`, `%s%s/%s%s` at `0x0060d880`, and `Downloading : %d\n` at `0x0060d894`.
- Raw helper range `0x00454e30-0x00455040` occurs once in `.text`; direct immediates inside it reference `0x0060d7e0` at offset `+0x23`, `0x0060d808` at `+0x40`, `0x0060d818` at `+0x4c`, and `0x0060d894` at `+0x19d`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | Pooled minimap download wide literals | `TRUE` | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` | `89/93` | Keep unchanged. |
| `0x0041a750-0x0041a9fe` | [UID:0002TR][DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) | FileDownloader message `10000` helper using all target literals | `TRUE` | `0000JC`; emits through FileDownloader | `80/84` | Helper page below 85/85, but live IDA proves FileDownloader source use. |
| `0x00453910-0x00453def` | [UID:0000XN][MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) | MiniMapDownloader function island including `sub_453AA0` | `TRUE` | `0000LE`; emits through MiniMap | `86/90` | Supports MiniMap emitter. |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-neighborhood helper-shaped byte body using selected target literals | unknown | none | n/a | Evidence only; not a separate emitter. |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL][CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Mixed split-audit literal container | `FALSE` | none | `89/92` | Not an owner; children carry source routes. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | Successor item-shop version literals | `TRUE` | `0000JC` | `86/91` | Confirms target end boundary. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` | `L"000"` head used by both modeled helpers. |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` | overlapped `L"000"` tail used by both modeled helpers. |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` | `L"%03d"` used by both modeled helpers. |
| `0x0060d808` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f` | `L".mnm"` used by both modeled helpers plus raw MiniMap-neighborhood code. |
| `0x0060d818` | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b` | S3 minimap URL used by both modeled helpers plus raw MiniMap-neighborhood code. |
| `0x0060d880` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0` | URL/path format string used by both modeled helpers. |
| `0x0060d894` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc` | progress debug string used by both modeled helpers plus raw MiniMap-neighborhood code. |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` only | successor item-shop child, not part of `0003FZ`. |
| `0x0041a750` | caller `0x0041b168` in `sub_41B110` | FileDownloader message `10000` route. |
| `0x00453aa0` | caller `0x00453a16` in `sub_453A00`; extra raw code ref `0x004539f4` not in a modeled function | MiniMapDownloader message `0` route plus a raw-context caveat. |
| `0x00454e30` | no incoming xrefs | raw helper-shaped body is evidence for MiniMap-side literal use, not a separate callable route. |

## Raw PE Reference-Form Inventory

| Target VA | Absolute VA hits in `.text` | RVA hits | rel32-to-target hits |
| --- | --- | --- | --- |
| `0x0060d7f4` | `0x0041a796`, `0x00453ae6` | none | none |
| `0x0060d7f8` | `0x0041a7a2`, `0x00453aef` | none | none |
| `0x0060d7fc` | `0x0041a7d3`, `0x00453b13` | none | none |
| `0x0060d808` | `0x0041a7e3`, `0x00453b23`, `0x00454e70` | none | none |
| `0x0060d818` | `0x0041a7f3`, `0x00453b33`, `0x00454e7c` | none | none |
| `0x0060d880` | `0x0041a7f8`, `0x00453b38` | none | none |
| `0x0060d894` | `0x0041a989`, `0x00453cd8`, `0x00454fcd` | none | none |
| `0x0060d8b8` | `0x0041aa65` | none | none |

## Documentation Evidence And IDA Status

- `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` already records the exact literal ranges, modeled xrefs, raw MiniMap-side refs, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`. Live IDA/PE evidence confirms this state.
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) is a valid file root at `85/88`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`. It documents `FileDownloader::OnMessage` and the message `10000` minimap helper route. Live IDA confirms the dispatcher call.
- [UID:0000LE][MiniMap](by-file/MiniMap.md) is a valid file root at `85/86`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. It documents `MiniMapDownloader`, `DownloadMinimap_453AA0`, and the open file split between compact `MiniMap.cpp` and focused `MiniMapDownloader.cpp`. Live IDA confirms the task callback route.
- [UID:0002TR][DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) is only `80/84`, but its low helper-page score does not invalidate the FileDownloader emitter because this pass directly proves the `sub_41A750` use path and the file root itself clears the route gate.
- [UID:0000XN][MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md) is `86/90`, assigned to MiniMap, and its `sub_453AA0` helper matches the current IDA route.
- [UID:0003AL][CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) is a non-emitting split-audit container. It is not a candidate owner.
- `by-project-structure/proposed-source-tree.md` keeps `FileDownloader.cpp` under `network/` and `MiniMap*.cpp` under `map/`, and explicitly notes that `DownloadMinimapFile_41A750` downloads the same `.mnm` family but is reached through `FileDownloader::OnMessage` message `10000`.
- `by-memory/-coverage-report.md` currently explains the no-owner-with-emitters state using B002/B001 provenance. The row is still semantically correct.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`

- Evidence for: this is the exact by-structure case for source-authored pooled literals with multiple proven source-use contexts. Both modeled helpers consume every target literal. The dispatch routes are distinct: FileDownloader message `10000` and MiniMapDownloader message `0`. `analyze_component` shows no internal call edge between the helpers. The PE scan found only direct absolute immediates from the known consumer sites, not a hidden shared owner table or rel32/RVA-based declaration structure. Both file roots clear the file-root route gate.
- Evidence against: the original source may have declared shared constants in a header/helper, but no binary/source/debug evidence proves that object.
- Decision: accepted. Keep current metadata unchanged.

### 2. Canonical owner [UID:0000LE] MiniMap

- Evidence for: the strings are minimap-domain-specific (`.mnm`, S3 minimap path, minimap download progress), `MiniMapDownloader` consumes the whole block, and raw MiniMap-neighborhood bytes use the identifying strings.
- Evidence against: `sub_41A750` also consumes the whole same physical block through FileDownloader message `10000`. There is no IDA or PE proof that FileDownloader imports these literals from a MiniMap declaration.
- Decision: reject as canonical owner; keep as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] FileDownloader

- Evidence for: `sub_41A750` consumes the whole block and is directly dispatched by `FileDownloader::OnMessage`; adjacent item-shop URL children are FileDownloader-owned.
- Evidence against: `sub_453AA0` consumes the whole same physical block through MiniMapDownloader, and the most identifying strings are minimap feature literals rather than generic downloader infrastructure.
- Decision: reject as canonical owner; keep as emitter `0000JC`.

### 4. New shared `MinimapDownloadConstants` / `MinimapDownloadShared` owner

- Evidence for: the two modeled helpers are near-clones with the same literal set, so a shared declaration is plausible.
- Evidence against: no pointer table, named global object, source/debug path, call edge, relocation pattern, or distinct source module proves such an owner. `by-structure.md` says not to invent a standalone helper/global file solely to avoid `NONE`.
- Decision: reject. Do not create a new owner/file.

### 5. Split the literal range further

- Evidence for: short strings have duplicate physical occurrences elsewhere, and only the suffix/URL/progress literals have raw MiniMap-neighborhood refs.
- Evidence against: the complete `0xc4` block is unique and behaviorally coherent. Every subrange participates in the same minimap download URL/path/progress construction flow. The successor boundary is already split at `0x0060d8b8`.
- Decision: reject. No split repair is required.

### 6. Reclassify as non-reconstructable compiler/linker output

- Evidence for: the exact physical pooling/layout is compiler/linker-produced.
- Evidence against: the strings are source-authored NexusTK literals that must surface in reconstructed source-use contexts. `by-structure.md` calls this `source-declared/generated-binary`, not non-reconstructable.
- Decision: reject. Keep `RECONSTRUCTABLE:TRUE`.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: the sibling literal container [UID:0003AL] is an audit container; raw `0x00454e30-0x00455040` is not a modeled callable source root; no shared constants file should be created.
- Standalone, narrow, or broad source-file inference: not applicable because the best decision is no canonical owner with two emitters.

## Negative Evidence Summary

- Consumer xrefs prove source-use routes, not declaration ownership. The two independent consumers prevent a single-owner assignment.
- Address adjacency to FileDownloader-only item-shop strings does not make FileDownloader the owner because MiniMapDownloader consumes the entire target block.
- Minimap-specific string content does not make MiniMap the owner because FileDownloader also consumes the entire physical block.
- The raw `0x00454e30-0x00455040` body is not a separate emitter: IDA does not model it as a function, `xrefs_to 0x00454e30` reports no incoming references, and there is no separate by-file/class/global root for it in this assignment.
- The PE scan found no RVA or rel32 reference forms and no hidden owner table for any target literal address.
- The IDA string search found no `.pdb`, `.cpp`, `.cxx`, or `.h` strings that would identify an original source file owner.
- The mixed parent [UID:0003AL] is a non-emitting audit container, not a semantic owner.

## Final Recommendation

- Exact changes applied or recommended: no by-* changes applied; no by-* changes recommended.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:NONE`; keep `EMITTER_UIDS:0000JC,0000LE`.
- Exact items left no-owner/non-emitting and why: `0003FZ` remains no-owner but not non-emitting, because no single declaration owner is proven while both source-use emitters are proven.
- Reconstruction C++: keep blank. This target is a pooled literal page that should surface through consuming source contexts, not a standalone source object.
- Coverage-report replacement: none required. The current `by-memory/-coverage-report.md` row is acceptable as-is. If the supervisor wants current B003 provenance, the optional replacement row would be:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B003 current Goal 2 pass keeps `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retains `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader message `0` (`sub_453AA0`), plus raw MiniMap-side literal refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`.
```

## Follow-Up Actions

- Supervisor actions: accept the current no-owner-with-emitters state for `0003FZ`; no coverage-report application is required unless provenance wording is being refreshed.
- A-agent actions: optional future improvement of [UID:0002TR][DownloadMinimapFile](by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) above `85/85`; this is not required for the current `0003FZ` emitter decision because live IDA proves the FileDownloader route and the file root clears the gate.
- B003 future research actions: only investigate raw `0x00454e30-0x00455040` if separately assigned as a MiniMap raw-helper/function-boundary repair target.

## Confidence

- Recommendation confidence: `92/100`.
- Score confidence: keep target `COMPLETION:89`, `CONFIDENCE:93`.
- Remaining uncertainty: the binary cannot distinguish conclusively between identical source literals repeated in two compilation units and an unproven shared header/helper declaration. The current no-owner-with-emitters model preserves that uncertainty while still routing proven source uses.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: no target, by-*, generated, project-level, or coverage-report file was edited. The user-required validator `--apply` condition only applies when target changes are needed; this pass found no changes needed.
- Dry runs: none used.
- Unresolved validator warnings/errors: none observed in this assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003FZ-MinimapDownloadWideLiterals-current-goal2-pass.md`.
- Modified: none outside the B003 research folder.
- Renamed: none.
- Moved to executed: none.

## Blockers

- None. Current documentation, live IDA MCP evidence, and raw PE evidence were sufficient to make the final Goal 2 recommendation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B003/0003FZ-MinimapDownloadWideLiterals-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
