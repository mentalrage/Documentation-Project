** TARGET-REPORT-UID:00018N **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID00018N JpegScreenshotWriter Source-Quality Report


- B-agent: Agent-B011
- Target UID: 00018N
- Target doc: `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md`
- Report path: `tools/leaser/Agents/Agent-B011/research/00018N-JpegScreenshotWriter-source-quality.md`
- Mode: implementation callback completed after supervisor Gate 1 acceptance. B011 edited the target by-memory doc and this report only; generated/tracker files were refreshed by the scoped validator, not manually edited by B011.

## Finalized Report / Current Recommendation

UID00018N remains [UID:0000K4][ImageWriters](by-file/ImageWriters.md)-owned product wrapper code over the bundled IJG libjpeg compression API. After the B011 implementation callback, the target is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000K4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K4`, blank `EMITTER_POSITION_OPTIONAL`, and has the accepted first-draft formal C++ block.

Callback disposition: target-only changes were applied; no support doc contradiction was found and no support docs were edited. Scoped validation passed with command `000000007514`, and validator-owned generated output refreshed UID00018N to emitted code at `88/90`. The remaining score caps are exact original file name, raw JPG path reachability, and final source names for two no-xref destination callback bodies.

## Supporting Research

- Agent-B011 read the project-level `ntk-b-agent-workflow` skill, Agent-B011 `goal.md`, the B-agent report template, and the score/blocker audit standard before writing this report.
- Search terms used against existing reports and docs: `TARGET-REPORT-UID:00018N`, `UID00018N`, `0x004efbc0-0x004efe94`, `JpegScreenshotWriter`, `ScreenshotJpegCapturePath`, `ImageWriters`, `LibJpegCompressApiFrontEnd`, `JpegScreenshotEoiMarker`, `0x005579d3`, and `0x0066db40`.
- Prior B005 report `0001G8-ScreenshotJpegCapturePath-source-quality.md` is a lead only: it proves the raw screenshot workflow and its first-draft `ScreenPane::SaveScreenshotJPG()` shape, but that code remains ScreenshotCapture-owned and must not be copied into UID00018N.
- Prior B007 report `0000VS-LibJpegCompressApiFrontEnd-source-quality.md` is a lead only: it proves the IJG compression API source-map and product caller sequence, but keeps libjpeg internals under LibJPEG and preserves UID00018N/ImageWriters as the product RGB555/RGB565 writer wrapper.
- Prior B009 `0000VT` and B014 `0000VZ` leads reject product ownership for adjacent IJG raw-data and marker-writer internals. They support the same boundary used here: UID00018N calls public IJG APIs; it does not own IJG source.
- Current support docs checked: `by-file/ImageWriters.md`, `by-file/ScreenshotCapture.md`, `by-file/LibJPEG.md`, `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`, `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md`, `by-memory/0x0066db40-0x0066db42.JpegScreenshotEoiMarker.md`, and `by-global/JpegScreenshotEoiMarker.md`.
- Historical pre-callback generated state checked during the report-only pass: `auto-generated/NexusTK/render/ImageWriters.cpp` command `000000007492` emitted UID00018N as `Completion:86 | Confidence:89 | Empty Emitter Marker`; `auto-generated/-ag-coverage-report-by-memory.md` command `000000007494` listed `emits_code:false`; `auto-generated/-ag-research-tracker.md` command `000000007497` listed UID00018N at `86/89`, combined `87.5`, reconstructable `true`, reports `0`.
- Post-callback generated state after scoped validation: validator command `000000007514` refreshed `auto-generated/NexusTK/render/ImageWriters.cpp` to UID00018N `Completion:88 | Confidence:90` with emitted C++; refreshed `auto-generated/-ag-coverage-report-by-memory.md` to `emits_code:true`; and refreshed `auto-generated/-ag-research-tracker.md` to `88/90`, combined `89.0`, reconstructable `true`, reports `0`.

## Target

Target doc is `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md`. After this B011 implementation callback, it is current at `88/90`, has ImageWriters ownership/emission, and emits the accepted first-draft formal C++ block. Its evidence covers the main writer, null stubs, raw destination callback bodies, writer-local error callback, caller xref, libjpeg callee set, RGB565/RGB555 conversion, scanline loop, fallback EOI marker, and `0xcc` alignment spans.

The report target is not ScreenshotCapture workflow code and not LibJPEG third-party source. ScreenshotCapture owns the raw caller at `0x00557840-0x00557a95`; LibJPEG owns the IJG implementations at `0x00401000-0x00414283`; UID00018N owns the product wrapper that converts a 16-bit surface into temporary RGB scanlines and calls the public compression API.

## Current Target State

Current target state after the B011 implementation callback:

- Metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000K4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K4`, blank `EMITTER_POSITION_OPTIONAL`.
- Formal C++: accepted first-draft `RECONSTRUCTION_CPP CODE` is present in the target and generated into `auto-generated/NexusTK/render/ImageWriters.cpp`.
- Generated route: scoped validator command `000000007514` refreshed `auto-generated/NexusTK/render/ImageWriters.cpp` to UID00018N `Completion:88 | Confidence:90` with emitted code.
- Tracker state at B011 callback completion: `auto-generated/-ag-research-tracker.md` lists UID00018N as `88/90`, combined `89.0`, reconstructable `true`, reports `0`; later supervisor-owned execution/archival history is authoritative after lifecycle execution.
- The previous blank-C++ blocker is historical. The target now states that the main wrapper and error manager are source-ready, while the two raw no-xref destination bodies remain first-draft with behavior-based local names and opaque local state fields.

