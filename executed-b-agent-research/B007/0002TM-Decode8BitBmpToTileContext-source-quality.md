** TARGET-REPORT-UID:0002TM **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002TM Decode8BitBmpToTileContext Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002TM] as source-authored, source-bearing `ImageLoaders` code. This is not no-code glue and not compiler-generated.
- Recommended source-quality function shape: `void __cdecl Decode8BitBmpToTileContext(const unsigned char* bmpData, int bmpDataSize, EPFTileContext* destination, DLPalette* palette)`.
- Recommended source-facing name: keep `Decode8BitBmpToTileContext` as the canonical documentation/IDA name. The generated MainMenuPane view uses a broader `DecodeBMP` call name, but the binary behavior only accepts full BMP files with `BM`, `biBitCount == 8`, an embedded 256-entry RGBQUAD palette, and byte-pixel output, so the precise `Decode8BitBmpToTileContext` name is the safer source-quality doc name.
- Recommended source file route: keep owner/emitter [UID:0000K3] `ImageLoaders`, proposed path `NexusTK/render/ImageLoaders.cpp`.
- Required implementation if accepted: update the target's stale two-argument signature and palette wording, add the four-argument callsite evidence, populate first-draft C++, and sync support docs/coverage row text below.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | keep `0000K3` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `0000K3` |
| Formal C++ | populate first-draft source-style helper C++ |

## Target

- Target UID: [UID:0002TM]
- Target path: `source-3/project-documentation/by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0002TM-Decode8BitBmpToTileContext-source-quality.md`
- Current target score/state: `85/86`, `CANONICAL_OWNER:0000K3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K3`, blank C++.
- Current target issue: source-authored status and owner are correct, but the working signature is stale (`bmpBuffer, destination` only), `0x00542cd0` is mis-described as palette initialization, final C++ is blank, and the target still treats palette/helper names as blockers.

## Supervisor / Workflow Recheck

- This is a B-agent report-only source-quality pass. No target/support by-* docs were edited.
- `by-memory/-coverage-report.md` was not edited; exact replacement row text is included below.
- The required report file did not exist before this pass.
- I did not coordinate with A/C agents.
- Completed older B007 reports were left in place. The current B007 research folder contains older reports such as `000125`, `00015G`, `00018P`, `00019M`, `0001C0`, and `00026T`; no older report was overwritten or moved.
- Fresh IDA MCP access was attempted at `http://127.0.0.1:13337/mcp` and failed with `Unable to connect to the remote server`. This report therefore uses current by-* docs plus local IDA exports under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.

## Evidence Checked

- Required guidance: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `Agent-B007/goal.md`, `by-structure.md`, and `inference_research.md`.
- Target and parent docs:
  - `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`
  - `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
  - sibling wrapper pages for ZPF/FPF/JPF/JPEG decode helpers.
  - `by-file/ImageLoaders.md`
- Destination/palette support docs:
  - `by-class/EPFTileContext.md`
  - `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
  - `by-file/EPFTileContext.md`
  - `by-class/DLPalette.md`
  - `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`
  - `by-file/Palette.md`
