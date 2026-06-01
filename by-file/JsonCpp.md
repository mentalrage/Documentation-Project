*** UID:0000KI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# JsonCpp

## Status

- Confidence: strong for JsonCpp identity; high for the current upstream snapshot candidate. The best current source match is official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802`, between tags `1.7.4` and `1.7.5`.
- Proposed module: `third_party/jsoncpp/`
- Evidence basis: read-only IDA MCP string/xref/decompile checks on 2026-05-25, local candidate archives in [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md), the current `source-3/third_party_embeds/jsoncpp` static embed, generated `source-3/simroot_v2/third_party/jsoncpp`, official upstream source/history checks for `1.7.0-1.7.7` and commit `b299d3581f4dc670734f1fe1a34fce1282337802`, existing cash-shop/download docs, and official JsonCpp integration notes. `wave3.py` was not executed for this pass.

## File Role

This is statically linked JsonCpp parser/writer support code. It should stay separate from NexusTK feature modules that consume JSON data, such as cash-shop/item-shop metadata.

Project modules should own URLs, downloader flow, catalog interpretation, and UI state. JsonCpp should own JSON parse/serialize support.

## Evidence

- IDA strings include JsonCpp parser/settings names at `0x0060e75c-0x0060e7f8`: `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, and `allowSpecialFloats`.
- IDA strings include `Json::Value` diagnostics such as `in Json::Value::asCString(): requires stringValue`, `in Json::Value::resize(): requires arrayValue`, `in Json::Value::getMemberNames(), value must be objectValue`, `duplicateStringValue`, and `duplicateAndPrefixStringValue`; [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) now anchors the main value/object helper island.
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) covers the adjacent `__crt_strtox::big_integer`, `Json::Value::setComment()`, `Json::Path`/`PathArgument`, and iterator-support island immediately before the document parse front ends.
- [UID:0000WX][0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md) cover the no-xref raw helper island immediately before the modeled `Json::Exception` constructor family.
- IDA RTTI-ish strings identify `Json::Exception`, `Json::RuntimeError`, `Json::LogicError`, `Json::FastWriter`, `Json::StyledWriter`, `Json::CharReader`, `Json::CharReader::Factory`, `Json::CharReaderBuilder`, `Json::OurCharReader`, `Json::StreamWriter`, `Json::StreamWriter::Factory`, `Json::StreamWriterBuilder`, and `Json::BuiltStyledStreamWriter`.
- Parser diagnostic xrefs show two reader families: [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md), with examples including `Exceeded stackLimit in readValue().` referenced from `0x0042ae90`, object separator/colon diagnostics from `0x0042b120`, and string-escape diagnostics from `0x0042bfc0`; and [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) plus [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md), with matching `OurReader` token/comment/error helpers and duplicate-key diagnostics from `0x004331f0`.
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) covers raw helper bodies immediately before the modeled reader/builder island; source comparison maps them to legacy `Json::Reader` C-style comment, C++-style comment, string, and number scanners.
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) immediately follows the second parser island and references `Unable to parse token length`, the current strongest `1.7.x`-over-`0.10.6` version-family discriminator.
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) continues the JsonCpp island with `OurReader` unicode/error/comment helpers and `BuiltStyledStreamWriter` stream serialization helpers, including a raw `hasCommentForValue` body at `0x00436180`.
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md) follows as MSVC/Dinkumware STL and iostream support heavily used by JsonCpp and other standard-library callers; it should come from the compiler/runtime rather than JsonCpp or NexusTK handwritten source.
- [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md) records a non-contiguous JsonCpp `Value` cleanup tail chunk assigned by IDA to `sub_427310`; it is third-party/compiler cleanup support, not a Deque or NexusTK product method.
- [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md) records the following MSVC/Dinkumware string, stream, locale, exception, and numeric conversion support island used by JsonCpp and other runtime callers.
- [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md) continues the ignored support area with Dinkumware runtime helpers plus JsonCpp `duplicateAndPrefixStringValue` and `duplicateStringValue` allocation helpers before the valid-key helper island.
- [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md) documents the JsonCpp writer/runtime tail after valid writer keys, including JSON escape/special-float formatting support and an embedded lookup table before LodePNG begins.
- Builder/settings xrefs include `collectComments`, `allowDroppedNullPlaceholders`, and `allowSpecialFloats` from settings/build helpers at `0x0042d380`, `0x0042db90`, `0x0042def0`, and the [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md) helper at `0x004417e0`.
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md) covers the writer settings/factory/defaults range. It reads and validates `indentation`, `commentStyle`, `enableYAMLCompatibility`, `dropNullPlaceholders`, `useSpecialFloats`, and `precision`, then allocates the `BuiltStyledStreamWriter`-style object.
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) covers the retained `Writer`/`FastWriter`/`StyledWriter` implementation family; [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) covers the following `StyledWriter::pushValue`-style helper and rejects the false Exchange/ClanBank owner starts; [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) maps the remaining `StyledWriter`/`StyledStreamWriter` tail, writer scalar/string helpers, stream insertion helper, and the `OurReader` constructor prelude before `0x00431d50`.
- Known product handoff: [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) calls [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) at `0x004298f0` and `0x00429b30`, then uses JsonCpp value helpers to read `version` and item-shop category arrays.
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
- [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md)
- [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md)
- [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md)
- [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md)
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md)
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md)
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md)
- [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md)
- [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md)
- [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md)
- [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md)
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md)
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md)
- [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md)
- [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md)
- [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md)
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md)
- [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md)
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:92` and `CONFIDENCE:88`.
  - Summary/evidence: JsonCpp identity, version narrowing to official commit `b299d3581f4dc670734f1fe1a34fce1282337802`, memory islands, product handoff, source layout, staged archive/static embed state, and rebuild strategy are documented in detail; confidence is capped by remaining lower-helper comparison and final per-function name mapping across the full library.
