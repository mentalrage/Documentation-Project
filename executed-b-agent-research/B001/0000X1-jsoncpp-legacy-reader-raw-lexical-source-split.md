** TARGET-REPORT-UID:0000X1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000X1 JsonCpp Legacy Reader Raw Lexical Helpers Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:0000X1] into a non-emitting JsonCpp split/index parent plus four exact source-bearing `Json::Reader` helper children and five exact ignored padding rows.
- Final disposition: [UID:0000X1] should remain a reviewed aggregate page, but its `CANONICAL_OWNER` should become [UID:0000KI] and the exact child helpers should carry `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KI`, and `EMITTER_UIDS:0000KI`.
- Required action: supervisor should create child pages for `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, and `0x0042adb0`; replace the broad coverage row with the nested block below; add exact padding rows to `by-memory/-ignored.md`; update JsonCpp support docs; then run scoped validation and memory-range refresh.
- Confidence: high for JsonCpp/source ownership, exact boundaries, padding, and no-direct-xref status; medium-high for final generated-output policy because the broader JsonCpp static-embed route currently creates an empty generated `JsonCpp.cpp` placeholder.

## Supporting Research

## Target

- Target UID: `0000X1`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md`
- Source queue/report row: supervisor assignment `B001-goal2-jsoncpp-legacy-reader-raw-lexical-source-split-0000X1-20260616`; `project-level/-auto-completion-stats.md` currently lists `0000X1` as a top `Low_Completion` / `Low_Both` row at `82/88`, average `85.0`.
- Current supervisor classification: report-only B-agent source-split/source-quality audit. Do not edit by-* docs, generated reports, `by-memory/-coverage-report.md`, or IDA DB.
- Current scores and parent state: target page is `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`. Existing narrative says likely owner [UID:0000KI] JsonCpp and lists four raw helper starts, but it keeps the whole span non-emitting.

## Executive Recommendation

The best direct source owner is [UID:0000KI] `JsonCpp`, specifically vendored `src/lib_json/json_reader.cpp` from the staged official commit `b299d3581f4dc670734f1fe1a34fce1282337802`.

Do not leave the range as one no-owner/non-emitting raw page. The range contains four source-authored third-party helper bodies with exact function starts and exact source matches, separated by compiler/linker alignment padding. Treat [UID:0000X1] as a non-emitting split/index parent and create source-bearing children:

| Proposed child | Exact range | Best source name | Metadata recommendation |
| --- | --- | --- | --- |
| `JsonCppLegacyReaderReadCStyleComment` | `0x0042ace0-0x0042ad27` | `Json::Reader::readCStyleComment()` | `86/91`, owner/emitter [UID:0000KI], reconstructable through static embed |
| `JsonCppLegacyReaderReadCppStyleComment` | `0x0042ad30-0x0042ad66` | `Json::Reader::readCppStyleComment()` | `86/91`, owner/emitter [UID:0000KI], reconstructable through static embed |
| `JsonCppLegacyReaderReadString` | `0x0042ad70-0x0042ada3` | `Json::Reader::readString()` | `86/91`, owner/emitter [UID:0000KI], reconstructable through static embed |
| `JsonCppLegacyReaderReadNumber` | `0x0042adb0-0x0042ae88` | `Json::Reader::readNumber()` | `87/91`, owner/emitter [UID:0000KI], reconstructable through static embed |

Padding spans should be ignored as compiler/linker alignment:

- `0x0042acdf-0x0042ace0`
- `0x0042ad27-0x0042ad30`
- `0x0042ad66-0x0042ad70`
- `0x0042ada3-0x0042adb0`
- `0x0042ae88-0x0042ae90`

The exact condition before any final generated C++ body is allowed: the child page must exist, validate, route to [UID:0000KI], and use the staged vendored `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` source route. Do not paste hand-written helper implementations into generated `JsonCpp.cpp`.

## Supervisor Active Recheck

- The assignment explicitly targets [UID:0000X1] and asks for raw/unmodeled starts, JsonCpp source matching, split/no-split, padding, generated-output/source-route cleanup, IDA recommendations, and final-C++ eligibility.
- This item requires split repair, but the assignment is report-only. No by-* docs, generated reports, coverage reports, or IDA state were edited by B001.
- Every source-bearing child in scope has a defensible exact range and source role. No remaining child is unresolved enough to block split recommendation.

