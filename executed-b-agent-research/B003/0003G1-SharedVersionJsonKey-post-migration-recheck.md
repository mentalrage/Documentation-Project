** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Post-Migration Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) unchanged.
- Final disposition: valid `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`; this is no-owner with proven emitters, not a dead/non-emitting reconstructable item.
- Required action: no metadata, owner/emitter, range, split, merge, score, IDA, or coverage-report change is required.
- Score before / after: keep `COMPLETION:88`, `CONFIDENCE:93`.
- Confidence: `94/100` for bytes/range/xrefs; `91/100` for the no-owner-with-three-emitters routing.

The target is a physical `.rdata` pooled/shared narrow `version` key. IDA MCP and raw PE evidence prove three source-use contexts: FileDownloader item-shop version parsing, FittingRoomDialogItemState catalog-state parsing, and StartupWindow update metadata parsing. No single declaration/source owner, shared constants object, JsonCpp owner, or literal-pool container owner is proven.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Required report path: `tools/leaser/Agents/Agent-B003/research/0003G1-SharedVersionJsonKey-post-migration-recheck.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner row with emitters `0000JC,0000JE,0000O5`.
- Tracker: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003G1`, assigned to Agent-B003 on 2026-06-13. The historical tracker row also records the B002 second-pass execution that kept the same three-emitter state.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.

## Executive Recommendation

Retain the current metadata:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000JE,0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Under the current owner/emitter model, this state is valid because `CANONICAL_OWNER` is semantic declaration ownership and `EMITTER_UIDS` is source-output routing. The binary proves the same physical `aVersion` literal is used by three independent source families, but it does not prove a single source declaration owner. The nonblank emitter list routes the reconstructed literal use through all proven source-use contexts, so this is not an invalid reconstructable item with no emission path.

No reconstruction C++ should be entered for this page. The item is `88/93`, below the active `90/90+` code-entry gate on completion, and a standalone declaration here would invent an owner that the binary does not prove. Final source rewrites should spell `"version"` at the consuming parse sites unless future source/debug/map evidence proves a named shared constant.

## Supervisor Active Recheck

- Supervisor instruction: perform a fresh Goal 2 post-migration B-agent review of current no-owner [UID:0003G1], verifying both the absence of a canonical owner and the exact emitter list `0000JC,0000JE,0000O5`.
- Prior reports reviewed as background, not accepted as authority: B001 post-migration report and B002 second-pass report. This pass independently rechecked current docs, live IDA MCP, raw PE bytes, generated coverage, and source-root documents.
- Split repair required: no. `0x0060d94c-0x0060d954` is ASCII `version\0`, `0x0060d954-0x0060d958` is unreferenced zero alignment, and `0x0060d958` begins the separate UTF-16 `itemshop.json` URL child.
- Parent/source repair required: no. The three emitters are valid file roots and clear the file-route gate.
- Coverage-report direct edit: not performed. No coverage row change is required.

## Inference Research Guidance Check