- Caller context:
  - `by-file/MainMenuPane.md`
  - `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`
  - `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
  - `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`
  - `source-3/simroot_v2/class_MainMenuPane.cpp`
- Local IDA exports:
  - `NexusTK.exe.c`
  - `NexusTK.exe.lst`
  - `NexusTK.exe.map`
- `int_convert.py` verified these conversions: `0xda` / decimal `218`, `0x1fc` / decimal `508`, `0x224` / decimal `548`, `0x28` / decimal `40`, BMP offsets `0x0a` / `10`, `0x0e` / `14`, `0x12` / `18`, `0x16` / `22`, `0x1c` / `28`, palette size `0x400` / `1024`, count `0x100` / `256`, and palette table default offset `0x36` / `54`.

## Raw Export Facts

### Range And Padding

- Local `.lst` confirms `sub_4D09B0 proc near` starts at `0x004d09b0` and ends at `0x004d0a89` with `retn`.
- The half-open range is therefore `0x004d09b0-0x004d0a8a`; size `0xda` / decimal `218` (Verified with `int_convert.py`).
- The `.lst` immediately shows `align 10h` at `0x004d0a8a`, then `sub_4D0A90` begins at `0x004d0a90`. Existing target/aggregate IDA notes identify the six bytes `0x004d0a8a-0x004d0a90` as `0xcc` padding. This recheck found no evidence to change the range.

### Signature And Direct Caller

Local `.c` export prototype:

```c
char *__cdecl sub_4D09B0(char *a1, int a2, int a3, _DWORD *a4)
```

Local `MainMenuPane` constructor call at `0x004f68bd`:

```asm
004F68A9 lea     eax, [esi+224h]
004F68AF push    eax
004F68B0 lea     eax, [esi+1FCh]
004F68B6 push    eax
004F68B7 push    [ebp+var_24]
004F68BA push    [ebp+Block]
004F68BD call    sub_4D09B0
```

This proves four caller-cleaned arguments:

| Argument | Evidence | Recommended type/name |
| --- | --- | --- |
| `arg0` | `[ebp+Block]` loaded by `StdioFile::ReadAll` into `_AUTOBUF<unsigned char>` | `const unsigned char* bmpData` |
| `arg1` | `[ebp+var_24]` auto-buffer length; not read inside `0x004d09b0` | `int bmpDataSize` |
| `arg2` | `this + 0x1fc`, decimal `508` (Verified with `int_convert.py`) | `EPFTileContext* destination` |
| `arg3` | `this + 0x224`, decimal `548` (Verified with `int_convert.py`) | `DLPalette* palette` |

The decompiler's `char*` return is a byproduct of `EAX` holding scratch pointers / `_memmove` return. The caller ignores it, and the source-facing return type should be `void`.

### Callee Set

The `.lst` body has exactly these behavioral callees:

| Call site | Raw callee | Source-quality name |
| --- | --- | --- |
| `0x004d09bc` | `sub_458500` | `EPFTileContext::ReleaseBuffers` |
| `0x004d09c4` | `sub_542CD0` | `DLPalette::FreePaletteData` |
| `0x004d0a16` | `sub_4583D0` | `EPFTileContext::AllocateBytePixels` |
| `0x004d0a26` | `sub_543020` | `DLPalette::LoadFromRawRGBA` / raw BMP RGBQUAD table loader |
| `0x004d0a48`, `0x004d0a6c` | `_memmove` | row/contiguous byte copy |

No `EPFTileContext::NormalizePostDecodePixels` call occurs because this helper produces indexed/byte pixels, not 16-bit pixels.

## Behavior Resolved

- The helper first releases any existing destination buffers.
- It calls `DLPalette::FreePaletteData` on the caller-supplied output palette. This is not a constructor and not generic "initialization"; it clears optional palette entry/remap data while leaving the object alive.
- It validates a full BMP file header, not a bare DIB:
  - byte `+0x00` must be `'B'`;
  - byte `+0x01` must be `'M'`;
  - `bfOffBits` at file offset `+0x0a` supplies the pixel-data pointer.
- It then treats `bmpData + 0x0e` (decimal `14`, Verified with `int_convert.py`) as the DIB info header:
  - `biSize` at DIB `+0x00` is used to locate the palette table at `bmpData + 0x0e + biSize`;
  - width is read at file offset `+0x12` / DIB `+0x04`;
  - signed height is read at file offset `+0x16` / DIB `+0x08`;
  - `biBitCount` is read at file offset `+0x1c` / DIB `+0x0e` and must be `8`.
- On success it writes `destination->pixelMode = 1`, then calls `EPFTileContext::AllocateBytePixels(width, abs(height))`. The allocation helper also sets `pixelMode = 1`, row stride to width, `bounds.right = width`, `bounds.bottom = abs(height)`, and zero-origin left/top.
- It calls `DLPalette::LoadFromRawRGBA` with the embedded BMP palette table. That method writes the `"DLPalette"` header, sets data offset `0x20` / `32`, count `0x100` / `256`, zero optional entry/remap count, and converts `0x400` / `1024` bytes of four-byte BGRA/RGBQUAD-style palette entries into native 16-bit colors.
- Pixel copy behavior:
  - Negative height: source rows are already top-down, so it copies `width * abs(height)` bytes contiguously into `destination->pixelData`.
  - Positive height: source rows are bottom-up, so it reads forward from `bfOffBits` but writes each row to descending destination offsets.
  - The helper advances the source by `width` bytes per row and does not compute a DWORD-aligned BMP row stride. Do not "fix" this in first-draft C++; exact behavior expects tightly packed rows or a width/resource where this is already compatible.
- The `bmpDataSize` argument is passed by the only caller but not read in this optimized body. Preserve it in the source signature for callsite fidelity and mark it intentionally unused in the draft.

## Source Name, Type, And Placement Decisions

| Question | Recommendation | Evidence / rejected alternatives |
| --- | --- | --- |
| Source placement | [UID:0000K3] `ImageLoaders`, `NexusTK/render/ImageLoaders.cpp` | Sibling wrappers, `by-file/ImageLoaders.md`, and the shared image decode neighborhood all route here. MainMenuPane is only the consumer. |
| Canonical function name | `Decode8BitBmpToTileContext` | Best doc/IDA name because the helper is a full BMP-file decoder, only supports 8-bit indexed images, fills `EPFTileContext`, and writes a `DLPalette`. |
| Broader `DecodeBMP` name | Mention as a possible original callsite spelling, but do not use as canonical without source symbols | Generated `class_MainMenuPane.cpp` uses `DecodeBMP(...)`, but that is broad and hides the 8-bit-only/paletted constraints. |
| `DIB` naming | Reject as canonical | The helper validates `BM` and uses `bfOffBits`; this is not a bare DIB-buffer decoder even though it reads the DIB info header after the file header. |
| Destination type | `EPFTileContext* destination` | `this+0x1fc` has size-compatible separation from palette at `+0x224`; EPFTileContext is `0x28` / decimal `40` bytes (Verified with `int_convert.py`). |
| Destination fields | use working names `pixelMode`, `pixelData`, `rowStride`, `bounds` | Matches current EPFTileContext support docs and allocation helper behavior. |
| Palette type | `DLPalette* palette` | Constructor at `MainMenuPane+0x224`, `DLPalette` docs, and callees `FreePaletteData` / `LoadFromRawRGBA` all support this. |
| Raw/compiler names | Remove raw names from source-facing wording | No compiler-generated wrapper pattern; `sub_4D09B0`, `sub_542CD0`, and `sub_543020` should be replaced by source-quality names in docs/IDA. |

## First-Draft C++

Populate the target C++ block if the supervisor accepts this report. This draft preserves the binary behavior, including the unused size argument and lack of BMP row-stride alignment.

```cpp
#pragma pack(push, 1)
struct BmpFileHeader
{
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int bitsOffset;
};

