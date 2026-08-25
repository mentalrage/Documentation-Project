** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) unchanged as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: valid no-owner-with-emitters pooled/shared literal case. No single source declaration owner is proven for the physical `.rdata` block, but live IDA and raw PE evidence prove two source-use output routes: [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md).
- Required action: no target metadata change, no score change, no `by-memory/-coverage-report.md` change, no split, no merge, no new shared constants owner, no IDA repair, and no reconstruction C++.
- Exact metadata recommendation: `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000JC,0000LE`; blank `EMITTER_POSITION_OPTIONAL`; keep `COMPLETION:89` and `CONFIDENCE:93`.
- Confidence: `93/100` for retaining the current route. The only material uncertainty is original source declaration style: separate literal spelling in two source files versus an unproven shared header/helper.

## Exact Recommendation

Retain the target header exactly:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. The current manual row is already accurate:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002 post-migration and B001 second-pass reviews keep `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but retain `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

The current generated rows should remain semantically unchanged after normal tool refresh:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` |  |
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000LE][MiniMap](by-file/MiniMap.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | no-owner | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | `0000JC`,`0000LE` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

The generated output path cell currently displays the first surfaced file path. It does not make `0000JC` the canonical owner and does not remove `0000LE` as a valid emitter.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current no-owner row with emitters `0000JC,0000LE`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003FZ`, assigned to B001 for `0003FZ-MinimapDownloadWideLiterals-post-migration-recheck.md`.
- Prior reports reviewed as background, not accepted without recheck:
  - `tools/leaser/Agents/Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-post-migration.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/0003FZ-MinimapDownloadWideLiterals-second-pass.md`
  - `tools/leaser/Agents/Agent-B001/research/executed/0003FZ-MinimapDownloadWideLiterals-B001-0003FZ.md`
- Current scores and state: `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, blank reconstruction C++.

## Executive Recommendation

Keep the current no-owner-with-emitters state. The target is one coherent UTF-16LE minimap download literal group:

| Range | Literal/data | Live consumers |
| --- | --- | --- |
| `0x0060d7f4-0x0060d7fc` | `L"000"` with overlapping IDA dword heads | `sub_41A750`, `sub_453AA0` |
| `0x0060d7fc-0x0060d808` | `L"%03d"` plus null/alignment | `sub_41A750`, `sub_453AA0` |
| `0x0060d808-0x0060d818` | `L".mnm"` plus null/alignment | `sub_41A750`, `sub_453AA0`, raw `0x00454e6f` |
| `0x0060d818-0x0060d880` | `L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"` | `sub_41A750`, `sub_453AA0`, raw `0x00454e7b` |
| `0x0060d880-0x0060d894` | `L"%s%s/%s%s"` | `sub_41A750`, `sub_453AA0` |
| `0x0060d894-0x0060d8b8` | `L"Downloading : %d\n"` | `sub_41A750`, `sub_453AA0`, raw `0x00454fcc` |

`FileDownloader` is a proven emitter because its message `10000` dispatcher calls `sub_41A750`, and that helper consumes the full group. `MiniMap` is a proven emitter because `MiniMapDownloader::OnThreadTask` calls `sub_453AA0`, that helper consumes the full group, and a raw MiniMap-neighborhood body consumes the suffix, URL, and progress literals. Neither file root should become the canonical owner because both materially use the same physical literals and no shared declaration object is proven.

Do not recommend reconstruction C++. Completion is `89`, below the active `90/90+` code-entry bar, and the page has no standalone source object to emit. The correct source-output behavior is routing the literals to proven consuming contexts when those functions are reconstructed.

## Supervisor Active Recheck

- Supervisor instruction: perform a fresh post-migration B-agent review of current `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000LE`.
- Split repair required: no. The range is exactly bounded by the first minimap literal at `0x0060d7f4` and the item-shop successor at `0x0060d8b8`; internal sub-literals are one coherent minimap download URL/path/progress group.
- Source-bearing child status: the target itself is already the exact source-bearing literal child; no child creation or parent repair was required.
- Coverage/report change required: no. Current target metadata, generated rows, tracker note, and manual coverage row already reflect the correct state.

