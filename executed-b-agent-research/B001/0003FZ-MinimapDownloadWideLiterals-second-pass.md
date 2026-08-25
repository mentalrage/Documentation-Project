** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Second-Pass Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) unchanged as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: valid no-owner-with-emitters pooled literal case. This is not a non-emitting dead end. The physical `.rdata` literals have no proven single declaration owner, but live IDA/PE evidence proves source-use contexts in both [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md).
- Required action: no by-memory metadata change, no `by-memory/-coverage-report.md` change, no split, no reclassification, no new shared constants owner, and no reconstruction C++.
- Exact metadata recommendation: `CANONICAL_OWNER:NONE`; `RECONSTRUCTABLE:TRUE`; `EMITTER_UIDS:0000JC,0000LE`; `EMITTER_POSITION_OPTIONAL:` blank; keep `COMPLETION:89` and `CONFIDENCE:93`.
- Confidence: `92/100` for the routing recommendation. The only material uncertainty is original source declaration style: separate literal spelling in two source files versus a shared header/helper that the binary does not prove.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current no-owner row with emitters `0000JC,0000LE`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003FZ`, reopened for `B001-0003FZ-second-pass`.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003FZ-MinimapDownloadWideLiterals-post-migration.md`.
- Current scores and state: `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.

## Executive Recommendation

Keep the current owner/emitter state. The target is a coherent UTF-16LE minimap download literal group:

| Range | Literal/data | Live consumers |
| --- | --- | --- |
| `0x0060d7f4-0x0060d7fc` | `L"000"` plus overlapped IDA dword heads | `sub_41A750`, `sub_453AA0` |
| `0x0060d7fc-0x0060d808` | `L"%03d"` | `sub_41A750`, `sub_453AA0` |
| `0x0060d808-0x0060d818` | `L".mnm"` | `sub_41A750`, `sub_453AA0`, raw `0x00454e6f` |
| `0x0060d818-0x0060d880` | `L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/"` | `sub_41A750`, `sub_453AA0`, raw `0x00454e7b` |
| `0x0060d880-0x0060d894` | `L"%s%s/%s%s"` | `sub_41A750`, `sub_453AA0` |
| `0x0060d894-0x0060d8b8` | `L"Downloading : %d\n"` | `sub_41A750`, `sub_453AA0`, raw `0x00454fcc` |

`FileDownloader` is a proven emitter because message `10000` dispatch calls `sub_41A750`, and that helper consumes the whole group. `MiniMap` is a proven emitter because `MiniMapDownloader::OnThreadTask` calls `sub_453AA0`, that helper consumes the whole group, and an additional raw MiniMap-neighborhood body consumes the suffix, URL, and progress strings. Neither file root should become the canonical owner because both materially use the same physical pooled literals and no shared declaration object is proven.

## Supervisor Active Recheck

- Supervisor instruction: perform an independent second-pass audit under the current owner/emitter model and verify whether the current no-owner-with-emitters state is defensible.
- Split repair required: no. The existing child range is behaviorally coherent and exactly bounded by `0x0060d7f4` at the first minimap literal and `0x0060d8b8` at the next item-shop URL child.
- Documentation repair required before routing: no. Both emitter file roots clear the source-root gate: `FileDownloader` is `85/88` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`; `MiniMap` is `85/86` with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- Coverage-report change required: no. The generated and by-memory coverage rows already show the accepted no-owner-with-emitters state.

## Inference Research Guidance Check

- `by-structure.md` separates semantic ownership from output routing. Lines 237-243 define `CANONICAL_OWNER` as the direct semantic owner and `EMITTER_UIDS` as one or more output routes.
- `by-structure.md` line 243 explicitly covers this case: pooled string literals or shared constants can keep `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts.
- `inference_research.md` warns that nearby `.rdata` placement and consumer xrefs are not proof of source ownership by themselves, especially when strings can be pooled. I therefore used xref fanout, function containment, caller routes, raw PE reference forms, adjacent child boundaries, and negative evidence before accepting the emitter-only route.
- Existing documentation was treated as a lead, not proof. The current page and prior B002 report were rechecked against live IDA MCP and a fresh PE scan.

