** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Second-Pass Ownership / Emitter Audit

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` unchanged.
- Final disposition: defensible `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`.
- Required action: none. Do not edit the target page, `by-memory/-coverage-report.md`, or generated reports for this assignment.
- Score before / after: keep `COMPLETION:88`, `CONFIDENCE:93`.
- Confidence: `94/100` for range/xref facts; `91/100` for the no-owner-with-three-emitters routing.

This is a reviewed no-owner-with-emitters state, not a dead non-emitting item. The physical `.rdata` object is one pooled narrow `version` key used by three independent source-use contexts. No single declaration/source owner is proven, but all three emitter file roots are proven consumers and clear the file-route gate.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Assignment: `B002-0003G1-second-pass`
- Coverage source: `auto-generated/-ag-memory-coverage.md`, current no-owner row with emitters `0000JC,0000JE,0000O5`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003G1`, reopened for B002 second-pass review.
- Prior report reviewed as background: `tools/leaser/Agents/Agent-B001/research/executed/0003G1-SharedVersionJsonKey-post-migration.md`.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.

## Executive Recommendation

Retain the current post-migration routing:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000JE,0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

No single canonical owner should be assigned. The item is not a FileDownloader literal, not a FittingRoom literal, not a StartupWindow literal, not a JsonCpp library literal, and not a standalone shared-constants object proven by the binary. It is one physical pooled/shared source string literal whose source uses are proven in:

| Emitter UID | File root | Source-use evidence |
| --- | --- | --- |
| `0000JC` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md) | `0x0041ad2e`, `push offset aVersion`, inside `sub_41AA00` / [UID:0002TS][DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md). |
| `0000JE` | [UID:0000JE][FittingRoom](by-file/FittingRoom.md) | `0x004227c6`, `push offset aVersion`, inside `sub_422740` / [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md), whose direct class [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) emits through `0000JE`. |
| `0000O5` | [UID:0000O5][StartupWindow](by-file/StartupWindow.md) | `0x00580cab`, `push offset aVersion`, inside `sub_580870` / [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md). |

## Supervisor Active Recheck

- Supervisor instruction: independently verify whether the current no-owner-with-emitters state should stay, gain a canonical owner, change emitters, split/reclassify, or receive repair.
- Split repair required: no. The exact item is already split from the surrounding literal pool. `0x0060d94c-0x0060d954` is `version\0`; `0x0060d954-0x0060d958` is unreferenced zero alignment; `0x0060d958` begins the separate UTF-16 `itemshop.json` URL child.
- Parent/source repair required: no. The target page already records the post-migration metadata, and current generated reports already show `CANONICAL_OWNER:NONE` with the three emitters.
- Coverage-report direct edit: not performed and not recommended.

## Inference Research Guidance Check

`by-structure.md` explicitly separates semantic ownership from output routing. It permits `CANONICAL_OWNER:NONE` with multiple `EMITTER_UIDS` for pooled string literals, shared constants, or small read-only data items referenced from independent source files when no declaration owner is proven. That rule applies exactly here.

`inference_research.md` treats `.rdata` adjacency as weak by itself. The adjacent `itemshop.ver` and `itemshop.json` FileDownloader literals are useful boundary context, but they do not prove FileDownloader owns the shared `version` key because two direct non-FileDownloader refs exist.

Evidence categories:

- IDA facts: exact bytes, string names, xrefs, source-use functions, and no interior/tail xrefs.
- Raw PE facts: exact object uniqueness, absolute-VA pointer hits, no RVA/interior/tail references, and unrelated duplicate substring contexts.
- Documentation evidence: current target, prior B001 report, current generated rows, current coverage row, and candidate file/class pages.
- Inference: this is pooled/shared source literal data with no proven canonical declaration owner, while all three observed source-use routes should remain emitters.

## Evidence Standards Used

- IDA MCP endpoint: `http://127.0.0.1:13337/mcp`
- IDA session: `b001_0003gy`
- IDB: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDA tools used: `server_health`, `get_bytes`, `get_string`, `entity_query`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `analyze_component`, `search_text`, and `trace_data_flow`.
- Raw evidence: read-only PowerShell PE section and byte-pattern scan of `NexusTK.exe`.
- Documentation evidence: target page, prior executed B001 report, tracker row, generated memory coverage rows, coverage report row, adjacent literal children, candidate file roots, FittingRoom class route, and JsonCpp source-root documentation.

