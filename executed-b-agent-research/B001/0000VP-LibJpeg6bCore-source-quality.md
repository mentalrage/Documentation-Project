** TARGET-REPORT-UID:0000VP **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
*** Assignment: B001-report-0000VP-libjpeg6bcore-source-quality-20260626 ***
*** Target: [UID:0000VP] by-memory/0x00401000-0x00414283.LibJpeg6bCore.md ***
*** Mode: REPORT_ONLY ***

# [UID:0000VP] LibJpeg6bCore Source-Quality Report

## Status

Report-only research completed with current live IDA MCP evidence. I did not lease or edit any by-* docs, generated/project-level files, coverage reports, validator/tool state, or the IDA database.

Primary finding: [UID:0000VP] should not remain a source-bearing/emitting aggregate. It should become a non-emitting third-party library split/index owned by [UID:0000KN][LibJPEG](../../../../../by-file/LibJPEG.md), with the actual source-bearing pages carried by exact source-file child docs and by the staged IJG libjpeg 6b static embed.

Recommended target metadata after implementation:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `85` | `90` |
| `CONFIDENCE` | `89` | `92` |
| `CANONICAL_OWNER` | `0000KN` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` |
| `EMITTER_UIDS` | `0000KN` | blank |
| `EMITTER_POSITION_OPTIONAL` | blank | unchanged |
| formal `RECONSTRUCTION_CPP CODE` | blank | blank |

The no-code reason is target-specific: [UID:0000VP] is an overlap/container index for a verified third-party static library. Emitting a Hex-Rays aggregate would duplicate or degrade the staged official IJG source.

## MCP Evidence

MCP endpoint: `http://127.0.0.1:13337/mcp`.

Current session/database: `80de0a67`.

Evidence commands used in this pass:

| Command id | Tool/call | Result |
| --- | --- | --- |
| `b001-0000VP-init2` | JSON-RPC `initialize` | `ida-pro-mcp` responded, protocol `2025-06-18`. |
| `b001-0000VP-schema2` | `tools/list` | Confirmed schemas for `server_health`, `idb_list`, `entity_query`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `analyze_function`, `decompile`, and related read-only tools. |
| `b001-0000VP-high-functions-compact` | `entity_query(kind=functions, 0x00406ed0-0x00414290)` | Returned `185` function records from `nullsub_2` at `0x00406ed0` through `_AIL_shutdown@0` at `0x00414290`. |
| `b001-0000VP-low-functions-compact` | `entity_query(kind=functions, 0x00401000-0x00406ee0)` | Returned `128` modeled function records from `0x00401000` through `0x00406ed0` and confirmed the `0x00406ee0` successor. |
| `b001-0000VP-analyze-*` | `analyze_function` on library initializers | Confirmed decompression/compression controller offsets and callback install patterns for `jdcoefct.c`, `jdmainct.c`, entropy, IDCT/DCT managers, color, sample, quantizer, and compression controller groups. |
| `b001-0000VP-xrefs-*` | `xrefs_to` on initializer heads | Confirmed `jinit_master_decompress` at `0x00405fe0` calls the decompression-side high-range initializers and `jinit_compress_master` at `0x00406d90` calls the compression-side high-range initializers. |
| `b001-0000VP-null-xrefs-*` | `xrefs_to` on null callback heads | Assigned one-byte null callbacks to the correct source files: `0x0040b220` to `jdcolor.c`, `0x0040cc00/0x0040cc10` to `jquant1.c`, `0x0040d840/0x0040d850` to `jquant2.c`, `0x00410930` to `jcsample.c`, `0x00411950` to `jccolor.c`, and `0x00406ed0` to `jmemnobs.c`. |
| `b001-0000VP-tail-bytes` | `get_bytes(0x00414280, 80)` | Confirmed final libjpeg return bytes ending at `0x00414283`, `0x90` padding through `0x0041428f`, `_AIL_shutdown@0` thunk at `0x00414290`, atexit glue at `0x004142a0`, and zlib code beginning after that. |
| `b001-0000VP-health-retry-after-timeout` | `server_health(database=80de0a67)` | After one heavy tail analysis timed out, MCP recovered on brief retry with `status:"ok"`, Hex-Rays ready, strings cache ready. No fallback-only conclusion is used. |