struct BmpInfoHeader
{
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitCount;
};
#pragma pack(pop)

void Decode8BitBmpToTileContext(
    const unsigned char* bmpData,
    int bmpDataSize,
    EPFTileContext* destination,
    DLPalette* palette)
{
    (void)bmpDataSize;

    destination->ReleaseBuffers();
    palette->FreePaletteData();

    const BmpFileHeader* fileHeader =
        reinterpret_cast<const BmpFileHeader*>(bmpData);
    if (fileHeader->type != 0x4d42) {
        return;
    }

    const BmpInfoHeader* infoHeader =
        reinterpret_cast<const BmpInfoHeader*>(bmpData + sizeof(BmpFileHeader));
    if (infoHeader->bitCount != 8) {
        return;
    }

    const int width = infoHeader->width;
    const int signedHeight = infoHeader->height;
    const int height = signedHeight < 0 ? -signedHeight : signedHeight;

    destination->pixelMode = 1;
    destination->AllocateBytePixels(width, height);

    const unsigned char* paletteData =
        bmpData + sizeof(BmpFileHeader) + infoHeader->size;
    palette->LoadFromRawRGBA(paletteData);

    const unsigned char* sourcePixels = bmpData + fileHeader->bitsOffset;
    unsigned char* destinationPixels =
        static_cast<unsigned char*>(destination->pixelData);

    if (signedHeight < 0) {
        memmove(destinationPixels, sourcePixels, width * height);
        return;
    }

    for (int row = 0; row < height; ++row) {
        memmove(
            destinationPixels + width * (height - row - 1),
            sourcePixels,
            width);
        sourcePixels += width;
    }
}
```

Implementation notes:

- If project style already has `BITMAPFILEHEADER`, `BITMAPINFOHEADER`, `BYTE`, `WORD`, `DWORD`, or `LONG`, use those instead of local structs.
- If `EPFTileContext` fields remain private in the reconstructed tree, either make this helper a friend/local implementation helper or use the existing class's internal layout convention. Do not invent a setter unless the support docs establish one.
- Do not add null checks, size bounds checks, compressed-BMP checks, palette-count checks, or DWORD row-stride alignment in this exact first draft; those would improve safety but would not match the observed body.

## Exact Recommended Target Changes

For `source-3/project-documentation/by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`:

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. In `Status`, replace the current confidence/source wording with:

```markdown
- Source-facing role: `Decode8BitBmpToTileContext`; possible broad callsite spelling `DecodeBMP` is noted but not used as canonical because the body is specifically an 8-bit paletted BMP-file-to-EPFTileContext decoder.
- Confidence: very strong for range, padding, four-argument signature, direct `LEVEL.BMP` caller, BMP field map, destination/palette helper identities, and first-draft C++; medium for exact original spelling of the helper name.
```

3. Replace `Behavior` with:

```markdown
This helper decodes an 8-bit paletted BMP file buffer into an `EPFTileContext` byte-pixel destination and a caller-supplied `DLPalette`.

