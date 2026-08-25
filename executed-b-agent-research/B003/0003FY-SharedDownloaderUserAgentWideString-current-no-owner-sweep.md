** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Current No-Owner Sweep

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: reconstructable shared UTF-16LE `HTTPTEST` user-agent literal; no canonical declaration owner is proven, but two source-use output routes are proven.
- Required action: no target edit, no split, no merge, no reclassification, no IDA-safe name repair, no C++ code entry, and no `by-memory/-coverage-report.md` edit are required.
- Confidence: high. Retain the current `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`.

## Supporting Research

## Target

- Target UID: `0003FY`.
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`.
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, section `Active 2026-06-14 Remaining No-Owner Memory Sweep`, row for `0003FY`.
- Current supervisor classification: current Goal 2 no-owner memory sweep; this item is no-owner with existing emitters, not a non-emitting dead end.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B002/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-goal2-pass.md`.

## Executive Recommendation

Keep `CANONICAL_OWNER:NONE` and keep both emitters. This target is a single physical wide string literal, not a unique class/file-owned declaration. Live IDA MCP and an independent raw PE scan confirm five direct source-use sites: three FileDownloader-dispatched WinINet helpers and two MiniMap-side users, one modeled and one raw/unmodeled. No single existing file, class, container, or new shared-constants owner is justified as the declaration owner for every use.

