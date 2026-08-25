** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Current No-Owner Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](../../../../../by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) as `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: reconstructable pooled UTF-16LE `HTTPTEST` user-agent literal. It has no defensible single declaration/source owner, but it has two proven source-use emitter routes.
- Required action: no target edit, no split, no merge, no reclassification, no IDA-safe name repair, no C++ entry, and no `by-memory/-coverage-report.md` edit are recommended.
- Confidence: high. Retain `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`, blank `EMITTER_POSITION_OPTIONAL`, and blank `RECONSTRUCTION_CPP`.

This is no-owner, but it is not a non-emitting dead end. `0000JC` and `0000LE` are output/source-use routes, not ownership claims.

## Target

- Target UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Source queue/report row: current Goal 2 no-owner memory sweep; `tools/leaser/Agents/no_owner_b-agent-tracker.md` active row assigned to Agent-B002 on 2026-06-14.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists this item as `no-owner`, owner `NONE`, emitters ``0000JC`,`0000LE``.
- Current scores and parent state: `88/93`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000LE`.
- Prior reports reviewed as historical context only:
  - `tools/leaser/Agents/Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md`
  - `tools/leaser/Agents/Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-sweep.md`
  - `tools/leaser/Agents/Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-second-pass.md`

## Executive Recommendation

Keep the current no-owner/two-emitter model. The target is one physical wide string literal, not a class vtable, not writable global state, not a unique file-local table, and not a named shared constants object. Current IDA MCP and raw PE evidence reconfirm exactly five direct references to the start address:

- FileDownloader-dispatched WinINet helpers: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`
- MiniMap-side paths: modeled `MiniMapDownloader` use at `0x00453ac3`, and raw MiniMap-neighborhood helper use at `0x00454e52`

`CANONICAL_OWNER:NONE` is correct because no single declaration/source owner covers every use. `EMITTER_UIDS:0000JC,0000LE` is also correct because [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) and [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) are both valid file roots with proven source-use contexts. No split repair is needed: `0x0060d7e0-0x0060d7f4` is the `HTTPTEST` UTF-16LE literal plus terminator/alignment, and successor `0x0060d7f4` has a separate xref set covered by sibling [UID:0003FZ][MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md).

## Supervisor Active Recheck

- Triggering instruction: fresh B002 current-state review for [UID:0003FY], a no-owner item with existing emitters `0000JC,0000LE`.
- Split repair requirement: not required. Current bytes, xrefs, and sibling docs support the existing exact range.
- Source-bearing children in scope: only [UID:0003FY]. The enclosing [UID:0003AL][CashShopDownloaderLiterals](../../../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) page is already a non-emitting split-audit container, and siblings were reviewed only for boundary and ownership contrast.
- Shared-report handling: `by-memory/-coverage-report.md` was not edited. No replacement row is required.

## Inference Research Guidance Check

- `by-structure.md` requires `CANONICAL_OWNER` to be the true direct semantic/declaration owner, not the nearest `.rdata` neighbor or the consumer with the most xrefs.
- `by-structure.md` explicitly allows pooled string literals and shared constants to remain `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` for proven source-use contexts.
- `EMITTER_UIDS` is output routing, not ownership. Keeping `0000JC,0000LE` says both reconstructed file roots need this literal at consuming sites; it does not say either file owns a standalone declaration.
- `inference_research.md` cautions that address adjacency and string pooling can mislead source-file ownership. The preceding FileDownloader vtable and enclosing mixed literal pool were treated as leads only.
- Existing docs and prior reports were treated as hypotheses. Current IDA MCP and PE evidence independently reconfirmed the bytes, xrefs, and boundary.

## Evidence Standards Used

Evidence checked:

- Current target page, generated memory coverage rows, active tracker row, and `by-memory/-coverage-report.md`.
- Current related docs: [UID:0003AL] `CashShopDownloaderLiterals`, [UID:0003FZ] `MinimapDownloadWideLiterals`, [UID:0003G0], [UID:0003G1], [UID:0003G2], [UID:0000JC] `FileDownloader`, [UID:0000LE] `MiniMap`, [UID:00004W] `FileDownloader`, [UID:00008D] `MiniMapDownloader`, [UID:0000XN], and [UID:0000XO].
- Live IDA MCP session `b001_0002bd` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: `server_health`, `get_bytes`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `search_text`, `insn_query`, `decompile`, `make_signature_for_range`, and `analyze_component`.
- Independent raw PE byte scan of `NexusTK.exe` for the literal sequence, absolute VA references, RVA references, interior/tail references, and `push` immediate forms.

The evidence is strong because IDA xrefs, rendered listing search, decompiler references, byte searches, raw helper instruction decoding, and raw PE scans agree on one physical literal and the same five direct source-use sites. Confidence remains below final-audit because the stripped binary cannot distinguish repeated pooled `L"HTTPTEST"` call-site literals from an unproven named shared declaration.

## IDA MCP Facts

Session facts:

- Session: `b001_0002bd`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x400000`
- Auto-analysis ready: `true`
- Hex-Rays ready: `true`
- Strings cache ready: `true`

