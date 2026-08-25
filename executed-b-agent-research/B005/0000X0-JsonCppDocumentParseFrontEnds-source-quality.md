** TARGET-REPORT-UID:0000X0 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Source-Quality Report - [UID:0000X0] JsonCppDocumentParseFrontEnds

## Assignment

- Assignment ID: `B005-report-jsoncpp-document-parse-front-ends-source-quality-0000X0-mcp-20260623`
- Agent: `B005`
- Target: [UID:0000X0] `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`
- Required report path: `tools/leaser/Agents/Agent-B005/research/0000X0-JsonCppDocumentParseFrontEnds-source-quality.md`
- Task type: report-only research. No by-* docs, generated/project-level docs, IDA database state, `executed/` report movement, or `-coverage-report.md` files were edited.
- Required MCP session: `80de0a67` at `http://127.0.0.1:13337/mcp`

## Current Target State

- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, blank `EMITTER_POSITION_OPTIONAL`, blank reconstruction C++.
- Current owner route: [UID:0000KI] `JsonCpp`, emitted through `NexusTK/third_party/jsoncpp/`.
- Current target role: contiguous third-party JsonCpp document/reader constructor and parse-front-end range, with product calls from item-shop version download and fitting-room cache parsing.
- Current stale points: evidence basis names 2026-05/2026-06 checks rather than current MCP session `80de0a67`; several functions remain `sub_` placeholders despite now-defensible upstream `Json::Reader` names; current coverage row still marks [UID:0000X0] as `ignored : 80%`.

## MCP Evidence Checked