## Heuristic / Inference Reanalysis And Validation

The old blank-code blocker was too broad. The wrapper is not a mixed third-party source-map page; it is a single product-owned writer island that calls public IJG APIs. Public libjpeg field and type names are available from the staged/generated IJG 6b headers, and the target's stack/error-manager layout can be expressed with a local wrapper around `jpeg_error_mgr` plus `jmp_buf`.

The local destination callback island remains lower confidence than the main writer. MCP proves complete bodies at `0x004efe00-0x004efe35` and `0x004efe40-0x004efe57`, but xrefs to those starts are still empty. They should remain documented as writer-local support retained in the same object/source neighborhood, not as live caller proof. Their exact original function names are inferred from behavior, so the target score should not exceed `88/90`.

Ownership heuristic validation:

1. `ImageWriters.cpp` wins for UID00018N because the page converts pixels and writes an image file through a codec library. It is utility writer code, not UI workflow code.
2. `ScreenshotCapture.cpp` owns the raw caller path because it opens the screenshot stream, passes `word_66DA94`, `word_66DA98`, `byte_69B3D5`, and `[edi+20h]`, then continues screenshot status/proof flow.
3. `LibJPEG` owns `jpeg_std_error`, `jpeg_CreateCompress`, `jpeg_stdio_dest`, `jpeg_set_defaults`, `jpeg_start_compress`, `jpeg_write_scanlines`, `jpeg_finish_compress`, and `jpeg_destroy_compress`.
4. `JpegScreenshotEoiMarker` is separate ImageWriters-owned data at `0x0066db40`; the raw destination callback references it, but UID00018N should not absorb the by-global/by-memory marker docs.
5. The successor `0x004efea0` is KeySpeedMgr; bytes `0x004efe94-0x004efea0` are clean `0xcc` alignment and not part of the JPEG writer.

## Evidence Standards Used

- MCP evidence is required and was collected from live IDA MCP session `supervisor_recovery_20260705`.
- Decompiler output is used only when corroborated by xrefs, stack-frame data, disassembly, bytes, and existing source-owner docs.
- Exact range and padding claims require byte reads or function-boundary checks.
- Ownership claims require both positive owner evidence and negative evidence against plausible alternates.
- First-draft C++ is allowed only because the target is reconstructable, has a nonblank emitter route to `ImageWriters.cpp`, clears the score threshold, and is product wrapper code rather than a mixed third-party import page.
- Any callback/source name not directly proven by symbol evidence is presented as a recommended source-facing name, not as original-symbol proof.
- Historical report-only current-state language is scoped to the initial B011 report pass; this post-callback artifact records implementation state, and later supervisor-owned execution/archival history is authoritative after lifecycle execution.

## Evidence Checked

