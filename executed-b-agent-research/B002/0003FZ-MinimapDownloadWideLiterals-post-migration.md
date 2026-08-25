** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Post-Migration Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) as `CANONICAL_OWNER:NONE`, but change it from non-emitting to emitted through `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: no canonical declaration owner is proven for the physical pooled `.rdata` literal group, but two independent source-use contexts are proven strongly enough for emitter routing: [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md).
- Required action: supervisor should update only the target metadata emitter field and derived coverage/tracker rows; do not assign a canonical owner, do not split further, do not create a new shared constants owner, and do not add reconstruction C++.
- Confidence: `91/100` for the post-migration recommendation. Byte/range/xref confidence remains `93/100`; routing confidence is slightly lower because [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) is still `80/84`, although the FileDownloader file root itself clears `85/85` and live IDA evidence directly proves the FileDownloader source-use context.

## Supporting Research

## Target

- Target UID: `0003FZ`.
- Target path: `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner/non-emitting row.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003FZ`.
- Previous report: `tools/leaser/Agents/Agent-B001/research/executed/0003FZ-MinimapDownloadWideLiterals-B001-0003FZ.md`.
- Current scores and parent state: `COMPLETION:89`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.

## Executive Recommendation

The B001 result was correct under the old combined parent model: no single direct source owner should receive the pooled literal group. Under the current split owner/emitter model, blank `EMITTER_UIDS` is no longer the best final state because this target has two proven source-use roots that both need these literals in reconstructed source:

- `0000JC` [FileDownloader](../../../../../by-file/FileDownloader.md): `sub_41A750` / `DownloadMinimapFile` consumes the full literal group through FileDownloader message `10000`.
- `0000LE` [MiniMap](../../../../../by-file/MiniMap.md): `sub_453AA0` / MiniMapDownloader consumes the full literal group, and raw MiniMap-neighborhood code consumes the `.mnm`, S3 URL, and progress literals.

Keep `RECONSTRUCTION_CPP` blank. The page documents pooled source-authored string literals, not a standalone global declaration. The final source should use the literals at the consuming source sites once those functions are reconstructed.

## Supervisor Active Recheck

- Supervisor instruction: perform `B002-0003FZ-post-migration` owner/emitter recheck for a pooled/shared literal group and specifically test whether one or more emitters are justified even if `CANONICAL_OWNER:NONE` remains correct.
- Split repair required: no. The existing `0x0060d7f4-0x0060d8b8` child is already an exact coherent minimap download literal group; further splitting would produce smaller fragments with the same two modeled consumers and would not improve owner or emitter routing.
- Source-bearing child status: the target itself is already `89/93`. No child page was created or repaired in this assignment.

## Inference Research Guidance Check

`by-structure.md` now separates semantic ownership from output routing. It explicitly allows compiler/linker-pooled string literals or shared constants to keep `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts. That rule fits `0003FZ` better than the previous no-owner/non-emitting state.

Facts, documentation evidence, and inference are separated here:

- IDA/PE fact: exact bytes, xrefs, function boundaries, and decompiled consumer behavior.
- Documentation evidence: current by-file/by-memory scores, source-root paths, and existing ownership notes.
- Inference: `FileDownloader` and `MiniMap` are emitters rather than canonical owners because source-use is proven but a single shared declaration owner is not.

## Evidence Standards Used

- IDA MCP evidence: function lookup, xrefs to each literal head, decompiled behavior of `sub_41A750` and `sub_453AA0`, raw helper/function-status checks, and adjacent successor boundary.
- Raw PE evidence: section mapping, exact block uniqueness, decoded UTF-16LE contents, absolute VA pointer hits, RVA-hit scan, and rel32 negative scan.
- Documentation evidence: target page, B001 report, `FileDownloader`, `MiniMap`, `DownloadMinimapFile`, `MiniMapDownloader`, split container `0003AL`, adjacent literal children, and accepted pooled-literal precedent `0003IO`.
- Negative evidence: no hidden pointer/RVA table, no single source declaration artifact, no call edge proving one consumer imports the other consumer's literals, and no safe standalone shared constants owner.

## IDA MCP Facts

