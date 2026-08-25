** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Post-Migration Ownership / Emitter Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` at `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, score `88/93`, and blank reconstruction C++, but change `EMITTER_UIDS` from blank to `0000JC,0000JE,0000O5`.
- Final disposition: no single direct declaration owner is proven for the pooled ASCII `version` key, but the current owner/emitter model should not leave it non-emitting. Live IDA MCP and raw PE evidence prove three source-use file roots: [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and [UID:0000O5][StartupWindow](by-file/StartupWindow.md).
- Required action: supervisor should update the target header only for `EMITTER_UIDS`, optionally refresh the target status/ownership wording, replace the `by-memory/-coverage-report.md` row text shown below, then regenerate generated reports through the normal validator/autogen flow. Do not hand-edit `auto-generated/-ag-memory-coverage.md`.
- Confidence: `94/100` for bytes, range, xrefs, and no-split state; `90/100` for `CANONICAL_OWNER:NONE` plus the three-emitter route. Remaining uncertainty is only original source declaration form, not consumer use.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md`, current `no-owner` row with `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.
- Tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003G1`, assigned to Agent-B001 as `B001-0003G1-post-migration`.
- Previous report: `tools/leaser/Agents/Agent-B001/research/executed/0003G1-SharedVersionJsonKey-B001-0003G1.md`.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank reconstruction C++.

## Executive Recommendation

The old no-owner conclusion remains correct for canonical ownership, but the old blank-emitter conclusion is stale after the owner/emitter split migration.

This page documents one physical `.rdata` literal: ASCII `version` plus terminator and four bytes of zero alignment. IDA reports direct pushes of the same `aVersion` address from three independent product parse paths:

| Emitter route | Proven source-use site | Why this route clears |
| --- | --- | --- |
| [UID:0000JC][FileDownloader](by-file/FileDownloader.md) | `0x0041ad2e` in `sub_41AA00`, [UID:0002TS][DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) | FileDownloader file root is `85/88`; the helper downloads/parses `itemshop.ver` and reads `"version"`. |
| [UID:0000JE][FittingRoom](by-file/FittingRoom.md) | `0x004227c6` in `sub_422740`, [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md) | FittingRoom file root is `85/87`; the direct class consumer [UID:000051][FittingRoomDialogItemState](by-class/FittingRoomDialogItemState.md) is `86/88` and already emits through `0000JE`. |
| [UID:0000O5][StartupWindow](by-file/StartupWindow.md) | `0x00580cab` in `sub_580870`, [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | StartupWindow file root is `87/85`; the update-check parser fetches `nexustk.ver` and searches `"version"`. |

Use the file roots as emitters rather than the narrower FittingRoomDialogItemState class because this is a pooled literal with no canonical declaration owner. The emitter list should record final source-use file contexts, not invent a class-level static member or standalone global declaration. The class consumer remains important evidence and is already represented through the `FittingRoom.cpp` route.

## Supervisor Active Recheck

- Supervisor instruction: perform a post-migration owner/emitter recheck for the pooled/shared key literal and specifically test whether one or more emitters are justified even if `CANONICAL_OWNER:NONE` remains correct.
- Split repair required: no. The target is already the exact child `0x0060d94c-0x0060d958`; IDA confirms the successor at `0x0060d958` is the separate wide `itemshop.json` URL, and there are no xrefs to the interior or alignment tail.
- Parent/source repair required before action: no. All three selected file emitters clear the `85/85` gate. The FittingRoom direct class consumer also clears the gate and routes to `0000JE`.
- Coverage-report direct edit: not performed. Exact replacement text is included for supervisor application.

## Inference Research Guidance Check

`by-structure.md` now separates `CANONICAL_OWNER` from `EMITTER_UIDS`. It explicitly permits `CANONICAL_OWNER:NONE` with multiple emitters for compiler/linker-pooled string literals when no single declaration owner is proven but source-use contexts are proven. That rule applies directly here.

`inference_research.md` warns that `.rdata` adjacency is weak evidence, especially around string pooling and merged constants. The report therefore treats the adjacent FileDownloader item-shop URL strings as context, not ownership proof. Direct xrefs and consumer file roots drive the emitter recommendation.

Facts, documentation evidence, and inference are separated as follows:

- IDA facts: bytes, string value, exact xrefs, containing functions, no interior/tail refs, no internal call graph between the three consumers.
- Raw PE facts: full target object occurs once; target VA occurs only as the three code immediates; RVA/interior/tail pointer scans are negative.
- Documentation evidence: target page, prior B001 report, current tracker row, file/class consumer docs, and post-migration pooled-literal precedents.
- Inference: the physical string is a pooled or shared source literal with no defensible single canonical declaration owner, but each observed consumer source root should receive an emitter route.

## Evidence Standards Used

- IDA MCP session: `b001_0003gy`, active worker for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA tools used: `server_health`, `get_bytes`, `get_string`, `entity_query`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `search_text`, and `decompile`.
- Raw PE checks: PowerShell byte scan of `NexusTK.exe` for exact literal bytes, full target object bytes, absolute VA dwords, RVA dwords, and duplicate ASCII `version\0` occurrences.
- Documentation checks: target page, prior executed B001 report, no-owner tracker, `by-structure.md`, `inference_research.md`, file/class consumer pages, container/sibling literal pages, current `auto-generated/-ag-memory-coverage.md`, and current `by-memory/-coverage-report.md`.

## IDA MCP Facts

Function/range facts:

- `server_health` reported module `NexusTK.exe`, IDB `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- `lookup_funcs 0x0060d94c` returns `Not a function`.
- `entity_query` over `0x0060d940-0x0060d970` returns names `aVersion` at `0x0060d94c` and `aHttpsSecureKru_0` at `0x0060d958`; string query returns one string at `0x0060d94c`, length `7`.
- `get_string` returns `version` at `0x0060d94c` and `https://secure.kru.com/itemshop/data/itemshop.json` at `0x0060d958`.

Data/table/padding facts:

- `get_bytes 0x0060d94c size 12` returns `76 65 72 73 69 6f 6e 00 00 00 00 00`.
- `0x0060d94c-0x0060d954` is ASCII `version` plus terminator.
- `0x0060d954-0x0060d958` is zero alignment.
- `0x0060d958` begins the separate UTF-16LE successor URL.

Xref facts:

| Address | IDA result | Meaning |
| --- | --- | --- |
| `0x0060d94c` | exactly three data refs | The target string is used by three code sites. |
| `0x0041ad2e` | `push offset aVersion` in `sub_41AA00`, size `0x41c` | FileDownloader item-shop version parse. |
| `0x004227c6` | `push offset aVersion` in `sub_422740`, size `0x1d9` | FittingRoomDialogItemState decoded catalog-state parse. |
| `0x00580cab` | `push offset aVersion` in `sub_580870`, size `0x88d` | StartupWindow update metadata parse. |
| `0x0060d950` | zero xrefs | No mid-string pointer use. |
| `0x0060d954` | zero xrefs | No alignment-tail owner or consumer. |
| `0x0060d958` | one data ref at `0x0041ae84` in `sub_41AE20` | Separate FileDownloader catalog URL child. |

Behavior facts:

- `search_text` in each consumer range finds one `push offset aVersion ; "version"` at the three addresses above.
- `trace_data_flow backward 0x0060d94c` reports the data node `db 'version',0` and exactly the three push instructions.
- `analyze_component` on `0x0041aa00`, `0x00422740`, and `0x00580870` reports no internal call graph edges between the three functions. Its shared globals are only `aVersion` and `___security_cookie`.
- `analyze_component` strings list `version` in all three consumers; StartupWindow also lists `nexustk.ver`, `minimap`, and `:` while FileDownloader/FittingRoom use JsonCpp-style helper calls.
- `decompile 0x0041aa00` shows `sub_4278E0(..., "version", ...)` after downloading/parsing `itemshop.ver`, then copying the parsed value into `dword_67A73C + 1936` when fitting-room state exists.
- `decompile 0x00422740` shows the FittingRoom item-state parser looking up `"version"`, moving the extracted value into the state header, then loading categories.
- `decompile 0x00580870` shows StartupWindow fetching `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`, searching `"version"`, parsing the numeric update version, then separately handling `minimap`.

Negative IDA facts:

- No vtable, constructor, initializer, table, RTTI item, global object, or helper function owns `0x0060d94c`.
- No IDA evidence ties the three consumers through a shared product parser abstraction.
- No xrefs to the alignment tail justify a separate child split.
- The successor URL is one-address-adjacent but separately referenced, so it does not make FileDownloader the canonical owner of this pooled key.

## Raw PE Facts

PowerShell PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found:

| Pattern | Result | Meaning |
| --- | --- | --- |
| Full target bytes `version\0\0\0\0\0` | one hit at file offset `0x20c34c`, VA `0x0060d94c` | The exact target object is unique. |
| ASCII `version\0` | three hits: `0x0060d94c`, `0x0060fcd4`, `0x00671b25` | The two non-target hits are embedded in unrelated library/runtime message strings. |
| Absolute VA `0x0060d94c` little-endian | three hits at VAs `0x0041ad2f`, `0x004227c7`, `0x00580cac` | Immediate operand bytes for the three IDA refs. |
| Absolute VA `0x0060d950` little-endian | zero hits | No hidden mid-string pointer. |
| Absolute VA `0x0060d954` little-endian | zero hits | No hidden alignment-tail pointer. |
| Absolute VA `0x0060d958` little-endian | one hit at VA `0x0041ae85` | Immediate operand bytes for separate successor URL ref. |
| RVA `0x0020d94c`, `0x0020d950`, `0x0020d954`, `0x0020d958` little-endian | zero hits | No RVA-form table/pointer owner found. |

The duplicate `version\0` substrings at `0x0060fcd4` and `0x00671b25` occur inside unrelated text such as color-conversion/CRC and incompatible-version/buffer-error messages. They are not product JSON key uses and do not affect emitter routing.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Canonical Owner | Emitters | Score | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL][CashShopDownloaderLiterals](by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Mixed literal-pool audit container | `FALSE` | `NONE` | blank | `89/92` | Keep non-emitting container. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | FileDownloader `itemshop.ver` URL/progress literals | `TRUE` | `0000JC` | `0000JC` | `86/91` | Separate predecessor, no merge. |
| `0x0060d94c-0x0060d958` | [UID:0003G1][SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | Shared ASCII `version` key plus alignment | `TRUE` | `NONE` | recommend `0000JC,0000JE,0000O5` | `88/93` | Current target. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) | FileDownloader `itemshop.json` URL | `TRUE` | `0000JC` | `0000JC` | `86/92` | Separate successor, no merge. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e` -> `0x0060d94c` | `push offset aVersion` in `sub_41AA00` / [UID:0002TS] | FileDownloader-dispatched `itemshop.ver` JSON/version parse. |
| `0x004227c6` -> `0x0060d94c` | `push offset aVersion` in `sub_422740` / [UID:0002E9] | FittingRoomDialogItemState decoded item-shop catalog-state parse. |
| `0x00580cab` -> `0x0060d94c` | `push offset aVersion` in `sub_580870` / [UID:0001IO] | StartupWindow update metadata parse. |
| `0x0041ae84` -> `0x0060d958` | `push offset aHttpsSecureKru_0` in `sub_41AE20` / [UID:0002TT] | Separate FileDownloader catalog URL consumer. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page [UID:0003G1] documents the exact range, `aVersion`, three xrefs, no-tail-ref state, and the old parent-blank conclusion. Live IDA confirms those facts.
- Previous report `0003G1-SharedVersionJsonKey-B001-0003G1.md` correctly rejected a single canonical parent, but it predates applying the current emitter model to this item.
- [UID:0002TS][DownloadCashShopVersion](by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) documents FileDownloader-dispatched `itemshop.ver` parsing and the `version` key. Live IDA confirms the use.
- [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md) documents decoded catalog-state parsing and the `version` key. Live IDA confirms the use.
- [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) documents `nexustk.ver` update parsing and the `version` key. Live IDA confirms the use.
- File roots [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), and [UID:0000O5][StartupWindow](by-file/StartupWindow.md) all meet the `85/85` route gate.
- Current post-migration pooled-literal precedents [UID:0003FY][SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md), [UID:0003FZ][MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md), and [UID:0003IO][SharedGmWideString](by-memory/0x0061e6f8-0x0061e700.SharedGmWideString.md) use `CANONICAL_OWNER:NONE` with multiple file-root emitters for comparable shared literal cases.

Existing docs that need migration/update:

- [UID:0003G1] still has blank `EMITTER_UIDS`; this is now incomplete for a proven pooled literal with three source-use routes.
- `by-memory/-coverage-report.md` still says "parent blank because no single direct source owner covers every use" without recording the now-justified emitter routes.
- `auto-generated/-ag-memory-coverage.md` currently lists `0003G1` as no-owner with blank emitters. This should be regenerated after metadata changes, not edited by hand.

## Ranked Ownership / Routing Analysis

### 1. `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`

Evidence for:

- This exactly matches the current by-structure rule for pooled literals with no proven declaration owner but multiple proven source-use contexts.
- IDA confirms one physical string used by three independent file roots.
- Raw PE scan finds no pointer table, RVA reference, alignment-tail reference, or hidden declaration object.
- All three file roots clear `85/85`.
- Comparable accepted pages use file-root emitter lists while keeping canonical owner `NONE`.

Evidence against:

- Original source may have had an explicit shared macro or constant declaration not recoverable from the stripped binary.
- Future source/debug/map evidence could prove a real shared constants owner.

Decision: accepted. This is no-owner, but not non-emitting.

### 2. New shared constants owner, such as `ProductJsonKeys` or `OnlineMetadataKeys`

Evidence for:

- The token `version` is semantically generic and appears in update, item-shop, and catalog parsing.
- A source tree could have used a shared macro/header constant for common metadata keys.

Evidence against:

- IDA and PE evidence show direct immediate string references, not a named global object, table, header-emitted data block, initializer, or helper.
- The three consumers do not share one parser abstraction: FileDownloader/FittingRoom use JsonCpp-style access while StartupWindow uses substring parsing around curl response text.
- Creating a new owner from one pooled key would invent source structure and risks becoming a catch-all for common words.

Decision: reject for current action. Revisit only if future source/debug/map evidence or a broader shared constants cluster appears.

### 3. [UID:0000JC] FileDownloader as canonical owner

Evidence for:

- One direct ref is in `DownloadCashShopVersion`.
- The target is adjacent to FileDownloader item-shop URL/progress literal children.
- `0000JC` clears `85/85`.

Evidence against:

- Two direct refs are outside FileDownloader: FittingRoomDialogItemState and StartupWindow.
- `.rdata` adjacency is weak evidence around string pooling.
- Canonical FileDownloader ownership would hide two material consumers.

Decision: reject as canonical owner; accept as one emitter.

### 4. [UID:000051] FittingRoomDialogItemState / [UID:0000JE] FittingRoom as canonical owner

Evidence for:

- One direct ref is in the direct class method [UID:0002E9].
- The class and file both clear `85/85`.
- FittingRoom item-state owns the cached item-shop catalog parsing context.

Evidence against:

- FileDownloader and StartupWindow refs are direct and independent.
- The target is not a class member, class vtable, or class-only literal.
- `000051` is better treated as the direct consumer evidence that justifies the file-root emitter `0000JE`.

Decision: reject as canonical owner; accept `0000JE` as one emitter route.

### 5. [UID:0000O5] StartupWindow as canonical owner

Evidence for:

- One direct ref is in [UID:0001IO] `StartupWindowUpdateCheck`.
- `StartupWindow.cpp` owns the `nexustk.ver` update metadata parse.
- `0000O5` clears `85/85`.

Evidence against:

- Item-shop version parsing and FittingRoom catalog-state parsing are direct independent consumers.
- StartupWindow does not own the cash-shop/fitting-room parse surfaces.

Decision: reject as canonical owner; accept as one emitter.

### 6. [UID:0000KI] JsonCpp

Evidence for:

- Two consumers use JsonCpp-style helpers.

Evidence against:

- `version` is a product field name supplied to the parser, not JsonCpp library data.
- StartupWindow uses a separate text-search path, not the JsonCpp object-access pattern.

Decision: reject.

### 7. [UID:0003AL] CashShopDownloaderLiterals container

Evidence for:

- The target is a child of this physical literal-pool container.

Evidence against:

- The container is a reviewed non-emitting mixed audit page.
- It has `RECONSTRUCTABLE:FALSE` and should not receive emitters.
- It includes unrelated minimap, FileDownloader, FittingRoom, and StartupWindow context.

Decision: reject as owner or emitter.

## Negative Evidence Summary

- No xrefs to `0x0060d950` or `0x0060d954`.
- No RVA-form references to the target, interior, tail, or successor URL.
- No extra absolute-VA references beyond the three text immediates.
- No component-level call edges between the three consumers.
- No hidden table, vtable, constructor, RTTI, initializer, or global object points to the target.
- No single existing source file owns all three source-use contexts.
- The two non-target raw `version\0` substrings are unrelated error/library text and have no bearing on product JSON key routing.
- Address adjacency to FileDownloader URL strings is outweighed by direct non-FileDownloader xrefs.

## Final Recommendation

Exact metadata/header changes recommended for `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`:

```text
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JC,0000JE,0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Only `EMITTER_UIDS` changes from current target metadata. Keep `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and blank reconstruction C++.

Recommended target-page body wording, if supervisor updates explanatory text:

```text
- Canonical owner: `NONE`. The exact same physical `version` literal is consumed by FileDownloader item-shop version parsing, FittingRoomDialogItemState catalog-state parsing, and StartupWindow update metadata parsing, and no shared declaration owner is proven.
- Emitter routing: `EMITTER_UIDS:0000JC,0000JE,0000O5`. These are source-use file roots, not declaration ownership. Final reconstructed source should spell `"version"` at the consuming parse sites unless later source/debug evidence proves a named shared constant.
```

Exact `by-memory/-coverage-report.md` replacement row:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001-0003G1 post-migration recheck keeps `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but recommends `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`).
```

Placement context: replace the existing `0003G1` row between [UID:0003G0][CashShopVersionDownloadWideLiterals](by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][CashShopCatalogDownloadWideUrl](by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md).

Expected generated-report effect after normal regeneration:

- `auto-generated/-ag-memory-coverage.md` should keep `Status` as `no-owner`, keep `Canonical Owner` as `NONE`, and show emitters `` `0000JC`,`0000JE`,`0000O5` `` for `0003G1`.
- Relative stats effect from the current report state: `Total_Reconstructable_NoOwner` unchanged; `Total_Reconstructable_NoOwner_Emitters` increases by `1`; `Total_Reconstructable_NonEmits` decreases by `1`; `Total_Reconstructable_Emits` increases by `1`; `Total_Reconstructable_MultipleEmitters` increases by `1`.

## Follow-Up Actions

- Supervisor actions: apply the single target metadata change, update the target explanatory body if desired, replace the `by-memory/-coverage-report.md` row above, run normal non-dry-run validator/autogen flow for the touched files, regenerate reports, and move this report to `research/executed` when accepted.
- A-agent actions: none required unless supervisor wants the target body wording updated by a normal docs pass.
- B001 future research actions: none for `0003G1` unless future source/debug/linker-map evidence proves an explicit shared constants owner.

## Confidence

- Recommendation confidence: `90/100`.
- Range/xref confidence: `94/100`.
- Score confidence: current `88/93` remains justified; no score increase is recommended.
- Remaining uncertainty: original source spelling and declaration form. The binary proves one pooled storage address and three source-use contexts, but not whether the original source used a shared constant, macro, or repeated string literals folded by the toolchain.

## Validator / Validation Results

- No `validator.py` run was performed because this session created only a B001 research report and did not edit target by-* docs or generated files.
- No dry-run validator mode was used.
- Validation performed:
  - IDA MCP `server_health`: ok, Hex-Rays ready, auto-analysis ready, strings cache ready.
  - IDA MCP `get_bytes`, `get_string`, `entity_query`, `xrefs_to`, `lookup_funcs`, `trace_data_flow`, `analyze_component`, `search_text`, and `decompile`: results summarized above.
  - PowerShell raw PE scan: exact target object unique; three absolute-VA immediate refs; zero RVA-form refs; zero interior/tail pointer refs.
- Unresolved validation warnings/errors: none for this report-only pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G1-SharedVersionJsonKey-post-migration.md`
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none. Supervisor owns execution/move.

## Blockers

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B001/0003G1-SharedVersionJsonKey-post-migration.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
