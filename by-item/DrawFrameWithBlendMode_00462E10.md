*** UID:0000UI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DrawFrameWithBlendMode 0x00462E10

## Status

- Confidence: strong for behavior and direct caller set; medium-high for final source ownership.
- Entity kind: free render helper.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Autogen parent: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Exact range: `0x00462e10-0x00462f1e`

## Behavior

`DrawFrameWithBlendMode` clips a source frame rectangle against an `AlphaMaskSurface` destination rectangle, computes matching source and destination byte pointers, and applies one of three transfer modes:

| Mode | Operation |
| --- | --- |
| `0` | Replace/copy source bytes into destination via [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md). |
| `1` | Add source bytes to destination bytes via [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md). |
| `2` | Subtract source bytes from destination bytes via [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md). |

## Evidence

- 2026-05-30 live IDA MCP reports `sub_462E10` at `0x00462e10-0x00462f1e`.
- IDA direct callers are `0x004dfc42` in `0x004dfbb0-0x004dfc5a` and `0x004dfcf2` in `0x004dfc60-0x004dfd0a`, the documented LightObjImageLib draw-mode helpers.
- The function guards against missing destination pixels (`[this+0x14] == 0`) and null rectangle/source arguments, then calls `0x004b7cc0` to clip/intersect the source and destination rectangles.
- After computing matching source/destination row starts, stride, width, and height, the mode dispatch at `0x00462ebf-0x00462ecc` calls `0x00460df0` for mode `0`, `0x00460e80` for mode `1`, and `0x00460f10` for mode `2`; unsupported modes fall through without drawing.
- Source ownership remains placed with [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) because the helper uses the AlphaMaskSurface pixel pointer/stride fields, but the row-operation callees live in the adjacent software span helper cluster.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md)
- [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md)
- [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE` and attached to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
  - Before: the blend-mode alpha-frame helper was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned alpha-mask helper source under the validated AlphaMaskSurface file root; C++ remains blank because final source-facing names and exact frame/input types are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_462E10` at `0x00462e10`, size `0x10e`, with callees to the byte-span copy/add/subtract row helpers and clipping helper `0x004b7cc0`.

- What existed before: this page had the right high-level behavior but unevaluated completion/confidence metadata and a non-IDA metadata bullet as evidence.
- What changed to: the page now uses live IDA MCP evidence for range, callers, clipping, and mode dispatch. Completion/confidence were set to `82/86`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `sub_462E10` as `0x00462e10-0x00462f1e`, direct callers at `0x004dfc42` and `0x004dfcf2`, clipping via `0x004b7cc0`, mode `0` call to `0x00460df0`, mode `1` call to `0x00460e80`, and mode `2` call to `0x00460f10`.