## Existing Documentation Review

Current [UID:0000VP] already proves the island identity and major edges: IJG copyright/version strings, `jpeg_std_error` at `0x00401000`, `jpeg_std_message_table` at `0x00631660`, support strings at `0x006707d4-0x00671a74`, no-backing-store memory backend, product decode and screenshot consumers, Miles exclusion at `0x00414290`, and zlib successor at `0x004142c0`.

The stale source-quality blocker is structural, not identity-related:

- [UID:0000VP] still carries `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000KN` even though it is a broad aggregate with blank formal C++.
- The current child set covers public API, marker, memory, master, utility, marker writer, compression master, and no-backing-store ranges, but leaves the largest remaining leaf at `0x00406ed1-0x00414283`.
- The target still frames remaining entropy, coefficient, color, sampling, quantizer, and DCT/IDCT helpers as open mapping work. Current MCP and staged IJG source resolve that mapping to exact source-file child ranges.
- Stale Wave2/Wave3 material should not be used as evidence. The new implementation should replace those notes with this current MCP/source-file map.

Support docs with same-or-greater boundary proof already present:

- [UID:0000W3][ZlibCore](../../../../../by-memory/0x004142c0-0x00419e56.ZlibCore.md) already records `0x004142c0` as zlib start and excludes the preceding Miles glue.
- [UID:0003OI][LibJpeg6bMessagePointerTable](../../../../../by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md) already ties `0x00631660` to `jerror.c`.
- [UID:00028D][LibJpeg6bDataMessagesAndMemoryStrings](../../../../../by-memory/0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md) already records the diagnostic string pool, `JPEGMEM`, `%ld%c`, and zlib data successor.
- [UID:0001G8][ScreenshotJpegCapturePath](../../../../../by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md) already documents JPG screenshot reachability as a product wrapper path and not libjpeg internals.

## Source Placement Decision

Use staged official IJG libjpeg 6b source from:

```text
source-3/third_party_embeds/libjpeg/
```

by-meta provenance confirms the folder is derived from `jpegsrc.v6b.tar.gz`, uses the Windows-style `jconfig.h`, and includes the static library source set plus `jmemnobs.c`.

Do not paste upstream libjpeg source bodies into by-memory formal C++ blocks. Source-bearing child pages should use comment-only static-embed markers, following the existing JsonCpp split-index precedent.

Parent [UID:0000VP] exact formal block policy:

```text
RECONSTRUCTION_CPP CODE remains empty between BEGIN/END.
```

New source-bearing child formal marker policy:

```cpp
// Static embed: third_party_embeds/libjpeg/<source-file>.c
```

Existing source-bearing libjpeg children may also be updated to the same marker style when touched. If they are not touched, their factual range/source mapping is already usable, but the parent should not imply that the broad aggregate itself emits code.

## Exact Child Coverage Plan

Create new by-memory child docs without guessing UIDs. Run the scoped validator after creation so UIDs are assigned before adding UID links to parent/support docs.

Recommended metadata for new source-bearing children:

| Field | Value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `0000KN` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `0000KN` |
| formal C++ | one-line static-embed marker for the mapped IJG file |

New child docs needed:

| Proposed file slug | Exact range | IJG source file | Key current MCP proof | Exact formal marker |
| --- | --- | --- | --- | --- |
| `LibJpegErrorManager` | `0x00401000-0x004011a1` | `jerror.c` | `sub_401000` installs `off_631660`/message table and sets last message `123`; callbacks continue through `0x00401190`. | `// Static embed: third_party_embeds/libjpeg/jerror.c` |
| `LibJpegDecompressCoefficientController` | `0x00406ee0-0x004075b7` | `jdcoefct.c` | `0x00405fe0` calls `0x00406ee0`; function stores controller at decompressor `+0x184`/decimal `388`; callback xrefs include `0x00407060` and coefficient-buffer helpers. | `// Static embed: third_party_embeds/libjpeg/jdcoefct.c` |
| `LibJpegDecompressMainController` | `0x004075c0-0x00408a58` | `jdmainct.c` | `0x00405fe0` calls `0x004075c0`; function stores main controller at `+0x188`/decimal `392`, installs `sub_4076d0` and `sub_407750`, and manages sample-row buffers. | `// Static embed: third_party_embeds/libjpeg/jdmainct.c` |
| `LibJpegHuffmanDecoder` | `0x00408a60-0x004090b0` | `jdhuff.c` | `0x00405fe0` calls `0x00408a60`; function stores entropy decoder at `+0x198`/decimal `408` and installs `sub_408aa0`/`sub_408bf0`. | `// Static embed: third_party_embeds/libjpeg/jdhuff.c` |
| `LibJpegProgressiveHuffmanDecoder` | `0x004090b0-0x00409e0f` | `jdphuff.c` | `0x00405fe0` calls `0x004090b0`; function stores progressive entropy decoder at `+0x198` and allocates per-component coefficient state. | `// Static embed: third_party_embeds/libjpeg/jdphuff.c` |
| `LibJpegInverseDctManager` | `0x00409e10-0x0040a0a5` | `jddctmgr.c` | `0x00405fe0` calls `0x00409e10`; `0x00409e90` selects `jpeg_idct_islow/ifast/float` and reduced IDCT callbacks by scaled DCT size. | `// Static embed: third_party_embeds/libjpeg/jddctmgr.c` |
| `LibJpegDecompressPostController` | `0x0040a0d0-0x0040a436` | `jdpostct.c` | `0x00405fe0` calls `0x0040a0d0`; function stores post controller at decompressor `+0x18c`/decimal `396` and allocates post-processing buffers. | `// Static embed: third_party_embeds/libjpeg/jdpostct.c` |
| `LibJpegUpsampler` | `0x0040a440-0x0040abb2` | `jdsample.c` | `0x00405fe0` calls `0x0040a440`; function stores upsampler at `+0x1a0`/decimal `416`, selects fullsize/h2v1/h2v2/fancy upsample callbacks. | `// Static embed: third_party_embeds/libjpeg/jdsample.c` |
| `LibJpegColorDeconverter` | `0x0040abc0-0x0040b221` | `jdcolor.c` | `0x00405fe0` calls `0x0040abc0`; function stores color converter at `+0x1a4`/decimal `420`; `nullsub_3` at `0x0040b220` is callback data-referenced from this initializer. | `// Static embed: third_party_embeds/libjpeg/jdcolor.c` |
| `LibJpegMergedUpsampler` | `0x0040b230-0x0040b820` | `jdmerge.c` | `0x00405fe0` calls `0x0040b230`; function stores merged upsampler at `+0x1a0` and selects merged YCbCr-to-RGB paths. | `// Static embed: third_party_embeds/libjpeg/jdmerge.c` |
| `LibJpegOnePassColorQuantizer` | `0x0040b820-0x0040cc1f` | `jquant1.c` | `0x00405fe0` calls `0x0040b820`; stores color quantizer at `+0x1a8`; `0x0040cc00`/`0x0040cc10` are callback-referenced from this range. | `// Static embed: third_party_embeds/libjpeg/jquant1.c` |
| `LibJpegTwoPassColorQuantizer` | `0x0040cc20-0x0040d864` | `jquant2.c` | `0x00405fe0` calls `0x0040cc20`; stores two-pass quantizer at `+0x1a8`; `0x0040d840`/`0x0040d850` are callback-referenced from this initializer. | `// Static embed: third_party_embeds/libjpeg/jquant2.c` |
| `LibJpegCompressMainController` | `0x0040d870-0x0040d9f9` | `jcmainct.c` | `0x00406d90` calls `0x0040d870`; function stores compression main controller at `+0x140`/decimal `320`. | `// Static embed: third_party_embeds/libjpeg/jcmainct.c` |
| `LibJpegCompressCoefficientController` | `0x0040da00-0x0040e6ab` | `jccoefct.c` | `0x00406d90` calls `0x0040da00`; function stores compression coefficient controller at `+0x148`/decimal `328`. | `// Static embed: third_party_embeds/libjpeg/jccoefct.c` |
| `LibJpegHuffmanEncoder` | `0x0040e6b0-0x0040f007` | `jchuff.c` | `0x00406d90` calls `0x0040e6b0`; function stores entropy encoder at `+0x15c`/decimal `348` and installs non-progressive Huffman callbacks. | `// Static embed: third_party_embeds/libjpeg/jchuff.c` |
| `LibJpegProgressiveHuffmanEncoder` | `0x0040f010-0x0040fc15` | `jcphuff.c` | `0x00406d90` calls `0x0040f010`; function stores progressive entropy encoder at `+0x15c` and installs progressive Huffman callbacks. | `// Static embed: third_party_embeds/libjpeg/jcphuff.c` |
| `LibJpegForwardDctManager` | `0x0040fc20-0x004101e9` | `jcdctmgr.c` | `0x00406d90` calls `0x0040fc20`; function stores FDCT manager at `+0x158`/decimal `344` and selects FDCT callbacks `0x004139d0`, `0x00413dd0`, or `0x00414020` by DCT method. | `// Static embed: third_party_embeds/libjpeg/jcdctmgr.c` |
| `LibJpegCompressPrepController` | `0x004101f0-0x004107a4` | `jcprepct.c` | `0x00406d90` calls `0x004101f0`; function stores prep controller at `+0x144`/decimal `324` and selects preprocessor buffer paths. | `// Static embed: third_party_embeds/libjpeg/jcprepct.c` |
| `LibJpegDownsampler` | `0x004107b0-0x004111cf` | `jcsample.c` | `0x00406d90` calls `0x004107b0`; function stores downsampler at `+0x154`/decimal `340`; `nullsub_6` at `0x00410930` is data-referenced from this initializer. | `// Static embed: third_party_embeds/libjpeg/jcsample.c` |
| `LibJpegColorConverter` | `0x004111d0-0x00411951` | `jccolor.c` | `0x00406d90` calls `0x004111d0`; function stores compression color converter at `+0x150`/decimal `336`; `nullsub_7` at `0x00411950` is data-referenced from this initializer. | `// Static embed: third_party_embeds/libjpeg/jccolor.c` |
| `LibJpegCompressMasterController` | `0x00411960-0x004124b8` | `jcmaster.c` | `0x00406d90` calls `0x00411960`; function stores compression master at `+0x13c`/decimal `316` and runs master-selection/pass-control helpers through `0x00412440`. | `// Static embed: third_party_embeds/libjpeg/jcmaster.c` |
| `LibJpegIntegerInverseDct` | `0x004124c0-0x00412aaf` | `jidctint.c` | `0x00409e90` selects `0x004124c0` for 8x8 IDCT with DCT method `0`/`JDCT_ISLOW`. | `// Static embed: third_party_embeds/libjpeg/jidctint.c` |
| `LibJpegFastIntegerInverseDct` | `0x00412ab0-0x00412f62` | `jidctfst.c` | `0x00409e90` selects `0x00412ab0` for 8x8 IDCT with DCT method `1`/`JDCT_IFAST`. | `// Static embed: third_party_embeds/libjpeg/jidctfst.c` |
| `LibJpegFloatInverseDct` | `0x00412f70-0x004133a4` | `jidctflt.c` | `0x00409e90` selects `0x00412f70` for 8x8 IDCT with DCT method `2`/`JDCT_FLOAT`. | `// Static embed: third_party_embeds/libjpeg/jidctflt.c` |
| `LibJpegReducedInverseDct` | `0x004133b0-0x004139ce` | `jidctred.c` | `0x00409e90` selects `0x004133b0`, `0x00413760`, and `0x00413990` for scaled IDCT sizes `4`, `2`, and `1`. | `// Static embed: third_party_embeds/libjpeg/jidctred.c` |
| `LibJpegIntegerForwardDct` | `0x004139d0-0x00413dc8` | `jfdctint.c` | `0x0040fc20` selects `0x004139d0` for `JDCT_ISLOW` forward DCT. | `// Static embed: third_party_embeds/libjpeg/jfdctint.c` |
| `LibJpegFastIntegerForwardDct` | `0x00413dd0-0x00414011` | `jfdctfst.c` | `0x0040fc20` selects `0x00413dd0` for `JDCT_IFAST` forward DCT. | `// Static embed: third_party_embeds/libjpeg/jfdctfst.c` |
| `LibJpegFloatForwardDct` | `0x00414020-0x00414283` | `jfdctflt.c` | `0x0040fc20` selects `0x00414020` for `JDCT_FLOAT` forward DCT; `get_bytes` confirms `ret` at `0x00414282` and padding begins at `0x00414283`. | `// Static embed: third_party_embeds/libjpeg/jfdctflt.c` |