- `server_health(database=80de0a67)` returned `status=ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings ready.
- `idb_list` returned one active/adopted/owned worker session `80de0a67`, not analyzing.
- `survey_binary(detail_level=minimal,database=80de0a67)` returned PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, `.text` `0x401000-0x60d000`, `.rdata` `0x60d670-0x66d000`, `.data` `0x66d000-0x69d000`.
- `entity_query(functions, 0x004298e0-0x0042acf0)` returned thirteen IDA-modeled functions in or immediately inside the range, including the target's twelve JsonCpp starts plus `std::_Func_class<void>::_Empty` at `0x0042a760`.
- `lookup_funcs` confirmed exact modeled starts and non-start gaps around all boundaries, including `0x004298f0`, `0x00429a10`, `0x00429b30`, `0x00429c40`, `0x00429dc0`, `0x00429ec0`, `0x0042a400`, `0x0042a570`, `0x0042a660`, `0x0042a760`, `0x0042a770`, `0x0042aaf0`, `0x0042ab40`, and successor `0x0042ae90`.
- `get_bytes` checked predecessor/successor padding, the raw deprecated error-wrapper bytes at `0x00429ea0`, the `std::_Func_class<void>::_Empty` helper bytes at `0x0042a760`, token/switch-table bytes after `0x0042aa01`, and the raw `Reader::skipSpaces()` body at `0x0042aac0`.
- `xrefs_to` checked all target function starts plus raw starts `0x00429ea0`, `0x0042aa01`, `0x0042aac0`, and successor `0x0042ae90`.
- `callees` checked all modeled target functions.
- `decompile` checked `0x004298f0`, `0x00429a10`, `0x00429b30`, `0x00429c40`, `0x00429dc0`, `0x00429ec0`, `0x0042a400`, `0x0042a570`, `0x0042a660`, `0x0042a760`, `0x0042a770`, `0x0042aaf0`, and `0x0042ab40`.
- Local source comparison used staged `source-3/third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`, `include/json/reader.h`, and matching `simroot_v2/third_party/jsoncpp` source.

## Function And Source Map

| Address/range | MCP/IDA state | Best source-facing role | Evidence |
| --- | --- | --- | --- |
| `0x004298e6-0x004298f0` | no function | predecessor alignment | `get_bytes` returned ten `0xcc` bytes after [UID:0003WK] and before this target. |
| `0x004298f0-0x00429a09` | `sub_4298F0`, size `0x119` | `Json::Reader::Reader()` | Decompile zeroes `errors_`, `document_`, parse pointer fields, `commentsBefore_`, installs default `features_(Features::all())`, and clears `collectComments_`; source line family `Reader::Reader()` matches. |
| `0x00429a09-0x00429a10` | no function | alignment | Seven `0xcc` bytes. |
| `0x00429a10-0x00429b2c` | `sub_429A10`, size `0x11c` | `Json::Reader::Reader(const Features& features)` | Same constructor body as `0x004298f0`, but stores caller-supplied feature dword into the feature field. |
| `0x00429b2c-0x00429b30` | no function | alignment | Four `0xcc` bytes. |
| `0x00429b30-0x00429c33` | `sub_429B30`, size `0x103` | `Json::Reader::parse(const std::string& document, Json::Value& root, bool collectComments)` | Decompile copies input `std::string` data/capacity into `document_`, swaps/moves it to the reader, computes `begin`/`end`, then calls `0x00429c40`; direct product callers pass downloaded/cache string buffers. |
| `0x00429c33-0x00429c40` | no function | alignment | Thirteen `0xcc` bytes. |
| `0x00429c40-0x00429db5` | `sub_429C40`, size `0x175` | `Json::Reader::parse(const char* beginDoc, const char* endDoc, Json::Value& root, bool collectComments)` | Decompile sets `begin_`, `end_`, `current_`, `lastValueEnd_`, clears errors/nodes/comments, resets global `dword_67A778` matching `stackDepth_g = 0`, calls `0x0042ae90` (`readValue()`), checks strict-root array/object, and uses literal `A valid JSON document must be either an array or an object value.`. |
| `0x00429db5-0x00429dc0` | no function | alignment | Eleven `0xcc` bytes. |
| `0x00429dc0-0x00429e96` | `sub_429DC0`, size `0xd6` | `Json::Reader::parse(std::istream& sin, Json::Value& root, bool collectComments)` | Decompile builds a local `JSONCPP_STRING doc`, calls stream/string read helper with delimiter `0xff`, then calls `0x00429c40` with `doc.data()` / `doc.size()`. No direct xrefs in this binary. |
| `0x00429e96-0x00429ea0` | no function | alignment | Ten `0xcc` bytes. |
| `0x00429ea0-0x00429eb2` | raw code, not an IDA function | `Json::Reader::getFormatedErrorMessages() const` deprecated typo wrapper | Bytes `55 8b ec ff 75 08 e8 15 00 00 00 8b 45 08 5d c2 04 00` push the return string pointer, call `0x00429ec0`, return the same pointer. Source lines 822-823 define the deprecated `getFormatedErrorMessages()` wrapper returning `getFormattedErrorMessages()`. No xrefs. |
| `0x00429eb2-0x00429ec0` | no function | alignment | Fourteen `0xcc` bytes. |
| `0x00429ec0-0x0042a3f7` | `sub_429EC0`, size `0x537` | `Json::Reader::getFormattedErrorMessages() const` | Decompile walks the reader error deque, appends `"* "`, location text, newline, two-space message line, optional `"See "` detail line, and returns formatted string. Only xref is the raw deprecated wrapper at `0x00429ea6`. |
| `0x0042a3f7-0x0042a400` | no function | alignment | Nine `0xcc` bytes. |
| `0x0042a400-0x0042a56e` | `sub_42A400`, size `0x16e` | `Json::Reader::getStructuredErrors() const` | Decompile iterates stored errors, computes `offset_start = token.start_ - begin_`, `offset_limit = token.end_ - begin_`, copies `message_`, and pushes structured entries. No direct xrefs in this binary. |
| `0x0042a56e-0x0042a570` | no function | alignment | Two `0xcc` bytes. |
| `0x0042a570-0x0042a653` | `sub_42A570`, size `0xe3` | `Json::Reader::pushError(const Value& value, const JSONCPP_STRING& message)` | Decompile bounds-checks value offsets against document length, builds token type `tokenError`, copies the message, pushes an error record. No direct xrefs. |
| `0x0042a653-0x0042a660` | no function | alignment | Thirteen `0xcc` bytes. |
| `0x0042a660-0x0042a756` | `sub_42A660`, size `0xf6` | `Json::Reader::pushError(const Value& value, const JSONCPP_STRING& message, const Value& extra)` | Decompile adds the extra-location bounds check and stores `extra_ = begin_ + extra.getOffsetStart()`. No direct xrefs. |
| `0x0042a756-0x0042a760` | no function | alignment | Ten `0xcc` bytes. |
| `0x0042a760-0x0042a768` | `std::_Func_class<void,>::_Empty`, size `0x8` | no-xref MSVC STL helper island | Decompile returns `this[9] == 0`; bytes `83 79 24 00 0f 94 c0 c3`; no xrefs/callees. This is not JsonCpp source, but it is isolated, dead/no-xref evidence inside the address span. |
| `0x0042a768-0x0042a770` | no function | alignment | Eight `0xcc` bytes. |
| `0x0042a770-0x0042aa01` | `sub_42A770`, size `0x291` | `Json::Reader::readToken(Token& token)` with inlined `skipSpaces`, `readString`, and `readNumber` scanner bodies | Decompile skips whitespace, reads one char, switches token types for `{}`, `[]`, string, number, `true`, `false`, `null`, comma, colon, comments, EOF, and error, calls `0x0042aaf0` for literal matching and `0x0042ab40` for comments. |
| `0x0042aa01-0x0042aabc` | raw data, not a function | `readToken` switch/jump table and token table | Byte check shows `0f 1f 00` followed by address/table bytes and token values; no xrefs to table starts surfaced in `xrefs_to`, but the table is contiguous with `readToken` code generation. |
| `0x0042aabc-0x0042aac0` | no function | alignment | `0xcc` bytes before raw `skipSpaces`. |
| `0x0042aac0-0x0042aaec` | raw code, not an IDA function | retained `Json::Reader::skipSpaces()` | Bytes load `current_` and `end_`, walk spaces/TAB/CR/LF, update `current_`, and return. `lookup_funcs` says not a function; `xrefs_to` says no xrefs, consistent with active `readToken` inlining this helper. |
| `0x0042aaec-0x0042aaf0` | no function | alignment | Four `0xcc` bytes. |
| `0x0042aaf0-0x0042ab40` | `sub_42AAF0`, size `0x50` | `Json::Reader::match(Location pattern, int patternLength)` | Decompile checks remaining length, compares pattern bytes backward, advances `current_` on success, returns false on mismatch. Called by `0x0042a770` for `true`/`false`/`null`. |
| `0x0042ab40-0x0042acdf` | `sub_42AB40`, size `0x19f` | `Json::Reader::readComment()` with inlined C-style/C++-style comment scanners and `addComment` path | Decompile distinguishes `/*...*/` and `//...` comments, optionally records normalized comment placement using `lastValueEnd_`, appends to `commentsBefore_` or sets comment on current value. Called by `0x0042a770` and `0x0042cf30`. |
| `0x0042acdf-0x0042ace0` | no function | successor alignment | One `0xcc` byte before [UID:0000X1] raw lexical helpers. |

