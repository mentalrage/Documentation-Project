*** UID:0000KI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/third_party/jsoncpp/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# JsonCpp

## Status

- Confidence: very strong for JsonCpp identity, active source closure, compiler-data routing, and the current upstream snapshot candidate. The best current source match is official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802`, between tags `1.7.4` and `1.7.5`; this is a commit identity, not an exact release-tag claim even though its `version.h` still reports `1.7.4`.
- Proposed module: `third_party/jsoncpp/`
- Formal import policy: source-bearing `json_reader.cpp` and `json_writer.cpp` by-memory children now use validator inline `RECONSTRUCTION_CPP CODE` import directives with blank multiline blocks. [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) remains a blocked blank-C++ exception because `json_value.cpp` depends on `json_valueiterator.inl`, and current validator import rules reject `.inl` paths.
- Evidence basis: read-only IDA MCP string/xref/decompile checks on 2026-05-25, local candidate archives in [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md), the current `source-3/third_party_embeds/jsoncpp` static embed, generated `source-3/simroot_v2/third_party/jsoncpp`, official upstream source/history checks for `1.7.0-1.7.7` and commit `b299d3581f4dc670734f1fe1a34fce1282337802`, existing cash-shop/download docs, and official JsonCpp integration notes. `wave3.py` was not executed for this pass.

## File Role

This is statically linked JsonCpp parser/writer support code. It should stay separate from NexusTK feature modules that consume JSON data, such as cash-shop/item-shop metadata.

Project modules should own URLs, downloader flow, catalog interpretation, and UI state. JsonCpp should own JSON parse/serialize support.

## Evidence

- IDA strings include JsonCpp parser/settings names at `0x0060e75c-0x0060e7f8`: `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, and `allowSpecialFloats`.
- IDA strings include `Json::Value` diagnostics such as `in Json::Value::asCString(): requires stringValue`, `in Json::Value::resize(): requires arrayValue`, `in Json::Value::getMemberNames(), value must be objectValue`, `duplicateStringValue`, and `duplicateAndPrefixStringValue`; [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) now anchors the main value/object helper island.
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) is now a non-emitting split index for the adjacent value/comment/path/iterator support range immediately before the document parse front ends. B002/supervisor reanalysis found the old CRT-primary framing incomplete: `0x00428b50/60` are best treated as folded `Json::Value::CommentInfo` ctor/dtor aliases despite the CRT `__crt_strtox::big_integer` IDA name, and the rest of the executable code maps to JsonCpp source methods.
- [UID:0003WI][0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor](by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md), [UID:0003WJ][0x00428c60-0x00429473.JsonCppPathArgumentAndPath](by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md), and [UID:0003WK][0x00429480-0x004298e6.JsonCppValueIteratorSupport](by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md) carry the source-bearing split children for `json_value.cpp` `CommentInfo`/`PathArgument`/`Path` and `json_valueiterator.inl` iterator support.
- [UID:0000WX][0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md) cover the no-xref raw helper island immediately before the modeled `Json::Exception` constructor family.
- IDA RTTI-ish strings identify `Json::Exception`, `Json::RuntimeError`, `Json::LogicError`, `Json::FastWriter`, `Json::StyledWriter`, `Json::CharReader`, `Json::CharReader::Factory`, `Json::CharReaderBuilder`, `Json::OurCharReader`, `Json::StreamWriter`, `Json::StreamWriter::Factory`, `Json::StreamWriterBuilder`, and `Json::BuiltStyledStreamWriter`.
- Parser diagnostic xrefs show two reader families: [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md), with examples including `Exceeded stackLimit in readValue().` referenced from `0x0042ae90`, object separator/colon diagnostics from `0x0042b120`, and string-escape diagnostics from `0x0042bfc0`; and [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) plus [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md), with matching `OurReader` token/comment/error helpers and duplicate-key diagnostics from `0x004331f0`.
- 2026-06-27 B008 source-quality incorporation for [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md): current MCP session `b001_000241_20260627` resolves the subrange mapping as legacy `Json::Reader` continuation at `0x0042ae90-0x0042d2e0` and `CharReaderBuilder`/`parseFromStream`/`operator>>` at `0x0042d2e0-0x0042e660` from `json_reader.cpp`, followed by `StreamWriter`/`StreamWriter::Factory`/`writeString`/`StreamWriterBuilder` constructor-destructor prelude at `0x0042e660-0x0042e850` from `json_writer.cpp`. The page uses the formal validator import directive with both source files plus `json_tool.h` and required public headers, keeps the multiline block blank, and leaves [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md) starting at `0x0042e850`.
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) is now a non-emitting split/index for retained no-direct-xref legacy `Json::Reader` lexical helpers. [UID:0003WL][0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment](by-memory/0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md), [UID:0003WM][0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment](by-memory/0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md), [UID:0003WN][0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString](by-memory/0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md), and [UID:0003WO][0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber](by-memory/0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md) carry the exact source-bearing children from `src/lib_json/json_reader.cpp`; active modeled paths inline equivalent scanner logic in `sub_42A770`/`sub_42AB40`, so do not hand-emit these helpers into zero-byte generated `JsonCpp.cpp`.
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) immediately follows the second parser island and is now identified by B014 MCP session `80de0a67` as `Json::OurReader::decodeDouble(Token&, Value&)` from staged `src/lib_json/json_reader.cpp`. It references `Unable to parse token length`, carries the two direct JsonCpp caller edges from `OurReader::decodeNumber(Token&, Value&)` and `OurReader::decodeDouble(Token&)`, keeps the `b299d3581f4dc670734f1fe1a34fce1282337802` source-snapshot/no-release-tag wording, rejects later `fixNumericLocaleInput` behavior, and emits through the formal validator inline import directive for `json_reader.cpp`.
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) is now a non-emitting split index. The reader child [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md) covers `OurReader` unicode/error/recovery/location/comment helpers, raw helper bodies at `0x00434db0`, `0x00434e30`, and `0x00434e50`, and reader switch/table data including `jpt_4350AB` at `0x004352f8` through the exact `0x004353c0` source-file boundary. The writer child [UID:00048C][0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers](by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md) starts at `sub_4353C0`, covers `BuiltStyledStreamWriter` construction/value/array/indent/comment helpers, records writer jump table `jpt_4355B0` at `0x004358a0-0x004358c0`, and ends after raw static `hasCommentForValue` at `0x00436180-0x004361ae`. Predecessor padding is nine `0xcc` bytes at `0x00434887-0x00434890`. Both children use validator inline import directives, and the parent emits nothing.
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md) follows as MSVC/Dinkumware STL and iostream support heavily used by JsonCpp and other standard-library callers; B005 recheck confirms JsonCpp is a heavy consumer rather than the source owner, with broad later runtime/product caller spread and standard-library diagnostics, so this code should come from the compiler/runtime rather than JsonCpp or NexusTK handwritten source.
- [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md) records a non-contiguous JsonCpp `Value` cleanup tail chunk assigned by IDA to `sub_427310`; it is third-party/compiler cleanup support, not a Deque or NexusTK product method.
- [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md) records the following MSVC/Dinkumware string, stream, locale, exception, and numeric conversion support island used by JsonCpp and other runtime callers.
- [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md) continues the ignored support area with Dinkumware runtime helpers plus JsonCpp `duplicateAndPrefixStringValue` and `duplicateStringValue` allocation helpers before the valid-key helper island.
- [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md) documents the JsonCpp writer/runtime tail after valid writer keys, including JSON escape/special-float formatting support and an embedded lookup table before LodePNG begins.
- Builder/settings xrefs include `collectComments`, `allowDroppedNullPlaceholders`, and `allowSpecialFloats` from settings/build helpers at `0x0042d380`, `0x0042db90`, `0x0042def0`, and the [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md) helper at `0x004417e0`.
- 2026-06-27 B012 source-quality incorporation for [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md): live MCP session `80de0a67` keeps `sub_4417E0` as the `0x004417e0-0x00441d24` `json_reader.cpp` `getValidReaderKeys` helper, with the direct caller `0x0042d86c` inside `sub_42D7F0` / `CharReaderBuilder::validate`, ten reader keys from `collectComments` through `allowSpecialFloats`, staged `json_reader.cpp` SHA-256 `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2`, and formal validator inline import directive for `json_reader.cpp`.
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md) covers the writer settings/factory/defaults range. It reads and validates `indentation`, `commentStyle`, `enableYAMLCompatibility`, `dropNullPlaceholders`, `useSpecialFloats`, and `precision`, then allocates the `BuiltStyledStreamWriter`-style object.
- 2026-06-26 B013 [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md) recheck: live IDA MCP session `80de0a67` reconfirmed `getValidWriterKeys` at `0x00441d30-0x00442084`, sole caller `0x0042ee8c` inside `StreamWriterBuilder::validate`, six writer-setting string inserts, clear/insert behavior, and `0xcc` padding to the `0x00442090` writer/runtime tail. The staged `third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp` and `include/json/writer.h` match the obtained `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` static embed hash-for-hash. Exact source-bearing JsonCpp children such as [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md) use validator inline import directives routed through this file UID.
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) covers the retained `Writer`/`FastWriter`/`StyledWriter` implementation family and now emits through the formal validator inline import directive for `third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp`, `json_tool.h`, and the staged public JsonCpp headers. B004 MCP session `73c77998` records the no-function raw `FastWriter::FastWriter()` body at `0x0042f400`, the corrected `0x0042f780-0x0042f800` FastWriter jump-table plus raw `StyledWriter::StyledWriter()` subrange, current no-xref/no-pointer-route confidence caps, and the pre-callback generated empty-marker state. [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) is the following source-bearing `Json::StyledWriter::pushValue(JSONCPP_STRING const&)` child and now emits through the same formal validator inline import directive for staged `json_writer.cpp`, `json_tool.h`, and public JsonCpp headers, with a blank multiline block. B012 MCP session `b5326241-58b0-4365-95aa-2284b04eb3cb` / database `supervisor_recovery_20260705` reconfirmed the exact `0x00430040-0x00430092` `0x52`-byte function, false internal starts at `0x00430041` and `0x00430058`, no function at `0x00430092`, five `sub_42F870` callsites, callees `0x0041d3b0`, `0x00437470`, and `0x0043f3f0`, and staged `json_writer.cpp` line 539 as the source identity. Keep UID0000X5 separate from neighboring writer pages; do not route it to Exchange, ClanBank, or other product owners. [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) is now a non-emitting source-file split index. Current B001 MCP session `80de0a67` places the `json_writer.cpp` child at [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md) through the exact `0x00431c00` boundary, including the remaining `StyledWriter`/`StyledStreamWriter` tail, scalar/string helpers, escape table, and `Json::operator<<`; the `json_reader.cpp` child [UID:000380][0x00431c00-0x00431d50.JsonCppOurReaderPrelude](by-memory/0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md) starts at raw `Json::OurFeatures::all()` and carries `OurReader::OurReader` plus padding before [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md). These source-bearing child pages should emit only their accepted validator inline import directives, and the split/index parents should emit nothing.
- [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) is a consumed SSO-15 `std::string`-like storage helper, not a JsonCpp-authored source body. B010 source-routing reanalysis records direct JsonCpp value/exception/writer/parser callers, including the `StyledWriter::pushValue` path, but FittingRoom and later MSVC/STL/runtime callers also use the same helper. Vendored JsonCpp should keep `JSONCPP_STRING` / `std::string` source operations and let compiler/runtime support emit equivalent storage machinery.
- Known product handoff: [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) calls [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) at `0x004298f0` (`Json::Reader::Reader()`) and `0x00429b30` (`Json::Reader::parse(const std::string& document, Json::Value& root, bool collectComments)`), then uses JsonCpp value helpers to read `version` and item-shop category arrays.
- 2026-06-23 B005 MCP session `80de0a67` resolves [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) as the legacy `Json::Reader` document/parse front-end range in `src/lib_json/json_reader.cpp`: `0x004298f0` and `0x00429a10` are the default and `Features` constructors; `0x00429b30`, `0x00429c40`, and `0x00429dc0` are the string, char-range, and stream parse overloads; `0x00429ea0` is the raw retained deprecated typo wrapper `getFormatedErrorMessages()` calling `getFormattedErrorMessages()` at `0x00429ec0`; `0x0042a400`, `0x0042a570`, and `0x0042a660` are structured-error and push-error helpers; `0x0042a770`, `0x0042aaf0`, and `0x0042ab40` are `readToken`, `match`, and `readComment`; raw `0x0042aa01-0x0042aabc` is token/switch table data; raw `0x0042aac0-0x0042aaec` is retained no-xref `Reader::skipSpaces()`. The no-xref `std::_Func_class<void,>::_Empty` helper at `0x0042a760` remains a tiny MSVC/STL caveat inside the broad address span, not a source-owner reroute. Product callers at `0x0041acea`/`0x0041ad09` and `0x0042278d`/`0x004227a9` are consumers only. Keep the source snapshot/root unchanged and use validator inline import directives for importable source-bearing JsonCpp by-memory children rather than copying or decompiler-rewriting third-party source; non-emitting split/index pages and `.inl`-blocked pages should explain their no-code disposition separately.
- 2026-06-24 B005 MCP session `80de0a67` resolves [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) as the builder-era `Json::OurReader::parse` method in `src/lib_json/json_reader.cpp`. MCP reports `sub_431D50` size `0x1cc`, exclusive end `0x00431f1c`, three bytes of predecessor padding at `0x00431d4d-0x00431d50`, four bytes of successor padding at `0x00431f1c-0x00431f20`, and a single direct code caller `0x0044270c` inside the `OurCharReader::parse` wrapper at `0x004426e0`. That wrapper uses the `OurCharReader` vtable cells at `0x0060e754` (`0x0043b430`, `0x004426e0`) and can call [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) at `0x0044271e` to return formatted errors. [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) calls [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md) at `0x00431dff` for `OurReader::readValue()` and calls `0x00435040` at `0x00431e0c` for comment-token skipping in [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md). Its fail-if-extra branch checks `tokenError=16` and `tokenEndOfStream=0`, its strict-root branch requires root value types `6/7`, and its literal xrefs include `Extra non-whitespace after JSON value.` plus `A valid JSON document must be either an array or an object value.` The staged `json_reader.cpp` source hash `89074ed5550883e9ea7d300ed24292bb3238a18f76103c1219adb4d08f8899d2` matches the method body and keeps this page on the validator import-directive path rather than a handwritten by-memory body.
- Current static embed state on 2026-05-25: `source-3/third_party_embeds/jsoncpp`, `source-3/simroot_v2/third_party/jsoncpp`, and [UID:0001QY][README](by-meta/obtained_thirdparty_files/static_embeds/README.md) for `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` are hash-identical. Earlier generated output lacked these marker names, but the current simroot now contains the upstream source tree.
- Existing product docs show JSON-facing behavior: [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) downloads `https://secure.kru.com/itemshop/data/itemshop.json`.
- No explicit JsonCpp version string such as `0.10.6`, `1.7.2`, `JSONCPP_VERSION_STRING`, `JsonCpp`, or `jsoncpp` has been found in the executable strings checked so far.
- IDA string `Unable to parse token length` at `0x0060e730` is referenced by `0x0043463c` inside `sub_4345F0`. That string is present in the `1.7.x` reader source line family and absent from `0.10.6`.
- IDA string search found no `reader error` string. `jsoncpp-0.10.6` contains `throwRuntimeError("reader error")` in `parseFromStream`, while the `1.7.x` path throws the collected error string instead.
- IDA decompile of `0x00431d50` shows the `OurReader::parse` fail-if-extra branch as `failIfExtra && token.type_ != tokenError && token.type_ != tokenEndOfStream`; it lacks the `strictRoot` condition added later by upstream commit `126bdc2` and included in tag `1.7.5+`.
- IDA decompile of `0x00424850` shows `Value::nullSingleton()` as a guarded static `Value` object with an `atexit` destructor, matching upstream commit `b299d358` and not tags `1.7.3-1.7.4`, which used a static pointer initialized with `new Value`.
- IDA decompile of `0x00424c90` shows the `Value(stringValue)` constructor path still assigning a null string pointer, so it predates upstream commit `7e0571b`, which changed default string values to a static empty string.