- MCP session/health: `idb_list` returned active session `supervisor_recovery_20260705` for `NexusTK.exe.i64`; `server_health` returned status `ok`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Function lookup: `0x004efbc0` is `sub_4EFBC0`, size `0x222`; `0x004efdf0` is `nullsub_36`, size `0x1`; `0x004efe00` and `0x004efe40` are not IDA functions; `0x004efe60` is `nullsub_37`, size `0x1`; `0x004efe70` is `sub_4EFE70`, size `0x24`; `0x004efea0` is successor `sub_4EFEA0`.
- Range math: whole target `0x004efbc0-0x004efe94` is `0x2d4` / 724 bytes; main body `0x222` / 546 bytes; raw destination body `0x35` / 53 bytes; raw advance body `0x17` / 23 bytes; error callback `0x24` / 36 bytes.
- Function profile: main writer has 159 instructions, 16 basic blocks, zero modeled callers, 13 listed callees including one self artifact; error callback has 15 instructions, 3 blocks, zero modeled callers, `_longjmp` callee.
- Stack/prototype: main writer prototype is `int __cdecl(int, int, unsigned int, char, int)` with five stack args (`pixels`, `width`, `height`, mode byte, `FILE*`); error callback prototype is `void __cdecl __noreturn(int *)`.
- Xrefs: `xrefs_to 0x004efbc0` reports one code xref at raw `0x005579d3`; `xrefs_to 0x004efe70` reports one data xref from `0x004efc0d` inside `sub_4EFBC0`; `xrefs_to 0x0066db40` reports one data xref at `0x004efe22`; xrefs to `0x004efdf0`, `0x004efe00`, `0x004efe40`, and `0x004efe60` are empty.
- Caller disassembly: raw `0x005579d3` pushes `esi` output stream, `unk_69B3D5` mode byte, `word_66DA98` height, `word_66DA94` width, and `[edi+20h]` source pixels before calling `sub_4EFBC0`.
- Callees: main writer calls `0x00401000` (`jpeg_std_error`), `__setjmp3`, `0x00403920` (`jpeg_CreateCompress`), `0x00403cc0` (`jpeg_stdio_dest`), `0x00403f70` (`jpeg_set_defaults`), `0x004047a0` (`jpeg_start_compress`), allocator/free helpers, `0x00404820` (`jpeg_write_scanlines`), `0x00403a60` (`jpeg_finish_compress`), `0x004039f0` (`jpeg_destroy_compress`), and the security cookie check. Error callback calls only `_longjmp`.
- Main decompile: initializes libjpeg error manager, installs `sub_4EFE70`, clears error-manager output-message slot, wraps compression in `_setjmp3`, creates compressor with version `62` and struct size `360`, installs `jpeg_stdio_dest`, sets width/height/components/color space, allocates `3 * width * height`, converts RGB565 or RGB555 pixels to RGB bytes, writes scanlines, frees the RGB buffer, finishes compression, destroys compressor, returns `0` on success and `-1` on setjmp error.
- Raw callback disassembly: `0x004efe00` reads `cinfo->dest` at `[arg0+0x18]`; if byte `+0x24` is clear, it copies fields `+0x1c/+0x20` into `next_output_byte/free_in_buffer`, sets `+0x24`, returns true; otherwise it points at `0x0066db40` and count `2`. `0x004efe40` advances `next_output_byte` and decrements `free_in_buffer` by a positive byte-count arg.
- Bytes: all internal/successor alignment spans are `0xcc`: `0x004efde2-0x004efdf0` 14 bytes, `0x004efdf1-0x004efe00` 15 bytes, `0x004efe35-0x004efe40` 11 bytes, `0x004efe57-0x004efe60` 9 bytes, `0x004efe61-0x004efe70` 15 bytes, `0x004efe94-0x004efea0` 12 bytes. `0x0066db40` bytes are `ff d9`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Required target/support disposition | Verification state |
| --- | --- | --- | --- | --- |
| C-00018N-001 | UID00018N remains ImageWriters-owned product image writer code. | ImageWriters source-placement contents and MCP public libjpeg call sequence. | Incorporate in target status/summary/source placement. | applied in target summary/status/source-placement prose. |
| C-00018N-002 | ScreenshotCapture owns the raw caller workflow, not this writer. | Raw caller at `0x005579d3`; B005 UID0001G8 report and target doc. | Incorporate as negative ownership evidence. | applied in target library-boundary and assignment-gate rejection of ScreenshotCapture direct ownership. |
| C-00018N-003 | LibJPEG owns IJG compression API bodies, not UID00018N. | B007 UID0000VS and LibJPEG docs; callee addresses. | Incorporate library boundary. | applied in target callee/library-boundary prose; no LibJPEG support edit required. |
| C-00018N-004 | Main function boundary is `0x004efbc0-0x004efde2`, size `0x222` / 546 bytes. | MCP `lookup_funcs`, `func_profile`, int conversion. | Already present; refresh with current session detail. | applied in B011 MCP evidence section at same-or-greater detail. |
| C-00018N-005 | Full target range is `0x004efbc0-0x004efe94`, `0x2d4` / 724 bytes. | Target slug plus MCP boundary/byte reads. | Incorporate in target summary/range evidence. | applied in target Item Summary and B011 MCP evidence. |
| C-00018N-006 | Main writer has 159 instructions and 16 basic blocks. | MCP `func_profile` / `basic_blocks`. | Add to target evidence. | applied in target Item Summary and B011 MCP evidence. |
| C-00018N-007 | Error callback has 15 instructions, 3 basic blocks, and calls only `_longjmp`. | MCP `func_profile`, `callees`, `decompile`. | Add to local callback evidence. | applied in target Item Summary and local-callback evidence. |
| C-00018N-008 | Only inbound writer code xref is raw `0x005579d3`; modeled callers remain zero. | MCP `xrefs_to`, `func_profile`, screenshot raw lookup. | Incorporate as reachability caveat. | applied in target caller evidence and score rationale. |
| C-00018N-009 | Call site passes source pixels, width, height, mode byte, and output stream. | MCP disassembly around `0x005579d3`. | Add to caller evidence and signature rationale. | applied with exact argument pushes in target B011 evidence. |
| C-00018N-010 | Writer installs local error callback at `0x004efc0d`. | MCP decompile and `xrefs_to 0x004efe70`. | Incorporate; already present at same-or-greater detail. | applied in target local error callback evidence. |
| C-00018N-011 | Error manager uses `jpeg_error_mgr` followed by `jmp_buf` at offset `0x84`. | MCP stack layout and error callback decompile. | Incorporate in first-draft C++ rationale. | applied in target C++ block and evidence/rationale. |
| C-00018N-012 | Main path creates IJG compressor version `62`, struct size `360`. | MCP decompile constants `0x3e` and `0x168`; LibJPEG headers. | Incorporate; already present but update with current session. | applied in target behavior/decompile evidence and C++ rationale. |
| C-00018N-013 | RGB565 extraction is red `HIBYTE(pixel)&0xf8`, green `(pixel>>3)&0xfc`, blue `8*pixel`. | MCP decompile/disassembly constants. | Preserve in target evidence and C++ block. | applied in formal C++ and target conversion evidence. |
| C-00018N-014 | RGB555 extraction is red `(pixel>>7)&0xf8`, green `(pixel>>2)&0xf8`, blue `8*pixel`. | MCP decompile/disassembly constants. | Preserve in target evidence and C++ block. | applied in formal C++ and target conversion evidence. |
| C-00018N-015 | Raw destination body `0x004efe00` is complete code but has no inbound xrefs. | MCP disasm, byte read, xrefs. | Incorporate as retained support/negative liveness. | applied in target raw callback evidence and remaining caveats. |
| C-00018N-016 | Raw advance body `0x004efe40` is complete code but has no inbound xrefs. | MCP disasm, byte read, xrefs. | Incorporate as retained support/negative liveness. | applied in target raw callback evidence and remaining caveats. |
| C-00018N-017 | Null stubs `0x004efdf0` and `0x004efe60` are one-byte `ret` bodies with empty xrefs. | MCP lookup, bytes, xrefs. | Preserve; source names remain inferred. | applied in target local stub evidence and caveat wording. |
| C-00018N-018 | Fallback marker at `0x0066db40` is `ff d9` and is referenced only from raw destination body. | MCP bytes and xrefs; UID0002ZL docs. | Preserve as external support data, not target-owned data. | applied in target support-data/library-boundary prose; marker docs left untouched. |
| C-00018N-019 | Internal and successor gaps are `0xcc` alignment, not missing code. | MCP get_bytes on six spans. | Already present; refresh with exact current reads. | applied in target padding/boundary evidence. |
| C-00018N-020 | Formal C++ is now justified as first draft for the wrapper page. | C++ gate, owner/emitter route, live MCP, source-field resolution. | Replace blank target formal C++ with exact block. | applied; target formal `RECONSTRUCTION_CPP CODE` now contains the exact accepted block. |
| C-00018N-021 | Score should become `88/90`, not higher. | Evidence resolves prior broad code blocker; raw no-xref callbacks and JPG liveness remain. | Update metadata and score rationale. | applied; target metadata is `COMPLETION:88`, `CONFIDENCE:90`, and score rationale records remaining caps. |
| C-00018N-022 | Support docs are mostly same-or-greater detail; no broad support edit is required. | ImageWriters/ScreenshotCapture/LibJPEG/UID0001G8/UID0002ZL checked. | Mark support as already sufficient unless callback comparison finds direct contradiction. | excluded-with-reason: no direct support contradiction found during target callback; no support docs edited by B011. |
| C-00018N-023 | Pre-callback generated/tracker state was empty emitter at `86/89`, reports `0`; post-callback validator output emits code at `88/90`. | Historical commands `000000007492`, `000000007494`, `000000007497`; post-callback command `000000007514`. | Preserve historical state and record current validator-owned generated refresh. | applied; target records pre-callback state as historical and this report records post-callback generated refresh to `88/90`. |

