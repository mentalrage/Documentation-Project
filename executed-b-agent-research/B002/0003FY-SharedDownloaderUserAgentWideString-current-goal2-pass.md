** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep `CANONICAL_OWNER:NONE` and retain `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: reconstructable shared UTF-16LE user-agent literal with two proven source-use emitter roots.
- Required action: no target edit, no split, no merge, no reclassification, no score change, and no coverage-report replacement required.
- Confidence: high; current `88/93` remains justified.

## Supporting Research

## Target
- Target UID: `0003FY`.
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`.
- Source queue/report row: current `auto-generated/-ag-memory-coverage.md` lists this row as `no-owner` with `CANONICAL_OWNER` `NONE` and emitters `0000JC`,`0000LE`.
- Current supervisor classification: current Goal 2 no-owner memory recheck; prior reports are background only and were not treated as authority.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`, blank C++.

## Executive Recommendation
- The best direct ownership disposition remains `CANONICAL_OWNER:NONE` because the physical literal is used by FileDownloader helper code and MiniMap helper code, and no source/debug evidence proves a single shared declaration owner.
- The two emitters are still correct: `0000JC` for the FileDownloader WinINet helper paths and `0000LE` for the MiniMap/MiniMapDownloader paths.
- Do not create a standalone shared-constants file, do not assign the literal to the physical `.rdata` container, and do not assign it solely to FileDownloader or MiniMap.
- No final reconstruction C++ should be entered. This page is a shared literal-routing record, not a proven declaration site; final source should spell `L"HTTPTEST"` at consuming source sites unless later source/debug evidence proves a named declaration.

## Supervisor Active Recheck
- Triggering instruction: recheck `[UID:0003FY] by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`, currently no-owner with emitters `0000JC`,`0000LE`, against current docs and live IDA MCP evidence.
- Split repair requirement: not required. The range is already exact: `0x0060d7e0-0x0060d7f4` is the `HTTPTEST` wide literal plus terminator/alignment, and `0x0060d7f4` begins the separate minimap literal child.
- Every source-bearing child in scope is already represented: this target records the shared user-agent literal; sibling `0003FZ` records the minimap wide literals; item-shop-only siblings are assigned to FileDownloader; the shared narrow `version` key has its own emitter set.

## Inference Research Guidance Check
- `by-structure.md` separates canonical declaration ownership from output emission. That rule is decisive here: no single declaration owner is proven, but two source-use file roots are proven.
- `by-structure.md` explicitly allows `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled strings and shared constants. This target fits that case.
- `inference_research.md` cautions that `.rdata` adjacency and IDA names are weak ownership evidence. I treated `szAgent`, the enclosing `CashShopDownloaderLiterals` container, and nearby FileDownloader vtable adjacency as leads only, not proof.
- Existing documentation assumptions treated as uncertain: all prior B001/B003 reports, the current target wording, and the current generated row were rechecked against live xrefs, decompilation, bytes, and raw PE search before accepting them.

## Evidence Standards Used
- Evidence types used: IDA MCP `server_health`, `get_bytes`, `xref_query`, `lookup_funcs`, `entity_query`, `search_text`, `find_bytes`, `disasm`, `decompile`, `find_xref_signatures`, `make_signature_for_range`, current by-* docs, current generated coverage, and raw PE byte/RVA/VA scans.
- The evidence is strong enough because both modeled code and raw executable bytes agree on exactly one physical literal instance and exactly five direct absolute-VA source-use sites.
- Stronger confidence is blocked only by absence of original source/debug proof about whether the compiler pooled repeated `L"HTTPTEST"` literals or the source had a named shared declaration.

## IDA MCP Facts
- Function/range facts:
  - Active IDA MCP session: `b001_0003gy`, `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs` maps `0x0041a773` to `sub_41A750`, `0x0041aa3b` to `sub_41AA00`, `0x0041ae5b` to `sub_41AE20`, and `0x00453ac3` to `sub_453AA0`.
  - `lookup_funcs` reports `0x00454e30`, `0x00454e52`, and `0x00455040` are not functions; following modeled functions begin at `0x00455050`, `0x00455060`, and `0x004550d0`.
  - Hex-Rays decompilation of `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` shows the same first WinINet open shape: `InternetOpenW(&szAgent, 0, 0, 0, 0)`.