## IDA MCP Facts

Function/range facts:

- `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and IDB path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.
- `lookup_funcs` reports `0x0060d94c` and `0x0060d958` are not functions.
- `lookup_funcs` reports source-use functions:
  - `0x0041aa00` -> `sub_41AA00`, size `0x41c`.
  - `0x00422740` -> `sub_422740`, size `0x1d9`.
  - `0x00580870` -> `sub_580870`, size `0x88d`.
  - Successor consumer `0x0041ae20` -> `sub_41AE20`, size `0x2ec`.

Data/string facts:

- `entity_query` over `0x0060d940-0x0060d970` reports names `aVersion` at `0x0060d94c` and `aHttpsSecureKru_0` at `0x0060d958`.
- `entity_query` reports one string in the target interval: `version`, length `7`, at `0x0060d94c`.
- `entity_query` reports globals `aVersion`, size `8`, at `0x0060d94c`, and successor `aHttpsSecureKru_0`, size `102`, at `0x0060d958`.
- `get_bytes 0x0060d94c size 12` returned `76 65 72 73 69 6f 6e 00 00 00 00 00`.
- `get_string 0x0060d94c` returned `version`.
- `get_string 0x0060d958` returned `https://secure.kru.com/itemshop/data/itemshop.json`.
- `get_string 0x0060d950` returned the interior substring `ion`; `xrefs_to` proves that interior substring is not used.
- `get_string 0x0060d954` returned no string.