## Positive Evidence Summary

- MCP confirms a clean writer island from `0x004efbc0` through `0x004efe94` with exact function/raw-body/padding boundaries.
- The only code xref to the main writer is the raw screenshot JPG path call at `0x005579d3`; its argument pushes match a product writer signature.
- The main writer performs a complete libjpeg compression sequence, not a partial helper: error setup, setjmp, create compressor, stdio destination, defaults, start, RGB conversion, scanline writes, finish, destroy.
- RGB565/RGB555 conversion formulas are exact and match prior support reports.
- The local error callback is live through a data assignment inside the writer and longjmps through the error-manager-adjacent `jmp_buf`.
- Raw destination bodies are complete prologue/epilogue code and the fallback marker data xref proves they are part of the writer's local support island even though direct xrefs to their starts are absent.
- `ImageWriters.md`, `ScreenshotCapture.md`, `LibJPEG.md`, and UID0001G8 agree on the same owner split.

## Negative Evidence Summary

- No modeled caller targets `0x004efbc0`; only raw `0x005579d3` does.
- `0x00557840` raw screenshot path is not an IDA function and has no xrefs to its start; that keeps JPG workflow reachability open.
- `0x004efdf0`, `0x004efe00`, `0x004efe40`, and `0x004efe60` have no inbound xrefs; destination callback names remain behavior-based.
- LibJPEG public API caller evidence does not transfer IJG source ownership into `ImageWriters.cpp`.
- ScreenshotCapture caller evidence does not transfer the product writer wrapper into `ScreenshotCapture.cpp`.
- `JpegScreenshotEoiMarker` data is a separate ImageWriters-owned global/memory item; UID00018N should not absorb its by-global/by-memory documentation.
- Historical pre-callback generated output had no code for UID00018N; post-callback validator command `000000007514` now emits UID00018N code at `88/90`. The old empty-emitter state was not evidence against first-draft eligibility.

## Ranked Ownership Analysis