Facts versus inference:

- IDA/PE facts: exact bytes, xrefs, containing functions, dispatcher call routes, raw helper non-function status, and absence of RVA/rel32 reference forms.
- Documentation facts: current page metadata, file-root scores/paths, and adjacent child/container states.
- Inference: no single canonical declaration owner is defensible; both FileDownloader and MiniMap are source-use emitters.

## Evidence Standards Used

- IDA MCP session: `b001_0003gy`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x00400000`, auto-analysis ready, Hex-Rays ready.
- IDA MCP tools used: `server_health`, `xrefs_to`, `lookup_funcs`, `analyze_component`, `analyze_function`, `decompile`, `get_bytes`, `get_string`, `make_signature_for_range`, and `find_regex`.
- Raw PE evidence: section mapping, exact block uniqueness, UTF-16LE byte decoding, absolute VA hit scan, RVA negative scan, and rel32 negative scan.
- Documentation evidence: target page, prior B002 report, `by-structure.md`, `inference_research.md`, `FileDownloader.md`, `MiniMap.md`, `DownloadMinimapFile.md`, `MiniMapDownloader.md`, `CashShopDownloaderLiterals.md`, and adjacent literal children.

## IDA MCP Facts

Server/session facts:

| Check | Result |
| --- | --- |
| MCP session | `b001_0003gy` |
| Input path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` |
| IDB path | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` |
| Image base | `0x400000` |
| Auto-analysis / Hex-Rays | ready / ready |

Function and route facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0041a750` | `sub_41A750`, size `0x2ae`, prototype `void *__stdcall(int)` | FileDownloader message `10000` minimap download helper. |
| `0x0041b110` | `sub_41B110`, size `0x70` | FileDownloader dispatcher; case `10000` calls `sub_41A750` at `0x0041b168`. |
| `0x00453a00` | `sub_453A00`, size `0x2f` | MiniMapDownloader task dispatch; message `0` calls `sub_453AA0` at `0x00453a16`. |
| `0x00453aa0` | `sub_453AA0`, size `0x2af`, prototype `char __stdcall(int *)` | MiniMapDownloader direct minimap download helper. |
| `0x00454e30` | not an IDA function | Raw MiniMap-neighborhood helper-shaped body; evidence only, not a separate route. |
| `0x00455040` | not an IDA function; code xref from raw `0x0045503f` | End of raw helper-shaped body. |
| `0x00455050`, `0x00455060`, `0x004550d0` | next modeled functions | Confirms the raw helper lies before a modeled MiniMap support-helper neighborhood. |

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
| `0x0060d8b8` | successor item-shop version URL | `0x0041aa64` in `sub_41AA00` only; confirms target end. |

Component facts:

- `analyze_component` over `0x0041a750` and `0x00453aa0` reports identical WinINet/file callee families: `InternetOpenW`, `InternetOpenUrlW`, `HttpQueryInfoW`, `InternetQueryDataAvailable`, `InternetReadFile`, `WriteFile`, `CloseHandle`, `InternetCloseHandle`, `OutputDebugStringW`, formatter `sub_41B9B0`, CreateFileW-like `unk_69BE34`, and DeleteFileW-like `unk_69BE60`.
- The same component analysis reports no internal call edge between `sub_41A750` and `sub_453AA0`.
- Shared globals/literals used by both modeled helpers are `szAgent`, `0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, and `0x0060d894`.

Decompilation facts:

- `sub_41A750` opens WinINet with `szAgent`, copies `L"000"`, formats `L"%03d"` from the request map id, builds the S3 minimap URL with `L"%s%s/%s%s"` and `L".mnm"`, writes downloaded bytes to the output path at `a1 + 16`, logs `L"Downloading : %d\n"`, and deletes the output path through `unk_69BE60` on failed loop completion.
- `sub_453AA0` performs the same minimap download flow for the MiniMapDownloader task layout: map id at `*a1`, output path after advancing the task pointer, and the same literal/API set.
- `sub_41B110` dispatches message `10000` to `sub_41A750`.
- `sub_453A00` dispatches message `0` to `sub_453AA0`.

Raw helper facts:

- `lookup_funcs` reports `0x00454e30`, `0x00454e6f`, `0x00454e7b`, `0x00454fcc`, and `0x00455040` are not functions.
- `xrefs_to 0x00454e30` reports no incoming references.
- `make_signature_for_range 0x00454e30-0x00455040` returned `unique:true` with a 1356-character signature. This proves the raw body is a stable, unique byte neighborhood, but it still does not prove a callable modeled function or separate source owner.

String/debug search facts:

- IDA `find_regex '(?i)minimap|\.mnm|kru-downloads'` found minimap-related strings and RTTI class names elsewhere, including `MiniMapDownloader` RTTI names, but did not reveal a source-file declaration owner for this literal group.
- IDA `find_regex '(?i)\.pdb|\.cpp|\.cxx|\.h'` returned no string-cache hits. No embedded source/debug path evidence was found by this check.

## Raw PE Facts

Read-only PE scan input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

| Check | Result |
| --- | --- |
| Image base | `0x00400000` |
| `.text` | `0x00401000-0x0060c600`, raw `0x400+0x20b600` |
| `.rdata` | `0x0060d000-0x0066c200`, raw `0x20ba00+0x5f200` |
| Target mapping | `0x0060d7f4-0x0060d8b8` maps to `.rdata` file `0x20c1f4-0x20c2b8`, length `0xc4` |
| Exact target block | Full `0xc4` byte block appears once, at VA `0x0060d7f4` |
| Successor boundary | `0x0060d8b8` begins the distinct UTF-16LE `https://secure.kru.com/itemshop/data/itemshop.ver` child |

String occurrence notes:

- The complete target block is unique.
- Short literals have other physical occurrences outside this target, which is expected for common strings: `L"000"` also appears at `0x006107b2` and `0x00612840`; `L"%03d"` also appears at `0x00612e82`; `L".mnm"` also appears at `0x006107fa`.
- The longer identifying literals are unique at the target addresses: the S3 minimap URL prefix, `L"%s%s/%s%s"`, and `L"Downloading : %d\n"` each appear only at the expected target VA in this scan.

Reference-form scan:

| VA | Absolute VA hits in `.text` | RVA hits | rel32-to-target hits |
| --- | --- | --- | --- |
| `0x0060d7f4` | `0x0041a796`, `0x00453ae6` | none | none |
| `0x0060d7f8` | `0x0041a7a2`, `0x00453aef` | none | none |
| `0x0060d7fc` | `0x0041a7d3`, `0x00453b13` | none | none |
| `0x0060d808` | `0x0041a7e3`, `0x00453b23`, `0x00454e70` | none | none |
| `0x0060d818` | `0x0041a7f3`, `0x00453b33`, `0x00454e7c` | none | none |
| `0x0060d880` | `0x0041a7f8`, `0x00453b38` | none | none |
| `0x0060d894` | `0x0041a989`, `0x00453cd8`, `0x00454fcd` | none | none |
| `0x0060d8b8` | `0x0041aa65` | none | none |

