*** UID:0000KW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/third_party/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LodePNG

## Status

- Confidence: very strong for exact LodePNG commit/version identity, complete source and binary inventory, ownership, compiler/data boundaries, and the sole formal source-pair route; optimizer-level address/name correspondence remains the only confidence ceiling.
- Exact source authority: upstream commit `c6cf08b8910d91b0830666c07845116df1e9b6fc`, version `20160501`.
- Semantic owner and placement: this FILE owner at `NexusTK/third_party/`.
- Formal source route: one aggregate compilation-unit directive, mechanically hosted by [UID:00007E][LodePNGState](by-class/LodePNGState.md), imports exactly `third_party_embeds/lodepng/lodepng.cpp` and `third_party_embeds/lodepng/lodepng.h`; its multiline CPP and H blocks are blank. This is not a class-only or per-child import. Every function/data/type child is covered by that single aggregate pair and either emits one compiler-covered comment or remains a non-emitting index.
- Complete scope: 228 physical/226 default-active source definitions, 12 public and seven internal types, 16 named source data definitions, 116 modeled functions, 55 raw standalone starts, two compiler tail chunks, seven compiler flow tables, and 120 semantic binary data/compiler identities.
- Dated pre-callback generated evidence showed four complete imports plus one empty UID0003AP marker. That symptom is historical evidence only. Exact generated command/hash identities in Changes are dated snapshots rather than permanent authority; every later gate must physically reread the then-current generated header, hash, import blocks, contributor semantics, and absent sibling H.

## File Role

This is bundled LodePNG codec support, not NexusTK feature code. The functions around `0x00443c80` are now matched to stock LodePNG public APIs: `lodepng_encode_memory`, `lodepng_encode_file`, and `lodepng_encode32_file`.

The exact project-facing user is [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md), emitted through [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md). Its direct call at `0x0055817b` invokes stock `lodepng_encode32_file` after ACP conversion of the generated wide path and RGBA expansion of the captured DirectDraw surface. No NexusTK-local wrapper exists at that call site. The larger anonymous `sub_44xxxx`/`sub_45xxxx` helper cluster belongs with LodePNG until proven otherwise.

## Proposed Contents

Source-level function inventory is exhaustive. Every named item below is defined in the staged `lodepng.cpp`; all are covered collectively by the one aggregate source-pair import, and no item requests its own import/body/H fragment. Physical definitions 76-77 are the custom-zlib fallback pair and are inactive when the default built-in zlib pair 73/75 is active.

| Claim | Physical ordinals | Source family | Exact definitions |
| --- | --- | --- | --- |
| C002 | 1-26 | Common allocation, vector, string, endian, and disk helpers | lodepng_malloc, lodepng_realloc, lodepng_free, uivector_cleanup, uivector_reserve, uivector_resize, uivector_resizev, uivector_init, uivector_push_back, ucvector_reserve, ucvector_resize, ucvector_cleanup, ucvector_init, ucvector_init_buffer, ucvector_push_back, string_resize, string_init, string_cleanup, string_set, lodepng_read32bitInt, lodepng_set32bitInt, lodepng_add32bitInt, lodepng_filesize, lodepng_buffer_file, lodepng_load_file, lodepng_save_file |
| C003 | 27-79 | Huffman, inflate, deflate, zlib, and settings helpers | addBitsToStream, addBitsToStreamReversed, readBitFromStream, readBitsFromStream, HuffmanTree_draw, HuffmanTree_init, HuffmanTree_cleanup, HuffmanTree_make2DTree, HuffmanTree_makeFromLengths2, HuffmanTree_makeFromLengths, bpmnode_create, bpmnode_sort, boundaryPM, lodepng_huffman_code_lengths, HuffmanTree_makeFromFrequencies, HuffmanTree_getCode, HuffmanTree_getLength, generateFixedLitLenTree, generateFixedDistanceTree, huffmanDecodeSymbol, getTreeInflateFixed, getTreeInflateDynamic, inflateHuffmanBlock, inflateNoCompression, lodepng_inflatev, lodepng_inflate, inflate, addHuffmanSymbol, searchCodeIndex, addLengthDistance, hash_init, hash_cleanup, getHash, countZeros, updateHashChain, encodeLZ77, deflateNoCompression, writeLZ77data, deflateDynamic, deflateFixed, lodepng_deflatev, lodepng_deflate, deflate, update_adler32, adler32, lodepng_zlib_decompress, zlib_decompress [built-in], lodepng_zlib_compress, zlib_compress [built-in], zlib_decompress [custom fallback], zlib_compress [custom fallback], lodepng_compress_settings_init, lodepng_decompress_settings_init |
| C004 | 80-98 | CRC and PNG chunk helpers | lodepng_crc32, readBitFromReversedStream, readBitsFromReversedStream, setBitOfReversedStream0, setBitOfReversedStream, lodepng_chunk_length, lodepng_chunk_type, lodepng_chunk_type_equals, lodepng_chunk_ancillary, lodepng_chunk_private, lodepng_chunk_safetocopy, lodepng_chunk_data, lodepng_chunk_data_const, lodepng_chunk_check_crc, lodepng_chunk_generate_crc, lodepng_chunk_next, lodepng_chunk_next_const, lodepng_chunk_append, lodepng_chunk_create |
| C005 | 99-149 | Color mode, metadata, conversion, and profiling helpers | getNumColorChannels, lodepng_get_bpp_lct, lodepng_color_mode_init, lodepng_color_mode_cleanup, lodepng_color_mode_copy, lodepng_color_mode_equal, lodepng_palette_clear, lodepng_palette_add, lodepng_get_bpp, lodepng_get_channels, lodepng_is_greyscale_type, lodepng_is_alpha_type, lodepng_is_palette_type, lodepng_has_palette_alpha, lodepng_can_have_alpha, lodepng_get_raw_size, lodepng_get_raw_size_lct, lodepng_get_raw_size_idat, LodePNGUnknownChunks_init, LodePNGUnknownChunks_cleanup, LodePNGUnknownChunks_copy, LodePNGText_init, LodePNGText_cleanup, LodePNGText_copy, lodepng_clear_text, lodepng_add_text, LodePNGIText_init, LodePNGIText_cleanup, LodePNGIText_copy, lodepng_clear_itext, lodepng_add_itext, lodepng_info_init, lodepng_info_cleanup, lodepng_info_copy, lodepng_info_swap, addColorBits, color_tree_init, color_tree_cleanup, color_tree_get, color_tree_has, color_tree_add, rgba8ToPixel, rgba16ToPixel, getPixelColorRGBA8, getPixelColorsRGBA8, getPixelColorRGBA16, lodepng_convert, lodepng_color_profile_init, getValueRequiredBits, lodepng_get_color_profile, lodepng_auto_choose_color |
| C006 | 150-177 | Filter, Adam7, decode, and state helpers | paethPredictor, Adam7_getpassvalues, lodepng_inspect, unfilterScanline, unfilter, Adam7_deinterlace, removePaddingBits, postProcessScanlines, readChunk_PLTE, readChunk_tRNS, readChunk_bKGD, readChunk_tEXt, readChunk_zTXt, readChunk_iTXt, readChunk_tIME, readChunk_pHYs, decodeGeneric, lodepng_decode, lodepng_decode_memory, lodepng_decode32, lodepng_decode24, lodepng_decode_file, lodepng_decode32_file, lodepng_decode24_file, lodepng_decoder_settings_init, lodepng_state_init, lodepng_state_cleanup, lodepng_state_copy |
| C007 | 178-207 | PNG construction, filter, encode, and error helpers | addChunk, writeSignature, addChunk_IHDR, addChunk_PLTE, addChunk_tRNS, addChunk_IDAT, addChunk_IEND, addChunk_tEXt, addChunk_zTXt, addChunk_iTXt, addChunk_bKGD, addChunk_tIME, addChunk_pHYs, filterScanline, flog2, filter, addPaddingBits, Adam7_interlace, preProcessScanlines, getPaletteTranslucency, addUnknownChunks, lodepng_encode, lodepng_encode_memory, lodepng_encode32, lodepng_encode24, lodepng_encode_file, lodepng_encode32_file, lodepng_encode24_file, lodepng_encoder_settings_init, lodepng_error_text |
| C008 | 208-228 | C++ wrapper overloads and State lifecycle | lodepng::load_file(vector&, string const&); lodepng::save_file(vector const&, string const&); decompress(vector&, byte pointer, size, DecompressSettings const&); decompress(vector&, vector const&, DecompressSettings const&); compress(vector&, byte pointer, size, CompressSettings const&); compress(vector&, vector const&, CompressSettings const&); State::State(); State::State(State const&); State::~State(); State::operator=(State const&); decode(vector&, w&, h&, byte pointer, size, color, depth); decode(vector&, w&, h&, vector const&, color, depth); decode(vector&, w&, h&, State&, byte pointer, size); decode(vector&, w&, h&, State&, vector const&); decode(vector&, w&, h&, string const&, color, depth); encode(vector&, byte pointer, w, h, color, depth); encode(vector&, vector const&, w, h, color, depth); encode(vector&, byte pointer, w, h, State&); encode(vector&, vector const&, w, h, State&); encode(string const&, byte pointer, w, h, color, depth); encode(string const&, vector const&, w, h, color, depth) |