| Rank | Candidate owner | Decision | Evidence |
| --- | --- | --- | --- |
| 1 | [UID:0000K4] `ImageWriters.cpp` | Keep as owner/emitter. | Converts pixels and writes a JPEG file through public codec APIs; support doc already lists this wrapper and marker. |
| 2 | [UID:0000ND] `ScreenshotCapture.cpp` | Reject as direct owner; keep as caller/workflow owner. | Raw path opens streams and calls UID00018N, then continues screenshot UI/proof flow. |
| 3 | [UID:0000KN] `LibJPEG` | Reject as product wrapper owner; keep as library dependency. | Callees are stock IJG API implementations already mapped under LibJPEG. |
| 4 | [UID:0000K3] `ImageLoaders` | Reject. | Decode/load wrappers are separate; UID00018N is write/compress output path. |
| 5 | [UID:0002ZG]/[UID:0002ZL] marker data | Reject as code owner; keep as support data. | Marker is referenced by a raw callback but is data, not the writer function body. |

## Source Placement

Recommended source placement remains `NexusTK/render/ImageWriters.cpp` through [UID:0000K4] `ImageWriters`. The formal item should be a product helper:

`int WriteJpegFileFromRgb565Surface(const unsigned short *pixels, int width, unsigned int height, bool usesRgb565, FILE *output);`

The adjacent local functions should remain in the same source file as writer-local support:

- `JpegScreenshotEmptyCallbackA`
- `JpegScreenshotDestinationEnsureBuffer`
- `JpegScreenshotDestinationAdvance`
- `JpegScreenshotEmptyCallbackB`
- `JpegScreenshotErrorExitLongjmp`

Do not create a standalone `JpegScreenshotWriter.cpp` without further source evidence. Do not move the code under `third_party/libjpeg`; this page is a product wrapper over the third-party library.

## First-Draft C++ Recommendation

The implementation callback replaced the blank target formal C++ with this exact block. It uses public IJG 6b names for the compression API, local structs for the product error/destination state, and an external marker declaration so UID0002ZG/UID0002ZL remain the data owners.

```cpp
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include "jpeglib.h"

extern const JOCTET JpegScreenshotEoiMarker[2];

struct JpegScreenshotErrorManager
{
    jpeg_error_mgr pub;
    jmp_buf setjmpBuffer;
};

struct JpegScreenshotDestinationManager
{
    jpeg_destination_mgr pub;
    void *reserved14;
    void *reserved18;
    JOCTET *pendingOutputByte;
    size_t pendingFreeInBuffer;
    unsigned char fallbackArmed;
};

static void JpegScreenshotEmptyCallbackA(j_compress_ptr)
{
}

static boolean JpegScreenshotDestinationEnsureBuffer(j_compress_ptr cinfo)
{
    JpegScreenshotDestinationManager *dest =
        reinterpret_cast<JpegScreenshotDestinationManager *>(cinfo->dest);

    if (dest->fallbackArmed == 0) {
        dest->fallbackArmed = 1;
        dest->pub.next_output_byte = dest->pendingOutputByte;
        dest->pub.free_in_buffer = dest->pendingFreeInBuffer;
        return TRUE;
    }

    dest->pub.next_output_byte = const_cast<JOCTET *>(JpegScreenshotEoiMarker);
    dest->pub.free_in_buffer = 2;
    return TRUE;
}

static void JpegScreenshotDestinationAdvance(j_compress_ptr cinfo, int byteCount)
{
    if (byteCount > 0) {
        cinfo->dest->next_output_byte += byteCount;
        cinfo->dest->free_in_buffer -= byteCount;
    }
}

static void JpegScreenshotEmptyCallbackB(j_compress_ptr)
{
}

static void JpegScreenshotErrorExitLongjmp(j_common_ptr cinfo)
{
    JpegScreenshotErrorManager *errorManager =
        reinterpret_cast<JpegScreenshotErrorManager *>(cinfo->err);

    if (errorManager->pub.output_message != 0) {
        errorManager->pub.output_message(cinfo);
    }

    longjmp(errorManager->setjmpBuffer, 1);
}

int WriteJpegFileFromRgb565Surface(
    const unsigned short *pixels,
    int width,
    unsigned int height,
    bool usesRgb565,
    FILE *output)
{
    jpeg_compress_struct cinfo;
    JpegScreenshotErrorManager errorManager;
    JSAMPLE *rgbBuffer = 0;

    cinfo.err = jpeg_std_error(&errorManager.pub);
    errorManager.pub.error_exit = JpegScreenshotErrorExitLongjmp;
    errorManager.pub.output_message = 0;

    if (setjmp(errorManager.setjmpBuffer) != 0) {
        jpeg_destroy_compress(&cinfo);
        if (rgbBuffer != 0) {
            free(rgbBuffer);
        }
        return -1;
    }

    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, output);
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    const int pixelCount = width * static_cast<int>(height);
    rgbBuffer = static_cast<JSAMPLE *>(malloc(3 * pixelCount));

    if (usesRgb565) {
        for (int i = 0; i < pixelCount; ++i) {
            const unsigned int pixel = pixels[i];
            JSAMPLE *out = rgbBuffer + (3 * i);
            out[0] = static_cast<JSAMPLE>((pixel >> 8) & 0xf8);
            out[1] = static_cast<JSAMPLE>((pixel >> 3) & 0xfc);
            out[2] = static_cast<JSAMPLE>(8 * pixel);
        }
    } else {
        for (int i = 0; i < pixelCount; ++i) {
            const unsigned int pixel = pixels[i];
            JSAMPLE *out = rgbBuffer + (3 * i);
            out[0] = static_cast<JSAMPLE>((pixel >> 7) & 0xf8);
            out[1] = static_cast<JSAMPLE>((pixel >> 2) & 0xf8);
            out[2] = static_cast<JSAMPLE>(8 * pixel);
        }
    }

    const int rowStride = 3 * width;
    while (cinfo.next_scanline < cinfo.image_height) {
        JSAMPROW row = rgbBuffer + (rowStride * cinfo.next_scanline);
        jpeg_write_scanlines(&cinfo, &row, 1);
    }

    free(rgbBuffer);
    rgbBuffer = 0;
    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    return 0;
}
```