This is exactly the by-structure shared-data case: no defensible canonical owner, but multiple proven source-use output routes. [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap` should remain emitters because their consuming source contexts are proven. Do not force the literal under FileDownloader merely because three of five uses are there, and do not force it under MiniMap because the minimap direct worker and raw helper also use it.

No split repair is needed. The target range `0x0060d7e0-0x0060d7f4` contains the `HTTPTEST` UTF-16LE literal plus terminator/alignment. The successor at `0x0060d7f4` has its own minimap literal xrefs and is already represented by sibling [UID:0003FZ].

## Supervisor Active Recheck

- Triggering instruction: recheck current no-owner memory-sweep item [UID:0003FY], with existing emitters `0000JC,0000LE`, against current docs and live IDA evidence.
- Split repair requirement: not required. The range is already exact and the enclosing [UID:0003AL] `CashShopDownloaderLiterals` page is already a non-emitting mixed-literal split inventory.
- Source-bearing children in scope: this exact child is source-declared/generated-binary data and remains reconstructable. Siblings were reviewed for boundary and ownership contrast only.
- Shared-report handling: `by-memory/-coverage-report.md` was not edited. Exact no-op row text is included below for supervisor reference.

## Inference Research Guidance Check

- `by-structure.md` requires `CANONICAL_OWNER` to be the true direct semantic/declaration owner, not the nearest `.rdata` neighbor or the consumer with the most xrefs.
- `by-structure.md` states that pooled string literals and shared constants may remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts. This target fits that rule directly.
- `EMITTER_UIDS` is output routing, not ownership. Keeping `0000JC,0000LE` does not claim either file owned the original declaration; it records that both reconstructed file roots must be able to surface the literal at consuming sites.
- `inference_research.md` cautions against using address adjacency in `.rdata` as ownership proof. The adjacent FileDownloader vtable and enclosing mixed literal container were treated as leads only.
- Existing docs and prior reports were treated as hypotheses until the current IDA MCP and PE scans reconfirmed the bytes, xrefs, and boundary.

## Evidence Standards Used

Evidence types used:

- Current target page, tracker row, generated memory coverage row, and `by-memory/-coverage-report.md` row.
- Current parent/sibling docs: [UID:0003AL], [UID:0003FZ], [UID:0003G0], [UID:0003G1], and [UID:0003G2].
- Current emitter/candidate docs: [UID:0000JC] `FileDownloader`, [UID:00004W] `FileDownloader`, [UID:0000LE] `MiniMap`, [UID:00008D] `MiniMapDownloader`, [UID:0000XN], and [UID:0000XO].
- Live IDA MCP session `b001_0003gy`: `server_health`, `get_bytes`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `make_signature_for_range`, `decompile`, and `search_text`.
- Raw PE byte scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for the literal sequence, VA references, RVA references, and push-immediate forms.

The evidence is strong because IDA xrefs, rendered listing search, decompiler refs, direct byte search, and raw PE search all agree on one physical literal and the same five direct use sites. Confidence remains below final-audit because stripped binaries cannot prove whether the original source repeated `L"HTTPTEST"` at call sites or declared a named shared constant.

## IDA MCP Facts

Session facts:

- Active session: `b001_0003gy`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Image base: `0x00400000`.
- Auto-analysis ready: `true`.
- Hex-Rays ready: `true`.
- Strings cache ready: `true`.

Data/table/padding facts:

- `get_bytes` at `0x0060d7d0` shows four preceding FileDownloader vtable dwords ending at `0x0060d7df`, then bytes at `0x0060d7e0`:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00
```

- Decoded as UTF-16LE, the source string is `HTTPTEST` followed by terminator/alignment.
- The successor bytes at `0x0060d7f4` begin the separate minimap literal sequence `000`, `%03d`, `.mnm`, S3 URL, `%s%s/%s%s`, and `Downloading : %d\n`.
- `find_bytes` for the full wide `HTTPTEST` sequence returned one IDB hit at `0x0060d7e0`.

Xref facts:

| Address | Live IDA xrefs | Meaning |
| --- | --- | --- |
| `0x0060d7e0` | five refs: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` | all source-use sites for this target |
| `0x0060d7e4` | none | interior IDA label `aTptest` is not a separate referenced literal |
| `0x0060d7f2` | none | tail terminator/alignment has no separate route |
| `0x0060d7f4` | two refs: `0x0041a794`, `0x00453ae4` | successor minimap literal child begins here |
| `0x0060d8b8` | one ref: `0x0041aa64` | FileDownloader-only item-shop version URL sibling begins here |
| `0x0060d94c` | three refs: `0x0041ad2e`, `0x004227c6`, `0x00580cab` | separate shared `version` key sibling |
| `0x0060d958` | one ref: `0x0041ae84` | FileDownloader-only item-shop catalog URL sibling begins here |
| `0x00454e30` | none | raw helper start has no incoming xrefs |

Function membership facts from `lookup_funcs`:

| Xref / address | Function membership |
| --- | --- |
| `0x0041a773` | `sub_41A750`, size `0x2ae` |
| `0x0041aa3b` | `sub_41AA00`, size `0x41c` |
| `0x0041ae5b` | `sub_41AE20`, size `0x2ec` |
| `0x00453ac3` | `sub_453AA0`, size `0x2af` |
| `0x00454e52` | not a function |
| `0x00454e30` | not a function |
| `0x00455040` | not a function |
| `0x00455050` | `sub_455050`, size `0x3` |
| `0x00455060` | `sub_455060`, size `0x68` |
| `0x004550d0` | `sub_4550D0`, size `0x10f` |

Decompiler facts:

- `sub_41A750` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041a77e`; this is the FileDownloader message `10000` minimap download helper.
- `sub_41AA00` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041aa46`; this is the FileDownloader item-shop version helper.
- `sub_41AE20` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041ae66`; this is the FileDownloader item-shop catalog helper.
- `sub_453AA0` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x00453ad4`; this is the modeled MiniMapDownloader helper.
- The raw bytes at `0x00454e30-0x00455040` show another stack-cookie WinINet/file-download body with `push 0x0060d7e0` at `0x00454e52`, calls through the InternetOpenW import pointer, minimap suffix/URL/progress literal uses, file writes, cleanup, and a return before `0xcc` padding. IDA does not model it as a function.

Rendered-listing facts:

- `search_text` for `szAgent` over `0x0041a000-0x00455100` returned exactly five hits:
  - `0x0041a773`: `push offset szAgent ; lpszAgent`
  - `0x0041aa3b`: `push offset szAgent ; lpszAgent`
  - `0x0041ae5b`: `push offset szAgent ; lpszAgent`
  - `0x00453ac3`: `push offset szAgent ; lpszAgent`
  - `0x00454e52`: `push offset szAgent`

Byte-pattern facts from IDA MCP:

- `find_bytes "68 E0 D7 60 00"` returned the same five push sites: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52`.
- `find_bytes "E0 D7 60 00"` returned the same five immediate dword occurrences at one byte after those push opcodes.
- `find_bytes "E4 D7 60 00"` returned zero hits.
- `find_bytes "F2 D7 60 00"` returned zero hits.
- `find_bytes "E0 D7 20 00"` returned zero RVA-form hits.

Raw helper signature fact:

- `make_signature_for_range 0x00454e30-0x00455040` produced a unique wildcarded signature containing the user-agent push and minimap literal pushes. This supports the raw MiniMap-side use route, but no incoming start xref means it is not a new canonical owner for this literal.

Negative IDA facts:

- No xrefs target the interior `0x0060d7e4` label.
- No xrefs target the terminator/alignment at `0x0060d7f2`.
- No IDA or byte evidence shows a named global declaration object, initializer, or source constants table for the literal.
- No single function family covers all five consumers.

## PE / Raw Executable Evidence

Raw PE scan target:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE section facts:

| Section | VA | VSZ | RAW | RSZ |
| --- | --- | --- | --- | --- |
| `.text` | `0x00001000` | `0x0020b4ac` | `0x00000400` | `0x0020b600` |
| `.rdata` | `0x0020d000` | `0x0005f0be` | `0x0020ba00` | `0x0005f200` |
| `.data` | `0x0026d000` | `0x0002fe24` | `0x0026ac00` | `0x0000d800` |
| `.rsrc` | `0x0029d000` | `0x00015c38` | `0x00278400` | `0x00015e00` |

Pattern results:

| Pattern | Raw/VA hits |
| --- | --- |
| UTF-16LE `HTTPTEST` plus terminator/alignment | one hit: raw `0x0020c1e0`, VA `0x0060d7e0` |
| `push 0x0060d7e0` (`68 e0 d7 60 00`) | five hits: VA `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` |
| absolute dword `0x0060d7e0` | five hits, each with previous byte `0x68` |
| RVA dword `0x0020d7e0` | none |
| absolute dword `0x0060d7e4` | none |
| absolute dword `0x0060d7f2` | none |
| absolute dword `0x0060d7f4` | two successor-child hits, matching the separate minimap literal refs |

The PE scan independently confirms the same routing as IDA: one physical pooled literal, five absolute source-use sites, no RVA-form refs, no interior refs, and a separate successor child at `0x0060d7f4`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d794-0x0060d7e0` | [UID:0003AK] `CashShopDownloaderVtables` | mixed vtable split-audit before target | false container | `NONE` | `88/strong` | not target; boundary before `szAgent` |
| `0x0060d7a4-0x0060d7e0` | [UID:0003FT] `FileDownloaderVtableData` | FileDownloader vtable data | true | `00004W` | `88/strong` | preceding FileDownloader class-owned data |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY] target | shared wide `HTTPTEST` user-agent literal | true | `NONE`; emitters `0000JC,0000LE` | `88/93` | keep current state |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ] `MinimapDownloadWideLiterals` | minimap URL/suffix/progress literals | true | `NONE`; emitters `0000JC,0000LE` | `89/93` | sibling shared minimap route |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `CashShopVersionDownloadWideLiterals` | item-shop version URL/progress literals | true | `0000JC` | `86/91` | FileDownloader-only sibling |
| `0x0060d94c-0x0060d958` | [UID:0003G1] `SharedVersionJsonKey` | shared narrow `version` key | true | `NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | separate shared-key child |
| `0x0060d958-0x0060d9c0` | [UID:0003G2] `CashShopCatalogDownloadWideUrl` | item-shop catalog URL | true | `0000JC` | `86/92` | FileDownloader-only sibling |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `CashShopDownloaderLiterals` | mixed literal split-audit container | false | `NONE` | `89/92` | parent remains non-emitting container |
| `0x0041a750-0x0041a9fe` | [UID:0002TR] `DownloadMinimapFile` | FileDownloader message `10000` helper | true | `0000JC` | `80/84` | first FileDownloader emitter route |
| `0x0041aa00-0x0041ae1c` | [UID:0002TS] `DownloadCashShopVersion` | FileDownloader message `10002` helper | true | `0000JC` | `80/84` | second FileDownloader emitter route |
| `0x0041ae20-0x0041b10c` | [UID:0002TT] `DownloadCashShopCatalog` | FileDownloader message `10001` helper | true | `0000JC` | `80/84` | third FileDownloader emitter route |
| `0x00453910-0x00453def` | [UID:0000XN] `MiniMapDownloader` | MiniMap downloader worker/helper island | true | `0000LE` | `86/90` | modeled MiniMap emitter route |
| `0x00454e30-0x00455040` | raw body inside [UID:0000XO] context | unmodeled WinINet/minimap-like helper | source-shaped; not split here | MiniMap-side caveat | n/a | supports `0000LE` emitter, not owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41A750` | FileDownloader minimap-message use; supports emitter `0000JC` |
| `0x0041aa3b` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41AA00` | FileDownloader item-shop version use; supports emitter `0000JC` |
| `0x0041ae5b` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41AE20` | FileDownloader item-shop catalog use; supports emitter `0000JC` |
| `0x00453ac3` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_453AA0` | modeled MiniMapDownloader use; supports emitter `0000LE` |
| `0x00454e52` | raw `push offset szAgent` inside `0x00454e30-0x00455040` | raw MiniMap-side helper use; supports emitter `0000LE` |
| `0x0060d7e4` | no xrefs | no interior split needed |
| `0x0060d7f2` | no xrefs | terminator/alignment, no split needed |
| `0x0060d7f4` | separate refs from `sub_41A750` and `sub_453AA0` | successor belongs to [UID:0003FZ], not target |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003FY] already records `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, exact `HTTPTEST` bytes, five xrefs, no interior/tail refs, and current no-owner/two-emitter reasoning. Live IDA and raw PE evidence reconfirmed those facts.
- Parent [UID:0003AL] is a `RECONSTRUCTABLE:FALSE` split-audit container with exact children. It correctly avoids pretending the mixed literal pool is a source owner.
- [UID:0000JC] `FileDownloader` and [UID:00004W] `FileDownloader` document the FileDownloader dispatcher, three WinINet helpers, vtable data ending immediately before `0x0060d7e0`, and network source root. IDA confirms three of the five literal refs are in FileDownloader-dispatched helpers.
- [UID:0000LE] `MiniMap`, [UID:00008D] `MiniMapDownloader`, and [UID:0000XN] document the MiniMapDownloader class/helper island and source root. IDA confirms `sub_453AA0` uses the literal.
- [UID:0000XO] documents the raw `0x00454e30-0x00455040` helper caveat. Current bytes confirm `0x00454e52` is the raw MiniMap-side user-agent reference.
- Siblings [UID:0003G0] and [UID:0003G2] show that FileDownloader-only literals in the same physical pool are assignable to `0000JC` when all xrefs support that. Their existence strengthens the decision not to overclaim FileDownloader ownership for `0003FY`.
- Sibling [UID:0003FZ] shows the same valid no-owner/two-emitter model for shared minimap literals.

Existing docs that are stale, incomplete, or contradicted:

- No contradiction requiring an in-scope edit was found.
- Older change-log mentions of `AUTOGEN_PARENT_UID` are legacy terminology; the current target header already uses `CANONICAL_OWNER` and `EMITTER_UIDS`.
- IDA string rendering can misdecode UTF-16LE strings as odd CJK-looking text in decompiler refs. Direct bytes, not IDA's string preview, are the authoritative text evidence here.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003FY] as `no-owner`, `CANONICAL_OWNER:NONE`, and emitters ``0000JC`,`0000LE``. This is correct.
- `by-memory/-coverage-report.md` already contains a current row matching the evidence. No replacement is required.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE` - accepted