The 228 physical definitions reduce to 226 active default definitions. No definition is omitted from the names above.

Public type inventory:

| Claim | Kind | Exact source identities | CPP/H disposition |
| --- | --- | --- | --- |
| C009 | enums | LodePNGColorType; LodePNGFilterStrategy | Imported header; no handwritten H fragment |
| C009 | C structs | LodePNGDecompressSettings; LodePNGCompressSettings; LodePNGColorMode; LodePNGTime; LodePNGInfo; LodePNGDecoderSettings; LodePNGColorProfile; LodePNGEncoderSettings; LodePNGState | Imported header; no handwritten H fragment |
| C009 | C++ class | lodepng::State : public LodePNGState | Imported header/source; compiler generates vtable/RTTI/destructor glue |
| C010 | internal structs | uivector; ucvector; HuffmanTree; BPMNode; BPMLists; Hash; ColorTree | Imported implementation; no public H fragment |

Named source data inventory:

| Claim | Count | Exact definitions | Binary disposition |
| --- | ---: | --- | --- |
| C011 | 1 | LODEPNG_VERSION_STRING | literal at 0x60F4C0; pointer at 0x66D000 |
| C011 | 5 | LENGTHBASE, LENGTHEXTRA, DISTANCEBASE, DISTANCEEXTRA, CLCL_ORDER | 0x60F228-0x60F46C with alignment/tail pooling |
| C011 | 3 | MAX_SUPPORTED_DEFLATE_LENGTH, HASH_NUM_VALUES, HASH_BIT_MASK | compiler immediates; no required standalone data |
| C011 | 2 | lodepng_default_compress_settings, lodepng_default_decompress_settings | compression default storage at 0x60F200; zero defaults may be folded |
| C011 | 1 | lodepng_crc32_table[256] | 0x66D008-0x66D408 |
| C011 | 4 | ADAM7_IX, ADAM7_IY, ADAM7_DX, ADAM7_DY | 0x60F38C and 0x60F46C-0x60F4C0; IX shares a zero tail |

Modeled binary function inventory. `Callers` and `Callees` are dated IDA profile counts, and every row is collectively covered by the aggregate source-pair route; no row gets a per-child import or separate CPP/H body.