The `JpegScreenshotDestinationManager` field names are behavior-based and should stay described as first-draft. The `reserved14/reserved18` fields preserve observed offsets without inventing semantics.

## Recommended Target Doc Changes

Accepted callback target changes were applied:

- Metadata is now `COMPLETION:88`, `CONFIDENCE:90`, with `CANONICAL_OWNER:0000K4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K4`, and blank `EMITTER_POSITION_OPTIONAL` preserved.
- The target formal C++ block now contains the exact first-draft block above.
- Item Summary now states B011 MCP proof: session `supervisor_recovery_20260705`, `0x004efbc0-0x004efe94`, `0x2d4` / 724-byte range, main writer `0x222` / 546 bytes, 159 instructions, 16 blocks, error callback 15 instructions and 3 blocks, raw destination body 21 instructions, raw advance body 11 instructions, clean `0xcc` gaps, one raw screenshot-path caller xref, no modeled callers, and post-callback generated output at `88/90`.
- Stale "corrected-gate unassigned status" and blank-C++ language were historicalized or replaced with current owner/emitter wording: ImageWriters owns/emits the product wrapper; ScreenshotCapture owns the raw caller workflow; LibJPEG owns IJG internals.
- Exact byte/padding details and the successor KeySpeedMgr boundary remain present.
- Negative evidence remains present: no direct xrefs to raw destination bodies/null stubs, no xrefs to raw screenshot start, and no transfer of LibJPEG or ScreenshotCapture ownership.
- Score rationale now explains why `88/90` is justified but not higher: the previous broad C++ blocker is resolved, but raw destination callback liveness and exact final names remain unresolved.

## Recommended Support Doc Changes

No support doc edit was required or performed during the implementation callback. Checked support docs already carry same-or-greater ownership detail:

- `by-file/ImageWriters.md` already places UID00018N in `render/ImageWriters.cpp`, excludes LodePNG/LibJPEG internals, and records the raw caller and marker support.
- `by-file/ScreenshotCapture.md` and UID0001G8 already record the raw caller path and preserve ScreenshotCapture workflow ownership.
- `by-file/LibJPEG.md` and UID0000VS already keep IJG compression APIs under LibJPEG while listing UID00018N as product wrapper caller.
- UID0002ZG/UID0002ZL already own the `ff d9` fallback marker data.

If future compile-unit work requires marker emission, the minimal support follow-up would be UID0002ZG/UID0002ZL marker emission for `JpegScreenshotEoiMarker[2]`. That was not required to fix the UID00018N target prose/source-quality blocker and was not broadened during this callback.

## Generated And Tracker Disposition

Historical pre-callback generated/tracker state from the report-only pass:

- `auto-generated/NexusTK/render/ImageWriters.cpp` header shows validator command `000000007492`, refreshed `2026-07-06T00:43:04-04:00`, and UID00018N as `Completion:86 | Confidence:89 | Empty Emitter Marker`.
- `auto-generated/-ag-coverage-report-by-memory.md` header shows command `000000007494`, refreshed `2026-07-06T00:43:27-04:00`, and UID00018N as `emits_code:false`, reconstructable, `86%`, strong.
- `auto-generated/-ag-research-tracker.md` header shows command `000000007497`, refreshed `2026-07-06T00:44:51-04:00`, and UID00018N as `86/89`, combined `87.5`, reconstructable `true`, reports `0`.

Post-callback validator-owned generated/tracker state:

- Scoped validator command `000000007514` refreshed `auto-generated/NexusTK/render/ImageWriters.cpp` at `2026-07-06T01:06:42-04:00` with UID00018N as `Completion:88 | Confidence:90` and emitted formal C++.
- The same command refreshed `auto-generated/-ag-coverage-report-by-memory.md` with UID00018N as `emits_code:true`, `88%`, very-strong.
- At B011 callback completion, `auto-generated/-ag-research-tracker.md` lists UID00018N as `88/90`, combined `89.0`, reconstructable `true`, reports `0`; later supervisor-owned report execution may update lifecycle/report counts.
- Queue status command `000000007515` at `2026-07-06T01:06:59-04:00` showed zero queued/processing generated refresh jobs, so the deferred generated refresh for this target had caught up.

After supervisor execution, validator-owned lifecycle footer, executed archive history, and any later generated refresh headers are authoritative for archival state.

