** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: reconstructable shared UTF-16LE `HTTPTEST` user-agent literal. It has no defensible single source declaration owner, but it has two proven source-use emitter routes.
- Required action: no target edit, no split, no merge, no reclassification, no IDA-safe name repair, no C++ entry, and no `by-memory/-coverage-report.md` edit are required.
- Confidence: high. Retain current `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, and `EMITTER_UIDS:0000JC,0000LE`.

## Supporting Research

## Target

- Target UID: `0003FY`.
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`.
- Source queue/report row: current Goal 2 no-owner memory sweep assignment; current generated state in `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, `CANONICAL_OWNER:NONE`, and emitters ``0000JC`,`0000LE``.
- Tracker evidence: `tools/leaser/Agents/no_owner_b-agent-tracker.md` still lists this UID in the active 2026-06-14 no-owner sweep area with Agent-B003.
- Prior report reviewed as background only: `tools/leaser/Agents/Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-sweep.md`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, blank `EMITTER_POSITION_OPTIONAL`, blank `RECONSTRUCTION_CPP`.

## Executive Recommendation

Keep the current no-owner/two-emitter model. The target is one physical wide string literal, not a vtable, not writable global state, not a unique file-local table, and not a named shared constants object. Current IDA MCP and raw PE evidence reconfirm exactly five direct references to the start address:

- Three FileDownloader-dispatched WinINet helper refs: `0x0041a773`, `0x0041aa3b`, and `0x0041ae5b`.
- One modeled MiniMapDownloader helper ref: `0x00453ac3`.
- One raw MiniMap-side helper-body ref: `0x00454e52`.

This is the by-structure shared-literal case. `CANONICAL_OWNER:NONE` is correct because no single declaration/source owner covers every use. `EMITTER_UIDS:0000JC,0000LE` is also correct because both [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap` are proven source-use file roots. This target is no-owner, but it is not non-emitting.

No split repair is needed. The range `0x0060d7e0-0x0060d7f4` contains the UTF-16LE `HTTPTEST` literal plus terminator/alignment. The successor at `0x0060d7f4` has a separate xref set and is already covered by sibling [UID:0003FZ] `MinimapDownloadWideLiterals`.

## Supervisor Active Recheck

- Triggering instruction: fresh current-state review for [UID:0003FY] under the Goal 2 no-owner memory sweep.
- Split repair requirement: not required. Current bytes, xrefs, and sibling docs support the existing exact range.
- Source-bearing children in scope: only [UID:0003FY]. Sibling and parent pages were checked for boundary and ownership contrast, not edited.
- Shared-report handling: `by-memory/-coverage-report.md` was not edited. No replacement row is required.

## Inference Research Guidance Check

- `by-structure.md` separates direct semantic ownership from generated-output routing. `CANONICAL_OWNER` must be the true direct owner, while `EMITTER_UIDS` records output routes.
- The same guidance explicitly permits compiler/linker-pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while using multiple emitters when source-use contexts are proven.
- `inference_research.md` warns that `.rdata` adjacency and string pooling do not prove source-file ownership. The preceding FileDownloader vtable and enclosing physical literal pool were treated as leads only.
- Existing docs and prior reports were treated as hypotheses. Current IDA MCP and PE evidence independently reconfirmed the bytes, xrefs, function membership, no-interior-ref state, and range boundary.

## Evidence Standards Used

Evidence checked:

- Current target page, active tracker row, generated memory coverage rows, and `by-memory/-coverage-report.md`.
- Current related docs: [UID:0003AL] `CashShopDownloaderLiterals`, [UID:0003FZ] `MinimapDownloadWideLiterals`, [UID:0003G0], [UID:0003G1], [UID:0003G2], [UID:0000JC] `FileDownloader`, [UID:0000LE] `MiniMap`, [UID:00004W] `FileDownloader`, [UID:00008D] `MiniMapDownloader`, [UID:0000XN], and [UID:0000XO].
- Live IDA MCP session `b001_0002bd` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: `server_health`, `get_bytes`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `search_text`, `decompile`, `disasm`, and `make_signature_for_range`.
- Independent raw PE byte scan of `NexusTK.exe` for the literal sequence, absolute VA references, RVA references, and push-immediate forms.