- Evidence for: one physical literal, five direct source-use sites, cross-file consumers in FileDownloader and MiniMap, no named shared declaration object, no initializer/global evidence, no single owner that covers all uses, and by-structure explicitly permits multi-emitter no-owner shared literals.
- Evidence against: the literal is reconstructable and must appear in rebuilt source. That is handled by emitters and does not require a canonical owner.
- Decision: accepted. This is no-owner but not non-emitting.

### 2. [UID:0000JC] `FileDownloader` as canonical owner - rejected

- Evidence for: three of five direct refs are in FileDownloader helpers; FileDownloader vtable data immediately precedes the literal; FileDownloader-only siblings [UID:0003G0] and [UID:0003G2] are correctly assigned to this file.
- Evidence against: the modeled MiniMapDownloader helper `0x00453aa0` and raw MiniMap-side helper `0x00454e30-0x00455040` also use the same physical literal. FileDownloader does not semantically own MiniMap's direct worker source path.
- Decision: reject canonical ownership. Retain `0000JC` as an emitter.

### 3. [UID:0000LE] `MiniMap` as canonical owner - rejected

- Evidence for: the MiniMapDownloader helper and raw MiniMap-side helper both use the literal, and the raw helper also uses minimap suffix/URL/progress literals.
- Evidence against: three FileDownloader-dispatched helpers use the same physical literal, including item-shop version/catalog download code outside MiniMap ownership.
- Decision: reject canonical ownership. Retain `0000LE` as an emitter.