- Data/table/padding facts:
  - `get_bytes 0x0060d7e0 size 0x14` returns `48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00`, i.e. UTF-16LE `HTTPTEST` plus terminator/alignment.
  - `get_bytes 0x0060d7d0 size 0x80` shows the target immediately follows FileDownloader vtable data and immediately precedes the separate minimap literal sequence beginning with UTF-16LE `000`.
  - Raw PE scan found the 20-byte `HTTPTEST`/null/pad sequence exactly once at file offset `0x0020C1E0`, VA `0x0060D7E0`.
- Xref facts:
  - `xref_query to 0x0060d7e0` returns exactly five data refs: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and raw/unmodeled `0x00454e52`.
  - `xref_query to 0x0060d7e4` returns zero refs.
  - `xref_query to 0x0060d7f2` returns zero refs.
  - `xref_query to 0x0060d7f4` returns two separate successor refs: `0x0041a794` in `sub_41A750` and `0x00453ae4` in `sub_453AA0`.
  - `find_bytes "68 E0 D7 60 00"` returns exactly five matches at `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and `0x00454e52`.
  - Raw PE scan of absolute dword `0x0060d7e0` found exactly five occurrences and every one is preceded by opcode `0x68` (`push imm32`). Raw PE scan found zero RVA-form `0x0020d7e0`, zero absolute references to interior `0x0060d7e4`, and zero absolute references to tail `0x0060d7f2`.
- Vtable/global/type facts:
  - No vtable, RTTI, global pointer, or initializer writes target this literal. It is consumed as an immediate string pointer argument to `InternetOpenW`.
  - The preceding FileDownloader vtable boundary at `0x0060d7e0` is adjacency only; it does not make FileDownloader the declaration owner of the following pooled literal.
- Negative IDA facts:
  - No xrefs to the interior IDA label `aTptest`.
  - No xrefs to the tail terminator/alignment.
  - No RVA references to the literal.
  - No modeled function object for raw helper start `0x00454e30`; the raw body is evidence for MiniMap-side use, not a standalone source owner.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d7f4` | `0003FY` / target | Shared `HTTPTEST` user-agent literal | Yes | `NONE`; emitters `0000JC,0000LE` | `88/93` | Keep current |
| `0x0060d7e0-0x0060d9c0` | `0003AL` / `CashShopDownloaderLiterals` | Mixed literal-pool audit container | No | `NONE` | `89/92` | Container only; not a declaration owner |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` / `MinimapDownloadWideLiterals` | Shared minimap literals | Yes | `NONE`; emitters `0000JC,0000LE` | `89/93` | Sibling confirms same FileDownloader/MiniMap sharing pattern |
| `0x0060d8b8-0x0060d94c` | `0003G0` / `CashShopVersionDownloadWideLiterals` | Item-shop version URL/progress literals | Yes | `0000JC` | `86/91` | FileDownloader-only sibling |
| `0x0060d94c-0x0060d958` | `0003G1` / `SharedVersionJsonKey` | Shared narrow `version` key | Yes | `NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | Separate shared-key child |
| `0x0060d958-0x0060d9c0` | `0003G2` / `CashShopCatalogDownloadWideUrl` | Item-shop catalog URL | Yes | `0000JC` | `86/92` | FileDownloader-only sibling |
| `0x0041a750-0x0041a9fe` | `0002TR` / `DownloadMinimapFile` | FileDownloader message `10000` minimap helper | Yes | `0000JC` | `80/84` | Proven FileDownloader source-use route, below owner reassignment gate but current file root is documented |
| `0x0041aa00-0x0041ae1c` | `0002TS` / `DownloadCashShopVersion` | FileDownloader message `10002` item-shop version helper | Yes | `0000JC` | `80/84` | Proven FileDownloader source-use route |
| `0x0041ae20-0x0041b10c` | `0002TT` / `DownloadCashShopCatalog` | FileDownloader message `10001` item-shop catalog helper | Yes | `0000JC` | `80/84` | Proven FileDownloader source-use route |
| `0x00453910-0x00453def` | `0000XN` / `MiniMapDownloader` | MiniMapDownloader class/helper island | Yes | `0000LE` | `86/90` | Proven MiniMap source-use route |
| `0x00454e30-0x00455040` | raw body within `0000XO` context | Unmodeled WinINet/minimap-like helper | Source-shaped, not split here | MiniMap-side evidence only | n/a | Future raw-helper research candidate; no target repair required |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `push offset szAgent`; then `InternetOpenW` at `0x0041a77e` in `sub_41A750` | FileDownloader message `10000` route uses the literal |
| `0x0041aa3b` | `push 0x0060d7e0`; then `InternetOpenW` at `0x0041aa46` in `sub_41AA00` | FileDownloader item-shop version route uses the literal |
| `0x0041ae5b` | `push 0x0060d7e0`; then `InternetOpenW` at `0x0041ae66` in `sub_41AE20` | FileDownloader item-shop catalog route uses the literal |
| `0x00453ac3` | `push 0x0060d7e0`; then `InternetOpenW` at `0x00453ace` / decompile line at `0x00453ad4` in `sub_453AA0` | MiniMapDownloader route uses the literal |
| `0x00454e52` | raw listing and bytes show `push offset szAgent`; then `InternetOpenW` at `0x00454e5d` | Raw MiniMap-side helper use; supports `0000LE` emitter, not canonical ownership |
| `0x0060d7f4` successor | separate xrefs at `0x0041a794` and `0x00453ae4` | Confirms target end boundary; successor belongs to minimap literal child |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page already records `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000LE`; live IDA and raw PE evidence confirm that state.
  - `by-file/FileDownloader.md` documents FileDownloader as the network/download root and identifies the three WinINet helpers that consume `HTTPTEST`, while explicitly keeping `MiniMapDownloader` separate.
  - `by-class/MiniMapDownloader.md` and `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` document MiniMap ownership of the modeled `0x00453aa0` helper.
  - `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` records the raw `0x00454e30-0x00455040` WinINet helper caveat with the `0x00454e52` `szAgent` use.
  - `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` documents the exact child split and explains why the parent container is mixed/non-emitting.
  - Sibling `0003FZ` uses the same no-owner/two-emitter model for shared minimap download literals; sibling `0003G0` and `0003G2` demonstrate that FileDownloader-only literals in the same physical pool are assigned when the xrefs justify it.