The evidence is strong enough for the current recommendation because IDA xrefs, rendered listing search, decompiler references, byte-pattern search, raw helper bytes, and raw PE scanning all agree on one physical literal and the same five direct source-use sites. Confidence remains below final-audit because the stripped binary cannot prove whether the original source repeated `L"HTTPTEST"` at call sites or had a named shared declaration that was later pooled.

## IDA MCP Facts

Session facts:

- Session: `b001_0002bd`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Image base: `0x00400000`.
- Auto-analysis ready: `true`; Hex-Rays ready: `true`; strings cache ready: `true`.

Data and boundary facts:

- `get_bytes` at `0x0060d7d0` shows FileDownloader vtable dwords through `0x0060d7df`, followed by:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00
```

- Decoded as UTF-16LE, the target data is `HTTPTEST` plus terminator/alignment.
- The successor bytes at `0x0060d7f4` begin separate minimap literals: `000`, `%03d`, `.mnm`, the S3 minimap URL, `%s%s/%s%s`, and `Downloading : %d\n`.
- `find_bytes` for the full wide `HTTPTEST` sequence returned exactly one IDB hit at `0x0060d7e0`.

Xref facts:

| Address | Current IDA result | Meaning |
| --- | --- | --- |
| `0x0060d7e0` | five xrefs: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` | all direct source-use sites for the target literal |
| `0x0060d7e4` | zero xrefs | interior IDA label `aTptest` is not a separate referenced child |
| `0x0060d7f2` | zero xrefs | terminator/alignment has no separate route |
| `0x0060d7f4` | two xrefs: `0x0041a794`, `0x00453ae4` | successor minimap-literal child begins here |
| `0x0060d8b8` | one xref: `0x0041aa64` | FileDownloader-only item-shop version URL sibling |
| `0x0060d94c` | three xrefs: `0x0041ad2e`, `0x004227c6`, `0x00580cab` | separate shared `version` key sibling |
| `0x0060d958` | one xref: `0x0041ae84` | FileDownloader-only item-shop catalog URL sibling |
| `0x00454e30` | zero xrefs | raw helper start has no incoming call/xref |

Function membership facts:

| Xref / address | `lookup_funcs` result |
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

Decompiler and listing facts:

- `sub_41A750` contains `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041a77e` and then uses minimap URL/suffix/progress strings. This is the FileDownloader message `10000` minimap helper route.
- `sub_41AA00` contains `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041aa46` and opens the item-shop version URL. This is a FileDownloader route.
- `sub_41AE20` contains `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041ae66` and opens the item-shop catalog URL. This is a FileDownloader route.
- `sub_453AA0` contains `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x00453ad4` and builds a minimap download URL. This is the modeled MiniMapDownloader route.
- `search_text` for `szAgent` over `0x0041a000-0x00455100` returned exactly five hits at the five xref sites above.
- `find_bytes "68 E0 D7 60 00"` returned exactly the five `push 0x0060d7e0` sites above.
- `find_bytes "E4 D7 60 00"`, `find_bytes "F2 D7 60 00"`, and `find_bytes "E0 D7 20 00"` returned zero hits, so no direct interior, terminator, or RVA-form reference was found.
- `make_signature_for_range 0x00454e30-0x00455040` produced a unique function-shaped signature containing `push 0x0060d7e0` and minimap literal pushes. This strengthens MiniMap-side consumer evidence but does not prove a callable source owner because IDA reports no function at the raw start and no incoming refs to `0x00454e30`.

Negative IDA facts:

- No xrefs target the interior `0x0060d7e4` label.
- No xrefs target the terminator/alignment at `0x0060d7f2`.
- No xrefs to the raw helper start `0x00454e30`.
- No current IDA evidence shows a named global declaration object, initializer, source constants table, or unique declaration owner for `HTTPTEST`.
- No single function family covers all five consumers.