## Inference Research Guidance Check

- `by-structure.md` says IDA/MCP is ground truth for boundaries/xrefs when available, and static embedded third-party code can be reconstructable through vendored source rather than NexusTK product C++.
- `inference_research.md` requires distinguishing direct facts from source-layout inference, checking disconfirming evidence, and not using address adjacency alone as ownership proof.
- Existing docs were treated as leads. The target page's JsonCpp match was validated, but its `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE` conclusion is not the best current state after live IDA/raw PE/source recheck.

## Heuristic / Inference Reanalysis And Validation

### Raw Helper Roles And Best Names

- `0x0042ace0-0x0042ad27`: best name `JsonCppLegacyReaderReadCStyleComment`, source name `Json::Reader::readCStyleComment()`. Evidence: reads `this+0x48` current cursor and `this+0x44` end cursor, loops until `'*'` followed by `'/'`, consumes the slash when present, and returns `setz al` success. This matches staged `json_reader.cpp` lines 403-410.
- `0x0042ad30-0x0042ad66`: best name `JsonCppLegacyReaderReadCppStyleComment`, source name `Json::Reader::readCppStyleComment()`. Evidence: same cursor/end fields, scans until LF or CR, consumes optional CRLF, and returns `true`. This matches staged `json_reader.cpp` lines 412-426.
- `0x0042ad70-0x0042ada3`: best name `JsonCppLegacyReaderReadString`, source name `Json::Reader::readString()`. Evidence: scans current/end fields, skips the next character after backslash, stops on double quote, and returns whether the terminator is `'"'`. This matches staged `json_reader.cpp` lines 450-460.
- `0x0042adb0-0x0042ae88`: best name `JsonCppLegacyReaderReadNumber`, source name `Json::Reader::readNumber()`. Evidence: initializes `dl` to `'0'`, walks integral digits, optional fractional digits after `'.'`, optional exponent after `'e'`/`'E'`, optional sign, and returns void. This matches staged `json_reader.cpp` lines 428-448.

### Legacy `Reader` Versus `OurReader`

- Accepted interpretation: these are legacy `Json::Reader` helpers.
- Rejected alternative: `Json::OurReader` helpers. The staged `OurReader::readNumber(bool checkInf)` has a `checkInf` parameter, an early `'I'` check, and returns `bool`; the raw body at `0x0042adb0` has no parameter/`I` branch and ends with a plain `ret`, matching `void Reader::readNumber()`. `Reader::readString()` and `OurReader::readString()` are nearly identical, but the number helper disambiguates the group.

### Split / No-Split Decision

- Accepted: split into four source-bearing children plus padding. The range is not one semantic function, and current [UID:0000X1] conflates source-authored JsonCpp methods with alignment bytes.
- Rejected: keep one non-emitting raw page. That preserves the old low-completion row and blocks exact source ownership/source-route decisions for four well-understood helpers.
- Rejected: merge into [UID:0000X0] or [UID:0000X2]. Live IDA function inventory shows `sub_42AB40` ends at `0x0042acdf` and `sub_42AE90` starts at `0x0042ae90`; the raw helpers form a clean intervening range with separate 16-byte alignment boundaries.

### Padding Treatment

- Exact ignored padding rows recommended:
  - `0x0042acdf-0x0042ace0`: one `0xcc` byte after `sub_42AB40`.
  - `0x0042ad27-0x0042ad30`: nine `0xcc` bytes after `readCStyleComment`.
  - `0x0042ad66-0x0042ad70`: ten `0xcc` bytes after `readCppStyleComment`.
  - `0x0042ada3-0x0042adb0`: thirteen `0xcc` bytes after `readString`.
  - `0x0042ae88-0x0042ae90`: eight `0xcc` bytes before `sub_42AE90`.
- Rejected: include padding inside child ranges. The `ret` endpoints are exact and IDA renders each following span as `align 10h`.

### Source-Bearing Children, JsonCpp Route, And Vendored Source

