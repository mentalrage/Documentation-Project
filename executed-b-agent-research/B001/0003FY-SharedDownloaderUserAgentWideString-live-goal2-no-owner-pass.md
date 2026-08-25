** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Ownership / Source-Routing Research

## Finalized Report / Current Recommendation

- Current recommendation: keep `CANONICAL_OWNER:NONE` and keep `EMITTER_UIDS:0000JC,0000LE`.
- Final disposition: no canonical owner is defensible, but this is not non-emitting. The exact physical wide `HTTPTEST` user-agent literal is a pooled/source-shared literal with proven source-use contexts in both [UID:0000JC] `FileDownloader` and [UID:0000LE] `MiniMap`.
- Required action: no split, merge, reclassification, child creation, owner change, emitter change, score change, or coverage-row replacement is recommended.
- Confidence: high for the no-owner-with-two-emitters recommendation. Fresh IDA MCP evidence again shows one physical literal and five direct immediate-use sites: three FileDownloader helper uses, one modeled MiniMapDownloader use, and one raw MiniMap-side helper use.

Recommended metadata remains:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000LE
RECONSTRUCTION_CPP:
```

Do not edit `by-memory/-coverage-report.md` for this target. The current row is still accurate and should be retained:

```text
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B001 post-migration and B003 second-pass reviews reconfirmed five direct `push offset szAgent` refs into `InternetOpenW` from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper `0x00454e30-0x00455040`; keep `CANONICAL_OWNER:NONE` because FileDownloader, MiniMap, and the physical mixed container each overclaim declaration ownership, while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

## Supporting Research

## Target

