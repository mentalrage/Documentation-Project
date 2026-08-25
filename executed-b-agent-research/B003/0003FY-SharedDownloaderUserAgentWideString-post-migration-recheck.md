** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` unchanged.
- Final disposition: valid reconstructable pooled UTF-16LE `HTTPTEST` user-agent literal with no canonical owner and two proven source-use emitters.
- Required action: no metadata, score, split, merge, reclassification, IDA repair, documentation repair, or coverage-row change is recommended.
- Confidence: high.

Retain:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Score before/after: `88/93 -> 88/93`.

The current no-owner-with-emitters state is defensible under the post-migration model. `CANONICAL_OWNER:NONE` is correct because current IDA and raw PE evidence prove one physical pooled literal used by both FileDownloader and MiniMap-side code, with no named shared declaration, storage object, initializer, or single source root covering every use. `EMITTER_UIDS:0000JC,0000LE` is also correct because the two source-use file roots are directly proven: [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap`.

This is not a non-emitting dead-end reconstructable item. It is a pooled/shared-literal case: no canonical declaration owner is proven, but the consuming source contexts are proven and should keep their emitter routes.

## Supporting Research

## Target

- Target UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Assignment: Goal 2 no-owner memory recheck for Agent-B003
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`
- Current generated state: `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`
- Current target score/state: `88/93`, `RECONSTRUCTABLE:TRUE`, blank C++
- Current range size: `0x14` bytes, 20 decimal bytes. Verified with `int_convert.py`.

Prior reports reviewed as background, not authority:

- `tools/leaser/Agents/Agent-B001/research/executed/0003FY-SharedDownloaderUserAgentWideString-post-migration.md`
- `tools/leaser/Agents/Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-second-pass.md`

## Executive Recommendation

Keep the exact current metadata and generated routing:

| Field | Recommendation | Reason |
| --- | --- | --- |
| `CANONICAL_OWNER` | `NONE` | FileDownloader, MiniMap, the mixed physical container, and a synthetic shared constants owner each overclaim declaration/source ownership. |
| `RECONSTRUCTABLE` | `TRUE` | The literal is source-authored program data used by WinINet downloader code and must be represented by consuming reconstructed source. |
| `EMITTER_UIDS` | `0000JC,0000LE` | Direct source-use contexts are proven in FileDownloader and MiniMap. |
| `EMITTER_POSITION_OPTIONAL` | blank | No special source ordering is needed. |
| `RECONSTRUCTION_CPP` | blank | This page should not emit a standalone declaration; the literal should surface at consuming source sites unless future source/debug evidence proves a named shared declaration. |

The active 90/90+ reconstruction C++ gate is not satisfied for code entry from this page: completion is `88`, and the final source shape is a pooled-use literal rather than a standalone source item.

## Supervisor Active Recheck

The supervisor requested a fresh recheck because this is a current reconstructable no-owner memory item that already has emitters. I rechecked:

- current target metadata;
- generated `-ag-memory-coverage` and `by-memory/-coverage-report` rows;
- `by-structure.md` owner/emitter rules;
- `inference_research.md` pooling/ownership guidance;
- FileDownloader and MiniMap source-root pages;
- exact helper pages for the five known use sites;
- live IDA MCP evidence;
- raw PE byte/pointer evidence.

The item does not need split repair. The exact child range already covers only the `HTTPTEST` UTF-16LE literal plus terminator/alignment, and the enclosing [UID:0003AL] `CashShopDownloaderLiterals` page is already a `RECONSTRUCTABLE:FALSE` split-audit container.

## Inference Research Guidance Check

`by-structure.md` distinguishes `CANONICAL_OWNER` from `EMITTER_UIDS`. It explicitly allows `CANONICAL_OWNER:NONE` with multiple emitters for compiler/linker-pooled strings or shared constants when no single declaration owner is proven but multiple source-use contexts are proven. That rule applies directly here.

`inference_research.md` cautions that `.rdata` adjacency and consumer/read xrefs alone do not prove source-file declaration ownership because linkers may pool strings and reorder constants. This report therefore treats:

- exact bytes, xrefs, containing functions, and raw pointer scans as IDA/PE facts;
- FileDownloader and MiniMap source-root scores and helper ownership as documentation evidence checked against IDA;
- no-owner plus two emitters as the ownership/emitter inference.

## Evidence Standards Used

Evidence used:

- Live IDA MCP session `b001_0003gy` against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP `server_health`, `xrefs_to`, `xref_query`, `lookup_funcs`, `get_bytes`, `find_bytes`, `search_text`, `entity_query`, `analyze_component`, and `make_signature_for_range`.
- Raw PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Current docs for `FileDownloader`, `MiniMap`, `CashShopDownloaderLiterals`, `MinimapDownloadWideLiterals`, `DownloadMinimapFile`, `DownloadCashShopVersion`, `DownloadCashShopCatalog`, and `MiniMapDownloader`.
- Generated rows from `auto-generated/-ag-memory-coverage.md` and `by-memory/-coverage-report.md`.

No dry-run modes were used. No by-* docs or coverage reports were edited.

## IDA MCP Facts

Live MCP state:

- Session: `b001_0003gy`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Image base: `0x00400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`

### Literal And Boundary Facts

`get_bytes` at `0x0060d7d0` confirms the end of the preceding FileDownloader vtable data, followed by the target bytes and successor minimap literal bytes:

```text
a0 b6 41 00 10 b1 41 00 40 69 59 00 b0 b6 41 00
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00
00 00 00 00 30 00 30 00 30 00 00 00 25 00 30 00
33 00 64 00 00 00 00 00 2e 00 6d 00 6e 00 6d 00
```

The target bytes decode as UTF-16LE `HTTPTEST` plus terminator/alignment:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00
```