| # | Address | Current name | Size | Insns | BB | Callers | Callees | Disposition | Claim |
| ---: | --- | --- | ---: | ---: | ---: | ---: | ---: | --- | --- |
| 1 | 0x443a60 | sub_443A60 | 0xe0 | 77 | 7 | 5 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 2 | 0x443b40 | sub_443B40 | 0x20 | 13 | 1 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 3 | 0x443b80 | sub_443B80 | 0xb7 | 82 | 8 | 1 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 4 | 0x443c40 | sub_443C40 | 0x1d | 12 | 1 | 0 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 5 | 0x443c80 | sub_443C80 | 0xe1 | 77 | 7 | 3 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 6 | 0x443db0 | sub_443DB0 | 0x82 | 51 | 5 | 1 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 7 | 0x443e40 | sub_443E40 | 0x1d | 12 | 1 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 8 | 0x443e80 | sub_443E80 | 0x15a | 131 | 12 | 0 | 9 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 9 | 0x443fe0 | sub_443FE0 | 0x168 | 138 | 12 | 0 | 10 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 10 | 0x444150 | sub_444150 | 0x22a | 219 | 33 | 0 | 15 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 11 | 0x444480 | sub_444480 | 0x125 | 146 | 25 | 0 | 12 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 12 | 0x4445b0 | sub_4445B0 | 0x183 | 182 | 27 | 0 | 13 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 13 | 0x444be0 | sub_444BE0 | 0x8d | 53 | 10 | 4 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 14 | 0x444e70 | sub_444E70 | 0xdd | 35 | 1 | 4 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 15 | 0x444f50 | sub_444F50 | 0x56 | 30 | 5 | 10 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 16 | 0x444fb0 | sub_444FB0 | 0x13a | 104 | 16 | 2 | 7 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 17 | 0x4450f0 | sub_4450F0 | 0x5 | 1 | 2 | 0 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 18 | 0x445100 | sub_445100 | 0xe6 | 81 | 8 | 1 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 19 | 0x4451f0 | sub_4451F0 | 0x5 | 1 | 2 | 0 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 20 | 0x445200 | sub_445200 | 0x165 | 122 | 6 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 21 | 0x445370 | sub_445370 | 0x306 | 284 | 43 | 2 | 10 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 22 | 0x445700 | sub_445700 | 0x5ed | 486 | 130 | 1 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 23 | 0x445cf0 | sub_445CF0 | 0x379 | 227 | 45 | 1 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 24 | 0x4460f0 | sub_4460F0 | 0x106 | 44 | 1 | 5 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 25 | 0x446240 | sub_446240 | 0x10a | 72 | 5 | 0 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 26 | 0x446350 | sub_446350 | 0x119 | 105 | 16 | 1 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 27 | 0x446470 | sub_446470 | 0x23e | 183 | 34 | 1 | 7 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 28 | 0x4466b0 | sub_4466B0 | 0x93b | 661 | 125 | 1 | 26 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 29 | 0x446ff0 | sub_446FF0 | 0x26 | 15 | 1 | 1 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 30 | 0x447050 | sub_447050 | 0x5a | 39 | 9 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 31 | 0x4470e0 | _get_srw_lock | 0xb | 6 | 1 | 0 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 32 | 0x4470f0 | _get_srw_lock_0 | 0xb | 6 | 1 | 0 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 33 | 0x447260 | sub_447260 | 0x8f | 66 | 9 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 34 | 0x4472f0 | sub_4472F0 | 0x13e | 124 | 14 | 8 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 35 | 0x4475d0 | sub_4475D0 | 0x1f7 | 192 | 39 | 4 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 36 | 0x4477d0 | sub_4477D0 | 0x371 | 327 | 54 | 1 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 37 | 0x4481c0 | sub_4481C0 | 0x26 | 15 | 1 | 2 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 38 | 0x448270 | sub_448270 | 0x188 | 164 | 17 | 5 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 39 | 0x448400 | sub_448400 | 0xcc | 90 | 12 | 1 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 40 | 0x448520 | sub_448520 | 0x7 | 2 | 1 | 0 | 0 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C012 |
| 41 | 0x448530 | sub_448530 | 0x27 | 15 | 3 | 0 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 42 | 0x448560 | sub_448560 | 0x5a | 28 | 5 | 0 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 43 | 0x4485c0 | sub_4485C0 | 0x2f7 | 202 | 29 | 1 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 44 | 0x4488c0 | sub_4488C0 | 0x10f | 99 | 11 | 4 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 45 | 0x4489d0 | sub_4489D0 | 0x2c6 | 197 | 30 | 1 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 46 | 0x448ca0 | sub_448CA0 | 0x161 | 133 | 25 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 47 | 0x448e10 | sub_448E10 | 0x8f | 58 | 9 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 48 | 0x448ea0 | sub_448EA0 | 0x136 | 120 | 21 | 3 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 49 | 0x448fe0 | sub_448FE0 | 0x17f | 143 | 26 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 50 | 0x449160 | sub_449160 | 0xa8 | 51 | 5 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 51 | 0x449210 | sub_449210 | 0x22d | 175 | 17 | 1 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 52 | 0x449440 | sub_449440 | 0x74 | 39 | 5 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 53 | 0x4494c0 | sub_4494C0 | 0x1ab | 151 | 24 | 1 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 54 | 0x449670 | sub_449670 | 0x54 | 34 | 7 | 2 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 55 | 0x4496d0 | sub_4496D0 | 0x9e | 66 | 14 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 56 | 0x449770 | sub_449770 | 0x1ae | 168 | 38 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 57 | 0x449920 | sub_449920 | 0xc5 | 83 | 14 | 1 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 58 | 0x4499f0 | sub_4499F0 | 0x15f | 132 | 20 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 59 | 0x449b50 | sub_449B50 | 0x43c | 421 | 104 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 60 | 0x449f90 | sub_449F90 | 0x165 | 147 | 33 | 1 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 61 | 0x44a100 | sub_44A100 | 0x1a0 | 163 | 29 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 62 | 0x44a2a0 | sub_44A2A0 | 0x21c | 212 | 49 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 63 | 0x44a4c0 | sub_44A4C0 | 0x5b | 44 | 6 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 64 | 0x44a520 | sub_44A520 | 0xa6 | 70 | 15 | 3 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 65 | 0x44a5d0 | sub_44A5D0 | 0xbc | 76 | 16 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 66 | 0x44a690 | sub_44A690 | 0x5d | 41 | 6 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 67 | 0x44a6f0 | sub_44A6F0 | 0xc5 | 71 | 11 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 68 | 0x44a7c0 | sub_44A7C0 | 0x106 | 98 | 12 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 69 | 0x44a8d0 | sub_44A8D0 | 0xdd | 79 | 21 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 70 | 0x44a9b0 | sub_44A9B0 | 0x5a | 36 | 16 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 71 | 0x44aa30 | sub_44AA30 | 0xa3 | 61 | 5 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 72 | 0x44aae0 | sub_44AAE0 | 0x32 | 22 | 5 | 3 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 73 | 0x44ab20 | sub_44AB20 | 0x77 | 53 | 6 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 74 | 0x44aba0 | sub_44ABA0 | 0x2f | 22 | 4 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 75 | 0x44abd0 | sub_44ABD0 | 0x1060 | 1100 | 208 | 1 | 18 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 76 | 0x44bc50 | sub_44BC50 | 0xaf7 | 938 | 178 | 1 | 11 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 77 | 0x44c750 | sub_44C750 | 0x24d | 210 | 37 | 1 | 8 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 78 | 0x44c9a0 | sub_44C9A0 | 0x23e | 225 | 51 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 79 | 0x44cbe0 | sub_44CBE0 | 0x4f6 | 444 | 91 | 2 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 80 | 0x44d0e0 | sub_44D0E0 | 0x7e1 | 555 | 98 | 1 | 7 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C013 |
| 81 | 0x44d8d0 | sub_44D8D0 | 0x4c8 | 451 | 81 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 82 | 0x44ddb0 | sub_44DDB0 | 0xac | 61 | 7 | 2 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 83 | 0x44de60 | sub_44DE60 | 0x12b | 75 | 7 | 2 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 84 | 0x44df90 | sub_44DF90 | 0x68 | 50 | 8 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 85 | 0x44e000 | sub_44E000 | 0x1bd | 151 | 16 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 86 | 0x44e1c0 | sub_44E1C0 | 0x2de | 272 | 39 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 87 | 0x44e4a0 | sub_44E4A0 | 0x470 | 422 | 100 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 88 | 0x44e910 | sub_44E910 | 0x52d | 461 | 87 | 1 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 89 | 0x44ee40 | sub_44EE40 | 0x51 | 39 | 6 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 90 | 0x44eea0 | sub_44EEA0 | 0x2c5 | 233 | 44 | 1 | 10 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 91 | 0x44f170 | sub_44F170 | 0x68 | 47 | 9 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 92 | 0x44f1e0 | sub_44F1E0 | 0x47 | 31 | 4 | 1 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 93 | 0x44f230 | sub_44F230 | 0x72 | 53 | 14 | 3 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 94 | 0x44f2b0 | sub_44F2B0 | 0x227 | 199 | 33 | 1 | 6 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 95 | 0x44f4e0 | sub_44F4E0 | 0x5e | 39 | 5 | 2 | 5 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 96 | 0x44f540 | sub_44F540 | 0x46 | 26 | 7 | 11 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 97 | 0x44f5b0 | sub_44F5B0 | 0x1bf | 179 | 31 | 1 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 98 | 0x44f770 | sub_44F770 | 0x35a | 262 | 25 | 1 | 9 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 99 | 0x44fad0 | sub_44FAD0 | 0x47 | 34 | 5 | 2 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 100 | 0x44fb20 | sub_44FB20 | 0x46 | 34 | 5 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 101 | 0x44fb70 | sub_44FB70 | 0x259 | 215 | 44 | 1 | 7 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 102 | 0x44fdd0 | sub_44FDD0 | 0x8b | 61 | 12 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 103 | 0x44fe60 | sub_44FE60 | 0x1ce | 201 | 26 | 1 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 104 | 0x450030 | sub_450030 | 0x4c | 35 | 13 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 105 | 0x450080 | sub_450080 | 0x25 | 16 | 3 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 106 | 0x4500b0 | sub_4500B0 | 0x52 | 39 | 7 | 3 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 107 | 0x450110 | sub_450110 | 0x54 | 42 | 8 | 5 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 108 | 0x450170 | sub_450170 | 0x4a | 38 | 8 | 3 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 109 | 0x4501c0 | sub_4501C0 | 0x62 | 45 | 8 | 2 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 110 | 0x450230 | sub_450230 | 0x4d | 37 | 7 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 111 | 0x450280 | sub_450280 | 0xc7 | 86 | 18 | 3 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 112 | 0x450350 | sub_450350 | 0x6d | 51 | 6 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 113 | 0x4503c0 | sub_4503C0 | 0x4d6 | 466 | 82 | 1 | 1 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 114 | 0x4508b0 | sub_4508B0 | 0xd4 | 70 | 7 | 2 | 3 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 115 | 0x450990 | sub_450990 | 0x1ce | 195 | 57 | 1 | 2 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |
| 116 | 0x450b60 | sub_450B60 | 0x13f | 144 | 20 | 2 | 4 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C014 |