## Inference Research Guidance Check

`by-structure.md` controls this decision:

- `CANONICAL_OWNER` is semantic ownership, not output routing.
- `EMITTER_UIDS` is output routing and may contain multiple emitters.
- Pooled/shared string literals can remain `CANONICAL_OWNER:NONE` when no single declaration owner is proven, while using multiple emitters for proven source-use contexts.
- Agents should not invent a standalone helper/global file just to avoid `NONE`.

`inference_research.md` cautions that `.rdata` adjacency and consumer xrefs alone do not prove original source-file ownership. I therefore treated the two consumer functions as strong source-use evidence, but not as canonical declaration ownership.

Facts:

- The bytes decode to a minimap download literal block.
- Both modeled helpers consume the full target group.
- Raw MiniMap-neighborhood bytes consume the suffix, URL, and progress literals.
- No single shared declaration object, table, source-path string, or debug record was found.

Inference:

- The physical literals are likely compiler/linker pooled or duplicated source literals from two source-use contexts.
- `FileDownloader` and `MiniMap` are exact emitters, while canonical ownership remains unresolved by design.

## Evidence Standards Used

Evidence types used:

- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, `get_bytes`, `make_signature_for_range`, `find_bytes`, and `find_regex`.
- Independent read-only PE scan for section mapping, exact block uniqueness, UTF-16LE decoding, literal occurrence counts, absolute-VA references, RVA references, and direct branch/reference candidates.
- Documentation review of target page, generated report rows, manual coverage row, tracker row, prior reports, `FileDownloader`, `MiniMap`, `DownloadMinimapFile`, `MiniMapDownloader`, split container `CashShopDownloaderLiterals`, adjacent literal children, and `by-structure.md`.

This evidence is strong enough to retain two emitters and reject all single-owner or extra-emitter alternatives.

## IDA MCP Facts

Live IDA MCP facts from 2026-06-13:

| Field | Value |
| --- | --- |
| Session | `b001_0003gy` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| Module | `NexusTK.exe` |
| Image base | `0x400000` |
| Auto-analysis | ready |
| Hex-Rays | ready |
| Strings cache | ready |

Function and route facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0041a750` | `sub_41A750`, size `0x2ae` | FileDownloader message `10000` minimap download helper. |
| `0x0041b110` | `sub_41B110`, size `0x70` | FileDownloader dispatcher. |
| `0x0041b168` | inside `sub_41B110` | Dispatcher call to `sub_41A750`. |
| `0x00453a00` | `sub_453A00`, size `0x2f` | MiniMapDownloader task dispatch. |
| `0x00453a16` | inside `sub_453A00` | Task-message `0` call to `sub_453AA0`. |
| `0x00453aa0` | `sub_453AA0`, size `0x2af` | MiniMapDownloader direct `.mnm` download helper. |
| `0x00454e30` | not a function | Raw MiniMap-neighborhood helper-shaped body. |
| `0x00454e6f`, `0x00454e7b`, `0x00454fcc` | not functions | Raw references to target literals. |
| `0x00455040` | not a function | End of raw helper-shaped body; xref from `0x0045503f`. |
| `0x00455050` | `sub_455050`, size `0x3` | Next modeled function after raw body. |

Direct xref facts:

| Literal address | Literal | Xrefs |
| --- | --- | --- |
| `0x0060d7f4` | `000` head | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0`. |
| `0x0060d7f8` | `000` tail/overlap | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0`. |
| `0x0060d7fc` | `%03d` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0`. |
| `0x0060d808` | `.mnm` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f`. |
| `0x0060d818` | S3 minimap URL prefix | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b`. |
| `0x0060d880` | `%s%s/%s%s` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0`. |
| `0x0060d894` | `Downloading : %d\n` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc`. |
| `0x0060d8b8` | successor item-shop URL | `0x0041aa64` in `sub_41AA00` only; confirms the target end. |

Dispatcher decompilation facts:

- `sub_41B110` dispatches message `10000` to `sub_41A750` at `0x0041b168` and then frees the task block.
- `sub_453A00` dispatches message `0` to `sub_453AA0` at `0x00453a16` and then frees the task block; nonzero messages forward to shared thread handling.

