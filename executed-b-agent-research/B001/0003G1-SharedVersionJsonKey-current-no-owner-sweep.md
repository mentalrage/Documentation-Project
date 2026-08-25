** TARGET-REPORT-UID:0003G1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003G1 **
# 0003G1 SharedVersionJsonKey Current Goal 2 Ownership / Emitter Recheck

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` unchanged.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, blank `RECONSTRUCTION_CPP`, score `88/93`.
- Required action: no target-doc edit, no split, no merge, no reclassification, no IDA-safe name repair, no emitter change, and no `by-memory/-coverage-report.md` replacement is required.
- Confidence: high (`93/100`). Current IDA MCP confirms the same physical `aVersion` literal has exactly three source-use refs and no provable single declaration owner.

## Supporting Research

## Target

- Target UID: `0003G1`
- Target path: `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
- Source queue/report row: current Goal 2 no-owner memory sweep from `auto-generated/-ag-memory-coverage.md`; tracker row in `tools/leaser/Agents/no_owner_b-agent-tracker.md` marks this target assigned to Agent-B001 on 2026-06-14.
- Prior background reviewed: `tools/leaser/Agents/Agent-B001/research/executed/0003G1-SharedVersionJsonKey-current-goal2-pass.md`
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, blank `RECONSTRUCTION_CPP`.

This report is a fresh B001 recheck from current docs and live IDA MCP evidence. The prior report and target page were treated as leads, not final authority.

## Executive Recommendation

Keep this item as a reconstructable shared source literal with no canonical owner and three proven file-root emitters:

- `0000JC` / `by-file/FileDownloader.md`: `sub_41AA00` pushes `aVersion` while parsing `itemshop.ver`.
- `0000JE` / `by-file/FittingRoom.md`: `sub_422740` pushes `aVersion` while loading FittingRoom item-state/catalog data.
- `0000O5` / `by-file/StartupWindow.md`: `sub_580870` pushes `aVersion` while parsing startup update metadata.

This is no-owner but not non-emitting. The owner/emitter split is the correct model: the binary proves three source-use contexts, but it does not prove a real shared declaration owner, shared constants file, JsonCpp-owned key table, or FileDownloader/FittingRoom/StartupWindow canonical declaration ownership.

## Supervisor Active Recheck

- Supervisor instruction: recheck UID `0003G1` from current documentation plus live IDA MCP evidence and decide whether current `CANONICAL_OWNER:NONE` with emitters remains correct.
- Split repair required: no. The exact range is correctly bounded as ASCII `version` plus zero alignment before the separate successor URL at `0x0060d958`.
- Direct edits allowed by this assignment: none outside the B001 research report unless explicitly required. No by-* documentation or shared coverage file was edited.

## Inference Research Guidance Check

- `by-structure.md` says `CANONICAL_OWNER` is the direct semantic owner, while `EMITTER_UIDS` are output routing. It explicitly permits pooled/shared literals to remain `CANONICAL_OWNER:NONE` with multiple emitters when no declaration owner is proven but multiple source-use contexts are proven.
- `inference_research.md` warns that adjacency and consumer xrefs alone are not declaration ownership proof. Here, FileDownloader adjacency and each consumer xref are treated as routing evidence, not as canonical ownership.
- Existing docs were checked against current IDA facts. No current doc contradicted the live xref/string/boundary evidence.

## Evidence Standards Used

- IDA MCP evidence: `server_health`, `lookup_funcs`, `get_string`, `get_bytes`, `entity_query`, `xrefs_to`, `find`, `find_bytes`, `find_xref_signatures`, `disasm`, and `decompile`.
- Documentation evidence: current target page, generated memory coverage rows, manual memory coverage row, no-owner tracker, related emitter by-file/by-class docs, consumer function pages, and neighboring literal/container pages.
- Negative checks: interior/tail xrefs, successor boundary refs, immediate/VA/RVA refs, duplicate raw `version` byte occurrences, JsonCpp owner hypothesis, physical container ownership, and new shared constants file hypothesis.

## IDA MCP Facts

Current IDA MCP session:

```text
database: b001_0003gy
input_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
idb_path: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
module: NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Function/range facts:

```text
0x0060d94c: not a function
0x0060d950: not a function
0x0060d954: not a function
0x0060d958: not a function
0x0041aa00 / 0x0041ad2e: sub_41AA00, size 0x41c
0x00422740 / 0x004227c6: sub_422740, size 0x1d9
0x00580870 / 0x00580cab: sub_580870, size 0x88d
0x0041ae20 / 0x0041ae84: sub_41AE20, size 0x2ec
```

String and byte facts:

```text
get_string 0x0060d94c -> "version"
get_string 0x0060d950 -> "ion" interior substring only
get_string 0x0060d954 -> no string
get_string 0x0060d958 -> "https://secure.kru.com/itemshop/data/itemshop.json"

get_bytes 0x0060d940 size 0x30:
20 00 25 00 64 00 0a 00 00 00 00 00
76 65 72 73 69 6f 6e 00 00 00 00 00
68 00 74 00 74 00 70 00 73 00 3a 00 2f 00 2f 00 73 00 65 00 63 00 75 00
```

Names/strings near the target:

```text
0x0060d94c: name aVersion, segment .rdata
0x0060d958: name aHttpsSecureKru_0, segment .rdata
extracted string in range: "version" at 0x0060d94c, length 7
```

Xref facts:

```text
xrefs_to 0x0060d94c:
  0x0041ad2e data ref in sub_41AA00
  0x004227c6 data ref in sub_422740
  0x00580cab data ref in sub_580870

xrefs_to 0x0060d950: none
xrefs_to 0x0060d954: none

xrefs_to 0x0060d958:
  0x0041ae84 data ref in sub_41AE20
```

IDA `find` confirms the same current reference set:

```text
data_ref 0x0060d94c -> 0x41ad2e, 0x4227c6, 0x580cab
data_ref 0x0060d950 -> none
data_ref 0x0060d954 -> none
data_ref 0x0060d958 -> 0x41ae84
code_ref 0x0060d94c/0x0060d950/0x0060d954/0x0060d958 -> none
immediate 0x0060d94c -> 0x41ad2e, 0x4227c6, 0x580cab
immediate 0x0060d950 -> none
immediate 0x0060d954 -> none
immediate 0x0060d958 -> 0x41ae84
RVA immediates 0x0020d94c/0x0020d950/0x0020d954/0x0020d958 -> none
```

Signature/xref-signature facts:

```text
find_xref_signatures 0x0060d94c -> total_xrefs 3
  0x580cab: 68 4C D9 60 00 8D 4D
  0x41ad2e: starts 68 4C D9 60 00 ...
  0x4227c6: starts 68 4C D9 60 00 ...

find_xref_signatures 0x0060d950 -> total_xrefs 0
find_xref_signatures 0x0060d954 -> total_xrefs 0

find_xref_signatures 0x0060d958 -> total_xrefs 1
  0x41ae84: 68 58 D9 60 00
```

Raw byte-pattern checks inside IDA:

```text
find_bytes "76 65 72 73 69 6F 6E 00" -> 0x0060d94c, 0x0060fcd4, 0x00671b25
xrefs_to/data_ref 0x0060fcd4 -> none
xrefs_to/data_ref 0x00671b25 -> none