## Existing Child Pages To Retain

These existing children already have useful range/source evidence and should be linked from the converted parent index. If touched, add static-embed marker comments rather than source bodies.

| Existing UID | Range | Source files | Support action |
| --- | --- | --- | --- |
| [UID:0000VQ] | `0x004011b0-0x004019e3` | `jdapimin.c`, `jdapistd.c` | Keep range; optionally add two static-embed marker comment lines. |
| [UID:0000VR] | `0x00401b00-0x004038c7` | `jdmarker.c` | Keep range; optionally add one marker. |
| [UID:0000VS] | `0x00403920-0x004048e2` | `jcapimin.c`, `jcapistd.c`, `jcparam.c`, `jdatadst.c` | Keep range; optionally add markers. Do not duplicate source bodies. |
| [UID:0000VT] | `0x004048f0-0x004049bb` | `jcapistd.c` | Keep range; optionally add marker. |
| [UID:0000VU] | `0x004049c0-0x00404a5c` | `jcomapi.c` | Keep range; optionally add marker. |
| [UID:0000VV] | `0x00404a60-0x0040505b` | `jdinput.c` | Keep range; optionally add marker. |
| [UID:0000VW] | `0x00405060-0x00405c77` | `jmemmgr.c` | Keep range; optionally add marker. |
| [UID:0000VX] | `0x00405c80-0x004063c8` | `jdmaster.c` | Keep range; optionally add marker. |
| [UID:0000VY] | `0x004063d0-0x0040649b` | `jutils.c` | Keep range; optionally add marker. |
| [UID:0000VZ] | `0x004064a0-0x00406d8c` | `jcmarker.c` | Keep range; optionally add marker. |
| [UID:0000W0] | `0x00406d90-0x00406e46` | `jcinit.c` | Keep range; optionally add marker. |
| [UID:0000W1] | `0x00406e50-0x00406ed1` | `jmemnobs.c` | Keep range and include `0x00406ed0` null/no-op cleanup. |