### 4. [UID:0003AL] `CashShopDownloaderLiterals` physical container - rejected

- Evidence for: the target is physically inside this `.rdata` literal pool.
- Evidence against: [UID:0003AL] is explicitly a non-emitting mixed split-audit container; it spans FileDownloader-only, MiniMap-shared, FittingRoom/StartupWindow-shared, and item-shop literals. Physical containment is not declaration ownership.
- Decision: rejected.

### 5. New shared constants/global owner - rejected

- Evidence for: a source project could theoretically have defined a shared user-agent constant.
- Evidence against: no source/debug path, no global storage object, no named declaration, no initializer, no address-taken table, and no surrounding coherent constants group prove such an owner. Creating a new shared file solely to remove `NONE` is disallowed.
- Decision: rejected.

### 6. Split, merge, reclassification, or IDA-safe name repair - rejected

- Evidence for: none.
- Evidence against: the target bytes decode cleanly as one wide literal plus terminator/alignment; no interior/tail xrefs exist; the successor at `0x0060d7f4` has its own xref set and child page; the item is rebuild-relevant source-declared data; IDA label `szAgent` is adequate as search evidence and does not require a documentation rename.
- Decision: keep current range, filename, classification, and score.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: [UID:0003FY] and [UID:0003FZ] should not seed a synthetic shared downloader constants file without declaration evidence; FileDownloader-only siblings remain FileDownloader-owned, and shared siblings already have explicit emitter sets.
- Standalone, narrow, or broad source-file inference: not applicable.