find_bytes "4C D9 60 00" -> 0x41ad2f, 0x4227c7, 0x580cac
find_bytes "50 D9 60 00" -> none
find_bytes "54 D9 60 00" -> none
find_bytes "58 D9 60 00" -> 0x41ae85
find_bytes RVA patterns "4C/50/54/58 D9 20 00" -> none
```

Instruction-level source-use refs:

```text
0x0041ad2e: push offset aVersion; "version" in sub_41AA00
0x004227c6: push offset aVersion; "version" in sub_422740
0x00580cab: push offset aVersion; "version" in sub_580870
0x0041ae84: push offset aHttpsSecureKru_0; successor itemshop.json URL in sub_41AE20
```

Decompiler observations:

- `sub_41AA00` opens `https://secure.kru.com/itemshop/data/itemshop.ver`, accumulates the response, parses it through local JsonCpp helpers, and calls `sub_4278E0(..., "version", ...)` before updating fitting-room version state.
- `sub_422740` parses an encoded/cached FittingRoom item-state/catalog buffer, calls `sub_4278E0(..., "version", ...)`, stores the parsed header/version value, then iterates the category loaders.
- `sub_580870` fetches `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`, searches `"version"` with `sub_581E40("version", 0)`, parses the numeric version, then separately searches `"minimap"` for minimap update metadata.
- `sub_41AE20` uses `0x0060d958` for the separate `itemshop.json` URL and does not reference `0x0060d94c`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0] `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md` | FileDownloader item-shop version URL/progress wide literals | Yes | `0000JC` | `86/91` | Separate predecessor, not part of `0003G1` |
| `0x0060d94c-0x0060d958` | [UID:0003G1] `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | Shared narrow `version` key plus zero alignment | Yes | `NONE`; emitters `0000JC,0000JE,0000O5` | `88/93` | Current target, keep unchanged |
| `0x0060d958-0x0060d9c0` | [UID:0003G2] `by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md` | FileDownloader item-shop catalog URL | Yes | `0000JC` | `86/92` | Separate successor, not part of `0003G1` |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL] `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` | Mixed literal audit/container | No | `NONE` | `89/92` | Context only; not a canonical owner |

No child creation is needed. Splitting the interior substring `ion` or alignment tail would create false children because both have zero refs.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041ad2e -> 0x0060d94c` | `sub_41AA00` / [UID:0002TS] `DownloadCashShopVersion` | FileDownloader source-use route; item-shop version payload key |
| `0x004227c6 -> 0x0060d94c` | `sub_422740` / [UID:0002E9] `FittingRoomDialogItemStateLoadEncodedStateBuffer` | FittingRoom source-use route; cached/decoded item-state catalog version key |
| `0x00580cab -> 0x0060d94c` | `sub_580870` / [UID:0001IO] `StartupWindowUpdateCheck` | StartupWindow source-use route; update metadata version search |
| `0x0041ae84 -> 0x0060d958` | `sub_41AE20` / [UID:0002TT] `DownloadCashShopCatalog` | Successor URL, separate child after `0003G1` |
| `0x0060d950` | no refs | Interior substring only |
| `0x0060d954` | no refs | Zero alignment tail only |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- The target page already records `CANONICAL_OWNER:NONE`, `EMITTER_UIDS:0000JC,0000JE,0000O5`, exact source-use contexts, no interior/tail refs, and the successor URL boundary.
- `by-file/FileDownloader.md` is `85/88`, projected to `NexusTK/network/`, and documents the item-shop download helpers and literal children. It also notes the neighboring shared `version` key is not FileDownloader-only.
- `by-file/FittingRoom.md` is `85/87`, projected to `NexusTK/cashshop/`, and `by-class/FittingRoomDialogItemState.md` is `86/88`; together they support the FittingRoom item-state/catalog source-use route.
- `by-file/StartupWindow.md` is `87/85`, projected to `NexusTK/app/`, and documents `StartupWindowUpdateCheck` parsing update/minimap metadata.
- `by-file/JsonCpp.md` is `92/88`, projected to `NexusTK/third_party/jsoncpp/`, and supports rejecting JsonCpp ownership of product-specific keys.
- `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` is a reviewed non-emitting split-audit container that lists this exact child as shared across FileDownloader, FittingRoom, and StartupWindow.
- The generated coverage rows currently list the target as `no-owner` with emitters `0000JC,0000JE,0000O5`.

Existing docs that are stale, incomplete, or contradicted:

- Older parent-blank wording from pre-owner/emitter terminology should be interpreted through the current `CANONICAL_OWNER:NONE` plus `EMITTER_UIDS` model.
- No current by-* page checked in this pass contradicts live IDA evidence for this target.

## Ranked Ownership Analysis

### 1. Keep `CANONICAL_OWNER:NONE` with emitters `0000JC,0000JE,0000O5`

