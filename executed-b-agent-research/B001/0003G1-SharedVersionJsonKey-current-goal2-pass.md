** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Current Goal 2 Ownership / Emitter Recheck

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, blank `RECONSTRUCTION_CPP`, score `88/93`.
- Required action: no target-doc edit, no split, no merge, no reclassification, no emitter change, and no shared coverage replacement is required.
- Confidence: high. Live IDA MCP and PE evidence independently prove the same three source-use routes and no single declaration owner.

## Supporting Research

## Target
- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Source queue/report row: user-assigned current Goal 2 no-owner memory pass from `auto-generated/-ag-memory-coverage.md`; current generated row lists `no-owner`, canonical owner `NONE`, emitters `0000JC`,`0000JE`,`0000O5`.
- Current supervisor classification: prior B002/B003 passes are recorded as complete in `tools/leaser/Agents/Supervisor_notes.md`, but this assignment explicitly requested a fresh B001 current-pass recheck.
- Current scores and parent state: target page currently has `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, and blank reconstruction C++.

## Executive Recommendation
- Keep this item as a reconstructable shared literal with no canonical owner, but with the three proven file-root emitters.
- The exact physical bytes are a narrow ASCII `version` key plus terminator and alignment before the next wide URL. They are referenced from FileDownloader item-shop version parsing, FittingRoom dialog item-state parsing, and StartupWindow update metadata parsing.
- No existing by-file, by-class, JsonCpp, surrounding literal container, or new constants file is a defensible single declaration owner. The active owner/emitter split is the correct model for this pooled shared literal.
- No remaining blocked assignment should happen unless future source/debug/linker-map evidence proves a real shared named constant or source file that owned this literal before compiler/linker pooling.

## Supervisor Active Recheck
- Supervisor instruction: recheck current no-owner memory target [UID:0003G1] from current docs and live IDA MCP evidence; decide whether `CANONICAL_OWNER:NONE` with emitters remains correct, or whether owner/emitter/split/repair changes are needed.
- Split repair: not required. The range is exact: `0x0060d94c-0x0060d954` is the `version` string and `0x0060d954-0x0060d958` is zero alignment before the separate successor at `0x0060d958`.
- Source-bearing children in scope: none need creation or repair. The predecessor/successor children already separate FileDownloader wide literals from this shared narrow key.

## Inference Research Guidance Check
- `by-structure.md` permits `CANONICAL_OWNER:NONE` with nonblank `EMITTER_UIDS` for pooled/shared literals when no single declaration owner is proven but source-use routes are proven.
- `inference_research.md` cautions against using adjacency or consumer xrefs alone as ownership proof. I treated FileDownloader adjacency and all three read/parse xrefs as routing evidence, not declaration ownership proof.
- Existing documentation was used as a lead only. The final recommendation is based on fresh IDA MCP xrefs, decompilation snippets, string/byte facts, and raw PE operand scans.

## Evidence Standards Used
- IDA MCP evidence: `server_health`, `lookup_funcs`, `get_string`, `get_bytes`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, and `decompile`.
- PE evidence: raw `NexusTK.exe` MD5, file-offset-to-VA mapping, exact byte scans, absolute VA operand scans, and negative scans for interior/tail operands.
- Documentation evidence: current target page, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, `Supervisor_notes.md`, prior executed reports, and candidate by-file/by-class/by-memory docs.
- The evidence is strong enough for the current no-owner/multi-emitter state because the physical bytes, all live refs, all negative interior/tail refs, and all three consumer contexts agree.

## IDA MCP Facts
- Function/range facts:
  - MCP `server_health` on database `b001_0003gy` reported IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` reports `0x0060d94c`, `0x0060d950`, `0x0060d954`, and `0x0060d958` are not functions.
  - `0x0041aa00` / `0x0041ad2e` resolve to `sub_41AA00`, size `0x41c`.
  - `0x00422740` / `0x004227c6` resolve to `sub_422740`, size `0x1d9`.
  - `0x00580870` / `0x00580cab` resolve to `sub_580870`, size `0x88d`.
  - `0x0041ae20` / `0x0041ae84` resolve to `sub_41AE20`, size `0x2ec`, the successor URL consumer.
