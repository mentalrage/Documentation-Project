** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Fresh No-Owner Pass

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](../../../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000JE,0000O5`.
- Final disposition: reconstructable pooled/source-use ASCII JSON key literal. It is not non-emitting; the three current emitters are proven source-use routes, but no single canonical declaration/source owner is defensible.
- Required action: no metadata change, no score change, no split/merge/reclassification, no IDA-safe rename, no by-memory/-coverage-report.md row replacement, and no standalone `RECONSTRUCTION_CPP` entry in this pass.
- Confidence: high. Current IDA MCP and raw PE evidence independently confirm the exact range, three source-use xrefs, no interior/tail refs, and separate successor URL ownership.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Source queue/report row: `auto-generated/-ag-memory-coverage.md` current no-owner row.
- Current supervisor classification: Goal 2 no-owner memory pass target with existing multiple emitters.
- Prior report read as evidence only: `Agent-B002/research/executed/0003G1-SharedVersionJsonKey-current-no-owner-research.md`.
- Live IDA MCP session used: `a001_goal2_class_batch`, IDB `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, imagebase `0x00400000`, auto-analysis ready, Hex-Rays ready.

Current metadata before this pass:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Recommended metadata after this pass:

```text
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: blank
```

Score before/after:

```text
Before: COMPLETION:88, CONFIDENCE:93
After:  COMPLETION:88, CONFIDENCE:93
```

## Executive Recommendation

Leave the item no-owner with three emitters. Current evidence proves that `0x0060d94c` is the single physical ASCII `version` key pushed by three independent source-use families:

- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md): item-shop version download parsing in `sub_41AA00`.
- [UID:0000JE][FittingRoom](../../../../../by-file/FittingRoom.md): fitting-room catalog/item-state parsing through [UID:000051][FittingRoomDialogItemState](../../../../../by-class/FittingRoomDialogItemState.md) and `sub_422740`.
- [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md): startup update/minimap metadata parsing in `sub_580870`.

Do not assign a canonical owner to any one of those consumers. Each is a real use site, but none is proven to be the source declaration owner. Do not assign the literal to [UID:0000KI][JsonCpp](../../../../../by-file/JsonCpp.md), because JsonCpp supplies parse/value helpers while the `"version"` key is caller-owned product data. Do not assign it to [UID:0003AL][CashShopDownloaderLiterals](../../../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md), because that page is a non-reconstructable split-audit container, not a source owner.

The exact condition that would justify changing this decision is new direct evidence of a named shared source declaration or constant owner, or evidence that one or more of the current xrefs no longer routes to a real generated file root. Current evidence shows neither.

## Supervisor Active Recheck

The supervisor assigned exactly one target for this pass: `0003G1` / `0x0060d94c-0x0060d958.SharedVersionJsonKey`.

The assigned item did not require split repair before final reporting. It is already the exact child between [UID:0003G0][CashShopVersionDownloadWideLiterals](../../../../../by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) and [UID:0003G2][CashShopCatalogDownloadWideUrl](../../../../../by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md). The predecessor ends at `0x0060d94c`; this page covers `version\0` plus four zero alignment bytes; the successor begins at `0x0060d958` and is a UTF-16LE `itemshop.json` URL with a separate xref.

No source-bearing child was created or repaired in this pass. Every source-use route in scope was rechecked and remains either proven emitter evidence or rejected as canonical-owner evidence.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` affected the recommendation in four ways:

- The canonical owner must be a direct declaration/source owner, not merely a consumer with a real xref.
- `EMITTER_UIDS` are output routes and may be multiple when a pooled literal has no defensible single source owner.
- Address adjacency in `.rdata` is weak evidence because literal pools and adjacent strings can come from multiple source-use contexts.
- A third-party parser library does not own caller-provided product keys, even when the key is passed into parser accessor helpers.

Existing documentation and prior B-agent reports were treated as leads. The final recommendation relies on current IDA MCP facts, current generated coverage state, and a raw PE scan.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `lookup_funcs`, `entity_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `get_string`, `insn_query`, `decompile`, and `analyze_component`.
- Raw PE scan for section mapping, exact bytes, absolute VA operands, RVA operands, and target/successor byte-pattern uniqueness.
- Current project documentation for target metadata, adjacent literal children, consumer pages, emitter file roots, JsonCpp boundary, and generated coverage state.
- Negative evidence: no function object at the data addresses, no xrefs to the alignment tail, no RVA refs, no owner-only consumer, no single-source declaration proof, and no need to merge into predecessor/successor children.