IDA names in the local range:

- `0x0060d7e0`: `szAgent`
- `0x0060d7e4`: `aTptest`
- `0x0060d7fc`: `a03d`
- `0x0060d808`: `aMnm`
- `0x0060d818`: `aHttpsS3Amazona`

`entity_query strings` did not return a separate string object for the target range, so the decoded UTF-16LE value should be treated as byte-decoding evidence rather than trusting IDA string typing.

### Direct Xrefs To Target

`xrefs_to 0x0060d7e0` reports five direct data references:

| Xref | Containing function | Meaning |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750`, size `0x2ae` | `push offset szAgent ; lpszAgent` in FileDownloader minimap helper. |
| `0x0041aa3b` | `sub_41AA00`, size `0x41c` | `push offset szAgent ; lpszAgent` in FileDownloader cash-shop version helper. |
| `0x0041ae5b` | `sub_41AE20`, size `0x2ec` | `push offset szAgent ; lpszAgent` in FileDownloader cash-shop catalog helper. |
| `0x00453ac3` | `sub_453AA0`, size `0x2af` | `push offset szAgent ; lpszAgent` in MiniMapDownloader helper. |
| `0x00454e52` | no IDA function | `push offset szAgent` in raw MiniMap-neighborhood helper body. |

Interior/tail checks:

- `xrefs_to 0x0060d7e4`: zero.
- `xrefs_to 0x0060d7f2`: zero.
- `xrefs_to 0x0060d7f4`: two xrefs, both to the successor minimap literal child.
- `find_bytes E4 D7 60 00`: zero.
- `find_bytes F2 D7 60 00`: zero.

The IDA interior `aTptest` label and the tail null/alignment are not separate source items.

### Consumer Function Facts

`search_text` over `0x0041a750-0x0041b110` finds exactly three FileDownloader-range `szAgent` pushes:

- `0x0041a773` in `sub_41A750`
- `0x0041aa3b` in `sub_41AA00`
- `0x0041ae5b` in `sub_41AE20`

The same FileDownloader range contains the matching `InternetOpenW` calls at:

- `0x0041a77e`
- `0x0041aa46`
- `0x0041ae66`

`search_text` over `0x00453aa0-0x00455040` finds the two MiniMap-side `szAgent` pushes:

- `0x00453ac3` in `sub_453AA0`
- `0x00454e52` in raw code, no containing IDA function

The same MiniMap-side range contains the matching `InternetOpenW` calls at:

- `0x00453ace`
- `0x00454e5d`

`lookup_funcs` confirms:

- `0x0041a773` -> `sub_41A750`
- `0x0041aa3b` -> `sub_41AA00`
- `0x0041ae5b` -> `sub_41AE20`
- `0x00453ac3` -> `sub_453AA0`
- `0x00454e52` -> no function
- `0x00454e30` -> no function
- `0x00455040` -> no function
- following modeled starts: `0x00455050`, `0x00455060`, `0x004550d0`

`xref_query 0x00454e30 direction=to` reports zero xrefs to the raw helper start. The raw body therefore supports MiniMap source-use context but does not become a proven callable source owner by itself.

### Component Analysis

`analyze_component` over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` reports `szAgent` at `0x0060d7e0` as the only shared global/string used by all four modeled downloader helpers.