Consumer helper decompilation facts:

- `sub_41A750` opens WinINet with `szAgent`, copies `L"000"`, formats `L"%03d"` from the request map id, builds the S3 minimap URL with `L"%s%s/%s%s"` and `L".mnm"`, writes downloaded bytes to the output path at `a1 + 16`, logs `L"Downloading : %d\n"`, and deletes the output path on failed loop completion.
- `sub_453AA0` performs the same minimap download flow for the MiniMapDownloader task layout: map id at `*a1`, output path after advancing the task pointer, and the same literal/API set.
- `analyze_component` over `0x0041a750` and `0x00453aa0` reports identical WinINet/file callee families and no internal call edges between the two helpers.
- Shared globals/literals reported by `analyze_component`: `szAgent`, `0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, `0x0060d894`, and `___security_cookie`.

Raw helper facts:

- `xrefs_to 0x00454e30` reports no incoming references.
- `make_signature_for_range 0x00454e30-0x00455040` returned `unique:true`.
- The signature contains direct pushes of `szAgent`, `.mnm`, the S3 minimap URL, and `Downloading : %d\n`. This strengthens MiniMap-side consumer evidence, but it does not establish a modeled function or a separate emitter route.

Name/string search facts:

- `find_regex '(?i)minimap|\.mnm|kru-downloads|s3\.amazonaws'` found minimap-domain strings and RTTI names, including `MiniMapDownloader` and related MiniMap classes.
- `find_regex '(?i)\.pdb|\.cpp|\.cxx|\.h|RSDS|NB10'` returned zero string-cache matches. No source/debug path evidence for a canonical literal declaration owner was found.

## PE / Raw Evidence

Read-only PE scan path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

PE section facts:

| Section | VA range | Role |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | executable code and immediate references |
| `.rdata` | `0x0060d000-0x0066c200` | target literal block |
| `.data` | `0x0066d000-0x0069ce24` | writable state |
| `.rsrc` | `0x0069d000-0x006b2e00` | resources |

Target mapping and decode:

| Check | Result |
| --- | --- |
| Target VA | `0x0060d7f4-0x0060d8b8` |
| Target file range | `0x20c1f4-0x20c2b8` |
| Length | `0xc4` |
| Decoded UTF-16LE | `000`, `%03d`, `.mnm`, `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`, `%s%s/%s%s`, `Downloading : %d\n` |
| Full `0xc4` block hits | one, at `0x0060d7f4` |
| Successor boundary | `0x0060d8b8` begins `https://secure.kru.com/itemshop/data/itemshop.ver` |

Literal occurrence facts:

| Literal | PE occurrences |
| --- | --- |
| `L"000"` | `0x0060d7f4`, `0x006107b2`, `0x00612840` |
| `L"%03d"` | `0x0060d7fc`, `0x00612e82` |
| `L".mnm"` | `0x0060d808`, `0x006107fa` |
| S3 minimap URL prefix | `0x0060d818` only |
| `L"%s%s/%s%s"` | `0x0060d880` only |
| `L"Downloading : %d\n"` | `0x0060d894` only |
| successor item-shop version URL | `0x0060d8b8` only |

Reference-form scan:

| VA | Absolute VA hits | RVA hits | direct branch/reference hits |
| --- | --- | --- | --- |
| `0x0060d7f4` | `0x0041a796`, `0x00453ae6` | none | none |
| `0x0060d7f8` | `0x0041a7a2`, `0x00453aef` | none | none |
| `0x0060d7fc` | `0x0041a7d3`, `0x00453b13` | none | none |
| `0x0060d808` | `0x0041a7e3`, `0x00453b23`, `0x00454e70` | none | none |
| `0x0060d818` | `0x0041a7f3`, `0x00453b33`, `0x00454e7c` | none | none |
| `0x0060d880` | `0x0041a7f8`, `0x00453b38` | none | none |
| `0x0060d894` | `0x0041a989`, `0x00453cd8`, `0x00454fcd` | none | none |
| `0x0060d8b8` | `0x0041aa65` | none | none |