The evidence is strong enough for a no-change recommendation because the same three source-use routes are confirmed by IDA xrefs, IDA decompilation, IDA instruction queries, generated emitter roots, and PE bytes.

## IDA MCP Facts

### Function / Range Facts

`server_health` for `a001_goal2_class_batch` reported module `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x00400000`, auto-analysis ready, and Hex-Rays ready.

Current `lookup_funcs` reports:

| Query | Result |
| --- | --- |
| `0x0060d94c` | not a function |
| `0x0060d950` | not a function |
| `0x0060d954` | not a function |
| `0x0060d958` | not a function |
| `0x0041aa00` | `sub_41AA00`, size `0x41c` |
| `0x00422740` | `sub_422740`, size `0x1d9` |
| `0x00580870` | `sub_580870`, size `0x88d` |
| `0x0041ae20` | `sub_41AE20`, size `0x2ec` |
| `0x004278e0` | `sub_4278E0`, JsonCpp value accessor helper |
| `0x004298f0` | `sub_4298F0`, JsonCpp document/parse support |
| `0x00581e40` | `sub_581E40`, startup substring/search helper |

`entity_query` over `0x0060d940-0x0060d970` reports:

| Address | Entity |
| --- | --- |
| `0x0060d94c` | non-function name `aVersion`; extracted string `version`, length `7`, segment `.rdata` |
| `0x0060d958` | non-function name `aHttpsSecureKru_0` |

`get_bytes 0x0060d940 size 80` confirms the local bytes:

```text
20 00 25 00 64 00 0a 00 00 00 00 00
76 65 72 73 69 6f 6e 00 00 00 00 00
68 00 74 00 74 00 70 00 73 00 3a 00 2f 00 2f 00 ...
```

This places the target exactly as:

| Range | Meaning |
| --- | --- |
| `0x0060d94c-0x0060d954` | ASCII `version` plus terminator |
| `0x0060d954-0x0060d958` | four zero alignment bytes |
| `0x0060d958` onward | UTF-16LE successor URL beginning `h\0t\0t\0p\0s\0` |

### Xref Facts

Current `xrefs_to` reports:

| Address | Xrefs |
| --- | --- |
| `0x0060d94c` | `0x0041ad2e` data ref in `sub_41AA00`; `0x004227c6` data ref in `sub_422740`; `0x00580cab` data ref in `sub_580870` |
| `0x0060d950` | no xrefs |
| `0x0060d954` | no xrefs |
| `0x0060d958` | `0x0041ae84` data ref in `sub_41AE20` |

Current `insn_query` confirms the three target uses are direct push operands:

| Address | Instruction | Function |
| --- | --- | --- |
| `0x0041ad2e` | `push offset aVersion; "version"` | `sub_41AA00` |
| `0x004227c6` | `push offset aVersion; "version"` | `sub_422740` |
| `0x00580cab` | `push offset aVersion; "version"` | `sub_580870` |
| `0x0041ae84` | `push offset aHttpsSecureKru_0; "https://secure.kru.com/itemshop/data/it"...` | `sub_41AE20` successor URL use |

Current `find_bytes` in IDA reports:

| Pattern | Matches |
| --- | --- |
| `76 65 72 73 69 6F 6E 00 00 00 00 00` | one match: `0x0060d94c` |
| `76 65 72 73 69 6F 6E 00` | three matches: `0x0060d94c`, `0x0060fcd4`, `0x00671b25` |
| `68 4C D9 60 00` | three matches: `0x0041ad2e`, `0x004227c6`, `0x00580cab` |
| absolute dword `0x0060d950` | no matches |
| absolute dword `0x0060d954` | no matches |
| absolute dword `0x0060d958` | one match: `0x0041ae85` |
| RVA forms for target/tail/successor | no matches |

The duplicate textual `version` strings are not this item. `get_string` identifies `0x0060fcd4` and `0x00671b25` as text string occurrences, but `xrefs_to` reports no xrefs to either. `entity_query` shows `0x00671b25` is inside the unrelated `.data` string `incompatible version`; `0x0060fcd4` has no xrefs and sits before the named string `invalid CRC encountered (checking CRC can be disabled)`.