Inference from PE facts: the binary presents direct immediate references from known consumer sites. It does not expose a hidden pointer/RVA table or single shared declaration object for this target.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Owner / Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | Pooled minimap download wide literals | `TRUE` | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` | `89/93` | Keep unchanged. |
| `0x0041a750-0x0041a9fe` | `0002TR` `DownloadMinimapFile` | FileDownloader message `10000` helper using all target literals | `TRUE` | `0000JC`; emits `0000JC` | `80/84` | Below 85/85 as a helper page, but live IDA still proves FileDownloader source use. |
| `0x00453910-0x00453def` | `0000XN` `MiniMapDownloader` | MiniMapDownloader class/helper range using all target literals | `TRUE` | `0000LE`; emits `0000LE` | `86/90` | Clears route gate and supports MiniMap emitter. |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-neighborhood helper-shaped body using `.mnm`, S3 URL, and progress literal | unknown | none | n/a | Evidence only; no separate emitter. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` `CashShopDownloaderLiterals` | Mixed literal split-audit container | `FALSE` | none | `89/92` | Non-emitting container, not a target owner. |
| `0x0060d8b8-0x0060d94c` | `0003G0` successor | Item-shop version URL/progress literals | `TRUE` | `0000JC`; emits `0000JC` | `86/91` | Confirms target end. |
| `0x0060d94c-0x0060d958` | `0003G1` | Shared ASCII `version` key | `TRUE` | `NONE`; emits `0000JC,0000JE,0000O5` | `88/93` | Adjacent no-owner/multi-emitter precedent. |
| `0x0060d958-0x0060d9c0` | `0003G2` | Item-shop catalog URL | `TRUE` | `0000JC`; emits `0000JC` | `86/92` | FileDownloader-only sibling. |

## Source-Use / Emitter Inventory

### Emitter `0000JC` FileDownloader

Evidence for source use:

- `FileDownloader.md` is a valid file root at `85/88`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`.
- `sub_41B110` dispatches downloader message `10000` to `sub_41A750` at `0x0041b168`.
- `sub_41A750` consumes every literal in the target range and performs the minimap HTTP download flow.
- `DownloadMinimapFile.md` documents this helper as a FileDownloader message helper, while preserving MiniMap feature context.

Emitter decision: keep `0000JC`.

### Emitter `0000LE` MiniMap

Evidence for source use:

- `MiniMap.md` is a valid file root at `85/86`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- `MiniMapDownloader.md` is `86/90` and routes to `0000LE`.
- `sub_453A00` calls `sub_453AA0` for MiniMapDownloader message `0`.
- `sub_453AA0` consumes every literal in the target range and performs the direct minimap HTTP download flow.
- Raw `0x00454e30-0x00455040` consumes `L".mnm"`, the S3 minimap URL prefix, and `L"Downloading : %d\n"` in a unique MiniMap-neighborhood body.

Emitter decision: keep `0000LE`.

### Candidate extra emitter for raw `0x00454e30-0x00455040`

Evidence for:

- Direct raw refs to three target literals exist at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`.
- The range has a unique signature and lies in the MiniMap renderer/control neighborhood.

Evidence against:

- IDA does not model `0x00454e30` as a function.
- `xrefs_to 0x00454e30` reports no incoming references.
- There is no separate `by-file` root, class, or modeled child page for this raw body in the current assignment.
- Its source-use evidence is already represented by `0000LE` MiniMap.

Emitter decision: reject as separate emitter. Treat as supporting evidence for `0000LE`.

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page `0003FZ` already records exact covered data, modeled xrefs, raw MiniMap-side refs, and `EMITTER_UIDS:0000JC,0000LE`.
- `FileDownloader.md` records `DownloadMinimapFile_41A750`, the message `10000` dispatcher route, and the `network/FileDownloader.cpp` source root.
- `MiniMap.md` records the minimap source family, `MiniMapDownloader`, and the `NexusTK/map/` source root.
- `MiniMapDownloader.md` records six functions in the downloader range and directly documents `sub_453AA0` as the MiniMap `.mnm` download helper.
- `CashShopDownloaderLiterals.md` documents the parent `0003AL` as a non-emitting split-audit container and lists `0003FZ` as the shared minimap literal child.
- Adjacent `0003FY` and `0003G1` pages show accepted no-owner/multi-emitter handling for pooled shared literals.

Existing docs that remain caveats:

- `DownloadMinimapFile.md` is only `80/84`. This should be improved in a separate task, but it does not invalidate FileDownloader as an emitter because the file root clears `85/85` and this second-pass IDA evidence directly verifies the `sub_41A750` source-use path.
- `MiniMap.md` still leaves the final compact `MiniMap.cpp` versus dedicated `MiniMapDownloader.cpp` source split open. This is not a blocker because `0000LE` is the current valid file-root emitter.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` already lists `0003FZ` as `no-owner`, owner `NONE`, emitters ``0000JC`,`0000LE``, and staged output path `auto-generated/NexusTK/network/FileDownloader.cpp`.
- The generated output path cell uses the tool-selected first surfaced file. It does not turn `0000JC` into a canonical owner and does not remove `0000LE` as an emitter.
- `by-memory/-coverage-report.md` already contains a correct no-owner-with-emitters explanation for `0003FZ`.

## Ranked Ownership / Emitter Analysis

### 1. `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- Directly matches the current `by-structure.md` owner/emitter split for pooled string literals.
- Both modeled helpers consume the whole target literal group.
- The two helpers have different entry routes and task layouts: FileDownloader message `10000` versus MiniMapDownloader message `0`.
- `analyze_component` reports no internal call edge between the two helpers.
- Raw PE scan found only direct immediate references from the known consumer sites, with no RVA table, rel32 reference pattern, or hidden shared owner object.
- Both file roots are valid source roots and clear the file-root gate.

Evidence against:

- The final original source might have used a shared header or source helper, but the binary does not prove it.
- `0002TR` is below `85/85`, so helper-page evidence should be improved later. The file-root emitter evidence itself is still sufficient.

Decision: accepted. Keep current state unchanged.

### 2. Canonical owner [UID:0000LE] MiniMap

Evidence for:

- The literal contents are minimap-domain-specific: `.mnm`, the KRU S3 minimap URL path, and minimap progress text.
- `MiniMapDownloader` consumes the whole group and has a strong `86/90` page routed to `MiniMap`.
- Raw MiniMap-neighborhood code consumes a subset of the group.

Evidence against:

- `sub_41A750` consumes the whole same physical group from the FileDownloader message path.
- No IDA or PE evidence proves that FileDownloader imports these literals from a MiniMap declaration.
- Assigning canonical ownership to MiniMap would convert a pooled/source-use fact into a semantic ownership claim.

Decision: reject as canonical owner; keep as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] FileDownloader

Evidence for:

- `sub_41A750` consumes the whole group.
- FileDownloader message dispatch is direct and documented.
- Neighboring item-shop literal children `0003G0` and `0003G2` are FileDownloader-owned.

Evidence against:

- `sub_453AA0` consumes the whole group under MiniMapDownloader.
- Raw MiniMap-neighborhood code consumes the most identifying literals.
- The literals are minimap-domain strings rather than generic downloader infrastructure.

Decision: reject as canonical owner; keep as emitter `0000JC`.

### 4. New shared `MinimapDownloadConstants` / `MinimapDownloadShared` owner

Evidence for:

- The two modeled helpers are near-clones and use the same literal group.
- A shared source helper/header is plausible as an original-source possibility.

Evidence against:

- No pointer table, global struct, named declaration object, source/debug path, or call edge proves a shared constants owner.
- The PE scan found direct immediate references only.
- `by-structure.md` says not to invent a standalone global/helper file solely to avoid `CANONICAL_OWNER:NONE`.

Decision: reject. Do not create a new owner or file.

### 5. Further split of `0003FZ`

Evidence for:

- Some sub-literals have raw MiniMap-side refs while others have only the two modeled refs.
- Short literals such as `L"000"`, `L"%03d"`, and `L".mnm"` have duplicate physical occurrences elsewhere in `.rdata`.

Evidence against:

- The exact `0xc4` target block is unique and behaviorally coherent.
- Every meaningful subrange remains part of one minimap download URL/path/progress construction flow.
- Splitting would not produce a single canonical owner for the pieces that matter; it would mostly fragment one documented pooled literal group.
- The successor at `0x0060d8b8` is already correctly split into `0003G0`.

Decision: reject. No split repair is required.

### 6. Reclassify as compiler-generated or non-reconstructable

Evidence for:

- The exact physical pooling/layout is linker/compiler output.

Evidence against:

- The contents are source-authored NexusTK string literals and must appear in reconstructed source-use contexts.
- `by-structure.md` classifies string literals as `source-declared/generated-binary` when source declarations are required but exact bytes are compiler/linker produced.