## Callers, Callees, And Reachability

Positive product reachability is narrow and unchanged:

- `xrefs_to 0x004298f0`: two product callers, `0x0041acea` in `sub_41AA00` / [UID:0002TS] `DownloadCashShopVersion`, and `0x0042278d` in `sub_422740` / [UID:0002E9] `FittingRoomDialogItemState::LoadEncodedStateBuffer`.
- `xrefs_to 0x00429b30`: two product callers, `0x0041ad09` in `sub_41AA00` and `0x004227a9` in `sub_422740`.
- These calls prove product consumers, not product ownership. The callers construct `Json::Reader`, parse a string into `Json::Value`, then consume product fields such as `version` or fitting-room category arrays.

Internal/reachability checks:

- `0x00429c40` has two code xrefs, from `0x00429b30+0xa6` and `0x00429dc0+0x7a`.
- `0x00429dc0`, `0x0042a400`, `0x0042a570`, `0x0042a660`, `0x0042a760`, `0x00429ea0`, and `0x0042aac0` have zero direct xrefs in current MCP checks.
- `0x00429ec0` has one xref from raw code `0x00429ea6`, the deprecated typo wrapper.
- `0x0042a770` has eleven parser-island xrefs from `0x0042b120`, `0x0042b730`, `0x0042cb50`, and `0x0042cf30`, consistent with legacy `Reader` object/array/comment parsing.
- `0x0042aaf0` has one xref from `0x0042a770`; `0x0042ab40` has xrefs from `0x0042a770` and `0x0042cf30`.
- Successor `0x0042ae90` has xrefs from `0x00429c40`, `0x0042b120`, and `0x0042b730`, confirming the `Reader::parse` to `Reader::readValue()` handoff and recursive parser flow.