The same component analysis separates narrower sibling use:

- Minimap successor literals at `0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, and `0x0060d894` are shared by `sub_41A750` and `sub_453AA0`.
- Item-shop progress literal `0x0060d91c` is shared by `sub_41AA00` and `sub_41AE20`.
- Fitting-room state `dword_67A73C` is used by the item-shop helpers only.

This supports the exact split: `HTTPTEST` is broader than the minimap-only successor group and broader than FileDownloader-only item-shop URL children.

### Raw MiniMap-Side Helper

`get_bytes 0x00454e30` shows function-shaped prologue code and an immediate `push 0x0060d7e0`:

```text
55 8b ec b8 c0 8c 01 00 e8 03 29 17 00 a1 24 2f
67 00 33 c5 89 45 fc 53 56 57 33 ff 8b d9 57 57
57 57 68 e0 d7 60 00 ...
```

`make_signature_for_range 0x00454e30-0x00455040` produced a unique function-shaped signature that includes `68 E0 D7 60 00`, minimap suffix/URL references, and progress text references. This strengthens MiniMap source-use evidence while keeping the raw helper itself unrouted until a caller/source boundary is proven.

## PE / Raw Executable Evidence

Raw scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Image base: `0x00400000`
- Target VA: `0x0060d7e0`
- Target RVA: `0x0020d7e0`, decimal `2152416`. Verified with `int_convert.py`.
- Target VA decimal: `6346720`. Verified with `int_convert.py`.
- Target file offset: `0x20c1e0`
- Target size: `0x14`, decimal `20`. Verified with `int_convert.py`.
- Section: `.rdata`

Findings:

| Check | Result |
| --- | --- |
| UTF-16LE `HTTPTEST` plus terminator | One physical hit at file offset `0x20c1e0`, VA `0x0060d7e0`. |
| Exact VA dword `0x0060d7e0` | Five hits. |
| RVA dword `0x0020d7e0` | Zero hits. |
| Any VA dword into `0x0060d7e0-0x0060d7f4` | Exactly the same five start-address hits. |
| Any RVA dword into `0x0060d7e0-0x0060d7f4` | Zero hits. |

The five exact VA dword hits all have preceding byte `0x68`, the x86 `push imm32` opcode:

| File offset | Ref VA | Instruction start |
| --- | --- | --- |
| `0x19b74` | `0x0041a774` | `0x0041a773` |
| `0x19e3c` | `0x0041aa3c` | `0x0041aa3b` |
| `0x1a25c` | `0x0041ae5c` | `0x0041ae5b` |
| `0x52ec4` | `0x00453ac4` | `0x00453ac3` |
| `0x54253` | `0x00454e53` | `0x00454e52` |

This independently confirms no hidden pointer form, RVA form, interior reference, or second physical `HTTPTEST` instance was found.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d7f4` | `0003FY` / target | Shared `L"HTTPTEST"` user-agent literal | `TRUE` | `NONE` | `88/93` | Keep emitters `0000JC,0000LE`. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` `CashShopDownloaderLiterals` | Mixed literal split-audit container | `FALSE` | `NONE` | `89/92` | Non-emitting container only. |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` `MinimapDownloadWideLiterals` | Adjacent shared minimap literal group | `TRUE` | `NONE` | `89/93` | Same two-emitter pattern; not part of this target. |
| `0x0060d8b8-0x0060d94c` | `0003G0` `CashShopVersionDownloadWideLiterals` | FileDownloader item-shop version literals | `TRUE` | `0000JC` | `86/91` | FileDownloader-only sibling. |
| `0x0060d94c-0x0060d958` | `0003G1` `SharedVersionJsonKey` | Shared JSON key | `TRUE` | `NONE` | `88/93` | Different multi-emitter shared-key case. |
| `0x0060d958-0x0060d9c0` | `0003G2` `CashShopCatalogDownloadWideUrl` | FileDownloader item-shop catalog URL | `TRUE` | `0000JC` | `86/92` | FileDownloader-only sibling. |

## Source-Use / Emitter Inventory

