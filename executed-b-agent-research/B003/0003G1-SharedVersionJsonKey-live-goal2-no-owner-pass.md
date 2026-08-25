** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# Final Recommendation

Keep [UID:0003G1] `0x0060d94c-0x0060d958.SharedVersionJsonKey` unchanged:

- `CANONICAL_OWNER:NONE`
- `EMITTER_UIDS:0000JC,0000JE,0000O5`
- `RECONSTRUCTABLE:TRUE`
- no split
- no reclassification
- no new child pages
- no coverage-report row change required

The current strange owner/emitter split is correct. Live IDA MCP evidence confirms that the exact physical ASCII `"version"` key at `0x0060d94c` has three source-use contexts: FileDownloader item-shop version parsing, FittingRoom item-state/catalog parsing, and StartupWindow update-metadata parsing. No one of those contexts is a defensible canonical declaration owner, and IDA shows the key is pushed directly as a string literal at each use rather than through a named shared global or constants object.

The exact emitter list should remain:

| Emitter UID | Source route | Proven source-use context |
| --- | --- | --- |
| `0000JC` | `by-file/FileDownloader.md` -> `auto-generated/NexusTK/network/FileDownloader.cpp` | `0x0041ad2e` in `sub_41AA00` / `DownloadCashShopVersion`, a FileDownloader-dispatched item-shop version helper. |
| `0000JE` | `by-file/FittingRoom.md` -> `auto-generated/NexusTK/cashshop/FittingRoom.cpp` | `0x004227c6` in `sub_422740` / `FittingRoomDialogItemState::LoadEncodedStateBuffer`, the cached/decoded item-shop catalog-state parser. |
| `0000O5` | `by-file/StartupWindow.md` -> `auto-generated/NexusTK/app/StartupWindow.cpp` | `0x00580cab` in `sub_580870` / `StartupWindow::RunUpdateCheck`, the startup update metadata parser. |

Do not add `CashShopVersionRequest`, `CashShopRequest`, `JsonCpp`, or a new shared constants owner as an emitter or canonical owner in this pass. Those candidates either own adjacent payload/parser infrastructure or library parsing code, not this pooled literal's proven source-use sites.

# Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Tracker row: active 2026-06-14 live Goal 2 no-owner memory pass, assigned to Agent-B003.
- Current metadata: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`.
- Current generated state: no-owner with three emitters. The generated memory report displays the first surfaced output path in the summary row, while `auto-generated/-ag-file-coverage.md` confirms all three emitter file roots are valid generated roots.

## Instruction Recheck

Read for this pass:

- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `inference_research.md`
- current `tools/leaser/Agents/no_owner_b-agent-tracker.md`

Relevant rule applied: `CANONICAL_OWNER` is semantic ownership, while `EMITTER_UIDS` is output routing. `by-structure.md` explicitly allows source-authored pooled strings/shared constants to keep `CANONICAL_OWNER:NONE` while using multiple proven source-use emitters.

## IDA MCP Facts

Live IDA MCP session:

- session: `a001_goal2_class_batch`
- input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- active: true
- analyzing: false

Target identity and bytes:

- `entity_query(0x0060d940-0x0060d970)` reports name `aVersion` at `0x0060d94c` and successor name `aHttpsSecureKru_0` at `0x0060d958`.
- The same query reports one extracted string at `0x0060d94c`, length `7`.
- Raw bytes show `76 65 72 73 69 6f 6e 00` at `0x0060d94c-0x0060d954`, followed by four zero bytes at `0x0060d954-0x0060d958`.
- `0x0060d958` starts the UTF-16LE `https://secure.kru.com/itemshop/data/itemshop.json` URL, not part of this child.

Xrefs:

| Address | IDA xrefs |
| --- | --- |
| `0x0060d94c` | exactly three xrefs: `0x0041ad2e`, `0x004227c6`, `0x00580cab` |
| `0x0060d950` | no xrefs |
| `0x0060d954` | no xrefs |
| `0x0060d958` | separate sole xref `0x0041ae84` in `sub_41AE20` |

Function mapping:

| Xref | Function | Function size | Current documented context |
| --- | --- | ---: | --- |
| `0x0041ad2e` | `sub_41AA00` | `0x41c` | [UID:0002TS] `DownloadCashShopVersion` |
| `0x004227c6` | `sub_422740` | `0x1d9` | [UID:0002E9] `FittingRoomDialogItemStateLoadEncodedStateBuffer` |
| `0x00580cab` | `sub_580870` | `0x88d` | [UID:0001IO] `StartupWindowUpdateCheck` |
| `0x0041ae84` | `sub_41AE20` | `0x2ec` | successor catalog URL use, not this target |

Decompiler context:

- `sub_41AA00` calls `sub_4278E0(..., "version", ...)` at `0x0041ad40` after parsing the downloaded `itemshop.ver` JSON-like buffer.
- `sub_422740` calls `sub_4278E0(..., "version", ...)` at `0x004227d8` while loading fitting-room item-state/catalog data.
- `sub_580870` calls `sub_581E40("version", 0)` at `0x00580cb3` while parsing startup update metadata from `nexustk.ver`.

Consumer function xrefs:

- `0x0041aa00` has one code xref from `0x0041b13c` inside `sub_41B110`, the FileDownloader message dispatcher.
- `0x00422740` has four code xrefs from fitting-room item-state/update paths: `0x0041cc30`, `0x004222c2`, `0x00422ac5`, and `0x00422f90`.
- `0x00580870` has one code xref from `_WinMain@16` at `0x004f5d52`.
- `0x0041ae20`, the successor catalog URL consumer, has one code xref from `sub_41B110` at `0x0041b156`.

Byte search for `76 65 72 73 69 6F 6E 00` found three hits: `0x0060d94c`, `0x0060fcd4`, and `0x00671b25`. The latter two have no direct xrefs and are not this source key; one lies in/near an unrelated CRC/error-string region and one is inside an `Incompatible version` style runtime string. They do not create additional emitters.

## Documentation Evidence

Current target page:

- Already records the exact range, string head, alignment tail, three xrefs, no-tail-ref state, and successor URL boundary.
- Current score `88/93` is supported by live IDA evidence.
- Current owner/emitter split matches current `by-structure.md` rules for pooled literals.

Emitter file roots:

| UID | Page | Score | Projected path | Route status |
| --- | --- | ---: | --- | --- |
| `0000JC` | `by-file/FileDownloader.md` | `85/88` | `NexusTK/network/` | valid generated root |
| `0000JE` | `by-file/FittingRoom.md` | `85/87` | `NexusTK/cashshop/` | valid generated root |
| `0000O5` | `by-file/StartupWindow.md` | `87/85` | `NexusTK/app/` | valid generated root |

Supporting pages:

- [UID:0002TS] `DownloadCashShopVersion` documents `itemshop.ver`, JsonCpp parse helpers, and `version` as a data ref in the FileDownloader-dispatched worker.
- [UID:0002E9] `FittingRoomDialogItemStateLoadEncodedStateBuffer` documents `version` lookup in the fitting-room catalog-state parser.
- [UID:000051] `FittingRoomDialogItemState` is `86/88`, owned/emitted through [UID:0000JE] `FittingRoom`, and documents the cache/catalog parse role.
- [UID:0001IO] `StartupWindowUpdateCheck` documents `version` parsing in the startup update path and is owned/emitted through [UID:0000O5] `StartupWindow`.
- [UID:0003AL] `CashShopDownloaderLiterals` is a reviewed `RECONSTRUCTABLE:FALSE` split-audit container. It correctly leaves this child as the shared literal between the FileDownloader, FittingRoom, and StartupWindow consumers.
- Neighbor [UID:0003G0] `CashShopVersionDownloadWideLiterals` and [UID:0003G2] `CashShopCatalogDownloadWideUrl` are FileDownloader-only literal children, which reinforces that `0003G1` was intentionally split out because its xrefs are broader.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with emitters `0000JC,0000JE,0000O5`

Evidence for:

- IDA shows exactly three direct references to the physical string head, one in each independent source-use family.
- The three consumers parse different payloads: online item-shop version data, cached/decoded fitting-room catalog state, and startup update metadata.
- All three emitter file roots clear the route gate and have valid generated file paths.
- `by-structure.md` explicitly allows pooled/shared literals to have no canonical owner and multiple emitters.

Evidence against:

- None strong. The remaining uncertainty is only final original source spelling: repeated string literal versus named constant.

Decision: accepted.

### 2. Assign canonical owner to `0000JC` FileDownloader

Evidence for:

- The string sits between FileDownloader/cash-shop literal children in `.rdata`.
- One xref is in `DownloadCashShopVersion`, and the surrounding URL/progress literals are FileDownloader-routed.

Evidence against:

- Two of the three live xrefs are not FileDownloader-owned: one is FittingRoom item-state parsing, one is StartupWindow update parsing.
- Consumer count or address adjacency is not declaration ownership proof.
- FileDownloader ownership would hide the other proven source-use contexts.

Decision: rejected as canonical owner; retained only as one emitter.

### 3. Assign canonical owner to `0000JE` FittingRoom or class `000051`

Evidence for:

- `FittingRoomDialogItemState::LoadEncodedStateBuffer` directly uses the key for catalog-state parsing.
- [UID:000051] and [UID:0000JE] both clear the current ownership/emitter gate.