Callee checks match upstream JsonCpp/library support:

- Constructors call only `operator new` for deque sentinel nodes.
- `Reader::parse(std::string const&,...)` calls string support `0x0041b8b0`, `0x00429c40`, free/validation/security helpers.
- `Reader::parse(char const*,...)` calls string clear/copy helpers, node-stack cleanup, `0x0042ae90` value parse, `0x0042cf30` token/comment skipping, `0x0042ca70` add-error support, and value type/comment helpers.
- `Reader::getFormattedErrorMessages()` calls location formatting `0x0042cda0`, string append/grow helpers, and standard cleanup helpers.
- `Reader::readToken()` only calls local `match` and `readComment`; active string/number/space scan logic is inlined in the function body.

## Source Comparison

The staged source file `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` provides exact matches:

- Lines 89-98: `Reader::Reader()` and `Reader::Reader(const Features& features)` match `0x004298f0` and `0x00429a10`.
- Lines 100-119: `Reader::parse(const std::string&...)` and `Reader::parse(std::istream&...)` match `0x00429b30` and `0x00429dc0`.
- Lines 121-160: `Reader::parse(const char*, const char*,...)` matches `0x00429c40`, including `stackDepth_g = 0`, `readValue`, optional comment attachment, and strict-root object/array failure message.
- Lines 257-326: `Reader::readToken(Token&)` matches `0x0042a770` token type assignments, `match("rue")`, `match("alse")`, `match("ull")`, string/number/comment token handling, and token-error fallback.
- Lines 328-346: `Reader::skipSpaces()` and `Reader::match(...)` match raw `0x0042aac0` and modeled `0x0042aaf0`.
- Lines 349-400: `Reader::readComment()` and `addComment(...)` match `0x0042ab40`; [UID:0000X1] carries the retained no-xref exact child scanners for `readCStyleComment`, `readCppStyleComment`, `readString`, and `readNumber`.
- Lines 822-826: deprecated `Reader::getFormatedErrorMessages() const` returns `getFormattedErrorMessages()`, matching raw wrapper `0x00429ea0 -> 0x00429ec0`.
- Lines 826-840: `Reader::getFormattedErrorMessages()` matches `0x00429ec0`.
- Lines 842-855: `Reader::getStructuredErrors()` matches `0x0042a400`.
- Lines 857-888: the two `Reader::pushError` overloads match `0x0042a570` and `0x0042a660`.
- Source also records `stackLimit_g` and `stackDepth_g` at lines 47-48, explaining `dword_67A778` writes/uses in this legacy reader family.