Decision: reject. Keep `RECONSTRUCTABLE:TRUE`.

## Negative Evidence Summary

- No single canonical owner is proven because FileDownloader and MiniMap both materially use the same physical target group.
- No hidden owner table was found: the PE scan found no RVA hits or rel32-to-target hits for any target literal address.
- No internal call edge exists between `sub_41A750` and `sub_453AA0`; they are parallel consumers, not one owner wrapping the other.
- The raw `0x00454e30-0x00455040` body is not a separate route because IDA does not model it as a function and there are no incoming xrefs to its start.
- The mixed parent `0003AL` is intentionally `RECONSTRUCTABLE:FALSE` and non-emitting; it is an audit container, not a declaration owner.
- The source/debug string scan found no `.pdb`, `.cpp`, `.cxx`, or `.h` strings that would identify an original source file owner.

## Exact Metadata / Coverage Recommendation

No target metadata change is recommended. Keep the header as:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is required. The current row is acceptable and should be kept unless the supervisor wants to rewrite it for second-pass provenance:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002-0003FZ post-migration recheck keeps `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but recommends `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

Generated report expectation: no generated coverage effect. `auto-generated/-ag-memory-coverage.md` should continue to report this row as `no-owner` with emitters ``0000JC`,`0000LE``.

## Score Before / After

| Field | Before second pass | Recommended after second pass | Reason |
| --- | ---: | ---: | --- |
| Completion | `89` | `89` | Existing page already records exact range, literals, xrefs, raw helper caveat, and owner/emitter reasoning. |
| Confidence | `93` | `93` | Fresh IDA and PE evidence reconfirms the current route; uncertainty remains only around original source declaration style. |
| Canonical owner | `NONE` | `NONE` | No single declaration owner is proven. |
| Emitters | `0000JC,0000LE` | `0000JC,0000LE` | Both source-use roots are proven and no additional route clears the gate. |

## Final Recommendation

- Keep `0003FZ` as a reconstructable source-declared/generated-binary pooled literal page.
- Keep `CANONICAL_OWNER:NONE` because FileDownloader and MiniMap both materially consume the physical literal group and no shared declaration owner is proven.
- Keep `EMITTER_UIDS:0000JC,0000LE` because those are the two proven source-use file roots.
- Keep reconstruction C++ blank. This page represents pooled literals that should surface at consuming source sites, not a standalone source object ready for final C++.
- Do not split or reclassify the target.
- Do not create a new `MinimapDownloadConstants` owner.
- Do not edit `by-memory/-coverage-report.md`.

## Follow-Up Actions

- Supervisor actions: if accepted, mark the tracker row executed/applied for `B001-0003FZ-second-pass` and move this report to `research/executed`. No by-* file changes are required.
- A-agent actions: optional future improvement of [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) above `85/85`; this is not needed to keep `0003FZ` routed through the `FileDownloader` file root.
- Future research actions: investigate raw `0x00454e30-0x00455040` only if assigned as its own MiniMap raw-helper/function-repair target.

## Confidence

- Recommendation confidence: `92/100`.
- Score confidence: keep `89/93`.
- Remaining uncertainty: the binary cannot distinguish with certainty between separate identical string-literal spelling in two source files and an unproven shared header/helper declaration. The current no-owner-with-emitters model accurately preserves that uncertainty while still routing proven source uses.

## Validator Results

- Validator commands run: none.
- Reason: this assignment did not edit by-* documentation, generated files, project-level files, or coverage reports. Only this B001 research report was created.
- Dry-run validator modes: not used.
- Memory-range validator modes: not used.
- Unresolved validator warnings/errors: none observed in this assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003FZ-MinimapDownloadWideLiterals-second-pass.md`.
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none.

## Blockers

- None. The relevant IDA MCP, raw PE, generated-report, tracker, and documentation evidence was available and sufficient for a final recommendation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B001/0003FZ-MinimapDownloadWideLiterals-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