Function/range facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0041a750` | `sub_41A750`, size `0x2ae` | FileDownloader message `10000` minimap download helper. |
| `0x0041b168` | inside `sub_41B110` | FileDownloader dispatcher callsite for the helper. |
| `0x00453a00` | `sub_453A00`, size `0x2f` | MiniMapDownloader task dispatch. |
| `0x00453aa0` | `sub_453AA0`, size `0x2af` | MiniMapDownloader direct `.mnm` download helper. |
| `0x00454e30` / `0x00455040` | not IDA functions | Raw MiniMap-side function-shaped body, but no modeled function entry. |
| `0x00455050`, `0x00455060`, `0x004550d0` | next modeled functions | Confirms the raw-body neighborhood boundary. |

Xref facts:

| Literal address | Literal | Direct xrefs |
| --- | --- | --- |
| `0x0060d7f4` | `000` head | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0`. |
| `0x0060d7f8` | overlapping `000` tail | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0`. |
| `0x0060d7fc` | `%03d` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0`. |
| `0x0060d808` | `.mnm` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f`. |
| `0x0060d818` | S3 minimap URL prefix | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b`. |
| `0x0060d880` | `%s%s/%s%s` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0`. |
| `0x0060d894` | `Downloading : %d\n` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc`. |
| `0x0060d8b8` | successor item-shop URL | `0x0041aa64` in `sub_41AA00` only. Confirms the target end. |

Decompilation observations:

- `sub_41A750` is `void *__stdcall sub_41A750(int a1)`. It uses `InternetOpenW(&szAgent)`, seeds a directory string with `L"000"`, formats `%03d`, builds the S3 minimap URL with `%s%s/%s%s`, downloads a `.mnm` file, logs `Downloading : %d\n`, writes to the output path at `a1 + 16`, and deletes a partial file through `dword_69BE60` on failure.
- `sub_453AA0` is `char __stdcall sub_453AA0(int *a1)`. It performs the same minimap download flow but uses the MiniMapDownloader task layout: map id at `*a1`, output path after advancing the task pointer, and direct dispatch from `sub_453A00`.
- The helpers are near-clones, but their task layouts differ and IDA did not show a caller/callee relationship between them. This supports pooled repeated literals rather than single-owner declaration proof.

Negative IDA facts:

- `xrefs_to 0x00454e30` returns no incoming references.
- The raw MiniMap-side helper strengthens MiniMap-source-use evidence, but because it is not a modeled function and lacks an entry xref, it should not become a separate emitter or owner from this assignment.
- IDA names in the range show the target is adjacent to but distinct from `szAgent`/`HTTPTEST` before it and item-shop/FittingRoom data after it.

## Raw PE Facts

Command:

> Executable block R001 was removed from this report and preserved verbatim in [0003FZ-MinimapDownloadWideLiterals-post-migration-removed.md](0003FZ-MinimapDownloadWideLiterals-post-migration-removed.md). The archived block is non-authoritative and must not be executed.

Result:

| Check | Result |
| --- | --- |
| Input | `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`. |
| Image base | `0x00400000`. |
| `.text` | `0x00401000-0x0060c4ac`, raw `0x000400-0x20ba00`. |
| `.rdata` | `0x0060d000-0x0066c0be`, raw `0x20ba00-0x26ac00`. |
| Target file mapping | `0x0060d7f4-0x0060d8b8` maps to `.rdata` file `0x20c1f4-0x20c2b8`, length `0xc4`. |
| Exact block uniqueness | The full `0xc4` byte block appears once, at VA `0x0060d7f4`. |
| Decoded literals | `000`, `%03d`, `.mnm`, `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`, `%s%s/%s%s`, `Downloading : %d\n`. |
| Absolute VA dword hits | Only known `.text` immediates: `0x0041a796`/`0x00453ae6` for `0x0060d7f4`; `0x0041a7d3`/`0x00453b13` for `0x0060d7fc`; `0x0041a7e3`/`0x00453b23`/`0x00454e70` for `0x0060d808`; `0x0041a7f3`/`0x00453b33`/`0x00454e7c` for `0x0060d818`; `0x0041a7f8`/`0x00453b38` for `0x0060d880`; `0x0041a989`/`0x00453cd8`/`0x00454fcd` for `0x0060d894`; `0x0041aa65` for successor `0x0060d8b8`. |
| RVA dword hits | None for any target literal address or successor. |
| rel32 candidates in `.text` | None ending at any target literal address or successor. |