`jctrans.c`, `jdtrans.c`, and stock `jdatasrc.c` do not need new child pages in this implementation pass. Current evidence still supports the existing caveat that NexusTK uses a local in-memory source helper outside the libjpeg island for active product decode paths; no direct `jpeg_stdio_src` product route was found in the target pages reviewed for this report.

## Padding And Non-Libjpeg Boundaries

The parent index should explicitly record padding/gap spans instead of leaving them as source blockers. IDA function inventory and tail byte reads support the following important boundaries:

| Boundary/gap | Interpretation |
| --- | --- |
| `0x004011a1-0x004011b0` | padding between `jerror.c` and public decompression API. |
| `0x004019e3-0x00401b00` | no modeled function before `jdmarker.c`. |
| `0x004038c7-0x00403920` | no modeled function before compression API front end. |
| `0x00406ed1-0x00406ee0` | padding after `jmemnobs.c` before `jdcoefct.c`. |
| `0x0040a0a5-0x0040a0d0` | alignment between `jddctmgr.c` and `jdpostct.c`. |
| `0x0040b221-0x0040b230` | alignment after `jdcolor.c` null callback before `jdmerge.c`. |
| `0x0040cc1f-0x0040cc20` | immediate boundary from `jquant1.c` to `jquant2.c`. |
| `0x00411951-0x00411960` | alignment after `jccolor.c` null callback before `jcmaster.c`. |
| `0x00414283-0x00414290` | `0x90` padding after `jfdctflt.c`; `_AIL_shutdown@0` begins at `0x00414290` and is not libjpeg. |
| `0x004142c0` | zlib successor start, already documented by [UID:0000W3]. |