The PE evidence shows direct immediate references from known consumers. It does not expose a hidden RVA table, relative-reference table, or single shared declaration object for this target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | pooled minimap download wide literals | `TRUE` | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` | `89/93` | keep unchanged |
| `0x0041a750-0x0041a9fe` | `0002TR` `DownloadMinimapFile` | FileDownloader message `10000` helper consuming all target literals | `TRUE` | `0000JC`; emits `0000JC` | `80/84` | source-use evidence for FileDownloader emitter; helper page should improve later |
| `0x00453910-0x00453def` | `0000XN` `MiniMapDownloader` | MiniMap worker/download helper consuming all target literals | `TRUE` | `0000LE`; emits `0000LE` | `86/90` | source-use evidence for MiniMap emitter |
| `0x00454e30-0x00455040` | no exact page | raw MiniMap-neighborhood helper-shaped body using `.mnm`, S3 URL, and progress literal | unknown | no separate owner/emitter | n/a | evidence for `0000LE`, not a separate route |
| `0x0060d7e0-0x0060d9c0` | `0003AL` `CashShopDownloaderLiterals` | mixed split-audit container | `FALSE` | none | `89/92` | not a source owner |
| `0x0060d7e0-0x0060d7f4` | `0003FY` | shared downloader user-agent literal | `TRUE` | `NONE`; emits `0000JC,0000LE` | `88/93` | adjacent no-owner/multi-emitter precedent |
| `0x0060d8b8-0x0060d94c` | `0003G0` | item-shop version URL/progress literals | `TRUE` | `0000JC`; emits `0000JC` | `86/91` | confirms target end |
| `0x0060d94c-0x0060d958` | `0003G1` | shared `version` key | `TRUE` | `NONE`; multi-emitter | `88/93` | separate pooled-key precedent |
| `0x0060d958-0x0060d9c0` | `0003G2` | item-shop catalog URL | `TRUE` | `0000JC`; emits `0000JC` | `86/92` | FileDownloader-only sibling |

## Source-Use / Emitter Inventory

### Emitter `0000JC` FileDownloader - accepted

Evidence for:

- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) is a valid file root at `85/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`.
- `sub_41B110` dispatches downloader message `10000` to `sub_41A750` at `0x0041b168`.
- `sub_41A750` consumes every literal in the target range and performs the minimap HTTP download flow.
- The direct xrefs and PE immediate references cover all sub-literals in the target group.

Evidence caveat:

- [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) is only `80/84`. This is a future helper-page improvement task, not a blocker for the emitter route, because the file root clears the source-root gate and live IDA directly proves the source-use path.

Decision: keep `0000JC` as an emitter.

### Emitter `0000LE` MiniMap - accepted

Evidence for:

- [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) is a valid file root at `85/86`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- [UID:0000XN][MiniMapDownloader](../../../../../by-memory/0x00453910-0x00453def.MiniMapDownloader.md) is `86/90` and routes to `0000LE`.
- `sub_453A00` calls `sub_453AA0` for MiniMapDownloader message `0`.
- `sub_453AA0` consumes every literal in the target range and performs the same minimap HTTP download flow with MiniMapDownloader task layout.
- Raw `0x00454e30-0x00455040` consumes `L".mnm"`, the S3 minimap URL prefix, and `L"Downloading : %d\n"` in a unique MiniMap-neighborhood body.

Decision: keep `0000LE` as an emitter.

### Candidate extra emitter for raw `0x00454e30-0x00455040` - rejected

Evidence for:

- Direct raw refs to three target literals exist at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`.
- The range has a unique signature and is in the MiniMap renderer/control neighborhood.

Evidence against:

- IDA does not model `0x00454e30` as a function.
- `xrefs_to 0x00454e30` reports no incoming references.
- There is no separate by-file root, class, exact by-memory child, or source owner for this raw body in this assignment.
- Its source-use evidence is already represented by `0000LE` MiniMap.

