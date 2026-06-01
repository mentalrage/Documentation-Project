*** UID:0000KW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LodePNG

## Status

- Confidence: strong for bundled-library identity and `20160501` source-snapshot candidate; medium for full per-function source map.
- Proposed module: `third_party/lodepng.cpp` or `external/lodepng.cpp`
- Version evidence: IDA string `20160501` at `0x0060f4c0`; obtained upstream commit `c6cf08b8910d91b0830666c07845116df1e9b6fc` contains `LodePNG version 20160501`, and its public encode/disk wrappers match `0x00443c80-0x00443e5d`.
- Current generated artifacts: `source-3/simroot_v2/class_LodePNGState.cpp` and `source-3/simroot_v2/recovered/WriteRGBA8PNGFile_00443E40.cpp`; the latter should be treated as stock LodePNG `lodepng_encode32_file`, not a NexusTK-local source file.
- Main address docs: [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md), [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md), [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md), [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md), [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md), and [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)
- Evidence basis: `simroot_v2` generated files plus read-only IDA MCP lookup, decompile, caller/callee, string, and tail-boundary checks on 2026-05-24 and 2026-05-25. `wave3.py` was not executed for this pass.

## File Role

This is bundled LodePNG codec support, not NexusTK feature code. The functions around `0x00443c80` are now matched to stock LodePNG public APIs: `lodepng_encode_memory`, `lodepng_encode_file`, and `lodepng_encode32_file`.

The project-facing user is [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md), which calls the fixed RGBA8 file helper for PNG screenshots. The larger anonymous `sub_44xxxx`/`sub_45xxxx` helper cluster belongs with LodePNG until proven otherwise.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| helper island inventory | `0x00443a60-0x00450c9f` | Dense IDA function inventory and raw LodePNG error/default block around the public encode front end. The previous `0x00456031` upper bound is rejected because `0x00450ca0+` is MiniMap/shared support code. |
| `lodepng_encode_memory` | `0x00443c80-0x00443d61` | Stock public memory encode wrapper; stack-constructs `LodePNGState`, initializes defaults, overrides raw/PNG color type and bit depth, calls the main encoder, then frees state-owned buffers. |
| `lodepng_encode_file` | `0x00443db0-0x00443e32` | Stock public disk encode wrapper; encodes a pixel buffer to PNG memory, saves bytes through the file helper behavior, and frees the encoded buffer. |
| `lodepng_encode32_file` | `0x00443e40-0x00443e5d` | Stock public fixed-RGBA8 wrapper that calls `lodepng_encode_file` with color type `6` and bit depth `8`. |
| raw error/settings helpers | `0x00444740-0x00444be0` | Raw unmodeled LodePNG switch/default helpers now matched to `lodepng_error_text`, settings initialization, `lodepng_color_mode_init`, and palette cleanup patterns. |
| `lodepng_state_init` | `0x004460f0-0x004461f6` | Initializes LodePNG encoder/color/default settings. |
| `LodePNGEncode_4466B0` provisional | `0x004466b0-0x00446feb` | Main encode routine; calls many local LodePNG helpers and allocator/free paths. |
| `LodePngLowerBoundHelper` provisional | `0x00450030-0x0045007b` | Dword-table lower-bound helper; disabled Wave3 data currently mis-attaches the interior address `0x0045004e` to `EditablePaperPane`. |
| [UID:00007E][LodePNGState](by-class/LodePNGState.md) destructors | `0x00448520-0x00448557` | Trivial vtable reset destructor and scalar deleting destructor. |

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
- Wave3 currently materializes only `LodePNGState` destructor glue and the RGBA8 public file helper; most of the encoder implementation remains anonymous helper code.

## Ownership Decision

Keep this code out of DAT/resource, screenshot workflow, generic render modules, and [UID:0000K4][ImageWriters](by-file/ImageWriters.md). A faithful reconstruction should treat it as bundled codec source, likely a single third-party `lodepng.cpp`.

Do not use the current `WriteRGBA8PNGFile_00443E40.cpp` file as evidence that the full encoder belongs to a one-function recovered global or a NexusTK image-writer source file. That file is a Wave3 staging artifact over a stock LodePNG public API.

## Rebuild Strategy

For project rebuilds, prefer vendoring upstream LodePNG source rather than hand-rewriting the whole `0x00443a60-0x00450c9f` helper island from decompiler output.

Recommended reconstruction path:

1. Add a third-party source folder such as `third_party/lodepng/` containing `lodepng.cpp` and `lodepng.h` from the `20160501` upstream revision.
2. Do not recreate `WritePNGFileWithFormat` or `WriteRGBA8PNGFile` as NexusTK-owned wrappers unless later source evidence proves the original code renamed the stock LodePNG APIs. Current evidence maps those addresses to `lodepng_encode_file` and `lodepng_encode32_file`.
3. Compile the vendored LodePNG with settings that match the binary evidence: C++ state support, encoder support, and no ownership by screenshot/render/DAT modules.
4. Compare symbols/strings/control flow against this binary island. If upstream does not match exactly, keep the upstream source as the base and document local patches rather than treating the recovered decompiler output as original application source.

Official source references for future version matching:

- <https://lodev.org/lodepng/>
- <https://github.com/lvandeve/lodepng>

## Open Questions

- Exact per-function LodePNG names inside `0x00443a60-0x00450c9f`; the source-level library span is now bounded before [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md).
- Whether the raw [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md) should be split into IDA/Wave3 function starts or retained as one documented raw helper island.
- Whether any small local wrapper existed above the stock `lodepng_encode32_file` call, or whether screenshot code called the LodePNG API directly.
- Whether any local LodePNG deflate/checksum helpers overlap with the separately recovered zlib `Crc32`/`Adler32` family. Current caller evidence keeps them separate.
- Continue whole-island source matching against upstream LodePNG revision `20160501`; public wrapper/source-version evidence is strong, but lower helper functions still need per-function naming.

## Cross-References

- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md)
- [UID:00007E][LodePNGState](by-class/LodePNGState.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md)
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md)
- [UID:0000XI][0x00448520-0x00448557.LodePNGStateDestructors](by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md)
- [UID:0000XJ][0x00450030-0x0045007b.LodePngLowerBoundHelper](by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: bundled LodePNG identity/version, public wrapper matches, helper island bounds, generated artifact caveats, ownership decision, rebuild strategy, and open questions are documented; confidence is capped by incomplete per-function naming across the full helper island.