## Negative Evidence Summary

- No direct evidence proves a canonical declaration owner.
- No interior ref at `0x0060d7e4`; do not split off `aTptest`.
- No tail ref at `0x0060d7f2`; do not create a padding/null child.
- No RVA-form refs; all use sites are absolute VA immediates.
- No source/debug/global declaration object for a named user-agent constant.
- No merge with [UID:0003FZ]; successor `0x0060d7f4` has a different xref set and minimap literal contents.
- No FileDownloader-only ownership; MiniMap uses are live and direct.
- No MiniMap-only ownership; FileDownloader uses are live and direct.
- No parent-container ownership; [UID:0003AL] is a non-emitting mixed index.

## Final Recommendation

Exact changes applied or recommended:

- Created this B003 research report only.
- No by-* target documentation edit is recommended.
- No generated report edit is recommended.
- No `by-memory/-coverage-report.md` edit is recommended.

Exact parent/emitter assignments recommended:

- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:0000JC,0000LE`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `RECONSTRUCTION_CPP` blank.
- Keep `COMPLETION:88` and `CONFIDENCE:93`.

Exact items left no-owner/non-emitting and why:

- [UID:0003FY] is left no-owner but not non-emitting. The lack of a canonical owner is because no source declaration owner is proven. The nonblank emitters are retained because FileDownloader and MiniMap source-use routes are proven.

Retain the current target header:

```text
*** UID:0003FY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Exact generated row to retain if the supervisor wants a no-op reference:

```markdown
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

Exact `by-memory/-coverage-report.md` row to retain if the supervisor wants a no-op reference:

```markdown
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001 post-migration and B003 second-pass reviews reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

Exact future work outside this assignment:

- A separate B-agent/code-page pass could eventually split or model raw helper `0x00454e30-0x00455040`, but this is not required for [UID:0003FY] and should not change its owner/emitter state unless new declaration evidence appears.

## Follow-Up Actions

- Supervisor actions: none required. Current rows may remain unchanged.
- A-agent actions: none required.
- B003 future research actions: none for this target. Reopen only if source/debug evidence or a new constants declaration object appears.

## Confidence

- Recommendation confidence: high, `93`.
- Score confidence: retain `88/93`.
- Remaining uncertainty: original source spelling only. The binary cannot distinguish repeated pooled `L"HTTPTEST"` literals from a named shared declaration without source/debug/build metadata.

## Validator Results

- Commands run: none.
- Results: validator was not run because no by-* documentation, generated report, or coverage report was edited. The only changed file is this B003 research report under the agent folder.
- Any unresolved validator warnings/errors: none introduced by this pass.
- Dry runs: none used.

## Lease State

- Before report creation, `current_leases.md` showed one unrelated Agent-B002 research-report lease and no B003 leases.
- The new report file was created as a stub because `leaser.py` rejects nonexistent paths for leasing.
- B003 successfully leased `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-sweep.md`.
- Final state: B003 lease released after finalization; no by-* files were leased or edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-sweep.md`.
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B003/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