Data and boundary facts:

- `get_bytes 0x0060d7d0 size 96` shows four preceding FileDownloader vtable dwords ending at `0x0060d7df`, then the target bytes:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00
```

- Decoded as UTF-16LE, the target data is `HTTPTEST` followed by terminator/alignment.
- The successor bytes at `0x0060d7f4` begin separate minimap literals: `000`, `%03d`, `.mnm`, S3 minimap URL, `%s%s/%s%s`, and `Downloading : %d\n`.
- `find_bytes` for the full wide `HTTPTEST` sequence returned one IDB hit at `0x0060d7e0`.

Xref facts:

| Address | Current IDA result | Meaning |
| --- | --- | --- |
| `0x0060d7e0` | five xrefs: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` | all current source-use sites for this literal |
| `0x0060d7e4` | zero xrefs | interior `aTptest` label is not a separate referenced child |
| `0x0060d7f2` | zero xrefs | terminator/alignment has no separate route |
| `0x0060d7f4` | two xrefs: `0x0041a794`, `0x00453ae4` | successor minimap-literal child begins here |
| `0x0060d8b8` | one xref: `0x0041aa64` | FileDownloader-only item-shop version URL sibling |
| `0x0060d94c` | three xrefs: `0x0041ad2e`, `0x004227c6`, `0x00580cab` | separate shared `version` key sibling |
| `0x0060d958` | one xref: `0x0041ae84` | FileDownloader-only item-shop catalog URL sibling |
| `0x00454e30` | zero xrefs | raw MiniMap-side helper start has no incoming start reference |

Function membership:

| Use site / address | `lookup_funcs` result |
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

- `sub_41A750` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041a77e`; this is a FileDownloader minimap-message helper route.
- `sub_41AA00` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041aa46`; this is a FileDownloader item-shop version helper route.
- `sub_41AE20` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041ae66`; this is a FileDownloader item-shop catalog helper route.
- `sub_453AA0` decompiles to `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x00453ad4`; this is the modeled MiniMapDownloader route.
- `search_text szAgent` over `0x0041a000-0x00455100` returned exactly five rendered listing hits at `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and `0x00454e52`.
- `find_bytes "68 E0 D7 60 00"` returned exactly the five `push 0x0060d7e0` sites above.
- `find_bytes "E0 D7 60 00"` returned the same five immediate dword occurrences at one byte after those push opcodes.
- `find_bytes "E4 D7 60 00"`, `find_bytes "F2 D7 60 00"`, and `find_bytes "E0 D7 20 00"` returned zero hits, so no direct interior, terminator, or RVA-form reference was found.
- `find_bytes "F4 D7 60 00"` returned two successor-child hits at `0x0041a796` and `0x00453ae6`.

Raw helper facts:

- `insn_query 0x00454e30-0x00455040` decodes a function-shaped raw helper body that starts with stack-cookie setup at `0x00454e30`.
- The raw helper pushes `szAgent` at `0x00454e52`, calls `InternetOpenW` at `0x00454e5d`, pushes `.mnm` at `0x00454e6f`, pushes the S3 minimap URL at `0x00454e7b`, calls `InternetOpenUrlW` at `0x00454ea9`, performs HTTP/query/read/file-write cleanup work, and returns before the modeled successor helpers.
- `make_signature_for_range 0x00454e30-0x00455040` produced a unique signature containing the `push 0x0060d7e0` and minimap literal pushes. This strengthens MiniMap-side consumer evidence, but the absence of an IDA function object and no incoming xref to `0x00454e30` means it does not create a new canonical owner.

Component facts:

- `analyze_component` over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` reports `szAgent` at `0x0060d7e0` as a shared global/string accessed by all four modeled functions.
- The same component analysis reports successor minimap literals at `0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, and `0x0060d894` as shared by `sub_41A750` and `sub_453AA0`, while item-shop progress at `0x0060d91c` is shared by `sub_41AA00` and `sub_41AE20`.

Negative IDA facts:

- No xrefs target the interior `0x0060d7e4` label.
- No xrefs target the terminator/alignment at `0x0060d7f2`.
- No IDA evidence shows a named global declaration object, initializer, source constants table, or unique declaration owner for `HTTPTEST`.
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
| Target VA | `0x0060d7e0` |
| Target raw offset | `0x0020c1e0` |
| Target section | `.rdata` |
| `.text` | VA `0x00001000`, VSZ `0x0020b4ac`, RAW `0x00000400`, RSZ `0x0020b600` |
| `.rdata` | VA `0x0020d000`, VSZ `0x0005f0be`, RAW `0x0020ba00`, RSZ `0x0005f200` |
| `.data` | VA `0x0026d000`, VSZ `0x0002fe24`, RAW `0x0026ac00`, RSZ `0x0000d800` |
| `.rsrc` | VA `0x0029d000`, VSZ `0x00015c38`, RAW `0x00278400`, RSZ `0x00015e00` |

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
| `0x0041a750-0x0041a9fe` | [UID:0002TR] `DownloadMinimapFile` | FileDownloader minimap helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x0041aa00-0x0041ae1c` | [UID:0002TS] `DownloadCashShopVersion` | FileDownloader item-shop version helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x0041ae20-0x0041b10c` | [UID:0002TT] `DownloadCashShopCatalog` | FileDownloader item-shop catalog helper | true | `0000JC` | `80/84` | FileDownloader emitter evidence |
| `0x00453910-0x00453def` | [UID:0000XN] `MiniMapDownloader` | MiniMap downloader worker/helper island | true | `0000LE` | `86/90` | modeled MiniMap emitter evidence |
| `0x00454e30-0x00455040` | raw body inside [UID:0000XO] context | unmodeled WinINet/minimap helper | source-shaped raw body | MiniMap-side evidence only | n/a | supports `0000LE` emitter, not canonical owner |

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
- [UID:0003AL] `CashShopDownloaderLiterals` is a reviewed `RECONSTRUCTABLE:FALSE` split-audit container. Current evidence supports keeping it as a non-emitting physical grouping, not a source owner.
- [UID:0000JC] `FileDownloader` is a valid file root: `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, score `85/88`, and generated file row `emits` to `auto-generated/NexusTK/network/FileDownloader.cpp`.
- [UID:0000LE] `MiniMap` is a valid file root: `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, score `85/86`, and generated file row `emits` to `auto-generated/NexusTK/map/MiniMap.cpp`.
- [UID:0000XO] explicitly records the raw `0x00454e30-0x00455040` helper caveat. Current IDA bytes and signature reconfirm the raw body uses `szAgent` and minimap literals but lacks an IDA function object and incoming refs.
- Siblings [UID:0003G0] and [UID:0003G2] show that FileDownloader-only literals from the same physical pool are assignable to `0000JC` when their xrefs are single-owner. That contrast supports not overclaiming FileDownloader ownership for [UID:0003FY].
- Sibling [UID:0003FZ] uses the same valid no-owner/two-emitter model for shared minimap literals.

Existing docs that are stale, incomplete, or contradicted:

- No contradiction requiring an in-scope edit was found.
- Some older related docs still mention legacy `AUTOGEN_PARENT_UID` terminology. Under current by-structure rules, read that as legacy owner/output-route wording; this target's active header already uses `CANONICAL_OWNER` and `EMITTER_UIDS`.
- IDA/Hex-Rays sometimes renders UTF-16LE strings as CJK-looking previews. Direct bytes and decoded ranges are the authoritative string evidence.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently lists [UID:0003FY] as `no-owner`, owner `NONE`, emitters ``0000JC`,`0000LE``. This is correct.
- `auto-generated/-ag-file-coverage.md` lists both `0000JC` and `0000LE` as `emits` file roots. The staged `.cpp` files are currently empty because this target and many surrounding items have no final C++ blocks, not because the emitter chain is dead.
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

- Created this B002 research report only.
- No by-* target documentation edit is recommended.
- No generated report edit is recommended.
- No `by-memory/-coverage-report.md` edit is recommended.

Exact owner/emitter assignments recommended:

- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:0000JC,0000LE`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `RECONSTRUCTION_CPP` blank.
- Keep `COMPLETION:88` and `CONFIDENCE:93`.

Code-entry/source-placement implications:

- The target is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank emitters, and has average score `(88 + 93) / 2 = 90.5`, so it clears the minimum route/score eligibility gate.
- No final C++ is entered or recommended by this B-agent report. The correct source placement is use-site spelling through FileDownloader and MiniMap contexts unless later source/debug evidence proves a named shared declaration. This memory page should not emit a standalone global declaration.

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

Recommended tracker close-out text for supervisor-owned tracker application:

```markdown
| `0003FY` | 0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` | Agent-B002 | 2026-06-14 | complete-no-change | `Agent-B002/research/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md` | `Agent-B003/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md` |
```

Future work outside this assignment:

- A later focused pass could model or split raw helper body `0x00454e30-0x00455040`. That may improve MiniMap-side code coverage, but it should not change [UID:0003FY]'s owner/emitter state unless new declaration evidence appears.

## Follow-Up Actions

- Supervisor actions: no coverage or target row change required. Optional tracker-only close-out as above.
- A-agent actions: none required.
- B002 future research actions: none for this target unless new source/debug evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: retain `88/93`.
- Emitter confidence: high for `0000JC`; high for `0000LE`.
- Remaining uncertainty: original source spelling and deduplication style only. The binary cannot prove whether the source repeated pooled `L"HTTPTEST"` at call sites or had a named shared declaration.

## Validator Results

- Commands run: none.
- Results: validator was not run because no by-* documentation, generated report, or coverage report was edited.
- Dry runs: none used.
- Unresolved validator warnings/errors: none introduced by this pass.

## Leases

- No lease was required. Per `goal.md`, research reports under `Agent-B002/research` do not require leases.
- No by-* files were edited or leased.
- `current_leases.md` search found no active lease for `0003FY` / `0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString`.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

Observed worktree note: `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and the target file have pre-existing dirty/untracked state in this workspace. This pass did not directly edit those files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B002/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