Inference from PE scan: there is no hidden pointer table, RVA table, or relative-reference pattern that would identify a single declaration owner. The physical bytes are a unique pooled literal group with only direct immediate uses.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` target | Pooled minimap download wide literals | `TRUE` | `NONE` | recommend `0000JC,0000LE` | `89/93` | Exact child; no split needed. |
| `0x0041a750-0x0041a9fe` | `0002TR` `DownloadMinimapFile` | FileDownloader message `10000` helper consuming all target literals | `TRUE` | `0000JC` | `0000JC` | `80/84` | Below 85/85 but direct IDA evidence still proves FileDownloader source use. |
| `0x00453910-0x00453def` | `0000XN` `MiniMapDownloader` | MiniMap worker and helper consuming all target literals | `TRUE` | `0000LE` | `0000LE` | `86/90` | Clears gate and supports MiniMap emitter. |
| `0x00454e30-0x00455040` | no exact page | Raw MiniMap-side helper-shaped body consuming three literals | unknown | none | none | n/a | Evidence only; not a separate route. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` split container | Mixed downloader literal pool | `FALSE` | `NONE` | blank | `89/92` | Container only; not an emitter. |
| `0x0060d8b8-0x0060d94c` | `0003G0` successor | FileDownloader item-shop version literals | `TRUE` | `0000JC` | `0000JC` | `86/91` | Confirms target boundary. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041b168` | caller in `sub_41B110` to `sub_41A750` | FileDownloader `OnMessage` dispatch for message `10000`. |
| `0x00453a16` | caller in `sub_453A00` to `sub_453AA0` | MiniMapDownloader task handler direct download path. |
| `0x00454e6f`, `0x00454e7b`, `0x00454fcc` | raw references to `.mnm`, S3 URL, and progress | Additional MiniMap-neighborhood use, but not a modeled function route. |
| `0x0041aa64` / `0x0060d8b8` | successor-only item-shop URL ref | Confirms `0003FZ` must not absorb the FileDownloader item-shop child. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page `0003FZ` already records the exact literal ranges, two modeled consumers, raw MiniMap-neighborhood refs, and no-single-owner blocker. B002 live IDA/PE evidence reconfirms those facts.
- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) is `85/88`, `CANONICAL_OWNER:FILE`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`. It documents `DownloadMinimapFile_41A750` as the message `10000` minimap download helper and warns that `MiniMapDownloader` remains related but separate.
- [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) is `85/86`, `CANONICAL_OWNER:FILE`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`. It documents `MiniMapDownloader`, `DownloadMinimap_453AA0`, and the broader minimap subsystem.
- [UID:0000XN][MiniMapDownloader](../../../../../by-memory/0x00453910-0x00453def.MiniMapDownloader.md) is `86/90`, routed to `0000LE`, and IDA confirms it directly consumes the target literals.
- [UID:0003IO][SharedGmWideString](../../../../../by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) is an accepted post-migration precedent: `CANONICAL_OWNER:NONE` plus multiple emitters for a pooled UTF-16 literal with several independent source-use file roots.

Existing docs that need reinterpretation, not repair:

- The B001 report correctly rejected a single old `AUTOGEN_PARENT_UID`. Its "no-op" result is stale only because the current model now separates `CANONICAL_OWNER` from `EMITTER_UIDS`.
- The target page wording says "not routed" and "parent assignment intentionally blank." The canonical-owner part remains correct, but the emitter part should be updated by the supervisor if target metadata is changed.
- [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) remains below `85/85`. This is a documentation-strength caveat for the helper page, not a blocker for file-root emitter `0000JC`, because `FileDownloader` itself clears the file-root gate and live IDA proves the `sub_41A750` source-use path.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently shows `0003FZ` as no-owner with `NONE` and blank emitters.
- `by-memory/-coverage-report.md` currently says parent remains blank because no single direct source owner covers the pooled group. That text should be updated to explain the no-owner-but-emitting state.

## Ranked Ownership / Emitter Analysis

### 1. `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- Matches `by-structure.md` pooled string-literal rule: no single canonical declaration owner, but multiple proven source-use contexts.
- FileDownloader use is direct, full-range, and semantically real: `sub_41A750` consumes every target literal through dispatcher message `10000`.
- MiniMap use is direct, full-range, and semantically real: `sub_453AA0` consumes every target literal through MiniMapDownloader, with extra raw MiniMap-neighborhood refs to important suffix/URL/progress literals.
- Both file roots clear as generated source roots: `0000JC` is `85/88` with `NexusTK/network/`; `0000LE` is `85/86` with `NexusTK/map/`.
- Existing accepted `0003IO` treatment proves this is valid for pooled literals: no canonical owner, but source-use emitters.