Implementation can include the remaining small alignment gaps from the child table in the parent "padding notes" table; no separate padding child docs are required unless the supervisor wants exhaustive gap pages.

## Rejected Alternatives

- Keep [UID:0000VP] as `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:0000KN`: rejected because the page is an overlap aggregate and would duplicate child/source-file ownership.
- Paste Hex-Rays C++ or upstream C bodies into the parent: rejected because the official static embed is the source of record and the parent is not a source unit.
- Treat the high `0x00406ed1-0x00414283` leaf as unresolved entropy/DCT work: rejected by current MCP initializer/xref evidence and staged IJG source comparison.
- Assign high-range helpers to image loaders, screenshot capture, render, or DAT code: rejected. Product modules call public libjpeg APIs; IJG internals remain with [UID:0000KN].
- Include `_AIL_shutdown@0` at `0x00414290` or the atexit glue at `0x004142a0`: rejected by live byte/function evidence and existing zlib/Miles boundary docs.
- Revive the old `0x00469640-0x00470dc9` LibJPEG hypothesis: rejected by existing IDA evidence showing BrowserWindow/WebBrowser COM code.

## Support Doc Update Plan

Recommended implementation edits after supervisor approval:

- Update [UID:0000VP] target page:
  - Change metadata to the recommended non-emitting split/index values above.
  - Replace stale Wave2/Wave3/open-helper language with current MCP evidence.
  - Add the exact child coverage table, existing child links, and padding/boundary notes.
  - Keep formal C++ blank.
- Create the new child by-memory docs listed above. Do not guess UIDs; validate first and then add UID links.
- Update [UID:0000KN][LibJPEG](../../../../../by-file/LibJPEG.md):
  - Replace "remaining lower-helper mapping" with the exact child/source-file map from this report.
  - Keep `third_party/libjpeg/` as the reconstruction owner.
  - Preserve `jmemnobs.c` and `jdatasrc.c` caveats.
- Update [UID:0001QE][client_libraries](../../../../../by-meta/client_libraries.md):
  - Add the new source-file children and parent non-emitting index decision.
  - Keep product decode/screenshot wrappers as consumers only.
- Update [UID:0001QY][static_embeds README](../../../../../by-meta/obtained_thirdparty_files/static_embeds/README.md) only if needed:
  - Current static embed provenance is already sufficient; likely no edit needed.
- Update [UID:0001R1][proposed-source-tree](../../../../../by-project-structure/proposed-source-tree.md):
  - Replace "remaining work is mostly entropy/coefficient/color/sampling/quantizer/DCT/IDCT lower-helper mapping" with the exact resolved source-file map.
- Do not edit [UID:0000W3], [UID:0003OI], [UID:00028D], or [UID:0001G8] unless adding a short back-link is explicitly requested; they already contain same-or-greater boundary proof.

## Implementation Tracking Checklist

