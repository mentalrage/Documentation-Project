** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Ownership / Split Research

Revision: B001-0003G1 final, 2026-06-12

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` parent-blank, reconstructable, and scored `88/93`. Do not assign it to FileDownloader, FittingRoomDialogItemState/FittingRoom, StartupWindow, JsonCpp, or the surrounding cash-shop literal container.
- Final disposition: source-declared/generated-binary narrow ASCII `version` key literal plus alignment. The source-level key is shared by three unrelated product parsing surfaces, and current IDA/PE evidence shows only direct consumer pushes, not a shared declaration owner or table owner.
- Required action: no by-* documentation edits and no coverage-report row edits are recommended. Supervisor should retain the existing `by-memory/-coverage-report.md` and `auto-generated/-ag-memory-coverage.md` rows unchanged.
- Confidence: `94/100` for bytes, range, xrefs, and split/no-split disposition; `88/100` for the parent-blank ownership recommendation. The remaining uncertainty is original source declaration placement, which the stripped binary does not prove.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Source queue/report row: active supervisor assignment `B001-0003G1`, sourced from the active `Supervisor_notes.md` row for a `reviewed-85-but-ownership-unknown-under-review` item.
- Current supervisor classification: ownership/source-family/split inference required after C001 Batch C001-014 raised the child to `88/93` and kept parent blank.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank.

## Executive Recommendation

The best direct documentation disposition is still parent blank. This is not because the item is poorly understood. The item is well bounded and well evidenced, but the one physical string literal is consumed by three separate source families:

- FileDownloader item-shop version parsing at `0x0041ad2e` inside [UID:0002TS].
- FittingRoomDialogItemState encoded catalog-state parsing at `0x004227c6` inside [UID:0002E9].
- StartupWindow update/minimap metadata parsing at `0x00580cab` inside [UID:0001IO].

No single existing direct parent owns all three uses. FileDownloader and FittingRoom both use JsonCpp-style object access around item-shop data, while StartupWindow uses its update-check parsing path for `nexustk.ver`. The shared literal is probably a compiler/linker-pooled string literal or a manually repeated identical source literal; the binary does not prove an explicit shared `const char[]` declaration.

If forced to choose an existing source family, FileDownloader is only the closest by address adjacency to the neighboring `itemshop.ver` and `itemshop.json` literals, but it is still the wrong direct parent because two of the three direct refs are outside FileDownloader. The correct action is therefore no-op: keep the page parent blank until a PDB, linker map, source artifact, relocation/table owner, or a broader IDA-backed constants cluster proves a shared owner.

## Supervisor Active Recheck

- Supervisor instruction: research whether the shared `version` literal should stay parent-blank, attach to an existing direct parent, split, or imply a new source/file owner.
- Split repair required: no. The target is already the exact narrow key plus alignment child from [UID:0003AL]. IDA and PE checks confirm the successor at `0x0060d958` is a separate wide URL with its own FileDownloader-only ref.
- Source-bearing children in scope: none to create. Splitting the four-byte alignment tail into a separate child would create padding-only documentation with no source-owner value and would make the key page less clear.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` both matter here because they warn against treating address adjacency or consumer xrefs as source declaration proof. This report separates:

- IDA facts: bytes, names, xrefs, functions, string extraction, and successor boundary.
- PE facts: direct VA immediate hits, no RVA/table/relative pointer hits, and incidental duplicate substring checks.
- Documentation evidence: current by-* pages for FileDownloader, FittingRoomDialogItemState, StartupWindow, JsonCpp, and the literal container.
- Inference: the literal is shared source-declared data, but no modeled source owner clears the direct-parent standard.

Existing documentation was treated as a hypothesis. The current target page's parent-blank conclusion is confirmed by fresh negative evidence; the broader [UID:0003AL] `CashShopDownloaderLiterals` name is useful as an address-neighborhood container only and is not treated as ownership proof.

## Evidence Standards Used