The best library snapshot remains official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802` between tags `1.7.4` and `1.7.5`, as documented by [UID:0000KI]. This pass did not find evidence that changes the project-level JsonCpp source snapshot.

## Heuristic And Inference Reanalysis

Resolved issues:

- The old "medium exact front-end names" cap is now mostly resolved for this target. Current source-facing names can replace the main `sub_` labels for the legacy `Json::Reader` constructor, parse overloads, error formatting, structured-error, push-error, token, match, and comment helpers.
- `0x00429ec0` is not a "parse/stream helper candidate"; it is `Json::Reader::getFormattedErrorMessages() const`. The no-xref raw body at `0x00429ea0` is the deprecated misspelled `getFormatedErrorMessages()` wrapper.
- `0x0042a400`, `0x0042a570`, and `0x0042a660` are source-bearing legacy reader API helpers, not product or CRT helpers, even though they currently have no direct xrefs.
- The `0x0042aa01-0x0042aaf0` gap is not plain padding. It contains generated switch/token data, a retained raw `Reader::skipSpaces()` helper at `0x0042aac0`, and alignment before `Reader::match`.

Remaining caps:

- The page is still an aggregate, not one source method. It spans multiple `Json::Reader` API methods, raw retained source bodies, generated switch/token tables, and one no-xref MSVC STL helper at `0x0042a760`.
- IDA still lacks function objects for some source starts (`0x00429ea0`, `0x0042aac0`), so a future exact-child split could make the source map cleaner.
- The reason the linker retained several no-xref legacy API helpers cannot be proven from current executable references alone.
- `std::_Func_class<void>::_Empty` at `0x0042a760` is not JsonCpp source. It is isolated and no-xref, so it does not change the practical owner of the target, but it should be documented as mixed runtime evidence and may deserve a future tiny runtime/ignored child if the structure is split.

## Positive Evidence

- Current MCP session `80de0a67` is live and IDB-backed; no fallback-only evidence was used.
- PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632` anchors this pass.
- Product calls are exactly the expected two consumer paths into the reader constructor and parse string overload: CashShop version download and FittingRoom item-state cache parse.
- Source comparison against the staged JsonCpp tree resolves most previously placeholder `sub_` names.
- Parser support links forward to [UID:0000X2] at `0x0042ae90` and back to [UID:0000X1] raw lexical helper children without ownership conflict.
- Current generated `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` already treats [UID:0000X0] as an empty emitter marker under [UID:0000KI], matching the static-embed source-route decision.

## Negative Evidence And Rejected Routes