| Emitter | Source root | Evidence | Decision |
| --- | --- | --- | --- |
| `0000JC` | `by-file/FileDownloader.md` | Three direct modeled `push offset szAgent` refs in `sub_41A750`, `sub_41AA00`, and `sub_41AE20`; all are FileDownloader-dispatched WinINet helpers documented under FileDownloader. | Keep emitter. |
| `0000LE` | `by-file/MiniMap.md` | One direct modeled `push offset szAgent` ref in `sub_453AA0` under `MiniMapDownloader`, plus raw MiniMap-neighborhood helper `0x00454e30-0x00455040`. | Keep emitter. |
| `0003AL` | `CashShopDownloaderLiterals` container | Physical range contains the target. | Reject; non-emitting split-audit container. |
| New shared constants file | Hypothetical | A named shared declaration is plausible in source style. | Reject; no binary/source evidence proves such an object. |

## Documentation Evidence And IDA Status

Current target page:

- Correctly records `88/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000LE`.
- Correctly describes the range as UTF-16LE `HTTPTEST` plus tail zero/alignment.
- Correctly records five direct xrefs and no interior/tail xrefs.
- Correctly states that the literal should appear at consuming source sites unless future evidence proves a named shared declaration.

`FileDownloader.md`:

- Scores `85/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, and is a valid source root.
- Documents the FileDownloader dispatcher and the three helper routes for message `10000`, `10001`, and `10002`.
- IDA MCP confirms the three target references in those helper functions.

`MiniMap.md`:

- Scores `85/86`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, and is a valid source root.
- Documents the MiniMapDownloader source family and raw minimap helper caveats.
- IDA MCP confirms the modeled MiniMapDownloader target reference and raw MiniMap-neighborhood target reference.

Exact helper docs:

- `DownloadMinimapFile` `0x0041a750-0x0041a9fe` is FileDownloader-owned and uses `HTTPTEST`.
- `DownloadCashShopVersion` `0x0041aa00-0x0041ae1c` is FileDownloader-owned and uses `HTTPTEST`.
- `DownloadCashShopCatalog` `0x0041ae20-0x0041b10c` is FileDownloader-owned and uses `HTTPTEST`.
- `MiniMapDownloader` `0x00453910-0x00453def` is MiniMap-owned and includes `DownloadMinimapFile_453AA0`, which uses `HTTPTEST`.

Generated state:

- `auto-generated/-ag-memory-coverage.md` currently reports `0003FY` as `no-owner`, owner `NONE`, emitters `0000JC`,`0000LE`.
- `by-memory/-coverage-report.md` currently records the same no-owner/two-emitter decision.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- One physical `HTTPTEST` UTF-16LE string instance.
- Five direct references, split across FileDownloader and MiniMap-side code.
- FileDownloader source-use is proven by three modeled functions.
- MiniMap source-use is proven by one modeled function and one raw MiniMap-neighborhood helper.
- No interior/tail references suggest another item or split.
- No RVA or hidden pointer form suggests a missed declaration/table.
- `by-structure.md` explicitly supports this state for pooled literals with multiple source-use contexts.

Evidence against:

- Original source may have had a named shared declaration, but the binary does not prove that.

Decision: accepted.

### 2. Canonical owner `0000JC` FileDownloader

Evidence for:

- Three of five direct refs are FileDownloader-dispatched helpers.
- The target physically follows FileDownloader vtable data.
- FileDownloader is the first generated emitter destination.

Evidence against:

- MiniMapDownloader and raw MiniMap-side helper code materially use the same literal.
- Physical `.rdata` adjacency is weak for pooled constants.
- Assigning FileDownloader as canonical owner would overclaim MiniMap source use.

Decision: reject as canonical owner; keep as emitter.

### 3. Canonical owner `0000LE` MiniMap

Evidence for:

- MiniMap owns the modeled `MiniMapDownloader` use.
- Raw `0x00454e30-0x00455040` use is MiniMap-neighborhood code.
- Adjacent minimap successor literals also use FileDownloader/MiniMap emitter routing.

Evidence against:

- Three direct FileDownloader uses include two item-shop helpers that are not MiniMap code.
- Assigning MiniMap as canonical owner would overclaim FileDownloader source use.

Decision: reject as canonical owner; keep as emitter.

### 4. Physical container `0003AL` CashShopDownloaderLiterals

Evidence for:

- The target lives inside the container range.

Evidence against:

- The container is `RECONSTRUCTABLE:FALSE`.
- It is a mixed split-audit index over FileDownloader, MiniMap, FittingRoom, StartupWindow, and shared literal children.
- It should not emit source.

Decision: reject as owner or emitter.

### 5. New shared constants/global owner

Evidence for:

- A shared user-agent declaration is plausible C++ style.

Evidence against:

- No storage object, pointer table, relocation, initializer, symbol, source/debug record, or unique declaration evidence exists.
- All observed uses are direct immediate references to the pooled literal.
- `by-structure.md` says not to invent a standalone global/helper file solely to avoid `NONE`.

Decision: reject.

### 6. FittingRoom, CashShopVersionRequest, StartupWindow, Socket, or ProtocolSend

Evidence for:

- Related sibling literals have item-shop, fitting-room, or startup/update uses.
- The behavior is network-adjacent because it uses WinINet.

Evidence against:

- `HTTPTEST` xrefs do not land in FittingRoom, StartupWindow, Socket, or ProtocolSend.
- The direct target references are FileDownloader and MiniMap-side downloader code only.
- Socket/ProtocolSend are game transport areas, not the WinINet downloader source route shown here.

Decision: reject as owner and reject as emitter.

## Negative Evidence Summary

Checked and rejected:

- Interior `0x0060d7e4` label as separate literal: no xrefs and no raw pointer hits.
- Tail `0x0060d7f2` as separate item: no xrefs and no raw pointer hits.
- RVA reference form to target/range: none.
- Extra absolute reference into the target range: none beyond the five start-address `push imm32` uses.
- Second physical `HTTPTEST` literal: none.
- Single FileDownloader owner: overclaims MiniMap uses.
- Single MiniMap owner: overclaims FileDownloader uses.
- Physical container owner: non-emitting mixed index.
- Synthetic shared constants owner: unsupported by current binary/source evidence.
- Split or merge: not needed; range is exact and successor `0x0060d7f4` is separately referenced.

One `xref_query direction=both` result produced a forward data xref from `0x0060d7e0` to `0x00540048`; this is an artifact of interpreting UTF-16 string bytes as a possible little-endian pointer and is not ownership evidence.

## Exact Recommended Metadata / Coverage Changes

No change is recommended.

Target header should remain:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Generated row should remain:

```text
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