Xref facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0060d94c` | three data xrefs | Complete source-use set for the target head. |
| `0x0041ad2e` | data ref in `sub_41AA00` | FileDownloader item-shop version parse. |
| `0x004227c6` | data ref in `sub_422740` | FittingRoomDialogItemState catalog-state parse. |
| `0x00580cab` | data ref in `sub_580870` | StartupWindow update metadata parse. |
| `0x0060d950` | zero xrefs | No mid-string pointer use. |
| `0x0060d954` | zero xrefs | No alignment-tail consumer. |
| `0x0060d958` | one data ref at `0x0041ae84` in `sub_41AE20` | Separate successor URL child, not part of `0003G1`. |

Consumer behavior facts:

- `search_text` scoped to `0x0041aa00-0x0041ae1c` found `.text:0041AD2E push offset aVersion ; "version"`.
- `search_text` scoped to `0x00422740-0x00422919` found `.text:004227C6 push offset aVersion ; "version"`.
- `search_text` scoped to `0x00580870-0x005810fd` found `.text:00580CAB push offset aVersion ; "version"`.
- `trace_data_flow backward 0x0060d94c` returned the data node `db 'version',0` and exactly those three code nodes.
- `analyze_component` over `0x0041aa00`, `0x00422740`, and `0x00580870` reported no internal call graph edges among the three functions.
- The same component analysis reported shared globals only `aVersion` and `___security_cookie`.
- `analyze_component` string usage maps `version` to all three functions.
- `analyze_function 0x0041aa00` identifies a `void __stdcall(int)` downloader helper with `InternetOpenW`, `InternetOpenUrlW`, HTTP status/content-length reads, JsonCpp parse helpers, and string `version`.
- `analyze_function 0x00422740` identifies the FittingRoom item-state parser with JsonCpp helper callees and string `version`.
- `analyze_function 0x00580870` identifies the StartupWindow update-check function with curl setup, `nexustk.ver`, `minimap`, and string `version`.

Negative IDA facts:

- No vtable, RTTI, constructor, initializer, named global object, pointer table, or helper function points to `0x0060d94c` as an owned declaration.
- No xrefs point to the interior substring or alignment tail.
- No source-use evidence ties the three consumers through one product-owned shared parser or constants object.
- A broad full-text `search_text` over `.text` timed out after 60 seconds; this is not a blocker because `xrefs_to`, `trace_data_flow`, scoped `search_text`, and raw PE pointer scans all independently found the same complete three-ref set.

## Raw PE Facts

Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found these sections:

| Section | VA range | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | `0x400-0x20ba00` |
| `.rdata` | `0x0060d000-0x0066c200` | `0x20ba00-0x26ac00` |
| `.data` | `0x0066d000-0x0069ce24` | `0x26ac00-0x278400` |
| `.rsrc` | `0x0069d000-0x006b2e00` | `0x278400-0x28e200` |

Pattern results:

| Pattern | Result | Meaning |
| --- | --- | --- |
| `version\0\0\0\0\0` | one hit at raw `0x20c34c`, VA `0x0060d94c` | Exact target object is unique. |
| `version\0` | hits at `0x0060d94c`, `0x0060fcd4`, `0x00671b25` | Two non-target substrings exist but are unrelated embedded message text. |
| absolute VA `0x0060d94c` | hits at VAs `0x0041ad2f`, `0x004227c7`, `0x00580cac` | Immediate operand bytes for the three IDA xrefs. |
| absolute VA `0x0060d950` | zero hits | No raw mid-string pointer. |
| absolute VA `0x0060d954` | zero hits | No raw alignment-tail pointer. |
| absolute VA `0x0060d958` | one hit at VA `0x0041ae85` | Immediate operand for separate successor URL ref. |
| RVA `0x0020d94c`, `0x0020d950`, `0x0020d954`, `0x0020d958` | zero hits | No RVA-form table/pointer owner. |

The two non-target `version\0` substrings are not product JSON key uses:

- `0x0060fcd4` is embedded in `.rdata` text `bitdepth not supported for color conversion`, with nearby LodePNG/zlib-style CRC/ADLER messages and zero xrefs to the embedded substring.
- `0x00671b25` is embedded in `.data` string `incompatible version`, followed by runtime error strings such as `buffer error`, `insufficient memory`, and `data error`; zero xrefs point to the embedded `version` substring.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Canonical Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL][CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Mixed literal-pool audit container | `FALSE` | `NONE` | blank | `89/92` | No emitter; exact children carry source routes. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | FileDownloader item-shop version URL/progress wide strings | `TRUE` | `0000JC` | `0000JC` | `86/91` | Separate predecessor; no merge. |
| `0x0060d94c-0x0060d958` | [UID:0003G1][SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | Shared narrow `version` key plus alignment | `TRUE` | `NONE` | `0000JC,0000JE,0000O5` | `88/93` | Current target; keep unchanged. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) | FileDownloader item-shop catalog URL | `TRUE` | `0000JC` | `0000JC` | `86/92` | Separate successor; no merge. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e` -> `0x0060d94c` | `push offset aVersion` in `sub_41AA00` | `DownloadCashShopVersion`; FileDownloader source-use route. |
| `0x004227c6` -> `0x0060d94c` | `push offset aVersion` in `sub_422740` | `FittingRoomDialogItemStateLoadEncodedStateBuffer`; FittingRoom source-use route. |
| `0x00580cab` -> `0x0060d94c` | `push offset aVersion` in `sub_580870` | `StartupWindowUpdateCheck`; StartupWindow source-use route. |
| `0x0041ae84` -> `0x0060d958` | `push offset aHttpsSecureKru_0` in `sub_41AE20` | Successor URL belongs to the separate FileDownloader catalog child. |

## Documentation Evidence And IDA Status

Existing docs that support the current state:

- [UID:0003G1][SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) already has current metadata `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000JE,0000O5`; second-pass IDA/raw checks confirm its factual claims.
- Prior B001 executed report correctly recommended no canonical owner and the same three emitters. This pass independently reconfirmed the result.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003G1` as `no-owner`, canonical owner `NONE`, emitters `0000JC`,`0000JE`,`0000O5`, and includes it in the multiple-emitter table.
- `by-memory/-coverage-report.md` current row already records the B001 post-migration result and the same three source-use sites.
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md) is `85/88`, `CANONICAL_OWNER:FILE`, path `NexusTK/network/`.
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md) is `85/87`, `CANONICAL_OWNER:FILE`, path `NexusTK/cashshop/`.
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md) is `87/85`, `CANONICAL_OWNER:FILE`, path `NexusTK/app/`.
- [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) is `86/88`, owned by and emitted through [UID:0000JE].
- Adjacent children [UID:0003G0] and [UID:0003G2] remain FileDownloader-only by direct refs; they do not absorb or own this shared key.
- [UID:0000KI][JsonCpp](by-file/JsonCpp.md) documents JsonCpp as third-party parser/writer support and explicitly keeps product keys/URLs with product modules.

Docs that are not changed:

- [UID:0002TS][DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) is still below `85/85` at `80/84`, but the source-use site is directly proven by IDA and the emitter file root [UID:0000JC] clears the route gate. This does not block the `0003G1` emitter because the emitter UID is the file root, not the lower-scored helper page.
- [UID:0002E9] is `84/88`, but its direct class route [UID:000051] and file route [UID:0000JE] clear the gate, and IDA directly proves the string use.
- [UID:0001IO] is `85/87` and [UID:0000O5] is `87/85`, so the StartupWindow route clears directly.

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`