## Version-Matching Notes

The presence of `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, and `BuiltStyledStreamWriter` points to a builder-era JsonCpp API family rather than early `Reader`/`Writer`-only releases. The latest comparison rejects `0.10.6` as an equal candidate and narrows the best current source snapshot to official upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802`.

Important strings/classes to use for matching:

- `collectComments`
- `allowComments`
- `allowDroppedNullPlaceholders`
- `allowNumericKeys`
- `allowSingleQuotes`
- `failIfExtra`
- `rejectDupKeys`
- `allowSpecialFloats`
- `CharReaderBuilder`
- `StreamWriterBuilder`
- `OurCharReader`
- `BuiltStyledStreamWriter`
- `FastWriter`
- `StyledWriter`
- `Json::Value` diagnostic messages

Local candidate archives currently staged:

| Archive | Version macro | Current status |
| --- | --- | --- |
| `jsoncpp-0.10.6.candidate.zip` | `JSONCPP_VERSION_STRING "0.10.6"` | No longer favored. It contains many public marker strings, but it lacks `Unable to parse token length` and contains the unfound `reader error` string. |
| `jsoncpp-1.7.0.candidate.zip` through `jsoncpp-1.7.2.candidate.zip` | `JSONCPP_VERSION_STRING "1.7.0"` through `"1.7.2"` | Retained comparisons. They match the reader string family, but they lack the `nullSingleton()` implementation shape observed at `0x00424850`. |
| `jsoncpp-1.7.3.candidate.zip` and `jsoncpp-1.7.4.candidate.zip` | `JSONCPP_VERSION_STRING "1.7.3"` / `"1.7.4"` | Retained comparisons. They introduce `nullSingleton()`, but their source uses a static pointer initialized with `new Value`, unlike the binary's static-object singleton. |
| `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` | Between `1.7.4` and `1.7.5`; version macro still follows the upstream source at that commit | Best current source snapshot. It has the static-object `nullSingleton()` behavior and still predates the later string-constructor and reader changes absent from the binary. |
| `jsoncpp-1.7.5.candidate.zip` through `jsoncpp-1.7.7.candidate.zip` | `JSONCPP_VERSION_STRING "1.7.5"` through `"1.7.7"` | Negative comparisons. They inherit later reader behavior not present in `0x00431d50`/`0x004345f0`. |