### Decompilation / Component Facts

`decompile 0x0041aa00` shows `sub_41AA00` downloading `L"https://secure.kru.com/itemshop/data/itemshop.ver"`, parsing the accumulated JSON through JsonCpp helpers, then calling the value accessor as:

```text
sub_4278E0(..., "version", ...)
```

It copies the parsed field into active fitting-room state when `dword_67A73C` is present. This is a FileDownloader-dispatched item-shop version source-use context.

`decompile 0x00422740` shows `sub_422740` parsing a fitting-room item-state/catalog buffer and calling:

```text
sub_4278E0(..., "version", ...)
```

It then extracts the value into the item-state header and loads category entries. This is a FittingRoom/FittingRoomDialogItemState source-use context.

`decompile 0x00580870` shows `sub_580870` in the startup update-check flow. Its refs include the startup update URL `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`, the `version` key, the `minimap` key, and startup substring helpers `sub_581E40` / `sub_581F50`. This is a StartupWindow source-use context.

`decompile 0x0041ae20` confirms the successor at `0x0060d958` is not part of this target. It is the FileDownloader catalog URL use:

```text
InternetOpenUrlW(..., L"https://secure.kru.com/itemshop/data/itemshop.json", ...)
```

`analyze_component` over `0x0041aa00`, `0x00422740`, and `0x00580870` reports:

- `shared_globals`: `0x0060d94c` / `aVersion` accessed by `sub_41AA00`, `sub_422740`, and `sub_580870`.
- `string_usage`: `version` used by all three functions.
- No internal call-graph edges among those three functions, supporting separate source-use contexts rather than one wrapper calling another.

## Raw PE Evidence

Raw PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reports:

```text
ImageBase=0x00400000
.text  0x00401000-0x0060c600 raw=0x400
.rdata 0x0060d000-0x0066c200 raw=0x20ba00
.data  0x0066d000-0x0069ce24 raw=0x26ac00
.rsrc  0x0069d000-0x006b2e00 raw=0x278400
Target VA 0x0060d94c -> raw=0x20c34c section=.rdata
```

Target raw bytes:

```text
76 65 72 73 69 6f 6e 00 00 00 00 00
68 00 74 00 74 00 70 00 73 00 3a 00 2f 00 2f 00 ...
```

PE pattern results:

| Pattern / value | Result |
| --- | --- |
| full target bytes `version\0\0\0\0\0` | one hit, VA `0x0060d94c` |
| shorter `version\0` | three hits, VA `0x0060d94c`, `0x0060fcd4`, `0x00671b25` |
| `push 0x0060d94c` | three hits, VA `0x0041ad2e`, `0x004227c6`, `0x00580cab` |
| absolute dword `0x0060d94c` | three hits, the immediate operands at `0x0041ad2f`, `0x004227c7`, `0x00580cac` |
| absolute dword `0x0060d950` | zero hits |
| absolute dword `0x0060d954` | zero hits |
| absolute dword `0x0060d958` | one hit, VA `0x0041ae85` |
| RVA forms for `0x0060d94c`, `0x0060d950`, `0x0060d954`, `0x0060d958` | zero hits |