- Live IDA MCP evidence: function lookup, xrefs, bytes, names/string extraction, decompilation snippets, and component analysis for the three consumers.
- PE/raw evidence: file-offset mapping, exact ASCII search, VA/RVA/relative pointer scans, and duplicate `version` substring checks.
- Documentation evidence: target page, sibling by-memory pages, candidate by-file/by-class parents, JsonCpp third-party page, generated coverage rows, and prior B001/C001 reports that touch this literal neighborhood.
- Negative evidence: absence of tail xrefs, absence of hidden pointer/table refs, absence of a single caller/callee cluster, absence of a broader IDA-extracted standalone `version` key family, and unrelated duplicate `version` substrings in third-party/runtime messages.

The evidence is strong enough to reject all current parent assignments. It is not strong enough to create a new shared constants owner because all confirmed references are direct immediate string references from the consumer functions.

## IDA MCP Facts

Function and range facts:

- `0x0060d94c` is not a function. IDA names it `aVersion`.
- `0x0060d958` is the successor named wide URL `aHttpsSecureKru_0`, not part of the `version` key.
- `lookup_funcs` maps the direct refs to:
  - `0x0041ad2e` in `sub_41AA00`, documented as [UID:0002TS] `DownloadCashShopVersion`.
  - `0x004227c6` in `sub_422740`, documented as [UID:0002E9] `FittingRoomDialogItemStateLoadEncodedStateBuffer`.
  - `0x00580cab` in `sub_580870`, documented as [UID:0001IO] `StartupWindowUpdateCheck`.

Data and padding facts:

- Bytes around the range decode as previous UTF-16 progress-string tail/alignment, then `76 65 72 73 69 6f 6e 00 00 00 00 00`, then the UTF-16 successor URL beginning at `0x0060d958`.
- `0x0060d94c-0x0060d954` is ASCII `version` plus terminator.
- `0x0060d954-0x0060d958` is zero alignment before the successor wide URL.
- IDA string extraction reports one standalone string at `0x0060d94c`, length `7`.

Xref facts:

- `xrefs_to 0x0060d94c` returns exactly three data refs: `0x0041ad2e`, `0x004227c6`, and `0x00580cab`.
- `xrefs_to 0x0060d950` returns none.
- `xrefs_to 0x0060d954` returns none.
- `xrefs_to 0x0060d958` returns exactly one data ref, `0x0041ae84` in `sub_41AE20`, documented as [UID:0002TT] `DownloadCashShopCatalog`.
- `trace_data_flow backward 0x0060d94c` reports the three `push offset aVersion` instructions and no alternate owner path.

Behavior facts from decompilation:

- `sub_41AA00` passes `"version"` to the JsonCpp/object-access helper while processing `itemshop.ver`, then copies the parsed version into active fitting-room/item-shop state near `dword_67A73C + 1936` when the parse succeeds.
- `sub_422740` parses a decoded FittingRoom item-state buffer and reads `"version"` before processing item-shop category data.
- `sub_580870` fetches/parses startup update metadata from `nexustk.ver`, reads `"version"` through the StartupWindow string parsing helper, then also handles `minimap` metadata and minimap downloads.

Component facts:

- `analyze_component` over `0x0041aa00`, `0x00422740`, and `0x00580870` reports all three functions sharing `aVersion`.
- The same component analysis reports no internal call edges between the three functions.
- The only meaningful shared global/string across the three product functions is `aVersion`; the remaining shared item is the security cookie machinery.

Negative IDA facts:

- No function object, data table, vtable, constructor, initializer, or direct parent object points to the `version` literal.
- No xrefs to the alignment tail support a separate source item there.
- No xref from the successor `itemshop.json` URL points back to the `version` key; that URL is a FileDownloader-only sibling and should remain separate.

## PE / Raw Binary Facts

PE mapping for the target neighborhood places the range in `.rdata`:

| VA | File offset | Section |
| --- | ---: | --- |
| `0x0060d940` | `0x20c340` | `.rdata` |
| `0x0060d94c` | `0x20c34c` | `.rdata` |
| `0x0060d958` | `0x20c358` | `.rdata` |
| `0x0060d9c0` | `0x20c3c0` | `.rdata` |

Direct VA immediate hits:

| Target VA | PE hits | Meaning |
| --- | --- | --- |
| `0x0060d94c` | `0x0041ad2f`, `0x004227c7`, `0x00580cac` in `.text` | Immediate operand bytes inside the three IDA data refs. |
| `0x0060d950` | none | No hidden pointer to the middle of the literal. |
| `0x0060d954` | none | No hidden pointer to alignment tail. |
| `0x0060d958` | `0x0041ae85` in `.text` | Immediate operand bytes inside the FileDownloader catalog URL ref. |
| `0x0060d9c0` | none | No hidden pointer just after the URL range. |

RVA dword scans for the target, tail, successor URL, and successor end found no hits. Text-relative candidate scans to `0x0060d94c` and `0x0060d958` found no hits. This rejects a hidden array/table owner or relative pointer owner for the literal.

Exact raw ASCII `version\0` occurrences in `NexusTK.exe`:

| VA | Context | Decision |
| --- | --- | --- |
| `0x0060d94c` | target standalone key | Real product key literal. |
| `0x0060fcd4` | inside LodePNG message text about unsupported color conversion | Incidental substring, no xrefs found. |
| `0x00671b25` | inside zlib/error text `incompatible version` | Incidental substring, no xrefs found. |

The duplicate raw substrings do not support a shared product key owner. They are embedded inside unrelated third-party/runtime messages and have no direct xrefs in this task's checks.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` | Non-emitting split-audit container for mixed literal neighborhood | `FALSE` | blank | `89/92` | Correct as container only. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md` | FileDownloader `itemshop.ver` URL/progress wide literals | `TRUE` | [UID:0000JC] FileDownloader | `86/91` | Separate predecessor child, should not merge with target. |
| `0x0060d94c-0x0060d958` | [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | Shared ASCII `version` key plus alignment | `TRUE` | blank | `88/93` | Current target; keep parent blank. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2] `by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md` | FileDownloader `itemshop.json` URL | `TRUE` | [UID:0000JC] FileDownloader | `86/92` | Separate successor child, one FileDownloader ref. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e` -> `0x0060d94c` | `push offset aVersion` in `sub_41AA00` / [UID:0002TS] | FileDownloader-dispatched `itemshop.ver` JSON/version parse. |
| `0x004227c6` -> `0x0060d94c` | `push offset aVersion` in `sub_422740` / [UID:0002E9] | FittingRoomDialogItemState decoded item-shop catalog-state parse. |
| `0x00580cab` -> `0x0060d94c` | `push offset aVersion` in `sub_580870` / [UID:0001IO] | StartupWindow update metadata parse. |
| `0x0041ae84` -> `0x0060d958` | `push offset aHttpsSecureKru_0` in `sub_41AE20` / [UID:0002TT] | Separate FileDownloader catalog URL consumer. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0003G1] already documents the exact range, xrefs, tail non-xrefs, successor split, candidate parents, and parent-blank blocker. B001 IDA/PE checks support the page rather than contradicting it.
- [UID:0003AL] documents the surrounding range as a mixed literal split-audit container, not as a direct owner. IDA confirms the neighborhood contains FileDownloader-only item-shop URLs and the shared key.
- [UID:0002TS] documents `DownloadCashShopVersion` as FileDownloader-dispatched item-shop version parsing. IDA confirms the `version` ref and the item-shop parse behavior.
- [UID:0002E9] documents `FittingRoomDialogItemStateLoadEncodedStateBuffer` as decoded item-shop catalog-state parsing. IDA confirms the `version` ref and the separate FittingRoom owner family.
- [UID:0001IO] documents `StartupWindowUpdateCheck` as startup update/minimap metadata parsing. IDA confirms the `version` ref and a distinct parsing surface from the item-shop code.
- [UID:0000KI] `JsonCpp` is a third-party parser owner. IDA confirms JsonCpp helper calls in item-shop/FittingRoom paths, but the target literal itself is a product key and not JsonCpp-owned.

Existing docs that are stale, incomplete, or contradicted:

- No direct contradiction was found in the current target page.
- Any future wording that treats [UID:0003AL] `CashShopDownloaderLiterals` as a source owner would be misleading; it is only a non-emitting mixed-range container.
- Any future wording that treats FileDownloader adjacency as proof of ownership would be incomplete because the two non-FileDownloader refs are direct IDA facts.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` lists `0003G1` as unassigned. That is correct.
- `by-memory/-coverage-report.md` lists `0003G1` as reconstructable, parent blank, and very-strong confidence. That is correct.