All staged `1.7.x` candidates contain `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, `BuiltStyledStreamWriter`, `allowDroppedNullPlaceholders`, `allowSpecialFloats`, `rejectDupKeys`, `collectComments`, `Error from reader: %s`, and `duplicateAndPrefixStringValue`, so those common strings alone do not distinguish them. The useful discriminators found in this pass are the second-reader token-length error path, `OurReader::parse` fail-if-extra condition, `Value::nullSingleton()` storage strategy, and default string-value constructor behavior.

The upstream history between tags `1.7.4` and `1.7.5` is especially important:

| Commit | Upstream change | Binary match status |
| --- | --- | --- |
| `b299d3581f4dc670734f1fe1a34fce1282337802` | Changes `nullSingleton()` from a heap-allocated static pointer to a static `Value` object. | Matches `0x00424850`. |
| `7e0571b444497ad9a0a8547d76a06ef426c7116e` | Changes default `stringValue` construction from null pointer to static empty string. | Not present; `0x00424c90` still uses null. |
| `094a7d8` | Adds `fixNumericLocaleInput(buffer, buffer + length)` before number `sscanf`. | Not present in `0x004345f0`. |
| `126bdc2` | Adds the `strictRoot` term to the fail-if-extra parse condition. | Not present in `0x00431d50`. |

This makes `b299d3581f4dc670734f1fe1a34fce1282337802` the best current official source snapshot candidate, not a release tag. Continue lower-helper comparison against that archive before assigning final per-function names across the whole library.

## Source-Structure Decision

Use the upstream multi-file folder layout from the staged official commit archive:

```text
third_party/
  jsoncpp/
    include/json/
      assertions.h
      autolink.h
      config.h
      features.h
      forwards.h
      json.h
      reader.h
      value.h
      version.h
      writer.h
    src/lib_json/
      json_reader.cpp
      json_tool.h
      json_value.cpp
      json_valueiterator.inl
      json_writer.cpp