Evidence against:

- `0002TR` is `80/84`, so the specific FileDownloader helper page should be improved later. However, the helper's IDA behavior is directly rechecked here and the FileDownloader file root itself clears the source-root gate.
- The target's reconstruction C++ remains blank. This is acceptable because emitter metadata can record routing without final C++ under the current model.

Decision: accepted.

### 2. Canonical owner [UID:0000LE] `MiniMap`

Evidence for:

- Literal contents are minimap-domain-specific: `.mnm` suffix, KRU S3 minimap URL prefix, and minimap download progress.
- `MiniMapDownloader` is `86/90`, owned by `0000LE`, and consumes the entire literal group.
- Raw `0x00454e30-0x00455040` MiniMap-neighborhood code consumes the `.mnm`, S3 URL, and progress literals.

Evidence against:

- `sub_41A750` consumes the entire group from the FileDownloader message `10000` path.
- There is no call edge, pointer table, shared declaration artifact, or source metadata proving FileDownloader imports these strings from MiniMap.
- Assigning canonical ownership to MiniMap would hide a real FileDownloader source-use context.

Decision: reject as canonical owner; accept as emitter `0000LE`.

### 3. Canonical owner [UID:0000JC] `FileDownloader`

Evidence for:

- `sub_41A750` consumes the entire group and is dispatched by FileDownloader `OnMessage` message `10000`.
- `FileDownloader` owns adjacent item-shop download literal children `0003G0` and `0003G2`.
- The source root is already a valid generated source root.

Evidence against:

- `sub_453AA0` consumes the same full group under MiniMapDownloader.
- Raw MiniMap-neighborhood code consumes three target literals.
- The strings are not generic downloader infrastructure; they are minimap-specific.

Decision: reject as canonical owner; accept as emitter `0000JC`.

### 4. New shared `MinimapDownloadConstants` / `MinimapDownloadShared` owner

Evidence for:

- The two modeled helpers are near-clones using the same WinINet/file API pattern and literals.
- A shared header or helper source is a plausible original-source possibility.

Evidence against:

- PE scan found no pointer table, no RVA table, and no additional storage that represents a source-level constants object.
- IDA shows direct immediate pushes at each consumer, not references to a shared data structure.
- The two helpers have different task layouts and no caller/callee relationship.
- The raw helper has no modeled entry or incoming reference.
- `by-structure.md` explicitly says not to invent a standalone global/helper file solely to avoid `CANONICAL_OWNER:NONE`.

Decision: reject. Do not create a new owner now.

### 5. Further split of `0003FZ`

Evidence for:

- Some literals have only the two modeled helper refs; `.mnm`, S3 URL, and progress also have raw MiniMap-side refs.

Evidence against:

- Every sub-split still has at least FileDownloader and MiniMap source-use, or a raw MiniMap subset plus FileDownloader and MiniMap use.
- Splitting would create smaller pooled-literal fragments without producing a single canonical owner.
- The current group is behaviorally coherent: directory seed, directory format, suffix, URL prefix, URL builder format, and progress text for one minimap download loop.

Decision: reject. No split repair required.

## Negative Evidence Summary

- No single canonical owner is proven: FileDownloader and MiniMap both materially use the full literal group.
- No hidden owner table exists in the PE evidence: no RVA dword hits, no rel32 candidates, and absolute VA hits only match known direct pushes.
- No standalone shared constants/source file is justified: there is no shared storage object, registration array, source-path clue, or function call edge.
- The raw MiniMap-side body is not a safe separate route: it has relevant data refs but no IDA-modeled function entry and no incoming xref to its start.
- Adjacent ranges do not change the recommendation: `0003FY` has broader user-agent consumers, `0003G0`/`0003G2` are FileDownloader item-shop literals, and `0003G1` is a separate shared `version` key.