## Ranked Ownership Analysis

### 1. Parent-blank pooled/shared product key literal

Evidence for:

- Exact same `.rdata` string literal has direct refs from FileDownloader, FittingRoomDialogItemState, and StartupWindow.
- PE scans found no hidden table, RVA pointer, or relative pointer owner.
- IDA component analysis found no call edges linking the three consumer functions into one source-family helper.
- The stripped binary cannot distinguish explicit shared declaration from compiler/linker string pooling, so attaching to a single consumer would overclaim direct source ownership.
- The item is reconstructable as source-declared/generated-binary data even while parent blank; by-structure permits confirmed reconstructable but unattached items when source ownership is not ready.

Evidence against:

- A future source artifact could prove that all three uses referenced a common `const char *kVersionKey` or shared header macro.
- The physical string is in one address, so there was some binary-level pooling or shared storage after compilation/linking.

Decision: accepted. Keep parent blank and document the exact evidence required to change the decision.

Confidence: `88/100`.

### 2. New shared constants owner, for example `ProductJsonKeys` or `OnlineMetadataKeys`

Evidence for:

- The semantic token `version` is generic and appears in three product metadata parsers.
- A real source tree could plausibly have used a shared header constant or macro for common protocol/update/item-shop keys.
- If such an owner existed, it would likely contain more than this item: the `version` key, the StartupWindow `minimap` key used in the same update parser, and possibly item-shop catalog/category field keys used by FittingRoom and cash-shop catalog parsers.

Evidence against:

- IDA and PE evidence show only direct immediate references to `aVersion`, not address-taken uses of a global constant object, pointer table, string array, import, initializer, or shared helper function.
- The three consumers do not share one parser abstraction. FileDownloader/FittingRoom use JsonCpp-style access, while StartupWindow uses a separate startup update parsing path.
- The neighboring literal pages do not form a generic key table. [UID:0003G0] and [UID:0003G2] are FileDownloader URLs/progress strings, not shared keys. [UID:0003FZ] is a separate minimap/download literal cluster and not proven to be a constants declaration owner.
- Creating a new source file now would invent a source module from one pooled string and would risk becoming a broad catch-all for common words.

Decision: rejected for current action. Revisit only if future evidence shows a shared declaration, matching source artifact, table owner, or wider cluster of direct refs to common key constants.

Confidence: `80/100` rejection as current action.

### 3. [UID:0000JC] FileDownloader

Evidence for:

- The target sits physically between FileDownloader item-shop version and catalog URL children.
- One direct ref is from [UID:0002TS] `DownloadCashShopVersion`.
- The successor URL at `0x0060d958` and predecessor URL/progress page are FileDownloader-owned.

Evidence against:

- Two of the three direct refs are outside FileDownloader: FittingRoomDialogItemState and StartupWindow.
- Address adjacency in `.rdata` is weak evidence for source declaration ownership, especially around pooled string literals.
- Assigning to FileDownloader would hide the StartupWindow update use and FittingRoom catalog-state use.

Decision: rejected. If forced to choose only one existing source-family owner, FileDownloader is the closest by adjacency, but it remains below the action threshold.