## PE / Raw Executable Evidence

Raw executable scanned:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts:

| Field | Value |
| --- | --- |
| Image base | `0x00400000` |
| Target raw offset | `0x0020c1e0` |
| `.text` | VA `0x00001000`, VSZ `0x20b4ac`, RAW `0x00000400`, RSZ `0x20b600` |
| `.rdata` | VA `0x0020d000`, VSZ `0x5f0be`, RAW `0x0020ba00`, RSZ `0x5f200` |
| `.data` | VA `0x0026d000`, VSZ `0x2fe24`, RAW `0x0026ac00`, RSZ `0xd800` |
| `.rsrc` | VA `0x0029d000`, VSZ `0x15c38`, RAW `0x00278400`, RSZ `0x15e00` |

Pattern results:

| Pattern | Hits |
| --- | --- |
| UTF-16LE `HTTPTEST` plus terminator/alignment | one: raw `0x0020c1e0`, VA `0x0060d7e0` |
| `push 0x0060d7e0` (`68 e0 d7 60 00`) | five: VA `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` |
| absolute dword `0x0060d7e0` | same five hits, each preceded by `0x68` |
| RVA dword `0x0020d7e0` | none |
| absolute dword `0x0060d7e4` | none |
| absolute dword `0x0060d7f2` | none |
| absolute dword `0x0060d7f4` | two successor-child hits: VA `0x0041a796`, `0x00453ae6` |

The raw scan independently confirms one physical literal, five absolute source-use sites, no RVA-form refs, no interior refs, and a separate successor literal at `0x0060d7f4`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent / Route | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d794-0x0060d7e0` | [UID:0003AK] `CashShopDownloaderVtables` | mixed vtable split-audit before target | false container | `NONE` | `88/strong` | boundary lead only |
| `0x0060d7a4-0x0060d7e0` | [UID:0003FT] `FileDownloaderVtableData` | FileDownloader vtable data | true | `00004W` | `88/strong` | preceding FileDownloader data; not owner proof for target |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY] target | shared wide `HTTPTEST` user-agent literal | true | `CANONICAL_OWNER:NONE`; emitters `0000JC,0000LE` | `88/93` | keep current state |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ] `MinimapDownloadWideLiterals` | minimap URL/suffix/progress literals | true | `CANONICAL_OWNER:NONE`; emitters `0000JC,0000LE` | `89/93` | sibling, separate xref set |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `CashShopVersionDownloadWideLiterals` | item-shop version URL/progress literals | true | `0000JC` | `86/91` | FileDownloader-only sibling |
| `0x0060d94c-0x0060d958` | [UID:0003G1] `SharedVersionJsonKey` | shared narrow `version` key | true | `CANONICAL_OWNER:NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | separate shared-key sibling |
| `0x0060d958-0x0060d9c0` | [UID:0003G2] `CashShopCatalogDownloadWideUrl` | item-shop catalog URL | true | `0000JC` | `86/92` | FileDownloader-only sibling |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `CashShopDownloaderLiterals` | mixed literal split-audit container | false | `NONE` | `89/92` | not a source owner |
| `0x0041a750-0x0041a9fe` | [UID:0002TR] `DownloadMinimapFile` | FileDownloader message `10000` helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x0041aa00-0x0041ae1c` | [UID:0002TS] `DownloadCashShopVersion` | FileDownloader item-shop version helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x0041ae20-0x0041b10c` | [UID:0002TT] `DownloadCashShopCatalog` | FileDownloader item-shop catalog helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x00453910-0x00453def` | [UID:0000XN] `MiniMapDownloader` | MiniMap downloader worker/helper island | true | `0000LE` | `86/90` | modeled MiniMap emitter evidence |
| `0x00454e30-0x00455040` | raw body inside [UID:0000XO] context | unmodeled WinINet/minimap-like helper | source-shaped raw body | MiniMap-side evidence only | n/a | supports `0000LE` emitter, not canonical owner |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41A750` | FileDownloader minimap-message source-use route; supports emitter `0000JC` |
| `0x0041aa3b` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41AA00` | FileDownloader item-shop version source-use route; supports emitter `0000JC` |
| `0x0041ae5b` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_41AE20` | FileDownloader item-shop catalog source-use route; supports emitter `0000JC` |
| `0x00453ac3` | `push offset szAgent`; `InternetOpenW(&szAgent, ...)` in `sub_453AA0` | modeled MiniMapDownloader source-use route; supports emitter `0000LE` |
| `0x00454e52` | raw `push offset szAgent` inside `0x00454e30-0x00455040` | raw MiniMap-side helper source-use route; supports emitter `0000LE` |
| `0x0060d7e4` | no xrefs | no interior child or rename repair needed |
| `0x0060d7f2` | no xrefs | terminator/alignment only |
| `0x0060d7f4` | refs from `sub_41A750` and `sub_453AA0` | successor belongs to [UID:0003FZ], not this target |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003FY] already records the exact range, current scores, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, `HTTPTEST` bytes, five xrefs, and no-interior/tail-ref state. Current IDA and raw PE evidence reconfirm those facts.
- [UID:0003AL] `CashShopDownloaderLiterals` is a reviewed `RECONSTRUCTABLE:FALSE` split-audit container. Current IDA evidence supports keeping it as a non-emitting physical grouping, not as a source owner.
- [UID:0000JC] `FileDownloader` is a valid file root: `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, score `85/88`. Current decompilation confirms three consuming FileDownloader helper routes.
- [UID:0000LE] `MiniMap` is a valid file root: `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, score `85/86`. Current decompilation confirms one modeled MiniMapDownloader route, and raw bytes confirm an additional MiniMap-side helper body.
- [UID:0000XO] explicitly records the raw `0x00454e30-0x00455040` helper caveat. Current IDA bytes and signature reconfirm the raw body uses `szAgent` and minimap literals but lacks an IDA function object and incoming refs.
- Siblings [UID:0003G0] and [UID:0003G2] show that FileDownloader-only literals from the same physical pool are assignable to `0000JC` when their xrefs are single-owner. That contrast supports not overclaiming FileDownloader ownership for [UID:0003FY].
- Sibling [UID:0003FZ] uses the same correct no-owner/two-emitter model for shared minimap literals.