## Exact Recommended Metadata / Coverage Changes

### Target Header Change

In `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`, change only this header line:

```text
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave these header fields unchanged:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Optional target prose replacement after metadata application:

```text
- Post-migration emitter routing: keep `CANONICAL_OWNER:NONE` because no single source declaration owner is proven for the pooled literal group, but route `EMITTER_UIDS:0000JC,0000LE` because direct IDA xrefs prove source-use contexts in FileDownloader message `10000` and MiniMapDownloader.
```

### Generated Report Expectation

Do not edit `auto-generated/-ag-memory-coverage.md` manually. After the target metadata is applied and the normal project tool flow refreshes generated reports, the `0003FZ` row should remain `no-owner` with owner ``NONE`` but should no longer have blank emitters; it should list ``0000JC`` and ``0000LE`` in the emitter field, matching the accepted `0003IO` no-owner/multi-emitter precedent. Any generated output path cell is tool-selected and should be accepted from the refresh rather than hand-authored in this report.

### `by-memory/-coverage-report.md` Replacement Row

Do not edit `by-memory/-coverage-report.md` directly from this B002 assignment. Replace the current `0003FZ` bullet with:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; B002-0003FZ post-migration recheck keeps `CANONICAL_OWNER:NONE` because no single declaration owner covers the pooled literal group, but recommends `EMITTER_UIDS:0000JC,0000LE` because live IDA/PE evidence proves source-use contexts in FileDownloader message `10000` (`sub_41A750`) and MiniMapDownloader (`sub_453AA0` plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`).
```

### Tracker Row Recommendation

Recommended replacement for `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003FZ` before supervisor metadata application:

```text
| `0003FZ` | `auto-generated/-ag-memory-coverage.md` | 0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` | yes | Agent-B002 | 2026-06-13 | yes | yes | `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE` | no | B002-0003FZ-post-migration completed on 2026-06-13. Final recommendation: keep no canonical owner but add FileDownloader and MiniMap emitters for the pooled minimap download literal group. Pending supervisor application of target metadata, generated/coverage refresh, and normal validation. Report: `Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-post-migration.md`. |
```

After supervisor applies the metadata and refreshes coverage, the `Executed/Applied?` cell can be changed to `yes`.

## Final Recommendation

- Exact changes recommended: set `EMITTER_UIDS:0000JC,0000LE` on `0003FZ`; keep `CANONICAL_OWNER:NONE`.
- Exact parent assignments recommended: no canonical owner assignment.
- Exact items left no-owner/non-emitting and why: `0003FZ` should no longer be non-emitting; it remains no-owner only. The raw helper body remains without an owner/emitter because it is not a modeled function and has no entry xref in this assignment.
- Exact future work outside scope: improve [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) above `85/85` in a separate A/B task, and separately investigate raw `0x00454e30-0x00455040` if the supervisor wants a modeled MiniMap-side helper page.

## Follow-Up Actions

- Supervisor actions: apply the target header emitter change, refresh generated coverage through the normal project tool flow, apply/update the coverage-report row if appropriate, and update the tracker row.
- A-agent actions: if assigned later, update target prose to say no canonical owner but two emitters; improve `0002TR` score/evidence if possible.
- B002 future research actions: none required for this target unless the raw MiniMap-side helper becomes a new assigned target.

## Confidence

- Recommendation confidence: `91/100`.
- Score confidence: keep existing `89/93`; no score change recommended.
- Remaining uncertainty: final original source may have had a shared minimap download helper/header, but the binary evidence does not prove it. The current model handles that uncertainty better with `CANONICAL_OWNER:NONE` plus two proven emitters.

## Validator Results

- Commands run: no validator command was run.
- Results: not applicable; this B002 pass created only a research report and did not edit target by-* docs or generated/project-level files.
- Dry-run/memory-range modes: not used.
- Unresolved validator warnings/errors: none observed in this assignment.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003FZ-MinimapDownloadWideLiterals-post-migration.md`.
- Modified: none outside the B002 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B002/0003FZ-MinimapDownloadWideLiterals-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