Standalone raw binary function-shaped starts. Live lookup reports `Not a function`, all four comment fields are absent, and incoming xref queries return zero because IDA has not established function boundaries. Each row remains source-covered even where optimization prevents a unique symbol name.

| # | Address | Current state | Best source-facing identity/role | Ownership and CPP/H disposition | Claim |
| ---: | --- | --- | --- | --- | --- |
| 1 | 0x443b60 | Not a function; type absent; comments absent | lodepng_decode24 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 2 | 0x443c60 | Not a function; type absent; comments absent | lodepng_decode24_file | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 3 | 0x443d70 | Not a function; type absent; comments absent | lodepng_encode32 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 4 | 0x443d90 | Not a function; type absent; comments absent | lodepng_encode24 | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 5 | 0x443e60 | Not a function; type absent; comments absent | lodepng_encode24_file | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 6 | 0x444380 | Not a function; type absent; comments absent | C++ wrapper/helper body; exact overload folded | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 7 | 0x4443e0 | Not a function; type absent; comments absent | C++ wrapper/helper body; exact overload folded | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 8 | 0x444740 | Not a function; type absent; comments absent | lodepng_error_text | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 9 | 0x444af0 | Not a function; type absent; comments absent | lodepng_decompress_settings_init | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 10 | 0x444b20 | Not a function; type absent; comments absent | lodepng_compress_settings_init | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 11 | 0x444b70 | Not a function; type absent; comments absent | lodepng_color_mode_init | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 12 | 0x444bb0 | Not a function; type absent; comments absent | lodepng_palette_clear | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 13 | 0x444c70 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 14 | 0x444ca0 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 15 | 0x444d10 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 16 | 0x444d30 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 17 | 0x444d80 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 18 | 0x444da0 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 19 | 0x444db0 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 20 | 0x444dc0 | Not a function; type absent; comments absent | color-mode/query helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 21 | 0x444df0 | Not a function; type absent; comments absent | raw-size/color helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 22 | 0x444e30 | Not a function; type absent; comments absent | raw-size/color helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 23 | 0x445680 | Not a function; type absent; comments absent | color conversion/profile helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 24 | 0x4456c0 | Not a function; type absent; comments absent | color conversion/profile helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 25 | 0x446070 | Not a function; type absent; comments absent | state/info cleanup helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 26 | 0x446200 | Not a function; type absent; comments absent | lodepng_state_cleanup | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 27 | 0x447020 | Not a function; type absent; comments absent | lodepng_chunk_type | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C015 |
| 28 | 0x4470b0 | Not a function; type absent; comments absent | lodepng_chunk_ancillary | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 29 | 0x4470c0 | Not a function; type absent; comments absent | lodepng_chunk_private | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 30 | 0x4470d0 | Not a function; type absent; comments absent | lodepng_chunk_safetocopy | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 31 | 0x447100 | Not a function; type absent; comments absent | lodepng_chunk_check_crc | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 32 | 0x447180 | Not a function; type absent; comments absent | lodepng_chunk_generate_crc | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 33 | 0x447200 | Not a function; type absent; comments absent | lodepng_chunk_next | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 34 | 0x447230 | Not a function; type absent; comments absent | lodepng_chunk_next_const | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 35 | 0x447430 | Not a function; type absent; comments absent | chunk/CRC/internal helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 36 | 0x447470 | Not a function; type absent; comments absent | chunk/CRC/internal helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 37 | 0x4474b0 | Not a function; type absent; comments absent | chunk/CRC/internal helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 38 | 0x447b50 | Not a function; type absent; comments absent | allocation/vector/internal helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 39 | 0x447b90 | Not a function; type absent; comments absent | allocation/vector/internal helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 40 | 0x447c30 | Not a function; type absent; comments absent | C++ State cleanup helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 41 | 0x447c70 | Not a function; type absent; comments absent | C++ State cleanup helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 42 | 0x447c90 | Not a function; type absent; comments absent | C++ State cleanup helper | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 43 | 0x447d00 | Not a function; type absent; comments absent | C++ State/helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 44 | 0x447d20 | Not a function; type absent; comments absent | C++ State/helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 45 | 0x447db0 | Not a function; type absent; comments absent | C++ State/helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 46 | 0x447e50 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 47 | 0x447eb0 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 48 | 0x447f50 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 49 | 0x447fb0 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 50 | 0x448010 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 51 | 0x448070 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 52 | 0x4480e0 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 53 | 0x448150 | Not a function; type absent; comments absent | C++ vector wrapper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 54 | 0x4481f0 | Not a function; type absent; comments absent | C++ vector helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |
| 55 | 0x448230 | Not a function; type absent; comments absent | C++ vector helper body | UID0000KW; aggregate source-pair coverage; no per-child import/body/H fragment | C016 |