- Existing docs that are stale, incomplete, or contradicted:
  - No current contradiction requiring repair was found.
  - Prior executed reports are useful background but not authority. This pass reconfirmed the material facts with live IDA MCP and raw PE scanning.
  - IDA `get_string 0x0060d7e0` returned only `H` because the target is a UTF-16LE wide literal with IDA item splitting; direct bytes prove the complete `HTTPTEST` string.
- Generated/coverage report state:
  - Current generated row is already correct as no-owner with emitters `0000JC`,`0000LE`.
  - Current `by-memory/-coverage-report.md` row is already correct and should be retained if supervisor refreshes it.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000LE`
- Evidence for: five direct source-use refs split across FileDownloader helpers and MiniMap/MiniMapDownloader helper bodies; one physical pooled literal; no single declaration-owner proof; `by-structure.md` allows no-owner with emitters for pooled/shared literals.
- Evidence against: the literal is reconstructable and is not dead or external. This is not evidence against the state, because emitters solve source-use output without overclaiming ownership.
- Decision: accepted. This is the best current representation.

### 2. `0000JC` FileDownloader as canonical owner
- Evidence for: three of five direct refs are in FileDownloader-dispatched helpers; FileDownloader owns adjacent vtable data and item-shop-only sibling literals; generated destination currently points at `network/FileDownloader.cpp`.
- Evidence against: `0x00453ac3` is a modeled MiniMapDownloader helper ref and `0x00454e52` is a raw MiniMap-side helper ref. Assigning the physical literal to FileDownloader would hide real MiniMap source-use routes.
- Decision: reject canonical ownership; keep `0000JC` as an emitter.

### 3. `0000LE` MiniMap as canonical owner
- Evidence for: `sub_453AA0` is MiniMapDownloader code, the raw `0x00454e30-0x00455040` body sits in the MiniMap renderer/control neighborhood, and both use the literal.
- Evidence against: three direct FileDownloader helper refs use the same physical literal. MiniMap cannot claim the FileDownloader item-shop helpers.
- Decision: reject canonical ownership; keep `0000LE` as an emitter.

### 4. `0003AL` physical literal container as owner
- Evidence for: the target is physically inside the mixed `CashShopDownloaderLiterals` pool.
- Evidence against: `0003AL` is a non-emitting split-audit container for mixed literal data, not a source file or declaration owner. It deliberately spans children with different owners/emitter sets.
- Decision: rejected.

### 5. New shared constants/global owner
- Evidence for: a named source constant could theoretically have existed for an HTTP user-agent string.
- Evidence against: no source/debug path, no initializer/write evidence, no global object, no dedicated references, and no neighboring named constants group proves a source-level shared declaration. Creating a new shared file solely to avoid `NONE` is disallowed by the owner/emitter rules.
- Decision: rejected.

### 6. FittingRoom, StartupWindow, JsonCpp, or other nearby owners
- Evidence for: some neighboring literal children have FittingRoom/StartupWindow uses, especially the separate `version` key.
- Evidence against: no refs from these owners to `0x0060d7e0`. Their involvement applies to other child literals, not this target.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: not applicable.
- Candidate related items that belong: not applicable.
- Candidate related items rejected: `0003FY` should not seed a shared constants file; siblings already have better per-child routing.
- Standalone, narrow, or broad source-file inference: not applicable; this is a pooled literal/source-use routing case.

## Negative Evidence Summary
- Checked and rejected interior ownership from `0x0060d7e4`: zero IDA xrefs and zero raw absolute references.
- Checked and rejected tail/terminator ownership from `0x0060d7f2`: zero IDA xrefs and zero raw absolute references.
- Checked and rejected RVA-form references: raw PE scan found zero `0x0020d7e0` references.
- Checked and rejected successor merge: `0x0060d7f4` has separate xrefs in only the two minimap paths and belongs to sibling `0003FZ`.
- Checked and rejected FileDownloader-only ownership: MiniMap modeled and raw uses are real.
- Checked and rejected MiniMap-only ownership: three FileDownloader uses are real.
- Checked and rejected synthetic shared declaration/global ownership: no source/debug/global/init evidence proves it.
- Checked and rejected raw helper as a reason to split this literal: it may deserve future code-page research, but it does not change the literal range, owner, or emitter set.

## Final Recommendation
- Exact changes applied or recommended: created this current research report only. No by-* documentation changes are recommended.
- Exact parent assignments applied or recommended: retain `CANONICAL_OWNER:NONE`; retain `EMITTER_UIDS:0000JC,0000LE`; retain `RECONSTRUCTABLE:TRUE`; retain `COMPLETION:88` and `CONFIDENCE:93`.
- Exact items left no-owner/non-emitting and why: `0003FY` is left no-owner but not non-emitting. It is reconstructable and routes through emitters `0000JC,0000LE` because source-use sites are proven in both file roots, while declaration ownership is unproven.
- Exact future work, if any, outside this assignment scope: a separate MiniMap raw-helper pass may eventually define/split `0x00454e30-0x00455040`, but this is not required for the `0003FY` literal and should not alter its owner/emitter state without new declaration evidence.

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

No generated row replacement is required. If the supervisor needs an exact no-op retained row, keep:

```markdown
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