- Accepted: exact children should route to [UID:0000KI] `JsonCpp` and be reconstructable via vendored source. The source file is `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`, mirrored in `simroot_v2/third_party/jsoncpp/src/lib_json/json_reader.cpp`.
- The source-bearing child pages should use `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KI`, and `EMITTER_UIDS:0000KI`. The coverage-report section may still classify them as `ignored` in the current third-party/procurement convention, as neighboring JsonCpp rows already do.
- Final source should come from the vendored JsonCpp file, not hand-written local reconstructions.

### Caller / Reachability And No-Xref Evidence

- Live IDA `lookup_funcs` on 2026-06-16 reports modeled functions at `0x0042a770`, `0x0042aaf0`, `0x0042ab40`, and `0x0042ae90`; it reports `0x0042acdf`, `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, `0x0042adb0`, and `0x0042ae88` as "Not a function."
- Live IDA `xrefs_to` reports no cross-references to `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, or `0x0042adb0`. It reports three code xrefs to `0x0042ae90` from `0x00429cf2`, `0x0042b524`, and `0x0042b910`, proving the xref system is working for the adjacent modeled function.
- Live IDA `callees` reports `sub_42A770` calls only `sub_42AB40` and `sub_42AAF0`; `sub_42AB40` calls runtime/string/comment helpers and does not call the raw starts.
- Live decompilation shows `sub_42A770` already inlines string and number scanning logic, and `sub_42AB40` already inlines C-style/C++-style comment scanning before adding comments. Therefore no-xrefs to the raw helper starts are best interpreted as true direct-reference absence in this binary, not merely IDA failing to promote function starts.
- Raw PE scan found no little-endian VA or RVA pointer hits for `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, `0x0042adb0`, or `0x0042ae90`. One-pass `.text` rel32 scan found no `call`/`jmp` hits to the four raw starts; it found the expected `call` hits to `0x0042ae90` at `0x00429cf2`, `0x0042b524`, and `0x0042b910`.
- Best reachability interpretation: the raw helpers are retained out-of-line JsonCpp `Reader` member methods with no direct call route in the current IDB/PE. They are likely present because the JsonCpp object/source unit was retained while callers use inlined scanner logic. This is "dead in the current direct call graph," not "not source."

### Generated-Output Pollution And Final-C++ Impact

- Current generated state is inconsistent: neighboring JsonCpp memory pages route to [UID:0000KI] and show output path `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp`, but that generated file is currently zero bytes; [UID:0000X1] is listed as `not_reconstructable` with owner `NONE`.
- Splitting [UID:0000X1] and routing the children to [UID:0000KI] fixes source-route accounting, but adding hand-written helper bodies to `JsonCpp.cpp` would pollute final output by fragmenting a third-party source file that should come from `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`.
- Final C++ eligibility: after split, each child can clear the combined-score/emitter gate for a static-embed source reference, not for hand-reconstructed local code. If a nonblank code marker is required, use only a static-embed comment such as:

```cpp
// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp
```

- Recommended source-route cleanup beyond this target: [UID:0000KI] should state clearly that `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` is not the final source body; the rebuild source is the multi-file static embed under `third_party_embeds/jsoncpp/`.

### IDA Start / Comment Recommendations

- Optional IDA DB cleanup, not performed by B001: define four functions at `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, and `0x0042adb0`.
- Suggested IDA names:
  - `Json_Reader_readCStyleComment_42ACE0`
  - `Json_Reader_readCppStyleComment_42AD30`
  - `Json_Reader_readString_42AD70`
  - `Json_Reader_readNumber_42ADB0`
- Suggested IDA comments should state: "Retained no-direct-xref out-of-line JsonCpp legacy Reader helper; active modeled reader token/comment paths inline equivalent logic in `sub_42A770` / `sub_42AB40`; source route is vendored `json_reader.cpp`."
- Do not synthesize callers or rename product code based on these raw starts.

### Rejected Alternatives

- Product ownership by CashShop/FittingRoom/FileDownloader: rejected. Product code consumes JsonCpp parse APIs; it does not own generic scanner helpers.
- Compiler padding-only treatment: rejected. Four executable helper bodies with `ret` endpoints and source-matched scanner logic are present.
- `OurReader` child names: rejected by `readNumber(bool checkInf)` mismatch.
- No-owner/non-emitting final state: rejected for the exact children because source owner and static embed are known. Acceptable only for the parent split/index if the supervisor keeps parent `RECONSTRUCTABLE:FALSE`, but parent `CANONICAL_OWNER` should still point to [UID:0000KI].
- Hand-written final helper C++: rejected. Use the upstream JsonCpp source file instead.

