*** UID:0000U9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for CreateDIBitmapFromPcxBuffer is covered by [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CreateDIBitmapFromPcxBuffer 0x004A18B0

## Status

- Confidence: strong for behavior and owner relationship.
- Entity kind: free image-loader helper.
- Likely source module: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Owner/emitter route: [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- Exact range: `0x004a18b0-0x004a1b0c`
- Current IDA label: `CreateDIBitmapFromPcxBuffer` saved on 2026-06-16.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now documents the exact function boundary, one-caller PCX loader route, one PCX decoder callee, DIBitmap allocation/construction, DIB-section validation, clipped row-copy loop, cleanup paths, ImageLoaders owner/emitter route, and saved IDA entry label. |
| Confidence | 91 | Live IDA MCP evidence agrees with the exact memory child [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md), the ImageLoaders file page, and the PCX decoder page, and the function name is now saved in IDA. Confidence remains below final-source level because the exact source signature, DIB/PCX local type names, and helper/member names are not final-audit quality. |

## Behavior

`CreateDIBitmapFromPcxBuffer` decodes an 8-bit PCX buffer to temporary RGB565 pixels, allocates and constructs a `DIBitmap`, validates the DIB pixel pointer, copies each decoded row into the DIB section using the DIB's aligned stride, frees the temporary decode buffer, and returns the bitmap.

It returns null on decode failure, invalid dimensions, allocation failure, or DIB-section pixel failure.

IDA MCP confirms one direct caller, `LoadPcxImage` at `0x004a1876`, and a direct call to `DecodePcxToRgb565Buffer` at `0x004a18f5`.

## 2026-06-14 Live IDA Refresh

- `lookup_funcs` resolves `0x004a18b0` to `sub_4A18B0`, size `0x25c`; `0x004a1b0c` is not a function. Decimal size `604 == 0x25c` was verified with `int_convert.py`.
- `analyze_function 0x004a18b0` reports one caller, eight callees, and a 12-complexity body; `xrefs_to 0x004a18b0` reports the single code ref at `0x004a1876` inside `sub_4A17B0`.
- Targeted decompilation shows the decoder call `sub_549410(a2, a3, &Block, &width, &height, a4, 0)`, returning null when decode fails, dimensions are nonpositive, or the decoded block is null.
- The factory allocates `60 == 0x3c` bytes for the DIBitmap object, verified with `int_convert.py`, initializes the DIBitmap vtable, creates a top-down 16-bit DIB section, and uses a 40-byte bitmap header (`40 == 0x28`, verified with `int_convert.py`).
- The row-copy loop copies `2 * min(decodedWidth, dibWidth)` bytes per row, advances by the DIB's aligned stride, frees the temporary decode block, and destroys the DIBitmap object when the DIB bits pointer is absent.
- Final reconstruction C++ stays blank even though the score/emitter minimum now clears: the final source-level signature, DIBitmap field names, PCX decoder result type, and allocator/free wrapper names are still below source-quality evidence.

## 2026-06-16 Live IDA Refresh

- Live IDA MCP `analyze_function 0x004a18b0` reconfirmed prototype `_DWORD *__cdecl(HDC hdc, int, int, int)`, size `604`, one caller `LoadPcxImage`, and xref `0x004a1876`.
- Decompilation reconfirmed `DecodePcxToRgb565Buffer` at `0x00549410`, rejection of negative decode results/nonpositive dimensions/null decoded block, 60-byte DIBitmap allocation, vtable write, 16-bit top-down DIB-section setup, row copy with `memmove`, and decoded-buffer free.
- Dry-run rename accepted `sub_4A18B0 -> CreateDIBitmapFromPcxBuffer`; C001 applied the function label, saved `NexusTK.exe.i64`, and post-save `lookup_funcs` verified the label at `0x004a18b0`.
- Source-quality decision: the entry label is safe, but prototype, locals, DIBitmap member names, PCX decode-result type, and final C++ remain unsafe because the current decompiler still relies on provisional helper/member names.

## Cross-References

- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)

## Changes

- 2026-07-01 B009 ImageLoaders empty-emitter implementation:
  - Formal C++ changed from blank to a covered-by comment pointing to exact by-memory child [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md).
  - Summary/evidence: this item page is a name-centric alias for the exact PCX-to-DIB factory. The accepted report preserves the item-level decoder/DIB evidence here while routing the first-draft implementation through the exact by-memory page to avoid duplicate generated bodies.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md), and stale generated-source wording was removed.
  - Before: the PCX-to-DIB helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned image loader source under the validated ImageLoaders file root; C++ remains blank because final helper names and DIB/PCX type declarations are not at source-quality evidence.
  - Evidence: live IDA MCP confirms `sub_4A18B0` at `0x004a18b0`, size `0x25c`, one direct caller from `sub_4A17B0`, and the direct PCX decoder callee at `0x00549410`.

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented PCX-to-DIB behavior, owner relationship, one caller, and decode helper link but remained unevaluated.
  - After: score reflects documented decode/allocation/validation/copy/free failure behavior and source placement.
  - Evidence: IDA notes confirm direct caller `LoadPcxImage`, direct call to [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md), and the linked DIBitmap/PCX loader memory range.

- 2026-06-14 A001: Raised from `82/88` to `85/90`.
  - Before: the page had correct ownership and behavior but lacked current score rationale, current code-entry wording, and written evidence for the DIB allocation/row-copy details.
  - After: added live IDA MCP boundary/caller/decompile refresh, `int_convert.py`-verified allocation/header constants, explicit source-quality blocker text, and current owner/emitter terminology.

- 2026-06-16 C001 safe IDA refresh:
  - Before: `85/90`, with current behavior evidence but IDA still named the entry `sub_4A18B0`.
  - After: raised to `86/91`, saved the `CreateDIBitmapFromPcxBuffer` IDA label, and kept owner/emitter route through [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md). Final C++ remains blank because the exact source signature, DIBitmap field names, and PCX decoder output type remain provisional.
  - Evidence: IDA MCP `analyze_function`, `rename` dry-run/apply, `idb_save`, and post-save `lookup_funcs` on 2026-06-16.