Evidence for:

- Direct IDA xrefs prove exactly three source-use sites, one in each source family.
- Raw PE scan proves the target VA appears only at the three immediate operands and has no interior/tail/RVA pointer owners.
- `by-structure.md` explicitly allows pooled literals to remain ownerless while using multiple emitters for proven source-use contexts.
- All selected emitter file roots clear `85/85` and have valid proposed reconstruction paths.
- The current target and generated rows already match this result.

Evidence against:

- Original source could have had a shared macro or constant declaration that the stripped binary no longer proves.
- The target's blank reconstruction C++ means the literal should still be spelled by consuming function rewrites, not by inventing a shared object here.

Decision: accepted. This is the best current state.

### 2. New shared constants owner, such as `ProductJsonKeys`, `VersionMetadataKeys`, or `OnlineVersionKeys`

Evidence for:

- The word `version` is a generic metadata key used in multiple product parsers.
- A source codebase could have used a shared constant in a header.

Evidence against:

- No global object, pointer table, initialization code, named declaration, or cluster of nearby shared keys proves such a source object.
- The three consumers do not share a single product parser abstraction. FileDownloader/FittingRoom use JsonCpp-style value access, while StartupWindow uses string-search parsing.
- Creating a one-key constants owner would invent source structure solely to avoid `NONE`, which `by-structure.md` says not to do for pooled literals.

Decision: reject for current action. Revisit only with source/debug/map evidence or a broader proven constants cluster.

### 3. [UID:0000JC] FileDownloader as canonical owner

Evidence for:

- One direct ref is in `DownloadCashShopVersion`.
- The target is adjacent to FileDownloader-owned item-shop URL/progress and catalog URL children.
- FileDownloader clears `85/85`.

Evidence against:

- Two direct refs are outside FileDownloader: FittingRoom item-state parsing and StartupWindow update parsing.
- `.rdata` adjacency is weak evidence in a literal pool and cannot override direct multi-file source-use refs.
- Assigning canonical owner `0000JC` would overclaim declaration ownership and hide material non-FileDownloader consumers.

Decision: reject as canonical owner; retain as emitter `0000JC`.

### 4. [UID:0000JE] FittingRoom / [UID:000051] FittingRoomDialogItemState as canonical owner

Evidence for:

- One direct ref is in a FittingRoomDialogItemState method.
- The class and file routes both clear `85/85`.

Evidence against:

- FileDownloader and StartupWindow are independent direct consumers.
- The target is not class storage, vtable data, or FittingRoom-only literal data.
- The class route is evidence for emitter `0000JE`, not canonical declaration ownership of a pooled literal.

Decision: reject as canonical owner; retain file-root emitter `0000JE`.

### 5. [UID:0000O5] StartupWindow as canonical owner

Evidence for:

- One direct ref is in StartupWindow update metadata parsing.
- StartupWindow file root clears `85/85`.

Evidence against:

- FileDownloader item-shop and FittingRoom catalog-state refs are direct and unrelated to StartupWindow ownership.
- StartupWindow does not own item-shop/fitting-room JSON parsing.

Decision: reject as canonical owner; retain emitter `0000O5`.

### 6. [UID:0000KI] JsonCpp as canonical owner or emitter

Evidence for:

- FileDownloader and FittingRoom use JsonCpp helper calls around the `version` key.

Evidence against:

- `version` is product data passed into JsonCpp, not JsonCpp library data.
- StartupWindow uses the same physical literal without a JsonCpp parse path.
- JsonCpp documentation correctly separates parser implementation from product keys/URLs.

Decision: reject.

### 7. [UID:0003AL] CashShopDownloaderLiterals container

Evidence for:

- The target is a child of this physical literal-pool container.