No `by-memory/-coverage-report.md` replacement is required. If the supervisor wants the retained row restated, keep the current row:

```text
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001 post-migration and B003 second-pass reviews reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

## Final Recommendation

Keep `0003FY` as a no-canonical-owner shared literal with two emitters:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:0000JC,0000LE`
- no reconstruction C++ from this page
- no score change
- no split/merge/reclassification
- no IDA repair
- no by-* edit required

The exact blockers to any different conclusion are:

- no single source route covers all five direct uses without overclaiming;
- no shared declaration/global object is visible;
- no pointer table or initializer proves a central owner;
- no extra source-use context beyond FileDownloader and MiniMap is present for this target.

## Follow-Up Actions

- Supervisor: no action required for this target.
- A-agent: no by-* documentation edit is required.
- Future research: if raw helper `0x00454e30-0x00455040` becomes an assigned split/IDA repair target, keep that work separate from `0003FY`. It can improve MiniMap coverage, but it should not change this literal's canonical owner unless new declaration evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `88/93`.
- Emitter confidence: high for `0000JC`, high for `0000LE`.
- Canonical-owner rejection confidence: high.
- Remaining uncertainty: original source declaration style. The binary cannot currently distinguish repeated local literals pooled by the linker from a named shared `static const wchar_t[]`; that uncertainty blocks canonical ownership but does not block the two proven emitter routes.

## Validator Results

No validator command was run because no by-* or validator-managed files were edited. No dry-run modes were used.

Read-only commands/evidence collected:

- IDA MCP `server_health`
- IDA MCP `xrefs_to`
- IDA MCP `xref_query`
- IDA MCP `lookup_funcs`
- IDA MCP `get_bytes`
- IDA MCP `find_bytes`
- IDA MCP `search_text`
- IDA MCP `entity_query`
- IDA MCP `analyze_component`
- IDA MCP `make_signature_for_range`
- Raw PE byte/reference scan
- `int_convert.py` for cited base conversions

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B003/research/0003FY-SharedDownloaderUserAgentWideString-post-migration-recheck.md`
- Modified:
  - none outside this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B003/0003FY-SharedDownloaderUserAgentWideString-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