The helper:

- releases the destination through `EPFTileContext::ReleaseBuffers`;
- clears caller-supplied palette optional data through `DLPalette::FreePaletteData`;
- validates the BMP file signature `BM`;
- treats `bmp + 0x0e` as the DIB info header and requires `biBitCount == 8`;
- reads width at file offset `+0x12` and signed height at `+0x16`;
- writes `destination->pixelMode = 1` and calls `EPFTileContext::AllocateBytePixels(width, abs(height))`;
- loads the embedded 256-entry BMP RGBQUAD palette through `DLPalette::LoadFromRawRGBA(bmp + 0x0e + biSize)`;
- reads pixels from `bmp + bfOffBits`;
- copies negative-height BMP data as top-down contiguous bytes;
- copies positive-height BMP data bottom-up by writing each forward-read source row into descending destination row offsets;
- advances source rows by `width` bytes and does not compute DWORD-aligned BMP row stride.
```

4. Replace `Signature And Layout Notes` with:

```markdown
Working source-facing signature:

    void Decode8BitBmpToTileContext(
        const unsigned char* bmpData,
        int bmpDataSize,
        EPFTileContext* destination,
        DLPalette* palette);

`bmpDataSize` is passed by the sole caller but not read by the optimized body; keep it for callsite/source fidelity and mark it intentionally unused in the draft C++.