- Target UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Source queue/report row: `tools/leaser/Agents/no_owner_b-agent-tracker.md`, Active 2026-06-14 Live Goal 2 No-Owner Memory Pass.
- Current supervisor classification: no-owner memory item with existing emitters.
- Current scores and parent state reviewed: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000LE`.
- Current generated state reviewed: `auto-generated/-ag-memory-coverage.md` lists this row as `no-owner` with emitter UIDs `0000JC`,`0000LE`, and a source-use route through `auto-generated/NexusTK/network/FileDownloader.cpp`; the generated emitter list still records both source-use roots.

The target file was treated as current documentation evidence, not proof. Prior B-agent reports were treated as historical leads only. This report rechecked the current docs and live IDA MCP evidence before making the recommendation.

## Executive Recommendation

Keep the existing unusual split state: `CANONICAL_OWNER:NONE` with multiple emitters.

This target is a real source-declared/generated-binary string literal. It should be reconstructable because the bytes represent the literal that downloader call sites pass as the WinINet `InternetOpenW` agent string. It should not receive a canonical owner because no single declaration/source owner is proven for the one physical pooled literal. The direct uses span the generic FileDownloader helper family and the MiniMap-specific downloader/helper family.

The correct emitter routing is still:

| Emitter UID | Path | Why it is justified |
| --- | --- | --- |
| `0000JC` | `by-file/FileDownloader.md` | Three direct xrefs from FileDownloader-dispatched helper functions use `szAgent` before `InternetOpenW`: `sub_41A750`, `sub_41AA00`, and `sub_41AE20`. |
| `0000LE` | `by-file/MiniMap.md` | The modeled MiniMapDownloader helper `sub_453AA0` uses `szAgent`, and the raw MiniMap-side helper at `0x00454e30-0x00455040` also pushes `szAgent` before `InternetOpenW`. |

No new owner/source file should be invented. No split is needed because the current `0x14`-byte range is already the exact child for the user-agent literal and its padding. `0x14` is 20 bytes, verified with `int_convert.py`; the UTF-16LE `HTTPTEST` plus terminator occupies `0x12` / 18 bytes, verified with `int_convert.py`, followed by two zero padding bytes before the `0x0060d7f4` minimap literal child.

## Supervisor Active Recheck

The user assigned this as a live Goal 2 B-agent no-owner memory pass on 2026-06-14. The tracker row lists Agent-B001 as assigned for `0003FY` and points to this report path.

The assigned item does not require split repair. It is already an exact child split from [UID:0003AL] `0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals`, and the surrounding children already separate the minimap literal group, item-shop version literals, shared `version` key, and item-shop catalog URL.

Every source-bearing route in scope was rechecked:

- [UID:0000JC] `FileDownloader` is a valid file root at `85/88`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`.
- [UID:0000LE] `MiniMap` is a valid file root at `85/86`, with `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
- No evidence supports replacing those two source-use emitters with a single canonical declaration owner.

## Inference Research Guidance Check

`by-structure.md` explicitly allows source-authored data with no defensible single canonical owner to keep `CANONICAL_OWNER:NONE` while using multiple `EMITTER_UIDS` when the source item must appear in multiple reconstructed source contexts. The supervisor override calls out the same strange split case for pooled string literals and shared constants.

`inference_research.md` also cautions that address adjacency and nearby literal pools do not prove source-file ownership. For this target, the decisive evidence is not adjacency to FileDownloader vtable data or the broader CashShop literal container. The decisive evidence is xref/source-use distribution: the same physical string is consumed by two independent downloader source families.

Facts, documentation evidence, and inference were separated as follows:

- IDA fact: bytes, xrefs, function containment, raw-helper non-function state, immediate-address pattern hits, and raw helper disassembly.
- Documentation evidence: current file roots, score gates, source folder paths, related memory pages, and current coverage rows.
- Inference: the original source likely spelled `L"HTTPTEST"` at use sites or had a compiler/linker-pooled literal; no named shared declaration object is proven.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `make_signature_for_range`, `disasm`, and `analyze_component`.
- Current `by-memory`, `by-file`, and `by-class` pages for FileDownloader and MiniMap consumers.
- Generated coverage rows in `auto-generated/-ag-memory-coverage.md`.
- Coverage row in `by-memory/-coverage-report.md`.
- Negative evidence: no single xref cluster, no single valid owner covering all uses, no incoming xrefs to the raw helper start, no unique shared declaration/global page, and no need to widen/split the exact child.

The evidence is strong enough to keep the current routing because the five xrefs and two source roots independently agree. Confidence stops below final-audit certainty because stripped-source binaries cannot prove whether the original source used repeated literal spelling, a macro, or a private shared constant that was later pooled by the compiler/linker.

## IDA MCP Facts

MCP session facts:

- Database/session: `a001_goal2_class_batch`.
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- Input path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- Auto-analysis: ready.
- Hex-Rays: ready.
- Strings cache: ready.

Function/range facts:

- `lookup_funcs` maps `0x0041a773` to `sub_41A750`, size `0x2ae`.
- `lookup_funcs` maps `0x0041aa3b` to `sub_41AA00`, size `0x41c`.
- `lookup_funcs` maps `0x0041ae5b` to `sub_41AE20`, size `0x2ec`.
- `lookup_funcs` maps `0x00453ac3` to `sub_453AA0`, size `0x2af`.
- `lookup_funcs` reports `0x00454e52`, `0x00454e30`, and `0x00455040` as not functions.
- The following modeled function after the raw helper starts at `0x00455050`, size `0x3`.

Data/string facts:

- `get_bytes` at `0x0060d7e0` returned:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00 30 00 30 00 30 00 00 00 25 00 30 00
```

- The first `0x12` / 18 bytes are UTF-16LE `HTTPTEST` plus terminator, verified with `int_convert.py`.
- The full child range is `0x14` / 20 bytes, verified with `int_convert.py`.
- `get_string(0x0060d7e0)` reports `H` and `get_string(0x0060d7e4)` reports `TPTEST`, matching IDA's split item labels rather than contradicting the raw UTF-16LE decode.
- `get_string(0x0060d7f4)` reports the successor minimap literal head `0`, confirming the next child begins immediately after this range.

Xref facts:

`xrefs_to(0x0060d7e0)` returned exactly five data refs:

| Xref | Function context | Source-use meaning |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750` | FileDownloader message `10000` minimap-file helper pushes `szAgent` before `InternetOpenW`. |
| `0x0041aa3b` | `sub_41AA00` | FileDownloader message `10002` cash-shop version helper uses `szAgent`. |
| `0x0041ae5b` | `sub_41AE20` | FileDownloader message `10001` catalog helper uses `szAgent`. |
| `0x00453ac3` | `sub_453AA0` | MiniMapDownloader modeled helper uses `szAgent`. |
| `0x00454e52` | no IDA function | Raw MiniMap-side helper pushes `szAgent` before `InternetOpenW`. |

Negative xref facts:

- `xrefs_to(0x0060d7e4)` returned zero xrefs.
- `xrefs_to(0x0060d7f2)` returned zero xrefs.
- `xrefs_to(0x0060d7f4)` returned two separate minimap-literal successor refs, not refs to this target's terminator/tail.
- `xrefs_to(0x00454e30)` returned zero incoming references to the raw helper start.

Search/signature facts:

- `find_bytes` for the exact UTF-16LE `HTTPTEST` plus terminator pattern found exactly one match: `0x0060d7e0`.
- `find_bytes` for the absolute little-endian pointer bytes `E0 D7 60 00` found exactly five matches: `0x0041a774`, `0x0041aa3c`, `0x0041ae5c`, `0x00453ac4`, and `0x00454e53`. These are the immediate operands for the five xref instructions.
- `make_signature_for_range(0x00454e30, 0x00455040)` reports the raw helper signature as unique.

Raw helper disassembly facts:

- `disasm(0x00454e30)` shows a function-shaped body with stack cookie setup.
- At `0x00454e52`, it executes `push offset szAgent`.
- At `0x00454e5d`, it calls `InternetOpenW`.
- The same body pushes the minimap `.mnm` suffix and the S3 minimap URL, then calls `InternetOpenUrlW`.
- This confirms a MiniMap-side source-use context even though IDA does not currently define a function object for the raw start.

Component facts:

- `analyze_component` over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` lists `0x0060d7e0` / `szAgent` as a shared global/string accessed by all four modeled downloader helpers.
- The same component analysis has no internal call edges among those four functions, supporting separate helper contexts rather than one single owner function.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY] `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` | Pooled UTF-16LE `HTTPTEST` user-agent literal | `TRUE` | `NONE` | `88/93` | Keep no-owner with emitters `0000JC,0000LE`. |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `CashShopDownloaderLiterals` | Non-emitting split-audit container | `FALSE` | `NONE` | `89/92` | Correct parent container; not a source owner. |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ] `MinimapDownloadWideLiterals` | Shared minimap download literal group | `TRUE` | `NONE` | `89/93` | Same valid no-owner/multi-emitter pattern. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `CashShopVersionDownloadWideLiterals` | FileDownloader-only item-shop version literals | `TRUE` | `0000JC` | `86/91` | Contrasting single-owner sibling. |
| `0x0060d94c-0x0060d958` | [UID:0003G1] `SharedVersionJsonKey` | Shared narrow `version` key | `TRUE` | `NONE` | `88/93` | Same no-owner/multi-emitter principle with three emitters. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2] `CashShopCatalogDownloadWideUrl` | FileDownloader-only item-shop catalog URL | `TRUE` | `0000JC` | `86/92` | Contrasting single-owner sibling. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750` pushes `szAgent` | FileDownloader message `10000` source-use context. |
| `0x0041aa3b` | `sub_41AA00` pushes `szAgent` | FileDownloader message `10002` source-use context. |
| `0x0041ae5b` | `sub_41AE20` pushes `szAgent` | FileDownloader message `10001` source-use context. |
| `0x00453ac3` | `sub_453AA0` pushes `szAgent` | MiniMapDownloader modeled helper source-use context. |
| `0x00454e52` | raw helper at `0x00454e30-0x00455040` pushes `szAgent` | MiniMap-side raw helper source-use context. |
| `0x00454e5d` | raw helper calls `InternetOpenW` | Confirms the raw `szAgent` use is the WinINet user-agent parameter path. |
| `0x00454e30` | no incoming xrefs to raw start | Blocks turning the raw helper into a separate caller-proven owner during this pass. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0003FY] target page already records the five source-use refs and the no-owner/two-emitter route. Fresh IDA MCP confirms the same xrefs.
- [UID:0000JC] `by-file/FileDownloader.md` is `85/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/"`, and documents the FileDownloader helper family, vtable boundary at `0x0060d7e0`, and message `10000-10002` dispatch map.
- [UID:00004W] `by-class/FileDownloader.md` is `85/89`, parented/emitted through [UID:0000JC], and documents `OnMessage` dispatch to the three helpers that reference `szAgent`.
- [UID:0000LE] `by-file/MiniMap.md` is `85/86`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, and owns the MiniMapDownloader/renderer-control family while preserving the exact file-split caveat.
- [UID:00008D] `by-class/MiniMapDownloader.md` is `85/88`, parented/emitted through [UID:0000LE], and documents the modeled MiniMapDownloader helper source route.
- [UID:0000XN] `MiniMapDownloader` memory page is `86/90`, emitted through [UID:0000LE], and documents `sub_453AA0` as the direct minimap download helper.
- [UID:0000XO] `MiniMapRendererAndControls` memory page is `85/86`, emitted through [UID:0000LE], and now records the raw `0x00454e30-0x00455040` WinINet helper caveat that references this literal.