- [x] Create child docs for all new ranges in the Exact Child Coverage Plan without assigning UIDs manually.
  - Proof: created 28 child files with no handwritten UID line; validator assigned [UID:00045M]-[UID:00046D].
  - Assigned UID/path map:
    - [UID:00045M] `by-memory/0x00401000-0x004011a1.LibJpegErrorManager.md`
    - [UID:00045N] `by-memory/0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController.md`
    - [UID:00045O] `by-memory/0x004075c0-0x00408a58.LibJpegDecompressMainController.md`
    - [UID:00045P] `by-memory/0x00408a60-0x004090b0.LibJpegHuffmanDecoder.md`
    - [UID:00045Q] `by-memory/0x004090b0-0x00409e0f.LibJpegProgressiveHuffmanDecoder.md`
    - [UID:00045R] `by-memory/0x00409e10-0x0040a0a5.LibJpegInverseDctManager.md`
    - [UID:00045S] `by-memory/0x0040a0d0-0x0040a436.LibJpegDecompressPostController.md`
    - [UID:00045T] `by-memory/0x0040a440-0x0040abb2.LibJpegUpsampler.md`
    - [UID:00045U] `by-memory/0x0040abc0-0x0040b221.LibJpegColorDeconverter.md`
    - [UID:00045V] `by-memory/0x0040b230-0x0040b820.LibJpegMergedUpsampler.md`
    - [UID:00045W] `by-memory/0x0040b820-0x0040cc1f.LibJpegOnePassColorQuantizer.md`
    - [UID:00045X] `by-memory/0x0040cc20-0x0040d864.LibJpegTwoPassColorQuantizer.md`
    - [UID:00045Y] `by-memory/0x0040d870-0x0040d9f9.LibJpegCompressMainController.md`
    - [UID:00045Z] `by-memory/0x0040da00-0x0040e6ab.LibJpegCompressCoefficientController.md`
    - [UID:000460] `by-memory/0x0040e6b0-0x0040f007.LibJpegHuffmanEncoder.md`
    - [UID:000461] `by-memory/0x0040f010-0x0040fc15.LibJpegProgressiveHuffmanEncoder.md`
    - [UID:000462] `by-memory/0x0040fc20-0x004101e9.LibJpegForwardDctManager.md`
    - [UID:000463] `by-memory/0x004101f0-0x004107a4.LibJpegCompressPrepController.md`
    - [UID:000464] `by-memory/0x004107b0-0x004111cf.LibJpegDownsampler.md`
    - [UID:000465] `by-memory/0x004111d0-0x00411951.LibJpegColorConverter.md`
    - [UID:000466] `by-memory/0x00411960-0x004124b8.LibJpegCompressMasterController.md`
    - [UID:000467] `by-memory/0x004124c0-0x00412aaf.LibJpegIntegerInverseDct.md`
    - [UID:000468] `by-memory/0x00412ab0-0x00412f62.LibJpegFastIntegerInverseDct.md`
    - [UID:000469] `by-memory/0x00412f70-0x004133a4.LibJpegFloatInverseDct.md`
    - [UID:00046A] `by-memory/0x004133b0-0x004139ce.LibJpegReducedInverseDct.md`
    - [UID:00046B] `by-memory/0x004139d0-0x00413dc8.LibJpegIntegerForwardDct.md`
    - [UID:00046C] `by-memory/0x00413dd0-0x00414011.LibJpegFastIntegerForwardDct.md`
    - [UID:00046D] `by-memory/0x00414020-0x00414283.LibJpegFloatForwardDct.md`
- [x] Run scoped validator from `source-3/project-documentation` so new child UIDs are assigned.
  - Proof: child validators all exited `0`, scanned `1` file each, and reported `generated_refresh: deferred`.
  - Command IDs/timestamps: `000000003296` at `2026-06-26T20:30:38-04:00` for [UID:00045M]; `000000003297`-`000000003325` at `2026-06-26T20:31:15-04:00` through `2026-06-26T20:33:16-04:00` for [UID:00045N]-[UID:00046D].
- [x] Update [UID:0000VP] metadata to `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
  - Proof: applied in `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`; validator `000000003435` at `2026-06-26T20:44:02-04:00`, exit `0`, scanned `1`, reported completion/confidence updates and `generated_refresh: deferred`.
- [x] Update [UID:0000VP] body to a non-emitting split/index with the exact child links, source-file map, padding notes, MCP evidence, third-party source placement, and rejected alternatives.
  - Proof: parent now includes B001 MCP evidence table, exact child map with [UID:00045M]-[UID:00046D] plus existing [UID:0000VQ]-[UID:0000W1], padding/boundary notes, static-embed/no-code proof, rejected alternatives, and preserved B007/B010 caveats.
- [x] Add static-embed marker formal blocks to new source-bearing child docs exactly as listed in the child table.
  - Proof: every new child formal block contains only `// Static embed: third_party_embeds/libjpeg/<source-file>.c` for its accepted source file; child validators `000000003296`-`000000003325` exited `0`.