Decision: reject a separate emitter. Treat the raw refs as additional evidence for `0000LE`.

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- Target page `0003FZ` records exact literal ranges, modeled xrefs, raw MiniMap-side refs, no single canonical owner, and emitters `0000JC,0000LE`.
- `FileDownloader.md` records the message `10000` dispatcher route, `DownloadMinimapFile_41A750`, and the `network/FileDownloader.cpp` root.
- `MiniMap.md` records the minimap source family, `MiniMapDownloader`, `DownloadMinimap_453AA0`, and the `NexusTK/map/` root.
- `MiniMapDownloader.md` directly documents `sub_453AA0` as the MiniMap `.mnm` download helper and clears `86/90`.
- `CashShopDownloaderLiterals.md` documents `0003AL` as a non-emitting split-audit container and `0003FZ` as the shared minimap literal child.
- Adjacent `0003FY` and `0003G1` pages show accepted no-owner/multi-emitter handling for pooled shared literals.

Documentation caveats:

- `DownloadMinimapFile.md` should eventually be improved above `85/85`, but the current assignment's IDA evidence proves FileDownloader source use directly.
- `MiniMap.md` still leaves compact `MiniMap.cpp` versus dedicated `MiniMapDownloader.cpp` unresolved. This is not a blocker because `0000LE` is the current valid file-root emitter.
- Current generated rows display a single surfaced output path under `FileDownloader.cpp`. This is a generated display artifact, not canonical ownership and not an emitter-list reduction.

## Ranked Ownership / Emitter Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` - accepted

Evidence for:

- This exactly matches the `by-structure.md` pooled/shared literal rule.
- Both modeled helpers consume the whole target literal group.
- The helpers have different source-use routes and task layouts: FileDownloader message `10000` versus MiniMapDownloader message `0`.
- `analyze_component` reports no internal call edge between `sub_41A750` and `sub_453AA0`.
- Raw PE scan found only direct immediate references from known consumer sites, with no RVA table, relative-reference pattern, or hidden shared owner object.
- Both file roots are valid source roots and clear the gate for emitter use.

Evidence against:

- The final original source might have used a shared header/helper declaration, but the binary does not prove it.
- `0002TR` is below `85/85`; improve it later.

Decision: accepted. Keep current state unchanged.

### 2. Canonical owner [UID:0000LE] MiniMap - rejected

Evidence for:

- The strings are minimap-specific: `.mnm`, S3 minimap URL prefix, and minimap progress text.
- `MiniMapDownloader` consumes the whole group and routes to MiniMap.
- Raw MiniMap-neighborhood bytes consume identifying literals.

Evidence against:

- `sub_41A750` consumes the same whole physical group from the FileDownloader message path.
- No IDA or PE evidence proves FileDownloader imports these literals from a MiniMap declaration.
- Canonical ownership would overclaim a pooled source-use item.

Decision: reject as canonical owner; keep as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] FileDownloader - rejected

Evidence for:

- `sub_41A750` consumes the whole group and is dispatched by FileDownloader `OnMessage`.
- FileDownloader owns neighboring item-shop literal children `0003G0` and `0003G2`.

Evidence against:

- `sub_453AA0` consumes the whole group under MiniMapDownloader.
- Raw MiniMap-neighborhood bytes consume the most identifying literals.
- The target literals are minimap-domain strings, not generic downloader constants.

Decision: reject as canonical owner; keep as emitter `0000JC`.

### 4. New shared `MinimapDownloadConstants` / `MinimapDownloadShared` owner - rejected

Evidence for:

- The two modeled helpers are near-clones and use the same literal group.
- A shared header or constants helper is possible in original source.

Evidence against:

- No pointer table, global struct, named declaration object, source/debug path, or call edge proves a shared constants owner.
- The PE scan found direct immediate references only.
- `by-structure.md` warns not to invent a standalone global/helper file solely to avoid `CANONICAL_OWNER:NONE`.

Decision: reject. Do not create a new owner/file.

### 5. Further split of `0003FZ` - rejected

Evidence for:

- Some sub-literals have raw MiniMap-side refs while others have only the two modeled refs.
- Short literals such as `L"000"`, `L"%03d"`, and `L".mnm"` have duplicate physical occurrences elsewhere.