Existing docs that are stale, incomplete, or contradicted:

- No contradiction requiring an in-scope edit was found.
- Some older text in related docs still mentions legacy `AUTOGEN_PARENT_UID` terminology. Under current by-structure rules, read that as legacy owner/output-route wording; the active headers on this target already use `CANONICAL_OWNER` and `EMITTER_UIDS`.
- IDA/Hex-Rays sometimes renders UTF-16LE string refs as CJK-looking previews. Direct bytes and decoded ranges are the authoritative text evidence.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003FY] as `no-owner`, owner `NONE`, emitters ``0000JC`,`0000LE``. This is correct.
- `by-memory/-coverage-report.md` current row matches the evidence and does not need replacement.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE` - accepted

- Evidence for: one physical literal, direct FileDownloader and MiniMap source-use refs, no named declaration object, no initializer/global storage, no single function/source family covering all uses, and current by-structure guidance for pooled literals.
- Evidence against: the literal is reconstructable and should eventually appear in rebuilt source. This is handled by the two emitter routes and does not require a canonical owner.
- Decision: accepted. This is no-owner but not non-emitting.

### 2. [UID:0000JC] `FileDownloader` as canonical owner - rejected

- Evidence for: three of five refs are in FileDownloader helpers, FileDownloader vtable data immediately precedes the literal, and FileDownloader-only siblings in the same pool are properly owned by `0000JC`.
- Evidence against: `sub_453AA0` and raw helper body `0x00454e30-0x00455040` also use the same physical literal on MiniMap-side paths. FileDownloader does not semantically own those MiniMap users.
- Decision: reject canonical ownership. Retain `0000JC` only as an emitter.

### 3. [UID:0000LE] `MiniMap` as canonical owner - rejected

- Evidence for: MiniMapDownloader uses the literal directly, and the raw helper body sits in the MiniMap renderer/control neighborhood and also uses minimap download strings.
- Evidence against: three FileDownloader-dispatched helper bodies use the same physical literal, including item-shop version/catalog code outside MiniMap source ownership.
- Decision: reject canonical ownership. Retain `0000LE` only as an emitter.

### 4. [UID:0003AL] `CashShopDownloaderLiterals` physical container - rejected

- Evidence for: physical containment.
- Evidence against: [UID:0003AL] is a non-emitting split-audit container spanning shared and FileDownloader-only literal children. Physical `.rdata` containment is not declaration ownership.
- Decision: rejected.

### 5. New shared constants/global owner - rejected

- Evidence for: the original source could theoretically have used a shared user-agent constant.
- Evidence against: no debug/source path, global object, initializer, address-taken table, or coherent constants-owner cluster proves that design. Creating a synthetic constants file solely to avoid `NONE` would violate current by-structure guidance.
- Decision: rejected.

### 6. Split, merge, reclassification, or IDA-safe name repair - rejected

- Evidence for: none.
- Evidence against: exact bytes are one wide literal plus terminator/alignment; no xrefs target the interior label or tail; the successor has a separate xref set and child page; the item is source-declared/generated-binary data; IDA `szAgent` is adequate as a search label.
- Decision: keep current range, filename, classification, and score.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: [UID:0003FY] and [UID:0003FZ] should not seed a synthetic shared downloader constants file without declaration evidence.
- Standalone, narrow, or broad source-file inference: not applicable.

## Negative Evidence Summary

- No current evidence proves a canonical declaration owner.
- No interior ref at `0x0060d7e4`; do not split `aTptest`.
- No tail ref at `0x0060d7f2`; do not create a padding/null child.
- No RVA-form refs; all current refs are absolute VA immediates.
- No source/debug/global declaration object for a named user-agent constant.
- No merge with [UID:0003FZ]; successor `0x0060d7f4` has different contents and a different xref set.
- No FileDownloader-only ownership; MiniMap uses are direct and live.
- No MiniMap-only ownership; FileDownloader uses are direct and live.
- No physical-container ownership; [UID:0003AL] is a non-emitting mixed index.

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

Code-entry gate:

- The target is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank emitters, and has average score `(88 + 93) / 2 = 90.5`, so it clears the minimum score/route eligibility gate.
- No final C++ is entered or recommended by this B-agent report. The remaining uncertainty is source spelling and declaration style: the evidence supports emitted source-use literals through FileDownloader and MiniMap, not a standalone declaration owned by this page.

Target header to retain:

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

Current generated row to retain:

```markdown
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