- [x] Update [UID:0000KN] LibJPEG with exact source-file coverage and remove stale "remaining lower-helper mapping" blocker language.
  - Proof: `by-file/LibJPEG.md` now records the non-emitting parent decision, the 28 new child/source rows, B007/B010 caveats, product-wrapper boundary, and score `92/92`; validator `000000003436` at `2026-06-26T20:44:12-04:00`, exit `0`, scanned `1`, `generated_refresh: deferred`.
- [x] Update [UID:0001QE] client_libraries IJG libjpeg section with the parent index decision and new child/source map.
  - Proof: `by-meta/client_libraries.md` now records [UID:0000VP] as non-emitting and lists the [UID:00045M]-[UID:00046D] child/source map; validator `000000003437` at `2026-06-26T20:44:14-04:00`, exit `0`, scanned `1`, `generated_refresh: deferred`.
- [x] Update [UID:0001R1] proposed-source-tree `third_party/libjpeg/` section with the resolved source-file map.
  - Proof: `by-project-structure/proposed-source-tree.md` now expands the `third_party/libjpeg/` file list and replaces the lower-helper-mapping rebuild note with the resolved source map; validator `000000003438` at `2026-06-26T20:44:16-04:00`, exit `0`, scanned `1`, `generated_refresh: deferred`.
- [x] Record same-or-greater-detail no-edit proof for [UID:0000W3], [UID:0003OI], [UID:00028D], [UID:0001G8], and static-embed provenance docs if not touched.
  - Proof: no edits were made to [UID:0000W3] `ZlibCore`, [UID:0003OI] message table, [UID:00028D] data strings, [UID:0001G8] screenshot capture path, or [UID:0001QY] static-embed provenance. Parent/support docs link or cite those already sufficient docs as boundary/provenance proof.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`.
  - Proof: new child validators `000000003296`-`000000003325` passed; changed support validators `000000003435`-`000000003438` passed, all exit `0`, scanned `1`, and reported `generated_refresh: deferred`.
- [x] Keep all coverage reports, generated/project-level files, validator/tool state, IDA DB files, and manual `-coverage-report.md` files untouched.
  - Proof: no manual edits were made to coverage reports, generated files, validator/tool state, IDA DB, or manual `-coverage-report.md` files. Required scoped validator runs reported normal validator-owned `projected_stats_update` side effects and deferred generated-refresh metadata; B001 did not hand-edit generated/project-level reports or tool state.
- [x] Final clean revalidation/lease-free finish checkpoint.
  - Proof: after the earlier B009 lease conflict expired, B001 rechecked MCP and lease state, then took a short validator-only lease on `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, `by-file/LibJPEG.md`, `by-meta/client_libraries.md`, and `by-project-structure/proposed-source-tree.md`.
  - MCP proof: JSON-RPC `idb_list` returned active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health(database=80de0a67)` returned `status:"ok"`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready at `2026-06-26T22:07:44-04:00`.
  - Final validators: `000000003536` at `2026-06-26T22:08:42-04:00` for `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`; `000000003537` at `2026-06-26T22:08:44-04:00` for `by-file/LibJPEG.md`; `000000003538` at `2026-06-26T22:08:46-04:00` for `by-meta/client_libraries.md`; `000000003539` at `2026-06-26T22:08:56-04:00` for `by-project-structure/proposed-source-tree.md`. All exited `0`, scanned `1`, reported `ok: 1`, and had `generated_refresh: deferred`; known pre-existing missing-reference diagnostics remain unrelated to this libjpeg callback.
  - Lease proof: `python .\leaser.py B001 lease ...` succeeded for all four final validator files; `python .\leaser.py B001 unlease ...` succeeded for all four; `python .\leaser.py B001 unlease` then returned `B001: No active leases`. A later shared lease report showed B006/B007 had acquired new libjpeg leases after B001's release, but no B001 lease remained active.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000VP-LibJpeg6bCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0000VP-LibJpeg6bCore-source-quality.md","timestamp":"2026-06-26T22:11:33","uid":"0000VP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