Evidence against:

- The full target block is unique and behaviorally coherent.
- Every subrange participates in the same minimap URL/path/progress construction flow.
- Splitting would not create a valid canonical owner or improve the emitter model; it would fragment one already-exact pooled literal group.

Decision: reject. No split repair required.

### 6. Reclassify as compiler-generated or non-reconstructable - rejected

Evidence for:

- Physical placement and pooling are compiler/linker output.

Evidence against:

- The contents are source-authored NexusTK string literals and must appear in reconstructed source-use contexts.
- `by-structure.md` supports `source-declared/generated-binary` handling for such data.

Decision: keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

Checked and rejected:

- Single canonical FileDownloader ownership.
- Single canonical MiniMap ownership.
- New shared constants owner.
- Extra raw-helper emitter.
- Further sub-splitting.
- Non-reconstructable/compiler-only classification.
- Hidden source owner table: no RVA hits and no direct branch/reference hits to target data addresses.
- Source/debug path evidence: no `.pdb`, `.cpp`, `.cxx`, `.h`, `RSDS`, or `NB10` string-cache hits.

The remaining uncertainty is exact original source declaration style. The current metadata preserves that uncertainty while routing all proven source uses.

## Score / Coverage Effects

| Field | Current | Recommendation | Reason |
| --- | ---: | ---: | --- |
| Completion | `89` | `89` | Existing page already documents exact literal ranges, xrefs, raw helper caveat, and routing reasoning. Completion remains below code-entry because final declaration/source spelling is unresolved. |
| Confidence | `93` | `93` | Fresh IDA and PE evidence reconfirm current route. |
| Canonical owner | `NONE` | `NONE` | No single declaration owner is proven. |
| Emitters | `0000JC,0000LE` | `0000JC,0000LE` | Both source-use roots are proven; no extra route clears the gate. |
| Coverage row | current row | no change | Current manual/generated rows already reflect the accepted no-owner-with-emitters state. |

## Final Recommendation

Exact changes recommended:

- No target metadata change.
- No score change.
- No coverage row change.
- No split/merge/rename.
- No new owner/source file.
- No IDA repair.
- No reconstruction C++.

Exact items left no-owner with emitters:

- `0003FZ` remains `CANONICAL_OWNER:NONE` because FileDownloader and MiniMap both materially consume the physical literal group and no shared declaration owner is proven.
- `0003FZ` keeps `EMITTER_UIDS:0000JC,0000LE` because those are the two proven source-use file roots.

Future work outside this assignment:

- Improve [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) above `85/85` if assigned.
- Investigate raw `0x00454e30-0x00455040` only as its own MiniMap raw-helper/function-repair target if assigned.

## Follow-Up Actions

Supervisor actions:

- Accept this recheck with no by-* or coverage changes.
- Move the report to `research/executed` if accepted.

A-agent actions:

- Do not attach `0003FZ` to only FileDownloader or only MiniMap during routine cleanup.
- Keep reconstruction C++ blank until the consuming functions themselves are ready for final source entry.

B001 future research actions:

- Revisit only if a later target uncovers source/debug evidence for a shared minimap download constants declaration.

## Confidence

- Recommendation confidence: `93/100`.
- Byte/range confidence: `96/100`.
- Emitter-route confidence: `94/100`.
- Canonical-owner rejection confidence: `91/100`.
- Remaining uncertainty: exact original declaration style and whether the raw `0x00454e30-0x00455040` body should eventually become a modeled MiniMap helper page.

## Validator Results

- Validator commands run: none.
- Reason: this assignment created only an Agent-B001 research report and did not edit validator-managed by-* documentation. The user prohibited dry-run modes, and no normal `--apply` validator action was required for an Agent research Markdown file.
- Dry-run validator modes: not used.
- Memory-range modes: not used.
- Unresolved validator warnings/errors from this pass: none.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003FZ-MinimapDownloadWideLiterals-post-migration-recheck.md`.
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.
- Direct `by-memory/-coverage-report.md` edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B001/0003FZ-MinimapDownloadWideLiterals-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
