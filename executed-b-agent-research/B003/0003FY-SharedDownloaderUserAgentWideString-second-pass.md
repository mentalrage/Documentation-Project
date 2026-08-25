** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Second-Pass Owner/Emitter Audit

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` unchanged.
- Final disposition: valid pooled UTF-16 string-literal item with no canonical owner and two proven emitter/source-use routes.
- Required action: no metadata, split, reclassification, score, coverage-row, or IDA/documentation repair is recommended.
- Confidence: high.

Retain:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
EMITTER_POSITION_OPTIONAL:
```

Score before: `88/93`. Score after: `88/93`.

The current no-owner-with-emitters state is defensible. `CANONICAL_OWNER:NONE` is correct because the binary evidence proves one pooled `L"HTTPTEST"` physical string used by both FileDownloader and MiniMap-side code, with no named global/static declaration or single source root covering every use. `EMITTER_UIDS:0000JC,0000LE` is correct because direct source-use contexts are proven in [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap`. This is not non-emitting and not a dead ownerless reconstructable item.

## Supporting Research

## Target

- Target UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Assignment: `B003-0003FY-second-pass`
- Current generated state: `CANONICAL_OWNER:NONE`; `EMITTER_UIDS:0000JC,0000LE`
- Prior report reviewed: `tools/leaser/Agents/Agent-B001/research/executed/0003FY-SharedDownloaderUserAgentWideString-post-migration.md`
- Current target scores/state: `88/93`, `RECONSTRUCTABLE:TRUE`, blank C++.

Current generated row already shows the post-migration route:

```text
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

## Executive Recommendation

Do not assign a canonical owner. Do not remove either emitter. Do not add a synthetic shared constants owner.

The two emitters are source-use routes, not ownership claims:

| Emitter | Source root | Evidence |
| --- | --- | --- |
| `0000JC` | `by-file/FileDownloader.md` | Three direct `push 0x0060d7e0` references in FileDownloader-dispatched WinINet helpers: `0x0041a750`, `0x0041aa00`, and `0x0041ae20`. |
| `0000LE` | `by-file/MiniMap.md` | One modeled MiniMapDownloader use at `0x00453aa0` plus raw MiniMap-side helper body evidence at `0x00454e30-0x00455040`. |

The final source should spell `L"HTTPTEST"` at consuming source sites unless later debug/source evidence proves a named shared declaration. This page should not emit a standalone global declaration.

## Supervisor Active Recheck

The supervisor requested an independent second-pass audit because this is a current no-owner memory item with nonblank emitters. The assigned item does not require split repair: the exact range is already a clean `0x14` byte UTF-16LE literal and alignment tail, and the enclosing [UID:0003AL] `CashShopDownloaderLiterals` page is already a non-emitting split-audit container with exact children.

Every source-bearing use context in scope has a clear decision:

- `FileDownloader`: proven source-use emitter.
- `MiniMap`: proven source-use emitter.
- Physical mixed container `0003AL`: not an emitter or owner.
- Synthetic shared constants owner: rejected.

## Inference Research Guidance Check

`by-structure.md` specifically allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals or shared constants when no single declaration owner is proven but multiple source-use contexts are proven. That rule applies directly here.

`inference_research.md` cautions that `.rdata` adjacency and read xrefs alone do not prove source-file ownership because linkers can pool strings and reorder constants. This report therefore separates:

- IDA/documentation facts: exact bytes, xrefs, helper function contexts, and raw helper caveat.
- Raw PE facts: one physical string and five direct absolute references.
- Inference: no canonical owner, but two source-use emitters.

## Evidence Standards Used

Evidence used:

- Current target page and prior B001 report.
- Existing IDA MCP facts recorded in target and helper documentation.
- Independent PE byte/reference scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Candidate source-root docs: `FileDownloader`, `MiniMap`, exact helper pages, and mixed literal container pages.
- Negative evidence: no interior label references, no tail references, no RVA references, no named global declaration, no single source root covering all uses.

The evidence is strong enough to retain emitters because both source roots clear the file-root gate and the direct operand uses land in already documented downloader/minimap functions. It is not strong enough to assign canonical ownership because the string is pooled and every owner candidate overclaims at least one use.

## IDA MCP Facts

Current documentation records the following IDA MCP facts:

- Bytes at `0x0060d7e0` decode as UTF-16LE `HTTPTEST`.
- `xrefs_to 0x0060d7e0` reports five direct references:
  - `0x0041a773` in [UID:0002TR] `DownloadMinimapFile`, routed through `FileDownloader`.
  - `0x0041aa3b` in [UID:0002TS] `DownloadCashShopVersion`, routed through `FileDownloader`.
  - `0x0041ae5b` in [UID:0002TT] `DownloadCashShopCatalog`, routed through `FileDownloader`.
  - `0x00453ac3` in [UID:0000XN] `MiniMapDownloader`, routed through `MiniMap`.
  - `0x00454e52` inside raw/unmodeled helper body `0x00454e30-0x00455040`, recorded as MiniMap-side support context.
- `xrefs_to 0x0060d7e4` and `xrefs_to 0x0060d7f2` report no direct references; IDA's interior `aTptest` label and tail zero/alignment are not separate source items.
- `xrefs_to 0x0060d7f4` reports successor minimap literal refs only, confirming the next child boundary.
- C001 documented the raw `0x00454e30-0x00455040` helper body as a WinINet/file-download-shaped MiniMap-neighborhood body with `push offset szAgent`, `InternetOpenW`, `InternetOpenUrlW`, file writes, progress logging, and cleanup. IDA does not model `0x00454e30` as a function and has no incoming xrefs to its start.
- Component analysis over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` identified `szAgent` as shared by all modeled downloader helpers, while successor minimap literals are shared by only the two minimap download paths.

## Fresh PE / Raw Facts

Independent scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- Image base: `0x00400000`
- Target section: `.rdata`
- Target VA: `0x0060d7e0`
- Target RVA: `0x0020d7e0`
- File offset: `0x0020c1e0`
- Target size: `0x14`
- Target bytes: `48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00`
- UTF-16 words: `0048 0054 0054 0050 0054 0045 0053 0054 0000 0000`
- Surrounding bytes show FileDownloader vtable tail ending before `0x0060d7e0` and successor minimap literal `L"000"` at `0x0060d7f4`.

Raw reference results:

| Pattern | Result |
| --- | --- |
| UTF-16LE `HTTPTEST` plus terminator | One hit at `0x0060d7e0`. |
| Absolute VA dword `0x0060d7e0` | Five hits. |
| `push 0x0060d7e0` | Five hits. |
| RVA dword `0x0020d7e0` | Zero hits. |
| Absolute VA `0x0060d7e4` | Zero hits. |
| Absolute VA `0x0060d7f2` | Zero hits. |
| Absolute VA `0x0060d7f4` | Two hits, matching successor literal uses. |
| Any VA dword into `0x0060d7e0-0x0060d7f4` | Exactly the same five start-address hits. |
| Any RVA dword into `0x0060d7e0-0x0060d7f4` | Zero hits. |

The five absolute hits are all immediate operands with preceding opcode byte `0x68`:

| Dword VA | Instruction start | Context |
| --- | --- | --- |
| `0x0041a774` | `0x0041a773` | `push 0x0060d7e0` in FileDownloader minimap helper. |
| `0x0041aa3c` | `0x0041aa3b` | `push 0x0060d7e0` in FileDownloader cash-shop version helper. |
| `0x0041ae5c` | `0x0041ae5b` | `push 0x0060d7e0` in FileDownloader cash-shop catalog helper. |
| `0x00453ac4` | `0x00453ac3` | `push 0x0060d7e0` in MiniMapDownloader helper. |
| `0x00454e53` | `0x00454e52` | `push 0x0060d7e0` in raw MiniMap-side helper. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d7f4` | `0003FY` / target page | Shared `L"HTTPTEST"` downloader user-agent literal | `TRUE` | `NONE` | `88/93` | Keep emitters `0000JC,0000LE`. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` `CashShopDownloaderLiterals` | Mixed literal split-audit container | `FALSE` | `NONE` | `89/92` | Non-emitting container only. |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` `MinimapDownloadWideLiterals` | Shared minimap download literal group | `TRUE` | `NONE` | `89/93` | Same no-owner/two-emitter pattern. |
| `0x0060d8b8-0x0060d94c` | `0003G0` `CashShopVersionDownloadWideLiterals` | FileDownloader item-shop version/progress literals | `TRUE` | `0000JC` | `86/91` | Single-owner FileDownloader child. |
| `0x0060d958-0x0060d9c0` | `0003G2` `CashShopCatalogDownloadWideUrl` | FileDownloader item-shop catalog URL | `TRUE` | `0000JC` | `86/92` | Single-owner FileDownloader child. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `push offset szAgent` in `DownloadMinimapFile` | FileDownloader source-use context for message `10000`. |
| `0x0041aa3b` | `push offset szAgent` in `DownloadCashShopVersion` | FileDownloader source-use context for message `10002`. |
| `0x0041ae5b` | `push offset szAgent` in `DownloadCashShopCatalog` | FileDownloader source-use context for message `10001`. |
| `0x00453ac3` | `push offset szAgent` in `MiniMapDownloader` | MiniMap source-use context. |
| `0x00454e52` | `push offset szAgent` inside raw `0x00454e30-0x00455040` helper | Additional MiniMap-neighborhood source-use support; not a separate owner. |
| `0x0060d7e4` | No xrefs | Interior IDA label is not a separate literal item. |
| `0x0060d7f2` | No xrefs | Tail null/alignment is not a separate literal item. |
| `0x0060d7f4` | Two xrefs | Successor minimap literal child starts separately. |

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- Target page already records exact bytes, five xrefs, no interior/tail xrefs, raw MiniMap-side helper context, and current `EMITTER_UIDS:0000JC,0000LE`.
- `FileDownloader.md` is `85/88`, has a valid `NexusTK/network/` source path, and owns the dispatcher plus item-shop download literal children.
- `MiniMap.md` is `85/86`, has a valid `NexusTK/map/` source path, and owns the MiniMapDownloader and MiniMap renderer/control aggregate.
- `DownloadMinimapFile`, `DownloadCashShopVersion`, and `DownloadCashShopCatalog` pages all document `HTTPTEST` data refs and FileDownloader routing.
- `MiniMapDownloader` and `MiniMapRendererAndControls` document MiniMap-side modeled and raw use.
- `0003FZ` now uses the same no-owner/two-emitter pattern for adjacent minimap download literals.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` shows `0003FY` as no-owner with emitters `0000JC`,`0000LE`.
- `by-memory/-coverage-report.md` already contains a row explaining the no-owner/two-emitter decision.

No current documentation contradicted the route. The only stale wording is older "parent blank" language in container summaries; under the current model that should be read as no canonical owner, not blank emitters.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`

Evidence for:

- One physical pooled `L"HTTPTEST"` instance.
- FileDownloader has three direct uses in scored FileDownloader-dispatched helper pages.
- MiniMap has one modeled direct use plus a raw MiniMap-side helper body using the same literal.
- Both file roots clear the source-root gate and have valid reconstruction paths.
- `by-structure.md` explicitly permits this model for pooled string literals with multiple proven source-use contexts.

Evidence against:

- The original source may have used a named shared declaration, but there is no binary evidence for that declaration.

Decision: accepted.

### 2. Canonical owner `0000JC` FileDownloader

Evidence for:

- Three of five direct refs are in FileDownloader-dispatched helpers.
- The literal physically follows FileDownloader vtable data.
- `auto-generated` currently reports `FileDownloader.cpp` as the generated destination because it is the first emitter/source route.

Evidence against:

- MiniMapDownloader has a modeled direct use, and raw MiniMap-neighborhood code uses the same literal.
- Physical adjacency to FileDownloader vtable data is weak for pooled `.rdata`.
- Assigning canonical ownership to FileDownloader would overclaim MiniMap source use.

Decision: reject as canonical owner; keep as emitter.

### 3. Canonical owner `0000LE` MiniMap

Evidence for:

- MiniMap owns the direct `MiniMapDownloader` helper and the raw helper context.
- Adjacent successor minimap literals are also shared with MiniMap routes.

Evidence against:

- FileDownloader has three direct uses, including item-shop version/catalog helpers that are not MiniMap source.
- Assigning canonical ownership to MiniMap would overclaim FileDownloader source use.

Decision: reject as canonical owner; keep as emitter.

### 4. Canonical owner or emitter `0003AL` CashShopDownloaderLiterals

Evidence for:

- Physical container covers this range.

Evidence against:

- `0003AL` is explicitly `RECONSTRUCTABLE:FALSE` and non-emitting.
- It is a mixed split-audit container, not a source owner.

Decision: reject.

### 5. New shared owner such as `DownloaderHttpConstants`

Evidence for:

- A shared user-agent constant is plausible source style.

Evidence against:

- No by-global storage object, relocation/pointer table, initializer, source symbol, or unique declaration evidence exists.
- Every observed use is a direct immediate operand to a pooled literal.
- `by-structure.md` warns not to invent a standalone global/helper file solely to avoid `NONE`.

Decision: reject.

## Negative Evidence Summary

Checked and rejected:

- Interior `0x0060d7e4` label as a separate literal: no xrefs.
- Tail `0x0060d7f2` as separate item: no xrefs.
- RVA-form references: none.
- Additional hidden absolute references: none beyond the five known push sites.
- Single FileDownloader owner: overclaims MiniMap uses.
- Single MiniMap owner: overclaims FileDownloader uses.
- Physical container owner: non-emitting mixed index.
- New shared constants owner: plausible but unsupported.
- Split/repair: not needed; range is exact and successor `0x0060d7f4` is separately referenced.

## Final Recommendation

No change.

Retain target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000LE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No `by-memory/-coverage-report.md` replacement is needed. If the supervisor wants the retained row restated, keep this current row:

```text
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001-0003FY post-migration live IDA reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

No C++ should be entered on this page. Even though score is near the current code-entry gate, this item is a pooled source literal that should appear at consuming source sites, not as a standalone emitted declaration from this memory page.

## Follow-Up Actions

- Supervisor: no action required for this target.
- A-agent: no by-* edit required.
- Future research: if the raw `0x00454e30-0x00455040` MiniMap-side helper is assigned as a future split/IDA repair target, keep it separate from this literal decision. It may improve MiniMap code coverage, but it should not create a canonical owner for the pooled `HTTPTEST` literal unless new declaration evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: keep `88/93`; fresh PE evidence confirms the current facts but does not add a new source declaration or final-source shape.
- Emitter confidence: high for `0000JC`, high for `0000LE`.
- Remaining uncertainty: original source declaration style. The binary cannot currently distinguish repeated local literals pooled by the linker from a manually shared `static const wchar_t[]`, so `CANONICAL_OWNER:NONE` remains the most accurate model.

## Validator Results

No validator command was run because no by-* or validator-managed files were edited. No dry-run modes were used.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003FY-SharedDownloaderUserAgentWideString-second-pass.md`
- Modified: none outside this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B003/0003FY-SharedDownloaderUserAgentWideString-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