| Candidate | Rank | Decision | Reason |
| --- | ---: | --- | --- |
| [UID:0000KI] `JsonCpp` / `third_party/jsoncpp/src/lib_json/json_reader.cpp` | 1 | Keep | Direct source match, JsonCpp strings/classes, source order, product consumers only call public reader APIs, and file parent already owns the staged static embed. |
| Product consumers: `CashShopVersionRequest`, `FileDownloader`, `FittingRoom`, `ItemCatalog` | 2 | Reject as owner | Product code calls `Json::Reader::Reader()` / `parse(std::string const&,...)`, then reads fields. It does not own the parser implementation. Existing product docs already keep this boundary. |
| Adjacent JsonCpp pages [UID:0000WY], [UID:0000WZ], [UID:0000X1], [UID:0000X2], [UID:0000X6], [UID:0000X7] | 3 | Reject merge | They are same library owner but different address/source subfamilies: value/path/iterator, raw lexical children, reader/builder prelude, writer/OurReader islands. Cross-links are enough. |
| CRT/MSVC runtime or STL | 4 | Reject as primary | Only `0x0042a760` is clearly `std::_Func_class<void>::_Empty` and no-xref. The rest maps to `Json::Reader`. Runtime support should be documented as a tiny island/caveat, not used to reroute the target. |
| No-owner/non-emitting aggregate | 5 | Reject as final target state | Despite mixed tiny runtime/gap evidence, the source-bearing and product-reachable code is vendored JsonCpp. Keep reconstructable through [UID:0000KI], with blank formal C++. |

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KI`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KI`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP` remains blank

Rationale:

- Raise completion from `85` to `88` because current MCP and staged-source comparison resolves the earlier blocker around exact upstream names for nearly every meaningful body in the target.
- Raise confidence from `88` to `90` because current IDB-backed xrefs, decompilation, byte boundaries, product handoffs, and exact source lines agree.
- Do not go higher yet because the target is still a mixed aggregate with raw no-function retained helpers, token tables, a no-xref STL helper, and no exact child split for every source body/table span.

## C++ / No-Code Recommendation

Do not add first-draft C++ to [UID:0000X0].

No-code proof:

- The target is not one source function or one coherent NexusTK method. It spans many legacy `Json::Reader` methods, generated switch/table bytes, raw retained helpers, and one unrelated STL helper.
- The correct source already exists in the staged vendored JsonCpp tree under `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`; the by-file parent emits through `NexusTK/third_party/jsoncpp/`.
- Current generated `JsonCpp.cpp` intentionally uses empty emitter markers for JsonCpp by-memory pages. Hand-writing decompiler-shaped C++ in this target would duplicate and distort the third-party source route.
- If exact children are later created for `Reader::Reader`, parse overloads, error formatting, structured errors, push-error overloads, `readToken`, `match`, and `readComment`, those child pages should still route to the staged static source rather than hand-authored replacements.

## Recommended Target And Support Doc Changes

Target [UID:0000X0]:

- Update metadata to `88/90` with owner/emitter unchanged.
- Replace stale Wave3/older MCP wording with current session `80de0a67`, PE SHA-256, function/xref/decompile/source evidence.
- Replace placeholder `sub_` roles with source-facing roles listed in this report.
- Add explicit rows for raw `0x00429ea0` deprecated `getFormatedErrorMessages()` wrapper, `0x0042a760` no-xref `std::_Func_class<void>::_Empty`, the `0x0042aa01` switch/token data, and raw `0x0042aac0` `Reader::skipSpaces()`.
- Preserve the product-call boundary: `DownloadCashShopVersion` and `FittingRoomDialogItemState::LoadEncodedStateBuffer` are consumers only.
- Record the score rationale and blank-C++ static-embed proof at report-level detail.

Recommended support updates:

- `by-file/JsonCpp.md`: add a concise but specific [UID:0000X0] update noting current MCP `80de0a67`, resolved `Json::Reader` constructor/parse/error/token helper mapping, raw no-xref helpers, and the retained static-embed no-code policy.
- `by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md`: optionally add/retain that `0x0042a770` is the legacy `Reader::readToken` caller target for `sub_42B120`, `sub_42B730`, `sub_42CB50`, and `sub_42CF30`; no ownership change.
- `by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md`: no required change unless implementing exact predecessor detail; it already correctly describes the raw `Reader` scanner children and boundary after `sub_42AB40`.
- `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`: already sufficient for product consumer behavior; optional wording can replace address-only JsonCpp helper labels with `Json::Reader::Reader()` and `Reader::parse(std::string const&,...)`.
- `by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md`: already sufficient for product consumer behavior; optional wording can replace address-only helper labels with `Json::Reader` names.
- `by-file/FittingRoom.md`, `by-file/ItemCatalog.md`, `by-file/CashShopVersionRequest.md`, and `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`: current docs already reject moving JsonCpp helpers into product files; update only if an implementation callback wants the new function names propagated.
- Do not edit generated files. Current `auto-generated/-ag-memory-coverage.md` already routes [UID:0000X0] as emitting through `0000KI`, and `auto-generated/NexusTK/third_party/jsoncpp/JsonCpp.cpp` already lists [UID:0000X0] as an empty emitter marker.

## Supervisor-Owned Coverage Text

`by-memory/-coverage-report.md` currently has a stale row for [UID:0000X0] marked `ignored : 80%`. B-agents must not edit this file. Recommended supervisor-owned replacement row:

```markdown
    - [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) 0x004298f0-0x0042acdf | third-party static-embed island | JsonCppDocumentParseFrontEnds : reconstructable : 88% : strong : Current IDA MCP session `80de0a67` confirms exact JsonCpp `Reader` constructor/parse/error/token helper mapping, product callers at `0x0041acea`/`0x0041ad09` and `0x0042278d`/`0x004227a9`, parser handoff to `0x0042ae90`, raw retained `getFormatedErrorMessages` and `skipSpaces` helpers, token/switch table bytes, and a no-xref `std::_Func_class<void>::_Empty` island; source should come from staged `third_party/jsoncpp/src/lib_json/json_reader.cpp`, not product code or hand-written C++.