No `by-memory/-coverage-report.md` replacement is required. If the supervisor needs an exact no-op retained row, keep:

```markdown
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001 post-migration and B003 second-pass reviews reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

## Follow-Up Actions
- Supervisor actions: none required beyond retaining the current row/state. The no-op rows above are included for supervisor application if a refresh wants exact text.
- A-agent actions: none required.
- B002 future research actions: none for this target. Treat `0x00454e30-0x00455040` as a possible future raw-helper target only if separately assigned.

## Confidence
- Recommendation confidence: high. Live IDA MCP and raw PE evidence agree with the current no-owner/two-emitter state.
- Score confidence: current `88/93` remains appropriate. Completion stays below 90 because final source declaration placement is unresolved; confidence remains high because use sites, bytes, and negative evidence are clean.
- Remaining uncertainty: only original-source declaration style remains unknown: repeated pooled literal at use sites versus a named shared constant.

## Validator Results
- Commands run: none.
- Results: no validator run was needed because no by-* target documentation, generated report, or coverage report was edited. No dry runs were used.
- Any unresolved validator warnings/errors: none introduced by this pass.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B002/research/0003FY-SharedDownloaderUserAgentWideString-current-goal2-pass.md`.
- Modified: none.
- Renamed: none.
- Moved to executed: none.
- Leases: none acquired; no leased-scope file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B002/0003FY-SharedDownloaderUserAgentWideString-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