```

The extracted best candidate archive does not contain a generated `dist/jsoncpp.cpp` amalgamation directory. Prefer the upstream multi-file layout unless a later source package or original build artifact proves the client used a generated amalgamated file.

Current generated placement mirrors this decision: `source-3/third_party_embeds/jsoncpp` is emitted under `source-3/simroot_v2/third_party/jsoncpp`. Treat those files as read-only third-party source inputs, not NexusTK product source to rewrite.

### Read-Only Data Regeneration Boundary

[UID:00024O][0x0060e2ac-0x0060f034.JsonCppReadOnlyData](by-memory/0x0060e2ac-0x0060f034.JsonCppReadOnlyData.md) is the reviewed static-data index for JsonCpp-authored literals/vftables plus embedded MSVC runtime data. It contains 341 unique physical item heads: 142 named, 8 typed, 266 data, 75 undefined, and zero code. The indexed query found 108 names and 80 exact strings with 268 inbound xrefs; byte-level reconciliation found 34 additional physical named heads. The older assumption that 108 indexed names represented every physical named head is retained only as corrected history.

The exact outer fences are ABI RTTI complete-object-locator pointers: `0x0060e2ac` points to the `Json::Exception` COL at `0x006412c0`, and `0x0060f034` points to the `std::num_put` COL at `0x00641618`. The adjacent runtime pages are [UID:00024N][0x0060e174-0x0060e2ac.MsvcStlLocaleIostreamRdata](by-memory/0x0060e174-0x0060e2ac.MsvcStlLocaleIostreamRdata.md) and [UID:00024P][0x0060f034-0x0060f200.MsvcStlNumericRdata](by-memory/0x0060f034-0x0060f200.MsvcStlNumericRdata.md). Runtime children inside the index are [UID:0003AN][0x0060e48c-0x0060e528.JsonCppMsvcIstreamRuntimeVtables](by-memory/0x0060e48c-0x0060e528.JsonCppMsvcIstreamRuntimeVtables.md), including the `basic_istringstream<char>` vftable and `{0,0x60}` vbtable, and [UID:0003AO][0x0060e810-0x0060e824.JsonCppMsvcOstreamRuntimeVtables](by-memory/0x0060e810-0x0060e824.JsonCppMsvcOstreamRuntimeVtables.md), including the `basic_ostringstream<char>` vftable and `{0,0x50}` vbtable.

The exact active staged-source closure needed to regenerate target semantics is 13 files:

| Active staged source | SHA256 |
| --- | --- |
| `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` | `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2` |
| `third_party_embeds/jsoncpp/src/lib_json/json_value.cpp` | `F2C47295CC3FD59AA2D725074958E8F7A21EACB7E0A9889AB2B1B7DB7D11980E` |
| `third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp` | `C197234A6B01D18355990168A0096BAF25AD3AF2381A38B39AAB62C97A41E609` |
| `third_party_embeds/jsoncpp/src/lib_json/json_tool.h` | `771D37DA2CCE1BE90BB62A1C35C65FA05149ABA386BEBD36FF6359D7A74F6F88` |
| `third_party_embeds/jsoncpp/src/lib_json/json_valueiterator.inl` | `0ECA25ECA79C61C64ABFFC93DA36644ED1553DAD0639397F8A20D998E9106D46` |
| `third_party_embeds/jsoncpp/include/json/assertions.h` | `2F2646718286632A45A45540AAC0F8240D3713945690530AC253C34D98C90151` |
| `third_party_embeds/jsoncpp/include/json/config.h` | `4A1B4EBF8DCE646091A42C9CCEE12476024FE8B69045972BA05AAC33F054CE7D` |
| `third_party_embeds/jsoncpp/include/json/version.h` | `3D995A29400D0EF889026D279EBA66CA8172086709E4842F86D12F84A3717F1F` |
| `third_party_embeds/jsoncpp/include/json/reader.h` | `4A707D6B3C9D0CA16A57BA20AE114C28E184F588C083D870765B9FBC4C9D1DC3` |
| `third_party_embeds/jsoncpp/include/json/features.h` | `29468BE6ED917D8889493E93A0142430AA560170D41DE56182D35F37B1D355C7` |
| `third_party_embeds/jsoncpp/include/json/forwards.h` | `46FA7154AB8E1FDF3C79B8D00751BF022F4F377B7F1A6BABE2B8076464F140C6` |
| `third_party_embeds/jsoncpp/include/json/value.h` | `361960D4C8401FF995D3CA6F2DCAF912FBD1401D46413C04AAF2ABB2F0585274` |
| `third_party_embeds/jsoncpp/include/json/writer.h` | `689FDD001A939D262457629FF69E12454DE4215483690441C9B2358179FF1369` |

`allocator.h` is inactive under `JSONCPP_USING_SECURE_MEMORY=0`; `autolink.h` is build-link convenience; umbrella `json.h` adds no target semantics beyond the active recursive headers. Source-bearing by-memory children should use validator import directives for the applicable staged files. UID00024O itself is false/non-emitting with blank formal C++/H because there is no upstream `JsonCppReadOnlyData.cpp`, no code item in the span, and no defensible direct static-data import. JsonCpp classes, functions, and source literals are regenerated by compiling the source-bearing children; the runtime vftables/vbtables are regenerated by compatible MSVC STL. Product cash-shop/fitting-room/download modules remain consumers rather than source owners.

For formal `RECONSTRUCTION_CPP CODE`, prefer validator inline import directives over legacy `// Static embed:` marker comments whenever the staged source can be represented with `.c`, `.cpp`, or `.h` import paths. `json_reader.cpp` and `json_writer.cpp` pages are importable now. `json_value.cpp`-dependent pages remain blocked where they require `json_valueiterator.inl`; do not import only `json_value.cpp` as a partial substitute, rename the `.inl`, or paste vendored source into a multiline C++ block.