## Evidence Standards Used

- IDA MCP live facts: `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `callees`, `analyze_function`, `insn_query`, `get_bytes`, and `make_signature_for_range`.
- Raw PE facts: local read-only scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for section layout, little-endian VA/RVA pointers, and `.text` rel32 call/jmp targets.
- Source facts: staged `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`, staged headers, and matching `simroot_v2/third_party/jsoncpp` files.
- Documentation evidence: [UID:0000KI], [UID:0000X0], [UID:0000X2], `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `by-project-structure/proposed-source-tree.md`, `by-meta/client_libraries.md`, `auto-generated/-ag-memory-coverage.md`, and `project-level/-auto-completion-stats.md`.
- Strength: high for function boundaries and source ownership because machine-code behavior, source lines, and neighboring JsonCpp docs agree. Remaining uncertainty is limited to broader JsonCpp generator/static-embed output policy and exact original linker settings that retained no-xref methods.

## IDA MCP Facts

- Function/range facts:
  - `sub_42AB40` at `0x0042ab40`, size `0x19f`, ends at `0x0042acdf`.
  - No function at `0x0042acdf`, `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, `0x0042adb0`, or `0x0042ae88`.
  - `sub_42AE90` at `0x0042ae90`, size `0x25f`.
  - Neighborhood function query over `0x0042a700-0x0042af00` returns only `0x0042a760`, `0x0042a770`, `0x0042aaf0`, `0x0042ab40`, and `0x0042ae90`.
- Data/table/padding facts:
  - `make_signature_for_range 0x0042acdf-0x0042ae90` returned a unique byte signature.
  - `insn_query` renders `0x0042acdf`, `0x0042ad27`, `0x0042ad66`, `0x0042ada3`, and `0x0042ae88` as `align 10h` boundaries.
- Xref facts:
  - No xrefs to raw starts `0x0042ace0`, `0x0042ad30`, `0x0042ad70`, or `0x0042adb0`.
  - `0x0042ae90` has code xrefs from `0x00429cf2`, `0x0042b524`, and `0x0042b910`.
  - Raw PE rel32 scan agrees: no `call`/`jmp` targets to the four raw starts; expected rel32 calls to `0x0042ae90` exist.
- Vtable/global/type facts:
  - No vtable or pointer-table evidence points to the raw starts.
  - Cursor/end fields at `this+0x48` and `this+0x44` match the surrounding legacy `Reader` implementation already documented in [UID:0000X0]/[UID:0000X2].
- Negative IDA facts:
  - No modeled callers, no function objects, no data xrefs, no raw VA/RVA pointer hits, and no rel32 call/jmp hits to the four raw starts.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0042acdf-0x0042ae90` | [UID:0000X1] current page | Split/index for retained raw helper bodies plus padding | `FALSE` after split | [UID:0000KI] | `88/91` recommended | Keep as parent index |