Evidence against:

- FittingRoom accounts for only one xref.
- It cannot own the FileDownloader `itemshop.ver` parse use or the StartupWindow update parse use.

Decision: rejected as canonical owner; retained as one file-root emitter through `0000JE`.

### 4. Assign canonical owner to `0000O5` StartupWindow

Evidence for:

- `StartupWindow::RunUpdateCheck` directly searches for `"version"` in update metadata.
- [UID:0000O5] is a valid generated file root.

Evidence against:

- StartupWindow accounts for only one xref.
- It cannot own the item-shop or fitting-room catalog uses.

Decision: rejected as canonical owner; retained as one emitter.

### 5. Use `0000I1` CashShopVersionRequest or `0000I0` CashShopRequest

Evidence for:

- `CashShopVersionRequest` and `CashShopRequest` are real cash-shop payload/request files with valid projected paths.
- The FileDownloader item-shop version worker is feature-adjacent to those request classes.

Evidence against:

- Current IDA and documentation route the actual `sub_41AA00` worker body through FileDownloader: `0x0041aa00` is called from FileDownloader's message dispatcher, and the current generated memory coverage emits [UID:0002TS] through `0000JC`.
- `CashShopVersionRequest` owns the small payload class/vtable/destructor, not the shared string key or all three parse sites.
- Neither file explains the FittingRoom catalog parser or StartupWindow update parser refs.

Decision: rejected for this target. Revisit only if the worker body ownership is later moved with evidence.

### 6. Assign to JsonCpp

Evidence for:

- Two use sites pass the key into JsonCpp-style helpers.

Evidence against:

- JsonCpp is a third-party parser dependency and does not own product-specific member names.
- StartupWindow uses plain text substring parsing, not JsonCpp.

Decision: rejected.

### 7. Create a new shared constants owner

Evidence for:

- A shared constant such as `VERSION_KEY` is possible in source.

Evidence against:

- IDA shows direct pushes of `aVersion` at the use sites, not references through a named global/static object.
- No separate constants table or global declaration is evidenced.
- Other raw `version\0` byte hits are unreferenced/interior hits, arguing against a universal source constant.
- Creating a new owner solely to avoid `NONE` would violate the current owner/emitter split guidance.

Decision: rejected.

## Split And Reclassification Assessment

No split is needed.

- The child is already exact: ASCII `version` plus terminator, four-byte zero alignment, and stop before the successor UTF-16LE catalog URL.
- There are no refs to the interior bytes or the alignment tail.
- Splitting the four zero bytes into a separate padding child would not improve ownership or source routing.
- Widening into either neighbor would be wrong: [UID:0003G0] is FileDownloader-only wide literals, and [UID:0003G2] is the separate FileDownloader catalog URL.

Do not reclassify to non-reconstructable.

- This is a source string literal/key that must be represented in reconstructed source.
- The exact binary address is generated/poolable data, but the source semantics are product-owned.
- `source-declared/generated-binary` and `RECONSTRUCTABLE:TRUE` remain correct.

## Coverage Report

No direct edit to `by-memory/-coverage-report.md` is needed.

The current row already states the important final state: no canonical owner, emitters `0000JC,0000JE,0000O5`, exact xrefs, no tail refs, and no split/merge/reclassification requirement. If the supervisor wants to refresh row provenance to include this B003 live pass, the exact replacement row can be:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : B003 2026-06-14 live Goal 2 recheck keeps `CANONICAL_OWNER:NONE` and `EMITTER_UIDS:0000JC,0000JE,0000O5`; IDA MCP session `a001_goal2_class_batch` reconfirmed `aVersion` at `0x0060d94c`, exact three xrefs from FileDownloader item-shop version parsing (`0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`0x004227c6`), and StartupWindow update metadata parsing (`0x00580cab`), no interior/tail refs, a separate successor URL ref at `0x0060d958`, no JsonCpp/shared-constant/single-owner proof, and no split/merge/reclassification need.
```

## Follow-Up Actions

- Supervisor: no required by-memory coverage change. Optional provenance refresh row text is provided above.
- A-agent follow-up: none for this target.
- Future research trigger: revisit emitter `0000JC` only if the `DownloadCashShopVersion` worker body [UID:0002TS] is later moved out of FileDownloader with fresh evidence. Do not change this string route independently of that worker ownership decision.

## Validator Results

No validator command was run. This pass created only an Agent-B003 research report and made no `by-*` edits, no split, no rename, and no metadata changes.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B003/research/0003G1-SharedVersionJsonKey-live-goal2-no-owner-pass.md`
- Modified: none outside this report
- Leases used: none
- Dry runs used: none

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B003/0003G1-SharedVersionJsonKey-live-goal2-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