Current source-bearing JsonCpp by-memory pages that are represented by staged `json_reader.cpp` or `json_writer.cpp` should use validator inline `RECONSTRUCTION_CPP CODE` import directives with blank multiline blocks. Legacy `// Static embed:` wording is superseded for those pages.

Do not assign JsonCpp internals to cash-shop, fitting-room, or downloader source files. Those modules should own product URLs, HTTP/request flow, catalog interpretation, and UI state; JsonCpp should remain a third-party parse/serialize dependency.

## Rebuild Strategy

1. Use the staged official `b299d3581f4dc670734f1fe1a34fce1282337802` commit archive as the current source target.
2. Preserve the upstream `include/json/` and `src/lib_json/` layout for the first rebuild attempt.
3. Continue mapping lower helpers against `json_reader.cpp`, `json_value.cpp`, and `json_writer.cpp` before assigning exact function names to every IDA-modeled helper.
4. Keep NexusTK-owned JSON feature code in cash-shop/download modules.

## Cross-References

- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md)
- [UID:0001QY][README](by-meta/obtained_thirdparty_files/static_embeds/README.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md)
- [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md)
- [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md)
- [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md)
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md)
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md)
- [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md)
- [UID:00048C][0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers](by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md)
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md)
- [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md)
- [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md)
- [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md)
- [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md)
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md)
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md)
- [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md)
- [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md)
- [UID:000380][0x00431c00-0x00431d50.JsonCppOurReaderPrelude](by-memory/0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md)
- [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md)
- [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md)
- [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md)
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md)
- [UID:0003WI][0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor](by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md)
- [UID:0003WJ][0x00428c60-0x00429473.JsonCppPathArgumentAndPath](by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md)
- [UID:0003WK][0x00429480-0x004298e6.JsonCppValueIteratorSupport](by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md)
- [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md)
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md)
- [UID:0003WL][0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment](by-memory/0x0042ace0-0x0042ad27.JsonCppLegacyReaderReadCStyleComment.md)
- [UID:0003WM][0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment](by-memory/0x0042ad30-0x0042ad66.JsonCppLegacyReaderReadCppStyleComment.md)
- [UID:0003WN][0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString](by-memory/0x0042ad70-0x0042ada3.JsonCppLegacyReaderReadString.md)
- [UID:0003WO][0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber](by-memory/0x0042adb0-0x0042ae88.JsonCppLegacyReaderReadNumber.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)