| `0x0042acdf-0x0042ace0` | `by-memory/-ignored.md` | `0xcc` alignment | `FALSE` | none | `100/strong` | Add ignored row |
| `0x0042ace0-0x0042ad27` | `0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md` | `Reader::readCStyleComment` | `TRUE` | [UID:0000KI] | `86/91` | Create child |
| `0x0042ad27-0x0042ad30` | `by-memory/-ignored.md` | `0xcc` alignment | `FALSE` | none | `100/strong` | Add ignored row |
| `0x0042ad30-0x0042ad66` | `0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md` | `Reader::readCppStyleComment` | `TRUE` | [UID:0000KI] | `86/91` | Create child |
| `0x0042ad66-0x0042ad70` | `by-memory/-ignored.md` | `0xcc` alignment | `FALSE` | none | `100/strong` | Add ignored row |
| `0x0042ad70-0x0042ada3` | `0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md` | `Reader::readString` | `TRUE` | [UID:0000KI] | `86/91` | Create child |
| `0x0042ada3-0x0042adb0` | `by-memory/-ignored.md` | `0xcc` alignment | `FALSE` | none | `100/strong` | Add ignored row |
| `0x0042adb0-0x0042ae88` | `0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md` | `Reader::readNumber` | `TRUE` | [UID:0000KI] | `87/91` | Create child |
| `0x0042ae88-0x0042ae90` | `by-memory/-ignored.md` | `0xcc` alignment | `FALSE` | none | `100/strong` | Add ignored row |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0042a770` | Calls `sub_42AB40` and `sub_42AAF0`; callers include `sub_42B120`, `sub_42B730`, `sub_42CB50`, `sub_42CF30` | Live legacy token reader path; scanner logic for string/number is inlined here |
| `0x0042ab40` | Callers `sub_42A770`, `sub_42CF30` | Live legacy comment reader/add-comment path; C/C++ comment scanners are inlined here |
| `0x0042ace0` | No xrefs and no raw rel32/VA/RVA hits | Retained out-of-line `Reader::readCStyleComment`, no direct call route |
| `0x0042ad30` | No xrefs and no raw rel32/VA/RVA hits | Retained out-of-line `Reader::readCppStyleComment`, no direct call route |
| `0x0042ad70` | No xrefs and no raw rel32/VA/RVA hits | Retained out-of-line `Reader::readString`, no direct call route |
| `0x0042adb0` | No xrefs and no raw rel32/VA/RVA hits | Retained out-of-line `Reader::readNumber`, no direct call route |
| `0x0042ae90` | Code xrefs from `0x00429cf2`, `0x0042b524`, `0x0042b910` | Adjacent modeled reader value parser is live/referenced |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000KI] already identifies JsonCpp as staged third-party source under `third_party/jsoncpp/` and names `b299d3581f4dc670734f1fe1a34fce1282337802` as the best source snapshot.
  - [UID:0000X0] identifies the preceding legacy reader/document parse front-end range and says the raw gap maps to JsonCpp comment/string/number scanners.
  - [UID:0000X2] identifies the following reader/builder island and confirms `sub_42AE90` as the next modeled start.
  - `by-project-structure/proposed-source-tree.md` already places JsonCpp under `third_party/jsoncpp/` and lists [UID:0000X1] among JsonCpp-owned docs.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:0000X1] currently has `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`; that is too weak for the source-bearing child functions now that live IDA/source/raw PE evidence is checked.
  - `by-memory/-ignored.md` has broad duplicate entries for `0x0042acdf-0x0042ae90` but does not separate true alignment padding from source-bearing JsonCpp helpers.
  - `auto-generated/-ag-memory-coverage.md` lists [UID:0000X1] as `not_reconstructable`, while neighboring JsonCpp source-bearing pages emit through [UID:0000KI].
- Generated/coverage report state:
  - `by-memory/-coverage-report.md` current row is a single broad `ignored : 82% : strong` row.
  - `project-level/-auto-completion-stats.md` lists `0000X1` in `Low_Completion` and `Low_Both`.
  - `project-documentation/auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` currently exists but is zero bytes, confirming the broader JsonCpp static-embed/generator route is not yet represented as actual multi-file generated source in that folder.

## Ranked Ownership Analysis

### 1. [UID:0000KI] JsonCpp

- Evidence for: staged source contains exact legacy `Reader` helper implementations; surrounding range is JsonCpp; field offsets match reader cursor/end fields; no product-specific strings, globals, packets, UI objects, or resources appear; proposed source tree and client_libraries already route JsonCpp to `third_party/jsoncpp/`.
- Evidence against: no xrefs to the raw helper starts. This weakens live-call evidence but does not weaken source ownership because source-matched out-of-line helper bodies are present.
- Decision: accepted. Parent index and exact children should use [UID:0000KI] as direct source owner/route.

### 2. [UID:0000X0] JsonCppDocumentParseFrontEnds as parent/container

- Evidence for: immediate predecessor and live callers eventually lead into reader token/comment parsing; `sub_42A770` and `sub_42AB40` contain inlined scanner logic.
- Evidence against: [UID:0000X0] ends exactly at `0x0042acdf`; using it as direct parent would hide four exact separate out-of-line helpers and padding.
- Decision: rejected as direct owner. It remains a sibling/caller-context page.

### 3. [UID:0000X2] JsonCppReaderAndBuilderPreludeIsland as parent/container

- Evidence for: adjacent following JsonCpp reader/parser island begins at `0x0042ae90`.
- Evidence against: `sub_42AE90` is an exact modeled start after `0x0042ae88-0x0042ae90` padding. Merging backward would create a range that crosses exact retained helper/padding boundaries.
- Decision: rejected as direct parent. It remains the following sibling.

### 4. Product JSON consumers

- Evidence for: product cash-shop/fitting-room code calls JsonCpp parse front ends elsewhere.
- Evidence against: no product code points to the raw helper starts; behavior is generic JSON lexical scanning; source is vendored JsonCpp.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new source file. Use existing [UID:0000KI] `JsonCpp`, proposed path `NexusTK/third_party/jsoncpp/`, source file `src/lib_json/json_reader.cpp`.
- Likely full contents: the full staged JsonCpp source tree already listed in [UID:0000KI], especially `include/json/*.h`, `src/lib_json/json_reader.cpp`, `json_value.cpp`, `json_valueiterator.inl`, `json_writer.cpp`, and `json_tool.h`.
- Candidate related items that belong: [UID:0000X0], [UID:0000X2], [UID:0000X7], [UID:0001ZR], [UID:0000X8], [UID:0000X9], [UID:0001ZS], [UID:0000X3], [UID:0000X4], [UID:0000X5], [UID:0000X6], [UID:0000XC], [UID:0000XD], and JsonCpp read-only/static data pages already route to [UID:0000KI] or are documented as JsonCpp support.
- Candidate related items rejected: CashShop/FittingRoom/FileDownloader pages are consumers; MSVC STL/CRT support islands are dependencies, not JsonCpp source.
- Standalone, narrow, or broad source-file inference: broad existing third-party source-file/grouping. The four children are narrow function-level docs inside the already identified `json_reader.cpp` translation unit.

## Negative Evidence Summary

- No direct IDA xrefs to raw helper starts.
- No raw PE VA/RVA pointer hits to raw helper starts.
- No raw PE rel32 `call`/`jmp` hits to raw helper starts.
- No vtable/table/global references to raw helper starts.
- No product strings, UI resources, packet constants, or product-owned globals inside the raw helper bodies.
- This negative evidence rejects live product ownership and direct reachability, but not source ownership. The strongest interpretation is retained no-direct-xref third-party out-of-line methods.

## Final Recommendation

- Exact changes applied by B001: created only this research report. No by-* docs, generated reports, `by-memory/-coverage-report.md`, or IDA DB were edited.
- Exact parent assignment recommended: [UID:0000X1] parent should become `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, score about `88/91`.
- Exact child assignment recommended: create four exact child pages with `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, and static-embed final-source route to `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`.
- Exact items left non-emitting: the parent split index and the five padding spans.
- Exact future work outside this target: broader [UID:0000KI] generated-output cleanup so the final rebuild uses the multi-file static embed and does not treat zero-byte `JsonCpp.cpp` as source.

## Exact Supervisor Actions

1. Create four child pages:
   - `by-memory/0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md`
   - `by-memory/0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md`
   - `by-memory/0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md`
   - `by-memory/0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md`
2. Update [UID:0000X1]:
   - `COMPLETION:88`
   - `CONFIDENCE:91`
   - `CANONICAL_OWNER:0000KI`
   - `RECONSTRUCTABLE:FALSE`
   - blank `EMITTER_UIDS`
   - body text should state it is a split/index parent, not a final source body.
3. Child header defaults:
   - `COMPLETION:86` / `CONFIDENCE:91` for the first three; `COMPLETION:87` / `CONFIDENCE:91` for `readNumber`.
   - `CANONICAL_OWNER:0000KI`
   - `RECONSTRUCTABLE:TRUE`
   - `EMITTER_UIDS:0000KI`
   - blank or static-embed-only final C++ as policy decides. If nonblank, use only:

```cpp
// Static embed: third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp
```

4. Update [UID:0000KI] `by-file/JsonCpp.md`:
   - Replace the [UID:0000X1] bullet with a note that [UID:0000X1] is the split/index and the four exact `Reader` helpers are retained no-direct-xref out-of-line methods from `json_reader.cpp`.
   - Add the reachability note: active modeled paths inline equivalent scanner logic in `sub_42A770` and `sub_42AB40`.
   - Add generated-output note: avoid hand-emitting these helpers into `JsonCpp.cpp`; rebuild source is the static embed.
5. Update `by-memory/-ignored.md`:
   - Replace broad duplicate `0x0042acdf-0x0042ae90` text with split/index wording.
   - Add the five exact padding entries listed below.
6. Update `by-project-structure/proposed-source-tree.md` under `third_party/jsoncpp/`:
   - Mention that the `0x0042ace0/0x0042ad30/0x0042ad70/0x0042adb0` raw helpers are exact legacy `Reader` methods in `src/lib_json/json_reader.cpp`, not product code and not separate generated `JsonCpp.cpp` snippets.
7. Optional IDA DB action, if supervisor wants IDA cleanup: define four functions and add comments using the names/comments in the IDA recommendation section. Do not synthesize callers.

## Exact Ignored Padding Rows

Add these to `by-memory/-ignored.md` near the JsonCpp `0x0042acdf-0x0042ae90` entry:

```markdown
- `0x0042acdf-0x0042ace0` - alignment padding between `sub_42AB40` and `Json::Reader::readCStyleComment`.
  - Why ignored: one `0xcc` byte after the modeled JsonCpp comment reader/add-comment helper and before the retained out-of-line C-style comment scanner.
  - Evidence: B001 2026-06-16 IDA `insn_query` renders `0x0042acdf` as `align 10h`; `get_bytes` shows `CC` followed by code at `0x0042ace0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:0000KI], [UID:0000X1].

- `0x0042ad27-0x0042ad30` - alignment padding after `Json::Reader::readCStyleComment`.
  - Why ignored: nine `0xcc` bytes after the `ret` at `0x0042ad26` and before code at `0x0042ad30`.
  - Evidence: B001 2026-06-16 IDA `insn_query` renders `0x0042ad27` as `align 10h`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000KI], [UID:0000X1].

- `0x0042ad66-0x0042ad70` - alignment padding after `Json::Reader::readCppStyleComment`.
  - Why ignored: ten `0xcc` bytes after the `ret` at `0x0042ad65` and before code at `0x0042ad70`.
  - Evidence: B001 2026-06-16 IDA `insn_query` renders `0x0042ad66` as `align 10h`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000KI], [UID:0000X1].

- `0x0042ada3-0x0042adb0` - alignment padding after `Json::Reader::readString`.
  - Why ignored: thirteen `0xcc` bytes after the `ret` at `0x0042ada2` and before code at `0x0042adb0`.
  - Evidence: B001 2026-06-16 IDA `insn_query` renders `0x0042ada3` as `align 10h`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000KI], [UID:0000X1].

- `0x0042ae88-0x0042ae90` - alignment padding after `Json::Reader::readNumber`.
  - Why ignored: eight `0xcc` bytes after the `ret` at `0x0042ae87` and before modeled `sub_42AE90`.
  - Evidence: B001 2026-06-16 IDA `insn_query` renders `0x0042ae88` as `align 10h`; live `lookup_funcs` shows `sub_42AE90` starts at `0x0042ae90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000KI], [UID:0000X1], [UID:0000X2].
```

## Exact Coverage Row Replacement / Insert Text

Replace the current single [UID:0000X1] row in `by-memory/-coverage-report.md`, where it appears after [UID:0000X0] and before the current broad `0x0042ae90-0x0042f3f0` / [UID:0000X2] context, with this nested block. Substitute actual validator-assigned UIDs for `[UID:<new>]`.

```markdown
    - [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) : ignored : 88% : very-strong : Non-emitting JsonCpp split/index for retained no-direct-xref legacy `Json::Reader` lexical helper bodies plus exact alignment padding; B001 2026-06-16 live IDA/raw PE/source audit maps the four source-bearing children to `json_reader.cpp` `Reader::readCStyleComment`, `readCppStyleComment`, `readString`, and `readNumber`, while active modeled parser paths inline equivalent scanner logic in `sub_42A770`/`sub_42AB40`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 100% : strong : `0x0042acdf-0x0042ace0` one-byte `0xcc` alignment after `sub_42AB40` and before retained `Json::Reader::readCStyleComment`.
        - [UID:<new>][0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment](by-memory/0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md) : ignored : 86% : very-strong : Exact retained no-direct-xref out-of-line `Json::Reader::readCStyleComment()` body from vendored `src/lib_json/json_reader.cpp`; scans current/end pointers at `+0x48/+0x44` until `*/`, consumes the slash, and routes to [UID:0000KI] JsonCpp static embed rather than product source.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 100% : strong : `0x0042ad27-0x0042ad30` nine-byte `0xcc` alignment after `Json::Reader::readCStyleComment`.
        - [UID:<new>][0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment](by-memory/0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md) : ignored : 86% : very-strong : Exact retained no-direct-xref out-of-line `Json::Reader::readCppStyleComment()` body from vendored `src/lib_json/json_reader.cpp`; scans to LF/CR, consumes optional CRLF, returns true, and routes to [UID:0000KI] JsonCpp static embed.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 100% : strong : `0x0042ad66-0x0042ad70` ten-byte `0xcc` alignment after `Json::Reader::readCppStyleComment`.
        - [UID:<new>][0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString](by-memory/0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md) : ignored : 86% : very-strong : Exact retained no-direct-xref out-of-line `Json::Reader::readString()` body from vendored `src/lib_json/json_reader.cpp`; advances over escapes until a closing double quote and returns quote-terminated success, with [UID:0000KI] JsonCpp as source owner/emitter route.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 100% : strong : `0x0042ada3-0x0042adb0` thirteen-byte `0xcc` alignment after `Json::Reader::readString`.
        - [UID:<new>][0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber](by-memory/0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md) : ignored : 87% : very-strong : Exact retained no-direct-xref out-of-line `Json::Reader::readNumber()` body from vendored `src/lib_json/json_reader.cpp`; walks integral/fractional/exponent digits, lacks the later `OurReader::readNumber(bool checkInf)` branch, returns void, and routes to [UID:0000KI] JsonCpp static embed.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) : ignored : 100% : strong : `0x0042ae88-0x0042ae90` eight-byte `0xcc` alignment after `Json::Reader::readNumber` and before [UID:0000X2] `sub_42AE90`.
```