Compiler code items:

| Item | Current state | Role | Disposition | Claim |
| --- | --- | --- | --- | --- |
| 0x447CC0 | tail chunk of sub_443E80 | C++ wrapper EH/cleanup lowering | Compiler-covered; no source function | C017 |
| 0x4484D0 | tail chunk of sub_444150 | C++ wrapper EH/cleanup lowering | Compiler-covered; no source function | C017 |

Binary data/compiler inventory:

| Range/item | Count | Exact role | Existing/new destination | CPP/H disposition | Claim |
| --- | ---: | --- | --- | --- | --- |
| 0x60F200-0x60F4C0 | 10 semantic storage objects plus 3 alignment/tail-pooling boundaries | default compression settings; five DEFLATE tables; four Adam7 arrays | [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md); UID00024P narrowed | compiler-covered comment; no H | C019 |
| 0x60F4C0 | 1 | version string 20160501 | UID0003AP | compiler-covered comment | C020 |
| 0x60F4CC, 0x60F4D4 | 2 | complete-object-locator pointers | UID0003AP | compiler-generated | C020 |
| 0x60F4D0, 0x60F4D8 | 2 | LodePNGState and lodepng::State vtable slices | UID0003AP/UID00007E | compiler-generated | C020 |
| 0x60F4DC | 1 | wb file mode | UID0003AP | imported source | C020 |
| 0x60F4E0-0x60F530 | 11 | IHDR, IDAT, IEND, PLTE, tRNS, bKGD, tEXt, zTXt, iTXt, tIME, pHYs | UID0003AP | imported source | C020 |
| 0x60F538 | 1 | LodePNG label | UID0003AP | imported source | C020 |
| 0x60F540-0x6104AB | 77 | exact error/diagnostic strings | UID0003AP | imported source | C020 |
| 0x64170C-0x6417A0 | 8 named RTTI descriptor items | LodePNGState and lodepng::State COL/CHD/base hierarchy | [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md) | compiler-generated; no H | C022 |
| 0x66D000 | 1 | pointer to 20160501 | UID000274 | compiler-covered comment | C021 |
| 0x66D004 | 1 | zero separator/alignment | UID000274 | compiler-covered | C021 |
| 0x66D008-0x66D408 | 1 | standard 256-dword reflected CRC-32 table | UID000274 | imported source | C021 |
| 0x674240-0x674278 | 4 named type/string items | two MSVC type descriptors and decorated names | [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md) | compiler-generated; no H | C022 |

This produces 173 binary code items and 120 semantic binary data/compiler identities. The source layer separately has 228 physical definitions, 19 type constructs, and 16 named data definitions; those layers intentionally overlap semantically and are not added into a misleading single total. Summary claims C002-C022 remain preserved, while additive per-item claims C046 onward give every function, type, source definition, raw start, tail, jump table, data identity, support/resource, generated route, caller, dependency, and boundary its own ledger/checklist twin.

Related support-page inventory:

| UID/path | Role | Required disposition |
| --- | --- | --- |
| UID00007E by-class/LodePNGState.md | public class and current first importer | sole import anchor |
| UID0000XE helper-island inventory | complete code container | semantic owner UID0000KW; non-emitting |
| UID0000XF encode front-end | public encode slice | semantic owner UID0000KW; non-emitting |
| UID0000XG raw error/settings | raw slice | semantic owner UID0000KW; non-emitting |
| UID0000XH state init | exact child/emitter | compiler-covered CPP comment |
| UID0000XI destructors | exact child/emitter | compiler-covered CPP comment |
| UID0000XJ searchCodeIndex | exact child/emitter | compiler-covered CPP comment |
| UID00024P MSVC numeric rdata | exact predecessor | narrowed end at 0x60F200 |
| UID00057C LodePngConstantTables | exact constant child/emitter | 0x60F200-0x60F4C0, compiler-covered |
| UID00024Q mixed rdata index | parent split index | remain non-emitting |
| UID0003AP static LodePNG rdata | exact child/emitter | replace empty marker with compiler-covered comment |
| UID00057D LodePngStateRttiDescriptors | exact RTTI hierarchy child/emitter | 0x64170C-0x6417A0, compiler-covered |
| UID000274 mutable data | exact child/emitter | synchronized compiler-covered comment |
| UID00057E LodePngStateTypeDescriptors | exact RTTI type child/emitter | 0x674240-0x674278, compiler-covered |
| UID0001Z7 ReadOnlyDataSection | section container | add constant/RTTI child links |
| UID0001Z8 DataSection | section container | add mutable/type-descriptor child links |
| ImageLoaders and decode-wrapper pages | NexusTK consumers | preserve three direct API calls; no ownership |
| ScreenshotCapture/ScreenPane pages | NexusTK consumer | preserve encode32_file call; no ownership |
| ImageWriters, DATArchive, LibJPEG | rejected owners | preserve negative ownership evidence |
| by-meta/client_libraries.md and obtained source metadata | provenance | update full-feature/source-route summary |
| by-structure.md | import policy | no rule change required |
| by-type/by-global/by-item/by-resource | targeted search found no LodePNG-owned exact page | no page change; do not fabricate targets |