Confidence: `86/100` rejection.

### 4. [UID:000051] FittingRoomDialogItemState / [UID:0000JE] FittingRoom

Evidence for:

- One direct ref is from [UID:0002E9], a FittingRoomDialogItemState parser that reads decoded item-shop catalog/cache state.
- The FileDownloader `itemshop.ver` path writes version-like data into fitting-room/item-shop state, so the key participates in the cash-shop/fitting-room data model.

Evidence against:

- FileDownloader and StartupWindow refs are direct and independent.
- The target is not localized to the FittingRoom encoded-state parser or its category key set.
- The FileDownloader version helper and StartupWindow update helper are not child functions of FittingRoomDialogItemState.

Decision: rejected as direct parent.

Confidence: `86/100` rejection.

### 5. [UID:0000O5] StartupWindow

Evidence for:

- One direct ref is from [UID:0001IO] `StartupWindowUpdateCheck`.
- StartupWindow's `nexustk.ver` parsing is a natural semantic owner for update `version` data.

Evidence against:

- The item-shop version and FittingRoom item-state refs are direct and independent.
- StartupWindow uses the same string as an update metadata key, not as the owner of item-shop parser constants.
- No caller/callee or table evidence ties the item-shop parse helpers to StartupWindow.

Decision: rejected as direct parent.

Confidence: `87/100` rejection.

### 6. [UID:0000KI] JsonCpp

Evidence for:

- Two of the three consumers use JsonCpp-style parse/access helpers around the `version` key.

Evidence against:

- JsonCpp is a third-party parser implementation; it does not own NexusTK product field names.
- StartupWindow's update path does not use the same JsonCpp object-access shape.
- The literal is a caller-supplied key, not library-internal parser data.

Decision: rejected.

Confidence: `93/100` rejection.

### 7. [UID:0003AL] CashShopDownloaderLiterals container

Evidence for:

- The target was split out of this literal-neighborhood page.
- The surrounding address range includes FileDownloader item-shop URLs and this shared key.

Evidence against:

- [UID:0003AL] is deliberately `RECONSTRUCTABLE:FALSE` as a mixed audit/container page.
- A container page is not a source owner for the exact child. Its children carry the actual reconstruction state.
- The target has a non-cash-shop StartupWindow ref.

Decision: rejected as direct parent. Keep as cross-reference/context only.

Confidence: `92/100` rejection.

## Proposed New File / Grouping Evaluation

No new file or grouping is recommended now.

If future evidence proves an explicit shared constants owner, the likely owner would be narrow rather than broad: something like `NexusTK/common/ProductJsonKeys.h` or `NexusTK/protocol/OnlineMetadataKeys.h`, containing source-level declarations for product metadata keys used across update, cash-shop, and catalog parsing. Likely candidates to investigate under that future hypothesis would include:

- `version` at `0x0060d94c`, current [UID:0003G1].
- The StartupWindow `minimap` key used inside [UID:0001IO], if a source-level constants cluster is proven.
- FittingRoom/item-shop catalog field keys consumed by [UID:0002E9] and nearby catalog loaders, if they share the same declaration pattern.

Candidate related items rejected for current grouping:

- [UID:0003G0] `CashShopVersionDownloadWideLiterals`: URL/progress wide literals, FileDownloader-owned, not generic JSON keys.
- [UID:0003G2] `CashShopCatalogDownloadWideUrl`: FileDownloader-only URL, not a shared key.
- [UID:0003FZ] `MinimapDownloadWideLiterals`: mixed minimap/download wide literals; related to StartupWindow/minimap behavior but not evidence of a shared key declaration.
- [UID:0000KI] `JsonCpp`: parser implementation, not product constants.

The new-file inference would be broad enough to include shared metadata key names, but current evidence does not justify creating it from one pooled literal. The correct current representation is a source-declared data item left unassigned with documented consumers.

## Negative Evidence Summary