```

## Expected Validators After Accepted Implementation

Run validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000X0-JsonCppDocumentParseFrontEnds-source-quality-removed.md](0000X0-JsonCppDocumentParseFrontEnds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the optional support validators for files actually changed in a later callback.

## Implementation Tracking Checklist

- [x] `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`: updated metadata to `88/90`; kept `CANONICAL_OWNER:0000KI`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KI`, blank emitter position, and blank aggregate C++. Proof: Status and Score Rationale sections now record the accepted metadata and static-embed route.
- [x] `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`: added current MCP session `80de0a67`, PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, exact function/source map, product xrefs, internal xrefs, callees, padding/table/raw-helper evidence, rejected owners, score rationale, no-code proof, and implementation-ready split candidates. Proof: sections `Status`, `MCP Function And Source Map`, `Product Callers`, `Parser Call Chain And Callees`, `Raw And Generated Fragments`, `Ownership Decision`, `C++ And Split Disposition`, and `Score Rationale`.
- [x] `by-file/JsonCpp.md`: synced [UID:0000X0] current evidence without changing source root or snapshot candidate. Proof: Evidence section now names `Json::Reader::Reader()`, `Json::Reader::Reader(const Features&)`, parse overloads, deprecated `getFormatedErrorMessages`, formatted/structured error helpers, push-error helpers, `readToken`, `match`, `readComment`, raw `skipSpaces`, token/switch table data, the no-xref STL island, and product-consumer boundary. Change log dated 2026-06-23.
- [x] `by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md`: added support note for predecessor `0x0042a770` as legacy `Json::Reader::readToken(Token&)` with MCP `80de0a67` xrefs from `sub_42B120`, `sub_42B730`, `sub_42CB50`, and `sub_42CF30`; ownership unchanged. Proof: Range Role, Evidence, and Changes sections.
- [x] `by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md`: added predecessor `Reader::readComment()` / raw-helper boundary proof. Proof: Range Role, Function Inventory, Evidence, and Changes sections now state `sub_42AB40` / `0x0042ab40-0x0042acdf` is legacy `Json::Reader::readComment()` followed by one-byte alignment `0x0042acdf-0x0042ace0` before raw `readCStyleComment`.
- [x] Product consumer docs: updated where materially useful and marked already sufficient where no stale/address-only [UID:0000X0] labels were present.
  - Changed `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`: Code refs, B001/Capstone evidence, and Changes now name `Json::Reader::Reader()` and `Reader::parse(std::string const&,...)`.
  - Changed `by-memory/0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md`: Behavior, Live IDA Evidence, JsonCpp Boundary, and Changes now name `Json::Reader::Reader()` and `Json::Reader::parse(const std::string&, Json::Value&, bool)`.
  - Changed `by-file/FittingRoom.md`: file-level fitting-room parser note and JSON/cache parser cluster note now route the parser implementation to [UID:0000KI] with source-facing `Json::Reader` names.
  - Changed `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`: product/third-party boundary, covered-range row, JsonCpp handoff, evidence, ownership decision, and Changes now name the exact `Json::Reader` constructor/parse dependency.
  - Already sufficient/not edited: `by-file/ItemCatalog.md` only states that FittingRoom item-state parses item-shop JSON through JsonCpp and has no stale [UID:0000X0] address-only helper labels; `by-file/CashShopVersionRequest.md` keeps the payload/FileDownloader boundary and mentions JsonCpp only as product version-key parsing context without owning parser helper addresses.
- [x] Did not edit `by-memory/-coverage-report.md`; the exact replacement row above remains supervisor-owned. Proof: post-validation check still shows the live [UID:0000X0] coverage row as the stale `ignored : 80%` row at `by-memory/-coverage-report.md`, so the `88%` replacement text was not applied by B005.
- [x] Did not manually edit generated docs, project-level generated files, IDA DB/tool state, or move this report to `executed/`. Validator side effects were limited to the requested `--apply` runs: filtered proof rerun reported `projected_stats_update:1`, `stats_incremental_noop:1`, and `autogen_report_noop:7` for each file; the initial unfiltered target validator also reported normal UID-link insertion and autogen/project stats refresh. Current lease report has only unrelated B004 MiniMap leases.
- [x] Validators run for every changed by-* doc from `E:\NTK\GhidraBridge\source-3\project-documentation`; each command exited `0` with `ok: 1`, no warning/error lines in the filtered proof output:
  - `python .\tools\validator.py --mode file --file by-memory\0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\JsonCpp.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00422740-0x00422919.FittingRoomDialogItemStateLoadEncodedStateBuffer.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-file\FittingRoom.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md --apply --queue-timeout 240` -> exit `0`, `ok: 1`.

## Blockers

No current blockers. MCP session `80de0a67` was available for this report, and no fallback-only evidence was used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000X0-JsonCppDocumentParseFrontEnds-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000X0"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000X0-JsonCppDocumentParseFrontEnds-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000X0-JsonCppDocumentParseFrontEnds-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000X0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
