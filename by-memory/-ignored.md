*** UID:0000VN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

## Description ##
Use this file to mark confirmed memory ranges that can be safely ignored for NexusTK source reconstruction. Verify all ranges completely before adding them here. Do not blanket-add large ranges without checking every included function/data span.

## What Belongs Here

- MSVC CRT/STL/Dinkumware support code and compiler helper thunks.
- Third-party library/runtime code that should be obtained or linked separately, such as zlib, IJG libjpeg, LodePNG, JsonCpp, Bink, Miles, libcurl, or Windows SDK/import glue.
- Exception-handling, RTTI, allocator, security-cookie, and compiler-generated support ranges when they are not project-owned logic.
- Confirmed duplicate/raw ranges that should not drive reconstruction after a better exact owner/range is documented elsewhere.

## Entry Standard

For each ignored range, include:

- exact start/end address range;
- why the range is ignored;
- evidence source, preferably IDA MCP plus local archive/source comparison when applicable;
- replacement/procurement path if the code comes from third-party source or runtime files;
- cross-reference to the active owner docs, data issue, or library page.

## Ignored Ranges

- `0x00493f7a-0x00493f80`, `0x0049ce49-0x0049ce50`, and `0x0058498c-0x00584990` - SimpleUStringVector helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans immediately after the exact `SimpleUStringVector` destructor, grow/insert, and push-back helper functions; not standalone project logic.
  - Evidence: IDA MCP byte check on 2026-05-31 shows each listed span is all `0xcc`; `lookup_funcs` confirms the preceding functions have sizes ending at `0x00493f79`, `0x0049ce48`, and `0x0058498b` respectively.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000DA][SimpleUStringVector](by-class/SimpleUStringVector.md), [UID:0001W6][SimpleUStringVectorLayout](by-type/by-struct/SimpleUStringVectorLayout.md), [UID:000112][0x00493f10-0x00493f79.SimpleUStringVectorDestructor](by-memory/0x00493f10-0x00493f79.SimpleUStringVectorDestructor.md), [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md), and [UID:0001J4][0x00584910-0x0058498b.SimpleUStringVectorPushBack](by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md).

- `0x00504090-0x00504093` - unreferenced no-op/dead stub between MapPane effect-list helpers.
  - Why ignored: the range is a real one-instruction function, but current evidence shows no caller, data reference, or pointer table entry requiring it in reconstructed source.
  - Evidence: IDA MCP `lookup_funcs` reports `nullsub_40` size `0x03`; `disasm` shows the only instruction is `retn 4`; `decompile` returns an empty `void __stdcall nullsub_40(int)`; `xrefs_to` and `idautils.XrefsTo` find no callers or data refs; an all-segment search for pointer bytes `90 40 50 00` found no hits.
  - Replacement/procurement: none. Keep ignored unless future table/caller evidence proves it is source-required.
  - Owner docs: adjacent reconstructable helpers are [UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md) and [UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md).

- `0x0046396e-0x00463970`, `0x00465115-0x00465120`, `0x00465124-0x00465130`, `0x004651b8-0x004651c0`, `0x004651c4-0x004651d0`, `0x004651d7-0x004651e0`, `0x004651e7-0x004651f0`, `0x004652dc-0x004652e0`, `0x004652fc-0x00465300`, `0x00465308-0x00465310`, `0x00465318-0x00465320`, and `0x00465424-0x00465430` - Application local helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans between exact source-authored Application helper/accessor functions; not standalone project logic.
  - Evidence: IDA MCP `get_bytes` on 2026-05-31 confirms the helper/accessor gaps are all `0xcc` bytes; IDA MCP `disasm` and `py_eval` on 2026-06-01 confirm `0x0046396e-0x00463970` is the `0xcc 0xcc` constructor/destructor alignment gap. Neighboring functions are documented as exact child pages under [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000HG][Application](by-file/Application.md), [UID:00000D][Application](by-class/Application.md).

- `0x005b3483-0x005b3490`, `0x005b34cf-0x005b34d0`, `0x005b356c-0x005b3570`, and `0x005b37ea-0x005b37f0` - SayInputPane neighborhood alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans around exact raw/confirmed `SayInputPane` bodies and the preceding raw spell-slot packet helper; not standalone project logic.
  - Evidence: IDA MCP byte/disassembly audit on 2026-06-02 confirms [UID:0002S6][0x005b3410-0x005b3483.ChangeSpellSlotPacketRawSender](by-memory/0x005b3410-0x005b3483.ChangeSpellSlotPacketRawSender.md) ends at `0x005b3483`, [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) has a one-byte tail pad at `0x005b34cf`, `sub_5B34D0` ends at `0x005b356c`, and `sub_5B3670` ends at `0x005b37ea` before raw adjacent `ChatInputPane` constructor-shaped bytes.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000C3][SayInputPane](by-class/SayInputPane.md), [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md), and [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md).

- `0x005b38d5-0x005b38e0`, `0x005b3935-0x005b3940`, and `0x005b3bba-0x005b3bc0` - ChatInputPane neighborhood alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans around exact raw/confirmed `ChatInputPane` bodies; not standalone project logic.
  - Evidence: IDA MCP byte/disassembly audit on 2026-06-02 confirms [UID:0002S8][0x005b37f0-0x005b38d5.ChatPacketRawSender](by-memory/0x005b37f0-0x005b38d5.ChatPacketRawSender.md) ends at `0x005b38d5`, [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md) has tail alignment at `0x005b3935-0x005b3940`, and `sub_5B3A40` ends at `0x005b3bba` before the adjacent raw helper at `0x005b3bc0`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md), [UID:0001MC][0x005b3940-0x005b3bba.ChatInputPane](by-memory/0x005b3940-0x005b3bba.ChatInputPane.md), and [UID:0002S9][0x005b38e0-0x005b3940.ChatInputPaneRawConstructor](by-memory/0x005b38e0-0x005b3940.ChatInputPaneRawConstructor.md).

- `0x004d02e5-0x004d02f0`, `0x004d039e-0x004d03a0`, `0x004d0522-0x004d0530`, `0x004d059b-0x004d05a0`, `0x004d05e6-0x004d05f0`, `0x004d1773-0x004d1780`, and `0x004d17b3-0x004d17c0` - ResourceLayoutTable helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans between exact ResourceLayoutTable/helper functions; not standalone project logic.
  - Evidence: IDA MCP `py_eval` byte audit on 2026-05-31 confirmed each listed span consists only of `0xcc` bytes while enumerating the child functions under [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md).

- `0x004d15c5-0x004d15d0`, `0x004d15fc-0x004d1600`, and `0x004d165d-0x004d1660` - ImageFrameTable helper-neighborhood alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans between exact source-authored helpers; not standalone project logic.
  - Evidence: IDA MCP `lookup_funcs` and `py_eval` byte audit on 2026-06-01 confirmed `sub_4D0F50` ends at `0x004d15c5`, `sub_4D15D0` covers `0x004d15d0-0x004d15fc`, `sub_4D1600` covers `0x004d1600-0x004d165d`, and the listed intervening bytes are all `0xcc`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md), [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md), [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md), and [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md).

- `0x00401000-0x00414283` - IJG libjpeg 6b static library core.
  - Why ignored: third-party codec implementation, not NexusTK product source.
  - Evidence: [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) maps this span to stock IJG libjpeg 6b source modules and explicitly ends before the Miles shutdown glue at `0x00414290`.
  - Replacement/procurement: [static_embeds/libjpeg-6b](../by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000KN][LibJPEG](by-file/LibJPEG.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00414290-0x004142b5` - Miles shutdown thunk / `atexit` glue.
  - Why ignored: dynamic Miles runtime support glue adjacent to libjpeg, not NexusTK product logic and not part of IJG libjpeg.
  - Evidence: [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) excludes this exact neighbor before zlib starts at `0x004142c0`; [UID:0001QE][client_libraries](by-meta/client_libraries.md) records Miles as a runtime dependency.
  - Replacement/procurement: [runtime_from_local_client/Mss32.dll](../by-meta/obtained_thirdparty_files/runtime_from_local_client/Mss32.dll) and [runtime_from_local_client/Mp3dec.asi](../by-meta/obtained_thirdparty_files/runtime_from_local_client/Mp3dec.asi), or a licensed RAD/Epic Miles package.
  - Owner docs: [UID:0001Q8][client_audio](by-meta/client_audio.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00414283-0x00414290` and `0x004142b5-0x004142c0` - alignment padding around Miles shutdown glue.
  - Why ignored: confirmed empty/padding spans; not executable product logic.
  - Evidence: IDA MCP byte/xref pass on 2026-05-27 shows both spans consist only of `0x90` bytes, decode as `align 10h`, have no function object, no xrefs to the start, and no xrefs from the bytes.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001Q8][client_audio](by-meta/client_audio.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x004142c0-0x00419e56` - zlib 1.1.4 static library core.
  - Why ignored: third-party compression/checksum implementation, not NexusTK product source.
  - Evidence: [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md), [UID:0000W4][0x00414820-0x00417b97.ZlibDeflateAndTrees](by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), and [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) map this span to stock zlib source-file families.
  - Replacement/procurement: [static_embeds/zlib-1.1.4](../by-meta/obtained_thirdparty_files/static_embeds/zlib-1.1.4/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000PC][Zlib](by-file/Zlib.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00419e56-0x00419ee0` - static initializer wrappers before OLE startup support.
  - Why ignored: compiler/static-initialization and `atexit` wrapper island with alignment padding; not standalone handwritten product logic.
  - Evidence: [UID:0000W7][0x00419e56-0x00419ee0.StaticInitializerWrappersPreOle](by-memory/0x00419e56-0x00419ee0.StaticInitializerWrappersPreOle.md) records IDA MCP byte/function audit, decompilation, and startup table xrefs at `0x0060d694-0x0060d6a0`.
  - Replacement/procurement: declare the underlying static objects/globals near their true owner modules; compiler static initialization should emit equivalent wrapper code.

- `0x00419ef4-0x00419f70` - static initializer wrappers after OLE startup support.
  - Why ignored: compiler/static-initialization and `atexit` wrapper island with alignment padding; not standalone handwritten product logic.
  - Evidence: [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) records IDA MCP byte/function audit, decompilation, and startup table xrefs at `0x0060d6a8-0x0060d6bc`.
  - Replacement/procurement: declare the underlying static objects/globals near their true owner modules; compiler static initialization should emit equivalent wrapper code.

- `0x00419f86-0x0041a040` - static initializer wrappers before PoolAllocator static constructor wrappers.
  - Why ignored: compiler/static-initialization and `atexit` wrapper island with alignment padding; not standalone handwritten product logic.
  - Evidence: [UID:0000WB][0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators](by-memory/0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators.md) records IDA MCP byte/function audit, decompilation, and startup table xrefs at `0x0060d6b8-0x0060d6d0`.
  - Replacement/procurement: declare the underlying static objects/globals near their true owner modules; compiler static initialization should emit equivalent wrapper code.

- `0x0041b9a0-0x0041b9de` - CRT local stdio options accessor and secure wide-formatting wrapper.
  - Why ignored: CRT/UCRT support glue that returns local stdio option storage at `0x0067a730` and forwards varargs wide formatting to `__stdio_common_vswprintf_s`; it is not NexusTK product logic.
  - Evidence: [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md) records IDA MCP decompilation for both `sub_41B9A0` and `sub_41B9B0`.
  - Replacement/procurement: MSVC/UCRT runtime behavior; reconstructed source should use normal secure formatting APIs rather than modeling this as a project-owned function.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).

- `0x00424630-0x00428b4b` - JsonCpp value/object core.
  - Why ignored: third-party JsonCpp value support, not fitting-room, downloader, or cash-shop product source.
  - Evidence: [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) ties the span to `Json::Value` diagnostics, value construction/destruction, object/member lookup, array access, and the current best upstream snapshot.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00428b4b-0x004298f0` - JsonCpp value/path/iterator and CRT numeric support.
  - Why ignored: mixed third-party JsonCpp support and MSVC CRT `__crt_strtox` helper fragments, not NexusTK product source.
  - Evidence: [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) records IDA MCP evidence for `__crt_strtox::big_integer`, `Json::Value::setComment()`, `Json::Path`/`PathArgument`-style syntax processing, and JsonCpp iterator diagnostics.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/) plus compatible MSVC CRT support.
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x004298f0-0x0042acdf` - JsonCpp document construction and parse front ends.
  - Why ignored: third-party JsonCpp parser API/support code; product modules only consume it.
  - Evidence: [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) records direct product callers and the parser-support chain while retaining JsonCpp ownership.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x0042acdf-0x0042ae90` - JsonCpp legacy `Reader` raw lexical helpers.
  - Why ignored: third-party JsonCpp lexer/comment/string/number scanner code, not NexusTK product source.
  - Evidence: [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) records IDA MCP disassembly and source comparison for `Json::Reader::readCStyleComment`, `readCppStyleComment`, `readString`, and `readNumber`-style helpers.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x0042ae90-0x0042f3f0` - JsonCpp reader/builder and stream-writer-builder island.
  - Why ignored: third-party JsonCpp parser/builder/writer infrastructure.
  - Evidence: [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md) and [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md) tie the combined contiguous span to JsonCpp reader, `CharReaderBuilder`, and `StreamWriterBuilder` support. The overlap at `0x0042e850-0x0042edeb` is intentional; the second page refines the writer-builder portion.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x0042f3f0-0x00430040` - JsonCpp legacy writer core.
  - Why ignored: third-party JsonCpp `Writer`/`FastWriter`/`StyledWriter` serialization code, not NexusTK product source.
  - Evidence: [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) records IDA MCP vtable, decompile, caller/callee, and staged `json_writer.cpp` source comparison evidence.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00430040-0x00430092` - JsonCpp writer push helper.
  - Why ignored: third-party JsonCpp `StyledWriter::pushValue`-style helper, not NexusTK product source.
  - Evidence: [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) records IDA MCP decompile/caller evidence showing only JsonCpp writer-family callers from `0x0042f870`.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00430092-0x00431d50` - JsonCpp writer tail and OurReader prelude.
  - Why ignored: third-party JsonCpp `StyledWriter`/`StyledStreamWriter` tail helpers, scalar/string writer helpers, stream insertion helper, and `OurReader` constructor prelude, not NexusTK product source.
  - Evidence: [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) records IDA MCP function listing, manual raw-code disassembly, writer literal/xref evidence, and staged `json_writer.cpp`/`json_reader.cpp` comparison.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00431d50-0x00431f1c` - JsonCpp `OurReader::parse`-style front end.
  - Why ignored: third-party parser method, not item-shop/fitting-room product logic.
  - Evidence: [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) matches JsonCpp parser diagnostics and version discriminators.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00431f1c-0x00431f20` - alignment padding between JsonCpp parser helpers.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_431D50` ending at `0x00431f1c`, the next real helper beginning at `0x00431f20`, and four `0xcc` bytes between them.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md), [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md).

- `0x00431f20-0x00432e10` - JsonCpp `OurReader` error/token helper island.
  - Why ignored: third-party JsonCpp parser implementation and adjacent MSVC STL helper, not NexusTK product logic.
  - Evidence: [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) maps the range to `OurReader::getFormattedErrorMessages`, `getStructuredErrors`, `pushError`, `readToken`, `match`, `readComment`, `readCStyleComment`, `readCppStyleComment`, `readString`, and `readStringSingleQuote`-style helpers using IDA MCP and staged source comparison.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00432e10-0x00434887` - JsonCpp second parser island and number-token helper.
  - Why ignored: third-party JsonCpp parser implementation.
  - Evidence: [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md) and [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) tie the span to JsonCpp reader diagnostics, duplicate-key handling, and numeric-token parsing.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00434887-0x00434890` - alignment padding after the JsonCpp number-token parse helper.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_4345F0` ending at `0x00434887`, `sub_434890` beginning at `0x00434890`, and three `0xcc` bytes between them.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md), [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md).

- `0x00434890-0x004361ae` - JsonCpp `OurReader` unicode/error/comment helpers and `BuiltStyledStreamWriter` helpers.
  - Why ignored: third-party JsonCpp parser/writer implementation, not NexusTK product logic.
  - Evidence: [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) maps the range to `OurReader::decodeUnicodeCodePoint`, `decodeUnicodeEscapeSequence`, `addError`, `recoverFromError`, location/comment helpers, and `BuiltStyledStreamWriter::write`, `writeValue`, `writeArrayValue`, `isMultineArray`, comment writers, and raw `hasCommentForValue` bytes using IDA MCP and staged source comparison.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x004361ae-0x004361b0` - alignment padding after raw JsonCpp `BuiltStyledStreamWriter::hasCommentForValue` bytes.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 shows raw helper bytes at `0x00436180-0x004361ae`, followed by two `0xcc` bytes before the modeled `sub_4361B0` function at `0x004361b0`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md).

- `0x004361b0-0x00439df9` - MSVC/Dinkumware STL, iostream, locale, exception, string, and map/set support island.
  - Why ignored: compiler/runtime and standard-library template support, not NexusTK product logic.
  - Evidence: [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md) records the 63-function IDA MCP inventory and standard-library diagnostics including `ios_base::badbit set`, `ios_base::failbit set`, `ios_base::eofbit set`, `map/set<T> too long`, and `bad locale name`.
  - Replacement/procurement: selected MSVC-era compiler/runtime and normal C++ standard-library/template instantiation; do not hand-port as NexusTK source.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000KI][JsonCpp](by-file/JsonCpp.md).

- `0x00439df9-0x00439e00` - alignment padding before project `DequeDestroy`.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_439CF0` ending at `0x00439df9`, seven `0xcc` bytes through `0x00439e00`, and [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) beginning at `0x00439e00`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md), [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md).

- `0x00439ea3-0x00439eb0` - alignment padding after project `DequeDestroy`.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_439E00` ending at `0x00439ea3`, followed by 13 `0xcc` bytes before the out-of-line JsonCpp cleanup tail chunk at `0x00439eb0`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md), [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md).

- `0x00439eb0-0x00439ed5` - JsonCpp `Value` helper EH cleanup tail chunk.
  - Why ignored: third-party JsonCpp/compiler cleanup support, not NexusTK product logic.
  - Evidence: [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md) records that IDA assigns this non-contiguous chunk to JsonCpp value helper `sub_427310`, with xrefs from out-of-line EH/unwind jumps at `0x005f7417`, `0x005f7716`, and `0x005f7770`.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/) plus selected MSVC-era compiler/runtime.
  - Owner docs: [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md), [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00439ed5-0x00439ee0` - alignment padding before the next runtime support island.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports the JsonCpp cleanup tail chunk returning at `0x00439ed4`, followed by `0xcc` alignment bytes through `0x00439ee0`, where `sub_439EE0` begins.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZU][0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk](by-memory/0x00439eb0-0x00439ed5.JsonCppValueCoreEhCleanupChunk.md), [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md).

- `0x00439ee0-0x0043e0a3` - MSVC/Dinkumware STL, iostream, locale, exception, string, and numeric conversion support island.
  - Why ignored: compiler/runtime and standard-library template support, not NexusTK product logic.
  - Evidence: [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md) records the 80-function IDA MCP inventory and standard-library diagnostics/constants including `ios_base::badbit set`, `ios_base::failbit set`, `0123456789-+Ee`, `0123456789ABCDEFabcdef-+XxPp`, and the decorated `std::basic_string::append` helper.
  - Replacement/procurement: selected MSVC-era compiler/runtime and normal C++ standard-library/template instantiation; do not hand-port as NexusTK source.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000KI][JsonCpp](by-file/JsonCpp.md).

- `0x0043e0a3-0x0043e0b0` - alignment padding before project `DequeEnsureCapacity`.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_43E090` ending at `0x0043e0a3`, followed by 13 `0xcc` bytes before [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md), [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md).

- `0x0043e241-0x0043e250` - no-xref filler/alignment after project `DequeEnsureCapacity`.
  - Why ignored: filler/alignment bytes after a project method, not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-31 reports `sub_43E0B0` ending at `0x0043e241`, followed by `0xcc` alignment bytes through `0x0043e250`, where `sub_43E250` begins.
  - Replacement/procurement: none; compiler/linker alignment/filler.
  - Owner docs: [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md), [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md).

- `0x0043e250-0x004417dd` - MSVC/Dinkumware and JsonCpp string/runtime support island.
  - Why ignored: mixed compiler/runtime, standard-library, and third-party JsonCpp support, not NexusTK product logic.
  - Evidence: [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md) records the 70-function IDA MCP inventory, Dinkumware diagnostics/decorated names, and JsonCpp value string-allocation diagnostics.
  - Replacement/procurement: selected MSVC-era compiler/runtime and [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000KI][JsonCpp](by-file/JsonCpp.md).

- `0x004417dd-0x004417e0` - alignment padding before JsonCpp valid-reader-key helpers.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_4416E0` ending at `0x004417dd`, followed by three `0xcc` bytes before [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md), [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md).

- `0x004417e0-0x00442084` - JsonCpp valid reader/writer key helpers.
  - Why ignored: third-party builder validation helpers.
  - Evidence: [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md) and [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md) match upstream `getValidReaderKeys` and `getValidWriterKeys`.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00442084-0x00442090` - alignment padding after JsonCpp valid writer keys.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports twelve `0xcc` bytes after [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md) and before `sub_442090` at `0x00442090`.
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md), [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md).

- `0x00442090-0x00443a55` - JsonCpp writer/runtime tail support before LodePNG.
  - Why ignored: mixed third-party JsonCpp writer support and MSVC/Dinkumware/CRT runtime support, not NexusTK product logic.
  - Evidence: [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md) records the 40-function IDA MCP inventory, stream/runtime diagnostics, JsonCpp writer escape/special-float strings, and embedded lookup/table block.
  - Replacement/procurement: selected MSVC-era compiler/runtime and [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00443a55-0x00443a60` - alignment padding before LodePNG helper island.
  - Why ignored: confirmed `0xcc` alignment padding; not executable product logic.
  - Evidence: IDA MCP byte/function check on 2026-05-27 reports `sub_443A30` ending at `0x00443a55`, followed by eleven `0xcc` bytes before [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md), [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md).

- `0x00430041-0x00430065` and `0x00430058-0x00430067` - false generated feature-method starts inside `sub_430040`.
  - Why ignored: these ranges are generated owner artifacts, not valid standalone methods. `0x00430041` starts one byte after the real function prologue, and `0x00430058` starts at an internal branch target that depends on the stack/register setup from `0x00430040`.
  - Evidence: [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) records IDA MCP lookup/decompile/xref evidence, including the false `ExchangeMoneyEditControlPane::GetClassName` and `ClanBankItemListPane::AppendEntryString` starts.
  - Replacement/procurement: no product source replacement; real helper is JsonCpp writer support from the staged third-party source.
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md), [UID:000025][ClanBankItemListPane](by-class/ClanBankItemListPane.md), [wave3 data issues](../wave3_data_issues.md).

- `0x00443a60-0x00450c9f` - LodePNG 20160501 helper island.
  - Why ignored: bundled third-party PNG encoder implementation. Exact per-helper names are still being refined, but current evidence keeps this bounded island out of NexusTK product modules.
  - Evidence: [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md) narrows the island and excludes the MiniMap/product-code tail beginning at `0x00450ca0`; [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md), [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md), [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md), [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md), and [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md) provide confirmed anchors.
  - Replacement/procurement: [static_embeds/lodepng-20160501](../by-meta/obtained_thirdparty_files/static_embeds/lodepng-20160501/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000KW][LodePNG](by-file/LodePNG.md), [UID:00007E][LodePNGState](by-class/LodePNGState.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00450c9f-0x00450ca0`, `0x0045381b-0x00453820`, `0x00453904-0x00453910`, `0x00453def-0x00453df0`, `0x004563b5-0x004563c0`, `0x0045709e-0x004570a0`, `0x004570a4-0x004570b0`, `0x00457547-0x00457550`, `0x0045757d-0x00457580`, `0x00457613-0x00457620`, and `0x00457a5d-0x00457a60` - MiniMap-adjacent alignment padding.
  - Why ignored: confirmed `0xcc` alignment padding between adjacent IDA functions or documented helper islands; not executable product logic.
  - Evidence: IDA MCP byte/function checks on 2026-05-27 report no xrefs or function bodies in most of these spans; IDA MCP disassembly on 2026-05-31 confirms `0x0045709e-0x004570a0` and `0x004570a4-0x004570b0` are alignment bytes around the MiniMapVersionManager accessor and lookup helper. Neighboring function ends were corrected where needed: `sub_4563B0` ends at `0x004563b5`, `sub_456A90` ends at `0x0045709e`, `sub_4570A0` ends at `0x004570a4`, `sub_4570B0` ends at `0x004570e0`, `sub_457480` ends at `0x00457547`, `sub_457550` ends at `0x0045757d`, and `sub_457580` ends at `0x00457613`. The real former UNKNOWN code spans are now documented as [UID:0001ZY][0x00453820-0x00453904.WideStringMapNodeSupport](by-memory/0x00453820-0x00453904.WideStringMapNodeSupport.md), [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md), [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md), and [UID:0001ZZ][0x00457620-0x00457a5d.MiniMapFileLoaderHelpers](by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md).
  - Replacement/procurement: none; compiler/linker alignment.
  - Owner docs: [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), [UID:0000XN][0x00453910-0x00453def.MiniMapDownloader](by-memory/0x00453910-0x00453def.MiniMapDownloader.md), [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), [UID:0000XP][0x004563c0-0x00457547.MiniMapVersionManager](by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md), [UID:0000XW][0x00457550-0x0045757d.CreateListNode](by-memory/0x00457550-0x0045757d.CreateListNode.md), and [UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md).

- `0x0045981b-0x00459830` - `RankingDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RankingDialog` scalar deleting destructor `0x00459840`; not handwritten ranking dialog behavior.
  - Evidence: [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RankingDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BM][RankingDialog](by-class/RankingDialog.md), [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).

- `0x0045bddd-0x0045bdf2` - `RankingEventListPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RankingEventListPane` scalar deleting destructor `0x0045be00`; not handwritten ranking list behavior.
  - Evidence: [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RankingEventListPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md), [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).

- `0x0045f0a8-0x0045f0bd` - `RankingRewardInfoDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RankingRewardInfoDialog` scalar deleting destructor `0x0045f0c0`; not handwritten reward-info dialog behavior.
  - Evidence: [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RankingRewardInfoDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md), [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).

- `0x0045f950-0x0045f97c` - `FormatWide64_45F950` fixed-size wide-formatting wrapper.
  - Why ignored: CRT/stdio varargs wrapper around `__stdio_common_vswprintf_s` with a fixed `0x40` wide-character destination bound; it is only formatting glue used by ranking drawing code.
  - Evidence: IDA MCP lookup reports `sub_45F950` size `0x2d`; decompilation forwards to `__stdio_common_vswprintf_s(*sub_41B9A0(), buffer, 0x40, format, 0, va)` and returns `-1` on negative results. Caller xrefs are the nine `RankingUserListPane::OnPaint` calls, and [UID:0000VO][-report.old](by-memory/-report.old.md) classifies it as non-reconstructable CRT/stdio support glue.
  - Replacement/procurement: MSVC/UCRT formatting support; final source can express the call sites as a local safe-format helper or direct `_snwprintf_s`/`vswprintf_s` use inside [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Owner docs: [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md), [wave3 data issues](../wave3_data_issues.md).

- `0x0045f97d-0x0045f992` - `RankingUserListPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RankingUserListPane` scalar deleting destructor `0x0045f9a0`; not handwritten ranking user-list behavior.
  - Evidence: [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RankingUserListPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).

- `0x004616c8-0x004616de` - `AboveFrame` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `AboveFrame` scalar deleting destructor `0x004616e0`; not handwritten frame-chrome behavior.
  - Evidence: [UID:0000YJ][0x004616c8-0x004616de.AboveFrameAdjustorThunks](by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md) records IDA MCP lookup/disassembly/xref evidence, and [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) records the owning vtables.
  - Replacement/procurement: no external dependency; generated by the compiler from the `AboveFrame` inheritance/vtable layout.
  - Owner docs: [UID:0000JL][FrameChrome](by-file/FrameChrome.md), [UID:000005][AboveFrame](by-class/AboveFrame.md), [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md).

- `0x0046178a-0x00461790`, `0x0046189b-0x004618a0`, `0x004619b8-0x004619c0`, `0x00461c07-0x00461c10`, `0x00461dc7-0x00461dd0`, `0x00461fd4-0x00461fe0`, `0x00462114-0x00462120` - AES helper island alignment padding.
  - Why ignored: confirmed `0xcc` alignment padding between adjacent AES helper functions and neighboring `AboveFrame` / `AlphaMaskSurface` code.
  - Evidence: IDA MCP raw byte checks on 2026-05-27 show these exact spans contain only `0xcc` bytes. The neighboring real code ranges are [UID:0000YH][0x004610f0-0x0046178a.AboveFrame](by-memory/0x004610f0-0x0046178a.AboveFrame.md), [UID:00020L][0x00461790-0x0046189b.AesCbcEncryptRaw](by-memory/0x00461790-0x0046189b.AesCbcEncryptRaw.md), [UID:00020M][0x004618a0-0x004619b8.AesCbcDecryptRaw](by-memory/0x004618a0-0x004619b8.AesCbcDecryptRaw.md), [UID:00020N][0x004619c0-0x00461c07.AesEncryptBlock](by-memory/0x004619c0-0x00461c07.AesEncryptBlock.md), [UID:00020O][0x00461c10-0x00461dc7.AesDecryptBlock](by-memory/0x00461c10-0x00461dc7.AesDecryptBlock.md), [UID:00020P][0x00461dd0-0x00461fd4.AesInvMixColumns](by-memory/0x00461dd0-0x00461fd4.AesInvMixColumns.md), [UID:00020Q][0x00461fe0-0x00462114.AesKeySchedule128](by-memory/0x00461fe0-0x00462114.AesKeySchedule128.md), and [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md).
  - Replacement/procurement: no source reconstruction required; generated by code alignment.
  - Owner docs: [UID:00020J][AesBlockCipher](by-file/AesBlockCipher.md), [UID:00020K][AesBlockCipherStateAndTables](by-global/AesBlockCipherStateAndTables.md).

- `0x00462230-0x00462258` - `IntAlphaSurface` EH/unwind cleanup fragment.
  - Why ignored: compiler-generated cleanup target for alpha-surface/view construction unwind; not a handwritten source method.
  - Evidence: [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) records IDA MCP raw disassembly, the `off_6112EC` vtable store at `0x00462237`, and the sole observed EH funclet jump from `0x005fa593`.
  - Replacement/procurement: no external dependency; generated by MSVC from normal `IntAlphaSurface`/alpha-surface object lifetime during `InitAlphaSurfaceView`-family construction.
  - Owner docs: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md).

- `0x00462161-0x00462170`, `0x00462e03-0x00462e10`, `0x00462f1e-0x00462f20`, `0x00463252-0x00463260`, `0x00463263-0x00463270`, `0x004632b1-0x004632c0`, and `0x0046330b-0x00463310` - alpha-surface helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment padding between adjacent alpha-surface, draw helper, nullsub, and application lifecycle functions.
  - Evidence: IDA MCP raw byte checks on 2026-05-27 show these exact spans contain only `0xcc` bytes. Boundary corrections include [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md), [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md), and [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md).
  - Replacement/procurement: no source reconstruction required; generated by code alignment.
  - Owner docs: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md), [UID:0000HG][Application](by-file/Application.md).

- `0x00463260-0x00463263` - `nullsub_24`.
  - Why ignored: IDA-modeled `retn 20h` nullsub with no direct xrefs and no stored function-pointer hits in the current database; not handwritten alpha-surface behavior.
  - Evidence: IDA MCP reports a function object `nullsub_24` at `0x00463260-0x00463263`, disassembling to `retn 20h`; `xrefs_to 0x00463260` and a loaded-dword scan for `0x00463260` both returned no hits on 2026-05-27.
  - Replacement/procurement: no source reconstruction required unless a later vtable/function-pointer pass finds a live owner.
  - Owner docs: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

- `0x00467b2d-0x00467b30` - BackPane/BalloonObjectPane alignment padding.
  - Why ignored: confirmed `0xcc` alignment padding after [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md) and before [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md).
  - Evidence: IDA MCP byte check on 2026-05-27 shows `0x00467b2d-0x00467b30` is `cc cc cc`; previous function `sub_467A80` ends at `0x00467b2d`, and `sub_467B30` begins at `0x00467b30`.
  - Replacement/procurement: no source reconstruction required; generated by code alignment.
  - Owner docs: [UID:0000HO][BackPane](by-file/BackPane.md), [UID:0000YY][0x00467510-0x00467b2d.BackPaneAndBackGroundPane](by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md), [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md).

- `0x0047e931-0x0047e947` - `NewPredefinedFormArticleDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `NewPredefinedFormArticleDialog` scalar deleting destructor `0x0047ec30`; not handwritten predefined-form article dialog logic.
  - Evidence: [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence and current disabled-output behavior. The broader [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) places this pair in the adjacent thunk strip.
  - Replacement/procurement: no external dependency; generated by the compiler from the `NewPredefinedFormArticleDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md), [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md), [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md).

- `0x0047e855-0x0047e931` - dialog, pane, session, exchange-list, alert, employee quantity, and mail secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into scalar deleting destructors for `ArticleDialog`, `ArticleListDialog`, list-pane variants, `BulletinDialog`, `ExchangeItemListPane`, `BulletinSession`, `TransferReplyAlert`, `EmployeeQuantityInputDialogPane`, `DeleteReplyAlert`, `MailDeleteReplyAlert`, and `MailDialog`; not handwritten project behavior.
  - Evidence: [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) records IDA MCP function enumeration, disassembly, vtable xrefs, and scalar-destructor target checks. Every function in this exact non-predefined subrange subtracts `0xa0` or `0xa4` from `ecx` and tail-jumps to the matching scalar deleting destructor.
  - Replacement/procurement: no external dependency; generated by the compiler from the owning class inheritance/vtable layouts.
  - Owner docs: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md), [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md), and [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).

- `0x0047ed20-0x0047ed50` - `ChangeMan` constructor cleanup/unwind fragment.
  - Why ignored: compiler-generated partial-construction cleanup for `ChangeMan::ChangeMan`; not a handwritten source method.
  - Evidence: [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) records IDA MCP disassembly, the vtable store at `0x0047ed26`, the `g_pChangeMan` clear at `0x0047ed3f`, and the tail jump to the `LObject` destructor before the real register method begins at `0x0047ed50`.
  - Replacement/procurement: no external dependency; generated by MSVC from normal `ChangeMan` construction, sorted-list ownership cleanup, and base-class destruction.
  - Owner docs: [UID:0000I2][ChangeMan](by-file/ChangeMan.md), [UID:00001K][ChangeMan](by-class/ChangeMan.md), [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md), [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md).

- `0x004b59d5-0x004b59eb` - `FolderTreePane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `FolderTreePane` scalar deleting destructor `0x004b5a70`; not handwritten filesystem tree-control logic.
  - Evidence: [UID:000159][0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks](by-memory/0x004b59d5-0x004b59eb.FolderTreePaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence and current disabled-output behavior.
  - Replacement/procurement: no external dependency; generated by the compiler from the `FolderTreePane` inheritance/vtable layout.
  - Owner docs: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md).

- `0x0061a5c4-0x0061a5dc` - `FolderTreePane` `TREEICON.EPF` UTF-16 string data misread as virtual slots.
  - Why ignored: this data begins immediately after the `FolderTreePane` tertiary vtable. Its dwords decode to address-like values `0x00520054`, `0x00450045`, and `0x00430049`, causing false generated virtual rows such as `virt_meth_0x450045` and `virt_meth_0x430049`.
  - Evidence: [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md) records IDA vtable-slot boundaries, xrefs to the `TREEICON.EPF` string from constructor/root-name code, and the false tail interpretation.
  - Replacement/procurement: keep this as a local icon resource-name string consumed by `FolderTreePane`; do not reconstruct virtual methods from the string dwords. Do not ignore the unrelated real code functions that contain addresses `0x00430049`, `0x00450045`, or `0x00520054`.
  - Owner docs: [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md), [UID:00005A][FolderTreePane](by-class/FolderTreePane.md), [UID:0001XL][FolderTreePaneVtables](by-type/by-vtable/FolderTreePaneVtables.md).

- `0x00613a1e-0x00613a20` - Browser/Dialog string boundary zero padding.
  - Why ignored: confirmed two zero bytes between the shared UTF-16 `OK` dialog button string and the browser alert string block; no source behavior or standalone data item.
  - Evidence: 2026-05-28 IDA MCP `py_eval` byte dump for `0x00613a1e-0x00613a20` reports bytes `00 00` in `.rdata`, with neighboring documented strings at `0x00613a18-0x00613a1e` and `0x00613a20-0x00613ab0`.
  - Replacement/procurement: compiler/linker/string-literal alignment or terminator padding; no source-level declaration needed.
  - Owner docs: [UID:0001OC][0x00613a18-0x00613a1e.DialogOkButtonString](by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md), [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x004b6c2b-0x004b6c41` - `FpsPane` secondary/timer-view destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `FpsPane` scalar deleting destructor `0x004b6c50`; not handwritten FPS diagnostics behavior.
  - Evidence: [UID:00015K][0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks](by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0061a66c` and `0x0061a69c`, and both thunks forward into `0x004b6c50`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `FpsPane` inheritance/vtable layout.
  - Owner docs: [UID:0000JK][FpsPane](by-file/FpsPane.md), [UID:00005F][FpsPane](by-class/FpsPane.md), [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md), [UID:0001XN][FpsPane_vtables](by-type/by-vtable/FpsPane_vtables.md).

- `0x004b7590-0x004b75a6` - `FramePartPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `FramePartPane` scalar deleting destructor `0x004b75b0`; not handwritten frame-part drawing or notification behavior.
  - Evidence: [UID:00015P][0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks](by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md) records IDA MCP lookup/disassembly/xref evidence, and [UID:0001XO][FrameChromeVtableFamily](by-type/by-vtable/FrameChromeVtableFamily.md) records the owning vtables.
  - Replacement/procurement: no external dependency; generated by the compiler from the `FramePartPane` inheritance/vtable layout.
  - Owner docs: [UID:0000JL][FrameChrome](by-file/FrameChrome.md), [UID:00005I][FramePartPane](by-class/FramePartPane.md), [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md).

- `0x004e85dc-0x004e8634` - IME pane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks. The source should model the IME pane destructors and inheritance layout, not handwritten thunk functions.
  - Evidence: [UID:00018D][0x004e85dc-0x004e8634.IMEAdjustorThunks](by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md) records IDA MCP lookup/decompile evidence for eight 0xb thunks targeting the `IMECandidatePane`, `IMECompositionPane`, `IMEPane`, and `IMEStatusPane` scalar deleting destructors.
  - Replacement/procurement: no external dependency; generated by the compiler from the IME pane inheritance/vtable layout.
  - Owner docs: [UID:0000K5][IMEPanes](by-file/IMEPanes.md), [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md), [UID:00006G][IMECompositionPane](by-class/IMECompositionPane.md), [UID:00006H][IMEPane](by-class/IMEPane.md), [UID:00006I][IMEStatusPane](by-class/IMEStatusPane.md).

- `0x004e8433-0x004e8450` - `IMEPane::HandleIMEMessage` switch jump table and alignment padding.
  - Why ignored: compiler-generated switch data and linker/compiler alignment after the source-level IME message dispatch; not standalone handwritten NexusTK logic.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4E81B0` ending with `retn 4` at `0x004e8430-0x004e8432`, then `0x90` alignment at `0x004e8433`, switch jump-table data at `0x004e8434-0x004e8448`, `0xcc` alignment at `0x004e8448-0x004e8450`, and the next modeled function `sub_4E8450`.
  - Replacement/procurement: reconstruct `IMEPane::HandleIMEMessage` as a source-level switch and let the compiler regenerate equivalent table/alignment bytes.
  - Owner docs: [UID:000189][0x004e70f0-0x004e8433.IMEPaneFamily](by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md), [UID:0000K5][IMEPanes](by-file/IMEPanes.md), [UID:00006H][IMEPane](by-class/IMEPane.md), [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md).

- `0x004e8450-0x004e85ae`, `0x004e8860-0x004e89f2`, `0x004e8a00-0x004e8ae6`, and `0x004e9710-0x004e97a3` - IME candidate-string deque/wstring STL template helpers.
  - Why ignored: MSVC/Dinkumware `std::deque<std::wstring>`-style helper materialization used by IME candidate UI/input handling; not handwritten NexusTK product logic. The surrounding IME pane methods and `InputMan::HandleWindowMessage` remain reconstructable product code.
  - Evidence: [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md), [UID:00018C][0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors](by-memory/0x004e8450-0x004e8ae6.IMECandidateQueueAndDestructors.md), exact helper pages [UID:0002MS][0x004e8450-0x004e85ae.CandidateStringQueueAssignRange](by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md), [UID:0002MT][0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional](by-memory/0x004e8860-0x004e89f2.CandidateStringQueueReserveAdditional.md), [UID:0002MU][0x004e8a00-0x004e8ae6.CandidateStringQueueClear](by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md), and [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md). IDA MCP finds `deque<T> too long` at `0x0060f0a8`, routes it through `0x0043f190`, and shows `0x004e8860` calling that overflow helper while manipulating 0x18-byte SSO-7 wide-string entries.
  - Replacement/procurement: generated from ordinary C++ standard-library container/string usage; reconstructed source should express a candidate string container, likely `std::deque<std::wstring>`, in [UID:0000K5][IMEPanes](by-file/IMEPanes.md) and [UID:0000K6][InputMan](by-file/InputMan.md).
  - Owner docs: [UID:00001G][CandidateStringQueue](by-class/CandidateStringQueue.md), [UID:00006F][IMECandidatePane](by-class/IMECandidatePane.md), [UID:0000K6][InputMan](by-file/InputMan.md), [wave3 data issues](../wave3_data_issues.md).

- `0x004e97a3-0x004e97b0` - alignment padding between `CandidateStringQueueAppendOwnedString` and `InterfaceEfxAndMgr`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent function bodies.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4E9710` ending with `retn 4` at `0x004e97a0-0x004e97a2`, `0x004e97a3-0x004e97af` as `align 10h`, and `sub_4E97B0` starting at `0x004e97b0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018F][0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString](by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md), [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md).

- `0x004ea121-0x004ea130` - alignment padding between `InterfaceEfxAndMgr` and `InventoryPanes`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `InterfaceEfxMgr` scalar deleting destructor and before the first `InventoryPane` constructor-side function.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4EA090` ending with `retn 4` bytes at `0x004ea11e-0x004ea120`, then `0x004ea121-0x004ea12f` as `align 10h`, and `sub_4EA130` starting at `0x004ea130`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md), [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md).

- `0x004efbb7-0x004efbc0` - alignment padding between `InventoryPanes` and `JpegScreenshotWriter`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent function bodies.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4EFB50` ending with `retn 4` at `0x004efbb4-0x004efbb6`, `0x004efbb7-0x004efbbf` as `align 10h`, and `sub_4EFBC0` starting at `0x004efbc0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md), [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md).

- `0x004eb044-0x004eb050`, `0x004edfa4-0x004edfb0`, and `0x004ef62e-0x004ef630` - BackPane help packet helper internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after exact BackPane help packet display helper bodies inside the broader `InventoryPanes` address island.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_4EAF20` as `0x004eaf20-0x004eb044`, `sub_4EDE80` as `0x004ede80-0x004edfa4`, and `sub_4EF510` as `0x004ef510-0x004ef62e`; byte reads at the three exclusive ends report `0xcc` padding before the next modeled functions.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md), and [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md).

- `0x004efde2-0x004efdf0`, `0x004efdf1-0x004efe00`, `0x004efe35-0x004efe40`, `0x004efe57-0x004efe60`, `0x004efe61-0x004efe70`, and `0x004efe94-0x004efea0` - JPEG screenshot writer callback island alignment padding.
  - Why ignored: compiler/linker alignment bytes around the writer-local JPEG callback/null-stub island after the main `WriteJpegFileFromRgb565Surface` body. These ranges contain no standalone handwritten logic.
  - Evidence: 2026-06-01 IDA MCP reconfirms `sub_4EFBC0` ending at `0x004efde2`, `nullsub_36` at `0x004efdf0-0x004efdf1`, raw callback bodies at `0x004efe00-0x004efe35` and `0x004efe40-0x004efe57`, `nullsub_37` at `0x004efe60-0x004efe61`, `sub_4EFE70` at `0x004efe70-0x004efe94`, and `KeySpeedMgr` beginning at `0x004efea0`; byte reads show the six listed spans are 14, 15, 11, 9, 15, and 12 bytes of `0xcc` alignment respectively.
  - Replacement/procurement: no source replacement; source should express the JPEG writer callbacks and let the compiler/linker generate alignment bytes.
  - Owner docs: [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md), [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md).

- `0x004efedd-0x004efee0`, `0x004efef5-0x004eff00`, `0x004eff25-0x004eff30`, `0x004eff5d-0x004eff60`, `0x004eff85-0x004effa0`, and `0x004effbd-0x004effc0` - KeySpeedMgr internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment between exact KeySpeedMgr method/helper bodies.
  - Evidence: 2026-05-31 IDA MCP byte review confirms these internal spans are all `0xcc`; the same pass identifies the previously undocumented raw helper bytes at `0x004eff60-0x004eff85`, so the padding split is not speculative.
  - Replacement/procurement: no source replacement; source should express the KeySpeedMgr class/helpers and let the compiler/linker generate alignment bytes.
  - Owner docs: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md).

- `0x004f0008-0x004f0010` - alignment padding between `KeySpeedMgr` and `LanguageManLocalization`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `KeySpeedMgr` scalar deleting destructor and before the first `LanguageManLocalization` function.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4EFFC0` ending with `retn 4` bytes at `0x004f0005-0x004f0007`, `0x004f0008-0x004f000f` as `align 10h`, and `sub_4F0010` starting at `0x004f0010`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md), [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md).

- `0x004f028c-0x004f0290`, `0x004f0342-0x004f0350`, `0x004f0372-0x004f0380`, `0x004f03bb-0x004f03c0`, and `0x004f03cb-0x004f03d0` - LanguageMan internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment between exact LanguageMan constructor, cleanup destructor, zero-initializer, lookup helpers, singleton-clear helper, and scalar deleting destructor bodies.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports function bodies ending at `0x004f028c`, `0x004f0342`, `0x004f0372`, `0x004f03bb`, and `0x004f03cb`; byte reads at each exclusive end show 4, 14, 14, 5, and 5 bytes of `0xcc` alignment respectively before the next function.
  - Replacement/procurement: no source replacement; source should express the LanguageMan methods/helpers and let compiler/linker alignment be regenerated.
  - Owner docs: [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md), [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md), [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md), [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md), and [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md).

- `0x004f0477-0x004f0480` - alignment padding between `LanguageManScalarDeletingDestructor` and `Layer`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent function bodies.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4F03D0` ending with `retn 4` at `0x004f0474-0x004f0476`, `0x004f0477-0x004f047f` as `align 10h`, and `sub_4F0480` starting at `0x004f0480`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md), [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md).

- `0x004f1bf6-0x004f1c00` - alignment padding between `Layer` and `InputPaneBases`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `Layer` scalar deleting destructor and before the first input-pane base function.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4F1B40` ending with `retn 4` bytes at `0x004f1bf3-0x004f1bf5`, `0x004f1bf6-0x004f1bff` as `align 10h`, and `sub_4F1C00` starting at `0x004f1c00`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018W][0x004f0480-0x004f1bf6.Layer](by-memory/0x004f0480-0x004f1bf6.Layer.md), [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md).

- `0x004f3017-0x004f3020` - alignment padding between `InputPaneBases` and `LineIteratorReadNextLine`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `ConfirmInputPane` scalar deleting destructor and before the next line-iterator helper.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4F2FB0` ending with `retn 4` bytes at `0x004f3014-0x004f3016`, `0x004f3017-0x004f301f` as `align 10h`, and `sub_4F3020` starting at `0x004f3020`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md), [UID:000190][0x004f3020-0x004f3060.LineIteratorReadNextLine](by-memory/0x004f3020-0x004f3060.LineIteratorReadNextLine.md).

- `0x004f30d5-0x004f30e0` - alignment padding between `ListConstructor` and `ListNonDeletingDestructor`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `List::List` constructor and before the non-deleting destructor.
  - Evidence: 2026-05-28 IDA MCP shows `sub_4F3060` ending with `retn 8` bytes at `0x004f30d2-0x004f30d4`, `0x004f30d5-0x004f30df` as `align 10h`, and `sub_4F30E0` starting at `0x004f30e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000191][0x004f3060-0x004f30d5.ListConstructor](by-memory/0x004f3060-0x004f30d5.ListConstructor.md), [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md).

- `0x004f3139-0x004f3140`, `0x004f31cc-0x004f31d0`, `0x004f329f-0x004f32a0`, `0x004f32a4-0x004f32b0`, `0x004f32da-0x004f32e0`, `0x004f33b5-0x004f33c0`, `0x004f33d5-0x004f33e0`, `0x004f3493-0x004f34a0`, `0x004f34ab-0x004f34b0`, `0x004f3532-0x004f3540`, `0x004f355b-0x004f3560`, `0x004f3597-0x004f35a0`, `0x004f35db-0x004f35e0`, and `0x004f35fd-0x004f3600` - List core-method alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the corrected `ListNonDeletingDestructor`, the List core method bodies, raw reserve/page-count helpers, and the adjacent `SortedList` cluster.
  - Evidence: 2026-05-28 IDA MCP function inventory lists modeled List methods at `0x004f30e0-0x004f3139`, `0x004f3140-0x004f31cc`, `0x004f31d0-0x004f329f`, `0x004f32a0-0x004f32a4`, `0x004f32b0-0x004f32da`, `0x004f32e0-0x004f33b5`, `0x004f33c0-0x004f33d5`, `0x004f33e0-0x004f3493`, `0x004f34a0-0x004f34ab`, `0x004f34b0-0x004f3532`, and `0x004f3540-0x004f355b`; raw disassembly identifies function-shaped helper bodies at `0x004f3560-0x004f3597`, `0x004f35a0-0x004f35db`, and `0x004f35e0-0x004f35fd`. The listed intervening spans are all alignment bytes.
  - Replacement/procurement: no source replacement; final source should express normal `List` methods/helpers and let the compiler/linker generate alignment.
  - Owner docs: [UID:000192][0x004f30e0-0x004f3139.ListNonDeletingDestructor](by-memory/0x004f30e0-0x004f3139.ListNonDeletingDestructor.md), [UID:00022S][0x004f3140-0x004f35fd.ListCoreMethods](by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md), [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md).

- `0x004f3a43-0x004f3a50` - alignment padding between `SortedList` and `ListPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the `SortedList::RemoveRange` tail body and before the `ListPane` cluster.
  - Evidence: 2026-05-28 IDA MCP function inventory lists `sub_4F3990` as `0x004f3990-0x004f3a43`, `sub_4F3A50` as `0x004f3a50-0x004f3b5b`, and raw bytes at `0x004f3a43-0x004f3a50` as thirteen `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000193][0x004f3600-0x004f3a43.SortedList](by-memory/0x004f3600-0x004f3a43.SortedList.md), [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).

- `0x004f4a77-0x004f4a80` - alignment padding between `ListPane` and `LObjectRuntimeShell`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the `ListPane` cluster and before the tiny `LObject` runtime helper shell.
  - Evidence: 2026-05-28 IDA MCP function inventory lists `sub_4F4A00` as `0x004f4a00-0x004f4a77`, `sub_4F4A80` as `0x004f4a80-0x004f4a89`, and raw bytes at `0x004f4a77-0x004f4a80` as nine `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md), [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md).

- `0x004f4c0d-0x004f4c10` - alignment padding between `LObjectRuntimeShell` and `LogoPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the tiny `LObject` runtime helper shell and before the `LogoPane` cluster.
  - Evidence: 2026-05-28 IDA MCP/raw-byte check shows three `0xcc` bytes at `0x004f4c0d-0x004f4c10`, immediately before `sub_4F4C10`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md), [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md).

- `0x004f53a8-0x004f53b0` - alignment padding between `LogoPane` and `LogoPlayerPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the `LogoPane` cluster and before the `LogoPlayerPane` cluster.
  - Evidence: 2026-05-28 IDA MCP function inventory lists `sub_4F4C10` before the gap and `sub_4F53B0` as `0x004f53b0-0x004f5500`; raw bytes at `0x004f53a8-0x004f53b0` are eight `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019C][0x004f4c10-0x004f53a8.LogoPane](by-memory/0x004f4c10-0x004f53a8.LogoPane.md), [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md).

- `0x004f570c-0x004f5710`, `0x004f59c6-0x004f59d0`, and `0x004f5ac7-0x004f5ad0` - startup-logo Bink playback alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around the startup-logo Bink playback loop and temporary window procedure.
  - Evidence: 2026-05-28 IDA MCP function inventory lists `sub_4F5710` as `0x004f5710-0x004f59c6`, `sub_4F59D0` as `0x004f59d0-0x004f5ac7`, and `sub_4F5AD0` as `0x004f5ad0-0x004f5ad4`; the listed intervening spans are alignment bytes.
  - Replacement/procurement: no source replacement; final source should express the playback helper and window procedure normally and let compiler/linker alignment be generated.
  - Owner docs: [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md), [UID:00022T][0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop](by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md), [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md).

- `0x004f5ad4-0x004f5ae0`, `0x004f5b1e-0x004f5b20`, and `0x004f5c73-0x004f5c80` - startup-logo/MAPI helper alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around the Bink midpoint/restart helper and raw MAPI send-mail helper.
  - Evidence: 2026-05-28 IDA MCP function inventory lists `sub_4F5AD0` as `0x004f5ad0-0x004f5ad4`, `sub_4F5AE0` as `0x004f5ae0-0x004f5b1e`, and `_WinMain@16` as starting at `0x004f5c80`; raw disassembly identifies the MAPI helper body at `0x004f5b20-0x004f5c73`. The listed intervening spans are alignment bytes.
  - Replacement/procurement: no source replacement; final source should express the real helpers and let compiler/linker alignment be generated.
  - Owner docs: [UID:00019F][0x004f5ad0-0x004f5ad4.StdioFileGetSize](by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md), [UID:00022U][0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart](by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md), [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md).

- `0x004f5f17-0x004f5f20` - alignment padding between `WinMain` and `BaramAppAndApplicationStartup`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `_WinMain@16` and before the application startup helper range.
  - Evidence: 2026-05-28 IDA MCP reports `_WinMain@16` as `0x004f5c80-0x004f5f17`; raw bytes at `0x004f5f17-0x004f5f20` are nine `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md), [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md).

- `0x004f66fb-0x004f6700` - alignment padding between `BaramAppAndApplicationStartup` and `MainMenuLoginAndAccountDialogs`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `BaramApp` scalar deleting destructor and before the main menu/login dialog cluster.
  - Evidence: 2026-05-28 IDA MCP reports `sub_4F66C0` as `0x004f66c0-0x004f66fb`; raw disassembly shows `0x004f66fa` is the final immediate byte of `retn 4`, and `0x004f66fb-0x004f6700` is `0xcc` alignment.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md), [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md).

- `0x004f8f02-0x004f8f10`, `0x004f8f95-0x004f8fa0`, `0x004f9055-0x004f9060`, and `0x004f927d-0x004f9280` - alignment padding between retained main-menu launch helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact helper functions in the main-menu/login aggregate.
  - Evidence: 2026-06-01 IDA MCP reports functions at `0x004f8d00-0x004f8f02`, `0x004f8f10-0x004f8f95`, `0x004f8fa0-0x004f9055`, `0x004f9060-0x004f90b4`, `0x004f91c0-0x004f927d`, and `0x004f9280+`; raw-byte checks show only `0xcc` bytes in the listed interstitial ranges.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md), [UID:00019O][0x004f8d00-0x004f8f02.LegacyMainMenuPacket](by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md), [UID:0002Q6][0x004f8f10-0x004f8f95.OpenTransferServerDialog](by-memory/0x004f8f10-0x004f8f95.OpenTransferServerDialog.md), [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md), [UID:00019Q][0x004f9060-0x004f90b4.OpenChangePasswordDialog](by-memory/0x004f9060-0x004f90b4.OpenChangePasswordDialog.md), [UID:00019S][0x004f91c0-0x004f927d.OpenTerminalPane](by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md), and [UID:00019T][0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport](by-memory/0x004f9280-0x004f9d28.ProfileLoadAndLegacyImport.md).

- `0x004fb62a-0x004fb630` - alignment padding between `MainMenuLoginAndAccountDialogs` and `NewUserMiscShapeAndPasswordDialogs`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the login/account dialog cluster and before the next account-creation/misc dialog cluster.
  - Evidence: 2026-05-28 IDA MCP/raw-byte check shows `0x004fb62a-0x004fb630` is six `0xcc` alignment bytes, and the next modeled function starts at `0x004fb630`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md), [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md).

- `0x004fdd33-0x004fdd40` - alignment padding between `NewUserShapeSelectControlPaneCore` and `ChangePasswordDialogPaneCore`.
  - Why ignored: compiler/code alignment between two source-bearing UI method islands.
  - Evidence: 2026-06-01 IDA MCP raw bytes at `0x004fdd30` show `sub_4FDC90` ending with `c2 08 00` at `0x004fdd33`, followed by `0xcc` bytes through the `ChangePasswordDialogPane` constructor start at `0x004fdd40`.
  - Owner docs: [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md), [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md).

- `0x004fe782-0x004fe790`, `0x004fe9d1-0x004fe9e0`, `0x004febe2-0x004febf0`, `0x004fee11-0x004fee14`, `0x004fee14-0x004fee38`, `0x004fee38-0x004fee40`, and `0x004ff03f-0x004ff040` - alignment and local switch-table support inside/around [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) `ChangePasswordDialogPacketHelpers`.
  - Why ignored: compiler alignment bytes or compiler-emitted switch support data; not standalone handwritten source to port.
  - Evidence: 2026-05-28 IDA MCP `py_eval` over `0x004fe782-0x004ff040` found defined functions at `0x004fe9e0-0x004febe2`, `0x004febf0-0x004fee11`, and `0x004fee40-0x004ff03f`; the intervening spans are `0xcc` padding, a three-byte alignment/no-op, or the local switch table used by the `0x004febf0` result-code switch.
  - Replacement/procurement: no source replacement for padding/table bytes; source should model the switch and let the compiler regenerate equivalent table/alignment output.
  - Owner docs: [UID:00022W][0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers](by-memory/0x004fe790-0x004ff03f.ChangePasswordDialogPacketHelpers.md) `ChangePasswordDialogPacketHelpers`, [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md), [UID:0002QD][0x004febf0-0x004fee11.HandlePasswordChangeReply](by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md), [UID:0002QE][0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple](by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md), [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md), [UID:00019W][0x004ff040-0x00502c0c.ScrolledTextControlPane](by-memory/0x004ff040-0x00502c0c.ScrolledTextControlPane.md).

- `0x004ff95e-0x004ff970` - `ScrolledPictureControlPane` constructor switch support.
  - Why ignored: compiler-generated no-op alignment plus four-entry jump table for the constructor's scroll-direction switch; not standalone handwritten source.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_4FF7D0` ending before `0x004ff960` and `sub_4FF970` starting at `0x004ff970`; `get_bytes` shows `66 90` followed by dword targets `0x004ff8ee`, `0x004ff8fd`, `0x004ff909`, and `0x004ff915`.
  - Replacement/procurement: regenerated from the constructor `switch(direction)` source.
  - Owner docs: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md), [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md).

- `0x004ff9d7-0x004ff9e0` - `ScrolledPictureControlPane` destructor-to-timer alignment.
  - Why ignored: `0xcc` padding between the non-deleting destructor and timer callback.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_4FF970` size `0x67` and `sub_4FF9E0` start at `0x004ff9e0`; `get_bytes` shows nine `0xcc` bytes in this span.
  - Replacement/procurement: no source-level replacement; regenerated by compiler/linker alignment.
  - Owner docs: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md), [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md).

- `0x004ffa4b-0x004ffa60` - `ScrolledPictureControlPane` timer switch support and paint alignment.
  - Why ignored: compiler-generated no-op, four-entry jump table for the timer direction switch, and `0xcc` padding before the paint callback; not standalone source.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_4FF9E0` size `0x6b` and `sub_4FFA60` start at `0x004ffa60`; `get_bytes` shows `90`, dword targets `0x004ff9f3`, `0x004ff9fd`, `0x004ffa04`, `0x004ffa0b`, then four `0xcc` bytes.
  - Replacement/procurement: regenerated from the timer callback `switch(direction)` and alignment.
  - Owner docs: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md), [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md).

- `0x004ffa9f-0x004ffaa0` - `ScrolledPictureControlPane` to `StaffsDialogPane` alignment.
  - Why ignored: single `0xcc` byte after `ScrolledPictureControlPane::OnPaintFrame` and before the next modeled function.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_4FFA60` ending at `0x004ffa9f` and `sub_4FFAA0` starting at `0x004ffaa0`; `get_bytes` shows one `0xcc` byte at `0x004ffa9f`.
  - Replacement/procurement: no source-level replacement; regenerated by compiler/linker alignment.
  - Owner docs: [UID:00019Y][0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore](by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md), [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md).

- `0x0050008b-0x00500090`, `0x005003e3-0x005003f0`, and `0x0050040d-0x00500410` - `BackStoryDialogPane` alignment around constructor/button handler.
  - Why ignored: compiler/linker alignment padding around source-authored `BackStoryDialogPane` constructor and button-click handler.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_500090` at `0x00500090` size `0x353`, `sub_5003F0` at `0x005003f0` size `0x1d`, and `sub_500410` at `0x00500410`; `get_bytes` shows five `0xcc` bytes before the constructor, thirteen `0xcc` bytes between constructor and handler, and three `0xcc` bytes after the handler.
  - Replacement/procurement: no source-level replacement; regenerated by compiler/linker alignment.
  - Owner docs: [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md), [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md), [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md).

- `0x00500632-0x00500640`, `0x00500697-0x005006a0`, `0x00500797-0x005007a0`, `0x005007e7-0x005007f0`, and `0x005008b9-0x005008c0` - specialized button/control alignment.
  - Why ignored: compiler/linker alignment padding between `NewHistoryDialogPaneCore`, raw/modelled gender/direction button methods, and `BlueAlertPaneCore`.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports no functions at the padding starts, real modeled functions at `0x00500690`, `0x005006d0`, `0x00500700`, `0x005007f0`, `0x00500820`, and `0x005008c0`, and raw disassembly confirms constructor-shaped bodies ending at `0x0050068f` and `0x005007e7`; `get_bytes` shows `0xcc`/alignment bytes in the listed gaps.
  - Replacement/procurement: no source-level replacement; regenerated by compiler/linker alignment.
  - Owner docs: [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md), [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md), [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md).

- `0x004ce34b-0x004ce361`, `0x004ce361-0x004ce377`, `0x004ce377-0x004ce38d`, `0x004ce38d-0x004ce3a3`, `0x004ce3ae-0x004ce3b9`, `0x004ce3c4-0x004ce3cf`, `0x004ce3da-0x004ce3e5` - Help/tooltip secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks. The source should model the `HelpPane`, `SimpleHelpPane`, `SimpleHelpPane2`, `ItemHelpPane`, `WillBeChangedItemPane`, `WillBeChangedSpellPane`, and embedded text-part destructors through normal C++ inheritance, not handwritten thunk functions.
  - Evidence: [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) records the exact thunk rows before the real scalar deleting destructors. The listed ranges intentionally skip alignment gaps and stop before `HelpPane::ScalarDeletingDestructor` at `0x004ce3f0`; scalar deleting destructors remain reconstructable project code.
  - Replacement/procurement: no external dependency; generated by the compiler from help/tooltip pane inheritance and vtable layout.
  - Owner docs: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), [UID:000063][HelpPane](by-class/HelpPane.md), [UID:0000D6][SimpleHelpPane](by-class/SimpleHelpPane.md), [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md), [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), [UID:0000G5][WillBeChangedItemPane](by-class/WillBeChangedItemPane.md), [UID:0000G6][WillBeChangedSpellPane](by-class/WillBeChangedSpellPane.md).

- `0x004ce725-0x004ce730` - Help/tooltip destructor-thunk island to `HierList` alignment padding.
  - Why ignored: IDA disassembly shows `WillBeChangedSpellPane::ScalarDeletingDestructor` ends with `C2 04 00` at `0x004ce722-0x004ce724`; the bytes from `0x004ce725` through `0x004ce72f` are `0xcc` alignment before `HierList::HierList` at `0x004ce730`.
  - Evidence: [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) records the corrected exclusive end after IDA MCP boundary verification.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JU][HelpPanes](by-file/HelpPanes.md), [UID:0000JV][HierList](by-file/HierList.md).

- `0x004cee52-0x004cee60` - `HierList` to `HourPane` alignment padding.
  - Why ignored: IDA disassembly shows `HierList` scalar deleting destructor ends with `C2 04 00` at `0x004cee4f-0x004cee51`; the bytes from `0x004cee52` through `0x004cee5f` are `0xcc` alignment before `HourPane` code starts at `0x004cee60`.
  - Evidence: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) records the destructor wrapper ending at `0x004cee52`; IDA MCP boundary verification confirmed no function object in the padding span.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JV][HierList](by-file/HierList.md), [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md).

- `HierList` internal alignment padding.
  - Ranges: `0x004ce7d1-0x004ce7e0`, `0x004ce839-0x004ce840`, `0x004ce854-0x004ce860`, `0x004ce9ad-0x004ce9b0`, `0x004ceafc-0x004ceb00`, `0x004ceb45-0x004ceb50`, `0x004ceb62-0x004ceb70`, `0x004ceba9-0x004cebb0`, `0x004cebb9-0x004cebc0`, `0x004cebec-0x004cebf0`, `0x004cec22-0x004cec30`, `0x004ced0f-0x004ced10`, `0x004ceda4-0x004cedb0`.
  - Why ignored: IDA MCP byte review on 2026-05-31 confirmed these spans are `0xcc` alignment between exact HierList methods/wrapper bodies.
  - Evidence: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md) records the exact split and child pages.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JV][HierList](by-file/HierList.md), [UID:000065][HierList](by-class/HierList.md).

- `0x004cf1ef-0x004cf1f0` - `HourPane` to `IconsPane` alignment padding.
  - Why ignored: IDA disassembly shows `HourPane` scalar deleting destructor ends with `C2 04 00` at `0x004cf1ec-0x004cf1ee`; byte `0x004cf1ef` is `0xcc` alignment before `IconsPane` code starts at `0x004cf1f0`.
  - Evidence: [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md) records the destructor wrapper ending at `0x004cf1ef`; IDA MCP boundary verification confirmed no function object at the padding byte.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JX][HourPane](by-file/HourPane.md), [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md).

- `0x004cf8d5-0x004cf8e0` - `IconsPane` core to raw action-dispatch alignment padding.
  - Why ignored: IDA disassembly shows `IconsPane::SetIconHighlight` ends with `C2 04 00` at `0x004cf8d2-0x004cf8d4`; bytes `0x004cf8d5-0x004cf8df` are `0xcc` alignment before the raw action-dispatch body at `0x004cf8e0`.
  - Evidence: [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) and [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md) record the adjacent executable ranges.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JZ][IconsPane](by-file/IconsPane.md), [UID:00006B][IconsPane](by-class/IconsPane.md).

- `0x004cf975-0x004cf980` - raw `IconsPane` action dispatch to `TabPane` alignment padding.
  - Why ignored: IDA disassembly shows the raw dispatch jump table ends at `0x004cf974`; bytes `0x004cf975-0x004cf97f` are `0xcc` alignment before `TabPane` code begins at `0x004cf980`.
  - Evidence: [UID:00022Q][0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf975.IconsPaneActionDispatchRawBody.md) records the raw dispatcher and jump-table bytes; [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) records the following `TabPane` constructor.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000JZ][IconsPane](by-file/IconsPane.md), [UID:0000OF][TabPane](by-file/TabPane.md).

- `0x004cfe5f-0x004cfe60` - `TabPane`/`IconsPane` destructor tail to `IdleWatcher` alignment padding.
  - Why ignored: IDA disassembly shows `TabPane::ScalarDeletingDestructor` ends with `C2 04 00` at `0x004cfe5c-0x004cfe5e`; byte `0x004cfe5f` is `0xcc` alignment before `IdleWatcher` starts at `0x004cfe60`.
  - Evidence: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) records the destructor tail, and IDA MCP boundary verification confirmed no function object at the padding byte.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000OF][TabPane](by-file/TabPane.md), [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md).

- `0x004cffaf-0x004cffb0` - `IdleWatcher` to `ImageLib` alignment padding.
  - Why ignored: IDA disassembly shows `IdleWatcher::ScalarDeletingDestructor` ends with `C2 04 00` at `0x004cffac-0x004cffae`; byte `0x004cffaf` is `0xcc` alignment before `ImageLib` code starts at `0x004cffb0`.
  - Evidence: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md) records the corrected exclusive end after IDA MCP boundary verification.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md), [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md).

- `0x004e6aa6-0x004e6ab0` - `StaticObjImageLib` to `AUTOBUF<unsigned char>` resize helper alignment padding.
  - Why ignored: IDA disassembly shows `StaticObjImageLib::DeletingDestructor` ends with `C2 04 00` at `0x004e6aa3-0x004e6aa5`; bytes `0x004e6aa6-0x004e6aaf` are `0xcc` alignment before `AUTOBUF<unsigned char>` resize helper code starts at `0x004e6ab0`.
  - Evidence: [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md) records the corrected exclusive end after IDA MCP boundary verification.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), [UID:000188][0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize.md).

- `0x004e6adf-0x004e6ae0`, `0x004e6c4c-0x004e6c50`, `0x004e6de4-0x004e6df0`, `0x004e6e49-0x004e6e50`, `0x004e6fe2-0x004e6ff0`, `0x004e7026-0x004e7030`, `0x004e7094-0x004e70a0`, `0x004e70e9-0x004e70f0` - image/vector helper island alignment padding.
  - Why ignored: IDA function listing for the former `0x004e6adf-0x004e70f0` gap shows seven real helpers at `0x004e6ae0`, `0x004e6c50`, `0x004e6df0`, `0x004e6e50`, `0x004e6ff0`, `0x004e7030`, and `0x004e70a0`; these spans are only `0xcc` alignment between or around those helpers.
  - Evidence: [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) records the helper functions and IDA xref evidence.
  - Replacement/procurement: no external dependency; compiler/linker alignment padding only.
  - Owner docs: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), [UID:00017A][0x004d2720-0x004e649b.HumanImageLib](by-memory/0x004d2720-0x004e649b.HumanImageLib.md), [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md).

- `0x0048c260-0x0048c314` - Clan dialog/list/status secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks in the Clan destructor band. The final source should model the owning Clan dialog/list/status destructors and inheritance layout, not handwritten adjustment stubs.
  - Evidence: [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md) records the exact thunk strip, and [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md) records the modal dialog vtable bases that reference this layout family.
  - Replacement/procurement: no external dependency; generated by the compiler from Clan dialog/list/status multiple-inheritance vtable layout.
  - Owner docs: [UID:0000I8][Clan](by-file/Clan.md), [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md), [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md).

- `0x0048c315-0x0048c32b` - `AlertPane`-family secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into the shared `AlertPane`-family scalar deleting destructor at `0x0048c550`; not handwritten product logic.
  - Evidence: [UID:00010V][0x0048c315-0x0048c32b.AlertPaneAdjustorThunks](by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Vtable refs include `ClanLeaveConfirmDialog`, `AlertPane`, `BlueAlertPane`, `CopyWindow`, and `QuitDialog`.
  - Replacement/procurement: no external dependency; generated by the compiler from alert/dialog inheritance and vtable layout.
  - Owner docs: [UID:0000HE][AlertPanes](by-file/AlertPanes.md), [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), [UID:0000IH][CopyWindow](by-file/CopyWindow.md), [UID:0000BG][QuitDialog](by-class/QuitDialog.md).

- `0x0048c32b-0x0048c341` - `ClanStatusPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ClanStatusPane` destructor `0x0048c590`; not handwritten clan status UI behavior.
  - Evidence: [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md) identifies this exact pair as `ClanStatusPane` adjustor thunks after the shared `AlertPane` thunk pair.
  - Replacement/procurement: no external dependency; generated by the compiler from `ClanStatusPane` inheritance and vtable layout.
  - Owner docs: [UID:0000I8][Clan](by-file/Clan.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md).

- `0x0049ac60-0x0049ad74` - `FontStyle` rule-vector growth helper.
  - Why ignored: compiler/template-style vector insert/growth support for 16-byte `FontStyleRule` records; not handwritten text-style feature logic.
  - Evidence: [UID:00011W][0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth](by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md) records IDA MCP lookup/caller/callee/decompile evidence. The only direct caller is `FontStyle::Configure` at `0x00499fcf`, and the body performs capacity growth, allocation, 16-byte record copy, `memmove`, old-storage free, and vector triplet updates.
  - Replacement/procurement: no external dependency; generated by the compiler from a normal vector/container append in [UID:0000JI][FontStyle](by-file/FontStyle.md).
  - Owner docs: [UID:0000JI][FontStyle](by-file/FontStyle.md), [UID:00005C][FontStyle](by-class/FontStyle.md), [UID:0001UN][FontStyleLayout](by-type/by-struct/FontStyleLayout.md), [UID:00011T][0x00499f10-0x00499fda.FontStyleCore](by-memory/0x00499f10-0x00499fda.FontStyleCore.md).

- `0x0049af7f-0x0049af95` - `NumericStringControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `NumericStringControlPane` scalar deleting destructor `0x0049b2f0`; not handwritten numeric-glyph rendering behavior.
  - Evidence: [UID:000121][0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks](by-memory/0x0049af7f-0x0049af95.NumericStringControlPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x006183f8` and `0x00618428`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `NumericStringControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md), [UID:00009M][NumericStringControlPane](by-class/NumericStringControlPane.md), [UID:000124][0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor](by-memory/0x0049b2f0-0x0049b3af.NumericStringControlPaneScalarDeletingDestructor.md).

- `0x0049afc1-0x0049afd7` - `RectangleControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RectangleControlPane` scalar deleting destructor `0x0049b490`; not handwritten rectangle-control behavior.
  - Evidence: [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0061849c` and `0x006184cc`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RectangleControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md), [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md), [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md).

- `0x004a4cb1-0x004a4cf3` - employee dialog family secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `AddEmployeeItemDialog`, `EmployeeDialogPane`, and `EmployeeItemPropertyDialogPane` scalar deleting destructors; not handwritten employee dialog behavior.
  - Evidence: [UID:00013B][0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks](by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. The six thunks adjust `this` by `0xa0` or `0xa4` and jump to scalar deleting destructors at `0x004a4d00`, `0x004a4d40`, and `0x004a4e30`.
  - Replacement/procurement: no external dependency; generated by the compiler from the employee dialog inheritance/vtable layout.
  - Owner docs: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md), [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md), [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md).

- `0x004b0ab5-0x004b0acb` - `ExchangeMoneyEditControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ExchangeMoneyEditControlPane` scalar deleting destructor `0x004b0a60`; not handwritten money-edit control behavior.
  - Evidence: [UID:00014Y][0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks](by-memory/0x004b0ab5-0x004b0acb.ExchangeMoneyEditControlPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Current disabled simroot output emits only the second thunk at `0x004b0ac0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ExchangeMoneyEditControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), [UID:00004T][ExchangeMoneyEditControlPane](by-class/ExchangeMoneyEditControlPane.md), [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md).

- `0x004b08cd-0x004b08e3` - `ExchangeAlertPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ExchangeAlertPane` scalar deleting destructor `0x004b09d0`; not handwritten exchange-alert behavior.
  - Evidence: [UID:00014X][0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks](by-memory/0x004b08cd-0x004b08e3.ExchangeAlertPaneAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x0061a228` and `0x0061a258`, and both thunks forward into `0x004b09d0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ExchangeAlertPane` inheritance/vtable layout.
  - Owner docs: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md), [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md), [UID:0001XJ][ExchangeAlertPaneVtables](by-type/by-vtable/ExchangeAlertPaneVtables.md), [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md).

- `0x005023b0-0x005023bb` - `HistoryViewingPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pHistoryViewingPane` during constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001A7][0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear](by-memory/0x005023b0-0x005023bb.HistoryViewingPaneSingletonClear.md) records IDA MCP lookup/decompile/xref evidence: the body only writes zero to `0x0069b494`, has no ordinary callers, and has a constructor-context unwind xref at `0x00601e9c`.
  - Replacement/procurement: no external dependency; generated from the `HistoryViewingPane` constructor/lifetime cleanup.
  - Owner docs: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), [UID:0000R3][g_pHistoryViewingPane](by-global/g_pHistoryViewingPane.md).

- `0x005023e0-0x005023eb` - `NewHistoryDialogPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pNewHistoryDialog` during constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001A8][0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear](by-memory/0x005023e0-0x005023eb.NewHistoryDialogPaneSingletonClear.md) records IDA MCP lookup/decompile/xref evidence: the body only writes zero to `0x0069b49c`, has no ordinary callers, and has a constructor-context unwind xref at `0x00601f62`.
  - Replacement/procurement: no external dependency; generated from the `NewHistoryDialogPane` constructor/lifetime cleanup.
  - Owner docs: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md), [UID:0000RS][g_pNewHistoryDialog](by-global/g_pNewHistoryDialog.md).

- `0x00502410-0x0050241b` - `StaffsDialogPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pStaffsDialog` during constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001A9][0x00502410-0x0050241b.StaffsDialogPaneSingletonClear](by-memory/0x00502410-0x0050241b.StaffsDialogPaneSingletonClear.md) records IDA MCP lookup/decompile/xref evidence: the body only writes zero to `0x0069b490`, has no ordinary callers, and has a constructor-context unwind xref at `0x00601e35`.
  - Replacement/procurement: no external dependency; generated from the `StaffsDialogPane` constructor/lifetime cleanup.
  - Owner docs: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md), [UID:0000SC][g_pStaffsDialog](by-global/g_pStaffsDialog.md).

- `0x0050248a-0x005024b6` - `DirectionButtonControlPane` and `GenderButtonControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `DirectionButtonControlPane` scalar deleting destructor `0x005026a0` and `GenderButtonControlPane` scalar deleting destructor `0x00502700`; not handwritten control behavior.
  - Evidence: [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) records IDA MCP lookup/xref/vtable evidence. Data refs land at `0x0061dc9c`, `0x0061dccc`, `0x0061dbf8`, and `0x0061dc28`; code refs forward into the scalar deleting destructors.
  - Replacement/procurement: no external dependency; generated by the compiler from the multiple-inheritance vtable layout.
  - Owner docs: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md), [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md), [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md).

- `0x005024b6-0x005024cc` - `HistoryViewingPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `HistoryViewingPane` scalar deleting destructor `0x00502760`; not handwritten history-viewer behavior.
  - Evidence: [UID:0001AB][0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks](by-memory/0x005024b6-0x005024cc.HistoryViewingPaneDestructorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0061da1c` and `0x0061da4c`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `HistoryViewingPane` inheritance/vtable layout.
  - Owner docs: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), [UID:000066][HistoryViewingPane](by-class/HistoryViewingPane.md), [UID:0001AG][0x00502760-0x005027cc.HistoryViewingPaneDestructor](by-memory/0x00502760-0x005027cc.HistoryViewingPaneDestructor.md).

- `0x005024f8-0x0050250e` - `NewHistoryDialogPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `NewHistoryDialogPane` scalar deleting destructor `0x00502920`; not handwritten history-dialog behavior.
  - Evidence: [UID:0001AC][0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks](by-memory/0x005024f8-0x0050250e.NewHistoryDialogPaneDestructorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0061db54` and `0x0061db84`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `NewHistoryDialogPane` inheritance/vtable layout.
  - Owner docs: [UID:0000LQ][NewHistoryDialogPane](by-file/NewHistoryDialogPane.md), [UID:000091][NewHistoryDialogPane](by-class/NewHistoryDialogPane.md), [UID:0001AH][0x00502920-0x00502965.NewHistoryDialogPaneDestructor](by-memory/0x00502920-0x00502965.NewHistoryDialogPaneDestructor.md).

- `0x00502592-0x005025a8` - `StaffsDialogPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `StaffsDialogPane` scalar deleting destructor `0x00502cc0`; not handwritten staff-dialog behavior.
  - Evidence: [UID:0001AE][0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks](by-memory/0x00502592-0x005025a8.StaffsDialogPaneDestructorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0061d994` and `0x0061d9c4`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `StaffsDialogPane` inheritance/vtable layout.
  - Owner docs: [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md), [UID:0000DY][StaffsDialogPane](by-class/StaffsDialogPane.md), [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md).

- `0x005025a8-0x005025ff` - old create-user appearance control destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into the `UserCreatePreviewControlPane`, `UserFaceSelectControlPane`, `UserHairSelectControlPane`, and `UserShapeSelectControlPane` scalar deleting destructors; not handwritten create-user appearance behavior.
  - Evidence: [UID:0001AF][0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks](by-memory/0x005025a8-0x005025ff.UserCreateAppearanceAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land in the appearance-control vtable block at `0x0061d5cc-0x0061df5c`.
  - Replacement/procurement: no external dependency; generated by the compiler from the appearance control inheritance/vtable layouts.
  - Owner docs: [UID:0000OX][UserCreateAppearanceControls](by-file/UserCreateAppearanceControls.md), [UID:0000FH][UserCreatePreviewControlPane](by-class/UserCreatePreviewControlPane.md), [UID:0000FJ][UserFaceSelectControlPane](by-class/UserFaceSelectControlPane.md), [UID:0000FL][UserHairSelectControlPane](by-class/UserHairSelectControlPane.md), [UID:0000FR][UserShapeSelectControlPane](by-class/UserShapeSelectControlPane.md).

- `0x00502cbd-0x00502cc0` - alignment padding between [UID:00019X][0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy](by-memory/0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy.md) `ScrolledTextControlPaneForMadeBy` and [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md) `StaffsDialogPaneDestructor`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `ScrolledTextControlPaneForMadeBy` scalar deleting destructor.
  - Evidence: 2026-05-28 IDA MCP reports `sub_502C10` as `0x00502c10-0x00502cbd`; raw bytes at `0x00502cbc-0x00502cc0` are `00 cc cc cc`, proving `0x00502cbc` belongs to the preceding `retn 4` immediate and only `0x00502cbd-0x00502cc0` is padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00019X][0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy](by-memory/0x004ff400-0x00502cbd.ScrolledTextControlPaneForMadeBy.md) `ScrolledTextControlPaneForMadeBy`, [UID:0001AJ][0x00502cc0-0x00502d05.StaffsDialogPaneDestructor](by-memory/0x00502cc0-0x00502d05.StaffsDialogPaneDestructor.md).

- `0x00502d05-0x00502d10`, `0x00502d4b-0x00502d50`, `0x00502d8b-0x00502d90`, `0x00502dcb-0x00502dd0`, `0x00502e0b-0x00502e10`, `0x00502e21-0x00502e30`, `0x0050305c-0x00503060`, `0x005030bc-0x005030c0`, `0x00503104-0x00503110`, and `0x005031e1-0x005031f0` - alignment padding inside the former `0x00502d05-0x005031f0` UNKNOWN gap.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between IDA-confirmed functions or raw function-shaped helper bodies.
  - Evidence: 2026-05-28 IDA MCP function and raw-disassembly pass splits the previous gap into [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md), [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md), and [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md); every listed interstitial range consists only of `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00022X][0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors](by-memory/0x00502d10-0x00502e0b.UserCreateAppearanceScalarDeletingDestructors.md), [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md), [UID:00022Z][0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers](by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md), and [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md).

- `0x0050395f-0x00503960` and `0x005039ed-0x005039f0` - alignment padding around the raw GameServer nation request packet helper.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-01 IDA MCP lookup/raw-byte pass confirms `0x00503960` is not a modeled IDA function but is valid raw code, with one `0xcc` byte before its prologue and three `0xcc` bytes after its `retn` at `0x005039ec`; 2026-05-28 IDA MCP reports `sub_503900` ending at `0x0050395f`, proving `0x0050395e` is the final `retn 4` immediate byte in [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md), [UID:000230][0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper](by-memory/0x00503960-0x005039ed.GameServerNationRequestPacketRawHelper.md), and [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md).

- `0x00503a42-0x00503a50`, `0x00503a7d-0x00503a80`, `0x00503b58-0x00503b60`, `0x00503c61-0x00503c70`, `0x00503d03-0x00503d10`, `0x00503e77-0x00503e80`, `0x00503e8b-0x00503e90`, `0x00503ecd-0x00503ed0`, `0x00503eef-0x00503ef0`, `0x0050408d-0x00504090`, `0x00504093-0x005040a0`, and `0x00504102-0x00504110` - alignment padding inside the GameServerConfig/MapPane split aggregate.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact code islands and modeled functions, not executable product logic.
  - Evidence: 2026-05-31 IDA MCP `py_eval` byte checks over [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md) verified every listed span as `0xcc` padding after splitting the old aggregate into exact child pages.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002HV][0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw](by-memory/0x005039f0-0x00503a42.GameServerConfigNationTableConstructorRaw.md), [UID:0002HW][0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw](by-memory/0x00503a50-0x00503a7d.GameServerConfigNationTableDestructorRaw.md), [UID:0002HY][0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw](by-memory/0x00503b60-0x00503c61.GameServerConfigSeedDefaultNationEntriesRaw.md), and [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md).

- `0x00504521-0x00504530`, `0x005046c6-0x005046d0`, `0x005047e8-0x005047f0`, `0x00504b6b-0x00504b70`, `0x00504b8f-0x00504b90`, `0x00504df1-0x00504e00`, `0x00505075-0x00505080`, `0x00505124-0x00505130`, `0x0050516a-0x00505170`, `0x005051bb-0x005051c0`, `0x00505228-0x00505230`, `0x00505281-0x00505290`, `0x00505304-0x00505310`, `0x0050534d-0x00505350`, `0x0050536b-0x00505370`, `0x005055ca-0x005055d0`, `0x005055db-0x005055e0`, `0x00505645-0x00505650`, `0x00505731-0x00505740`, `0x0050593e-0x00505940`, `0x005059cb-0x005059d0`, `0x00505dfe-0x00505e00`, `0x005060e3-0x005060f0`, and `0x00506169-0x00506170` - alignment padding inside the MapPane weather/coordinate/object aggregate.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact MapPane child functions, not executable product logic.
  - Evidence: 2026-06-01 IDA MCP `py_eval` enumerated function starts/ends inside [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) and checked every listed span byte-for-byte as all `0xcc`. Non-`0xcc` gaps in the same aggregate were deliberately left out because they contain jump tables or additional raw/function-shaped code that still needs separate documentation.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md), [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](by-memory/0x00504530-0x005046c6.MapPaneCleanup.md), [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md), [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md), and [UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md).

- `0x0050637a-0x00506380` and `0x005063db-0x005063e0` - alignment padding around the MapPane opcode `0x0c` object-id packet helper.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-05-28 IDA MCP reports `sub_5062f0` ending at `0x0050637a`, proving `0x00506379` is the final `retn 4` immediate byte in [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md). IDA reports [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) as the next function, followed by five `0xcc` bytes before [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md), [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md), and [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md).

- `0x00506962-0x00506970` - alignment padding between `ProfileSidecarRefresh` and `MapPaneInputPacketRenderCore`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-05-28 IDA MCP reports `sub_5063e0` ending at `0x00506962`, `sub_506970` starting at `0x00506970`, no xrefs into the gap, and fourteen raw `0xcc` bytes from `0x00506962-0x00506970`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) and [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md).

- `0x00506cdd-0x00506ce0` and `0x00506d15-0x00506d20` - alignment padding around the MapPane target-selection hit-test helper.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes inside the MapPane input/packet/render aggregate, not executable product logic.
  - Evidence: 2026-06-01 IDA MCP reports [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) as `sub_506CE0`, size `0x35`; raw bytes show the prior return ending at `0x00506cdc`, three `0xcc` bytes before `0x00506ce0`, the helper ending at `0x00506d15`, and eleven `0xcc` bytes before `sub_506d20`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) and [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md).

- `0x0050e4b6-0x0050e4c0` - alignment padding after `MapPaneObjectEffectDescriptorDispatch`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-05-28 IDA MCP reports [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) as `sub_50e320` ending at `0x0050e4b6`, the next function [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md) starting at `0x0050e4c0`, and ten raw `0xcc` bytes in between.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) and [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md).

- `0x00514e1b-0x00514e20` - alignment padding after the MapPane scalar deleting destructor.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes, not executable product logic.
  - Evidence: 2026-06-01 IDA MCP reports `sub_514DE0` at `0x00514de0`, size `0x3b`; raw bytes show the final `retn 4` byte at `0x00514e1a`, five `0xcc` bytes at `0x00514e1b-0x00514e20`, and the next modeled function `sub_514E20` starting at `0x00514e20`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md).

- `0x005147cb-0x005147d0`, `0x005148d6-0x005148e0`, and `0x00514914-0x00514920` - alignment padding around the SelfSaveOKPane constructor and timer-facet island.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around exact SelfSaveOKPane methods, not executable product logic.
  - Evidence: 2026-06-01 IDA MCP reports [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) containing `sub_5147D0` size `0x106` and `sub_5148E0` size `0x34`; raw bytes show five `0xcc` bytes before `0x005147d0`, ten `0xcc` bytes between the constructor and timer function, and twelve `0xcc` bytes before `sub_514920`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) and [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md).

- `0x00520aa5-0x00520abb` and `0x00520b70-0x00520bab` - shared default dialog destructor glue.
  - Why ignored: compiler-generated/shared default destructor thunks and scalar deleting destructor body reused by many dialog vtables; not handwritten `PursuitMessageDialogPane` or message-dialog behavior.
  - Evidence: [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md) and [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md) record IDA MCP lookup/decompile/xref evidence. Vtable refs span `0x0061ec10-0x0061f4b8` and `0x00622428-0x00622c58`, plus thunk code refs from `0x00520aa5`, `0x00520ab0`, `0x005539c3`, and `0x005539ce`.
  - Replacement/procurement: no external dependency; generated by the compiler from shared dialog inheritance/default destructor layout.
  - Owner docs: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md), [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md), [UID:0000IT][DialogPane](by-file/DialogPane.md).

- `0x00520abb-0x00520ae7` - argumented/client-item/spell menu list secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into menu-list scalar deleting destructor paths; not handwritten menu-list row behavior.
  - Evidence: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) covers the argumented menu list thunks, and [UID:0001BY][0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks](by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md) records the shared `ClientItemMenuItemList` / spell-list thunk pair. [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md) records the vtable groups that reference this layout glue.
  - Replacement/procurement: no external dependency; generated by the compiler from menu-list inheritance/vtable layout.
  - Owner docs: [UID:0000HI][ArgumentedMenuDialogs](by-file/ArgumentedMenuDialogs.md), [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000O2][SpellMenuDialogs](by-file/SpellMenuDialogs.md), [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).

- `0x00520b13-0x00520b6b` - server-item and text-menu list/dialog secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ServerItemMenuItemList`, `TextInputMenuDialog`, `TextMenuDialog`, and `TextMenuItemList` destructor paths; not handwritten item/text menu behavior.
  - Evidence: [UID:0001BZ][0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks](by-memory/0x00520b13-0x00520b29.ServerItemMenuItemListDestructorThunks.md) and [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) record the exact thunk starts and vtable refs.
  - Replacement/procurement: no external dependency; generated by the compiler from menu dialog/list inheritance and vtable layout.
  - Owner docs: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md), [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md).

- `0x00530c78-0x00530c8e` - `NumberInputDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `NumberInputDialog` scalar deleting destructor `0x00530c90`; not handwritten numeric dialog behavior.
  - Evidence: [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x00620234` and `0x00620264`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `NumberInputDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000M1][NumberInputDialog](by-file/NumberInputDialog.md), [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md), [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md).

- `0x00545ddd-0x00545df3` - `EditablePaperPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `EditablePaperPane` scalar deleting destructor `0x00545e00`; not handwritten paper document behavior.
  - Evidence: [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) and [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md) record IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00621b60` and `0x00621b90`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `EditablePaperPane` inheritance/vtable layout.
  - Owner docs: [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md), [UID:000048][EditablePaperPane](by-class/EditablePaperPane.md), [UID:0001XF][EditablePaperPaneVtables](by-type/by-vtable/EditablePaperPaneVtables.md), [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md).

- `0x00556212-0x00556228` - `RightButtonMenuPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `RightButtonMenuPane` scalar deleting destructor `0x00556240`; not handwritten right-click menu behavior.
  - Evidence: [UID:0001G0][0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks](by-memory/0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks.md) records IDA MCP lookup/disassembly/decompile evidence. `0x00556212` subtracts `0xa0`, `0x0055621d` subtracts `0xa4`, and both jump to `0x00556240`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `RightButtonMenuPane` inheritance/vtable layout.
  - Owner docs: [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), [UID:0000C0][RightButtonMenuPane](by-class/RightButtonMenuPane.md), [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md).

- `0x0059efeb-0x0059f001` - `CheckBoxTextControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `CheckBoxTextControlPane` scalar deleting destructor `0x0059f050`; not handwritten checkbox/text control behavior.
  - Evidence: [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) records IDA MCP lookup/xref/vtable evidence. Data refs land at `0x0062ea04` and `0x0062ea34`, and the thunks forward into scalar deleting destructor `0x0059f050`.
  - Replacement/procurement: no external dependency; generated by the compiler from the multiple-inheritance vtable layout.
  - Owner docs: [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md), [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), [UID:0001KJ][0x0059ded0-0x0059f0a4.CheckBoxTextControlPane](by-memory/0x0059ded0-0x0059f0a4.CheckBoxTextControlPane.md).

- `0x00556228-0x0055623e` - `VoteMenuPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `VoteMenuPane` scalar deleting destructor `0x00556320`; not handwritten vote-popup behavior.
  - Evidence: [UID:0001G1][0x00556228-0x0055623e.VoteMenuPaneDestructorThunks](by-memory/0x00556228-0x0055623e.VoteMenuPaneDestructorThunks.md) records IDA MCP lookup/disassembly/decompile evidence. `0x00556228` subtracts `0xa0`, `0x00556233` subtracts `0xa4`, and both jump to `0x00556320`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `VoteMenuPane` inheritance/vtable layout.
  - Owner docs: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), [UID:0001G3][0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor](by-memory/0x00556320-0x005563cd.VoteMenuPaneScalarDeletingDestructor.md).

- `0x00555945-0x00555950`, `0x005559bc-0x005559c0`, `0x00555ad5-0x00555ae0`, `0x00555c68-0x00555c70`, `0x00555ce1-0x00555cf0`, `0x00556012-0x00556020`, and `0x005560fb-0x00556100` - `VoteMenuPane` internal alignment padding.
  - Why ignored: compiler/linker alignment bytes between exact `VoteMenuPane` method/helper bodies; not handwritten source.
  - Evidence: IDA MCP `lookup_funcs` on 2026-05-31 confirms adjacent exact function sizes, and IDA MCP `get_bytes` confirms every listed range is `0xcc` padding. Parent/child docs: [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md), [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md), [UID:0002LQ][0x005558d0-0x00555945.VoteMenuPaneRawConstructor](by-memory/0x005558d0-0x00555945.VoteMenuPaneRawConstructor.md), [UID:0002LR][0x00555950-0x005559bc.VoteMenuPaneDestructor](by-memory/0x00555950-0x005559bc.VoteMenuPaneDestructor.md), [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md), [UID:0002LT][0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss](by-memory/0x00555ae0-0x00555aef.VoteMenuPaneOnDismiss.md), [UID:0002LU][0x00555af0-0x00555c68.VoteMenuPaneOnPaint](by-memory/0x00555af0-0x00555c68.VoteMenuPaneOnPaint.md), [UID:0002LV][0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground](by-memory/0x00555c70-0x00555ce1.VoteMenuPaneDrawBackground.md), [UID:0002LW][0x00555cf0-0x00556012.VoteMenuPaneDrawBorder](by-memory/0x00555cf0-0x00556012.VoteMenuPaneDrawBorder.md), [UID:0002LX][0x00556020-0x0055606d.VoteMenuPaneGetItemRect](by-memory/0x00556020-0x0055606d.VoteMenuPaneGetItemRect.md), [UID:0002LY][0x00556070-0x005560fb.VoteMenuPaneHitTest](by-memory/0x00556070-0x005560fb.VoteMenuPaneHitTest.md), and [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md).
  - Replacement/procurement: no source migration; regenerated by compiler alignment.
  - Owner docs: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md), [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md), [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md).

- `0x00573273-0x005732b5` - group pane family secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `GroupPane2`, `GroupPane`, and `NewGroupPane` scalar deleting destructors; not handwritten group UI behavior.
  - Evidence: [UID:0001HM][0x00573273-0x005732b5.GroupPaneAdjustorThunks](by-memory/0x00573273-0x005732b5.GroupPaneAdjustorThunks.md) records IDA MCP disassembly and vtable-slot evidence. Each thunk subtracts `0xa0` or `0xa4` from `this` and jumps to scalar deleting destructor `0x005733e0`, `0x00573490`, or `0x00573570`.
  - Replacement/procurement: no external dependency; generated by the compiler from the group-pane multiple-inheritance vtable layout.
  - Owner docs: [UID:0000JS][Group](by-file/Group.md), [UID:00005Y][GroupPane](by-class/GroupPane.md), [UID:00005Z][GroupPane2](by-class/GroupPane2.md), [UID:000090][NewGroupPane](by-class/NewGroupPane.md), [UID:0001XP][GroupPaneFamilyVtables](by-type/by-vtable/GroupPaneFamilyVtables.md).

- `0x005732b5-0x00573302` - self-look/spelled-pane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `SelfLookPane2`, `SelfLookPane`, and `SpelledPane` scalar deleting destructors; not handwritten look/status UI behavior.
  - Evidence: [UID:0001HN][0x005732b5-0x00573302.LookPaneAdjustorThunks](by-memory/0x005732b5-0x00573302.LookPaneAdjustorThunks.md) records IDA MCP `py_eval` function enumeration/disassembly, and [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) records the owning vtables.
  - Replacement/procurement: no external dependency; generated by the compiler from look-pane inheritance/vtable layout.
  - Owner docs: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md), [UID:0000NZ][SpelledPane](by-file/SpelledPane.md), [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md).

- `0x00573247-0x00573273` - `CollectionPane` / `CollectionPane2` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into scalar deleting destructors, not handwritten collection UI behavior.
  - Evidence: [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md) records the IDA MCP disassembly: each helper subtracts `0xa0` or `0xa4` from `ecx` and jumps to `0x00573310` or `0x00573370`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `CollectionPane`/`CollectionPane2` inheritance and vtable layout.
  - Owner docs: [UID:0000IC][CollectionPane](by-file/CollectionPane.md), [UID:00002X][CollectionPane](by-class/CollectionPane.md), [UID:00002Y][CollectionPane2](by-class/CollectionPane2.md).

- `0x005729c3-0x005729e0`, `0x00573232-0x00573240`, `0x00573302-0x00573310`, `0x0057353d-0x00573540`, `0x00573564-0x00573570`, `0x0057399e-0x005739a0`, `0x005739f6-0x00573a00`, `0x00573d15-0x00573d20`, `0x005747df-0x005747e0`, `0x00574ad8-0x00574ae0`, `0x00574b83-0x00574b90` - alignment or compiler table bytes in the look/list/socket helper area.
  - Why ignored: IDA MCP confirms these spans are `0xcc`/alignment bytes, except `0x005729c3-0x005729e0`, which is a switch/jump-table tail plus alignment after `SelfLookPane2` code.
  - Evidence: 2026-05-28 IDA MCP `py_eval` byte/disassembly sweep over `0x005729c3-0x00574b90`; adjacent owner docs are [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md), [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md), [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md), [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md), and [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md).
  - Replacement/procurement: no external dependency; compiler/linker layout only.

- `0x00573c38-0x00573c4e` - `SimpleListPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `SimpleListPane` scalar deleting destructor `0x00573c50`; not handwritten list-control behavior.
  - Evidence: [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md) records IDA MCP lookup/decompile evidence. `0x00573c38` subtracts `0xa0`, `0x00573c43` subtracts `0xa4`, and both jump to `0x00573c50`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `SimpleListPane` inheritance/vtable layout.
  - Owner docs: [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md), [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md), [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md).

- `0x005538fe-0x00553914` - `HeadSelectDialog` secondary/tertiary adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks, not handwritten project logic. Final source should implement the destructor/scalar deleting destructor behavior, not reconstruct these tiny adjustment stubs as feature methods.
  - Evidence: [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) records IDA `lookup_funcs` and disassembly: `0x005538fe` subtracts `0xa0`, `0x00553909` subtracts `0xa4`, and both jump to `0x00553920`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `HeadSelectDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md).

- `0x0054b4f0-0x0054b51c` - `PowerDialogPane` / `PowerListPane` secondary/tertiary adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks, not handwritten power-dialog or embedded-list behavior. Final source should model the dialog/list destructors and inheritance layout, not reconstruct these tiny stubs.
  - Evidence: [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) records IDA MCP evidence: all four starts are real `0xb` functions, vtable refs land at `0x006221b8`, `0x006221e8`, `0x0062227c`, and `0x006222ac`, and each body forwards to the scalar deleting destructor after a `this - 0xa0` or `this - 0xa4` adjustment.
  - Replacement/procurement: no external dependency; generated by the compiler from `PowerDialogPane` / `PowerListPane` inheritance and vtable layout.
  - Owner docs: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md), [UID:0000AP][PowerDialogPane](by-class/PowerDialogPane.md), [UID:0000AQ][PowerListPane](by-class/PowerListPane.md).

- `0x00549b4d-0x00549b63` - `PictureViewPane` secondary/tertiary adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks. The source should model the `PictureViewPane` destructor and inheritance layout, not handwritten thunk functions.
  - Evidence: [UID:0001F3][0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks](by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md) records IDA lookup/disassembly: `0x00549b4d` subtracts `0xa0`, `0x00549b58` subtracts `0xa4`, and both jump to `0x00549b70`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `PictureViewPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MK][PhotoPane](by-file/PhotoPane.md), [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md).

- `0x005499a2-0x005499b8` - `PhotoPane` secondary/tertiary adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks. The source should model the `PhotoPane` destructor and inheritance layout, not handwritten thunk functions.
  - Evidence: [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md) records IDA lookup/disassembly: `0x005499a2` subtracts `0xa0`, `0x005499ad` subtracts `0xa4`, and both jump to `0x005499c0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `PhotoPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MK][PhotoPane](by-file/PhotoPane.md), [UID:0000AG][PhotoPane](by-class/PhotoPane.md).

- `0x00502550-0x00502566` - `ScrolledPictureControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks that dispatch to the real scalar deleting destructor at `0x00502ab0`.
  - Evidence: [UID:0001AD][0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks](by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md) records IDA lookup/disassembly: `0x00502550` subtracts `0xa0`, `0x0050255b` subtracts `0xa4`, and both jump to `0x00502ab0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ScrolledPictureControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000NH][ScrolledPictureControlPane](by-file/ScrolledPictureControlPane.md), [UID:0000CH][ScrolledPictureControlPane](by-class/ScrolledPictureControlPane.md).

- `0x005226f0-0x005226fb` - `MessageShowPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pMessageShowPane` during constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001C5][0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH](by-memory/0x005226f0-0x005226fb.MessageShowPaneClearSingletonEH.md) records the single write to `0x0069b4f4`, no ordinary callers, and the constructor EH/unwind xref.
  - Replacement/procurement: no external dependency; generated from the `MessageShowPane` constructor/lifetime cleanup.
  - Owner docs: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), [UID:000087][MessageShowPane](by-class/MessageShowPane.md), [UID:0000RK][g_pMessageShowPane](by-global/g_pMessageShowPane.md).

- `0x005226fb-0x00522711` - `MessageShowPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `MessageShowPane` scalar deleting destructor `0x00522720`; not handwritten overlay logic.
  - Evidence: [UID:0001C6][0x005226fb-0x00522711.MessageShowPaneAdjustorThunks](by-memory/0x005226fb-0x00522711.MessageShowPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence and current disabled-output behavior.
  - Replacement/procurement: no external dependency; generated by the compiler from the `MessageShowPane` inheritance/vtable layout.
  - Owner docs: [UID:0000LB][MessageShowPane](by-file/MessageShowPane.md), [UID:000087][MessageShowPane](by-class/MessageShowPane.md), [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md).

- `0x0058aa90-0x0058aa9b` - `ForcedInformMessageDialog` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pForcedInformMessageDialog` during constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) records IDA MCP lookup/decompile/xref evidence: the body only writes zero to `0x0069b4a0`, has no ordinary callers, and has a constructor-context unwind xref at `0x00608f3b`.
  - Replacement/procurement: no external dependency; generated from the `ForcedInformMessageDialog` constructor/lifetime cleanup.
  - Owner docs: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md), [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md), [UID:0000QY][g_pForcedInformMessageDialog](by-global/g_pForcedInformMessageDialog.md).

- `0x0058aadb-0x0058aaf1` - `ForcedInformMessageDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ForcedInformMessageDialog` scalar deleting destructor `0x0058abf0`; not handwritten forced-inform dialog behavior.
  - Evidence: [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062d778` and `0x0062d7a8`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ForcedInformMessageDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md), [UID:00005E][ForcedInformMessageDialog](by-class/ForcedInformMessageDialog.md), [UID:0001JA][0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor](by-memory/0x0058abf0-0x0058acb2.ForcedInformMessageDialogDestructor.md).

- `0x0058dbe0-0x0058dbeb` - `TerminalPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pTerminalPane` during `TerminalPane` constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0001JI][0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md) records the single write to `0x0069bdf8`, no ordinary callers, and the constructor unwind xref at `0x00609241`.
  - Replacement/procurement: no external dependency; generated from the `TerminalPane` constructor/lifetime cleanup.
  - Owner docs: [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000EG][TerminalPane](by-class/TerminalPane.md), [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md).

- `0x0058dbeb-0x0058dc00` - `DialDialog` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `DialDialog` scalar deleting destructor `0x0058dc20`; not handwritten dial-dialog logic.
  - Evidence: [UID:0001JJ][0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062dda4` and `0x0062ddd4`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `DialDialog` inheritance/vtable layout.
  - Owner docs: [UID:0000MJ][PhoneBookDialog](by-file/PhoneBookDialog.md), [UID:00003R][DialDialog](by-class/DialDialog.md), [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md).

- `0x0058dc01-0x0058dc16` - `TerminalPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `TerminalPane` scalar deleting destructor `0x0058dc60`; not handwritten terminal-pane logic.
  - Evidence: [UID:0001JK][0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc16.TerminalPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062da70` and `0x0062daa0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `TerminalPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OI][TerminalPane](by-file/TerminalPane.md), [UID:0000EG][TerminalPane](by-class/TerminalPane.md), [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md).

- `0x00584d7e-0x00584d80`, `0x00584e9e-0x00584ea0`, `0x0058af3b-0x0058af40`, `0x0058af48-0x0058af50`, `0x0058d74c-0x0058d750`, `0x0058dc5b-0x0058dc60`, `0x0058dca5-0x0058dcb0`, `0x0058dcd3-0x0058dce0`, `0x005958fe-0x00595900`, `0x00595f26-0x00595f30`, and `0x00596242-0x00596250` - small alignment padding spans resolved from former UNKNOWN rows.
  - Why ignored: confirmed `0xcc` alignment padding between IDA-confirmed function/helper boundaries; no handwritten source logic.
  - Evidence: 2026-05-28 IDA MCP function-boundary and raw-byte pass around `0x00584d7d-0x00584ea0`, `0x0058af3b-0x0058af50`, `0x0058d74b-0x0058dce0`, `0x005958fd-0x00595900`, and `0x00595f26-0x00596250`.
  - Replacement/procurement: no external dependency; generated by compiler/linker code alignment.
  - Owner docs: [UID:0001J3][0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.LObjectStringReleaseFormatAndMutation.md), [UID:0001J5][0x00584d80-0x00584e9e.StringIter](by-memory/0x00584d80-0x00584e9e.StringIter.md), [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md), [UID:000246][0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual](by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md), [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md), [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md), [UID:000247][0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor](by-memory/0x0058dc60-0x0058dca5.TerminalPaneScalarDeletingDestructor.md), [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md), [UID:0001JU][0x00595760-0x005958fe.TextFilterAndSanitizer](by-memory/0x00595760-0x005958fe.TextFilterAndSanitizer.md), [UID:0001JV][0x00595900-0x00596242.TextPad](by-memory/0x00595900-0x00596242.TextPad.md), and [UID:000248][0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers](by-memory/0x00595f30-0x00596242.TextPadStandaloneFileAndInsertHelpers.md).

- `0x0059bc2d-0x0059bc43` - `UserInfoDialogPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `UserInfoDialogPane` scalar deleting destructor `0x0059bc50`; not handwritten account-info form behavior.
  - Evidence: [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062e688` and `0x0062e6b8`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `UserInfoDialogPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md), [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md), [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md).

- `0x004f2e59-0x004f2e9a` - reusable input-pane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into the `LineInputPane`, `CharInputPane`, and `ConfirmInputPane` scalar deleting destructors; not handwritten prompt, key-input, or confirmation behavior.
  - Evidence: [UID:00018Z][0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9a.InputPaneBaseAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. The thunks subtract `0xa0` or `0xa4` from `ecx` and tail-jump to `0x004f2ea0`, `0x004f2f70`, or `0x004f2fb0`.
  - Replacement/procurement: no external dependency; generated by the compiler from the reusable input-pane inheritance/vtable layout.
  - Owner docs: [UID:0000K7][InputPanes](by-file/InputPanes.md), [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), [UID:000077][LineInputPane](by-class/LineInputPane.md), [UID:00001P][CharInputPane](by-class/CharInputPane.md), [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md).

- `0x005b77c8-0x005b77de` - shared input-pane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into shared scalar deleting destructor `0x005b7940`; not handwritten item, command, spell, or target-input pane behavior.
  - Evidence: [UID:0001N6][0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks](by-memory/0x005b77c8-0x005b77de.SharedInputPaneAdjustorThunks.md) records IDA MCP disassembly and broad vtable xrefs. `0x005b77c8` subtracts `0xa0`, `0x005b77d3` subtracts `0xa4`, and both jump to `0x005b7940`.
  - Replacement/procurement: no external dependency; generated by the compiler from the input-pane inheritance/vtable layout.
  - Owner docs: [UID:0000K7][InputPanes](by-file/InputPanes.md), [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md).

- `0x005b7836-0x005b784c` - `QuitInputPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `QuitInputPane` scalar deleting destructor `0x005b7b30`; not handwritten typed quit-prompt behavior.
  - Evidence: [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062f0a4` and `0x0062f0d4`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `QuitInputPane` inheritance/vtable layout.
  - Owner docs: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md), [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md).

- `0x005b7862-0x005b7878` - `SelectObjectWithKeyboardPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `SelectObjectWithKeyboardPane` scalar deleting destructor `0x005b7bc0`; not handwritten target-selection behavior.
  - Evidence: [UID:0001N8][0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062f378` and `0x0062f3a8`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `SelectObjectWithKeyboardPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), [UID:0000CT][SelectObjectWithKeyboardPane](by-class/SelectObjectWithKeyboardPane.md), [UID:0001ND][0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md).

- `0x005b7878-0x005b78fc` - spell argument input pane secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into the `SpellFourArgsInputPane`, `SpellOneArgInputPane`, `SpellSlotInputPane`, `SpellStringInputPane`, `SpellThreeArgsInputPane`, and `SpellTwoArgsInputPane` scalar deleting destructors; not handwritten spell argument behavior.
  - Evidence: [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land in the spell input vtable block at `0x0062f1d4-0x0062f6f0`.
  - Replacement/procurement: no external dependency; generated by the compiler from spell input pane inheritance/vtable layouts.
  - Owner docs: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md), [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md), [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md), [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md), [UID:0000DU][SpellStringInputPane](by-class/SpellStringInputPane.md), [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md), [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md).

- `0x005b78fc-0x005b7912` - `SpellWhoInputPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `SpellWhoInputPane` scalar deleting destructor `0x005b8100`; not handwritten spell-target selection behavior.
  - Evidence: [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062f260` and `0x0062f290`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `SpellWhoInputPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), [UID:0000DX][SpellWhoInputPane](by-class/SpellWhoInputPane.md), [UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md).

- `0x005ae372-0x005ae380`, `0x005ae403-0x005ae410`, `0x005aea53-0x005aea60`, `0x005aeaf3-0x005aeb00`, and `0x005b81c4-0x005b81d0` - `SpellWhoInputPane` alignment padding.
  - Why ignored: confirmed `0xcc` compiler alignment between exact `SpellWhoInputPane` bodies and after the scalar deleting destructor; no handwritten source semantics.
  - Evidence: 2026-06-02 IDA MCP raw-byte check shows each listed range is all `0xcc`; disassembly shows alignment directives at the same boundaries.
  - Replacement/procurement: compiler/linker-generated alignment.
  - Owner docs: [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md), [UID:0001NK][0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor](by-memory/0x005b8100-0x005b81c4.SpellWhoInputPaneScalarDeletingDestructor.md).

- `0x005ae68a-0x005ae730` - `SpellWhoInputPane` key-handler switch support table.
  - Why ignored: compiler-generated switch/jump-table support bytes for [UID:0001L0][0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput](by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md), not a standalone handwritten function.
  - Evidence: 2026-06-02 IDA MCP raw bytes and disassembly label the span as `jpt_5AE45D` / `byte_5AE6A4` followed by alignment before `0x005ae730`.
  - Replacement/procurement: compiler-generated table from the key-handler switch.
  - Owner docs: [UID:0001L0][0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput](by-memory/0x005ae410-0x005ae68a.SpellWhoInputPaneKeyNavigationInput.md), [UID:0001KY][0x005ae2a0-0x005aeb1f.SpellWhoInputPane](by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md).

- `0x005aed3d-0x005aed40`, `0x005aedcb-0x005aedd0`, `0x005af2e7-0x005af2f0`, `0x005af383-0x005af390`, `0x005af3af-0x005af3b0`, `0x005af4ef-0x005af4f0`, `0x005af57b-0x005af580`, `0x005af5ea-0x005af5f0`, and `0x005b7aec-0x005b7af0` - `ItemWhoInputPane` and target-selection alignment padding.
  - Why ignored: confirmed `0xcc` compiler alignment between exact `ItemWhoInputPane` and target-selection bodies and after the scalar deleting destructor; no handwritten source semantics.
  - Evidence: 2026-06-02 IDA MCP raw-byte check shows each listed range is all `0xcc`; `lookup_funcs` confirms the neighboring function end/start boundaries.
  - Replacement/procurement: compiler/linker-generated alignment.
  - Owner docs: [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), [UID:0001L8][0x005af390-0x005b050d.TargetSelectionInputPanes](by-memory/0x005af390-0x005b050d.TargetSelectionInputPanes.md), [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md), [UID:0001L9][0x005af4f0-0x005af57b.SendTargetedActionPacket](by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md), [UID:0001LA][0x005af580-0x005af5ea.SendObjectActionPacket](by-memory/0x005af580-0x005af5ea.SendObjectActionPacket.md), [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md).

- `0x005aefaf-0x005af050` - `ItemWhoInputPane` key-handler switch support table.
  - Why ignored: compiler-generated switch/jump-table support bytes for [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md), not a standalone handwritten function.
  - Evidence: 2026-06-02 IDA MCP raw bytes show table data followed by alignment, and disassembly at `0x005aefaf` labels a jump table plus indirect table for the preceding switch before the mouse handler starts at `0x005af050`.
  - Replacement/procurement: compiler-generated table from the key-handler switch.
  - Owner docs: [UID:0001L4][0x005aec60-0x005af2e7.ItemWhoInputPane](by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md), [UID:0002S2][0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput](by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md).

- `0x005b780a-0x005b7820` - `ItemWhoInputPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ItemWhoInputPane` scalar deleting destructor `0x005b7a20`; not handwritten item-target selection behavior.
  - Evidence: 2026-06-02 IDA MCP `lookup_funcs`, `disasm`, and `xrefs_to` show `0x005b780a` subtracts `0xa0` then jumps to `0x005b7a20`, `0x005b7815` subtracts `0xa4` then jumps to `0x005b7a20`, and data refs land at `0x0062f2ec` and `0x0062f31c`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ItemWhoInputPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), [UID:0002S4][0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor](by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md).

- `0x005b7912-0x005b7928` - `TargetObjectWithKeyboardPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `TargetObjectWithKeyboardPane` scalar deleting destructor `0x005b81d0`; not handwritten target-dispatch selection behavior.
  - Evidence: [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. Data refs land at `0x0062f404` and `0x0062f434`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `TargetObjectWithKeyboardPane` inheritance/vtable layout.
  - Owner docs: [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md), [UID:0000ED][TargetObjectWithKeyboardPane](by-class/TargetObjectWithKeyboardPane.md), [UID:0001NL][0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor](by-memory/0x005b81d0-0x005b822f.TargetObjectWithKeyboardPaneScalarDeletingDestructor.md).

- `0x0049d81e-0x0049d834` - `DescPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `DescPane` scalar deleting destructor `0x0049d840`; not handwritten description-pane behavior.
  - Evidence: [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) and [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) record IDA MCP lookup/decompile/xref evidence. Data refs land at `0x00618a28` and `0x00618a58`, and current disabled simroot output still omits the second thunk body.
  - Replacement/procurement: no external dependency; generated by the compiler from the `DescPane` inheritance/vtable layout.
  - Owner docs: [UID:0000IS][DescPane](by-file/DescPane.md), [UID:00003Q][DescPane](by-class/DescPane.md), [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md).

- `0x0048c27b-0x0048c290` - `DialogPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `DialogPane` scalar deleting destructor `0x0048c350`; not handwritten dialog behavior.
  - Evidence: [UID:00010U][0x0048c27b-0x0048c290.DialogPaneAdjustorThunks](by-memory/0x0048c27b-0x0048c290.DialogPaneAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00618ac4` and `0x00618af4`; current disabled simroot output still marks `0x0048c27b` as missing code.
  - Replacement/procurement: no external dependency; generated by the compiler from the `DialogPane` inheritance/vtable layout.
  - Owner docs: [UID:0000IT][DialogPane](by-file/DialogPane.md), [UID:00003T][DialogPane](by-class/DialogPane.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md), [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md).

- `0x004a146f-0x004a149b` - `DialogInSession` and `DialogSession` destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `DialogInSession` scalar deleting destructor `0x004a14a0` and `DialogSession` scalar deleting destructor `0x004a1500`; not handwritten session stack behavior.
  - Evidence: [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00618e18`, `0x00618e48`, `0x00618d7c`, and `0x00618dac`; current metadata still reports `vtable_count: 0` for both classes.
  - Replacement/procurement: no external dependency; generated by the compiler from the `DialogInSession`/`DialogSession` inheritance and vtable layout.
  - Owner docs: [UID:0000IU][DialogSession](by-file/DialogSession.md), [UID:00003U][DialogSession](by-class/DialogSession.md), [UID:00003S][DialogInSession](by-class/DialogInSession.md), [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md).

- `0x0049af3d-0x0049af52` - `ControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `ControlPane` scalar deleting destructor `0x0049b170`; not handwritten control behavior.
  - Evidence: [UID:000120][0x0049af3d-0x0049af52.ControlPaneAdjustorThunks](by-memory/0x0049af3d-0x0049af52.ControlPaneAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00617af8` and `0x00617b28`; current disabled simroot output still marks `0x0049af3d` as missing code.
  - Replacement/procurement: no external dependency; generated by the compiler from the `ControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000IG][ControlPane](by-file/ControlPane.md), [UID:000038][ControlPane](by-class/ControlPane.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md), [UID:000114][0x004949e0-0x00494bf6.ControlPane](by-memory/0x004949e0-0x00494bf6.ControlPane.md).

- `0x0049af27-0x0049af3d` - `CheckBoxControlPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `CheckBoxControlPane` scalar deleting destructor `0x0049b110`; not handwritten checkbox behavior.
  - Evidence: [UID:00011Z][0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks](by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence. `0x0049af27` adjusts `this - 0xa0`, `0x0049af32` adjusts `this - 0xa4`, and both forward to `0x0049b110`.
  - Replacement/procurement: no external dependency; generated by the compiler from the `CheckBoxControlPane` inheritance/vtable layout.
  - Owner docs: [UID:0000I7][CheckBoxControlPane](by-file/CheckBoxControlPane.md), [UID:000021][CheckBoxControlPane](by-class/CheckBoxControlPane.md), [UID:0001X8][CheckBoxControlPaneVtables](by-type/by-vtable/CheckBoxControlPaneVtables.md), [UID:00011Y][0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors](by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md).

- `0x005450ef-0x00545104` - `PanelPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `PanelPane` scalar deleting destructor `0x00545110`; not handwritten panel behavior.
  - Evidence: [UID:0001ED][0x005450ef-0x00545104.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00621ac0` and `0x00621af0`; current disabled simroot output still marks `0x005450ef` as missing code.
  - Replacement/procurement: no external dependency; generated by the compiler from the `PanelPane` inheritance/vtable layout.
  - Owner docs: [UID:0000ME][PanelPane](by-file/PanelPane.md), [UID:0000A4][PanelPane](by-class/PanelPane.md), [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md), [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md).

- `0x00544f2e-0x00544f43` - `Pane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `Pane` scalar deleting destructor `0x00544f50`; not handwritten pane behavior.
  - Evidence: [UID:0001EB][0x00544f2e-0x00544f43.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence. Data refs land at `0x00621a34` and `0x00621a64`; current disabled simroot output still marks `0x00544f39` as missing code.
  - Replacement/procurement: no external dependency; generated by the compiler from the `Pane` inheritance/vtable layout.
  - Owner docs: [UID:0000MC][Pane](by-file/Pane.md), [UID:0000A2][Pane](by-class/Pane.md), [UID:0001YC][PaneCoreVtableFamily](by-type/by-vtable/PaneCoreVtableFamily.md), [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md).

- `0x00546e8b-0x00546ecd` - parcel notification secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into the `FlyingParcelPane`, `ParcelIconPane`, and `ParcelPane` scalar deleting destructors; not handwritten parcel notification behavior.
  - Evidence: [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md) records IDA MCP lookup/disasm/xref evidence, and [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from parcel pane inheritance/vtable layout.
  - Owner docs: [UID:0000MF][ParcelPane](by-file/ParcelPane.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md), [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md).

- `0x005484db-0x005484f0` - `PatchPane` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `PatchPane` scalar deleting destructor `0x00548560`; not handwritten patch/update behavior.
  - Evidence: [UID:0001EU][0x005484db-0x005484f0.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f0.PatchPaneAdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `PatchPane` inheritance/callback layout.
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000A9][PatchPane](by-class/PatchPane.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x005474e6-0x005474f0` and `0x00547850-0x00547860` - `PatchPane` packet-response handler alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around the real packet-response callback at `0x005474f0-0x00547850`.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports previous destructor `sub_5473F0` ending at `0x005474e6`, packet handler `sub_5474F0` spanning `0x005474f0-0x00547850`, no function at `0x00547850`, and next function `sub_547860` beginning at `0x00547860`; raw-byte review shows both intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000A9][PatchPane](by-class/PatchPane.md), [UID:0001ER][0x005474f0-0x00547850.PatchPanePacketResponseHandler](by-memory/0x005474f0-0x00547850.PatchPanePacketResponseHandler.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x00548a7d-0x00548a80` and `0x00548f1a-0x00548f30` - `PatchPane2` main-loop alignment and switch table.
  - Why ignored: compiler-generated alignment and switch dispatch data around the real `PatchPane2` main loop, not handwritten source code.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_548A80` spanning `0x00548a80-0x00548f1a`, no function at `0x00548f1a`, and `sub_548F30` beginning at `0x00548f30`; disassembly shows `0x00548a7d-0x00548a80` alignment before the handler, plus `0x00548f1a-0x00548f1c` alignment and `0x00548f1c-0x00548f30` as the `jpt_548AD9` jump table referenced by `0x00548ad9`.
  - Replacement/procurement: generated naturally from the C++ switch in [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md).
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0001EV][0x00548a80-0x00548f1a.PatchPane2MainLoop](by-memory/0x00548a80-0x00548f1a.PatchPane2MainLoop.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x00548f41-0x00548f50` - `PatchPane2` work-event predicate to close-file helper alignment.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the real predicate helper and the real active-file close helper.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_548F30` spanning `0x00548f30-0x00548f41`, no function at `0x00548f41`, and `sub_548F50` beginning at `0x00548f50`; raw-byte review shows the intervening bytes are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x0054901f-0x00549020` and `0x00549214-0x00549220` - `PatchPane2` helper alignment around raw advance and close/rename helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around real `PatchPane2` helper bodies.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_548F80` ending at `0x0054901f`, no modeled function at `0x00549020` despite real raw helper bytes through `0x00549080`, `sub_549080` spanning `0x00549080-0x00549214`, no function at `0x00549214`, and `sub_549220` beginning at `0x00549220`; raw-byte review confirms both listed gaps are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0002R7][0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw](by-memory/0x00549020-0x00549080.PatchPane2AdvanceDownloadIndexRaw.md), [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x0054934b-0x00549360` - `PatchPane2` secondary/tertiary destructor adjustor thunks.
  - Why ignored: compiler-generated vtable adjustor thunks into `PatchPane2` scalar deleting destructor `0x00549370`; not handwritten patch/download behavior.
  - Evidence: [UID:0001F0][0x0054934b-0x00549360.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549360.PatchPane2AdjustorThunks.md) records IDA MCP lookup/decompile/xref evidence, and [UID:0001YF][PatchPaneVtableFamily](by-type/by-vtable/PatchPaneVtableFamily.md) records the owning vtable slots.
  - Replacement/procurement: no external dependency; generated by the compiler from the `PatchPane2` inheritance/callback layout.
  - Owner docs: [UID:0000MH][PatchPane](by-file/PatchPane.md), [UID:0000AA][PatchPane2](by-class/PatchPane2.md), [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md).

- `0x005c5c87-0x005cea43` - MSVC runtime, STL support, and import jump thunk island.
  - Why ignored: import thunks and compiler/runtime helper bodies are not handwritten NexusTK product source. The preceding project-owned `WorldMapPane` helper ends at `0x005c5c87`.
  - Evidence: [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md) records IDA MCP enumeration of DirectDraw/VERSION/IMM/libcurl jump thunks and MSVC CRT/STL helpers including exception, locale, iostream, startup, security-cookie, invalid-parameter, and integer parsing support.
  - Replacement/procurement: supplied by the selected compiler/runtime model and import libraries during rebuild. Do not reconstruct this block as product code; rebuild equivalent project calls and let toolchain/runtime linkage provide the support code.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md), and [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md).

- `0x005cea43-0x005cea6d` - CRT `__wtol` wrapper.
  - Why ignored: Microsoft Visual C runtime wrapper for wide string to long conversion, not NexusTK product source and not a `SpellOneArgInputPane` method.
  - Evidence: [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) records IDA MCP `unknown_libname_24` lookup/decompile evidence and broad runtime caller fanout.
  - Replacement/procurement: supplied by the compiler/runtime library during rebuild; call `_wtol`/`wcstol` through the normal CRT instead of reconstructing this function as project code.
  - Owner docs: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md), [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md), [wave3 data issues](../wave3_data_issues.md).

- `0x005cea6d-0x005f66f7` - MSVC/ACRT stdio, locale, heap, lowio, math, and string support.
  - Why ignored: statically linked Microsoft runtime/library implementation, not handwritten NexusTK product source.
  - Evidence: [UID:00024C][0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport](by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md) records IDA MCP enumeration of 1009 function starts, including `common_vsnprintf_s`, `formatting_buffer`, `__acrt_stdio_char_traits`, `_malloc`, `__initterm`, `__control87`, `__sopen_nolock`, and `_strrchr`.
  - Replacement/procurement: supplied by the selected MSVC-era runtime/toolchain model during rebuild.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md).

- `0x005f66f7-0x0060c0a0` - MSVC SEH/EH funclet island.
  - Why ignored: compiler-generated exception/unwind cleanup fragments and handler labels, not standalone source functions.
  - Evidence: [UID:00024D][0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland](by-memory/0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md) records IDA MCP evidence for zero function starts but 25,367 heads, including `SEH_...` labels and data xrefs from many owning functions/EH tables.
  - Replacement/procurement: regenerate from source-level object lifetimes, destructors, and exception paths through the compiler.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md).

- `0x0060c0a0-0x0060c0f0` - static cleanup thunks before `AutoInit`.
  - Why ignored: compiler-generated `atexit` cleanup thunks and alignment bytes for static objects at `unk_67A780`, `dword_67A998`/`Block`, and `stru_67A9A4`; not standalone handwritten source.
  - Evidence: [UID:00024E][0x0060c0a0-0x0060c0f0.StaticCleanupThunksBeforeAutoInit](by-memory/0x0060c0a0-0x0060c0f0.StaticCleanupThunksBeforeAutoInit.md) records IDA disassembly/decompilation/xref evidence for `sub_60C0A0`, `sub_60C0B0`, and `sub_60C0E0`, plus `0xcc` alignment gaps.
  - Replacement/procurement: express the source-level static object declarations and teardown ownership; let the compiler produce the cleanup thunks.
  - Owner docs: [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md).

- `0x00680067` and `0x00690052` - false `DeleteFromBlockListenInputPane` generated method starts.
  - Why ignored: not executable functions or reconstructable project code. These are bogus address-like values read out of UTF-16 string/data bytes and should not drive class or method reconstruction.
  - Evidence: IDA MCP `lookup_funcs` reports both addresses as `Not a function`; `xrefs_to` reports only data references. [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) records the string-data origin from `"Right click look :ON"` / `"Right click look :OFF"` at `0x006307ec`, `0x006307f0`, `0x00630818`, and `0x0063081c`.
  - Replacement/procurement: remove/quarantine the false method rows from `DeleteFromBlockListenInputPane`; keep the real class code at `0x005b7100-0x005b7354`.
  - Owner docs: [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), [UID:00003N][DeleteFromBlockListenInputPane](by-class/DeleteFromBlockListenInputPane.md), [wave3 data issues](../wave3_data_issues.md).

- `0x00502420-0x0050245e` - `UserPane` constructor-failure pool-free wrapper.
  - Why ignored: compiler-generated cleanup/delete wrapper around the class-specific [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md) free path, not a handwritten `UserPane` method.
  - Evidence: [UID:0001AA][0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper](by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md) records IDA MCP lookup/disassembly/decompile evidence. The body frees through `0x004b14c0` on pool `0x0069bf34`, and xrefs come from EH funclets attached to `InitializeMainUiGraph`.
  - Replacement/procurement: no external dependency; reconstruct as `UserPane` pool allocation/delete policy using the [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), then let the compiler emit constructor-failure cleanup.
  - Owner docs: [UID:0000P1][UserPane](by-file/UserPane.md), [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md).

- `0x00514ae0-0x00514d1e` - object-pane constructor-failure pool-free wrapper strip.
  - Why ignored: compiler-generated cleanup/delete wrappers around object-pane class-specific pool frees, not standalone handwritten object-pane methods.
  - Evidence: [UID:0001B3][0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers](by-memory/0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers.md) records IDA MCP lookup/disassembly/decompile/xref evidence for the nine `0x3e`-byte wrappers. Each wrapper frees through `0x004b14c0` on the corresponding object-pane pool.
  - Replacement/procurement: no external dependency; reconstruct as object-pane pool allocation/delete policy near the owning object-pane modules.
  - Owner docs: [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md), [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md).

- `0x0053ce50-0x0053ce8e` - `Motion` constructor-failure pool-free wrapper.
  - Why ignored: compiler-generated cleanup/delete wrapper around the `Motion` animation-object pool free path, not a handwritten `Motion` method.
  - Evidence: [UID:0001DK][0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper](by-memory/0x0053ce50-0x0053ce8e.MotionPoolFreeUnwindWrapper.md) records IDA MCP lookup/disassembly/decompile evidence. The body frees through `0x004b14c0` on pool `0x0069b984`, and the only xref is an EH funclet attached to the `0x0053b3d0` construction path.
  - Replacement/procurement: no external dependency; reconstruct as `Motion` animation-object pool allocation/delete policy using the [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md).
  - Owner docs: [UID:00008R][Motion](by-class/Motion.md), [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md), [UID:000153][0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront](by-memory/0x004b14c0-0x004b14ef.ThreadSafeNodeListPushFront.md).

- `0x0041a040-0x0041a27d` - object/string `PoolAllocator` static constructor wrappers.
  - Why ignored: compiler-generated static-initialization wrappers that call `PoolAllocator::PoolAllocator` and register matching `atexit` cleanup; not handwritten product source.
  - Evidence: [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md) records IDA MCP lookup/decompile evidence for eighteen wrappers and the exact pool/block-size arguments.
  - Replacement/procurement: no external dependency; declare the concrete static pool globals near their owning modules and let compiler static initialization generate these wrappers.
  - Owner docs: [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md), [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md).

- `0x0041a27d-0x0041a280` - alignment padding after object/string `PoolAllocator` static constructor wrappers.
  - Why ignored: confirmed empty `0xcc` alignment padding with no IDA function objects; not executable product source.
  - Evidence: 2026-05-27 IDA MCP `py_eval` byte/function audit reports `.text` bytes `cc cc cc`, `pad_only=true`, and no functions in the span.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md), [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).

- `0x0041a4a8-0x0041a4b0` - alignment padding before the `UserPane` pool static constructor wrapper.
  - Why ignored: confirmed empty `0xcc` alignment padding with no IDA function objects; not executable product source.
  - Evidence: 2026-05-27 IDA MCP `py_eval` byte/function audit reports eight `.text` bytes of `0xcc`, `pad_only=true`, and no functions in the span.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md), [UID:0000WE][0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper](by-memory/0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md).

- `0x0041a4b0-0x0041a4cd` - `UserPane` pool static constructor wrapper.
  - Why ignored: compiler-generated static-initialization wrapper for the large `UserPane` pool at `0x0069bf34`; not handwritten product source.
  - Evidence: [UID:0000WE][0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper](by-memory/0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md) records IDA MCP lookup/decompile evidence and the matching cleanup wrapper at `0x0060c450`.
  - Replacement/procurement: no external dependency; declare the static `UserPane` pool near [UID:0000P1][UserPane](by-file/UserPane.md).
  - Owner docs: [UID:0000P1][UserPane](by-file/UserPane.md), [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:0001OA][0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper](by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md).

- `0x0041a4cd-0x0041a550` - static runtime initializer wrappers after the `UserPane` pool static constructor.
  - Why ignored: compiler/runtime static-initialization and `atexit` wrapper island with alignment padding; not standalone handwritten product logic.
  - Evidence: [UID:0000WF][0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool](by-memory/0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md) records IDA MCP byte/function audit, decompilation, startup table xrefs, and paired cleanup thunk behavior.
  - Replacement/procurement: runtime, standard-library, and platform static state should be supplied by the compiler/runtime and source-level static declarations, not hand-reconstructed as NexusTK feature code.

- `0x0041a5c1-0x0041a5d0` - alignment padding before `CashShopRequest` setup.
  - Why ignored: confirmed empty `0xcc` alignment padding with no IDA function objects; not executable product source.
  - Evidence: 2026-05-27 IDA MCP `py_eval` byte/function audit reports fifteen `.text` bytes of `0xcc`, `pad_only=true`, and no functions in the span.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), [UID:0000WH][0x0041a5d0-0x0041b5da.CashShopRequestItemSetup](by-memory/0x0041a5d0-0x0041b5da.CashShopRequestItemSetup.md).

- `0x0041b69f-0x0041b6a0` - alignment padding before the CFG guard-check no-op.
  - Why ignored: confirmed `0xcc` alignment byte between `FileDownloader` teardown and the next tiny runtime helper.
  - Evidence: 2026-05-27 IDA MCP `py_eval` byte audit reports byte `0xcc` at `0x0041b69f`, rendered as `align 10h`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:0000WI][0x0041a670-0x0041b69f.FileDownloaderDispatch](by-memory/0x0041a670-0x0041b69f.FileDownloaderDispatch.md).

- `0x0041b6a0-0x0041b6a1` - CFG indirect-call guard check no-op.
  - Why ignored: MSVC compiler/runtime helper (`@_guard_check_icall_nop@4`) consisting of a single `retn`; not NexusTK product logic.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs` reports `@_guard_check_icall_nop@4` at `0x0041b6a0` with size `0x01`, and IDA decompilation emits an empty body.
  - Replacement/procurement: compiler/security runtime emits the equivalent helper when needed.

- `0x0041b6a1-0x0041b6b0` - alignment padding before `nullsub_17`.
  - Why ignored: confirmed `0xcc` alignment padding with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports fifteen `0xcc` bytes between the one-byte guard helper and [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.

- `0x0041b6b3-0x0041b6c0` - alignment padding between default no-op virtual bodies.
  - Why ignored: confirmed `0xcc` alignment padding with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports thirteen `0xcc` bytes between [UID:0000WL][0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual](by-memory/0x0041b6b0-0x0041b6b3.ThreadDefaultNoOpVirtual.md) and [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.

- `0x0041b6c3-0x0041b6d0` - alignment padding before MSVC string support helpers.
  - Why ignored: confirmed `0xcc` alignment padding with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports thirteen `0xcc` bytes between [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) and [UID:0000WN][0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers](by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.

- `0x0041b6d0-0x0041b9a0` - MSVC/Dinkumware `std::string` support helpers.
  - Why ignored: standard-library string allocation/growth/copy support, not NexusTK handwritten product logic.
  - Evidence: [UID:0000WN][0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers](by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md) records IDA MCP decompilation for length-error, aligned allocation, append, and assign helpers.
  - Replacement/procurement: use the compiler/runtime `std::string` implementation in rebuilt source.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x0041b9de-0x0041b9e0` - alignment padding before the raw fitting-room download pane constructor body.
  - Why ignored: confirmed `0xcc` alignment padding.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports two `0xcc` bytes between [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md) and [UID:0000WP][0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor](by-memory/0x0041b9e0-0x0041ba20.FittingRoomDownloadControlPaneRawConstructor.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.

- `0x0041ba3f-0x0041ba40` - alignment padding before `FittingRoomDownloadControlPane::OnPaint`.
  - Why ignored: confirmed `0xcc` alignment byte.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports byte `0xcc` at `0x0041ba3f`, rendered as `align 10h`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:0000WQ][0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor](by-memory/0x0041ba20-0x0041ba3f.FittingRoomDownloadControlPaneRawDestructor.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041d431-0x0041d440`, `0x0041d44b-0x0041d450`, `0x0041d481-0x0041d490`, `0x0041d572-0x0041d580`, and `0x0041d5d5-0x0041d5e0` - alignment padding around fitting-room helper/thunk/destructor island.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented fitting-room helper functions, destructor thunks, and destructor wrappers.
  - Evidence: 2026-05-30 IDA MCP function inventory reports `sub_41D3B0` ending at `0x0041d431`, `sub_41D440` at `0x0041d440-0x0041d44b`, thunk functions at `0x0041d450-0x0041d481`, [UID:0002CR][0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor](by-memory/0x0041d490-0x0041d572.FittingRoomDialogScalarDeletingDestructor.md), [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md), and [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md); the intervening bytes decode as padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md), [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md), [UID:0002D0][0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal](by-memory/0x0041d440-0x0041d44b.ClearFittingRoomDialogGlobal.md), [UID:0002D1][0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks](by-memory/0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks.md), [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md), [UID:0000WS][0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries](by-memory/0x0041d5e0-0x0041d671.FittingEquipmentStateResetEntries.md).

- `0x0041d450-0x0041d481` - fitting-room dialog destructor adjustor thunk island.
  - Why ignored: compiler-generated this-adjustor/deleting thunks around fitting-room destructor paths; not handwritten product source to port directly.
  - Evidence: [UID:0002D1][0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks](by-memory/0x0041d450-0x0041d481.FittingRoomDialogAdjustorThunks.md) records five tiny function records that only jump, subtract `0xa0`/`0xa4` from `ecx`, and tail-jump to destructor targets.
  - Replacement/procurement: class inheritance/destructor declarations should cause the compiler to emit equivalent thunks if they are needed in the rebuilt binary.
  - Owner docs: [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041d580-0x0041d5d5` - `FittingRoomDownloadControlPane` scalar deleting destructor wrapper.
  - Why ignored: compiler-generated MSVC deleting-destructor wrapper, not a handwritten source function to port directly.
  - Evidence: [UID:0002EI][0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor](by-memory/0x0041d580-0x0041d5d5.FittingRoomDownloadControlPaneDeletingDestructor.md) records IDA MCP function size, vtable/data xref, adjacent adjustor-thunk callers, vtable restoration, shared teardown call, and conditional delete-helper call.
  - Replacement/procurement: source-level `FittingRoomDownloadControlPane` destructor and class inheritance should cause the compiler to emit the equivalent deleting wrapper if needed in the rebuilt binary.
  - Owner docs: [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041da51-0x0041da60`, `0x0041da65-0x0041da70`, `0x0041daa3-0x0041dab0`, `0x0041e1c6-0x0041e1d0`, `0x0041e4ed-0x0041e4f0`, `0x0041e777-0x0041e780`, `0x0041e8af-0x0041e8b0`, `0x0041eb24-0x0041eb30`, and `0x0041eb8c-0x0041eb90` - fitting-room scroll-pane alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent `FittingRoomScrollPane` helper bodies.
  - Evidence: 2026-05-30 IDA MCP function inventory and byte/disassembly audit splits the scroll-pane core into [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md), [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md), [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md), [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md), [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md), [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md), [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md), [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md), [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md), and [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md); the intervening bytes decode as padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041ecbd-0x0041ecc0`, `0x0041ecf5-0x0041ed00`, `0x0041ed88-0x0041ed90`, `0x0041ee03-0x0041ee10`, `0x0041f0fd-0x0041f100`, `0x0041f219-0x0041f220`, `0x0041f286-0x0041f290`, and `0x0041f2a6-0x0041f2b0` - fitting-room list-pane alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent `FittingRoomListPane` constructor, virtual methods, and scrollbar-management bodies.
  - Evidence: 2026-05-30 IDA MCP function inventory and byte/disassembly audit splits the first list-pane core into [UID:0002DC][0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor](by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md), [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md), [UID:0002DE][0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize](by-memory/0x0041ed00-0x0041ed88.FittingRoomListPaneOnResize.md), [UID:0002DG][0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane](by-memory/0x0041ed90-0x0041ee03.FittingRoomListPaneOnMovePane.md), [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md), [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md), [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md), [UID:0002DJ][0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane](by-memory/0x0041f220-0x0041f286.FittingRoomListPaneOnInsertPane.md), and [UID:0002DK][0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane](by-memory/0x0041f290-0x0041f2a6.FittingRoomListPaneOnDetachPane.md); the padding bytes decode as alignment between those bodies.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041ecc0-0x0041ecf5` - fitting-room list-pane raw destructor/constructor-cleanup body.
  - Why ignored: this body is real executable cleanup logic, but IDA has no current function record or xrefs for it; the byte pattern restores `FittingRoomListPane` vtables, deletes/cleans the embedded scroll child, and tail-jumps into base cleanup, so it is compiler-generated destructor/exception-cleanup support rather than a standalone handwritten project method.
  - Evidence: [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md) records the 2026-05-30 IDA MCP disassembly and missing-function/xref audit.
  - Replacement/procurement: implement normal C++ class ownership/destructor semantics for `FittingRoomListPane`; the rebuilt compiler should emit equivalent cleanup support as needed.
  - Owner docs: [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x0041fb9b-0x0041fba0`, `0x0041fcc5-0x0041fcd0`, `0x00420949-0x00420950`, `0x00420cf9-0x00420d00`, `0x00420dd5-0x00420de0`, and `0x00421301-0x00421310` - fitting-room list-pane paint/input/helper alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the newly split list-pane paint, key-scroll, input, raw geometry, validator, raw layout, vector-helper, and shared string-helper ranges.
  - Evidence: 2026-05-30 IDA MCP byte audit reports all bytes in these spans are `0xcc`; adjacent documented ranges are [UID:0002DL][0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint](by-memory/0x0041f2b0-0x0041fb9b.FittingRoomListPaneOnPaint.md), [UID:0002DM][0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll](by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md), [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md), [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md), [UID:0002DT][0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers](by-memory/0x00420950-0x00420b60.FittingRoomListPaneSlotRectRawHelpers.md), [UID:0002DP][0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot](by-memory/0x00420b60-0x00420cf9.FittingRoomListPaneHitTestSlot.md), [UID:0002DQ][0x00420d00-0x00420d50.ValidateFittingSelectionIndex](by-memory/0x00420d00-0x00420d50.ValidateFittingSelectionIndex.md), [UID:0002DU][0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers](by-memory/0x00420d50-0x00420dd5.FittingRoomListPaneSlotLayoutRawHelpers.md), [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md), and [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x00421362-0x00421370`, `0x00421375-0x00421380`, `0x004213e1-0x004213e2`, `0x0042140e-0x00421410`, `0x00421477-0x00421480`, `0x004214bb-0x004214c0`, `0x004214c5-0x004214d0`, `0x004214f7-0x00421500`, `0x0042151a-0x00421520`, and `0x00421584-0x00421590` - alignment padding inside the early SimpleUString/pane/vector helper island.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact functions in the mixed `0x00421310-0x004216cb` island.
  - Evidence: 2026-05-30 IDA MCP byte audit reports every byte in these spans is `0xcc`; [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md) records the adjacent function inventory.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md).

- `0x00421370-0x00421375` - pane-base destructor thunk.
  - Why ignored: five-byte compiler-generated tail-jump thunk into shared pane teardown `0x00544580`; no standalone product behavior.
  - Evidence: 2026-05-30 IDA MCP decompilation emits a thunk body calling `sub_544580(this)`; [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md) records the function inventory.
  - Replacement/procurement: declare/implement the source-level pane class hierarchy and let the compiler emit or merge thunks as needed.
  - Owner docs: [UID:0000CM][ScrollPane](by-class/ScrollPane.md), [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md).

- `0x004213e2-0x0042140e` - fitting-room and scroll-pane deleting-destructor adjustor thunks.
  - Why ignored: vtable-only `this` adjustor thunks that subtract `0xa0` or `0xa4` before forwarding to [UID:0002DX][0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor](by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md) or [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md).
  - Evidence: 2026-05-30 IDA MCP decompilation and data refs show `0x004213e2` / `0x004213ed` referenced from `FittingRoomListPane` vtables, and `0x004213f8` / `0x00421403` referenced from several scroll-pane-family vtables.
  - Replacement/procurement: source class declarations and inheritance should generate equivalent adjustor thunks; do not hand-port as handwritten NexusTK functions.
  - Owner docs: [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md), [UID:0000WT][0x00421310-0x004216cb.SimpleUStringSso7](by-memory/0x00421310-0x004216cb.SimpleUStringSso7.md).

- `0x00421480-0x004214bb` - scroll-pane-family scalar deleting destructor wrapper.
  - Why ignored: shared compiler-generated deleting-destructor wrapper for scroll-pane-like classes that only calls pane-base teardown and optional object delete; source declarations/destructors should regenerate it.
  - Evidence: [UID:0002DY][0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor](by-memory/0x00421480-0x004214bb.ScrollPaneFamilyScalarDeletingDestructor.md) records IDA decompilation and vtable data refs from `FittingRoomScrollPane`, `RankingEventScrollPane`, `ScrollPane`, `ScrollInventoryPane`, and related scroll-pane classes.
  - Replacement/procurement: declare the scroll-pane hierarchy/destructors in source; let the compiler emit or merge deleting-destructor wrappers.
  - Owner docs: [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md), [UID:0000CM][ScrollPane](by-class/ScrollPane.md).

- `0x00421500-0x0042151a` - MSVC/Dinkumware vector throw helper pair.
  - Why ignored: runtime/STL exception support for `"vector<T> too long"` and `"invalid vector<T> subscript"`, not NexusTK-authored product code.
  - Evidence: [UID:0002E1][0x00421500-0x0042151a.MsvcVectorThrowHelpers](by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md) records IDA MCP decompilation and broad vector-template caller fan-in.
  - Replacement/procurement: use matching toolchain/STL/runtime support or a compatibility runtime shim if exact binary behavior is required.
  - Owner docs: [UID:0002E1][0x00421500-0x0042151a.MsvcVectorThrowHelpers](by-memory/0x00421500-0x0042151a.MsvcVectorThrowHelpers.md).

- `0x00421520-0x00421584` - shared aligned dword-array allocation helper.
  - Why ignored: runtime/STL-style vector allocator helper with broad caller fan-in; important to understand but not currently treated as NexusTK-authored source.
  - Evidence: [UID:0002E2][0x00421520-0x00421584.AllocateAlignedDwordArray](by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md) records IDA MCP decompilation showing small direct `operator new`, large 32-byte aligned allocation, and raw-pointer header storage.
  - Replacement/procurement: prefer matching STL/toolchain-generated allocation support; create an explicit shim only if the rebuilt project requires binary-compatible allocator behavior.
  - Owner docs: [UID:0002E2][0x00421520-0x00421584.AllocateAlignedDwordArray](by-memory/0x00421520-0x00421584.AllocateAlignedDwordArray.md).

- `0x004207ce-0x00420840` - fitting-room list-pane input-handler jump tables.
  - Why ignored: source-declared/generated-binary switch/jump-table data owned by [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md); not handwritten standalone source.
  - Evidence: [UID:0002DO][0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables](by-memory/0x004207ce-0x00420840.FittingRoomListPaneOnInputEventJumpTables.md) records IDA MCP byte evidence showing local code-address dwords rather than padding between `sub_41FCD0` and `sub_420840`.
  - Replacement/procurement: rebuild the owning source-level switch/branch logic and let the compiler emit dispatch tables if needed.
  - Owner docs: [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md), [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md).

- `0x00420eea-0x00420ef0`, `0x00421143-0x00421150`, `0x0042122b-0x00421230`, and `0x0042125d-0x00421260` - fitting-room selection/vector helper island alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between exact helper functions inside [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md).
  - Evidence: 2026-05-30 IDA MCP function inventory reports functions ending at `0x00420eea`, `0x00421143`, `0x0042122b`, and `0x0042125d`; byte audit reports the intervening spans are all `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md), [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

- `0x004245f5-0x00424600` - alignment padding after `FittingRoomUserImageControlPane` scalar-deleting destructor.
  - Why ignored: confirmed `0xcc` alignment padding with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports `sub_4245A0` ends at `0x004245f5`; bytes through `0x00424600` render as `align 10h` padding with no xrefs.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md), [UID:0000WX][0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md).

- `0x00424600-0x00424629` - JsonCpp/runtime-adjacent pre-exception flag initializer helpers.
  - Why ignored: tiny third-party/compiler-support helper island immediately before the modeled JsonCpp exception constructors; not NexusTK product logic.
  - Evidence: [UID:0000WX][0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md) records IDA MCP lookup/decompile/disassembly evidence for the two raw no-function helper bodies and `sub_424620`.
  - Replacement/procurement: use the matched vendored JsonCpp source plus compiler/runtime support rather than hand-reconstructing this as product code.
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md).

- `0x00424629-0x00424630` - alignment padding before JsonCpp value core.
  - Why ignored: confirmed `0xcc` alignment padding with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports seven `0xcc` bytes after `sub_424620` and before `sub_424630`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000WX][0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers](by-memory/0x00424600-0x00424629.JsonCppPreExceptionFlagInitializers.md), [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md).

- `0x00428b4b-0x004298f0` - JsonCpp value/path/iterator and CRT numeric support.
  - Why ignored: mixed third-party JsonCpp support and MSVC CRT `__crt_strtox` helper fragments, not NexusTK product source.
  - Evidence: [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) records IDA MCP evidence for `__crt_strtox::big_integer`, `Json::Value::setComment()`, `Json::Path`/`PathArgument`-style syntax processing, and JsonCpp iterator diagnostics.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/) plus compatible MSVC CRT support.
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md), [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md).

- `0x0042acdf-0x0042ae90` - JsonCpp legacy `Reader` raw lexical helpers.
  - Why ignored: raw/unmodeled third-party JsonCpp lexer helper code and alignment padding, not NexusTK product source.
  - Evidence: [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) records IDA MCP disassembly and source comparison for legacy `Json::Reader` comment, string, and number scanners.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md), [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md).

- `0x0042f3f0-0x00430040` - JsonCpp legacy writer core.
  - Why ignored: third-party JsonCpp `Writer`/`FastWriter`/`StyledWriter` serialization code, not NexusTK product source.
  - Evidence: [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) records IDA MCP vtable, decompile, caller/callee, and staged `json_writer.cpp` source comparison evidence.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md), [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md).

- `0x00430040-0x00430092` - JsonCpp writer push helper.
  - Why ignored: third-party JsonCpp `StyledWriter::pushValue`-style helper, not NexusTK product source.
  - Evidence: [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) records IDA MCP decompile/caller evidence showing only JsonCpp writer-family callers from `0x0042f870`.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md), [wave3 data issues](../wave3_data_issues.md).

- `0x00430092-0x00431d50` - JsonCpp writer tail and OurReader prelude.
  - Why ignored: third-party JsonCpp `StyledWriter`/`StyledStreamWriter` tail helpers, scalar/string writer helpers, stream insertion helper, and `OurReader` constructor prelude, not NexusTK product source.
  - Evidence: [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) records IDA MCP function listing, manual raw-code disassembly, writer literal/xref evidence, and staged `json_writer.cpp`/`json_reader.cpp` comparison.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md), [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md).

- `0x0060c320-0x0060c43a` - object/string `PoolAllocator` static destructor wrappers.
  - Why ignored: compiler-generated `atexit` cleanup wrappers that call `PoolAllocator::~PoolAllocator` for concrete static pool globals; not handwritten product source.
  - Evidence: [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md) records IDA MCP lookup/decompile evidence for eighteen cleanup wrappers. Boundary note: `0x0060c440` is `UniAPIInit` cleanup, not a pool cleanup wrapper.
  - Replacement/procurement: no external dependency; generated from static `PoolAllocator` object lifetime.
  - Owner docs: [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md), [UID:0000WC][0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers](by-memory/0x0041a040-0x0041a27d.PoolAllocatorStaticConstructorWrappers.md).

- `0x0060c450-0x0060c45a` - `UserPane` pool static destructor wrapper.
  - Why ignored: compiler-generated `atexit` cleanup wrapper for the large `UserPane` pool at `0x0069bf34`; not handwritten product source.
  - Evidence: [UID:0001OA][0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper](by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md) records IDA MCP lookup/decompile evidence. Boundary note: the preceding `0x0060c440` function belongs to `UniAPIInit` cleanup.
  - Replacement/procurement: no external dependency; generated from static `PoolAllocator` object lifetime.
  - Owner docs: [UID:0000P1][UserPane](by-file/UserPane.md), [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md), [UID:0000WE][0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper](by-memory/0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md).

- `0x0060c440-0x0060c44b` - `UniAPIInit` static cleanup wrapper.
  - Why ignored: compiler-generated `atexit` cleanup wrapper for platform API initializer state; not handwritten platform logic and not part of the adjacent allocator cleanup wrappers.
  - Evidence: [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) records IDA MCP lookup/decompile/xref evidence. The body only writes `UniAPIInit::vftable` to `0x006702c4`, and its only xref is the `atexit` registration inside [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md).
  - Replacement/procurement: no external dependency; generated from static `UniAPIInit` object lifetime.
  - Owner docs: [UID:0000ML][PlatformApi](by-file/PlatformApi.md), [UID:0000FE][UniAPIInit](by-class/UniAPIInit.md), [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md).

- `0x0060c0f0-0x0060c100` - `AutoInit` static shutdown thunk.
  - Why ignored: compiler/static-lifetime `atexit` cleanup thunk for the process OLE helper; not a standalone handwritten source function.
  - Evidence: [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) records IDA MCP lookup/decompile/disassembly/xref evidence. The body writes the [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) to `off_66D42C` and tail-jumps to `OleUninitialize`; its only function xref is the `atexit` registration inside [UID:0000W8][0x00419ee0-0x00419ef4.InitializeOleSupport](by-memory/0x00419ee0-0x00419ef4.InitializeOleSupport.md). IDA MCP `py_eval` on 2026-05-28 corrected the exclusive end to `0x0060c100`.
  - Replacement/procurement: no external dependency; generated from static `AutoInit` object lifetime around OLE initialization.
  - Owner docs: [UID:00000Q][AutoInit](by-class/AutoInit.md), [UID:0000ML][PlatformApi](by-file/PlatformApi.md), [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md).

- `0x0060c100-0x0060c260` - static string/container cleanup thunks.
  - Why ignored: compiler/static-lifetime `atexit` cleanup bodies plus `0xcc` alignment for static string/container objects; not standalone handwritten source.
  - Evidence: [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) records IDA MCP function boundaries, decompilation, xrefs, and paired startup registrations at `0x00419f20`, `0x00419f40`, and `0x00419f50`.
  - Replacement/procurement: preserve the source-level static object declarations for `dword_66DAEC`, `dword_69B39C`/`dword_69B3A0`/`dword_69B3A4`, and `dword_69B3D0`; let the compiler emit equivalent cleanup code.
  - Owner docs: [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md), [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md), [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md).

- `0x0060c26a-0x0060c320` - static destructor wrappers before object/string `PoolAllocator` destructor wrappers.
  - Why ignored: compiler/static-lifetime `atexit` cleanup wrappers, one registered null destructor stub, and `0xcc` alignment padding; not standalone handwritten source.
  - Evidence: [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md) records IDA MCP function boundaries, decompilation, xrefs, padding runs, and paired startup registrations from [UID:0000WB][0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators](by-memory/0x00419f86-0x0041a040.StaticInitializerWrappersBeforePoolAllocators.md).
  - Replacement/procurement: preserve the source-level static globals/classes for `TimerMgr`, image-definition helper tables, `g_metaAliasTableName`, and MIDI document state; let compiler static lifetime code emit equivalent cleanup wrappers.
  - Owner docs: [UID:0000OT][TimerMgr](by-file/TimerMgr.md), [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md), [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md), [UID:0000T9][MidiPlayerWinMMState](by-global/MidiPlayerWinMMState.md).

- `0x0060c43a-0x0060c440` - alignment padding before `UniAPIInit` static cleanup.
  - Why ignored: confirmed `0xcc` alignment bytes with no IDA function starts; not executable product behavior.
  - Evidence: [UID:00024H][0x0060c43a-0x0060c440.AlignmentPaddingBeforeUniAPIInitCleanup](by-memory/0x0060c43a-0x0060c440.AlignmentPaddingBeforeUniAPIInitCleanup.md) records IDA MCP byte/function audit evidence.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md), [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md).

- `0x0060c44b-0x0060c450` - alignment padding before `UserPane` pool cleanup.
  - Why ignored: confirmed `0xcc` alignment bytes with no IDA function starts; not executable product behavior.
  - Evidence: [UID:00024I][0x0060c44b-0x0060c450.AlignmentPaddingBeforeUserPanePoolCleanup](by-memory/0x0060c44b-0x0060c450.AlignmentPaddingBeforeUserPanePoolCleanup.md) records IDA MCP byte/function audit evidence.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md), [UID:0001OA][0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper](by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md).

- `0x0060c45a-0x0060c4ac` - runtime/static cleanup wrappers after `UserPane` pool cleanup.
  - Why ignored: STL/CRT/COM/runtime static cleanup wrappers and alignment padding; not NexusTK-authored product source.
  - Evidence: [UID:00024J][0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool](by-memory/0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool.md) records IDA MCP function boundaries, decompilation, xrefs, and paired startup registrations from [UID:0000WF][0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool](by-memory/0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md).
  - Replacement/procurement: runtime/toolchain/static-object declarations should regenerate or replace this cleanup code.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0000WF][0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool](by-memory/0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md).

- `0x0060c4ac-0x0060d000` - `.text` section tail fill.
  - Why ignored: non-code section fill to the end of IDA `.text`; no function starts and no source semantics to port.
  - Evidence: [UID:00024K][0x0060c4ac-0x0060d000.TextSectionTailFill](by-memory/0x0060c4ac-0x0060d000.TextSectionTailFill.md) records IDA MCP byte counts and data-head boundaries: 340 zero bytes followed by 2560 `0xff` bytes.
  - Replacement/procurement: generated by linker/section layout, not source.
  - Owner docs: [UID:0001Z5][0x00401000-0x0060d000.MasterCodeTextSection](by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md), [UID:0001Z6][0x0060d000-0x0060d670.ImportDataSection](by-memory/0x0060d000-0x0060d670.ImportDataSection.md).

- `0x00458557-0x00458560` and `0x00458585-0x00458590` - EPFTileContext helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes with no product behavior.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports `sub_458500` ends at `0x00458557`, `sub_458560` spans `0x00458560-0x00458585`, `sub_458590` spans `0x00458590-0x00458610`, and the only bytes between those code bodies are `0xcc` padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md), [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md), [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md).

- `0x0045d740-0x0045d750`, `0x0045d78a-0x0045d790`, `0x0045d7c2-0x0045d7d0`, `0x0045d7db-0x0045d7e0`, `0x0045db54-0x0045db60`, `0x0045db9e-0x0045dba0`, and `0x0045f9f5-0x0045fa00` - RankingDialog alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between exact RankingDialog helper/method bodies.
  - Evidence: 2026-05-27 IDA MCP byte/function audit of the former UNKNOWN rows shows these spans contain only alignment bytes and no external xrefs. The adjacent real helper bodies are documented as [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md), [UID:000203][0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk](by-memory/0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk.md), and [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md).

- `0x0045d7d0-0x0045d7db` - `RankingRewardEntryItemVectorUnwindThunk`.
  - Why ignored: compiler cleanup thunk with only unwind-table xref at `0x005fa3ba`; not a handwritten source method.
  - Evidence: [UID:000203][0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk](by-memory/0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk.md) records the exact `add ecx, 0x224; jmp 0x0045f160` body and IDA xref evidence.
  - Replacement/procurement: express the source-level nested reward-item vector/destructor semantics and let compiler cleanup glue be regenerated.
  - Owner docs: [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md).

- `0x004604f4-0x00460500`, `0x00460709-0x00460710`, `0x0046093c-0x00460940`, `0x004609d3-0x004609e0`, `0x00460af9-0x00460b00`, `0x00460c0a-0x00460c10`, `0x00460c8c-0x00460c90`, `0x00460d51-0x00460d60`, `0x00460dee-0x00460df0`, `0x00460e79-0x00460e80`, `0x00460f09-0x00460f10`, `0x00460f99-0x00460fa0`, `0x00460ffe-0x00461000`, `0x0046104b-0x00461050`, `0x0046109e-0x004610a0`, and `0x004610ee-0x004610f0` - SoftwareBlend16/render helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between exact RGB565/RGB555/byte-span helper bodies; not product logic.
  - Evidence: 2026-05-27 IDA MCP `py_eval` byte/function audit of former UNKNOWN rows around `0x004604f3-0x004610f0` shows the adjacent real helper bodies and these padding spans. `sub_460410` ends at `0x004604f4`; raw helpers are documented at [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md), [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md), and [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md); modeled helpers are documented at [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md), [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md), [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md), [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md), [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md), [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md), [UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md), [UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md), and [UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md), [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md), [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md), and [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md).

- `0x0046904e-0x00469050`, `0x0046907a-0x00469080`, and `0x004690a5-0x004690b0` - ObjectPane virtual helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes around exact object-pane virtual helper bodies.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports `sub_468f80` ends at `0x0046904e`, `sub_469050` spans `0x00469050-0x0046907a`, `sub_469080` spans `0x00469080-0x004690a5`, and `sub_4690b0` starts at `0x004690b0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md), [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md), [UID:00009R][ObjectPane](by-class/ObjectPane.md), and [UID:0000M5][ObjectPane](by-file/ObjectPane.md).

- `0x004690f6-0x00469100`, `0x00469115-0x00469120`, `0x00469171-0x00469180`, `0x004691fa-0x00469200`, and `0x00469233-0x00469240` - BlackHole internal function alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between exact BlackHole constructor/destructor/enqueue/queue/drain/deleting-destructor child functions.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs` reports BlackHole child functions at `0x004690b0-0x004690f6`, `0x00469100-0x00469115`, `0x00469120-0x00469171`, `0x00469180-0x004691fa`, `0x00469200-0x00469233`, and `0x00469240-0x00469288`; `py_eval` byte checks show the listed intervening spans are all `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md), [UID:0002M0][0x004690b0-0x004690f6.BlackHoleConstructor](by-memory/0x004690b0-0x004690f6.BlackHoleConstructor.md), [UID:0002M1][0x00469100-0x00469115.BlackHoleDestructor](by-memory/0x00469100-0x00469115.BlackHoleDestructor.md), [UID:0002M3][0x00469120-0x00469171.BlackHoleEnqueueIfMissing](by-memory/0x00469120-0x00469171.BlackHoleEnqueueIfMissing.md), [UID:0000Z1][0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion](by-memory/0x00469180-0x004691fa.BlackHoleQueuePaneForDeferredDeletion.md), [UID:0002M4][0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects](by-memory/0x00469200-0x00469233.BlackHoleReleaseQueuedOwnedObjects.md), and [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md).

- `0x00469288-0x00469290` - BlackHole/BrowserDialogOld alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between the BlackHole scalar deleting destructor and the next BrowserDialogOld constructor-like method.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports `sub_469240` spans `0x00469240-0x00469288`, `sub_469290` starts at `0x00469290`, and the intervening bytes are alignment padding; 2026-05-31 IDA MCP reconfirmed these eight bytes are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z0][0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue](by-memory/0x004690b0-0x00469288.BlackHoleDeferredDeletionQueue.md), [UID:0002M2][0x00469240-0x00469288.BlackHoleScalarDeletingDestructor](by-memory/0x00469240-0x00469288.BlackHoleScalarDeletingDestructor.md), and [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md).

- `0x0046963c-0x00469640` - BrowserDialogOld/BrowserWindowCore alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between the BrowserDialogOld navigation callback and `BrowserWindowCore`.
  - Evidence: 2026-05-27 IDA MCP byte/function audit reports `sub_469620` spans `0x00469620-0x0046963c`, `sub_469640` starts at `0x00469640`, and the intervening bytes are alignment padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) and [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md).

- `0x0046a39c-0x0046a3d0` - `BrowserWindow::Invoke` switch tables and alignment padding.
  - Why ignored: compiler-generated jump table, byte table, and alignment padding for the source-level dispatch switch in [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md); not standalone handwritten product logic.
  - Evidence: 2026-05-27 IDA MCP reports `sub_46A250` ends at `0x0046a39c`, `jpt_46A26E` begins at `0x0046a39c`, `byte_46A3B8` begins at `0x0046a3b8`, and `0xcc` padding begins at `0x0046a3cd` before `sub_46A3D0`.
  - Replacement/procurement: write the source-level `Invoke` switch and let the compiler regenerate tables.
  - Owner docs: [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md).

- `0x0046a505-0x0046a510` - BrowserWindow UI-handler alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the browser UI-handler stub cluster and before the next browser accelerator helper.
  - Evidence: 2026-05-27 IDA MCP reports `sub_46A500` spans `0x0046a500-0x0046a505`, followed by padding through `0x0046a510`, where `sub_46A510` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md).

- `0x0046a617-0x0046a630` - BrowserWindow accelerator switch table and alignment padding.
  - Why ignored: compiler-generated switch metadata and padding after [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md); not standalone handwritten product logic.
  - Evidence: 2026-05-27 IDA MCP reports `sub_46A510` spans `0x0046a510-0x0046a617`, with alignment/switch metadata at `0x0046a617-0x0046a630` before `sub_46A630`.
  - Replacement/procurement: write the source-level message switch and let the compiler regenerate tables.
  - Owner docs: [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md).

- `0x0046a6ea-0x0046a760` - BrowserWindow host WndProc switch table, byte table, and alignment padding.
  - Why ignored: compiler-generated `WM_SYSCOMMAND` switch data and alignment after the host WndProc, not standalone handwritten source.
  - Evidence: 2026-05-27 IDA MCP reports `sub_46A630` spans `0x0046a630-0x0046a6ea`, followed by switch/table bytes and padding through the raw prologue-like body at `0x0046a760`.
  - Replacement/procurement: write the source-level WndProc switch and let the compiler regenerate tables.
  - Owner docs: [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md), [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md).

- `0x0046a855-0x0046a860` - Browser raw WndProc/BrowserPane alignment padding.
  - Why ignored: confirmed alignment bytes after the raw browser-adjacent WndProc-like body and before the next BrowserPane/Dialog range.
  - Evidence: 2026-05-27 IDA MCP raw disassembly reports `byte_46A7F4` table data through `0x0046a855`, `0xcc` alignment bytes at `0x0046a855-0x0046a860`, and the next prologue-like body at `0x0046a860`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md), [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md).

- `0x0046ad0a-0x0046ad10` - BrowserDialog constructor/virtuals alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes between the `BrowserDialog` constructor and the next BrowserDialog virtual-method cluster.
  - Evidence: 2026-05-27 IDA MCP function enumeration reports `sub_46AA40` spans `0x0046aa40-0x0046ad0a`, followed by alignment bytes through `0x0046ad10`, where `sub_46AD10` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md).

- `0x0046b51d-0x0046b520` - BrowserDialog/BrowserControlPane alignment padding.
  - Why ignored: confirmed alignment bytes between the BrowserDialog child-rect helper and the BrowserControlPane constructor.
  - Evidence: 2026-05-27 IDA MCP function enumeration reports `sub_46B4B0` spans `0x0046b4b0-0x0046b51d`, followed by padding through `0x0046b520`, where `sub_46B520` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md).

- `0x0046cfe0-0x0046d050` - BrowserControlPane child-window message switch table, byte table, and alignment padding.
  - Why ignored: compiler-generated jump table, indirect byte dispatch table, and alignment padding for the source-level child-window message switch in [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md); not standalone handwritten product logic.
  - Evidence: 2026-05-27 IDA MCP disassembly reports the raw message-handler tail at `0x0046cfd0`, `jpt_46CFDA` at `0x0046cfe4`, `byte_46CFEC` at `0x0046cfec-0x0046d04d`, `0xcc` alignment through `0x0046d050`, and `sub_46D050` beginning the next `WebBoardDialog` constructor.
  - Replacement/procurement: write the source-level BrowserControlPane message switch and let the compiler regenerate tables.
  - Owner docs: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md).

- `0x0046d324-0x0046d330` - WebBoardDialog constructor/destructor alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the active `WebBoardDialog` constructor and before the ordinary destructor.
  - Evidence: 2026-05-27 IDA MCP function enumeration reports `sub_46D050` spans `0x0046d050-0x0046d324`, followed by `0xcc` bytes through `0x0046d330`, where `sub_46D330` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md), [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md).

- `0x0046d475-0x0046d480` - WebBoardDialog virtuals/packet-forwarder alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the WebBoardDialog virtual companion cluster and before the packet-forwarder callback.
  - Evidence: 2026-05-27 IDA MCP function enumeration reports `sub_46D3B0` spans `0x0046d3b0-0x0046d475`, followed by `0xcc` bytes through `0x0046d480`, where `sub_46D480` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md).

- `0x0046d4a3-0x0046d4b0` - WebBoardDialog packet-forwarder/input alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the packet-forwarder callback and before the WebBoardDialog input helper.
  - Evidence: 2026-05-27 IDA MCP function enumeration reports `sub_46D480` spans `0x0046d480-0x0046d4a3`, followed by alignment bytes through `0x0046d4b0`, where `sub_46D4B0` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md), [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md).

- `0x0046d57b-0x0046d580` - WebBoardDialog request/response alignment padding.
  - Why ignored: confirmed alignment bytes after the raw initial board request/timer helper and before the response handler.
  - Evidence: 2026-05-27 IDA MCP raw disassembly shows a `retn 4` at `0x0046d579`, alignment bytes at `0x0046d57b-0x0046d580`, and `sub_46D580` beginning the next modeled response handler.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md), [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md).

- `0x0046da63-0x0046da70` - WebBoardDialog response/render-helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the active response handler and before the raw URL escape helper at `0x0046da70`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46D580` ending at `0x0046da63`, raw prologue-like code beginning at `0x0046da70`, and only alignment bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md), [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md).

- `0x0046e294-0x0046e2a0` - WebBoardDialog helper/old-layout alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw teardown-like helper and before the old layout refresh helper at `0x0046e2a0`.
  - Evidence: 2026-05-27 IDA MCP raw disassembly shows a `retn` at `0x0046e293`, alignment bytes at `0x0046e294-0x0046e2a0`, and `sub_46E2A0` beginning the next modeled function.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md), [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md).

- `0x0046e4b6-0x0046e4c0` - WebBoardDialogOld layout/mode-rect alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the old layout refresh helper and before the raw mode/control rectangle helper at `0x0046e4c0`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46E2A0` ending at `0x0046e4b6`, raw helper bytes beginning at `0x0046e4c0`, and only alignment bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md), [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md).

- `0x0046e63c-0x0046e640` - WebBoardDialogOld mode-rect/constructor alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw mode/control rectangle helper jump tables and before the old constructor at `0x0046e640`.
  - Evidence: 2026-05-27 IDA MCP raw disassembly shows jump-table data through `0x0046e63c`, followed by alignment bytes at `0x0046e63c-0x0046e640`, where `sub_46E640` begins.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md), [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md).

- `0x0046e8be-0x0046e8c0` - WebBoardDialogOld constructor/destructor alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the old constructor and before the old-dialog destructor at `0x0046e8c0`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46E640` ending at `0x0046e8be`, padding bytes at `0x0046e8be-0x0046e8c0`, and `sub_46E8C0` beginning the destructor/callback cluster.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md), [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md).

- `0x0046e9f5-0x0046ea00` - WebBoardDialogOld callback/packet-forwarder alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the old-dialog secondary input callback and before packet forwarder `sub_46EA00`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46E930` ending at `0x0046e9f5`, padding bytes at `0x0046e9f5-0x0046ea00`, and `sub_46EA00` beginning the packet-forwarding vtable callback.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md), [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md).

- `0x0046ea23-0x0046ea30` - WebBoardDialogOld packet-forwarder/request-helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after packet forwarder `sub_46EA00` and before the raw initial request helper at `0x0046ea30`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46EA00` ending at `0x0046ea23`, padding bytes at `0x0046ea23-0x0046ea30`, and raw helper bytes beginning at `0x0046ea30`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md), [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md).

- `0x0046ea99-0x0046eaa0` - WebBoardDialogOld request-helper/response alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw initial request helper and before response parser `sub_46EAA0`.
  - Evidence: 2026-05-27 IDA MCP raw disassembly reports `retn` at `0x0046ea99`, padding bytes at `0x0046ea99-0x0046eaa0`, and `sub_46EAA0` beginning the response parser.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md), [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md).

- `0x0046ee7a-0x0046ee80` - WebBoardDialogOld response/url-escape alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the old response parser and before the raw old URL escape helper at `0x0046ee80`.
  - Evidence: 2026-05-27 IDA MCP function/byte audit reports `sub_46EAA0` ending at `0x0046ee7a`, padding bytes at `0x0046ee7a-0x0046ee80`, and raw helper bytes beginning at `0x0046ee80`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md), [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md).

- `0x0046efda-0x0046efe0` - WebBoardDialogOld url-escape/AutoInit alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw old URL escape helper and before `AutoInit` non-deleting destructor `sub_46EFE0`.
  - Evidence: 2026-05-27 IDA MCP raw disassembly reports range-check failure tail through `0x0046efda`, padding bytes at `0x0046efda-0x0046efe0`, and `sub_46EFE0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md), [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md).

- `0x0046efec-0x0046eff0` - AutoInit/BrowserThread destructor alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the `AutoInit` non-deleting destructor and before the ordinary `BrowserThread` destructor body.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_46EFE0` at half-open range `0x0046efe0-0x0046efec`, padding bytes at `0x0046efec-0x0046eff0`, and `sub_46EFF0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZE][0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor](by-memory/0x0046efe0-0x0046efeb.AutoInitNonDeletingDestructor.md), [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md).

- `0x0046f005-0x0046f010` - BrowserThread destructor/browser OLE alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the ordinary `BrowserThread` destructor and before `BrowserThread::RunMessageLoop`.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_46EFF0` at `0x0046eff0-0x0046f005`, padding bytes at `0x0046f005-0x0046f010`, and `sub_46F010` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md).

- `0x00470159-0x00470160` - BrowserControlPaneOld constructor/next helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the focused `BrowserControlPaneOld` constructor child and before the next helper function.
  - Evidence: 2026-06-01 IDA MCP reports `sub_46FF50` at half-open range `0x0046ff50-0x00470159`; byte check reports `0xcc` at `0x00470159-0x0047015f`, and `unknown_libname_10` begins at `0x00470160`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md).

- `0x004710cc-0x004710d0` - BrowserWindow release-adjustor/BrowserPane sound alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the BrowserWindow release adjustor tail thunks and before `BrowserPane::PlaySound`.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_4710C2` ending at `0x004710cc`, padding bytes at `0x004710cc-0x004710d0`, and `sub_4710D0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md), [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md).

- `0x004710df-0x004710e0` - BrowserPane sound/GUID compare alignment padding.
  - Why ignored: confirmed one-byte `0xcc` alignment after `BrowserPane::PlaySound` and before the browser COM GUID compare helper.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_4710D0` ending at `0x004710df`, padding byte at `0x004710df`, and `sub_4710E0` beginning at `0x004710e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md), [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md).

- `0x0047110e-0x00471110` - Browser GUID compare/CRT wide-format alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the browser COM GUID compare helper and before a CRT wide-format wrapper.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_4710E0` ending at `0x0047110e`, padding bytes at `0x0047110e-0x00471110`, and `sub_471110` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md), [UID:000219][0x00471110-0x00471141.CrtWideVsnprintfWrapper](by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md).

- `0x00471110-0x00471141` - CRT wide `vsnwprintf_s` wrapper.
  - Why ignored: CRT/static-runtime stdio wrapper around `__stdio_common_vsnwprintf_s`; not NexusTK product logic.
  - Evidence: [UID:000219][0x00471110-0x00471141.CrtWideVsnprintfWrapper](by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md) records the `sub_41B9A0` local-options call and `__stdio_common_vsnwprintf_s` forwarding pattern.
  - Replacement/procurement: MSVC CRT/UCRT runtime behavior; reconstructed source should use normal secure wide formatting APIs.
  - Owner docs: [UID:000219][0x00471110-0x00471141.CrtWideVsnprintfWrapper](by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md), [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md).

- `0x00471141-0x00471150` - CRT wide-format/BulletinSession alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the CRT wide-format wrapper and before `BulletinSession::BulletinSession`.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_471110` ending at `0x00471141`, padding bytes at `0x00471141-0x00471150`, and `sub_471150` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000219][0x00471110-0x00471141.CrtWideVsnprintfWrapper](by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md), [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md).

- `0x00471ff1-0x00472000` - BulletinSession/BulletinDialog alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the `BulletinSession` search-result handler and before raw `BulletinDialog` constructor bytes.
  - Evidence: 2026-05-27 IDA MCP function inventory reports `sub_471EA0` ending at `0x00471ff1`, padding bytes at `0x00471ff1-0x00472000`, and raw `BulletinDialog` constructor bytes beginning at `0x00472000`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md), [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md).

- `0x0047203a-0x00472040` - BulletinDialog constructor/command virtual alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw `BulletinDialog` constructor-shaped body and before `sub_472040`.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports only `0xcc` bytes in `0x0047203a-0x00472040`, with no function object and `sub_472040` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md).

- `0x00472069-0x00472070` - board-dialog command virtual/BoardArticleDialogs alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the board-dialog command-one virtual and before the board/article dialog aggregate begins.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports only `0xcc` bytes in `0x00472069-0x00472070`, with no function object and `sub_472070` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md), [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md).

- `0x00477790-0x004777a0` - BoardArticleDialogs/NewPredefinedFormArticleDialog alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the board/article dialog aggregate and before the predefined-form article dialog constructor.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports only `0xcc` bytes in `0x00477790-0x004777a0`, with no function object and `sub_4777A0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md), [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md).

- `0x00478f8e-0x00478f90` - NewPredefinedFormArticleDialog/TransferReplyAlert alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the final byte of `NewPredefinedFormArticleDialog::SubmitArticle` and before raw `TransferReplyAlert` constructor bytes.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports `sub_478BE0` ending end-exclusive at `0x00478f8e`, two `0xcc` bytes at `0x00478f8e-0x00478f90`, and constructor-shaped code beginning at `0x00478f90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZL][0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8d.NewPredefinedFormArticleDialog.md), [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md).

- `0x00478fd8-0x00478fe0` - TransferReplyAlert constructor/action alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the raw `TransferReplyAlert` constructor and before the confirmed `TransferReplyAlert::OnConfirm` function.
  - Evidence: 2026-05-27 IDA MCP raw disassembly reports `ret 0x0c` at `0x00478fd5`, alignment bytes at `0x00478fd8-0x00478fe0`, and `sub_478FE0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md), [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md).

- `0x0047ec6b-0x0047ec70` - NewPredefinedFormArticleDialog scalar destructor/ChangeMan alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the predefined-form article dialog scalar deleting destructor and before `ChangeMan` constructor code.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports five `0xcc` bytes in `0x0047ec6b-0x0047ec70`, with `sub_47EC30` ending at `0x0047ec6b` and `sub_47EC70` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md), [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md).

- `0x0047efae-0x0047efb0` - ChangeMan/ChattingUI alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `ChangeMan` scalar deleting destructor and before the chat UI constructor.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports two `0xcc` bytes in `0x0047efae-0x0047efb0`, with `sub_47EF50` ending at `0x0047efae` and `sub_47EFB0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x0047f1ce-0x0047f1d0` - ChattingPane constructor/destructor alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `ChattingPane` constructor and before `ChattingPane` destructor.
  - Evidence: 2026-05-30 IDA MCP function lookup and raw disassembly report `sub_47EFB0` ending at `0x0047f1ce`, `sub_47F1D0` beginning at `0x0047f1d0`, and two `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EO][0x0047efb0-0x0047f1ce.ChattingPaneConstructor](by-memory/0x0047efb0-0x0047f1ce.ChattingPaneConstructor.md), [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md).

- `0x0047f27e-0x0047f280` - ChattingPane destructor/FolderTreePane chat-message alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `ChattingPane` destructor and before the next chat-message helper.
  - Evidence: 2026-05-30 IDA MCP function lookup and raw disassembly report `sub_47F1D0` ending at `0x0047f27e`, `sub_47F280` beginning at `0x0047f280`, and two `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x0047f36f-0x0047f370` - AddChattingMessage/AddIncomingMessage alignment padding.
  - Why ignored: confirmed `0xcc` alignment byte after `sub_47F280` and before `sub_47F370`.
  - Evidence: 2026-05-30 IDA MCP function lookup and raw disassembly report `sub_47F280` ending at `0x0047f36f`, `sub_47F370` beginning at `0x0047f370`, and one `0xcc` byte between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EQ][0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage](by-memory/0x0047f280-0x0047f36f.FolderTreePaneAddChattingMessage.md), [UID:0002ER][0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage.md).

- `0x0047f512-0x0047f520` - AddIncomingMessage/ChattingPane scroll helpers alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `sub_47F370` and before `sub_47F520`.
  - Evidence: 2026-05-30 IDA MCP function lookup and raw disassembly report `sub_47F370` ending at `0x0047f512`, `sub_47F520` beginning at `0x0047f520`, and fourteen `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002ER][0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage](by-memory/0x0047f370-0x0047f512.FolderTreePaneAddIncomingMessage.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x0047f6e5-0x0047f6f0` - ChattingPane scroll metric virtuals/keyboard scroll handler alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the small scroll metric virtual cluster and before `ChattingPane` keyboard scroll handler.
  - Evidence: 2026-05-31 IDA MCP function inventory and byte audit reports `sub_47F6B0` ending at `0x0047f6e5`, `sub_47F6F0` beginning at `0x0047f6f0`, and eleven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002ES][0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals](by-memory/0x0047f520-0x0047f6e5.ChattingPaneScrollMetricVirtuals.md), [UID:0002ET][0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler](by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md).

- `0x0047f8c9-0x0047f8d0` - ChattingPane packet router/paint alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the chat packet router and before `ChattingPane::OnPaint`.
  - Evidence: 2026-05-31 IDA MCP function inventory and byte audit reports `sub_47F890` ending at `0x0047f8c9`, `sub_47F8D0` beginning at `0x0047f8d0`, and seven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md), [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md).

- `0x0047fbc5-0x0047fbd0` - ChattingPane paint/visible-row update alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after `ChattingPane::OnPaint` and before visible-row update helper.
  - Evidence: 2026-05-31 IDA MCP function inventory and byte audit reports `sub_47F8D0` ending at `0x0047fbc5`, `sub_47FBD0` beginning at `0x0047fbd0`, and eleven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EV][0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint](by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md), [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md).

- `0x0047fc6b-0x0047fc70` - ChattingPane visible-row update/line-count alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after visible-row update helper and before line-count helper.
  - Evidence: 2026-05-31 IDA MCP function inventory and byte audit reports `sub_47FBD0` ending at `0x0047fc6b`, `sub_47FC70` beginning at `0x0047fc70`, and five `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md), [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md).

- `0x0047fd3b-0x0047fd40` - ChattingPane line-count/raw scroll helper alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after line-count helper and before raw scroll-range helper.
  - Evidence: 2026-05-31 IDA MCP function inventory and byte audit reports `sub_47FC70` ending at `0x0047fd3b`, raw helper bytes beginning at `0x0047fd40`, and five `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md), [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md).

- `0x0047fd68-0x0047fd70` - ChattingPane raw scroll helper/packet type-13 alignment padding.
  - Why ignored: confirmed alignment bytes after raw scroll-range helper and before packet type-13 handler.
  - Evidence: 2026-05-31 IDA MCP raw disassembly reports a complete raw helper ending at `0x0047fd68`, `sub_47FD70` beginning at `0x0047fd70`, and alignment bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md), [UID:0002EZ][0x0047fd70-0x0047ff80.ChatPacketType13Handler](by-memory/0x0047fd70-0x0047ff80.ChatPacketType13Handler.md).

- `0x00480694-0x004806a0` - ChattingBackPane constructor/destructor alignment padding.
  - Why ignored: confirmed alignment bytes after the exact `ChattingBackPane` constructor and before the destructor body.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480640` ending at `0x00480694`, `sub_4806A0` beginning at `0x004806a0`, and twelve `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md), [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md).

- `0x004806c9-0x004806d0` - ChattingBackPane destructor/viewport helper alignment padding.
  - Why ignored: confirmed alignment bytes after the destructor body and before the viewport rectangle helper.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_4806A0` ending at `0x004806c9`, `sub_4806D0` beginning at `0x004806d0`, and seven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md), [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md).

- `0x00480739-0x00480740` - ChattingBackPane viewport helper/update virtual alignment padding.
  - Why ignored: confirmed alignment bytes after the viewport helper and before the `ChattingBackPane` update/visibility virtual.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_4806D0` ending at `0x00480739`, `sub_480740` beginning at `0x00480740`, and seven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md), [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md).

- `0x004807aa-0x004807b0` - ChattingBackPane/ChattingModifyHeightPane alignment padding.
  - Why ignored: confirmed alignment bytes after the `ChattingBackPane` update/visibility virtual and before the next `ChattingModifyHeightPane` function.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480740` ending at `0x004807aa`, `sub_4807B0` beginning at `0x004807b0`, and six `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x0048085e-0x00480860` - ChattingModifyHeightPane constructor/destructor alignment padding.
  - Why ignored: confirmed alignment bytes after the exact constructor and before the destructor body.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_4807B0` ending at `0x0048085e`, `sub_480860` beginning at `0x00480860`, and two `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md), [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md).

- `0x00480889-0x00480890` - ChattingModifyHeightPane destructor/mouse-handler alignment padding.
  - Why ignored: confirmed alignment bytes after the destructor body and before the mouse event method.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480860` ending at `0x00480889`, `sub_480890` beginning at `0x00480890`, and seven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md), [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md).

- `0x00480a7b-0x00480a80` - ChattingModifyHeightPane mouse/cancel input alignment padding.
  - Why ignored: confirmed alignment bytes after the mouse event method and before the cancel input helper.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480890` ending at `0x00480a7b`, `sub_480A80` beginning at `0x00480a80`, and five `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md), [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md).

- `0x00480ac5-0x00480ad0` - ChattingModifyHeightPane cancel/line-count helper alignment padding.
  - Why ignored: confirmed alignment bytes after the cancel input helper and before the line-count layout helper.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480A80` ending at `0x00480ac5`, `sub_480AD0` beginning at `0x00480ad0`, and eleven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md), [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md).

- `0x00480ba3-0x00480bb0` - ChattingModifyHeightPane line-count/paint alignment padding.
  - Why ignored: confirmed alignment bytes after the line-count layout helper and before the paint method.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480AD0` ending at `0x00480ba3`, `sub_480BB0` beginning at `0x00480bb0`, and thirteen `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md), [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md).

- `0x00480c45-0x00480c50` - ChattingModifyHeightPane/ChattingVarietyPane alignment padding.
  - Why ignored: confirmed alignment bytes after the paint method and before the next `ChattingVarietyPane` function.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480BB0` ending at `0x00480c45`, `sub_480C50` beginning at `0x00480c50`, and eleven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x00480c9f-0x00480ca0` - ChattingVarietyPane constructor/destructor alignment padding.
  - Why ignored: confirmed alignment byte after the constructor and before the destructor body.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480C50` ending at `0x00480c9f`, `sub_480CA0` beginning at `0x00480ca0`, and one `0xcc` byte between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md), [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md).

- `0x00480cc9-0x00480cd0` - ChattingVarietyPane destructor/mouse-handler alignment padding.
  - Why ignored: confirmed alignment bytes after the destructor body and before the mouse event method.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480CA0` ending at `0x00480cc9`, `sub_480CD0` beginning at `0x00480cd0`, and seven `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md), [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md).

- `0x00480ff1-0x00481000` - ChattingVarietyPane paint/refresh forwarder alignment padding.
  - Why ignored: confirmed alignment bytes after the paint method and before the tiny refresh forwarder.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_480E80` ending at `0x00480ff1`, `sub_481000` beginning at `0x00481000`, and fifteen `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md), [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md).

- `0x0048100a-0x00481010` - ChattingVarietyPane forwarder/raw selector helper alignment padding.
  - Why ignored: confirmed alignment bytes after the tiny refresh forwarder and before the raw selector rectangle helper.
  - Evidence: 2026-05-31 IDA MCP raw decode reports `sub_481000` ending at `0x0048100a`, raw code beginning at `0x00481010`, and six `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md), [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md).

- `0x00481056-0x00481060` - selector row rectangle/initial hit-test alignment padding.
  - Why ignored: confirmed alignment bytes after the raw row rectangle helper and before the raw hit-test helper.
  - Evidence: 2026-05-31 IDA MCP raw decode reports a helper ending at `0x00481056`, another beginning at `0x00481060`, and ten `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md), [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md).

- `0x004810ea-0x004810f0` - selector hit-test/raw constructor alignment padding.
  - Why ignored: confirmed alignment bytes after the raw hit-test helper and before the raw constructor body.
  - Evidence: 2026-05-31 IDA MCP raw decode reports a helper ending at `0x004810ea`, raw constructor body beginning at `0x004810f0`, and six `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md), [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md).

- `0x00481146-0x00481150` - ChattingVarietySelectPane raw constructor/destructor alignment padding.
  - Why ignored: confirmed alignment bytes after the raw constructor body and before the modeled destructor body.
  - Evidence: 2026-05-31 IDA MCP raw decode reports constructor body ending at `0x00481146`, `sub_481150` beginning at `0x00481150`, and ten `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md), [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md).

- `0x004811bc-0x004811c0` - ChattingVarietySelectPane destructor/mouse dispatcher alignment padding.
  - Why ignored: confirmed alignment bytes after the modeled destructor body and before the mouse dispatcher.
  - Evidence: 2026-05-31 IDA MCP function iteration reports `sub_481150` ending at `0x004811bc`, `sub_4811C0` beginning at `0x004811c0`, and four `0xcc` bytes between them.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x00481461-0x00481470`, `0x0048148f-0x00481490`, `0x004816ce-0x004816d0`, `0x00481741-0x00481750`, `0x00481a72-0x00481a80`, `0x00481acd-0x00481ad0`, `0x00481b5b-0x00481b60`, `0x00481bb9-0x00481bc0`, and `0x00481c05-0x00481c10` - ChattingVarietySelectPane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented selector methods/helpers.
  - Evidence: 2026-05-31 IDA MCP function/raw-body review reports exact code bodies at [UID:0002FJ][0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent](by-memory/0x004811c0-0x00481461.ChattingVarietySelectPaneOnMouseEvent.md), [UID:0002FK][0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss](by-memory/0x00481470-0x0048148f.ChattingVarietySelectPaneOnDismiss.md), [UID:0002FL][0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint](by-memory/0x00481490-0x004816ce.ChattingVarietySelectPaneOnPaint.md), [UID:0002FN][0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground](by-memory/0x004816d0-0x00481741.ChattingVarietySelectPaneSetupBackground.md), [UID:0002FO][0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder](by-memory/0x00481750-0x00481a72.ChattingVarietySelectPaneDrawBorder.md), [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md), [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md), [UID:0002FP][0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper](by-memory/0x00481b60-0x00481bb9.ChattingVarietySelectPaneStateCompareHelper.md), and [UID:0002FQ][0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper](by-memory/0x00481bc0-0x00481c05.ChattingVarietySelectPaneStateSnapshotHelper.md), with only `0xcc` bytes in the listed gaps.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md), [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md).

- `0x00481d2a-0x00481d30`, `0x00481d59-0x00481d60`, `0x0048214f-0x00482150`, `0x004822f6-0x00482300`, and `0x0048230a-0x00482310` - ChattingHandlePane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented handle-pane methods/helpers.
  - Evidence: 2026-05-31 IDA MCP function/raw-body review reports exact code bodies at [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md), [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md), [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md), [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md), [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md), and [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md), with only `0xcc` bytes in the listed gaps.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md), [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md).

- `0x00483ef7-0x00483f00` - ChattingUI/CheatDetector alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the chat UI cluster and before `CheatDetector` constructor code.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports nine `0xcc` bytes in `0x00483ef7-0x00483f00`, with `sub_483E60` ending at `0x00483ef7` and `sub_483F00` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md), [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md).

- `0x0048402d-0x00484030` - CheatDetector/ClanStatusPane alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the `CheatDetector` scalar deleting destructor helper and before `ClanStatusPane` constructor code.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports three `0xcc` bytes in `0x0048402d-0x00484030`, with `sub_484000` ending at `0x0048402d` and `sub_484030` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md), [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md).

- `0x00484222-0x00484230` - ClanStatusPane constructor/cleanup alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the `ClanStatusPane` constructor return and before compiler-generated constructor cleanup code.
  - Evidence: 2026-05-27 IDA MCP raw byte audit reports `sub_484030` ending end-exclusive at `0x00484222`, fourteen `0xcc` bytes at `0x00484222-0x00484230`, and cleanup-shaped code beginning at `0x00484230`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md).

- `0x00484230-0x004842ad` - ClanStatusPane constructor cleanup fragment.
  - Why ignored: compiler-generated constructor-unwind/destructor-support fragment that restores `ClanStatusPane` vtables, releases partially constructed child panes, clears the singleton/global, and tail-calls base teardown; not handwritten project behavior.
  - Evidence: [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md) records the raw disassembly and matching `0x0048c590` destructor-side vtable/global-store pattern.
  - Replacement/procurement: no direct source replacement; represented by normal C++ member ownership/destructor semantics.
  - Owner docs: [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x004842ad-0x004842b0` - ClanStatusPane cleanup/ClanAttributePacketParser alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the constructor cleanup fragment and before the clan attribute packet parser.
  - Evidence: 2026-05-27 IDA MCP raw disassembly shows cleanup code ending with a tail jump at `0x004842a8`, followed by `0xcc` bytes at `0x004842ad-0x004842b0`, with `sub_4842B0` beginning immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021B][0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup](by-memory/0x00484230-0x004842ad.ClanStatusPaneConstructorCleanup.md), [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md).

- `0x00484a51-0x00484a60` - ClanAttributePacketParser/ClanStatusPaneFrameAndInput alignment padding.
  - Why ignored: confirmed `0xcc` alignment bytes after the clan attribute parser's range-check-failure tail and before `ClanStatusPane::OnPaintFrame`.
  - Evidence: 2026-05-27 IDA MCP function-boundary audit reports `sub_4842B0` ending end-exclusive at `0x00484a51`; bytes `0x00484a51-0x00484a60` are `0xcc` alignment, and `sub_484A60` begins immediately after.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md), [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md).

- `0x00484f17-0x00484f18`, `0x00484f6a-0x00484f70`, `0x0048540b-0x0048540c`, `0x004854a6-0x004854b0`, `0x00485519-0x00485520`, `0x00485589-0x00485590`, `0x00485682-0x00485690`, and `0x004856f9-0x00485700` - Clan packet-handler/helper alignment padding.
  - Why ignored: confirmed alignment bytes between reviewed clan status packet handlers and helper routines; not source-authored behavior.
  - Evidence: 2026-05-27 IDA MCP disassembly reports `align 4`/`align 10h` directives at these boundaries after `sub_484DB0`, `sub_484F70`, raw opcode `0x4b` packet helpers, `sub_485590`, and the raw leave-request helper.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md), [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md), [UID:00021D][0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request](by-memory/0x00485440-0x004854a5.SendClanOpcode4BSubtype0Request.md), [UID:00021E][0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request](by-memory/0x004854b0-0x00485518.SendClanOpcode4BSubtype1Request.md), [UID:00021F][0x00485520-0x00485588.SendClanJoinListRefreshPacket](by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md), [UID:00021G][0x00485590-0x00485682.SendClanJoinListSelectionPacket](by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md), [UID:00021H][0x00485690-0x004856f9.SendClanLeaveRequestPacket](by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md), [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md).

- `0x00484f18-0x00484f6a` - ClanStatusPane mouse-event switch tables.
  - Why ignored: compiler-generated switch data for [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md); not handwritten product logic.
  - Evidence: 2026-05-27 IDA MCP xrefs show `sub_484DB0` switch jumps at `0x00484e3d` and `0x00484e87` reading `jpt_484E3D` at `0x00484f18`, `jpt_484E87` at `0x00484f50`, and an indirect byte table at `0x00484f5c`.
  - Replacement/procurement: no source replacement; generated from the `ClanStatusPane::OnMouseEvent` switch statements.
  - Owner docs: [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md).

- `0x0048540c-0x00485440` - ClanStatusPacketDispatcher switch table.
  - Why ignored: compiler-generated jump table for [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md)'s 13-case packet switch.
  - Evidence: 2026-05-27 IDA MCP xrefs show `sub_484F70` jump at `0x00484fba` reading `jpt_484FBA` at `0x0048540c`.
  - Replacement/procurement: no source replacement; generated from the clan packet-dispatch switch.
  - Owner docs: [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x00485779-0x00485780`, `0x00485867-0x00485870`, `0x00485955-0x00485960`, and `0x00485abe-0x00485ac0` - Clan deposit/subtype-6 packet helper alignment padding.
  - Why ignored: confirmed alignment bytes between reviewed clan opcode `0x4b` helper clusters; not source-authored behavior.
  - Evidence: 2026-05-27 IDA MCP disassembly reports `align 10h` directives after [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md), after [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyPacketHelpers.md), after [UID:00021J][0x00485870-0x00485955.ClanDepositItemPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemPacketHelpers.md), and after [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000I8][Clan](by-file/Clan.md), [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyPacketHelpers.md), [UID:00021J][0x00485870-0x00485955.ClanDepositItemPacketHelpers](by-memory/0x00485870-0x00485955.ClanDepositItemPacketHelpers.md), [UID:00021K][0x00485960-0x00485abe.ClanSubtype6PacketHelpers](by-memory/0x00485960-0x00485abe.ClanSubtype6PacketHelpers.md), [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md).

- `0x00485cbe-0x00485cc0` and `0x0048632e-0x00486330` - Clan name-action packet helper alignment padding.
  - Why ignored: confirmed alignment bytes around the clan opcode `0x4b` subtype `6-10` action-helper strip.
  - Evidence: 2026-05-27 IDA MCP disassembly reports `align 10h` bytes after [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md) and after [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md), before [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000I8][Clan](by-file/Clan.md), [UID:00021L][0x00485cc0-0x0048632e.ClanNameActionPacketHelpers](by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md), [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md).

- `0x0048652e-0x00486530` and `0x004867f2-0x00486800` - Clan withdraw/helper-to-row alignment padding.
  - Why ignored: confirmed alignment bytes around the clan opcode `0x4b` subtype `11-13` helper strip.
  - Evidence: 2026-05-27 IDA MCP disassembly reports `align 10h` bytes after [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) and after [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md), before [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0000I8][Clan](by-file/Clan.md), [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md), [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md).

- `0x00487292-0x00487294`, `0x00487294-0x004872d8`, and `0x004872d8-0x004872e0` - ClanStatusPane row-hit-test switch data and alignment.
  - Why ignored: compiler-generated alignment and jump-table data after [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md), not handwritten source behavior.
  - Evidence: 2026-05-27 IDA MCP reports `align 4` at `0x00487292`, `jpt_486FB8` at `0x00487294` referenced from `0x00486fb8`, and `align 10h` at `0x004872d8` before raw helper code at `0x004872e0`.
  - Replacement/procurement: no source replacement; generated from the `ClanStatusPane::HitTestRow` switch.
  - Owner docs: [UID:00010G][0x00486800-0x00487291.ClanStatusPaneRows](by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x00487336-0x00487338` and `0x00487338-0x00487370` - ClanStatusPane row-eligibility switch data and alignment.
  - Why ignored: compiler-generated alignment and jump-table data for [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md).
  - Evidence: 2026-05-27 IDA MCP reports the row-eligibility helper returning at `0x00487335`, two alignment bytes before `jpt_4872EF`, and the jump table `0x00487338-0x00487370` referenced from `0x004872ef`.
  - Replacement/procurement: no source replacement; generated from the helper's row-index switch.
  - Owner docs: [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x004873b6-0x004873c0`, `0x00487476-0x00487480`, `0x00487536-0x00487540`, and `0x004875f6-0x00487600` - ClanStatusPane child-view helper alignment padding.
  - Why ignored: confirmed alignment bytes between the child-pane refresh helper, three raw child-view switch helpers, and [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md).
  - Evidence: 2026-05-27 IDA MCP reports `align 10h` after `sub_487370`, after raw helpers ending at `0x00487475`, `0x00487535`, and `0x004875f5`, and before `sub_487600`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), [UID:00021P][0x004873c0-0x00487475.ClanStatusPaneShowInfoList](by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md), [UID:00021Q][0x00487480-0x00487535.ClanStatusPaneShowJoinList](by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md), [UID:00021R][0x00487540-0x004875f5.ClanStatusPaneShowEnlistList](by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md), [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md).

- `0x004877a0-0x004877d0` - ClanStatusRowActionPacket switch table.
  - Why ignored: compiler-generated jump-table data for [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md), not source-authored behavior.
  - Evidence: 2026-05-27 IDA MCP reports `jpt_487623` at `0x004877a0`, referenced from the switch jump at `0x00487623`.
  - Replacement/procurement: no source replacement; generated from the row-action packet helper switch.
  - Owner docs: [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md), [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x004879d8-0x004879e0`, `0x00487c37-0x00487c40`, `0x00487d61-0x00487d70`, `0x00487e13-0x00487e20`, `0x00487e9c-0x00487ea0`, `0x00488167-0x00488170`, `0x00488213-0x00488220`, `0x004882c3-0x004882d0`, `0x0048836b-0x00488370`, `0x0048845d-0x00488460`, and `0x00488503-0x00488510` - ClanStatusPacketDialogHandlers internal alignment padding.
  - Why ignored: confirmed alignment bytes between functions in [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md).
  - Evidence: 2026-05-27 IDA MCP function inventory reports the exact end-exclusive function boundaries from `sub_4877D0` through `sub_488510`, with `align 10h` padding before the next function start at each listed interval.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes within the Clan packet-dialog helper island.
  - Owner docs: [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md), [UID:00021C][0x00484f70-0x0048540b.ClanStatusPacketDispatcher](by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md), [UID:0000I8][Clan](by-file/Clan.md).

- `0x00488594-0x004885a0` and `0x00488603-0x00488610` - Clan packet/dialog helper to list-pane constructor/virtual alignment padding.
  - Why ignored: confirmed alignment bytes before and after [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md).
  - Evidence: 2026-05-27 IDA MCP raw head and byte audit reports `align 10h` at `0x00488594`, constructor-shaped bytes at `0x004885a0-0x00488602`, and `align 10h` bytes at `0x00488603-0x00488610` before `sub_488610`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md), [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md), [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md).

- `0x004888f1-0x00488900`, `0x00488968-0x00488970`, `0x00488991-0x004889a0`, and `0x00488b3d-0x00488b40` - Clan list-pane virtual handler alignment padding.
  - Why ignored: confirmed alignment bytes around and inside [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md), not source-authored behavior.
  - Evidence: 2026-05-27 IDA MCP raw head audit reports `sub_4888D0` ending at `0x004888f1`, `sub_488900` at `0x00488900-0x00488968`, `sub_488970` at `0x00488970-0x00488991`, `sub_4889A0` at `0x004889a0-0x00488b3d`, and `0xcc` alignment in each listed interval.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md), [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md), [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md).

- `0x00488615-0x00488620`, `0x00488625-0x00488630`, `0x00488674-0x004887d0`, and `0x004888c1-0x004888d0` - Clan list-pane virtual/internal alignment padding.
  - Why ignored: confirmed `0xcc` padding between exact `ClanInfoListPane` false-return virtuals, the raw `ClanStringListPane` constructor-shaped block, the shared draw method, and the `ClanJoinListPane` selected-row action method.
  - Evidence: 2026-05-31 IDA MCP `py_eval` byte audit reports `0xcc` bytes in each listed span; `lookup_funcs` and raw disassembly bound the neighboring source-relevant items as [UID:0002NN][0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual](by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md), [UID:0002NO][0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual](by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md), [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md), [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md), and [UID:0002NR][0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction](by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010I][0x00488610-0x004888f0.ClanListPaneVirtuals](by-memory/0x00488610-0x004888f0.ClanListPaneVirtuals.md) and the exact child docs listed above.

- `0x00488fd5-0x00488fe0` - ClanDepMoneyInputDialog raw constructor to submitter alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) and before [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md).
  - Evidence: 2026-05-27 IDA MCP raw head audit reports constructor-shaped bytes ending at `0x00488fd5` and `0xcc` alignment bytes through `0x00488fe0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md).

- `0x00489062-0x00489070`, `0x004890a5-0x004890b0`, `0x00489132-0x00489140`, `0x00489175-0x00489180`, `0x0048926e-0x00489270`, `0x004892a5-0x004892b0`, `0x0048939e-0x004893a0`, `0x004893d5-0x004893e0`, `0x004894ce-0x004894d0`, and `0x00489505-0x00489510` - Clan name/money dialog submitter-family internal alignment padding.
  - Why ignored: confirmed `0xcc` alignment spans between exact submitter functions and raw constructor-shaped bodies in the `ClanNameInputDialog` derived family.
  - Evidence: 2026-05-31 IDA MCP byte audit verified every listed span is all `0xcc`; `lookup_funcs` and disassembly bound the neighboring source-relevant children as [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md), [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md), [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md), [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md), [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md), [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md), [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md), [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md), [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md), [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md), and [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md) and the exact child docs listed above.

- `0x004895fe-0x00489600` - ClanNameDialogSubmitters to ClanAttrInputDialogCore alignment padding.
  - Why ignored: confirmed two-byte compiler alignment after [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md) and before [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_489510` at `0x00489510-0x004895fe`, next function `sub_489600` at `0x00489600`, and bytes `cc cc` in the intervening span.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md), [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md).

- `0x00489fb5-0x00489fc0` - ClanEnlistInputDialog raw constructor to submitter alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md) and before [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md).
  - Evidence: 2026-05-27 IDA MCP raw head audit reports constructor-shaped bytes ending at `0x00489fb5`, then eleven `0xcc` bytes before `sub_489FC0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md).

- `0x00489fe9-0x00489ff0` - ClanEnlistInputDialog submitter to ClanChangeInputDialog raw constructor alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) and before [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md).
  - Evidence: 2026-05-31 IDA MCP byte audit reports seven `0xcc` bytes between `sub_489FC0` end and the raw constructor-shaped body at `0x00489ff0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md), [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md).

- `0x0048a025-0x0048a030` - ClanChangeInputDialog raw constructor to submitter alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) and before [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md).
  - Evidence: 2026-05-31 IDA MCP byte audit reports eleven `0xcc` bytes between the raw constructor-shaped body and `sub_48A030`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md), [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md).

- `0x0048a059-0x0048a060` - ClanChangeInputDialog submitter to ClanLeaveConfirmDialog raw constructor alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md) and before [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md).
  - Evidence: 2026-05-31 IDA MCP byte audit reports seven `0xcc` bytes between `sub_48A030` end and the raw constructor-shaped body at `0x0048a060`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md), [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md).

- `0x0048a09e-0x0048a0a0` - ClanLeaveConfirmDialog raw constructor to confirm callback alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md) and before [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md).
  - Evidence: 2026-05-31 IDA MCP byte audit reports two `0xcc` bytes before `sub_48A0A0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md), [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md).

- `0x0048a0ae-0x0048a0b0` - ClanLeaveConfirmDialog confirm to cancel callback alignment padding.
  - Why ignored: confirmed alignment bytes after [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) and before [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md).
  - Evidence: 2026-05-31 IDA MCP byte audit reports two `0xcc` bytes before `sub_48A0B0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md), [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md).

- `0x0048a0be-0x0048a0c0` - ClanLeaveConfirmDialog to ClanItemDialog raw constructor alignment padding.
  - Why ignored: confirmed two-byte compiler alignment after [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) and before [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48A0B0` at `0x0048a0b0-0x0048a0be`, followed by `cc cc` before constructor-shaped bytes at `0x0048a0c0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md), [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md).

- `0x0048a0fb-0x0048a100` - ClanItemDialog raw constructor to vtable-reset helper alignment padding.
  - Why ignored: confirmed five-byte compiler alignment after [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md) and before [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md).
  - Evidence: 2026-05-27 IDA MCP raw head audit reports constructor-shaped bytes ending at `0x0048a0fb`, then five `0xcc` bytes before `sub_48A100`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021X][0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor](by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md), [UID:0002OC][0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail](by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md).

- `0x0048a1be-0x0048a1c0` - ClanItemDialog confirm callback to ClanDepItemDialog alignment padding.
  - Why ignored: confirmed two-byte compiler alignment after [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md) and before [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48A120` at `0x0048a120-0x0048a1be`, followed by `cc cc` before `sub_48A1C0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002OB][0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation](by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md), [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md).

- `0x0048a805-0x0048a810` - ClanDepItemDialog to ClanWidItemDialog alignment padding.
  - Why ignored: confirmed eleven-byte compiler alignment after [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md) and before [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48A790` at `0x0048a790-0x0048a805`, followed by eleven `0xcc` bytes before `sub_48A810`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010O][0x0048a1c0-0x0048a805.ClanDepItemDialog](by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md), [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md).

- `0x0048ae65-0x0048ae70` - ClanWidItemDialog to ClanItemListPane alignment padding.
  - Why ignored: confirmed eleven-byte compiler alignment after [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md) and before [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48ADF0` at `0x0048adf0-0x0048ae65`, followed by eleven `0xcc` bytes before `sub_48AE70`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md), [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md).

- `0x0048b1b1-0x0048b1c0` - ClanItemListPane to ClanBankPane alignment padding.
  - Why ignored: confirmed fifteen-byte compiler alignment after [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) and before [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48B0A0` at `0x0048b0a0-0x0048b1b1`, followed by fifteen `0xcc` bytes before `sub_48B1C0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md), [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md).

- `0x0048b7dc-0x0048b7e0` - ClanBankPane to raw bank packet helper alignment padding.
  - Why ignored: confirmed four-byte compiler alignment after [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md) and before [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48B630` at `0x0048b630-0x0048b7dc`, followed by four `0xcc` bytes before helper-shaped bytes at `0x0048b7e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md), [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md).

- `0x0048b8bc-0x0048b8c0` - raw bank packet helper to ClanBankItemListPane alignment padding.
  - Why ignored: confirmed four-byte compiler alignment after [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) and before [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md).
  - Evidence: 2026-05-27 IDA MCP reports the second helper-shaped body returning at `0x0048b8bb`, followed by four `0xcc` bytes before `sub_48B8C0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md), [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md).

- `0x0048c251-0x0048c260` - ClanBankItemListPane to ClanDestructorBand alignment padding.
  - Why ignored: confirmed fifteen-byte compiler alignment after [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md) and before [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_48C040` at `0x0048c040-0x0048c251`, followed by fifteen `0xcc` bytes before `sub_48C260`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010S][0x0048b8c0-0x0048c251.ClanBankItemListPane](by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md), [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md).

- `0x0048c63f-0x0048c640` - ClanDestructorBand to CollectionDialogControls alignment padding.
  - Why ignored: confirmed one-byte compiler alignment after [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md) and before [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md).
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs` reports `sub_48C590` size `0xaf`, so the function ends at `0x0048c63f` exclusive. Direct PE byte review shows the final `retn 04` immediate byte at `0x0048c63e`, one `0xcc` byte at `0x0048c63f`, and `sub_48C640` beginning at `0x0048c640`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md), [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md).

- `0x0048e305-0x0048e310` - CollectionDialogControls to ConfigRawTableHelpers alignment padding.
  - Why ignored: confirmed eleven-byte compiler alignment after [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md) and before [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).
  - Evidence: 2026-05-27 direct PE byte review shows `CollectionEntryControlPane` destructor returns at `0x0048e304`, followed by eleven `0xcc` bytes before the helper prologue at `0x0048e310`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00010X][0x0048c640-0x0048e305.CollectionDialogControls](by-memory/0x0048c640-0x0048e305.CollectionDialogControls.md), [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).

- `0x0048e408-0x0048e410` - Config raw helper internal alignment padding.
  - Why ignored: confirmed eight-byte compiler alignment between the `0x0048e310` and `0x0048e410` helper bodies inside [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).
  - Evidence: 2026-05-27 direct PE byte review shows the first helper epilogue ending at `0x0048e407`, followed by eight `0xcc` bytes and the second helper body at `0x0048e410`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md).

- `0x0048e479-0x0048e480` - ConfigRawTableHelpers to InitializeConfigEntry alignment padding.
  - Why ignored: confirmed seven-byte compiler alignment after [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md) and before [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md).
  - Evidence: 2026-05-27 direct PE byte review shows the second helper returns at `0x0048e478`, followed by seven `0xcc` bytes before `InitializeConfigEntry` at `0x0048e480`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00021Z][0x0048e310-0x0048e479.ConfigRawTableHelpers](by-memory/0x0048e310-0x0048e479.ConfigRawTableHelpers.md), [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md).

- `0x0048f3f1-0x0048f400` - ConfigAndRegistryDefaults to RegistryCommandLineParsers alignment padding.
  - Why ignored: confirmed fifteen-byte compiler alignment after [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md) and before [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md).
  - Evidence: 2026-05-27 direct PE byte review shows `RegistryConfig::InitializeDefaults` returning at `0x0048f3f0`, followed by fifteen `0xcc` bytes before the helper prologue at `0x0048f400`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000110][0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults](by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md), [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md).

- `0x00491b28-0x00491b30` - RegistryCommandLineParsers to RegistryPersistence alignment padding.
  - Why ignored: confirmed eight-byte compiler alignment after [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) and before [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md).
  - Evidence: 2026-05-27 direct PE byte review shows the last command-line/session helper returning at `0x00491b27`, followed by eight `0xcc` bytes before `RegistryConfig::SaveToRegistry` at `0x00491b30`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md), [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md).

- `0x00492695-0x004926a0` - RegistryConfig save/load alignment padding.
  - Why ignored: confirmed eleven-byte compiler alignment after [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md) and before [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md).
  - Evidence: 2026-06-01 IDA MCP function inventory reports `sub_491B30` ending at `0x00492695` and `sub_4926A0` starting at `0x004926a0`; byte review in that span shows `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002P7][0x00491b30-0x00492695.RegistryConfigSaveToRegistry](by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md), [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md).

- `0x00494126-0x00494130` - Config cleanup to ConfigEntryBlock cleanup alignment padding.
  - Why ignored: confirmed ten-byte compiler alignment after [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md) and before [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md).
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs` reports `sub_494020` ending at `0x00494126` and `sub_494130` starting at `0x00494130`; the intervening bytes are `0xcc` alignment padding.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002P9][0x00494020-0x00494126.ConfigDeletingDestructor](by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md), [UID:0002PA][0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers](by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md).

- `0x004941d6-0x004941e0` - Registry persistence cleanup to MSVC COM helper alignment padding.
  - Why ignored: confirmed ten-byte compiler alignment after [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md) and before [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_494130` size `0xa6`, ending at `0x004941d6`; direct PE byte review shows ten `0xcc` bytes through `0x004941e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000111][0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup](by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md), [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md).

- `0x004941e0-0x00494519` - MSVC COM support and CRT formatting helper island.
  - Why ignored: real executable helper bodies, but IDA decompilation matches Microsoft COM support and CRT wrapper code rather than NexusTK-authored class/gameplay code.
  - Evidence: 2026-05-27 IDA MCP reports functions at `0x004941e0`, `0x004943a0`, `0x00494440`, `0x004944a0`, `0x004944c0`, and `0x004944f0`. Decompilation shows `_com_ptr_t::CreateInstance`-style COM creation, refcounted BSTR holder cleanup, `_freea` sentinel cleanup, narrow formatting wrapper, and `__stdio_common_vswscanf` forwarding.
  - Replacement/procurement: no NexusTK source replacement; express the caller-side COM/scanning operations in source and let the MSVC runtime/headers provide equivalent helper code.
  - Owner docs: [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md).

- `0x00494519-0x00494520` - MSVC COM helper island to ConnStatusPane alignment padding.
  - Why ignored: confirmed seven-byte compiler alignment after [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md) and before [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_4944F0` size `0x29`, ending at `0x00494519`; direct PE byte review shows seven `0xcc` bytes before `ConnStatusPane::ConnStatusPane` at `0x00494520`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000221][0x004941e0-0x00494519.MsvcComAndFormattingHelpers](by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md), [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md).

- `0x004949df-0x004949e0` - ConnStatusPane to ControlPane alignment padding.
  - Why ignored: confirmed one-byte compiler alignment after [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) and before [UID:000114][0x004949e0-0x00494bf6.ControlPane](by-memory/0x004949e0-0x00494bf6.ControlPane.md).
  - Evidence: 2026-05-27 IDA MCP reports `sub_494980` size `0x5f`, ending at `0x004949df`; direct PE byte review shows `0xcc` at `0x004949df` and the `ControlPane` constructor prologue at `0x004949e0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md), [UID:000114][0x004949e0-0x00494bf6.ControlPane](by-memory/0x004949e0-0x00494bf6.ControlPane.md).

- `0x00494a81-0x00494a90`, `0x00494ae7-0x00494af0`, `0x00494b4b-0x00494b50`, `0x00494bea-0x00494bf0`, and `0x00494bf7-0x00494c00` - alignment padding in the ControlPane/progress-bar/button-control helper neighborhood.
  - Why ignored: confirmed compiler alignment between exact neighboring helper bodies; not source-authored logic.
  - Evidence: 2026-06-01 IDA MCP byte review reports all listed spans consist entirely of `0xcc` bytes. Function/boundary evidence places `ControlPane::ControlPane` at [UID:0002PB][0x004949e0-0x00494a81.ControlPaneConstructor](by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md), raw progress-bar helpers at [UID:000115][0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter](by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md) and [UID:000117][0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter](by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md), button/radio helpers after `0x00494b50`, and `ControlPane::IgnoresHitTesting` at [UID:0002PC][0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting](by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000114][0x004949e0-0x00494bf6.ControlPane](by-memory/0x004949e0-0x00494bf6.ControlPane.md), [UID:000116][0x00494a90-0x00494b4b.ProgressBarRangeSetters](by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md), [UID:000118][0x00494b50-0x00499e30.ButtonChoiceControlCore](by-memory/0x00494b50-0x00499e30.ButtonChoiceControlCore.md).

- `0x0049b915-0x0049b920`, `0x0049b925-0x0049b930`, `0x0049ba2b-0x0049ba30`, and `0x0049bad9-0x0049bae0` - alignment padding around static/control helper tail functions.
  - Why ignored: confirmed `0xcc` compiler/linker alignment between exact IDA function bodies; not source-authored logic.
  - Evidence: 2026-05-27 IDA MCP reports `sub_49B910` size `0x5`, `sub_49B920` size `0x5`, `sub_49B9F0` size `0x3b`, and `sub_49BAA0` size `0x39`. The following functions start at `0x0049b920`, `0x0049b930`, `0x0049ba30`, and `0x0049bae0`, leaving these exact padding spans.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00011V][0x0049a410-0x0049b915.StaticTextControlPane2](by-memory/0x0049a410-0x0049b915.StaticTextControlPane2.md), [UID:000222][0x0049b920-0x0049b925.StaticTextControlPaneTypeId](by-memory/0x0049b920-0x0049b925.StaticTextControlPaneTypeId.md), [UID:000223][0x0049b930-0x0049ba2b.ControlPaneScrollOffsetHelpers](by-memory/0x0049b930-0x0049ba2b.ControlPaneScrollOffsetHelpers.md), [UID:000224][0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers](by-memory/0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers.md), [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md).

- `0x0049ba30-0x0049bad9` - MSVC aligned array allocation/free helper pair.
  - Why ignored: runtime/compiler helper code for 16-byte element arrays and 32-byte large-allocation alignment, not NexusTK-authored product behavior.
  - Evidence: [UID:000224][0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers](by-memory/0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers.md) records IDA MCP decompilation and caller evidence. The helper pair wraps `operator new`, `_invalid_parameter_noinfo_noreturn`, a 32-byte alignment mask, a back-pointer cookie, and a common free helper.
  - Replacement/procurement: express source-level allocation normally and let MSVC/runtime support or a deliberate local allocator provide equivalent generated code.
  - Owner docs: [UID:000224][0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers](by-memory/0x0049ba30-0x0049bad9.MsvcAlignedArrayAllocationHelpers.md).

- `0x0049bbef-0x0049bbf0`, `0x0049bca9-0x0049bcb0`, and `0x0049bce8-0x0049bcf0` - alignment padding around checksum and critical-section helper tail functions.
  - Why ignored: confirmed `0xcc` compiler/linker alignment between exact helper bodies; not source-authored logic.
  - Evidence: 2026-05-27 IDA MCP/raw disassembly shows `Crasher::ScalarDeletingDestructor` ending at `0x0049bbef`, checksum helper bodies at `0x0049bbf0-0x0049bca9`, critical-section wrappers at `0x0049bcb0-0x0049bce8`, and `CriticalSectionLock::CriticalSectionLock` starting at `0x0049bcf0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md), [UID:000225][0x0049bbf0-0x0049bca9.ChecksumTableHelpers](by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md), [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md), [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md).

- `0x0049bd19-0x0049bd20` and `0x0049bd2c-0x0049bd30` - alignment padding around the DAT manager find-entry forwarder.
  - Why ignored: confirmed `0xcc` compiler/linker alignment before and after the tiny public DAT manager wrapper at `0x0049bd20-0x0049bd2c`.
  - Evidence: 2026-05-27 IDA MCP/raw disassembly shows `CriticalSectionLock::~CriticalSectionLock` ending at `0x0049bd19`, the wrapper body at `0x0049bd20-0x0049bd2c`, and `DATFileMgr::DATFileMgr` beginning at `0x0049bd30`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md), [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md), [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md).

- `0x0049d6ed-0x0049d6f0` - alignment padding between DAT managers and `DescPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment after `_DATFileMgr::FindNodeByKey` and before the raw `DescPane` constructor body.
  - Evidence: 2026-05-27 IDA MCP/raw bytes show `_DATFileMgr::FindNodeByKey` ending at `0x0049d6ed`; the preceding `retn 8` occupies `0x0049d6ea-0x0049d6ec`, and bytes `0x0049d6ed-0x0049d6f0` are three `0xcc` alignment bytes before `DescPane` starts at `0x0049d6f0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md).

- `0x0049d89f-0x0049d8a0` - alignment padding between `DescPane` and `DialogPane`.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte after `DescPane` scalar deleting destructor and before `DialogPane`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs` reports `0x0049d840` size `0x5f`, so the `DescPane` scalar deleting destructor ends at `0x0049d89f`; raw bytes at `0x0049d89c` are `c2 04 00 cc 55 8b ec 6a`, with `0x0049d89f` as padding before `DialogPane` starts at `0x0049d8a0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md), [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md).

- `0x0049feae-0x0049feb0` - alignment padding between `DialogPane` and `AlertPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final `DialogPane` method and before `AlertPane`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x0049fe80` reports `sub_49FE20` size `0x8e`, placing the end-exclusive bound at `0x0049feae`; raw bytes around the end are `8b e5 5d c3 cc cc 55 8b`, so `0x0049feae-0x0049feb0` is padding before `AlertPane` starts at `0x0049feb0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012R][0x0049d8a0-0x0049feae.DialogPane](by-memory/0x0049d8a0-0x0049feae.DialogPane.md), [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md).

- `0x004a0686-0x004a0690` - alignment padding between `AlertPaneCore` and `VersatileAlertPane` callbacks.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final `AlertPaneCore` method and before `VersatileAlertPane`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a0580` reports `sub_4A0580` size `0x106`, placing the end-exclusive bound at `0x004a0686`; raw bytes after the `retn 8` are ten `0xcc` bytes before `0x004a0690`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md).

- `0x004a0752-0x004a0760` - alignment padding between `VersatileAlertPane` callbacks and `ModelessDialogPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the `0x004a0740` callback and before `ModelessDialogPane`.
  - Evidence: 2026-05-27 IDA MCP/raw disassembly shows the final callback `retn` at `0x004a0751`; raw bytes after it are fourteen `0xcc` bytes before `ModelessDialogPane` begins at `0x004a0760`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md), [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md).

- `0x004a0c8e-0x004a0c90` and `0x004a0c90-0x004a0cb0` - `ModelessDialogPane` mouse-handler alignment and switch jump-table data.
  - Why ignored: the first two bytes are compiler alignment (`66 90`), and the following 32 bytes are a compiler-generated jump table for the preceding `ModelessDialogPane::HandleMouseEvent` switch.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a0c80` reports `sub_4A0840` size `0x44e`, ending at `0x004a0c8e`; `xrefs_to 0x004a0c90` reports a data reference from `sub_4A0840` at `0x004a0871`; raw bytes at `0x004a0c90` are eight little-endian addresses inside the handler.
  - Replacement/procurement: no source replacement; a compiler will regenerate equivalent switch data from the recovered `switch`.
  - Owner docs: [UID:00012Z][0x004a0760-0x004a0c8e.ModelessDialogPane](by-memory/0x004a0760-0x004a0c8e.ModelessDialogPane.md), [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md).

- `0x004a0d37-0x004a0d40` and `0x004a0d71-0x004a0d80` - alignment padding around help-pane singleton close helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment before and after the tiny help-pane close-helper pair.
  - Evidence: 2026-05-27 IDA MCP/raw disassembly shows `VersatileAlertPane::ScalarDeletingDestructor` ending at `0x004a0d37`, close helpers at `0x004a0d40-0x004a0d51` and `0x004a0d60-0x004a0d71`, and `DialogSessionCore` beginning at `0x004a0d80`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md), [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md), [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md).

- `0x004a15f8-0x004a1600` - alignment padding between `DialogSessionCore` and DIBitmap/PCX loaders.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final `DialogSessionCore` function and before the DIBitmap loader range.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a15f0` reports the containing function `sub_4A1500` size `0xf8`, ending at `0x004a15f8`; raw bytes after `retn 4` are eight `0xcc` bytes before `0x004a1600`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md), [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md).

- `0x004a1b5e-0x004a1b60` - alignment padding between DIBitmap/PCX loaders and `DirectX`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `DIBitmap::ScalarDeletingDestructor` and before the `DirectX` range.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a1b5d` maps the byte to `sub_4A1B10`, size `0x4e`; raw bytes show `c2 04 00` at `0x004a1b5b-0x004a1b5d` followed by two `0xcc` bytes before `DirectX` begins at `0x004a1b60`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md), [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md).

- `0x004a1d6a-0x004a1d70` - alignment padding between `DirectX` and `EmployeeDialogPanes`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final DirectX helper and before the employee dialog range.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a1b60` reports `sub_4A1B60` size `0xf6`, ending at `0x004a1d6a`; raw bytes after `retn 4` are six `0xcc` bytes before `0x004a1d70`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md), [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md).

- `0x004a4e6b-0x004a4e70` - alignment padding between `EmployeeDialogPanes` and `EncoderCore`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final employee-dialog scalar deleting destructor and before `Encoder::Encoder`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a4e30` reports size `0x3b`, ending at `0x004a4e6b`; raw bytes after `retn 4` are five `0xcc` bytes before `0x004a4e70`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md), [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md).

- `0x004a5621-0x004a5630` - alignment padding between `EncoderCore` and codec vtable glue.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `Encoder::Finalize` and before the encoder no-op virtual slot.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a55e0` reports size `0x41`, ending at `0x004a5621`; raw bytes after `retn 4` are fifteen `0xcc` bytes before `0x004a5630`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md), [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md).

- `0x004a5e54-0x004a5e60` - alignment padding between codec vtable glue and `ParseEntries`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `Encoder::ScalarDeletingDestructor` and before `ParseEntries`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a5e30` reports size `0x24`, ending at `0x004a5e54`; raw bytes after `retn 4` are twelve `0xcc` bytes before `0x004a5e60`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md), [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md).

- `0x004a609f-0x004a60a0`, `0x004a60a0-0x004a60cb`, and `0x004a60cb-0x004a60d0` - padding plus MSVC-style integer runtime helpers before `ErrorWrappers`.
  - Why ignored: `0x004a609f` and `0x004a60cb-0x004a60d0` are compiler alignment bytes; `0x004a60a0-0x004a60cb` is runtime/compiler helper code, not NexusTK handwritten source.
  - Evidence: 2026-05-27 IDA MCP raw disassembly shows a complete helper-shaped body at `0x004a60a0-0x004a60c0`, modeled helper `unknown_libname_12` at `0x004a60c0-0x004a60cb`, and `0xcc` padding before and after. IDA decompilation labels `0x004a60c0` as Microsoft Visual C runtime and returns `HIDWORD(a1) | a1`; `xrefs_to` reports no current direct xrefs to either helper start.
  - Replacement/procurement: no NexusTK source replacement; compiler/runtime code should be supplied by the toolchain or regenerated from source-level expressions.
  - Owner docs: [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md), [UID:000229][0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers](by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md), [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md).

- `0x004a6a76-0x004a6a80` - alignment padding between `ErrorWrappers` and `EventDispatcher`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the last error-wrapper helper and before `sub_4A6A80`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a6a76` reports "Not a function"; raw bytes at `0x004a6a76-0x004a6a80` are ten `0xcc` bytes; `lookup_funcs 0x004a6a80` reports `sub_4A6A80` size `0x16e`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00013X][0x004a60d0-0x004a6a76.ErrorWrappers](by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md).

- `0x004a82a9-0x004a82b0` - alignment padding between the `EventDispatcher` aggregate and handler-record relink helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the final byte of `sub_4A7E70` and before `sub_4A82B0`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a7e70` reports size `0x439`, making the exclusive end `0x004a82a9`; raw bytes at `0x004a82a9-0x004a82b0` are seven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md).

- `0x004a8795-0x004a87a0` - alignment padding between handler-record relink helpers and vector-free helper.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4A8740` and before `sub_4A87A0`.
  - Evidence: 2026-05-27 IDA MCP `py_eval` lists `sub_4A8740` as `0x004a8740-0x004a8795`; raw bytes at `0x004a8795-0x004a87a0` are eleven `0xcc` bytes; `lookup_funcs 0x004a87a0` reports `sub_4A87A0` size `0x70`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md).

- `0x004a8810-0x004a8820` - alignment padding between handler-record vector free and allocation helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4A87A0` and before `sub_4A8820`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a87a0` reports size `0x70`, ending at `0x004a8810`; raw bytes at `0x004a8810-0x004a8820` are sixteen `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md).

- `0x004a8889-0x004a8890` - alignment padding between handler-record vector allocator and deallocator.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the paired allocation helper functions.
  - Evidence: 2026-05-27 IDA MCP `py_eval` lists `sub_4A8820` as `0x004a8820-0x004a8889` and `sub_4A8890` as `0x004a8890-0x004a88d2`; raw bytes at `0x004a8889-0x004a8890` are seven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md).

- `0x004a88d2-0x004a88e0` - alignment padding between handler-record vector allocation helpers and `DequePushBack`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4A8890` and before `sub_4A88E0`.
  - Evidence: 2026-05-27 IDA MCP `py_eval` lists `sub_4A8890` as `0x004a8890-0x004a88d2`; raw bytes at `0x004a88d2-0x004a88e0` are fourteen `0xcc` bytes; `lookup_funcs 0x004a88e0` reports `sub_4A88E0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md), [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md).

- `0x004a8966-0x004a8970` - alignment padding between `DequePushBack` and `EventHandlerBase`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4A88E0` and before `sub_4A8970`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a88e0` reports size `0x86`, ending at `0x004a8966`; raw bytes at `0x004a8966-0x004a8970` are ten `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md).

- `0x004a8a84-0x004a8a90` - alignment padding between `EventHandlerBase` and `EventObjects`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `EventHandler::ScalarDeletingDestructor` and before `sub_4A8A90`.
  - Evidence: 2026-05-27 IDA MCP `lookup_funcs 0x004a8a83` reports it belongs to `sub_4A8A60` size `0x24`, ending at `0x004a8a84`; raw bytes at `0x004a8a84-0x004a8a90` are twelve `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md).

- `0x004ab476-0x004ab480` - alignment padding between `EventMan` and `ExceptionHandler`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4AB440` and before `sub_4AB480`.
  - Evidence: 2026-05-27 IDA MCP `py_eval` lists `sub_4AB440` as `0x004ab440-0x004ab476`; raw bytes at `0x004ab476-0x004ab480` are ten `0xcc` bytes; `lookup_funcs 0x004ab480` reports `sub_4AB480`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014C][0x004a8b40-0x004ab476.EventMan](by-memory/0x004a8b40-0x004ab476.EventMan.md), [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md).

- `0x004ac89a-0x004ac8a0` - alignment padding between `ExceptionHandler` and `ExchangeDialog`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `sub_4AC860` and before `sub_4AC8A0`.
  - Evidence: 2026-05-27 IDA MCP `py_eval` lists `sub_4AC860` as `0x004ac860-0x004ac89a`; raw bytes at `0x004ac89a-0x004ac8a0` are six `0xcc` bytes; `lookup_funcs 0x004ac8a0` reports `sub_4AC8A0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md), [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md).

- `0x004ae4b6-0x004ae4c0` - alignment padding between `ExchangeDialog` and `ItemExchangeMixDialogs`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `ExchangeItemListPane::DrawItemEntry` and before `sub_4AE4C0`.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004ae4b5` reports it belongs to `sub_4AE1C0` size `0x2f6`, ending at `0x004ae4b6`; raw bytes at `0x004ae4b6-0x004ae4c0` are ten `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014K][0x004ac8a0-0x004ae4b6.ExchangeDialog](by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md), [UID:00014T][0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs](by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md).

- `0x004aec77-0x004aec80` and `0x004aec8e-0x004aec90` - alignment padding around `MyItemListPane::GetSelectedSlotIndex`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around the real helper at `0x004aec80-0x004aec8e`; these bytes are not source-authored item-picker logic.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs` reports `0x004aeb30` size `0x147`, `0x004aec80` size `0x0e`, and `0x004aec90` size `0x3a1`; `get_u32` at `0x004aec77`, `0x004aec78`, and `0x004aec7c` returns `0xcccccccc`, and the dword at `0x004aec8e` starts with two `0xcc` bytes before the draw method prologue.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md), [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md), [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md), [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md).

- `0x004b0ba5-0x004b0bb0` - alignment padding between `ExchangeDialogTail` and `FieldMapPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `ExchangeMoneyEditControlPane::IsEditable` and before `sub_4B0BB0`.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b0ba4` reports it belongs to `sub_4B0BA0` size `0x5`, ending at `0x004b0ba5`; raw bytes at `0x004b0ba5-0x004b0bb0` are eleven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md), [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md).

- `0x004b129b-0x004b12a0`, `0x004b1334-0x004b1340`, and `0x004b13ce-0x004b13d0` - alignment padding around virtual readable string helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `FieldMapPane`, between the helper pair, and before `PoolAllocatorCore`.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b129a` reports FieldMap's `sub_4B1260` ends at `0x004b129b`; `lookup_funcs` reports `sub_4B12A0` as `0x004b12a0-0x004b1334` and `sub_4B1340` as `0x004b1340-0x004b13ce`; raw bytes show the intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00014Z][0x004b0bb0-0x004b129b.FieldMapPane](by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md), [UID:00022C][0x004b12a0-0x004b13ce.VirtualReadableStringHelpers](by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md), [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md).

- `0x004b1585-0x004b1590` - alignment padding between `PoolAllocatorCore` and `FolderSelectDialog`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `PoolAllocator::~PoolAllocator` and before `sub_4B1590`.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b1584` reports it belongs to `sub_4B1520` size `0x65`, ending at `0x004b1585`; raw bytes at `0x004b1585-0x004b1590` are eleven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000152][0x004b13d0-0x004b1585.PoolAllocatorCore](by-memory/0x004b13d0-0x004b1585.PoolAllocatorCore.md), [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md).

- `0x004b1b87-0x004b1b90` - alignment padding between `FolderSelectDialog` and `FolderTreePaneCore`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `FolderSelectDialog` scalar deleting destructor and before `sub_4B1B90`.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b1b87` reports "Not a function"; raw bytes at `0x004b1b87-0x004b1b90` are nine `0xcc` bytes; `lookup_funcs 0x004b1b90` reports `sub_4B1B90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000154][0x004b1590-0x004b1b87.FolderSelectDialog](by-memory/0x004b1590-0x004b1b87.FolderSelectDialog.md), [UID:000155][0x004b1b90-0x004b32c9.FolderTreePaneCore](by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md).

- `0x004b32c9-0x004b32d0` and `0x004b3344-0x004b3350` - alignment padding around `PatchPane2DownloadPathJoinHelper`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `FolderTreePane::SetSelection` and after the download-path join helper.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs` reports `sub_4B3210` ends at `0x004b32c9`, `sub_4B32D0` spans `0x004b32d0-0x004b3344`, and `sub_4B3350` begins at `0x004b3350`; raw bytes show both intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000156][0x004b3210-0x004b32c9.FolderTreePaneSetSelection](by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md), [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md), [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md).

- `0x004b564d-0x004b5650`, `0x004b5bae-0x004b5bb0`, `0x004b5c13-0x004b5c20`, `0x004b5c3f-0x004b5c40`, `0x004b5cbc-0x004b5cc0`, `0x004b5ce5-0x004b5cf0`, `0x004b5d14-0x004b5d20`, `0x004b5ddf-0x004b5de0`, `0x004b5e75-0x004b5e80`, `0x004b5ebc-0x004b5ec0`, and `0x004b5efc-0x004b5f00` - alignment padding around and inside `FolderTreePane` tree/vector helper ranges.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent helper functions.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs` reports the newly split tree helpers ending at `0x004b564d`, `0x004b5bae`, `0x004b5c13`, and `0x004b5c3f`, with next helper starts at `0x004b5650`, `0x004b5bb0`, `0x004b5c20`, and `0x004b5c40`. 2026-05-28 IDA MCP `lookup_funcs` and raw-byte scan identify real vector helper functions at `0x004b5c40-0x004b5cbc`, `0x004b5cc0-0x004b5ce5`, `0x004b5cf0-0x004b5d14`, `0x004b5d20-0x004b5ddf`, `0x004b5de0-0x004b5e75`, `0x004b5e80-0x004b5ebc`, and `0x004b5ec0-0x004b5efc`; all listed gaps are `0xcc` alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md), [UID:00022E][0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers](by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md), [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md).

- `0x004b6409-0x004b6410` - alignment padding between `FontImageLib` and `FpsPaneDiagnostics`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment byte after the final `FontImageLib` scalar-deleting destructor byte and before FpsPane constructor code.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b6408` reports it belongs to `sub_4B6350` with exclusive end `0x004b6409`; raw bytes at `0x004b6409-0x004b6410` are seven `0xcc` bytes before the FpsPane constructor prologue.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md), [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md).

- `0x004b6caf-0x004b6cb0` - alignment padding between `FpsPane` and `FrameScheduler`.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte after `FpsPane` scalar-deleting destructor and before the next function.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b6cae` reports it belongs to `sub_4B6C50` ending at `0x004b6caf`; `lookup_funcs 0x004b6cb0` reports the next function start; raw byte at `0x004b6caf` is `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md), [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md).

- `0x004b7112-0x004b7120` and `0x004b731f-0x004b7320` - alignment padding around `BuildFramePartPanes`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `FrameMgr::ScalarDeletingDestructor` and after the frame-part factory helper.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004b7111` reports it belongs to `sub_4B70C0` ending at `0x004b7112`; `lookup_funcs 0x004b7120` reports `sub_4B7120` as `0x004b7120-0x004b731f`; raw bytes show the listed intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md), [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md), [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md).

- `0x004b73a3-0x004b73b0` - alignment padding between `FramePartPaneSlotCleanup` and `FramePartPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the raw cleanup body's final `ret` and before `FramePartPane::OnNotification`.
  - Evidence: 2026-05-28 IDA MCP raw-byte review shows `c3` at `0x004b73a2`, followed by `0xcc` bytes through `0x004b73af`; `lookup_funcs 0x004b73b0` reports `sub_4B73B0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015N][0x004b7320-0x004b73a3.FramePartPaneSlotCleanup](by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md), [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md).

- `0x004b7661-0x004b7670`, `0x004b7685-0x004b7690`, `0x004b76c8-0x004b76d0`, `0x004b76f8-0x004b7700`, `0x004b7774-0x004b7780`, `0x004b7828-0x004b7830`, and `0x004b78c8-0x004b78d0` - alignment padding around and inside `RectBoundsPredicateAndCombinationMethods`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the corrected `FramePartPane` end, RectBounds predicate/combination helper bodies, and the next RectBounds method page.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs` and raw-byte review identify code at `0x004b7670-0x004b7685`, `0x004b7690-0x004b76c8`, `0x004b76d0-0x004b76f8`, `0x004b7700-0x004b7774`, `0x004b7780-0x004b7828`, and `0x004b7830-0x004b78c8`; all listed intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015O][0x004b73b0-0x004b7661.FramePartPane](by-memory/0x004b73b0-0x004b7661.FramePartPane.md), [UID:00022G][0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods](by-memory/0x004b7670-0x004b78c8.RectBoundsPredicateAndCombinationMethods.md), [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md).

- `0x004b7ae8-0x004b7af0`, `0x004b7b86-0x004b7b90`, and `0x004b7c1f-0x004b7c30` - alignment padding around `RectBoundsQuarterScaleHelpers`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes before, between, and after the raw quarter-scale rectangle helpers.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs` reports no modeled function starts in the span, while raw disassembly shows prologue/epilogue-bounded code at `0x004b7af0-0x004b7b86` and `0x004b7b90-0x004b7c1f`; the listed intervening spans are alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015Q][0x004b78d0-0x004b7ae8.RectBoundsMethods](by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md), [UID:00022H][0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers](by-memory/0x004b7af0-0x004b7c1f.RectBoundsQuarterScaleHelpers.md), [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md).

- `0x004b7f87-0x004b7f90`, `0x004b8005-0x004b8010`, `0x004b8198-0x004b81a0`, `0x004b81eb-0x004b81f0`, `0x004b821e-0x004b8220`, `0x004b8284-0x004b8290`, and `0x004b83c5-0x004b83d0` - alignment padding around mixed geometry/hash/file helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the adjacent helper bodies from `RectGeometryHelpers` through `GeneralPurposePanel`.
  - Evidence: 2026-05-28 IDA MCP lookup/disassembly identifies code at `0x004b7f90-0x004b8198`, `0x004b81a0-0x004b81eb`, `0x004b81f0-0x004b821e`, `0x004b8220-0x004b8284`, and `0x004b8290-0x004b83c5`; listed spans between them are alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md), [UID:00022I][0x004b7f90-0x004b8198.RectAnchorTransformHelpers](by-memory/0x004b7f90-0x004b8198.RectAnchorTransformHelpers.md), [UID:00022J][0x004b81a0-0x004b81eb.WideStringHashHelper](by-memory/0x004b81a0-0x004b81eb.WideStringHashHelper.md), [UID:00022K][0x004b81f0-0x004b821e.FileExists](by-memory/0x004b81f0-0x004b821e.FileExists.md), [UID:00015U][0x004b8220-0x004b8284.BuildFieldMapPath](by-memory/0x004b8220-0x004b8284.BuildFieldMapPath.md), [UID:00022L][0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper](by-memory/0x004b8290-0x004b83c5.RectAnchorAxisAdjustHelper.md), [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md).

- `0x004b8bd3-0x004b8be0` and `0x004b8be8-0x004b8bf0` - alignment padding around `GrafPortDirtyFlagSetter`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `GeneralPurposePanel` scalar deleting destructor and after the tiny GrafPort dirty/state flag setter.
  - Evidence: 2026-05-28 IDA MCP disassembly shows `sub_4B8B40` ends with `retn 4` bytes `c2 04 00` at `0x004b8bd0-0x004b8bd2`; `sub_4B8BE0` is `0x004b8be0-0x004b8be8`; `0x004b8be8` disassembles as `align 10h` before `GrafPort::GrafPort` at `0x004b8bf0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md), [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md), [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md).

- `0x004bb8c4-0x004bb8d0` - alignment padding between `GrafPort` and `SoftwareRenderCompatCallbacks`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `GrafPort::ScalarDeletingDestructor` and before the first compatibility software-render callback.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004bb8c3` reports it belongs to `sub_4BB7E0` ending at `0x004bb8c4`; `lookup_funcs 0x004bb8c4` reports "Not a function"; disassembly at `0x004bb8c4` is `align 10h`; `lookup_funcs 0x004bb8d0` reports `sub_4BB8D0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md), [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md).

- `0x004c069e-0x004c06a0`, `0x004c06a0-0x004c0704`, and `0x004c0704-0x004c0710` - final `SoftwareRenderCompatCallbacks` switch-data tail and alignment.
  - Why ignored: the middle span is compiler-generated jump-table data for a switch inside `sub_4BEE40`; the surrounding spans are confirmed alignment bytes. None is standalone handwritten source.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004c069d` reports it belongs to `sub_4BEE40`; `lookup_funcs 0x004c069e`, `0x004c06a0`, and `0x004c0700` report no function; disassembly shows `align 10h` at `0x004c069e`, `dd offset loc_4BFC4A; jump table for switch statement` at `0x004c06a0`, `align 10h` at `0x004c0704`, and `BlendRgb555` starts at `0x004c0710`.
  - Replacement/procurement: no standalone source replacement; source reconstruction should express the original switch in the final `sub_4BEE40` callback and let the compiler regenerate equivalent jump-table data.
  - Owner docs: [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md), [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md).

- `0x004c076d-0x004c0770` - alignment padding between `BlendRgb555` and `SoftwareRenderRgb565Callbacks`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the single-pixel RGB555 blend helper and before the first RGB565 software-render callback.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004c076c` reports it belongs to `sub_4C0710`; `lookup_funcs 0x004c076d` reports "Not a function"; disassembly at `0x004c076d` is `align 10h`; `lookup_funcs 0x004c0770` reports `sub_4C0770`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md), [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md).

- `0x004c5fde-0x004c5fe0`, `0x004c5fe0-0x004c6044`, and `0x004c6044-0x004c6050` - final `SoftwareRenderRgb565Callbacks` switch-data tail and alignment.
  - Why ignored: the middle span is compiler-generated jump-table data for a switch inside `sub_4C4790`; the surrounding spans are confirmed alignment bytes. None is standalone handwritten source.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004c5fdd` reports it belongs to `sub_4C4790`; `lookup_funcs 0x004c5fde`, `0x004c5fe0`, and `0x004c6040` report no function; disassembly shows `align 10h` at `0x004c5fde`, `dd offset loc_4C558A; jump table for switch statement` at `0x004c5fe0`, `align 10h` at `0x004c6044`, and `BlendRgb565Pixel` starts at `0x004c6050`.
  - Replacement/procurement: no standalone source replacement; source reconstruction should express the original switch in the final `sub_4C4790` callback and let the compiler regenerate equivalent jump-table data.
  - Owner docs: [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md), [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md).

- `0x004c60c7-0x004c60d0` and `0x004c6151-0x004c6160` - alignment padding around `BlendRgb565Pair`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent RGB565 blend helpers and before the `CachedHashTable` lifecycle island.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs` reports `sub_4C6050` ends at `0x004c60c7`, `sub_4C60D0` spans `0x004c60d0-0x004c6151`, and `sub_4C6160` begins at `0x004c6160`; disassembly shows `align 10h` at both intervening spans.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md), [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md), [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md).

- `0x004c659c-0x004c65a0` - alignment padding between `CachedHashTableLifecycle` and `HelpPaneCore`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `CachedHashTable::ScalarDeletingDestructor` end and before `HelpPane__SimpleHelpTextPartPane` constructor.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004c659b` reports it belongs to `sub_4C64F0`; disassembly shows the final `retn 4` bytes end at `0x004c659c`, and `lookup_funcs 0x004c65a0` reports `sub_4C65A0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00016O][0x004c6160-0x004c659c.CachedHashTableLifecycle](by-memory/0x004c6160-0x004c659c.CachedHashTableLifecycle.md), [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md).

- `0x004c6ea9-0x004c6eb0` and `0x004c6f89-0x004c6f90` - alignment padding around `HelpPaneFadeStateUpdate`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after `HelpPane::OnPaintFrame` and after the raw fade/state update helper.
  - Evidence: 2026-05-28 IDA MCP `lookup_funcs 0x004c6ea8` reports it belongs to `sub_4C6E50`; `lookup_funcs 0x004c6ea9` and `0x004c6eb0` report no function object; raw disassembly shows a complete helper body at `0x004c6eb0-0x004c6f89`, followed by `align 10h` at `0x004c6f89`; `lookup_funcs 0x004c6f90` reports `sub_4C6F90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00016R][0x004c65a0-0x004c6ea9.HelpPaneCore](by-memory/0x004c65a0-0x004c6ea9.HelpPaneCore.md), [UID:00022N][0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate](by-memory/0x004c6eb0-0x004c6f89.HelpPaneFadeStateUpdate.md), [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md).

- `0x004c7808-0x004c7810`, `0x004c7845-0x004c7850`, and `0x004c78db-0x004c78e0` - alignment padding around `SimpleHelpPane2FactoryHelpers`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between raw `SimpleHelpPane2` factory helper bodies and before `WillBeChangedPreviewPanes`.
  - Evidence: 2026-05-28 IDA MCP raw disassembly shows complete helper bodies at `0x004c77e0-0x004c7808`, `0x004c7810-0x004c7845`, and `0x004c7850-0x004c78db`; the listed intervening spans are all `0xcc` bytes and `0x004c78e0` begins `WillBeChangedItemPane` code.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md).

- `0x004c82cf-0x004c82d0` - alignment padding between `WillBeChangedPreviewPanes` and `ItemHelpPaneCore`.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte after `WillBeChangedSpellPane::HandleKeyInput` and before `ItemHelpPane` constructor code.
  - Evidence: 2026-05-28 IDA MCP raw disassembly shows `sub_4C8290` ending with `retn 4` bytes at `0x004c82cc-0x004c82ce`, `0xcc` alignment at `0x004c82cf`, and `ItemHelpPane` code beginning at `0x004c82d0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment byte.
  - Owner docs: [UID:00016U][0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes](by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md), [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md).

- `0x004ce1ab-0x004ce1b0`, `0x004ce30d-0x004ce310`, `0x004ce31b-0x004ce320`, `0x004ce32b-0x004ce330`, and `0x004ce33b-0x004ce340` - alignment padding inside `HelpTooltipSupportHelpers`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between STL-style helper functions and tiny singleton-clear cleanup helpers.
  - Evidence: 2026-05-28 IDA MCP raw disassembly shows modeled helper functions at `0x004ce160-0x004ce1ab`, `0x004ce1b0-0x004ce30d`, `0x004ce310-0x004ce31b`, `0x004ce320-0x004ce32b`, `0x004ce330-0x004ce33b`, and `0x004ce340-0x004ce34b`; the listed spans between them are all `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md).

- `0x00514e5b-0x00514e60`, `0x00514e98-0x00514ea0`, `0x00514edd-0x00514ee0`, `0x00514f6b-0x00514f70`, `0x005151a9-0x005151b0`, and `0x005151ef-0x005151f0` - alignment padding around the MapRefreshDimmer/SystemMessage/LivingObjectPane/nation-entry/string utility cluster.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-confirmed functions or helper clusters.
  - Evidence: 2026-05-28 IDA MCP reports `sub_514e20` ending at `0x00514e5b`, `sub_514e60` ending at `0x00514e98`, `sub_514ea0` ending at `0x00514edd`, `sub_514ee0` ending at `0x00514f6b`, `sub_514f70`/`sub_515110` covering the map-path deque support cluster through `0x005151a9`, `sub_5151b0`/`sub_5151d0` covering the default-codepage wrappers through `0x005151ef`, and raw bytes in each listed intervening span are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md), [UID:0001B5][0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md), [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md), [UID:000234][0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize](by-memory/0x00514ee0-0x00514f6b.GameServerNationEntryArrayResize.md), [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md), and [UID:000236][0x005151b0-0x005151ef.DefaultCodepageConversionWrappers](by-memory/0x005151b0-0x005151ef.DefaultCodepageConversionWrappers.md).

- `0x00515f48-0x00515f50`, `0x00515f9c-0x00515fa0`, and `0x00515ff2-0x00516000` - alignment padding around MD5 endian encode/decode helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the modeled MD5 transform, two raw MD5 endian helper bodies, and the following `MemoryMan` constructor.
  - Evidence: 2026-05-28 IDA MCP reports `sub_515840` ending at `0x00515f48`, raw function-shaped bodies at `0x00515f50-0x00515f9c` and `0x00515fa0-0x00515ff2`, and `sub_516000` beginning at `0x00516000`; raw bytes in the intervening spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md), [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md), and [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md).

- `0x0051628e-0x00516290` - alignment padding between `MemoryManScalarDeletingDestructor` and `MenuPaneAndItems`.
  - Why ignored: confirmed two `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_516260` as `0x00516260-0x0051628e`, raw bytes `cc cc` at `0x0051628e-0x00516290`, and `sub_516290` beginning at `0x00516290`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) and [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md).

- Internal `MenuPaneAndItems` alignment spans `0x00516f67-0x00516f70`, `0x00516f74-0x00516f80`, `0x00516f8d-0x00516f90`, `0x00516f94-0x00516fa0`, `0x00516fad-0x00516fb0`, `0x00516fc1-0x00516fd0`, `0x00516fe1-0x00516ff0`, `0x00517089-0x00517090`, `0x005170e9-0x005170f0`, `0x005171a2-0x005171b0`, `0x0051721d-0x00517220`, `0x00517237-0x00517240`, `0x0051724f-0x00517250`, `0x005172d4-0x005172e0`, and `0x0051731e-0x00517320` - alignment padding around `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact menu item helper functions and raw method-shaped bodies.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs`, `disasm`, and `py_eval` byte review split the modeled functions and raw helper bodies; each listed padding span contains only `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md), [UID:0002J3][0x00516f00-0x00516f67.MenuItemConstructor](by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md), [UID:0002J4][0x00516f70-0x00516f74.MenuItemStateFlag0Accessor](by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md), [UID:0002JH][0x00516f80-0x00516f8d.MenuItemSetStateFlag0](by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md), [UID:0002J5][0x00516f90-0x00516f94.MenuItemStateFlag1Accessor](by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md), [UID:0002JI][0x00516fa0-0x00516fad.MenuItemSetStateFlag1](by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md), [UID:0002JJ][0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect](by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md), [UID:0002JK][0x00516fd0-0x00516fe1.MenuItemSetBoundsRect](by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md), [UID:0002J6][0x00516ff0-0x00517070.StringMenuItemConstructor](by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md), [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md), [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md), and [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md).

- `0x005172be-0x005172d4` - `MenuPane` destructor adjustor thunks.
  - Why ignored: IDA models two tiny compiler-generated forwarding thunks at `0x005172be` and `0x005172c9` that call the `MenuPane` scalar deleting destructor at `0x00517320` with adjusted `this` pointers. These are compiler-generated glue, not source-authored method bodies.
  - Evidence: 2026-05-31 IDA MCP `decompile` shows `sub_5172BE(this, a2)` returning `sub_517320(this - 40, a2)` and `sub_5172C9(this, a2)` returning `sub_517320(this - 41, a2)`.
  - Replacement/procurement: no direct source replacement; regenerated by the compiler from inheritance/vtable layout.
  - Owner docs: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md).

- `0x00517441-0x00517450` and `0x00517d23-0x00517d30` - alignment padding around `MenuDialogFactoryHelpers`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented code ranges.
  - Evidence: 2026-05-28 IDA MCP reports `sub_517400` ending at `0x00517441`, `sub_517450` beginning at `0x00517450`, raw helper code ending at `0x00517d23`, and raw `MerchantDialogPane` constructor-shaped code beginning at `0x00517d30`; raw bytes in the two listed boundary spans are all `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes. Internal switch-table bytes and wrapper alignment inside the factory cluster are documented in the owner page rather than as standalone source items.
  - Owner docs: [UID:0001BK][0x00516290-0x00517441.MenuPaneAndItems](by-memory/0x00516290-0x00517441.MenuPaneAndItems.md), [UID:000238][0x00517450-0x00517d23.MenuDialogFactoryHelpers](by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md), and [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md).

- `0x00517ebf-0x00517ec0` - alignment padding between `MerchantDialogPaneActionStringVirtual` and `TextMenuDialogs`.
  - Why ignored: confirmed single `0xcc` compiler/linker alignment byte between adjacent IDA-modeled functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_517d80` ending at `0x00517ebf`, raw byte `cc` at `0x00517ebf`, and `sub_517ec0` beginning at `0x00517ec0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) and [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md).

- `0x0051a417-0x0051a420` and `0x0051a51c-0x0051a520` - alignment padding around `TextInputMenuDialogReplyPacketHelper`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around a raw `TextInputMenuDialog` reply-packet helper.
  - Evidence: 2026-05-28 IDA MCP reports modeled `sub_51a3e0` ending at `0x0051a417`, raw helper body `0x0051a420-0x0051a51c`, modeled `sub_51a520` beginning at `0x0051a520`, and `0xcc` bytes in the two listed boundary spans.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md), [UID:000239][0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper](by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md), and [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md).

- `0x0051c46d-0x0051c470`, `0x0051ca3c-0x0051ca40`, `0x0051e998-0x0051e9a0`, and `0x0051fc8d-0x0051fc90` - menu-dialog family alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between adjacent item, spell, argumented-menu, and argumented-input dialog ranges.
  - Evidence: 2026-05-28 IDA MCP reports `sub_51c430` ending at `0x0051c46d`, `sub_51c470` beginning at `0x0051c470`, `sub_51f840` ending at `0x0051fc8d`, and `sub_51fc90` beginning at `0x0051fc90`; all listed spans are `0xcc` alignment except the corrected `sub_51e890` endpoint, where `0x0051e997` is the final `retn 0Ch` operand byte and padding starts at `0x0051e998`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BO][0x0051a520-0x0051c46d.ItemMenuDialogs](by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md), [UID:0001BQ][0x0051c470-0x0051ca3c.ClientItemMenuItemList](by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md), [UID:0001BR][0x0051ca40-0x0051e998.SpellMenuDialogs](by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md), [UID:0001BS][0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs](by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md), and [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md).

- `0x00520539-0x00520540` and `0x00520816-0x00520820` - alignment padding around `ObjectImageControlPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around the object-image display control.
  - Evidence: 2026-05-28 IDA MCP reports `sub_5203c0` ending at `0x00520539`, `sub_520540` beginning at `0x00520540`, `sub_5205c0` ending at `0x00520816`, and `sub_520820` beginning at `0x00520820`; raw bytes in the listed boundary spans are `0xcc` except `0x00520815`, which is the `retn` byte included in the corrected `ObjectImageControlPane` endpoint.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BT][0x0051fc90-0x00520539.ArgumentedItemInputDialogs](by-memory/0x0051fc90-0x00520539.ArgumentedItemInputDialogs.md), [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md), and [UID:0001BV][0x00520820-0x00520c9a.ObjectImageButtonPane](by-memory/0x00520820-0x00520c9a.ObjectImageButtonPane.md).

- `0x00520e2b-0x00520e30` - alignment padding between menu-dialog destructor thunks and `MessageAndMessageShowPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_520df0` ending at `0x00520e2b`, raw bytes `cc cc cc cc cc` at `0x00520e2b-0x00520e30`, and message dialog code beginning at `0x00520e30`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001BX][0x00520abb-0x00520e2b.MenuDialogDestructorThunks](by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md) and [UID:0001C3][0x00520e30-0x005227c6.MessageAndMessageShowPane](by-memory/0x00520e30-0x005227c6.MessageAndMessageShowPane.md).

- `0x005227c6-0x005227d0` - alignment padding between `MessageShowPane` destructor and `MetaMan`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_522720` ending at `0x005227c6`, raw bytes in `0x005227c6-0x005227d0` are all `0xcc`, and `sub_5227d0` begins at `0x005227d0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001C7][0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor](by-memory/0x00522720-0x005227c6.MessageShowPaneScalarDeletingDestructor.md) and [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md).

- `0x00524581-0x00524590`, `0x005245b1-0x005245c0`, and `0x0052462a-0x00524630` - metadata subsystem alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes around metadata tree helper functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_524590` as `0x00524590-0x005245b1`, `sub_5245c0` as `0x005245c0-0x0052462a`, and `sub_524630` beginning at `0x00524630`; raw bytes in the listed boundary spans are all `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001C8][0x005227d0-0x00524581.MetaMan](by-memory/0x005227d0-0x00524581.MetaMan.md), [UID:00023A][0x00524590-0x005245b1.MetaManNodeDestroyHelper](by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md), [UID:0001CA][0x005245c0-0x0052462a.MetaTableRowFindByKey](by-memory/0x005245c0-0x0052462a.MetaTableRowFindByKey.md), and [UID:0001CB][0x00524630-0x005258f1.MetaTable](by-memory/0x00524630-0x005258f1.MetaTable.md).

- `0x00525914-0x00525920` - alignment padding between `MetaTableRowTreeHelpers` and MIDI stream setup.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `sub_525900` endpoint.
  - Evidence: 2026-05-28 IDA MCP reports `sub_525900` as `0x00525900-0x00525914`, with `0x00525913` being the final operand byte of `retn 4`, and `sub_525920` beginning at `0x00525920`; bytes `0x00525914-0x00525920` are `0xcc` alignment.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001CD][0x00524d10-0x00525914.MetaTableRowTreeHelpers](by-memory/0x00524d10-0x00525914.MetaTableRowTreeHelpers.md) and [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md).

- `0x00525b0d-0x00525b10` - alignment padding between MIDI stream setup and `MidiPlayer` helpers.
  - Why ignored: confirmed three `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions.
  - Evidence: 2026-05-28 IDA MCP reports `sub_525920` ending at `0x00525b0d`, raw bytes `cc cc cc` at `0x00525b0d-0x00525b10`, and `sub_525b10` beginning at `0x00525b10`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md) and [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md).

- `0x0052664b-0x00526650` and `0x005270d5-0x005270e0` - boundary alignment padding around MIDI file reader/parser helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent MIDI helper ranges.
  - Evidence: 2026-05-28 IDA MCP reports `sub_526580` ending at `0x0052664b`, `sub_526650` beginning at `0x00526650`, parser-wrapper helper `sub_5270c0` ending at `0x005270d5`, and MIDI document release `sub_5270e0` beginning at `0x005270e0`. Raw bytes in both boundary spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes. Internal padding inside the helper island is documented on the owner page rather than as standalone coverage rows.
  - Owner docs: [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md), [UID:00023B][0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers](by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md), and [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md).

- `0x005271a3-0x005271b0` and `0x005277bb-0x005277c0` - boundary alignment padding around MIDI SMF load and stream-fill helpers.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent MIDI and worker-thread ranges.
  - Evidence: 2026-05-28 IDA MCP reports `sub_5270e0` ending at `0x005271a3`, `sub_5271b0` beginning at `0x005271b0`, `sub_5273a0` ending at `0x005277bb`, and `sub_5277c0` beginning at `0x005277c0`. Raw bytes in both boundary spans are `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001CI][0x005270e0-0x005271a3.MidiDocumentRelease](by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md), [UID:00023C][0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers](by-memory/0x005271b0-0x005277bb.MidiSMFLoadAndStreamFillHelpers.md), and [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md).

- `0x005285dd-0x005285e0`, `0x00528929-0x00528930`, `0x00528d51-0x00528d60`, `0x00528e55-0x00528e60`, and `0x0052a535-0x0052a540` - UI/thread/helper alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions or helper islands.
  - Evidence: 2026-05-28 IDA MCP reports `sub_528560` ending at `0x005285dd`, `sub_5288f0` ending at `0x00528929`, `nullsub_13` ending at `0x00528d51`, `sub_528df0` ending at `0x00528e55`, and `sub_52a4e0` ending at `0x0052a535`; the following bytes in each listed span are `0xcc` until the next documented function start.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md), [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md), [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md), [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md), [UID:0001CP][0x00528e60-0x0052a535.MusicControlDialog](by-memory/0x00528e60-0x0052a535.MusicControlDialog.md), and [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md).

- `0x0052f94c-0x0052f950`, `0x00530636-0x00530640`, `0x00530cf7-0x00530d00`, and `0x00530ed9-0x00530ee0` - login/dialog/ObjectList alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions or helper islands.
  - Evidence: 2026-05-28 IDA MCP reports `sub_52f8e0` ending at `0x0052f94c`, `sub_530580` ending at `0x00530636`, `sub_530c90` ending at `0x00530cf7`, `sub_530d00` spanning `0x00530d00-0x00530ed9`, and `sub_530ee0` beginning at `0x00530ee0`; the listed gaps are alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md), [UID:0001CT][0x0052f950-0x00530636.NexonclubRegistrationDialog](by-memory/0x0052f950-0x00530636.NexonclubRegistrationDialog.md), [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md), [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md), and [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md).

- `0x0053125d-0x00531260` and `0x00531473-0x00531480` - ObjectList lifecycle alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact ObjectList lifecycle functions and the next ObjectList helper cluster.
  - Evidence: 2026-05-31 IDA MCP reports `sub_530EE0` ending at `0x0053125d`, `sub_531260` beginning at `0x00531260`, and bytes `0x0053125d-0x00531260` as `cc cc cc`; 2026-05-28 IDA MCP reports `sub_531260` ending at `0x00531473`, `sub_531480` beginning at `0x00531480`, and the bytes between them as `0xcc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md), [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md), [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md), and [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md).

- `0x00532f67-0x00532f70` and `0x0053728e-0x00537290` - ObjectList extended lookup alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes around the extended ObjectList type lookup helper family.
  - Evidence: 2026-05-28 IDA MCP byte/disassembly review shows `0x00532f67-0x00532f70` as `0xcc` bytes before the IDA-missed helper start at `0x00532f70`; `0x0053728e-0x00537290` is alignment before `ObjectList::ScalarDeletingDestructor` at `0x00537290`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md), [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md), and [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md).

- `0x005372c8-0x005372d0`, `0x005378fa-0x00537900`, `0x00537abf-0x00537ac0`, `0x00537b39-0x00537b40`, `0x005380af-0x005380b0`, `0x005387a3-0x005387b0`, `0x0053887c-0x00538880`, `0x0053889f-0x005388a0`, `0x005388b4-0x005388c0`, `0x00538baa-0x00538bb0`, `0x00538bb7-0x00538bc0`, `0x00539bb2-0x00539bc0`, `0x0053a10c-0x0053a110`, and `0x0053d589-0x0053d590` - object-pane/Motion family alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between adjacent object-pane family functions and helper islands.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports the outer spans as `0xcc` alignment after correcting IDA exclusive ends for `ObjectList::ScalarDeletingDestructor` (`0x005372c8`) and `EffectObjectPane::RenderEffect` (`0x00538baa`). The same pass identifies real missed code at [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md) and [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md). A 2026-06-01 IDA MCP recheck identifies the internal EffectObjectPane gaps `0x0053887c-0x00538880`, `0x0053889f-0x005388a0`, and `0x005388b4-0x005388c0` as `0xcc` alignment between modeled child functions. The same MotionAnimation pass identifies `0x0053a10c-0x0053a110` as `0xcc` alignment after the corrected Motion timer endpoint and `0x0053d589-0x0053d590` as `0xcc` alignment before the Motion scalar deleting destructor.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001D4][0x00537290-0x005372c8.ObjectListScalarDeletingDestructor](by-memory/0x00537290-0x005372c8.ObjectListScalarDeletingDestructor.md), [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md), [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md), [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md), [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md), [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md), [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md), and [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md).

- `0x0053d818-0x0053d820`, `0x0053e3c1-0x0053e3d0`, `0x0053f2b6-0x0053f2c0`, `0x0053f939-0x0053f940`, `0x0053fe87-0x0053fe90`, `0x0053fe9b-0x0053fea0`, and `0x0053ff8d-0x0053ff90` - option/macro/social/profile/scroll alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between adjacent UI dialog/helper ranges after correcting several one-byte exclusive-end mistakes.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports `sub_53D810` ending at `0x0053d818`, `sub_53E380` ending at `0x0053e3c1`, `sub_53F210` ending at `0x0053f2b6`, `sub_53F930` ending at `0x0053f939`, `sub_53FDC0` ending at `0x0053fe87`, `sub_53FE90` ending at `0x0053fe9b`, and `sub_53FF00` ending at `0x0053ff8d`; the bytes after those ends in the listed spans are `0xcc` alignment.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001DE][0x0053a110-0x0053d818.LivingObjectPaneCore](by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md), [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md), [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md), [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md), [UID:0001DR][0x0053e520-0x0053f2b6.MacroDialogs](by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md), [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md), [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md), [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md), [UID:0001DV][0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore](by-memory/0x0053fea0-0x0053ff8d.CScrollBarBackPaneCore.md), and [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md).

- `0x00541b2b-0x00541b30`, `0x00542265-0x00542270`, `0x00542534-0x00542540`, `0x0054267b-0x00542680`, `0x005426d5-0x005426e0`, and `0x00542ab5-0x00542ac0` - option/macro/target/dialog-destructor alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between adjacent IDA-confirmed functions, raw helper code, thunk island, and destructor island.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports `sub_541a90` ending at `0x00541b2b`, `sub_5421f0` ending at `0x00542265`, `sub_5424b0` ending at `0x00542534`, target-option config-save helper `0x00542540-0x0054259f`, adjustor thunk island `0x0054259f-0x0054267b`, `sub_542680` ending at `0x005426d5`, scalar deleting destructor island `0x005426e0-0x00542ab5`, and `DLPalette` beginning at `0x00542ac0`; all listed boundary spans are `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001DW][0x0053ff90-0x00541b2b.NewOptionPane](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md), [UID:0001E1][0x00541b30-0x00542265.IntegrateMacroDialog](by-memory/0x00541b30-0x00542265.IntegrateMacroDialog.md), [UID:0001E2][0x00542270-0x0054259f.TargetOptionDialog](by-memory/0x00542270-0x0054259f.TargetOptionDialog.md), [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md), [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md), and [UID:0001E4][0x00542ac0-0x00544411.DLPalette](by-memory/0x00542ac0-0x00544411.DLPalette.md).

- `0x0054259f-0x0054267b` - dialog/option-pane this-adjustor thunk island.
  - Why ignored: compiler/linker-generated this-adjustor thunks forward to adjacent scalar deleting destructor wrappers; the source should reconstruct class inheritance/destructors, not these thunk bodies.
  - Evidence: 2026-05-28 IDA MCP review shows pairs of compact adjustor jumps targeting `0x00542680`, `0x005426e0`, `0x00542740`, `0x005427a0`, `0x00542800`, `0x00542860`, `0x00542940`, `0x005429a0`, `0x00542a00`, and `0x00542a60`, with vtable/data references rather than handwritten source callers.
  - Replacement/procurement: generated by the C++ compiler from class layout/destructor declarations.
  - Owner docs: [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md), [UID:0001E3][0x00542680-0x005426d5.CScrollBarBackPaneDestructor](by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md), and [UID:00023K][0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland](by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md).

- `0x00543665-0x00543670`, `0x005436f4-0x00543700`, `0x00544411-0x00544420`, `0x0054445b-0x00544460`, `0x00545086-0x00545090`, `0x00545165-0x00545170`, `0x00545e3b-0x00545e40`, `0x00546b74-0x00546b80`, `0x00546bb5-0x00546bc0`, `0x00546d64-0x00546d70`, `0x005470ad-0x005470b0`, `0x0054940f-0x00549410`, `0x00549616-0x00549620`, `0x00549911-0x00549920`, `0x005499b8-0x005499c0`, `0x00549a22-0x00549a30`, `0x00549ad6-0x00549ae0`, `0x00549aff-0x00549b00`, `0x00549b22-0x00549b30`, `0x00549b63-0x00549b70`, `0x00549bc5-0x00549bd0`, `0x00549bf1-0x00549c00`, `0x00549c18-0x00549c20`, `0x0054b5d5-0x0054b5e0`, `0x0054bcbd-0x0054bcc0`, and `0x0054bcec-0x0054bcf0` - palette/pane/photo/pool/button boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled functions, raw helper bodies, and class clusters after correcting several one-byte exclusive-end mistakes.
    - Evidence: 2026-05-28 IDA MCP byte/function review shows the prior UNKNOWN spans are alignment, except for the newly split [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md). The same pass confirms function endpoints at `0x0054445b`, `0x00545086`, `0x00545165`, `0x00545e3b`, `0x005470ad`, `0x0054940f`, `0x00549616`, `0x00549bc5`, `0x00549bf1`, `0x00549c18`, `0x0054b5d5`, `0x0054bcbd`, and `0x0054bcec`. 2026-06-01 IDA MCP byte/function review adds `0x00543665-0x00543670`, `0x005436f4-0x00543700`, `0x00543f55-0x00543f60`, `0x00543f77-0x00543f80`, `0x00546b74-0x00546b80`, `0x00546bb5-0x00546bc0`, `0x00546d64-0x00546d70`, `0x00544411-0x00544420`, and PhotoPane/PictureViewPane internal alignment spans `0x00549911-0x00549920`, `0x005499b8-0x005499c0`, `0x00549a22-0x00549a30`, `0x00549ad6-0x00549ae0`, `0x00549aff-0x00549b00`, `0x00549b22-0x00549b30`, and `0x00549b63-0x00549b70` after correcting palette and FlyingParcelPane helper boundaries, splitting raw helper bodies, correcting `DLPalette::ScalarDeletingDestructor`, and documenting [UID:0002R8][0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw](by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001E4][0x00542ac0-0x00544411.DLPalette](by-memory/0x00542ac0-0x00544411.DLPalette.md), [UID:0001E6][0x005431c0-0x0054445b.PaletteLib](by-memory/0x005431c0-0x0054445b.PaletteLib.md), [UID:0001E7][0x00543450-0x00543665.PaletteListAndEntryMoveHelpers](by-memory/0x00543450-0x00543665.PaletteListAndEntryMoveHelpers.md), [UID:0002R4][0x00543670-0x005436f4.PaletteCollectionColorTransformRaw](by-memory/0x00543670-0x005436f4.PaletteCollectionColorTransformRaw.md), [UID:0001E9][0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers](by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md), [UID:0001EA][0x00544460-0x00545086.PaneCore](by-memory/0x00544460-0x00545086.PaneCore.md), [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md), [UID:0001EE][0x00545170-0x00545e3b.EditablePaperPane](by-memory/0x00545170-0x00545e3b.EditablePaperPane.md), [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md), [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md), [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md), [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md), [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md), [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md), [UID:0001F4][0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper](by-memory/0x00549bd0-0x00549bf1.PoolAllocatorChunkHelper.md), [UID:00023L][0x00549c00-0x00549c18.PoolAllocatorFreeChunkList](by-memory/0x00549c00-0x00549c18.PoolAllocatorFreeChunkList.md), [UID:0001F6][0x00549c20-0x0054b5d5.PowerDialogPane](by-memory/0x00549c20-0x0054b5d5.PowerDialogPane.md), [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md), [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md), and [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md).

- `0x0054a472-0x0054a480`, `0x0054a4a9-0x0054a4b0`, `0x0054a4b6-0x0054a4c0`, `0x0054c062-0x0054c070`, `0x0054c09c-0x0054c0a0`, `0x0054c0bc-0x0054c0c0`, `0x0054c15a-0x0054c160`, `0x0054c1f1-0x0054c200`, `0x0054caa9-0x0054cab0`, `0x0054cae9-0x0054caf0`, `0x0054cc2f-0x0054cc30`, `0x0054ce0f-0x0054ce10`, `0x00551021-0x00551030`, `0x00553609-0x00553610`, and `0x005538fd-0x005538fe` - dialog/container boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent dialog/container helper functions after splitting the previous UNKNOWN rows and correcting several one-byte exclusive-end mistakes.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports the listed ranges as alignment after `PrimeNumberGenerator`, `DequeClear`, [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), `PursuitMessageDialogPane` raw constructor, `MessageDialogObjectResponseVirtual`, [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md), `NpcMessageAndMenuQuestionDialogs`, [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md), and [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md). 2026-06-01 IDA MCP byte/function review adds the PowerDialogPane singleton-helper alignment spans `0x0054a472-0x0054a480`, `0x0054a4a9-0x0054a4b0`, and `0x0054a4b6-0x0054a4c0` around [UID:0001F7][0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers](by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md), and splits PrimeNumberGenerator constructor-to-Dequeue-helper alignment into `0x0054c062-0x0054c070`, `0x0054c09c-0x0054c0a0`, and `0x0054c0bc-0x0054c0c0` around raw cleanup helpers documented under [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001FB][0x0054bcf0-0x0054c15a.PrimeNumberGenerator](by-memory/0x0054bcf0-0x0054c15a.PrimeNumberGenerator.md), [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md), [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), [UID:0001FE][0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor](by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md), [UID:0001FF][0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual](by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md), [UID:0001FG][0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers](by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md), [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md), [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md), [UID:0001FJ][0x00552110-0x00553609.TextDialogCore](by-memory/0x00552110-0x00553609.TextDialogCore.md), and [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md).

- `0x005520e5-0x00552110` - `HeadSelectDialog::OnAction` switch table and boundary padding.
  - Why ignored: compiler-generated switch jump/indirect tables plus final alignment for `HeadSelectDialog::OnAction`; not standalone handwritten source logic.
  - Evidence: 2026-05-28 IDA MCP byte/item review identifies `0x005520e5-0x005520e8` as alignment, `0x005520e8-0x005520fc` as `jpt_551FBD`, `0x005520fc-0x0055210c` as `byte_5520FC`, and `0x0055210c-0x00552110` as final alignment before `TextDialog`.
  - Replacement/procurement: reconstructing the `OnAction` switch in source should regenerate equivalent compiler tables; do not hand-port this as source-authored data.
  - Owner docs: [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md), [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md), and [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md).

- `0x005539c3-0x005539d9` - late shared dialog default destructor adjustor thunks.
  - Why ignored: compiler-generated this-adjustor thunks forward to the shared dialog default scalar deleting destructor; source should reconstruct the dialog class layout/destructor, not hand-port these thunk bodies.
  - Evidence: 2026-05-28 IDA MCP reports real functions at `0x005539c3-0x005539ce` and `0x005539ce-0x005539d9`, with `this - 0xa0` / `this - 0xa4` adjustments and jumps to `0x00520b70`.
  - Replacement/procurement: generated by the C++ compiler from inheritance layout and vtable destructor slots.
  - Owner docs: [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md), [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), and [UID:0001BW][0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks](by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md).

- `0x005539d9-0x005539e0`, `0x00553ab9-0x00553ac0`, `0x00553b05-0x00553b10`, `0x00553b55-0x00553b60`, `0x00553b6a-0x00553b70`, `0x00553c07-0x00553c10`, `0x00553cbf-0x00553cc0`, `0x00553e5b-0x00553e60`, `0x00553f36-0x00553f40`, `0x005544b8-0x005544c0`, `0x00554513-0x00554520`, `0x00554536-0x00554540`, `0x00554635-0x00554640`, `0x0055464b-0x00554650`, `0x00554654-0x00554660`, `0x00554675-0x00554680`, `0x00554b38-0x00554b40`, `0x0055577b-0x00555780`, `0x005557da-0x005557e0`, `0x005558c2-0x005558d0`, `0x0055606d-0x00556070`, `0x00556211-0x00556212`, `0x0055623e-0x00556240`, `0x00556314-0x00556320`, `0x005563cd-0x005563d0`, `0x005568c8-0x005568d0`, `0x005568dc-0x005568e0`, `0x00556907-0x00556910`, `0x00557132-0x00557140`, `0x00559a0f-0x00559a10`, `0x00559aef-0x00559af0`, `0x00559b1d-0x00559b20`, and `0x00559b8b-0x00559b90` - queue/dialog/menu/container/screen/surface boundary alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes between adjacent documented functions, raw helper islands, or corrected one-byte endpoints.
  - Evidence: 2026-05-28 IDA MCP byte/function review split the prior UNKNOWN rows from `0x005539c3-0x00559b90`; real code is now documented in [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md), [UID:00023P][0x00554640-0x00554675.WordRefCountHelpers](by-memory/0x00554640-0x00554675.WordRefCountHelpers.md), [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md), [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), [UID:00023S][0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper](by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md), [UID:00023T][0x00559af0-0x00559b1d.FormatWideTextFixedBuffer](by-memory/0x00559af0-0x00559b1d.FormatWideTextFixedBuffer.md), and [UID:00023U][0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland](by-memory/0x00559b20-0x00559b8b.ScreenPaneDestructorThunkIsland.md). 2026-06-01 IDA MCP byte review adds internal Queue alignment spans `0x00553ab9-0x00553ac0`, `0x00553b05-0x00553b10`, `0x00553b55-0x00553b60`, and `0x00553b6a-0x00553b70`, reconnect-helper alignment spans `0x00553e5b-0x00553e60` and `0x00553f36-0x00553f40`, CopyWindow alignment spans `0x005544b8-0x005544c0`, `0x00554513-0x00554520`, and `0x00554536-0x00554540`, WordRefCount internal alignment spans `0x0055464b-0x00554650` and `0x00554654-0x00554660`, RightButtonMenuPacketHelpers internal alignment span `0x005557da-0x005557e0`, and RuntimeClassCallbackAndMembershipHelpers internal alignment span `0x005568dc-0x005568e0`; the same review corrected the raw write/read helper endpoints, reconnect init helper endpoint, CopyWindow callback endpoint, WordRefCount helper evidence, packet helper evidence, and runtime-class helper evidence.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes. Corrected final instruction bytes are covered by the owning memory pages rather than these padding ranges.
  - Owner docs: [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md), [UID:0001FN][0x005539e0-0x00553c07.Queue](by-memory/0x005539e0-0x00553c07.Queue.md), [UID:0001FT][0x00553c10-0x00554635.ConnectionClosedReconnectDialogs](by-memory/0x00553c10-0x00554635.ConnectionClosedReconnectDialogs.md), [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md), [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md), [UID:0001FY][0x005558d0-0x0055606d.VoteMenuPaneCore](by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md), [UID:0001FZ][0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit](by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md), [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md), [UID:0001G5][0x00556910-0x00557132.ScreenPane](by-memory/0x00556910-0x00557132.ScreenPane.md), [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), and [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md).

- `0x005564d4-0x005564e0`, `0x00556579-0x00556580`, `0x005565ec-0x005565f0`, `0x0055665a-0x00556660`, `0x00556668-0x00556670`, `0x0055667a-0x00556680`, `0x00556688-0x00556690`, `0x00556698-0x005566a0`, `0x005566a8-0x005566b0`, `0x005566ba-0x005566c0`, `0x005566eb-0x005566f0`, `0x005566fa-0x00556700`, `0x00556715-0x00556720`, `0x00556749-0x00556750`, `0x00556767-0x00556770`, `0x0055677d-0x00556780`, `0x00556794-0x005567a0`, `0x005567ae-0x005567b0`, and `0x00556887-0x00556890` - RingBuffer internal helper alignment padding.
  - Why ignored: confirmed compiler/linker `0xcc` alignment bytes between documented RingBuffer and RingBufferIterator helper bodies.
  - Evidence: 2026-06-01 IDA MCP byte/disassembly review of [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md) confirmed modeled function boundaries, raw helper endpoints, and these exact padding spans.
  - Replacement/procurement: no source replacement; these are alignment bytes between helpers.
  - Owner docs: [UID:0001G4][0x005563d0-0x005568c8.RingBuffer](by-memory/0x005563d0-0x005568c8.RingBuffer.md), [UID:0000N8][RingBuffer](by-file/RingBuffer.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), and [UID:0000C2][RingBufferIterator](by-class/RingBufferIterator.md).

- `0x00557377-0x00557380`, `0x005573a1-0x005573b0`, `0x005573e3-0x005573f0`, `0x0055742c-0x00557430`, `0x00557439-0x00557440`, `0x00557449-0x00557450`, `0x00557458-0x00557460`, `0x00557468-0x00557470`, `0x0055769d-0x005576a0`, `0x00557810-0x00557820`, `0x00557828-0x00557830`, `0x00557838-0x00557840`, `0x00557a95-0x00557aa0`, `0x00557e73-0x00557e80`, `0x00558239-0x00558240`, `0x00558391-0x005583a0`, `0x0055867a-0x00558680`, `0x00558688-0x00558690`, `0x0055883d-0x00558840`, `0x00558f63-0x00558f70`, `0x00559075-0x00559080`, `0x005590da-0x005590e0`, `0x00559108-0x00559110`, `0x00559138-0x00559140`, `0x0055914f-0x00559160`, `0x0055916b-0x00559170`, `0x005591fc-0x00559200`, `0x005592a9-0x005592b0`, `0x00559359-0x00559360`, `0x005593a2-0x005593b0`, `0x0055940c-0x00559410`, `0x005595ca-0x005595d0`, and `0x00559a0f-0x00559a10` - SurfacePresentation internal helper alignment padding.
  - Why ignored: confirmed compiler/linker `0xcc` alignment bytes between modeled and raw surface/presentation, screenshot, cursor, and redraw helper bodies.
  - Evidence: 2026-06-01 IDA MCP byte/disassembly review of [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) enumerated exact function/raw-helper endpoints and these padding spans.
  - Replacement/procurement: no source replacement; these are alignment bytes between helpers.
  - Owner docs: [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md), [UID:0000OC][Surface](by-file/Surface.md), [UID:0000NB][ScreenPane](by-file/ScreenPane.md), and [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).

- `0x0055a252-0x0055a260`, `0x0055c1ff-0x0055c200`, `0x0055c643-0x0055c650`, `0x0055d957-0x0055d960`, `0x00565502-0x00565510`, `0x00565608-0x00565610`, `0x0056a373-0x0056a380`, `0x0056ba99-0x0056baa0`, `0x0056bb15-0x0056bb20`, `0x0056c3f1-0x0056c400`, `0x0056c493-0x0056c4a0`, `0x0056c4b5-0x0056c4c0`, `0x0056e939-0x0056e940`, and `0x0056fe75-0x0056fe80` - effecter/scroll/self-look/group/collection boundary alignment padding.
  - Why ignored: confirmed compiler/linker alignment bytes after splitting the former UNKNOWN rows from `0x0055a252-0x0056fe80`.
  - Evidence: 2026-05-28 IDA MCP byte/function review identifies real code now documented in [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), [UID:0001GH][0x0055c200-0x0055c643.ScrollPaneInputCore](by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md), [UID:0001GI][0x0055c650-0x0055d957.ScrollPaneOnDraw](by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md), [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md), [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md), and [UID:00023W][0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs](by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md); the listed gaps are `0xcc` alignment around those bodies.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes. Switch/jump-table data inside `0x0056a380-0x0056ba99` is documented on the owner page because it is generated from source switch logic.
  - Owner docs: [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), [UID:0001GJ][0x0055d960-0x00565488.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md), [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md), [UID:0001H8][0x0056baa0-0x0056bb00.GroupListPaneRawConstructor](by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md), [UID:0001HA][0x0056bb20-0x0056c3f1.SpelledPane](by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md), [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md), [UID:0001HC][0x0056c4c0-0x0056e939.GroupPanes](by-memory/0x0056c4c0-0x0056e939.GroupPanes.md), [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), and [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md).

- `0x00575377-0x00575380`, `0x00575abb-0x00575ac0`, `0x00575b8c-0x00575b90`, `0x00575caa-0x00575cb0`, and `0x00575d83-0x00575d90` - packet helper/transform boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent packet helper and packet-transform functions after splitting the former UNKNOWN rows around `PacketBufferHelpers`, new length-prefixed read helpers, new string-key transform helpers, and `PacketNonceInitialization`.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports the listed spans as `0xcc` alignment. The same pass identifies real code at [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md) and [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md), [UID:000243][0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers](by-memory/0x00575ac0-0x00575b8c.PacketBufferLengthPrefixedReadHelpers.md), [UID:000244][0x00575b90-0x00575caa.PacketTransformStringKeyHelpers](by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md), [UID:0001I0][0x00575cb0-0x00575d83.PacketNonceInitialization](by-memory/0x00575cb0-0x00575d83.PacketNonceInitialization.md), and [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md).

- `0x00578f70-0x005797ae` - STL tree/string-map support helpers.
  - Why ignored: MSVC STL/Dinkumware tree and string-map helper bodies generated from owning C++ container declarations; source reconstruction should model the owning containers instead of porting these helper bodies as handwritten NexusTK code.
  - Evidence: 2026-05-28 IDA MCP disassembly shows fixed 0x14-byte tree node allocation/free, self-linked sentinel/header setup, recursive tree-node destruction, and string construction/destruction helper calls. Direct callers cross multiple owner modules, including CashShopRequest packet-building code and the VirusChecker constructor.
  - Replacement/procurement: generated by the C++ compiler/STL from source-level container usage. Reconstruct the owner structures in [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md), [UID:0000P5][VirusChecker](by-file/VirusChecker.md), and any confirmed EventDispatcher tree owner; do not create a standalone source-authored implementation from this helper island.
  - Owner docs: [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md), [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md), [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), and [UID:0001QA][client_containers](by-meta/client_containers.md).

- `0x005797ae-0x005797b0` - STL tree/string-map support to SoundManager boundary alignment padding.
  - Why ignored: confirmed two `0xcc` compiler/linker alignment bytes after the final STL diagnostic/helper body and before `SoundManager`.
  - Evidence: 2026-05-28 IDA MCP byte/function review shows `sub_579780` ending at `0x005797ae`, raw bytes `cc cc` at `0x005797ae-0x005797b0`, and `sub_5797B0` beginning the SoundManager cluster at `0x005797b0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) and [UID:0001I8][0x005797b0-0x0057bc58.SoundManager](by-memory/0x005797b0-0x0057bc58.SoundManager.md).

- `0x0057bf6e-0x0057bf70`, `0x0057c2cf-0x0057c2d0`, `0x0057f742-0x0057f750`, and `0x005807c5-0x005807d0` - sound/macro/startup boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent SoundPathVector, SoundStatusPane, SpellInventoryPane, MacroEditControlPane, and StartupWindow ranges.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports `sub_57BF40` ending at `0x0057bf6e`, `sub_57C270` ending at `0x0057c2cf`, `sub_57F6A0` ending at `0x0057f742`, and `sub_580770` ending at `0x005807c5`; the listed spans are `0xcc` alignment before the next documented function starts.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001IF][0x0057bf40-0x0057bf6e.SoundPathVectorClear](by-memory/0x0057bf40-0x0057bf6e.SoundPathVectorClear.md), [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md), [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md), [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md), and [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md).

- `0x0058206e-0x00582070`, `0x005824f6-0x00582500`, and `0x00583206-0x00583210` - StartupWindow/File/LOBject string boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent IDA-modeled StartupWindow, `StdioFile`, `LObject`, and `SimpleUString` ranges.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports `sub_581F50` ending at `0x0058206e`, `sub_5824A0` ending at `0x005824f6`, and `sub_5831C0` ending at `0x00583206`; the following bytes in each listed span are `0xcc` until the next documented function start.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md), [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md), [UID:0001J1][0x00582500-0x00583206.LObjectStringConstructionAndCow](by-memory/0x00582500-0x00583206.LObjectStringConstructionAndCow.md), and [UID:0001J2][0x00583210-0x005845eb.SimpleUStringPointerBacked](by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md).

- `0x0060d670-0x0060d798` - MSVC `.rdata` startup tables.
  - Why ignored: compiler/linker-generated CFG, static initializer, pre-C initializer, TLS callback, and CRT uninitializer tables; not handwritten NexusTK source.
  - Evidence: 2026-05-28 IDA MCP `py_eval` shows `___guard_check_icall_fptr`, `First`/`Last`, `TlsCallbacks`, CRT init/uninit function pointers, and startup-code xrefs from `0x005c850f-0x005c853a`.
  - Replacement/procurement: regenerated by the selected MSVC-compatible compiler/linker and CRT startup/runtime.
  - Owner docs: [UID:00024L][0x0060d670-0x0060d798.MsvcRdataStartupTables](by-memory/0x0060d670-0x0060d798.MsvcRdataStartupTables.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x0060e174-0x0060e2b0` and `0x0060f038-0x0060f4c0` - MSVC STL/Dinkumware read-only data.
  - Why ignored: standard-library/runtime exception, locale, facet, iostream, numeric, stream-formatting, and container diagnostic data; source reconstruction should use normal C++ library facilities.
  - Evidence: 2026-05-28 IDA MCP names include `std::runtime_error`, `_Facet_base`, `ctype<char>`, `_System_error`, `_Iostream_error_category`, `ios_base`, `num_put`, `num_get`, and STL diagnostic strings.
  - Replacement/procurement: regenerated by the standard library/runtime selected for the rebuild.
  - Owner docs: [UID:00024N][0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata](by-memory/0x0060e174-0x0060e2b0.MsvcStlLocaleIostreamRdata.md), [UID:00024P][0x0060f038-0x0060f4c0.MsvcStlNumericRdata](by-memory/0x0060f038-0x0060f4c0.MsvcStlNumericRdata.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x0060e2b0-0x0060f038` - JsonCpp `.rdata` vtables/settings/diagnostics.
  - Why ignored: third-party JsonCpp static-embed data rather than NexusTK-owned source.
  - Evidence: 2026-05-28 IDA MCP names show `Json::Exception`, `Json::CharReader`, `Json::StreamWriter`, `Json::Writer`, `Json::FastWriter`, `Json::StyledWriter`, parser setting keys, and Json::Value diagnostic strings.
  - Replacement/procurement: rebuild from the obtained JsonCpp source/header files documented in [UID:0000KI][JsonCpp](by-file/JsonCpp.md) and third-party library notes.
  - Owner docs: [UID:00024O][0x0060e2b0-0x0060f038.JsonCppReadOnlyData](by-memory/0x0060e2b0-0x0060f038.JsonCppReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x0060f4c0-0x006104f4` - LodePNG `.rdata` vtables/chunk constants/error strings.
  - Why ignored: third-party LodePNG static-embed data rather than NexusTK-owned source.
  - Evidence: 2026-05-28 IDA MCP names and strings show the LodePNG version/date `"20160501"`, `LodePNGState`/`lodepng::State` vtables, PNG chunk tags, and PNG/zlib/deflate error messages.
  - Replacement/procurement: rebuild from the obtained LodePNG source/header files documented in [UID:0000KW][LodePNG](by-file/LodePNG.md) and third-party library notes.
  - Owner docs: [UID:00024Q][0x0060f4c0-0x006104f4.LodePngReadOnlyData](by-memory/0x0060f4c0-0x006104f4.LodePngReadOnlyData.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x0066d000-0x0066d408` - LodePNG `.data` mutable lookup/state tables.
  - Why ignored: third-party LodePNG static-embed data rather than NexusTK-owned source.
  - Evidence: 2026-05-28 IDA MCP xrefs show `off_66D000` used from the LodePNG helper island with the `"LodePNG"` label and `dword_66D008` used by LodePNG CRC/chunk validation paths.
  - Replacement/procurement: rebuild from the obtained LodePNG source/header files documented in [UID:0000KW][LodePNG](by-file/LodePNG.md) and third-party library notes.
  - Owner docs: [UID:000274][0x0066d000-0x0066d408.LodePngMutableDataTables](by-memory/0x0066d000-0x0066d408.LodePngMutableDataTables.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0066da9a-0x0066da9c` and `0x0066da9e-0x0066daa0` - display/map-dimension zero padding.
  - Why ignored: confirmed zero padding between adjacent 16-bit globals, not standalone source data.
  - Evidence: 2026-05-28 IDA MCP byte/xref review shows both spans are `00 00` and have no direct data xrefs. Neighboring source globals are `g_screenHeight`, `g_mapTilePixelWidth`, and `g_mapTilePixelHeight`.
  - Replacement/procurement: no source replacement; compiler/linker or source-layout alignment bytes.
  - Owner docs: [UID:00027G][0x0066da9a-0x0066da9c.DisplayDimensionPadding](by-memory/0x0066da9a-0x0066da9c.DisplayDimensionPadding.md), [UID:00027H][0x0066da9e-0x0066daa0.MapTileDimensionPadding](by-memory/0x0066da9e-0x0066daa0.MapTileDimensionPadding.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0066de6c-0x0066deb0` - NCA URL to monster/riding table sentinel zero padding.
  - Why ignored: confirmed zero-filled gap between the obfuscated NCA confirm-user URL and the monster/riding image default frame record; no source behavior is stored here.
  - Evidence: 2026-05-28 IDA MCP byte/xref review shows all bytes in `0x0066de6c-0x0066deb0` are `00` and found no direct data xrefs. The preceding URL object ends at its NUL terminator, and the next referenced data starts at `0x0066deb0`.
  - Replacement/procurement: no source replacement; regenerated by declaration/layout alignment around adjacent static objects.
  - Owner docs: [UID:00027T][0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding](by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md), [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md), [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0066dee1-0x0066dee4`, `0x0066ed20-0x0066eea0`, `0x0066fce4-0x0066fe40`, and `0x0066fe4a-0x0066fe50` - data-section alignment padding around option/palette, HeadSelect, SelfLook, SpelledPane, and packet-transform globals.
  - Why ignored: confirmed zero-filled alignment/declaration gaps between adjacent initialized static data structures, not standalone source variables.
  - Evidence: 2026-05-28 IDA MCP byte/xref review reports no nonzero bytes and no direct xrefs for these spans. The surrounding referenced data starts at `0x0066dee4`, `0x0066df00`, `0x0066eea0`, `0x0066fe40`, `0x0066fe44`, and `0x0066fe50`.
  - Replacement/procurement: no source replacement; regenerated by declaration layout and compiler/linker alignment.
  - Owner docs: [UID:00027X][0x0066dee1-0x0066dee4.FriendNameOptionPalettePadding](by-memory/0x0066dee1-0x0066dee4.FriendNameOptionPalettePadding.md), [UID:000280][0x0066ed20-0x0066eea0.HeadSelectDialogLayoutPadding](by-memory/0x0066ed20-0x0066eea0.HeadSelectDialogLayoutPadding.md), [UID:000282][0x0066fce4-0x0066fe40.HeadSelectToSelfLookPadding](by-memory/0x0066fce4-0x0066fe40.HeadSelectToSelfLookPadding.md), [UID:000285][0x0066fe4a-0x0066fe50.SpelledPaneToPacketTransformPadding](by-memory/0x0066fe4a-0x0066fe50.SpelledPaneToPacketTransformPadding.md), and [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x006707d0-0x006707d4` - data-section alignment padding between snow-pattern tables and libjpeg data.
  - Why ignored: confirmed zero-filled alignment gap, not standalone source data.
  - Evidence: [UID:00028C][0x006707d0-0x006707d4.SnowToLibJpegDataPadding](by-memory/0x006707d0-0x006707d4.SnowToLibJpegDataPadding.md) records IDA MCP byte/xref review and neighboring range evidence.
  - Replacement/procurement: no source replacement; regenerated by data layout/alignment.
  - Owner docs: [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x006707d4-0x00671a74` - IJG libjpeg 6b `.data` diagnostics and memory-manager strings.
  - Why ignored: third-party libjpeg static data, not NexusTK product source data.
  - Evidence: [UID:00028D][0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings](by-memory/0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md) records IDA MCP data names/xrefs and ownership boundaries against libjpeg core and zlib data.
  - Replacement/procurement: [static_embeds/libjpeg-6b](../by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md), [UID:0000KN][LibJPEG](by-file/LibJPEG.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00671a74-0x00672f24` - zlib 1.1.4 `.data` messages, status pointers, and inflate/static table data.
  - Why ignored: third-party zlib static data, not NexusTK product source data.
  - Evidence: [UID:00028E][0x00671a74-0x00672f24.Zlib114DataMessagesAndTables](by-memory/0x00671a74-0x00672f24.Zlib114DataMessagesAndTables.md) records IDA MCP data names/xrefs and the exact boundary before `___security_cookie`.
  - Replacement/procurement: [static_embeds/zlib-1.1.4](../by-meta/obtained_thirdparty_files/static_embeds/zlib-1.1.4/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000PC][Zlib](by-file/Zlib.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x00672f24-0x006738c0` - MSVC runtime mutable data.
  - Why ignored: compiler/runtime support state such as security-cookie, TLS, locale, and console/runtime data, not project-owned logic or data.
  - Evidence: [UID:00028F][0x00672f24-0x006738c0.MsvcRuntimeMutableData](by-memory/0x00672f24-0x006738c0.MsvcRuntimeMutableData.md) records the IDA MCP audit and symbolic anchors including `___security_cookie`, `dwTlsIndex`, and `hConsoleOutput`.
  - Replacement/procurement: regenerated by the selected MSVC-compatible compiler/linker and runtime.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x006738c0-0x0067a730` - MSVC C++ RTTI type descriptor data.
  - Why ignored: compiler-generated RTTI/type-name metadata; useful for class discovery but not handwritten project data to port manually.
  - Evidence: [UID:00028G][0x006738c0-0x0067a730.CppRttiTypeDescriptorData](by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md) records IDA MCP range statistics and representative `??_R0?...@8` type descriptor names.
  - Replacement/procurement: regenerated from reconstructed class declarations, RTTI compiler settings, and linked third-party/runtime classes.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067a730-0x0067a738` - CRT local stdio-options storage.
  - Why ignored: CRT/UCRT support storage returned by formatted-output glue, not NexusTK project state.
  - Evidence: [UID:00028H][0x0067a730-0x0067a738.CrtStdioOptionsStorage](by-memory/0x0067a730-0x0067a738.CrtStdioOptionsStorage.md) records IDA MCP xrefs from `0x0041b9a0`; [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md) documents the function-side return of this address.
  - Replacement/procurement: regenerated by compatible CRT/UCRT formatted-output support.
  - Owner docs: [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md), [UID:0001QE][client_libraries](by-meta/client_libraries.md).

- `0x0067a768-0x0067a770` - CRT local stdio-options storage for scanf-family wrappers.
  - Why ignored: CRT/UCRT support storage returned by formatted-input glue, not NexusTK project state.
  - Evidence: [UID:00028M][0x0067a768-0x0067a770.CrtStdioScanOptionsStorage](by-memory/0x0067a768-0x0067a770.CrtStdioScanOptionsStorage.md) records IDA MCP xrefs from `sub_443980`, `__scrt_initialize_default_local_stdio_options`, and scanf/wscanf wrapper thunks.
  - Replacement/procurement: regenerated by compatible CRT/UCRT formatted-input support.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067a770-0x0067a79c` - JsonCpp static value and reader state.
  - Why ignored: third-party JsonCpp static data and compiler static-initialization support, not NexusTK project state.
  - Evidence: [UID:00028N][0x0067a770-0x0067a79c.JsonCppStaticValueData](by-memory/0x0067a770-0x0067a79c.JsonCppStaticValueData.md) records IDA MCP xrefs from startup wrappers, JsonCpp parser stack-depth checks, the static null-value accessor, and the cleanup thunk.
  - Replacement/procurement: [static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802](../by-meta/obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/) from [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md).
  - Owner docs: [UID:0000KI][JsonCpp](by-file/JsonCpp.md), [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md), [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md).

- `0x0067a79c-0x0067a7c4` - MSVC STL locale/facet static storage.
  - Why ignored: compiler/runtime standard-library locale and once-flag state, not NexusTK project state.
  - Evidence: [UID:00028O][0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage](by-memory/0x0067a79c-0x0067a7c4.MsvcLocaleFacetStaticStorage.md) records IDA MCP xrefs from `std::_Lockit`-guarded facet helpers and `std::_Execute_once`.
  - Replacement/procurement: regenerated by compatible C++ standard-library/runtime support.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067a830-0x0067a834` - unreferenced initialized filler before AboveFrame slots.
  - Why ignored: no direct IDA xrefs and no named code owner; it is a four-byte initialized `0xffffffff` spacer after the MMX blend-weight scratch qwords and before the first `AboveFrame*` slot.
  - Evidence: 2026-05-28 IDA MCP `py_eval` reports `.data` bytes `ff ff ff ff` at `0x0067a830`, zero xrefs to that dword, and real `AboveFrame` slot xrefs beginning at `0x0067a834`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md), [UID:0001P1][0x0067a834-0x0067a874.AboveFrameSlots](by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067a934-0x0067a938` - unreferenced initialized filler between AES state and application flags.
  - Why ignored: no direct IDA xrefs and no named code owner; it is a four-byte initialized spacer between real AES mutable state and real application lifecycle flags.
  - Evidence: 2026-05-28 IDA MCP `py_eval` reports no xrefs for the dword at `0x0067a934`; nearby xrefs target the AES state ending at `0x0067a934` and application flag data beginning at `0x0067a938`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md), [UID:00028Z][0x0067a938-0x0067a940.ApplicationLifecycleFlags](by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067ab18-0x0067ab1c` - ATL base-module initialization failure flag.
  - Why ignored: ATL/runtime support state, not NexusTK project-owned state. The flag records critical-section initialization failure inside `CAtlBaseModule` startup support.
  - Evidence: 2026-05-28 IDA MCP decompilation of `sub_5C8B0B` shows `byte_67AB18` set when the ATL base-module critical-section initialization fails, followed by optional `OutputDebugStringW("ERROR : Unable to initialize critical section in CAtlBaseModule\n")`.
  - Replacement/procurement: regenerated by the ATL/runtime support linked into the rebuilt executable.
  - Owner docs: [UID:000293][0x0067a9c0-0x0067ab18.ApplicationOsVersionState](by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md), [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0067adec-0x0067adf0` - unreferenced initialized filler between UI singleton slots and global wide-character scratch storage.
  - Why ignored: no direct IDA xrefs, no IDA name, and no identified source owner; it is a four-byte initialized spacer between real project-owned `.data` objects.
  - Evidence: 2026-05-28 IDA MCP byte review reports `ff ff ff ff`, zero direct xrefs, the clan-bank singleton slot ending at `0x0067adec`, and the `WideCharStr` buffer beginning at `0x0067adf0`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:0002B6][0x0067adec-0x0067adf0.UnreferencedInitializedDword_67ADEC](by-memory/0x0067adec-0x0067adf0.UnreferencedInitializedDword_67ADEC.md), [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md), [UID:0002B7][0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer](by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md).

- `0x0069ae14-0x0069ae18` - unreferenced initialized filler between frame-registry and keyboard-state globals.
  - Why ignored: no direct IDA xrefs, no IDA name, and no identified source owner; it is a four-byte initialized spacer between real project-owned `.data` objects.
  - Evidence: 2026-05-28 IDA MCP byte review reports `ff ff ff ff`, zero direct xrefs, `g_frameRegistry` ending at `0x0069ae14`, and the live `KeyState` buffer beginning at `0x0069ae18`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:0002AU][0x0069ae14-0x0069ae18.UnreferencedInitializedDword_69AE14](by-memory/0x0069ae14-0x0069ae18.UnreferencedInitializedDword_69AE14.md), [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md), [UID:0002AV][0x0069ae18-0x0069af20.KeyboardStateGlobals](by-memory/0x0069ae18-0x0069af20.KeyboardStateGlobals.md).

- `0x0069af21-0x0069b328` - unreferenced initialized filler between keyboard shortcut state and item/exchange singleton slots.
  - Why ignored: no direct IDA xrefs, no IDA name, and no identified source owner; it is initialized `0xff` filler after the keyboard chord gate byte.
  - Evidence: 2026-05-28 IDA MCP byte review reports all bytes in this exact span are `0xff`, with the last live keyboard byte ending at `0x0069af21` and the next named/referenced slot beginning at `0x0069b328`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:0002AX][0x0069af21-0x0069b328.UnreferencedInitializedBytes_69AF21](by-memory/0x0069af21-0x0069b328.UnreferencedInitializedBytes_69AF21.md), [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md), [UID:0002AY][0x0069b328-0x0069b33c.ItemExchangeAndFpsSingletonGlobals](by-memory/0x0069b328-0x0069b33c.ItemExchangeAndFpsSingletonGlobals.md).

- `0x0069ba30-0x0069ba34` - unreferenced initialized filler between PatchPane2 and PowerDialog slots.
  - Why ignored: no direct IDA xrefs, no IDA name, and no identified source owner; the neighboring dwords are real singleton slots.
  - Evidence: 2026-05-28 IDA MCP `py_eval` reports bytes `ff ff ff ff` at `0x0069ba30`, zero xrefs, and no name; `dword_69BA28` and `dword_69BA2C` are real `ParcelPane`/`PatchPane2` slots, and `g_pPowerDialog` begins at `0x0069ba34`.
  - Replacement/procurement: regenerated naturally by source/linker layout or omitted in a non-address-identical rebuild.
  - Owner docs: [UID:0002A1][0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30](by-memory/0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md).

- `0x0069c044-0x0069d000` - MSVC runtime mutable-data tail.
  - Why ignored: final `.data` tail contains CRT/STL/compiler/runtime support state, not NexusTK-owned source data.
  - Evidence: [UID:0002AJ][0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail](by-memory/0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md) records the 2026-05-28 IDA MCP byte/xref audit: all `4028` bytes initialize to `0xff`, but the span has `198` named or referenced anchors across startup, STL locale/facet, API-pointer, security-failure, TLS, stdio, heap, timezone, file, environment, and multibyte runtime support.
  - Replacement/procurement: regenerated by the selected MSVC-compatible compiler/linker, CRT, STL, and runtime libraries.
  - Owner docs: [UID:0001QE][client_libraries](by-meta/client_libraries.md), [UID:0001Z8][0x0066d000-0x0069d000.DataSection](by-memory/0x0066d000-0x0069d000.DataSection.md), [UID:00028F][0x00672f24-0x006738c0.MsvcRuntimeMutableData](by-memory/0x00672f24-0x006738c0.MsvcRuntimeMutableData.md), [UID:000273][0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail](by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md).

- `0x00632560-0x0066d000` - MSVC runtime/CRT/STL `.rdata` tail.
  - Why ignored: compiler/runtime-generated function metadata, standard-library exception and locale vtables, system error text, API-set names, CRT math/assert/locale strings, and formatting tables; not handwritten NexusTK source.
  - Evidence: 2026-05-28 IDA MCP names show `funcs_4149B4`, C++ exception vtables, standard error strings, API-set imports, CRT math and assertion labels, locale/date/month strings, code-page labels, and other MSVC runtime data across this span.
  - Replacement/procurement: regenerated by the selected MSVC-compatible compiler, linker, CRT, and STL. Exact contents may legitimately differ if the rebuild uses a different runtime.
  - Owner docs: [UID:000273][0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail](by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md), [UID:0001Z7][0x0060d670-0x0066d000.ReadOnlyDataSection](by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md).

- `0x0059756e-0x00597570`, `0x005986da-0x005986e0`, `0x00598cbf-0x00598cc0`, `0x00598ecf-0x00598ed0`, `0x0059943f-0x00599440`, `0x005994a8-0x005994b0`, `0x005994c5-0x005994d0`, `0x00599543-0x00599550`, `0x00599565-0x00599570`, `0x005995a7-0x005995b0`, `0x00599a34-0x00599a40`, `0x00599cb3-0x00599cc0`, `0x0059bc8b-0x0059bc90`, `0x0059f25b-0x0059f260`, and `0x005a2523-0x005a2530` - thread/timer/totem/platform/user-pane boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented functions and helper islands after splitting the former UNKNOWN rows from `0x0059756e-0x005a2530`.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports these spans as alignment around `ThreadMan`, `TimerMgr`, `TimerPane`, corrected `TotemFrame`, `TransferServerDialogPane`, [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), corrected `UniAPIInit`, `UrlAlertPane`, `UserInfoDialogPane`, `UserListDialogPane`, `UserLookPane`, and `UserPane`. The same pass confirms real helper code at `0x00599440-0x005995a7`, the corrected TotemFrame destructor boundary `0x00598e70-0x00598ecf`, and the corrected UniAPIInit scalar deleting destructor boundary `0x00599a10-0x00599a34`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001K5][0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor](by-memory/0x005974f0-0x0059756e.ThreadManScalarDeletingDestructor.md), [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md), [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md), [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md), [UID:0001KD][0x00598ed0-0x0059943f.TransferServerDialogPane](by-memory/0x00598ed0-0x0059943f.TransferServerDialogPane.md), [UID:000249][0x00599440-0x005995a7.PlatformStringConversionHelpers](by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md), [UID:0001KE][0x005995b0-0x00599a34.UniAPIInit](by-memory/0x005995b0-0x00599a34.UniAPIInit.md), [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md), [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md), [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md), [UID:0001KK][0x0059f260-0x005a2523.UserLookPaneAndProfilePanes](by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md), and [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md).

- `0x00597e3f-0x00597e40`, `0x00597e8a-0x00597e90`, `0x00597ea3-0x00597eb0`, `0x00597f17-0x00597f20`, `0x00597fc9-0x00597fd0`, `0x00597fdb-0x00597fe0`, `0x00598083-0x00598090`, `0x005980eb-0x005980f0`, `0x00598282-0x00598290`, and `0x00598472-0x00598480` - internal TimerMgr queue helper alignment padding.
  - Disposition: ignore as compiler alignment filler between exact TimerMgr queue helper functions.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs` confirmed the neighboring function starts/sizes, and `py_eval` byte inspection reported these spans as all `0xcc` bytes.
  - Owner docs: [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md), [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md), [UID:0002KY][0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod.md), [UID:0002KZ][0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick.md), [UID:0002L0][0x00597eb0-0x00597f16.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f16.TimerQueueReverseRange.md), [UID:0002L1][0x00597f20-0x00597fc8.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc8.TimerQueueRotateRange.md), [UID:0002L2][0x00597fd0-0x00597fda.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fda.ClearGlobalTimerMgr.md), [UID:0002L3][0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor.md), [UID:0002L4][0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor.md), [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md), [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md), and [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md).

- `0x005b8395-0x005b83a0`, `0x005b83a7-0x005b83b0`, `0x005baafe-0x005bab00`, `0x005bc60c-0x005bc610`, `0x005c0034-0x005c0040`, `0x005c045b-0x005c0460`, `0x005c0fe1-0x005c0ff0`, `0x005c129a-0x005c12a0`, `0x005c1bc7-0x005c1bd0`, and `0x005c2ab5-0x005c2ac0` - user-pane/status/weather-layer boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between adjacent documented functions and class clusters after splitting the former UNKNOWN rows from `0x005b8395-0x005c2ac0`.
  - Evidence: 2026-05-28 IDA MCP byte/function review reports the listed spans as alignment around `UserPane`, [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md), `UserStatusPane`, `UserStatusPane2`, `MenuVarietyPanes`, the UI pane destructor thunk island, `VideoPlayerPane`, `VirusChecker`, corrected `WaitableTimer`, corrected weather/rain panes, and corrected snow/swallow panes. The same pass confirms the real tiny `UserPane` vtable accessor at `0x005b83a0-0x005b83a7`, `WaitableTimer` scalar deleting destructor end `0x005c129a`, `RainingLayerPane::DrawRainOnTarget` end `0x005c1bc7`, and `SwallowLayerPane` scalar deleting destructor end `0x005c2ab5`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes. Corrected final instruction bytes are covered by their owning memory pages.
  - Owner docs: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md), [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md), [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md), [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md), [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md), [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md), [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md), [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md), [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md).

- `0x005b68b0-0x005b68c0` - alignment padding between `SelfSaveInputPane` and `BlockListenInputPane`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the raw SelfSave send helper and before the block-list input pane constructor neighborhood.
  - Evidence: 2026-06-02 IDA MCP raw byte read for `0x005b67c0-0x005b68c0` shows the raw helper returning at `0x005b68af`, followed by sixteen `0xcc` bytes through the next reviewed range start at `0x005b68c0`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001MU][0x005b67c0-0x005b68b0.SelfSaveInputPane](by-memory/0x005b67c0-0x005b68b0.SelfSaveInputPane.md), [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md), and [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md).

- `0x005b27b3-0x005b27c0`, `0x005b2827-0x005b2830`, and `0x005b296b-0x005b2970` - TakeOffInputPane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the TakeOff shortcut handler, shared packet helper, command handler, and following function boundary.
  - Evidence: 2026-06-02 IDA MCP `lookup_funcs` confirms `sub_5B2720` ends at `0x005b27b3`, `sub_5B27C0` ends at `0x005b2827`, and `sub_5B2830` ends at `0x005b296b`; raw byte reads show thirteen, nine, and five `0xcc` bytes respectively before the next boundary.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001M1][0x005b2720-0x005b296b.TakeOffInputPane](by-memory/0x005b2720-0x005b296b.TakeOffInputPane.md), [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), and [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md).

- `0x005b2f68-0x005b2f70` and `0x005b2fcb-0x005b2fd0` - EmotionInputPane helper boundary alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between `EmotionInputPane::OnCharInput`, the private emotion packet helper, and the following `ChangeItemSlotInputPane` raw constructor neighborhood.
  - Evidence: 2026-06-02 IDA MCP `lookup_funcs` confirms `sub_5B2A70` ends at `0x005b2f68`, `sub_5B2F70` starts at `0x005b2f70` and ends at `0x005b2fcb`, and `0x005b2fd0` is not an IDA function start; raw byte reads show eight and five `0xcc` bytes respectively.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md), [UID:0001M4][0x005b2f70-0x005b2fcb.SendEmotionPacket](by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md), and [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md).

- `0x005b307c-0x005b3080` and `0x005b3196-0x005b31a0` - ChangeItemSlotInputPane internal alignment padding.
    - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between `ChangeItemSlotInputPane` virtual handler/submit functions and after the submit handler before the next neighborhood.
  - Evidence: 2026-06-02 IDA MCP `lookup_funcs` confirms `sub_5B3010` ends at `0x005b307c`, `sub_5B3080` starts at `0x005b3080` and ends at `0x005b3196`; raw byte reads show four and ten `0xcc` bytes respectively.
    - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md), [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md), and [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md).

  - `0x005b32cc-0x005b32d0` and `0x005b340e-0x005b3410` - ChangeSpellSlotInputPane internal and tail alignment padding.
    - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between `ChangeSpellSlotInputPane` key/submit functions and after the submit handler before the next `SayInputPane` raw constructor neighborhood.
    - Evidence: 2026-06-02 IDA MCP `lookup_funcs` confirms `sub_5B3260` ends at `0x005b32cc`, `sub_5B32D0` starts at `0x005b32d0` and ends at `0x005b340e`; raw byte reads show four and two `0xcc` bytes respectively.
    - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
    - Owner docs: [UID:0001M8][0x005b3220-0x005b340e.ChangeSpellSlotInputPane](by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md), [UID:0001M9][0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput](by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md), [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md), and [UID:00001M][ChangeSpellSlotInputPane](by-class/ChangeSpellSlotInputPane.md).

  - `0x005b6c00-0x005b6c30` - switch/jump table bytes for `BlockListenInputPane` command dispatch.
  - Why ignored: compiler-generated switch data supporting the `A/a` and `D/d` command dispatcher, not a standalone source function.
  - Evidence: 2026-06-02 IDA MCP disassembly at `0x005b6c00` labels the bytes as a jump table and indirect table for the switch in [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md); raw byte read reports 48 bytes from `0x005b6c00-0x005b6c30`.
  - Replacement/procurement: no independent source replacement; recreate through the dispatcher source.
  - Owner docs: [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) and [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md).

- `0x005b6c7c-0x005b6c80`, `0x005b70f7-0x005b7100`, and `0x005b7447-0x005b7450` - alignment padding around block-list packet helper islands.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between raw block-list packet helper bodies and adjacent constructor/function starts.
  - Evidence: 2026-06-02 IDA MCP raw byte reads report four `0xcc` bytes at `0x005b6c7c-0x005b6c80`, nine `0xcc` bytes at `0x005b70f7-0x005b7100`, and nine `0xcc` bytes at `0x005b7447-0x005b7450`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md), [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md), [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md), and [UID:0001MW][0x005b68c0-0x005b7354.BlockListenInputPanes](by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md).

- `0x005add18-0x005add20` and `0x005add8a-0x005add90` - alignment padding around `QuitInputPane::OnConfirmInput`.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the raw `QuitInputPane` constructor-shaped body, the modeled confirmation handler, and the next raw helper body.
  - Evidence: 2026-06-02 IDA MCP raw byte read for `0x005adcc0-0x005add90` shows the constructor-shaped body returning at `0x005add17`, eight `0xcc` bytes through `0x005add20`, the modeled handler returning at `0x005add89`, and six `0xcc` bytes through `0x005add90`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md), [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md), and [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).

- `0x00483f86-0x00483f90`, `0x00483fd9-0x00483fe0`, `0x00483fe5-0x00483ff0`, and `0x00483ffb-0x00484000` - CheatDetector internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between documented `CheatDetector` constructor, time-snapshot helper, vtable helper, singleton-clear helper, and scalar deleting destructor ranges.
  - Evidence: 2026-05-30 IDA MCP byte audit reports all four spans as `0xcc` alignment. The same pass discovered the previously undocumented executable helper at [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md), [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md), [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md).

- `0x00482b01-0x00482b10`, `0x00482b2f-0x00482b30`, `0x00482c32-0x00482c40`, `0x00482c54-0x00482c60`, and `0x00482c9f-0x00482ca0` - ChattingColorPane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the documented `ChattingColorPane` constructor, destructor body, button response, raw selector refresh helper, raw list-sync helper, and the following `ChattingColorSelectPane` start.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports these exact spans as `0xcc` alignment and confirms executable bodies at [UID:0002FX][0x004824e0-0x00482b01.ChattingColorPaneConstructor](by-memory/0x004824e0-0x00482b01.ChattingColorPaneConstructor.md), [UID:0002FY][0x00482b10-0x00482b2f.ChattingColorPaneDestructor](by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md), [UID:0002FZ][0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse](by-memory/0x00482b30-0x00482c32.ChattingColorPaneOnButtonResponse.md), [UID:0002G0][0x00482c40-0x00482c54.ChattingColorPaneRefreshColorSelectHelperRaw](by-memory/0x00482c40-0x00482c54.ChattingColorPaneRefreshColorSelectHelperRaw.md), and [UID:0002G1][0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListSelectionHelperRaw](by-memory/0x00482c60-0x00482c9f.ChattingColorPaneSyncColorListSelectionHelperRaw.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x00482d3c-0x00482d40`, `0x00482d4a-0x00482d50`, `0x00482d5a-0x00482d60`, `0x00482f4f-0x00482f50`, and `0x00482fa5-0x00482fb0` - ChattingColorSelectPane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the documented `ChattingColorSelectPane` constructor, raw refresh helper, raw selection notify helper, draw-item virtual, selection-changed virtual, and the following `ChattingColorListPane` constructor.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports these exact spans as `0xcc` alignment and confirms executable bodies at [UID:0002G2][0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor](by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md), [UID:0002G3][0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw](by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md), [UID:0002G4][0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw](by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md), [UID:0002G5][0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem](by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md), and [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00001U][ChattingColorSelectPane](by-class/ChattingColorSelectPane.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x004d006f-0x004d0070`, `0x004d011b-0x004d0120`, and `0x004e6572-0x004e6580` - ImageLib internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact `ImageLib` constructor/destructor/scalar-deleting destructor functions and neighboring functions after correcting the old off-by-one range ends.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports `sub_4CFFB0` as `0x004cffb0-0x004d006f`, `sub_4D0070` as `0x004d0070-0x004d011b`, `sub_4E64A0` as `0x004e64a0-0x004e6572`, and the listed spans as all `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000172][0x004cffb0-0x004e6572.ImageLib](by-memory/0x004cffb0-0x004e6572.ImageLib.md), [UID:0002IN][0x004cffb0-0x004d006f.ImageLibConstructor](by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md), [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md), [UID:0002IO][0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor](by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md).

- `0x004dee1b-0x004dee20`, `0x004dee4d-0x004dee50`, `0x004defba-0x004defc0`, `0x004df1d4-0x004df1e0`, `0x004df2b7-0x004df2c0`, `0x004df455-0x004df460`, `0x004e5bab-0x004e5bb0`, and `0x004e65dc-0x004e65e0` - ItemObjImageLib internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between corrected `ItemObjImageLib` constructor, ordinary destructor, draw methods, singleton helper, scalar deleting destructor, and neighboring functions.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports constructor `0x004dec30-0x004dee1b`, draw methods `0x004dee50-0x004defba`, `0x004defc0-0x004df1d4`, `0x004df1e0-0x004df2b7`, `0x004df2c0-0x004df455`, singleton helper `0x004e5ba0-0x004e5bab`, scalar deleting destructor `0x004e6580-0x004e65dc`, and all listed spans as `0xcc` bytes. The ordinary destructor body `0x004dee20-0x004dee4d` is not an IDA function object but is documented from byte/disassembly evidence.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md), [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md), [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md).

- `0x004dfaa6-0x004dfab0`, `0x004dfb36-0x004dfb40`, `0x004dfc5a-0x004dfc60`, `0x004dfd0a-0x004dfd10`, and `0x004e669d-0x004e66a0` - LightObjImageLib internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact `LightObjImageLib` constructor, raw ordinary destructor, bounds helper, draw methods, scalar deleting destructor, and neighboring image-library/template code.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports constructor `0x004df7e0-0x004dfaa6`, raw ordinary destructor `0x004dfab0-0x004dfb36`, bounds helper `0x004dfb40-0x004dfbb0`, draw methods `0x004dfbb0-0x004dfc5a` and `0x004dfc60-0x004dfd0a`, scalar deleting destructor `0x004e65e0-0x004e669d`, and all listed spans as alignment bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00017P][0x004df7e0-0x004e669c.LightObjImageLib](by-memory/0x004df7e0-0x004e669c.LightObjImageLib.md), [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md), [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md), [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md), [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md), [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md).

- `0x004e024a-0x004e0250` - NewHumanImageLib constructor-to-destructor alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the exact NewHumanImageLib constructor end and ordinary destructor start.
  - Evidence: 2026-05-31 IDA MCP `lookup_funcs 0x004dfd10` reports `0x004dfd10-0x004e024a`, `lookup_funcs 0x004e0250` reports the destructor start, and byte read for `0x004e024a-0x004e0250` returns `cc cc cc cc cc cc`.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md), [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md), [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md).

- `0x004e5415-0x004e5420` - VectorGrowMotion-to-next-vector-helper alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the exact `VectorGrowMotion` body and before the adjacent vector growth helper at `0x004e5420`.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs 0x004e5240` reports `0x004e5240-0x004e5415`, `lookup_funcs 0x004e5420` reports the next helper start, and byte read for `0x004e5415-0x004e5420` returns eleven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md), [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md).

- `0x004e5e39-0x004e5e40` - DestroyMotionVector-to-next-vector-cleanup alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes after the corrected `DestroyMotionVector` body and before the next vector cleanup helper at `0x004e5e40`.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs 0x004e5dd0` reports `sub_4E5DD0` size `0x69`, so the exclusive end is `0x004e5e39`; `lookup_funcs 0x004e5e40` reports the next helper start, and byte read for `0x004e5e39-0x004e5e40` returns seven `0xcc` bytes.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md), [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md).

- `0x004e5b7b-0x004e5b80`, `0x004e5b8b-0x004e5b90`, `0x004e5b9b-0x004e5ba0`, `0x004e5bab-0x004e5bb0`, `0x004e5bbb-0x004e5bc0`, `0x004e5bcb-0x004e5bd0`, `0x004e5bdb-0x004e5be0`, `0x004e5beb-0x004e5bf0`, `0x004e5bfb-0x004e5c00`, and `0x004e5c0b-0x004e5c10` - image-library singleton clear helper island alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between exact `0xb` singleton clear helpers in the image-library cleanup island.
  - Evidence: 2026-06-01 IDA MCP function and byte audit reports helpers at `0x004e5b70`, `0x004e5b80`, `0x004e5b90`, `0x004e5ba0`, `0x004e5bb0`, `0x004e5bc0`, `0x004e5bd0`, `0x004e5be0`, `0x004e5bf0`, and `0x004e5c00`, each size `0xb`; raw bytes show five `0xcc` alignment bytes after each helper before the next 16-byte boundary.
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md), [UID:00017X][0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper](by-memory/0x004e5b80-0x004e5b8b.HumanImageLibSingletonClearHelper.md), [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md), [UID:00017Z][0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper](by-memory/0x004e5bb0-0x004e5bbb.LightObjImageLibSingletonClearHelper.md), [UID:000180][0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper](by-memory/0x004e5bc0-0x004e5bcb.MapTileImageLibSingletonClearHelper.md), [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md), [UID:000182][0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper](by-memory/0x004e5be0-0x004e5beb.NewHumanImageLibSingletonClearHelper.md), [UID:000183][0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper](by-memory/0x004e5bf0-0x004e5bfb.RidingImageLibSingletonClearHelper.md), and [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md). The executable helper at `0x004e5b90-0x004e5b9b` is not padding.

- `0x00483206-0x00483210`, `0x0048325b-0x00483260`, `0x0048326f-0x00483270`, `0x004832b9-0x004832c0`, `0x00483414-0x00483420`, and `0x00483487-0x00483490` - ChattingColorListPane internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the documented `ChattingColorListPane` constructor, select-current helper, raw selected-color accessor, find-index helper, draw-item virtual, selected-item virtual, and the following `ColorStringChattingMessage` start.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports these exact spans as `0xcc` alignment and confirms executable bodies at [UID:0002G7][0x00482fb0-0x00483206.ChattingColorListPaneConstructor](by-memory/0x00482fb0-0x00483206.ChattingColorListPaneConstructor.md), [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md), [UID:0002G9][0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw](by-memory/0x00483260-0x0048326f.ChattingColorListPaneGetSelectedColorValueRaw.md), [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md), [UID:0002GB][0x004832c0-0x00483414.ChattingColorListPaneDrawItem](by-memory/0x004832c0-0x00483414.ChattingColorListPaneDrawItem.md), and [UID:0002GC][0x00483420-0x00483487.ChattingColorListPaneOnItemSelected](by-memory/0x00483420-0x00483487.ChattingColorListPaneOnItemSelected.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00001S][ChattingColorListPane](by-class/ChattingColorListPane.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x00483541-0x00483550`, `0x004835a9-0x004835b0`, `0x0048362b-0x00483630`, and `0x0048369a-0x004836a0` - ColorStringChattingMessage internal alignment padding.
  - Why ignored: confirmed `0xcc` compiler/linker alignment bytes between the documented `ColorStringChattingMessage` constructor, destructor body, clone virtual, line-count virtual, and draw virtual.
  - Evidence: 2026-05-31 IDA MCP function/byte audit reports these exact spans as `0xcc` alignment and confirms executable bodies at [UID:0002GD][0x00483490-0x00483541.ColorStringChattingMessageConstructor](by-memory/0x00483490-0x00483541.ColorStringChattingMessageConstructor.md), [UID:0002GE][0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody](by-memory/0x00483550-0x004835a9.ColorStringChattingMessageDestructorBody.md), [UID:0002GF][0x004835b0-0x0048362b.ColorStringChattingMessageClone](by-memory/0x004835b0-0x0048362b.ColorStringChattingMessageClone.md), [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md), and [UID:0002GH][0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables](by-memory/0x004836a0-0x004839c0.ColorStringChattingMessageDrawWithTables.md).
  - Replacement/procurement: no source replacement; compiler/linker alignment bytes.
  - Owner docs: [UID:00002Z][ColorStringChattingMessage](by-class/ColorStringChattingMessage.md), [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md).

- `0x004839c0-0x00483ef7` - Chatting UI destructor/adjustor glue family.
  - Why ignored: documented compiler-generated singleton-clear helpers, adjustor thunks, and scalar deleting destructor wrappers; these are generated from class destructor semantics, vtables, and inheritance layout rather than handwritten standalone source.
  - Evidence: 2026-05-31 IDA MCP function iteration, decompilation, vtable xrefs, and raw thunk disassembly are documented in [UID:0002GI][0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily](by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md).
  - Replacement/procurement: no source replacement; re-created by implementing the owning class destructors and matching vtable/inheritance layout.
  - Owner docs: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md), [UID:0000I5][Chatting](by-file/Chatting.md).