- Evidence for: current IDA shows exactly three refs to the physical `aVersion` head from three independent source families. The item is a small string literal, not a constructed object, vtable, table, writable global, or class field. Current by-structure rules explicitly allow this no-owner/multi-emitter state for pooled or shared literals.
- Evidence against: physical adjacency to FileDownloader item-shop URL/progress strings could tempt a FileDownloader owner, and two other raw `version` strings exist elsewhere in the binary.
- Decision: accepted. Adjacency and duplicate raw strings do not overcome the three live source-use refs to this exact address.

### 2. FileDownloader / `0000JC` as canonical owner

- Evidence for: the target sits between FileDownloader-owned item-shop literal children, and `sub_41AA00` uses it while parsing `itemshop.ver`.
- Evidence against: `sub_422740` and `sub_580870` also use the same physical literal. FileDownloader does not write, construct, table-own, or uniquely reference it. Assigning FileDownloader as canonical owner would hide FittingRoom and StartupWindow source-use routes.
- Decision: reject as canonical owner; retain `0000JC` as an emitter.

### 3. FittingRoomDialogItemState / FittingRoom / `000051` and `0000JE`

- Evidence for: `sub_422740` is an item-state/catalog parser and uses the `version` key directly. The class and file parent clear the route threshold.
- Evidence against: the literal is not class storage and is not FittingRoom-only. It is also referenced by FileDownloader and StartupWindow.
- Decision: reject as canonical owner; retain file-root `0000JE` as an emitter.

### 4. StartupWindow / `0000O5`

- Evidence for: `sub_580870` uses the same `version` key while parsing startup update metadata.
- Evidence against: the same physical literal is also used by FileDownloader and FittingRoom. No startup-only declaration/table owns it.
- Decision: reject as canonical owner; retain `0000O5` as an emitter.

### 5. JsonCpp / `0000KI`

- Evidence for: FileDownloader and FittingRoom consumers pass `"version"` into JsonCpp value/document helpers.
- Evidence against: JsonCpp is parser infrastructure. The literal is product-specific key data supplied by product modules. StartupWindow's route uses string-search parsing rather than proving a JsonCpp key-table owner.
- Decision: reject.

### 6. Physical literal container `0003AL`

- Evidence for: `0003G1` is inside the broader `CashShopDownloaderLiterals` physical block.
- Evidence against: `0003AL` is documented as a mixed non-emitting split-audit container. Its child table includes different owner/emitter routes across FileDownloader, MiniMap, FittingRoom, and StartupWindow contexts.
- Decision: reject as canonical owner.

### 7. New shared constants file/grouping

- Evidence for: a shared key literal could have come from a header macro, named constant, or compiler/linker-pooled literal.
- Evidence against: there is no debug/source/linker-map evidence, no named constants table, no xref table, no write/initialization path, and no cluster of related shared keys with the same emitter set that would define a plausible file scope.
- Decision: reject. Do not invent a constants owner solely to remove `NONE`.

## Split / Merge / Reclassification Analysis

- Split: not recommended. `0x0060d94c-0x0060d954` is the string head plus terminator, and `0x0060d954-0x0060d958` is unreferenced zero alignment. The interior substring at `0x0060d950` has no refs. Splitting would create false child pages.
- Merge with predecessor: not recommended. `0003G0` contains FileDownloader-only wide literals ending at the target head; `0003G1` has broader emitter routing.
- Merge with successor: not recommended. `0x0060d958` is a separate wide `itemshop.json` URL with a sole FileDownloader catalog ref.
- Reclassification: not recommended. This is source-authored/reconstructable literal data that must appear at source-use sites, not compiler/runtime metadata, padding-only data, or a non-reconstructable container.

## Negative Evidence Summary

- No refs to `0x0060d950` or `0x0060d954`, so there is no interior/tail child.
- No code refs to the target/head/tail/successor data addresses.
- No RVA immediate refs for target head, interior, tail, or successor.
- Other raw `version\0` byte occurrences at `0x0060fcd4` and `0x00671b25` have no xrefs and do not add emitters for this UID.
- The successor URL at `0x0060d958` has a separate sole xref from `DownloadCashShopCatalog`; it must not be merged into `0003G1`.
- Consumer xrefs prove source-use routing but do not prove declaration ownership by any one consumer.
- JsonCpp parser calls prove parser dependency only, not product-key ownership.