The raw PE evidence independently supports the exact range, the absence of alignment-tail references, the three target source-use operands, and the separate successor URL operand.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL][CashShopDownloaderLiterals](../../../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Split-audit container for mixed downloader/cash-shop/startup literal block | `FALSE` | `NONE` | `89/92` | Keep container-only |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0][CashShopVersionDownloadWideLiterals](../../../../../by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | FileDownloader item-shop version URL/progress wide literals | `TRUE` | `0000JC` | `86/91` | Keep assigned/emitting to FileDownloader |
| `0x0060d94c-0x0060d958` | [UID:0003G1][SharedVersionJsonKey](../../../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | Shared ASCII `version` key plus alignment | `TRUE` | `NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | Keep no-owner/multi-emitter |
| `0x0060d958-0x0060d9c0` | [UID:0003G2][CashShopCatalogDownloadWideUrl](../../../../../by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) | FileDownloader item-shop catalog URL wide literal | `TRUE` | `0000JC` | `86/92` | Keep assigned/emitting to FileDownloader |
| `0x0041aa00-0x0041ae1c` | [UID:0002TS][DownloadCashShopVersion](../../../../../by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) | FileDownloader item-shop version parser/use site | `TRUE` | `0000JC`; emitter `0000JC` | `80/84` | Below 85/85 as a child, but file root route is established |
| `0x00422740-0x00422919` | [UID:0002E9][FittingRoomDialogItemStateLoadEncodedStateBuffer](../../../../../by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md) | FittingRoomDialogItemState catalog-state parser/use site | `TRUE` | `000051`; emitter `000051` -> `0000JE` | `84/88` | Source-use route into FittingRoom confirmed |
| `0x005807d0-0x0058206e` | [UID:0001IO][StartupWindowUpdateCheck](../../../../../by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | StartupWindow update/minimap metadata parser/use site | `TRUE` | `0000O5`; emitter `0000O5` | `85/87` | Source-use route into StartupWindow confirmed |

Notes on scores: `0002TS` and `0002E9` are below the 85/85 child assignment threshold for their own final code readiness, but they are not the proposed canonical owner of `0003G1`. The file-root emitters `0000JC`, `0000JE`, and `0000O5` themselves clear the route threshold and have generated file roots.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e` | `push offset aVersion` in `sub_41AA00` | FileDownloader item-shop version parse uses `"version"` |
| `0x004227c6` | `push offset aVersion` in `sub_422740` | FittingRoomDialogItemState encoded/catalog-state parse uses `"version"` |
| `0x00580cab` | `push offset aVersion` in `sub_580870` | StartupWindow update/minimap metadata parse uses `"version"` |
| `0x0060d950` | no xrefs | Interior of ASCII string is not separately referenced |
| `0x0060d954` | no xrefs | Alignment tail is not separately referenced |
| `0x0041ae84` | `push offset aHttpsSecureKru_0` in `sub_41AE20` | Successor URL is separate FileDownloader catalog literal |

## Documentation Evidence And IDA Status

Current target page evidence:

- Header already records `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC,0000JE,0000O5`.
- Body identifies `0x0060d94c-0x0060d954` as ASCII `version`, `0x0060d954-0x0060d958` as zero alignment, and `0x0060d958` as the successor URL boundary.
- Body lists the same three xrefs rechecked above.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` row currently says:

```markdown
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `NONE` | `0000JC`,`0000JE`,`0000O5` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
```

- The emitter detail section resolves the emitters to [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md), [UID:0000JE][FittingRoom](../../../../../by-file/FittingRoom.md), and [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md).
- `auto-generated/-ag-file-coverage.md` currently lists all three file roots as generated roots:
  - [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) -> `auto-generated/NexusTK/network/FileDownloader.cpp`
  - [UID:0000JE][FittingRoom](../../../../../by-file/FittingRoom.md) -> `auto-generated/NexusTK/cashshop/FittingRoom.cpp`
  - [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md) -> `auto-generated/NexusTK/app/StartupWindow.cpp`
- The three generated output files currently exist but are zero bytes. That is not an emitter dead end; it only reflects that final approved reconstruction C++ has not been entered for those routes yet.

Related docs:

- [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) is `85/88`, has proposed reconstruction path `NexusTK/network/`, and explicitly records `0003G1` as a shared literal sibling not assigned to FileDownloader because FittingRoom and StartupWindow also consume it.
- [UID:0000JE][FittingRoom](../../../../../by-file/FittingRoom.md) is `85/87`, has proposed reconstruction path `NexusTK/cashshop/`, and owns the fitting-room item-state source context that consumes this key.
- [UID:000051][FittingRoomDialogItemState](../../../../../by-class/FittingRoomDialogItemState.md) is `86/88` and records that `LoadEncodedStateBuffer` uses the `version` key through JsonCpp helpers.
- [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md) is `87/85`, has proposed reconstruction path `NexusTK/app/`, and records the update/minimap metadata parsing context.
- [UID:0000KI][JsonCpp](../../../../../by-file/JsonCpp.md) is a third-party parser implementation. It owns parser/value helpers, not product-specific key literals.

Existing docs that remain uncertain but not contradicted:

- Whether the original source had three independent literal spellings or a named shared constant is not recoverable from current binary evidence. That uncertainty is exactly why `CANONICAL_OWNER:NONE` is correct while the source-use emitters remain filled.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`

Evidence for:

- IDA xrefs prove exactly three target refs from three separate source families: FileDownloader item-shop version parsing, FittingRoom catalog-state parsing, and StartupWindow update metadata parsing.
- `analyze_component` reports `aVersion` as a shared global/string used by `sub_41AA00`, `sub_422740`, and `sub_580870`, with no internal call-graph edge that would collapse these into one source-use path.
- Raw PE scan finds exactly three `push 0x0060d94c` operands and no tail/interior references.
- All three emitter roots are current generated file roots with valid proposed reconstruction paths.
- `by-structure.md` explicitly permits no canonical owner with multiple emitters for pooled string literals and shared constants when no declaration owner is proven.

Evidence against:

- The generated coverage row displays only the first generated output path in the summary column, so a superficial read can make the item look FileDownloader-primary. The emitter detail section and file-root coverage resolve all three emitters.

Decision:

- Accepted. This is the most accurate current state.

### 2. Assign canonical owner to FileDownloader (`0000JC`)

Evidence for:

- The target sits between FileDownloader-owned item-shop version/catalog wide literal children.
- `sub_41AA00` is a direct FileDownloader-dispatched consumer.
- The generated memory coverage summary column currently lists `auto-generated/NexusTK/network/FileDownloader.cpp` as the representative output path.

Evidence against:

- Two of three direct xrefs are outside FileDownloader: FittingRoom item-state parsing and StartupWindow update parsing.
- The successor and predecessor FileDownloader-only literals are already split into exact children; their ownership should not be used to overclaim this shared narrow key.
- No source declaration, local static, table, or file-private evidence proves FileDownloader owned the shared key itself.

Decision:

- Rejected as canonical owner. Keep `0000JC` as a proven emitter only.

### 3. Assign canonical owner to FittingRoom / FittingRoomDialogItemState (`0000JE` or `000051`)

Evidence for:

- `sub_422740` is a real FittingRoomDialogItemState parse method using the key.
- [UID:000051][FittingRoomDialogItemState](../../../../../by-class/FittingRoomDialogItemState.md) and [UID:0000JE][FittingRoom](../../../../../by-file/FittingRoom.md) both document this source context and clear route thresholds.

Evidence against:

- FileDownloader and StartupWindow also directly push the same physical literal.
- The literal is not proven to be a FittingRoomDialogItemState member/static declaration; it is merely one parser key consumed by that class.
- `EMITTER_UIDS` should route output to the file root `0000JE`, not replace no-owner with class ownership.

Decision:

- Rejected as canonical owner. Keep `0000JE` as a proven source-use emitter.

### 4. Assign canonical owner to StartupWindow (`0000O5`)

Evidence for:

- `sub_580870` directly pushes the target and uses it in startup update/minimap metadata parsing.
- [UID:0000O5][StartupWindow](../../../../../by-file/StartupWindow.md) is a current generated file root and clears the route threshold.

Evidence against:

- FileDownloader and FittingRoom also directly push the same physical literal.
- The startup context is a consumer of a generic key name, not a recovered source declaration.

Decision:

- Rejected as canonical owner. Keep `0000O5` as a proven source-use emitter.

### 5. Assign canonical owner to JsonCpp (`0000KI`)

Evidence for:

- Two of the three decompilations pass the key into JsonCpp value/accessor helpers such as `sub_4278E0`.
- JsonCpp owns the parser/value implementation island.

Evidence against:

- The key is a caller-provided product string. JsonCpp does not own product schema keys such as item-shop version or startup update metadata names.
- StartupWindow's use path is through startup string helpers rather than proving a JsonCpp-owned declaration.
- JsonCpp ownership would collapse product data into a third-party library incorrectly.

Decision:

- Rejected.

### 6. Create a new shared constants/global owner

Evidence for:

- Multiple independent source contexts use the same physical literal.
- A project could have used a named shared constant such as a JSON key symbol.

Evidence against:

- No xref, table, symbol, address-taken pattern, function, or neighboring source-owner cluster proves a named shared declaration.
- The compiler/linker evidence is equally consistent with ordinary literal pooling of repeated `"version"` spellings.
- Creating a new owner solely to avoid `NONE` conflicts with the current owner/emitter model.

Decision:

- Rejected. Do not create a new file/global owner for this one literal.

### 7. Assign to physical literal container (`0003AL`)

Evidence for:

- `0003AL` physically contains this child and related downloader/cash-shop literals.

Evidence against:

- `0003AL` is explicitly a non-reconstructable split-audit container over mixed literal data.
- The exact children carry the real source decisions.
- A container cannot become a source declaration owner merely because it spans adjacent addresses.

Decision:

- Rejected.

## Negative Evidence Summary

Checked and rejected:

- Single canonical source owner: rejected because direct xrefs span three independent source families.
- FileDownloader-only placement from physical adjacency: rejected because the key has FittingRoom and StartupWindow refs.
- Merge backward with `0003G0`: rejected because `0003G0` ends at `0x0060d94c` and covers FileDownloader-only wide literals.
- Merge forward with `0003G2`: rejected because `0x0060d958` is a separate UTF-16LE `itemshop.json` URL with a sole xref in `sub_41AE20`.
- Split the alignment tail: rejected because `0x0060d950` and `0x0060d954` have no xrefs, no absolute/RVA operands, and functionally serve as string terminator/alignment before the successor.
- Reclassify non-reconstructable: rejected because there are proven source-use routes and the item is a source-level string literal.
- IDA rename repair: rejected because `aVersion` and `aHttpsSecureKru_0` already describe the target and successor boundary well enough for documentation.
- JsonCpp ownership: rejected because parser helpers consume the caller key but do not own product schema literals.

## C++ Entry Eligibility

The target satisfies the active minimum gate:

```text
RECONSTRUCTABLE:TRUE
confirmed nonblank EMITTER_UIDS:0000JC,0000JE,0000O5
(COMPLETION + CONFIDENCE) / 2 = (88 + 93) / 2 = 90.5 > 85
```

However, no standalone final `RECONSTRUCTION_CPP` block is recommended for this by-memory data page in this pass. The safe source representation is for reconstructed consumers to spell `"version"` at the proven parse/use sites unless future source/debug evidence proves a named shared constant. Adding a single emitted declaration here would falsely imply a recovered canonical declaration owner.

## Final Recommendation

Exact changes applied or recommended:

- No by-memory target edit.
- No by-file, by-class, by-global, by-type, or by-item edit.
- No generated report edit.
- No `by-memory/-coverage-report.md` edit.
- No score change.
- No C++ entry.

Exact owner/emitter state to retain:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
```

Exact future work outside this assignment:

- If future decompilation/source recovery proves a named common JSON-key constant, reopen ownership and consider a real shared global/type/file owner.
- If final method C++ is later entered for the three consumers, use `"version"` directly at each proven use site unless that future evidence appears.

## Exact Required Edits

No shared coverage-report replacement row is needed. Retain the current `by-memory/-coverage-report.md` row:

```markdown
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but retain `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`); B002 reconfirmed no interior/tail refs, no split/merge/reclassification, and no IDA repair need.
```

No `auto-generated/-ag-memory-coverage.md` edit is needed. Current generated row is already correct:

```markdown
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `NONE` | `0000JC`,`0000JE`,`0000O5` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
```

Supervisor may mark the current tracker assignment as `complete-no-change` for `0003G1` with this report path. No documentation repair is pending from B001.

## Follow-Up Actions

Supervisor actions:

- Mark this fresh pass as complete-no-change for `0003G1`.
- Do not apply any shared coverage-report replacement for this target.

A-agent actions:

- None required for this target.

B001 future research actions:

- Reopen only if new evidence appears for a named shared constant, different xref set, changed emitter root, or invalid generated route.

## Confidence

- Recommendation confidence: `91/100`.
- Score confidence: keep existing `88/93`; current evidence reconfirms the documented facts but does not add new behavior or a recovered declaration owner.
- Remaining uncertainty: original source may have had three independent literal spellings or a named constant. The binary does not prove either source style, so the current owner/emitter split is the most accurate representation.

## Validator Results

- Commands run: none.
- Result: not applicable.
- Reason: no by-* documentation, generated report, or shared coverage file was changed. The only created file is this Agent-B001 research report.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G1-SharedVersionJsonKey-fresh-no-owner-pass.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none by this pass.

## Lease State

No lease was acquired. Per `goal.md`, no lease is required for Agent-B001 research files. No by-* documentation or shared report file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B001/0003G1-SharedVersionJsonKey-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