## Changes

- 2026-08-04 B007 accepted UID00024O callback raised this file page from `92/88` to `94/92` and incorporated the lossless read-only-data/source-closure decision: exact commit-not-tag wording, all 13 active staged files with hashes, corrected UID00024N/O/P and UID0003AN/AO ranges, physical item/name/string/xref totals, and the distinction between source-bearing JsonCpp imports, compiler-generated runtime data, and the non-emitting static-data index. No product module was made an owner and no hand-authored static-data source was introduced.

- 2026-07-05 B012 [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) source-quality incorporation: converted the `StyledWriter::pushValue` helper from a blank/support-only marker to the formal validator inline import directive for staged `json_writer.cpp`, `json_tool.h`, and public JsonCpp headers. Scores on the child move to `88/91`; this by-file page keeps `COMPLETION:92`, `CONFIDENCE:88`, and projected path `NexusTK/third_party/jsoncpp/`. B012 MCP session `b5326241-58b0-4365-95aa-2284b04eb3cb` confirmed one `0x52`-byte function at `0x00430040-0x00430092`, false internal starts at `0x00430041` and `0x00430058`, no function at `0x00430092`, five `sub_42F870` callsites, callees `0x0041d3b0`, `0x00437470`, and `0x0043f3f0`, staged `json_writer.cpp` line 539 as `Json::StyledWriter::pushValue(JSONCPP_STRING const&)`, no product owner/caller route, no handwritten C++ route, and no merge into neighboring JsonCpp writer pages.
- 2026-07-04 B004 [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) source-quality incorporation: converted the legacy writer core from a blank empty-emitter marker to the formal validator inline import directive for staged `json_writer.cpp`, `json_tool.h`, and public JsonCpp headers; recorded current MCP session `73c77998`, raw constructor and jump-table evidence, no-xref/no-pointer-route caps, staged source hashes/anchors, and preserved [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) as a separate successor.
- 2026-06-27 B008 [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md) source-quality incorporation: recorded current MCP-backed `json_reader.cpp` / `json_writer.cpp` subrange mapping, formal import directive with both source files plus required headers, blank multiline block handling, and the preserved [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md) boundary at `0x0042e850`.
- 2026-06-27 B001 [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) split-index implementation: recorded current MCP session `80de0a67`, exact `0x004353c0` boundary, reader child [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md), writer child [UID:00048C][0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers](by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md), corrected raw helper/table inventory (`0x00434db0`, `0x00434e30`, `0x00434e50`, `0x00435ed0`, `0x00436180`, `jpt_4350AB`, `jpt_4355B0`), staged source hashes/anchors, and current validator inline import-directive policy.
- 2026-06-27 B001 `000TP` import-directive callback: added current formal import policy. Converted source-bearing `json_reader.cpp` / `json_writer.cpp` child pages to validator inline import directives with blank multiline blocks; left [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) blank and documented the `json_valueiterator.inl` validator-extension blocker.
- 2026-06-27 B013 JsonCpp valid-writer-key helper incorporation: added [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md) evidence for the `sub_441D30` range, `StreamWriterBuilder::validate` caller at `0x0042ee8c`, six writer-key strings, staged `json_writer.cpp` / `writer.h` static-embed hash match, padding to the `0x00442090` writer/runtime tail, and marker-only `json_writer.cpp` formal C++ policy under the existing JsonCpp source route.
- 2026-06-27 B014 JsonCpp number-token helper incorporation: updated [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) from generic number-token helper wording to exact `Json::OurReader::decodeDouble(Token&, Value&)` identity, with MCP `80de0a67` caller-edge/source-line/hash evidence and the formal `json_reader.cpp` validator import directive. Source snapshot remains commit `b299d3581f4dc670734f1fe1a34fce1282337802`; no exact release-tag claim was introduced.
- 2026-06-27 B012 JsonCpp valid-reader-key helper incorporation: scores unchanged. Added [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md) evidence for the `sub_4417E0` range, `CharReaderBuilder::validate` caller, ten reader-key strings, staged `json_reader.cpp` SHA-256, and static-embed marker under the existing JsonCpp source route.
- 2026-06-24 B001 JsonCpp writer/reader source-file split: superseded the old single [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) mixed-aggregate statement. Current MCP session `80de0a67` confirms the `0x00431c00` `json_writer.cpp` / `json_reader.cpp` boundary, local writer jump and escape tables, raw `OurFeatures::all()`, no product-owner route, and no pointer route for raw/zero-xref starts. The parent is now a non-emitting index; [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md) and [UID:000380][0x00431c00-0x00431d50.JsonCppOurReaderPrelude](by-memory/0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md) carry validator inline import directives for `json_writer.cpp` and `json_reader.cpp`. Source snapshot and path remain `NexusTK/third_party/jsoncpp/`.
- 2026-06-23 B005 JsonCpp parse-front-end source-quality incorporation: added the current [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) `80de0a67` MCP source map for the legacy `Json::Reader` constructors, parse overloads, error/token/comment helpers, raw retained `getFormatedErrorMessages` and `skipSpaces` bodies, token/switch table bytes, no-xref STL island, and product-consumer boundary. Source root remains `NexusTK/third_party/jsoncpp/`; static embed/no-handwritten-C++ policy unchanged.
- 2026-06-24 B005 [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) incorporation: added the current `80de0a67` MCP source map for the builder-era `Json::OurReader::parse` method, its `OurCharReader::parse` vtable wrapper route, value/comment-token callees, fail-if-extra and strict-root source discriminators, staged `json_reader.cpp` hash/source-match evidence, and the source-bearing validator import-directive policy. Product callers remain consumers, not owners.
- 2026-06-21 B010 Rule 26 incorporation: Scores unchanged. Added [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) as consumed SSO-15 compiler/runtime support rather than JsonCpp source, despite many JsonCpp callers. This preserves vendored JsonCpp source as `JSONCPP_STRING` / `std::string` operations and rejects direct helper ownership by JsonCpp.
- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/third_party/jsoncpp/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented JsonCpp anchors at `0x00424630` and `0x00431d50`; the existing source-structure decision places the parser/writer implementation under the vendored `third_party/jsoncpp/` folder, not under cash-shop, downloader, or other product modules.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:92` and `CONFIDENCE:88`.
  - Summary/evidence: JsonCpp identity, version narrowing to official commit `b299d3581f4dc670734f1fe1a34fce1282337802`, memory islands, product handoff, source layout, staged archive/static embed state, and rebuild strategy are documented in detail; confidence is capped by remaining lower-helper comparison and final per-function name mapping across the full library.