## Final Recommendation

Preserve the target metadata exactly:

```text
UID:0003G1
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000JC,0000JE,0000O5
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP:
```

No C++ should be entered. The item is below the active `90/90+` code-entry gate and source declaration ownership remains intentionally unresolved.

## Required Edits / Supervisor Text

Required by-memory target edits: none.

Required by-structure/by-file/by-class edits: none.

Required `by-memory/-coverage-report.md` edits: none. The current row is semantically correct and should remain:

```md
            - [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) 0x0060d94c-0x0060d958 | string-data | SharedVersionJsonKey : reconstructable : 88% : very-strong : Narrow ASCII `version` JSON key; B001 post-migration and B002 second-pass reviews keep `CANONICAL_OWNER:NONE` because FileDownloader, FittingRoom, StartupWindow, JsonCpp, and the physical mixed literal container each overclaim declaration ownership, but retain `EMITTER_UIDS:0000JC,0000JE,0000O5` because live IDA/PE evidence proves source-use contexts in FileDownloader item-shop version parsing (`sub_41AA00` / `0x0041ad2e`), FittingRoomDialogItemState catalog-state parsing (`sub_422740` / `0x004227c6`), and StartupWindow update metadata parsing (`sub_580870` / `0x00580cab`); B002 reconfirmed no interior/tail refs, no split/merge/reclassification, and no IDA repair need.
```

Generated rows are read-only and should continue to be generated in their current form:

```md
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `NONE` | `0000JC`,`0000JE`,`0000O5` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` |  |
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000O5][StartupWindow](by-file/StartupWindow.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
| [UID:0003G1][0x0060d94c-0x0060d958.SharedVersionJsonKey](by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | no-owner | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | `0000JC`,`0000JE`,`0000O5` | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

Optional supervisor-owned tracker closeout row:

```md
| `0003G1` | 0x0060d94c-0x0060d958.SharedVersionJsonKey | `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md` | Agent-B001 | 2026-06-14 | complete-no-change | Keep `CANONICAL_OWNER:NONE` with `EMITTER_UIDS:0000JC,0000JE,0000O5`; current B001 IDA MCP recheck reconfirmed exactly three source-use refs at `0x0041ad2e`, `0x004227c6`, and `0x00580cab`, no interior/tail refs, and separate successor URL ref at `0x0041ae84`. | `Agent-B001/research/0003G1-SharedVersionJsonKey-current-goal2-pass.md` |
```

## Follow-Up Actions

- Supervisor actions: none required for by-memory or coverage state. Move this report to `executed` after acceptance if that is the normal workflow.
- A-agent actions: none required.
- B001 future research actions: none for this target unless future source/debug/linker-map evidence appears for a real shared constant declaration.

## Confidence

- Recommendation confidence: `93/100`.
- Score confidence: keep `88/93`. The range, bytes, xrefs, source-use routes, and rejected alternatives are strongly evidenced. Confidence does not rise higher because original source declaration placement and literal-pooling behavior remain unrecovered.
- Remaining uncertainty: whether original source had a header/static named constant before compiler/linker string pooling. The current binary does not prove one.

## Validator Results

- Commands run: none.
- Results: not applicable. No by-memory, by-file, by-class, generated, or shared coverage documentation was edited, so normal validator `--apply` was not required.
- Dry runs: none used.
- Unresolved validator warnings/errors: none from this pass.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003G1-SharedVersionJsonKey-current-goal2-pass.md`
- Modified: none outside the B001 research report.
- Renamed: none.
- Moved to executed: none.

## Lease State

```text
B001 lease acquired for this report before writing.
B001 lease released after final report verification.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003G1","source_path":"executed-b-agent-research/B001/0003G1-SharedVersionJsonKey-current-no-owner-sweep.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