## Evidence

- IDA strings include `LodePNG`, `.?AULodePNGState@@`, `.?AVState@lodepng@@`, `must provide custom zlib function pointer if LODEPNG_COMPILE_ZLIB is not defined`, and `invalid filter strategy given for LodePNGEncoderSettings.filter_strategy`.
- IDA strings also include PNG validation/error text such as `PNG file is smaller than a PNG header` and `incorrect PNG signature, it's no PNG or corrupted`.
- IDA decompilation of `0x00443c80` stores `LodePNGState::vftable`, calls `0x004460f0`, writes both raw and PNG color type/bit depth fields, then calls `0x004466b0`.
- Local source comparison against the obtained `20160501` archive matches `0x00443c80` to `lodepng_encode_memory`, `0x00443db0` to `lodepng_encode_file`, and `0x00443e40` to `lodepng_encode32_file`.
- IDA callers show `0x00443c80` is not only screenshot-facing: it is called by `lodepng_encode_file` at `0x00443db0` and by internal LodePNG helpers at `0x00444480` and `0x004445b0`.
- IDA callers show `lodepng_encode32_file` at `0x00443e40` has one current project-facing caller: the PNG screenshot capture function at `0x00557e80`.
- 2026-05-26 IDA MCP recheck reconfirmed `0x00443e40` size `0x1d` and its sole modeled caller at `0x0055817b` inside `SaveScreenshotPNG`.
- IDA callgraph rooted at the encode front end/main encode roots reaches 73 modeled helper functions through `0x00450b5e`; caller evidence keeps the adjacent `0x00450b60-0x00450c9f` helper in the LodePNG island.
- IDA `lookup_funcs 0x0045004e` maps to the real helper start at `0x00450030`; the helper's direct callers are in `0x0044cbe0`, so it remains LodePNG-island code rather than `EditablePaperPane`.
- IDA does not model the raw `0x00444740-0x00444be0` block as functions, but disassembly shows a LodePNG error-code string switch and small settings/color/default helpers. This block is now documented as [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md).
- IDA MCP follow-up on 2026-05-25 rejects the old `0x00450ca0-0x00456031` tail as LodePNG: `0x00450ca0` is [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), `0x00453df0+` is [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), and multiple old-tail helpers have direct callers from non-LodePNG UI/metadata/audio code.
- Prior documented IDA facts on [UID:000274][0x0066d000-0x0066d408.LodePngMutableDataTables](by-memory/0x0066d000-0x0066d408.LodePngMutableDataTables.md) identify the `.data` version pointer at `0x0066d000`, zero separator at `0x0066d004`, standard reflected CRC-32 table at `0x0066d008-0x0066d407`, LodePNG helper xrefs, and the exclusive `xRight` successor boundary at `0x0066d408`.
- 2026-06-11 A001 Batch202 live IDA MCP split [UID:0003AP][0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData](by-memory/0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData.md) as the exact `.rdata` child for the LodePNG version literal, state vtables, PNG chunk names, and error-text strings. The adjacent shared literal-pool constants and MiniMap RTTI boundary are documented separately and are not LodePNG parent-owned.
- Local vendored source `by-meta/obtained_thirdparty_files/static_embeds/lodepng-20160501/lodepng.cpp` declares `LODEPNG_VERSION_STRING = "20160501"` and `static unsigned lodepng_crc32_table[256]`; `lodepng_crc32`, `lodepng_chunk_check_crc`, and `lodepng_chunk_generate_crc` consume the table in the same PNG CRC role documented by the prior IDA xrefs.
- 2026-06-27 B002 `0000XJ` source-quality implementation maps `0x00450030-0x0045007c` to staged LodePNG `searchCodeIndex` in `source-3/third_party_embeds/lodepng/lodepng.cpp` lines 1326-1341. Live IDA MCP session `80de0a67` reconfirmed the `sub_450030` size `0x4c` / 76 bytes, rejected `0x0045004e` as a midpoint instruction inside the helper, showed the next function at `0x00450080`, found two direct callers in `sub_44CBE0`, and found no callees. The staged source pair hashes are `lodepng.cpp` SHA-256 `71F9A45829F9AF7A6675200153DAAB5D791846A7EC4C5385241AC6F1E35B629A` and `lodepng.h` SHA-256 `9B330CA0224E85EB8937DC83627BDFA0285C6CC6691223D3FD51D8987A2D284B`. Its dated recommendation that [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md) carry the same formal import is superseded: UID00007E now mechanically hosts the one aggregate source-pair directive, and UID0000XJ gets no per-child import/body/H fragment.
- B001-039 live IDA retry note: on 2026-06-10, B001 and the supervisor confirmed that the MCP endpoint answers `tools/list`, but tiny IDB-backed `py_eval` and `xrefs_to` calls time out. The B001-039 parent-gate repair therefore adds no new live IDA facts and instead relies on the prior documented IDA facts plus the local vendored source comparison.
- Wave3 currently materializes only `LodePNGState` destructor glue and the RGBA8 public file helper; most of the encoder implementation remains anonymous helper code.

## Ownership Decision

Keep this code out of DAT/resource, screenshot workflow, generic render modules, and [UID:0000K4][ImageWriters](by-file/ImageWriters.md). A faithful reconstruction should treat it as bundled codec source, likely a single third-party `lodepng.cpp`.

Do not use the current `WriteRGBA8PNGFile_00443E40.cpp` file as evidence that the full encoder belongs to a one-function recovered global or a NexusTK image-writer source file. That file is a Wave3 staging artifact over a stock LodePNG public API.

## Rebuild Strategy

Use the exact staged third-party source pair, never a decompiler-shaped hand port. [UID:00007E][LodePNGState](by-class/LodePNGState.md) is the sole validator routing anchor and carries `<import-from-start>"third_party_embeds/lodepng/lodepng.cpp","third_party_embeds/lodepng/lodepng.h"</import-from-end>` in its formal CPP inline-import value. The multiline CPP block and the independent H block remain blank because the imported header is already the exact declaration authority.

UID0000XH, UID0000XI, UID0000XJ, UID000274, UID0003AP, UID00057C, UID00057D, and UID00057E emit only synchronized compiler-covered comments. UID0000XE, UID0000XF, UID0000XG, and UID00024Q remain non-emitting indexes. This yields one implementation/header import, no copied source, no duplicate translation units, no empty emitter, and no separate generated H sibling.

## Open Questions