## Score And Metadata Recommendation

| Field | Pre-callback state | Applied callback state | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `86` | `88` | Adds current MCP metrics, exact first-draft C++ route, and resolves the broad "blank until libjpeg fields" blocker while retaining raw callback/liveness caveats. |
| `CONFIDENCE` | `89` | `90` | Live MCP corroborates behavior/range/owner strongly; still capped by no-xref raw callbacks and raw JPG reachability. |
| `CANONICAL_OWNER` | `0000K4` | `0000K4` | ImageWriters remains correct owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Product wrapper is reconstructable. |
| `EMITTER_UIDS` | `0000K4` | `0000K4` | Generated route remains `render/ImageWriters.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No optional-position override is needed. |
| Formal C++ | blank | first-draft block above | Source-ready wrapper can now be emitted, with documented first-draft local callback names. |

## Open Questions With Attempted Resolution

- Exact original file name: attempted via ImageWriters/ScreenshotCapture/LibJPEG source-placement support docs and old reports. Best current placement is `render/ImageWriters.cpp`; no evidence proves a separate original `JpegScreenshotWriter.cpp`.
- Raw JPG path reachability: attempted via MCP lookup/xrefs to `0x00557840` and call-site disassembly. Start remains not a function and has no xrefs; treat as retained/legacy workflow while preserving the one raw writer call at `0x005579d3`.
- Raw destination callback liveness: attempted via `xrefs_to 0x004efe00` and `xrefs_to 0x004efe40`; both remain zero. Bodies are complete and adjacent, but live invocation is not proven.
- Exact destination-manager field names: attempted through raw disassembly and IJG `jpeg_destination_mgr` layout. Current first-draft names preserve exact offsets while keeping unknown fields as `reserved14/reserved18`.
- Marker emission support: UID0002ZG/UID0002ZL already own the `ff d9` marker; target first-draft C++ references it externally. Support emission can be handled separately if supervisor requires compile-unit completeness.

## Final Recommendation

At B011 callback completion, proceed to supervisor Gate 2 / execute review. The accepted target-focused implementation callback is complete: UID00018N is `88/90`, owner/emitter metadata is preserved, the exact formal C++ block is present, target prose/evidence reflects the B011 MCP facts, generated/tracker state is refreshed, and the corrected owner split is documented. After supervisor execution, validator-owned lifecycle history and archive metadata are authoritative.

Do not edit generated files, coverage reports, lifecycle/archive files, validator state, or supervisor ledgers. Do not run `execute_report` or lifecycle/archive commands from B011.

## Validator Results

Scoped target validator was run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the target edit:

- Command: `python .\tools\validator.py --mode file --file by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md --apply --queue-timeout 240`
- Command ID: `000000007514`
- Command timestamp: `2026-07-06T01:06:42-04:00`
- Exit code: `0`
- Result: `ok: 1`, `completion_update: 1`, `confidence_update: 1`, `autogen_registry_update: 2`; UID00018N changed from blank emitted code to a formal C++ block.
- Generated refresh: validator reported `generated_refresh: deferred`, then deferred refresh completed for `auto-generated/NexusTK/render/ImageWriters.cpp`, generated by-memory coverage, and research tracker at command `000000007514`.

Generated freshness check:

- Command: `python .\tools\validator.py --queue-status`
- Command ID: `000000007515`
- Command timestamp: `2026-07-06T01:06:59-04:00`
- Exit code: `0`
- Result: zero queued generated refresh jobs and zero processing generated refresh jobs; `auto-generated/NexusTK/render/ImageWriters.cpp` header shows command `000000007514`, refreshed `2026-07-06T01:06:42-04:00`, source `deferred-generated-refresh`.

## Changed Files

- `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md` - edited by B011 during the implementation callback and validated with command `000000007514`.
- `tools/leaser/Agents/Agent-B011/research/00018N-JpegScreenshotWriter-source-quality.md` - updated by B011 with callback ledger/checklist/validator results.

B011 did not edit support by-* docs, generated files, coverage reports, validator state, lifecycle/archive files, queue files, or supervisor ledgers. B011 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves. Validator-owned side effects from command `000000007514` refreshed `auto-generated/NexusTK/render/ImageWriters.cpp`, generated by-memory coverage, the research tracker row, projected stats, and registry/autogen state.

Lease record: B011 acquired the target by-memory lease immediately before editing; the lease report showed creation `2026-07-06T05:03:29Z` and expiration `2026-07-06T05:08:29Z`. The explicit post-validation unlease attempt returned `Rejected[No active lease]` because the short-lived lease had already expired; the subsequent lease report showed no active B011 lease for UID00018N.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation; this repaired report-only artifact was returned for Gate 1 review before any by-* edits.
- [x] Target/support docs to update recorded: target `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md` only unless the supervisor broadens callback scope for marker emission; support docs were inspected and already sufficient.
- [x] Initial target state and actual evidence checked recorded: at report-only time the target was `86/89`, ImageWriters-owned/emitted, reconstructable, blank formal C++, generated as empty emitter, and tracker reports `0`.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes to apply recorded: update target metadata from `86/89` to `88/90`.
- [x] Score-limiting blockers researched to resolution or evidence-backed remaining caveat: broad C++ blocker resolved; raw destination callback liveness, exact callback names, exact original file name, and raw JPG workflow reachability remain score caps.
- [x] Owner/emitter/reconstructable changes to apply recorded: preserve `CANONICAL_OWNER:0000K4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K4`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child changes to apply recorded: no split, rename, or new child is recommended; reject standalone `JpegScreenshotWriter.cpp`.
- [x] Source-placement/range/padding/reclassification changes to apply or confirm not applicable recorded: keep `NexusTK/render/ImageWriters.cpp`, preserve total range `0x004efbc0-0x004efe94`, internal `0xcc` padding, and KeySpeedMgr successor boundary.
- [x] First-draft C++ to apply recorded: replace blank target formal C++ with the exact block in this report.
- [x] Third-party import directive confirmed not applicable: UID00018N is product wrapper code over public IJG APIs, not a static third-party source embed.
- [x] Exact target/support doc facts to incorporate at report-level detail recorded: MCP session/health, range/metric facts, stack/prototype facts, callee list, caller evidence, RGB565/RGB555 formulas, raw callback facts, null stub facts, fallback marker xref, padding spans, generated/tracker state, and owner split.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve recorded: historicalize stale blank-C++ rationale; preserve rejected ScreenshotCapture direct owner, LibJPEG direct owner, ImageLoaders, marker-data owner, and standalone source-file placement.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale where applicable; no current explicit override required their use.
- [x] Open questions closed or documented as evidence-backed unresolved: exact original file name, raw JPG path reachability, raw destination callback liveness, exact destination-manager field names, and marker emission support.
- [x] Validators to run after callback recorded: only scoped validator(s) for edited by-* docs; target validator should be run if the target is edited.
- [x] Generated report refresh expected after callback recorded: generated `ImageWriters.cpp`, coverage, and tracker state should refresh through validator-owned mechanisms if target changes are applied.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: accepted SHA `E8667D064D66E104299A84DBFA0DE7F738BC92AE77AADE9F0CE623271BB5BEFF`.
- [x] Update target metadata from `86/89` to `88/90`: applied and validator command `000000007514` recorded `completion_update: 1` and `confidence_update: 1`.
- [x] Preserve `CANONICAL_OWNER:0000K4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K4`, and blank `EMITTER_POSITION_OPTIONAL`: confirmed in target after edit/validation.
- [x] Replace blank target formal C++ with the exact block in this report: applied; generated `ImageWriters.cpp` now emits UID00018N code at `88/90`.
- [x] Update target Item Summary with current B011 MCP session/range/metric/generated-state facts: applied with session `supervisor_recovery_20260705`, `0x2d4` / 724-byte range, instruction/block counts, raw body sizes, caller/callee state, and post-validator generated state.
- [x] Add current MCP health/session provenance to target evidence: applied in the B011 MCP evidence section.
- [x] Add exact total range `0x2d4` / 724 bytes, main `0x222` / 546 bytes, raw body sizes, instruction/block counts, and stack/prototype facts: applied in target evidence.
- [x] Preserve callee list and map public IJG APIs to LibJPEG: applied in target callee/library-boundary prose.
- [x] Preserve caller evidence: no modeled callers, one raw call at `0x005579d3`, exact argument pushes: applied in target caller evidence.
- [x] Preserve raw destination callback evidence and explicitly label no-xref liveness as unresolved: applied in target raw callback evidence and score caveats.
- [x] Preserve null stub evidence and avoid overclaiming exact original names: applied; names remain behavior-based/first-draft.
- [x] Preserve `0x0066db40` fallback marker xref and keep marker data ownership separate: applied; marker data remains under UID0002ZG/UID0002ZL.
- [x] Preserve all `0xcc` padding spans and KeySpeedMgr successor boundary: applied in target padding/boundary evidence.
- [x] Historicalize stale target language about C++ being blank until libjpeg fields are final; replace with first-draft C++ rationale and remaining caveats: applied in target status/changes/rationale.
- [x] Reject ownership alternatives in target prose: ScreenshotCapture direct owner, LibJPEG direct owner, ImageLoaders, marker data owner, standalone `JpegScreenshotWriter.cpp`: applied in target assignment/library-boundary sections.
- [x] Keep support docs unchanged unless supervisor broadens callback scope or a direct contradiction is found: no direct support contradiction found; no support docs edited.
- [x] Run only scoped validator(s) for edited by-* docs and record command IDs/timestamps/exits/generated refresh in the report: target validator `000000007514` exit `0`, `ok: 1`; queue/generated check `000000007515` exit `0`.
- [x] Update Claim And Incorporation Ledger with applied/already-present/excluded verification states after implementation callback: applied above for every accepted claim.
- [x] List any remaining unapplied accepted item with exact blocker before returning for supervisor execute: no accepted target item remains unapplied; support docs were excluded-with-reason because no direct contradiction was found.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000007525","destination_path":"executed-b-agent-research/B011/00018N-JpegScreenshotWriter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00018N-JpegScreenshotWriter-source-quality.md","timestamp":"2026-07-06T01:19:33-04:00","uid":"00018N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