Caller `MainMenuPane::MainMenuPane` passes the auto-buffer pointer, auto-buffer byte count, `this + 0x1fc` (`EPFTileContext*`), and `this + 0x224` (`DLPalette*`) at call site `0x004f68bd`.
```

5. Update `Touched State And Dependencies` bullets to:

```markdown
- `EPFTileContext::ReleaseBuffers` (`0x00458500`) and `EPFTileContext::AllocateBytePixels` (`0x004583d0`) own the destination lifecycle/allocation behavior.
- `DLPalette::FreePaletteData` (`0x00542cd0`) clears optional palette entry/remap data before validation.
- `DLPalette::LoadFromRawRGBA` (`0x00543020`) stamps the `DLPalette` header and converts the BMP RGBQUAD table into 256 native 16-bit colors.
- `_memmove` copies indexed byte pixels into `destination->pixelData`.
```

6. Add the first-draft C++ block from this report.

7. Replace `Open Questions` with:

```markdown
- Exact original spelling remains unproven: `DecodeBMP` is plausible from generated caller context, but `Decode8BitBmpToTileContext` is the safer canonical doc/IDA name because it captures the 8-bit indexed output and destination type.
- Live IDA MCP should be retried when available to reconfirm the local export evidence, but no current evidence blocks first-draft C++.
```

## Exact Recommended Support-Doc Updates

### `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`

Update the `0002TM` row/notes to say:

```markdown
`Decode8BitBmpToTileContext` at `0x004d09b0-0x004d0a8a` is the four-argument `LEVEL.BMP` helper: `const unsigned char* bmpData`, unused caller-supplied byte count, `EPFTileContext* destination`, and `DLPalette* palette`. It releases the destination, clears the palette through `DLPalette::FreePaletteData`, validates `BM` plus `biBitCount == 8`, allocates byte pixels, loads the embedded RGBQUAD table through `DLPalette::LoadFromRawRGBA`, and copies rows top-down or bottom-up without DWORD stride alignment.
```

### `by-file/ImageLoaders.md`

Update the proposed contents row for [UID:0002TM] to:

```markdown
| [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) | `0x004d09b0-0x004d0a8a` | `Decode8BitBmpToTileContext(const unsigned char* bmpData, int bmpDataSize, EPFTileContext* destination, DLPalette* palette)`; 8-bit paletted BMP file decoder used by `MainMenuPane` for `LEVEL.BMP`. |
```

Add a note:

```markdown
The BMP helper takes both an `EPFTileContext*` and a `DLPalette*`; the byte-count argument is passed by the `AUTOBUF<unsigned char>` caller but is not read in the optimized body.
```

### `by-file/MainMenuPane.md`

Add/replace the `LEVEL.BMP` note with:

```markdown
The constructor checks `LEVEL.BMP`, reads it into an `_AUTOBUF<unsigned char>`, then calls [UID:0002TM] at `0x004f68bd` with `(buffer, byteCount, this + 0x1fc, this + 0x224)`. The offsets are the `EPFTileContext` background image and `DLPalette` background palette. The decode helper stays owned by [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
```

### `by-class/DLPalette.md` and `by-memory/0x00542ac0-0x00543149.DLPaletteMethodCluster.md`

Add a consumer note under `LoadFromRawRGBA`:

```markdown
`Decode8BitBmpToTileContext` calls `DLPalette::LoadFromRawRGBA` with the embedded BMP RGBQUAD table at `bmp + sizeof(BITMAPFILEHEADER) + biSize`; in this context the four-byte entries are BMP BGRA/RGBQUAD-style entries, not a DAT stream palette.
```

### `by-class/EPFTileContext.md` / `by-file/EPFTileContext.md`

Update the `AllocateBytePixels` caller evidence to:

```markdown
`Decode8BitBmpToTileContext` calls `AllocateBytePixels` at `0x004d0a16` after validating an 8-bit BMP; width becomes `rowStride` and `bounds.right`, while `abs(signedHeight)` becomes `bounds.bottom`. The helper writes indexed byte pixels directly to `pixelData` and does not call `NormalizePostDecodePixels`.
```

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` during B-report review. If the implementation is accepted, replace the existing [UID:0002TM] row with:

```markdown
        - [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) 0x004d09b0-0x004d0a8a | function | Decode8BitBmpToTileContext : reconstructable : 88% : very strong : B007 source-quality pass; exact `0xda` / 218-byte range, six-byte `0xcc` postpad, single MainMenuPane `LEVEL.BMP` caller at `0x004f68bd`, four-argument `Decode8BitBmpToTileContext` signature, `EPFTileContext` byte-pixel output, `DLPalette::FreePaletteData`/`LoadFromRawRGBA` palette route, BMP file-header/DIB-header field map, top-down/bottom-up row-copy behavior without DWORD row-stride alignment, and first-draft C++ readiness documented.
```

## Validation Commands

Commands already used or suitable for implementation verification:

> Executable block R001 was removed from this report and preserved verbatim in [0002TM-Decode8BitBmpToTileContext-source-quality-removed.md](0002TM-Decode8BitBmpToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R002 was removed from this report and preserved verbatim in [0002TM-Decode8BitBmpToTileContext-source-quality-removed.md](0002TM-Decode8BitBmpToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

> Executable block R003 was removed from this report and preserved verbatim in [0002TM-Decode8BitBmpToTileContext-source-quality-removed.md](0002TM-Decode8BitBmpToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After implementation, run the repository's normal documentation/coverage validators if available, plus targeted checks:

> Executable block R004 was removed from this report and preserved verbatim in [0002TM-Decode8BitBmpToTileContext-source-quality-removed.md](0002TM-Decode8BitBmpToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Fresh live IDA MCP validation to run when the endpoint is available:

- `lookup_funcs 0x004d09b0`
- `decompile 0x004d09b0`
- `callers 0x004d09b0`
- `callees 0x004d09b0`
- byte check for `0x004d0a8a-0x004d0a90`.

## IDA Rename / Type / Comment Recommendations

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x004d09b0` | Rename `sub_4D09B0` to `Decode8BitBmpToTileContext` | High |
| `0x004d09b0` | Apply type `void __cdecl Decode8BitBmpToTileContext(const unsigned char* bmpData, int bmpDataSize, EPFTileContext* destination, DLPalette* palette)` | High |
| `0x004d09bc` | Callee type/comment `EPFTileContext::ReleaseBuffers(destination)` | High |
| `0x004d09c4` | Callee type/comment `DLPalette::FreePaletteData(palette)` | High |
| `0x004d0a16` | Callee type/comment `EPFTileContext::AllocateBytePixels(width, absHeight)` | High |
| `0x004d0a21-0x004d0a26` | Comment: `paletteData = bmp + sizeof(BITMAPFILEHEADER) + biSize` | High |
| `0x004d0a26` | Callee type/comment `DLPalette::LoadFromRawRGBA(palette, paletteData)`; alternate comment `BMP RGBQUAD table` | High for behavior, medium-high for exact method spelling |
| `0x004d0a2e-0x004d0a33` | Comment: `sourcePixels = bmp + bfOffBits` | High |
| `0x004d0a3c-0x004d0a50` | Comment: `negative height: top-down contiguous copy` | High |
| `0x004d0a57-0x004d0a81` | Comment: `positive height: bottom-up row copy, source stride is width bytes` | High |
| `0x004f68bd` | Comment call as `Decode8BitBmpToTileContext(buffer, byteCount, &m_backgroundTile, &m_backgroundPalette)` | High |

Suggested struct/type imports:

```cpp
struct EPFTileContext; // 0x28-byte render/image context
class DLPalette;
```

Use packed BMP header structs or Win32 `BITMAPFILEHEADER` / `BITMAPINFOHEADER` when available.

## Open Questions And Attempted Resolution

| Question | Resolution |
| --- | --- |
| Should this stay source-bearing? | Yes. It is ordinary project image-loader logic with direct caller/callee evidence and first-draft C++ readiness. |
| Is this no-code compiler glue? | No. It has validation, allocation, palette conversion, and row-order logic; no scalar-deleting/destructor/thunk pattern. |
| Does the signature have two or four args? | Four args. Target's two-arg signature is stale; local caller and export prove `(bmpData, bmpDataSize, destination, palette)`. |
| Is `0x00542cd0` palette initialization? | No. DLPalette docs and local export show it is `DLPalette::FreePaletteData`. It clears optional data; construction happened earlier in `MainMenuPane`. |
| Is `0x00543020` a bitmap-handle loader? | No. It is `DLPalette::LoadFromRawRGBA`, a raw 256-entry four-byte palette converter. `DLPalette::LoadFromBitmapPalette` is the separate `0x005430a0` method. |
| BMP or DIB naming? | BMP. The body validates `BM` and reads `bfOffBits`; it only uses the DIB info header after the BMP file header. |
| What about standard BMP row alignment? | The body does not align source rows to 4 bytes. Document exact behavior and do not add row-stride math in the first draft. |
| Exact original spelling? | No symbol proof found. `DecodeBMP` is plausible from generated MainMenuPane code, but `Decode8BitBmpToTileContext` is the best source-quality canonical doc/IDA name because it encodes the actual restrictions and destination. |
| Is `bmpDataSize` an implementation blocker? | No. It is a real callsite argument but unused in the optimized body. Preserve it and mark intentionally unused. |

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

- Update only the target page and listed support docs.
- Populate the target C++ block with the draft above or project-style equivalent.
- Update `by-memory/-coverage-report.md` only from the exact row text above.
- Do not move ownership to MainMenuPane; only add MainMenuPane caller/consumer context.
- Do not add safety checks or BMP stride correction unless a separate source-fidelity decision accepts binary behavior drift.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002TM-Decode8BitBmpToTileContext-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0002TM"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TM-Decode8BitBmpToTileContext-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002TM-Decode8BitBmpToTileContext-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