Existing docs that are stale, incomplete, or caveated:

- The target page and generated rows are structurally correct, but final source declaration style is still unresolved. The safest reconstruction guidance remains to spell `L"HTTPTEST"` at the consuming source sites unless future source/debug evidence proves a named shared declaration.
- `auto-generated/-ag-memory-coverage.md` shows both emitter UIDs but only one concrete path in its path column for the no-owner row. Since both emitter roots have valid file paths and the emitter UID list is present, this is treated as generated-report presentation rather than evidence that [UID:0000LE] is invalid.
- The target page itself appeared as untracked in the scoped Git status before this report was written. This pass read it as the current working-tree documentation and did not modify it.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` line for [UID:0003FY] lists `no-owner`, `CANONICAL_OWNER:NONE`, and emitters `0000JC`,`0000LE`.
- `by-memory/-coverage-report.md` row under the `CashShopDownloaderLiterals` container already says to keep `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000LE`.
- No replacement row is required.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE` with emitters `0000JC,0000LE`

Evidence for:

- Fresh `xrefs_to(0x0060d7e0)` returned exactly five source-use refs split across FileDownloader and MiniMap-side code.
- Fresh `find_bytes` confirms exactly one physical UTF-16LE `HTTPTEST` literal and exactly five absolute immediate references to that address.
- FileDownloader has three modeled helper uses and a valid file root.
- MiniMap has one modeled MiniMapDownloader helper use plus one raw MiniMap-side helper use and a valid file root.
- Current by-structure rules explicitly allow no canonical owner with multiple emitters for pooled/shared literals.

Evidence against:

- None strong. The only caveat is final original-source declaration style, which cannot be proven from the stripped binary.

Decision:

- Accept. This is the best-supported current state.

### 2. Canonical owner [UID:0000JC] FileDownloader

Evidence for:

- Three of the five refs are in FileDownloader helper functions.
- The literal physically follows [UID:0003FT] FileDownloader vtable data at `0x0060d7a4-0x0060d7e0`.
- `FileDownloader` is the valid root for `DownloadMinimapFile`, `DownloadCashShopVersion`, and `DownloadCashShopCatalog`.

Evidence against:

- Two refs are MiniMap-side: modeled `sub_453AA0` and raw `0x00454e30-0x00455040`.
- Assigning the canonical owner to FileDownloader would overclaim declaration ownership for MiniMap source-use contexts.
- Address adjacency after FileDownloader vtable data is weak for pooled literals and does not override xref distribution.

Decision:

- Reject as canonical owner. Keep FileDownloader as one emitter.

### 3. Canonical owner [UID:0000LE] MiniMap

Evidence for:

- The modeled MiniMapDownloader helper and raw MiniMap-side helper both use the literal.
- The successor minimap literals at [UID:0003FZ] are also shared with MiniMap and FileDownloader, reinforcing the minimap source-use route.

Evidence against:

- Three direct refs are FileDownloader-dispatched helpers, including cash-shop version/catalog helpers with no MiniMap ownership.
- Assigning MiniMap as canonical owner would overclaim the FileDownloader/cash-shop downloader uses.

Decision:

- Reject as canonical owner. Keep MiniMap as one emitter.

### 4. Parent container [UID:0003AL] CashShopDownloaderLiterals

Evidence for:

- It physically contains this child and adjacent downloader/cash-shop/minimap literals.

Evidence against:

- It is explicitly a `RECONSTRUCTABLE:FALSE` split-audit container.
- It has no generated source path and no source-level declaration semantics.
- Exact children carry the source-routing decisions.

Decision:

- Reject as canonical owner or emitter.

### 5. New shared constants/global owner

Evidence for:

- The same physical literal is shared by multiple consumers.

Evidence against:

- No named global declaration, address-taken constant object, source/debug path, constructor, table, or unique constants module is proven.
- Existing sibling patterns show pooled literals should remain no-owner with source-use emitters when no declaration owner is proven.
- Creating a new constants file would invent source structure solely to avoid `NONE`, which by-structure forbids for pooled string literals.

Decision:

- Reject.

### 6. Split or reclassification

Evidence for:

- IDA labels `0x0060d7e0` as `szAgent` and the interior at `0x0060d7e4` as `aTptest`, so a superficial IDA-item split exists.

Evidence against:

- Raw bytes show one UTF-16LE `HTTPTEST` literal plus terminator and padding.
- `xrefs_to(0x0060d7e4)` and `xrefs_to(0x0060d7f2)` return zero refs.
- The current child range is already exact: `0x0060d7f4` starts the next minimap literal child.

Decision:

- Reject split/reclassification.

## Negative Evidence Summary

Checked and rejected:

- Single FileDownloader ownership: rejected because MiniMap has direct source-use refs.
- Single MiniMap ownership: rejected because FileDownloader has three direct source-use refs.
- Physical container ownership: rejected because the container is a non-emitting split audit page.
- New constants/source file: rejected because no source declaration object or named constants cluster is proven.
- Interior child split: rejected because interior/tail xrefs are absent and raw bytes form one literal.
- Raw helper as a new owner: rejected because the raw helper has no incoming xrefs to its start and is not a declaration owner for the literal.
- Adjacency after FileDownloader vtable data: treated as layout evidence only, weaker than cross-source xref distribution.

## Final Recommendation

Exact changes applied or recommended:

- Applied: created this Agent-B001 research report.
- Recommended: no by-* metadata changes.
- Recommended: keep target score `88/93`.
- Recommended: keep `CANONICAL_OWNER:NONE`.
- Recommended: keep `RECONSTRUCTABLE:TRUE`.
- Recommended: keep `EMITTER_UIDS:0000JC,0000LE`.
- Recommended: keep `RECONSTRUCTION_CPP` blank until the consuming source pages have final-quality code and the literal placement style is settled.

Exact future work outside this assignment scope:

- If a future pass creates exact child documentation for the raw `0x00454e30-0x00455040` MiniMap-side helper, cross-link it from this target and [UID:0000XO]. That would strengthen the MiniMap emitter route but should not change this target's canonical owner by itself.
- If future source/debug evidence proves an actual named shared declaration, revisit `CANONICAL_OWNER`. Current IDA evidence does not prove such a declaration.

## Follow-Up Actions

Supervisor actions:

- Mark tracker row `0003FY` complete-no-change for this live pass.
- No coverage-report edit is needed.

A-agent actions:

- None required for this target.
- Optional future work: focused split/research of the raw MiniMap-side helper at `0x00454e30-0x00455040` if it becomes a direct assigned target.

B001 future research actions:

- None for this target unless new evidence appears.

## Confidence

- Recommendation confidence: high.
- Score confidence: current `88/93` remains appropriate.
- Remaining uncertainty: original source declaration style is unknowable from current stripped-binary evidence. It may have been repeated literal spelling, a macro, or a local constant that the compiler/linker pooled. That uncertainty supports `CANONICAL_OWNER:NONE`; it does not undermine the two proven emitter routes.

## Validator Results

- Commands run: none.
- Results: not applicable.
- Reason: this was a research-only report inside the Agent-B001 folder. No by-* page, split child, metadata field, or coverage report was edited.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003FY-SharedDownloaderUserAgentWideString-live-goal2-no-owner-pass.md`
- Modified: none outside this Agent-B001 report.
- Renamed: none.
- Moved to executed: none.

Lease state:

- No lease was required. `goal.md` explicitly allows creating/updating reports inside `tools/leaser/Agents/Agent-B001/research` without a lease.
- Scoped pre-edit status showed `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` as already untracked, and `by-memory/-coverage-report.md` / `auto-generated/-ag-memory-coverage.md` as already modified. This pass did not touch those files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B001/0003FY-SharedDownloaderUserAgentWideString-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