- Was LodePNG locally patched? Source hashes, version, wrappers, strings, tables, default settings, and source order show no required patch. Resolution: import the exact staged revision.
- Which feature macros were enabled? Binary contains decode, encode, zlib/deflate, disk I/O, ancillary chunks, error text, default allocators, and C++ RTTI. Resolution: default full-feature header configuration.
- Why 228 physical versus 226 active definitions? The source contains built-in and no-built-in-zlib fallback definitions under opposite conditions. Resolution: default build selects the built-in pair.
- Are the 55 raw starts data? Prologues, returns, source order, and surrounding calls prove standalone source-shaped code. Resolution: code, source-covered; bounded IDA definitions only where identity/end are strong.
- Are all 116 modeled bodies uniquely nameable? Optimization/folding prevents a safe full symbol bijection. Resolution: preserve exact addresses/current profiles and import the exact source; do not fabricate names.
- Is a separate generated header needed? The formal pair imports the header and current H channels are independent. Resolution: no generated sibling H.
- Which page should import? Existing UID00007E gives a coherent first route without converting a container. Resolution: sole routing anchor, explicitly not semantic full-file owner.
- Are the three support UIDs known? Resolution: the Supervisor allocated UID00057C, UID00057D, and UID00057E; their exact pages, ranges, metadata, compiler-covered comments, and links are now current.
- No unresolved issue remains that would justify lower ownership, an empty emitter, duplicate import, hand-port, or generic future-research entry.

## Cross-References

- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md)
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md)
- [UID:00007E][LodePNGState](by-class/LodePNGState.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md)
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md)
- [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md)
- [UID:0000XJ][0x00450030-0x0045007c.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md)
- [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md)
- [UID:0003AP][0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData](by-memory/0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData.md)
- [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md)
- [UID:000274][0x0066d000-0x0066d408.LodePngMutableDataTables](by-memory/0x0066d000-0x0066d408.LodePngMutableDataTables.md)
- [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-25 B010 allocated-support callback: linked complete `92/94` pages [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md), [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md), and [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md). All three emit compiler-covered comments through UID0000KW while UID00007E remains the sole aggregate source-pair import anchor.
- 2026-07-24 B004 UID0001G9 PNG-consumer synchronization: score, third-party ownership, and import policy are unchanged. Linked exact [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md), recorded the direct `0x0055817b` call to stock `lodepng_encode32_file`, and closed the stale local-wrapper question without moving LodePNG source into ScreenshotCapture.cpp.
- 2026-06-27 B001 `0000XI` source-quality implementation: Scores unchanged at `90/88`. At that dated checkpoint it replaced legacy marker wording with a class/destructor-page import recommendation after live IDA MCP session `80de0a67` reconfirmed the base destructor at `0x00448520`, scalar deleting destructor at `0x00448530`, pre/post target `0xcc` padding, EH cleanup/vtable xrefs, and neighboring `lodepng::State` cleanup/deleting destructor at `0x00448560`; staged `lodepng.h` hash matched the obtained `lodepng-20160501` static source and contains inline `virtual ~LodePNGState(){}`. That per-child recommendation is superseded: UID00007E mechanically hosts the one aggregate source-pair directive, while UID0000XI emits only its compiler-covered disposition and no separate import/body/H fragment.
- 2026-06-26 B013 `0000XH` source-quality implementation: Scores unchanged at `90/88`. At that dated checkpoint it added a source-bearing child-policy note after live IDA MCP session `80de0a67` reconfirmed `lodepng_state_init` at `0x004460f0-0x004461f6`, its seven LodePNG-local xrefs, default writes, and `0xcc` post-range padding, and after staged `source-3/third_party_embeds/lodepng/lodepng.cpp` / `.h` matched the obtained `lodepng-20160501` static-source copy hash-for-hash. Its per-child import reading is superseded: UID00007E mechanically hosts the one aggregate source-pair directive, while UID0000XH emits only its compiler-covered disposition and no separate import/body/H fragment.
- 2026-06-11 A001 Batch202 read-only-data split: Scores unchanged at `90/88`. Added [UID:0003AP][0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData](by-memory/0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData.md) as the exact `.rdata` child for LodePNG version/vtable/chunk/error-text data and kept the shared literal-pool/MiniMap RTTI tail outside LodePNG ownership. Evidence: live IDA MCP names, strings, xrefs, and the `0x006104ac` boundary split.
- 2026-06-10 B001-039 parent-gate repair:
  - What existed before: `COMPLETION:88`, `CONFIDENCE:84`; the file parent was below the strict `85/85` gate for assigning [UID:000274][0x0066d000-0x0066d408.LodePngMutableDataTables](by-memory/0x0066d000-0x0066d408.LodePngMutableDataTables.md).
  - Changed to: `COMPLETION:90`, `CONFIDENCE:88`.
  - Summary/evidence: prior documented IDA evidence already ties the mutable version pointer and CRC-32 table to LodePNG helper xrefs and the `0x0066d408` successor boundary; local vendored `lodepng-20160501` source independently declares `LODEPNG_VERSION_STRING` and `lodepng_crc32_table[256]`. B001-039 live IDA retries timed out on tiny IDB-backed calls, so this repair does not claim new live IDA facts.
- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/third_party/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented LodePNG encode anchors at `0x00443c80` and `0x00443e40`; the existing source-structure decision treats this as a vendored single-file codec module rather than NexusTK render, DAT, or screenshot workflow code.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: bundled LodePNG identity/version, public wrapper matches, helper island bounds, generated artifact caveats, ownership decision, rebuild strategy, and open questions are documented; confidence is capped by incomplete per-function naming across the full helper island.

## Accepted Whole-File Ownership, Xrefs, Boundaries, And Negative Evidence

### Direct Xref / Caller Inventory

The modeled-function table above gives caller/callee counts for all 116 modeled bodies. The raw table records explicit zero incoming-xref results for all 55 currently undefined starts.

Project-entry callers:

| Target | Callsite/current caller | Meaning |
| --- | --- | --- |
| 0x443B40 lodepng_decode32 | 0x4D0E1B in sub_4D0D90 | Decode PNG resource to tile context |
| 0x443C40 lodepng_decode32_file | 0x4D0C8B, currently outside modeled caller metadata | Decode PNG file to tile context |
| 0x443E40 lodepng_encode32_file | 0x55817B in ScreenPane_SaveScreenshotPNG | Save RGBA screenshot as PNG |

Public-wrapper local xrefs include decode32/decode24 to decode_memory, decode32_file/decode24_file to decode_file, encode32/encode24 to encode_memory, and encode32_file/encode24_file to encode_file. The five raw convenience wrappers have no incoming entry because their starts are unmodeled, not because they are data.

External callee set, deduplicated:

| Dependency | Role |
| --- | --- |
| j___free_base, _malloc, _realloc | default LodePNG allocators |
| _fopen, _fread, _fwrite, _fclose, _fseek, _ftell | disk feature |
| _memmove, _memmove_0, _memset | vector/buffer support |
| sub_5C7526 | compiler delete wrapper |
| sub_41B6E0, sub_421500 | std::vector/string support |
| @__security_check_cookie@4, ___CxxFrameHandler3 | MSVC lowering |
| __invalid_parameter_noinfo_noreturn | MSVC library guard |

Data xrefs:

| Item | Xrefs/meaning |
| --- | --- |
| 0x60F4C0 | one data xref from 0x66D000 |
| LodePNGState vtable 0x60F4D0 | six refs from decode/encode construction and 0x448520/30/60 destructor glue |
| lodepng::State vtable 0x60F4D8 | ten refs from C++ wrappers, raw cleanup starts, and destructor glue |
| 0x60F228 LENGTHBASE | two refs in sub_44CBE0 |
| 0x60F2A0 DISTANCEBASE | three refs in sub_44CBE0/sub_44EEA0 |
| 0x60F38C/0x60F46C/0x60F488/0x60F4A4 Adam7/tail-pooled arrays | 21 refs across sub_4485C0/sub_4488C0/sub_4489D0 |
| 0x60F420 CLCL_ORDER | three refs in sub_44BC50/sub_44E910 |
| 0x66D000 | one read from sub_4466B0 |
| 0x66D008 CRC table | six refs in modeled and raw CRC functions |
| 0x64170C and 0x641754 | each referenced by its vtable complete-object-locator slot |
| 0x674240 and 0x67425C | each referenced by RTTI descriptors and RTTI vftable |

No additional project caller or external codec dependency was found.

### Ranked Ownership Analysis

### 1. UID0000KW LodePNG compilation unit
- Evidence for: exact upstream source identity, complete code/data/type match, file-local call graph, library strings, version, vtables, RTTI, and direct API-only consumers.
- Evidence against: none.
- Decision: canonical semantic owner and source path `NexusTK/third_party/`.

### 2. UID00007E LodePNGState as routing anchor
- Evidence for: already the first source-pair importer; requires the exact header and implementation for State lifecycle; preserves six contributor sections after comment conversion.
- Evidence against: it is not semantic owner of every helper.
- Decision: sole mechanical import anchor, explicitly documented as routing-only.

### 3. UID0000XE helper-island container as importer
- Evidence for: widest exact code range.
- Evidence against: established non-emitting inventory container; conversion would add a seventh contributor and conflate range documentation with source emission.
- Decision: reject as importer; assign semantic ownership only.

### 4. NexusTK consumers
- Evidence for: three direct calls.
- Evidence against: calls into public third-party APIs do not establish source ownership.
- Decision: preserve as consumers only.

### Proposed new file/grouping, if applicable
- No new source compilation unit is needed.
- Three documentation children are needed for exact binary coverage: constants and two RTTI ranges.
- All generated source should remain one imported `lodepng.cpp`/header pair.

### Source Placement

- Recommended source file: `NexusTK/third_party/LodePNG.cpp` generated from the exact import pair.
- Import paths: `third_party_embeds/lodepng/lodepng.cpp` and `third_party_embeds/lodepng/lodepng.h`.
- Rejected: `NexusTK/ImageWriters`, screenshot source, DAT/resource source, render source, one-function recovered files, or hand-authored decompiler ports.
- The staged source is an exact third-party unit. NexusTK integration remains in its three callers.
- Case of generated `LodePNG.cpp` is project routing policy; upstream filenames stay lowercase inside the import path.

### Range / Split / Padding / Reclassification Analysis

- Code predecessor: `0x443A55-0x443A5F`, eleven CC bytes between JsonCpp tail and LodePNG start.
- Code body: `0x443A60-0x450C9E`; final source byte range ends at `0x450C9F` exclusive.
- Code successor padding: one CC at `0x450C9F`.
- Next family: MiniMap begins `0x450CA0`; no LodePNG tail extends beyond it.
- Internal compiler tails: `0x447CC0` belongs to `sub_443E80`; `0x4484D0` belongs to `sub_444150`.
- Constant split: UID00024P now ends at `0x60F200`; its old `0x60F4C0` endpoint is superseded history. [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md) is the exact standalone `[0x60F200,0x60F4C0)` authority.
- Static rdata: keep UID0003AP exactly `0x60F4C0-0x6104AC`; `0x6104AC+` remains shared/non-LodePNG.
- RTTI split A: [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md) owns exact `[0x64170C,0x6417A0)`; MiniMap RTTI starts at `0x6417A0`.
- Mutable data: keep UID000274 exactly `0x66D000-0x66D408`; `xRight` starts at `0x66D408`.
- RTTI split B: [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md) owns exact `[0x674240,0x674278)`; MiniMap type data starts at `0x674278`.
- Parent/container impact: section authorities contain the exact child inventories, UID00024P endpoint, and links to allocated UID00057C/UID00057D/UID00057E. Generated reports remain validator-owned.

### Negative Evidence Summary

- No evidence places the codec in ImageWriters, ScreenshotCapture, DATArchive, render, map, or LibJPEG source.
- No NexusTK wrapper exists inside the LodePNG island; consumers call public APIs directly.
- No code at or beyond `0x450CA0` belongs to LodePNG.
- No bytes at or beyond `0x6104AC` are exclusively LodePNG-owned.
- No `xRight` bytes at `0x66D408+` belong to LodePNG.
- No current IDA UDT justifies partial local struct recreation.
- No fourth source import is needed; duplicate imports are not corroborating source units.
- No standalone source should be written for vtables, RTTI, tail chunks, padding, diagnostic strings, or CRC storage.
- No separate generated header is required under the formal paired import mechanism.
- No historical or report-time session is timeless current authority. A later Gate 2B dynamically supersedes all dated session facts by establishing fresh canonical/session/disk/attestation/prestate evidence.

- 2026-08-24 callback disposition: the three exact missing data children remain represented here and in their section-container authorities, but standalone page creation is excluded until the primary supervisor allocates valid UIDs through the registry-owned process. No placeholder UID was written into an ordinary page.

- 2026-08-24 Gate 2A current-authority repair: clarified that UID00007E mechanically hosts one aggregate LodePNG compilation-unit import rather than 228 per-definition or per-child imports; every modeled/raw item now states aggregate coverage and no per-child import/body/H fragment. Generated command/hash receipts are dated snapshots only, and each later gate must reread then-current validator-owned output.
