*** UID:0000TV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// This by-item page is a legacy alias for the canonical by-memory
// reconstruction [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md). Emitted source is covered there; no
// standalone duplicate body is emitted for [UID:0000TV].
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlphaBlendSpan16 0x00460500

## Status

- Confidence: strong for behavior and source ownership.
- Entity kind: free render helper.
- Likely source module: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Autogen parent: [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- Exact range: `0x00460500-0x00460709`
- Formal C++: emitted on [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md) for the dispatcher/scalar-tail body. 2026-06-30 B013 resolves this by-item alias with a covered-by comment, and sibling block/helper rows now have their own accepted code or covered-by dispositions.

## Behavior

`AlphaBlendSpan16` blends RGB565 source rows into destination rows. It divides each row into four-pixel blocks and a scalar tail. For an exact 50 percent weight (`16` of `32`), it dispatches block work to `HalfBlendSpan16Blocks` and half-blends tail pixels directly. For other weights, it dispatches block work to `AlphaBlendSpan16Blocks` with source-side weight `32 - alpha32` and performs the scalar RGB565 weighted tail inline.

IDA decompilation exposes an `int` return because `eax` is live on exit, but the only direct caller at `0x004c2ad4` discards `eax`. Treat the source-level contract as a side-effect span helper unless a future caller proves a meaningful return value.

## Evidence

- 2026-06-05 live IDA MCP `lookup_funcs` reports `sub_460500` at `0x00460500-0x00460709`, size `0x209`, 185 decoded instructions.
- 2026-06-05 live IDA MCP reports one direct caller at `0x004c2ad4` in the `0x004c0f80` render path; the call site immediately adjusts the stack and returns through the caller's epilogue without reading `eax`.
- The function body has two direct calls: `0x00460544 -> sub_460C10` for the half-blend block path and `0x004605fd -> sub_460B00` for the weighted block path.
- The scalar tails are inline: the half path uses `0x7bef` and `0x0821`, while the weighted path uses `0xf81f` and `0x07e0` and shifts weighted sums by 5.
- The helper is state-free and only performs 16-bit blend math and source/destination pitch advancement.
- 2026-06-29 B002 implementation accepted the source-quality split: this item's dispatcher/scalar-tail C++ can emit now, while `AlphaBlendSpan16Blocks` and `HalfBlendSpan16Blocks` remain blank formal bodies until their own MMX inline-assembly/intrinsic source forms are chosen.

## Cross-References

- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md)
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md)
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md), and stale generated-source evidence wording was replaced with live IDA evidence.
  - Before: the item was unclassified and its current evidence section still cited generated metadata.
  - After: it is marked as a NexusTK-owned render helper under the validated SoftwareBlend16 file root. The former `95/95` family-wide blank-C++ rationale was superseded by the 2026-06-29 B002 implementation callback, which emits the dispatcher/scalar-tail body while leaving the MMX block helpers blank.
  - Evidence: live IDA MCP confirms `sub_460500` at `0x00460500`, size `0x209`, one direct caller in `sub_4C0F80`, and block-helper callees `0x00460c10` and `0x00460b00`.
- 2026-06-29 B002 implementation callback:
  - Synchronized item status with [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md) after inserting the accepted `AlphaBlendSpan16(...)` formal C++ there.
  - Preserved [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) ownership and rejected [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) as a caller/consumer context, not direct owner.
- 2026-06-05 A001 correction:
  - Corrected the scalar-tail and return-value summary after a live IDA call-site audit.
  - The weighted scalar tail is inline in `sub_460500`; it does not call `BlendRgb565Pixel`.
  - The only direct caller does not consume `eax`, so the item no longer claims a meaningful advanced-pointer return contract.

- 2026-05-30: Grading changed from unevaluated `0/0` to `88/92`.
  - Before: item had behavior/evidence notes but no completion/confidence score.
  - After: score reflects the exact memory range, recovered dispatcher body, block-helper split, and source ownership under [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
  - Evidence: linked by-memory evidence records the exact IDA range and callees for the 50-percent and weighted paths.