- Data/table/padding facts:
  - `get_string 0x0060d94c` returns `version`.
  - `get_string 0x0060d950` returns the interior substring `ion`, but `xrefs_to 0x0060d950` returns no refs and the PE scan finds no `0x0060d950` operands.
  - `get_string 0x0060d954` returns no string; this is the zero alignment tail.
  - `get_string 0x0060d958` returns `https://secure.kru.com/itemshop/data/itemshop.json`, the next child.
  - `get_bytes 0x0060d94c size 12` returns `76 65 72 73 69 6f 6e 00 00 00 00 00`.
  - `entity_query 0x0060d940-0x0060d970` reports name `aVersion` at `0x0060d94c`, name `aHttpsSecureKru_0` at `0x0060d958`, and one extracted string at `0x0060d94c` length `7`.
- Xref facts:
  - `xrefs_to 0x0060d94c` returns exactly three data refs: `0x0041ad2e` in `sub_41AA00`, `0x004227c6` in `sub_422740`, and `0x00580cab` in `sub_580870`.
  - `xrefs_to 0x0060d950` returns none.
  - `xrefs_to 0x0060d954` returns none.
  - `xrefs_to 0x0060d958` returns exactly one data ref: `0x0041ae84` in `sub_41AE20`.
- Decompilation observations:
  - `sub_41AA00` opens `https://secure.kru.com/itemshop/data/itemshop.ver` and then indexes/parses `"version"` via `sub_4278E0(..., "version", ...)`.
  - `sub_422740` parses a state/catalog buffer and indexes/parses `"version"` via `sub_4278E0(..., "version", ...)`.
  - `sub_580870` opens `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`, searches `"version"` with `sub_581E40("version", 0)`, and later searches `"minimap"` in the same update/minimap metadata flow.
  - `sub_41AE20` opens `https://secure.kru.com/itemshop/data/itemshop.json`, proving the successor at `0x0060d958` is a separate FileDownloader catalog URL child.
- PE scan facts:
  - Raw executable MD5: `4247e04e20b65d6414c7238aa8ff5515`.
  - Exact target bytes `version\0` plus four zero bytes occur once, at file offset `0x20C34C`, VA `0x0060D94C`.
  - ASCII `version\0` occurs at VAs `0x0060D94C`, `0x0060FCD4`, and `0x00671B25`; the latter two are unrelated string occurrences in other text contexts, not extra refs to this target.
  - Absolute VA operand `0x0060D94C` occurs at operand bytes `0x0041AD2F`, `0x004227C7`, and `0x00580CAC`, matching IDA xrefs at the surrounding instruction addresses.
  - Absolute VA operands `0x0060D950` and `0x0060D954` do not occur.
  - Absolute VA operand `0x0060D958` occurs once at operand bytes `0x0041AE85`, matching the separate successor URL xref.
  - RVA patterns for `0x0020D94C`, `0x0020D950`, `0x0020D954`, and `0x0020D958` do not occur.
- Negative IDA facts:
  - No interior or tail xrefs justify splitting `ion` or the zero alignment tail.
  - No hidden pointer table or global indirection points to the item head, interior, or tail.
  - No IDA evidence shows a named shared constant owner or a JsonCpp-owned key table.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d8b8-0x0060d94c` | `0003G0` / `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md` | FileDownloader itemshop version URL/progress wide literals | Yes | `0000JC` | `86/91` | Separate predecessor, keep FileDownloader-owned |
| `0x0060d94c-0x0060d958` | `0003G1` / `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | Shared narrow `version` key plus zero alignment | Yes | `NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | Current target, keep unchanged |
| `0x0060d958-0x0060d9c0` | `0003G2` / `by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md` | FileDownloader itemshop catalog URL | Yes | `0000JC` | `86/92` | Separate successor, not part of `0003G1` |
| `0x0060d7e0-0x0060d9c0` | `0003AL` / `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` | Mixed literal audit/container covering adjacent children | No | `NONE` | documented as container | Not a canonical owner |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e -> 0x0060d94c` | `sub_41AA00` / `DownloadCashShopVersion` | FileDownloader source-use route; itemshop version payload key |
| `0x004227c6 -> 0x0060d94c` | `sub_422740` / `FittingRoomDialogItemStateLoadEncodedStateBuffer` | FittingRoom source-use route; cached/decoded item-state catalog version key |
| `0x00580cab -> 0x0060d94c` | `sub_580870` / `StartupWindowUpdateCheck` | StartupWindow source-use route; update metadata version search |
| `0x0041ae84 -> 0x0060d958` | `sub_41AE20` / `DownloadCashShopCatalog` | Successor wide `itemshop.json` URL, separate from this target |
| `0x0060d950` | no xrefs | Interior substring only, not a child or separate literal |
| `0x0060d954` | no xrefs | Alignment tail only |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, exact xrefs, no tail refs, and the separate successor URL.
  - `by-file/FileDownloader.md` supports the FileDownloader route for item-shop version/catalog downloads, but also notes the neighboring shared `version` key spans more than FileDownloader.
  - `by-class/FittingRoomDialogItemState.md` and `by-file/FittingRoom.md` support the FittingRoom route for cached item-shop/catalog state parsing.
  - `by-file/StartupWindow.md` supports the StartupWindow update/minimap metadata route.
  - `by-file/JsonCpp.md` supports rejecting JsonCpp as owner: JsonCpp owns parser support, not product-specific keys and URLs.
  - `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` supports treating the broader physical region as a mixed container whose children carry routes.