Current `by-memory/-coverage-report.md` row to retain:

```markdown
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001 post-migration and B003 second-pass reviews reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

Exact future work outside this assignment:

- A later focused function-gap pass could model or split raw helper body `0x00454e30-0x00455040`. That is not required for [UID:0003FY] and should not change this target's owner/emitter state unless new declaration evidence appears.

## Follow-Up Actions

- Supervisor actions: none required for coverage rows. Optional tracker-only action: mark this fresh 2026-06-14 pass complete/no-change.
- A-agent actions: none required.
- B003 future research actions: none for this target unless new source/debug evidence appears.

## Confidence

- Recommendation confidence: high, retain `93`.
- Score confidence: retain `88/93`.
- Remaining uncertainty: original source spelling and deduplication style only. The binary cannot distinguish repeated pooled `L"HTTPTEST"` source literals from an unproven named shared constant.

## Validator Results

- Commands run: none.
- Result: validator was not run because no by-* documentation, generated report, or coverage report was edited.
- Dry runs: none used.
- Unresolved validator warnings/errors: none introduced by this pass.

## Lease State

- No lease was required. Per `goal.md`, B003 research reports under `Agent-B003/research` do not require leases.
- No by-* files were edited or leased.
- B003 holds no lease for this target as part of this pass.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md`.
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B003/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