`by-structure.md` permits `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for compiler/linker-pooled string literals, shared constants, or small read-only data referenced from independent source files when no single declaration owner is proven. That is the governing rule here.

`inference_research.md` treats `.rdata` adjacency as weak evidence by itself. The neighboring FileDownloader URL literals are useful boundary context, but they do not prove FileDownloader owns this target because direct non-FileDownloader xrefs exist.

Evidence categories:

- IDA facts: exact bytes, string values, names/globals, xrefs, containing functions, scoped rendered-listing hits, data-flow trace, consumer function summaries, and component-level shared data.
- Raw PE facts: full-object uniqueness, absolute-VA pointer hits, no RVA-form pointer hits, no interior/tail pointer hits, and duplicate substring contexts.
- Documentation evidence: current target page, current generated and coverage rows, candidate file/class pages, exact consumer pages, adjacent child pages, and JsonCpp ownership boundary.
- Inference: the target is source-declared/generated-binary literal data that should be emitted at proven consumer sites, while semantic declaration ownership remains unproven.

## Evidence Standards Used

- IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Current MCP schema check: `initialize` and `tools/list` succeeded; current server is `ida-pro-mcp 1.0.0` and inspection calls require a `database` session id.
- IDA database/session: `b001_0003gy`, opened/adopted for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA tools used: `idb_list`, `idb_open`, `server_health`, `get_bytes`, `get_string`, `entity_query`, `lookup_funcs`, `xrefs_to`, `search_text`, `trace_data_flow`, `analyze_component`, and `analyze_function`.
- Raw evidence: PowerShell PE section parser and byte-pattern scan of the read-only executable.
- Base conversions: verified with `tools/int_convert.py` for `0xc` -> decimal `12`, `0x41c` -> decimal `1052`, `0x1d9` -> decimal `473`, `0x88d` -> decimal `2189`, and `0x0020d94c` -> decimal `2152780`.

## IDA MCP Facts

Function/range facts:

- `server_health` returned `status: ok`, IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and strings cache size `2067`.
- `lookup_funcs` reports `0x0060d94c`, `0x0060d950`, `0x0060d954`, and `0x0060d958` are not functions.
- `lookup_funcs` maps source-use sites as:
  - `0x0041ad2e` / `0x0041aa00` -> `sub_41AA00`, size `0x41c` / decimal `1052` (Verified with int_convert.py).
  - `0x004227c6` / `0x00422740` -> `sub_422740`, size `0x1d9` / decimal `473` (Verified with int_convert.py).
  - `0x00580cab` / `0x00580870` -> `sub_580870`, size `0x88d` / decimal `2189` (Verified with int_convert.py).
  - Successor URL consumer `0x0041ae84` / `0x0041ae20` -> `sub_41AE20`, size `0x2ec`.

Data/string facts:

- `get_bytes` for `0x0060d94c`, size `0xc` / decimal `12` (Verified with int_convert.py), returned `76 65 72 73 69 6f 6e 00 00 00 00 00`.
- `get_string` returned `version` at `0x0060d94c`, interior substring `ion` at `0x0060d950`, no string at `0x0060d954`, and successor URL `https://secure.kru.com/itemshop/data/itemshop.json` at `0x0060d958`.
- `get_bytes` at `0x0060d958` returned UTF-16LE prefix bytes `68 00 74 00 74 00 70 00 73 00 3a 00 2f 00 2f 00`, confirming the successor starts a wide URL.
- `entity_query` over `0x0060d940-0x0060d970` returned names `aVersion` at `0x0060d94c` and `aHttpsSecureKru_0` at `0x0060d958`, one extracted string `version` at `0x0060d94c`, and globals `aVersion` size `8` plus `aHttpsSecureKru_0` size `102`.

Xref facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0060d94c` | exactly three data xrefs | Complete proven source-use set for the target head. |
| `0x0041ad2e` | data ref in `sub_41AA00` | FileDownloader item-shop version parse. |
| `0x004227c6` | data ref in `sub_422740` | FittingRoomDialogItemState decoded catalog-state parse. |
| `0x00580cab` | data ref in `sub_580870` | StartupWindow update metadata parse. |
| `0x0060d950` | zero xrefs | No mid-string pointer use. |
| `0x0060d954` | zero xrefs | No alignment-tail consumer. |
| `0x0060d958` | one data ref at `0x0041ae84` in `sub_41AE20` | Separate successor URL child, not part of `0003G1`. |

Scoped listing/search facts:

- `search_text` in `0x0041aa00-0x0041ae1c` found `.text:0041AD2E push offset aVersion ; "version"`.
- `search_text` in `0x00422740-0x00422919` found `.text:004227C6 push offset aVersion ; "version"`.
- `search_text` in `0x00580870-0x005810fd` found `.text:00580CAB push offset aVersion ; "version"`.
- `search_text` in `0x0041ae20-0x0041b10c` found `.text:0041AE84 push offset aHttpsSecureKru_0`, confirming the separate successor ref.
- `trace_data_flow backward 0x0060d94c` returned data node `db 'version',0` and exactly the three code nodes above.

Consumer/component facts:

- `analyze_component` over `0x0041aa00`, `0x00422740`, and `0x00580870` reported no internal call graph edges among the three functions.
- The same component analysis reported shared globals only `aVersion` and `___security_cookie`; `aVersion` is accessed by `sub_41AA00`, `sub_422740`, and `sub_580870`.
- `analyze_function 0x0041aa00` reports a `void __stdcall(int)` WinINet helper with `InternetOpenUrlW` for `https://secure.kru.com/itemshop/data/itemshop.ver`, JsonCpp parse helpers, string `version`, caller `sub_41B110`, and xref from `0x0041b13c`.
- `analyze_function 0x00422740` reports a FittingRoomDialogItemState-style `__thiscall` parser using JsonCpp helpers, string `version`, category loader `sub_422BA0`, and callers `sub_41CB70`, `sub_422020`, `sub_4229F0`, and `sub_422EC0`.
- `analyze_function 0x00580870` reports a StartupWindow `__thiscall` update-check function with strings `http://www.nexustk.com/news/news.asp`, `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`, `version`, `:`, `minimap`, and `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt`, plus caller `_WinMain@16`.

Negative IDA facts:

- No IDA xrefs target the interior substring at `0x0060d950` or the zero alignment at `0x0060d954`.
- No vtable, RTTI, constructor, initializer, global object, or pointer table owns `0x0060d94c`.
- No source-use evidence ties the three consumer functions together through one product-owned shared constants object or parser abstraction.

## PE / Raw Evidence

PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found:

| Section | VA range | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | `0x400-0x20ba00` |
| `.rdata` | `0x0060d000-0x0066c200` | `0x20ba00-0x26ac00` |
| `.data` | `0x0066d000-0x0069ce24` | `0x26ac00-0x278400` |
| `.rsrc` | `0x0069d000-0x006b2e00` | `0x278400-0x28e200` |

Pattern results:

| Pattern | Result | Meaning |
| --- | --- | --- |
| Full target bytes `version\0\0\0\0\0` | one hit at raw `0x20c34c`, VA `0x0060d94c` | Exact target object is unique. |
| ASCII `version\0` | hits at VAs `0x0060d94c`, `0x0060fcd4`, `0x00671b25` | Two duplicate substrings exist but are unrelated embedded message text. |
| Absolute VA `0x0060d94c` | hits at operand VAs `0x0041ad2f`, `0x004227c7`, `0x00580cac`, each preceded by opcode byte `0x68` | Immediate operand bytes for the three IDA refs at instruction starts `0x0041ad2e`, `0x004227c6`, `0x00580cab`. |
| Absolute VA `0x0060d950` | zero hits | No raw mid-string pointer. |
| Absolute VA `0x0060d954` | zero hits | No raw alignment-tail pointer. |
| Absolute VA `0x0060d958` | one hit at operand VA `0x0041ae85`, preceded by `0x68` | Immediate operand for separate successor URL ref at `0x0041ae84`. |
| RVA `0x0020d94c`, `0x0020d950`, `0x0020d954`, `0x0020d958` | zero hits | No RVA-form table/pointer owner. `0x0020d94c` was converted to decimal `2152780` with int_convert.py. |

Duplicate substring contexts:

- `0x0060fcd4` occurs inside unrelated `.rdata` text around `bitdepth not supported for color conversion` and `invalid CRC encountered`.
- `0x00671b25` occurs inside `.data` text `incompatible version`, near runtime-style error strings `buffer error`, `insufficient memory`, and `data error`.
- Neither duplicate is a product JSON key use, and neither changes the emitter decision for this exact target object.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Canonical Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL][CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Mixed literal-pool audit container | `FALSE` | `NONE` | blank | `89/92` | Non-emitting container; exact children carry source routes. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | FileDownloader `itemshop.ver` URL/progress wide strings | `TRUE` | `0000JC` | `0000JC` | `86/91` | Separate predecessor; no merge. |
| `0x0060d94c-0x0060d958` | [UID:0003G1][SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | Shared narrow `version` key plus alignment | `TRUE` | `NONE` | `0000JC,0000JE,0000O5` | `88/93` | Current target; keep unchanged. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) | FileDownloader `itemshop.json` URL | `TRUE` | `0000JC` | `0000JC` | `86/92` | Separate successor; no merge. |

## Source-Use / Emitter Inventory

| Emitter UID | File root | Source-use evidence | Decision |
| --- | --- | --- | --- |
| `0000JC` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), `NexusTK/network/`, `85/88` | IDA xref `0x0041ad2e` in `sub_41AA00`; consumer page [UID:0002TS][DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) documents `itemshop.ver` parsing and `version` extraction. | Keep emitter. Do not make canonical owner because two non-FileDownloader consumers are direct. |
| `0000JE` | [UID:0000JE][FittingRoom](by-file/FittingRoom.md), `NexusTK/cashshop/`, `85/87` | IDA xref `0x004227c6` in `sub_422740`; direct class [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) is `86/88`, owned/emitted through `0000JE`; consumer page [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md) documents decoded catalog-state parsing. | Keep file-root emitter. Do not make class/file canonical owner because FileDownloader and StartupWindow also use the same physical literal. |
| `0000O5` | [UID:0000O5][StartupWindow](by-file/StartupWindow.md), `NexusTK/app/`, `87/85` | IDA xref `0x00580cab` in `sub_580870`; consumer page [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) documents `nexustk.ver` update metadata parsing. | Keep emitter. Do not make canonical owner because it does not own item-shop or FittingRoom catalog-state parsing. |

## Documentation Evidence And IDA Status

Existing docs confirmed by this pass:

- Target page [UID:0003G1] already records `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000JE,0000O5`; live IDA and raw PE checks confirm the factual basis.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003G1` as no-owner with emitters `0000JC`,`0000JE`,`0000O5`, and includes it in the multiple-emitter table.
- `by-memory/-coverage-report.md` current row already records the B001/B002 conclusion and the same three source-use sites.
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) documents FileDownloader as a valid generated source root and explicitly says the adjacent shared narrow `version` key is not FileDownloader-owned because xrefs span FileDownloader, FittingRoom, and StartupWindow.
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md) and [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) document the FittingRoom catalog-state route.
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md) documents the startup update route and valid `NexusTK/app/` reconstruction path.
- [UID:0000KI][JsonCpp](by-file/JsonCpp.md) explicitly separates JsonCpp parser implementation from product URLs, downloader flow, catalog interpretation, and UI state; this rejects a JsonCpp owner for product key strings.

Docs not changed:

- [UID:0002TS] remains `80/84`, and [UID:0002E9] remains `84/88`, but the selected emitters are file roots/classes that clear the route gate. The lower child scores do not block the file-root emitter evidence because the direct string uses are independently proven by IDA.
- The current target score `88/93` remains appropriate: range, bytes, xrefs, source-use contexts, and no-owner/emitter rationale are strong, while final original source declaration form remains unknown.

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`

Evidence for:

- Direct IDA xrefs prove exactly three source-use sites in three independent source families.
- Raw PE scan proves no hidden absolute-VA, RVA-form, interior, or alignment-tail references beyond the expected three code immediates.
- `by-structure.md` explicitly allows pooled/shared literals to remain ownerless while using multiple emitters for proven source-use contexts.
- All selected emitter file roots clear the file-route gate and have valid reconstruction paths.

Evidence against:

- Original source could have used a macro or shared header constant that was folded into one string. The stripped binary does not prove or name such a declaration.

Decision: accepted. This is the current and recommended state.

### 2. New shared constants owner, such as `ProductJsonKeys`, `VersionMetadataKeys`, or `OnlineVersionKeys`

Evidence for:

- `version` is a generic metadata key used by more than one product parser.

Evidence against:

- No global object, pointer table, initializer, debug/source symbol, named declaration, or broader nearby shared-key cluster proves a constants object.
- The three consumers do not share one product parser abstraction: FileDownloader and FittingRoom use JsonCpp-style helpers, while StartupWindow uses update-response string parsing helpers.
- Creating a one-key constants owner would invent source structure solely to avoid `NONE`.

Decision: reject for current action. Revisit only with source/debug/map evidence or a broader proven constants cluster.

### 3. [UID:0000JC] FileDownloader as canonical owner

Evidence for:

- One direct ref is in FileDownloader-dispatched `DownloadCashShopVersion`.
- The target is adjacent to FileDownloader-owned item-shop URL/progress literal children.
- [UID:0000JC] clears the gate.

Evidence against:

- Direct non-FileDownloader xrefs exist in FittingRoomDialogItemState and StartupWindow.
- `.rdata` adjacency is weak in a literal pool and is outweighed by direct cross-file use.
- Canonical FileDownloader ownership would overclaim declaration ownership.

Decision: reject as canonical owner; keep emitter `0000JC`.

### 4. [UID:000051] FittingRoomDialogItemState / [UID:0000JE] FittingRoom as canonical owner

Evidence for:

- One direct ref is in a FittingRoomDialogItemState method.
- The direct class and file route both clear the gate.

Evidence against:

- FileDownloader and StartupWindow refs are direct and independent.
- The target is not class storage, vtable data, or FittingRoom-only literal data.

Decision: reject as canonical owner; keep file-root emitter `0000JE`.

### 5. [UID:0000O5] StartupWindow as canonical owner

Evidence for:

- One direct ref is in StartupWindow update metadata parsing.
- [UID:0000O5] clears the gate.

Evidence against:

- StartupWindow does not own FileDownloader item-shop version parsing or FittingRoom catalog-state parsing.
- The target is not StartupWindow class/static state; it is a shared literal address.

Decision: reject as canonical owner; keep emitter `0000O5`.

### 6. [UID:0000KI] JsonCpp

Evidence for:

- Two consumers use JsonCpp helper calls around the key.

Evidence against:

- `version` is product field text passed into JsonCpp, not JsonCpp library implementation data.
- StartupWindow uses the same physical literal outside a JsonCpp parser path.
- JsonCpp documentation explicitly keeps product keys and URLs with product modules.

Decision: reject as owner or emitter.

### 7. [UID:0003AL] CashShopDownloaderLiterals container

Evidence for:

- The target is physically nested in the `0x0060d7e0-0x0060d9c0` literal-pool container.

Evidence against:

- [UID:0003AL] is a reviewed `RECONSTRUCTABLE:FALSE` split-audit container and should not emit.
- The container intentionally groups mixed FileDownloader, MiniMap, FittingRoom, StartupWindow, and shared literal children.

Decision: reject as owner or emitter. No merge or container repair is needed.

## Negative Evidence Summary

- No xrefs to `0x0060d950` or `0x0060d954`.
- No raw absolute-VA hits for `0x0060d950` or `0x0060d954`.
- No raw RVA hits for the target, interior, tail, or successor.
- No hidden raw absolute-VA hits for `0x0060d94c` beyond the three known text immediates.
- No component-level call graph among the three consumer functions.
- No table/global/vtable/RTTI/initializer evidence for a source declaration object.
- No single existing source file owns all three source-use contexts.
- The successor URL at `0x0060d958` is separately referenced from `sub_41AE20` and remains [UID:0003G2], so no merge is justified.
- The two non-target raw `version\0` substrings are unrelated embedded message text and have no bearing on this exact object.

## Final Recommendation

Exact changes applied or recommended:

- Applied changes: created this B003 research report only.
- Recommended metadata changes: none.
- Recommended score changes: none; retain `88/93`.
- Recommended range/split/merge/reclassification changes: none.
- Recommended IDA repair: none.
- Recommended `by-memory/-coverage-report.md` changes: none required.
- Validation/memory_ranges rerun: not required for this report-only no-change result. If the supervisor applies optional wording-only coverage provenance, run the normal non-dry-run validator/autogen refresh afterward.

Exact retained metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000JE,0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Current `by-memory/-coverage-report.md` row is acceptable and may be kept:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but retain `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`); B002 reconfirmed no interior/tail refs, no split/merge/reclassification, and no IDA repair need.
```

Optional wording-only replacement if supervisor wants this B003 pass cited:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key plus zero alignment; B003 Goal 2 post-migration recheck keeps `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000JE,0000O5` because fresh IDA MCP and raw PE evidence prove exactly three source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`), with no interior/tail refs, no hidden absolute/RVA pointer-table owner, no split/merge/reclassification need, and no single source declaration owner.
```

Placement context: if used, replace the existing `0003G1` row between [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md).

## Follow-Up Actions

- Supervisor actions: accept no change, or optionally apply the wording-only coverage provenance row above.
- A-agent actions: none required.
- B003 future research actions: none for this target unless new source/debug/map evidence proves a real shared constants declaration or broader constants cluster.

## Confidence

- Recommendation confidence: `91/100`.
- Range/xref confidence: `94/100`.
- Score confidence: current `88/93` remains justified.
- Remaining uncertainty: original source spelling/declaration form. The binary proves one pooled storage address and three source-use contexts, but not whether the original source used repeated literals, a macro, or an unreferenced source-level constant folded into one string.

## Validator Results

- `validator.py` was not run because no by-* documentation, generated report, or coverage report was edited.
- No dry-run mode was used.
- `memory_ranges.py` was not run; not required for a no-change B research report.
- IDA MCP validation performed:
  - `initialize` / `tools/list`: endpoint live, current `ida-pro-mcp` schema confirmed.
  - `idb_list` / `idb_open`: session `b001_0003gy` adopted/opened for `NexusTK.exe`.
  - `server_health`: ok, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `get_bytes` / `get_string`: target bytes and successor string boundary confirmed.
  - `entity_query`: names, strings, and global sizes around the target confirmed.
  - `lookup_funcs`: target data is not a function; consumer function identities and sizes confirmed.
  - `xrefs_to`: three target-head refs, zero interior/tail refs, one successor URL ref.
  - `search_text`: scoped source-use instructions confirmed.
  - `trace_data_flow`: data node and three code-use nodes confirmed.
  - `analyze_component` / `analyze_function`: three independent consumer functions and source-use behavior confirmed.
- Raw PE validation performed:
  - exact target object uniqueness confirmed.
  - absolute-VA references confirmed only at three expected code immediate operands.
  - interior/tail/RVA pointer scans negative.
  - unrelated duplicate `version\0` substring contexts checked and rejected.
- Unresolved validation warnings/errors: none. Initial `get_bytes`/`get_string` calls used old argument names from prior reports and returned current-schema parameter errors; reruns with `regions` and `addrs` succeeded and are the facts recorded above.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003G1-SharedVersionJsonKey-post-migration-recheck.md`
- Modified: none outside the B003 research folder.
- Renamed: none.
- Moved to executed: none. Supervisor owns execution/move.

## Blockers

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B003/0003G1-SharedVersionJsonKey-post-migration-recheck.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