- Existing docs that are stale, incomplete, or contradicted:
  - Older B001 reports predate the current owner/emitter split and used parent-blank wording. That history is superseded by the current `CANONICAL_OWNER:NONE` plus emitter model.
  - No current by-* doc is contradicted by the live recheck.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` currently lists the target as `no-owner`, canonical owner `NONE`, emitters `0000JC`,`0000JE`,`0000O5`, and includes it in the multiple-emitter table.
  - `by-memory/-coverage-report.md` currently records the same conclusion and the three evidence routes. No direct edit is allowed or needed.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with emitters `0000JC,0000JE,0000O5`
- Evidence for:
  - Three live data refs point to the same physical `aVersion` head from three different source families.
  - The three consumer functions parse different payloads: online itemshop version, FittingRoom item-state/catalog data, and startup update metadata.
  - The target is a narrow key string, not an object with construction/destruction, write sites, table ownership, or a unique source module.
  - Current by-structure rules explicitly allow no-owner with multiple emitters for pooled/shared literals.
- Evidence against:
  - The byte range is adjacent to FileDownloader-only wide literals, so a superficial address-clustering argument could overclaim FileDownloader ownership.
  - There are unrelated duplicate `version` strings elsewhere in the binary, so the source-level literal-pooling mechanism cannot be fully reconstructed from bytes alone.
- Decision: accepted. This is no-owner but not non-emitting; the three emitter UIDs are required and correct.

### 2. FileDownloader / `0000JC` as canonical owner
- Evidence for:
  - `sub_41AA00` references the target while fetching/parsing `itemshop.ver`.
  - The target is physically between FileDownloader-owned item-shop wide literal children.
  - `by-file/FileDownloader.md` clears the route score gate.
- Evidence against:
  - `sub_422740` and `sub_580870` also reference the same head, and they belong to FittingRoom and StartupWindow source families.
  - Address adjacency to FileDownloader-only wide strings does not prove declaration ownership for a pooled narrow key.
  - Assigning canonical ownership to FileDownloader would hide two proven source-use routes.
- Decision: reject as canonical owner; keep `0000JC` as one emitter.

### 3. FittingRoomDialogItemState / FittingRoom / `000051` and `0000JE`
- Evidence for:
  - `sub_422740` references the target in the item-state/catalog parser path.
  - `by-class/FittingRoomDialogItemState.md` and `by-file/FittingRoom.md` support the source-use context and clear route scoring.
- Evidence against:
  - The same physical key is also used by FileDownloader and StartupWindow.
  - The target is not class storage, a vtable-adjacent class object, or a unique FittingRoom-only string.
- Decision: reject FittingRoom as canonical owner; keep file-root `0000JE` as one emitter.

### 4. StartupWindow / `0000O5`
- Evidence for:
  - `sub_580870` references the target while processing update/minimap metadata.
  - The decompiler shows the startup update flow fetching `nexustk.ver` and searching `"version"`.
  - `by-file/StartupWindow.md` clears the route score gate.
- Evidence against:
  - The same physical literal is also used by FileDownloader and FittingRoom.
  - No startup-only declaration or storage owns the literal.
- Decision: reject StartupWindow as canonical owner; keep `0000O5` as one emitter.

### 5. JsonCpp / `0000KI`
- Evidence for:
  - Some consumers use JsonCpp-like parse helpers around the key.
- Evidence against:
  - JsonCpp is parser infrastructure. The product key `"version"` is passed by product modules into parser accessors/search helpers.
  - The StartupWindow route uses a string-search update parser rather than demonstrating JsonCpp ownership.
  - Current `JsonCpp.md` explicitly separates parser support from product keys and URLs.
- Decision: reject.

### 6. Physical literal container `0003AL`
- Evidence for:
  - The target lies inside the broader `0x0060d7e0-0x0060d9c0` cash-shop/downloader literal region.
- Evidence against:
  - `0003AL` is a mixed audit/container, not a source declaration owner.
  - Neighboring children have different routing: shared user-agent/minimap cases, FileDownloader-only itemshop literals, this shared key, and successor FileDownloader URL.
- Decision: reject as canonical owner. Keep it only as context.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: none.
- Likely full contents: no defensible source file can be inferred from this one pooled key. A hypothetical shared constants file would have to explain FileDownloader URLs, FittingRoom catalog keys, StartupWindow update keys, and adjacent mixed literals, but those items have different proven routes.
- Candidate related items that belong: none proven.
- Candidate related items rejected:
  - `0003G0` and `0003G2` are FileDownloader-only item-shop wide literals.
  - `0003FZ` and other nearby shared literals have different emitter sets and do not prove a single constants owner.
  - JsonCpp parser support is not a product-key constants owner.
- Standalone, narrow, or broad source-file inference: reject new source file. Creating one would invent source structure not supported by IDA facts.

## Negative Evidence Summary
- Checked interior/tail xrefs: none to `0x0060d950` or `0x0060d954`.
- Checked raw PE absolute VA operands: none to `0x0060d950` or `0x0060d954`; three to `0x0060d94c`; one to successor `0x0060d958`.
- Checked raw PE RVA operands: none to target head, interior, tail, or successor.
- Checked successor boundary: `0x0060d958` is `aHttpsSecureKru_0`, consumed by `sub_41AE20`, and should not be merged into this item.
- Checked consumer routes: all three are source-use evidence, but no one route is declaration ownership proof.
- Checked existing docs/prior reports: prior reports are consistent after the post-migration emitter update; older parent-blank language is historical, not a reason to remove emitters.

## Final Recommendation
- Exact changes applied or recommended: no by-* metadata changes. Preserve:
  - `*** COMPLETION:88`
  - `*** CONFIDENCE:93`
  - `*** CANONICAL_OWNER:NONE`
  - `*** RECONSTRUCTABLE:TRUE`
  - `*** EMITTER_UIDS:0000JC,0000JE,0000O5`
  - blank `RECONSTRUCTION_CPP`
- Exact parent assignments applied or recommended: no canonical parent. Keep emitter routing to:
  - `0000JC` / `by-file/FileDownloader.md`, proven by `sub_41AA00` at `0x0041ad2e`.
  - `0000JE` / `by-file/FittingRoom.md`, proven by `sub_422740` at `0x004227c6`.
  - `0000O5` / `by-file/StartupWindow.md`, proven by `sub_580870` at `0x00580cab`.
- Exact items left no-owner/non-emitting and why: `0003G1` is left no-owner but not non-emitting. It has three proven emitters.
- Exact future work outside this assignment scope: none for `0003G1` unless future source/debug/linker-map evidence proves a real shared declaration owner.

## Shared Report / Coverage Text
- `by-memory/-coverage-report.md`: no replacement row is required. Current row is already semantically correct and should be preserved:

```markdown
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but retain `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`); B002 reconfirmed no interior/tail refs, no split/merge/reclassification, and no IDA repair need.
```

- `auto-generated/-ag-memory-coverage.md`: no manual edit. Current generated rows are correct:

```markdown
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `NONE` | `0000JC`,`0000JE`,`0000O5` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | `0000JC`,`0000JE`,`0000O5` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

## Follow-Up Actions
- Supervisor actions: none required. If moving reports to `executed`, move this current-pass report after acceptance.
- A-agent actions: none required for `0003G1`.
- B001 future research actions: none for this target.

## Confidence
- Recommendation confidence: high. The current `NONE` plus three-emitter state is directly supported by current IDA and raw PE evidence.
- Score confidence: keep `88/93`. The item is thoroughly bounded and routed, but no source/debug evidence proves source declaration placement, and the target remains below the `90/90+` code-entry gate.
- Remaining uncertainty: only whether original source had a named shared constant before compiler/linker literal pooling. Current binary evidence does not prove one.

## Validator Results
- Commands run: none.
- Results: not applicable. No target by-* docs or generated/shared reports were edited, so normal validator `--apply` was not required. No dry runs were used.
- Any unresolved validator warnings/errors: none from this pass.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B001/research/0003G1-SharedVersionJsonKey-current-goal2-pass.md`
- Modified: none outside the B001 research report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B001/0003G1-SharedVersionJsonKey-current-goal2-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