- No hidden xrefs to the alignment tail at `0x0060d954`.
- No hidden xrefs to `0x0060d950`, so there is no evidence of mid-string pointer use.
- No RVA dword, VA table, or relative pointer owner beyond the three immediate text operands.
- No direct component call graph linking FileDownloader, FittingRoomDialogItemState, and StartupWindow through one source-owned parser helper.
- No table, constructor, vtable, RTTI, global object, or initializer ties this literal to a direct owner.
- No other standalone product `version\0` key occurrence with xrefs was found in the PE scan. The other raw substring hits are unrelated LodePNG/zlib messages.
- Address adjacency favors FileDownloader only weakly and is outweighed by the two non-FileDownloader direct refs.
- JsonCpp involvement in two consumers does not make a product key a third-party parser-owned item.

## Final Recommendation

Exact changes applied or recommended:

- Applied: created this B001 research report only.
- Recommended by-* documentation changes: none.
- Recommended coverage-report changes: none.
- Recommended parent assignment: none. Keep `AUTOGEN_PARENT_UID:` blank for [UID:0003G1].
- Recommended score changes: none. Current `88/93` remains justified.

Exact items left unassigned and why:

- [UID:0003G1] should remain unassigned because every existing candidate parent is only one consumer family, and current binary evidence does not prove an explicit shared constants owner.

Exact future work outside this assignment:

- If a PDB, source tree, linker map, object map, or broader constants table is found, revisit whether a shared `ProductJsonKeys`/`OnlineMetadataKeys` owner exists. The evidence must show more than direct consumer pushes of one pooled string.

## Supervisor-Actionable Text

No supervisor edit is requested. Retain these rows unchanged.

Current `by-memory/-coverage-report.md` row to retain:

```text
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; C001-014 live IDA reconfirmed exactly three refs from FileDownloader item-shop version parsing, FittingRoom encoded catalog-state parsing, and StartupWindow update parsing, with separate successor URL at `0x0060d958`; parent blank because no single direct source owner covers every use.
```

Current `auto-generated/-ag-memory-coverage.md` row to retain:

```text
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | unassigned |  |  | no |  | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
```

## Follow-Up Actions

- Supervisor actions: accept this as a no-op ownership result; leave the target in its current parent-blank state unless supervisor bookkeeping needs to mark the research complete.
- A-agent actions: none required for this target.
- B001 future research actions: none for `0003G1` unless future source/debug/table evidence appears. If a later assignment covers broader update/cash-shop metadata keys, use this report's negative evidence to avoid prematurely creating a catch-all constants file.

## Confidence

- Recommendation confidence: `88/100` for parent blank/no-op as the best current ownership disposition.
- Range and xref confidence: `94/100`; the only reason this is not higher is that the page itself remains below the extreme `95+` final-audit gate by project policy.
- Score confidence: current `88/93` is defensible and should not be changed by this B001 pass.
- Remaining uncertainty: original source declaration placement. The binary proves shared storage and three consumers; it does not prove whether that storage came from an explicit shared constant, identical repeated literals folded by the toolchain, or ordinary compiler/linker string pooling.

## Validator Results

- Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0003G1-SharedVersionJsonKey-B001-0003G1-removed.md](0003G1-SharedVersionJsonKey-B001-0003G1-removed.md). The archived block is non-authoritative and must not be executed.

- Result: dry-run validation succeeded for the target page. Output included `ok: 1`, `ok 0003G1 by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md UID header exists`, and `autogen_report_noop ... auto-generated/-ag-memory-coverage.md unchanged`.
- Unresolved validator warnings/errors: none specific to [UID:0003G1]. The validator reported normal dry-run/generated no-op lines for unrelated roots.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G1-SharedVersionJsonKey-B001-0003G1.md`
- Modified: none outside the B001 research folder.
- Renamed: none.
- Moved to executed: none. Supervisor owns execution/move.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B001/0003G1-SharedVersionJsonKey-B001-0003G1.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