## Validator Results

- Commands run by B001 for this report:
  - IDA MCP `idb_open` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` returned session `b002_ranking_0001ZC_20260616` with `auto_analysis_ready:true`, `hexrays_ready:true`.
  - IDA MCP read-only queries listed above.
  - Raw PE read-only pointer/rel32 scan listed above.
- Documentation validator was not run because B001 did not edit by-* docs or shared coverage reports and research reports are not validator-managed by-memory pages.
- Supervisor validator commands after applying recommendations:

> Executable block R001 was removed from this report and preserved verbatim in [0000X1-jsoncpp-legacy-reader-raw-lexical-source-split-removed.md](0000X1-jsoncpp-legacy-reader-raw-lexical-source-split-removed.md). The archived block is non-authoritative and must not be executed.

## Follow-Up Actions

- Supervisor actions:
  - Apply the split and support-doc updates above.
  - Decide whether to add static-embed comments to child `RECONSTRUCTION_CPP CODE` blocks or keep them blank until the global JsonCpp static-embed generator policy is cleaned up.
  - If IDA DB cleanup is desired, define/comment the four functions but do not invent callers.
- A-agent actions:
  - After supervisor creates child pages, fill each page with the IDA/source evidence in this report and keep final C++ limited to static-embed route comments.
  - Do not assign these helpers to product JSON consumers.
- B001 future research actions:
  - If assigned, audit the wider JsonCpp generated-output model so `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` is not mistaken for the final third-party source body.

## Confidence

- Recommendation confidence: high.
- Score confidence: parent `88/91`; children `86-87/91`; padding `100/strong`.
- Remaining uncertainty: exact original linker settings that retained the no-direct-xref out-of-line helpers; broader JsonCpp static-embed generator policy; whether IDA DB should be mechanically updated now or left as documentation-only evidence.

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000X1"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000X1-jsoncpp-legacy-reader-raw-lexical-source-split-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000X1-jsoncpp-legacy-reader-raw-lexical-source-split.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000X1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