Evidence against:

- The container is a non-reconstructable split-audit page and intentionally has no emitters.
- It mixes FileDownloader, MiniMap, FittingRoom, StartupWindow, and shared literal children.

Decision: reject as owner or emitter.

## Negative Evidence Summary

- No xrefs to `0x0060d950` or `0x0060d954`.
- No absolute-VA or RVA-form raw references to `0x0060d950`, `0x0060d954`, or RVA variants.
- No raw hidden references to `0x0060d94c` beyond the three known code immediates.
- No table/global/vtable/RTTI/initializer evidence for a source declaration object.
- No internal call graph among the three consumer functions.
- No single existing source file owns all three source-use contexts.
- The successor URL at `0x0060d958` is separately referenced and remains [UID:0003G2], so no merge is justified.
- The two non-target `version\0` substrings are embedded inside unrelated runtime/library text and have no xrefs.

## Final Recommendation

Exact changes applied or recommended:

- Applied changes: none.
- Recommended metadata changes: none.
- Recommended score changes: none; retain `88/93`.
- Recommended coverage-report changes: none.
- Recommended generated-report changes: none by hand. Current generated state is already correct.

Exact retained coverage state:

- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000JC,0000JE,0000O5`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE` blank

Why blank reconstruction C++ remains acceptable:

- This page represents a physical pooled source literal, not a proven standalone declaration.
- The emitters record source-use routing. Final function/method rewrites should spell `"version"` at the consuming parse sites unless later source/debug evidence proves a named shared constant.
- Adding a standalone source declaration here would invent a canonical owner that the binary does not support.

Exact `by-memory/-coverage-report.md` row text:

- No replacement row is required. The current row already records the correct owner/emitter result. If the supervisor wants a wording-only refresh to cite this second-pass audit, replace the existing `0003G1` row in place with:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key plus zero alignment; B002-0003G1 second-pass audit keeps `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000JE,0000O5` because IDA MCP and raw PE evidence prove exactly three source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`), with no interior/tail refs, no hidden pointer-table/global owner, and no single source declaration owner.
```

Placement context: if used, replace the current `0003G1` row between [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md).

## Follow-Up Actions

- Supervisor actions: accept no metadata/coverage change, or optionally apply the wording-only row refresh above.
- A-agent actions: none required.
- B002 future research actions: none for this target unless new source/debug/map evidence proves a real shared constants declaration.

## Confidence

- Recommendation confidence: `91/100`.
- Range/xref confidence: `94/100`.
- Score confidence: current `88/93` remains justified.
- Remaining uncertainty: original source spelling/declaration form. The binary proves one pooled storage address and three source-use contexts, but not whether the original source used repeated literals, a macro, or an unreferenced source-level constant folded into one string.

## Validator / Validation Results

- `validator.py` was not run because this was report-only work and no by-* documentation or generated report was edited.
- No dry-run validator mode was used.
- No memory-range validator mode was used.
- IDA MCP validation performed:
  - `server_health`: ok.
  - `get_bytes`: exact target bytes and successor bytes confirmed.
  - `get_string`: target `version` and successor URL confirmed.
  - `entity_query`: names, strings, and global sizes around the range confirmed.
  - `lookup_funcs`: target data is not a function; consumer function ranges confirmed.
  - `xrefs_to`: three target-head refs, zero interior/tail refs, one successor URL ref.
  - `analyze_function` / `analyze_component`: three independent consumer functions and shared `aVersion` use confirmed.
  - `search_text`: scoped source-use instructions confirmed.
  - `trace_data_flow`: data node and three code-use nodes confirmed.
- Raw PE validation performed:
  - exact target object uniqueness confirmed.
  - absolute-VA references confirmed only at three expected code immediate operands.
  - interior/tail/RVA pointer scans negative.
  - unrelated duplicate `version\0` substring contexts checked and rejected.
- Unresolved validation warnings/errors: none. One broad full-text IDA search timed out, but narrower IDA xrefs/scoped searches and raw PE scans completed and are sufficient.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0003G1-SharedVersionJsonKey-second-pass.md`
- Modified: none outside the B002 research folder.
- Renamed: none.
- Moved to executed: none. Supervisor owns execution/move.

## Blockers

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B002/0003G1-SharedVersionJsonKey-second-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
