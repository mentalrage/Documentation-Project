*** UID:0000UH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DrawEncodedAlphaFrame 0x00462F20

## Status

- Confidence: strong for boundary, behavior, and shared alpha-mask owner family; medium for final source-facing name.
- Entity kind: free render helper.
- Likely source module: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Autogen parent: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Exact range: [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)

## Behavior

This helper draws encoded frame rows into an alpha-mask surface. It clips a requested destination/source rectangle pair, skips encoded rows until the source start row, then walks signed run tokens for each row. Runs with the high bit set are drawn; the low seven bits carry run length. The written alpha value is interpolated vertically between two caller-provided alpha endpoints.

The transfer mode mirrors the other mask helpers:

| Mode | Operation |
| --- | --- |
| `0` | Fill/replace the covered run with the interpolated alpha. |
| `1` | Add the interpolated alpha to destination bytes. |
| `2` | Subtract the interpolated alpha from destination bytes. |

## Evidence

- IDA MCP decompilation on 2026-05-22 shows the signed-run row walker, vertical alpha ramp, and replace/add/subtract branches.
- IDA MCP live recheck on 2026-05-26 confirms function start `0x00462f20`, end-exclusive `0x00463252`, IDA name `sub_462F20`, and nine direct code xrefs.
- IDA MCP recheck on 2026-05-25 reports nine code xrefs in render/image-library neighborhoods. Six currently resolve to caller functions through IDA's caller query: `0x4db5a4`, `0x4dd7f6`, `0x4de289`, `0x4defa2`, `0x4df1bd`, and `0x4e31c4`.
- 2026-05-26 IDA MCP caller/xref recheck maps those six modeled callers to established image-library owners:

| Call site | Containing function | Current owner evidence |
| --- | --- | --- |
| `0x004db5a4` | `0x004db3b0` | [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) `RenderMonsterImage` overlay pass. |
| `0x004dd7f6` | `0x004dd2c0` | [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) `RenderStaticObject` overlay pass. |
| `0x004de289` | `0x004de190` | [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) `RenderEffectFrame` overlay pass. |
| `0x004defa2` | `0x004dee50` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) `DrawItemImage` overlay pass. |
| `0x004df1bd` | `0x004defc0` | [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) `DrawItemImageIn43x43Slot` overlay pass. |
| `0x004e31c4` | `0x004e2fe0` | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) prepared-composition overlay pass. |

- The remaining xrefs at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` are still code refs but IDA currently reports no containing function. Local disassembly shows the same scaled overlay-strength setup before calling `0x00462f20`, so keep them as raw image-library neighborhood evidence rather than separate source owners.
- The helper uses the same alpha-surface layout and rect intersection helper family as `AlphaMaskSurface` and `DrawFrameWithBlendMode`.
- 2026-05-30 IDA MCP recheck confirms `sub_462F20` size `0x332`, the same six modeled callers, and the same three raw xrefs outside modeled functions.
- 2026-05-30 decompilation confirms the encoded source rows are read from `a3[9]`, target pixels/stride are read from alpha-surface offsets `+0x14/+0x20`, and the vertical alpha ramp is rounded from the caller-provided row/alpha endpoints.

## Reconstruction Notes

Keep this as a shared alpha-mask blitter in the alpha-surface source family. The frame/source payload type is still provisional, but the helper should not be duplicated into `MonsterImageLib`, `StaticObjImageLib`, `EffectObjImageLib`, `ItemObjImageLib`, or `NewHumanImageLib`.

The source form should keep the three blend modes visible: replace/fill, add, and subtract. Runs with the high bit set are drawn; non-negative run tokens only advance the x cursor.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), and stale generated-emission wording was removed.
  - Before: the encoded alpha-frame blitter was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned alpha-mask blitter source under the validated AlphaMaskSurface file root; C++ remains blank because final frame-source type names and mode naming are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_462F20` at `0x00462f20`, size `0x332`, with alpha-surface/rectangle callees and the already documented image-library caller spread.

- 2026-05-30: Raised completion/confidence from `0/0` to `84/88` and replaced the stale raw range text with the canonical by-memory UID link. Added current IDA MCP boundary/caller/xref/decompilation evidence and preserved the open frame-source type/raw-xref caveats.
